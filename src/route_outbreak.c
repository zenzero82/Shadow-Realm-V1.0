#include "global.h"
#include "daycare.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "route_outbreak.h"
#include "rtc.h"
#include "string_util.h"
#include "constants/abilities.h"
#include "constants/map_groups.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/species.h"

#define ROUTE_OUTBREAK_MARKER         0xA5
#define ROUTE_OUTBREAK_BONUS_CHANCE   35
#define ROUTE_OUTBREAK_PROBABILITY    50
#define ROUTE_OUTBREAK_DURATION_DAYS  1

enum
{
    ROUTE_REGION_KANTO,
    ROUTE_REGION_JOHTO,
};

struct RouteOutbreakData
{
    u16 mapSec;
    u16 mapId;
    u16 species;
    u8 level;
    u16 moves[MAX_MON_MOVES];
};

static const struct RouteOutbreakData sKantoOutbreaks[] =
{
    {
        .mapSec = MAPSEC_ROUTE_2,
        .mapId = MAP_ROUTE2,
        .species = SPECIES_GRUBBIN,
        .level = 7,
        .moves = { MOVE_BUG_BITE, MOVE_VISE_GRIP, MOVE_MUD_SLAP, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_5,
        .mapId = MAP_ROUTE5,
        .species = SPECIES_MINCCINO,
        .level = 13,
        .moves = { MOVE_TAIL_SLAP, MOVE_TICKLE, MOVE_ECHOED_VOICE, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_12,
        .mapId = MAP_ROUTE12,
        .species = SPECIES_VENIPEDE,
        .level = 23,
        .moves = { MOVE_BUG_BITE, MOVE_POISON_TAIL, MOVE_DEFENSE_CURL, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_16,
        .mapId = MAP_ROUTE16,
        .species = SPECIES_SCRAGGY,
        .level = 41,
        .moves = { MOVE_CHIP_AWAY, MOVE_HEADBUTT, MOVE_LOW_KICK, MOVE_NONE },
    },
};

static const struct RouteOutbreakData sJohtoOutbreaks[] =
{
    {
        .mapSec = MAPSEC_ROUTE_26,
        .mapId = MAP_ROUTE26,
        .species = SPECIES_PANCHAM,
        .level = 35,
        .moves = { MOVE_VITAL_THROW, MOVE_WORK_UP, MOVE_CIRCLE_THROW, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_27,
        .mapId = MAP_ROUTE27,
        .species = SPECIES_LUXIO,
        .level = 34,
        .moves = { MOVE_SPARK, MOVE_BITE, MOVE_BABY_DOLL_EYES, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_28,
        .mapId = MAP_ROUTE28,
        .species = SPECIES_ZOROARK,
        .level = 75,
        .moves = { MOVE_NIGHT_DAZE, MOVE_TAUNT, MOVE_U_TURN, MOVE_NONE },
    },
    {
        .mapSec = MAPSEC_ROUTE_39,
        .mapId = MAP_ROUTE39,
        .species = SPECIES_MILTANK,
        .level = 30,
        .moves = { MOVE_MILK_DRINK, MOVE_STOMP, MOVE_BODY_SLAM, MOVE_NONE },
    },
};

static u32 GetWeeklySeed(u8 region)
{
    return (gLocalTime.days / 7) * 1103515245u + 12345u + region * 977u;
}

static void BuildWeekdayOrder(u8 region, u8 weekdays[WEEKDAY_COUNT])
{
    u32 seed = GetWeeklySeed(region);
    s32 i;

    for (i = 0; i < WEEKDAY_COUNT; i++)
        weekdays[i] = i;

    for (i = WEEKDAY_COUNT - 1; i > 0; i--)
    {
        u32 j;
        u8 temp;

        seed = seed * 1103515245u + 12345u;
        j = seed % (i + 1);
        temp = weekdays[i];
        weekdays[i] = weekdays[j];
        weekdays[j] = temp;
    }
}

static const struct RouteOutbreakData *GetRouteOutbreakSet(u8 region, u32 *count)
{
    switch (region)
    {
    case ROUTE_REGION_KANTO:
        *count = ARRAY_COUNT(sKantoOutbreaks);
        return sKantoOutbreaks;
    case ROUTE_REGION_JOHTO:
        *count = ARRAY_COUNT(sJohtoOutbreaks);
        return sJohtoOutbreaks;
    default:
        *count = 0;
        return NULL;
    }
}

static bool32 TryGetSupportedRegion(u16 mapSec, u8 *region)
{
    switch (mapSec)
    {
    case MAPSEC_ROUTE_2:
    case MAPSEC_ROUTE_5:
    case MAPSEC_ROUTE_12:
    case MAPSEC_ROUTE_16:
        *region = ROUTE_REGION_KANTO;
        return TRUE;
    case MAPSEC_ROUTE_26:
    case MAPSEC_ROUTE_27:
    case MAPSEC_ROUTE_28:
    case MAPSEC_ROUTE_39:
        *region = ROUTE_REGION_JOHTO;
        return TRUE;
    default:
        return FALSE;
    }
}

static const struct RouteOutbreakData *TryGetTodaysBroadcast(u16 mapSec)
{
    const struct RouteOutbreakData *outbreaks;
    u8 region;
    u8 weekdayOrder[WEEKDAY_COUNT];
    u8 today = GetDayOfWeek();
    u32 outbreakCount;
    u32 i;

    if (!TryGetSupportedRegion(mapSec, &region))
        return NULL;

    outbreaks = GetRouteOutbreakSet(region, &outbreakCount);
    if (outbreaks == NULL || outbreakCount == 0)
        return NULL;

    BuildWeekdayOrder(region, weekdayOrder);
    for (i = 0; i < outbreakCount; i++)
    {
        u32 outbreakIndex;

        if (weekdayOrder[i] != today)
            continue;

        outbreakIndex = (i + (gLocalTime.days / 7)) % outbreakCount;
        if (outbreaks[outbreakIndex].mapSec == mapSec)
            return &outbreaks[outbreakIndex];
        break;
    }

    return NULL;
}

static void StartRouteOutbreak(const struct RouteOutbreakData *outbreak)
{
    u32 i;

    gSaveBlock1Ptr->outbreakPokemonSpecies = outbreak->species;
    gSaveBlock1Ptr->outbreakLocationMapNum = MAP_NUM(outbreak->mapId);
    gSaveBlock1Ptr->outbreakLocationMapGroup = MAP_GROUP(outbreak->mapId);
    gSaveBlock1Ptr->outbreakPokemonLevel = outbreak->level;
    gSaveBlock1Ptr->outbreakUnused1 = ROUTE_OUTBREAK_MARKER;
    gSaveBlock1Ptr->outbreakUnused2 = 0;
    gSaveBlock1Ptr->outbreakUnused3 = 0;
    gSaveBlock1Ptr->outbreakPokemonProbability = ROUTE_OUTBREAK_PROBABILITY;
    gSaveBlock1Ptr->outbreakDaysLeft = ROUTE_OUTBREAK_DURATION_DAYS;

    for (i = 0; i < MAX_MON_MOVES; i++)
        gSaveBlock1Ptr->outbreakPokemonMoves[i] = outbreak->moves[i];
}

void RouteHouse_TV_TryStartBroadcast(void)
{
    const struct RouteOutbreakData *outbreak = TryGetTodaysBroadcast(gMapHeader.regionMapSectionId);

    gSpecialVar_Result = FALSE;
    if (outbreak == NULL)
        return;

    StringCopy(gStringVar1, GetSpeciesName(outbreak->species));
    GetMapName(gStringVar2, outbreak->mapSec, 0);
    StartRouteOutbreak(outbreak);
    gSpecialVar_Result = TRUE;
}

u32 RouteOutbreak_ModifyShinyThreshold(u16 species, u32 shinyThreshold)
{
    if (gSaveBlock1Ptr->outbreakUnused1 == ROUTE_OUTBREAK_MARKER
     && gSaveBlock1Ptr->outbreakPokemonSpecies == species
     && shinyThreshold < (SHINY_ODDS << (OPTIONS_SHINY_ODDS_COUNT - 1)))
        shinyThreshold <<= 1;

    return shinyThreshold;
}

void RouteOutbreak_ApplyEncounterBonuses(struct Pokemon *mon)
{
    u16 species;
    u16 eggMoves[EGG_MOVES_ARRAY_COUNT];
    u8 abilityNum = 2;
    u8 numEggMoves;

    if (gSaveBlock1Ptr->outbreakUnused1 != ROUTE_OUTBREAK_MARKER)
        return;

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    if (species != gSaveBlock1Ptr->outbreakPokemonSpecies)
        return;

    if (gSpeciesInfo[species].abilities[abilityNum] != ABILITY_NONE
     && Random() % 100 < ROUTE_OUTBREAK_BONUS_CHANCE)
        SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);

    if (Random() % 100 < ROUTE_OUTBREAK_BONUS_CHANCE)
    {
        numEggMoves = GetEggMoves(mon, eggMoves);
        if (numEggMoves != 0)
            SetMonMoveSlot(mon, eggMoves[Random() % numEggMoves], 0);
    }
}
