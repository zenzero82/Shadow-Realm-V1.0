#include "global.h"
#include "roaming_shadow_hunter.h"
#include "battle.h"
#include "battle_setup.h"
#include "event_data.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "shadow_monitor_species.h"
#include "constants/pokemon.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/opponents.h"
#include "constants/shadow.h"
#include "constants/vars.h"

#define ROAMING_HUNTER_MIN_MAP_LOADS 10
#define ROAMING_HUNTER_LEGACY_MAGIC_0 'R'
#define ROAMING_HUNTER_LEGACY_MAGIC_1 'S'
#define ROAMING_HUNTER_LEGACY_MAGIC_2 'H'

static bool8 PushMissedShadow(u8 region, u16 species, u8 level, u16 shadowId);

static const struct HunterSpawnPoint sHunterSpawnPoints_Kanto[] =
{
    {MAP_GROUP(MAP_ROCK_TUNNEL_B1F),     MAP_NUM(MAP_ROCK_TUNNEL_B1F),     24, 19},
    {MAP_GROUP(MAP_MT_MOON_CAVE),        MAP_NUM(MAP_MT_MOON_CAVE),        7, 7},
    {MAP_GROUP(MAP_DIGLETTS_CAVE_TUNNEL), MAP_NUM(MAP_DIGLETTS_CAVE_TUNNEL), 44, 37},
    {MAP_GROUP(MAP_DIGLETTS_CAVE_TUNNEL), MAP_NUM(MAP_DIGLETTS_CAVE_TUNNEL), 45, 37},
};

static const struct HunterSpawnPoint sHunterSpawnPoints_Johto[] =
{
    {MAP_GROUP(MAP_DARK_CAVE_SOUTH_SIDE), MAP_NUM(MAP_DARK_CAVE_SOUTH_SIDE), 17, 10},
    {MAP_GROUP(MAP_DARK_CAVE_NORTH_SIDE), MAP_NUM(MAP_DARK_CAVE_NORTH_SIDE), 6, 7},
    {MAP_GROUP(MAP_UNION_CAVE_1F),        MAP_NUM(MAP_UNION_CAVE_1F),        22, 55},
    {MAP_GROUP(MAP_UNION_CAVE_B1F),       MAP_NUM(MAP_UNION_CAVE_B1F),       23, 25},
    {MAP_GROUP(MAP_ILEX_FOREST),          MAP_NUM(MAP_ILEX_FOREST),          10, 24},
};

static const struct HunterSpawnPoint sHunterSpawnPoints_Hoenn[] =
{
    {MAP_GROUP(MAP_METEOR_FALLS_1F_1R),          MAP_NUM(MAP_METEOR_FALLS_1F_1R),          8, 9},
    {MAP_GROUP(MAP_MT_PYRE_1F),                  MAP_NUM(MAP_MT_PYRE_1F),                  7, 8},
    {MAP_GROUP(MAP_DESERT_RUINS),                MAP_NUM(MAP_DESERT_RUINS),                6, 7},
    {MAP_GROUP(MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM), MAP_NUM(MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM), 8, 7},
    {MAP_GROUP(MAP_RUSTURF_TUNNEL),              MAP_NUM(MAP_RUSTURF_TUNNEL),              9, 6},
};

static const struct HunterSpawnPoint *const sHunterSpawnPoints[ROAMING_SHADOW_HUNTER_REGION_COUNT] =
{
    sHunterSpawnPoints_Kanto,
    sHunterSpawnPoints_Johto,
    sHunterSpawnPoints_Hoenn,
};

static const u8 sHunterSpawnPointCounts[ROAMING_SHADOW_HUNTER_REGION_COUNT] =
{
    ARRAY_COUNT(sHunterSpawnPoints_Kanto),
    ARRAY_COUNT(sHunterSpawnPoints_Johto),
    ARRAY_COUNT(sHunterSpawnPoints_Hoenn),
};

static s8 RegionToIndex(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return 0;
    case REGION_JOHTO:
        return 1;
    case REGION_HOENN:
        return 2;
    default:
        return -1;
    }
}

static u8 ChooseHunterId(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return HUNTER_CASSIDY;
    case REGION_JOHTO:
        return HUNTER_SILVER;
    case REGION_HOENN:
        return HUNTER_HEX_1 + (Random() % 6);
    default:
        return HUNTER_CASSIDY;
    }
}

static u16 GetRegionActiveFlag(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return FLAG_ROAMING_HUNTER_KANTO_ACTIVE;
    case REGION_JOHTO:
        return FLAG_ROAMING_HUNTER_JOHTO_ACTIVE;
    case REGION_HOENN:
        return FLAG_ROAMING_HUNTER_HOENN_ACTIVE;
    default:
        return FLAG_ROAMING_HUNTER_KANTO_ACTIVE;
    }
}

static u16 GetHunterTrainerId(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
    case HUNTER_BUTCH:
        return TRAINER_CASSIDY_HUNTER;
    case HUNTER_SILVER:
        return TRAINER_SILVER_HUNTER;
    case HUNTER_HEX_1:
        return TRAINER_HEX_RESIX;
    case HUNTER_HEX_2:
        return TRAINER_HEX_BLUSIX;
    case HUNTER_HEX_3:
        return TRAINER_HEX_GREESIX;
    case HUNTER_HEX_4:
        return TRAINER_HEX_PURPSIX;
    case HUNTER_HEX_5:
        return TRAINER_HEX_BROWSIX;
    case HUNTER_HEX_6:
        return TRAINER_HEX_YELLOSIX;
    default:
        return TRAINER_NONE;
    }
}

static u8 GetHunterIdFromTrainer(u16 trainerId)
{
    switch (trainerId)
    {
    case TRAINER_CASSIDY_HUNTER:
        return HUNTER_CASSIDY;
    case TRAINER_BUTCH_HUNTER:
        return HUNTER_BUTCH;
    case TRAINER_SILVER_HUNTER:
        return HUNTER_SILVER;
    case TRAINER_HEX_RESIX:
        return HUNTER_HEX_1;
    case TRAINER_HEX_BLUSIX:
        return HUNTER_HEX_2;
    case TRAINER_HEX_GREESIX:
        return HUNTER_HEX_3;
    case TRAINER_HEX_PURPSIX:
        return HUNTER_HEX_4;
    case TRAINER_HEX_BROWSIX:
        return HUNTER_HEX_5;
    case TRAINER_HEX_YELLOSIX:
        return HUNTER_HEX_6;
    default:
        return HUNTER_COUNT;
    }
}

static u8 GetHunterRegionForId(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
    case HUNTER_BUTCH:
        return REGION_KANTO;
    case HUNTER_SILVER:
        return REGION_JOHTO;
    case HUNTER_HEX_1:
    case HUNTER_HEX_2:
    case HUNTER_HEX_3:
    case HUNTER_HEX_4:
    case HUNTER_HEX_5:
    case HUNTER_HEX_6:
        return REGION_HOENN;
    default:
        return REGION_KANTO;
    }
}

static u16 GetHunterObjectGfx(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
        return OBJ_EVENT_GFX_CASSIDY;
    case HUNTER_BUTCH:
        return OBJ_EVENT_GFX_BUTCH;
    case HUNTER_SILVER:
        return OBJ_EVENT_GFX_SILVER_GEN2;
    case HUNTER_HEX_1:
        return OBJ_EVENT_GFX_RESIX;
    case HUNTER_HEX_2:
        return OBJ_EVENT_GFX_BLUSIX;
    case HUNTER_HEX_3:
        return OBJ_EVENT_GFX_GREESIX;
    case HUNTER_HEX_4:
        return OBJ_EVENT_GFX_PURPSIX;
    case HUNTER_HEX_5:
        return OBJ_EVENT_GFX_BROWSIX;
    case HUNTER_HEX_6:
        return OBJ_EVENT_GFX_YELLOSIX;
    default:
        return OBJ_EVENT_GFX_HEX_MANIAC;
    }
}

static struct RoamingShadowHunterSave *GetRoamingHunterSave(void)
{
    return &gSaveBlock1Ptr->roamingShadowHunter;
}

static u8 GetFallbackHunterLevel(void)
{
    u8 i;
    u8 highest = 1;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE)
            continue;

        if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) > highest)
            highest = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
    }

    return highest;
}

static bool8 IsShadowIdQueued(u8 regionIndex, u16 shadowId)
{
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    u8 i;
    u8 pos;

    if (regionIndex >= ROAMING_SHADOW_HUNTER_REGION_COUNT)
        return FALSE;

    pos = save->queueHead[regionIndex];
    for (i = 0; i < save->queueCount[regionIndex]; i++)
    {
        if (save->queue[regionIndex][pos].shadowId == shadowId)
            return TRUE;
        pos = (pos + 1) % ROAMING_SHADOW_QUEUE_SIZE;
    }

    return FALSE;
}

static void ScanLegacyFailedShadows(u8 region)
{
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    s8 regionIndex = RegionToIndex(region);
    u16 shadowId;
    u8 level;

    if (save->legacyScanMagic[0] != ROAMING_HUNTER_LEGACY_MAGIC_0
     || save->legacyScanMagic[1] != ROAMING_HUNTER_LEGACY_MAGIC_1
     || save->legacyScanMagic[2] != ROAMING_HUNTER_LEGACY_MAGIC_2)
    {
        save->legacyScanMagic[0] = ROAMING_HUNTER_LEGACY_MAGIC_0;
        save->legacyScanMagic[1] = ROAMING_HUNTER_LEGACY_MAGIC_1;
        save->legacyScanMagic[2] = ROAMING_HUNTER_LEGACY_MAGIC_2;
        save->legacyScanDone = FALSE;
    }

    if (save->legacyScanDone == TRUE)
        return;
    save->legacyScanDone = TRUE;

    if (regionIndex < 0)
        return;

    level = GetFallbackHunterLevel();

    // TODO: map shadowId to its original region if needed.
    for (shadowId = 1; shadowId <= MAX_SHADOW_MON_IDS; shadowId++)
    {
        u16 species;

        if (Shdw_GetState(shadowId) != SHDW_STATE_FAILED)
            continue;
        if (IsShadowIdQueued(regionIndex, shadowId))
            continue;
        if (save->active[regionIndex].active && save->active[regionIndex].shadowId == shadowId)
            continue;

        species = GetShadowMonitorSpecies(shadowId);
        if (species == SPECIES_NONE)
            continue;

        if (!PushMissedShadow(region, species, level, shadowId))
            break;
    }

    if (!save->active[regionIndex].active && save->queueCount[regionIndex] != 0)
        save->mapLoadCounter[regionIndex] = 0;
}

static void UpdateHunterHideFlagForMap(const struct ActiveHunterState *active)
{
    if (active != NULL
     && active->active
     && !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING)
     && active->mapGroup == gSaveBlock1Ptr->location.mapGroup
     && active->mapNum == gSaveBlock1Ptr->location.mapNum)
    {
        VarSet(VAR_OBJ_GFX_ID_0, GetHunterObjectGfx(active->hunterId));
        VarSet(VAR_ROAMING_HUNTER_X, active->x);
        VarSet(VAR_ROAMING_HUNTER_Y, active->y);
        FlagClear(FLAG_ROAMING_HUNTER_NPC_HIDE);
    }
    else
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
}

bool8 RoamingHunter_IsUnlocked(void)
{
    return FlagGet(FLAG_SHADOW_TRACKER_UNLOCKED);
}

static bool8 PushMissedShadow(u8 region, u16 species, u8 level, u16 shadowId)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct MissedShadowEntry *entry;
    u8 insertIndex;

    if (regionIndex < 0)
        return FALSE;
    if (save->queueCount[regionIndex] >= ROAMING_SHADOW_QUEUE_SIZE)
        return FALSE;

    insertIndex = (save->queueHead[regionIndex] + save->queueCount[regionIndex]) % ROAMING_SHADOW_QUEUE_SIZE;
    entry = &save->queue[regionIndex][insertIndex];
    entry->species = species;
    entry->shadowId = shadowId;
    entry->level = level;
    entry->region = region;
    entry->resolved = FALSE;
    entry->padding = 0;
    save->queueCount[regionIndex]++;
    return TRUE;
}

static bool8 PopMissedShadow(u8 region, struct MissedShadowEntry *out)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct MissedShadowEntry *entry;
    u8 head;

    if (regionIndex < 0)
        return FALSE;
    if (save->queueCount[regionIndex] == 0)
        return FALSE;

    head = save->queueHead[regionIndex];
    entry = &save->queue[regionIndex][head];
    if (out != NULL)
        *out = *entry;
    save->queueHead[regionIndex] = (head + 1) % ROAMING_SHADOW_QUEUE_SIZE;
    save->queueCount[regionIndex]--;
    return TRUE;
}

static void SpawnHunterForRegion(u8 region)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct ActiveHunterState *active;
    struct MissedShadowEntry entry;
    const struct HunterSpawnPoint *spawnPoint;
    u8 spawnIndex;

    if (regionIndex < 0)
        return;
    if (!RoamingHunter_IsUnlocked())
        return;

    active = &save->active[regionIndex];
    if (active->active)
        return;
    if (!PopMissedShadow(region, &entry))
        return;

    spawnIndex = Random() % sHunterSpawnPointCounts[regionIndex];
    spawnPoint = &sHunterSpawnPoints[regionIndex][spawnIndex];

    active->active = TRUE;
    active->region = region;
    active->hunterId = ChooseHunterId(region);
    active->shadowId = entry.shadowId;
    if (entry.shadowId != 0 && entry.shadowId <= MAX_SHADOW_MON_IDS)
        active->species = GetShadowMonitorSpecies(entry.shadowId);
    else
        active->species = entry.species;
    active->level = entry.level;
    active->mapGroup = spawnPoint->mapGroup;
    active->mapNum = spawnPoint->mapNum;
    active->x = spawnPoint->x;
    active->y = spawnPoint->y;
    save->mapLoadCounter[regionIndex] = 0;
    FlagSet(GetRegionActiveFlag(region));
    FlagSet(FLAG_ROAMING_HUNTER_ALERT_PENDING);
}

void RoamingHunter_OnShadowSnagFailed(u16 species, u8 level, u8 region, u16 shadowId)
{
    struct RoamingShadowHunterSave *save;
    s8 regionIndex;

    if (!RoamingHunter_IsUnlocked())
        return;
    if (species == SPECIES_NONE)
        return;
    if (level == 0)
        level = 1;
    if (!PushMissedShadow(region, species, level, shadowId))
        return;

    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return;

    save = GetRoamingHunterSave();
    if (!save->active[regionIndex].active && save->queueCount[regionIndex] == 1)
        save->mapLoadCounter[regionIndex] = 0;
}

const struct ActiveHunterState *RoamingHunter_GetActiveForRegion(u8 region)
{
    s8 regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return NULL;
    if (!RoamingHunter_IsUnlocked())
        return NULL;
    return &GetRoamingHunterSave()->active[regionIndex];
}

u16 RoamingHunter_TryCreateNpcOnMap(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);

    if (!RoamingHunter_IsUnlocked())
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }
    if (active == NULL || !active->active)
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }
    if (FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING))
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    if (active->mapGroup != gSaveBlock1Ptr->location.mapGroup
     || active->mapNum != gSaveBlock1Ptr->location.mapNum)
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    VarSet(VAR_ROAMING_HUNTER_X, active->x);
    VarSet(VAR_ROAMING_HUNTER_Y, active->y);
    VarSet(VAR_OBJ_GFX_ID_0, GetHunterObjectGfx(active->hunterId));
    gSpecialVar_Result = 1;
    return gSpecialVar_Result;
}

void RoamingHunter_OnMapTransition(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save;
    struct ActiveHunterState *active;

    if (!RoamingHunter_IsUnlocked())
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }
    if (regionIndex < 0)
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }

    save = GetRoamingHunterSave();
    ScanLegacyFailedShadows(region);
    active = &save->active[regionIndex];
    if (!active->active)
    {
        if (save->queueCount[regionIndex] == 0)
        {
            save->mapLoadCounter[regionIndex] = 0;
            UpdateHunterHideFlagForMap(active);
            return;
        }

        if (save->mapLoadCounter[regionIndex] < 0xFF)
            save->mapLoadCounter[regionIndex]++;
        if (save->mapLoadCounter[regionIndex] < ROAMING_HUNTER_MIN_MAP_LOADS)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }
        if ((Random() & 1) == 0)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }

        SpawnHunterForRegion(region);
        active = &save->active[regionIndex];
        if (!active->active)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }
    }

    UpdateHunterHideFlagForMap(active);
}

void RoamingHunter_PrepareMapLoad(u8 mapGroup, u8 mapNum)
{
    u8 region = RegionMap_GetRegionFromMapGroup(mapGroup);
    const struct ActiveHunterState *active;

    if (!RoamingHunter_IsUnlocked())
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }

    active = RoamingHunter_GetActiveForRegion(region);
    if (active != NULL
     && active->active
     && !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING)
     && active->mapGroup == mapGroup
     && active->mapNum == mapNum)
        FlagClear(FLAG_ROAMING_HUNTER_NPC_HIDE);
    else
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
}

u16 RoamingHunter_TryConsumeAlert(void)
{
    if (!RoamingHunter_IsUnlocked() || !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING))
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    FlagClear(FLAG_ROAMING_HUNTER_ALERT_PENDING);
    UpdateHunterHideFlagForMap(RoamingHunter_GetActiveForRegion(
        RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup)));
    gSpecialVar_Result = 1;
    return gSpecialVar_Result;
}

u16 RoamingHunter_StartBattle(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);
    u16 trainerId;

    if (active == NULL || !active->active)
        return 0;
    if (!RoamingHunter_IsUnlocked())
        return 0;
    if (active->mapGroup != gSaveBlock1Ptr->location.mapGroup
     || active->mapNum != gSaveBlock1Ptr->location.mapNum)
        return 0;

    trainerId = GetHunterTrainerId(active->hunterId);
    if (trainerId == TRAINER_NONE)
        return 0;

    memset(gTrainerBattleParameter.data, 0, sizeof(gTrainerBattleParameter));
    TRAINER_BATTLE_PARAM.mode = TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT;
    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    TRAINER_BATTLE_PARAM.objEventLocalIdA = gSpecialVar_LastTalked;
    BattleSetup_StartTrainerBattle();
    return 1;
}

u16 RoamingHunter_OnBattleWon(void)
{
    u8 region;
    s8 regionIndex;
    struct RoamingShadowHunterSave *save;
    struct ActiveHunterState *active;

    if (!(gBattleOutcome & B_OUTCOME_WON))
        return 0;
    if (!RoamingHunter_IsUnlocked())
        return 0;

    region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return 0;

    save = GetRoamingHunterSave();
    active = &save->active[regionIndex];
    if (!active->active)
        return 0;

    memset(active, 0, sizeof(*active));
    save->mapLoadCounter[regionIndex] = 0;
    FlagClear(GetRegionActiveFlag(region));
    return 1;
}

void RoamingHunter_TryOverrideTrainerParty(u16 trainerId, struct Pokemon *party)
{
    u8 hunterId = GetHunterIdFromTrainer(trainerId);
    u8 region;
    s8 regionIndex;
    struct ActiveHunterState *active;
    u16 shadowId;
    u8 isShadow = TRUE;
    u8 snagged = FALSE;
    u8 aggro;
    u8 ball = BALL_DARK;

    if (hunterId == HUNTER_COUNT)
        return;
    if (!RoamingHunter_IsUnlocked())
        return;
    if (party < gEnemyParty || party >= gEnemyParty + PARTY_SIZE)
        return;

    region = GetHunterRegionForId(hunterId);
    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return;

    active = &GetRoamingHunterSave()->active[regionIndex];
    if (!active->active)
        return;
    if (active->hunterId != hunterId)
    {
        u8 activeId = active->hunterId;
        if (activeId != HUNTER_BUTCH || hunterId != HUNTER_CASSIDY)
            return;
    }

    shadowId = active->shadowId;
    CreateMon(&party[0], active->species, active->level, USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
    SetMonData(&party[0], MON_DATA_IS_SHADOW, &isShadow);
    SetMonData(&party[0], MON_DATA_SNAGGED, &snagged);
    SetMonData(&party[0], MON_DATA_POKEBALL, &ball);
    SetMonData(&party[0], MON_DATA_SHADOW_ID, &shadowId); // TODO: derive a valid shadow ID if none is available.
    SetMonHeartMax(&party[0], SHADOW_HEART_GAUGE_MAX);
    SetMonHeartValue(&party[0], SHADOW_HEART_GAUGE_MAX);
    aggro = Shdw_GetAggroForNature(GetNature(&party[0]));
    SetMonData(&party[0], MON_DATA_SHADOW_AGGRO, &aggro);
    CalculateMonStats(&party[0], 0);
}
