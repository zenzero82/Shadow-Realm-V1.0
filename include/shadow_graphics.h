#ifndef GUARD_SHADOW_GRAPHICS_H
#define GUARD_SHADOW_GRAPHICS_H

#include "global.h"
#include "constants/pokemon_icon.h"

struct ShadowGraphicsOverride
{
    u16 species;
    const u32 *frontPic;
    const u32 *backPic;
#if P_GENDER_DIFFERENCES
    const u32 *frontPicFemale;
    const u32 *backPicFemale;
#endif
    const u16 *palette;
    const u16 *iconPalette;
    u16 iconPaletteTag;
    const u8 *icon;
#if P_GENDER_DIFFERENCES
    const u16 *iconPaletteFemale;
    u16 iconPaletteTagFemale;
    const u8 *iconFemale;
#endif
};

const struct ShadowGraphicsOverride *GetShadowGraphicsOverride(u16 species);
const u32 *GetShadowMonPic(u16 species, u32 personality, bool8 isFrontPic);
const u16 *GetShadowMonPalette(u16 species);
const u16 *GetShadowMonIconPalette(u16 species, u32 personality);
u16 GetShadowMonIconPaletteTag(u16 species, u32 personality);
const u8 *GetShadowMonIcon(u16 species, u32 personality);

#endif // GUARD_SHADOW_GRAPHICS_H
