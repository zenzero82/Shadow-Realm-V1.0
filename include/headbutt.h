#ifndef GUARD_HEADBUTT_H
#define GUARD_HEADBUTT_H

#include "constants/headbutt.h"
#include "wild_encounter.h"

struct HeadbuttEncounterTable
{
    const struct WildPokemon *wildMonsInfo[TIMES_OF_DAY_COUNT];
};

struct HeadbuttTreeData
{
    u16 treeId;
    u8 mapGroup;
    u8 mapNum;
    s16 x;
    s16 y;
    u16 primaryApricorn;
    const u16 *assortedPool;
    u8 assortedPoolCount;
    u8 encounterTableId;
    u8 cooldownDays;
};

u16 Special_HeadbuttTree(void);
u16 Special_HeadbuttTree_StartBattle(void);

#endif // GUARD_HEADBUTT_H
