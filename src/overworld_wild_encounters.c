#include "global.h"
#include "overworld_wild_encounters.h"
#include "battle_setup.h"
#include "bug_contest.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "random.h"
#include "surf_ow.h"
#include "dexnav.h"
#include "wild_encounter.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/global.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/trainer_types.h"

#define OVERWORLD_WILD_SPAWN_TRIES 100
#define OVERWORLD_WILD_SPAWN_RADIUS 8
#define OVERWORLD_WILD_MIN_PLAYER_DISTANCE 6
#define OVERWORLD_WILD_MAX_PLAYER_DISTANCE 8
#define OVERWORLD_WILD_MIN_WILD_DISTANCE 6
#define OVERWORLD_WILD_MOVEMENT_RANGE 2
#define OVERWORLD_WILD_MIN_TILES_FOR_TWO 20
#define OVERWORLD_WILD_MIN_TILES_FOR_THREE 45

EWRAM_DATA static bool8 sOverworldWildActive[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u16 sOverworldWildSpecies[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u8 sOverworldWildLevel[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static bool8 sOverworldWildIsDexNav[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u8 sOverworldWildPotential[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u8 sOverworldWildAbilityNum[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u16 sOverworldWildHeldItem[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u16 sOverworldWildMoves[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT][MAX_MON_MOVES];

static void OverworldWildEncounters_ClearSlot(u8 slot);
static bool8 OverworldWildEncounters_FindAvailableSlot(u8 *slotOut);
static u8 OverworldWildEncounters_GetMaxSpawns(void);
static bool8 OverworldWildEncounters_IsOpenWaterTile(s16 x, s16 y);

static bool8 OverworldWildEncounters_Enabled(void)
{
    return gSaveBlock2Ptr->optionsOverworldWildEncounters == OPTIONS_OVERWORLD_WILD_ON;
}

static bool8 OverworldWildEncounters_GetLandWildMon(u16 *species, u8 *level)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *landMonsInfo;

    if (headerId == HEADER_NONE)
        return FALSE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    landMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
    if (landMonsInfo == NULL || landMonsInfo->encounterRate == 0)
        return FALSE;

    return TryGetRandomWildMonForArea(landMonsInfo, WILD_AREA_LAND, WILD_MON_CHECK_REPEL | WILD_MON_CHECK_KEEN_EYE, species, level);
}

static bool8 OverworldWildEncounters_GetWaterWildMon(u16 *species, u8 *level)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *waterMonsInfo;

    if (headerId == HEADER_NONE)
        return FALSE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
    waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
    if (waterMonsInfo == NULL || waterMonsInfo->encounterRate == 0)
        return FALSE;

    return TryGetRandomWildMonForArea(waterMonsInfo, WILD_AREA_WATER, WILD_MON_CHECK_REPEL | WILD_MON_CHECK_KEEN_EYE, species, level);
}

static bool8 OverworldWildEncounters_HasLandMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *landMonsInfo;

    if (headerId == HEADER_NONE)
        return FALSE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    landMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
    return landMonsInfo != NULL && landMonsInfo->encounterRate != 0;
}

static bool8 OverworldWildEncounters_HasWaterMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *waterMonsInfo;

    if (headerId == HEADER_NONE)
        return FALSE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
    waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
    return waterMonsInfo != NULL && waterMonsInfo->encounterRate != 0;
}

static bool8 OverworldWildEncounters_IsOpenWaterTile(s16 x, s16 y)
{
    for (s16 yOffset = -1; yOffset <= 1; yOffset++)
    {
        for (s16 xOffset = -1; xOffset <= 1; xOffset++)
        {
            if (!MetatileBehavior_IsSurfableAndNotWaterfall(MapGridGetMetatileBehaviorAt(x + xOffset, y + yOffset)))
                return FALSE;
        }
    }

    return TRUE;
}

static bool8 OverworldWildEncounters_IsSpawnTileValid(s16 x, s16 y, u8 elevation, bool8 allowLand, bool8 allowWater, bool8 *isWaterTile)
{
    u8 behavior = MapGridGetMetatileBehaviorAt(x, y);
    bool8 validLandTile = allowLand && MetatileBehavior_IsLandWildEncounter(behavior);
    bool8 validWaterTile = allowWater && OverworldWildEncounters_IsOpenWaterTile(x, y);

    if (!validLandTile && !validWaterTile)
        return FALSE;
    if (MapGridGetCollisionAt(x, y))
        return FALSE;
    if (GetObjectEventIdByPosition(x, y, elevation) != OBJECT_EVENTS_COUNT)
        return FALSE;
    if (IsElevationMismatchAt(elevation, x, y))
        return FALSE;

    if (isWaterTile != NULL)
        *isWaterTile = validWaterTile;

    return TRUE;
}

static u16 OverworldWildEncounters_CountSpawnableTiles(s16 playerX, s16 playerY, u8 elevation)
{
    s16 minX = playerX - OVERWORLD_WILD_SPAWN_RADIUS;
    s16 maxX = playerX + OVERWORLD_WILD_SPAWN_RADIUS;
    s16 minY = playerY - OVERWORLD_WILD_SPAWN_RADIUS;
    s16 maxY = playerY + OVERWORLD_WILD_SPAWN_RADIUS;
    s16 mapMinX = MAP_OFFSET;
    s16 mapMinY = MAP_OFFSET;
    s16 mapMaxX = MAP_OFFSET + gMapHeader.mapLayout->width - 1;
    s16 mapMaxY = MAP_OFFSET + gMapHeader.mapLayout->height - 1;
    bool8 allowLand = OverworldWildEncounters_HasLandMons();
    bool8 allowWater = OverworldWildEncounters_HasWaterMons();
    u16 count = 0;

    if (minX < mapMinX)
        minX = mapMinX;
    if (minY < mapMinY)
        minY = mapMinY;
    if (maxX > mapMaxX)
        maxX = mapMaxX;
    if (maxY > mapMaxY)
        maxY = mapMaxY;

    for (s16 y = minY; y <= maxY; y++)
    {
        for (s16 x = minX; x <= maxX; x++)
        {
            u8 behavior = MapGridGetMetatileBehaviorAt(x, y);

            if ((!allowLand || !MetatileBehavior_IsLandWildEncounter(behavior))
             && (!allowWater || !OverworldWildEncounters_IsOpenWaterTile(x, y)))
                continue;
            if (MapGridGetCollisionAt(x, y))
                continue;
            if (IsElevationMismatchAt(elevation, x, y))
                continue;

            count++;
        }
    }

    return count;
}

static u8 OverworldWildEncounters_GetMaxSpawns(void)
{
    s16 playerX = gSaveBlock1Ptr->pos.x;
    s16 playerY = gSaveBlock1Ptr->pos.y;
    u8 elevation = PlayerGetElevation();
    u16 tiles;

    if (gPlayerAvatar.objectEventId < OBJECT_EVENTS_COUNT && gObjectEvents[gPlayerAvatar.objectEventId].active)
    {
        playerX = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
        playerY = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
        elevation = gObjectEvents[gPlayerAvatar.objectEventId].currentElevation;
    }

    tiles = OverworldWildEncounters_CountSpawnableTiles(playerX, playerY, elevation);
    if (tiles < OVERWORLD_WILD_MIN_TILES_FOR_TWO)
        return tiles > 0 ? 1 : 0;
    if (tiles < OVERWORLD_WILD_MIN_TILES_FOR_THREE)
        return 2;
    return OBJ_EVENT_ID_OVERWORLD_WILD_COUNT;
}

static bool8 OverworldWildEncounters_IsFarFromOtherWilds(s16 x, s16 y, u8 elevation)
{
    for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        u8 localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
        u8 objectEventId;
        s16 dx;
        s16 dy;

        if (!sOverworldWildActive[slot])
            continue;
        objectEventId = GetObjectEventIdByLocalId(localId);
        if (objectEventId == OBJECT_EVENTS_COUNT)
            continue;
        if (gObjectEvents[objectEventId].currentElevation != elevation)
            continue;

        dx = gObjectEvents[objectEventId].currentCoords.x - x;
        dy = gObjectEvents[objectEventId].currentCoords.y - y;
        if (dx < 0)
            dx = -dx;
        if (dy < 0)
            dy = -dy;
        if (dx + dy < OVERWORLD_WILD_MIN_WILD_DISTANCE)
            return FALSE;
    }

    return TRUE;
}

static bool8 OverworldWildEncounters_FindSpawnCoords(s16 *xOut, s16 *yOut, u8 *elevationOut, bool8 *isWaterTileOut)
{
    s16 playerX = gSaveBlock1Ptr->pos.x;
    s16 playerY = gSaveBlock1Ptr->pos.y;
    s16 minX = playerX - OVERWORLD_WILD_SPAWN_RADIUS;
    s16 maxX = playerX + OVERWORLD_WILD_SPAWN_RADIUS;
    s16 minY = playerY - OVERWORLD_WILD_SPAWN_RADIUS;
    s16 maxY = playerY + OVERWORLD_WILD_SPAWN_RADIUS;
    s16 mapMinX = MAP_OFFSET;
    s16 mapMinY = MAP_OFFSET;
    s16 mapMaxX = MAP_OFFSET + gMapHeader.mapLayout->width - 1;
    s16 mapMaxY = MAP_OFFSET + gMapHeader.mapLayout->height - 1;
    bool8 allowLand = OverworldWildEncounters_HasLandMons();
    bool8 allowWater = OverworldWildEncounters_HasWaterMons();
    u8 elevation = PlayerGetElevation();
    u8 tries;

    if (gPlayerAvatar.objectEventId < OBJECT_EVENTS_COUNT && gObjectEvents[gPlayerAvatar.objectEventId].active)
    {
        playerX = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
        playerY = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
        minX = playerX - OVERWORLD_WILD_SPAWN_RADIUS;
        maxX = playerX + OVERWORLD_WILD_SPAWN_RADIUS;
        minY = playerY - OVERWORLD_WILD_SPAWN_RADIUS;
        maxY = playerY + OVERWORLD_WILD_SPAWN_RADIUS;
        elevation = gObjectEvents[gPlayerAvatar.objectEventId].currentElevation;
    }

    if (minX < mapMinX)
        minX = mapMinX;
    if (minY < mapMinY)
        minY = mapMinY;
    if (maxX > mapMaxX)
        maxX = mapMaxX;
    if (maxY > mapMaxY)
        maxY = mapMaxY;

    for (tries = 0; tries < OVERWORLD_WILD_SPAWN_TRIES; tries++)
    {
        s16 x;
        s16 y;
        s16 dx;
        s16 dy;

        if (minX > maxX || minY > maxY)
            break;

        x = (Random() % (maxX - minX + 1)) + minX;
        y = (Random() % (maxY - minY + 1)) + minY;
        dx = x - playerX;
        dy = y - playerY;
        if (dx < 0)
            dx = -dx;
        if (dy < 0)
            dy = -dy;
        if (dx + dy < OVERWORLD_WILD_MIN_PLAYER_DISTANCE || dx + dy > OVERWORLD_WILD_MAX_PLAYER_DISTANCE)
            continue;

        if (!OverworldWildEncounters_IsSpawnTileValid(x, y, elevation, allowLand, allowWater, isWaterTileOut))
            continue;
        if (!OverworldWildEncounters_IsFarFromOtherWilds(x, y, elevation))
            continue;

        *xOut = x;
        *yOut = y;
        *elevationOut = MapGridGetElevationAt(x, y);
        return TRUE;
    }

    return FALSE;
}

static bool8 OverworldWildEncounters_Spawn(u8 slot, u16 species, u8 level, s16 x, s16 y, u8 elevation, bool8 isWaterTile)
{
    struct ObjectEventTemplate objectEventTemplate = {0};

    if (slot >= OBJ_EVENT_ID_OVERWORLD_WILD_COUNT)
        return FALSE;

    objectEventTemplate.localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
    objectEventTemplate.graphicsId = species + OBJ_EVENT_MON;
    if (isWaterTile && SurfOw_HasSpeciesEntry(species))
        objectEventTemplate.graphicsId |= OBJ_EVENT_MON_SURF;
    objectEventTemplate.kind = OBJ_KIND_NORMAL;
    objectEventTemplate.x = x - MAP_OFFSET;
    objectEventTemplate.y = y - MAP_OFFSET;
    objectEventTemplate.elevation = elevation;
    objectEventTemplate.movementType = MOVEMENT_TYPE_WANDER_AROUND;
    objectEventTemplate.movementRangeX = OVERWORLD_WILD_MOVEMENT_RANGE;
    objectEventTemplate.movementRangeY = OVERWORLD_WILD_MOVEMENT_RANGE;
    objectEventTemplate.trainerType = TRAINER_TYPE_NONE;
    objectEventTemplate.trainerRange_berryTreeId = 0;
    objectEventTemplate.script = EventScript_OverworldWildMon;
    objectEventTemplate.flagId = 0;

    if (SpawnSpecialObjectEvent(&objectEventTemplate) != OBJECT_EVENTS_COUNT)
    {
        sOverworldWildActive[slot] = TRUE;
        sOverworldWildSpecies[slot] = species;
        sOverworldWildLevel[slot] = level;
        sOverworldWildIsDexNav[slot] = FALSE;
        sOverworldWildPotential[slot] = 0;
        sOverworldWildAbilityNum[slot] = 0;
        sOverworldWildHeldItem[slot] = ITEM_NONE;
        for (u8 i = 0; i < MAX_MON_MOVES; i++)
            sOverworldWildMoves[slot][i] = MOVE_NONE;
        return TRUE;
    }

    return FALSE;
}

static bool8 OverworldWildEncounters_FindAvailableSlot(u8 *slotOut)
{
    for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        u8 localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;

        if (sOverworldWildActive[slot])
        {
            if (GetObjectEventIdByLocalId(localId) != OBJECT_EVENTS_COUNT)
                continue;
            OverworldWildEncounters_ClearSlot(slot);
        }

        *slotOut = slot;
        return TRUE;
    }

    return FALSE;
}

static void OverworldWildEncounters_ClearSlot(u8 slot)
{
    u8 localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
    u8 objectEventId = GetObjectEventIdByLocalId(localId);

    if (objectEventId != OBJECT_EVENTS_COUNT)
        RemoveObjectEvent(&gObjectEvents[objectEventId]);

    sOverworldWildActive[slot] = FALSE;
    sOverworldWildIsDexNav[slot] = FALSE;
    sOverworldWildSpecies[slot] = SPECIES_NONE;
    sOverworldWildLevel[slot] = 0;
    sOverworldWildPotential[slot] = 0;
    sOverworldWildAbilityNum[slot] = 0;
    sOverworldWildHeldItem[slot] = ITEM_NONE;
    for (u8 i = 0; i < MAX_MON_MOVES; i++)
        sOverworldWildMoves[slot][i] = MOVE_NONE;
}

void OverworldWildEncounters_TrySpawn(void)
{
    s16 x;
    s16 y;
    u8 elevation;
    bool8 isWaterTile;
    u16 species;
    u8 level;
    u8 maxSpawns;

    if (!OverworldWildEncounters_Enabled())
        return;
    if (FlagGet(OW_FLAG_NO_ENCOUNTER))
        return;
    if (MapHasNoEncounterData())
        return;
    maxSpawns = OverworldWildEncounters_GetMaxSpawns();
    if (maxSpawns == 0)
    {
        for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
        {
            if (sOverworldWildActive[slot])
                OverworldWildEncounters_ClearSlot(slot);
        }
        return;
    }

    for (u8 slot = maxSpawns; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        if (sOverworldWildActive[slot])
            OverworldWildEncounters_ClearSlot(slot);
    }

    for (u8 slot = 0; slot < maxSpawns; slot++)
    {
        u8 localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
        if (sOverworldWildActive[slot])
        {
            if (GetObjectEventIdByLocalId(localId) != OBJECT_EVENTS_COUNT)
                continue;
            OverworldWildEncounters_ClearSlot(slot);
        }

        if (!OverworldWildEncounters_FindSpawnCoords(&x, &y, &elevation, &isWaterTile))
            return;
        if (isWaterTile)
        {
            if (!OverworldWildEncounters_GetWaterWildMon(&species, &level))
                return;
        }
        else
        {
            if (!OverworldWildEncounters_GetLandWildMon(&species, &level))
                return;
        }

        OverworldWildEncounters_Spawn(slot, species, level, x, y, elevation, isWaterTile);
    }
}

void OverworldWildEncounters_OnMapLoad(void)
{
    for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        sOverworldWildActive[slot] = FALSE;
        sOverworldWildSpecies[slot] = SPECIES_NONE;
        sOverworldWildLevel[slot] = 0;
        sOverworldWildIsDexNav[slot] = FALSE;
        sOverworldWildPotential[slot] = 0;
        sOverworldWildAbilityNum[slot] = 0;
        sOverworldWildHeldItem[slot] = ITEM_NONE;
        for (u8 i = 0; i < MAX_MON_MOVES; i++)
            sOverworldWildMoves[slot][i] = MOVE_NONE;
        RemoveObjectEventByLocalIdAndMap(OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }

    if (GetBugContestFlag())
        return;

    OverworldWildEncounters_TrySpawn();
}

void OverworldWildEncounters_OnReturnToField(void)
{
    if (GetBugContestFlag()
     || !OverworldWildEncounters_Enabled()
     || FlagGet(OW_FLAG_NO_ENCOUNTER)
     || MapHasNoEncounterData())
    {
        for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
        {
            if (sOverworldWildActive[slot])
                OverworldWildEncounters_ClearSlot(slot);
        }
        return;
    }

    OverworldWildEncounters_TrySpawn();
}

bool8 OverworldWildEncounters_SpawnDexNavMon(u16 species, u8 level, u8 potential, u8 abilityNum, u16 item, const u16 *moves,
                                             s16 x, s16 y, u8 elevation, u8 *outLocalId)
{
    bool8 isWaterTile;
    u8 slot;

    if (!OverworldWildEncounters_IsSpawnTileValid(x, y, elevation, TRUE, TRUE, &isWaterTile))
        return FALSE;

    if (!OverworldWildEncounters_FindAvailableSlot(&slot))
    {
        slot = 0;
        OverworldWildEncounters_ClearSlot(slot);
    }

    if (!OverworldWildEncounters_Spawn(slot, species, level, x, y, elevation, isWaterTile))
        return FALSE;

    sOverworldWildIsDexNav[slot] = TRUE;
    sOverworldWildPotential[slot] = potential;
    sOverworldWildAbilityNum[slot] = abilityNum;
    sOverworldWildHeldItem[slot] = item;
    for (u8 i = 0; i < MAX_MON_MOVES; i++)
        sOverworldWildMoves[slot][i] = moves[i];

    if (outLocalId != NULL)
        *outLocalId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;

    return TRUE;
}

bool8 OverworldWildEncounters_TryStartBattleAtCoords(s16 x, s16 y, u8 elevation)
{
    u8 objectEventId;
    u8 slot;

    objectEventId = GetObjectEventIdByPosition(x, y, elevation);
    if (objectEventId == OBJECT_EVENTS_COUNT)
        return FALSE;
    if (gObjectEvents[objectEventId].localId < OBJ_EVENT_ID_OVERWORLD_WILD_BASE
     || gObjectEvents[objectEventId].localId >= OBJ_EVENT_ID_OVERWORLD_WILD_BASE + OBJ_EVENT_ID_OVERWORLD_WILD_COUNT)
        return FALSE;

    slot = gObjectEvents[objectEventId].localId - OBJ_EVENT_ID_OVERWORLD_WILD_BASE;
    if (slot >= OBJ_EVENT_ID_OVERWORLD_WILD_COUNT || !sOverworldWildActive[slot])
        return FALSE;

    gIsFishingEncounter = FALSE;
    gIsSurfingEncounter = FALSE;
    if (sOverworldWildIsDexNav[slot])
    {
        gDexNavSpecies = sOverworldWildSpecies[slot];
        CreateDexNavWildMon(sOverworldWildSpecies[slot], sOverworldWildPotential[slot], sOverworldWildLevel[slot],
                            sOverworldWildAbilityNum[slot], sOverworldWildHeldItem[slot], sOverworldWildMoves[slot]);
    }
    else
    {
        CreateWildMon(sOverworldWildSpecies[slot], sOverworldWildLevel[slot]);
    }
    RemoveObjectEvent(&gObjectEvents[objectEventId]);
    sOverworldWildActive[slot] = FALSE;
    sOverworldWildIsDexNav[slot] = FALSE;
    sOverworldWildSpecies[slot] = SPECIES_NONE;
    sOverworldWildLevel[slot] = 0;
    sOverworldWildPotential[slot] = 0;
    sOverworldWildAbilityNum[slot] = 0;
    sOverworldWildHeldItem[slot] = ITEM_NONE;
    for (u8 i = 0; i < MAX_MON_MOVES; i++)
        sOverworldWildMoves[slot][i] = MOVE_NONE;
    BattleSetup_StartWildBattle();
    return TRUE;
}
