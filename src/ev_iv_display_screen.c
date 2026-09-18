#include "global.h"
#include "menu.h"
#include "task.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "strings.h"
#include "sound.h"
#include "event_data.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/moves.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "field_effect.h"
#include "text_window.h"
#include "overworld.h"
#include "field_weather.h"
#include "trainer_pokemon_sprites.h"
#include "link.h"
#include "pokemon.h"

#include "ev_iv_display_screen.h"

// LANGUAGE_SPANISH o 7 para usar los textos en español
// LANGUAGE_ENGLISH or 2 to use the english text
#define EV_IV_TEXT              LANGUAGE_ENGLISH

// Cambiar a TRUE si la potencia base de Poder Oculto es fija.
// Set TRUE if Hidden Power's Base Power is fixed
#define HIDDEN_POWER_STATIC     FALSE

// Cambie esto a la potencia base de Poder Oculto si está fijo en cualquier número que no sea 60.
// Change this to the base power of Hidden Power if it's fixed to any number other than 60.
#define HIDDEN_POWER_BASE_POWER 60

// TRUE = ACTIVADO,     FALSE = DESACTIVADO.    Activa o desactiva el salto de sprite
// TRUE = ON,           FALSE = OFF.            Activates or deactivates the sprite jump
#define SPRITE_JUMP             TRUE

// 1 = DE DERECHA A IZQUIERDA,  0 = EN EL CENTRO,       -1 = DE IZQUIERDA A DERECHA.
// 1 = FROM RIGHT TO LEFT,      0 = IN THE CENTER,      -1 = FROM LEFT TO RIGHT.
#define SPRITE_JUMP_DIRECTION   1

// 1 = A LA DERECHA,    0 = A LA IZQUIERDA.
// 1 = RIGHT,           0 = LEFT.
#define SPRITE_VIEW_DIRECTION   0

#define STAT_DECREASE -1
#define STAT_NEUTRAL 0
#define STAT_INCREASE 1

#define EV_IV_EDIT_COL_EV 0
#define EV_IV_EDIT_COL_IV 1
#define EV_IV_ROW_COUNT 6
#define EV_IV_MAX 252
#define IV_MAX 31
#define EV_IV_TOTAL_MAX 510


//coordenada x del sprite pokémon, se mide en tiles de 8 pixeles
//x coordinate of the pokémon sprite, measured in tiles of 8 pixels
#define PICMON_X    18

//coordenada y del sprite pokémon, se mide en tiles de 8 pixeles
//y coordinate of the pokémon sprite, measured in tiles of 8 pixels
#define PICMON_Y     5

// ------------------------------------------------------------------ 
//                           FIRE RED/ROJOFUEGO     EMERALD/ESMERALDA
// FLAG_SYS_POKEMON_GET      0x828                  0x860
// FLAG_SYS_POKEDEX_GET      0x829                  0x861
//
// [ESP] ------------------------------------------------------------ 
// Cambiar FLAG_SYS_POKEMON_GET por la flag que quieras usar.
// ejemplo: FLAG_EV_IV  0x200
//
//  [ENG] ------------------------------------------------------------ 
// Change FLAG_SYS_POKEMON_GET to the flag you want to use.
// example: FLAG_EV_IV  0x200

#define DIR_DOWN        0
#define DIR_UP          2
#define ALLOW_EGGS      1
#define DIR_DOWN_2      (DIR_DOWN | ALLOW_EGGS)
#define DIR_UP_2        (DIR_UP | ALLOW_EGGS)

struct EvIvDisplayScreen
{
    u8 state;
    u8 gfxStep;
    u8 callbackStep;
    bool8 return_summary_screen;

    u8 spriteTaskId;
    u8 cursorPos;
    u8 lastIdx;
    bool8 isBoxMon;
    bool8 editMode;
    bool8 editValueMode;
    u8 selectedRow;
    u8 selectedColumn;
    s8 editValueRepeatDirection;
    u8 editValueRepeatCount;

    u8 stats_ev[NUM_STATS];
    u8 stats_iv[NUM_STATS];
    u8 stats_bs[NUM_STATS];
    u16 totalStatsEV;
    u16 totalStatsIV;
    u16 totalStatsBS;

    struct Pokemon currentMon;

    union
    {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;

    MainCallback savedCallback;
    u16 tilemapBuffer[0x400];
};

static struct EvIvDisplayScreen *gEvIv;


static void Task_EvIvInit(u8);
static u8 EvIvLoadGfx(void);
static void EvIvVblankHandler(void);
static void Task_WaitForExit(u8);
static void UpdateCurrentMon(void);
static void UpdateCurrentStats(void);
static void Task_EvIvReturn(u8);
static void BufferMonData(struct Pokemon * mon);
static s16 SeekToNextMonInBox(struct BoxPokemon *boxMons, u8 curIndex, u8 maxIndex, u8 flags);
static s8 AdvanceMultiBattleMonIndex(s8 direction);
static void ShowSprite(struct Pokemon *mon);
static void EvIvPrintText(struct Pokemon *mon);
static void ShowPokemonPic2(u16 species, bool8 isShiny, u32 personality, bool8 isShadow, u8 x, u8 y);
static void Task_ScriptShowMonPic(u8 taskId);
static void HidePokemonPic2(u8 taskId);

static void PrintStat(u8 nature, u8 stat);
static void PrintStatCursor(void);
static u8 GetDigitsDec(u32 num);
static u8 GetDigitsHex(u32 num);
static u8 GetColorByNature(u8 nature, u8 statIndex);
static bool8 TryAdjustSelectedValue(s8 delta);
static s8 GetEditValueDeltaFromInput(void);
static void MoveSelectedRow(s8 delta);
static u8 GetSelectedStat(void);
static void SetSelectedStatData(u16 field, u8 value);

extern void SummaryScreen_ReturnFromEvIv(u8 cursorPos);
extern const u8 gFireRedMenuElements_Gfx[];

static const u32 gBgEvIvGfx[] = INCBIN_U32("graphics/ev_iv_screen/bgEvIv.4bpp.lz");
static const u32 gBgEvIvTilemap[] = INCBIN_U32("graphics/ev_iv_screen/bgEvIv.bin.lz");
static const u16 gBgEvIvPal[] = INCBIN_U16("graphics/ev_iv_screen/bgEvIv.gbapal");

enum
{
    WIN_POKEMON_NAME,
    WIN_STATS,
    WIN_BOTTOM_BOX,
    WIN_HIDDEN_POWER,
    WIN_TYPE,
    WIN_TOP_BOX
};


static const struct BgTemplate sBg_Templates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 22,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    }, {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 19,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    }
};

//window 0 = pokémon name
#define WINDOW0_WIDTH   29
#define WINDOW0_HEIGTH  2

//window 1 = stats
#define WINDOW1_WIDTH   16
#define WINDOW1_HEIGTH  11
#define WINDOW1_BASEBLOCK  (WINDOW0_WIDTH * WINDOW0_HEIGTH)

//window 2 = text in the bottom bar / texto en la barra inferior
#define WINDOW2_WIDTH   16
#define WINDOW2_HEIGTH  5
#define WINDOW2_BASEBLOCK WINDOW1_WIDTH * WINDOW1_HEIGTH + WINDOW1_BASEBLOCK

//windows 3 = text hidden power
#define WINDOW3_WIDTH   11
#define WINDOW3_HEIGTH  4
#define WINDOW3_BASEBLOCK (WINDOW2_WIDTH * WINDOW2_HEIGTH) + WINDOW2_BASEBLOCK

//window 4 = type hidden power
#define WINDOW4_WIDTH   5
#define WINDOW4_HEIGTH  2
#define WINDOW4_BASEBLOCK (WINDOW3_WIDTH * WINDOW3_HEIGTH) + WINDOW3_BASEBLOCK

//window 5 = POKéMON EV-IV          +SEL. (A)(B)EXIT
#define WINDOW5_WIDTH   0
#define WINDOW5_HEIGTH  0
#define WINDOW5_BASEBLOCK (WINDOW4_WIDTH * WINDOW4_HEIGTH) + WINDOW4_BASEBLOCK

static const struct WindowTemplate sWindows_templates[] =
{
    [WIN_POKEMON_NAME] = 
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = WINDOW0_WIDTH,
        .height = WINDOW0_HEIGTH,
        .paletteNum = 15,
        .baseBlock = 0x000
    },
    [WIN_STATS] = 
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 4,
        .width = WINDOW1_WIDTH,
        .height = WINDOW1_HEIGTH,
        .paletteNum = 15,
        .baseBlock = WINDOW1_BASEBLOCK
    },
    [WIN_BOTTOM_BOX] = 
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = WINDOW2_WIDTH,
        .height = WINDOW2_HEIGTH,
        .paletteNum = 15,
        .baseBlock = WINDOW2_BASEBLOCK
    },
    [WIN_HIDDEN_POWER] = 
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 15,
        .width = WINDOW3_WIDTH,
        .height = WINDOW3_HEIGTH,
        .paletteNum = 15,
        .baseBlock = WINDOW3_BASEBLOCK
    },
    [WIN_TYPE] = 
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 17,
        .width = WINDOW4_WIDTH,
        .height = WINDOW4_HEIGTH,
        .paletteNum = 14,
        .baseBlock = WINDOW4_BASEBLOCK
    },
    [WIN_TOP_BOX] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = WINDOW5_WIDTH,
        .height = WINDOW5_HEIGTH,
        .paletteNum = 15,
        .baseBlock = WINDOW5_BASEBLOCK
    },
    DUMMY_WIN_TEMPLATE
};

struct MoveMenuInfoIcon
{
    u8 width;
    u8 height;
    u16 offset;
};

static const struct MoveMenuInfoIcon sMoveMenuInfoIcons[] =
{
    { 12, 12, 0x000 },       // Unused
    { 32, 12, 0x020 },       // Normal icon
    { 32, 12, 0x064 },       // Fight icon
    { 32, 12, 0x060 },       // Flying icon
    { 32, 12, 0x080 },       // Poison icon
    { 32, 12, 0x048 },       // Ground icon
    { 32, 12, 0x044 },       // Rock icon
    { 32, 12, 0x06C },       // Bug icon
    { 32, 12, 0x068 },       // Ghost icon
    { 32, 12, 0x088 },       // Steel icon
    { 32, 12, 0x0AC },       // ??? (Mystery) icon
    { 32, 12, 0x024 },       // Fire icon
    { 32, 12, 0x028 },       // Water icon
    { 32, 12, 0x02C },       // Grass icon
    { 32, 12, 0x040 },       // Electric icon
    { 32, 12, 0x084 },       // Psychic icon
    { 32, 12, 0x04C },       // Ice icon
    { 32, 12, 0x0A8 },       // Dragon icon
    { 32, 12, 0x08C },       // Dark icon
    { 32, 12, 0x0A4 },       // Fairy icon
    { 32, 12, 0x0AC },       // Stellar icon (fallback to ???)
    { 32, 12, 0x0A0 },       // Shadow icon
    { 40, 12, 0x0C5 },       // -Type- icon
    { 40, 12, 0x0CA },       // -Power- icon
    { 40, 12, 0x0E0 },       // -Accuracy- icon
    { 40, 12, 0x0E5 },       // -PP- icon
    { 40, 12, 0x0EC },       // -Effect- icon
    // Category icons
    { 32, 16, 0x004 },       // Physical icon
    { 32, 16, 0x008 },       // Special icon
    { 32, 16, 0x00C },       // Status icon
    // Category icons mini
    { 16, 16, 0x100 },       // Physical icon
    { 16, 16, 0x102 },       // Special icon
    { 16, 16, 0x104 },       // Status icon
};


//                                     fondo                    fuente                  sombra
//                                     highlight                font                    shadow
static const u8 sBlackTextColor[3]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,   TEXT_COLOR_LIGHT_GRAY};
static const u8 sBlueTextColor[3]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,        TEXT_COLOR_LIGHT_GRAY};
static const u8 sRedTextColor[3]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,         TEXT_COLOR_LIGHT_GRAY};
static const u8 sGrayTextColor[3]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_LIGHT_GRAY,  TEXT_COLOR_DARK_GRAY};
static const u8 sWhiteTextColor[3]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,       TEXT_COLOR_TRANSPARENT};

static const u8 *const sTextColorByNature[] = 
{
    [STAT_DECREASE + 1] = sBlueTextColor,
    [STAT_NEUTRAL + 1]  = sBlackTextColor,
    [STAT_INCREASE + 1] = sRedTextColor,
};

static void BlitMoveInfoIcon(u8 windowId, u8 iconId, u16 x, u16 y)
{
    if (iconId >= ARRAY_COUNT(sMoveMenuInfoIcons))
        iconId = TYPE_MYSTERY + 1;

    BlitBitmapRectToWindow(windowId,
                           gFireRedMenuElements_Gfx + sMoveMenuInfoIcons[iconId].offset * 32,
                           0, 0, 128, 128,
                           x, y,
                           sMoveMenuInfoIcons[iconId].width, sMoveMenuInfoIcons[iconId].height);
}

const u8 gText_eviv_Slash[] = _("/");
const u8 gText_CensorEgg[]  = _("{CLEAR_TO 12}?{CLEAR_TO 42}?{CLEAR_TO 66}?");

const u8 gText_BsEvIv[] = _("BS{CLEAR_TO 30}EV{CLEAR_TO 54}IV");

const u8 gText_eviv_Total[] = _("Total:");
const u8 gText_Percent[] = _("% ");
const u8 gText_eviv_Tittle[] = _("POKéMON EV-IV");

#if EV_IV_TEXT == LANGUAGE_SPANISH
const u8 gText_eviv_Buttons[] = _("{DPAD_UPDOWN}SEL. {B_BUTTON}SALIR");
const u8 gText_eviv_Edit[] = _("{A_BUTTON} EDITAR");
const u8 gText_eviv_Hp[]     = _(" ");
const u8 gText_eviv_Atk[]    = _(" ");
const u8 gText_eviv_Def[]    = _(" ");
const u8 gText_eviv_SpAtk[]  = _(" ");
const u8 gText_eviv_SpDef[]  = _(" ");
const u8 gText_eviv_Speed[]  = _(" ");

const u8 gText_Your[]   = _("Tu ");
const u8 gText_Is[]     = _(" es ");
const u8 gText_Happy[]  = _("Felicidad: ");
const u8 gText_HiddenPower[] = _("Poder oculto");
static const u8 sText_Power[]  = _("  Power: ");

const u8 gText_Steps_to_hatching[]  = _("Pasos para\neclosionar: ");

#elif EV_IV_TEXT == LANGUAGE_ENGLISH
const u8 gText_eviv_Buttons[] = _("{DPAD_UPDOWN}SEL. {B_BUTTON}EXIT");
const u8 gText_eviv_Edit[] = _("{A_BUTTON} EDIT");
const u8 gText_eviv_Hp[]     = _(" ");
const u8 gText_eviv_Atk[]    = _(" ");
const u8 gText_eviv_Def[]    = _(" ");
const u8 gText_eviv_SpAtk[]  = _(" ");
const u8 gText_eviv_SpDef[]  = _(" ");
const u8 gText_eviv_Speed[]  = _(" ");

const u8 gText_Your[]   = _("Your ");
const u8 gText_Is[]     = _(" is ");
const u8 gText_Happy[]  = _("Happiness: ");
const u8 gText_HiddenPower[] = _("Hidden power");
static const u8 sText_Power[]  = _("  Power: ");

const u8 gText_Steps_to_hatching[]  = _("Steps to\nhatch: ");
#endif


static void EvIvBgInit(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

static void CB2_EvIv(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

#define FREE_AND_SET_NULL_IF_SET(ptr) \
{                                     \
    if (ptr != NULL)                  \
    {                                 \
        Free(ptr);                    \
        (ptr) = NULL;                 \
    }                                 \
}

/**
 * 2022-03-03
 * ACIMUT:
 * Esta función configura el ev-iv summary screen por 
 * defecto, muestra nuestro equipo pokémon.
*/

void CB2_ShowEvIv_PlayerParty(void)
{
    u8 lastIdx;
    if (gPlayerPartyCount == 0)
        lastIdx = 0;
    else
        lastIdx = gPlayerPartyCount - 1;
    Show_EvIv(gPlayerParty, 0, lastIdx, CB2_ReturnToFieldFadeFromBlack, FALSE, FALSE);
}

void Show_EvIv(struct Pokemon * party, u8 cursorPos, u8 lastIdx, MainCallback savedCallback, bool8 isboxMon, bool8 return_summary_screen)
{
    gEvIv = AllocZeroed(sizeof(*gEvIv));

    if (gEvIv == NULL)
    {
        SetMainCallback2(savedCallback);
        return;
    }
    
    gEvIv->state = 0;
    gEvIv->gfxStep = 0;
    gEvIv->callbackStep = 0;
    
    gEvIv->monList.mons = party;
    gEvIv->cursorPos = cursorPos;
    gEvIv->lastIdx = lastIdx;
    gEvIv->savedCallback = savedCallback;
    gEvIv->isBoxMon = isboxMon;
    gEvIv->return_summary_screen = return_summary_screen;
    gEvIv->editMode = FALSE;
    gEvIv->editValueMode = FALSE;
    gEvIv->selectedRow = 0;
    gEvIv->selectedColumn = EV_IV_EDIT_COL_EV;
    gEvIv->editValueRepeatDirection = 0;
    gEvIv->editValueRepeatCount = 0;

    BufferMonData(&gEvIv->currentMon);

    EvIvBgInit();
    CreateTask(Task_EvIvInit, 80);
    SetMainCallback2(CB2_EvIv);
}

static void VCBC_EvIvOam(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_EvIvInit(u8 taskId)
{
    switch (gEvIv->callbackStep)
    {
    case 0:
        SetVBlankCallback(NULL);
        break;
    case 1:
        EvIvVblankHandler();
        break;
    case 2:
        if (!EvIvLoadGfx())
        {
            return;
        }
        break;
    case 3:
        CopyToBgTilemapBuffer(1, gBgEvIvTilemap, 0, 0);
        break;
    case 4:
    {
        u8 titleX = 0x10;
        u8 buttonsX = 0x98;
        u16 editX = buttonsX - GetStringWidth(2, gText_eviv_Edit, 0) - 4;

        FillWindowPixelBuffer(WIN_TOP_BOX, 0);
        AddTextPrinterParameterized3(WIN_TOP_BOX, 2, titleX, 2, sWhiteTextColor, 0, gText_eviv_Tittle);
        if (gSaveBlock2Ptr->optionsEvIvEditor == OPTIONS_EV_IV_EDITOR_ON)
            AddTextPrinterParameterized3(WIN_TOP_BOX, 2, editX, 2, sWhiteTextColor, 0, gText_eviv_Edit);
        AddTextPrinterParameterized3(WIN_TOP_BOX, 0, buttonsX, 1, sWhiteTextColor, 0, gText_eviv_Buttons);
        break;
    }
    case 5:
        PutWindowTilemap(WIN_TOP_BOX);
        ShowSprite(&gEvIv->currentMon);
        EvIvPrintText(&gEvIv->currentMon);
        break;
    case 6:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        break;
    case 8:
        SetVBlankCallback(VCBC_EvIvOam);
        break;
    default:
        if (gPaletteFade.active)
        {
            break;
        }
        gTasks[taskId].func = Task_WaitForExit;
    }
    gEvIv->callbackStep++;
}

static void Task_WaitForExit(u8 taskId)
{
    s8 monId = -1;
    bool8 update_mon = TRUE;

    switch (gEvIv->state)
    {
    case 0:
        gEvIv->state++;
        break;
    case 1:
        if (gEvIv->editMode)
        {
            bool8 redraw = FALSE;

            if (gEvIv->editValueMode)
            {
                s8 valueDelta = 0;

                if (JOY_REPEAT(DPAD_LEFT) || JOY_REPEAT(DPAD_RIGHT))
                {
                    gEvIv->selectedColumn ^= 1;
                    gEvIv->editValueRepeatDirection = 0;
                    gEvIv->editValueRepeatCount = 0;
                    redraw = TRUE;
                }

                valueDelta = GetEditValueDeltaFromInput();
                if (valueDelta != 0)
                    TryAdjustSelectedValue(valueDelta);

                if (JOY_NEW(B_BUTTON))
                {
                    gEvIv->editValueMode = FALSE;
                    gEvIv->editValueRepeatDirection = 0;
                    gEvIv->editValueRepeatCount = 0;
                    redraw = TRUE;
                }
            }
            else
            {
                if (JOY_REPEAT(DPAD_UP))
                {
                    MoveSelectedRow(-1);
                    redraw = TRUE;
                }
                else if (JOY_REPEAT(DPAD_DOWN))
                {
                    MoveSelectedRow(+1);
                    redraw = TRUE;
                }

                if (JOY_NEW(A_BUTTON))
                {
                    gEvIv->editValueMode = TRUE;
                    gEvIv->editValueRepeatDirection = 0;
                    gEvIv->editValueRepeatCount = 0;
                    redraw = TRUE;
                }
                else if (JOY_NEW(B_BUTTON))
                {
                    gEvIv->editMode = FALSE;
                    redraw = TRUE;
                }
            }

            if (redraw)
                EvIvPrintText(&gEvIv->currentMon);
            break;
        }
        if (gEvIv->lastIdx)
        {
            if (JOY_REPEAT(DPAD_DOWN))
            {
                if (gEvIv->isBoxMon)
                {
                    monId =  SeekToNextMonInBox(gEvIv->monList.boxMons, gEvIv->cursorPos, gEvIv->lastIdx, DIR_DOWN_2);
                    if (monId == -1)//si llega al final, revise el primer elemento.
                        monId = SeekToNextMonInBox(gEvIv->monList.boxMons, 1, gEvIv->lastIdx, DIR_UP_2);
                    if (monId == -1)//si el primer elemento no tiene boxmon, revise desde el segundo en adelante.
                        monId = SeekToNextMonInBox(gEvIv->monList.boxMons, 0, gEvIv->lastIdx, DIR_DOWN_2);
                    if (gEvIv->cursorPos == monId)
                        update_mon = FALSE;
                    else
                        gEvIv->cursorPos = monId;
                }
                else if (IsMultiBattle() == TRUE)
                {
                    gEvIv->cursorPos = AdvanceMultiBattleMonIndex(+1);
                }
                else
                {
                    if (gEvIv->cursorPos == gEvIv->lastIdx)
                        gEvIv->cursorPos = 0;
                    else
                        gEvIv->cursorPos++;
                }

                if (update_mon)
                    UpdateCurrentMon();
            }
            else if (JOY_REPEAT(DPAD_UP))
            {
                if (gEvIv->isBoxMon)
                {
                    monId =  SeekToNextMonInBox(gEvIv->monList.boxMons, gEvIv->cursorPos, gEvIv->lastIdx, DIR_UP_2);
                    if (monId == -1)//si llega al inicio, revise el último elemento.
                        monId = SeekToNextMonInBox(gEvIv->monList.boxMons, gEvIv->lastIdx -1, gEvIv->lastIdx, DIR_DOWN_2);
                    if (monId == -1)//si el último elemento no tiene boxMon, revise desde el penúltimo hacia atrás
                        monId = SeekToNextMonInBox(gEvIv->monList.boxMons, gEvIv->lastIdx, gEvIv->lastIdx, DIR_UP_2);
                    if (gEvIv->cursorPos == monId)
                        update_mon = FALSE;
                    else
                        gEvIv->cursorPos = monId;
                }
                else if (IsMultiBattle() == TRUE)
                {
                    gEvIv->cursorPos = AdvanceMultiBattleMonIndex(-1);
                }
                else
                {
                    if (gEvIv->cursorPos == 0)
                        gEvIv->cursorPos = gEvIv->lastIdx;
                    else
                        gEvIv->cursorPos--;
                }

                if (update_mon)
                    UpdateCurrentMon();
            }
        }

        if (JOY_NEW(A_BUTTON) && gSaveBlock2Ptr->optionsEvIvEditor == OPTIONS_EV_IV_EDITOR_ON)
        {
            if (!GetMonData(&gEvIv->currentMon, MON_DATA_IS_EGG, NULL))
            {
                gEvIv->editMode = TRUE;
                gEvIv->editValueMode = FALSE;
                gEvIv->selectedColumn = EV_IV_EDIT_COL_EV;
                EvIvPrintText(&gEvIv->currentMon);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_RG_CARD_FLIP);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gEvIv->state++;
        }
        break;
    case 2:
        if (!IsCryPlaying())
            Task_EvIvReturn(taskId);
        break;
    }
}

static void UpdateCurrentMon(void)
{
    BufferMonData(&gEvIv->currentMon);
    HidePokemonPic2(gEvIv->spriteTaskId);
    EvIvPrintText(&gEvIv->currentMon);
    ShowSprite(&gEvIv->currentMon);
}

static void UpdateCurrentStats(void)
{
    BufferMonData(&gEvIv->currentMon);
    EvIvPrintText(&gEvIv->currentMon);
}

static void Task_EvIvReturn(u8 taskId)
{
    bool8 return_summary_screen = gEvIv->return_summary_screen;

    if (gPaletteFade.active)
        return;

    HidePokemonPic2(gEvIv->spriteTaskId);
    FreeAllWindowBuffers();
    DestroyTask(taskId);
    
    if (return_summary_screen)
        SummaryScreen_ReturnFromEvIv(gEvIv->cursorPos);
    else
        SetMainCallback2(gEvIv->savedCallback);
    FREE_AND_SET_NULL_IF_SET(gEvIv);
}

static void BufferMonData(struct Pokemon * mon)
{
    if (!gEvIv->isBoxMon)
    {
        struct Pokemon * partyMons = gEvIv->monList.mons;
        *mon = partyMons[gEvIv->cursorPos];
    }
    else
    {
#if CFRU == FALSE
        struct BoxPokemon * boxMons = gEvIv->monList.boxMons;
        BoxMonToMon(&boxMons[gEvIv->cursorPos], mon);
#else //CFRU
        struct CompressedPokemon * compMon = gEvIv->monList.compMon;
        CompressedMonToMon(&compMon[gEvIv->cursorPos], mon);
#endif
    }
}

static s16 SeekToNextMonInBox(struct BoxPokemon *boxMons, u8 curIndex, u8 maxIndex, u8 flags)
{
    s8 dir = (flags == DIR_DOWN || flags == DIR_DOWN_2) ? 1 : -1;
    bool8 allowEggs = (flags & ALLOW_EGGS) != 0;
    s16 idx = curIndex;

    while (TRUE)
    {
        idx += dir;
        if (idx < 0 || idx > maxIndex)
            return -1;

        if (GetBoxMonData(&boxMons[idx], MON_DATA_SPECIES) == SPECIES_NONE)
            continue;
        if (!allowEggs && GetBoxMonData(&boxMons[idx], MON_DATA_IS_EGG))
            continue;

        return idx;
    }
}

//EMERALD: sMultiBattleOrder
static const u8 sMultiBattlePartyOrder[]    = {0, 2, 3, 1, 4, 5};

static bool8 IsValidToViewInMulti(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    //if (gEvIv->cursorPos != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    //return FALSE;
}

static s8 AdvanceMultiBattleMonIndex(s8 direction)
{
    struct Pokemon *mons = gEvIv->monList.mons;
    s8 index, foundPartyIdx = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattlePartyOrder[i] == gEvIv->cursorPos)
        {
            foundPartyIdx = i;
            break;
        }
    }

    while (TRUE)
    {
        foundPartyIdx += direction;
        if (foundPartyIdx < 0)
            foundPartyIdx = (PARTY_SIZE - 1);
        if (foundPartyIdx >= PARTY_SIZE)
            foundPartyIdx = 0;

        index = sMultiBattlePartyOrder[foundPartyIdx];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static void ResetBGPos(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static void ResetGpu(void)
{
    void *vram = (void *)VRAM;
    DmaClearLarge16(3, vram, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
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

static void EvIvVblankHandler(void)
{
    ResetGpu();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBg_Templates, 2);
    ResetBGPos();
    InitWindows(sWindows_templates);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetBgTilemapBuffer(1, gEvIv->tilemapBuffer);
    ShowBg(0);
    ShowBg(1);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
}

static u8 EvIvLoadGfx(void)
{
    switch (gEvIv->gfxStep)
    {
    case 0:
        ResetTempTileDataBuffers();
        break;
    case 1:
        DecompressAndCopyTileDataToVram(1, gBgEvIvGfx, 0, 0, 0);
        break;
    case 2:
        if (!(FreeTempTileDataBuffersIfPossible() == 1))
        {
            break;
        }
        return 0;
    case 3:
        LoadPalette(gBgEvIvPal, 0, 0x20);
        LoadPalette(GetTextWindowPalette(0), 0xf0, 0x20);
        ListMenuLoadStdPalAt(0xE0, 1);
        break;
    default:
        return 1;
    }
    gEvIv->gfxStep++;
    return 0;
}

static void ShowSprite(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 isEgg    = GetMonData(mon, MON_DATA_IS_EGG, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    bool8 isShiny = IsMonShiny(mon);
    bool8 isShadow = GetMonData(mon, MON_DATA_IS_SHADOW, NULL);

    //imprime el sprite del pokémon, si es un huevo no suena grito.
    //Print the sprite of the pokémon, if it is an egg it does not sound a scream.
    if (!isEgg)
    {
        if (ShouldIgnoreDeoxysForm(3, gEvIv->cursorPos))
            species = SPECIES_DEOXYS;
        ShowPokemonPic2(species, isShiny, personality, isShadow, PICMON_X, PICMON_Y);
        PlayCry_Normal(species, 0);
    }
    else
    {
        ShowPokemonPic2(SPECIES_EGG, FALSE, 0, FALSE, PICMON_X, PICMON_Y);
    }
}

#define tState               data[0]
#define tSpecie              data[1]
#define tSpriteId            data[2]
#define tTimer               data[3]

void HidePokemonPic2(u8 taskId)
{
    struct Task * task = &gTasks[taskId];
    task->tState = 2;
}

static u8 CreateMonSprite_Field(u16 species, bool8 isShiny, u32 personality, bool8 isShadow, s16 x, s16 y, u8 subpriority)
{
    (void)subpriority;
    u16 spriteId = CreateMonPicSprite_ShadowAware(species, isShiny, personality, TRUE, x, y, 0, TAG_NONE, isShadow);
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

static void ShowPokemonPic2(u16 species, bool8 isShiny, u32 personality, bool8 isShadow, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreateMonSprite_Field(species, isShiny, personality, isShadow, 8 * x + 40, 8 * y + 40, FALSE);
    gEvIv->spriteTaskId = CreateTask(Task_ScriptShowMonPic, 80);

    gSprites[spriteId].hFlip = SPRITE_VIEW_DIRECTION;

    //Ajusta el sprite del pokémon 2 píxeles a la izquierda
    //Adjust the pokémon sprite 2 pixels to the left
    gSprites[spriteId].x -= 2;

#if SPRITE_JUMP
    gSprites[spriteId].y -= 32;
    gSprites[spriteId].x += 48 * SPRITE_JUMP_DIRECTION;
#endif

    gTasks[gEvIv->spriteTaskId].tState = 0;
    gTasks[gEvIv->spriteTaskId].tSpecie = species;
    gTasks[gEvIv->spriteTaskId].tSpriteId = spriteId;
    gTasks[gEvIv->spriteTaskId].tTimer = 0;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 0;
}

static const s8 delta_jump[] =
{
    [ 0 ...  9] =  0, // < 10
    [10 ... 17] =  1, // < 18
    [18 ... 23] =  2, // < 24
    [24 ... 27] =  3, // < 28
    [28 ... 29] = -3, // < 30
    [30 ... 31] = -2, // < 32
    [32 ... 35] = -1, // < 36
    [36 ... 39] =  0, // < 40
    [40 ... 43] =  1, // < 44
    [44 ... 45] =  2, // < 46
    [46 ... 47] =  3, // < 48

};

static void Task_ScriptShowMonPic(u8 taskId)
{
    struct Task * task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tTimer = 0;
        task->tState++;
        break;
    case 1:

#if SPRITE_JUMP
        if (task->tTimer < 48)
        {
            gSprites[task->tSpriteId].y += delta_jump[task->tTimer];
            gSprites[task->tSpriteId].x -= SPRITE_JUMP_DIRECTION;
        }
        else
            task->tState = 4;

        task->tTimer++;
#endif

        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tSpriteId], task->tSpriteId);
        task->tState++;
        break;
    case 3:
        DestroyTask(taskId);
        break;
    }
}

#undef tState
#undef tSpecie
#undef tSpriteId
#undef tTimer

/*

+- - - - - - - - - - - +
|HP       160  255  16 |  HP_Y
|ATTACK   110   10  30 |  ATK_Y
|DEFENSE   65   20  31 |  DEF_Y
|SP.ATK.   65    1  20 |  SPATK_Y
|SP.DEF.  110   80  31 |  SPDEF_Y
|SPEED     30   11  13 |  SPEED_Y
+- - - - - - - - - - - +
|        |    |    |
 HP_X     BS_X EV_X IV_X

*/

#define HP_X        4
#define BS_X        54
#define EV_X        BS_X + 30
#define IV_X        EV_X + 30

#define HP_Y        3
#define ATK_Y       HP_Y + 14
#define DEF_Y       ATK_Y + 14
#define SPATK_Y     DEF_Y + 14
#define SPDEF_Y     SPATK_Y + 14
#define SPEED_Y     SPDEF_Y + 14

static const u8 sEvIvStatOrder[EV_IV_ROW_COUNT] =
{
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
};

static const u8 sEvIvStatRowY[EV_IV_ROW_COUNT] =
{
    HP_Y,
    ATK_Y,
    DEF_Y,
    SPATK_Y,
    SPDEF_Y,
    SPEED_Y,
};

static const u16 sEvIvEvDataIds[EV_IV_ROW_COUNT] =
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPEED_EV,
};

static const u16 sEvIvIvDataIds[EV_IV_ROW_COUNT] =
{
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPATK_IV,
    MON_DATA_SPDEF_IV,
    MON_DATA_SPEED_IV,
};


static void PrintWindow0(struct Pokemon *mon);
static void PrintWindow1(u8 nature, u8 isEgg);
static void PrintWindow2(u16 species, u8 isEgg, u8 friendship);
static void PrintWindow_HiddenPower(u8 isEgg);

static void EvIvPrintText(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 nature   = GetNature(mon);
    u8 isEgg    = GetMonData(mon, MON_DATA_IS_EGG, NULL);
    u8 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);

    //reinicia los totales.
    //reset the totals.
    gEvIv->totalStatsEV = 0;
    gEvIv->totalStatsIV = 0;
    gEvIv->totalStatsBS = 0;

    //obtiene las estadísticas del pokémon
    //get pokémon stats

    //STAT_HP
    gEvIv->stats_bs[STAT_HP] = gSpeciesInfo[species].baseHP;
    gEvIv->stats_ev[STAT_HP] = GetMonData(mon,MON_DATA_HP_EV,NULL);
    gEvIv->stats_iv[STAT_HP] = GetMonData(mon,MON_DATA_HP_IV,NULL);

    //STAT_ATK
    gEvIv->stats_bs[STAT_ATK] = gSpeciesInfo[species].baseAttack;
    gEvIv->stats_ev[STAT_ATK] = GetMonData(mon,MON_DATA_ATK_EV,NULL);
    gEvIv->stats_iv[STAT_ATK] = GetMonData(mon,MON_DATA_ATK_IV,NULL);

    //STAT_DEF
    gEvIv->stats_bs[STAT_DEF] = gSpeciesInfo[species].baseDefense;
    gEvIv->stats_ev[STAT_DEF] = GetMonData(mon,MON_DATA_DEF_EV,NULL);
    gEvIv->stats_iv[STAT_DEF] = GetMonData(mon,MON_DATA_DEF_IV,NULL);

    //STAT_SPATK
    gEvIv->stats_bs[STAT_SPATK] = gSpeciesInfo[species].baseSpAttack;
    gEvIv->stats_ev[STAT_SPATK] = GetMonData(mon,MON_DATA_SPATK_EV,NULL);
    gEvIv->stats_iv[STAT_SPATK] = GetMonData(mon,MON_DATA_SPATK_IV,NULL);
    
    //STAT_SPDEF
    gEvIv->stats_bs[STAT_SPDEF] = gSpeciesInfo[species].baseSpDefense;
    gEvIv->stats_ev[STAT_SPDEF] = GetMonData(mon,MON_DATA_SPDEF_EV,NULL);
    gEvIv->stats_iv[STAT_SPDEF] = GetMonData(mon,MON_DATA_SPDEF_IV,NULL);
    
    //STAT_SPEED
    gEvIv->stats_bs[STAT_SPEED] = gSpeciesInfo[species].baseSpeed;
    gEvIv->stats_ev[STAT_SPEED] = GetMonData(mon,MON_DATA_SPEED_EV,NULL);
    gEvIv->stats_iv[STAT_SPEED] = GetMonData(mon,MON_DATA_SPEED_IV,NULL);

    //realiza la suma de los totales
    //performs the sum of the totals
    for (int i = 0; i < NUM_STATS; i++)
    {
        gEvIv->totalStatsEV += gEvIv->stats_ev[i];
        gEvIv->totalStatsIV += gEvIv->stats_iv[i];
        gEvIv->totalStatsBS += gEvIv->stats_bs[i];
    }

    FillWindowPixelBuffer(WIN_POKEMON_NAME, 0);
    FillWindowPixelBuffer(WIN_STATS, 0);
    FillWindowPixelBuffer(WIN_BOTTOM_BOX, 0);
    FillWindowPixelBuffer(WIN_HIDDEN_POWER, 0);
    FillWindowPixelBuffer(WIN_TYPE, 0);

    PrintWindow0(mon);
    PrintWindow1(nature, isEgg);
    PrintWindow2(species, isEgg, friendship);
    PrintWindow_HiddenPower(isEgg);

    PutWindowTilemap(WIN_POKEMON_NAME);
    PutWindowTilemap(WIN_STATS);
    PutWindowTilemap(WIN_BOTTOM_BOX);
    PutWindowTilemap(WIN_HIDDEN_POWER);
    PutWindowTilemap(WIN_TYPE);
    CopyWindowToVram(WIN_TYPE, COPYWIN_GFX);
}

static void PrintWindow0(struct Pokemon *mon)
{
    u8 max_mon_count;
    u8 current_mon = gEvIv->cursorPos + 1;
    u8 x = 16;

    ConvertIntToDecimalStringN(gStringVar4, current_mon, STR_CONV_MODE_LEFT_ALIGN, GetDigitsDec(current_mon));
    if (!IsMultiBattle())
    {
        StringAppend(gStringVar4, gText_eviv_Slash);
        max_mon_count = gEvIv->lastIdx + 1;
        ConvertIntToDecimalStringN(gStringVar1, max_mon_count, STR_CONV_MODE_LEFT_ALIGN, GetDigitsDec(max_mon_count));
        StringAppend(gStringVar4, gStringVar1);

        if(gEvIv->isBoxMon)
            x = 4;
        else
            x = 10;
    }
    AddTextPrinterParameterized3(WIN_POKEMON_NAME, 2, x, 2, sBlackTextColor, 0, gStringVar4);

    AddTextPrinterParameterized3(WIN_POKEMON_NAME, 2, 0x3C, 2, sBlackTextColor, 0, gText_BsEvIv);

    GetMonNickname(mon, gStringVar4);
    AddTextPrinterParameterized3(WIN_POKEMON_NAME, 2, 0x90, 2, sBlackTextColor, 0, gStringVar4);
}

static void PrintWindow1(u8 nature, u8 isEgg)
{
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, HP_Y,    sTextColorByNature[GetColorByNature(nature, STAT_HP)],    0, gText_eviv_Hp);
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, ATK_Y,   sTextColorByNature[GetColorByNature(nature, STAT_ATK)],   0, gText_eviv_Atk);
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, DEF_Y,   sTextColorByNature[GetColorByNature(nature, STAT_DEF)],   0, gText_eviv_Def);
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, SPATK_Y, sTextColorByNature[GetColorByNature(nature, STAT_SPATK)], 0, gText_eviv_SpAtk);
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, SPDEF_Y, sTextColorByNature[GetColorByNature(nature, STAT_SPDEF)], 0, gText_eviv_SpDef);
    AddTextPrinterParameterized3(WIN_STATS, 2, HP_X, SPEED_Y, sTextColorByNature[GetColorByNature(nature, STAT_SPEED)], 0, gText_eviv_Speed);

    if (!isEgg)
    {
        PrintStat(nature, STAT_HP);
        PrintStat(nature, STAT_ATK);
        PrintStat(nature, STAT_DEF);
        PrintStat(nature, STAT_SPATK);
        PrintStat(nature, STAT_SPDEF);
        PrintStat(nature, STAT_SPEED);
    }else{
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, HP_Y,    sBlackTextColor, 0, gText_CensorEgg);
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, ATK_Y,   sBlackTextColor, 0, gText_CensorEgg);
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, DEF_Y,   sBlackTextColor, 0, gText_CensorEgg);
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPATK_Y, sBlackTextColor, 0, gText_CensorEgg);
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPDEF_Y, sBlackTextColor, 0, gText_CensorEgg);
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPEED_Y, sBlackTextColor, 0, gText_CensorEgg);
    }

    if (gEvIv->editMode && !isEgg)
        PrintStatCursor();
}

static void PrintStat(u8 nature, u8 stat)
{
    u8 color_idx = GetColorByNature(nature, stat);
    const u8 *bsColor = sTextColorByNature[color_idx];
    const u8 *evColor = sTextColorByNature[color_idx];
    const u8 *ivColor = sTextColorByNature[color_idx];

    if (gEvIv->editValueMode && GetSelectedStat() == stat)
    {
        if (gEvIv->selectedColumn == EV_IV_EDIT_COL_EV)
            evColor = sWhiteTextColor;
        else
            ivColor = sWhiteTextColor;
    }

    ConvertIntToDecimalStringN(gStringVar1, gEvIv->stats_bs[stat], STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gEvIv->stats_ev[stat], STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gEvIv->stats_iv[stat], STR_CONV_MODE_RIGHT_ALIGN, 2);

    switch (stat)
    {
    case STAT_HP:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, HP_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, HP_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, HP_Y, ivColor, 0, gStringVar3);
        break;
    case STAT_ATK:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, ATK_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, ATK_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, ATK_Y, ivColor, 0, gStringVar3);
        break;
    case STAT_DEF:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, DEF_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, DEF_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, DEF_Y, ivColor, 0, gStringVar3);
        break;
    case STAT_SPATK:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPATK_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, SPATK_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, SPATK_Y, ivColor, 0, gStringVar3);
        break;
    case STAT_SPDEF:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPDEF_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, SPDEF_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, SPDEF_Y, ivColor, 0, gStringVar3);
        break;
    case STAT_SPEED:
        AddTextPrinterParameterized3(WIN_STATS, 2, BS_X, SPEED_Y, bsColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_STATS, 2, EV_X, SPEED_Y, evColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_STATS, 2, IV_X, SPEED_Y, ivColor, 0, gStringVar3);
        break;
    default:
        break;
    }
}

static void PrintStatCursor(void)
{
    u8 y = sEvIvStatRowY[gEvIv->selectedRow];
    AddTextPrinterParameterized3(WIN_STATS, 2, 0, y, sWhiteTextColor, 0, gText_SelectorArrow2);
}

static bool8 TryAdjustSelectedValue(s8 delta)
{
    u8 row = gEvIv->selectedRow;
    u8 stat = sEvIvStatOrder[row];
    s16 current;
    s16 newValue;

    if (gEvIv->selectedColumn == EV_IV_EDIT_COL_EV)
    {
        current = gEvIv->stats_ev[stat];
        newValue = current + delta;
        if (newValue < 0 || newValue > EV_IV_MAX)
            return FALSE;
        if ((gEvIv->totalStatsEV - current + newValue) > EV_IV_TOTAL_MAX)
            return FALSE;
        SetSelectedStatData(sEvIvEvDataIds[row], (u8)newValue);
    }
    else
    {
        current = gEvIv->stats_iv[stat];
        newValue = current + delta;
        if (newValue < 0 || newValue > IV_MAX)
            return FALSE;
        SetSelectedStatData(sEvIvIvDataIds[row], (u8)newValue);
    }

    UpdateCurrentStats();
    return TRUE;
}

static s8 GetEditValueDeltaFromInput(void)
{
    s8 direction = 0;
    s8 magnitude = 1;

    if (JOY_REPEAT(DPAD_UP))
        direction = +1;
    else if (JOY_REPEAT(DPAD_DOWN))
        direction = -1;

    if (direction == 0)
    {
        gEvIv->editValueRepeatDirection = 0;
        gEvIv->editValueRepeatCount = 0;
        return 0;
    }

    if (gEvIv->editValueRepeatDirection == direction)
    {
        if (gEvIv->editValueRepeatCount < 0xFF)
            gEvIv->editValueRepeatCount++;
    }
    else
    {
        gEvIv->editValueRepeatDirection = direction;
        gEvIv->editValueRepeatCount = 1;
    }

    if (gEvIv->editValueRepeatCount >= 30)
        magnitude = 50;
    else if (gEvIv->editValueRepeatCount >= 5)
        magnitude = 10;

    return direction * magnitude;
}

static void MoveSelectedRow(s8 delta)
{
    s8 next = gEvIv->selectedRow + delta;
    if (next < 0)
        next = EV_IV_ROW_COUNT - 1;
    else if (next >= EV_IV_ROW_COUNT)
        next = 0;
    gEvIv->selectedRow = next;
}

static u8 GetSelectedStat(void)
{
    return sEvIvStatOrder[gEvIv->selectedRow];
}

static void SetSelectedStatData(u16 field, u8 value)
{
    if (gEvIv->isBoxMon)
    {
        struct BoxPokemon *boxMon = &gEvIv->monList.boxMons[gEvIv->cursorPos];
        SetBoxMonData(boxMon, field, &value);
    }
    else
    {
        struct Pokemon *mon = &gEvIv->monList.mons[gEvIv->cursorPos];
        SetMonData(mon, field, &value);
        CalculateMonStats(mon);
    }
}

static void PrintWindow2(u16 species, u8 isEgg, u8 friendship)
{
    u32 friendship_result = 0;

    if(!isEgg)
    {
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, 12, 4, sBlackTextColor, 0, gText_eviv_Total);

        ConvertIntToDecimalStringN(gStringVar1, gEvIv->totalStatsBS, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, gEvIv->totalStatsEV, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, gEvIv->totalStatsIV, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, BS_X, 4, sBlackTextColor, 0, gStringVar1);
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, EV_X, 4, sBlackTextColor, 0, gStringVar2);
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, IV_X -6, 4, sBlackTextColor, 0, gStringVar3);

        StringCopy(gStringVar4, gText_Happy);
        
        friendship_result = (friendship * 100) / 0xFF;
        ConvertIntToDecimalStringN(gStringVar2, friendship_result, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(gStringVar4, gStringVar2);
        
        StringAppend(gStringVar4, gText_Percent);
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, 14, 18, sBlackTextColor, 0, gStringVar4);
        
    }else
    {
        friendship_result = ((friendship + 1) * 0x100) - (gSaveBlock1Ptr->daycare.stepCounter + 1);
        if (gSaveBlock1Ptr->daycare.stepCounter == 0xFF)
            friendship_result += 0x100;
        StringCopy(gStringVar4, gText_Steps_to_hatching);
        ConvertIntToDecimalStringN(gStringVar2, friendship_result, STR_CONV_MODE_LEFT_ALIGN, GetDigitsDec(friendship_result));
        StringAppend(gStringVar4, gStringVar2);
        AddTextPrinterParameterized3(WIN_BOTTOM_BOX, 2, 14, 4, sBlackTextColor, 0, gStringVar4);
    }
}

static u8 GetPower_HiddenPower(void)
{
#if HIDDEN_POWER_STATIC
	return HIDDEN_POWER_BASE_POWER;
#else
    s32 powerBits;

    powerBits = ((gEvIv->stats_iv[STAT_HP] & 2) >> 1)
              | ((gEvIv->stats_iv[STAT_ATK] & 2) << 0)
              | ((gEvIv->stats_iv[STAT_DEF] & 2) << 1)
              | ((gEvIv->stats_iv[STAT_SPEED] & 2) << 2)
              | ((gEvIv->stats_iv[STAT_SPATK] & 2) << 3)
              | ((gEvIv->stats_iv[STAT_SPDEF] & 2) << 4);

    return (40 * powerBits) / 63 + 30;
#endif
}

static u8 GetType_HiddenPower(void)
{
    u8 type;
    s32 typeBits;

    typeBits  = ((gEvIv->stats_iv[STAT_HP] & 1) << 0)
              | ((gEvIv->stats_iv[STAT_ATK] & 1) << 1)
              | ((gEvIv->stats_iv[STAT_DEF] & 1) << 2)
              | ((gEvIv->stats_iv[STAT_SPEED] & 1) << 3)
              | ((gEvIv->stats_iv[STAT_SPATK] & 1) << 4)
              | ((gEvIv->stats_iv[STAT_SPDEF] & 1) << 5);

    type = (15 * typeBits) / 63 + 1;

    if (type >= TYPE_MYSTERY)
        type++;

    return type;
}

static void PrintWindow_HiddenPower(u8 isEgg)
{
    u8 power = GetPower_HiddenPower();
    u8 type = GetType_HiddenPower();

    const u8 gText_q[2] = _("?");

    StringCopy(gStringVar4, gText_HiddenPower);

    AddTextPrinterParameterized3(WIN_HIDDEN_POWER, 0, 4, 3, sBlackTextColor, 0, gStringVar4);

    if (!isEgg)
    {
        ConvertIntToDecimalStringN(gStringVar1, power, STR_CONV_MODE_LEFT_ALIGN, GetDigitsDec(power));
        StringCopy(gStringVar4, sText_Power);
        StringAppend(gStringVar4, gStringVar1);
        AddTextPrinterParameterized3(WIN_HIDDEN_POWER, 0, 16, 16, sBlackTextColor, 0, gStringVar4);
        BlitMoveInfoIcon(WIN_TYPE, type, 2, 4);
    }
    else
        AddTextPrinterParameterized3(WIN_HIDDEN_POWER, 0, 32, 16, sWhiteTextColor, 0, gText_q);
}

/**
 * Devuelve el número de dígitos de un número
 * 
 * Returns the number of digits in a number
*/
static u8 GetDigitsDec(u32 num)
{
    u8 digits = 1;
    while (num >= 10)
    {
        digits++;
        num = num / 10;
    }
    return digits;
    /*
    if (num < 10)
        return 1;
    else
        return 1 + GetDigitsDec(num/10);
    */
}

static u8 GetDigitsHex(u32 num)
{
    u8 digits = 1;
    while (num >= 0x10)
    {
        digits++;
        num = num / 0x10;
    }
    return digits;
    /*
    if (num < 0x10)
        return 1;
    else
        return 1 + GetDigitsHex(num/0x10);
    */
}


/**
 * Devuelve el número de dígitos de un entero con signo
 * 
 * Returns the number of digits in a signed int
*/
u8 GetDigitsDec_Signed(s32 num)
{
    if (num < 0)
        num = num * (-1);
    
    return GetDigitsDec(num);
}

u8 GetDigitsHex_Signed(s32 num)
{
    if (num < 0)
        num = num * (-1);
    
    return GetDigitsHex(num);
}

const s8 gNatureStatTable_copy[NUM_NATURES][NUM_NATURE_STATS] =
{
                    //  Atk             Def             Spd             Sp.Atk          Sp.Def
    [NATURE_HARDY]   = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_LONELY]  = {STAT_INCREASE,  STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_BRAVE]   = {STAT_INCREASE,  STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_ADAMANT] = {STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL},
    [NATURE_NAUGHTY] = {STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE},
    [NATURE_BOLD]    = {STAT_DECREASE,  STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_DOCILE]  = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_RELAXED] = {STAT_NEUTRAL,   STAT_INCREASE,  STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_IMPISH]  = {STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL},
    [NATURE_LAX]     = {STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE},
    [NATURE_TIMID]   = {STAT_DECREASE,  STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_HASTY]   = {STAT_NEUTRAL,   STAT_DECREASE,  STAT_INCREASE,  STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_SERIOUS] = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_JOLLY]   = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE,  STAT_DECREASE,  STAT_NEUTRAL},
    [NATURE_NAIVE]   = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL,   STAT_DECREASE},
    [NATURE_MODEST]  = {STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL},
    [NATURE_MILD]    = {STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL,   STAT_INCREASE,  STAT_NEUTRAL},
    [NATURE_QUIET]   = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE,  STAT_INCREASE,  STAT_NEUTRAL},
    [NATURE_BASHFUL] = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
    [NATURE_RASH]    = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE,  STAT_DECREASE},
    [NATURE_CALM]    = {STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE},
    [NATURE_GENTLE]  = {STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_INCREASE},
    [NATURE_SASSY]   = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE,  STAT_NEUTRAL,   STAT_INCREASE},
    [NATURE_CAREFUL] = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_DECREASE,  STAT_INCREASE},
    [NATURE_QUIRKY]  = {STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL,   STAT_NEUTRAL},
};

static u8 GetColorByNature(u8 nature, u8 statIndex)
{
    if (statIndex < STAT_ATK || statIndex > STAT_SPDEF)
        return STAT_NEUTRAL + 1;

    return gNatureStatTable_copy[nature][statIndex - 1] + 1;
}
