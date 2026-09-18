#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_dome.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bug_contest.h"
#include "battle_tv.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "malloc.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "reshow_battle_screen.h"
#include "battle_gfx_sfx_util.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "line_break.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_partner.h"
#include "constants/hold_effects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"
#include "caps.h"
#include "menu.h"
#include "pokemon_summary_screen.h"
#include "type_icons.h"
#include "pokedex.h"

#define MOVE_TYPE_PAL_BASE 13
#define TAG_MOVE_TYPE_PAL 0xD7F8
#define TAG_MOVE_TYPE_ICON 0xD7FB
#define MOVE_TYPE_ICON_SIZE 0x100
#define MOVE_TYPE_PAL_SLOT 13

static u8 sLoadedMoveTypeIcon;
static u8 sMoveTypePaletteRefreshBattler;
static u8 sMoveTypePaletteRefreshFrames;

static void SpriteCB_ShowMoveMenuIconNextFrame(struct Sprite *sprite);

static const struct SpritePalette sMoveTypeIconSpritePal =
{
    .data = gMoveTypes_Pal,
    .tag = TAG_MOVE_TYPE_PAL,
};

static void DestroyMoveMenuIcons(void);
static void FreeMoveMenuIconPalettes(void);
void ReserveMoveTypeIconPaletteSlot(void);
static void RefreshCategoryIconPalette(void);

static const struct OamData sOamData_MoveTypeIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_MoveTypeIcon[] =
{
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_MoveTypeIcon[] =
{
    sSpriteAnim_MoveTypeIcon,
};

static const struct SpriteTemplate sSpriteTemplate_MoveTypeIcon =
{
    .tileTag = TAG_MOVE_TYPE_ICON,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_MoveTypeIcon,
    .anims = sSpriteAnimTable_MoveTypeIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void SpriteCB_ShowMoveMenuIconNextFrame(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[0] = 1;
        return;
    }

    sprite->invisible = FALSE;
    sprite->data[0] = 0;
    sprite->callback = SpriteCallbackDummy;
}

static u8 GetMoveTypeIconPaletteNum(u32 type)
{
    s32 offset = (s32)gTypesInfo[type].palette - MOVE_TYPE_PAL_BASE;
    u8 palNum;

    if (offset < 0 || offset > 2)
        return 0xFF;
    palNum = IndexOfSpritePaletteTag(TAG_MOVE_TYPE_PAL);
    if (palNum == 0xFF)
    {
        ReserveMoveTypeIconPaletteSlot();
        palNum = IndexOfSpritePaletteTag(TAG_MOVE_TYPE_PAL);
    }
    if (palNum != 0xFF)
    {
        LoadPalette(gMoveTypes_Pal + (offset * 16), OBJ_PLTT_ID(palNum), PLTT_SIZE_4BPP);
        TransferPlttBuffer();
    }
    return palNum;
}

static bool8 LoadMoveTypeIconTiles(u32 type)
{
    u16 tileStart = GetSpriteTileStartByTag(TAG_MOVE_TYPE_ICON);
    void *buffer;
    const u8 *frame;

    if (type >= NUMBER_OF_MON_TYPES)
        type = TYPE_MYSTERY;
    if (tileStart != 0xFFFF && sLoadedMoveTypeIcon == type)
        return TRUE;

    buffer = malloc_and_decompress(gMoveTypes_Gfx, NULL);
    if (buffer == NULL)
        return FALSE;

    frame = (const u8 *)buffer + (type * MOVE_TYPE_ICON_SIZE);
    if (tileStart == 0xFFFF)
    {
        struct SpriteSheet sheet = { .data = frame, .size = MOVE_TYPE_ICON_SIZE, .tag = TAG_MOVE_TYPE_ICON };
        LoadSpriteSheet(&sheet);
        tileStart = GetSpriteTileStartByTag(TAG_MOVE_TYPE_ICON);
    }
    else
    {
        CpuSmartCopy16(frame, (u8 *)OBJ_VRAM0 + (tileStart * TILE_SIZE_4BPP), MOVE_TYPE_ICON_SIZE);
    }

    Free(buffer);

    if (tileStart == 0xFFFF)
        return FALSE;

    sLoadedMoveTypeIcon = type;
    return TRUE;
}

static void DestroyMoveMenuIcons(void)
{
    if (gMoveTypeIconSpriteId != 0xFF)
    {
        DestroySprite(&gSprites[gMoveTypeIconSpriteId]);
        gMoveTypeIconSpriteId = 0xFF;
    }
    FreeSpriteTilesByTag(TAG_MOVE_TYPE_ICON);
    sLoadedMoveTypeIcon = 0xFF;

    if (gCategoryIconSpriteId != 0xFF)
    {
        DestroySprite(&gSprites[gCategoryIconSpriteId]);
        gCategoryIconSpriteId = 0xFF;
    }

    if (IsDoubleBattle())
    {
        FreeSpriteTilesByTag(gSpriteSheet_CategoryIcons.tag);
        FreeMoveMenuIconPalettes();
    }
}

static void FreeMoveMenuIconPalettes(void)
{
    if (IsDoubleBattle())
    {
        FreeSpritePaletteByTag(TAG_MOVE_TYPE_PAL);
        FreeSpritePaletteByTag(gSpritePal_CategoryIcons.tag);
    }
}

void ReserveMoveTypeIconPaletteSlot(void)
{
    u8 palNum = IndexOfSpritePaletteTag(TAG_MOVE_TYPE_PAL);

    if (palNum == 0xFF && MOVE_TYPE_PAL_SLOT >= gReservedSpritePaletteCount)
    {
        u16 slotTag = GetSpritePaletteTagByPaletteNum(MOVE_TYPE_PAL_SLOT);

        if (slotTag == TAG_NONE || slotTag == TAG_MOVE_TYPE_PAL)
            palNum = LoadSpritePaletteInSlot(&sMoveTypeIconSpritePal, MOVE_TYPE_PAL_SLOT);
    }

    if (palNum == 0xFF)
        palNum = LoadSpritePalette(&sMoveTypeIconSpritePal);

    if (palNum != 0xFF)
        LoadPalette(gMoveTypes_Pal, OBJ_PLTT_ID(palNum), PLTT_SIZE_4BPP);
}

static void RefreshCategoryIconPalette(void)
{
    u32 palIndex = IndexOfSpritePaletteTag(gSpritePal_CategoryIcons.tag);

    if (palIndex != 0xFF)
        LoadPalette(gSpritePal_CategoryIcons.data, OBJ_PLTT_ID(palIndex), PLTT_SIZE_4BPP);
}

void ShadowHud_Clear(u8 battler);
void ShadowHud_SyncForBattler(u8 battler);
void BattleHud_ApplyHealthboxPalette(u8 battler, bool8 isShadowNow);

static void PlayerBufferExecCompleted(u32 battler);
static void PlayerHandleLoadMonSprite(u32 battler);
static void PlayerHandleSwitchInAnim(u32 battler);
static void PlayerHandleDrawTrainerPic(u32 battler);
static void PlayerHandleTrainerSlide(u32 battler);
static void PlayerHandleTrainerSlideBack(u32 battler);
static void PlayerHandlePaletteFade(u32 battler);
static void PlayerHandleSuccessBallThrowAnim(u32 battler);
static void PlayerHandlePause(u32 battler);
static void PlayerHandleMoveAnimation(u32 battler);
static void PlayerHandlePrintString(u32 battler);
static void PlayerHandlePrintSelectionString(u32 battler);
static void PlayerHandleChooseAction(u32 battler);
static void PlayerHandleYesNoBox(u32 battler);
static void PlayerHandleChooseItem(u32 battler);
static void PlayerHandleChoosePokemon(u32 battler);
static void PlayerHandleCmd23(u32 battler);
static void PlayerHandleHealthBarUpdate(u32 battler);
static void PlayerHandleStatusXor(u32 battler);
static void PlayerHandleDMA3Transfer(u32 battler);
static void PlayerHandlePlayBGM(u32 battler);
static void PlayerHandleTwoReturnValues(u32 battler);
static void PlayerHandleChosenMonReturnValue(u32 battler);
static void PlayerHandleOneReturnValue(u32 battler);
static void PlayerHandleOneReturnValue_Duplicate(u32 battler);
static void PlayerHandleIntroTrainerBallThrow(u32 battler);
static void PlayerHandleDrawPartyStatusSummary(u32 battler);
static void PlayerHandleEndBounceEffect(u32 battler);
static void PlayerHandleBattleAnimation(u32 battler);
static void PlayerHandleLinkStandbyMsg(u32 battler);
static void PlayerHandleResetActionMoveSelection(u32 battler);
static void PlayerHandleEndLinkBattle(u32 battler);
static void PlayerHandleBattleDebug(u32 battler);
static void PlayerHandleHeartValueUpdate(u32 battler);

static void PlayerBufferRunCommand(u32 battler);
static void MoveSelectionDisplayPpNumber(u32 battler);
static void MoveSelectionDisplayPpString(u32 battler);
static void MoveSelectionDisplayMoveType(u32 battler);
static void MoveSelectionDisplayMoveNames(u32 battler);
static void TryMoveSelectionDisplayMoveDescription(u32 battler);
static void MoveSelectionDisplayMoveDescription(u32 battler);
static void SwitchIn_HandleSoundAndEnd(u32 battler);
static void WaitForMonSelection(u32 battler);
static void CompleteWhenChoseItem(u32 battler);
static void HandleInputChooseBallTarget(u32 battler);
static bool8 IsOpponentShadowBattler(u8 battler);
static bool8 ShouldSelectShadowBallTarget(void);
static void StartBallTargetSelection(u32 battler, u8 mode, u16 itemId);
static u8 GetOtherShadowOpponent(u8 battler);
static void Task_LaunchLvlUpAnim(u8);
static void Task_PrepareToGiveExpWithExpBar(u8);
static void Task_SetControllerToWaitForString(u8);
static void Task_GiveExpWithExpBar(u8);
static void Task_UpdateLvlInHealthbox(u8);
static void PrintLinkStandbyMsg(void);

// Shadow Pokemon
static s32 GetTaskHeartValue(u8 taskId);
static void Task_LowerHeartValue(u8 taskId);
static void Task_PrepareToLowerHeartValWithBar(u8 taskId);
static void Task_LowerHeartValWithBar(u8 taskId);
static void Task_LaunchSectionUnlockAnim(u8 taskId);

static void ReloadMoveNames(u32 battler);
static u32 CheckTypeEffectiveness(u32 targetId, u32 battler);
static u32 CheckTargetTypeEffectiveness(u32 battler);
static void MoveSelectionDisplayMoveEffectiveness(u32 foeEffectiveness, u32 battler);

enum
{
    BALL_TARGET_NONE,
    BALL_TARGET_FROM_LAST_USED,
    BALL_TARGET_FROM_BAG,
};

static u8 sBallTargetMode[MAX_BATTLERS_COUNT];
static u16 sBallTargetItem[MAX_BATTLERS_COUNT];

static void (*const sPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = PlayerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = PlayerHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = PlayerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = PlayerHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = PlayerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = PlayerHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = PlayerHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = PlayerHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = PlayerHandlePause,
    [CONTROLLER_MOVEANIMATION]            = PlayerHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = PlayerHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = PlayerHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = PlayerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = PlayerHandleYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = PlayerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = PlayerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = PlayerHandleChoosePokemon,
    [CONTROLLER_23]                       = PlayerHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = PlayerHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_HandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = PlayerHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = PlayerHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = PlayerHandlePlayBGM,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = PlayerHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = PlayerHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = PlayerHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = PlayerHandleOneReturnValue_Duplicate,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = PlayerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = PlayerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = PlayerHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = PlayerHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = PlayerHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = PlayerHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = PlayerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = PlayerHandleBattleDebug,
    [CONTROLLER_HEARTVALUEUPDATE]         = PlayerHandleHeartValueUpdate,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToPlayer(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = PlayerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = PlayerBufferRunCommand;
    gDoingBattleAnim = FALSE;
    gPlayerDpadHoldFrames = 0;
}

static void PlayerBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = PlayerBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~(1u << battler);
    }
}

static void PlayerBufferRunCommand(u32 battler)
{
    if (gBattleControllerExecFlags & (1u << battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sPlayerBufferCommands))
            sPlayerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            PlayerBufferExecCompleted(battler);
    }
}

static void CompleteOnBattlerSpritePosX_0(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        PlayerBufferExecCompleted(battler);
}

static u16 GetPrevBall(u16 ballId)
{
    if (GetBugContestFlag())
        return ITEM_SPORT_BALL;

    u16 ballPrev;
    s32 i, j;
    CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);
    for (i = 0; i < gBagPockets[BALLS_POCKET].capacity; i++)
    {
        if (ballId == gBagPockets[BALLS_POCKET].itemSlots[i].itemId)
        {
            if (i <= 0)
            {
                for (j = gBagPockets[BALLS_POCKET].capacity - 1; j >= 0; j--)
                {
                    ballPrev = gBagPockets[BALLS_POCKET].itemSlots[j].itemId;
                    if (ballPrev != ITEM_NONE)
                        return ballPrev;
                }
            }
            i--;
            break;
        }
    }
    return gBagPockets[BALLS_POCKET].itemSlots[i].itemId;
}

static u32 GetNextBall(u32 ballId)
{
    if (GetBugContestFlag())
        return ITEM_SPORT_BALL;

    u32 ballNext = ITEM_NONE;
    s32 i;
    CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);
    for (i = 1; i < gBagPockets[BALLS_POCKET].capacity; i++)
    {
        if (ballId == gBagPockets[BALLS_POCKET].itemSlots[i-1].itemId)
        {
            ballNext = gBagPockets[BALLS_POCKET].itemSlots[i].itemId;
            break;
        }
    }
    if (ballNext == ITEM_NONE)
        return gBagPockets[BALLS_POCKET].itemSlots[0].itemId; // Zeroth slot
    else
        return ballNext;
}

extern const u8 BattleScript_PlayerCall[]; // defined below in step 3

static void HandleInputChooseAction(u32 battler)
{
    u16 itemId = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);

    DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
    DoBounceEffect(battler, BOUNCE_MON, 7, 1);

    if (JOY_REPEAT(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == TRUE)
    {
        if (!gLastUsedBallMenuPresent)
        {
            gBattleStruct->ackBallUseBtn = FALSE;
        }
        else if (JOY_NEW(B_LAST_USED_BALL_BUTTON))
        {
            gBattleStruct->ackBallUseBtn = TRUE;
            gBattleStruct->ballSwapped = FALSE;
            ArrowsChangeColorLastBallCycle(TRUE);
        }

        if (gBattleStruct->ackBallUseBtn)
        {
            if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_DOWN) || JOY_NEW(DPAD_RIGHT)))
            {
                bool32 sameBall = FALSE;
                u32 nextBall = GetNextBall(gBallToDisplay);
                gBattleStruct->ballSwapped = TRUE;
                if (gBallToDisplay == nextBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = nextBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_LEFT)))
            {
                bool32 sameBall = FALSE;
                u32 prevBall = GetPrevBall(gBallToDisplay);
                gBattleStruct->ballSwapped = TRUE;
                if (gBallToDisplay == prevBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = prevBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_NEW(B_BUTTON) || (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && gBattleStruct->ballSwapped))
            {
                gBattleStruct->ackBallUseBtn = FALSE;
                gBattleStruct->ballSwapped = FALSE;
                ArrowsChangeColorLastBallCycle(FALSE);
            }
            else if (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
            {
                gBattleStruct->ackBallUseBtn = FALSE;
                PlaySE(SE_SELECT);
                ArrowsChangeColorLastBallCycle(FALSE);
                if (ShouldSelectShadowBallTarget())
                {
                    StartBallTargetSelection(battler, BALL_TARGET_FROM_LAST_USED, ITEM_NONE);
                }
                else
                {
                    TryHideLastUsedBall();
                    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_THROW_BALL, 0);
                    PlayerBufferExecCompleted(battler);
                }
            }
            return;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();

        switch (gActionSelectionCursor[battler])
        {
        case 0: // Top left
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
            break;
        case 1: // Top right
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_ITEM, 0);
            break;
        case 2: // Bottom left
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
            break;
        case 3: // Bottom right
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_CALL, 0);  // NEW
            else
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_RUN, 0);
            break;
        }
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_CALL, 0);
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1) // if is B_ACTION_USE_ITEM or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[battler] & 1)) // if is B_ACTION_USE_MOVE or B_ACTION_SWITCH
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[battler] & 2) // if is B_ACTION_SWITCH or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[battler] & 2)) // if is B_ACTION_USE_MOVE or B_ACTION_USE_ITEM
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        if (IsDoubleBattle()
         && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT
         && !(gAbsentBattlerFlags & (1u << GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
         && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            // Return item to bag if partner had selected one (if consumable).
            if (gBattleResources->bufferA[battler][1] == B_ACTION_USE_ITEM && GetItemConsumability(itemId))
            {
                AddBagItem(itemId, 1);
            }
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_CANCEL_PARTNER, 0);
            PlayerBufferExecCompleted(battler);
        }
        else if (B_QUICK_MOVE_CURSOR_TO_RUN)
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER)) // If wild battle, pressing B moves cursor to "Run".
            {
                PlaySE(SE_SELECT);
                ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
                gActionSelectionCursor[battler] = 3;
                ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
            }
        }
    }
    else if (JOY_NEW(START_BUTTON))
    {
        SwapHpBarsWithHpText();
    }
    else if (DEBUG_BATTLE_MENU == TRUE && JOY_NEW(SELECT_BUTTON))
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_DEBUG, 0);
        PlayerBufferExecCompleted(battler);
    }
    else if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == FALSE
             && JOY_NEW(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
    {
        PlaySE(SE_SELECT);
        if (ShouldSelectShadowBallTarget())
        {
            StartBallTargetSelection(battler, BALL_TARGET_FROM_LAST_USED, ITEM_NONE);
        }
        else
        {
            TryHideLastUsedBall();
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_THROW_BALL, 0);
            PlayerBufferExecCompleted(battler);
        }
    }
}

void HandleInputChooseTarget(u32 battler)
{
    s32 i;
    static const u8 identities[MAX_BATTLERS_COUNT] = {B_POSITION_PLAYER_LEFT, B_POSITION_PLAYER_RIGHT, B_POSITION_OPPONENT_RIGHT, B_POSITION_OPPONENT_LEFT};
    u16 move = GetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + gMoveSelectionCursor[battler]);
    u16 moveTarget = GetBattlerMoveTargetType(battler, move);

    DoBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX, 15, 1);
    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gMultiUsePlayerCursor)
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
    }

    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
        TryHideLastUsedBall();
        HideGimmickTriggerSprite();
        DestroyMoveMenuIcons();
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_UP))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gMultiUsePlayerCursor ^= BIT_FLANK;
        }
        else
        {
            do
            {
                u8 currSelIdentity = GetBattlerPosition(gMultiUsePlayerCursor);

                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (--i < 0)
                        i = MAX_BATTLERS_COUNT - 1;
                    gMultiUsePlayerCursor = GetBattlerAtPosition(identities[i]);
                } while (gMultiUsePlayerCursor == gBattlersCount);

                i = 0;
                switch (GetBattlerPosition(gMultiUsePlayerCursor))
                {
                case B_POSITION_PLAYER_LEFT:
                case B_POSITION_PLAYER_RIGHT:
                    if (battler != gMultiUsePlayerCursor)
                        i++;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                case B_POSITION_OPPONENT_RIGHT:
                    i++;
                    break;
                }
                if (B_SHOW_EFFECTIVENESS)
                    MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(GetBattlerPosition(gMultiUsePlayerCursor), battler), battler);

                if (gAbsentBattlerFlags & (1u << gMultiUsePlayerCursor)
                 || !CanTargetBattler(battler, gMultiUsePlayerCursor, move)
                 || (moveTarget & MOVE_TARGET_OPPONENT && IsOnPlayerSide(gMultiUsePlayerCursor)))
                    i = 0;
            } while (i == 0);
        }
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
    }
    else if (JOY_NEW(DPAD_RIGHT | DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gMultiUsePlayerCursor ^= BIT_FLANK;
        }
        else
        {
            do
            {
                u8 currSelIdentity = GetBattlerPosition(gMultiUsePlayerCursor);

                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (++i > 3)
                        i = 0;
                    gMultiUsePlayerCursor = GetBattlerAtPosition(identities[i]);
                } while (gMultiUsePlayerCursor == gBattlersCount);

                i = 0;
                switch (GetBattlerPosition(gMultiUsePlayerCursor))
                {
                case B_POSITION_PLAYER_LEFT:
                case B_POSITION_PLAYER_RIGHT:
                    if (battler != gMultiUsePlayerCursor)
                        i++;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                case B_POSITION_OPPONENT_RIGHT:
                    i++;
                    break;
                }
                if (B_SHOW_EFFECTIVENESS)
                    MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(GetBattlerPosition(gMultiUsePlayerCursor), battler), battler);

                if (gAbsentBattlerFlags & (1u << gMultiUsePlayerCursor)
                 || !CanTargetBattler(battler, gMultiUsePlayerCursor, move)
                 || (moveTarget & MOVE_TARGET_OPPONENT && IsOnPlayerSide(gMultiUsePlayerCursor)))
                    i = 0;
            } while (i == 0);
        }

        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
    }
}

static bool8 IsOpponentShadowBattler(u8 battler)
{
    if (GetBattlerSide(battler) != B_SIDE_OPPONENT || !IsBattlerAlive(battler))
        return FALSE;

    if (gBattleMons[battler].isShadow)
        return TRUE;

    return GetMonData(GetBattlerMon(battler), MON_DATA_IS_SHADOW);
}

static bool8 ShouldSelectShadowBallTarget(void)
{
    u8 left, right;
    u8 count = 0;

    if (!IsDoubleBattle())
        return FALSE;
    if (!(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FRONTIER)))
        return FALSE;

    left = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    right = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

    if (IsOpponentShadowBattler(left))
        count++;
    if (IsOpponentShadowBattler(right))
        count++;

    return (count > 1);
}

static u8 GetOtherShadowOpponent(u8 battler)
{
    u8 left = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    u8 right = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

    if (battler == left && IsOpponentShadowBattler(right))
        return right;
    if (battler == right && IsOpponentShadowBattler(left))
        return left;

    return battler;
}

static void StartBallTargetSelection(u32 battler, u8 mode, u16 itemId)
{
    u8 left = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    u8 right = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

    sBallTargetMode[battler] = mode;
    sBallTargetItem[battler] = itemId;

    if (IsOpponentShadowBattler(left))
        gMultiUsePlayerCursor = left;
    else
        gMultiUsePlayerCursor = right;

    gPlayerDpadHoldFrames = 0;
    gBattlerControllerFuncs[battler] = HandleInputChooseBallTarget;
    gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
    DoBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX, 15, 1);
    TryHideLastUsedBall();
}

static void HandleInputChooseBallTarget(u32 battler)
{
    s32 i;

    DoBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX, 15, 1);
    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gMultiUsePlayerCursor)
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
    }

    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);

        gBattleStruct->ballThrowTarget = gMultiUsePlayerCursor;
        if (sBallTargetMode[battler] == BALL_TARGET_FROM_BAG)
            BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, sBallTargetItem[battler]);
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_THROW_BALL, 0);

        sBallTargetMode[battler] = BALL_TARGET_NONE;
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
        sBallTargetMode[battler] = BALL_TARGET_NONE;
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT | DPAD_UP | DPAD_DOWN))
    {
        u8 next = GetOtherShadowOpponent(gMultiUsePlayerCursor);
        if (next != gMultiUsePlayerCursor)
        {
            PlaySE(SE_SELECT);
            gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
            gMultiUsePlayerCursor = next;
            gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
            DoBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX, 15, 1);
        }
    }
}

static void HideAllTargets(void)
{
    s32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

static void HideShownTargets(u32 battler)
{
    s32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing && i != battler)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

void HandleInputShowEntireFieldTargets(u32 battler)
{
    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        HideGimmickTriggerSprite();
        DestroyMoveMenuIcons();
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

void HandleInputShowTargets(u32 battler)
{
    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        HideGimmickTriggerSprite();
        TryHideLastUsedBall();
        DestroyMoveMenuIcons();
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

static void TryShowAsTarget(u32 battler)
{
    if (IsBattlerAlive(battler))
    {
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 15, 1);
        gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_ShowAsMoveTarget;
    }
}

void HandleInputChooseMove(u32 battler)
{
    u16 moveTarget;
    u32 canSelectTarget = 0;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

    if (sMoveTypePaletteRefreshBattler == battler)
    {
        MoveSelectionDisplayMoveType(battler);
        RefreshCategoryIconPalette();
        sMoveTypePaletteRefreshBattler = 0xFF;
    }
    if (sMoveTypePaletteRefreshFrames != 0)
    {
        MoveSelectionDisplayMoveType(battler);
        RefreshCategoryIconPalette();
        sMoveTypePaletteRefreshFrames--;
    }

    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON) && !gBattleStruct->descriptionSubmenu)
    {
        TryToHideMoveInfoWindow();
        PlaySE(SE_SELECT);

        moveTarget = GetBattlerMoveTargetType(battler, moveInfo->moves[gMoveSelectionCursor[battler]]);

        if (gBattleStruct->zmove.viewing)
        {
            gBattleStruct->zmove.viewing = FALSE;
            if (GetMoveCategory(moveInfo->moves[gMoveSelectionCursor[battler]]) != DAMAGE_CATEGORY_STATUS)
                moveTarget = MOVE_TARGET_SELECTED;  //damaging z moves always have selected target
        }

        // Status moves turn into Max Guard when Dynamaxed, targets user.
        if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX))
            moveTarget = GetMoveTarget(GetMaxMove(battler, moveInfo->moves[gMoveSelectionCursor[battler]]));

        if (moveTarget & MOVE_TARGET_USER)
            gMultiUsePlayerCursor = battler;
        else
            gMultiUsePlayerCursor = GetOpposingSideBattler(battler);

        if (gBattleResources->bufferA[battler][1]) // a double battle
        {
            if (!(moveTarget & (MOVE_TARGET_RANDOM | MOVE_TARGET_BOTH | MOVE_TARGET_DEPENDS | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_USER | MOVE_TARGET_ALLY)))
                canSelectTarget = 1; // either selected or user
            if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY) && IsBattlerAlive(BATTLE_PARTNER(battler)))
                canSelectTarget = 1;

            if (moveInfo->currentPp[gMoveSelectionCursor[battler]] == 0)
            {
                canSelectTarget = 0;
            }
            else if (!(moveTarget & MOVE_TARGET_USER) && CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, battler) <= 1)
            {
                gMultiUsePlayerCursor = GetDefaultMoveTarget(battler);
                canSelectTarget = 0;
            }

            if (B_SHOW_TARGETS == TRUE)
            {
                // Show all available targets for multi-target moves
                if ((moveTarget & MOVE_TARGET_ALL_BATTLERS) == MOVE_TARGET_ALL_BATTLERS)
                {
                    u32 i = 0;
                    for (i = 0; i < gBattlersCount; i++)
                        TryShowAsTarget(i);

                    canSelectTarget = 3;
                }
                else if (moveTarget & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
                {
                    TryShowAsTarget(gMultiUsePlayerCursor);
                    TryShowAsTarget(BATTLE_PARTNER(gMultiUsePlayerCursor));
                    if (moveTarget & MOVE_TARGET_FOES_AND_ALLY)
                        TryShowAsTarget(BATTLE_PARTNER(battler));
                    canSelectTarget = 2;
                }
            }
        }

        switch (canSelectTarget)
        {
        case 0:
        default:
            if (gBattleStruct->gimmick.playerSelect)
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
            else
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
            HideGimmickTriggerSprite();
            TryHideLastUsedBall();
            DestroyMoveMenuIcons();
            PlayerBufferExecCompleted(battler);
            break;
        case 1:
            gBattlerControllerFuncs[battler] = HandleInputChooseTarget;

            if (moveTarget & MOVE_TARGET_USER)
                gMultiUsePlayerCursor = battler;
            else if (gAbsentBattlerFlags & (1u << GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)))
                gMultiUsePlayerCursor = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            else
                gMultiUsePlayerCursor = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(GetBattlerPosition(gMultiUsePlayerCursor), battler), battler);

            gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
            break;
        case 2:
            gBattlerControllerFuncs[battler] = HandleInputShowTargets;
            break;
        case 3: // Entire field
            gBattlerControllerFuncs[battler] = HandleInputShowEntireFieldTargets;
            break;
        }
    }
    else if ((JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)  && !gBattleStruct->descriptionSubmenu)
    {
        PlaySE(SE_SELECT);
        gBattleStruct->gimmick.playerSelect = FALSE;
        if (gBattleStruct->zmove.viewing)
        {
            ReloadMoveNames(battler);
            ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, gBattleStruct->gimmick.playerSelect);
        }
        else
        {
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, 0xFFFF);
            HideGimmickTriggerSprite();
            DestroyMoveMenuIcons();
            PlayerBufferExecCompleted(battler);
            TryToHideMoveInfoWindow();
        }
    }
    else if (JOY_NEW(DPAD_LEFT) && !gBattleStruct->zmove.viewing)
    {
        if (gMoveSelectionCursor[battler] & 1)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT) && !gBattleStruct->zmove.viewing)
    {
        if (!(gMoveSelectionCursor[battler] & 1)
         && (gMoveSelectionCursor[battler] ^ 1) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }
    }
    else if (JOY_NEW(DPAD_UP) && !gBattleStruct->zmove.viewing)
    {
        if (gMoveSelectionCursor[battler] & 2)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }
    }
    else if (JOY_NEW(DPAD_DOWN) && !gBattleStruct->zmove.viewing)
    {
        if (!(gMoveSelectionCursor[battler] & 2)
         && (gMoveSelectionCursor[battler] ^ 2) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }
    }
    else if (B_MOVE_REARRANGEMENT_IN_BATTLE < GEN_4 && JOY_NEW(SELECT_BUTTON) && !gBattleStruct->zmove.viewing && !gBattleStruct->descriptionSubmenu)
    {
        if (gNumberOfMovesToChoose > 1 && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
        {
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);

            if (gMoveSelectionCursor[battler] != 0)
                gMultiUsePlayerCursor = 0;
            else
                gMultiUsePlayerCursor = gMoveSelectionCursor[battler] + 1;

            MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
            BattlePutTextOnWindow(gText_BattleSwitchWhich, B_WIN_SWITCH_PROMPT);
            gBattlerControllerFuncs[battler] = HandleMoveSwitching;
        }
    }
    else if (gBattleStruct->descriptionSubmenu)
    {
        if (JOY_NEW(B_MOVE_DESCRIPTION_BUTTON) || JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            gBattleStruct->descriptionSubmenu = FALSE;
            if (gCategoryIconSpriteId != 0xFF)
            {
                DestroySprite(&gSprites[gCategoryIconSpriteId]);
                gCategoryIconSpriteId = 0xFF;
            }

            FillWindowPixelBuffer(B_WIN_MOVE_DESCRIPTION, PIXEL_FILL(0));
            ClearStdWindowAndFrame(B_WIN_MOVE_DESCRIPTION, FALSE);
            CopyWindowToVram(B_WIN_MOVE_DESCRIPTION, COPYWIN_GFX);
            PlaySE(SE_SELECT);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
    else if (JOY_NEW(B_MOVE_DESCRIPTION_BUTTON))
    {
        gBattleStruct->descriptionSubmenu = TRUE;
        TryMoveSelectionDisplayMoveDescription(battler);
    }
    else if (JOY_NEW(START_BUTTON))
    {
        if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_NONE && !HasTrainerUsedGimmick(battler, gBattleStruct->gimmick.usableGimmick[battler]))
        {
            gBattleStruct->gimmick.playerSelect ^= 1;
            ReloadMoveNames(battler);
            ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, gBattleStruct->gimmick.playerSelect);
            PlaySE(SE_SELECT);
        }
    }
}

static void ReloadMoveNames(u32 battler)
{
    if (gBattleStruct->zmove.viable && !gBattleStruct->zmove.viewing)
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
        MoveSelectionDisplayZMove(GetUsableZMove(battler, moveInfo->moves[gMoveSelectionCursor[battler]]), battler);
    }
    else
    {
        gBattleStruct->zmove.viewing = FALSE;
        MoveSelectionDestroyCursorAt(battler);
        MoveSelectionDisplayMoveNames(battler);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
    }
}

static u32 UNUSED HandleMoveInputUnused(u32 battler)
{
    u32 var = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        var = 1;
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT * 2;
        var = 0xFF;
    }
    if (JOY_NEW(DPAD_LEFT) && gMoveSelectionCursor[battler] & 1)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
        gMoveSelectionCursor[battler] ^= 1;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    }
    if (JOY_NEW(DPAD_RIGHT) && !(gMoveSelectionCursor[battler] & 1)
        && (gMoveSelectionCursor[battler] ^ 1) < gNumberOfMovesToChoose)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
        gMoveSelectionCursor[battler] ^= 1;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    }
    if (JOY_NEW(DPAD_UP) && gMoveSelectionCursor[battler] & 2)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
        gMoveSelectionCursor[battler] ^= 2;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    }
    if (JOY_NEW(DPAD_DOWN) && !(gMoveSelectionCursor[battler] & 2)
        && (gMoveSelectionCursor[battler] ^ 2) < gNumberOfMovesToChoose)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
        gMoveSelectionCursor[battler] ^= 2;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    }

    return var;
}

void HandleMoveSwitching(u32 battler)
{
    u8 perMovePPBonuses[MAX_MON_MOVES];
    struct ChooseMoveStruct moveStruct;
    u8 totalPPBonuses;

    if (JOY_NEW(A_BUTTON | SELECT_BUTTON))
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
        PlaySE(SE_SELECT);

        if (gMoveSelectionCursor[battler] != gMultiUsePlayerCursor)
        {
            struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
            s32 i;

            // swap moves and pp
            i = moveInfo->moves[gMoveSelectionCursor[battler]];
            moveInfo->moves[gMoveSelectionCursor[battler]] = moveInfo->moves[gMultiUsePlayerCursor];
            moveInfo->moves[gMultiUsePlayerCursor] = i;

            i = moveInfo->currentPp[gMoveSelectionCursor[battler]];
            moveInfo->currentPp[gMoveSelectionCursor[battler]] = moveInfo->currentPp[gMultiUsePlayerCursor];
            moveInfo->currentPp[gMultiUsePlayerCursor] = i;

            i = moveInfo->maxPp[gMoveSelectionCursor[battler]];
            moveInfo->maxPp[gMoveSelectionCursor[battler]] = moveInfo->maxPp[gMultiUsePlayerCursor];
            moveInfo->maxPp[gMultiUsePlayerCursor] = i;

            if (gDisableStructs[battler].mimickedMoves & (1u << gMoveSelectionCursor[battler]))
            {
                gDisableStructs[battler].mimickedMoves &= ~(1u << gMoveSelectionCursor[battler]);
                gDisableStructs[battler].mimickedMoves |= 1u << gMultiUsePlayerCursor;
            }

            MoveSelectionDisplayMoveNames(battler);

            for (i = 0; i < MAX_MON_MOVES; i++)
                perMovePPBonuses[i] = (gBattleMons[battler].ppBonuses & (3 << (i * 2))) >> (i * 2);

            totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[battler]];
            perMovePPBonuses[gMoveSelectionCursor[battler]] = perMovePPBonuses[gMultiUsePlayerCursor];
            perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

            totalPPBonuses = 0;
            for (i = 0; i < MAX_MON_MOVES; i++)
                totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

            gBattleMons[battler].ppBonuses = totalPPBonuses;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                gBattleMons[battler].moves[i] = moveInfo->moves[i];
                gBattleMons[battler].pp[i] = moveInfo->currentPp[i];
            }

            if (!(gBattleMons[battler].status2 & STATUS2_TRANSFORMED))
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    moveStruct.moves[i] = GetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + i);
                    moveStruct.currentPp[i] = GetMonData(GetBattlerMon(battler), MON_DATA_PP1 + i);
                }

                totalPPBonuses = GetMonData(GetBattlerMon(battler), MON_DATA_PP_BONUSES);
                for (i = 0; i < MAX_MON_MOVES; i++)
                    perMovePPBonuses[i] = (totalPPBonuses & (3 << (i * 2))) >> (i * 2);

                i = moveStruct.moves[gMoveSelectionCursor[battler]];
                moveStruct.moves[gMoveSelectionCursor[battler]] = moveStruct.moves[gMultiUsePlayerCursor];
                moveStruct.moves[gMultiUsePlayerCursor] = i;

                i = moveStruct.currentPp[gMoveSelectionCursor[battler]];
                moveStruct.currentPp[gMoveSelectionCursor[battler]] = moveStruct.currentPp[gMultiUsePlayerCursor];
                moveStruct.currentPp[gMultiUsePlayerCursor] = i;

                totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[battler]];
                perMovePPBonuses[gMoveSelectionCursor[battler]] = perMovePPBonuses[gMultiUsePlayerCursor];
                perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

                totalPPBonuses = 0;
                for (i = 0; i < MAX_MON_MOVES; i++)
                    totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    SetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + i, &moveStruct.moves[i]);
                    SetMonData(GetBattlerMon(battler), MON_DATA_PP1 + i, &moveStruct.currentPp[i]);
                }

                SetMonData(GetBattlerMon(battler), MON_DATA_PP_BONUSES, &totalPPBonuses);
            }
        }

        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        gMoveSelectionCursor[battler] = gMultiUsePlayerCursor;
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        else
            MoveSelectionDisplayPpString(battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
        AssignUsableZMoves(battler, moveInfo->moves);
    }
    else if (JOY_NEW(B_BUTTON | SELECT_BUTTON))
    {
        PlaySE(SE_SELECT);
        MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        else
            MoveSelectionDisplayPpString(battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gMultiUsePlayerCursor & 1)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gMultiUsePlayerCursor & 1) && (gMultiUsePlayerCursor ^ 1) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gMultiUsePlayerCursor & 2)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gMultiUsePlayerCursor & 2) && (gMultiUsePlayerCursor ^ 2) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
}

static void SetLinkBattleEndCallbacks(u32 battler)
{
    if (gWirelessCommType == 0)
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(CB2_InitEndLinkBattle);
            if (gBattleOutcome == B_OUTCOME_WON)
                TryPutLinkBattleTvShowOnAir();
            FreeAllWindowBuffers();
        }
    }
    else
    {
        if (IsLinkTaskFinished())
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(CB2_InitEndLinkBattle);
            if (gBattleOutcome == B_OUTCOME_WON)
                TryPutLinkBattleTvShowOnAir();
            FreeAllWindowBuffers();
        }
    }
}

// Despite handling link battles separately, this is only ever used by link battles
void SetBattleEndCallbacks(u32 battler)
{
    if (!gPaletteFade.active)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (IsLinkTaskFinished())
            {
                if (gWirelessCommType == 0)
                    SetCloseLinkCallback();
                else
                    SetLinkStandbyCallback();

                gBattlerControllerFuncs[battler] = SetLinkBattleEndCallbacks;
            }
        }
        else
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(gMain.savedCallback);
        }
    }
}

static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        PlayerBufferExecCompleted(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool8 healthboxAnimDone = FALSE;

    // Check if healthbox has finished sliding in
    if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
         && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }

    // If healthbox and shiny anim are done
    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
    {
        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        HandleLowHpMusicChange(GetBattlerMon(battler), battler);

        if (TwoPlayerIntroMons(battler))
            HandleLowHpMusicChange(GetBattlerMon(BATTLE_PARTNER(battler)), BATTLE_PARTNER(battler));

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;

    // Start shiny animation if applicable for 1st Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    // Start shiny animation if applicable for 2nd Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
        TryShinyAnimation(BATTLE_PARTNER(battler), GetBattlerMon(BATTLE_PARTNER(battler)));

    // Show healthbox after ball anim
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], GetBattlerMon(BATTLE_PARTNER(battler)), HEALTHBOX_ALL);
                ShadowHud_Clear(BATTLE_PARTNER(battler));
                ShadowHud_SyncForBattler(BATTLE_PARTNER(battler));
                StartHealthboxSlideIn(BATTLE_PARTNER(battler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
            ShadowHud_Clear(battler);
            ShadowHud_SyncForBattler(battler);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    // Restore bgm after cry has played and healthbox anim is started
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                m4aMPlayContinue(&gMPlayInfo_BGM);
            else
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    // Wait for battler anims
    if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }
    else
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }

    // Clean up
    if (bgmRestored && battlerAnimsDone)
    {
        if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
        DestroySprite(&gSprites[gBattleControllerData[battler]]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void SwitchIn_CleanShinyAnimShowSubstitute(u32 battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(battler);

        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        // Check if Substitute should be shown
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[battler] = SwitchIn_HandleSoundAndEnd;
    }
}

static void SwitchIn_HandleSoundAndEnd(u32 battler)
{
    if (SwitchIn_HandleSoundAndEndUtil(battler))
    {
        HandleLowHpMusicChange(GetBattlerMon(battler), battler);
        PlayerBufferExecCompleted(battler);
    }
}

static void SwitchIn_TryShinyAnimShowHealthbox(u32 battler)
{
    if (SwitchIn_TryShinyAnimUtil(battler))
    {
        u32 partner = BATTLE_PARTNER(battler);

        if (GetBattlerCoordsIndex(battler) == BATTLE_COORDS_SINGLES)
            ShdwLoadHealthboxSprite();
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
        if (IsDoubleBattle() && IsBattlerAlive(partner) && gHealthboxSpriteIds[partner] < MAX_SPRITES)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[partner], GetBattlerMon(partner), HEALTHBOX_ALL);
        ShadowHud_Clear(battler);
        ShadowHud_SyncForBattler(battler);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        gBattlerControllerFuncs[battler] = SwitchIn_CleanShinyAnimShowSubstitute;
    }
}

void Task_PlayerController_RestoreBgmAfterCry(u8 taskId)
{
    if (!IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        DestroyTask(taskId);
    }
}

#define tExpTask_monId          data[0]
#define tExpTask_battler        data[2]
#define tExpTask_gainedExp_1    data[3]
#define tExpTask_gainedExp_2    data[4] // Stored as two half-words containing a word.
#define tExpTask_frames         data[10]

static void DynamaxModifyHPLevelUp(struct Pokemon *mon, u32 battler, u32 oldMaxHP)
{
    ApplyDynamaxHPMultiplier(mon);
    gBattleScripting.levelUpHP = GetMonData(mon, MON_DATA_MAX_HP) - oldMaxHP; // overwrite levelUpHP since it overflows
    gBattleMons[battler].hp += gBattleScripting.levelUpHP;
    SetMonData(mon, MON_DATA_HP, &gBattleMons[battler].hp);
}

static s32 GetTaskExpValue(u8 taskId)
{
    return (u16)(gTasks[taskId].tExpTask_gainedExp_1) | (gTasks[taskId].tExpTask_gainedExp_2 << 16);
}

static void Task_GiveExpToMon(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].tExpTask_monId);
    u8 battler = gTasks[taskId].tExpTask_battler;
    s32 gainedExp = GetTaskExpValue(taskId);
    if ((GetBattlerCoordsIndex(battler) == BATTLE_COORDS_DOUBLES || monId != gBattlerPartyIndexes[battler])
        || (monId == gBattlerPartyIndexes[battler] && GetMonData(&gPlayerParty[monId], MON_DATA_IS_SHADOW))) // Give exp without moving the expbar.
    {
        struct Pokemon *mon = &gPlayerParty[monId];
        u16 species = GetMonData(mon, MON_DATA_SPECIES);
        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        u32 currExp = GetMonData(mon, MON_DATA_EXP);
        u32 nextLvlExp = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1];
        u32 expAfterGain = currExp + gainedExp;
        u32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP);

        if (expAfterGain >= nextLvlExp && !GetMonData(mon, MON_DATA_IS_SHADOW))
        {
            SetMonData(mon, MON_DATA_EXP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? &expAfterGain : &nextLvlExp);

            CalculateMonStats(mon);

            // Reapply Dynamax HP multiplier after stats are recalculated.
            if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && monId == gBattlerPartyIndexes[battler])
                DynamaxModifyHPLevelUp(mon, battler, oldMaxHP);

            gainedExp -= nextLvlExp - currExp;
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? 0 : gainedExp);

            if (IsDoubleBattle() == TRUE
             && (monId == gBattlerPartyIndexes[battler] || monId == gBattlerPartyIndexes[BATTLE_PARTNER(battler)]))
                gTasks[taskId].func = Task_LaunchLvlUpAnim;
            else
                gTasks[taskId].func = Task_SetControllerToWaitForString;
        }
        else
        {
            currExp += gainedExp;
            SetMonData(mon, MON_DATA_EXP, &currExp);
            gBattlerControllerFuncs[battler] = Controller_WaitForString;
            DestroyTask(taskId);
        }
    }
    else
    {
        gTasks[taskId].func = Task_PrepareToGiveExpWithExpBar;
    }
}

static void Task_PrepareToGiveExpWithExpBar(u8 taskId)
{
    u8 monIndex = gTasks[taskId].tExpTask_monId;
    s32 gainedExp = GetTaskExpValue(taskId);
    u8 battler = gTasks[taskId].tExpTask_battler;
    struct Pokemon *mon = &gPlayerParty[monIndex];
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 exp = GetMonData(mon, MON_DATA_EXP);
    u32 currLvlExp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
    u32 expToNextLvl;

    exp -= currLvlExp;
    expToNextLvl = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - currLvlExp;
    SetBattleBarStruct(battler, gHealthboxSpriteIds[battler], expToNextLvl, exp, -gainedExp);
    TestRunner_Battle_RecordExp(battler, exp, -gainedExp);
    PlaySE(SE_EXP);
    gTasks[taskId].func = Task_GiveExpWithExpBar;
}

static void Task_GiveExpWithExpBar(u8 taskId)
{
    u32 level, expAfterGain;
    u16 species;
    u32 oldMaxHP;
    s32 currExp, expOnNextLvl, newExpPoints;

    if (gTasks[taskId].tExpTask_frames < 13)
    {
        gTasks[taskId].tExpTask_frames++;
    }
    else
    {
        u8 monId = gTasks[taskId].tExpTask_monId;
        s32 gainedExp = GetTaskExpValue(taskId);
        u8 battler = gTasks[taskId].tExpTask_battler;
        struct Pokemon *mon = &gPlayerParty[monId];

        newExpPoints = MoveBattleBar(battler, gHealthboxSpriteIds[battler], EXP_BAR, 0);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        if (newExpPoints == -1) // The bar has been filled with given exp points.
        {
            m4aSongNumStop(SE_EXP);
            level = GetMonData(mon, MON_DATA_LEVEL);
            currExp = GetMonData(mon, MON_DATA_EXP);
            species = GetMonData(mon, MON_DATA_SPECIES);
            oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP);
            expOnNextLvl = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1];

            expAfterGain = currExp + gainedExp;
            if (expAfterGain >= expOnNextLvl && !GetMonData(&gPlayerParty[monId], MON_DATA_IS_SHADOW))
            {
                if (B_LEVEL_UP_NOTIFICATION >= GEN_9)
                    SetMonData(mon, MON_DATA_EXP, &expAfterGain);
                else
                    SetMonData(mon, MON_DATA_EXP, &expOnNextLvl);

                CalculateMonStats(mon);

                // Reapply Dynamax HP multiplier after stats are recalculated.
                if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && monId == gBattlerPartyIndexes[battler])
                    DynamaxModifyHPLevelUp(mon, battler, oldMaxHP);

                gainedExp -= expOnNextLvl - currExp;
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? 0 : gainedExp);
                gTasks[taskId].func = Task_LaunchLvlUpAnim;
            }
            else
            {
                currExp += gainedExp;
                SetMonData(mon, MON_DATA_EXP, &currExp);
                gBattlerControllerFuncs[battler] = Controller_WaitForString;
                DestroyTask(taskId);
            }
        }
    }
}

static void Task_LaunchLvlUpAnim(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    u8 monIndex = gTasks[taskId].tExpTask_monId;

    if (IsDoubleBattle() == TRUE && monIndex == gBattlerPartyIndexes[BATTLE_PARTNER(battler)])
        battler ^= BIT_FLANK;

    InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_LVL_UP);
    gTasks[taskId].func = Task_UpdateLvlInHealthbox;
}

static void Task_UpdateLvlInHealthbox(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
    {
        u8 monIndex = gTasks[taskId].tExpTask_monId;

        if (IsDoubleBattle() == TRUE && monIndex == gBattlerPartyIndexes[BATTLE_PARTNER(battler)])
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gPlayerParty[monIndex], HEALTHBOX_ALL);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[monIndex], HEALTHBOX_ALL);

        gTasks[taskId].func = Task_SetControllerToWaitForString;
    }
}

static void Task_SetControllerToWaitForString(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    gBattlerControllerFuncs[battler] = Controller_WaitForString;
    DestroyTask(taskId);
}

static void OpenPartyMenuToChooseMon(u32 battler)
{
    if (!gPaletteFade.active)
    {
        u8 caseId;

        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        caseId = gTasks[gBattleControllerData[battler]].data[0];
        DestroyTask(gBattleControllerData[battler]);
        FreeAllWindowBuffers();
        OpenPartyMenuInBattle(caseId);
    }
}

static void WaitForMonSelection(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gPartyMenuUseExitCallback == TRUE)
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, PARTY_SIZE, NULL);

        if ((gBattleResources->bufferA[battler][1] & 0xF) == 1)
            PrintLinkStandbyMsg();

        PlayerBufferExecCompleted(battler);
    }
}

static void OpenBagAndChooseItem(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChoseItem;
        ReshowBattleScreenDummy();
        FreeAllWindowBuffers();
        CB2_BagMenuFromBattle();
    }
}

static void CompleteWhenChoseItem(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gSpecialVar_ItemId != ITEM_NONE
            && GetItemPocket(gSpecialVar_ItemId) == POCKET_POKE_BALLS
            && ShouldSelectShadowBallTarget())
        {
            StartBallTargetSelection(battler, BALL_TARGET_FROM_BAG, gSpecialVar_ItemId);
            return;
        }
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        PlayerBufferExecCompleted(battler);
    }
}

static void PlayerHandleYesNoInput(u32 battler)
{
    if (JOY_NEW(DPAD_UP) && gMultiUsePlayerCursor != 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 0;
        BattleCreateYesNoCursorAt(0);
    }
    if (JOY_NEW(DPAD_DOWN) && gMultiUsePlayerCursor == 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
    }
    if (JOY_NEW(A_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);

        if (gMultiUsePlayerCursor != 0)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 0xE, 0);
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 0xD, 0);

        PlayerBufferExecCompleted(battler);
    }
    if (JOY_NEW(B_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);
        PlayerBufferExecCompleted(battler);
    }
}

static void MoveSelectionDisplayMoveNames(u32 battler)
{
    s32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    gNumberOfMovesToChoose = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = moveInfo->moves[i];
        u32 displayMove = move;
        if (IsGimmickSelected(battler, GIMMICK_DYNAMAX) || GetActiveGimmick(battler) == GIMMICK_DYNAMAX)
            displayMove = GetMaxMove(battler, move);

        StringCopy(gDisplayedStringBattle, GetMoveName(displayMove));
        // Prints on windows B_WIN_MOVE_NAME_1, B_WIN_MOVE_NAME_2, B_WIN_MOVE_NAME_3, B_WIN_MOVE_NAME_4
        BattlePutTextOnWindow(gDisplayedStringBattle, i + B_WIN_MOVE_NAME_1);

        if (move != MOVE_NONE)
            gNumberOfMovesToChoose++;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
        MoveSelectionDestroyCursorAt(i);
}

static void MoveSelectionDisplayPpString(u32 battler)
{
    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_PP);
    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_PP_REMAINING);
}

static void MoveSelectionDisplayPpNumber(u32 battler)
{
    u8 *txtPtr;
    struct ChooseMoveStruct *moveInfo;

    if (gBattleResources->bufferA[battler][2] == TRUE) // check if we didn't want to display pp number
        return;

    SetPpNumbersPaletteInMoveSelection(battler);
    moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, moveInfo->currentPp[gMoveSelectionCursor[battler]], STR_CONV_MODE_RIGHT_ALIGN, 2);
    *(txtPtr)++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, moveInfo->maxPp[gMoveSelectionCursor[battler]], STR_CONV_MODE_RIGHT_ALIGN, 2);

    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP);
}

static void MoveSelectionDisplayMoveType(u32 battler)
{
    u32 speciesId = gBattleMons[battler].species;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u32 move = moveInfo->moves[gMoveSelectionCursor[battler]];
    u32 type = GetMoveType(move);
    enum BattleMoveEffects effect = GetMoveEffect(move);
    u32 category = GetBattleMoveCategory(move);

    if (move == MOVE_NONE)
    {
        BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MOVE_TYPE);
        if (gMoveTypeIconSpriteId != 0xFF)
            gSprites[gMoveTypeIconSpriteId].invisible = TRUE;
        if (gCategoryIconSpriteId != 0xFF)
            gSprites[gCategoryIconSpriteId].invisible = TRUE;
        return;
    }

    if (effect == EFFECT_TERA_BLAST)
    {
        if (IsGimmickSelected(battler, GIMMICK_TERA) || GetActiveGimmick(battler) == GIMMICK_TERA)
            type = GetBattlerTeraType(battler);
    }
    else if (effect == EFFECT_IVY_CUDGEL)
    {
        if (speciesId == SPECIES_OGERPON_WELLSPRING || speciesId == SPECIES_OGERPON_WELLSPRING_TERA
         || speciesId == SPECIES_OGERPON_HEARTHFLAME || speciesId == SPECIES_OGERPON_HEARTHFLAME_TERA
         || speciesId == SPECIES_OGERPON_CORNERSTONE || speciesId == SPECIES_OGERPON_CORNERSTONE_TERA)
            type = gSpeciesInfo[speciesId].types[1];
    }
    else if (GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS
             && (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX)))
    {
        type = TYPE_NORMAL; // Max Guard is always a Normal-type move
    }
    else if (effect == EFFECT_TERA_STARSTORM)
    {
        if (speciesId == SPECIES_TERAPAGOS_STELLAR
        || (IsGimmickSelected(battler, GIMMICK_TERA) && speciesId == SPECIES_TERAPAGOS_TERASTAL))
            type = TYPE_STELLAR;
    }
    else if (P_SHOW_DYNAMIC_TYPES) // Non-vanilla changes to battle UI showing dynamic types
    {
        struct Pokemon *mon = GetBattlerMon(battler);
        type = CheckDynamicMoveType(mon, move, battler, MON_IN_BATTLE);
    }
    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MOVE_TYPE);

    {
        s32 typeBaseX = gWindows[B_WIN_MOVE_TYPE].window.tilemapLeft * TILE_WIDTH - gBattle_BG0_X;
        s32 typeBaseY = gWindows[B_WIN_MOVE_TYPE].window.tilemapTop * TILE_HEIGHT - gBattle_BG0_Y;
        s32 catBaseX = typeBaseX + WindowWidthPx(B_WIN_MOVE_TYPE) - 16;
        s32 catBaseY = typeBaseY;

        if (LoadMoveTypeIconTiles(type))
        {
            if (gMoveTypeIconSpriteId == 0xFF)
            {
                gMoveTypeIconSpriteId = CreateSprite(&sSpriteTemplate_MoveTypeIcon, typeBaseX + 16, typeBaseY + 8, 1);
                if (gMoveTypeIconSpriteId == MAX_SPRITES)
                {
                    gMoveTypeIconSpriteId = 0xFF;
                    return;
                }

                gSprites[gMoveTypeIconSpriteId].invisible = TRUE;
                gSprites[gMoveTypeIconSpriteId].data[0] = 0;
                gSprites[gMoveTypeIconSpriteId].callback = SpriteCB_ShowMoveMenuIconNextFrame;
            }

            StartSpriteAnim(&gSprites[gMoveTypeIconSpriteId], 0);
            {
                u8 palNum = GetMoveTypeIconPaletteNum(type);
                if (palNum != 0xFF)
                    gSprites[gMoveTypeIconSpriteId].oam.paletteNum = palNum;
            }
            gSprites[gMoveTypeIconSpriteId].oam.priority = 0;
            gSprites[gMoveTypeIconSpriteId].x = typeBaseX + 16;
            gSprites[gMoveTypeIconSpriteId].y = typeBaseY + 8;
            if (gSprites[gMoveTypeIconSpriteId].callback == SpriteCallbackDummy)
                gSprites[gMoveTypeIconSpriteId].invisible = FALSE;
        }
        else if (gMoveTypeIconSpriteId != 0xFF)
        {
            gSprites[gMoveTypeIconSpriteId].invisible = TRUE;
        }

        if (gCategoryIconSpriteId == 0xFF)
        {
            CategoryIcons_LoadSpritesGfx();
            gCategoryIconSpriteId = CreateSprite(&gSpriteTemplate_CategoryIcons, catBaseX + 8, catBaseY + 8, 1);
            if (gCategoryIconSpriteId != MAX_SPRITES)
            {
                gSprites[gCategoryIconSpriteId].invisible = TRUE;
                gSprites[gCategoryIconSpriteId].data[0] = 0;
                gSprites[gCategoryIconSpriteId].callback = SpriteCB_ShowMoveMenuIconNextFrame;
            }
        }
        {
            u32 palIndex = IndexOfSpritePaletteTag(gSpritePal_CategoryIcons.tag);

            if (palIndex == 0xFF)
            {
                CategoryIcons_LoadSpritesGfx();
                palIndex = IndexOfSpritePaletteTag(gSpritePal_CategoryIcons.tag);
            }

            RefreshCategoryIconPalette();
            if (palIndex != 0xFF)
                gSprites[gCategoryIconSpriteId].oam.paletteNum = (u8)palIndex;
        }

        StartSpriteAnim(&gSprites[gCategoryIconSpriteId], category);
        gSprites[gCategoryIconSpriteId].oam.priority = 0;
        gSprites[gCategoryIconSpriteId].x = catBaseX + 8;
        gSprites[gCategoryIconSpriteId].y = catBaseY + 8;
        if (gSprites[gCategoryIconSpriteId].callback == SpriteCallbackDummy)
            gSprites[gCategoryIconSpriteId].invisible = FALSE;
    }
}

static void TryMoveSelectionDisplayMoveDescription(u32 battler)
{
    if (!B_SHOW_MOVE_DESCRIPTION)
        return;

    if (gBattleStruct->descriptionSubmenu)
        MoveSelectionDisplayMoveDescription(battler);
}

static void MoveSelectionDisplayMoveDescription(u32 battler)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[battler][4]);
    u16 move = moveInfo->moves[gMoveSelectionCursor[battler]];
    u16 pwr = GetMovePower(move);
    u16 acc = GetMoveAccuracy(move);

    u8 pwr_num[3], acc_num[3];
    u8 cat_desc[7] = _("CAT: ");
    u8 pwr_desc[7] = _("PWR: ");
    u8 acc_desc[7] = _("ACC: ");
    u8 cat_start[] = _("{CLEAR_TO 0x03}");
    u8 pwr_start[] = _("{CLEAR_TO 0x38}");
    u8 acc_start[] = _("{CLEAR_TO 0x6D}");
    LoadMessageBoxAndBorderGfx();
    DrawStdWindowFrame(B_WIN_MOVE_DESCRIPTION, FALSE);
    if (pwr < 2)
        StringCopy(pwr_num, gText_BattleSwitchWhich5);
    else
        ConvertIntToDecimalStringN(pwr_num, pwr, STR_CONV_MODE_LEFT_ALIGN, 3);
    if (acc < 2)
        StringCopy(acc_num, gText_BattleSwitchWhich5);
    else
        ConvertIntToDecimalStringN(acc_num, acc, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringCopy(gDisplayedStringBattle, cat_start);
    StringAppend(gDisplayedStringBattle, cat_desc);
    StringAppend(gDisplayedStringBattle, pwr_start);
    StringAppend(gDisplayedStringBattle, pwr_desc);
    StringAppend(gDisplayedStringBattle, pwr_num);
    StringAppend(gDisplayedStringBattle, acc_start);
    StringAppend(gDisplayedStringBattle, acc_desc);
    StringAppend(gDisplayedStringBattle, acc_num);
    StringAppend(gDisplayedStringBattle, gText_NewLine);
    StringAppend(gDisplayedStringBattle, GetMoveDescription(move));
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_DESCRIPTION);

    if (gCategoryIconSpriteId == 0xFF)
    {
        CategoryIcons_LoadSpritesGfx();
        gCategoryIconSpriteId = CreateSprite(&gSpriteTemplate_CategoryIcons, 38, 64, 1);
        if (gCategoryIconSpriteId != MAX_SPRITES)
        {
            gSprites[gCategoryIconSpriteId].invisible = TRUE;
            gSprites[gCategoryIconSpriteId].data[0] = 0;
            gSprites[gCategoryIconSpriteId].callback = SpriteCB_ShowMoveMenuIconNextFrame;
        }
    }
    {
        u32 palIndex = IndexOfSpritePaletteTag(gSpritePal_CategoryIcons.tag);

        if (palIndex == 0xFF)
        {
            CategoryIcons_LoadSpritesGfx();
            palIndex = IndexOfSpritePaletteTag(gSpritePal_CategoryIcons.tag);
        }

        RefreshCategoryIconPalette();
        if (palIndex != 0xFF)
            gSprites[gCategoryIconSpriteId].oam.paletteNum = (u8)palIndex;
    }

    StartSpriteAnim(&gSprites[gCategoryIconSpriteId], GetBattleMoveCategory(move));
    gSprites[gCategoryIconSpriteId].oam.priority = 0;
    gSprites[gCategoryIconSpriteId].x = 38;
    gSprites[gCategoryIconSpriteId].y = 64;
    if (gSprites[gCategoryIconSpriteId].callback == SpriteCallbackDummy)
        gSprites[gCategoryIconSpriteId].invisible = FALSE;

    CopyWindowToVram(B_WIN_MOVE_DESCRIPTION, COPYWIN_FULL);
}

void MoveSelectionCreateCursorAt(u8 cursorPosition, u8 baseTileNum)
{
    u8 windowId = B_WIN_MOVE_NAME_1 + cursorPosition;
    u16 widthTiles;
    u16 heightTiles;
    u16 widthPixels;
    u16 heightPixels;

    (void)baseTileNum;

    if (windowId > B_WIN_MOVE_NAME_4)
        return;

    widthTiles = gWindows[windowId].window.width;
    heightTiles = gWindows[windowId].window.height;
    if ((windowId == B_WIN_MOVE_NAME_1 || windowId == B_WIN_MOVE_NAME_3) && !gBattleStruct->zmove.viewing)
        widthTiles /= 2;
    widthPixels = widthTiles * TILE_WIDTH;
    heightPixels = heightTiles * TILE_HEIGHT;

    FillWindowPixelRect(windowId, 10, 0, 0, widthPixels, 1);
    FillWindowPixelRect(windowId, 10, 0, heightPixels - 1, widthPixels, 1);
    FillWindowPixelRect(windowId, 10, 0, 0, 1, heightPixels);
    FillWindowPixelRect(windowId, 10, widthPixels - 1, 0, 1, heightPixels);
    CopyWindowRectToVram(windowId, COPYWIN_GFX, 0, 0, widthTiles, heightTiles);
}

void MoveSelectionDestroyCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    if (B_WIN_MOVE_NAME_1 + cursorPosition <= B_WIN_MOVE_NAME_4)
    {
        u8 windowId = B_WIN_MOVE_NAME_1 + cursorPosition;
        u16 widthTiles = gWindows[windowId].window.width;
        u16 heightTiles = gWindows[windowId].window.height;
        u16 widthPixels;
        u16 heightPixels;

        if ((windowId == B_WIN_MOVE_NAME_1 || windowId == B_WIN_MOVE_NAME_3) && !gBattleStruct->zmove.viewing)
            widthTiles /= 2;
        widthPixels = widthTiles * TILE_WIDTH;
        heightPixels = heightTiles * TILE_HEIGHT;

        FillWindowPixelRect(windowId, 5, 0, 0, widthPixels, 1);
        FillWindowPixelRect(windowId, 5, 0, heightPixels - 1, widthPixels, 1);
        FillWindowPixelRect(windowId, 5, 0, 0, 1, heightPixels);
        FillWindowPixelRect(windowId, 5, widthPixels - 1, 0, 1, heightPixels);
        CopyWindowRectToVram(windowId, COPYWIN_GFX, 0, 0, widthTiles, heightTiles);
    }

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void ActionSelectionCreateCursorAt(u8 cursorPosition, u8 baseTileNum)
{
    u16 x;
    u16 y;
    u16 optionWidth = 6 * TILE_WIDTH;
    u16 optionHeight = 2 * TILE_HEIGHT;

    (void)baseTileNum;

    x = (cursorPosition & 1) * optionWidth;
    y = (cursorPosition & 2) ? optionHeight : 0;

    FillWindowPixelRect(B_WIN_ACTION_MENU, 10, x, y, optionWidth, 1);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 10, x, y + optionHeight - 1, optionWidth, 1);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 10, x, y, 1, optionHeight);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 10, x + optionWidth - 1, y, 1, optionHeight);
    CopyWindowToVram(B_WIN_ACTION_MENU, COPYWIN_GFX);
}

void ActionSelectionDestroyCursorAt(u8 cursorPosition)
{
    u16 x;
    u16 y;
    u16 optionWidth = 6 * TILE_WIDTH;
    u16 optionHeight = 2 * TILE_HEIGHT;

    x = (cursorPosition & 1) * optionWidth;
    y = (cursorPosition & 2) ? optionHeight : 0;

    FillWindowPixelRect(B_WIN_ACTION_MENU, 5, x, y, optionWidth, 1);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 5, x, y + optionHeight - 1, optionWidth, 1);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 5, x, y, 1, optionHeight);
    FillWindowPixelRect(B_WIN_ACTION_MENU, 5, x + optionWidth - 1, y, 1, optionHeight);
    CopyWindowToVram(B_WIN_ACTION_MENU, COPYWIN_GFX);
}

void CB2_SetUpReshowBattleScreenAfterMenu(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

void CB2_SetUpReshowBattleScreenAfterMenu2(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

static void PrintLinkStandbyMsg(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        BattlePutTextOnWindow(gText_LinkStandby, B_WIN_MSG);
    }
}

static void PlayerHandleLoadMonSprite(u32 battler)
{
    BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = GetBattlerPosition(battler);
    gBattlerControllerFuncs[battler] = CompleteOnBattlerSpritePosX_0;
}

static void PlayerHandleSwitchInAnim(u32 battler)
{
    gActionSelectionCursor[battler] = 0;
    gMoveSelectionCursor[battler] = 0;
    BtlController_HandleSwitchInAnim(battler, TRUE, SwitchIn_TryShinyAnimShowHealthbox);
}

u32 LinkPlayerGetTrainerPicId(u32 multiplayerId)
{
    u32 trainerPicId;

    u8 gender = gLinkPlayers[multiplayerId].gender;
    u8 version = gLinkPlayers[multiplayerId].version & 0xFF;

    if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        trainerPicId = gender + TRAINER_BACK_PIC_RED;
    else if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
        trainerPicId = gender + TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN;
    else
        trainerPicId = gender + TRAINER_BACK_PIC_BRENDAN;

    return trainerPicId;
}

static u32 PlayerGetTrainerBackPicId(void)
{
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        trainerPicId = LinkPlayerGetTrainerPicId(GetMultiplayerId());
    else
        trainerPicId = gSaveBlock2Ptr->playerGender + TRAINER_BACK_PIC_BRENDAN;

    return trainerPicId;
}

// In emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven)
// that use an animated back pic.
static void PlayerHandleDrawTrainerPic(u32 battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    u32 trainerPicId;

    trainerPicId = PlayerGetTrainerBackPicId();
    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBattlerPosition(battler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
            xPos = 90;
        else // First mon, on the left.
            xPos = 32;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
        {
            xPos = 90;
            yPos = 80;
        }
        else
        {
            yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;
        }

    }
    else
    {
        xPos = 80;
        yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;
    }

    // Use front pic table for any tag battles unless your partner is Steven or a custom partner.
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
    {
        trainerPicId = PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender);
        isFrontPic = TRUE;
    }
    else // Use back pic in all the other usual circumstances.
    {
        isFrontPic = FALSE;
    }

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void PlayerHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId = PlayerGetTrainerBackPicId();
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void PlayerHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 50, TRUE);
}

static void PlayerHandlePaletteFade(u32 battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleSuccessBallThrowAnim(u32 battler)
{
    BtlController_HandleSuccessBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

void PlayerHandleBallThrowAnim(u32 battler)
{
    BtlController_HandleBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

static void PlayerHandlePause(u32 battler)
{
    u8 timer = gBattleResources->bufferA[battler][1];

    while (timer != 0)
        timer--;

    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleMoveAnimation(u32 battler)
{
    DestroyMoveMenuIcons();
    FreeMoveMenuIconPalettes();
    BattleInterface_FreeInactiveWindowPalettes();
    BtlController_HandleMoveAnimation(battler, TRUE);
}

static void PlayerHandlePrintString(u32 battler)
{
    DestroyMoveMenuIcons();
    BtlController_HandlePrintString(battler, TRUE, TRUE);
}

static void PlayerHandlePrintSelectionString(u32 battler)
{
    if (IsOnPlayerSide(battler))
        PlayerHandlePrintString(battler);
    else
        PlayerBufferExecCompleted(battler);
}

static void HandleChooseActionAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        if (gBattleStruct->aiDelayTimer != 0)
        {
            gBattleStruct->aiDelayFrames = gMain.vblankCounter1 - gBattleStruct->aiDelayTimer;
            gBattleStruct->aiDelayTimer = 0;
            if (DEBUG_AI_DELAY_TIMER)
            {
                static const u8 sFramesText[] = _(" frames thinking\n");
                static const u8 sCyclesText[] = _(" cycles");
                ConvertIntToDecimalStringN(gDisplayedStringBattle, gBattleStruct->aiDelayFrames, STR_CONV_MODE_RIGHT_ALIGN, 3);
                u8* end = StringAppend(gDisplayedStringBattle, sFramesText);
                ConvertIntToDecimalStringN(end, gBattleStruct->aiDelayCycles, STR_CONV_MODE_RIGHT_ALIGN, 8);
                // Clear old result once read out
                gBattleStruct->aiDelayCycles = 0;
                StringAppend(gDisplayedStringBattle, sCyclesText);
                BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
            }
        }
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
    }
}

static void PlayerHandleChooseAction(u32 battler)
{
    s32 i;

    DestroyMoveMenuIcons();
    if (IsDoubleBattle())
    {
        ReserveAbilityPopupPaletteSlot();
        BattleInterface_RestoreAbilityPopupPalette();
        ReserveLastUsedBallPaletteSlot();
    }
    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattleTv_ClearExplosionFaintCause();
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        BattlePutTextOnWindow(gText_BattleMenuTrainerCall, B_WIN_ACTION_MENU);
    else
        BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    TryRestoreLastUsedBall();
    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo);
    else
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDoCall);

    if (B_SHOW_PARTNER_TARGET && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && IsBattlerAlive(B_POSITION_PLAYER_RIGHT))
    {
        StringCopy(gStringVar1, COMPOUND_STRING("Partner will use:\n"));
        u32 move = gBattleMons[B_POSITION_PLAYER_RIGHT].moves[gBattleStruct->chosenMovePositions[B_POSITION_PLAYER_RIGHT]];
        StringAppend(gStringVar1, GetMoveName(move));
        u32 moveTarget = GetBattlerMoveTargetType(B_POSITION_PLAYER_RIGHT, move);
        if (moveTarget == MOVE_TARGET_SELECTED)
        {
            if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_OPPONENT_LEFT)
                StringAppend(gStringVar1, COMPOUND_STRING(" -{UP_ARROW}"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_OPPONENT_RIGHT)
                StringAppend(gStringVar1, COMPOUND_STRING(" {UP_ARROW}-"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_PLAYER_LEFT)
                StringAppend(gStringVar1, COMPOUND_STRING(" {DOWN_ARROW}-"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_PLAYER_RIGHT)
                StringAppend(gStringVar1, COMPOUND_STRING(" {DOWN_ARROW}-"));
        }
        else if (moveTarget == MOVE_TARGET_BOTH)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {UP_ARROW}{UP_ARROW}"));
        }
        else if (moveTarget == MOVE_TARGET_FOES_AND_ALLY)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {V_D_ARROW}{UP_ARROW}"));
        }
        else if (moveTarget == MOVE_TARGET_ALL_BATTLERS)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {V_D_ARROW}{V_D_ARROW}"));
        }
        BattlePutTextOnWindow(gStringVar1, B_WIN_ACTION_PROMPT);
    }
    else
    {
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
    }
}

static void PlayerHandleYesNoBox(u32 battler)
{
    if (IsOnPlayerSide(battler))
    {
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
        gBattlerControllerFuncs[battler] = PlayerHandleYesNoInput;
    }
    else
    {
        PlayerBufferExecCompleted(battler);
    }
}

void HandleChooseMoveAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT * 2;
        if (IsDoubleBattle())
        {
            ReserveAbilityPopupPaletteSlot();
            BattleInterface_RestoreAbilityPopupPalette();
            ReserveMoveTypeIconPaletteSlot();
            ReserveCategoryIconPaletteSlot();
        }
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        else
            MoveSelectionDisplayPpString(battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
        sMoveTypePaletteRefreshBattler = battler;
        sMoveTypePaletteRefreshFrames = 2;
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
    }
}

// arenaMindPoints is used here as a placeholder for a timer.

static void PlayerChooseMoveInBattlePalace(u32 battler)
{
    if (--gBattleStruct->arenaMindPoints[battler] == 0)
    {
        gBattlePalaceMoveSelectionRngValue = gRngValue;
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 10, ChooseMoveAndTargetInBattlePalace(battler));
        PlayerBufferExecCompleted(battler);
    }
}

void PlayerHandleChooseMove(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gBattleStruct->arenaMindPoints[battler] = 8;
        gBattlerControllerFuncs[battler] = PlayerChooseMoveInBattlePalace;
    }
    else
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

        sMoveTypePaletteRefreshBattler = 0xFF;
        sMoveTypePaletteRefreshFrames = 0;
        if (IsDoubleBattle())
        {
            BattleInterface_DiscardTransientWindows();
            TryToAddMoveInfoWindow();
        }
        ReserveMoveTypeIconPaletteSlot();
        ReserveCategoryIconPaletteSlot();
        InitMoveSelectionsVarsAndStrings(battler);
        gBattleStruct->gimmick.playerSelect = FALSE;
        if (!IsDoubleBattle())
            TryToAddMoveInfoWindow();

        AssignUsableZMoves(battler, moveInfo->moves);
        gBattleStruct->zmove.viable = (gBattleStruct->zmove.possibleZMoves[battler] & (1u << gMoveSelectionCursor[battler])) != 0;

        if (!IsGimmickTriggerSpriteActive())
            gBattleStruct->gimmick.triggerSpriteId = 0xFF;
        if (!(gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_Z_MOVE && !gBattleStruct->zmove.viable))
            CreateGimmickTriggerSprite(battler);

        gBattlerControllerFuncs[battler] = HandleChooseMoveAfterDma3;
    }
}

void InitMoveSelectionsVarsAndStrings(u32 battler)
{
    LoadTypeIcons(battler);
    MoveSelectionDisplayMoveNames(battler);
    gMultiUsePlayerCursor = 0xFF;
    MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    if (B_SHOW_EFFECTIVENESS)
        MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
    else
        MoveSelectionDisplayPpString(battler);
    MoveSelectionDisplayPpNumber(battler);
    MoveSelectionDisplayMoveType(battler);
}

static void PlayerHandleChooseItem(u32 battler)
{
    s32 i;

    DestroyMoveMenuIcons();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenBagAndChooseItem;
    gBattlerInMenuId = battler;

    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][1 + i];
}

static void PlayerHandleChoosePokemon(u32 battler)
{
    s32 i;

    DestroyMoveMenuIcons();
    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CANT_SWITCH
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CHOOSE_FAINTED_MON
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_SEND_MON_TO_BOX)
    {
        BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattlerPartyIndexes[battler] + 1, gBattlePartyCurrentOrder);
        PlayerBufferExecCompleted(battler);
    }
    else
    {
        gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
        gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1] & 0xF;
        *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][1] >> 4;
        *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
        *(&gBattleStruct->abilityPreventingSwitchout) = (gBattleResources->bufferA[battler][3] & 0xFF) | (gBattleResources->bufferA[battler][7] << 8);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
        gBattlerInMenuId = battler;
    }
}

static void PlayerHandleCmd23(u32 battler)
{
    BattleStopLowHpSound();
    BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler, TRUE);
}

void PlayerHandleExpUpdate(u32 battler)
{
    u8 monId = gBattleResources->bufferA[battler][1];
    s32 taskId, expPointsToGive;

    if (GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL) >= MAX_LEVEL)
    {
        PlayerBufferExecCompleted(battler);
    }
    else
    {
        LoadBattleBarGfx(1);
        expPointsToGive = T1_READ_32(&gBattleResources->bufferA[battler][2]);
        taskId = CreateTask(Task_GiveExpToMon, 10);
        gTasks[taskId].tExpTask_monId = monId;
        gTasks[taskId].tExpTask_gainedExp_1 = expPointsToGive;
        gTasks[taskId].tExpTask_gainedExp_2 = expPointsToGive >> 16;
        gTasks[taskId].tExpTask_battler = battler;
        gBattlerControllerFuncs[battler] = BattleControllerDummy;
    }
}

#undef tExpTask_monId
#undef tExpTask_battler
#undef tExpTask_gainedExp_1
#undef tExpTask_gainedExp_2
#undef tExpTask_frames

static void PlayerHandleStatusXor(u32 battler)
{
    u32 val = GetMonData(GetBattlerMon(battler), MON_DATA_STATUS) ^ gBattleResources->bufferA[battler][1];

    SetMonData(GetBattlerMon(battler), MON_DATA_STATUS, &val);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleDMA3Transfer(u32 battler)
{
    u32 dstArg = gBattleResources->bufferA[battler][1]
            | (gBattleResources->bufferA[battler][2] << 8)
            | (gBattleResources->bufferA[battler][3] << 16)
            | (gBattleResources->bufferA[battler][4] << 24);
    u16 sizeArg = gBattleResources->bufferA[battler][5] | (gBattleResources->bufferA[battler][6] << 8);

    const u8 *src = &gBattleResources->bufferA[battler][7];
    u8 *dst = (u8 *)(dstArg);
    u32 size = sizeArg;

    while (1)
    {
        if (size <= 0x1000)
        {
            DmaCopy16(3, src, dst, size);
            break;
        }
        DmaCopy16(3, src, dst, 0x1000);
        src += 0x1000;
        dst += 0x1000;
        size -= 0x1000;
    }
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandlePlayBGM(u32 battler)
{
    PlayBGM(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleTwoReturnValues(u32 battler)
{
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, 0, 0);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleChosenMonReturnValue(u32 battler)
{
    BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, 0, NULL);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleOneReturnValue(u32 battler)
{
    BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, 0);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleOneReturnValue_Duplicate(u32 battler)
{
    BtlController_EmitOneReturnValue_Duplicate(battler, B_COMM_TO_ENGINE, 0);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleIntroTrainerBallThrow(u32 battler)
{
    const u16 *trainerPal = gTrainerBacksprites[gSaveBlock2Ptr->playerGender].palette.data;
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

static void PlayerHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void PlayerHandleEndBounceEffect(u32 battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, FALSE, TRUE);
}

static void PlayerHandleLinkStandbyMsg(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][2]);
    switch (gBattleResources->bufferA[battler][1])
    {
    case LINK_STANDBY_MSG_STOP_BOUNCE:
        PrintLinkStandbyMsg();
        // fall through
    case LINK_STANDBY_STOP_BOUNCE_ONLY:
        EndBounceEffect(battler, BOUNCE_HEALTHBOX);
        EndBounceEffect(battler, BOUNCE_MON);
        break;
    case LINK_STANDBY_MSG_ONLY:
        PrintLinkStandbyMsg();
        break;
    }
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleResetActionMoveSelection(u32 battler)
{
    switch (gBattleResources->bufferA[battler][1])
    {
    case RESET_ACTION_MOVE_SELECTION:
        gActionSelectionCursor[battler] = 0;
        gMoveSelectionCursor[battler] = 0;
        break;
    case RESET_ACTION_SELECTION:
        gActionSelectionCursor[battler] = 0;
        break;
    case RESET_MOVE_SELECTION:
        gMoveSelectionCursor[battler] = 0;
        break;
    }
    DestroyMoveMenuIcons();
    PlayerBufferExecCompleted(battler);
}

static void PlayerHandleEndLinkBattle(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][4]);
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    gSaveBlock2Ptr->frontier.disableRecordBattle = gBattleResources->bufferA[battler][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    PlayerBufferExecCompleted(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}

static void Controller_WaitForDebug(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        PlayerBufferExecCompleted(battler);
    }
}

static void PlayerHandleBattleDebug(u32 battler)
{
    // 1) Give balls for testing snag / catching
    AddBagItem(ITEM_POKE_BALL, 50);
    AddBagItem(ITEM_MASTER_BALL, 50);
    AddBagItem(ITEM_DARK_BALL, 50);
    AddBagItem(ITEM_SNAG_MACHINE, 1);
    AddBagItem(ITEM_SHADOW_MONITOR, 1);
    AddBagItem(ITEM_TIME_FLUTE, 1);
    AddBagItem(ITEM_PHOTO_CAMERA, 1);
    FlagSet(FLAG_HAS_SNAG_MACHINE);
    FlagSet(FLAG_RECEIVED_SNAG_MACHINE);
    FlagSet(FLAG_RECEIVED_SHADOW_MONITOR);
    FlagSet(FLAG_SHADOW_TRACKER_UNLOCKED);
    AddBagItem(ITEM_POTION, 2);
    AddBagItem(ITEM_FULL_RESTORE, 2);
    FlagSet(FLAG_SYS_POKENAV_GET);
    FlagSet(FLAG_RECEIVED_POKENAV);

    // 2) Toggle Reverse Mode on the active player mon if it's a Shadow mon
    //    (relies on the Shadow fields we pulled in from the Shadow PR)
    if (gBattleMons[battler].isShadow)
    {
        // Flip the reverse flag
        gBattleMons[battler].isReverse ^= 1;

        // Optional: if you want a message or animation later, you can hook it via battle script,
        // but for now this is enough to trigger the end-turn Reverse Mode damage handler.
    }

    // 3) Immediately finish the debug action back to the battle engine
    // We keep using Controller_WaitForDebug so the function isn't unused.
    gBattlerControllerFuncs[battler] = Controller_WaitForDebug;
}

// Order based numerically, with EFFECTIVENESS_CANNOT_VIEW at 0 to always prioritize any other effectiveness during comparison
enum
{
    EFFECTIVENESS_CANNOT_VIEW,
    EFFECTIVENESS_NO_EFFECT,
    EFFECTIVENESS_NOT_VERY_EFFECTIVE,
    EFFECTIVENESS_NORMAL,
    EFFECTIVENESS_SUPER_EFFECTIVE_2X,
    EFFECTIVENESS_SUPER_EFFECTIVE_4X,
};

static bool32 ShouldShowTypeEffectiveness(u32 targetId)
{
    if (B_SHOW_EFFECTIVENESS == SHOW_EFFECTIVENESS_NEVER)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return TRUE;

    if (B_SHOW_EFFECTIVENESS == SHOW_EFFECTIVENESS_CAUGHT)
        return GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[targetId].species), FLAG_GET_CAUGHT);

    if (B_SHOW_EFFECTIVENESS == SHOW_EFFECTIVENESS_SEEN)
        return GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[targetId].species), FLAG_GET_SEEN);

    return TRUE;
}

static u32 CheckTypeEffectiveness(u32 targetId, u32 battler)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    struct Pokemon *mon = GetBattlerMon(battler);
    u32 move = moveInfo->moves[gMoveSelectionCursor[battler]];
    u32 moveType = CheckDynamicMoveType(mon, move, battler, MON_IN_BATTLE);
    uq4_12_t modifier = CalcTypeEffectivenessMultiplier(move, moveType, battler, targetId, GetBattlerAbility(targetId), FALSE);

    if (!ShouldShowTypeEffectiveness(targetId))
        return EFFECTIVENESS_CANNOT_VIEW;

    if (modifier == UQ_4_12(0.0))
        return EFFECTIVENESS_NO_EFFECT; // No effect
    else if (modifier <= UQ_4_12(0.5))
        return EFFECTIVENESS_NOT_VERY_EFFECTIVE; // Not very effective
    else if (modifier >= UQ_4_12(4.0))
        return EFFECTIVENESS_SUPER_EFFECTIVE_4X; // Super effective (4x+)
    else if (modifier >= UQ_4_12(2.0))
        return EFFECTIVENESS_SUPER_EFFECTIVE_2X; // Super effective (2x)
    return EFFECTIVENESS_NORMAL; // Normal effectiveness
}

static u32 CheckTargetTypeEffectiveness(u32 battler)
{
    u32 battlerFoe = BATTLE_OPPOSITE(GetBattlerPosition(battler));
    u32 foeEffectiveness = CheckTypeEffectiveness(battlerFoe, battler);

    if (IsDoubleBattle())
    {
        u32 partnerFoe = BATTLE_PARTNER(battlerFoe);
        u32 partnerFoeEffectiveness = CheckTypeEffectiveness(partnerFoe, battler);
        if (!IsBattlerAlive(battlerFoe))
            return partnerFoeEffectiveness;
        if (IsBattlerAlive(battlerFoe) && IsBattlerAlive(partnerFoe)
         && partnerFoeEffectiveness > foeEffectiveness)
            return partnerFoeEffectiveness;
    }
    return foeEffectiveness; // fallthrough for any other circumstance
}

static void MoveSelectionDisplayMoveEffectiveness(u32 foeEffectiveness, u32 battler)
{
    static const u8 noIcon[] =  _("");
    static const u8 superEffective2xText[] =  _("{COLOR LIGHT_GREEN}{SHADOW 13}2x{COLOR 14}{SHADOW 13}");
    static const u8 superEffective4xText[] =  _("{COLOR LIGHT_GREEN}{SHADOW 13}{UP_ARROW_2}4x{COLOR 14}{SHADOW 13}");
    static const u8 notVeryEffectiveText[] =  _("{COLOR 1}{SHADOW 13}{DOWN_ARROW}.5x{COLOR 14}{SHADOW 13}");
    static const u8 normalEffectiveText[] =  _("1x");
    // The battle window uses its own palette: indices 1 and 2 are red and dark red.
    static const u8 immuneIcon[] =  _("{COLOR 1}{SHADOW 2}X{COLOR 14}{SHADOW 13}");
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u8 *txtPtr;

    txtPtr = gDisplayedStringBattle;
    *txtPtr = EOS;

    if (!IsBattleMoveStatus(moveInfo->moves[gMoveSelectionCursor[battler]]))
    {
        switch (foeEffectiveness)
        {
        case EFFECTIVENESS_SUPER_EFFECTIVE_4X:
            StringCopy(txtPtr, superEffective4xText);
            break;
        case EFFECTIVENESS_SUPER_EFFECTIVE_2X:
            StringCopy(txtPtr, superEffective2xText);
            break;
        case EFFECTIVENESS_NOT_VERY_EFFECTIVE:
            StringCopy(txtPtr, notVeryEffectiveText);
            break;
        case EFFECTIVENESS_NO_EFFECT:
            StringCopy(txtPtr, immuneIcon);
            break;
        case EFFECTIVENESS_NORMAL:
            StringCopy(txtPtr, normalEffectiveText);
            break;
        default:
        case EFFECTIVENESS_CANNOT_VIEW:
            StringCopy(txtPtr, noIcon);
            break;
        }
    }

    BattlePutTextOnWindowRightAlign(gDisplayedStringBattle, B_WIN_PP_REMAINING);
}

#define tHgTask_monId         data[0]
#define tHgTask_battler       data[2]
#define tHgTask_amount_1      data[3]
#define tHgTask_amount_2      data[4] // Stored as two half-words containing a word.
#define tHgTask_frames        data[10]

static s32 GetTaskHeartValue(u8 taskId)
{
    DebugPrintf("GetTaskHeartValue: %d", (gTasks[taskId].tHgTask_amount_1) | (gTasks[taskId].tHgTask_amount_2 << 16));
    return (gTasks[taskId].tHgTask_amount_1) | (gTasks[taskId].tHgTask_amount_2 << 16);
}

static void Task_LowerHeartValue(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].tHgTask_monId);
    u8 battler = gTasks[taskId].tHgTask_battler;
    s32 amount = GetTaskHeartValue(taskId);
    struct Pokemon *mon = &gPlayerParty[monId];
    u16 hVal = GetMonData(mon, MON_DATA_HEART_VALUE);
    u16 hMax = GetMonData(mon, MON_DATA_HEART_MAX);
    u8 UNUSED hgCurrSection = GetHeartGaugeSection(hVal, hMax);
    u8 UNUSED hgNewSection = GetHeartGaugeSection(hVal + amount, hMax);

    if ((IsDoubleBattle() == TRUE || monId != gBattlerPartyIndexes[battler])) // no bar anim
    {
        // TODOSHADOW if (hgCurrSection != hgNewSection) // handle new section unlock?
        if (0)
        {
            //SetMonData(mon, MON_DATA_HEART_VALUE, &newVal);
            //CalculateMonStats(mon);
            //TODO BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, amount);

            if (IsDoubleBattle() == TRUE
             && ((u16)(monId) == gBattlerPartyIndexes[battler] || (u16)(monId) == gBattlerPartyIndexes[BATTLE_PARTNER(battler)]))
                gTasks[taskId].func = Task_LaunchSectionUnlockAnim;
            else
            {
                gBattlerControllerFuncs[battler] = Controller_WaitForString;
                DestroyTask(taskId);
            }
        }
        else
        {
            hVal += amount;
            SetMonData(mon, MON_DATA_HEART_VALUE, &hVal);
            gBattlerControllerFuncs[battler] = Controller_WaitForString;
            DestroyTask(taskId);
        }
    }
    else
    {
        //SetMonData(mon, MON_DATA_HEART_VALUE, &newVal);
        gTasks[taskId].func = Task_PrepareToLowerHeartValWithBar;
    }
}

static void Task_PrepareToLowerHeartValWithBar(u8 taskId)
{
    u32 monIndex = gTasks[taskId].tHgTask_monId;
    s32 amount = GetTaskHeartValue(taskId);
    u8 battler = gTasks[taskId].tHgTask_battler;
    struct Pokemon *mon = &gPlayerParty[monIndex];
    u16 hVal = GetMonData(mon, MON_DATA_HEART_VALUE);
    u16 hMax = GetMonData(mon, MON_DATA_HEART_MAX);
    \
    DebugPrintf("Task_PrepareToLowerHeartValWithBar/SetBattleBarStruct: %d, %d, %d, %d, %d", 
    battler, gHealthboxSpriteIds[battler], hMax, hVal, -amount);

    SetBattleBarStruct(battler, gHealthboxSpriteIds[battler], hMax, hVal, -amount);
    PlaySE(SE_EXP);
    gTasks[taskId].func = Task_LowerHeartValWithBar;
}

static void Task_LowerHeartValWithBar(u8 taskId)
{
    if (gTasks[taskId].tHgTask_frames < 13)
    {
        gTasks[taskId].tHgTask_frames++;
    }
    else
    {
        u8 monId = gTasks[taskId].tHgTask_monId;
        s32 gainedVal = GetTaskHeartValue(taskId);
        u8 battler = gTasks[taskId].tHgTask_battler;
        s32 newHeartVal;

        newHeartVal = MoveBattleBar(battler, gHealthboxSpriteIds[battler], HEART_GAUGE, 0);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        if (newHeartVal == -1) // The bar has been filled with given exp points.
        {
            u16 hVal = GetMonData(&gPlayerParty[monId], MON_DATA_HEART_VALUE);
            u16 hMax = GetMonData(&gPlayerParty[monId], MON_DATA_HEART_MAX);
            u8 UNUSED currSection = GetHeartGaugeSection(hVal, hMax);
            u8 UNUSED newSection = GetHeartGaugeSection(newHeartVal, hMax);

            m4aSongNumStop(SE_EXP);

            //TODO if (currSection != newSection) // handle new section unlock
            if (0)
            {
                SetMonData(&gPlayerParty[monId], MON_DATA_HEART_VALUE, &hVal);
                // CalculateMonStats(&gPlayerParty[monId]);
                //TODO BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, amount);
                gTasks[taskId].func = Task_LaunchSectionUnlockAnim;
            }
            else
            {
                hVal += gainedVal;
                SetMonData(&gPlayerParty[monId], MON_DATA_HEART_VALUE, &hVal);
                gBattlerControllerFuncs[battler] = Controller_WaitForString;
                DestroyTask(taskId);
            }
        }
    }
}

static void Task_LaunchSectionUnlockAnim(u8 taskId)
{
    u8 battlerId = gTasks[taskId].tHgTask_battler;
    u8 monIndex = gTasks[taskId].tHgTask_monId;

    if (IsDoubleBattle() == TRUE && monIndex == gBattlerPartyIndexes[BATTLE_PARTNER(battlerId)])
        battlerId ^= BIT_FLANK;

    InitAndLaunchSpecialAnimation(battlerId, battlerId, battlerId, B_ANIM_SECTION_UNLOCK);

    gBattlerControllerFuncs[battlerId] = Controller_WaitForString;
    DestroyTask(taskId);
}

static void PlayerHandleHeartValueUpdate(u32 battler)
{
    u8 monId = gBattleResources->bufferA[battler][1];
    s32 taskId, amount;

    if (GetMonData(&gPlayerParty[monId], MON_DATA_HEART_VALUE) == 0)
    {
        PlayerBufferExecCompleted(battler);
    }
    else
    {
        LoadBattleBarGfx(1);
        amount = T1_READ_32(&gBattleResources->bufferA[battler][2]);
        taskId = CreateTask(Task_LowerHeartValue, 10);
        gTasks[taskId].tHgTask_monId = monId;
        gTasks[taskId].tHgTask_amount_1 = amount;
        gTasks[taskId].tHgTask_amount_2 = amount >> 16;
        gTasks[taskId].tHgTask_battler = battler;
        gBattlerControllerFuncs[battler] = BattleControllerDummy;
    }
}

#undef tHgTask_monId
#undef tHgTask_battler
#undef tHgTask_amount_1
#undef tHgTask_amount_2
#undef tHgTask_frames
