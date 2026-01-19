#ifndef GUARD_SHADOW_MONITOR_H
#define GUARD_SHADOW_MONITOR_H

#include "pokedex_view.h"

#define SHADOW_MON_LIST_HEADER_ROWS 0
#define SHADOW_MON_STATS_LINES 4
#define SHADOW_MON_STATS_LINE_HEIGHT 16
#define SHADOW_MON_STATS_RIGHT_X 176
#define SHADOW_MON_STATS_TOP_Y 16
#define SHADOW_MON_STATS_AREA_WIDTH 96
#define SHADOW_MON_LEFT_TEXT_X 0
#define SHADOW_MON_LEFT_TEXT_Y 2
#define SHADOW_MON_LEFT_TEXT_SPACING 8
#define WIN_SHADOW_MON_STATS 1
#define SHADOW_MON_BORDER_HEIGHT (SHADOW_MON_LEFT_TEXT_Y * 8 + SHADOW_MON_LEFT_TEXT_SPACING * 5 + 8)
#define SHADOW_MON_STATS_LEFT 25
#define SHADOW_MON_STATS_TOP 1
#define SHADOW_MON_STATS_WIDTH 10
#define SHADOW_MON_STATS_ROWS 4

struct ShadowMonitorInfo
{
    bool8 found;
    bool8 isSnagged;
    u16 heartValue;
    u16 heartMax;
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
};

void CB2_OpenShadowMonitor(void);
void BuildShadowMonitorList(void);
void UpdateShadowMonitorListState(void);
void PrintShadowMonitorHeader(void);
void PrintShadowMonitorFooter(void);
const u8 *GetShadowMonitorStateName(u8 state);
bool8 ShadowMonitorPopulateInfo(u16 shadowId, struct ShadowMonitorInfo *info);
bool8 ShadowMonitorMonIsOwned(u16 shadowId);
void ShadowMonitor_CreateMonSpriteForSelected(u16 selectedMon);
void ShadowMonitor_RefreshMonSprite(void);
void ShadowMonitor_DrawListEntries(u16 selectedMon, u16 ignored);
u8 ShadowMonitor_GetListHeaderOffsetRows(void);

#endif // GUARD_SHADOW_MONITOR_H
