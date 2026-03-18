#include "global.h"
#include "overworld_wild_encounters.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "random.h"
#include "wild_encounter.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/global.h"
#include "constants/trainer_types.h"

#define OVERWORLD_WILD_SPAWN_TRIES 50
#define OVERWORLD_WILD_SPAWN_RADIUS 4
#define OVERWORLD_WILD_MIN_DISTANCE 1
#define OVERWORLD_WILD_MOVEMENT_RANGE 2

EWRAM_DATA static bool8 sOverworldWildActive[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u16 sOverworldWildSpecies[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];
EWRAM_DATA static u8 sOverworldWildLevel[OBJ_EVENT_ID_OVERWORLD_WILD_COUNT];

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

static bool8 OverworldWildEncounters_IsSpawnTileValid(s16 x, s16 y, u8 elevation)
{
    u8 behavior = MapGridGetMetatileBehaviorAt(x, y);

    if (!MetatileBehavior_IsLandWildEncounter(behavior))
        return FALSE;
    if (MapGridGetCollisionAt(x, y))
        return FALSE;
    if (GetObjectEventIdByPosition(x, y, elevation) != OBJECT_EVENTS_COUNT)
        return FALSE;
    if (IsElevationMismatchAt(elevation, x, y))
        return FALSE;

    return TRUE;
}

static bool8 OverworldWildEncounters_FindSpawnCoords(s16 *xOut, s16 *yOut, u8 *elevationOut)
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
        if (dx + dy < OVERWORLD_WILD_MIN_DISTANCE)
            continue;

        if (!OverworldWildEncounters_IsSpawnTileValid(x, y, elevation))
            continue;

        *xOut = x;
        *yOut = y;
        *elevationOut = MapGridGetElevationAt(x, y);
        return TRUE;
    }

    return FALSE;
}

static bool8 OverworldWildEncounters_Spawn(u8 slot, u16 species, u8 level, s16 x, s16 y, u8 elevation)
{
    struct ObjectEventTemplate objectEventTemplate = {0};

    if (slot >= OBJ_EVENT_ID_OVERWORLD_WILD_COUNT)
        return FALSE;

    objectEventTemplate.localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
    objectEventTemplate.graphicsId = species + OBJ_EVENT_MON;
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
        return TRUE;
    }

    return FALSE;
}

void OverworldWildEncounters_TrySpawn(void)
{
    s16 x;
    s16 y;
    u8 elevation;
    u16 species;
    u8 level;

    if (!OverworldWildEncounters_Enabled())
        return;
    if (FlagGet(OW_FLAG_NO_ENCOUNTER))
        return;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        return;
    if (MapHasNoEncounterData())
        return;
    for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        u8 localId = OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot;
        if (sOverworldWildActive[slot])
        {
            if (GetObjectEventIdByLocalId(localId) != OBJECT_EVENTS_COUNT)
                continue;
            sOverworldWildActive[slot] = FALSE;
        }

        if (!OverworldWildEncounters_GetLandWildMon(&species, &level))
            return;
        if (!OverworldWildEncounters_FindSpawnCoords(&x, &y, &elevation))
            return;

        OverworldWildEncounters_Spawn(slot, species, level, x, y, elevation);
    }
}

void OverworldWildEncounters_OnMapLoad(void)
{
    for (u8 slot = 0; slot < OBJ_EVENT_ID_OVERWORLD_WILD_COUNT; slot++)
    {
        sOverworldWildActive[slot] = FALSE;
        sOverworldWildSpecies[slot] = SPECIES_NONE;
        sOverworldWildLevel[slot] = 0;
        RemoveObjectEventByLocalIdAndMap(OBJ_EVENT_ID_OVERWORLD_WILD_BASE + slot, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
    OverworldWildEncounters_TrySpawn();
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
    CreateWildMon(sOverworldWildSpecies[slot], sOverworldWildLevel[slot]);
    RemoveObjectEvent(&gObjectEvents[objectEventId]);
    sOverworldWildActive[slot] = FALSE;
    BattleSetup_StartWildBattle();
    return TRUE;
}
