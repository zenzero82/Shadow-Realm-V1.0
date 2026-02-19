#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/flags.h"
#include "constants/event_objects.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "list_menu.h"
#include "mystery_event_menu.h"
#include "naming_screen.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokedex.h"
#include "region_map.h"
#include "pokemon_icon.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"
#include "mystery_gift_menu.h"
#include "constants/event_object_movement.h"

/*
 * Main menu state machine
 * -----------------------
 *
 * Entry point: CB2_InitMainMenu
 *
 * Note: States advance sequentially unless otherwise stated.
 *
 * CB2_InitMainMenu / CB2_ReinitMainMenu
 *  - Both of these states call InitMainMenu, which does all the work.
 *  - In the Reinit case, the init code will check if the user came from
 *    the options screen. If they did, then the options menu item is
 *    pre-selected.
 *
 * Task_MainMenuCheckSaveFile
 *  - Determines how many menu options to show based on whether
 *    the save file is Ok, empty, corrupted, etc.
 *  - If there was an error loading the save file, advance to
 *    Task_WaitForSaveFileErrorWindow.
 *  - If there were no errors, advance to Task_MainMenuCheckBattery.
 *  - Note that the check to enable Mystery Events would normally happen
 *    here, but this version of Emerald has them disabled.
 *
 * Task_WaitForSaveFileErrorWindow
 *  - Wait for the text to finish printing and then for the A button
 *    to be pressed.
 *
 * Task_MainMenuCheckBattery
 *  - If the battery is OK, advance to Task_DisplayMainMenu.
 *  - If the battery is dry, advance to Task_WaitForBatteryDryErrorWindow.
 *
 * Task_WaitForBatteryDryErrorWindow
 *  - Wait for the text to finish printing and then for the A button
 *    to be pressed.
 *
 * Task_DisplayMainWindow
 *  - Display the buttons to the user. If the menu is in HAS_MYSTERY_EVENTS
 *    mode, there are too many buttons for one screen and a scrollbar is added,
 *    and the scrollbar task is spawned (Task_ScrollIndicatorArrowPairOnMainMenu).
 *
 * Task_HighlightSelectedMainMenuItem
 *  - Update the UI to match the currently selected item.
 *
 * Task_HandleMainMenuInput
 *  - If A is pressed, advance to Task_HandleMainMenuAPressed.
 *  - If B is pressed, return to the title screen via CB2_InitTitleScreen.
 *  - If Up or Down is pressed, handle scrolling if there is a scroll bar, change
 *    the selection, then go back to Task_HighlightSelectedMainMenuItem.
 *
 * Task_HandleMainMenuAPressed
 *  - If the user selected New Game, advance to Task_NewGameBirchSpeech_Init.
 *  - If the user selected Continue, advance to CB2_ContinueSavedGame.
 *  - If the user selected the Options menu, advance to CB2_InitOptionMenu.
 *  - If the user selected Mystery Gift, advance to CB2_InitMysteryGift. However,
 *    if the wireless adapter was removed, instead advance to
 *    Task_DisplayMainMenuInvalidActionError.
 *  - Code to start a Mystery Event is present here, but is unreachable in this
 *    version.
 *
 * Task_HandleMainMenuBPressed
 *  - Clean up the main menu and go back to CB2_InitTitleScreen.
 *
 * Task_DisplayMainMenuInvalidActionError
 *  - Print one of three different error messages, wait for the text to stop
 *    printing, and then wait for A or B to be pressed.
 * - Then advance to Task_HandleMainMenuBPressed.
 *
 * Task_NewGameBirchSpeech_Init
 *  - Load the sprites for the intro speech, start playing music
 * Task_NewGameBirchSpeech_WaitToShowBirch
 *  - Spawn Task_NewGameBirchSpeech_FadeInTarget1OutTarget2
 *  - Spawn Task_NewGameBirchSpeech_FadePlatformOut
 *  - Both of these tasks destroy themselves when done.
 * Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome
 * Task_NewGameBirchSpeech_ThisIsAPokemon
 *  - When the text is done printing, spawns Task_NewGameBirchSpeechSub_InitPokeball
 * Task_NewGameBirchSpeech_MainSpeech
 * Task_NewGameBirchSpeech_AndYouAre
 * Task_NewGameBirchSpeech_StartBirchLotadPlatformFade
 * Task_NewGameBirchSpeech_StartBirchLotadPlatformFade
 * Task_NewGameBirchSpeech_SlidePlatformAway
 * Task_NewGameBirchSpeech_StartPlayerFadeIn
 * Task_NewGameBirchSpeech_WaitForPlayerFadeIn
 * Task_NewGameBirchSpeech_BoyOrGirl
 * Task_NewGameBirchSpeech_WaitToShowGenderMenu
 * Task_NewGameBirchSpeech_ChooseGender
 *  - Animates by advancing to Task_NewGameBirchSpeech_SlideOutOldGenderSprite
 *    whenever the player's selection changes.
 *  - Advances to Task_NewGameBirchSpeech_WhatsYourName when done.
 *
 * Task_NewGameBirchSpeech_SlideOutOldGenderSprite
 * Task_NewGameBirchSpeech_SlideInNewGenderSprite
 *  - Returns back to Task_NewGameBirchSpeech_ChooseGender.
 *
 * Task_NewGameBirchSpeech_WhatsYourName
 * Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint
 * Task_NewGameBirchSpeech_WaitPressBeforeNameChoice
 * Task_NewGameBirchSpeech_StartNamingScreen
 * C2_NamingScreen
 *  - Returns to CB2_NewGameBirchSpeech_ReturnFromNamingScreen when done
 * CB2_NewGameBirchSpeech_ReturnFromNamingScreen
 * Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
 * Task_NewGameBirchSpeech_SoItsPlayerName
 * Task_NewGameBirchSpeech_CreateNameYesNo
 * Task_NewGameBirchSpeech_ProcessNameYesNoMenu
 *  - If confirmed, advance to Task_NewGameBirchSpeech_SlidePlatformAway2.
 *  - Otherwise, return to Task_NewGameBirchSpeech_BoyOrGirl.
 *
 * Task_NewGameBirchSpeech_SlidePlatformAway2
 * Task_NewGameBirchSpeech_ReshowBirchLotad
 * Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter
 * Task_NewGameBirchSpeech_AreYouReady
 * Task_NewGameBirchSpeech_ShrinkPlayer
 * Task_NewGameBirchSpeech_WaitForPlayerShrink
 * Task_NewGameBirchSpeech_FadePlayerToWhite
 * Task_NewGameBirchSpeech_Cleanup
 *  - Advances to CB2_NewGame.
 *
 * Task_NewGameBirchSpeechSub_InitPokeball
 *  - Advances to Task_NewGameBirchSpeechSub_WaitForLotad
 * Task_NewGameBirchSpeechSub_WaitForLotad
 *  - Destroys itself when done.
 */

#define OPTION_MENU_FLAG (1 << 15)

// Static type declarations

// Static RAM declarations

static EWRAM_DATA bool8 sStartedPokeBallTask = 0;
static EWRAM_DATA u16 sCurrItemAndOptionMenuCheck = 0;

static u8 sBirchSpeechMainTaskId;

// Static ROM declarations

static u32 InitMainMenu(bool8);
static void Task_MainMenuCheckSaveFile(u8);
static void Task_MainMenuCheckBattery(u8);
static void Task_WaitForSaveFileErrorWindow(u8);
static void UNUSED CreateMainMenuErrorWindow(const u8 *);
static void UNUSED ClearMainMenuWindowTilemap(const struct WindowTemplate *);
static void Task_DisplayMainMenu(u8);
static void Task_WaitDma3AndFadeIn(u8);
static void PrintSaveErrorStatus(u8 taskId, const u8 *str);
static void PrintMessageOnWindow4(const u8 *str);
static void MoveWindowByMenuTypeAndCursorPos(u8 menuType, u8 cursorPos);
static void PrintContinueStats(void);
static void PrintPlayerName(void);
static void PrintPlayTime(void);
static void PrintDexCount(void);
static void PrintBadgeCount(void);
static void PrintLocation(void);
static void PrintTeam(void);
static void DestroyAllSprites(void);
static void LoadOverWorld(u8 anim);
static void LoadMonIcon(u8 anim);
static void LoadUserFrameToBg(u8 bgId);
static void SetStdFrame0OnBg(u8 bgId);
static void MainMenu_BlankScreen(void);
static void PrintMainMenuItem(const u8 *string, u8 left, u8 top, u8 textColor);
static void MainMenu_DrawWindow(const struct WindowTemplate *template);
static void MainMenu_EraseWindow(const struct WindowTemplate *template);
static void Task_WaitForBatteryDryErrorWindow(u8);
static void UNUSED MainMenu_FormatSavegameText(void);
static void HighlightSelectedMainMenuItem(u8, u8, s16);
static void Task_HandleMainMenuInput(u8);
static void Task_HandleMainMenuAPressed(u8);
static void Task_HandleMainMenuBPressed(u8);
static void UNUSED Task_NewGameBirchSpeech_Init(u8);
static void UNUSED Task_DisplayMainMenuInvalidActionError(u8);
static void AddBirchSpeechObjects(u8);
static void Task_NewGameBirchSpeech_WaitToShowBirch(u8);
static void NewGameBirchSpeech_StartFadeInTarget1OutTarget2(u8, u8);
static void NewGameBirchSpeech_StartFadePlatformOut(u8, u8);
static void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8);
static void NewGameBirchSpeech_ShowDialogueWindow(u8, u8);
static void NewGameBirchSpeech_ClearWindow(u8);
static void Task_NewGameBirchSpeech_ThisIsAPokemon(u8);
static void Task_NewGameBirchSpeech_MainSpeech(u8);
static void NewGameBirchSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *, u16);
static void Task_NewGameBirchSpeech_AndYouAre(u8);
static void Task_NewGameBirchSpeechSub_WaitForLotad(u8);
static void Task_NewGameBirchSpeech_StartBirchLotadPlatformFade(u8);
static void NewGameBirchSpeech_StartFadeOutTarget1InTarget2(u8, u8);
static void NewGameBirchSpeech_StartFadePlatformIn(u8, u8);
static void Task_NewGameBirchSpeech_SlidePlatformAway(u8);
static void Task_NewGameBirchSpeech_StartPlayerFadeIn(u8);
static void Task_NewGameBirchSpeech_WaitForPlayerFadeIn(u8);
static void Task_NewGameBirchSpeech_BoyOrGirl(u8);
static void LoadMainMenuWindowFrameTiles(u8, u16);
static void DrawMainMenuWindowBorder(const struct WindowTemplate *, u16);
static void Task_HighlightSelectedMainMenuItem(u8);
static void Task_NewGameBirchSpeech_WaitToShowGenderMenu(u8);
static void Task_NewGameBirchSpeech_ChooseGender(u8);
static void NewGameBirchSpeech_ShowGenderMenu(void);
static s8 NewGameBirchSpeech_ProcessGenderMenuInput(void);
static void NewGameBirchSpeech_ClearGenderWindow(u8, u8);
static void Task_NewGameBirchSpeech_WhatsYourName(u8);
static void Task_NewGameBirchSpeech_SlideOutOldGenderSprite(u8);
static void Task_NewGameBirchSpeech_SlideInNewGenderSprite(u8);
static void Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint(u8);
static void Task_NewGameBirchSpeech_WaitPressBeforeNameChoice(u8);
static void Task_NewGameBirchSpeech_StartNamingScreen(u8);
static void CB2_NewGameBirchSpeech_ReturnFromNamingScreen(void);
static void Task_NewGameBirchSpeech_CreateNameYesNo(u8);
static void Task_NewGameBirchSpeech_ProcessNameYesNoMenu(u8);
void CreateYesNoMenuParameterized(u8, u8, u16, u16, u8, u8);
static void Task_NewGameBirchSpeech_SlidePlatformAway2(u8);
static void Task_NewGameBirchSpeech_ReshowBirchLotad(u8);
static void Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter(u8);
static void Task_NewGameBirchSpeech_AreYouReady(u8);
static void Task_NewGameBirchSpeech_ShrinkPlayer(u8);
static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *);
static void Task_NewGameBirchSpeech_WaitForPlayerShrink(u8);
static void Task_NewGameBirchSpeech_FadePlayerToWhite(u8);
static void Task_NewGameBirchSpeech_Cleanup(u8);
static void SpriteCB_Null(struct Sprite *);
static void Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox(u8);
static void UNUSED MainMenu_FormatSavegamePlayer(void);
static void UNUSED MainMenu_FormatSavegamePokedex(void);
static void UNUSED MainMenu_FormatSavegameTime(void);
static void UNUSED MainMenu_FormatSavegameBadges(void);
static void NewGameBirchSpeech_CreateDialogueWindowBorder(u8, u8, u8, u8, u8, u8);
// add these near the other forward declarations
static void CB2_NewGame_GenderName(void);
static void Task_GenderThenName(u8 taskId);
static void UpdateGenderSelectionSprites(u8 taskId);
static void PrintNewGameFlowText(void);
static void PrepareNewGameFlowTextWindow(void);

// .rodata

static const u16 sBirchSpeechBgPals[][16] = {
    INCBIN_U16("graphics/birch_speech/bg0.gbapal"),
    INCBIN_U16("graphics/birch_speech/bg1.gbapal")
};

static const u32 sBirchSpeechShadowGfx[] = INCBIN_U32("graphics/birch_speech/shadow.4bpp.smol");
static const u32 sBirchSpeechBgMap[] = INCBIN_U32("graphics/birch_speech/map.bin.smolTM");
static const u16 sBirchSpeechBgGradientPal[] = INCBIN_U16("graphics/birch_speech/bg2.gbapal");

static const u8 gText_SaveFileCorrupted[] = _("The save file is corrupted. The\nprevious save file will be loaded.");
static const u8 gText_SaveFileErased[] = _("The save file has been erased\ndue to corruption or damage.");
static const u8 gJPText_No1MSubCircuit[] = _("1Mサブきばんが ささっていません！");
static const u8 gText_BatteryRunDry[] = _("The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur.");

static const u8 gText_MainMenuNewGame[] = _("NEW GAME");
static const u8 gText_MainMenuContinue[] = _("CONTINUE");
static const u8 gText_MainMenuOption[] = _("OPTION");
static const u8 gText_MainMenuMysteryGift[] UNUSED = _("MYSTERY GIFT");
static const u8 gText_MainMenuMysteryGift2[] UNUSED = _("MYSTERY GIFT");
static const u8 gText_MainMenuMysteryEvents[] UNUSED = _("MYSTERY EVENTS");
static const u8 gText_WirelessNotConnected[] = _("The Wireless Adapter is not\nconnected.");
static const u8 gText_MysteryGiftCantUse[] = _("MYSTERY GIFT can't be used while\nthe Wireless Adapter is attached.");
static const u8 gText_MysteryEventsCantUse[] = _("MYSTERY EVENTS can't be used while\nthe Wireless Adapter is attached.");
static const u16 sNewGameTextPal[16] = {
    RGB(0, 0, 0),
    RGB(31, 31, 31),
    RGB(22, 22, 22),
    RGB(12, 12, 12),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
    RGB(0, 0, 0),
};
static const u8 sText_NewGameIntroStory[] = _(
    "Welcome to POKEMON THE SHADOW REALM.\p"
    "A brand new story that pulls the\n"
    "Shadow mechanics from fan favorites\l"
    "POKEMON COLOSSEUM & XD.\p"
    "This game is a free rom hack and is\n"
    "absolutely not for sale.\p"
    "As of now it's a one-man project,\n"
    "so it will take some time to finish.\l"
    "Hope you enjoy the demo!$"
);
static const u8 sText_NewGameChooseGender[] = _(
    "First choose your gender.\n"
    "Use LEFT/RIGHT to choose, then press A."
);

static const u8 gText_ContinueMenuPlayer[] = _("PLAYER");
static const u8 gText_ContinueMenuTime[] = _("TIME");
static const u8 gText_ContinueMenuPokedex[] = _("POKéDEX");
static const u8 gText_ContinueMenuBadges[] = _("BADGES");
static const u8 gText_MainMenuTeam[] = _("Team: ");
static const u8 gText_MainMenuBadges[] = _("Badges: ");
static const u8 gText_MainMenuTime[] = _("Time: ");
static const u8 gText_MainMenuPokedex[] = _("Pokedex: ");

#define MENU_LEFT 2
#define MENU_TOP_WIN0 1
#define MENU_TOP_WIN1 5
#define MENU_TOP_WIN2 1
#define MENU_TOP_WIN3 9
#define MENU_TOP_WIN4 13
#define MENU_TOP_WIN5 17
#define MENU_TOP_WIN6 21
#define MENU_WIDTH 26
#define MENU_HEIGHT_WIN0 2
#define MENU_HEIGHT_WIN1 2
#define MENU_HEIGHT_WIN2 6
#define MENU_HEIGHT_WIN3 2
#define MENU_HEIGHT_WIN4 2
#define MENU_HEIGHT_WIN5 2
#define MENU_HEIGHT_WIN6 2

#define MENU_LEFT_ERROR 2
#define MENU_TOP_ERROR 15
#define MENU_WIDTH_ERROR 26
#define MENU_HEIGHT_ERROR 4

#define MENU_SHADOW_PADDING 1

#define MENU_WIN_HCOORDS WIN_RANGE(((MENU_LEFT - 1) * 8) + MENU_SHADOW_PADDING, (MENU_LEFT + MENU_WIDTH + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_WIN_VCOORDS(n) WIN_RANGE(((MENU_TOP_WIN##n - 1) * 8) + MENU_SHADOW_PADDING, (MENU_TOP_WIN##n + MENU_HEIGHT_WIN##n + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_SCROLL_SHIFT WIN_RANGE(32, 32)

static const struct WindowTemplate sWindowTemplates_MainMenu[] =
{
    // No saved game
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN0,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN0,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // OPTIONS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN1,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN1,
        .paletteNum = 15,
        .baseBlock = 0x35
    },
    // Has saved game
    // CONTINUE
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN2,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN3,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN3,
        .paletteNum = 15,
        .baseBlock = 0x9D
    },
    // OPTION / MYSTERY GIFT
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN4,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN4,
        .paletteNum = 15,
        .baseBlock = 0xD1
    },
    // OPTION / MYSTERY EVENTS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN5,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN5,
        .paletteNum = 15,
        .baseBlock = 0x105
    },
    // OPTION
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN6,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN6,
        .paletteNum = 15,
        .baseBlock = 0x139
    },
    // Error message window
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT_ERROR,
        .tilemapTop = MENU_TOP_ERROR,
        .width = MENU_WIDTH_ERROR,
        .height = MENU_HEIGHT_ERROR,
        .paletteNum = 15,
        .baseBlock = 0x16D
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sNewGameBirchSpeechTextWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x85
    },
    DUMMY_WIN_TEMPLATE
};

enum MainMenuBWWindow
{
    MAIN_MENU_BW_WINDOW_TEXT,
    MAIN_MENU_BW_WINDOW_ERROR,
};

static const struct WindowTemplate sMainMenuBWWindowTemplates[] =
{
    [MAIN_MENU_BW_WINDOW_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 20,
        .paletteNum = 15,
        .baseBlock = 0
    },
    [MAIN_MENU_BW_WINDOW_ERROR] =
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 16
    },
    DUMMY_WIN_TEMPLATE
};
static const u16 sMainMenuBgPal[] = INCBIN_U16("graphics/interface/main_menu_bw/bg.gbapal");
static const u16 sMainMenuNoSelPal[] = INCBIN_U16("graphics/interface/main_menu_bw/no_sel.gbapal");
static const u16 sMainMenuSelPal[] = INCBIN_U16("graphics/interface/main_menu_bw/sel.gbapal");
static const u16 sMainMenuTextPal[] = {RGB(0, 0, 0), RGB(30, 30, 30), RGB(17, 17, 17), RGB(7, 20, 31), RGB(7, 13, 20)};
static const u16 sMainMenuTextFemalePal[] = {RGB(31, 9, 11), RGB(21, 8, 8)};
static const u32 sMainMenuTilesBg1[] = INCBIN_U32("graphics/interface/main_menu_bw/tiles_bg1.4bpp.lz");
static const u32 sMainMenuTilesBg2[] = INCBIN_U32("graphics/interface/main_menu_bw/tiles_bg2.4bpp.lz");
static const u32 sMainMenuMapBg2[] = INCBIN_U32("graphics/interface/main_menu_bw/bg.bin.lz");
static const u32 sMainMenuMapNewGame[] = INCBIN_U32("graphics/interface/main_menu_bw/new_game.bin.lz");
static const u32 sMainMenuMapContinue[] = INCBIN_U32("graphics/interface/main_menu_bw/continue.bin.lz");

static const u8 sTextColor_Headers[] UNUSED = {TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3};
static const u8 sTextColor_MenuInfo[] = {TEXT_DYNAMIC_COLOR_1, TEXT_COLOR_WHITE, TEXT_DYNAMIC_COLOR_3};
static const u8 sMainMenuTextColorError[] = { 1, 2, 3 };

static const struct BgTemplate sMainMenuBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct BgTemplate sBirchBgTemplate = {
    .bg = 0,
    .charBaseIndex = 3,
    .mapBaseIndex = 30,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0
};

static const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu UNUSED = {2, 0x78, 8, 3, 0x78, 0x98, 3, 4, 1, 1, 0};

static const union AffineAnimCmd sSpriteAffineAnim_PlayerShrink[] = {
    AFFINEANIMCMD_FRAME(-2, -2, 0, 0x30),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_PlayerShrink[] =
{
    sSpriteAffineAnim_PlayerShrink
};

static const struct MenuAction sMenuActions_Gender[] = {
    {COMPOUND_STRING("BOY"), {NULL}},
    {COMPOUND_STRING("GIRL"), {NULL}}
};

static const u8 *const sMalePresetNames[] = {
    COMPOUND_STRING("ZEN"),
};

static const u8 *const sFemalePresetNames[] = {
    COMPOUND_STRING("KRIS"),
};

// The number of male vs. female names is assumed to be the same.
// If they aren't, the smaller of the two sizes will be used and any extra names will be ignored.
#define NUM_PRESET_NAMES min(ARRAY_COUNT(sMalePresetNames), ARRAY_COUNT(sFemalePresetNames))

enum
{
    HAS_NO_SAVED_GAME,  //NEW GAME, OPTION
    HAS_SAVED_GAME,     //CONTINUE, NEW GAME, OPTION
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY GIFT, OPTION
    HAS_MYSTERY_EVENTS, //CONTINUE, NEW GAME, MYSTERY GIFT, MYSTERY EVENTS, OPTION
};

enum
{
    ACTION_NEW_GAME,
    ACTION_CONTINUE,
    ACTION_OPTION,
    ACTION_MYSTERY_GIFT,
    ACTION_MYSTERY_EVENTS,
    ACTION_EREADER,
    ACTION_INVALID
};

#define MAIN_MENU_BORDER_TILE   0x1D5
#define BIRCH_DLG_BASE_TILE_NUM 0xFC

static void CB2_MainMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_MainMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitMainMenu(void)
{
    InitMainMenu(FALSE);
}

void CB2_ReinitMainMenu(void)
{
    InitMainMenu(TRUE);
}

static u32 InitMainMenu(bool8 returningFromOptionsMenu)
{
    u8 taskId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, -4);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)PLTT, PLTT_SIZE);

    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    InitWindows(sMainMenuBWWindowTemplates);
    DeactivateAllTextPrinters();

    LoadPalette(sMainMenuBgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sMainMenuNoSelPal, BG_PLTT_ID(1), 96);
    LoadPalette(sMainMenuSelPal, BG_PLTT_ID(1), 32);
    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), sizeof(sMainMenuTextPal));
    if (gSaveBlock2Ptr->playerGender != MALE)
        LoadPalette(sMainMenuTextFemalePal, BG_PLTT_ID(15) + 3, sizeof(sMainMenuTextFemalePal));

    LZ77UnCompVram(sMainMenuTilesBg1, (void *)VRAM);
    LZ77UnCompVram(sMainMenuTilesBg2, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(sMainMenuMapBg2, (void *)BG_SCREEN_ADDR(30));

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0x442);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x8);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);

    taskId = CreateTask(Task_MainMenuCheckSaveFile, 0);
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[8] = returningFromOptionsMenu;

    return 0;
}

#define tMenuType data[0]
#define tCurrItem data[1]
#define tReturnFromOptions data[8]
#define tItemCount data[12]
#define tScrollArrowTaskId data[13]
#define tIsScrolled data[14]
#define tWirelessAdapterConnected data[15]

#define tArrowTaskIsScrolled data[15]   // For scroll indicator arrow task

static void Task_MainMenuCheckSaveFile(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        SetGpuReg(REG_OFFSET_BLDY, 7);

        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_OK:
            LoadUserFrameToBg(0);
            tMenuType = HAS_SAVED_GAME;
            gTasks[taskId].func = Task_MainMenuCheckBattery;
            break;
        case SAVE_STATUS_CORRUPT:
            SetStdFrame0OnBg(0);
            tMenuType = HAS_NO_SAVED_GAME;
            PrintSaveErrorStatus(taskId, gText_SaveFileErased);
            gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
            break;
        case SAVE_STATUS_ERROR:
            SetStdFrame0OnBg(0);
            tMenuType = HAS_SAVED_GAME;
            PrintSaveErrorStatus(taskId, gText_SaveFileCorrupted);
            gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
            break;
        case SAVE_STATUS_EMPTY:
        default:
            LoadUserFrameToBg(0);
            tMenuType = HAS_NO_SAVED_GAME;
            gTasks[taskId].func = Task_MainMenuCheckBattery;
            break;
        case SAVE_STATUS_NO_FLASH:
            SetStdFrame0OnBg(0);
            tMenuType = HAS_NO_SAVED_GAME;
            PrintSaveErrorStatus(taskId, gJPText_No1MSubCircuit);
            gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
            break;
        }

        if (sCurrItemAndOptionMenuCheck & OPTION_MENU_FLAG)
        {
            sCurrItemAndOptionMenuCheck &= ~OPTION_MENU_FLAG;
            tCurrItem = (tMenuType == HAS_SAVED_GAME) ? 2 : 1;
        }
        else
        {
            tCurrItem = sCurrItemAndOptionMenuCheck;
        }

        tItemCount = (tMenuType == HAS_SAVED_GAME) ? 3 : 2;
        if (tCurrItem >= tItemCount)
            tCurrItem = 0;
    }
}

static void Task_WaitForSaveFileErrorWindow(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RunTextPrinters();
        if (!IsTextPrinterActive(MAIN_MENU_BW_WINDOW_ERROR) && JOY_NEW(A_BUTTON))
        {
            ClearWindowTilemap(MAIN_MENU_BW_WINDOW_ERROR);
            MainMenu_EraseWindow(&sMainMenuBWWindowTemplates[MAIN_MENU_BW_WINDOW_ERROR]);
            LoadUserFrameToBg(0);
            gTasks[taskId].func = Task_MainMenuCheckBattery;
        }
    }
}

static void Task_MainMenuCheckBattery(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        SetGpuReg(REG_OFFSET_BLDY, 7);

        if (!(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK))
        {
            gTasks[taskId].func = Task_DisplayMainMenu;
        }
        else
        {
            PrintSaveErrorStatus(taskId, gText_BatteryRunDry);
            gTasks[taskId].func = Task_WaitForBatteryDryErrorWindow;
        }
    }
}

static void Task_WaitForBatteryDryErrorWindow(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RunTextPrinters();
        if (!IsTextPrinterActive(MAIN_MENU_BW_WINDOW_ERROR) && JOY_NEW(A_BUTTON))
        {
            ClearWindowTilemap(MAIN_MENU_BW_WINDOW_ERROR);
            MainMenu_EraseWindow(&sMainMenuBWWindowTemplates[MAIN_MENU_BW_WINDOW_ERROR]);
            gTasks[taskId].func = Task_DisplayMainMenu;
        }
    }
}

static void Task_DisplayMainMenu(u8 taskId)
{

    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x10, 0x7));
        SetGpuReg(REG_OFFSET_BLDY, 0);

        FillWindowPixelBuffer(MAIN_MENU_BW_WINDOW_TEXT, PIXEL_FILL(0));
        switch (gTasks[taskId].tMenuType)
        {
        case HAS_NO_SAVED_GAME:
        default:
            LZ77UnCompVram(sMainMenuMapNewGame, (void *)BG_SCREEN_ADDR(29));
            PrintMainMenuItem(gText_MainMenuNewGame, 24, 16, 0);
            PrintMainMenuItem(gText_MainMenuOption, 24, 40, 0);
            break;
        case HAS_SAVED_GAME:
            LZ77UnCompVram(sMainMenuMapContinue, (void *)BG_SCREEN_ADDR(29));
            PrintMainMenuItem(gText_MainMenuContinue, 24, 8, 0);
            PrintMainMenuItem(gText_MainMenuNewGame, 24, 112, 0);
            PrintMainMenuItem(gText_MainMenuOption, 24, 136, 0);
            PrintContinueStats();
            break;
        }

        PutWindowTilemap(MAIN_MENU_BW_WINDOW_TEXT);
        CopyWindowToVram(MAIN_MENU_BW_WINDOW_TEXT, COPYWIN_FULL);
        gTasks[taskId].func = Task_WaitDma3AndFadeIn;
    }
}

static void Task_WaitDma3AndFadeIn(u8 taskId)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
        if (gTasks[taskId].tReturnFromOptions == TRUE)
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        else
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        SetVBlankCallback(VBlankCB_MainMenu);
    }
}
static void Task_HighlightSelectedMainMenuItem(u8 taskId)
{
    HighlightSelectedMainMenuItem(gTasks[taskId].tMenuType, gTasks[taskId].tCurrItem, gTasks[taskId].tIsScrolled);
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

static bool8 HandleMainMenuInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 menuItemCount = tItemCount;

    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_HandleMainMenuAPressed;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
        gTasks[taskId].func = Task_HandleMainMenuBPressed;
    }
    else if (JOY_NEW(DPAD_UP) && tCurrItem > 0)
    {
        tCurrItem--;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        PlaySE(SE_SELECT);
        return TRUE;
    }
    else if (JOY_NEW(DPAD_DOWN) && tCurrItem < menuItemCount - 1)
    {
        tCurrItem++;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        PlaySE(SE_SELECT);
        return TRUE;
    }

    return FALSE;
}

static void Task_HandleMainMenuInput(u8 taskId)
{
    if (HandleMainMenuInput(taskId))
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
}

static void Task_HandleMainMenuAPressed(u8 taskId)
{
    u8 action;

    if (!gPaletteFade.active)
    {
        switch (gTasks[taskId].tMenuType)
        {
        case HAS_SAVED_GAME:
            switch (gTasks[taskId].tCurrItem)
            {
            case 0:
            default:
                action = ACTION_CONTINUE;
                break;
            case 1:
                action = ACTION_NEW_GAME;
                break;
            case 2:
                action = ACTION_OPTION;
                break;
            }
            break;
        case HAS_NO_SAVED_GAME:
        default:
            action = (gTasks[taskId].tCurrItem == 0) ? ACTION_NEW_GAME : ACTION_OPTION;
            break;
        }

        DestroyAllSprites();
        switch (action)
        {
        case ACTION_NEW_GAME:
        default:
            MainMenu_BlankScreen();
            gPlttBufferUnfaded[0] = RGB_BLACK;
            gPlttBufferFaded[0] = RGB_BLACK;
            OptionMenu_SetNewGameSetup(TRUE);
            gMain.savedCallback = CB2_NewGame_GenderName;
            SetMainCallback2(CB2_InitOptionMenu);
            break;
        case ACTION_CONTINUE:
            MainMenu_BlankScreen();
            gPlttBufferUnfaded[0] = RGB_BLACK;
            gPlttBufferFaded[0] = RGB_BLACK;
            SetMainCallback2(CB2_ContinueSavedGame);
            DestroyTask(taskId);
            break;
        case ACTION_OPTION:
            OptionMenu_SetNewGameSetup(FALSE);
            gMain.savedCallback = CB2_ReinitMainMenu;
            SetMainCallback2(CB2_InitOptionMenu);
            DestroyTask(taskId);
            break;
        }
        FreeAllWindowBuffers();
        if (action != ACTION_OPTION)
            sCurrItemAndOptionMenuCheck = 0;
        else
            sCurrItemAndOptionMenuCheck = gTasks[taskId].tCurrItem | OPTION_MENU_FLAG;
    }
}

static void Task_HandleMainMenuBPressed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sCurrItemAndOptionMenuCheck = 0;
        DestroyAllSprites();
        MainMenu_BlankScreen();
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

static void UNUSED Task_DisplayMainMenuInvalidActionError(u8 taskId)
{
    switch (gTasks[taskId].tCurrItem)
    {
        case 0:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
            switch (gTasks[taskId].tMenuType)
            {
                case 0:
                    CreateMainMenuErrorWindow(gText_WirelessNotConnected);
                    break;
                case 1:
                    CreateMainMenuErrorWindow(gText_MysteryGiftCantUse);
                    break;
                case 2:
                    CreateMainMenuErrorWindow(gText_MysteryEventsCantUse);
                    break;
            }
            gTasks[taskId].tCurrItem++;
            break;
        case 1:
            if (!gPaletteFade.active)
                gTasks[taskId].tCurrItem++;
            break;
        case 2:
            RunTextPrinters();
            if (!IsTextPrinterActive(7))
                gTasks[taskId].tCurrItem++;
            break;
        case 3:
            if (JOY_NEW(A_BUTTON | B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_HandleMainMenuBPressed;
            }
    }
}

#undef tMenuType
#undef tCurrItem
#undef tReturnFromOptions
#undef tItemCount
#undef tScrollArrowTaskId
#undef tIsScrolled
#undef tWirelessAdapterConnected

#undef tArrowTaskIsScrolled

static void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 isScrolled)
{
    (void)isScrolled;
    MoveWindowByMenuTypeAndCursorPos(menuType, selectedMenuItem);
}

static void MoveWindowByMenuTypeAndCursorPos(u8 menuType, u8 cursorPos)
{
    LoadPalette(sMainMenuNoSelPal, BG_PLTT_ID(1), 96);
    switch (menuType)
    {
    case HAS_SAVED_GAME:
        switch (cursorPos)
        {
        case 0:
        default:
            LoadPalette(sMainMenuSelPal, BG_PLTT_ID(1), 32);
            DestroyAllSprites();
            LoadOverWorld(1);
            LoadMonIcon(1);
            break;
        case 1:
            LoadPalette(sMainMenuSelPal, BG_PLTT_ID(2), 32);
            DestroyAllSprites();
            LoadOverWorld(0);
            LoadMonIcon(0);
            break;
        case 2:
            LoadPalette(sMainMenuSelPal, BG_PLTT_ID(3), 32);
            break;
        }
        break;
    case HAS_NO_SAVED_GAME:
    default:
        switch (cursorPos)
        {
        case 0:
        default:
            LoadPalette(sMainMenuSelPal, BG_PLTT_ID(1), 32);
            break;
        case 1:
            LoadPalette(sMainMenuSelPal, BG_PLTT_ID(2), 32);
            break;
        }
        break;
    }
}

static void PrintSaveErrorStatus(u8 taskId, const u8 *str)
{
    (void)taskId;
    PrintMessageOnWindow4(str);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetVBlankCallback(VBlankCB_MainMenu);
}

static void PrintMessageOnWindow4(const u8 *str)
{
    FillWindowPixelBuffer(MAIN_MENU_BW_WINDOW_TEXT, PIXEL_FILL(0));
    FillWindowPixelBuffer(MAIN_MENU_BW_WINDOW_ERROR, PIXEL_FILL(1));
    MainMenu_DrawWindow(&sMainMenuBWWindowTemplates[MAIN_MENU_BW_WINDOW_ERROR]);
    AddTextPrinterParameterized3(MAIN_MENU_BW_WINDOW_ERROR, FONT_NORMAL, 0, 2, sMainMenuTextColorError, 2, str);
    PutWindowTilemap(MAIN_MENU_BW_WINDOW_ERROR);
    CopyWindowToVram(MAIN_MENU_BW_WINDOW_ERROR, COPYWIN_FULL);
}

static void PrintContinueStats(void)
{
    PrintPlayerName();
    PrintDexCount();
    PrintPlayTime();
    PrintBadgeCount();
    PrintLocation();
    PrintTeam();
    LoadOverWorld(1);
    LoadMonIcon(1);
}

static void PrintPlayerName(void)
{
    PrintMainMenuItem(gSaveBlock2Ptr->playerName, 72, 40, 1);
}

static void PrintPlayTime(void)
{
    u8 strbuf[20];
    u8 time[8];
    u8 *timePtr;

    timePtr = ConvertIntToDecimalStringN(time, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *timePtr++ = CHAR_COLON;
    ConvertIntToDecimalStringN(timePtr, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);

    StringCopy(strbuf, gText_MainMenuTime);
    StringAppend(strbuf, time);
    PrintMainMenuItem(strbuf, 128, 56, 0);
}

static void PrintDexCount(void)
{
    u16 dexcount;
    u8 dexCount[4];
    u8 strbuf[20];

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        StringCopy(strbuf, gText_MainMenuPokedex);
        if (IsNationalPokedexEnabled())
            dexcount = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        else
            dexcount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
        ConvertIntToDecimalStringN(dexCount, dexcount, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(strbuf, dexCount);
        PrintMainMenuItem(strbuf, 128, 40, 0);
    }
}

static const u16 sMainMenuBadgeFlags[] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
    FLAG_BADGE09_GET,
    FLAG_BADGE10_GET,
    FLAG_BADGE11_GET,
    FLAG_BADGE12_GET,
    FLAG_BADGE13_GET,
    FLAG_BADGE14_GET,
    FLAG_BADGE15_GET,
    FLAG_BADGE16_GET,
    FLAG_BADGE17_GET,
    FLAG_BADGE18_GET,
    FLAG_BADGE19_GET,
    FLAG_BADGE20_GET,
    FLAG_BADGE21_GET,
    FLAG_BADGE22_GET,
    FLAG_BADGE23_GET,
    FLAG_BADGE24_GET,
};

static void PrintBadgeCount(void)
{
    u8 badgecount = 0;
    u8 strbuf[20];
    u8 badgeCount[3];
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMainMenuBadgeFlags); i++)
    {
        if (FlagGet(sMainMenuBadgeFlags[i]))
            badgecount++;
    }
    if (badgecount)
    {
        StringCopy(strbuf, gText_MainMenuBadges);
        ConvertIntToDecimalStringN(badgeCount, badgecount, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(strbuf, badgeCount);
        PrintMainMenuItem(strbuf, 128, 24, 0);
    }
}

static void PrintLocation(void)
{
    GetMapName(gStringVar4, Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId, 0);
    PrintMainMenuItem(gStringVar4, 128, 8, 0);
}

static void PrintTeam(void)
{
    PrintMainMenuItem(gText_MainMenuTeam, 24, 56, 0);
}

static void MainMenu_BlankScreen(void)
{
    ClearWindowTilemap(MAIN_MENU_BW_WINDOW_TEXT);
    ClearWindowTilemap(MAIN_MENU_BW_WINDOW_ERROR);
    FillBgTilemapBufferRect(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 0);
    FillBgTilemapBufferRect(1, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 0);
    FillBgTilemapBufferRect(2, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 0);
    CopyBgTilemapBufferToVram(0);
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(2);
    HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
}

static void DestroyAllSprites(void)
{
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
}

static void LoadOverWorld(u8 anim)
{
    u16 graphicsId;
    u8 spriteId;

    graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gSaveBlock2Ptr->playerGender);
    spriteId = CreateObjectGraphicsSprite(graphicsId, SpriteCallbackDummy, 40, 40, 0);
    gSprites[spriteId].oam.priority = 0;
    if (anim == 0)
        StartSpriteAnim(&gSprites[spriteId], ANIM_STD_FACE_SOUTH);
    else
        StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_SOUTH);
}

static void LoadMonIcon(u8 anim)
{
    u8 i;
    u8 spriteId;
    u32 personality;
    u16 species;
    bool8 isShadow;

    LoadMonIconPalettes();
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY, NULL);
        isShadow = GetMonData(&gPlayerParty[i], MON_DATA_IS_SHADOW, NULL);
        if (anim == 0)
            spriteId = CreateMonIcon(species, SpriteCallbackDummy, 32 * i + 40, 88, 0, personality, isShadow);
        else
            spriteId = CreateMonIcon(species, SpriteCB_MonIcon, 32 * i + 40, 88, 0, personality, isShadow);
        StartSpriteAnim(&gSprites[spriteId], 0);
    }
}

static void LoadUserFrameToBg(u8 bgId)
{
    LoadUserWindowBorderGfxOnBg(bgId, 0x1B1, BG_PLTT_ID(14));
    MainMenu_EraseWindow(&sMainMenuBWWindowTemplates[MAIN_MENU_BW_WINDOW_ERROR]);
}

static void SetStdFrame0OnBg(u8 bgId)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(0)->tiles, 0x120, 0x1B1);
    LoadPalette(GetWindowFrameTilesPal(0)->pal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    MainMenu_EraseWindow(&sMainMenuBWWindowTemplates[MAIN_MENU_BW_WINDOW_ERROR]);
}

static void PrintMainMenuItem(const u8 *string, u8 left, u8 top, u8 textColor)
{
    u8 color[3];

    switch (textColor)
    {
    case 1:
        color[0] = 0;
        color[1] = 3;
        color[2] = 4;
        break;
    case 0:
    default:
        color[0] = 0;
        color[1] = 1;
        color[2] = 2;
        break;
    }

    AddTextPrinterParameterized3(MAIN_MENU_BW_WINDOW_TEXT, FONT_NORMAL, left, top + 1, color, 0, string);
    CopyWindowToVram(MAIN_MENU_BW_WINDOW_TEXT, COPYWIN_GFX);
}

static void MainMenu_DrawWindow(const struct WindowTemplate *windowTemplate)
{
    u8 palNum = windowTemplate->paletteNum;

    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B1, windowTemplate->tilemapLeft - 1, windowTemplate->tilemapTop - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B2, windowTemplate->tilemapLeft, windowTemplate->tilemapTop - 1, windowTemplate->width, 1, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B3, windowTemplate->tilemapLeft + windowTemplate->width, windowTemplate->tilemapTop - 1, 1, 1, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B4, windowTemplate->tilemapLeft - 1, windowTemplate->tilemapTop, 1, windowTemplate->height, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B6, windowTemplate->tilemapLeft + windowTemplate->width, windowTemplate->tilemapTop, 1, windowTemplate->height, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B7, windowTemplate->tilemapLeft - 1, windowTemplate->tilemapTop + windowTemplate->height, 1, 1, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B8, windowTemplate->tilemapLeft, windowTemplate->tilemapTop + windowTemplate->height, windowTemplate->width, 1, palNum);
    FillBgTilemapBufferRect(windowTemplate->bg, 0x1B9, windowTemplate->tilemapLeft + windowTemplate->width, windowTemplate->tilemapTop + windowTemplate->height, 1, 1, palNum);
    CopyBgTilemapBufferToVram(windowTemplate->bg);
}

static void MainMenu_EraseWindow(const struct WindowTemplate *windowTemplate)
{
    FillBgTilemapBufferRect(windowTemplate->bg, 0, windowTemplate->tilemapLeft - 1, windowTemplate->tilemapTop - 1,
                            windowTemplate->width + 2, windowTemplate->height + 2, windowTemplate->paletteNum);
    CopyBgTilemapBufferToVram(windowTemplate->bg);
}
#define tPlayerSpriteId data[2]
#define tBG1HOFS data[4]
#define tIsDoneFadingSprites data[5]
#define tPlayerGender data[6]
#define tTimer data[7]
#define tBirchSpriteId data[8]
#define tLotadSpriteId data[9]
#define tBrendanSpriteId data[10]
#define tMaySpriteId data[11]

static void UNUSED Task_NewGameBirchSpeech_Init(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
    InitBgFromTemplate(&sBirchBgTemplate);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DecompressDataWithHeaderVram(sBirchSpeechShadowGfx, (void *)VRAM);
    DecompressDataWithHeaderVram(sBirchSpeechBgMap, (void *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sBirchSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sBirchSpeechBgGradientPal[8], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gTasks[taskId].tBG1HOFS = 0;
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitToShowBirch;
    gTasks[taskId].tPlayerSpriteId = SPRITE_NONE;
    gTasks[taskId].data[3] = 0xFF;
    gTasks[taskId].tTimer = 0xD8;
    PlayBGM(MUS_ROUTE122);
    ShowBg(0);
    ShowBg(1);
}

static void Task_NewGameBirchSpeech_WaitToShowBirch(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        spriteId = gTasks[taskId].tBirchSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 10);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 20);
        gTasks[taskId].tTimer = 80;
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome;
    }
}

static void Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            InitWindows(sNewGameBirchSpeechTextWindows);
            LoadMainMenuWindowFrameTiles(0, 0xF3);
            LoadMessageBoxGfx(0, BIRCH_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
            NewGameBirchSpeech_ShowDialogueWindow(0, 1);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_GFX);
            NewGameBirchSpeech_ClearWindow(0);
            StringExpandPlaceholders(gStringVar4, gText_Birch_Welcome);
            AddTextPrinterForMessage(TRUE);
            gTasks[taskId].func = Task_NewGameBirchSpeech_ThisIsAPokemon;
        }
    }
}

static void Task_NewGameBirchSpeech_ThisIsAPokemon(u8 taskId)
{
    if (!gPaletteFade.active && !RunTextPrintersAndIsPrinter0Active())
    {
        gTasks[taskId].func = Task_NewGameBirchSpeech_MainSpeech;
        StringExpandPlaceholders(gStringVar4, gText_ThisIsAPokemon);
        AddTextPrinterWithCallbackForMessage(TRUE, NewGameBirchSpeech_WaitForThisIsPokemonText);
        sBirchSpeechMainTaskId = taskId;
    }
}

static void Task_NewGameBirchSpeech_MainSpeech(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StringExpandPlaceholders(gStringVar4, gText_Birch_MainSpeech);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_AndYouAre;
    }
}

#define tState data[0]

static void Task_NewGameBirchSpeechSub_InitPokeBall(u8 taskId)
{
    u8 spriteId = gTasks[sBirchSpeechMainTaskId].tLotadSpriteId;

    gSprites[spriteId].x = 100;
    gSprites[spriteId].y = 75;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = 0;

    CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 112, 58, 0, 0, 32, PALETTES_BG, SPECIES_LOTAD);
    gTasks[taskId].func = Task_NewGameBirchSpeechSub_WaitForLotad;
    gTasks[sBirchSpeechMainTaskId].tTimer = 0;
}

static void Task_NewGameBirchSpeechSub_WaitForLotad(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Sprite *sprite = &gSprites[gTasks[sBirchSpeechMainTaskId].tLotadSpriteId];

    switch (tState)
    {
        case 0:
            if (sprite->callback != SpriteCallbackDummy)
                return;
            sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
            break;
        case 1:
            if (gTasks[sBirchSpeechMainTaskId].tTimer >= 96)
            {
                DestroyTask(taskId);
                if (gTasks[sBirchSpeechMainTaskId].tTimer < 0x4000)
                    gTasks[sBirchSpeechMainTaskId].tTimer++;
            }
            return;
    }
    tState++;
    if (gTasks[sBirchSpeechMainTaskId].tTimer < 0x4000)
        gTasks[sBirchSpeechMainTaskId].tTimer++;
}

#undef tState

static void Task_NewGameBirchSpeech_AndYouAre(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        sStartedPokeBallTask = FALSE;
        StringExpandPlaceholders(gStringVar4, gText_Birch_AndYouAre);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartBirchLotadPlatformFade;
    }
}

static void Task_NewGameBirchSpeech_StartBirchLotadPlatformFade(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
        gTasks[taskId].tTimer = 64;
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlidePlatformAway;
    }
}

static void Task_NewGameBirchSpeech_SlidePlatformAway(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS != -60)
    {
        gTasks[taskId].tBG1HOFS -= 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].tBG1HOFS = -60;
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartPlayerFadeIn;
    }
}

static void Task_NewGameBirchSpeech_StartPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tLotadSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            u8 spriteId = gTasks[taskId].tBrendanSpriteId;

            gSprites[spriteId].x = 180;
            gSprites[spriteId].y = 60;
            gSprites[spriteId].invisible = FALSE;
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gTasks[taskId].tPlayerSpriteId = spriteId;
            gTasks[taskId].tPlayerGender = MALE;
            NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForPlayerFadeIn;
        }
    }
}

static void Task_NewGameBirchSpeech_WaitForPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gTasks[taskId].func = Task_NewGameBirchSpeech_BoyOrGirl;
    }
}

static void Task_NewGameBirchSpeech_BoyOrGirl(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_BoyOrGirl);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitToShowGenderMenu;
}

static void Task_NewGameBirchSpeech_WaitToShowGenderMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        NewGameBirchSpeech_ShowGenderMenu();
        gTasks[taskId].func = Task_NewGameBirchSpeech_ChooseGender;
    }
}

static void Task_NewGameBirchSpeech_ChooseGender(u8 taskId)
{
    int gender = NewGameBirchSpeech_ProcessGenderMenuInput();
    int gender2;

    switch (gender)
    {
        case MALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            NewGameBirchSpeech_ClearGenderWindow(1, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WhatsYourName;
            break;
        case FEMALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            NewGameBirchSpeech_ClearGenderWindow(1, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WhatsYourName;
            break;
    }
    gender2 = Menu_GetCursorPos();
    if (gender2 != gTasks[taskId].tPlayerGender)
    {
        gTasks[taskId].tPlayerGender = gender2;
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlideOutOldGenderSprite;
    }
}

static void Task_NewGameBirchSpeech_SlideOutOldGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;
    if (gTasks[taskId].tIsDoneFadingSprites == 0)
    {
        gSprites[spriteId].x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].tPlayerGender != MALE)
            spriteId = gTasks[taskId].tMaySpriteId;
        else
            spriteId = gTasks[taskId].tBrendanSpriteId;
        gSprites[spriteId].x = DISPLAY_WIDTH;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SlideInNewGenderSprite;
    }
}

static void Task_NewGameBirchSpeech_SlideInNewGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].x > 180)
    {
        gSprites[spriteId].x -= 4;
    }
    else
    {
        gSprites[spriteId].x = 180;
        if (gTasks[taskId].tIsDoneFadingSprites)
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
            gTasks[taskId].func = Task_NewGameBirchSpeech_ChooseGender;
        }
    }
}

static void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_WhatsYourName);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint;
}

static void Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitPressBeforeNameChoice;
}

static void Task_NewGameBirchSpeech_WaitPressBeforeNameChoice(u8 taskId)
{
    if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_NewGameBirchSpeech_StartNamingScreen;
    }
}

static void Task_NewGameBirchSpeech_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tLotadSpriteId);
        NewGameBirchSpeech_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, FALSE, CB2_NewGameBirchSpeech_ReturnFromNamingScreen);
    }
}

static void Task_NewGameBirchSpeech_SoItsPlayerName(u8 taskId)
{
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_SoItsPlayer);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameBirchSpeech_CreateNameYesNo;
}

static void Task_NewGameBirchSpeech_CreateNameYesNo(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        CreateYesNoMenuParameterized(2, 1, 0xF3, 0xDF, 2, 15);
        gTasks[taskId].func = Task_NewGameBirchSpeech_ProcessNameYesNoMenu;
    }
}

static void Task_NewGameBirchSpeech_ProcessNameYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            PlaySE(SE_SELECT);
            gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
            gTasks[taskId].func = Task_NewGameBirchSpeech_SlidePlatformAway2;
            break;
        case MENU_B_PRESSED:
        case 1:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_NewGameBirchSpeech_BoyOrGirl;
    }
}

static void Task_NewGameBirchSpeech_SlidePlatformAway2(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS)
    {
        gTasks[taskId].tBG1HOFS += 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].func = Task_NewGameBirchSpeech_ReshowBirchLotad;
    }
}

static void Task_NewGameBirchSpeech_ReshowBirchLotad(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBrendanSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tMaySpriteId].invisible = TRUE;
        spriteId = gTasks[taskId].tBirchSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        spriteId = gTasks[taskId].tLotadSpriteId;
        gSprites[spriteId].x = 100;
        gSprites[spriteId].y = 75;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
        NewGameBirchSpeech_ClearWindow(0);
        StringExpandPlaceholders(gStringVar4, gText_Birch_YourePlayer);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter;
    }
}

static void Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            gSprites[gTasks[taskId].tBirchSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gSprites[gTasks[taskId].tLotadSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            NewGameBirchSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
            NewGameBirchSpeech_StartFadePlatformIn(taskId, 1);
            gTasks[taskId].tTimer = 64;
            gTasks[taskId].func = Task_NewGameBirchSpeech_AreYouReady;
        }
    }
}

static void Task_NewGameBirchSpeech_AreYouReady(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tBirchSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tLotadSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
            return;
        }
        if (gSaveBlock2Ptr->playerGender != MALE)
            spriteId = gTasks[taskId].tMaySpriteId;
        else
            spriteId = gTasks[taskId].tBrendanSpriteId;
        gSprites[spriteId].x = 120;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        NewGameBirchSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameBirchSpeech_StartFadePlatformOut(taskId, 1);
        StringExpandPlaceholders(gStringVar4, gText_Birch_AreYouReady);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameBirchSpeech_ShrinkPlayer;
    }
}

static void Task_NewGameBirchSpeech_ShrinkPlayer(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            spriteId = gTasks[taskId].tPlayerSpriteId;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_PlayerShrink;
            InitSpriteAffineAnim(&gSprites[spriteId]);
            StartSpriteAffineAnim(&gSprites[spriteId], 0);
            gSprites[spriteId].callback = SpriteCB_MovePlayerDownWhileShrinking;
            BeginNormalPaletteFade(PALETTES_BG, 0, 0, 16, RGB_BLACK);
            FadeOutBGM(4);
            gTasks[taskId].func = Task_NewGameBirchSpeech_WaitForPlayerShrink;
        }
    }
}

static void Task_NewGameBirchSpeech_WaitForPlayerShrink(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].affineAnimEnded)
        gTasks[taskId].func = Task_NewGameBirchSpeech_FadePlayerToWhite;
}

static void Task_NewGameBirchSpeech_FadePlayerToWhite(u8 taskId)
{
    u8 spriteId;

    if (!gPaletteFade.active)
    {
        spriteId = gTasks[taskId].tPlayerSpriteId;
        gSprites[spriteId].callback = SpriteCB_Null;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = Task_NewGameBirchSpeech_Cleanup;
    }
}

static void Task_NewGameBirchSpeech_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tLotadSpriteId);
        ResetAllPicSprites();
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}

static void CB2_NewGameBirchSpeech_ReturnFromNamingScreen(void)
{
    u8 taskId;
    u8 spriteId;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    InitBgFromTemplate(&sBirchBgTemplate);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    DecompressDataWithHeaderVram(sBirchSpeechShadowGfx, (u8 *)VRAM);
    DecompressDataWithHeaderVram(sBirchSpeechBgMap, (u8 *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sBirchSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sBirchSpeechBgGradientPal[1], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ResetTasks();
    taskId = CreateTask(Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox, 0);
    gTasks[taskId].tTimer = 5;
    gTasks[taskId].tBG1HOFS = -60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        gTasks[taskId].tPlayerGender = FEMALE;
        spriteId = gTasks[taskId].tMaySpriteId;
    }
    else
    {
        gTasks[taskId].tPlayerGender = MALE;
        spriteId = gTasks[taskId].tBrendanSpriteId;
    }
    gSprites[spriteId].x = 180;
    gSprites[spriteId].y = 60;
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].tPlayerSpriteId = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    InitWindows(sNewGameBirchSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, BIRCH_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void SpriteCB_Null(struct Sprite *sprite)
{
}

static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *sprite)
{
    u32 y;

    y = (sprite->y << 16) + sprite->data[0] + 0xC000;
    sprite->y = y >> 16;
    sprite->data[0] = y;
}

static u8 NewGameBirchSpeech_CreateLotadSprite(u8 x, u8 y)
{
    return CreateMonPicSprite_Affine(SPECIES_LOTAD, FALSE, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
}

static void AddBirchSpeechObjects(u8 taskId)
{
    u8 birchSpriteId;
    u8 lotadSpriteId;
    u8 brendanSpriteId;
    u8 maySpriteId;

    birchSpriteId = AddNewGameBirchObject(0x88, 0x3C, 1);
    gSprites[birchSpriteId].callback = SpriteCB_Null;
    gSprites[birchSpriteId].oam.priority = 0;
    gSprites[birchSpriteId].invisible = TRUE;
    gTasks[taskId].tBirchSpriteId = birchSpriteId;
    lotadSpriteId = NewGameBirchSpeech_CreateLotadSprite(100, 0x4B);
    gSprites[lotadSpriteId].callback = SpriteCB_Null;
    gSprites[lotadSpriteId].oam.priority = 0;
    gSprites[lotadSpriteId].invisible = TRUE;
    gTasks[taskId].tLotadSpriteId = lotadSpriteId;
    brendanSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), 120, 60, 0, NULL);
    gSprites[brendanSpriteId].callback = SpriteCB_Null;
    gSprites[brendanSpriteId].invisible = TRUE;
    gSprites[brendanSpriteId].oam.priority = 0;
    gTasks[taskId].tBrendanSpriteId = brendanSpriteId;
    maySpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_MAY), 120, 60, 0, NULL);
    gSprites[maySpriteId].callback = SpriteCB_Null;
    gSprites[maySpriteId].invisible = TRUE;
    gSprites[maySpriteId].oam.priority = 0;
    gTasks[taskId].tMaySpriteId = maySpriteId;
}

#undef tPlayerSpriteId
#undef tBG1HOFS
#undef tPlayerGender
#undef tBirchSpriteId
#undef tLotadSpriteId
#undef tBrendanSpriteId
#undef tMaySpriteId

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameBirchSpeech_FadeOutTarget1InTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameBirchSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameBirchSpeech_FadeInTarget1OutTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameBirchSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tAlphaCoeff1
#undef tAlphaCoeff2
#undef tDelay
#undef tDelayTimer

#undef tIsDoneFadingSprites

#define tMainTask data[0]
#define tPalIndex data[1]
#define tDelayBefore data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameBirchSpeech_FadePlatformIn(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 8)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex++;
        LoadPalette(&sBirchSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameBirchSpeech_StartFadePlatformIn(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadePlatformIn, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 0;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameBirchSpeech_FadePlatformOut(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 0)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex--;
        LoadPalette(&sBirchSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameBirchSpeech_StartFadePlatformOut(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameBirchSpeech_FadePlatformOut, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 8;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tPalIndex
#undef tDelayBefore
#undef tDelay
#undef tDelayTimer

static void NewGameBirchSpeech_ShowGenderMenu(void)
{
    DrawMainMenuWindowBorder(&sNewGameBirchSpeechTextWindows[1], 0xF3);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PrintMenuTable(1, ARRAY_COUNT(sMenuActions_Gender), sMenuActions_Gender);
    InitMenuInUpperLeftCornerNormal(1, ARRAY_COUNT(sMenuActions_Gender), 0);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static s8 NewGameBirchSpeech_ProcessGenderMenuInput(void)
{
    return Menu_ProcessInputNoWrap();
}

void NewGameBirchSpeech_SetDefaultPlayerName(u8 nameId)
{
    const u8 *name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = sMalePresetNames[nameId];
    else
        name = sFemalePresetNames[nameId];
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[PLAYER_NAME_LENGTH] = EOS;
}

static void UNUSED CreateMainMenuErrorWindow(const u8 *str)
{
    FillWindowPixelBuffer(7, PIXEL_FILL(1));
    AddTextPrinterParameterized(7, FONT_NORMAL, str, 0, 1, 2, 0);
    PutWindowTilemap(7);
    CopyWindowToVram(7, COPYWIN_GFX);
    DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[7], MAIN_MENU_BORDER_TILE);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(9, DISPLAY_WIDTH - 9));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(113, DISPLAY_HEIGHT - 1));
}

static void UNUSED MainMenu_FormatSavegameText(void)
{
    MainMenu_FormatSavegamePlayer();
    MainMenu_FormatSavegamePokedex();
    MainMenu_FormatSavegameTime();
    MainMenu_FormatSavegameBadges();
}

static void UNUSED MainMenu_FormatSavegamePlayer(void)
{
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPlayer);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 17, sTextColor_MenuInfo, TEXT_SKIP_DRAW, gStringVar4);
    AddTextPrinterParameterized3(2, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, gSaveBlock2Ptr->playerName, 100), 17, sTextColor_MenuInfo, TEXT_SKIP_DRAW, gSaveBlock2Ptr->playerName);
}

static void UNUSED MainMenu_FormatSavegameTime(void)
{
    u8 str[0x20];
    u8 *ptr;

    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuTime);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0x6C, 17, sTextColor_MenuInfo, TEXT_SKIP_DRAW, gStringVar4);
    ptr = ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr = 0xF0;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(2, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, str, 0xD0), 17, sTextColor_MenuInfo, TEXT_SKIP_DRAW, str);
}

static void UNUSED MainMenu_FormatSavegamePokedex(void)
{
    u8 str[0x20];
    u16 dexCount;

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        if (IsNationalPokedexEnabled())
            dexCount = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        else
            dexCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
        StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPokedex);
        AddTextPrinterParameterized3(2, FONT_NORMAL, 0, 33, sTextColor_MenuInfo, TEXT_SKIP_DRAW, gStringVar4);
        ConvertIntToDecimalStringN(str, dexCount, STR_CONV_MODE_LEFT_ALIGN, 4);
        AddTextPrinterParameterized3(2, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, str, 100), 33, sTextColor_MenuInfo, TEXT_SKIP_DRAW, str);
    }
}

static void UNUSED MainMenu_FormatSavegameBadges(void)
{
    u8 str[0x20];
    u8 badgeCount = 0;
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (FlagGet(gBadgeFlags[i]))
            badgeCount++;
    }
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuBadges);
    AddTextPrinterParameterized3(2, FONT_NORMAL, 0x6C, 33, sTextColor_MenuInfo, TEXT_SKIP_DRAW, gStringVar4);
    ConvertIntToDecimalStringN(str, badgeCount, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(2, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, str, 0xD0), 33, sTextColor_MenuInfo, TEXT_SKIP_DRAW, str);
}

static void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
}

static void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u16 r9 = 1 + baseTileNum;
    u16 r10 = 2 + baseTileNum;
    u16 sp18 = 3 + baseTileNum;
    u16 spC = 5 + baseTileNum;
    u16 sp10 = 6 + baseTileNum;
    u16 sp14 = 7 + baseTileNum;
    u16 r6 = 8 + baseTileNum;

    FillBgTilemapBufferRect(template->bg, baseTileNum, template->tilemapLeft - 1, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, r9, template->tilemapLeft, template->tilemapTop - 1, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r10, template->tilemapLeft + template->width, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp18, template->tilemapLeft - 1, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, spC, template->tilemapLeft + template->width, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, sp10, template->tilemapLeft - 1, template->tilemapTop + template->height, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp14, template->tilemapLeft, template->tilemapTop + template->height, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r6, template->tilemapLeft + template->width, template->tilemapTop + template->height, 1, 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

static void UNUSED ClearMainMenuWindowTilemap(const struct WindowTemplate *template)
{
    FillBgTilemapBufferRect(template->bg, 0, template->tilemapLeft - 1, template->tilemapTop - 1, template->tilemapLeft + template->width + 1, template->tilemapTop + template->height + 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

static void NewGameBirchSpeech_ClearGenderWindowTilemap(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 unused)
{
    FillBgTilemapBufferRect(bg, 0, x + 255, y + 255, width + 2, height + 2, 2);
}

static void NewGameBirchSpeech_ClearGenderWindow(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, NewGameBirchSpeech_ClearGenderWindowTilemap);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void NewGameBirchSpeech_ClearWindow(u8 windowId)
{
    u8 bgColor = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    u8 maxCharWidth = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_WIDTH);
    u8 maxCharHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    u8 winWidth = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u8 winHeight = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillWindowPixelRect(windowId, bgColor, 0, 0, maxCharWidth * winWidth, maxCharHeight * winHeight);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void NewGameBirchSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *printer, u16 renderCmd)
{
    // Wait for Birch's "This is a Pokémon" text to reach the pause
    // Then start the PokéBall release (if it hasn't been started already)
    if (*(printer->currentChar - 2) == EXT_CTRL_CODE_PAUSE && !sStartedPokeBallTask)
    {
        sStartedPokeBallTask = TRUE;
        CreateTask(Task_NewGameBirchSpeechSub_InitPokeBall, 0);
    }
}

void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, 5, 4, winPalNum, baseBlock);
    CreateYesNoMenu(&template, baseTileNum, yesNoPalNum, 0);
}

static void NewGameBirchSpeech_ShowDialogueWindow(u8 windowId, u8 copyToVram)
{
    CallWindowFunction(windowId, NewGameBirchSpeech_CreateDialogueWindowBorder);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void NewGameBirchSpeech_CreateDialogueWindowBorder(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palNum)
{
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  1, x-2,       y-1, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  3, x-1,       y-1, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  4, x,         y-1, width,   1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  5, x+width-1, y-1, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  6, x+width,   y-1, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  7, x-2,       y,   1,       5, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM +  9, x-1,       y,   width+1, 5, palNum);
    FillBgTilemapBufferRect(bg, BIRCH_DLG_BASE_TILE_NUM + 10, x+width,   y,   1,       5, palNum);

    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 1), x-2,       y+height, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 3), x-1,       y+height, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 4), x,         y+height, width-1, 1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 5), x+width-1, y+height, 1,       1, palNum);
    FillBgTilemapBufferRect(bg, BG_TILE_V_FLIP(BIRCH_DLG_BASE_TILE_NUM + 6), x+width,   y+height, 1,       1, palNum);
}

static void Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId)
{
    if (gTasks[taskId].tTimer-- <= 0)
    {
        NewGameBirchSpeech_ShowDialogueWindow(0, 1);
        gTasks[taskId].func = Task_NewGameBirchSpeech_SoItsPlayerName;
    }
}
// --- New Game story -> gender select -> naming screen ---

#define tState data[0]
#define tSelectedGender data[1]
#define tMaleSpriteId data[2]
#define tFemaleSpriteId data[3]
#define tSpritesCreated data[4]
#define tMaleOwSpriteId data[5]
#define tFemaleOwSpriteId data[6]

static void CB2_NewGame_GenderName(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    ShowBg(0);
    HideBg(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    FillBgTilemapBufferRect(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 0);
    CopyBgTilemapBufferToVram(0);
    InitWindows(sNewGameBirchSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, BIRCH_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
    LoadPalette(sNewGameTextPal, BG_PLTT_ID(15), sizeof(sNewGameTextPal));
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    CreateTask(Task_GenderThenName, 0);

    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
}

static void Task_GenderThenName(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            PrepareNewGameFlowTextWindow();
            StringCopy(gStringVar4, sText_NewGameIntroStory);
            PrintNewGameFlowText();
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            if (JOY_NEW(A_BUTTON | B_BUTTON))
            {
                PrepareNewGameFlowTextWindow();
                StringCopy(gStringVar4, sText_NewGameChooseGender);
                PrintNewGameFlowText();
                gTasks[taskId].tState = 2;
            }
        }
        break;
    case 2:
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            if (!gTasks[taskId].tSpritesCreated)
            {
                gTasks[taskId].tMaleSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), 56, 64, 0, NULL);
                gTasks[taskId].tFemaleSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_MAY), 184, 64, 0, NULL);
                gTasks[taskId].tMaleOwSpriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_BRENDAN_NORMAL, SpriteCallbackDummy, 24, 88, 0);
                gTasks[taskId].tFemaleOwSpriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MAY_NORMAL, SpriteCallbackDummy, 216, 88, 0);
                gSprites[gTasks[taskId].tMaleSpriteId].oam.priority = 0;
                gSprites[gTasks[taskId].tFemaleSpriteId].oam.priority = 0;
                gSprites[gTasks[taskId].tMaleOwSpriteId].oam.priority = 0;
                gSprites[gTasks[taskId].tFemaleOwSpriteId].oam.priority = 0;
                StartSpriteAnim(&gSprites[gTasks[taskId].tMaleOwSpriteId], ANIM_STD_GO_SOUTH);
                StartSpriteAnim(&gSprites[gTasks[taskId].tFemaleOwSpriteId], ANIM_STD_GO_SOUTH);
                gTasks[taskId].tSelectedGender = MALE;
                gTasks[taskId].tSpritesCreated = 1;
                UpdateGenderSelectionSprites(taskId);
            }
            gTasks[taskId].tState = 3;
        }
        break;
    case 3:
        if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
        {
            gTasks[taskId].tSelectedGender = (gTasks[taskId].tSelectedGender == MALE) ? FEMALE : MALE;
            PlaySE(SE_SELECT);
            UpdateGenderSelectionSprites(taskId);
        }

        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gTasks[taskId].tSelectedGender;
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].tState = 4;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            DestroySprite(&gSprites[gTasks[taskId].tMaleSpriteId]);
            DestroySprite(&gSprites[gTasks[taskId].tFemaleSpriteId]);
            DestroySprite(&gSprites[gTasks[taskId].tMaleOwSpriteId]);
            DestroySprite(&gSprites[gTasks[taskId].tFemaleOwSpriteId]);
            ResetAllPicSprites();
            NewGameBirchSpeech_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
            DestroyTask(taskId);
            DoNamingScreen(
                NAMING_SCREEN_PLAYER,
                gSaveBlock2Ptr->playerName,
                gSaveBlock2Ptr->playerGender,
                0,
                0,
                FALSE,
                CB2_NewGame
            );
        }
        break;
    }
}

static void UpdateGenderSelectionSprites(u8 taskId)
{
    u8 maleSpriteId = gTasks[taskId].tMaleSpriteId;
    u8 femaleSpriteId = gTasks[taskId].tFemaleSpriteId;

    if (gTasks[taskId].tSelectedGender == MALE)
    {
        gSprites[maleSpriteId].y = 56;
        gSprites[femaleSpriteId].y = 72;
    }
    else
    {
        gSprites[maleSpriteId].y = 72;
        gSprites[femaleSpriteId].y = 56;
    }
}

static void PrintNewGameFlowText(void)
{
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(0, FONT_NORMAL, gStringVar4, GetPlayerTextSpeedDelay(), NULL, TEXT_COLOR_WHITE, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY);
}

static void PrepareNewGameFlowTextWindow(void)
{
    NewGameBirchSpeech_ShowDialogueWindow(0, 1);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    CopyWindowToVram(0, COPYWIN_GFX);
}

#undef tState
#undef tSelectedGender
#undef tMaleSpriteId
#undef tFemaleSpriteId
#undef tSpritesCreated

#undef tTimer
