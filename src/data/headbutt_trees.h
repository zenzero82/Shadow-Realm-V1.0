#include "headbutt.h"
#include "constants/items.h"

static const u16 sHeadbuttApricornPool_Default[] =
{
    ITEM_RED_APRICORN,
    ITEM_BLUE_APRICORN,
    ITEM_YELLOW_APRICORN,
    ITEM_GREEN_APRICORN,
    ITEM_WHITE_APRICORN,
    ITEM_PINK_APRICORN,
    ITEM_BLACK_APRICORN,
};

static const struct HeadbuttTreeData gHeadbuttTreeDefault =
{
    .treeId = HEADBUTT_TREE_ID_NONE,
    .mapGroup = 0xFF,
    .mapNum = 0xFF,
    .x = 0,
    .y = 0,
    .primaryApricorn = ITEM_RED_APRICORN,
    .assortedPool = sHeadbuttApricornPool_Default,
    .assortedPoolCount = ARRAY_COUNT(sHeadbuttApricornPool_Default),
    .encounterTableId = 0,
    .cooldownDays = 1,
};

static const struct HeadbuttTreeData gHeadbuttTrees[] =
{
    {
        .treeId = HEADBUTT_TREE_ID_NONE,
        .mapGroup = 0xFF,
        .mapNum = 0xFF,
        .x = 0,
        .y = 0,
        .primaryApricorn = ITEM_RED_APRICORN,
        .assortedPool = sHeadbuttApricornPool_Default,
        .assortedPoolCount = ARRAY_COUNT(sHeadbuttApricornPool_Default),
        .encounterTableId = 0,
        .cooldownDays = 1,
    },
};
