#include "global.h"
#include "surf_ow.h"
#include "field_effect_helpers.h"
#include "field_move.h"
#include "event_object_movement.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/species.h"

struct SurfOwState
{
    bool8 active;
    bool8 isShiny;
    u16 species;
    u16 entryIndex;
    u16 paletteTag;
    u8 objEventId;
    u8 baseSpriteId;
    u8 overlaySpriteId;
};

static EWRAM_DATA struct SurfOwState sSurfOwState = {0};

static void UpdateSurfMonOverlay(struct Sprite *sprite);

#include "data/graphics/surf_ow.h"

static EWRAM_DATA struct SpriteFrameImage sShinySurfFrames[SURFABLE_POKEMON_MAX_FRAME_COUNT] = {0};
static EWRAM_DATA struct SpriteFrameImage sShinySurfOverlayFrames[SURFABLE_POKEMON_MAX_FRAME_COUNT] = {0};

#define SURF_OW_INVALID_INDEX 0xFFFF

static void SurfOw_ResetState(void)
{
    sSurfOwState.active = FALSE;
    sSurfOwState.isShiny = FALSE;
    sSurfOwState.species = SPECIES_NONE;
    sSurfOwState.entryIndex = SURF_OW_INVALID_INDEX;
    sSurfOwState.paletteTag = TAG_NONE;
    sSurfOwState.objEventId = 0;
    sSurfOwState.baseSpriteId = MAX_SPRITES;
    sSurfOwState.overlaySpriteId = MAX_SPRITES;
}

static u16 SurfOw_GetEntryIndex(u16 species)
{
    u32 i;

    if (species == SPECIES_PIKACHU_PARTNER || species == SPECIES_PIKACHU_STARTER)
        species = SPECIES_PIKACHU;

    for (i = 1; i < ARRAY_COUNT(gSurfablePokemon); i++)
    {
        if (gSurfablePokemon[i].species == species)
            return i;
    }

    return SURF_OW_INVALID_INDEX;
}

bool8 SurfOw_HasSpeciesEntry(u16 species)
{
    return SurfOw_GetEntryIndex(species) != SURF_OW_INVALID_INDEX;
}

bool8 SurfOw_IsSpeciesEligible(u16 species)
{
    return SurfOw_HasSpeciesEntry(species);
}

bool8 SurfOw_CacheCurrentFromFieldMoveMonInfo(u8 objEventId)
{
    const struct FieldMoveMonInfo *info = GetFieldMoveMonInfo();
    u16 entryIndex = SurfOw_GetEntryIndex(info->species);

    if (!info->valid || entryIndex == SURF_OW_INVALID_INDEX)
    {
        SurfOw_ResetState();
        return FALSE;
    }

    sSurfOwState.active = TRUE;
    sSurfOwState.species = info->species;
    sSurfOwState.entryIndex = entryIndex;
    sSurfOwState.paletteTag = sSurfablePokemonPalettes[entryIndex].tag;
    sSurfOwState.isShiny = info->isShiny;
    sSurfOwState.objEventId = objEventId;
    sSurfOwState.baseSpriteId = MAX_SPRITES;
    sSurfOwState.overlaySpriteId = MAX_SPRITES;
    return TRUE;
}

void SurfOw_ClearCurrent(void)
{
    bool8 wasActive = sSurfOwState.active;
    u16 paletteTag = sSurfOwState.paletteTag;

    SurfOw_ResetState();
    if (wasActive && paletteTag != TAG_NONE)
        FreeSpritePaletteByTag(paletteTag);
}

bool8 SurfOw_CurrentIsShiny(void)
{
    return sSurfOwState.active && sSurfOwState.isShiny;
}

bool8 SurfOw_IsCurrentActiveForObjectEvent(u8 objEventId)
{
    return sSurfOwState.active && sSurfOwState.objEventId == objEventId;
}

bool8 SurfOw_ShouldOverridePlayerPriority(u8 objEventId)
{
    (void)objEventId;
    return FALSE;
}

static const struct SpritePalette *SurfOw_GetCurrentPalette(void)
{
    if (!sSurfOwState.active || sSurfOwState.entryIndex == SURF_OW_INVALID_INDEX)
        return NULL;

    if (sSurfOwState.isShiny)
        return &sSurfablePokemonShinyPalettes[sSurfOwState.entryIndex];

    return &sSurfablePokemonPalettes[sSurfOwState.entryIndex];
}

static bool8 SurfOw_SetupShinyFrames(void)
{
    const u8 *shinyPic = (const u8 *)gSurfablePokemon[sSurfOwState.entryIndex].shinyPic;
    const struct SpriteFrameImage *normalFrames = gSurfablePokemonOverworldSprites[sSurfOwState.entryIndex].images;
    const struct SpriteTemplate *overlayTemplate = &gSurfablePokemonOverlaySprites[sSurfOwState.entryIndex];
    u32 frameSize = normalFrames[0].size;
    u32 frameCount = SURFABLE_POKEMON_DEFAULT_FRAME_COUNT;
    u32 i;

    if (!sSurfOwState.isShiny || shinyPic == NULL)
        return FALSE;

    if (overlayTemplate->images != NULL)
    {
        const u8 *normalPic = normalFrames[0].data;
        const u8 *normalOverlayPic = overlayTemplate->images[0].data;

        frameCount = (normalOverlayPic - normalPic) / frameSize;
    }
    if (frameCount > ARRAY_COUNT(sShinySurfFrames))
        return FALSE;

    for (i = 0; i < frameCount; i++)
    {
        sShinySurfFrames[i].data = shinyPic + frameSize * i;
        sShinySurfFrames[i].size = frameSize;
        sShinySurfFrames[i].relativeFrames = FALSE;
        sShinySurfOverlayFrames[i].data = shinyPic + frameSize * (i + frameCount);
        sShinySurfOverlayFrames[i].size = frameSize;
        sShinySurfOverlayFrames[i].relativeFrames = FALSE;
    }

    return TRUE;
}

bool8 SurfOw_CreateSpritePair(u8 objEventId, s16 x, s16 y, u8 subpriority, u8 *outSpriteId)
{
    const struct SpritePalette *palette;
    const struct SpriteTemplate *baseTemplate;
    const struct SpriteTemplate *overlayTemplate;
    bool8 useShinyFrames;
    u8 spriteId;
    u8 paletteNum;

    if (!SurfOw_IsCurrentActiveForObjectEvent(objEventId))
        return FALSE;

    palette = SurfOw_GetCurrentPalette();
    if (palette == NULL)
        return FALSE;

    baseTemplate = &gSurfablePokemonOverworldSprites[sSurfOwState.entryIndex];
    overlayTemplate = &gSurfablePokemonOverlaySprites[sSurfOwState.entryIndex];
    useShinyFrames = SurfOw_SetupShinyFrames();

    paletteNum = LoadSpritePalette(palette);
    if (paletteNum == 0xFF)
        return FALSE;

    spriteId = CreateSpriteAtEnd(baseTemplate, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
    {
        FreeSpritePaletteByTag(palette->tag);
        return FALSE;
    }

    gSprites[spriteId].coordOffsetEnabled = TRUE;
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].data[2] = objEventId;
    gSprites[spriteId].data[3] = -1;
    gSprites[spriteId].data[4] = 0;
    gSprites[spriteId].data[5] = 0;
    gSprites[spriteId].data[6] = -1;
    gSprites[spriteId].data[7] = -1;
    gSprites[spriteId].oam.paletteNum = paletteNum;
    if (useShinyFrames)
    {
        gSprites[spriteId].images = sShinySurfFrames;
        StartSpriteAnim(&gSprites[spriteId], gSprites[spriteId].animNum);
    }

    if (overlayTemplate->images != NULL)
    {
        u8 overlayId = CreateSpriteAtEnd(overlayTemplate, x, y, subpriority);

        if (overlayId != MAX_SPRITES)
        {
            gSprites[overlayId].coordOffsetEnabled = TRUE;
            gSprites[overlayId].data[0] = spriteId;
            gSprites[overlayId].callback = UpdateSurfMonOverlay;
            gSprites[overlayId].oam.paletteNum = paletteNum;
            gSprites[overlayId].subpriority = (gSprites[spriteId].subpriority == 0) ? 0 : gSprites[spriteId].subpriority - 1;
            if (useShinyFrames)
            {
                gSprites[overlayId].images = sShinySurfOverlayFrames;
                StartSpriteAnim(&gSprites[overlayId], gSprites[overlayId].animNum);
            }
            sSurfOwState.overlaySpriteId = overlayId;
        }
    }

    sSurfOwState.baseSpriteId = spriteId;
    if (outSpriteId != NULL)
        *outSpriteId = spriteId;
    return TRUE;
}

void SurfOw_DestroySprites(u8 baseSpriteId)
{
    if (!sSurfOwState.active || sSurfOwState.baseSpriteId != baseSpriteId)
        return;

    if (sSurfOwState.overlaySpriteId < MAX_SPRITES)
    {
        u8 overlayId = sSurfOwState.overlaySpriteId;
        if (gSprites[overlayId].inUse)
            DestroySprite(&gSprites[overlayId]);
    }
    sSurfOwState.baseSpriteId = MAX_SPRITES;
    sSurfOwState.overlaySpriteId = MAX_SPRITES;
}

static void UpdateSurfMonOverlay(struct Sprite *sprite)
{
    u8 baseSpriteId = sprite->data[0];

    if (baseSpriteId >= MAX_SPRITES || !gSprites[baseSpriteId].inUse)
    {
        DestroySprite(sprite);
        return;
    }

    sprite->x = gSprites[baseSpriteId].x;
    sprite->y = gSprites[baseSpriteId].y;
    sprite->x2 = gSprites[baseSpriteId].x2;
    sprite->y2 = gSprites[baseSpriteId].y2;
    sprite->oam.priority = gSprites[baseSpriteId].oam.priority;
    sprite->subpriority = (gSprites[baseSpriteId].subpriority == 0) ? 0 : gSprites[baseSpriteId].subpriority - 1;
    sprite->subspriteMode = gSprites[baseSpriteId].subspriteMode;
    sprite->subspriteTableNum = gSprites[baseSpriteId].subspriteTableNum;
    sprite->invisible = gSprites[baseSpriteId].invisible;
    StartSpriteAnimIfDifferent(sprite, gSprites[baseSpriteId].animNum);
}
