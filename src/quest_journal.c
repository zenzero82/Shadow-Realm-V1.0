#include "global.h"
#include "quest_journal.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sound.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "gba/io_reg.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"
#include "international_string_util.h"
#include "event_data.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "constants/flags.h"
#include "constants/songs.h"

#define TEXT_SPEED_FF 0xFF
#define QUEST_JOURNAL_MAX_ENTRIES 150
#define QUEST_JOURNAL_VISIBLE_ENTRIES 6
#define QUEST_JOURNAL_ENTRY_TEXT_X 20
#define QUEST_JOURNAL_ENTRY_ICON_X 12
#define QUEST_JOURNAL_ENTRY_ICON_Y_BASE 24

#define TAG_QUEST_JOURNAL_MARKINGS 0x1200
#define PALTAG_QUEST_JOURNAL_MARKINGS 0x1200

struct QuestJournalEntry
{
    const u8 *title;
    const u8 *description;
    u16 flagStarted;
    u16 flagCompleted;
};

enum
{
    QUEST_JOURNAL_MARKING_ICON_IN_PROGRESS,
    QUEST_JOURNAL_MARKING_ICON_COMPLETE,
    QUEST_JOURNAL_MARKING_ICON_COUNT,
};

enum
{
    QUEST_JOURNAL_TAB_ALL,
    QUEST_JOURNAL_TAB_ACTIVE,
    QUEST_JOURNAL_TAB_INACTIVE,
    QUEST_JOURNAL_TAB_COUNT,
};

enum
{
    QUEST_JOURNAL_ENTRY_STATE_COMPLETE,
    QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE,
    QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED,
};

static void QuestJournal_MainCB2(void);
static void QuestJournal_VBlankCB(void);
static void Task_QuestJournalFadeIn(u8 taskId);
static void Task_QuestJournalHandleInput(u8 taskId);
static void Task_QuestJournalFadeOut(u8 taskId);
static void Task_QuestJournalExit(u8 taskId);
static void QuestJournal_BuildEntryList(void);
static void QuestJournal_AddEntriesByStatePinned(u8 state, bool8 pinned);
static void QuestJournal_AddEntriesAllPinned(bool8 pinned);
static void QuestJournal_DrawTexts(u8 selection);
static void QuestJournal_SetDescription(u8 selection);
static void QuestJournal_ShowDescription(const u8 *text);
static void QuestJournal_LoadCursorMap(u8 selection);
static void QuestJournal_DrawFrame(void);
static void QuestJournal_CreateLegendIcons(void);
static void QuestJournal_DestroyLegendIcons(void);
static void QuestJournal_CreateEntryIcons(void);
static void QuestJournal_DestroyEntryIcons(void);
static void QuestJournal_UpdateEntryIcons(void);
static void QuestJournal_HideButtonIcons(void);
static bool8 QuestJournal_IsEntryUnlocked(const struct QuestJournalEntry *entry);
static u8 QuestJournal_GetEntryState(const struct QuestJournalEntry *entry);
static void QuestJournal_SetTab(u8 taskId, u8 tab);

static const u8 sQuestJournalMarkingsGfx[] = INCBIN_U8("graphics/interface/mon_markings.4bpp");
static const u16 sQuestJournalLegendPal[] =
{
    RGB_BLACK,
    RGB_WHITE,
    RGB(22, 22, 22),
    RGB_WHITE,
    RGB(22, 22, 22),
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
    RGB_BLACK,
};

static const struct OamData sOamData_QuestJournalMarking =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_QuestJournalMarkingCircle[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_QuestJournalMarkingStar[] =
{
    ANIMCMD_FRAME(7, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_QuestJournalMarkings[] =
{
    sAnim_QuestJournalMarkingCircle,
    sAnim_QuestJournalMarkingStar,
};

static const struct SpriteTemplate sQuestJournalMarkingTemplate =
{
    .tileTag = TAG_QUEST_JOURNAL_MARKINGS,
    .paletteTag = PALTAG_QUEST_JOURNAL_MARKINGS,
    .oam = &sOamData_QuestJournalMarking,
    .anims = sAnimTable_QuestJournalMarkings,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 sText_QuestTabAll[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}All Quests");
static const u8 sText_QuestTabActive[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}Active Quests");
static const u8 sText_QuestTabInactive[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}Inactive Quests");
static const u8 sText_QuestTabPage1[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}1/3");
static const u8 sText_QuestTabPage2[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}2/3");
static const u8 sText_QuestTabPage3[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}3/3");
static const u8 sText_QuestTabHint[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}{R_BUTTON} Type");
static const u8 sText_QuestStatusActive[] = _("{COLOR RED}{HIGHLIGHT TRANSPARENT}Active");
static const u8 sText_QuestStatusDone[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}Done");
static const u8 sText_QuestNone[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}No quests yet.");
static const u8 sText_QuestEntryStyle[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}");
static const u8 sText_QuestEntryStylePinned[] = _("{COLOR 6}{HIGHLIGHT TRANSPARENT}");
static const u8 sText_QuestLockedTitle[] = _("-------");
static const u8 sText_QuestLockedDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Quest not unlocked yet.");
static const u8 sText_QuestPalletTitle[] = _("NPCs in Pallet Town");
static const u8 sText_QuestPalletDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}It's important to gather\ninformation from everyone.");
static const u8 sText_QuestViridianTitle[] = _("Go Visit Viridian Gym");
static const u8 sText_QuestViridianDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Viridian seems to be in trouble.\nSeek Gary at Viridian Gym.");
static const u8 sText_QuestPewterTitle[] = _("NPCs in Pewter City");
static const u8 sText_QuestPewterDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nPewter City. Might help!");
static const u8 sText_QuestBrockTitle[] = _("Defeat Brock!");
static const u8 sText_QuestBrockDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Show Brock you're worthy of the\nBOULDER BADGE.");
static const u8 sText_QuestMtMoonTitle[] = _("Explore Mt Moon");
static const u8 sText_QuestMtMoonDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Explore MT Moon and the Outside\narea.");
static const u8 sText_QuestCeruleanNPCsTitle[] = _("NPCs in Cerulean City");
static const u8 sText_QuestCeruleanNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nCerulean City. Might help!");
static const u8 sText_QuestCeruleanWesTitle[] = _("Find Wes in Cerulean City");
static const u8 sText_QuestCeruleanWesDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Wes is waiting for you to prove\nyour strength. Look for clues.");
static const u8 sText_QuestCapeWesTitle[] = _("Wes Has A Hideout at the Cape?!");
static const u8 sText_QuestCapeWesDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Head to Route 25 and look for\nMichael by the Cape.");
static const u8 sText_QuestTalkWesTitle[] = _("Talk to Wes");
static const u8 sText_QuestTalkWesDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Enter Wes' Hideout and speak to\nWes.");
static const u8 sText_QuestTalkTeamTitle[] = _("Talk to the Team");
static const u8 sText_QuestTalkTeamDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit The Under and speak to all\nProfessors.");
static const u8 sText_QuestKukuiShadowTitle[] = _("Finding a... specific Shadow?");
static const u8 sText_QuestKukuiShadowDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}There is a certain {COLOR PURPLE}Shadow POKéMON{COLOR 1}\nthat Kukui needs.");
static const u8 sText_QuestSnagMachineTitle[] = _("The Snag Machine!");
static const u8 sText_QuestSnagMachineDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Talk to Wes before you leave the\nHideout.");
static const u8 sText_QuestMistyTitle[] = _("Defeat Misty!");
static const u8 sText_QuestMistyDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Show Misty that the CASCADE BADGE\nbelongs to you!");
static const u8 sText_QuestRoute9GuardsTitle[] = _("Talk to the Guards at Rt 9.");
static const u8 sText_QuestRoute9GuardsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}The guards would love to see that\nshiny new badge!");
static const u8 sText_QuestPlasmaTunnelTitle[] = _("Plasma Tunnel");
static const u8 sText_QuestPlasmaTunnelDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Team Plasma took over Rock Tunnel.\nDefeat them!");
static const u8 sText_QuestVioletNPCsTitle[] = _("NPCs in Violet City");
static const u8 sText_QuestVioletNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nViolet City. Might help!");
static const u8 sText_QuestFalknerTitle[] = _("Defeat Falkner!");
static const u8 sText_QuestFalknerDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Show Falkner you can fly high and\nsnatch the ZEPHYR BADGE.");
static const u8 sText_QuestKurtTitle[] = _("Kurt the Apricorn Master");
static const u8 sText_QuestKurtDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Head down to Azalea Town and find\nKurt.");
static const u8 sText_QuestAzaleaNPCsTitle[] = _("NPCs in Azalea Town");
static const u8 sText_QuestAzaleaNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nAzalea Town. Might help!");
static const u8 sText_QuestBugsyTitle[] = _("Defeat Bugsy!");
static const u8 sText_QuestBugsyDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Prove to Bugsy that you're the ruler\nof the Hive. Get that HIVE BADGE!");
static const u8 sText_QuestSlowpokeWellTitle[] = _("Slowpoke Well Flared Up!");
static const u8 sText_QuestSlowpokeWellDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Team Flare is up to something.\nFind out what it is!");
static const u8 sText_QuestCherrygroveNPCsTitle[] = _("NPCs in Cherrygrove City");
static const u8 sText_QuestCherrygroveNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nCherrygrove City. Might help!");
static const u8 sText_QuestNewBarkNPCsTitle[] = _("NPCs in New Bark Town");
static const u8 sText_QuestNewBarkNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nNew Bark Town. Might help!");
static const u8 sText_QuestGoldsMomTitle[] = _("Gold's Mom Our Favorite Banker");
static const u8 sText_QuestGoldsMomDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Check on Gold's mom in New Bark\nTown to see how she's doing.");
static const u8 sText_QuestShadowTrainerTitle[] = _("The Shadow Imitation");
static const u8 sText_QuestShadowTrainerDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Search Route 10 for any suspicious\ntrainers.");
static const u8 sText_QuestBackToHQTitle[] = _("Back To HQ... ASAP!");
static const u8 sText_QuestBackToHQDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Birch is tripping... bad.\nLet's get to the Lab as fast as we can!");
static const u8 sText_QuestThunderbirdTitle[] = _("The Thunderbird");
static const u8 sText_QuestThunderbirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit the Power Plant on Route 10\nto seek ZAPDOS.");
static const u8 sText_QuestIcebirdTitle[] = _("The Icebird");
static const u8 sText_QuestIcebirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit Seafoam Islands south of\nFuchsia to seek ARTICUNO.");
static const u8 sText_QuestFirebirdTitle[] = _("The Firebird");
static const u8 sText_QuestFirebirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit MT. SILVER west of the\nRECEPTION GATE to seek MOLTRES.");
static const u8 sText_QuestPhoenixTitle[] = _("The Life Giving Phoenix");
static const u8 sText_QuestPhoenixDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit Tin Tower in Ecruteak City\nto seek HO-OH.");
static const u8 sText_QuestShiningBeastTitle[] = _("The Shining Silver Beast");
static const u8 sText_QuestShiningBeastDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit the Whirl Islands on Route 41\nto seek LUGIA.");

static const struct QuestJournalEntry sQuestJournalEntries[] =
{
    {
        .title = sText_QuestPalletTitle,
        .description = sText_QuestPalletDesc,
        .flagStarted = FLAG_QUEST_PALLET_TOWN_STARTED,
        .flagCompleted = FLAG_QUEST_PALLET_TOWN_COMPLETED,
    },
    {
        .title = sText_QuestViridianTitle,
        .description = sText_QuestViridianDesc,
        .flagStarted = FLAG_QUEST_VIRIDIAN_GYM_STARTED,
        .flagCompleted = FLAG_QUEST_VIRIDIAN_GYM_COMPLETED,
    },
    {
        .title = sText_QuestPewterTitle,
        .description = sText_QuestPewterDesc,
        .flagStarted = FLAG_QUEST_PEWTER_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_PEWTER_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestBrockTitle,
        .description = sText_QuestBrockDesc,
        .flagStarted = FLAG_QUEST_BROCK_STARTED,
        .flagCompleted = FLAG_QUEST_BROCK_COMPLETED,
    },
    {
        .title = sText_QuestMtMoonTitle,
        .description = sText_QuestMtMoonDesc,
        .flagStarted = FLAG_QUEST_MT_MOON_STARTED,
        .flagCompleted = FLAG_QUEST_MT_MOON_COMPLETED,
    },
    {
        .title = sText_QuestCeruleanNPCsTitle,
        .description = sText_QuestCeruleanNPCsDesc,
        .flagStarted = FLAG_QUEST_CERULEAN_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_CERULEAN_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestCeruleanWesTitle,
        .description = sText_QuestCeruleanWesDesc,
        .flagStarted = FLAG_QUEST_CERULEAN_WES_STARTED,
        .flagCompleted = FLAG_QUEST_CERULEAN_WES_COMPLETED,
    },
    {
        .title = sText_QuestCapeWesTitle,
        .description = sText_QuestCapeWesDesc,
        .flagStarted = FLAG_QUEST_CAPE_WES_STARTED,
        .flagCompleted = FLAG_QUEST_CAPE_WES_COMPLETED,
    },
    {
        .title = sText_QuestTalkWesTitle,
        .description = sText_QuestTalkWesDesc,
        .flagStarted = FLAG_QUEST_TALK_WES_STARTED,
        .flagCompleted = FLAG_QUEST_TALK_WES_COMPLETED,
    },
    {
        .title = sText_QuestTalkTeamTitle,
        .description = sText_QuestTalkTeamDesc,
        .flagStarted = FLAG_QUEST_TALK_TEAM_STARTED,
        .flagCompleted = FLAG_QUEST_TALK_TEAM_COMPLETED,
    },
    {
        .title = sText_QuestKukuiShadowTitle,
        .description = sText_QuestKukuiShadowDesc,
        .flagStarted = FLAG_QUEST_KUKUI_SHADOW_STARTED,
        .flagCompleted = FLAG_QUEST_KUKUI_SHADOW_COMPLETED,
    },
    {
        .title = sText_QuestSnagMachineTitle,
        .description = sText_QuestSnagMachineDesc,
        .flagStarted = FLAG_QUEST_SNAG_MACHINE_STARTED,
        .flagCompleted = FLAG_QUEST_SNAG_MACHINE_COMPLETED,
    },
    {
        .title = sText_QuestShadowTrainerTitle,
        .description = sText_QuestShadowTrainerDesc,
        .flagStarted = FLAG_QUEST_SHADOW_TRAINER_STARTED,
        .flagCompleted = FLAG_QUEST_SHADOW_TRAINER_COMPLETED,
    },
    {
        .title = sText_QuestMistyTitle,
        .description = sText_QuestMistyDesc,
        .flagStarted = FLAG_QUEST_DEFEAT_MISTY_STARTED,
        .flagCompleted = FLAG_QUEST_DEFEAT_MISTY_COMPLETED,
    },
    {
        .title = sText_QuestRoute9GuardsTitle,
        .description = sText_QuestRoute9GuardsDesc,
        .flagStarted = FLAG_QUEST_ROUTE9_GUARDS_STARTED,
        .flagCompleted = FLAG_QUEST_ROUTE9_GUARDS_COMPLETED,
    },
    {
        .title = sText_QuestPlasmaTunnelTitle,
        .description = sText_QuestPlasmaTunnelDesc,
        .flagStarted = FLAG_QUEST_PLASMA_TUNNEL_STARTED,
        .flagCompleted = FLAG_QUEST_PLASMA_TUNNEL_COMPLETED,
    },
    {
        .title = sText_QuestVioletNPCsTitle,
        .description = sText_QuestVioletNPCsDesc,
        .flagStarted = FLAG_QUEST_VIOLET_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_VIOLET_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestFalknerTitle,
        .description = sText_QuestFalknerDesc,
        .flagStarted = FLAG_QUEST_DEFEAT_FALKNER_STARTED,
        .flagCompleted = FLAG_QUEST_DEFEAT_FALKNER_COMPLETED,
    },
    {
        .title = sText_QuestKurtTitle,
        .description = sText_QuestKurtDesc,
        .flagStarted = FLAG_QUEST_KURT_APRICOT_STARTED,
        .flagCompleted = FLAG_QUEST_KURT_APRICOT_COMPLETED,
    },
    {
        .title = sText_QuestAzaleaNPCsTitle,
        .description = sText_QuestAzaleaNPCsDesc,
        .flagStarted = FLAG_QUEST_AZALEA_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_AZALEA_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestBugsyTitle,
        .description = sText_QuestBugsyDesc,
        .flagStarted = FLAG_QUEST_DEFEAT_BUGSY_STARTED,
        .flagCompleted = FLAG_QUEST_DEFEAT_BUGSY_COMPLETED,
    },
    {
        .title = sText_QuestSlowpokeWellTitle,
        .description = sText_QuestSlowpokeWellDesc,
        .flagStarted = FLAG_QUEST_SLOWPOKE_WELL_FLARE_STARTED,
        .flagCompleted = FLAG_QUEST_SLOWPOKE_WELL_FLARE_COMPLETED,
    },
    {
        .title = sText_QuestCherrygroveNPCsTitle,
        .description = sText_QuestCherrygroveNPCsDesc,
        .flagStarted = FLAG_QUEST_CHERRYGROVE_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_CHERRYGROVE_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestNewBarkNPCsTitle,
        .description = sText_QuestNewBarkNPCsDesc,
        .flagStarted = FLAG_QUEST_NEW_BARK_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_NEW_BARK_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestGoldsMomTitle,
        .description = sText_QuestGoldsMomDesc,
        .flagStarted = FLAG_QUEST_GOLDS_MOM_STARTED,
        .flagCompleted = FLAG_QUEST_GOLDS_MOM_COMPLETED,
    },
    {
        .title = sText_QuestBackToHQTitle,
        .description = sText_QuestBackToHQDesc,
        .flagStarted = FLAG_QUEST_BACK_TO_HQ_STARTED,
        .flagCompleted = FLAG_QUEST_BACK_TO_HQ_COMPLETED,
    },
    {
        .title = sText_QuestThunderbirdTitle,
        .description = sText_QuestThunderbirdDesc,
        .flagStarted = FLAG_QUEST_THUNDERBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_THUNDERBIRD_COMPLETED,
    },
    {
        .title = sText_QuestIcebirdTitle,
        .description = sText_QuestIcebirdDesc,
        .flagStarted = FLAG_QUEST_ICEBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_ICEBIRD_COMPLETED,
    },
    {
        .title = sText_QuestFirebirdTitle,
        .description = sText_QuestFirebirdDesc,
        .flagStarted = FLAG_QUEST_FIREBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_FIREBIRD_COMPLETED,
    },
    {
        .title = sText_QuestPhoenixTitle,
        .description = sText_QuestPhoenixDesc,
        .flagStarted = FLAG_QUEST_PHOENIX_STARTED,
        .flagCompleted = FLAG_QUEST_PHOENIX_COMPLETED,
    },
    {
        .title = sText_QuestShiningBeastTitle,
        .description = sText_QuestShiningBeastDesc,
        .flagStarted = FLAG_QUEST_SHINING_BEAST_STARTED,
        .flagCompleted = FLAG_QUEST_SHINING_BEAST_COMPLETED,
    },
};

static const u32 *const sQuestJournalCursorMaps[] =
{
    gMapOptionMenu0,
    gMapOptionMenu1,
    gMapOptionMenu2,
    gMapOptionMenu3,
    gMapOptionMenu4,
    gMapOptionMenu5,
};

static const u8 sQuestJournalDescriptionTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_LIGHT_GRAY,
};

static const struct WindowTemplate sQuestJournalWinTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 20,
        .paletteNum = 5,
        .baseBlock = 0
    },
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 14,
        .width = 30,
        .height = 6,
        .paletteNum = 14,
        .baseBlock = 0
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sQuestJournalBgTemplates[] =
{
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 1,
       .charBaseIndex = 0,
       .mapBaseIndex = 7,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   },
   {
       .bg = 2,
       .charBaseIndex = 0,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   }
};

static EWRAM_DATA u8 sQuestJournalEntryCount = 0;
static EWRAM_DATA u8 sQuestJournalEntryIds[QUEST_JOURNAL_MAX_ENTRIES];
static EWRAM_DATA u8 sQuestJournalMarkingSpriteIds[QUEST_JOURNAL_MARKING_ICON_COUNT];
static EWRAM_DATA u8 sQuestJournalEntryMarkingSpriteIds[QUEST_JOURNAL_MAX_ENTRIES];
static EWRAM_DATA u8 sQuestJournalScrollTop = 0;
static EWRAM_DATA u8 sQuestJournalTab = QUEST_JOURNAL_TAB_ALL;
static EWRAM_DATA bool8 sQuestJournalEntryPinned[ARRAY_COUNT(sQuestJournalEntries)];

void CB2_OpenQuestJournal(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sQuestJournalBgTemplates, ARRAY_COUNT(sQuestJournalBgTemplates));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        InitWindows(sQuestJournalWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(2, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0xE0, 0x20);
        gMain.state++;
        break;
    case 5:
        LZ77UnCompVram(gTilesOptionMenu, (void *)VRAM);
        gMain.state++;
        break;
    case 6:
        LZ77UnCompVram(gMapOptionMenu0, (void *)(VRAM + 0x3800));
        gMain.state++;
        break;
    case 7:
        LoadPalette(gPalOptionMenu, 0x50, 0xE0);
        gMain.state++;
        break;
    case 8:
        sQuestJournalTab = QUEST_JOURNAL_TAB_ALL;
        QuestJournal_BuildEntryList();
        sQuestJournalScrollTop = 0;
        PutWindowTilemap(0);
        QuestJournal_DrawTexts(0);
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(1);
        QuestJournal_DrawFrame();
        QuestJournal_CreateLegendIcons();
        QuestJournal_CreateEntryIcons();
        QuestJournal_UpdateEntryIcons();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_QuestJournalFadeIn, 0);

        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        QuestJournal_LoadCursorMap(0);
        CopyWindowToVram(0, COPYWIN_BOTH);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
        SetVBlankCallback(QuestJournal_VBlankCB);
        SetMainCallback2(QuestJournal_MainCB2);
        return;
    }
}

static void QuestJournal_MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void QuestJournal_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_QuestJournalFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_QuestJournalHandleInput;
}

static void Task_QuestJournalHandleInput(u8 taskId)
{
    u8 selection = gTasks[taskId].data[0];
    u8 top = gTasks[taskId].data[1];
    u8 i;
    u8 entryId;

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_QuestJournalFadeOut;
        return;
    }

    if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        QuestJournal_SetTab(taskId, (sQuestJournalTab + 1) % QUEST_JOURNAL_TAB_COUNT);
        return;
    }

    if (JOY_NEW(SELECT_BUTTON))
    {
        if (sQuestJournalEntryCount == 0)
            return;

        PlaySE(SE_SELECT);
        entryId = sQuestJournalEntryIds[selection];
        sQuestJournalEntryPinned[entryId] ^= 1;
        QuestJournal_BuildEntryList();

        selection = 0;
        for (i = 0; i < sQuestJournalEntryCount; i++)
        {
            if (sQuestJournalEntryIds[i] == entryId)
            {
                selection = i;
                break;
            }
        }

        if (sQuestJournalEntryCount > QUEST_JOURNAL_VISIBLE_ENTRIES)
        {
            if (selection < top)
                top = selection;
            else if (selection >= top + QUEST_JOURNAL_VISIBLE_ENTRIES)
                top = selection - (QUEST_JOURNAL_VISIBLE_ENTRIES - 1);
        }
        else
        {
            top = 0;
        }

        gTasks[taskId].data[0] = selection;
        gTasks[taskId].data[1] = top;
        sQuestJournalScrollTop = top;
        QuestJournal_LoadCursorMap(selection - top);
        QuestJournal_DrawTexts(selection);
        return;
    }

    if (sQuestJournalEntryCount <= 1)
        return;

    if (JOY_NEW(DPAD_UP))
    {
        selection = (selection == 0) ? (sQuestJournalEntryCount - 1) : (selection - 1);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        selection = (selection + 1) % sQuestJournalEntryCount;
        PlaySE(SE_SELECT);
    }
    else
    {
        return;
    }

    gTasks[taskId].data[0] = selection;
    if (sQuestJournalEntryCount > QUEST_JOURNAL_VISIBLE_ENTRIES)
    {
        if (selection < top)
            top = selection;
        else if (selection >= top + QUEST_JOURNAL_VISIBLE_ENTRIES)
            top = selection - (QUEST_JOURNAL_VISIBLE_ENTRIES - 1);
    }
    else
    {
        top = 0;
    }

    gTasks[taskId].data[1] = top;
    sQuestJournalScrollTop = top;
    QuestJournal_LoadCursorMap(selection - top);
    QuestJournal_DrawTexts(selection);
}

static void Task_QuestJournalFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
        gTasks[taskId].func = Task_QuestJournalExit;
    }
}

static void Task_QuestJournalExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        QuestJournal_DestroyEntryIcons();
        QuestJournal_DestroyLegendIcons();
        DestroyTask(taskId);
        SetVBlankCallback(NULL);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void QuestJournal_BuildEntryList(void)
{
    u8 i;

    sQuestJournalEntryCount = 0;
    for (i = 0; i < QUEST_JOURNAL_MAX_ENTRIES; i++)
        sQuestJournalEntryMarkingSpriteIds[i] = MAX_SPRITES;
    if (sQuestJournalTab == QUEST_JOURNAL_TAB_ALL)
    {
        QuestJournal_AddEntriesAllPinned(TRUE);
        QuestJournal_AddEntriesAllPinned(FALSE);
    }
    else if (sQuestJournalTab == QUEST_JOURNAL_TAB_ACTIVE)
    {
        QuestJournal_AddEntriesByStatePinned(QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE, TRUE);
        QuestJournal_AddEntriesByStatePinned(QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE, FALSE);
    }
    else
    {
        QuestJournal_AddEntriesByStatePinned(QUEST_JOURNAL_ENTRY_STATE_COMPLETE, TRUE);
        QuestJournal_AddEntriesByStatePinned(QUEST_JOURNAL_ENTRY_STATE_COMPLETE, FALSE);
    }
}

static void QuestJournal_AddEntriesByStatePinned(u8 state, bool8 pinned)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sQuestJournalEntries); i++)
    {
        const struct QuestJournalEntry *entry = &sQuestJournalEntries[i];

        if (sQuestJournalEntryCount >= QUEST_JOURNAL_MAX_ENTRIES)
            break;
        if (sQuestJournalEntryPinned[i] != pinned)
            continue;
        if (QuestJournal_GetEntryState(entry) != state)
            continue;

        sQuestJournalEntryIds[sQuestJournalEntryCount++] = i;
    }
}

static void QuestJournal_AddEntriesAllPinned(bool8 pinned)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sQuestJournalEntries); i++)
    {
        if (sQuestJournalEntryCount >= QUEST_JOURNAL_MAX_ENTRIES)
            break;
        if (sQuestJournalEntryPinned[i] != pinned)
            continue;

        sQuestJournalEntryIds[sQuestJournalEntryCount++] = i;
    }
}

static void QuestJournal_DrawTexts(u8 selection)
{
    u8 top = sQuestJournalScrollTop;
    u8 i;
    const u8 *tabTitle;
    const u8 *tabPage;
    u8 tabHintX;
    u8 pageX;
    u32 pageWidth;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    switch (sQuestJournalTab)
    {
    case QUEST_JOURNAL_TAB_ACTIVE:
        tabTitle = sText_QuestTabActive;
        tabPage = sText_QuestTabPage2;
        break;
    case QUEST_JOURNAL_TAB_INACTIVE:
        tabTitle = sText_QuestTabInactive;
        tabPage = sText_QuestTabPage3;
        break;
    default:
        tabTitle = sText_QuestTabAll;
        tabPage = sText_QuestTabPage1;
        break;
    }

    AddTextPrinterParameterized(0, FONT_NORMAL, tabTitle, 8, 1, TEXT_SPEED_FF, NULL);
    tabHintX = GetStringRightAlignXOffset(FONT_NORMAL, sText_QuestTabHint, 228);
    pageWidth = GetStringWidth(FONT_NORMAL, tabPage, 0);
    pageX = (tabHintX > pageWidth + 4) ? tabHintX - pageWidth - 4 : 0;
    AddTextPrinterParameterized(0, FONT_NORMAL, tabPage, pageX, 1, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_QuestTabHint, tabHintX, 1, TEXT_SPEED_FF, NULL);

    if (sQuestJournalEntryCount == 0)
    {
        AddTextPrinterParameterized(0, FONT_NORMAL, sText_QuestNone, 8, 17, TEXT_SPEED_FF, NULL);
        QuestJournal_ShowDescription(sText_QuestNone);
        CopyWindowToVram(0, COPYWIN_BOTH);
        return;
    }

    QuestJournal_SetDescription(selection);
    for (i = 0; i < QUEST_JOURNAL_VISIBLE_ENTRIES; i++)
    {
        u8 entryIndex = top + i;
        const struct QuestJournalEntry *entry;
        u8 entryId;
        const u8 *statusText = NULL;
        u8 line[96];
        u8 statusX;
        u8 state;

        if (entryIndex >= sQuestJournalEntryCount)
            break;

        entryId = sQuestJournalEntryIds[entryIndex];
        entry = &sQuestJournalEntries[entryId];
        if (sQuestJournalEntryPinned[entryId])
            StringCopy(line, sText_QuestEntryStylePinned);
        else
            StringCopy(line, sText_QuestEntryStyle);
        if (QuestJournal_IsEntryUnlocked(entry))
            StringAppend(line, entry->title);
        else
            StringAppend(line, sText_QuestLockedTitle);
        AddTextPrinterParameterized(0, FONT_NORMAL, line, QUEST_JOURNAL_ENTRY_TEXT_X, (i * 16) + 17, TEXT_SPEED_FF, NULL);

        if (QuestJournal_IsEntryUnlocked(entry))
        {
            state = QuestJournal_GetEntryState(entry);
            if (state == QUEST_JOURNAL_ENTRY_STATE_COMPLETE)
                statusText = sText_QuestStatusDone;
            else if (state == QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE)
                statusText = sText_QuestStatusActive;
        }

        if (statusText != NULL)
        {
            statusX = GetStringRightAlignXOffset(FONT_NORMAL, statusText, 228);
            AddTextPrinterParameterized(0, FONT_NORMAL, statusText, statusX, (i * 16) + 17, TEXT_SPEED_FF, NULL);
        }
    }

    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void QuestJournal_SetDescription(u8 selection)
{
    const struct QuestJournalEntry *entry;

    if (sQuestJournalEntryCount == 0)
    {
        QuestJournal_ShowDescription(sText_QuestNone);
        return;
    }

    if (selection >= sQuestJournalEntryCount)
        selection = 0;

    entry = &sQuestJournalEntries[sQuestJournalEntryIds[selection]];
    if (QuestJournal_IsEntryUnlocked(entry))
        QuestJournal_ShowDescription(entry->description);
    else
        QuestJournal_ShowDescription(sText_QuestLockedDesc);
}

static void QuestJournal_ShowDescription(const u8 *text)
{
    u8 dst[160];
    u16 i;

    for (i = 0; *text != EOS && i <= 160; i++)
        dst[i] = *(text++);

    dst[2] = TEXT_COLOR_WHITE;
    dst[i] = EOS;
    AddTextPrinterParameterized4(0, FONT_NORMAL, 12, 120, 0, 0, sQuestJournalDescriptionTextColors, 0, dst);
    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void QuestJournal_LoadCursorMap(u8 selection)
{
    if (selection >= ARRAY_COUNT(sQuestJournalCursorMaps))
        selection = 0;

    LZ77UnCompVram(sQuestJournalCursorMaps[selection], (void *)(VRAM + 0x3800));
    QuestJournal_HideButtonIcons();
}

static void QuestJournal_DrawFrame(void)
{
    FillBgTilemapBufferRect(2, 0x1A2, 0, 14, 1, 1, 14);
    FillBgTilemapBufferRect(2, 0x1A3, 1, 14, 28, 1, 14);
    FillBgTilemapBufferRect(2, 0x1A4, 29, 14, 1, 1, 14);
    FillBgTilemapBufferRect(2, 0x1A5, 0, 15, 1, 4, 14);
    FillBgTilemapBufferRect(2, 0x1A6, 1, 15, 28, 4, 14);
    FillBgTilemapBufferRect(2, 0x1A7, 29, 15, 1, 4, 14);
    FillBgTilemapBufferRect(2, 0x1A8, 0, 19, 1, 1, 14);
    FillBgTilemapBufferRect(2, 0x1A9, 1, 19, 28, 1, 14);
    FillBgTilemapBufferRect(2, 0x1AA, 29, 19, 1, 1, 14);

    CopyBgTilemapBufferToVram(2);
}

static void QuestJournal_CreateLegendIcons(void)
{
    u8 i;

    for (i = 0; i < QUEST_JOURNAL_MARKING_ICON_COUNT; i++)
        sQuestJournalMarkingSpriteIds[i] = MAX_SPRITES;

    (void)sQuestJournalMarkingsGfx;
    (void)sQuestJournalLegendPal;
    (void)sQuestJournalMarkingTemplate;
}

static void QuestJournal_CreateEntryIcons(void)
{
    u8 i;

    for (i = 0; i < QUEST_JOURNAL_MAX_ENTRIES; i++)
        sQuestJournalEntryMarkingSpriteIds[i] = MAX_SPRITES;
}

static void QuestJournal_DestroyLegendIcons(void)
{
    u8 i;

    for (i = 0; i < QUEST_JOURNAL_MARKING_ICON_COUNT; i++)
    {
        if (sQuestJournalMarkingSpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sQuestJournalMarkingSpriteIds[i]]);
            sQuestJournalMarkingSpriteIds[i] = MAX_SPRITES;
        }
    }
}

static void QuestJournal_DestroyEntryIcons(void)
{
    u8 i;

    for (i = 0; i < QUEST_JOURNAL_MAX_ENTRIES; i++)
    {
        if (sQuestJournalEntryMarkingSpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sQuestJournalEntryMarkingSpriteIds[i]]);
            sQuestJournalEntryMarkingSpriteIds[i] = MAX_SPRITES;
        }
    }
}

static void QuestJournal_UpdateEntryIcons(void)
{
    return;
}

static void QuestJournal_HideButtonIcons(void)
{
    u16 *tilemap = (u16 *)(VRAM + 0x3800);
    u16 row0Fill = tilemap[0];
    u16 row1Fill = tilemap[32];
    const u8 cols[] = {16, 23};
    u8 i;

    for (i = 0; i < ARRAY_COUNT(cols); i++)
    {
        tilemap[cols[i]] = row0Fill;
        tilemap[32 + cols[i]] = row1Fill;
    }

    DmaClear16(3, (void *)(VRAM + (0x20 * 0x11)), 0x20 * 4);
}

static bool8 QuestJournal_IsEntryUnlocked(const struct QuestJournalEntry *entry)
{
    return FlagGet(entry->flagStarted) || FlagGet(entry->flagCompleted);
}

static u8 QuestJournal_GetEntryState(const struct QuestJournalEntry *entry)
{
    if (FlagGet(entry->flagCompleted))
        return QUEST_JOURNAL_ENTRY_STATE_COMPLETE;
    if (FlagGet(entry->flagStarted))
        return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;

    return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
}

static void QuestJournal_SetTab(u8 taskId, u8 tab)
{
    if (sQuestJournalTab == tab)
        return;

    sQuestJournalTab = tab;
    QuestJournal_BuildEntryList();
    sQuestJournalScrollTop = 0;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    QuestJournal_LoadCursorMap(0);
    QuestJournal_DrawTexts(0);
}
