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
#include "gimmighoul_signpost.h"
#include "sprite.h"
#include "item.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/songs.h"

#define TEXT_SPEED_FF 0xFF
#define QUEST_JOURNAL_MAX_ENTRIES 150
#define QUEST_JOURNAL_VISIBLE_ENTRIES 6
#define QUEST_JOURNAL_ENTRY_TEXT_X 20
#define QUEST_JOURNAL_ENTRY_ICON_X 12
#define QUEST_JOURNAL_ENTRY_ICON_Y_BASE 24
#define QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES 6

#define TAG_QUEST_JOURNAL_MARKINGS 0x1200
#define PALTAG_QUEST_JOURNAL_MARKINGS 0x1200

struct QuestJournalEntry
{
    const u8 *title;
    const u8 *description;
    u16 flagStarted;
    u16 flagCompleted;
    u16 flagReveal;
};

struct GimmighoulJournalEntry
{
    bool8 isChest;
    u8 mapGroup;
    u8 mapNum;
    u16 chestFlag;
    u8 coins;
    const u8 *shortName;
    const u8 *locationName;
};

struct OddKeystoneJournalEntry
{
    u16 discoveredFlag;
    const u8 *shortName;
    const u8 *locationName;
    const u8 *trainerName;
};

struct ZygardeJournalEntry
{
    u16 discoveredFlag;
    bool8 isCore;
    const u8 *shortName;
    const u8 *locationName;
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

enum
{
    QUEST_JOURNAL_MODE_LIST,
    QUEST_JOURNAL_MODE_GIMMI_DETAIL,
    QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL,
    QUEST_JOURNAL_MODE_ZYGARDE_DETAIL,
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
static void QuestJournal_DrawListTexts(u8 selection);
static void QuestJournal_DrawGimmighoulDetailTexts(u8 selection);
static void QuestJournal_DrawOddKeystoneDetailTexts(u8 selection);
static void QuestJournal_DrawZygardeDetailTexts(u8 selection);
static bool8 QuestJournal_IsSpecialDetailQuestSelected(u8 selection);
static u8 QuestJournal_GetCurrentSelection(u8 taskId);
static u8 QuestJournal_GetCurrentTop(u8 taskId);
static void QuestJournal_SetCurrentSelection(u8 taskId, u8 selection);
static void QuestJournal_SetCurrentTop(u8 taskId, u8 top);
static void QuestJournal_EnterGimmighoulDetail(u8 taskId);
static void QuestJournal_ExitGimmighoulDetail(u8 taskId);
static void QuestJournal_EnterOddKeystoneDetail(u8 taskId);
static void QuestJournal_ExitOddKeystoneDetail(u8 taskId);
static void QuestJournal_EnterZygardeDetail(u8 taskId);
static void QuestJournal_ExitZygardeDetail(u8 taskId);
static void QuestJournal_GetGimmighoulDisplayName(u8 *dst, u8 entryIndex);
static void QuestJournal_GetGimmighoulDescription(u8 *dst, u8 entryIndex);
static bool8 QuestJournal_IsGimmighoulEntryDiscovered(u8 entryIndex);
static u16 QuestJournal_GetGimmighoulFoundCount(void);
static void QuestJournal_GetOddKeystoneDisplayName(u8 *dst, u8 entryIndex);
static void QuestJournal_GetOddKeystoneDescription(u8 *dst, u8 entryIndex);
static bool8 QuestJournal_IsOddKeystoneEntryDiscovered(u8 entryIndex);
static u16 QuestJournal_GetOddKeystoneFoundCount(void);
static void QuestJournal_GetZygardeDisplayName(u8 *dst, u8 entryIndex);
static void QuestJournal_GetZygardeDescription(u8 *dst, u8 entryIndex);
static bool8 QuestJournal_IsZygardeEntryDiscovered(u8 entryIndex);
static u16 QuestJournal_GetZygardeFoundCount(void);
static bool8 QuestJournal_IsCurrentModeDetail(void);

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
static const u8 sText_GimmighoulHeaderCount[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}");
static const u8 sText_QuestStatusActive[] = _("{COLOR RED}{HIGHLIGHT TRANSPARENT}Active");
static const u8 sText_QuestStatusDone[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}Done");
static const u8 sText_QuestNone[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}No quests yet.");
static const u8 sText_QuestEntryStyle[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}");
static const u8 sText_QuestEntryStylePinned[] = _("{COLOR 6}{HIGHLIGHT TRANSPARENT}");
static const u8 sText_QuestLockedTitle[] = _("-------");
static const u8 sText_QuestLockedDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Quest not unlocked yet.");
static const u8 sText_QuestAButtonIcon[] = _("{A_BUTTON}");
static const u8 sText_GimmighoulUnknownName[] = _("??????");
static const u8 sText_GimmighoulUnknownLocation[] = _("??????");
static const u8 sText_GimmighoulSignPrefix[] = _("Sign - ");
static const u8 sText_GimmighoulChestPrefix[] = _("Chest - ");
static const u8 sText_GimmighoulTotalCount[] = _("/30");
static const u8 sText_GimmighoulListNumberSuffix[] = _(". ");
static const u8 sText_GimmighoulLocationPrefix[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Location: ");
static const u8 sText_GimmighoulDescriptionNewLine[] = _("\n");
static const u8 sText_GimmighoulUnknownCoins[] = _("?");
static const u8 sText_GimmighoulCoinsSuffix[] = _(" coins obtained.");
static const u8 sText_OddKeystoneTotalCount[] = _("/32");
static const u8 sText_OddKeystoneUnknownName[] = _("??????");
static const u8 sText_OddKeystoneUnknownLocation[] = _("??????");
static const u8 sText_OddKeystoneUnknownTrainer[] = _("??????");
static const u8 sText_OddKeystoneDescriptionNewLine[] = _("\n");
static const u8 sText_OddKeystoneDefeatedPrefix[] = _("defeated ");
static const u8 sText_ZygardeTotalCount[] = _("/100");
static const u8 sText_ZygardeUnknownName[] = _("??????");
static const u8 sText_ZygardeUnknownLocation[] = _("??????");
static const u8 sText_ZygardeCellPrefix[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Cell found at ");
static const u8 sText_ZygardeCorePrefix[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Core found at ");
static const u8 sText_QuestPalletTitle[] = _("NPCs in Pallet Town");
static const u8 sText_QuestPalletDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}It's important to gather\ninformation from everyone.");
static const u8 sText_QuestViridianTitle[] = _("Go Visit Viridian Gym");
static const u8 sText_QuestViridianDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Viridian seems to be in trouble.\nSeek Gary at Viridian Gym.");
static const u8 sText_QuestPewterTitle[] = _("NPCs in Pewter City");
static const u8 sText_QuestPewterDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nPewter City. Might help!");
static const u8 sText_QuestGimmighoulTitle[] = _("Gimmi my ¥");
static const u8 sText_QuestGimmighoulDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Locate Gimmighoul's around sign\nposts and as static encounters.");
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
static const u8 sText_QuestKukuiShadowDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}There is a certain {COLOR BLUE}Shadow POKéMON{COLOR 1}\nthat Kukui needs.");
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
static const u8 sText_Quest100PowerTitle[] = _("100% Power");
static const u8 sText_Quest100PowerDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Collect Zygarde cells/cores\nscattered across the regions.");
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
static const u8 sText_QuestStartersStolenTitle[] = _("Starters Stolen!");
static const u8 sText_QuestStartersStolenDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Someone has stolen the remaining\nstarter POKeMON! Track them down!");
static const u8 sText_QuestThunderbirdTitle[] = _("The Thunderbird");
static const u8 sText_QuestThunderbirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit the Power Plant on Route 10\nto seek ZAPDOS.");
static const u8 sText_QuestEricaTitle[] = _("Erica, Natures Princess");
static const u8 sText_QuestEricaDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Conquer Celadon Gym and earn\nErica's RAINBOW BADGE!");
static const u8 sText_QuestMegaMomentsTitle[] = _("Mega Moments");
static const u8 sText_QuestMegaMomentsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Calem & Serena are heading to\nCeladon. Find them!");
static const u8 sText_QuestAlolaLillieTitle[] = _("Alola Lillie!");
static const u8 sText_QuestAlolaLillieDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Help Lillie reach VERMILION and\ncheck on the S.S. ANNE.");
static const u8 sText_QuestLtSurgeTitle[] = _("Lt Surge...");
static const u8 sText_QuestLtSurgeDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Surge is very upset and might be a\ntough challenge. Snatch that\nTHUNDERBADGE by force.");
static const u8 sText_QuestNebbyPowerhouseTitle[] = _("Nebby The PowerHouse");
static const u8 sText_QuestNebbyPowerhouseDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Bring Nebby to Birch to help\nfix the TIME MACHINE.");
static const u8 sText_QuestWhitneyTitle[] = _("Whitney The MooMoo Tank");
static const u8 sText_QuestWhitneyDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Show Whitney that the PLAIN BADGE\nis not worthy of her!");
static const u8 sText_QuestCipherTakeoverTitle[] = _("Cipher's Takeover Revealed");
static const u8 sText_QuestCipherTakeoverDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}CIPHER is taking over RADIO\nTOWER. Find who's responsible!");
static const u8 sText_QuestMachinePartTitle[] = _("The Machine Part");
static const u8 sText_QuestMachinePartDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Maybe a Plasma Grunt has a clue\nto help find the missing part.");
static const u8 sText_QuestIcebirdTitle[] = _("The Icebird");
static const u8 sText_QuestIcebirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit Seafoam Islands south of\nFuchsia to seek ARTICUNO.");
static const u8 sText_QuestFirebirdTitle[] = _("The Firebird");
static const u8 sText_QuestFirebirdDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit MT. SILVER west of the\nRECEPTION GATE to seek MOLTRES.");
static const u8 sText_QuestPhoenixTitle[] = _("The Life Giving Phoenix");
static const u8 sText_QuestPhoenixDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit Tin Tower in Ecruteak City\nto seek HO-OH.");
static const u8 sText_QuestShiningBeastTitle[] = _("The Shining Silver Beast");
static const u8 sText_QuestShiningBeastDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Visit the Whirl Islands on Route 41\nto seek LUGIA.");
static const u8 sText_QuestLavenderNPCsTitle[] = _("NPCs in Lavender Town");
static const u8 sText_QuestLavenderNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nLavender Town. Might help!");
static const u8 sText_QuestOddKeystoneTitle[] = _("The Odd Keystone");
static const u8 sText_QuestOddKeystoneDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Whispers can be heard from the\nkeystone. Find out what it wants!");
static const u8 sText_ZygardeShort_RuinsLab[] = _("Ruins Lab");
static const u8 sText_ZygardeShort_Pewter[] = _("Pewter");
static const u8 sText_ZygardeShort_Route2[] = _("Route 2");
static const u8 sText_ZygardeShort_ViridianForest[] = _("Viridian F.");
static const u8 sText_ZygardeShort_MtMoon[] = _("Mt. Moon");
static const u8 sText_ZygardeShort_Celadon[] = _("Celadon");
static const u8 sText_ZygardeShort_Route8[] = _("Route 8");
static const u8 sText_ZygardeShort_Saffron[] = _("Saffron");
static const u8 sText_ZygardeShort_SaffronTunnel[] = _("Saffron Tun.");
static const u8 sText_ZygardeShort_SaffronTunnelSW[] = _("Saffron Tun SW");
static const u8 sText_ZygardeShort_Vermilion[] = _("Vermilion");
static const u8 sText_ZygardeShort_Route11[] = _("Route 11");
static const u8 sText_ZygardeShort_Route12[] = _("Route 12");
static const u8 sText_ZygardeShort_Route13[] = _("Route 13");
static const u8 sText_ZygardeShort_Route17[] = _("Route 17");
static const u8 sText_ZygardeShort_Route20[] = _("Route 20");
static const u8 sText_ZygardeShort_Cinnabar[] = _("Cinnabar");
static const u8 sText_ZygardeShort_Digletts[] = _("Diglett Cave");
static const u8 sText_ZygardeShort_Route21[] = _("Route 21");
static const u8 sText_ZygardeShort_CeruleanCave[] = _("Cerulean C.");
static const u8 sText_ZygardeShort_PowerPlant[] = _("Power Plant");
static const u8 sText_ZygardeShort_Fuchsia[] = _("Fuchsia");
static const u8 sText_ZygardeShort_PalletForest[] = _("Pallet For.");
static const u8 sText_ZygardeLoc_RuinsLab[] = _("Ruins of Alph Lab");
static const u8 sText_ZygardeLoc_Pewter[] = _("Pewter City");
static const u8 sText_ZygardeLoc_Route2[] = _("Route 2");
static const u8 sText_ZygardeLoc_ViridianForest[] = _("Viridian Forest");
static const u8 sText_ZygardeLoc_MtMoon[] = _("Mt. Moon Cave");
static const u8 sText_ZygardeLoc_Celadon[] = _("Celadon City");
static const u8 sText_ZygardeLoc_Route8[] = _("Route 8");
static const u8 sText_ZygardeLoc_Saffron[] = _("Saffron City");
static const u8 sText_ZygardeLoc_SaffronTunnel[] = _("Saffron Tunnel");
static const u8 sText_ZygardeLoc_SaffronTunnelSW[] = _("Saffron Tunnel SW");
static const u8 sText_ZygardeLoc_Vermilion[] = _("Vermilion City");
static const u8 sText_ZygardeLoc_Route11[] = _("Route 11");
static const u8 sText_ZygardeLoc_Route12[] = _("Route 12");
static const u8 sText_ZygardeLoc_Route13[] = _("Route 13");
static const u8 sText_ZygardeLoc_Route17[] = _("Route 17");
static const u8 sText_ZygardeLoc_Route20[] = _("Route 20");
static const u8 sText_ZygardeLoc_Cinnabar[] = _("Cinnabar Island");
static const u8 sText_ZygardeLoc_Digletts[] = _("Diglett's Cave Tunnel");
static const u8 sText_ZygardeLoc_Route21[] = _("Route 21 North");
static const u8 sText_ZygardeLoc_CeruleanCave[] = _("Cerulean Cave B1F");
static const u8 sText_ZygardeLoc_PowerPlant[] = _("Route 10 Power Plant Back");
static const u8 sText_ZygardeLoc_Fuchsia[] = _("Fuchsia City");
static const u8 sText_ZygardeLoc_PalletForest[] = _("Pallet Town Western Forest");
static const u8 sText_QuestCeladonNPCsTitle[] = _("NPCs in Celadon City");
static const u8 sText_QuestCeladonNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nCeladon City. Might help!");
static const u8 sText_QuestSaffronNPCsTitle[] = _("NPCs in Saffron City");
static const u8 sText_QuestSaffronNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nSaffron City. Might help!");
static const u8 sText_QuestVermilionNPCsTitle[] = _("NPCs in Vermilion City");
static const u8 sText_QuestVermilionNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nVermilion City. Might help!");
static const u8 sText_QuestGoldenrodCityInfoTitle[] = _("NPCs in Goldenrod City");
static const u8 sText_QuestGoldenrodCityInfoDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nGoldenrod City. Might help!");
static const u8 sText_QuestGoldenrodNPCsTitle[] = _("Peril In Goldenrod!");
static const u8 sText_QuestGoldenrodNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Investigate the Dept. Store\nBasement for clues on the Radio\nTower employees.");
static const u8 sText_QuestRustboroNPCsTitle[] = _("NPCs in Rustboro City");
static const u8 sText_QuestRustboroNPCsDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Learn about whats happening in\nRustboro City. Might help!");
static const u8 sText_QuestRockyRoxyTitle[] = _("Rocky Roxy... Right?");
static const u8 sText_QuestRockyRoxyDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Roxanne is different than before.\nNo matter, that stone badge\nbelongs on your trainer card!");
static const u8 sText_QuestFindBrendanMayTitle[] = _("Find Brendan and May");
static const u8 sText_QuestFindBrendanMayDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Brendan and May are in Hoenn.\nFind out what they know.");
static const u8 sText_QuestMoreToComeTitle[] = _("More to Come...");
static const u8 sText_QuestMoreToComeDesc[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Talk to Brendan in the Devon\nCorp. Building.");
static const u8 sText_GimmiShort_Pewter[] = _("Pewter");
static const u8 sText_GimmiShort_Route6[] = _("Rt 6");
static const u8 sText_GimmiShort_Route7[] = _("Rt 7");
static const u8 sText_GimmiShort_Route10[] = _("Rt 10");
static const u8 sText_GimmiShort_Route42[] = _("Rt 42");
static const u8 sText_GimmiShort_Route46[] = _("Rt 46");
static const u8 sText_GimmiShort_Route108[] = _("Rt 108");
static const u8 sText_GimmiShort_Route111[] = _("Rt 111");
static const u8 sText_GimmiShort_Route114[] = _("Rt 114");
static const u8 sText_GimmiShort_Route123[] = _("Rt 123");
static const u8 sText_GimmiShort_Celadon[] = _("Celadon");
static const u8 sText_GimmiShort_Fuchsia[] = _("Fuchsia");
static const u8 sText_GimmiShort_Saffron[] = _("Saffron");
static const u8 sText_GimmiShort_Indigo[] = _("Indigo");
static const u8 sText_GimmiShort_Blackthorn[] = _("Blackthorn");
static const u8 sText_GimmiShort_Goldenrod[] = _("Goldenrod");
static const u8 sText_GimmiShort_Azalea[] = _("Azalea");
static const u8 sText_GimmiShort_Olivine[] = _("Olivine");
static const u8 sText_GimmiShort_Cianwood[] = _("Cianwood");
static const u8 sText_GimmiShort_Ilex[] = _("Ilex");
static const u8 sText_GimmiShort_RuinsOutside[] = _("Ruins Outside");
static const u8 sText_GimmiShort_Littleroot[] = _("Littleroot");
static const u8 sText_GimmiShort_Mauville[] = _("Mauville");
static const u8 sText_GimmiShort_Slateport[] = _("Slateport");
static const u8 sText_GimmiShort_EverGrande[] = _("Ever Grande");
static const u8 sText_GimmiShort_LavenderSoul[] = _("Soul House");
static const u8 sText_GimmiShort_RuinsB1F[] = _("Ruins B1F");
static const u8 sText_GimmiShort_MtPyre[] = _("Mt. Pyre");
static const u8 sText_GimmiShort_Ship[] = _("Abandoned Ship");
static const u8 sText_GimmiShort_Whirl[] = _("Whirl Islands");
static const u8 sText_GimmiLoc_Pewter[] = _("Pewter City");
static const u8 sText_GimmiLoc_Route6[] = _("Route 6");
static const u8 sText_GimmiLoc_Route7[] = _("Route 7");
static const u8 sText_GimmiLoc_Route10[] = _("Route 10");
static const u8 sText_GimmiLoc_Route42[] = _("Route 42");
static const u8 sText_GimmiLoc_Route46[] = _("Route 46");
static const u8 sText_GimmiLoc_Route108[] = _("Route 108");
static const u8 sText_GimmiLoc_Route111[] = _("Route 111");
static const u8 sText_GimmiLoc_Route114[] = _("Route 114");
static const u8 sText_GimmiLoc_Route123[] = _("Route 123");
static const u8 sText_GimmiLoc_Celadon[] = _("Celadon City");
static const u8 sText_GimmiLoc_Fuchsia[] = _("Fuchsia City");
static const u8 sText_GimmiLoc_Saffron[] = _("Saffron City");
static const u8 sText_GimmiLoc_Indigo[] = _("Indigo Plateau");
static const u8 sText_GimmiLoc_Blackthorn[] = _("Blackthorn City");
static const u8 sText_GimmiLoc_Goldenrod[] = _("Goldenrod City");
static const u8 sText_GimmiLoc_Azalea[] = _("Azalea Town");
static const u8 sText_GimmiLoc_Olivine[] = _("Olivine City");
static const u8 sText_GimmiLoc_Cianwood[] = _("Cianwood City");
static const u8 sText_GimmiLoc_Ilex[] = _("Ilex Forest");
static const u8 sText_GimmiLoc_RuinsOutside[] = _("Ruins of Alph Outside");
static const u8 sText_GimmiLoc_Littleroot[] = _("Littleroot Town");
static const u8 sText_GimmiLoc_Mauville[] = _("Mauville City");
static const u8 sText_GimmiLoc_Slateport[] = _("Slateport City");
static const u8 sText_GimmiLoc_EverGrande[] = _("Ever Grande City");
static const u8 sText_GimmiLoc_LavenderSoul[] = _("Lavender Soul House");
static const u8 sText_GimmiLoc_RuinsB1F[] = _("Ruins of Alph B1F");
static const u8 sText_GimmiLoc_MtPyre[] = _("Mt. Pyre Summit");
static const u8 sText_GimmiLoc_Ship[] = _("Abandoned Ship Rooms 1F");
static const u8 sText_GimmiLoc_Whirl[] = _("Whirl Islands B1F");
static const u8 sText_OddKeystoneShort_CeladonRoof[] = _("Celadon Roof");
static const u8 sText_OddKeystoneShort_GoldenrodRoof[] = _("Goldenrod Roof");
static const u8 sText_OddKeystoneLoc_CeladonRoof[] = _("Celadon Department Roof");
static const u8 sText_OddKeystoneLoc_GoldenrodRoof[] = _("Goldenrod Dept. Store Roof");
static const u8 sText_OddKeystoneTrainer_Mara[] = _("MARA");
static const u8 sText_OddKeystoneTrainer_Mina[] = _("MINA");

static const struct GimmighoulJournalEntry sGimmighoulJournalEntries[] =
{
    { FALSE, MAP_GROUP(MAP_PEWTER_CITY), MAP_NUM(MAP_PEWTER_CITY), 0, 25, sText_GimmiShort_Pewter, sText_GimmiLoc_Pewter },
    { FALSE, MAP_GROUP(MAP_ROUTE6), MAP_NUM(MAP_ROUTE6), 0, 25, sText_GimmiShort_Route6, sText_GimmiLoc_Route6 },
    { FALSE, MAP_GROUP(MAP_ROUTE7), MAP_NUM(MAP_ROUTE7), 0, 25, sText_GimmiShort_Route7, sText_GimmiLoc_Route7 },
    { FALSE, MAP_GROUP(MAP_ROUTE10), MAP_NUM(MAP_ROUTE10), 0, 25, sText_GimmiShort_Route10, sText_GimmiLoc_Route10 },
    { FALSE, MAP_GROUP(MAP_ROUTE42), MAP_NUM(MAP_ROUTE42), 0, 25, sText_GimmiShort_Route42, sText_GimmiLoc_Route42 },
    { FALSE, MAP_GROUP(MAP_ROUTE46), MAP_NUM(MAP_ROUTE46), 0, 25, sText_GimmiShort_Route46, sText_GimmiLoc_Route46 },
    { FALSE, MAP_GROUP(MAP_ROUTE108), MAP_NUM(MAP_ROUTE108), 0, 25, sText_GimmiShort_Route108, sText_GimmiLoc_Route108 },
    { FALSE, MAP_GROUP(MAP_ROUTE111), MAP_NUM(MAP_ROUTE111), 0, 25, sText_GimmiShort_Route111, sText_GimmiLoc_Route111 },
    { FALSE, MAP_GROUP(MAP_ROUTE114), MAP_NUM(MAP_ROUTE114), 0, 25, sText_GimmiShort_Route114, sText_GimmiLoc_Route114 },
    { FALSE, MAP_GROUP(MAP_ROUTE123), MAP_NUM(MAP_ROUTE123), 0, 25, sText_GimmiShort_Route123, sText_GimmiLoc_Route123 },
    { FALSE, MAP_GROUP(MAP_CELADON_CITY), MAP_NUM(MAP_CELADON_CITY), 0, 25, sText_GimmiShort_Celadon, sText_GimmiLoc_Celadon },
    { FALSE, MAP_GROUP(MAP_FUCHSIA_CITY), MAP_NUM(MAP_FUCHSIA_CITY), 0, 25, sText_GimmiShort_Fuchsia, sText_GimmiLoc_Fuchsia },
    { FALSE, MAP_GROUP(MAP_SAFFRON_CITY), MAP_NUM(MAP_SAFFRON_CITY), 0, 25, sText_GimmiShort_Saffron, sText_GimmiLoc_Saffron },
    { FALSE, MAP_GROUP(MAP_INDIGO_PLATEAU), MAP_NUM(MAP_INDIGO_PLATEAU), 0, 25, sText_GimmiShort_Indigo, sText_GimmiLoc_Indigo },
    { FALSE, MAP_GROUP(MAP_BLACKTHORN_CITY), MAP_NUM(MAP_BLACKTHORN_CITY), 0, 25, sText_GimmiShort_Blackthorn, sText_GimmiLoc_Blackthorn },
    { FALSE, MAP_GROUP(MAP_GOLDENROD_CITY), MAP_NUM(MAP_GOLDENROD_CITY), 0, 25, sText_GimmiShort_Goldenrod, sText_GimmiLoc_Goldenrod },
    { FALSE, MAP_GROUP(MAP_AZALEA_TOWN), MAP_NUM(MAP_AZALEA_TOWN), 0, 25, sText_GimmiShort_Azalea, sText_GimmiLoc_Azalea },
    { FALSE, MAP_GROUP(MAP_OLIVINE_CITY), MAP_NUM(MAP_OLIVINE_CITY), 0, 25, sText_GimmiShort_Olivine, sText_GimmiLoc_Olivine },
    { FALSE, MAP_GROUP(MAP_CIANWOOD_CITY), MAP_NUM(MAP_CIANWOOD_CITY), 0, 25, sText_GimmiShort_Cianwood, sText_GimmiLoc_Cianwood },
    { FALSE, MAP_GROUP(MAP_ILEX_FOREST), MAP_NUM(MAP_ILEX_FOREST), 0, 25, sText_GimmiShort_Ilex, sText_GimmiLoc_Ilex },
    { FALSE, MAP_GROUP(MAP_RUINS_OF_ALPH_OUTSIDE), MAP_NUM(MAP_RUINS_OF_ALPH_OUTSIDE), 0, 25, sText_GimmiShort_RuinsOutside, sText_GimmiLoc_RuinsOutside },
    { FALSE, MAP_GROUP(MAP_LITTLEROOT_TOWN), MAP_NUM(MAP_LITTLEROOT_TOWN), 0, 25, sText_GimmiShort_Littleroot, sText_GimmiLoc_Littleroot },
    { FALSE, MAP_GROUP(MAP_MAUVILLE_CITY), MAP_NUM(MAP_MAUVILLE_CITY), 0, 25, sText_GimmiShort_Mauville, sText_GimmiLoc_Mauville },
    { FALSE, MAP_GROUP(MAP_SLATEPORT_CITY), MAP_NUM(MAP_SLATEPORT_CITY), 0, 25, sText_GimmiShort_Slateport, sText_GimmiLoc_Slateport },
    { FALSE, MAP_GROUP(MAP_EVER_GRANDE_CITY), MAP_NUM(MAP_EVER_GRANDE_CITY), 0, 25, sText_GimmiShort_EverGrande, sText_GimmiLoc_EverGrande },
    { TRUE, 0, 0, FLAG_HIDE_LAVENDER_SOULHOUSE_GIMMIGHOUL, 75, sText_GimmiShort_LavenderSoul, sText_GimmiLoc_LavenderSoul },
    { TRUE, 0, 0, FLAG_HIDE_RUINS_OF_ALPH_B1F_GIMMIGHOUL, 75, sText_GimmiShort_RuinsB1F, sText_GimmiLoc_RuinsB1F },
    { TRUE, 0, 0, FLAG_HIDE_MT_PYRE_SUMMIT_GIMMIGHOUL, 75, sText_GimmiShort_MtPyre, sText_GimmiLoc_MtPyre },
    { TRUE, 0, 0, FLAG_HIDE_ABANDONED_SHIP_ROOMS_1F_GIMMIGHOUL, 75, sText_GimmiShort_Ship, sText_GimmiLoc_Ship },
    { TRUE, 0, 0, FLAG_HIDE_WHIRL_ISLANDS_B1F_GIMMIGHOUL, 75, sText_GimmiShort_Whirl, sText_GimmiLoc_Whirl },
};

static const struct OddKeystoneJournalEntry sOddKeystoneJournalEntries[] =
{
    { TRAINER_FLAGS_START + TRAINER_CELADON_ODD_KEYSTONE, sText_OddKeystoneShort_CeladonRoof, sText_OddKeystoneLoc_CeladonRoof, sText_OddKeystoneTrainer_Mara },
    { TRAINER_FLAGS_START + TRAINER_GOLDENROD_ODD_KEYSTONE, sText_OddKeystoneShort_GoldenrodRoof, sText_OddKeystoneLoc_GoldenrodRoof, sText_OddKeystoneTrainer_Mina },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
    { 0, NULL, NULL, NULL },
};

#define ZYGARDE_ENTRY(flag, isCoreValue, shortNameValue, locationNameValue) { flag, isCoreValue, shortNameValue, locationNameValue }
#define ZYGARDE_EMPTY { 0, FALSE, NULL, NULL }
static const struct ZygardeJournalEntry sZygardeJournalEntries[] =
{
    ZYGARDE_ENTRY(FLAG_HIDE_PEWTER_CITY_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Pewter, sText_ZygardeLoc_Pewter),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE2_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route2, sText_ZygardeLoc_Route2),
    ZYGARDE_ENTRY(FLAG_HIDE_VIRIDIAN_FOREST_ZYGARDE_CELL, FALSE, sText_ZygardeShort_ViridianForest, sText_ZygardeLoc_ViridianForest),
    ZYGARDE_ENTRY(FLAG_HIDE_MT_MOON_CAVE_ZYGARDE_CELL, FALSE, sText_ZygardeShort_MtMoon, sText_ZygardeLoc_MtMoon),
    ZYGARDE_ENTRY(FLAG_HIDE_CELADON_CITY_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Celadon, sText_ZygardeLoc_Celadon),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE8_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route8, sText_ZygardeLoc_Route8),
    ZYGARDE_ENTRY(FLAG_HIDE_SAFFRON_CITY_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Saffron, sText_ZygardeLoc_Saffron),
    ZYGARDE_ENTRY(FLAG_HIDE_SAFFRON_TUNNEL_ZYGARDE_CELL, FALSE, sText_ZygardeShort_SaffronTunnel, sText_ZygardeLoc_SaffronTunnel),
    ZYGARDE_ENTRY(FLAG_HIDE_SAFFRON_TUNNEL_SW_ZYGARDE_CELL, FALSE, sText_ZygardeShort_SaffronTunnelSW, sText_ZygardeLoc_SaffronTunnelSW),
    ZYGARDE_ENTRY(FLAG_HIDE_VERMILION_CITY_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Vermilion, sText_ZygardeLoc_Vermilion),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE11_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route11, sText_ZygardeLoc_Route11),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE12_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route12, sText_ZygardeLoc_Route12),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE13_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route13, sText_ZygardeLoc_Route13),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE17_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route17, sText_ZygardeLoc_Route17),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE20_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route20, sText_ZygardeLoc_Route20),
    ZYGARDE_ENTRY(FLAG_HIDE_CINNABAR_ISLAND_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Cinnabar, sText_ZygardeLoc_Cinnabar),
    ZYGARDE_ENTRY(FLAG_HIDE_DIGLETTS_CAVE_TUNNEL_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Digletts, sText_ZygardeLoc_Digletts),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE21_NORTH_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Route21, sText_ZygardeLoc_Route21),
    ZYGARDE_ENTRY(FLAG_HIDE_CERULEAN_CAVE_B1F_ZYGARDE_CELL, FALSE, sText_ZygardeShort_CeruleanCave, sText_ZygardeLoc_CeruleanCave),
    ZYGARDE_ENTRY(FLAG_HIDE_ROUTE10_POWERPLANTBACK_ZYGARDE_CELL, FALSE, sText_ZygardeShort_PowerPlant, sText_ZygardeLoc_PowerPlant),
    ZYGARDE_ENTRY(FLAG_HIDE_FUCHSIA_CITY_ZYGARDE_CELL, FALSE, sText_ZygardeShort_Fuchsia, sText_ZygardeLoc_Fuchsia),
    ZYGARDE_ENTRY(FLAG_HIDE_PALLET_TOWN_WESTERN_FOREST_ZYGARDE_CELL, FALSE, sText_ZygardeShort_PalletForest, sText_ZygardeLoc_PalletForest),
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY,
    ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY, ZYGARDE_EMPTY
};
#undef ZYGARDE_ENTRY
#undef ZYGARDE_EMPTY

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
        .title = sText_QuestGimmighoulTitle,
        .description = sText_QuestGimmighoulDesc,
        .flagStarted = FLAG_QUEST_GIMMI_MY_MONEY_STARTED,
        .flagCompleted = FLAG_QUEST_GIMMI_MY_MONEY_COMPLETED,
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
        .title = sText_Quest100PowerTitle,
        .description = sText_Quest100PowerDesc,
        .flagStarted = FLAG_QUEST_100_POWER_STARTED,
        .flagCompleted = FLAG_QUEST_100_POWER_COMPLETED,
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
        // This flag is set immediately before Birch's Ilex Forest call and is
        // independent of the quest progress flags used by older saves.
        .flagReveal = FLAG_HIDE_ILEX_JJ_GROUP,
    },
    {
        .title = sText_QuestStartersStolenTitle,
        .description = sText_QuestStartersStolenDesc,
        .flagStarted = FLAG_QUEST_STARTERS_STOLEN_STARTED,
        .flagCompleted = FLAG_QUEST_STARTERS_STOLEN_COMPLETED,
    },
    {
        .title = sText_QuestThunderbirdTitle,
        .description = sText_QuestThunderbirdDesc,
        .flagStarted = FLAG_QUEST_THUNDERBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_THUNDERBIRD_COMPLETED,
        .flagReveal = FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestMachinePartTitle,
        .description = sText_QuestMachinePartDesc,
        .flagStarted = FLAG_QUEST_MACHINE_PART_STARTED,
        .flagCompleted = FLAG_QUEST_MACHINE_PART_COMPLETED,
        .flagReveal = FLAG_QUEST_MACHINE_PART_REVEALED,
    },
    {
        .title = sText_QuestIcebirdTitle,
        .description = sText_QuestIcebirdDesc,
        .flagStarted = FLAG_QUEST_ICEBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_ICEBIRD_COMPLETED,
        .flagReveal = FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestFirebirdTitle,
        .description = sText_QuestFirebirdDesc,
        .flagStarted = FLAG_QUEST_FIREBIRD_STARTED,
        .flagCompleted = FLAG_QUEST_FIREBIRD_COMPLETED,
        .flagReveal = FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestPhoenixTitle,
        .description = sText_QuestPhoenixDesc,
        .flagStarted = FLAG_QUEST_PHOENIX_STARTED,
        .flagCompleted = FLAG_QUEST_PHOENIX_COMPLETED,
        .flagReveal = FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestShiningBeastTitle,
        .description = sText_QuestShiningBeastDesc,
        .flagStarted = FLAG_QUEST_SHINING_BEAST_STARTED,
        .flagCompleted = FLAG_QUEST_SHINING_BEAST_COMPLETED,
        .flagReveal = FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestLavenderNPCsTitle,
        .description = sText_QuestLavenderNPCsDesc,
        .flagStarted = FLAG_QUEST_LAVENDER_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_LAVENDER_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestOddKeystoneTitle,
        .description = sText_QuestOddKeystoneDesc,
        .flagStarted = FLAG_QUEST_ODD_KEYSTONE_STARTED,
        .flagCompleted = FLAG_QUEST_ODD_KEYSTONE_COMPLETED,
    },
    {
        .title = sText_QuestCeladonNPCsTitle,
        .description = sText_QuestCeladonNPCsDesc,
        .flagStarted = FLAG_QUEST_CELADON_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_CELADON_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestMegaMomentsTitle,
        .description = sText_QuestMegaMomentsDesc,
        .flagStarted = FLAG_QUEST_MEGA_MOMENTS_STARTED,
        .flagCompleted = FLAG_QUEST_MEGA_MOMENTS_COMPLETED,
    },
    {
        .title = sText_QuestEricaTitle,
        .description = sText_QuestEricaDesc,
        .flagStarted = FLAG_QUEST_ERICA_STARTED,
        .flagCompleted = FLAG_QUEST_ERICA_COMPLETED,
    },
    {
        .title = sText_QuestAlolaLillieTitle,
        .description = sText_QuestAlolaLillieDesc,
        .flagStarted = FLAG_QUEST_ALOLA_LILLIE_STARTED,
        .flagCompleted = FLAG_QUEST_ALOLA_LILLIE_COMPLETED,
        .flagReveal = FLAG_CELADON_LILLIE_JOINED,
    },
    {
        .title = sText_QuestLtSurgeTitle,
        .description = sText_QuestLtSurgeDesc,
        .flagStarted = FLAG_QUEST_LT_SURGE_STARTED,
        .flagCompleted = FLAG_QUEST_LT_SURGE_COMPLETED,
    },
    {
        .title = sText_QuestNebbyPowerhouseTitle,
        .description = sText_QuestNebbyPowerhouseDesc,
        .flagStarted = FLAG_QUEST_NEBBY_POWERHOUSE_STARTED,
        .flagCompleted = FLAG_QUEST_NEBBY_POWERHOUSE_COMPLETED,
        .flagReveal = FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE,
    },
    {
        .title = sText_QuestSaffronNPCsTitle,
        .description = sText_QuestSaffronNPCsDesc,
        .flagStarted = FLAG_QUEST_SAFFRON_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_SAFFRON_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestVermilionNPCsTitle,
        .description = sText_QuestVermilionNPCsDesc,
        .flagStarted = FLAG_QUEST_VERMILION_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_VERMILION_NPCS_COMPLETED,
    },
    {
        .title = sText_QuestGoldenrodCityInfoTitle,
        .description = sText_QuestGoldenrodCityInfoDesc,
        .flagStarted = FLAG_QUEST_GOLDENROD_CITY_INFO_STARTED,
        .flagCompleted = FLAG_QUEST_GOLDENROD_CITY_INFO_COMPLETED,
        .flagReveal = FLAG_VISITED_GOLDENROD_CITY,
    },
    {
        .title = sText_QuestWhitneyTitle,
        .description = sText_QuestWhitneyDesc,
        .flagStarted = FLAG_QUEST_WHITNEY_STARTED,
        .flagCompleted = FLAG_QUEST_WHITNEY_COMPLETED,
        .flagReveal = FLAG_KURTS_HOUSE_GOLD_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestCipherTakeoverTitle,
        .description = sText_QuestCipherTakeoverDesc,
        .flagStarted = FLAG_QUEST_CIPHER_TAKEOVER_STARTED,
        .flagCompleted = FLAG_QUEST_CIPHER_TAKEOVER_COMPLETED,
        .flagReveal = FLAG_KURTS_HOUSE_GOLD_QUESTS_REVEALED,
    },
    {
        .title = sText_QuestGoldenrodNPCsTitle,
        .description = sText_QuestGoldenrodNPCsDesc,
        .flagStarted = FLAG_QUEST_GOLDENROD_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_GOLDENROD_NPCS_COMPLETED,
        .flagReveal = FLAG_VISITED_GOLDENROD_CITY,
    },
    {
        .title = sText_QuestRustboroNPCsTitle,
        .description = sText_QuestRustboroNPCsDesc,
        .flagStarted = FLAG_QUEST_RUSTBORO_NPCS_STARTED,
        .flagCompleted = FLAG_QUEST_RUSTBORO_NPCS_COMPLETED,
        .flagReveal = FLAG_VISITED_RUSTBORO_CITY,
    },
    {
        .title = sText_QuestRockyRoxyTitle,
        .description = sText_QuestRockyRoxyDesc,
        .flagStarted = FLAG_QUEST_ROCKY_ROXY_STARTED,
        .flagCompleted = FLAG_QUEST_ROCKY_ROXY_COMPLETED,
    },
    {
        .title = sText_QuestFindBrendanMayTitle,
        .description = sText_QuestFindBrendanMayDesc,
        .flagStarted = FLAG_QUEST_FIND_BRENDAN_MAY_STARTED,
        .flagCompleted = FLAG_QUEST_FIND_BRENDAN_MAY_COMPLETED,
    },
    {
        .title = sText_QuestMoreToComeTitle,
        .description = sText_QuestMoreToComeDesc,
        .flagStarted = FLAG_QUEST_MORE_TO_COME_STARTED,
        .flagCompleted = FLAG_QUEST_MORE_TO_COME_COMPLETED,
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

static const u8 sQuestJournalActiveTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_RED,
    TEXT_COLOR_LIGHT_RED,
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
static EWRAM_DATA u8 sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;

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
        sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;
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
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
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
    u8 selection = QuestJournal_GetCurrentSelection(taskId);
    u8 top = QuestJournal_GetCurrentTop(taskId);
    u8 i;
    u8 entryId;
    u8 entryCount = sQuestJournalEntryCount;
    u8 visibleEntries = QUEST_JOURNAL_VISIBLE_ENTRIES;

    if (sQuestJournalMode == QUEST_JOURNAL_MODE_GIMMI_DETAIL)
    {
        entryCount = ARRAY_COUNT(sGimmighoulJournalEntries);
        visibleEntries = QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES;
    }
    else if (sQuestJournalMode == QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL)
    {
        entryCount = ARRAY_COUNT(sOddKeystoneJournalEntries);
        visibleEntries = QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES;
    }
    else if (sQuestJournalMode == QUEST_JOURNAL_MODE_ZYGARDE_DETAIL)
    {
        entryCount = ARRAY_COUNT(sZygardeJournalEntries);
        visibleEntries = QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sQuestJournalMode == QUEST_JOURNAL_MODE_GIMMI_DETAIL)
        {
            QuestJournal_ExitGimmighoulDetail(taskId);
            return;
        }
        if (sQuestJournalMode == QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL)
        {
            QuestJournal_ExitOddKeystoneDetail(taskId);
            return;
        }
        if (sQuestJournalMode == QUEST_JOURNAL_MODE_ZYGARDE_DETAIL)
        {
            QuestJournal_ExitZygardeDetail(taskId);
            return;
        }
        gTasks[taskId].func = Task_QuestJournalFadeOut;
        return;
    }

    if (QuestJournal_IsCurrentModeDetail())
    {
        if (entryCount <= 1)
            return;

        if (JOY_NEW(DPAD_UP))
        {
            selection = (selection == 0) ? (entryCount - 1) : (selection - 1);
            PlaySE(SE_SELECT);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            selection = (selection + 1) % entryCount;
            PlaySE(SE_SELECT);
        }
        else
        {
            return;
        }

        if (entryCount > visibleEntries)
        {
            if (selection < top)
                top = selection;
            else if (selection >= top + visibleEntries)
                top = selection - (visibleEntries - 1);
        }
        else
        {
            top = 0;
        }

        QuestJournal_SetCurrentSelection(taskId, selection);
        QuestJournal_SetCurrentTop(taskId, top);
        sQuestJournalScrollTop = top;
        QuestJournal_LoadCursorMap(selection - top);
        QuestJournal_DrawTexts(selection);
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

    if (JOY_NEW(A_BUTTON) && QuestJournal_IsSpecialDetailQuestSelected(selection))
    {
        PlaySE(SE_SELECT);
        entryId = sQuestJournalEntryIds[selection];
        if (sQuestJournalEntries[entryId].flagStarted == FLAG_QUEST_GIMMI_MY_MONEY_STARTED)
            QuestJournal_EnterGimmighoulDetail(taskId);
        else if (sQuestJournalEntries[entryId].flagStarted == FLAG_QUEST_ODD_KEYSTONE_STARTED)
            QuestJournal_EnterOddKeystoneDetail(taskId);
        else if (sQuestJournalEntries[entryId].flagStarted == FLAG_QUEST_100_POWER_STARTED)
            QuestJournal_EnterZygardeDetail(taskId);
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

    QuestJournal_SetCurrentSelection(taskId, selection);
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

    QuestJournal_SetCurrentTop(taskId, top);
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
        if (!QuestJournal_IsEntryUnlocked(entry))
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
        const struct QuestJournalEntry *entry = &sQuestJournalEntries[i];

        if (sQuestJournalEntryCount >= QUEST_JOURNAL_MAX_ENTRIES)
            break;
        if (sQuestJournalEntryPinned[i] != pinned)
            continue;
        if (!QuestJournal_IsEntryUnlocked(entry))
            continue;

        sQuestJournalEntryIds[sQuestJournalEntryCount++] = i;
    }
}

static void QuestJournal_DrawTexts(u8 selection)
{
    if (sQuestJournalMode == QUEST_JOURNAL_MODE_GIMMI_DETAIL)
        QuestJournal_DrawGimmighoulDetailTexts(selection);
    else if (sQuestJournalMode == QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL)
        QuestJournal_DrawOddKeystoneDetailTexts(selection);
    else if (sQuestJournalMode == QUEST_JOURNAL_MODE_ZYGARDE_DETAIL)
        QuestJournal_DrawZygardeDetailTexts(selection);
    else
        QuestJournal_DrawListTexts(selection);
}

static void QuestJournal_DrawListTexts(u8 selection)
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

        if (QuestJournal_IsEntryUnlocked(entry)
         && (entry->flagStarted == FLAG_QUEST_GIMMI_MY_MONEY_STARTED
          || entry->flagStarted == FLAG_QUEST_ODD_KEYSTONE_STARTED
          || entry->flagStarted == FLAG_QUEST_100_POWER_STARTED))
        {
            u8 aButtonX = QUEST_JOURNAL_ENTRY_TEXT_X + GetStringWidth(FONT_NORMAL, line, 0) + 4;
            AddTextPrinterParameterized(0, FONT_NORMAL, sText_QuestAButtonIcon, aButtonX, (i * 16) + 17, TEXT_SPEED_FF, NULL);
        }

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
            if (state == QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE)
                AddTextPrinterParameterized4(0, FONT_NORMAL, statusX, (i * 16) + 17, 0, 0, sQuestJournalActiveTextColors, TEXT_SPEED_FF, statusText);
            else
                AddTextPrinterParameterized(0, FONT_NORMAL, statusText, statusX, (i * 16) + 17, TEXT_SPEED_FF, NULL);
        }
    }

    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void QuestJournal_DrawGimmighoulDetailTexts(u8 selection)
{
    u8 top = sQuestJournalScrollTop;
    u8 i;
    u8 line[96];
    u8 name[64];
    u8 countText[24];
    u8 countX;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_QuestGimmighoulTitle, 8, 1, TEXT_SPEED_FF, NULL);

    StringCopy(countText, sText_GimmighoulHeaderCount);
    ConvertIntToDecimalStringN(gStringVar1, QuestJournal_GetGimmighoulFoundCount(), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(countText, gStringVar1);
    StringAppend(countText, sText_GimmighoulTotalCount);
    countX = GetStringRightAlignXOffset(FONT_NORMAL, countText, 228);
    AddTextPrinterParameterized(0, FONT_NORMAL, countText, countX, 1, TEXT_SPEED_FF, NULL);

    QuestJournal_GetGimmighoulDescription(line, selection);
    QuestJournal_ShowDescription(line);

    for (i = 0; i < QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES; i++)
    {
        u8 entryIndex = top + i;

        if (entryIndex >= ARRAY_COUNT(sGimmighoulJournalEntries))
            break;

        ConvertIntToDecimalStringN(gStringVar1, entryIndex + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringCopy(line, sText_QuestEntryStyle);
        StringAppend(line, gStringVar1);
        StringAppend(line, sText_GimmighoulListNumberSuffix);

        if (QuestJournal_IsGimmighoulEntryDiscovered(entryIndex))
        {
            QuestJournal_GetGimmighoulDisplayName(name, entryIndex);
            StringAppend(line, name);
        }
        else
        {
            StringAppend(line, sText_GimmighoulUnknownName);
        }

        AddTextPrinterParameterized(0, FONT_NORMAL, line, QUEST_JOURNAL_ENTRY_TEXT_X, (i * 16) + 17, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void QuestJournal_DrawOddKeystoneDetailTexts(u8 selection)
{
    u8 top = sQuestJournalScrollTop;
    u8 i;
    u8 line[96];
    u8 name[64];
    u8 countText[24];
    u8 countX;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_QuestOddKeystoneTitle, 8, 1, TEXT_SPEED_FF, NULL);

    StringCopy(countText, sText_GimmighoulHeaderCount);
    ConvertIntToDecimalStringN(gStringVar1, QuestJournal_GetOddKeystoneFoundCount(), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(countText, gStringVar1);
    StringAppend(countText, sText_OddKeystoneTotalCount);
    countX = GetStringRightAlignXOffset(FONT_NORMAL, countText, 228);
    AddTextPrinterParameterized(0, FONT_NORMAL, countText, countX, 1, TEXT_SPEED_FF, NULL);

    QuestJournal_GetOddKeystoneDescription(line, selection);
    QuestJournal_ShowDescription(line);

    for (i = 0; i < QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES; i++)
    {
        u8 entryIndex = top + i;

        if (entryIndex >= ARRAY_COUNT(sOddKeystoneJournalEntries))
            break;

        ConvertIntToDecimalStringN(gStringVar1, entryIndex + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringCopy(line, sText_QuestEntryStyle);
        StringAppend(line, gStringVar1);
        StringAppend(line, sText_GimmighoulListNumberSuffix);

        if (QuestJournal_IsOddKeystoneEntryDiscovered(entryIndex))
        {
            QuestJournal_GetOddKeystoneDisplayName(name, entryIndex);
            StringAppend(line, name);
        }
        else
        {
            StringAppend(line, sText_OddKeystoneUnknownName);
        }

        AddTextPrinterParameterized(0, FONT_NORMAL, line, QUEST_JOURNAL_ENTRY_TEXT_X, (i * 16) + 17, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void QuestJournal_DrawZygardeDetailTexts(u8 selection)
{
    u8 top = sQuestJournalScrollTop;
    u8 i;
    u8 line[96];
    u8 name[64];
    u8 countText[24];
    u8 countX;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_Quest100PowerTitle, 8, 1, TEXT_SPEED_FF, NULL);

    StringCopy(countText, sText_GimmighoulHeaderCount);
    ConvertIntToDecimalStringN(gStringVar1, QuestJournal_GetZygardeFoundCount(), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(countText, gStringVar1);
    StringAppend(countText, sText_ZygardeTotalCount);
    countX = GetStringRightAlignXOffset(FONT_NORMAL, countText, 228);
    AddTextPrinterParameterized(0, FONT_NORMAL, countText, countX, 1, TEXT_SPEED_FF, NULL);

    QuestJournal_GetZygardeDescription(line, selection);
    QuestJournal_ShowDescription(line);

    for (i = 0; i < QUEST_JOURNAL_GIMMI_VISIBLE_ENTRIES; i++)
    {
        u8 entryIndex = top + i;

        if (entryIndex >= ARRAY_COUNT(sZygardeJournalEntries))
            break;

        ConvertIntToDecimalStringN(gStringVar1, entryIndex + 1, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(line, sText_QuestEntryStyle);
        StringAppend(line, gStringVar1);
        StringAppend(line, sText_GimmighoulListNumberSuffix);

        if (QuestJournal_IsZygardeEntryDiscovered(entryIndex))
        {
            QuestJournal_GetZygardeDisplayName(name, entryIndex);
            StringAppend(line, name);
        }
        else
        {
            StringAppend(line, sText_ZygardeUnknownName);
        }

        AddTextPrinterParameterized(0, FONT_NORMAL, line, QUEST_JOURNAL_ENTRY_TEXT_X, (i * 16) + 17, TEXT_SPEED_FF, NULL);
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
    if (entry->flagReveal != 0
     && !FlagGet(entry->flagReveal))
        return FALSE;

    if (entry->flagStarted == FLAG_QUEST_ERICA_STARTED
     && !FlagGet(FLAG_QUEST_THUNDERBIRD_COMPLETED))
        return FALSE;

    if (entry->flagStarted == FLAG_QUEST_ODD_KEYSTONE_STARTED
     && VarGet(VAR_LAVENDER_SOULHOUSE_ODD_KEYSTONE_STATE) != 2)
        return FALSE;

    return FlagGet(entry->flagStarted) || FlagGet(entry->flagCompleted);
}

static u8 QuestJournal_GetEntryState(const struct QuestJournalEntry *entry)
{
    if (entry->flagStarted == FLAG_QUEST_ODD_KEYSTONE_STARTED)
    {
        FlagClear(FLAG_QUEST_ODD_KEYSTONE_COMPLETED);
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_ERICA_STARTED)
    {
        if (FlagGet(FLAG_BADGE12_GET))
            return QUEST_JOURNAL_ENTRY_STATE_COMPLETE;
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_MACHINE_PART_STARTED)
    {
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_WHITNEY_STARTED)
    {
        if (FlagGet(FLAG_BADGE19_GET))
            return QUEST_JOURNAL_ENTRY_STATE_COMPLETE;
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_CIPHER_TAKEOVER_STARTED)
    {
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_GOLDENROD_CITY_INFO_STARTED)
    {
        if (FlagGet(entry->flagCompleted))
            return QUEST_JOURNAL_ENTRY_STATE_COMPLETE;
        if (FlagGet(FLAG_VISITED_GOLDENROD_CITY) || FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_ROCKY_ROXY_STARTED)
    {
        if (FlagGet(FLAG_BADGE01_GET))
            return QUEST_JOURNAL_ENTRY_STATE_COMPLETE;
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_ICEBIRD_STARTED)
    {
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

    if (entry->flagStarted == FLAG_QUEST_PHOENIX_STARTED)
    {
        if (FlagGet(entry->flagStarted))
            return QUEST_JOURNAL_ENTRY_STATE_INCOMPLETE;
        return QUEST_JOURNAL_ENTRY_STATE_UNOBTAINED;
    }

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
    sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;
    QuestJournal_BuildEntryList();
    sQuestJournalScrollTop = 0;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    QuestJournal_LoadCursorMap(0);
    QuestJournal_DrawTexts(0);
}

static bool8 QuestJournal_IsSpecialDetailQuestSelected(u8 selection)
{
    const struct QuestJournalEntry *entry;

    if (selection >= sQuestJournalEntryCount)
        return FALSE;

    entry = &sQuestJournalEntries[sQuestJournalEntryIds[selection]];
    if (entry->flagStarted == FLAG_QUEST_GIMMI_MY_MONEY_STARTED
     || entry->flagStarted == FLAG_QUEST_ODD_KEYSTONE_STARTED
     || entry->flagStarted == FLAG_QUEST_100_POWER_STARTED)
        return QuestJournal_IsEntryUnlocked(entry);

    return FALSE;
}

static u8 QuestJournal_GetCurrentSelection(u8 taskId)
{
    return QuestJournal_IsCurrentModeDetail() ? gTasks[taskId].data[2] : gTasks[taskId].data[0];
}

static u8 QuestJournal_GetCurrentTop(u8 taskId)
{
    return QuestJournal_IsCurrentModeDetail() ? gTasks[taskId].data[3] : gTasks[taskId].data[1];
}

static void QuestJournal_SetCurrentSelection(u8 taskId, u8 selection)
{
    if (QuestJournal_IsCurrentModeDetail())
        gTasks[taskId].data[2] = selection;
    else
        gTasks[taskId].data[0] = selection;
}

static void QuestJournal_SetCurrentTop(u8 taskId, u8 top)
{
    if (QuestJournal_IsCurrentModeDetail())
        gTasks[taskId].data[3] = top;
    else
        gTasks[taskId].data[1] = top;
}

static void QuestJournal_EnterGimmighoulDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_GIMMI_DETAIL;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    sQuestJournalScrollTop = 0;
    QuestJournal_LoadCursorMap(0);
    QuestJournal_DrawTexts(0);
}

static void QuestJournal_ExitGimmighoulDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;
    sQuestJournalScrollTop = gTasks[taskId].data[1];
    QuestJournal_LoadCursorMap(gTasks[taskId].data[0] - gTasks[taskId].data[1]);
    QuestJournal_DrawTexts(gTasks[taskId].data[0]);
}

static void QuestJournal_EnterOddKeystoneDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    sQuestJournalScrollTop = 0;
    QuestJournal_LoadCursorMap(0);
    QuestJournal_DrawTexts(0);
}

static void QuestJournal_ExitOddKeystoneDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;
    sQuestJournalScrollTop = gTasks[taskId].data[1];
    QuestJournal_LoadCursorMap(gTasks[taskId].data[0] - gTasks[taskId].data[1]);
    QuestJournal_DrawTexts(gTasks[taskId].data[0]);
}

static void QuestJournal_EnterZygardeDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_ZYGARDE_DETAIL;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    sQuestJournalScrollTop = 0;
    QuestJournal_LoadCursorMap(0);
    QuestJournal_DrawTexts(0);
}

static void QuestJournal_ExitZygardeDetail(u8 taskId)
{
    sQuestJournalMode = QUEST_JOURNAL_MODE_LIST;
    sQuestJournalScrollTop = gTasks[taskId].data[1];
    QuestJournal_LoadCursorMap(gTasks[taskId].data[0] - gTasks[taskId].data[1]);
    QuestJournal_DrawTexts(gTasks[taskId].data[0]);
}

static void QuestJournal_GetGimmighoulDisplayName(u8 *dst, u8 entryIndex)
{
    const struct GimmighoulJournalEntry *entry = &sGimmighoulJournalEntries[entryIndex];

    StringCopy(dst, entry->isChest ? sText_GimmighoulChestPrefix : sText_GimmighoulSignPrefix);
    StringAppend(dst, entry->shortName);
}

static void QuestJournal_GetGimmighoulDescription(u8 *dst, u8 entryIndex)
{
    const struct GimmighoulJournalEntry *entry = &sGimmighoulJournalEntries[entryIndex];

    StringCopy(dst, sText_GimmighoulLocationPrefix);
    if (QuestJournal_IsGimmighoulEntryDiscovered(entryIndex))
        StringAppend(dst, entry->locationName);
    else
        StringAppend(dst, sText_GimmighoulUnknownLocation);
    StringAppend(dst, sText_GimmighoulDescriptionNewLine);

    if (QuestJournal_IsGimmighoulEntryDiscovered(entryIndex))
    {
        ConvertIntToDecimalStringN(gStringVar1, entry->coins, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(dst, gStringVar1);
    }
    else
    {
        StringAppend(dst, sText_GimmighoulUnknownCoins);
    }
    StringAppend(dst, sText_GimmighoulCoinsSuffix);
}

static bool8 QuestJournal_IsGimmighoulEntryDiscovered(u8 entryIndex)
{
    const struct GimmighoulJournalEntry *entry = &sGimmighoulJournalEntries[entryIndex];

    if (entry->isChest)
        return FlagGet(entry->chestFlag);

    return GimmighoulSignpost_HasAnyUsedOnMap(entry->mapGroup, entry->mapNum);
}

static u16 QuestJournal_GetGimmighoulFoundCount(void)
{
    u16 i;
    u16 count = 0;

    for (i = 0; i < ARRAY_COUNT(sGimmighoulJournalEntries); i++)
    {
        if (QuestJournal_IsGimmighoulEntryDiscovered(i))
            count++;
    }

    return count;
}

static void QuestJournal_GetOddKeystoneDisplayName(u8 *dst, u8 entryIndex)
{
    const struct OddKeystoneJournalEntry *entry = &sOddKeystoneJournalEntries[entryIndex];

    if (entry->shortName != NULL)
        StringCopy(dst, entry->shortName);
    else
        StringCopy(dst, sText_OddKeystoneUnknownName);
}

static void QuestJournal_GetOddKeystoneDescription(u8 *dst, u8 entryIndex)
{
    const struct OddKeystoneJournalEntry *entry = &sOddKeystoneJournalEntries[entryIndex];

    StringCopy(dst, sText_GimmighoulLocationPrefix);
    if (QuestJournal_IsOddKeystoneEntryDiscovered(entryIndex) && entry->locationName != NULL)
        StringAppend(dst, entry->locationName);
    else
        StringAppend(dst, sText_OddKeystoneUnknownLocation);
    StringAppend(dst, sText_OddKeystoneDescriptionNewLine);
    StringAppend(dst, sText_OddKeystoneDefeatedPrefix);

    if (QuestJournal_IsOddKeystoneEntryDiscovered(entryIndex) && entry->trainerName != NULL)
        StringAppend(dst, entry->trainerName);
    else
        StringAppend(dst, sText_OddKeystoneUnknownTrainer);
}

static bool8 QuestJournal_IsOddKeystoneEntryDiscovered(u8 entryIndex)
{
    const struct OddKeystoneJournalEntry *entry = &sOddKeystoneJournalEntries[entryIndex];

    if (entry->discoveredFlag == 0)
        return FALSE;

    return FlagGet(entry->discoveredFlag);
}

static u16 QuestJournal_GetOddKeystoneFoundCount(void)
{
    u16 i;
    u16 count = 0;

    for (i = 0; i < ARRAY_COUNT(sOddKeystoneJournalEntries); i++)
    {
        if (QuestJournal_IsOddKeystoneEntryDiscovered(i))
            count++;
    }

    return count;
}

static void QuestJournal_GetZygardeDisplayName(u8 *dst, u8 entryIndex)
{
    const struct ZygardeJournalEntry *entry = &sZygardeJournalEntries[entryIndex];

    if (entry->shortName != NULL)
        StringCopy(dst, entry->shortName);
    else
        StringCopy(dst, sText_ZygardeUnknownName);
}

static void QuestJournal_GetZygardeDescription(u8 *dst, u8 entryIndex)
{
    const struct ZygardeJournalEntry *entry = &sZygardeJournalEntries[entryIndex];

    StringCopy(dst, entry->isCore ? sText_ZygardeCorePrefix : sText_ZygardeCellPrefix);
    if (QuestJournal_IsZygardeEntryDiscovered(entryIndex) && entry->locationName != NULL)
        StringAppend(dst, entry->locationName);
    else
        StringAppend(dst, sText_ZygardeUnknownLocation);
}

static bool8 QuestJournal_IsZygardeEntryDiscovered(u8 entryIndex)
{
    const struct ZygardeJournalEntry *entry = &sZygardeJournalEntries[entryIndex];
    const u16 foundCount = entry->isCore ? VarGet(VAR_ZYGARDE_CORE_COUNT) : VarGet(VAR_ZYGARDE_CELL_COUNT);

    if (entry->discoveredFlag == 0)
        return FALSE;

    if (!FlagGet(FLAG_QUEST_100_POWER_STARTED)
     && !FlagGet(FLAG_QUEST_100_POWER_COMPLETED))
        return FALSE;

    if (!CheckBagHasItem(ITEM_ZYGARDE_CUBE, 1)
     && !FlagGet(FLAG_QUEST_100_POWER_COMPLETED))
        return FALSE;

    if (foundCount == 0)
        return FALSE;

    return FlagGet(entry->discoveredFlag);
}

static u16 QuestJournal_GetZygardeFoundCount(void)
{
    u16 i;
    u16 count = 0;

    for (i = 0; i < ARRAY_COUNT(sZygardeJournalEntries); i++)
    {
        if (QuestJournal_IsZygardeEntryDiscovered(i))
            count++;
    }

    return count;
}

static bool8 QuestJournal_IsCurrentModeDetail(void)
{
    return sQuestJournalMode == QUEST_JOURNAL_MODE_GIMMI_DETAIL
        || sQuestJournalMode == QUEST_JOURNAL_MODE_ODD_KEYSTONE_DETAIL
        || sQuestJournalMode == QUEST_JOURNAL_MODE_ZYGARDE_DETAIL;
}
