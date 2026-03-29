#ifndef GUARD_SURF_OW_H
#define GUARD_SURF_OW_H

#include "global.h"
#include "sprite.h"

struct SurfOwEntry
{
    u16 species;
    const u16 *palette;
    const u16 *shinyPalette;
    const struct SpriteTemplate *baseTemplate;
    const struct SpriteTemplate *overlayTemplate;
};

bool8 SurfOw_HasSpeciesEntry(u16 species);
const struct SurfOwEntry *SurfOw_GetEntry(u16 species);
bool8 SurfOw_IsSpeciesEligible(u16 species);
bool8 SurfOw_CacheCurrentFromFieldMoveMonInfo(u8 objEventId);
void SurfOw_ClearCurrent(void);
const struct SurfOwEntry *SurfOw_GetCurrentEntry(void);
bool8 SurfOw_CurrentIsShiny(void);
bool8 SurfOw_IsCurrentActiveForObjectEvent(u8 objEventId);
bool8 SurfOw_ShouldOverridePlayerPriority(u8 objEventId);
bool8 SurfOw_CreateSpritePair(u8 objEventId, s16 x, s16 y, u8 subpriority, u8 *outSpriteId);
void SurfOw_DestroySprites(u8 baseSpriteId);

#endif // GUARD_SURF_OW_H
