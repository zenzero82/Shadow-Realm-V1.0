#ifndef GUARD_ROAMING_SHADOW_HUNTER_H
#define GUARD_ROAMING_SHADOW_HUNTER_H

#include "gba/gba.h"
#include "constants/regions.h"

#define ROAMING_SHADOW_QUEUE_SIZE 8
#define ROAMING_SHADOW_HUNTER_REGION_COUNT 3

enum HunterId
{
    HUNTER_CASSIDY,
    HUNTER_BUTCH,
    HUNTER_SILVER,
    HUNTER_HEX_1,
    HUNTER_HEX_2,
    HUNTER_HEX_3,
    HUNTER_HEX_4,
    HUNTER_HEX_5,
    HUNTER_HEX_6,
    HUNTER_COUNT
};

struct HunterSpawnPoint
{
    u16 mapGroup;
    u16 mapNum;
    s16 x;
    s16 y;
};

struct MissedShadowEntry
{
    u16 species;
    u16 shadowId;
    u8 level;
    u8 region;
    u8 resolved;
    u8 padding;
};

struct ActiveHunterState
{
    u8 active;
    u8 region;
    u8 hunterId;
    u16 species;
    u16 shadowId;
    u8 level;
    u16 mapGroup;
    u16 mapNum;
    s16 x;
    s16 y;
};

struct RoamingShadowHunterSave
{
    struct MissedShadowEntry queue[ROAMING_SHADOW_HUNTER_REGION_COUNT][ROAMING_SHADOW_QUEUE_SIZE];
    u8 queueHead[ROAMING_SHADOW_HUNTER_REGION_COUNT];
    u8 queueCount[ROAMING_SHADOW_HUNTER_REGION_COUNT];
    u8 mapLoadCounter[ROAMING_SHADOW_HUNTER_REGION_COUNT];
    struct ActiveHunterState active[ROAMING_SHADOW_HUNTER_REGION_COUNT];
    u8 legacyScanDone;
    u8 legacyScanMagic[3];
};

struct Pokemon;

void RoamingHunter_OnShadowSnagFailed(u16 species, u8 level, u8 region, u16 shadowId);
u16 RoamingHunter_TryCreateNpcOnMap(void);
u16 RoamingHunter_TryConsumeAlert(void);
u16 RoamingHunter_StartBattle(void);
u16 RoamingHunter_OnBattleWon(void);
void RoamingHunter_TryOverrideTrainerParty(u16 trainerId, struct Pokemon *party);
void RoamingHunter_OnMapTransition(void);
void RoamingHunter_PrepareMapLoad(u8 mapGroup, u8 mapNum);

bool8 RoamingHunter_IsUnlocked(void);
const struct ActiveHunterState *RoamingHunter_GetActiveForRegion(u8 region);

#endif // GUARD_ROAMING_SHADOW_HUNTER_H
