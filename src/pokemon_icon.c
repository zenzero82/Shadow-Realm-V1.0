#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_icon.h"
#include "shadow_graphics.h"
#include "sprite.h"
#include "data.h"
#include "constants/pokemon_icon.h"

#if P_GENDER_DIFFERENCES
#if P_CUSTOM_GENDER_DIFF_ICONS
extern const u8 gMonIcon_PikachuFShadow[];
#endif
#endif
extern const u8 gMonIcon_PikachuShadow[];

#define MON_ICON_BASE_PALETTE_COUNT (POKE_ICON_SHADOW_PAL_TAG - POKE_ICON_BASE_PAL_TAG)
#define SHINY_ICON_TONE_R 450
#define SHINY_ICON_TONE_G 390
#define SHINY_ICON_TONE_B 120

static u16 sShinyIconPaletteBuffers[MON_ICON_BASE_PALETTE_COUNT][16];
static u16 sGiftAuraIconPaletteBuffers[MON_ICON_BASE_PALETTE_COUNT][16];

extern const u16 gMonPalette_RioluGiftAura[];
extern const u16 gMonPalette_LucarioGiftAura[];
extern const u16 gMonPalette_LucarioMegaGiftAura[];
extern const u16 gMonIconPalette_RioluGiftAura[];
extern const u8 gMonIcon_RioluGiftAura[];

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);
static const u16 *GetGiftAuraIconPalette(u16 species, u32 personality, bool8 isShiny);
static u16 GetDedicatedShadowIconPaletteTag(u16 species);

const struct SpritePalette gMonIconPaletteTable[] __attribute__((used)) __attribute__((section(".rodata"))) =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

// Ensure the table’s section is kept by referencing it from read-only data.
const struct SpritePalette *const gMonIconPaletteTableRef __attribute__((used)) = gMonIconPaletteTable;

static u8 GetIconPaletteIndexForSpeciesAndPersonality(u16 species, u32 personality)
{
    species = SanitizeSpeciesId(species);
#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
        return gSpeciesInfo[species].iconPalIndexFemale;
#endif
    return gSpeciesInfo[species].iconPalIndex;
}

bool8 LoadMonIconPaletteShadowPersonality(u16 species, u32 personality, u16 *paletteTag)
{
    const u16 *palette = GetShadowMonIconPalette(species, personality);
    struct SpritePalette spritePalette;
    u8 slot;
    u8 palIndex = GetIconPaletteIndexForSpeciesAndPersonality(species, personality);
    bool8 hasShadowPalette = (palette != NULL);
    u16 tag = GetShadowMonIconPaletteTag(species, personality);

    if (palIndex >= MON_ICON_BASE_PALETTE_COUNT)
        palIndex = 0;

    if (palette == NULL)
        palette = gMonIconPalette_Shadow;

    if (tag == TAG_NONE)
        tag = GetDedicatedShadowIconPaletteTag(species);

    if (tag == TAG_NONE)
        tag = POKE_ICON_SHADOW_PAL_TAG + palIndex;

    spritePalette.data = palette;
    spritePalette.tag = tag;
    slot = IndexOfSpritePaletteTag(tag);
    if (slot == 0xFF)
        LoadSpritePalette(&spritePalette);
    else
        LoadPalette(spritePalette.data, OBJ_PLTT_ID(slot), PLTT_SIZE_4BPP);

    if (paletteTag != NULL)
        *paletteTag = tag;
    return hasShadowPalette;
}

bool8 LoadMonIconPaletteGiftAuraPersonality(u16 species, u32 personality, bool8 isShiny, u16 *paletteTag)
{
    const u16 *palette = GetGiftAuraIconPalette(species, personality, isShiny);
    struct SpritePalette spritePalette;
    u8 slot;
    u8 palIndex = GetIconPaletteIndexForSpeciesAndPersonality(species, personality);
    u16 tag;

    if (palette == NULL)
        return FALSE;

    if (palIndex >= MON_ICON_BASE_PALETTE_COUNT)
        palIndex = 0;

    memcpy(sGiftAuraIconPaletteBuffers[palIndex], palette, sizeof(sGiftAuraIconPaletteBuffers[palIndex]));

    tag = POKE_ICON_GIFT_AURA_PAL_TAG + palIndex;
    spritePalette.data = sGiftAuraIconPaletteBuffers[palIndex];
    spritePalette.tag = tag;
    slot = IndexOfSpritePaletteTag(tag);
    if (slot == 0xFF)
        LoadSpritePalette(&spritePalette);
    else
        LoadSpritePaletteInSlot(&spritePalette, slot);

    if (paletteTag != NULL)
        *paletteTag = tag;
    return TRUE;
}

void LoadMonIconPaletteShinyByIndex(u8 palIndex)
{
    struct SpritePalette palette;
    u8 slot;

    if (palIndex >= MON_ICON_BASE_PALETTE_COUNT)
        palIndex = 0;

    memcpy(sShinyIconPaletteBuffers[palIndex], gMonIconPalettes[palIndex], sizeof(sShinyIconPaletteBuffers[palIndex]));
    TintPalette_CustomTone(sShinyIconPaletteBuffers[palIndex], 16, SHINY_ICON_TONE_R, SHINY_ICON_TONE_G, SHINY_ICON_TONE_B);

    palette.data = sShinyIconPaletteBuffers[palIndex];
    palette.tag = POKE_ICON_SHINY_PAL_TAG + palIndex;

    slot = IndexOfSpritePaletteTag(palette.tag);
    if (slot == 0xFF)
        LoadSpritePalette(&palette);
    else
        LoadSpritePaletteInSlot(&palette, slot);
}

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool8 isShiny, bool8 isShadow)
{
    u8 spriteId;
    u16 sanitizedSpecies = SanitizeSpeciesId(species);
    u16 iconSpecies = GetIconSpecies(species, personality);
    u16 shadowPaletteTag = POKE_ICON_SHADOW_PAL_TAG;
    u16 giftAuraPaletteTag = POKE_ICON_GIFT_AURA_PAL_TAG;
    const struct ShadowGraphicsOverride *shadow = GetShadowGraphicsOverride(iconSpecies);
    bool8 useShadowIcon = isShadow && shadow != NULL && shadow->icon != NULL;
    bool8 hasGiftAuraPalette = FALSE;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconTiles_ShadowAware(species, personality, useShadowIcon),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
    };

    if (isShadow)
        LoadMonIconPaletteShadowPersonality(iconSpecies, personality, &shadowPaletteTag);
    else if (IsGiftAuraPersonality(personality))
        hasGiftAuraPalette = LoadMonIconPaletteGiftAuraPersonality(iconSpecies, personality, isShiny, &giftAuraPaletteTag);

    if (isShadow)
    {
        iconTemplate.paletteTag = shadowPaletteTag;
    }
    else if (hasGiftAuraPalette)
    {
        iconTemplate.paletteTag = giftAuraPaletteTag;
    }
    else
    {
        u8 palIndex = gSpeciesInfo[sanitizedSpecies].iconPalIndex;

        if (sanitizedSpecies > NUM_SPECIES)
            palIndex = 0;
#if P_GENDER_DIFFERENCES
        else if (gSpeciesInfo[sanitizedSpecies].iconSpriteFemale != NULL && IsPersonalityFemale(sanitizedSpecies, personality))
            palIndex = gSpeciesInfo[sanitizedSpecies].iconPalIndexFemale;
#endif

        if (isShiny)
        {
            LoadMonIconPaletteShinyByIndex(palIndex);
            iconTemplate.paletteTag = POKE_ICON_SHINY_PAL_TAG + palIndex;
        }
        else
        {
            iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG + palIndex;
        }
    }

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}


u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gSpeciesInfo[species].iconPalIndex,
    };

    iconTemplate.image = GetMonIconTiles(species, 0);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    species = SanitizeSpeciesId(species);
    if (species == SPECIES_UNOWN)
        species = GetUnownSpeciesId(personality);
    return species;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return GET_UNOWN_LETTER(personality);
}

u16 GetIconSpeciesNoPersonality(u16 species)
{
    species = SanitizeSpeciesId(species);

    if (MailSpeciesToSpecies(species, &species) == SPECIES_UNOWN)
        return species += SPECIES_UNOWN_B; // TODO
    return GetIconSpecies(species, 0);
}

const u8 *GetMonIconPtr(u16 species, u32 personality)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), personality);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalettePersonality(u16 species, u32 personality)
{
    u8 palIndex;
    species = SanitizeSpeciesId(species);
#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
        palIndex = gSpeciesInfo[species].iconPalIndexFemale;
    else
#endif
        palIndex = gSpeciesInfo[species].iconPalIndex;
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
    for (i = 0; i < MON_ICON_BASE_PALETTE_COUNT; i++)
        FreeSpritePaletteByTag(POKE_ICON_SHADOW_PAL_TAG + i);
    for (i = 0; i < MON_ICON_BASE_PALETTE_COUNT; i++)
        FreeSpritePaletteByTag(POKE_ICON_SHINY_PAL_TAG + i);
    for (i = 0; i < MON_ICON_BASE_PALETTE_COUNT; i++)
        FreeSpritePaletteByTag(POKE_ICON_GIFT_AURA_PAL_TAG + i);
    for (i = 0; i < POKE_ICON_SHADOW_UNIQUE_PAL_TAG_COUNT; i++)
        FreeSpritePaletteByTag(POKE_ICON_SHADOW_UNIQUE_PAL_TAG_START + i);
    FreeSpritePaletteByTag(POKE_ICON_SHADOW_MEOWTH_PAL_TAG);
    FreeSpritePaletteByTag(POKE_ICON_SHADOW_MIMIKYU_PAL_TAG);
    FreeSpritePaletteByTag(POKE_ICON_SHADOW_PANGORO_PAL_TAG);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
    FreeSpritePaletteByTag(POKE_ICON_SHINY_PAL_TAG + palIndex);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    u16 dedicatedShadowTag = GetDedicatedShadowIconPaletteTag(species);
    palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
    FreeSpritePaletteByTag(POKE_ICON_SHINY_PAL_TAG + palIndex);
    FreeSpritePaletteByTag(POKE_ICON_GIFT_AURA_PAL_TAG + palIndex);
    if (dedicatedShadowTag != TAG_NONE)
        FreeSpritePaletteByTag(dedicatedShadowTag);
}

static const u16 *GetGiftAuraIconPalette(u16 species, u32 personality, bool8 isShiny)
{
    if (isShiny || !IsGiftAuraPersonality(personality))
        return NULL;

    switch (SanitizeSpeciesId(species))
    {
    case SPECIES_RIOLU:
        return gMonIconPalette_RioluGiftAura;
    case SPECIES_LUCARIO:
        return gMonPalette_LucarioGiftAura;
    case SPECIES_LUCARIO_MEGA:
        return gMonPalette_LucarioMegaGiftAura;
    default:
        return NULL;
    }
}

static u16 GetDedicatedShadowIconPaletteTag(u16 species)
{
    switch (SanitizeSpeciesId(species))
    {
    case SPECIES_MEOWTH:
        return POKE_ICON_SHADOW_MEOWTH_PAL_TAG;
    case SPECIES_MIMIKYU:
    case SPECIES_MIMIKYU_BUSTED:
        return POKE_ICON_SHADOW_MIMIKYU_PAL_TAG;
    case SPECIES_PANGORO:
        return POKE_ICON_SHADOW_PANGORO_PAL_TAG;
    default:
        return TAG_NONE;
    }
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8 *GetMonIconTiles(u16 species, u32 personality)
{
    const u8 *iconSprite;

    if (species > NUM_SPECIES)
        species = SPECIES_NONE;

    if (species == SPECIES_RIOLU && IsGiftAuraPersonality(personality))
        return gMonIcon_RioluGiftAura;

#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
        iconSprite = gSpeciesInfo[species].iconSpriteFemale;
    else
#endif
    if (gSpeciesInfo[species].iconSprite != NULL)
        iconSprite = gSpeciesInfo[species].iconSprite;
    else
        iconSprite = gSpeciesInfo[SPECIES_NONE].iconSprite;

    return iconSprite;
}

const u8 *GetMonIconTiles_ShadowAware(u16 species, u32 personality, bool8 useShadowIcon)
{
    u16 iconSpecies = GetIconSpecies(species, personality);

    if (useShadowIcon)
    {
        const u8 *shadowIcon = GetShadowMonIcon(iconSpecies, personality);
        if (shadowIcon != NULL)
            return shadowIcon;
    }

    return GetMonIconTiles(iconSpecies, personality);
}

void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    if (offset <= BG_PLTT_ID(16 - ARRAY_COUNT(gMonIconPaletteTable)))
    {
        for (i = 0; i < (int)ARRAY_COUNT(gMonIconPaletteTable); i++)
        {
            LoadPalette(gMonIconPaletteTable[i].data, offset, PLTT_SIZE_4BPP);
            offset += 16;
        }
    }
}

u8 GetValidMonIconPalIndex(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

const u16 *GetValidMonIconPalettePtr(u16 species)
{
    return gMonIconPaletteTable[gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
