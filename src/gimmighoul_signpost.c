#include "global.h"
#include "gimmighoul_signpost.h"
#include "constants/map_types.h"
#include "constants/maps.h"

struct GimmighoulSignpostInfo gLastSignpost = {0};

#include "data/gimmighoul_signposts.h"

static bool8 IsGimmighoulMapTypeAllowed(u8 mapType)
{
    switch (mapType)
    {
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_UNDERGROUND:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool8 IsGimmighoulMapExcluded(u8 mapGroup, u8 mapNum)
{
    if (mapGroup == MAP_GROUP(MAP_PALLET_TOWN) && mapNum == MAP_NUM(MAP_PALLET_TOWN))
        return TRUE;
    if (mapGroup == MAP_GROUP(MAP_ROUTE1) && mapNum == MAP_NUM(MAP_ROUTE1))
        return TRUE;
    if (mapGroup == MAP_GROUP(MAP_ROUTE2) && mapNum == MAP_NUM(MAP_ROUTE2))
        return TRUE;
    if (mapGroup == MAP_GROUP(MAP_VIRIDIAN_FOREST) && mapNum == MAP_NUM(MAP_VIRIDIAN_FOREST))
        return TRUE;
    if (mapGroup == MAP_GROUP(MAP_VIRIDIAN_CITY) && mapNum == MAP_NUM(MAP_VIRIDIAN_CITY))
        return TRUE;

    return FALSE;
}

static bool8 TryGetGimmighoulSignpostIndex(u8 mapGroup, u8 mapNum, u16 x, u16 y, u16 *outIndex)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(gGimmighoulSignposts); i++)
    {
        if (gGimmighoulSignposts[i].mapGroup == mapGroup
         && gGimmighoulSignposts[i].mapNum == mapNum
         && gGimmighoulSignposts[i].x == x
         && gGimmighoulSignposts[i].y == y)
        {
            *outIndex = i;
            return TRUE;
        }
    }

    return FALSE;
}

bool8 GimmighoulSignpost_IsTracked(u8 mapGroup, u8 mapNum, u16 x, u16 y)
{
    u16 index;

    return TryGetGimmighoulSignpostIndex(mapGroup, mapNum, x, y, &index);
}

static bool8 GimmighoulSignpost_HasUsed(u16 index)
{
    u16 byte = index / 8;
    u8 bit = index % 8;

    if (byte >= GIMMIGHOUL_SIGNPOST_FLAGS_BYTES)
        return TRUE;

    if (gSaveBlock3Ptr->gimmighoulSignpostInit != GIMMIGHOUL_SIGNPOST_INIT_VALUE)
    {
        memset(gSaveBlock3Ptr->gimmighoulSignpostFlags, 0, sizeof(gSaveBlock3Ptr->gimmighoulSignpostFlags));
        gSaveBlock3Ptr->gimmighoulSignpostInit = GIMMIGHOUL_SIGNPOST_INIT_VALUE;
    }

    return (gSaveBlock3Ptr->gimmighoulSignpostFlags[byte] & (1 << bit)) != 0;
}

bool8 GimmighoulSignpost_ShouldTrigger(u8 mapGroup, u8 mapNum, u16 x, u16 y, u16 *outIndex)
{
    u16 index;

    if (!IsGimmighoulMapTypeAllowed(gMapHeader.mapType))
        return FALSE;
    if (IsGimmighoulMapExcluded(mapGroup, mapNum))
        return FALSE;
    if (!TryGetGimmighoulSignpostIndex(mapGroup, mapNum, x, y, &index))
        return FALSE;
    if (GimmighoulSignpost_HasUsed(index))
        return FALSE;

    if (outIndex != NULL)
        *outIndex = index;
    return TRUE;
}

bool8 GimmighoulSignpost_HasAnyUsedOnMap(u8 mapGroup, u8 mapNum)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(gGimmighoulSignposts); i++)
    {
        if (gGimmighoulSignposts[i].mapGroup == mapGroup
         && gGimmighoulSignposts[i].mapNum == mapNum
         && GimmighoulSignpost_HasUsed(i))
            return TRUE;
    }

    return FALSE;
}

void GimmighoulSignpost_MarkUsed(u16 index)
{
    u16 byte = index / 8;
    u8 bit = index % 8;

    if (byte >= GIMMIGHOUL_SIGNPOST_FLAGS_BYTES)
        return;

    if (gSaveBlock3Ptr->gimmighoulSignpostInit != GIMMIGHOUL_SIGNPOST_INIT_VALUE)
    {
        memset(gSaveBlock3Ptr->gimmighoulSignpostFlags, 0, sizeof(gSaveBlock3Ptr->gimmighoulSignpostFlags));
        gSaveBlock3Ptr->gimmighoulSignpostInit = GIMMIGHOUL_SIGNPOST_INIT_VALUE;
    }

    gSaveBlock3Ptr->gimmighoulSignpostFlags[byte] |= (1 << bit);
}
