#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "item.h"
#include "item_icon.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "decompress.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/vars.h"

#define KURT_MENU_BALL_COUNT 8
#define KURT_MENU_ITEM_COUNT (KURT_MENU_BALL_COUNT + 1)
#define KURT_MENU_NAME_LEN 32
#define KURT_MAX_ITEMS_SHOWN 8
#define KURT_ICON_TAG_BASE 5600
#define KURT_SCROLL_ARROW_TAG 5602

enum
{
    KURT_STATE_LIST,
    KURT_STATE_QUANTITY,
};

enum
{
    COLORID_NORMAL,
    COLORID_ITEM_LIST,
    COLORID_GRAY_CURSOR,
};

enum
{
    KURTWIN_MONEY,
    KURTWIN_ITEM_LIST,
    KURTWIN_ITEM_DESCRIPTION,
    KURTWIN_QUANTITY_IN_BAG,
    KURTWIN_QUANTITY_PRICE,
    KURTWIN_MESSAGE,
    KURTWIN_COUNT
};

static const u8 sText_KurtApricorns[] = _("APRICORNS");
static const u8 sText_ApricornsInBagFmt[] = _("{STR_VAR_1} x{STR_VAR_2}");
static const u8 sText_RedApricorns[] = _("Red Apricorns");
static const u8 sText_BlueApricorns[] = _("Blue Apricorns");
static const u8 sText_YellowApricorns[] = _("Yellow Apricorns");
static const u8 sText_GreenApricorns[] = _("Green Apricorns");
static const u8 sText_WhiteApricorns[] = _("White Apricorns");
static const u8 sText_PinkApricorns[] = _("Pink Apricorns");
static const u8 sText_BlackApricorns[] = _("Black Apricorns");
static const u8 sText_AsstdApricorns[] = _("Asstd. Apricorns");
static const u16 sKurtApricornColors[] =
{
    ITEM_RED_APRICORN,
    ITEM_BLUE_APRICORN,
    ITEM_YELLOW_APRICORN,
    ITEM_GREEN_APRICORN,
    ITEM_WHITE_APRICORN,
    ITEM_PINK_APRICORN,
    ITEM_BLACK_APRICORN,
};

static const u16 sKurtApricornBallItems[KURT_MENU_BALL_COUNT] =
{
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_MOON_BALL,
    ITEM_FRIEND_BALL,
    ITEM_FAST_BALL,
    ITEM_LOVE_BALL,
    ITEM_HEAVY_BALL,
    ITEM_DARK_BALL,
};

static const u8 *const sKurtApricornLabelTexts[KURT_MENU_BALL_COUNT] =
{
    sText_RedApricorns,
    sText_BlueApricorns,
    sText_YellowApricorns,
    sText_GreenApricorns,
    sText_WhiteApricorns,
    sText_PinkApricorns,
    sText_BlackApricorns,
    sText_AsstdApricorns,
};

static const u16 sKurtBallToApricornItem[KURT_MENU_BALL_COUNT] =
{
    ITEM_RED_APRICORN,
    ITEM_BLUE_APRICORN,
    ITEM_YELLOW_APRICORN,
    ITEM_GREEN_APRICORN,
    ITEM_WHITE_APRICORN,
    ITEM_PINK_APRICORN,
    ITEM_BLACK_APRICORN,
    ITEM_NONE,
};

static const struct BgTemplate sKurtApricornBgTemplates[] =
{
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
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sKurtApricornWindowTemplates[] =
{
    [KURTWIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    [KURTWIN_ITEM_LIST] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    [KURTWIN_ITEM_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    [KURTWIN_QUANTITY_IN_BAG] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0176,
    },
    [KURTWIN_QUANTITY_PRICE] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    [KURTWIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x01A2,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct ListMenuTemplate sKurtApricornListTemplate =
{
    .items = NULL,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = KURTWIN_ITEM_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 1,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_BLACK_ARROW,
    .textNarrowWidth = 84,
};

static const u8 sKurtMenuTextColors[][3] =
{
    [COLORID_NORMAL]      = {1, 2, 3},
    [COLORID_ITEM_LIST]   = {0, 2, 1},
    [COLORID_GRAY_CURSOR] = {0, 2, 1},
};

struct KurtApricornMenu
{
    struct ListMenuItem items[KURT_MENU_ITEM_COUNT];
    struct ListMenuTemplate listMenuTemplate;
    u16 itemCounts[KURT_MENU_BALL_COUNT];
    u8 names[KURT_MENU_ITEM_COUNT][KURT_MENU_NAME_LEN];
    u16 tilemapBuffers[2][0x400];
    u16 scrollOffset;
    u16 listRow;
    u16 maxQuantity;
    s16 quantity;
    u16 selectedBallItem;
    u8 listTaskId;
    u8 scrollIndicatorsTaskId;
    u8 menuTaskId;
    u8 itemSpriteIds[2];
    u8 iconSlot;
    u8 state;
    bool8 exitPending;
    bool8 quantityWindowVisible;
    bool8 messageWindowVisible;
};

static EWRAM_DATA struct KurtApricornMenu *sKurtMenu = NULL;

static void Task_KurtApricornMenu(u8 taskId);
static void CB2_InitKurtApricornMenu(void);
static void CB2_KurtApricornMenu(void);
static void VBlankCB_KurtApricornMenu(void);
static void Task_WaitForKurtApricornFadeOut(u8 taskId);
static void InitKurtApricornBackgroundLayers(void);
static void KurtMenu_DecompressBgGraphics(void);
static void KurtMenu_InitWindows(void);
static void KurtMenu_Print(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet);
static void KurtMenu_PrintCountInList(u8 windowId, u32 itemId, u8 y);
static void KurtMenu_PrintDescriptionAndShowItemIcon(s32 itemId, bool8 onInit, struct ListMenu *list);
static void KurtMenu_AddScrollArrows(void);
static void KurtMenu_RemoveScrollArrows(void);
static void KurtMenu_AddItemIcon(u16 itemId, u8 iconSlot);
static void KurtMenu_RemoveItemIcon(u8 iconSlot);
static void KurtMenu_PrintQuantityInBag(u16 itemId);
static void KurtMenu_ShowMessage(const u8 *text);
static void KurtMenu_HideMessage(void);
static void KurtMenu_RestoreListWindows(void);
static void KurtMenu_ShowQuantityWindow(void);
static void KurtMenu_HideQuantityWindow(void);
static void KurtMenu_PrintQuantity(void);
static void KurtMenu_Destroy(void);
static void KurtMenu_Exit(bool8 orderPlaced);

static u16 KurtMenu_GetDarkBallCount(void)
{
    u32 i;
    u16 minCount = CountTotalItemQuantityInBag(sKurtApricornColors[0]);

    for (i = 1; i < ARRAY_COUNT(sKurtApricornColors); i++)
    {
        u16 count = CountTotalItemQuantityInBag(sKurtApricornColors[i]);
        if (count < minCount)
            minCount = count;
    }

    return minCount;
}

static s32 KurtMenu_GetIndexByItemId(u16 itemId)
{
    u32 i;

    for (i = 0; i < KURT_MENU_BALL_COUNT; i++)
    {
        if (sKurtApricornBallItems[i] == itemId)
            return i;
    }

    return -1;
}

static void KurtMenu_BuildItems(void)
{
    u32 i;

    for (i = 0; i < KURT_MENU_BALL_COUNT; i++)
    {
        u16 count;

        if (i == KURT_MENU_BALL_COUNT - 1)
            count = KurtMenu_GetDarkBallCount();
        else
            count = CountTotalItemQuantityInBag(sKurtBallToApricornItem[i]);

        sKurtMenu->itemCounts[i] = count;
        CopyItemName(sKurtApricornBallItems[i], sKurtMenu->names[i]);
        sKurtMenu->items[i].name = sKurtMenu->names[i];
        sKurtMenu->items[i].id = sKurtApricornBallItems[i];
    }

    StringCopy(sKurtMenu->names[KURT_MENU_ITEM_COUNT - 1], gText_Cancel);
    sKurtMenu->items[KURT_MENU_ITEM_COUNT - 1].name = sKurtMenu->names[KURT_MENU_ITEM_COUNT - 1];
    sKurtMenu->items[KURT_MENU_ITEM_COUNT - 1].id = LIST_CANCEL;
}

static void KurtMenu_Print(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet)
{
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 0, 0, sKurtMenuTextColors[colorSet], speed, text);
}

static void KurtMenu_PrintCountInList(u8 windowId, u32 itemId, u8 y)
{
    u8 x;
    s32 index;

    if (itemId == LIST_CANCEL)
        return;

    index = KurtMenu_GetIndexByItemId(itemId);
    if (index < 0)
        return;

    ConvertIntToDecimalStringN(gStringVar1, sKurtMenu->itemCounts[index], STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    x = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 120);
    AddTextPrinterParameterized4(windowId, FONT_NARROW, x, y, 0, 0, sKurtMenuTextColors[COLORID_ITEM_LIST], TEXT_SKIP_DRAW, gStringVar4);
}

static void KurtMenu_AddItemIcon(u16 itemId, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &sKurtMenu->itemSpriteIds[iconSlot];

    if (*spriteIdPtr != SPRITE_NONE)
        return;

    spriteId = AddItemIconSprite(iconSlot + KURT_ICON_TAG_BASE, iconSlot + KURT_ICON_TAG_BASE, itemId);
    if (spriteId != MAX_SPRITES)
    {
        *spriteIdPtr = spriteId;
        gSprites[spriteId].x2 = 24;
        gSprites[spriteId].y2 = 88;
    }
}

static void KurtMenu_RemoveItemIcon(u8 iconSlot)
{
    u8 *spriteIdPtr = &sKurtMenu->itemSpriteIds[iconSlot];

    if (*spriteIdPtr == SPRITE_NONE)
        return;

    FreeSpriteTilesByTag(iconSlot + KURT_ICON_TAG_BASE);
    FreeSpritePaletteByTag(iconSlot + KURT_ICON_TAG_BASE);
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = SPRITE_NONE;
}

static void KurtMenu_PrintQuantityInBag(u16 itemId)
{
    s32 index;
    u16 count = 0;
    const u8 *label = NULL;

    if (itemId != LIST_CANCEL)
    {
        index = KurtMenu_GetIndexByItemId(itemId);
        if (index >= 0)
        {
            count = sKurtMenu->itemCounts[index];
            label = sKurtApricornLabelTexts[index];
        }
    }

    FillWindowPixelBuffer(KURTWIN_QUANTITY_IN_BAG, PIXEL_FILL(1));
    if (label != NULL)
    {
        ConvertIntToDecimalStringN(gStringVar2, count, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(gStringVar1, label);
        StringExpandPlaceholders(gStringVar4, sText_ApricornsInBagFmt);
        AddTextPrinterParameterized4(KURTWIN_QUANTITY_IN_BAG, FONT_NARROW, 0, 0, 0, 0,
                                     sKurtMenuTextColors[COLORID_NORMAL], TEXT_SKIP_DRAW, gStringVar4);
    }
    CopyWindowToVram(KURTWIN_QUANTITY_IN_BAG, COPYWIN_GFX);
}

static void KurtMenu_ShowMessage(const u8 *text)
{
    if (!sKurtMenu->messageWindowVisible)
        PutWindowTilemap(KURTWIN_MESSAGE);

    FillWindowPixelBuffer(KURTWIN_MESSAGE, PIXEL_FILL(1));
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_MESSAGE, FALSE, 1, 0xE);
    KurtMenu_Print(KURTWIN_MESSAGE, text, 0, 0, 0, COLORID_NORMAL);
    CopyWindowToVram(KURTWIN_MESSAGE, COPYWIN_FULL);
    ScheduleBgCopyTilemapToVram(0);
    sKurtMenu->messageWindowVisible = TRUE;
}

static void KurtMenu_HideMessage(void)
{
    if (!sKurtMenu->messageWindowVisible)
        return;

    ClearStdWindowAndFrameToTransparent(KURTWIN_MESSAGE, TRUE);
    ClearWindowTilemap(KURTWIN_MESSAGE);
    ScheduleBgCopyTilemapToVram(0);
    sKurtMenu->messageWindowVisible = FALSE;

    if (!sKurtMenu->quantityWindowVisible)
        KurtMenu_RestoreListWindows();
}

static void KurtMenu_RestoreListWindows(void)
{
    u16 arrayId = 0;
    s32 itemId;

    PutWindowTilemap(KURTWIN_ITEM_LIST);
    PutWindowTilemap(KURTWIN_ITEM_DESCRIPTION);
    PutWindowTilemap(KURTWIN_QUANTITY_IN_BAG);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_ITEM_LIST, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_ITEM_DESCRIPTION, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_QUANTITY_IN_BAG, FALSE, 1, 0xE);

    RedrawListMenu(sKurtMenu->listTaskId);
    CopyWindowToVram(KURTWIN_ITEM_LIST, COPYWIN_GFX);

    ListMenuGetCurrentItemArrayId(sKurtMenu->listTaskId, &arrayId);
    itemId = sKurtMenu->items[arrayId].id;
    KurtMenu_PrintDescriptionAndShowItemIcon(itemId, TRUE, NULL);
    ScheduleBgCopyTilemapToVram(0);
}

static void KurtMenu_PrintDescriptionAndShowItemIcon(s32 itemId, bool8 onInit, struct ListMenu *list)
{
    const u8 *desc;

    (void)list;

    if (itemId != LIST_CANCEL)
        desc = GetItemDescription(itemId);
    else
        desc = gText_QuitShopping;

    FillWindowPixelBuffer(KURTWIN_ITEM_DESCRIPTION, PIXEL_FILL(1));
    KurtMenu_Print(KURTWIN_ITEM_DESCRIPTION, desc, 3, 1, 0, COLORID_NORMAL);
    CopyWindowToVram(KURTWIN_ITEM_DESCRIPTION, COPYWIN_GFX);

    KurtMenu_PrintQuantityInBag(itemId);

    if (!onInit)
        PlaySE(SE_SELECT);

    if (itemId != LIST_CANCEL)
        KurtMenu_AddItemIcon(itemId, sKurtMenu->iconSlot);
    else
        KurtMenu_AddItemIcon(ITEM_LIST_END, sKurtMenu->iconSlot);

    KurtMenu_RemoveItemIcon(sKurtMenu->iconSlot ^ 1);
    sKurtMenu->iconSlot ^= 1;
}

static void KurtMenu_AddScrollArrows(void)
{
    if (sKurtMenu->scrollIndicatorsTaskId == TASK_NONE && KURT_MENU_ITEM_COUNT > KURT_MAX_ITEMS_SHOWN)
    {
        sKurtMenu->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            172,
            12,
            148,
            KURT_MENU_ITEM_COUNT - (KURT_MAX_ITEMS_SHOWN - 1),
            KURT_SCROLL_ARROW_TAG,
            KURT_SCROLL_ARROW_TAG,
            &sKurtMenu->scrollOffset);
    }
}

static void KurtMenu_RemoveScrollArrows(void)
{
    if (sKurtMenu->scrollIndicatorsTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sKurtMenu->scrollIndicatorsTaskId);
        sKurtMenu->scrollIndicatorsTaskId = TASK_NONE;
    }
}

static void KurtMenu_ShowQuantityWindow(void)
{
    if (sKurtMenu->quantityWindowVisible)
        return;

    PutWindowTilemap(KURTWIN_QUANTITY_PRICE);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_QUANTITY_PRICE, FALSE, 1, 0xE);
    ScheduleBgCopyTilemapToVram(0);
    sKurtMenu->quantityWindowVisible = TRUE;
    KurtMenu_PrintQuantity();
}

static void KurtMenu_HideQuantityWindow(void)
{
    if (!sKurtMenu->quantityWindowVisible)
        return;

    ClearStdWindowAndFrameToTransparent(KURTWIN_QUANTITY_PRICE, TRUE);
    ClearWindowTilemap(KURTWIN_QUANTITY_PRICE);
    ScheduleBgCopyTilemapToVram(0);
    sKurtMenu->quantityWindowVisible = FALSE;

    if (!sKurtMenu->messageWindowVisible)
        KurtMenu_RestoreListWindows();
}

static void KurtMenu_PrintQuantity(void)
{
    FillWindowPixelBuffer(KURTWIN_QUANTITY_PRICE, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, sKurtMenu->quantity, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    KurtMenu_Print(KURTWIN_QUANTITY_PRICE, gStringVar4, 0, 1, 0, COLORID_NORMAL);
    CopyWindowToVram(KURTWIN_QUANTITY_PRICE, COPYWIN_FULL);
}

static void KurtMenu_PlaceOrder(u16 ballItem, u16 quantity)
{
    u32 i;

    if (ballItem == ITEM_DARK_BALL)
    {
        for (i = 0; i < ARRAY_COUNT(sKurtApricornColors); i++)
            RemoveBagItem(sKurtApricornColors[i], quantity);
    }
    else
    {
        for (i = 0; i < KURT_MENU_BALL_COUNT; i++)
        {
            if (sKurtApricornBallItems[i] == ballItem)
            {
                RemoveBagItem(sKurtBallToApricornItem[i], quantity);
                break;
            }
        }
    }

    VarSet(VAR_KURT_ORDER_STATE, 1);
    VarSet(VAR_KURT_ORDER_ITEM, ballItem);
    VarSet(VAR_KURT_ORDER_COUNT, quantity);
}

static void KurtMenu_HandleListInput(s32 input)
{
    s32 index;

    if (input == LIST_CANCEL)
    {
        PlaySE(SE_SELECT);
        KurtMenu_Exit(FALSE);
        return;
    }

    index = KurtMenu_GetIndexByItemId(input);
    if (index < 0)
        return;

    if (sKurtMenu->itemCounts[index] == 0)
    {
        PlaySE(SE_FAILURE);
        return;
    }

    sKurtMenu->selectedBallItem = input;
    sKurtMenu->maxQuantity = sKurtMenu->itemCounts[index];
    sKurtMenu->quantity = 1;

    if (sKurtMenu->maxQuantity == 1)
    {
        KurtMenu_PlaceOrder(sKurtMenu->selectedBallItem, 1);
        KurtMenu_Exit(TRUE);
        return;
    }

    sKurtMenu->state = KURT_STATE_QUANTITY;
    KurtMenu_ShowQuantityWindow();
    CopyItemName(sKurtMenu->selectedBallItem, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CertainlyHowMany);
    KurtMenu_ShowMessage(gStringVar4);
}

static void KurtMenu_HandleQuantityInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        KurtMenu_PlaceOrder(sKurtMenu->selectedBallItem, sKurtMenu->quantity);
        KurtMenu_HideMessage();
        KurtMenu_Exit(TRUE);
        return;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        KurtMenu_HideQuantityWindow();
        KurtMenu_HideMessage();
        sKurtMenu->state = KURT_STATE_LIST;
        return;
    }

    if (AdjustQuantityAccordingToDPadInput(&sKurtMenu->quantity, sKurtMenu->maxQuantity))
    {
        PlaySE(SE_SELECT);
        KurtMenu_PrintQuantity();
    }
}

static void Task_KurtApricornMenu(u8 taskId)
{
    s32 input;

    if (sKurtMenu->exitPending)
        return;

    switch (sKurtMenu->state)
    {
    case KURT_STATE_LIST:
        input = ListMenu_ProcessInput(sKurtMenu->listTaskId);
        ListMenuGetScrollAndRow(sKurtMenu->listTaskId, &sKurtMenu->scrollOffset, &sKurtMenu->listRow);
        if (input != LIST_NOTHING_CHOSEN)
            KurtMenu_HandleListInput(input);
        break;
    case KURT_STATE_QUANTITY:
        KurtMenu_HandleQuantityInput();
        break;
    }
}

static void KurtMenu_Destroy(void)
{
    u32 i;

    if (sKurtMenu == NULL)
        return;

    KurtMenu_RemoveScrollArrows();

    for (i = 0; i < ARRAY_COUNT(sKurtMenu->itemSpriteIds); i++)
        KurtMenu_RemoveItemIcon(i);

    if (sKurtMenu->listTaskId != TASK_NONE)
        DestroyListMenuTask(sKurtMenu->listTaskId, NULL, NULL);

    if (sKurtMenu->menuTaskId != TASK_NONE)
        DestroyTask(sKurtMenu->menuTaskId);

    FreeAllWindowBuffers();
    Free(sKurtMenu);
    sKurtMenu = NULL;
}

static void KurtMenu_Exit(bool8 orderPlaced)
{
    if (sKurtMenu->exitPending)
        return;

    gSpecialVar_Result = orderPlaced;
    sKurtMenu->exitPending = TRUE;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

static void VBlankCB_KurtApricornMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitKurtApricornBackgroundLayers(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sKurtApricornBgTemplates, ARRAY_COUNT(sKurtApricornBgTemplates));
    SetBgTilemapBuffer(1, sKurtMenu->tilemapBuffers[0]);
    SetBgTilemapBuffer(2, sKurtMenu->tilemapBuffers[1]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void KurtMenu_DecompressBgGraphics(void)
{
    DecompressAndCopyTileDataToVram(1, gShopMenu_Gfx, 0, 4, 0);
    DecompressAndCopyTileDataToVram(2, gShopMenu_ScrollGfx, 0, 0, 0);
    DecompressDataWithHeaderWram(gShopMenu_ScrollTilemap, sKurtMenu->tilemapBuffers[1]);
    LoadPalette(gShopMenu_Pal, BG_PLTT_ID(12), PLTT_SIZE_4BPP);
}

static void KurtMenu_InitWindows(void)
{
    InitWindows(sKurtApricornWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(KURTWIN_MONEY, 1, BG_PLTT_ID(13));
    LoadMessageBoxGfx(KURTWIN_MONEY, 0xA, BG_PLTT_ID(14));
    PutWindowTilemap(KURTWIN_ITEM_LIST);
    PutWindowTilemap(KURTWIN_ITEM_DESCRIPTION);
    PutWindowTilemap(KURTWIN_QUANTITY_IN_BAG);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_ITEM_LIST, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_ITEM_DESCRIPTION, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(KURTWIN_QUANTITY_IN_BAG, FALSE, 1, 0xE);
}

static void CB2_KurtApricornMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();

    if (sKurtMenu != NULL && sKurtMenu->exitPending && !gPaletteFade.active)
    {
        KurtMenu_Destroy();
        SetMainCallback2(CB2_ReturnToField);
    }
}

static void CB2_InitKurtApricornMenu(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ClearScheduledBgCopiesToVram();

    sKurtMenu = AllocZeroed(sizeof(*sKurtMenu));
    if (sKurtMenu == NULL)
    {
        gSpecialVar_Result = 0;
        SetMainCallback2(CB2_ReturnToField);
        return;
    }

    sKurtMenu->listTaskId = TASK_NONE;
    sKurtMenu->scrollIndicatorsTaskId = TASK_NONE;
    sKurtMenu->menuTaskId = TASK_NONE;
    sKurtMenu->itemSpriteIds[0] = SPRITE_NONE;
    sKurtMenu->itemSpriteIds[1] = SPRITE_NONE;
    sKurtMenu->iconSlot = 0;
    sKurtMenu->state = KURT_STATE_LIST;
    sKurtMenu->scrollOffset = 0;
    sKurtMenu->listRow = 0;
    sKurtMenu->exitPending = FALSE;
    sKurtMenu->quantityWindowVisible = FALSE;
    sKurtMenu->messageWindowVisible = FALSE;

    SetVBlankCallback(VBlankCB_KurtApricornMenu);
    InitKurtApricornBackgroundLayers();
    KurtMenu_DecompressBgGraphics();
    KurtMenu_InitWindows();
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);

    KurtMenu_BuildItems();

    sKurtMenu->listMenuTemplate = sKurtApricornListTemplate;
    sKurtMenu->listMenuTemplate.items = sKurtMenu->items;
    sKurtMenu->listMenuTemplate.totalItems = KURT_MENU_ITEM_COUNT;
    sKurtMenu->listMenuTemplate.maxShowed = (KURT_MENU_ITEM_COUNT < KURT_MAX_ITEMS_SHOWN) ? KURT_MENU_ITEM_COUNT : KURT_MAX_ITEMS_SHOWN;
    sKurtMenu->listMenuTemplate.moveCursorFunc = KurtMenu_PrintDescriptionAndShowItemIcon;
    sKurtMenu->listMenuTemplate.itemPrintFunc = KurtMenu_PrintCountInList;

    sKurtMenu->listTaskId = ListMenuInit(&sKurtMenu->listMenuTemplate, sKurtMenu->scrollOffset, sKurtMenu->listRow);
    KurtMenu_AddScrollArrows();

    sKurtMenu->menuTaskId = CreateTask(Task_KurtApricornMenu, 0);
    SetBackdropFromColor(RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetMainCallback2(CB2_KurtApricornMenu);
}

static void Task_WaitForKurtApricornFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InitKurtApricornMenu);
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        DestroyTask(taskId);
    }
}

void Special_KurtApricornMenu(void)
{
    if (sKurtMenu != NULL)
        return;

    LockPlayerFieldControls();
    CreateTask(Task_WaitForKurtApricornFadeOut, 10);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}
