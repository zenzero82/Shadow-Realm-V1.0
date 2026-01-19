#include "global.h"
#include "pokemon.h"
#include "shadow_graphics.h"
#include "data/graphics/shadow_forms.h"


static const struct ShadowGraphicsOverride sShadowGraphicsTable[] =
{
#include "data/graphics/shadow_forms_table.inc"
};

const struct ShadowGraphicsOverride *GetShadowGraphicsOverride(u16 species)
{
    species = SanitizeSpeciesId(species);
    for (int i = 0; i < ARRAY_COUNT(sShadowGraphicsTable); i++)
    {
        if (sShadowGraphicsTable[i].species == species)
            return &sShadowGraphicsTable[i];
    }

    return NULL;
}

const u32 *GetShadowMonPic(u16 species, u32 personality, bool8 isFrontPic)
{
    const struct ShadowGraphicsOverride *override = GetShadowGraphicsOverride(species);
    if (override == NULL)
        return NULL;

#if P_GENDER_DIFFERENCES
    if (IsPersonalityFemale(species, personality))
    {
        const u32 *femaleSrc = isFrontPic ? override->frontPicFemale : override->backPicFemale;
        if (femaleSrc != NULL)
            return femaleSrc;
    }
#endif

    return isFrontPic ? override->frontPic : override->backPic;
}

const u16 *GetShadowMonPalette(u16 species)
{
    const struct ShadowGraphicsOverride *override = GetShadowGraphicsOverride(species);
    return override ? override->palette : NULL;
}

const u8 *GetShadowMonIcon(u16 species, u32 personality)
{
    const struct ShadowGraphicsOverride *override = GetShadowGraphicsOverride(species);
    if (override == NULL)
        return NULL;

#if P_GENDER_DIFFERENCES
    if (IsPersonalityFemale(species, personality) && override->iconFemale != NULL)
        return override->iconFemale;
#endif

    return override->icon;
}
