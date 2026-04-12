#ifndef GUARD_GIMMIGHOUL_SIGNPOST_H
#define GUARD_GIMMIGHOUL_SIGNPOST_H

#include "constants/gimmighoul_signpost.h"

struct GimmighoulSignpostInfo
{
    u8 mapGroup;
    u8 mapNum;
    u16 x;
    u16 y;
};

struct GimmighoulSignpost
{
    u8 mapGroup;
    u8 mapNum;
    u16 x;
    u16 y;
};

extern struct GimmighoulSignpostInfo gLastSignpost;
extern const struct GimmighoulSignpost gGimmighoulSignposts[];

bool8 GimmighoulSignpost_IsTracked(u8 mapGroup, u8 mapNum, u16 x, u16 y);
bool8 GimmighoulSignpost_ShouldTrigger(u8 mapGroup, u8 mapNum, u16 x, u16 y, u16 *outIndex);
void GimmighoulSignpost_MarkUsed(u16 index);

#endif // GUARD_GIMMIGHOUL_SIGNPOST_H
