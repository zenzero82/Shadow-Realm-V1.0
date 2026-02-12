#include "global.h"
#include "shadow_monitor.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/characters.h"
#include "constants/species.h"

static const u8 sText_Empty[] = "";

void CB2_OpenShadowMonitor(void)
{
    // Placeholder: open the standard Pokédex until shadow monitor is rebuilt.
    gIsShadowMonitorOpen = TRUE;
    CB2_OpenPokedexHoenn();
}

void BuildShadowMonitorList(void)
{
}

void UpdateShadowMonitorListState(void)
{
}

void PrintShadowMonitorHeader(void)
{
}

void PrintShadowMonitorFooter(void)
{
}

const u8 *GetShadowMonitorStateName(u8 state)
{
    (void)state;
    return sText_Empty;
}

bool8 ShadowMonitorPopulateInfo(u16 shadowId, struct ShadowMonitorInfo *info)
{
    s32 i, box, slot;

    if (info == NULL)
        return FALSE;

    info->found = FALSE;
    info->isSnagged = FALSE;
    info->location = SHADOW_MON_LOCATION_NONE;
    info->boxId = 0;
    info->heartValue = 0;
    info->heartMax = 0;
    info->trainerName[0] = EOS;

    if (shadowId == 0 || shadowId > MAX_SHADOW_MON_IDS)
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_SHADOW, NULL))
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_SHADOW_ID, NULL) != shadowId)
            continue;

        info->found = TRUE;
        info->location = SHADOW_MON_LOCATION_PARTY;
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
            info->location = SHADOW_MON_LOCATION_BOX;
            info->boxId = box;
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
    (void)shadowId;
    return FALSE;
}

void ShadowMonitor_CreateMonSpriteForSelected(u16 selectedMon)
{
    (void)selectedMon;
}

void ShadowMonitor_RefreshMonSprite(void)
{
}

void ShadowMonitor_DrawListEntries(u16 selectedMon, u16 ignored)
{
    (void)selectedMon;
    (void)ignored;
}

u8 ShadowMonitor_GetListHeaderOffsetRows(void)
{
    return 0;
}
