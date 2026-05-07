#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bug_contest.h"
#include "bg.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "region_map.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "load_save.h"
#include "malloc.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "union_room.h"
#include "dexnav.h"
#include "wild_encounter.h"
#include "rtc.h"
#include "constants/battle_frontier.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_RETIRE_BUG_CONTEST,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
    MENU_ACTION_DEBUG,
    MENU_ACTION_DEXNAV,
};

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

// IWRAM common
COMMON_DATA bool8 (*gMenuCallback)(void) = NULL;

// EWRAM
EWRAM_DATA static u8 sSafariBallsWindowId = 0;
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u8 sCurrentStartMenuActions[16] = {0};
EWRAM_DATA static s8 sInitStartMenuData[2] = {0};

#define START_MENU_COLUMNS 2
#define START_MENU_ROWS 3
#define START_MENU_VISIBLE_ITEMS (START_MENU_COLUMNS * START_MENU_ROWS)
#define START_MENU_PANEL_X 34
#define START_MENU_PANEL_Y 41
#define START_MENU_PANEL_H_SPACING 20
#define START_MENU_PANEL_V_SPACING 6
#define START_MENU_SCROLLBAR_X 235
#define START_MENU_SCROLLBAR_Y 48
#define START_MENU_SCROLLBAR_RANGE 62
#define START_MENU_EXIT_Y_OFFSET 4
#define START_MENU_EXIT_OPTION_Y_OFFSET 4
#define START_MENU_BG_TILE_SIZE 1312
#define START_MENU_BG_TILEMAP_SIZE 1280
#define START_MENU_SPRITE_NONE 0xFF

enum StartMenuBWWindowIds
{
    WIN_TOPBAR_TIME,
    WIN_TOPBAR,
    WIN_ITEMS,
    WIN_BOTTOMBAR,
    WIN_COUNT
};

struct StartMenuBWResources
{
    u8 cursorPos;
    u8 scrollOffset;
    u8 numItems;
    u8 numVisibleItems;
    u8 visibleActions[START_MENU_VISIBLE_ITEMS];
    u8 iconSpriteIds[START_MENU_VISIBLE_ITEMS];
    u16 *bgTilemapBuffer;
    bool8 returnToField;
    bool8 fadingOut;
    bool8 menuHidden;
    s8 lastSecond;
};

EWRAM_DATA static struct StartMenuBWResources *sStartMenuBW = NULL;
EWRAM_DATA bool8 gReturnToStartMenu = FALSE;
EWRAM_DATA static u8 sStartMenuScrollOffset = 0;
static bool8 sStartMenuExitToSave = FALSE;

#define STARTMENU_CURSOR_POS (sStartMenuBW->cursorPos)
#define STARTMENU_SCROLL_OFFSET (sStartMenuBW->scrollOffset)
#define STARTMENU_NUM_ITEMS (sStartMenuBW->numItems)
#define STARTMENU_NUM_VISIBLE (sStartMenuBW->numVisibleItems)
#define STARTMENU_VISIBLE_ACTIONS (sStartMenuBW->visibleActions)
EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuSafariZoneRetireCallback(void);
static bool8 StartMenuBugContestRetireCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 StartMenuDebugCallback(void);
static bool8 StartMenuDexNavCallback(void);

// Menu callbacks
static bool8 SaveCallback(void);
static bool8 BattlePyramidRetireStartCallback(void);
static bool8 BattlePyramidRetireReturnCallback(void);
static bool8 BattlePyramidRetireCallback(void);
static bool8 HandleStartMenuInput(void);

// Save dialog callbacks
static u8 SaveConfirmSaveCallback(void);
static u8 SaveYesNoCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveFileExistsCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveDoSaveCallback(void);
static u8 SaveSuccessCallback(void);
static u8 SaveReturnSuccessCallback(void);
static u8 SaveErrorCallback(void);
static u8 SaveReturnErrorCallback(void);
static u8 BattlePyramidConfirmRetireCallback(void);
static u8 BattlePyramidRetireYesNoCallback(void);
static u8 BattlePyramidRetireInputCallback(void);

// Task callbacks
static UNUSED void StartMenuTask(u8 taskId);
static void SaveGameTask(u8 taskId);
static void StartMenuBW_SaveGameTask(u8 taskId);
static void Task_WaitForFadeStartMenuSave(u8 taskId);
static void Task_SaveAfterLinkBattle(u8 taskId);
static void Task_WaitForBattleTowerLinkSave(u8 taskId);
static bool8 FieldCB_ReturnToFieldStartMenu(void);
static void ReturnToFieldFromStartMenuSave(void);

static void FieldCB_ReturnToFieldStartMenuSave(void);
static void StartMenuBW_StartSaveFromField(void);

static const struct WindowTemplate sWindowTemplate_SafariBalls = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 9,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};

static const struct WindowTemplate sWindowTemplate_PyramidFloor = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const struct WindowTemplate sWindowTemplate_PyramidPeak = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 12,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const u8 sText_MenuDebug[] = _("DEBUG");

static const struct MenuAction sStartMenuItems[] =
{
    [MENU_ACTION_POKEDEX]         = {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    [MENU_ACTION_POKEMON]         = {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    [MENU_ACTION_BAG]             = {gText_MenuBag,     {.u8_void = StartMenuBagCallback}},
    [MENU_ACTION_POKENAV]         = {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    [MENU_ACTION_PLAYER]          = {gText_MenuPlayer,  {.u8_void = StartMenuPlayerNameCallback}},
    [MENU_ACTION_SAVE]            = {gText_MenuSave,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_OPTION]          = {gText_MenuOption,  {.u8_void = StartMenuOptionCallback}},
    [MENU_ACTION_EXIT]            = {gText_MenuExit,    {.u8_void = StartMenuExitCallback}},
    [MENU_ACTION_RETIRE_SAFARI]   = {gText_MenuRetire,  {.u8_void = StartMenuSafariZoneRetireCallback}},
    [MENU_ACTION_RETIRE_BUG_CONTEST] = {gText_MenuRetire, {.u8_void = StartMenuBugContestRetireCallback}},
    [MENU_ACTION_PLAYER_LINK]     = {gText_MenuPlayer,  {.u8_void = StartMenuLinkModePlayerNameCallback}},
    [MENU_ACTION_REST_FRONTIER]   = {gText_MenuRest,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_RETIRE_FRONTIER] = {gText_MenuRetire,  {.u8_void = StartMenuBattlePyramidRetireCallback}},
    [MENU_ACTION_PYRAMID_BAG]     = {gText_MenuBag,     {.u8_void = StartMenuBattlePyramidBagCallback}},
    [MENU_ACTION_DEBUG]           = {sText_MenuDebug,   {.u8_void = StartMenuDebugCallback}},
    [MENU_ACTION_DEXNAV]          = {gText_MenuDexNav,  {.u8_void = StartMenuDexNavCallback}},
};

static const struct BgTemplate sBgTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSaveInfoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 8
};

enum StartMenuBWBgIds
{
    BG_START_MENU_TEXT,
    BG_START_MENU_BACKGROUND,
};

enum
{
    TAG_START_MENU_PANEL = 0x3000,
    TAG_START_MENU_EXIT,
    TAG_START_MENU_SCROLLBAR,
    TAG_START_MENU_POKEDEX,
    TAG_START_MENU_DEXNAV,
    TAG_START_MENU_POKEMON,
    TAG_START_MENU_BAG,
    TAG_START_MENU_POKENAV,
    TAG_START_MENU_PLAYER,
    TAG_START_MENU_SAVE,
    TAG_START_MENU_OPTIONS,
    TAG_START_MENU_EXIT_OPTION,
    TAG_START_MENU_RETIRE,
    TAG_START_MENU_DEBUG,
};

struct StartMenuBWIcon
{
    struct SpriteSheet sheet;
    struct SpritePalette palette;
    struct SpriteTemplate template;
};

enum StartMenuBWIconId
{
    START_MENU_ICON_POKEDEX,
    START_MENU_ICON_DEXNAV,
    START_MENU_ICON_POKEMON,
    START_MENU_ICON_BAG,
    START_MENU_ICON_POKENAV,
    START_MENU_ICON_PLAYER,
    START_MENU_ICON_SAVE,
    START_MENU_ICON_OPTIONS,
    START_MENU_ICON_EXIT_OPTION,
    START_MENU_ICON_RETIRE,
    START_MENU_ICON_DEBUG,
    START_MENU_ICON_COUNT,
};

static const u8 sStartMenuTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};

static const u8 *const sStartMenuDayNames[] =
{
    gText_StartMenu_Sun,
    gText_StartMenu_Mon,
    gText_StartMenu_Tue,
    gText_StartMenu_Wed,
    gText_StartMenu_Thu,
    gText_StartMenu_Fri,
    gText_StartMenu_Sat,
};

static const struct BgTemplate sStartMenuBWBgTemplates[] =
{
    {
        .bg = BG_START_MENU_TEXT,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = BG_START_MENU_BACKGROUND,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct WindowTemplate sStartMenuBWWindowTemplates[] =
{
    [WIN_TOPBAR_TIME] =
    {
        .bg = BG_START_MENU_TEXT,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 10,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 1,
    },
    [WIN_TOPBAR] =
    {
        .bg = BG_START_MENU_TEXT,
        .tilemapLeft = 10,
        .tilemapTop = 0,
        .width = 20,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 42,
    },
    [WIN_ITEMS] =
    {
        .bg = BG_START_MENU_TEXT,
        .tilemapLeft = 0,
        .tilemapTop = 4,
        .width = 30,
        .height = 12,
        .paletteNum = 14,
        .baseBlock = 123,
    },
    [WIN_BOTTOMBAR] =
    {
        .bg = BG_START_MENU_TEXT,
        .tilemapLeft = 0,
        .tilemapTop = 16,
        .width = 30,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 484,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u16 sStartMenuBWTextPal[] =
{
    RGB(8, 8, 8),     // Background (matches panel)
    RGB(31, 31, 31),  // White text
    RGB(0, 0, 0),
    RGB(25, 25, 24),  // Light gray text
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

static const struct SpriteSheet sStartMenuPanelSpriteSheet =
{
    .data = gStartMenuBWPanelTiles,
    .size = 0x2000,
    .tag = TAG_START_MENU_PANEL
};

static const struct SpritePalette sStartMenuPanelSpritePalette =
{
    .data = gStartMenuBWPanelPal,
    .tag = TAG_START_MENU_PANEL
};

static const struct SpriteSheet sStartMenuExitSpriteSheet =
{
    .data = gStartMenuBWExitTiles,
    .size = 0x100,
    .tag = TAG_START_MENU_EXIT
};

static const struct SpritePalette sStartMenuExitSpritePalette =
{
    .data = gStartMenuBWExitPal,
    .tag = TAG_START_MENU_EXIT
};

static const struct SpriteSheet sStartMenuScrollBarSpriteSheet =
{
    .data = gStartMenuBWScrollBarTiles,
    .size = 0x200,
    .tag = TAG_START_MENU_SCROLLBAR
};

static const struct SpritePalette sStartMenuScrollBarSpritePalette =
{
    .data = gStartMenuBWScrollBarPal,
    .tag = TAG_START_MENU_SCROLLBAR
};

static const struct OamData sStartMenuPanelOamData =
{
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const struct OamData sStartMenuIconOamData =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct OamData sStartMenuExitOamData =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 0
};

static const struct OamData sStartMenuScrollBarOamData =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const union AnimCmd sAnim_StartMenuPanelLeft_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StartMenuPanelLeft_1[] =
{
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sStartMenuPanelLeftAnims[] =
{
    sAnim_StartMenuPanelLeft_0,
    sAnim_StartMenuPanelLeft_1
};

static const union AnimCmd sAnim_StartMenuPanelRight_0[] =
{
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StartMenuPanelRight_1[] =
{
    ANIMCMD_FRAME(192, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sStartMenuPanelRightAnims[] =
{
    sAnim_StartMenuPanelRight_0,
    sAnim_StartMenuPanelRight_1
};

static const union AnimCmd sAnim_StartMenuIcon_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StartMenuIcon_1[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sStartMenuIconAnims[] =
{
    sAnim_StartMenuIcon_0,
    sAnim_StartMenuIcon_1
};

static const union AnimCmd sAnim_StartMenuExit[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sStartMenuExitAnims[] =
{
    sAnim_StartMenuExit
};

static const union AnimCmd sAnim_StartMenuScrollBar[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sStartMenuScrollBarAnims[] =
{
    sAnim_StartMenuScrollBar
};

static void PanelCallBack(struct Sprite *sprite);
static void StartMenuIconCallback(struct Sprite *sprite);
static void ScrollBarCallback(struct Sprite *sprite);

static const struct SpriteTemplate sStartMenuPanelSpriteTemplate1 =
{
    .tileTag = TAG_START_MENU_PANEL,
    .paletteTag = TAG_START_MENU_PANEL,
    .oam = &sStartMenuPanelOamData,
    .anims = sStartMenuPanelLeftAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = PanelCallBack,
};

static const struct SpriteTemplate sStartMenuPanelSpriteTemplate2 =
{
    .tileTag = TAG_START_MENU_PANEL,
    .paletteTag = TAG_START_MENU_PANEL,
    .oam = &sStartMenuPanelOamData,
    .anims = sStartMenuPanelRightAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = PanelCallBack,
};

static const struct SpriteTemplate sStartMenuExitSpriteTemplate =
{
    .tileTag = TAG_START_MENU_EXIT,
    .paletteTag = TAG_START_MENU_EXIT,
    .oam = &sStartMenuExitOamData,
    .anims = sStartMenuExitAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = PanelCallBack,
};

static const struct SpriteTemplate sStartMenuScrollBarSpriteTemplate =
{
    .tileTag = TAG_START_MENU_SCROLLBAR,
    .paletteTag = TAG_START_MENU_SCROLLBAR,
    .oam = &sStartMenuScrollBarOamData,
    .anims = sStartMenuScrollBarAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ScrollBarCallback,
};

#define START_MENU_ICON_ENTRY(tagId, tiles, pal) \
    { \
        .sheet = { .data = tiles, .size = 0x400, .tag = tagId }, \
        .palette = { .data = pal, .tag = tagId }, \
        .template = { .tileTag = tagId, .paletteTag = tagId, .oam = &sStartMenuIconOamData, .anims = sStartMenuIconAnims, .images = NULL, .affineAnims = gDummySpriteAffineAnimTable, .callback = StartMenuIconCallback } \
    }

static const struct StartMenuBWIcon sStartMenuBWIcons[] =
{
    [START_MENU_ICON_POKEDEX] = START_MENU_ICON_ENTRY(TAG_START_MENU_POKEDEX, gStartMenuBWPokedexTiles, gStartMenuBWPokedexPal),
    [START_MENU_ICON_DEXNAV] = START_MENU_ICON_ENTRY(TAG_START_MENU_DEXNAV, gStartMenuBWDexnavTiles, gStartMenuBWDexnavPal),
    [START_MENU_ICON_POKEMON] = START_MENU_ICON_ENTRY(TAG_START_MENU_POKEMON, gStartMenuBWPokemonTiles, gStartMenuBWPokemonPal),
    [START_MENU_ICON_BAG] = START_MENU_ICON_ENTRY(TAG_START_MENU_BAG, gStartMenuBWBagTiles, gStartMenuBWBagPal),
    [START_MENU_ICON_POKENAV] = START_MENU_ICON_ENTRY(TAG_START_MENU_POKENAV, gStartMenuBWPokenavTiles, gStartMenuBWPokenavPal),
    [START_MENU_ICON_PLAYER] = START_MENU_ICON_ENTRY(TAG_START_MENU_PLAYER, gStartMenuBWPlayerTiles, gStartMenuBWPlayerPal),
    [START_MENU_ICON_SAVE] = START_MENU_ICON_ENTRY(TAG_START_MENU_SAVE, gStartMenuBWSaveTiles, gStartMenuBWSavePal),
    [START_MENU_ICON_OPTIONS] = START_MENU_ICON_ENTRY(TAG_START_MENU_OPTIONS, gStartMenuBWOptionsTiles, gStartMenuBWOptionsPal),
    [START_MENU_ICON_EXIT_OPTION] = START_MENU_ICON_ENTRY(TAG_START_MENU_EXIT_OPTION, gStartMenuBWExitOptionTiles, gStartMenuBWExitOptionPal),
    [START_MENU_ICON_RETIRE] = START_MENU_ICON_ENTRY(TAG_START_MENU_RETIRE, gStartMenuBWRetireTiles, gStartMenuBWRetirePal),
    [START_MENU_ICON_DEBUG] = START_MENU_ICON_ENTRY(TAG_START_MENU_DEBUG, gStartMenuBWDebugTiles, gStartMenuBWDebugPal),
};

#undef START_MENU_ICON_ENTRY

static const u8 sStartMenuActionIcons[] =
{
    [MENU_ACTION_POKEDEX] = START_MENU_ICON_POKEDEX,
    [MENU_ACTION_POKEMON] = START_MENU_ICON_POKEMON,
    [MENU_ACTION_BAG] = START_MENU_ICON_BAG,
    [MENU_ACTION_POKENAV] = START_MENU_ICON_POKENAV,
    [MENU_ACTION_PLAYER] = START_MENU_ICON_PLAYER,
    [MENU_ACTION_SAVE] = START_MENU_ICON_SAVE,
    [MENU_ACTION_OPTION] = START_MENU_ICON_OPTIONS,
    [MENU_ACTION_EXIT] = START_MENU_ICON_EXIT_OPTION,
    [MENU_ACTION_RETIRE_SAFARI] = START_MENU_ICON_RETIRE,
    [MENU_ACTION_RETIRE_BUG_CONTEST] = START_MENU_ICON_RETIRE,
    [MENU_ACTION_PLAYER_LINK] = START_MENU_ICON_PLAYER,
    [MENU_ACTION_REST_FRONTIER] = START_MENU_ICON_SAVE,
    [MENU_ACTION_RETIRE_FRONTIER] = START_MENU_ICON_RETIRE,
    [MENU_ACTION_PYRAMID_BAG] = START_MENU_ICON_BAG,
    [MENU_ACTION_DEBUG] = START_MENU_ICON_DEBUG,
    [MENU_ACTION_DEXNAV] = START_MENU_ICON_DEXNAV,
};

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildDebugStartMenu(void);
static void BuildSafariZoneStartMenu(void);
static void BuildBugContestStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiPartnerRoomStartMenu(void);
static void ShowSafariBallsWindow(void);
static void ShowPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static bool32 InitStartMenuStep(void);
static void InitStartMenu(void);
static UNUSED void CreateStartMenuTask(TaskFunc followupFunc);
static void InitSave(void);
static u8 RunSaveCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void HideSaveMessageWindow(void);
static void HideSaveInfoWindow(void);
static void SaveStartTimer(void);
static bool8 SaveSuccesTimer(void);
static bool8 SaveErrorTimer(void);
static void InitBattlePyramidRetire(void);
static void VBlankCB_LinkBattleSave(void);
static bool32 InitSaveWindowAfterLinkBattle(u8 *par1);
static void CB2_SaveAfterLinkBattle(void);
static void ShowSaveInfoWindow(void);
static void RemoveSaveInfoWindow(void);
static void HideStartMenuWindow(void);
static void HideStartMenuDebug(void);
static bool8 StartMenuBW_WaitForFadeOut(void);
static bool8 StartMenuBW_ExitToSave(void);

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;

    if (IsOverworldLinkActive() == TRUE)
    {
        BuildLinkModeStartMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomStartMenu();
    }
    else if (GetSafariZoneFlag() == TRUE)
    {
        BuildSafariZoneStartMenu();
    }
    else if (GetBugContestFlag() == TRUE)
    {
        BuildBugContestStartMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeStartMenu();
    }
    else if (InBattlePyramid())
    {
        BuildBattlePyramidStartMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomStartMenu();
    }
    else
    {
        if (DEBUG_OVERWORLD_MENU == TRUE && DEBUG_OVERWORLD_IN_MENU == TRUE)
            BuildDebugStartMenu();
        else
            BuildNormalStartMenu();
    }
}

static void AddStartMenuAction(u8 action)
{
    if (sNumStartMenuActions >= ARRAY_COUNT(sCurrentStartMenuActions))
        return;

    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildNormalStartMenu(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);

    if (DN_FLAG_DEXNAV_GET != 0 && FlagGet(DN_FLAG_DEXNAV_GET))
        AddStartMenuAction(MENU_ACTION_DEXNAV);

    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildDebugStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_DEBUG);
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildSafariZoneStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBugContestStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_BUG_CONTEST);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiPartnerRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void StartMenuBW_ClearTasksAndGraphicalStructs(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetTempTileDataBuffers();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void StartMenuBW_ClearVramOamPlttRegs(void)
{
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void StartMenuBW_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void StartMenuBW_MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static u8 StartMenuBW_GetMaxScrollOffset(void)
{
    u8 rows = (sNumStartMenuActions + START_MENU_COLUMNS - 1) / START_MENU_COLUMNS;
    if (rows <= START_MENU_ROWS)
        return 0;
    return rows - START_MENU_ROWS;
}

static void StartMenuBW_BuildVisibleItems(void)
{
    u8 startIndex;
    u8 count = 0;
    u8 maxScroll = StartMenuBW_GetMaxScrollOffset();

    STARTMENU_NUM_ITEMS = sNumStartMenuActions;
    if (STARTMENU_SCROLL_OFFSET > maxScroll)
        STARTMENU_SCROLL_OFFSET = maxScroll;

    startIndex = STARTMENU_SCROLL_OFFSET * START_MENU_COLUMNS;
    for (u8 i = 0; i < START_MENU_VISIBLE_ITEMS; i++)
    {
        if (startIndex + i >= sNumStartMenuActions)
            break;
        STARTMENU_VISIBLE_ACTIONS[i] = sCurrentStartMenuActions[startIndex + i];
        count++;
    }
    STARTMENU_NUM_VISIBLE = count;
    if (STARTMENU_NUM_VISIBLE != 0 && STARTMENU_CURSOR_POS >= STARTMENU_NUM_VISIBLE)
        STARTMENU_CURSOR_POS = STARTMENU_NUM_VISIBLE - 1;
}

static void StartMenuBW_ClearWindow(u8 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
}

static void StartMenuBW_ClearWindows(void)
{
    for (u32 i = 0; i < WIN_COUNT; i++)
        StartMenuBW_ClearWindow(i);
}

static void StartMenuBW_CommitWindow(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void StartMenuBW_CommitWindows(void)
{
    for (u32 i = 0; i < WIN_COUNT; i++)
        StartMenuBW_CommitWindow(i);
}

static void PanelCallBack(struct Sprite *sprite)
{
    if (sprite->data[0] >= STARTMENU_NUM_VISIBLE && sprite->data[0] != START_MENU_SPRITE_NONE)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;

    if (sprite->data[0] == STARTMENU_CURSOR_POS)
        StartSpriteAnimIfDifferent(sprite, 1);
    else
        StartSpriteAnimIfDifferent(sprite, 0);
}

static void StartMenuIconCallback(struct Sprite *sprite)
{
    if (sprite->data[0] == STARTMENU_CURSOR_POS)
    {
        StartSpriteAnim(sprite, 1);
        if (sprite->data[4] % 5 == 0)
        {
            if (sprite->data[1] == 0)
                sprite->data[3] = 1;
            else if (sprite->data[1] == 3)
                sprite->data[3] = -1;
            sprite->data[1] += sprite->data[3];
            sprite->y = sprite->data[2] + sprite->data[1];
        }
        sprite->data[4]++;
    }
    else
    {
        sprite->y = sprite->data[2];
        StartSpriteAnim(sprite, 0);
    }
}

static void StartMenuBW_DrawPanels(void)
{
    u16 x;
    u16 y;
    u8 counter = 0;

    LoadSpriteSheet(&sStartMenuPanelSpriteSheet);
    LoadSpritePalette(&sStartMenuPanelSpritePalette);
    for (u8 row = 0; row < START_MENU_ROWS; row++)
    {
        for (u8 col = 0; col < START_MENU_COLUMNS; col++)
        {
            x = START_MENU_PANEL_X + (START_MENU_PANEL_H_SPACING + (64 / 2) + 62) * col;
            y = START_MENU_PANEL_Y + (START_MENU_PANEL_V_SPACING + 32) * row;
            u8 spriteId1 = CreateSprite(&sStartMenuPanelSpriteTemplate1, x, y, 0);
            u8 spriteId2 = CreateSprite(&sStartMenuPanelSpriteTemplate2, x + 64, y, 0);
            gSprites[spriteId1].data[0] = counter;
            gSprites[spriteId2].data[0] = counter;
            counter++;
        }
    }

    LoadSpriteSheet(&sStartMenuExitSpriteSheet);
    LoadSpritePalette(&sStartMenuExitSpritePalette);
    u8 spriteId = CreateSprite(&sStartMenuExitSpriteTemplate, 240 - 16, 160 - 11 + START_MENU_EXIT_Y_OFFSET, 0);
    gSprites[spriteId].data[0] = START_MENU_SPRITE_NONE;
}

static void StartMenuBW_DrawIcons(void)
{
    u16 x = 0;
    u16 y = 0;
    u8 counter = 0;

    for (u8 i = 0; i < START_MENU_VISIBLE_ITEMS; i++)
        sStartMenuBW->iconSpriteIds[i] = START_MENU_SPRITE_NONE;

    for (u8 row = 0; row < START_MENU_ROWS; row++)
    {
        if (counter >= STARTMENU_NUM_VISIBLE)
            break;
        for (u8 col = 0; col < START_MENU_COLUMNS; col++)
        {
            if (counter >= STARTMENU_NUM_VISIBLE)
                break;
            x = (START_MENU_PANEL_X - 11) + (START_MENU_PANEL_H_SPACING - 2 + (64 / 2) + 64) * col;
            y = (START_MENU_PANEL_Y - 3) + (START_MENU_PANEL_V_SPACING + 32) * row;
            u8 action = STARTMENU_VISIBLE_ACTIONS[counter];
            if (action >= ARRAY_COUNT(sStartMenuItems))
            {
                counter++;
                continue;
            }

            if (action >= ARRAY_COUNT(sStartMenuActionIcons))
            {
                counter++;
                continue;
            }

            u8 iconId = sStartMenuActionIcons[action];
            if (iconId >= START_MENU_ICON_COUNT)
            {
                counter++;
                continue;
            }

            if (iconId == START_MENU_ICON_EXIT_OPTION)
                y += START_MENU_EXIT_OPTION_Y_OFFSET;
            const struct StartMenuBWIcon *icon = &sStartMenuBWIcons[iconId];
            LoadSpriteSheet(&icon->sheet);
            LoadSpritePalette(&icon->palette);
            u8 spriteId = CreateSprite(&icon->template, x, y, 0);
            gSprites[spriteId].data[0] = counter;
            gSprites[spriteId].data[1] = 3;
            gSprites[spriteId].data[2] = y;
            gSprites[spriteId].data[3] = -1;
            gSprites[spriteId].data[4] = 0;
            sStartMenuBW->iconSpriteIds[counter] = spriteId;
            counter++;
        }
    }
}

static void StartMenuBW_PrintMapName(void)
{
    GetMapName(gStringVar4, GetCurrentRegionMapSectionId(), 0);
    AddTextPrinterParameterized4(WIN_BOTTOMBAR, FONT_NORMAL, 2, 13, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, gStringVar4);
}

static void StartMenuBW_PrintMenuItemsName(void)
{
    u16 x;
    u16 y;
    u8 counter = 0;

    for (u8 row = 0; row < START_MENU_ROWS; row++)
    {
        if (counter >= STARTMENU_NUM_VISIBLE)
            break;
        for (u8 col = 0; col < START_MENU_COLUMNS; col++)
        {
            if (counter >= STARTMENU_NUM_VISIBLE)
                break;
            x = (START_MENU_PANEL_X + (START_MENU_PANEL_H_SPACING + (64 / 2) + 64) * col) + 8;
            y = (START_MENU_PANEL_Y + (START_MENU_PANEL_V_SPACING + 32) * row) - 40;
            u8 action = STARTMENU_VISIBLE_ACTIONS[counter];
            if (action >= ARRAY_COUNT(sStartMenuItems))
            {
                counter++;
                continue;
            }
            if (action == MENU_ACTION_PLAYER || action == MENU_ACTION_PLAYER_LINK)
                AddTextPrinterParameterized4(WIN_ITEMS, FONT_NORMAL, x, y, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, gSaveBlock2Ptr->playerName);
            else
            {
                StringExpandPlaceholders(gStringVar4, sStartMenuItems[action].text);
                AddTextPrinterParameterized4(WIN_ITEMS, FONT_NORMAL, x, y, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, gStringVar4);
            }
            counter++;
        }
    }
}

static void StartMenuBW_CreateScrollbar(void)
{
    LoadSpriteSheet(&sStartMenuScrollBarSpriteSheet);
    LoadSpritePalette(&sStartMenuScrollBarSpritePalette);
    CreateSprite(&sStartMenuScrollBarSpriteTemplate, START_MENU_SCROLLBAR_X, START_MENU_SCROLLBAR_Y, 0);
}

static void ScrollBarCallback(struct Sprite *sprite)
{
    u8 maxScroll = StartMenuBW_GetMaxScrollOffset();
    if (maxScroll == 0)
    {
        sprite->invisible = TRUE;
        return;
    }

    sprite->invisible = FALSE;
    sprite->y = START_MENU_SCROLLBAR_Y + (START_MENU_SCROLLBAR_RANGE * STARTMENU_SCROLL_OFFSET) / maxScroll;
}

static void StartMenuBW_UpdateTimeText(void)
{
    const u8 *amPmString = (gLocalTime.hours >= 12) ? gText_StartMenu_PM : gText_StartMenu_AM;
    u8 displayHour = gLocalTime.hours % 12;

    if (displayHour == 0)
        displayHour = 12;

    ConvertIntToDecimalStringN(gStringVar1, displayHour, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringCopy(gStringVar3, sStartMenuDayNames[GetDayOfWeek()]);
    StringExpandPlaceholders(gStringVar4, gText_StartMenu_TimeBase_12Hr);

    AddTextPrinterParameterized4(WIN_TOPBAR_TIME, FONT_NORMAL, 3, 0, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, gStringVar4);
    AddTextPrinterParameterized4(WIN_TOPBAR_TIME, FONT_NORMAL, 63, 0, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, amPmString);
}

static void StartMenuBW_UpdateSafariZoneStats(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, SafariZoneGetStepCounter(), STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_StartMenu_SafariZoneStats);
    AddTextPrinterParameterized4(WIN_TOPBAR, FONT_NORMAL, 60, 0, 0, 0, sStartMenuTextColors, TEXT_SKIP_DRAW, gStringVar4);
}

static void StartMenuBW_LoadBgGfx(void)
{
    LoadBgTiles(BG_START_MENU_BACKGROUND, gStartMenuBWBgTiles, START_MENU_BG_TILE_SIZE, 0);
    memcpy(sStartMenuBW->bgTilemapBuffer, gStartMenuBWBgTilemap, START_MENU_BG_TILEMAP_SIZE);
    LoadPalette(gStartMenuBWBgPal, 0, 0x20);
    LoadPalette(sStartMenuBWTextPal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
}

static bool8 StartMenuBW_InitGui(void)
{
    ShowBg(BG_START_MENU_BACKGROUND);
    CopyBgTilemapBufferToVram(BG_START_MENU_BACKGROUND);
    StartMenuBW_ClearWindows();
    StartMenuBW_DrawPanels();
    StartMenuBW_DrawIcons();
    StartMenuBW_PrintMapName();
    StartMenuBW_PrintMenuItemsName();
    if (GetSafariZoneFlag())
        StartMenuBW_UpdateSafariZoneStats();
    StartMenuBW_UpdateTimeText();
    StartMenuBW_CreateScrollbar();
    StartMenuBW_CommitWindows();
    return TRUE;
}

static void StartMenuBW_RefreshMenuOptions(void)
{
    StartMenuBW_ClearWindow(WIN_ITEMS);
    for (u8 i = 0; i < STARTMENU_NUM_VISIBLE; i++)
    {
        if (sStartMenuBW->iconSpriteIds[i] != START_MENU_SPRITE_NONE)
            DestroySpriteAndFreeResources(&gSprites[sStartMenuBW->iconSpriteIds[i]]);
        sStartMenuBW->iconSpriteIds[i] = START_MENU_SPRITE_NONE;
    }
    StartMenuBW_BuildVisibleItems();
    StartMenuBW_DrawIcons();
    StartMenuBW_PrintMenuItemsName();
    StartMenuBW_CommitWindow(WIN_ITEMS);
}

static void StartMenuBW_Close(void)
{
    if (sStartMenuBW == NULL)
        return;

    sStartMenuCursorPos = STARTMENU_CURSOR_POS;
    sStartMenuScrollOffset = STARTMENU_SCROLL_OFFSET;

    FreeAllWindowBuffers();
    UnsetBgTilemapBuffer(BG_START_MENU_BACKGROUND);
    if (sStartMenuBW->bgTilemapBuffer != NULL)
        Free(sStartMenuBW->bgTilemapBuffer);
    ResetSpriteData();
    FreeAllSpritePalettes();
    Free(sStartMenuBW);
    sStartMenuBW = NULL;
}

static void ReturnToFieldFromStartMenu(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CB2_ReturnToField();
}

static void ReturnToFieldFromStartMenuSave(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    gFieldCallback = FieldCB_ReturnToFieldStartMenuSave;
    CB2_ReturnToField();
}

static void Task_WaitForFadeStartMenuSave(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        StartMenuBW_StartSaveFromField();
    }
}

static void FieldCB_ReturnToFieldStartMenuSave(void)
{
    FreezeObjectEvents();
    PlayerFreeze();
    StopPlayerAvatar();
    LockPlayerFieldControls();
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeStartMenuSave, 0x50);
}

static void StartMenuBW_StartSaveFromField(void)
{
    InitSave();
    CreateTask(StartMenuBW_SaveGameTask, 0x50);
}

static void StartMenuBW_RequestExit(void)
{
    if (sStartMenuBW == NULL)
        return;

    sStartMenuBW->returnToField = TRUE;
    if (!sStartMenuBW->fadingOut)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sStartMenuBW->fadingOut = TRUE;
    }
    gMenuCallback = StartMenuBW_WaitForFadeOut;
}

static bool8 StartMenuBW_ExitToSave(void)
{
    if (sStartMenuBW == NULL)
        return FALSE;

    sStartMenuExitToSave = TRUE;
    sStartMenuBW->returnToField = TRUE;
    return TRUE;
}

static bool8 StartMenuBW_WaitForFadeOut(void)
{
    if (!gPaletteFade.active)
        return TRUE;

    return FALSE;
}

static void Task_RunStartMenuCallback(u8 taskId)
{
    if (gMenuCallback != NULL && gMenuCallback() == TRUE)
    {
        if (sStartMenuBW != NULL && sStartMenuBW->returnToField)
        {
            StartMenuBW_Close();
            if (sStartMenuExitToSave)
            {
                sStartMenuExitToSave = FALSE;
                ReturnToFieldFromStartMenuSave();
            }
            else
            {
                ScriptUnfreezeObjectEvents();
                UnlockPlayerFieldControls();
                ReturnToFieldFromStartMenu();
            }
        }
        else
        {
            StartMenuBW_Close();
        }
        DestroyTask(taskId);
    }
}

static void CB2_StartMenuBW(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        StartMenuBW_ClearVramOamPlttRegs();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
        gMain.state++;
        break;
    case 1:
        StartMenuBW_ClearTasksAndGraphicalStructs();
        gMain.state++;
        break;
    case 2:
        sStartMenuBW->bgTilemapBuffer = Alloc(0x1000);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sStartMenuBWBgTemplates, ARRAY_COUNT(sStartMenuBWBgTemplates));
        SetBgTilemapBuffer(BG_START_MENU_BACKGROUND, sStartMenuBW->bgTilemapBuffer);
        gMain.state++;
        break;
    case 3:
        BuildStartMenuActions();
        StartMenuBW_BuildVisibleItems();
        StartMenuBW_LoadBgGfx();
        gMain.state++;
        break;
    case 4:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            ShowBg(BG_START_MENU_TEXT);
            ShowBg(BG_START_MENU_BACKGROUND);
            CopyBgTilemapBufferToVram(BG_START_MENU_BACKGROUND);
            gMain.state++;
        }
        break;
    case 5:
        InitWindows(sStartMenuBWWindowTemplates);
        DeactivateAllTextPrinters();
        StartMenuBW_InitGui();
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(StartMenuBW_VBlankCB);
        CreateTask(Task_RunStartMenuCallback, 0);
        SetMainCallback2(StartMenuBW_MainCB2);
        gMain.state = 0;
        break;
    }
}

static void StartMenuBW_Init(void)
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        ResetBgsAndClearDma3BusyFlags(0);
        CleanupOverworldWindowsAndTilemaps();
        sStartMenuBW = AllocZeroed(sizeof(*sStartMenuBW));
        if (sStartMenuBW == NULL)
            return;
        sStartMenuBW->cursorPos = sStartMenuCursorPos;
        sStartMenuBW->scrollOffset = sStartMenuScrollOffset;
        sStartMenuBW->returnToField = FALSE;
        sStartMenuBW->fadingOut = FALSE;
        sStartMenuBW->menuHidden = FALSE;
        gReturnToStartMenu = FALSE;
        sStartMenuBW->lastSecond = -1;
        gMenuCallback = HandleStartMenuInput;
        PlaySE(SE_PC_LOGIN);
        SetMainCallback2(CB2_StartMenuBW);
    }
}

static void ShowSafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&sWindowTemplate_SafariBalls);
    PutWindowTilemap(sSafariBallsWindowId);
    DrawStdWindowFrame(sSafariBallsWindowId, FALSE);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
}

static void ShowPyramidFloorWindow(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == FRONTIER_STAGES_PER_CHALLENGE)
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidPeak);
    else
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidFloor);

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramidFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    AddTextPrinterParameterized(sBattlePyramidFloorWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, COPYWIN_GFX);
}

static void RemoveExtraStartMenuWindows(void)
{
    // Legacy start menu windows are unused by the BW layout.
}

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;

    do
    {
        u8 action = sCurrentStartMenuActions[index];

        if (action >= ARRAY_COUNT(sStartMenuItems))
        {
            index++;
            if (index >= sNumStartMenuActions)
            {
                *pIndex = index;
                return TRUE;
            }

            count--;
            continue;
        }

        if (sStartMenuItems[action].func.u8_void == StartMenuPlayerNameCallback)
        {
            PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[action].text, 8, (index << 4) + 9);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, sStartMenuItems[action].text);
            AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, 8, (index << 4) + 9, TEXT_SKIP_DRAW, NULL);
        }

        index++;
        if (index >= sNumStartMenuActions)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static bool32 InitStartMenuStep(void)
{
    s8 state = sInitStartMenuData[0];

    switch (state)
    {
    case 0:
        sInitStartMenuData[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        sInitStartMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        DrawStdWindowFrame(AddStartMenuWindow(sNumStartMenuActions), FALSE);
        sInitStartMenuData[1] = 0;
        sInitStartMenuData[0]++;
        break;
    case 3:
        if (GetSafariZoneFlag())
            ShowSafariBallsWindow();
        if (InBattlePyramid())
            ShowPyramidFloorWindow();
        sInitStartMenuData[0]++;
        break;
    case 4:
        if (PrintStartMenuActions(&sInitStartMenuData[1], 2))
            sInitStartMenuData[0]++;
        break;
    case 5:
        sStartMenuCursorPos = InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, 0, 9, 16, sNumStartMenuActions, sStartMenuCursorPos);
        CopyWindowToVram(GetStartMenuWindowId(), COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void InitStartMenu(void)
{
    if (sStartMenuBW == NULL)
        return;

    BuildStartMenuActions();
    StartMenuBW_RefreshMenuOptions();
}

static UNUSED void StartMenuTask(u8 taskId)
{
    if (InitStartMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static UNUSED void CreateStartMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    taskId = CreateTask(StartMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, StartMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldStartMenu(void)
{
    ReturnToFieldOpenStartMenu();
    return TRUE;
}

void ShowReturnToFieldStartMenu(void)
{
    gFieldCallback2 = FieldCB_ReturnToFieldStartMenu;
}

void Task_ShowStartMenu(u8 taskId)
{
    if (InUnionRoom() == TRUE)
        SetUsingUnionRoomStartMenu();

    gMenuCallback = HandleStartMenuInput;
    StartMenuBW_Init();
    DestroyTask(taskId);
}

void ShowStartMenu(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
    StartMenuBW_Init();
    LockPlayerFieldControls();
}

static bool8 HandleStartMenuInput(void)
{
    if (sStartMenuBW == NULL)
        return FALSE;

    if (sStartMenuBW->lastSecond != gLocalTime.seconds)
    {
        sStartMenuBW->lastSecond = gLocalTime.seconds;
        StartMenuBW_ClearWindow(WIN_TOPBAR_TIME);
        StartMenuBW_UpdateTimeText();
        StartMenuBW_CommitWindow(WIN_TOPBAR_TIME);
    }

    if (gPaletteFade.active)
        return FALSE;

    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        StartMenuBW_RequestExit();
        return FALSE;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if ((STARTMENU_CURSOR_POS % START_MENU_COLUMNS) == 0
            && STARTMENU_CURSOR_POS + 1 < STARTMENU_NUM_VISIBLE)
        {
            PlaySE(SE_SELECT);
            STARTMENU_CURSOR_POS++;
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if ((STARTMENU_CURSOR_POS % START_MENU_COLUMNS) == 1)
        {
            PlaySE(SE_SELECT);
            STARTMENU_CURSOR_POS--;
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        u8 absoluteIndex = STARTMENU_SCROLL_OFFSET * START_MENU_COLUMNS + STARTMENU_CURSOR_POS;
        if (absoluteIndex >= START_MENU_COLUMNS)
        {
            u8 newAbsolute = absoluteIndex - START_MENU_COLUMNS;
            if (newAbsolute >= STARTMENU_SCROLL_OFFSET * START_MENU_COLUMNS)
            {
                PlaySE(SE_SELECT);
                STARTMENU_CURSOR_POS -= START_MENU_COLUMNS;
            }
            else if (STARTMENU_SCROLL_OFFSET > 0)
            {
                PlaySE(SE_SELECT);
                STARTMENU_SCROLL_OFFSET--;
                StartMenuBW_RefreshMenuOptions();
            }
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        u8 absoluteIndex = STARTMENU_SCROLL_OFFSET * START_MENU_COLUMNS + STARTMENU_CURSOR_POS;
        u8 newAbsolute = absoluteIndex + START_MENU_COLUMNS;
        if (newAbsolute < sNumStartMenuActions)
        {
            u8 visibleEnd = (STARTMENU_SCROLL_OFFSET + START_MENU_ROWS) * START_MENU_COLUMNS;
            if (newAbsolute < visibleEnd)
            {
                PlaySE(SE_SELECT);
                STARTMENU_CURSOR_POS += START_MENU_COLUMNS;
            }
            else
            {
                PlaySE(SE_SELECT);
                STARTMENU_SCROLL_OFFSET++;
                StartMenuBW_RefreshMenuOptions();
            }
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        u8 action = STARTMENU_VISIBLE_ACTIONS[STARTMENU_CURSOR_POS];
        if (action >= ARRAY_COUNT(sStartMenuItems))
            return FALSE;
        PlaySE(SE_SELECT);
        if (sStartMenuItems[action].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0 && !FlagGet(FLAG_SYS_POKEDEX_GET))
                return FALSE;
        }
        if (action == MENU_ACTION_DEXNAV && MapHasNoEncounterData())
            return FALSE;

        gMenuCallback = sStartMenuItems[action].func.u8_void;

        if (gMenuCallback != StartMenuSaveCallback
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuDebugCallback
            && gMenuCallback != StartMenuSafariZoneRetireCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback)
        {
            gReturnToStartMenu = TRUE;
            FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    return FALSE;
}
bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav);  // Display Pok??Nav

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void)
{
    if (InBattlePyramid())
        RemoveExtraStartMenuWindows();

    gMenuCallback = StartMenuBW_ExitToSave;

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        OptionMenu_SetNewGameSetup(FALSE);
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    StartMenuBW_RequestExit();

    return FALSE;
}

static bool8 StartMenuDebugCallback(void)
{
    HideStartMenuDebug(); // Hide start menu without enabling movement

    if (DEBUG_OVERWORLD_MENU)
    {
        FreezeObjectEvents();
        Debug_ShowMainMenu();
    }

    return TRUE;
}

static bool8 StartMenuSafariZoneRetireCallback(void)
{
    SafariZoneRetirePrompt();
    StartMenuBW_RequestExit();

    return FALSE;
}

static bool8 StartMenuBugContestRetireCallback(void)
{
    BugContestRetirePrompt();
    StartMenuBW_RequestExit();

    return FALSE;
}

static void HideStartMenuDebug(void)
{
    PlaySE(SE_SELECT);
    StartMenuBW_Close();
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        ShowTrainerCardInLink(gLocalLinkPlayerId, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = BattlePyramidRetireStartCallback; // Confirm retire

    return FALSE;
}

// Functionally unused
void ShowBattlePyramidStartMenu(void)
{
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    ScriptUnfreezeObjectEvents();
    StartMenuBW_Init();
    LockPlayerFieldControls();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}


static bool8 SaveCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR:    // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        SoftResetInBattlePyramid();
        StartMenuBW_RequestExit();
        return FALSE;
    }

    return FALSE;
}

static bool8 BattlePyramidRetireStartCallback(void)
{
    InitBattlePyramidRetire();
    gMenuCallback = BattlePyramidRetireCallback;

    return FALSE;
}

static bool8 BattlePyramidRetireReturnCallback(void)
{
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 BattlePyramidRetireCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_SUCCESS: // No (Stay in battle pyramid)
        gMenuCallback = BattlePyramidRetireReturnCallback;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Yes (Retire from battle pyramid)
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptContext_SetupScript(BattlePyramid_Retire);
        StartMenuBW_RequestExit();
        return FALSE;
    }

    return FALSE;
}

static void InitSave(void)
{
    SaveMapView();
    sSaveDialogCallback = SaveConfirmSaveCallback;
    sSavingComplete = FALSE;
}

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void SaveGame(void)
{
    InitSave();
    CreateTask(SaveGameTask, 0x50);
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void))
{
    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }

    DestroyTask(taskId);
    ScriptContext_Enable();
}

static void StartMenuBW_SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    if (status == SAVE_IN_PROGRESS)
        return;

    ClearDialogWindowAndFrameToTransparent(0, TRUE);
    SoftResetInBattlePyramid();

    if (status == SAVE_CANCELED)
    {
        ShowStartMenu();
    }
    else
    {
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
    }

    DestroyTask(taskId);
}

static void HideSaveMessageWindow(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
}

static void HideSaveInfoWindow(void)
{
    RemoveSaveInfoWindow();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;

    if (JOY_HELD(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveConfirmSaveCallback(void)
{
    ShowSaveInfoWindow();

    if (InBattlePyramid())
    {
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_ConfirmSave, SaveYesNoCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_AlreadySavedFile, SaveConfirmOverwriteCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void)
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static void InitBattlePyramidRetire(void)
{
    sSaveDialogCallback = BattlePyramidConfirmRetireCallback;
    sSavingComplete = FALSE;
}

static u8 BattlePyramidConfirmRetireCallback(void)
{
    ShowSaveMessage(gText_BattlePyramidConfirmRetire, BattlePyramidRetireYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireYesNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = BattlePyramidRetireInputCallback;

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveMessageWindow();
        return SAVE_SUCCESS;
    }

    return SAVE_IN_PROGRESS;
}

static void VBlankCB_LinkBattleSave(void)
{
    TransferPlttBuffer();
}

static bool32 InitSaveWindowAfterLinkBattle(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates_LinkBattleSave, ARRAY_COUNT(sBgTemplates_LinkBattleSave));
        InitWindows(sWindowTemplates_LinkBattleSave);
        LoadUserWindowBorderGfx_(0, 8, BG_PLTT_ID(14));
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetVBlankCallback(VBlankCB_LinkBattleSave);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*state)++;
    return FALSE;
}

void CB2_SetUpSaveAfterLinkBattle(void)
{
    if (InitSaveWindowAfterLinkBattle(&gMain.state))
    {
        CreateTask(Task_SaveAfterLinkBattle, 0x50);
        SetMainCallback2(CB2_SaveAfterLinkBattle);
    }
}

static void CB2_SaveAfterLinkBattle(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_SaveAfterLinkBattle(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0,
                                        FONT_NORMAL,
                                        gText_SavingDontTurnOffPower,
                                        TEXT_SKIP_DRAW,
                                        NULL,
                                        TEXT_COLOR_DARK_GRAY,
                                        TEXT_COLOR_WHITE,
                                        TEXT_COLOR_LIGHT_GRAY);
            DrawTextBorderOuter(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_FULL);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (Link_AnyPartnersPlayingFRLG_JP())
                {
                    *state = 1;
                }
                else
                {
                    *state = 5;
                }
            }
            else
            {
                gSoftResetDisabled = TRUE;
                *state = 1;
            }
            break;
        case 1:
            SetContinueGameWarpStatusToDynamicWarp();
            WriteSaveBlock2();
            *state = 2;
            break;
        case 2:
            if (WriteSaveBlock1Sector())
            {
                ClearContinueGameWarpStatus2();
                *state = 3;
                gSoftResetDisabled = FALSE;
            }
            break;
        case 3:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            *state = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(Task_LinkFullSave, 5);
            *state = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(Task_LinkFullSave))
            {
                *state = 3;
            }
            break;
        }
    }
}

static void ShowSaveInfoWindow(void)
{
    struct WindowTemplate saveInfoWindow = sSaveInfoWindowTemplate;
    u8 gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;

    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }

    sSaveInfoWindowId = AddWindow(&saveInfoWindow);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED;  // Red when female, blue when male.

    if (gender == MALE)
    {
        color = TEXT_COLOR_BLUE;
    }

    // Print region name
    yOffset = 1;
    BufferSaveMenuText(SAVE_MENU_LOCATION, gStringVar4, TEXT_COLOR_BLUE);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, 0, yOffset, TEXT_SKIP_DRAW, NULL);

    // Print player name
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPlayer, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_NAME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    PrintPlayerNameOnWindow(sSaveInfoWindowId, gStringVar4, xOffset, yOffset);

    // Print badge count
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingBadges, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        // Print Pok??dex count
        yOffset += 16;
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPokedex, 0, yOffset, TEXT_SKIP_DRAW, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);
    }

    // Print play time
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingTime, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(sSaveInfoWindowId, COPYWIN_GFX);
}

static void RemoveSaveInfoWindow(void)
{
    ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
    RemoveWindow(sSaveInfoWindowId);
}

static void Task_WaitForBattleTowerLinkSave(u8 taskId)
{
    if (!FuncIsActiveTask(Task_LinkFullSave))
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

#define tInBattleTower data[2]

void SaveForBattleTowerLink(void)
{
    u8 taskId = CreateTask(Task_LinkFullSave, 5);
    gTasks[taskId].tInBattleTower = TRUE;
    gTasks[CreateTask(Task_WaitForBattleTowerLinkSave, 6)].data[1] = taskId;
}

#undef tInBattleTower

static void HideStartMenuWindow(void)
{
    StartMenuBW_RequestExit();
}

void HideStartMenu(void)
{
    PlaySE(SE_SELECT);
    HideStartMenuWindow();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 StartMenuDexNavCallback(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
    return TRUE;
}

void Script_ForceSaveGame(struct ScriptContext *ctx)
{
    SaveGame();
    ShowSaveInfoWindow();
    gMenuCallback = SaveCallback;
    sSaveDialogCallback = SaveSavingMessageCallback;
}



































