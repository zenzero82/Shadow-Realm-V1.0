#include "global.h"
#include "headbutt.h"
#include "event_data.h"
#include "battle_setup.h"
#include "field_player_avatar.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "script.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/map_types.h"
#include "constants/moves.h"
#include "constants/species.h"

#include "data/headbutt_encounters.h"
#include "data/headbutt_trees.h"

#define HEADBUTT_BATTLE_CHANCE 10
#define HEADBUTT_APRICORN_CHANCE 60
#define HEADBUTT_TREE_KEY_VALID 0x80000000
#define HEADBUTT_RANDOM_APRICORN_COUNT 3

static u16 sHeadbuttWildSpecies = SPECIES_NONE;
static u8 sHeadbuttWildLevel = 0;

enum HeadbuttApricornDropType
{
    HEADBUTT_DROP_ONE,
    HEADBUTT_DROP_RANDOM,
    HEADBUTT_DROP_ALL,
};

static u32 BuildHeadbuttTreeKey(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    return HEADBUTT_TREE_KEY_VALID
        | ((u32)mapGroup << 24)
        | ((u32)mapNum << 16)
        | ((u32)(u8)x << 8)
        | (u32)(u8)y;
}

static bool8 IsHeadbuttWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!REPEL_STEP_COUNT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (I_REPEL_INCLUDE_FAINTED == GEN_1 || I_REPEL_INCLUDE_FAINTED >= GEN_6 || GetMonData(&gPlayerParty[i], MON_DATA_HP))
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                return wildLevel >= GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        }
    }

    return FALSE;
}

static bool8 IsHeadbuttAbilityAllowingEncounter(u8 level)
{
    u16 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static u16 GetWildMonHeaderIdForMap(u8 mapGroup, u8 mapNum)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];

        if (wildHeader->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            break;
        if (wildHeader->mapGroup == mapGroup && wildHeader->mapNum == mapNum)
            return i;
    }

    return HEADER_NONE;
}

static bool8 GetLandWildLevelRangeForMap(u8 mapGroup, u8 mapNum, u8 *outMin, u8 *outMax)
{
    u16 headerId = GetWildMonHeaderIdForMap(mapGroup, mapNum);
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *landInfo;
    u8 minLevel = 0xFF;
    u8 maxLevel = 0;
    u8 i;

    if (headerId == HEADER_NONE)
        return FALSE;

    timeOfDay = OW_TIME_OF_DAY_ENCOUNTERS ? GetTimeOfDay() : TIME_OF_DAY_DEFAULT;
    landInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
    if (landInfo == NULL || landInfo->wildPokemon == NULL)
        return FALSE;

    for (i = 0; i < LAND_WILD_COUNT; i++)
    {
        const struct WildPokemon *entry = &landInfo->wildPokemon[i];
        u8 entryMin = entry->minLevel;
        u8 entryMax = entry->maxLevel;

        if (entry->species == SPECIES_NONE)
            continue;

        if (entryMax < entryMin)
        {
            u8 temp = entryMax;
            entryMax = entryMin;
            entryMin = temp;
        }

        if (entryMin < minLevel)
            minLevel = entryMin;
        if (entryMax > maxLevel)
            maxLevel = entryMax;
    }

    if (minLevel == 0xFF)
        return FALSE;

    *outMin = minLevel;
    *outMax = maxLevel;
    return TRUE;
}

static bool8 GetHeadbuttLevelRange(u8 *outMin, u8 *outMax)
{
    const struct MapConnections *connections;
    const struct MapConnection *connection;

    if (gMapHeader.mapType == MAP_TYPE_TOWN || gMapHeader.mapType == MAP_TYPE_CITY)
    {
        connections = gMapHeader.connections;
        if (connections != NULL && connections->count > 0)
        {
            connection = connections->connections;
            return GetLandWildLevelRangeForMap(connection->mapGroup, connection->mapNum, outMin, outMax);
        }

        return FALSE;
    }

    if (GetLandWildLevelRangeForMap(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, outMin, outMax))
        return TRUE;

    connections = gMapHeader.connections;
    if (connections != NULL && connections->count > 0)
    {
        connection = connections->connections;
        return GetLandWildLevelRangeForMap(connection->mapGroup, connection->mapNum, outMin, outMax);
    }

    return FALSE;
}

static bool8 SpeciesCanUseFieldHeadbutt(u16 species)
{
    const struct LevelUpMove *learnset;
    const u16 *eggMoves;
    u32 i;

    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    if (CanLearnTeachableMove(species, MOVE_HEADBUTT))
        return TRUE;

    learnset = GetSpeciesLevelUpLearnset(species);
    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END && i < MAX_LEVEL_UP_MOVES; i++)
    {
        if (learnset[i].move == MOVE_HEADBUTT)
            return TRUE;
    }

    eggMoves = GetSpeciesEggMoves(species);
    for (i = 0; eggMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        if (eggMoves[i] == MOVE_HEADBUTT)
            return TRUE;
    }

    return FALSE;
}

static bool8 CanPartyUseHeadbuttFieldMove(u8 *partyIndex)
{
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        if (species == SPECIES_NONE)
            break;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            continue;
        if (SpeciesCanUseFieldHeadbutt(species))
        {
            *partyIndex = i;
            return TRUE;
        }
    }

    return FALSE;
}

static const struct HeadbuttTreeData *FindHeadbuttTreeData(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(gHeadbuttTrees); i++)
    {
        const struct HeadbuttTreeData *tree = &gHeadbuttTrees[i];

        if (tree->mapGroup == mapGroup && tree->mapNum == mapNum && tree->x == x && tree->y == y)
            return tree;
    }

    return NULL;
}

static const struct HeadbuttTreeData *GetHeadbuttTreeData(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    const struct HeadbuttTreeData *tree = FindHeadbuttTreeData(mapGroup, mapNum, x, y);

    if (tree != NULL)
        return tree;

    return &gHeadbuttTreeDefault;
}

static struct HeadbuttTreeUsage *GetHeadbuttTreeUsage(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    u32 i;
    u32 key = BuildHeadbuttTreeKey(mapGroup, mapNum, x, y);

    for (i = 0; i < HEADBUTT_TREE_TRACKED_MAX; i++)
    {
        if (gSaveBlock1Ptr->headbuttTreeUsage[i].key == key)
            return &gSaveBlock1Ptr->headbuttTreeUsage[i];
    }

    for (i = 0; i < HEADBUTT_TREE_TRACKED_MAX; i++)
    {
        if (gSaveBlock1Ptr->headbuttTreeUsage[i].key == 0)
        {
            gSaveBlock1Ptr->headbuttTreeUsage[i].key = key;
            gSaveBlock1Ptr->headbuttTreeUsage[i].lastUsedDay = 0;
            return &gSaveBlock1Ptr->headbuttTreeUsage[i];
        }
    }

    return NULL;
}

static bool8 IsHeadbuttTreeOnCooldown(const struct HeadbuttTreeData *tree, const struct HeadbuttTreeUsage *usage, u16 today)
{
    if (tree->cooldownDays == 0 || usage == NULL)
        return FALSE;

    if (usage->lastUsedDay == 0)
        return FALSE;

    return (u16)(today - usage->lastUsedDay) < tree->cooldownDays;
}

static u16 GetHeadbuttApricornCount(void)
{
    u16 roll = Random() % 100;

    if (roll < 70)
        return 1;
    if (roll < 95)
        return HEADBUTT_RANDOM_APRICORN_COUNT;
    return 0;
}

static void GiveHeadbuttApricorns(const struct HeadbuttTreeData *tree, u16 count, bool8 assorted)
{
    u32 i;

    if (count == 0)
    {
        if (tree->assortedPool == NULL || tree->assortedPoolCount == 0)
        {
            AddBagItem(tree->primaryApricorn, 1);
            return;
        }

        for (i = 0; i < tree->assortedPoolCount; i++)
            AddBagItem(tree->assortedPool[i], 1);
        return;
    }

    for (i = 0; i < count; i++)
    {
        u16 item = tree->primaryApricorn;

        if (assorted && tree->assortedPool != NULL && tree->assortedPoolCount != 0)
            item = tree->assortedPool[Random() % tree->assortedPoolCount];

        AddBagItem(item, 1);
    }
}

static bool8 PrepareHeadbuttWildEncounter(u8 encounterTableId)
{
    const struct HeadbuttEncounterTable *table;
    enum TimeOfDay timeOfDay;
    const struct WildPokemon *wildMons;
    const struct WildPokemon *entry;
    u8 rangeMin;
    u8 rangeMax;
    u8 index;
    u8 level;

    sHeadbuttWildSpecies = SPECIES_NONE;
    sHeadbuttWildLevel = 0;
    if (encounterTableId >= ARRAY_COUNT(gHeadbuttEncounterTables))
        return FALSE;

    table = &gHeadbuttEncounterTables[encounterTableId];
    timeOfDay = OW_TIME_OF_DAY_ENCOUNTERS ? GetTimeOfDay() : TIME_OF_DAY_DEFAULT;
    wildMons = table->wildMonsInfo[timeOfDay];
    if (wildMons == NULL)
        return FALSE;

    index = Random() % HEADBUTT_WILD_COUNT;
    entry = &wildMons[index];
    if (GetHeadbuttLevelRange(&rangeMin, &rangeMax))
    {
        if (rangeMax < rangeMin)
        {
            u8 temp = rangeMax;
            rangeMax = rangeMin;
            rangeMin = temp;
        }

        if (rangeMax == rangeMin)
            level = rangeMin;
        else
            level = rangeMin + (Random() % (rangeMax - rangeMin + 1));
    }
    else if (entry->minLevel >= entry->maxLevel)
    {
        level = entry->minLevel;
    }
    else
    {
        level = entry->minLevel + (Random() % (entry->maxLevel - entry->minLevel + 1));
    }

    if (!IsHeadbuttWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS
     && !IsHeadbuttAbilityAllowingEncounter(level))
        return FALSE;

    sHeadbuttWildSpecies = entry->species;
    sHeadbuttWildLevel = level;

    return TRUE;
}

u16 Special_HeadbuttTree(void)
{
    s16 x;
    s16 y;
    u8 partyIndex;
    u16 today;
    const struct HeadbuttTreeData *tree;
    struct HeadbuttTreeUsage *usage;
    u16 roll;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tree = GetHeadbuttTreeData(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, x, y);

    if (!CanPartyUseHeadbuttFieldMove(&partyIndex))
        return HEADBUTT_RESULT_NO_MON;

    today = (u16)RtcGetLocalDayCount();
    usage = GetHeadbuttTreeUsage(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, x, y);
    if (IsHeadbuttTreeOnCooldown(tree, usage, today))
        return HEADBUTT_RESULT_TOO_SOON;

    gSpecialVar_0x8004 = partyIndex;
    if (usage != NULL)
        usage->lastUsedDay = today;

    roll = Random() % 100;
    if (roll < HEADBUTT_APRICORN_CHANCE)
    {
        u16 count = GetHeadbuttApricornCount();
        bool8 assorted = (Random() % 100) >= 75;

        if (count != 1)
            assorted = TRUE;

        GiveHeadbuttApricorns(tree, count, assorted);
        gSpecialVar_0x8005 = count;
        if (count == 1)
            return HEADBUTT_RESULT_APRICORN_1;
        if (count == HEADBUTT_RANDOM_APRICORN_COUNT)
            return HEADBUTT_RESULT_APRICORN_2;
        return HEADBUTT_RESULT_APRICORN_10;
    }
    else if (roll < HEADBUTT_APRICORN_CHANCE + HEADBUTT_BATTLE_CHANCE)
    {
        if (PrepareHeadbuttWildEncounter(tree->encounterTableId))
            return HEADBUTT_RESULT_BATTLE;
    }

    return HEADBUTT_RESULT_NOTHING;
}

u16 Special_HeadbuttTree_StartBattle(void)
{
    if (sHeadbuttWildSpecies == SPECIES_NONE)
        return FALSE;

    CreateWildMon(sHeadbuttWildSpecies, sHeadbuttWildLevel);
    BattleSetup_StartWildBattle();
    return TRUE;
}
