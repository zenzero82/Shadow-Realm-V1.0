#include "global.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sound.h"
#include "gba/m4a_internal.h"
#include "sprite.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "string_util.h"

#define WINDOW_FRAMES_COUNT_FR WINDOW_FRAMES_COUNT
#define TEXT_SPEED_FF 0xFF

// Task data
enum
{
    TD_MENUSELECTION,
    TD_TEXTSPEED,
    TD_BATTLESCENE,
    TD_BATTLESTYLE,
    TD_SOUND,
    TD_BUTTONMODE,
    TD_FRAMETYPE,
	TD_TIMER,
    TD_PAGE,
    TD_SHINY_ODDS,
    TD_LEVEL_CAP,
    TD_PAGE_SELECTION_OPTIONS,
    TD_PAGE_SELECTION_FEATURES,
    TD_PAGE_SELECTION_DIFFICULTY,
};

// Menu items
enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_COUNT,
};

enum
{
    MENUITEM_FEATURES_SHINY_ODDS,
    MENUITEM_FEATURES_COUNT,
};

enum
{
    MENUITEM_DIFFICULTY_LEVEL_CAP,
    MENUITEM_DIFFICULTY_COUNT,
};

enum
{
    OPTION_MENU_PAGE_FEATURES,
    OPTION_MENU_PAGE_DIFFICULTY,
    OPTION_MENU_PAGE_OPTIONS,
    OPTION_MENU_PAGE_COUNT,
};

static const u8 sOptionMenuPagesDefault[] =
{
    OPTION_MENU_PAGE_OPTIONS,
};

static const u8 sOptionMenuPagesNewGame[] =
{
    OPTION_MENU_PAGE_FEATURES,
    OPTION_MENU_PAGE_DIFFICULTY,
};

// this file's functions
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuCancel(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static u8   TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8   BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection);
static u8   BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection);
static u8   Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection);
static u8   FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection);
static u8   ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection);
static u8   ShinyOdds_ProcessInput(u8 selection);
static void ShinyOdds_DrawChoices(u8 selection);
static u8   LevelCap_ProcessInput(u8 selection);
static void LevelCap_DrawChoices(u8 selection);
static void DrawOptionMenuTexts(u8 page, u8 selection);
static void OptionMenu_DrawChoicesForPage(u8 taskId);
static void DrawFrame(void);
static void OptionMenu_ClearWindow(u8 option);
static void ShowDescription(const u8 *text);
static void SetDescriptionForSelection(u8 page, u8 selection);
static const u8 *OptionMenu_GetLevelCapDescription(u8 selection);
static const u8 *OptionMenu_GetPageList(u8 *count);
static u8 OptionMenu_GetPageCount(void);
static u8 OptionMenu_GetPageIndex(u8 page);
static u8 OptionMenu_GetInitialPage(void);
static u8 OptionMenu_GetItemCount(u8 page);
static const u8 *OptionMenu_GetItemName(u8 page, u8 index);
static const u8 *OptionMenu_GetDescription(u8 page, u8 index);
static const u8 *OptionMenu_GetPageTitle(u8 page);
static void OptionMenu_LoadCursorMap(u8 selection);
static void OptionMenu_HideNewGameButtons(void);
static void OptionMenu_ChangePage(u8 taskId, s8 direction);
static u8 OptionMenu_ClampShinyOdds(u8 value);
static u8 OptionMenu_ClampLevelCap(u8 value);

// EWRAM vars
EWRAM_DATA static bool8 sArrowPressed = FALSE;
EWRAM_DATA static bool8 sOptionMenuNewGameSetup = FALSE;
EWRAM_DATA static u8 sOptionMenuLevelCapSelection;

// const rom data
const u16 gPalOptionMenu[] = INCBIN_U16("graphics/option_menu/option_menu_text.gbapal");
const u32 gTilesOptionMenu[] = INCBIN_U32("graphics/option_menu/option_menu_tiles.4bpp.lz");
const u32 gMapOptionMenu0[] = INCBIN_U32("graphics/option_menu/option_menu_0.bin.lz");
const u32 gMapOptionMenu1[] = INCBIN_U32("graphics/option_menu/option_menu_1.bin.lz");
const u32 gMapOptionMenu2[] = INCBIN_U32("graphics/option_menu/option_menu_2.bin.lz");
const u32 gMapOptionMenu3[] = INCBIN_U32("graphics/option_menu/option_menu_3.bin.lz");
const u32 gMapOptionMenu4[] = INCBIN_U32("graphics/option_menu/option_menu_4.bin.lz");
const u32 gMapOptionMenu5[] = INCBIN_U32("graphics/option_menu/option_menu_5.bin.lz");
const u8 localText_Option[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}OPTIONS");
const u8 localText_Features[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}FEATURES");
const u8 localText_Difficulty[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}DIFFICULTY");
const u8 localText_InstructionsSave[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}SAVE");
const u8 localText_InstructionsCancel[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}CANCEL");
const u8 localText_InstructionsSaveNewGame[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}{A_BUTTON}SAVE");
const u8 localText_InstructionsPrev[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}L:PREV");
const u8 localText_InstructionsNext[] = _("{COLOR 2}{HIGHLIGHT TRANSPARENT}R:NEXT");
const u8 localText_TextSpeed[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Text Speed");
const u8 localText_BattleScene[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}BATTLE SCENE");
const u8 localText_BattleStyle[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}BATTLE STYLE");
const u8 localText_Sound[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}SOUND");
const u8 localText_Frame[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}FRAME");
const u8 localText_ButtonMode[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}CONTROLS");
const u8 localText_ShinyOdds[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}SHINY ODDS");
const u8 localText_LevelCap[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}LEVEL CAP");
const u8 localText_TextSpeedSlow[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}SLOW");
const u8 localText_TextSpeedMid[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}MID");
const u8 localText_TextSpeedFast[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}FAST");
const u8 localText_BattleSceneOn[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}ON");
const u8 localText_BattleSceneOff[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}OFF");
const u8 localText_BattleStyleShift[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}SHIFT");
const u8 localText_BattleStyleSet[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}SET");
const u8 localText_SoundMono[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}MONO");
const u8 localText_SoundStereo[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}STEREO");
const u8 localText_FrameType[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}TYPE");
const u8 localText_FrameTypeNumber[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}");
const u8 localText_ButtonTypeNormal[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}NORMAL");
const u8 localText_ButtonTypeLR[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}LR");
const u8 localText_ButtonTypeLEqualsA[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}L=A");
const u8 localText_ShinyOdds8192[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}8192");
const u8 localText_ShinyOdds4096[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}4096");
const u8 localText_ShinyOdds2048[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}2048");
const u8 localText_ShinyOdds1024[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}1024");
const u8 localText_ShinyOdds512[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}512");
const u8 localText_LevelCapOff[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}OFF");
const u8 localText_LevelCapNormal[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}NORMAL");
const u8 localText_LevelCapHard[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}HARD");
const u8 localText_TextSpeedDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Choose from three text speed levels.");
const u8 localText_BattleSceneDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Show or disable animations\nduring battles.");
const u8 localText_BattleStyleDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Configure the rules that apply in\ncombat.");
const u8 localText_SoundDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Set the sound to mono or stereo. ");
const u8 localText_FrameDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Configure menu borders.");
const u8 localText_ButtonModeDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Configures the behavior of the\nL and R buttons.");
const u8 localText_ShinyOddsDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Choose the shiny encounter rate.");
const u8 localText_LevelCapOffDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Off: Overleveling is allowed.");
const u8 localText_LevelCapNormalDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Normal: Level Cap per Badge.");
const u8 localText_LevelCapHardDescription[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Hard: Level Cap per previous Badge.\n(You will be underleveled)");
const u8 localText_ExitWithSave[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Saving the changes made...");
const u8 localText_ExitWithoutSave[] = _("{COLOR 1}{HIGHLIGHT TRANSPARENT}Discarding the changes made...");

static const u8 sOptionMenuDescriptionTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_LIGHT_GRAY,
};


static const u8 *const sOptionMenuItemsNamesOptions[MENUITEM_COUNT] =
{
    localText_TextSpeed,
    localText_BattleScene,
    localText_BattleStyle,
    localText_Sound,
    localText_ButtonMode,
    localText_Frame,
};

static const u8 *const sOptionMenuItemsNamesFeatures[MENUITEM_FEATURES_COUNT] =
{
    localText_ShinyOdds,
};

static const u8 *const sOptionMenuItemsNamesDifficulty[MENUITEM_DIFFICULTY_COUNT] =
{
    localText_LevelCap,
};

static const u8 *const sOptionMenuDescriptionsOptions[MENUITEM_COUNT] =
{
    localText_TextSpeedDescription,
    localText_BattleSceneDescription,
    localText_BattleStyleDescription,
    localText_SoundDescription,
    localText_ButtonModeDescription,
    localText_FrameDescription,
};

static const u8 *const sOptionMenuDescriptionsFeatures[MENUITEM_FEATURES_COUNT] =
{
    localText_ShinyOddsDescription,
};

static const u8 *const sOptionMenuDescriptionsDifficulty[MENUITEM_DIFFICULTY_COUNT] =
{
    localText_LevelCapNormalDescription,
};

static const u32 *const sOptionMenuItems[MENUITEM_COUNT] =
{
    gMapOptionMenu0,
    gMapOptionMenu1,
    gMapOptionMenu2,
    gMapOptionMenu3,
    gMapOptionMenu4,
    gMapOptionMenu5,
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
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

static const struct BgTemplate sOptionMenuBgTemplates[] =
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

enum
{
	DESCRIPTION,
	FRAME,
};

// code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void OptionMenu_SetNewGameSetup(bool8 enable)
{
    sOptionMenuNewGameSetup = enable;
}

void CB2_InitOptionMenu(void)
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
		DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
		ResetBgsAndClearDma3BusyFlags(0);
		InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
		ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
    	InitWindows(sOptionMenuWinTemplates);
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
        OptionMenu_HideNewGameButtons();
        gMain.state++;
        break;
    case 7:
		LoadPalette(gPalOptionMenu, 0x50, 0xE0);
        gMain.state++;
        break;
    case 8:
        sOptionMenuLevelCapSelection = OptionMenu_ClampLevelCap(gSaveBlock2Ptr->optionsLevelCap);
		PutWindowTilemap(0);
		DrawOptionMenuTexts(OptionMenu_GetInitialPage(), 0);
        gMain.state++;
        break;
    case 9:
		PutWindowTilemap(1);
		DrawFrame();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);
        u8 initialPage = OptionMenu_GetInitialPage();

        gTasks[taskId].data[TD_PAGE] = initialPage;
        gTasks[taskId].data[TD_PAGE_SELECTION_OPTIONS] = 0;
        gTasks[taskId].data[TD_PAGE_SELECTION_FEATURES] = 0;
        gTasks[taskId].data[TD_PAGE_SELECTION_DIFFICULTY] = 0;
        switch (initialPage)
        {
        case OPTION_MENU_PAGE_FEATURES:
            gTasks[taskId].data[TD_MENUSELECTION] = gTasks[taskId].data[TD_PAGE_SELECTION_FEATURES];
            break;
        case OPTION_MENU_PAGE_DIFFICULTY:
            gTasks[taskId].data[TD_MENUSELECTION] = gTasks[taskId].data[TD_PAGE_SELECTION_DIFFICULTY];
            break;
        case OPTION_MENU_PAGE_OPTIONS:
        default:
            gTasks[taskId].data[TD_MENUSELECTION] = gTasks[taskId].data[TD_PAGE_SELECTION_OPTIONS];
            break;
        }
        gTasks[taskId].data[TD_TEXTSPEED] = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].data[TD_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].data[TD_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].data[TD_SOUND] = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].data[TD_BUTTONMODE] = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].data[TD_FRAMETYPE] = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].data[TD_SHINY_ODDS] = OptionMenu_ClampShinyOdds(gSaveBlock2Ptr->optionsShinyOdds);
        gTasks[taskId].data[TD_LEVEL_CAP] = OptionMenu_ClampLevelCap(gSaveBlock2Ptr->optionsLevelCap);
        sOptionMenuLevelCapSelection = gTasks[taskId].data[TD_LEVEL_CAP];
        gSaveBlock2Ptr->optionsShinyOdds = gTasks[taskId].data[TD_SHINY_ODDS];
        gSaveBlock2Ptr->optionsLevelCap = gTasks[taskId].data[TD_LEVEL_CAP];

        OptionMenu_DrawChoicesForPage(taskId);
        
		CopyWindowToVram(0, 3);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
		return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    u8 page = gTasks[taskId].data[TD_PAGE];
    u8 itemCount = OptionMenu_GetItemCount(page);

    if ((gMain.newKeys & L_BUTTON) && OptionMenu_GetPageCount() > 1)
    {
        OptionMenu_ChangePage(taskId, -1);
        return;
    }
    else if ((gMain.newKeys & R_BUTTON) && OptionMenu_GetPageCount() > 1)
    {
        OptionMenu_ChangePage(taskId, 1);
        return;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
		OptionMenu_ClearWindow(DESCRIPTION);
        gTasks[taskId].data[TD_TIMER] = 20;
		gTasks[taskId].func = Task_OptionMenuSave;
    }
	else if (gMain.newKeys & B_BUTTON)
    {
        if (sOptionMenuNewGameSetup)
            return;
		OptionMenu_ClearWindow(DESCRIPTION);
        gTasks[taskId].data[TD_TIMER] = 20;
		gTasks[taskId].func = Task_OptionMenuCancel;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gTasks[taskId].data[TD_MENUSELECTION] > 0)
            gTasks[taskId].data[TD_MENUSELECTION]--;
        else
            gTasks[taskId].data[TD_MENUSELECTION] = itemCount - 1;
		OptionMenu_LoadCursorMap(gTasks[taskId].data[TD_MENUSELECTION]);
		OptionMenu_ClearWindow(DESCRIPTION);
		SetDescriptionForSelection(page, gTasks[taskId].data[TD_MENUSELECTION]);
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (gTasks[taskId].data[TD_MENUSELECTION] < itemCount - 1)
            gTasks[taskId].data[TD_MENUSELECTION]++;
        else
            gTasks[taskId].data[TD_MENUSELECTION] = 0;
		OptionMenu_LoadCursorMap(gTasks[taskId].data[TD_MENUSELECTION]);
		OptionMenu_ClearWindow(DESCRIPTION);
		SetDescriptionForSelection(page, gTasks[taskId].data[TD_MENUSELECTION]);
    }
    else
    {
        u8 previousOption;

        switch (page)
        {
        case OPTION_MENU_PAGE_OPTIONS:
            switch (gTasks[taskId].data[TD_MENUSELECTION])
            {
            case MENUITEM_TEXTSPEED:
                previousOption = gTasks[taskId].data[TD_TEXTSPEED];
                gTasks[taskId].data[TD_TEXTSPEED] = TextSpeed_ProcessInput(gTasks[taskId].data[TD_TEXTSPEED]);

                if (previousOption != gTasks[taskId].data[TD_TEXTSPEED])
                    TextSpeed_DrawChoices(gTasks[taskId].data[TD_TEXTSPEED]);
                break;
            case MENUITEM_BATTLESCENE:
                previousOption = gTasks[taskId].data[TD_BATTLESCENE];
                gTasks[taskId].data[TD_BATTLESCENE] = BattleScene_ProcessInput(gTasks[taskId].data[TD_BATTLESCENE]);

                if (previousOption != gTasks[taskId].data[TD_BATTLESCENE])
                    BattleScene_DrawChoices(gTasks[taskId].data[TD_BATTLESCENE]);
                break;
            case MENUITEM_BATTLESTYLE:
                previousOption = gTasks[taskId].data[TD_BATTLESTYLE];
                gTasks[taskId].data[TD_BATTLESTYLE] = BattleStyle_ProcessInput(gTasks[taskId].data[TD_BATTLESTYLE]);

                if (previousOption != gTasks[taskId].data[TD_BATTLESTYLE])
                    BattleStyle_DrawChoices(gTasks[taskId].data[TD_BATTLESTYLE]);
                break;
            case MENUITEM_SOUND:
                previousOption = gTasks[taskId].data[TD_SOUND];
                gTasks[taskId].data[TD_SOUND] = Sound_ProcessInput(gTasks[taskId].data[TD_SOUND]);

                if (previousOption != gTasks[taskId].data[TD_SOUND])
                    Sound_DrawChoices(gTasks[taskId].data[TD_SOUND]);
                break;
            case MENUITEM_BUTTONMODE:
                previousOption = gTasks[taskId].data[TD_BUTTONMODE];
                gTasks[taskId].data[TD_BUTTONMODE] = ButtonMode_ProcessInput(gTasks[taskId].data[TD_BUTTONMODE]);

                if (previousOption != gTasks[taskId].data[TD_BUTTONMODE])
                    ButtonMode_DrawChoices(gTasks[taskId].data[TD_BUTTONMODE]);
                break;
            case MENUITEM_FRAMETYPE:
                previousOption = gTasks[taskId].data[TD_FRAMETYPE];
                gTasks[taskId].data[TD_FRAMETYPE] = FrameType_ProcessInput(gTasks[taskId].data[TD_FRAMETYPE]);

                if (previousOption != gTasks[taskId].data[TD_FRAMETYPE])
                    FrameType_DrawChoices(gTasks[taskId].data[TD_FRAMETYPE]);
                break;
            default:
                return;
            }
            break;
        case OPTION_MENU_PAGE_FEATURES:
            previousOption = gTasks[taskId].data[TD_SHINY_ODDS];
            gTasks[taskId].data[TD_SHINY_ODDS] = ShinyOdds_ProcessInput(gTasks[taskId].data[TD_SHINY_ODDS]);

            if (previousOption != gTasks[taskId].data[TD_SHINY_ODDS])
                ShinyOdds_DrawChoices(gTasks[taskId].data[TD_SHINY_ODDS]);
            break;
        case OPTION_MENU_PAGE_DIFFICULTY:
            previousOption = gTasks[taskId].data[TD_LEVEL_CAP];
            gTasks[taskId].data[TD_LEVEL_CAP] = LevelCap_ProcessInput(gTasks[taskId].data[TD_LEVEL_CAP]);

            if (previousOption != gTasks[taskId].data[TD_LEVEL_CAP])
            {
                LevelCap_DrawChoices(gTasks[taskId].data[TD_LEVEL_CAP]);
                sOptionMenuLevelCapSelection = gTasks[taskId].data[TD_LEVEL_CAP];
                OptionMenu_ClearWindow(DESCRIPTION);
                SetDescriptionForSelection(page, gTasks[taskId].data[TD_MENUSELECTION]);
            }
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(0, 2);
        }
    }
}

static void OptionMenu_ClearWindow(u8 option)
{
	if (option == DESCRIPTION)
	{	
		FillWindowPixelRect(0, 0, 8, 120, 224, 32);
	}
	else //(option == FRAME)
	{	
		FillWindowPixelRect(0, 0, 142, 96, 16, 16);
	}
	CopyWindowToVram(0, 2);
}

static void Task_OptionMenuSave(u8 taskId)
{
	ShowDescription(localText_ExitWithSave);
	if (gTasks[taskId].data[TD_TIMER])
    {
        gTasks[taskId].data[TD_TIMER]--;
    }
    else
	{
		gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].data[TD_TEXTSPEED];
		gSaveBlock2Ptr->optionsBattleSceneOff = gTasks[taskId].data[TD_BATTLESCENE];
		gSaveBlock2Ptr->optionsBattleStyle = gTasks[taskId].data[TD_BATTLESTYLE];
		gSaveBlock2Ptr->optionsSound = gTasks[taskId].data[TD_SOUND];
		gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].data[TD_BUTTONMODE];
		gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].data[TD_FRAMETYPE];
		gSaveBlock2Ptr->optionsShinyOdds = gTasks[taskId].data[TD_SHINY_ODDS];
		gSaveBlock2Ptr->optionsLevelCap = gTasks[taskId].data[TD_LEVEL_CAP];

		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
		gTasks[taskId].func = Task_OptionMenuFadeOut;
	}
}

static void Task_OptionMenuCancel(u8 taskId)
{
	ShowDescription(localText_ExitWithoutSave);
	if (gTasks[taskId].data[TD_TIMER])
    {
        gTasks[taskId].data[TD_TIMER]--;
    }
    else
	{
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
		gTasks[taskId].func = Task_OptionMenuFadeOut;
	}
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        bool8 isNewGame = sOptionMenuNewGameSetup;

        DestroyTask(taskId);
        FreeAllWindowBuffers();
        if (isNewGame)
        {
            SetVBlankCallback(NULL);
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
        }
        sOptionMenuNewGameSetup = FALSE;
        SetMainCallback2(gMain.savedCallback);
    }
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[160];
    u16 i;

    for (i = 0; *text != EOS && i <= 160; i++)
        dst[i] = *(text++);
	
	dst[2] = style;
    dst[i] = EOS;
    AddTextPrinterParameterized(0, FONT_NORMAL, dst, x, y + 1, TEXT_SPEED_FF, NULL);
	CopyWindowToVram(0, 2);
}

static void SetDescriptionForSelection(u8 page, u8 selection)
{
	ShowDescription(OptionMenu_GetDescription(page, selection));
}

static void ShowDescription(const u8 *text)
{
	u8 dst[160];
    u16 i;

    for (i = 0; *text != EOS && i <= 160; i++)
        dst[i] = *(text++);
	
	dst[2] = TEXT_COLOR_WHITE;
    dst[i] = EOS;
	AddTextPrinterParameterized4(0, FONT_NORMAL, 12, 120, 0, 0, sOptionMenuDescriptionTextColors, 0, dst);
    CopyWindowToVram(0, 2);
}

static const u8 *OptionMenu_GetPageList(u8 *count)
{
    if (sOptionMenuNewGameSetup)
    {
        *count = ARRAY_COUNT(sOptionMenuPagesNewGame);
        return sOptionMenuPagesNewGame;
    }

    *count = ARRAY_COUNT(sOptionMenuPagesDefault);
    return sOptionMenuPagesDefault;
}

static u8 OptionMenu_GetPageCount(void)
{
    u8 count;

    OptionMenu_GetPageList(&count);
    return count;
}

static u8 OptionMenu_GetPageIndex(u8 page)
{
    u8 count;
    const u8 *pageList = OptionMenu_GetPageList(&count);
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (pageList[i] == page)
            return i;
    }

    return 0;
}

static u8 OptionMenu_GetInitialPage(void)
{
    u8 count;
    const u8 *pageList = OptionMenu_GetPageList(&count);

    if (count == 0)
        return OPTION_MENU_PAGE_OPTIONS;

    return pageList[0];
}

static u8 OptionMenu_GetItemCount(u8 page)
{
    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        return MENUITEM_COUNT;
    case OPTION_MENU_PAGE_FEATURES:
        return MENUITEM_FEATURES_COUNT;
    case OPTION_MENU_PAGE_DIFFICULTY:
        return MENUITEM_DIFFICULTY_COUNT;
    default:
        return 0;
    }
}

static const u8 *OptionMenu_GetItemName(u8 page, u8 index)
{
    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        if (index >= MENUITEM_COUNT)
            index = 0;
        return sOptionMenuItemsNamesOptions[index];
    case OPTION_MENU_PAGE_FEATURES:
        if (index >= MENUITEM_FEATURES_COUNT)
            index = 0;
        return sOptionMenuItemsNamesFeatures[index];
    case OPTION_MENU_PAGE_DIFFICULTY:
        if (index >= MENUITEM_DIFFICULTY_COUNT)
            index = 0;
        return sOptionMenuItemsNamesDifficulty[index];
    default:
        return localText_TextSpeed;
    }
}

static const u8 *OptionMenu_GetDescription(u8 page, u8 index)
{
    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        if (index >= MENUITEM_COUNT)
            index = 0;
        return sOptionMenuDescriptionsOptions[index];
    case OPTION_MENU_PAGE_FEATURES:
        if (index >= MENUITEM_FEATURES_COUNT)
            index = 0;
        return sOptionMenuDescriptionsFeatures[index];
    case OPTION_MENU_PAGE_DIFFICULTY:
        if (index == MENUITEM_DIFFICULTY_LEVEL_CAP)
            return OptionMenu_GetLevelCapDescription(sOptionMenuLevelCapSelection);
        if (index >= MENUITEM_DIFFICULTY_COUNT)
            index = 0;
        return sOptionMenuDescriptionsDifficulty[index];
    default:
        return localText_TextSpeedDescription;
    }
}

static const u8 *OptionMenu_GetLevelCapDescription(u8 selection)
{
    switch (selection)
    {
    case OPTIONS_LEVEL_CAP_OFF:
        return localText_LevelCapOffDescription;
    case OPTIONS_LEVEL_CAP_HARD:
        return localText_LevelCapHardDescription;
    case OPTIONS_LEVEL_CAP_NORMAL:
    default:
        return localText_LevelCapNormalDescription;
    }
}

static const u8 *OptionMenu_GetPageTitle(u8 page)
{
    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        return localText_Option;
    case OPTION_MENU_PAGE_FEATURES:
        return localText_Features;
    case OPTION_MENU_PAGE_DIFFICULTY:
        return localText_Difficulty;
    default:
        return localText_Option;
    }
}

static void OptionMenu_LoadCursorMap(u8 selection)
{
    if (selection >= MENUITEM_COUNT)
        selection = 0;
	LZ77UnCompVram(sOptionMenuItems[selection], (void *)(VRAM + 0x3800));
    OptionMenu_HideNewGameButtons();
}

static void OptionMenu_HideNewGameButtons(void)
{
    u16 *tilemap;
    u16 row0Fill;
    u16 row1Fill;
    const u8 cols[] = {16, 23};
    u8 i;

    if (!sOptionMenuNewGameSetup)
        return;

    tilemap = (u16 *)(VRAM + 0x3800);
    row0Fill = tilemap[0];
    row1Fill = tilemap[32];

    for (i = 0; i < ARRAY_COUNT(cols); i++)
    {
        tilemap[cols[i]] = row0Fill;
        tilemap[32 + cols[i]] = row1Fill;
    }

    DmaClear16(3, (void *)(VRAM + (0x20 * 0x11)), 0x20 * 4);
}

static void OptionMenu_ChangePage(u8 taskId, s8 direction)
{
    u8 page = gTasks[taskId].data[TD_PAGE];
    u8 selection = gTasks[taskId].data[TD_MENUSELECTION];
    u8 itemCount;

    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        gTasks[taskId].data[TD_PAGE_SELECTION_OPTIONS] = selection;
        break;
    case OPTION_MENU_PAGE_FEATURES:
        gTasks[taskId].data[TD_PAGE_SELECTION_FEATURES] = selection;
        break;
    case OPTION_MENU_PAGE_DIFFICULTY:
        gTasks[taskId].data[TD_PAGE_SELECTION_DIFFICULTY] = selection;
        break;
    }

    {
        u8 pageCount;
        u8 pageIndex;
        const u8 *pageList = OptionMenu_GetPageList(&pageCount);

        if (pageCount <= 1)
            return;

        pageIndex = OptionMenu_GetPageIndex(page);
        if (direction > 0)
            pageIndex = (pageIndex + 1) % pageCount;
        else
            pageIndex = (pageIndex + pageCount - 1) % pageCount;

        page = pageList[pageIndex];
    }

    gTasks[taskId].data[TD_PAGE] = page;

    switch (page)
    {
    case OPTION_MENU_PAGE_OPTIONS:
        selection = gTasks[taskId].data[TD_PAGE_SELECTION_OPTIONS];
        break;
    case OPTION_MENU_PAGE_FEATURES:
        selection = gTasks[taskId].data[TD_PAGE_SELECTION_FEATURES];
        break;
    case OPTION_MENU_PAGE_DIFFICULTY:
        selection = gTasks[taskId].data[TD_PAGE_SELECTION_DIFFICULTY];
        break;
    default:
        selection = 0;
        break;
    }

    itemCount = OptionMenu_GetItemCount(page);
    if (selection >= itemCount)
        selection = 0;

    gTasks[taskId].data[TD_MENUSELECTION] = selection;
    OptionMenu_LoadCursorMap(selection);
    DrawOptionMenuTexts(page, selection);
    OptionMenu_DrawChoicesForPage(taskId);
}

static u8 OptionMenu_ClampShinyOdds(u8 value)
{
    if (value >= OPTIONS_SHINY_ODDS_COUNT)
        return OPTIONS_SHINY_ODDS_8192;
    return value;
}

static u8 OptionMenu_ClampLevelCap(u8 value)
{
    if (value > OPTIONS_LEVEL_CAP_HARD)
        return OPTIONS_LEVEL_CAP_NORMAL;
    return value;
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < 2)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection)
{
    u8 styles[3];

    styles[0] = 5;
    styles[1] = 5;
    styles[2] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_TextSpeedSlow, 112, 16, styles[0]);
    DrawOptionMenuChoice(localText_TextSpeedMid,  148, 16, styles[1]);
    DrawOptionMenuChoice(localText_TextSpeedFast, 184, 16, styles[2]);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 5;
    styles[1] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_BattleSceneOn,  112, 32, styles[0]);
    DrawOptionMenuChoice(localText_BattleSceneOff, 162, 32, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 5;
    styles[1] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_BattleStyleShift, 112, 48, styles[0]);
    DrawOptionMenuChoice(localText_BattleStyleSet,   162, 48, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 5;
    styles[1] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_SoundMono,   112, 64, styles[0]);
    DrawOptionMenuChoice(localText_SoundStereo, 162, 64, styles[1]);
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < WINDOW_FRAMES_COUNT_FR - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0xE0, 0x20);
        sArrowPressed = TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT_FR - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0xE0, 0x20);
        sArrowPressed = TRUE;
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection)
{
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; localText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = localText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACE;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACER;
        i++;
    }

    text[i] = EOS;
	
	OptionMenu_ClearWindow(FRAME);
	DrawOptionMenuChoice(localText_FrameType, 112, 96, 1);
    DrawOptionMenuChoice(text, 142, 96, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection)
{
    u8 styles[3];

    styles[0] = 5;
    styles[1] = 5;
    styles[2] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_ButtonTypeNormal,   112, 80, styles[0]);
    DrawOptionMenuChoice(localText_ButtonTypeLR,       162, 80, styles[1]);
    DrawOptionMenuChoice(localText_ButtonTypeLEqualsA, 188, 80, styles[2]);
}

static u8 ShinyOdds_ProcessInput(u8 selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < OPTIONS_SHINY_ODDS_COUNT - 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = OPTIONS_SHINY_ODDS_COUNT - 1;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ShinyOdds_DrawChoices(u8 selection)
{
    u8 styles[OPTIONS_SHINY_ODDS_COUNT];
    u8 i;

    for (i = 0; i < OPTIONS_SHINY_ODDS_COUNT; i++)
        styles[i] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_ShinyOdds8192, 104, 16, styles[0]);
    DrawOptionMenuChoice(localText_ShinyOdds4096, 132, 16, styles[1]);
    DrawOptionMenuChoice(localText_ShinyOdds2048, 160, 16, styles[2]);
    DrawOptionMenuChoice(localText_ShinyOdds1024, 188, 16, styles[3]);
    DrawOptionMenuChoice(localText_ShinyOdds512,  216, 16, styles[4]);
}

static u8 LevelCap_ProcessInput(u8 selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < OPTIONS_LEVEL_CAP_HARD)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = OPTIONS_LEVEL_CAP_HARD;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void LevelCap_DrawChoices(u8 selection)
{
    u8 styles[3];

    styles[0] = 5;
    styles[1] = 5;
    styles[2] = 5;
    styles[selection] = 1;

    DrawOptionMenuChoice(localText_LevelCapOff,    112, 16, styles[0]);
    DrawOptionMenuChoice(localText_LevelCapNormal, 148, 16, styles[1]);
    DrawOptionMenuChoice(localText_LevelCapHard,   198, 16, styles[2]);
}

static void DrawOptionMenuTexts(u8 page, u8 selection)
{
    u8 i;
    u8 itemCount = OptionMenu_GetItemCount(page);
    u8 instructionsY = 0;
    u8 prevX = 8;
    u8 nextX = 76;
    u8 saveX = 140;
    const u8 *saveText = localText_InstructionsSave;

    if (sOptionMenuNewGameSetup)
    {
        prevX = 76;
        nextX = 140;
        saveX = 204;
        saveText = localText_InstructionsSaveNewGame;
    }

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
	AddTextPrinterParameterized(0, FONT_NORMAL, OptionMenu_GetPageTitle(page), 8, 1, TEXT_SPEED_FF, NULL);
    if (OptionMenu_GetPageCount() > 1)
    {
        AddTextPrinterParameterized(0, FONT_NORMAL, localText_InstructionsPrev, prevX, instructionsY, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, FONT_NORMAL, localText_InstructionsNext, nextX, instructionsY, TEXT_SPEED_FF, NULL);
    }
    if (sOptionMenuNewGameSetup)
    {
        AddTextPrinterParameterized(0, FONT_NORMAL, saveText, saveX, instructionsY, TEXT_SPEED_FF, NULL);
    }
    else
    {
	    AddTextPrinterParameterized(0, FONT_NORMAL, saveText, saveX, instructionsY , TEXT_SPEED_FF, NULL);
	    AddTextPrinterParameterized(0, FONT_NORMAL, localText_InstructionsCancel, 204, instructionsY , TEXT_SPEED_FF, NULL);
    }
	SetDescriptionForSelection(page, selection);
	for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized(0, FONT_NORMAL, OptionMenu_GetItemName(page, i), 8, (i * 16) + 17, TEXT_SPEED_FF, NULL);
    }
    CopyWindowToVram(0, 2);
}

static void OptionMenu_DrawChoicesForPage(u8 taskId)
{
    switch (gTasks[taskId].data[TD_PAGE])
    {
    case OPTION_MENU_PAGE_OPTIONS:
        TextSpeed_DrawChoices(gTasks[taskId].data[TD_TEXTSPEED]);
        BattleScene_DrawChoices(gTasks[taskId].data[TD_BATTLESCENE]);
        BattleStyle_DrawChoices(gTasks[taskId].data[TD_BATTLESTYLE]);
        Sound_DrawChoices(gTasks[taskId].data[TD_SOUND]);
        ButtonMode_DrawChoices(gTasks[taskId].data[TD_BUTTONMODE]);
        FrameType_DrawChoices(gTasks[taskId].data[TD_FRAMETYPE]);
        break;
    case OPTION_MENU_PAGE_FEATURES:
        ShinyOdds_DrawChoices(gTasks[taskId].data[TD_SHINY_ODDS]);
        break;
    case OPTION_MENU_PAGE_DIFFICULTY:
        LevelCap_DrawChoices(gTasks[taskId].data[TD_LEVEL_CAP]);
        break;
    }
}

static void DrawFrame(void)
{   //                     bg, tileNum,  x,    y,  width, height,  pal
    FillBgTilemapBufferRect(2,   0x1A2,  0,   14,      1,      1,   14);
    FillBgTilemapBufferRect(2, 	 0x1A3,  1,   14,     28,      1,   14);
    FillBgTilemapBufferRect(2,   0x1A4, 29,   14,      1,      1,   14);
    FillBgTilemapBufferRect(2,   0x1A5,  0,   15,      1,      4,   14);
    FillBgTilemapBufferRect(2,   0x1A6,  1,   15,     28,      4,   14);
    FillBgTilemapBufferRect(2,   0x1A7, 29,   15,      1,      4,   14);
    FillBgTilemapBufferRect(2,   0x1A8,  0,   19,      1,      1,   14);
    FillBgTilemapBufferRect(2,   0x1A9,  1,   19,     28,      1,   14);
    FillBgTilemapBufferRect(2,   0x1AA, 29,   19,      1,      1,   14);

    CopyBgTilemapBufferToVram(2);
}
