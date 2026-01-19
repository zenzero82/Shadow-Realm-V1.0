#include "global.h"
#include "shadow_monitor.h"
#include "constants/shadow.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "constants/species.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "palette.h"
#include "string_util.h"
#include "menu.h"
#include "text.h"
#include "strings.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "shadow_monitor_species.h"

static const u8 sText_ShadowMonitorTitle[] = _("SHADOW MONITOR");
static const u8 sText_ShadowMonitorStateFmt[] = _("State: {STR_VAR_1}");
static const u8 sText_ShadowMonitorHeartFmt[] = _("Heart: {STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_ShadowMonitorPurifiedFmt[] = _("Purified: {STR_VAR_1}");
static const u8 sText_ShadowMonitorTrainerFmt[] = _("Snagged from {STR_VAR_1}");
static const u8 sText_ShadowStateUnseen[] = _("UNSEEN");
static const u8 sText_ShadowStateSeen[] = _("SEEN");
static const u8 sText_ShadowStateSnagged[] = _("SNAGGED");
static const u8 sText_ShadowStatePurified[] = _("PURIFIED");
static const u8 sText_ShadowStateFailed[] = _("FAILED");
static const u8 sText_ShadowMonitorUnknownName[] = _("------");
static const u8 sText_ShadowMonitorHint[] = _("Press R to return");
static const u8 sText_ShadowMonitorHeaderFmt[] = _("{STR_VAR_1}: {STR_VAR_2}");
static const u8 *const sShadowMonitorStatsLabels[] = 
{
    sText_ShadowStateSeen,
    sText_ShadowStateSnagged,
    sText_ShadowStateFailed,
    sText_ShadowStatePurified,
};

static u16 GetShadowMonitorShadowIdByLine(u16 line);
static u16 GetShadowMonitorNationalDexNum(u16 shadowId);
static void ShadowMonitor_UpdateSpritePalette(u16 spriteId, u16 shadowId, u8 state);

#define SHADOW_MON_PAGE_X 96
#define SHADOW_MON_PAGE_Y 80
#define SHADOW_MON_SPRITE_PALETTE_SLOT 0

static EWRAM_DATA u16 sShadowMonitorSpriteId;
static EWRAM_DATA u16 sShadowMonitorSelectedMon;

const u8 *GetShadowMonitorStateName(u8 state)
{
    switch (state)
    {
    case SHDW_STATE_SEEN:
    case SHDW_STATE_FAILED:
        return sText_ShadowStateFailed;
    case SHDW_STATE_SNAGGED:
        return sText_ShadowStateSnagged;
    case SHDW_STATE_PURIFIED:
        return sText_ShadowStatePurified;
    default:
        return sText_ShadowStateUnseen;
    }
}

void BuildShadowMonitorList(void)
{
    u16 line;

    for (line = 0; line < MAX_SHADOW_MON_IDS; line++)
    {
        u16 shadowId = gShadowMonitorIdList[line];
        struct PokedexListItem *entry = &sPokedexView->pokedexList[line];
        u8 state = SHDW_STATE_NEVER_SEEN;

        if (shadowId != 0)
            state = Shdw_GetState(shadowId);

        entry->dexNum = line + 1;
        sPokedexView->shadowIdList[line] = shadowId;
        sPokedexView->shadowStateList[line] = state;
        entry->seen = state != SHDW_STATE_NEVER_SEEN;
        entry->owned = (state == SHDW_STATE_SNAGGED || state == SHDW_STATE_PURIFIED);
    }

    sPokedexView->shadowListCount = MAX_SHADOW_MON_IDS;
    sPokedexView->pokemonListCount = MAX_SHADOW_MON_IDS;
}

bool8 ShadowMonitorPopulateInfo(u16 shadowId, struct ShadowMonitorInfo *info)
{
    s32 i, box, slot;

    info->found = FALSE;
    info->isSnagged = FALSE;
    info->heartValue = 0;
    info->heartMax = 0;
    info->trainerName[0] = EOS;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_SHADOW, NULL))
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_SHADOW_ID, NULL) != shadowId)
            continue;

        info->found = TRUE;
        info->heartValue = GetMonData(&gPlayerParty[i], MON_DATA_HEART_VALUE, NULL);
        info->heartMax = GetMonData(&gPlayerParty[i], MON_DATA_HEART_MAX, NULL);
        info->isSnagged = GetMonData(&gPlayerParty[i], MON_DATA_SNAGGED, NULL);
        GetMonData(&gPlayerParty[i], MON_DATA_OT_NAME, info->trainerName);
        return TRUE;
    }

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (slot = 0; slot < IN_BOX_COUNT; slot++)
        {
            struct BoxPokemon *boxMon = &gPokemonStoragePtr->boxes[box][slot];

            if (GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
                continue;
            if (!GetBoxMonData(boxMon, MON_DATA_IS_SHADOW, NULL))
                continue;
            if (GetBoxMonData(boxMon, MON_DATA_SHADOW_ID, NULL) != shadowId)
                continue;

            info->found = TRUE;
            info->heartValue = GetBoxMonData(boxMon, MON_DATA_HEART_VALUE, NULL);
            info->heartMax = GetBoxMonData(boxMon, MON_DATA_HEART_MAX, NULL);
            info->isSnagged = GetBoxMonData(boxMon, MON_DATA_SNAGGED, NULL);
            GetBoxMonData(boxMon, MON_DATA_OT_NAME, info->trainerName);
            return TRUE;
        }
    }

    return FALSE;
}

bool8 ShadowMonitorMonIsOwned(u16 shadowId)
{
    u8 state = Shdw_GetState(shadowId);
    struct ShadowMonitorInfo info;

    if (state == SHDW_STATE_SNAGGED || state == SHDW_STATE_PURIFIED)
        return TRUE;

    if (ShadowMonitorPopulateInfo(shadowId, &info))
        return info.isSnagged;

    return FALSE;
}

void UpdateShadowMonitorListState(void)
{
    u16 i;

    for (i = 0; i < sPokedexView->shadowListCount; i++)
    {
        u16 shadowId = sPokedexView->shadowIdList[i];

        if (shadowId == 0)
        {
            sPokedexView->pokedexList[i].seen = FALSE;
            sPokedexView->pokedexList[i].owned = FALSE;
            sPokedexView->shadowStateList[i] = SHDW_STATE_NEVER_SEEN;
            continue;
        }

        u8 state = Shdw_GetState(shadowId);
        sPokedexView->shadowStateList[i] = state;
        sPokedexView->shadowIdList[i] = shadowId;
        sPokedexView->pokedexList[i].seen = state != SHDW_STATE_NEVER_SEEN;
        sPokedexView->pokedexList[i].owned = (state == SHDW_STATE_SNAGGED || state == SHDW_STATE_PURIFIED);
    }

}

static void PrintShadowMonitorStats(u16 seenCount, u16 snaggedCount, u16 failedCount, u16 purifiedCount)
{
    const u16 counts[SHADOW_MON_STATS_LINES] = { seenCount, snaggedCount, failedCount, purifiedCount };
    const u16 baseX = SHADOW_MON_STATS_RIGHT_X;
    const u16 baseY = SHADOW_MON_STATS_TOP_Y;
    const u16 areaHeight = SHADOW_MON_STATS_LINES * SHADOW_MON_STATS_LINE_HEIGHT;
    static const u8 colors[] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY };

    FillWindowPixelRect(0, PIXEL_FILL(0), baseX, baseY, SHADOW_MON_STATS_AREA_WIDTH, areaHeight);

    for (u8 i = 0; i < SHADOW_MON_STATS_LINES; i++)
    {
        u8 lineText[20];
        u8 numberText[4];
        u16 count = counts[i];

        ConvertIntToDecimalStringN(numberText, count, STR_CONV_MODE_LEADING_ZEROS, 3);
        u8 *numStart = numberText;
        while (*numStart == '0' && *(numStart + 1) != EOS)
            numStart++;

        StringCopy(lineText, sShadowMonitorStatsLabels[i]);
        StringAppend(lineText, CHAR_SPACE);
        StringAppend(lineText, numStart);

        u16 y = baseY + (i * SHADOW_MON_STATS_LINE_HEIGHT);
        AddTextPrinterParameterized4(0, FONT_NORMAL, baseX, y, 0, 0, colors, TEXT_SKIP_DRAW, lineText);
    }

    CopyWindowToVram(0, COPYWIN_GFX);
}

void PrintShadowMonitorHeader(void)
{
    u16 seenCount = 0;
    u16 snaggedCount = 0;
    u16 failedCount = 0;
    u16 purifiedCount = 0;
    u16 i;

    for (i = 0; i < MAX_SHADOW_MON_IDS; i++)
    {
        u8 state = sPokedexView->shadowStateList[i];

        if (state != SHDW_STATE_NEVER_SEEN)
            seenCount++;
        if (state == SHDW_STATE_SNAGGED || state == SHDW_STATE_PURIFIED)
            snaggedCount++;
        if (state == SHDW_STATE_FAILED)
            failedCount++;
        if (state == SHDW_STATE_PURIFIED)
            purifiedCount++;
    }

    PrintShadowMonitorStats(seenCount, snaggedCount, failedCount, purifiedCount);

    const u16 headerWidth = SHADOW_MON_STATS_RIGHT_X;
    const u16 headerHeight = SHADOW_MON_BORDER_HEIGHT;

    FillWindowPixelRect(0, PIXEL_FILL(0), 0, 0, headerWidth, headerHeight);
    CopyWindowToVram(0, COPYWIN_GFX);
}

void PrintShadowMonitorFooter(void)
{
    const u16 headerX = SHADOW_MON_STATS_RIGHT_X;
    const u16 footerBaseRow = SHADOW_MON_LEFT_TEXT_Y + 4;
    const u16 footerBaseY = footerBaseRow * 8;
    FillWindowPixelRect(0, PIXEL_FILL(0), 0, footerBaseY, headerX, 32 * 8 - footerBaseY);

    CopyWindowToVram(0, COPYWIN_GFX);
}

static u32 GetShadowMonitorMonPersonality(u16 species)
{
    if (species == SPECIES_UNOWN)
        return gSaveBlock2Ptr->pokedex.unownPersonality;
    if (species == SPECIES_SPINDA)
        return gSaveBlock2Ptr->pokedex.spindaPersonality;
    return 0xFF;
}

static u16 GetShadowMonitorShadowIdByLine(u16 line)
{
    if (line >= MAX_SHADOW_MON_IDS)
        return 0;
    return sPokedexView->shadowIdList[line];
}

static u16 GetShadowMonitorNationalDexNum(u16 shadowId)
{
    if (shadowId == 0)
        return 0;

    u16 species = GetShadowMonitorSpecies(shadowId);
    if (species == SPECIES_NONE)
        return 0;

    u16 nationalNum = SpeciesToNationalPokedexNum(species);
    return nationalNum != 0 ? nationalNum : 0;
}

static void ShadowMonitor_UpdateSpritePalette(u16 spriteId, u16 shadowId, u8 state)
{
    if (spriteId == 0xFFFF || shadowId == 0)
        return;

    u16 species = GetShadowMonitorSpecies(shadowId);
    if (species == SPECIES_NONE)
        return;

    u32 personality = GetShadowMonitorMonPersonality(species);
    const u16 *palette = GetMonSpritePalFromSpeciesAndPersonality_ShadowAware(species, FALSE, personality, state != SHDW_STATE_PURIFIED);
    if (palette != NULL)
        LoadPalette(palette, OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
}

void ShadowMonitor_CreateMonSpriteForSelected(u16 selectedMon)
{
    if (sShadowMonitorSpriteId != 0xFFFF)
    {
        FreeAndDestroyMonPicSprite(sShadowMonitorSpriteId);
        sShadowMonitorSpriteId = 0xFFFF;
    }

    sPokedexView->selectedMonSpriteId = 0xFFFF;
    sShadowMonitorSelectedMon = 0xFFFF;

    if (selectedMon >= sPokedexView->pokemonListCount)
        return;

    u16 shadowId = GetShadowMonitorShadowIdByLine(selectedMon);
    if (shadowId == 0)
        return;

    u8 state = sPokedexView->shadowStateList[shadowId - 1];
    u16 spriteId;

    if (state == SHDW_STATE_NEVER_SEEN)
    {
        spriteId = CreateMonIcon(SPECIES_NONE, SpriteCB_MonIcon, SHADOW_MON_PAGE_X, SHADOW_MON_PAGE_Y, 3, 0xFFFFFFFF, FALSE);
    }
    else
    {
        u16 nationalDexNum = GetShadowMonitorNationalDexNum(shadowId);
        spriteId = CreateMonSpriteFromNationalDexNumber(nationalDexNum, SHADOW_MON_PAGE_X, SHADOW_MON_PAGE_Y, SHADOW_MON_SPRITE_PALETTE_SLOT);
    }

    if (spriteId == 0xFFFF)
        return;

    sShadowMonitorSpriteId = spriteId;
    sShadowMonitorSelectedMon = selectedMon;

    gSprites[spriteId].oam.priority = 3;
    gSprites[spriteId].data[5] = state;

    if (state != SHDW_STATE_NEVER_SEEN)
        ShadowMonitor_UpdateSpritePalette(spriteId, shadowId, state);
}

void ShadowMonitor_RefreshMonSprite(void)
{
    u16 selectedMon = sPokedexView->selectedPokemon;

    if (selectedMon >= sPokedexView->pokemonListCount)
        return;

    if (sShadowMonitorSpriteId == 0xFFFF || sShadowMonitorSelectedMon != selectedMon)
    {
        ShadowMonitor_CreateMonSpriteForSelected(selectedMon);
        return;
    }

    u16 shadowId = GetShadowMonitorShadowIdByLine(selectedMon);
    if (shadowId == 0)
    {
        if (sShadowMonitorSpriteId != 0xFFFF)
        {
            FreeAndDestroyMonPicSprite(sShadowMonitorSpriteId);
            sShadowMonitorSpriteId = 0xFFFF;
            sShadowMonitorSelectedMon = 0xFFFF;
        }
        return;
    }

    u8 state = sPokedexView->shadowStateList[shadowId - 1];

    if (gSprites[sShadowMonitorSpriteId].data[5] == state)
        return;

    gSprites[sShadowMonitorSpriteId].data[5] = state;
    ShadowMonitor_UpdateSpritePalette(sShadowMonitorSpriteId, shadowId, state);
}

void ShadowMonitor_DrawListEntries(u16 selectedMon, u16 ignored)
{
    const u8 colors[] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY };
    const u8 startRow = SHADOW_MON_LIST_HEADER_ROWS;
    const u8 rowsOnScreen = 11;
    const u8 lineHeight = 16;
    const u16 baseY = startRow * 8;
    const u16 baseX = 4 * 8;
    s16 entryNum = selectedMon - 5;
    u16 i;

    FillWindowPixelRect(0, PIXEL_FILL(0), 0, baseY, 0x60, rowsOnScreen * lineHeight);

    for (i = 0; i < rowsOnScreen; i++)
    {
        s16 lineIndex = entryNum + i;
        u16 y = baseY + (i * lineHeight);

        if (lineIndex < 0 || lineIndex >= MAX_SHADOW_MON_IDS)
            continue;

        u16 lineNumber = lineIndex + 1;
        u16 shadowId = sPokedexView->shadowIdList[lineIndex];
        u8 state = shadowId == 0 ? SHDW_STATE_NEVER_SEEN : sPokedexView->shadowStateList[lineIndex];
        u8 digits[4];
        u8 lineText[32];

        ConvertIntToDecimalStringN(digits, lineNumber, STR_CONV_MODE_LEADING_ZEROS, 3);
        lineText[0] = 'N';
        lineText[1] = 'o';
        lineText[2] = digits[0];
        lineText[3] = digits[1];
        lineText[4] = digits[2];
        lineText[5] = CHAR_SPACE;
        lineText[6] = EOS;
        StringAppend(lineText, GetShadowMonitorStateName(state));

        AddTextPrinterParameterized4(0, FONT_NARROW, baseX, y, 0, 0, colors, TEXT_SKIP_DRAW, lineText);
    }

    CopyWindowToVram(0, COPYWIN_GFX);
}

u8 ShadowMonitor_GetListHeaderOffsetRows(void)
{
    return SHADOW_MON_LIST_HEADER_ROWS;
}
