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
    u8 objEventId;
    u8 baseSpriteId;
    u8 overlaySpriteId;
};

static EWRAM_DATA struct SurfOwState sSurfOwState = {0};

static void SurfOw_OverlaySpriteCallback(struct Sprite *sprite);

#include "data/graphics/surf_ow.h"

static void SurfOw_ResetState(void)
{
    sSurfOwState.active = FALSE;
    sSurfOwState.isShiny = FALSE;
    sSurfOwState.species = SPECIES_NONE;
    sSurfOwState.objEventId = 0;
    sSurfOwState.baseSpriteId = MAX_SPRITES;
    sSurfOwState.overlaySpriteId = MAX_SPRITES;
}

const struct SurfOwEntry *SurfOw_GetEntry(u16 species)
{
    u32 i;

    for (i = 0; gSurfOwEntries[i].species != SPECIES_NONE; i++)
    {
        if (gSurfOwEntries[i].species == species)
            return &gSurfOwEntries[i];
    }

    return NULL;
}

bool8 SurfOw_HasSpeciesEntry(u16 species)
{
    return SurfOw_GetEntry(species) != NULL;
}

bool8 SurfOw_IsSpeciesEligible(u16 species)
{
    return SurfOw_HasSpeciesEntry(species);
}

bool8 SurfOw_CacheCurrentFromFieldMoveMonInfo(u8 objEventId)
{
    const struct FieldMoveMonInfo *info = GetFieldMoveMonInfo();

    if (!info->valid || !SurfOw_HasSpeciesEntry(info->species))
    {
        SurfOw_ResetState();
        return FALSE;
    }

    sSurfOwState.active = TRUE;
    sSurfOwState.species = info->species;
    sSurfOwState.isShiny = info->isShiny;
    sSurfOwState.objEventId = objEventId;
    sSurfOwState.baseSpriteId = MAX_SPRITES;
    sSurfOwState.overlaySpriteId = MAX_SPRITES;
    return TRUE;
}

void SurfOw_ClearCurrent(void)
{
    SurfOw_ResetState();
    FreeSpritePaletteByTag(OBJ_EVENT_PAL_TAG_SURF_OW);
}

const struct SurfOwEntry *SurfOw_GetCurrentEntry(void)
{
    if (!sSurfOwState.active)
        return NULL;

    return SurfOw_GetEntry(sSurfOwState.species);
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
    if (!SurfOw_IsCurrentActiveForObjectEvent(objEventId))
        return FALSE;

    switch (sSurfOwState.species)
    {
    case SPECIES_LAPRAS:
    case SPECIES_PIKACHU:
        return TRUE;
    default:
        return FALSE;
    }
}

static const u16 *SurfOw_GetPaletteForEntry(const struct SurfOwEntry *entry)
{
    if (entry == NULL)
        return NULL;

    if (sSurfOwState.isShiny && entry->shinyPalette != NULL)
        return entry->shinyPalette;

    return entry->palette;
}

bool8 SurfOw_CreateSpritePair(u8 objEventId, s16 x, s16 y, u8 subpriority, u8 *outSpriteId)
{
    const struct SurfOwEntry *entry;
    const u16 *palette;
    u8 spriteId;
    u8 paletteNum;

    if (!SurfOw_IsCurrentActiveForObjectEvent(objEventId))
        return FALSE;

    entry = SurfOw_GetCurrentEntry();
    palette = SurfOw_GetPaletteForEntry(entry);
    if (entry == NULL || palette == NULL)
        return FALSE;

    paletteNum = LoadSpritePaletteWithTag(palette, OBJ_EVENT_PAL_TAG_SURF_OW);
    if (paletteNum == 0xFF)
        return FALSE;

    spriteId = CreateSpriteAtEnd(entry->baseTemplate, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
        return FALSE;

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

    if (entry->overlayTemplate != NULL)
    {
        u8 overlayId = CreateSpriteAtEnd(entry->overlayTemplate, x, y, subpriority);

        if (overlayId != MAX_SPRITES)
        {
            gSprites[overlayId].coordOffsetEnabled = TRUE;
            gSprites[overlayId].data[0] = spriteId;
            gSprites[overlayId].callback = SurfOw_OverlaySpriteCallback;
            gSprites[overlayId].oam.paletteNum = paletteNum;
            gSprites[overlayId].subpriority = gSprites[spriteId].subpriority + 1;
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

static void SurfOw_OverlaySpriteCallback(struct Sprite *sprite)
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
    sprite->subpriority = gSprites[baseSpriteId].subpriority + 1;
    sprite->invisible = gSprites[baseSpriteId].invisible;
    StartSpriteAnimIfDifferent(sprite, gSprites[baseSpriteId].animNum);
}
