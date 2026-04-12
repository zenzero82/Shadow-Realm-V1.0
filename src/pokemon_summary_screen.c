#include "global.h"
#include "gflib.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "battle_gfx_sfx_util.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "party_menu.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "ev_iv_display_screen.h"
#include "field_specials.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "move.h"
#include "move_relearner.h"
#include "naming_screen.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trade.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "window.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/characters.h"

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

#define TEXT_SPEED_FF 0xFF
#define PSS_MOVE_DESC_FONT_ID 2
#define PSS_MOVE_DESC_TEXT_X 7
#define PSS_MOVE_DESC_TEXT_Y 62
#define PSS_MOVE_DESC_WINDOW_WIDTH_TILES 15
#define PSS_MOVE_DESC_WINDOW_WIDTH_PX (PSS_MOVE_DESC_WINDOW_WIDTH_TILES * 8)
#define PSS_MOVE_DESC_MAX_WIDTH_PX (PSS_MOVE_DESC_WINDOW_WIDTH_PX - PSS_MOVE_DESC_TEXT_X - 1)
#define PSS_MOVE_DESC_WORD_BUF_SIZE 256

// Internal summary screen modes (separate from SUMMARY_MODE_* in the public header)
enum
{
    PSS_MODE_NORMAL,
    PSS_MODE_UNK1,
    PSS_MODE_SELECT_MOVE,
    PSS_MODE_FORGET_MOVE,
    PSS_MODE_TRADE,
    PSS_MODE_BOX
};

enum
{
    PSS_STATE3270_0,
    PSS_STATE3270_1,
    PSS_STATE3270_2,
    PSS_STATE3270_3,
    PSS_STATE3270_4,
    PSS_STATE3270_5,
    PSS_STATE3270_6,
};

enum
{
    PSS_STAT_ATK,
    PSS_STAT_DEF,
    PSS_STAT_SPA,
    PSS_STAT_SPD,
    PSS_STAT_SPE,
};

// Map BW summary screen page names onto Emerald's summary screen pages.
#define PSS_PAGE_MOVES      PSS_PAGE_BATTLE_MOVES
#define PSS_PAGE_MOVES_INFO PSS_PAGE_CONTEST_MOVES

#define SUMMARY_PAGE_TILEMAP_SIZE 0x800

#define TAG_PSS_UNK_64 0x64
#define TAG_PSS_UNK_6E 0x6E
#define TAG_PSS_UNK_78 0x78
#define TAG_PSS_UNK_82 0x82
#define TAG_PSS_UNK_8C 0x8C
#define TAG_PSS_UNK_96 0x96
#define TAG_PSS_UNK_A0 0xA0

// Local text used by the BW summary screen
static const u8 gText_StringDummy[] = _("");
static const u8 gText_ThreeHyphens[] = _("---");
static const u8 gText_8416202[] = _("???");
static const u8 gText_84161EF[] = _("None");
static const u8 gText_841620E[] = _("---");
static const u8 gText_8416210[] = _("---");
static const u8 gText_8416238[] = _("PP");
static const u8 gText_PSS_DexNumber[] = _("Dex No.");
static const u8 gText_PSS_Name[] = _("Name");
static const u8 gText_PSS_Type[] = _("Type");
static const u8 gText_PSS_OT[] = _("OT");
static const u8 gText_PSS_IDNumber[] = _("ID No.");
static const u8 gText_PSS_Item[] = _("Item");
static const u8 gText_PSS_Status[] = _("Status");
static const u8 gText_PSS_HP[] = _("HP");
static const u8 gText_PSS_Attack[] = _("Attack");
static const u8 gText_PSS_Defense[] = _("Defense");
static const u8 gText_PSS_SpAtk[] = _("Sp. Atk");
static const u8 gText_PSS_SpDef[] = _("Sp. Def");
static const u8 gText_PSS_Speed[] = _("Speed");
static const u8 gText_PSS_ExpPoints[] = _("Exp. Points");
static const u8 gText_PSS_ToNextLv[] = _("To Next Lv.");
static const u8 gText_PSS_StoredExp[] = _("Stored Exp");
static const u8 gText_PSS_LvAfterPure[] = _("Lv After Pur.");
static const u8 gText_PSS_TrainerMemo[] = _("Trainer Memo");
static const u8 gText_PSS_Ability[] = _("Ability");
static const u8 gText_PSS_Category[] = _("Category");
static const u8 gText_PSS_Power[] = _("Power");
static const u8 gText_PSS_Accuracy[] = _("Accuracy");
static const u8 gText_PSS_Effect[] = _("Effect");
static const u8 gText_FameChecker_Cancel[] = _("Cancel");
static const u8 gText_8419C1D[] = _("Info");
static const u8 gText_8419C2A[] = _("Skills");
static const u8 gText_8419C39[] = _("Moves");
static const u8 gText_8419C45[] = _("");
static const u8 gText_8419C62[] = _("Switch");
static const u8 gText_8419C72[] = _("Cancel");
static const u8 gText_8419C7B[] = _("Check");
static const u8 gText_8419C82[] = _("{A_BUTTON} Switch");
static const u8 gText_8419C92[] = _("{A_BUTTON} Select");
static const u8 gText_8419CA2[] = _("Cancel");
static const u8 gText_8419CA9[] = _("Forget");
static const u8 gText_PSS_RenameA[] = _("{A_BUTTON} RENAME");
static const u8 gText_PSS_RelearnL[] = _("{L_BUTTON} RELEARN");
static const u8 gText_PSS_EvIv[] = _("{A_BUTTON} EV-IV");
static const u8 gText_8419C4D[] = _("Exp. Points");
static const u8 gText_8419C59[] = _("To Next Lv.");

static const u8 sMemoNatureTextColor[] = _("{COLOR BLUE}{SHADOW DARK_GRAY}");
static const u8 sMemoMiscTextColor[] = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");

// BW summary screen graphics (defined in pokemon_summary_screen_bw_graphics.c)
extern const u8 gFireRedMenuElements_Gfx[];
extern const u16 gFireRedMenuElements2_Pal[];
extern const u32 gIconStatusSummaryScreen[];
extern const u32 gIconStatusSummaryScreenSpa[];
extern const u16 gIconStatusPalSummaryScreen[];
extern const u32 gExpBarSummaryScreen[];
extern const u32 gHeartBarSummaryScreen[];
extern const u32 gHpBarSummaryScreen[];
extern const u32 gHpBarSummaryScreenSpa[];
extern const u16 gPal0SummaryScreen[];
extern const u16 gPal1SummaryScreen[];
extern const u16 gPal2SummaryScreen[];
extern const u16 gSelectCursorPalette[];
extern const u32 gSelectCursorGfxLeft[];
extern const u32 gSelectCursorGfxRight[];
extern const u16 gShinyIndicatorPalette[];
extern const u32 gShinyIndicatorGfx[];
extern const u16 gPalSummaryScreen[];
extern const u32 gTilesSummaryScreen[];
extern const u32 gMapSummaryScreenBg[];
extern const u32 gMapSummaryScreenEgg[];
extern const u32 gMapSummaryScreenKnownMoves[];
extern const u32 gMapSummaryScreenMovesInfo[];
extern const u32 gMapSummaryScreenMoves[];
extern const u32 gMapSummaryScreenMoves2[];
extern const u32 gMapSummaryScreenPokemonInfo[];
extern const u32 gMapSummaryScreenPokemonSkills[];
 
static s16 SeekToNextMonInBox(struct BoxPokemon * boxMons, u8 curIndex, u8 maxIndex, u8 flags);

static void sub_8138B8C(struct Pokemon * mon);
static void sub_8135C34(void);
static void PSS_PlayMonCry(void);
static void PSS_RemoveAllWindows(u8 curPageIndex);
static void sub_8134BAC(u8 taskId);
static void sub_8134E84(u8 taskId);
static void sub_8134840(u8 taskId);
static void sub_813B3F0(u8 taskId);
static void sub_813B120(u8, s8);
static void sub_8137E64(u8 taskId);
static void sub_8135638(void);
static void sub_81356EC(void);
static void sub_8138280(u8 curPageIndex);
static void sub_8137D28(u8 curPageIndex);
static void sub_8135514(void);
static u8 sub_81357A0(u8);
static void PSS_SetHelpContext(void);
static void sub_8138CD8(u8 taskId);
static void sub_8135AA4(void);
static void sub_8135B90(void);
static void sub_8138538(void);
static void sub_8137D28(u8 curPageIndex);
static void PSS_AddTextToWin3(void);
static void PSS_AddTextToWin4(void);
static void PSS_AddTextToWin5(void);
static void PSS_DrawMonMoveIcon(void);
static void PSS_AddTextToWin0(const u8 * str);
static void PSS_AddTextToWin1(const u8 * str);
static void PSS_AddTextToWin2(const u8 * str);
static void PSS_SetInvisibleHpBar(u8 invisible);
static void PSS_SetInvisibleExpBar(u8 invisible);
static void PSS_SetInvisibleMonSprite(u8 invisible);
static void PSS_SetInvisibleMarkings(u8 invisible);
static void PSS_SetInvisiblePokeball(u8 invisible);
static void PSS_SetInvisibleIconStatus(u8 invisible);
static void PSS_StoreEvIvContext(void);
static u8 PSS_GetSummaryModeForReturn(void);
static void CB2_ShowEvIvFromSummary(void);
static bool8 PSS_CanRenameMon(void);
static void PSS_BeginRenameFromSummary(void);
static void CB2_StartRenameFromSummary(void);
static void CB2_ReturnToSummaryFromRename(void);
static bool8 PSS_CanUseMoveRelearner(void);
static void PSS_BeginMoveRelearnerFromSummary(void);
static void CB2_StartMoveRelearnerFromSummary(void);
static void PSS_InitTilemapCache(void);
static void PSS_FreeTilemapCache(void);
static void sub_813ACF8(u8 invisible);
static void sub_813AEB0(u8 invisible);
static void sub_813A0E8(u8 invisible);
static void sub_8139EE4(u8 invisible);
static void PSS_TurnOffScreen(void);
static void PSS_InitDisplay(void);
static void PSS_ResetAll(void);
static u8 PSS_LoadTilesAndMap(void);
static u8 PSS_LoadSpritesData(void);
static void PSS_InitWindows(void);
static u8 sub_8136040(void);
static void sub_8137E28(void);
static void sub_81381C0(void);
static void sub_8136D54(void);
static void PSS_GetDataPokemon(void);
static void PSS_GetStatsPokemon(void);
static void sub_81367B0(void);
static u8 PSS_CheckMonStatus(u32 status);
static void PSS_GetMoveNames(u8);
static u16 PSS_GetMonMove(struct Pokemon * mon, u8 moveSlot);
static u16 PSS_GetMovePP(struct Pokemon * mon, u8 moveSlot);
static void PSS_LoadShinyIndicator(u16, u16);
static void PSS_LoadUnkPoint(u16, u16);
static void PSS_LoadMarkings(void);
static void PSS_LoadMovesSelectCursor(u16, u16);
static void PSS_LoadIconStatus(u16, u16);
static void PSS_LoadHpBar(u16, u16);
static void PSS_LoadExpBar(u16, u16);
static void PSS_LoadPokeball(void);
static void PSS_ClearWindow2Tilemap(void);
static void PSS_SetMovesInfoWindow4Position(void);
static void PSS_SetMonSpritePositionForPage(void);
static void PSS_SetMonIconPositionForPage(void);
static void PSS_LoadMonIcon(void);
static void PSS_LoadMonSprite(void);
static void sub_81393D4(u8 taskId);
static void sub_8137EE8(void);
static void PSS_ShowInfoPokemon(void);
static void PSS_ShowMonStats(void);
static void PSS_PrintMoveNamesOrCancel(void);
static void PSS_PrintMoveNamesAndPP(u8 i);
static void PSS_CheckIfMonIsEgg(void);
static void PSS_PrintExpPointAndNextLvTexts(void);
static void PSS_ShowAttackInfo(void);
static void PSS_CopyMoveDescriptionWrapped(u8 *dst, const u8 *src);
static void PSS_ShowEggInfo(void);
static void PSS_BufferNatureString(void);
static void PSS_GetMetLevelString(u8 *output);
static bool8 PSS_IsInGamePartnerMon(void);
static bool8 PSS_DoesMonOTMatchOwner(void);
static bool8 PSS_DidMonComeFromGBAGames(void);
static void PSS_BufferMonTrainerMemo(void);
static void PSS_ShowTrainerMemo(void);
static void PSS_PrintAbilityNameAndDescription(void);
static void PSS_DrawMoveIcon(void);
static void sub_813AF90(void);
static void sub_81380F0(void);
static void sub_81390B0(void);
static void sub_81391EC(void);
static void sub_8139328(struct Pokemon * mon);
static void sub_8139AAC(u16 spriteId);
static void sub_813A124(struct Sprite * sprite);
static void PSS_ShowIconStatus(void);
static void PSS_SetupHpBar(void);
static void PSS_SetupExpBar(void);
static void sub_813ACB4(void);
static void sub_813AF50(void);
static void PSS_UnloadMarkings(void);
static void PSS_GetMarkings(void);
static s8 sub_813B20C(s8);
static s8 sub_813B38C(s8);
static void PSS_ScrollPSSBackground(void);
u8 GetLastViewedMonIndex(void);


struct PokemonSummaryScreenData
{
    u8 window[7];

    u8 spriteId_0;
    u8 spriteId_1;
    u8 spriteId_2;

    u8 task;
    u8 unk301C;

    u8 unk3020;

    bool32 isEnemyParty; /* 0x3024 */

    struct PokeSummary
    {
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        u8 specieName[POKEMON_NAME_LENGTH + 1];
        u8 ot_name[12];
        u8 unk304C[2][12];

        u8 dexNum[5];
        u8 ot_id[7];
        u8 heldItem[ITEM_NAME_LENGTH + 1];

        u8 genderSymbol[3];
        u8 level[7];
        u8 unk3090[9];
        u8 unk309C[5][5];

        u8 unk30B8[5][11];
        u8 unk30F0[5][11];
        u8 moveName[5][MOVE_NAME_LENGTH + 1];
        u8 power[5][5];
        u8 unk3188[5][5];

        u8 unk31A4[9];
        u8 unk31B0[9];

        u8 abilityName[13];
        u8 abilityDescription[52];
    } summary;

    u8 isEgg; /* 0x3200 */
    u8 isBadEgg; /* 0x3204 */

    u8 mode; /* 0x3208 */
    u8 unk320C; /* 0x320C */
    u8 lastIndex; /* 0x3210 */
    u8 curPageIndex; /* 0x3214 */
    u8 unk3218; /* 0x3218 */
    u8 isBoxMon; /* 0x321C */
    u8 typeIcons[2]; /* 0x3220 */

    u8 unk3224; /* 0x3224 */
    u8 unk3228; /* 0x3228 */
    u8 unk322C; /* 0x322C */
    u8 unk3230; /* 0x3230 */

    u8 lockMovesFlag; /* 0x3234 */

    u8 unk3238; /* 0x3238 */
    u8 unk323C; /* 0x323C */
    u8 unk3240; /* 0x3240 */
    u8 unk3244; /* 0x3244 */
    u8 unk3248; /* 0x3248 */
    s16 unk324C; /* 0x324C */

    u16 move[5]; /* 0x3250 */
    u16 currentMove[5]; /* 0x325A */
    u8 unk3264; /* 0x3264 */
    u8 unk3268; /* 0x3268 */

    u8 monStatus; /* 0x326C */

    u8 state3270; /* 0x3270 */
    u8 state3274; /* 0x3274 */
    u8 unk3278; /* 0x3278 */
    u8 state; /* 0x327C */
    u8 unk3280; /* 0x3280 */
    u8 unk3284; /* 0x3284 */
    u8 unk3288; /* 0x3288 */
    u8 unk328C; /* 0x328C */

    struct Pokemon currentMon; /* 0x3290 */

    union
    {
        struct Pokemon * mons;
        struct BoxPokemon * boxMons;
    } monList;

    MainCallback savedCallback;
    struct Sprite * markingSprite;

    u8 unk3300[2]; /* 0x3300 */
    u8 unk3304[3]; /* 0x3304 */
    u8 unused[200]; /* 0x3304 */
};

struct Struct203B144
{
    u16 unk00;
    u16 unk02;
    u16 tileTag;
    u16 palTag;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;

    u16 unk12[5];
    u16 unk1C[5];

    u16 unk26;
};

struct Struct203B160
{
    struct Sprite * sprites[11]; /* 0x00 */
    u16 cordX[11]; /* 0x2c */
    u16 tileTag; /* 0x42 */
    u16 palTag; /* 0x44 */
};

struct Struct203B15C
{
    struct Sprite * sprites[10]; /* 0x00 */
    u16 cordX[10]; /* 0x28 */
    u16 unk3C; /* 0x3c */
    u16 unk3E; /* 0x3e */
};

struct Struct203B170
{
    u8 unk00; /* 0x00 */
    u8 tileTag; /* 0x04 */
    u8 unk08; /* 0x08 */
};

struct Struct203B148
{
    struct Sprite * sprite; /* 0x00 */
    u16 tileTag; /* 0x04 */
    u16 palTag; /* 0x06 */
    u16 unk08; /* 0x08 */
};

struct Struct203B158
{
    struct Sprite * sprite; /* 0x00 */
    u16 tileTag; /* 0x04 */
    u16 palTag; /* 0x06 */
};

struct Struct203B164
{
    struct Sprite * sprite; /* 0x00 */
    u16 tileTag; /* 0x04 */
    u16 palTag; /* 0x06 */
};

struct Struct203B168
{
    struct Sprite * sprite; /* 0x00 */
    u16 tileTag; /* 0x04 */
    u16 palTag; /* 0x06 */
};

struct SummaryScreenEvIvContext
{
    void *mons;
    u8 cursorPos;
    u8 lastIdx;
    MainCallback savedCallback;
    u8 summaryMode;
    bool8 isBoxMon;
};

struct SummaryScreenRenameContext
{
    void *mons;
    u8 cursorPos;
    u8 lastIdx;
    MainCallback savedCallback;
    u8 summaryMode;
    bool8 isBoxMon;
};

static EWRAM_DATA struct PokemonSummaryScreenData * sMonSummaryScreen;
static EWRAM_DATA struct Struct203B144 * sUnknown_203B144;
static EWRAM_DATA struct Struct203B148 * sUnknown_203B148[4];
static EWRAM_DATA struct Struct203B158 * sStatusIconSummaryScreen;
static EWRAM_DATA struct Struct203B15C * sHpBarSummaryScreen;
static EWRAM_DATA struct Struct203B160 * sExpBarSummaryScreen;
static EWRAM_DATA struct Struct203B164 * sUnknown_203B164;
static EWRAM_DATA struct Struct203B168 * sUnknown_203B168;
EWRAM_DATA u8 gLastViewedMonIndex = 0;
static EWRAM_DATA u8 sUnknown_203B16D = 0;
static EWRAM_DATA u8 sUnknown_203B16E = 0;
static EWRAM_DATA struct Struct203B170 * sUnknown_203B170;
EWRAM_DATA MainCallback gInitialSummaryScreenCallback = NULL;
static EWRAM_DATA u8 sAnimDelayTaskId = TASK_NONE;
static bool8 sExpBarIsShadow;
static struct SummaryScreenEvIvContext sEvIvContext;
static bool8 sEvIvContextActive = FALSE;
static struct SummaryScreenRenameContext sRenameContext;
static u16 *sSummaryPageTilemaps[PSS_PAGE_COUNT];
static u16 *sSummaryPageTilemapEgg;
static u16 *sSummaryMovesTilemap;
static u16 *sSummaryMovesInfoTilemap;
static bool8 sSummaryTilemapCacheReady = FALSE;
static bool8 sSummaryScreenOverridePageActive = FALSE;
static u8 sSummaryScreenOverridePage;
static MainCallback sSummaryScreenExitCallbackOverride = NULL;

static const u32 sUnknown_84636C0[] = INCBIN_U32("graphics/summary_screen_bw/pokesummary_unk_84636C0.gbapal");
static const u16 sUnknown_84636E0[] = INCBIN_U16("graphics/summary_screen_bw/pokesummary_unk_84636E0.gbapal");
static const u32 sUnknown_8463700[] = INCBIN_U32("graphics/summary_screen_bw/pokesummary_unk_8463700.gbapal");

static const struct OamData sUnknown_846398C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0
};

static const union AnimCmd sUnknown_8463994[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_846399C[] = 
{
    ANIMCMD_FRAME(0x20, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sUnknown_84639A4[] =
{
    sUnknown_8463994,
    sUnknown_846399C
};

static const struct OamData sUnknown_84639AC = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0
};

static const union AnimCmd sUnknown_84639B4[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639BC[] = 
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639C4[] = 
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639CC[] = 
{
    ANIMCMD_FRAME(12, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639D4[] = 
{
    ANIMCMD_FRAME(16, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639DC[] = 
{
    ANIMCMD_FRAME(20, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639E4[] = 
{
    ANIMCMD_FRAME(24, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_84639EC[] = 
{
    ANIMCMD_FRAME(28, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sUnknown_84639F4[] =
{
    sUnknown_84639B4,
    sUnknown_84639BC,
    sUnknown_84639C4,
    sUnknown_84639CC,
    sUnknown_84639D4,
    sUnknown_84639DC,
    sUnknown_84639E4,
    sUnknown_84639EC
};

static const struct OamData sUnknown_8463A14 = {
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
    .paletteNum = 0
};

static const union AnimCmd sUnknown_8463A1C[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A24[] = 
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A2C[] = 
{
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A34[] = 
{
    ANIMCMD_FRAME(3, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A3C[] = 
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A44[] = 
{
    ANIMCMD_FRAME(5, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A4C[] = 
{
    ANIMCMD_FRAME(6, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A54[] = 
{
    ANIMCMD_FRAME(7, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A5C[] = 
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A64[] = 
{
    ANIMCMD_FRAME(9, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A6C[] = 
{
    ANIMCMD_FRAME(10, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sUnknown_8463A74[] = 
{
    ANIMCMD_FRAME(11, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sUnknown_8463A7C[] =
{
    sUnknown_8463A1C,
    sUnknown_8463A24,
    sUnknown_8463A2C,
    sUnknown_8463A34,
    sUnknown_8463A3C,
    sUnknown_8463A44,
    sUnknown_8463A4C,
    sUnknown_8463A54,
    sUnknown_8463A5C,
    sUnknown_8463A64,
    sUnknown_8463A6C,
    sUnknown_8463A74
};

static const struct OamData sUnknown_8463AEC = {
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
    .paletteNum = 0
};

static const union AnimCmd sUnknown_8463AF4[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sUnknown_8463AFC[] =
{
    sUnknown_8463AF4
};

static const u16 sUnknown_8463B00[] = INCBIN_U16("graphics/summary_screen_bw/pokesummary_unk_8463B00.gbapal");
static const u32 sUnknown_8463B20[] = INCBIN_U32("graphics/summary_screen_bw/pokesummary_unk_8463B20.4bpp.lz");

static const struct OamData sUnknown_8463B30 =
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
    .paletteNum = 0
};

static const union AnimCmd sUnknown_8463B38[] = 
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sUnknown_8463B40[] =
{
    sUnknown_8463B38
};

static const u8 * const sUnknown_8463EC4[] =
{
    gText_EggWillTakeALongTime,
    gText_EggWillTakeSomeTime,
    gText_EggWillHatchSoon,
    gText_EggAboutToHatch,
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

#define MOVE_CATEGORY_ICON_BASE 27

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

static const struct BgTemplate SummayScreenBgTemplate[] = 
{
	{ //Text
		.bg = 0,
		.charBaseIndex = 1,
		.mapBaseIndex = 29,
		.screenSize = 0,
		.paletteMode = 0,
		.priority = 0,
		.baseTile = 0	   
	},
	{ //Page Showed
	 	.bg = 1,
	 	.charBaseIndex = 0,
	 	.mapBaseIndex = 30,
	 	.screenSize = 0,
	 	.paletteMode = 0,
	 	.priority = 2,
	 	.baseTile = 0
	 },
	 { // BG
	 	.bg = 2,
	 	.charBaseIndex = 0,
	 	.mapBaseIndex = 31,
	 	.screenSize = 0,
	 	.paletteMode = 0,
	 	.priority = 3,
	 	.baseTile = 0
	 },
	 { //Moves
	 	.bg = 3,
	 	.charBaseIndex = 0,
	 	.mapBaseIndex = 28,
	 	.screenSize = 0,
	 	.paletteMode = 0,
	 	.priority = 1,
	 	.baseTile = 0
	 }
};

static const struct WindowTemplate WindowTemplatePokemonInfo[] =
{
    { //PAGE TITLE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 13,
        .height = 2,
        .paletteNum = 7,
        .baseBlock = 0x0258
    },
    { //INSTRUCTION
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 7,
        .baseBlock = 0x0272
    },
    { // NICKNAME & LV OR TYPES
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = 10,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 0x0288
    }
};

static const struct WindowTemplate sDataMonAndNatureWindowTemplate[] = 
{
    { //Data Pokemon
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 21,
        .height = 10,
        .paletteNum = 6,
        .baseBlock = 0
    },
    { // Nature and Found place
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 12,
        .width = 28,
        .height = 8,
        .paletteNum = 6,
        .baseBlock = 220
    },
    { //DUMMY_WIN_TEMPLATE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0
    },
    { //DUMMY_WIN_TEMPLATE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0
    },
};

static const struct WindowTemplate sMonStatsAndAbilityWindowTemplate[] = 
{
    { // Pokemon Stats
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 17,
        .height = 13,
        .paletteNum = 6,
        .baseBlock = 1
    },
    { //Exp Point & Next Lv
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0
    },
    { // Ability & Description
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 29,
        .height = 5,
        .paletteNum = 6,
        .baseBlock = 292
    },
    { // DUMMY_WIN_TEMPLATE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0
    },
};

static const struct WindowTemplate sMovesInfoWindowTemplate[] = 
{
    { //Move Names
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 10,
        .height = 18,
        .paletteNum = 6,
        .baseBlock = 1
    },
    { //Move Data & Description
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 6,
        .width = 15,
        .height = 15,
        .paletteNum = 6,
        .baseBlock = 181
    },
    { //Move Icons
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 5,
        .height = 18,
        .paletteNum = 6,
        .baseBlock = 452
    },
    { //DUMMY_WIN_TEMPLATE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0
    },
};

static const struct WindowTemplate sUnknown_8463F9C[] = 
{
    {
        .bg = 255,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0x0000
    },
};

static const s8 sPSSNatureStatTable[][5] =
{
    // Atk Def Spd Sp.Atk Sp.Def
    {    0,  0,  0,     0,     0}, // Hardy
    {   +1, -1,  0,     0,     0}, // Lonely
    {   +1,  0, -1,     0,     0}, // Brave
    {   +1,  0,  0,    -1,     0}, // Adamant
    {   +1,  0,  0,     0,    -1}, // Naughty
    {   -1, +1,  0,     0,     0}, // Bold
    {    0,  0,  0,     0,     0}, // Docile
    {    0, +1, -1,     0,     0}, // Relaxed
    {    0, +1,  0,    -1,     0}, // Impish
    {    0, +1,  0,     0,    -1}, // Lax
    {   -1,  0, +1,     0,     0}, // Timid
    {    0, -1, +1,     0,     0}, // Hasty
    {    0,  0,  0,     0,     0}, // Serious
    {    0,  0, +1,    -1,     0}, // Jolly
    {    0,  0, +1,     0,    -1}, // Naive
    {   -1,  0,  0,    +1,     0}, // Modest
    {    0, -1,  0,    +1,     0}, // Mild
    {    0,  0, -1,    +1,     0}, // Quiet
    {    0,  0,  0,     0,     0}, // Bashful
    {    0,  0,  0,    +1,    -1}, // Rash
    {   -1,  0,  0,     0,    +1}, // Calm
    {    0, -1,  0,     0,    +1}, // Gentle
    {    0,  0, -1,     0,    +1}, // Sassy
    {    0,  0,  0,    -1,    +1}, // Careful
    {    0,  0,  0,     0,     0}, // Quirky
};

enum
{
	DARK,
	WHITE_TITLE,
	BLUE_SHADOW,
	WHITE,
	RED_SHADOW,
	BLUE,
	RED,
	ORANGE,
	RED_2,
	WHITE_SOLID,
};

enum
{
	tTimer,
	Offset,
};

static const u8 sPSSTextColours[][3] =
{
    [DARK] = {0, 14, 13},		//Text Dark
    [WHITE_TITLE] = {0, 1, 2}, 	//Text White (title) 
    [BLUE_SHADOW] = {0, 15, 7}, //Red Shadow
    [WHITE] = {0, 15, 14},		//Text White
    [RED_SHADOW] = {0, 15, 1}, 	//Blue Shadow
    [BLUE] = {0, 7, 6}, 		//Male Symbol
    [RED] = {0, 1, 2}, 			//Female Symbol (red)
    [ORANGE] = {0, 3, 14}, 		//Low PP
    [RED_2] = {0, 1, 14}, 		//Whithout PP
    [WHITE_SOLID] = {0, 14, 14}, //Solid light gray
};

#define TAG_MOVE_TYPES 30002
#define TAG_CATEGORY_ICONS 30004

static const struct OamData sOamData_CategoryIcons =
{
    .size = SPRITE_SIZE(16x16),
    .shape = SPRITE_SHAPE(16x16),
    .priority = 0,
};

const struct CompressedSpriteSheet gSpriteSheet_CategoryIcons =
{
    .data = gCategoryIcons_Gfx,
    .size = 16 * 16 * 3 / 2,
    .tag = TAG_CATEGORY_ICONS,
};

const struct SpritePalette gSpritePal_CategoryIcons =
{
    .data = gCategoryIcons_Pal,
    .tag = TAG_CATEGORY_ICONS
};

static const union AnimCmd sSpriteAnim_CategoryIcon0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategoryIcon1[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategoryIcon2[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_CategoryIcons[] =
{
    sSpriteAnim_CategoryIcon0,
    sSpriteAnim_CategoryIcon1,
    sSpriteAnim_CategoryIcon2,
};

const struct SpriteTemplate gSpriteTemplate_CategoryIcons =
{
    .tileTag = TAG_CATEGORY_ICONS,
    .paletteTag = TAG_CATEGORY_ICONS,
    .oam = &sOamData_CategoryIcons,
    .anims = sSpriteAnimTable_CategoryIcons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveTypes =
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

static const union AnimCmd sSpriteAnim_TypeNone[] = {
    ANIMCMD_FRAME(TYPE_NONE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeStellar[] = {
    ANIMCMD_FRAME(TYPE_STELLAR * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeShadow[] = {
    ANIMCMD_FRAME(TYPE_SHADOW * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCool[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_COOL + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryBeauty[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_BEAUTY + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCute[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_CUTE + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategorySmart[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_SMART + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryTough[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_TOUGH + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] =
{
    [TYPE_NONE] = sSpriteAnim_TypeNone,
    [TYPE_NORMAL] = sSpriteAnim_TypeNormal,
    [TYPE_FIGHTING] = sSpriteAnim_TypeFighting,
    [TYPE_FLYING] = sSpriteAnim_TypeFlying,
    [TYPE_POISON] = sSpriteAnim_TypePoison,
    [TYPE_GROUND] = sSpriteAnim_TypeGround,
    [TYPE_ROCK] = sSpriteAnim_TypeRock,
    [TYPE_BUG] = sSpriteAnim_TypeBug,
    [TYPE_GHOST] = sSpriteAnim_TypeGhost,
    [TYPE_STEEL] = sSpriteAnim_TypeSteel,
    [TYPE_MYSTERY] = sSpriteAnim_TypeMystery,
    [TYPE_FIRE] = sSpriteAnim_TypeFire,
    [TYPE_WATER] = sSpriteAnim_TypeWater,
    [TYPE_GRASS] = sSpriteAnim_TypeGrass,
    [TYPE_ELECTRIC] = sSpriteAnim_TypeElectric,
    [TYPE_PSYCHIC] = sSpriteAnim_TypePsychic,
    [TYPE_ICE] = sSpriteAnim_TypeIce,
    [TYPE_DRAGON] = sSpriteAnim_TypeDragon,
    [TYPE_DARK] = sSpriteAnim_TypeDark,
    [TYPE_FAIRY] = sSpriteAnim_TypeFairy,
    [TYPE_STELLAR] = sSpriteAnim_TypeStellar,
    [TYPE_SHADOW] = sSpriteAnim_TypeShadow,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_COOL] = sSpriteAnim_CategoryCool,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_BEAUTY] = sSpriteAnim_CategoryBeauty,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_CUTE] = sSpriteAnim_CategoryCute,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_SMART] = sSpriteAnim_CategorySmart,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_TOUGH] = sSpriteAnim_CategoryTough,
};

const struct CompressedSpriteSheet gSpriteSheet_MoveTypes =
{
    .data = gMoveTypes_Gfx,
    .size = (NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT) * 0x100,
    .tag = TAG_MOVE_TYPES
};

const struct SpriteTemplate gSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u8 sUnknown_8463FB8[] =
{
    0, 2, 3, 1, 4, 5
};

static const s8 sUnknown_8463FBE[] =
{
    -1, 0, 1
};

static const s8 sUnknown_8463FC1[] =
{
    -2, -1, 0, 1, 2
};

static const s8 sUnknown_8463FC6[] =
{
    -3, -2, -1, 0, 1, 2, 3
};

static const s8 sUnknown_8463FCD[] =
{
    -5, -3, -1, 0, 1, 3, 5
};

static const s8 sUnknown_8463FD4[] =
{
    1, 1, 0, -1, -1, 0, -1, -1, 0, 1, 1
};

static const s8 sUnknown_8463FDF[] =
{
    2, 1, 0, -1, -2, 0, -2, -1, 0, 1, 2
};

static const s8 sUnknown_8463FEA[] =
{
    2, 1, 1, 0, -1, -1, -2, 0, -2, -1, -1, 0, 1, 1, 2
};

static const u16 * const sHpBarPalettes[] =
{
    gPal0SummaryScreen,
    gPal1SummaryScreen,
    gPal2SummaryScreen,
};

#define FREE_AND_SET_NULL_IF_SET(ptr) \
{                                     \
    if (ptr != NULL)                  \
    {                                 \
        Free(ptr);                    \
        (ptr) = NULL;                 \
    }                                 \
}

static void PSS_ShowPokemonSummaryScreen(struct Pokemon * party, u8 cursorPos, u8 lastIdx, MainCallback savedCallback, u8 mode)
{
    sMonSummaryScreen = AllocZeroed(sizeof(struct PokemonSummaryScreenData));
    sUnknown_203B144 = AllocZeroed(sizeof(struct Struct203B144));

    if (sMonSummaryScreen == NULL)
    {
        SetMainCallback2(savedCallback);
        return;
    }

    gLastViewedMonIndex = cursorPos;

    sUnknown_203B16D = 0;
    sUnknown_203B16E = 0;
    sMonSummaryScreen->savedCallback = savedCallback;
    sMonSummaryScreen->monList.mons = party;
    if (party == gEnemyParty)
        sMonSummaryScreen->isEnemyParty = TRUE;
    else
        sMonSummaryScreen->isEnemyParty = FALSE;

    sMonSummaryScreen->lastIndex = lastIdx;
    sMonSummaryScreen->mode = mode;

    switch (sMonSummaryScreen->mode)
    {
    case PSS_MODE_NORMAL:
    default:
        sMonSummaryScreen->curPageIndex = PSS_PAGE_INFO;
        sMonSummaryScreen->isBoxMon = FALSE;
        sMonSummaryScreen->lockMovesFlag = FALSE;
        break;
    case PSS_MODE_BOX:
        sMonSummaryScreen->curPageIndex = PSS_PAGE_INFO;
        sMonSummaryScreen->isBoxMon = TRUE;
        sMonSummaryScreen->lockMovesFlag = FALSE;
        break;
    case PSS_MODE_SELECT_MOVE:
    case PSS_MODE_FORGET_MOVE:
        sMonSummaryScreen->curPageIndex = PSS_PAGE_MOVES_INFO;
        sMonSummaryScreen->isBoxMon = FALSE;
        sMonSummaryScreen->lockMovesFlag = TRUE;
        break;
    }

    if (sSummaryScreenOverridePageActive
        && (sMonSummaryScreen->mode == PSS_MODE_NORMAL || sMonSummaryScreen->mode == PSS_MODE_BOX)
        && sSummaryScreenOverridePage < PSS_PAGE_COUNT)
    {
        sMonSummaryScreen->curPageIndex = sSummaryScreenOverridePage;
    }
    sSummaryScreenOverridePageActive = FALSE;

    sMonSummaryScreen->state3270 = 0;
    sMonSummaryScreen->state3274 = 0;
    sMonSummaryScreen->unk3278 = 0;
    sMonSummaryScreen->state = 0;

    sMonSummaryScreen->unk3238 = 0;
    sMonSummaryScreen->unk323C = 2;
    sMonSummaryScreen->unk3240 = 1;
    sMonSummaryScreen->unk3244 = FALSE;

    sMonSummaryScreen->unk3228 = 0;
    sMonSummaryScreen->unk322C = 1;

    sub_8138B8C(&sMonSummaryScreen->currentMon);
    sMonSummaryScreen->isEgg = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_EGG);
    sMonSummaryScreen->isBadEgg = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SANITY_IS_BAD_EGG);

    if (sMonSummaryScreen->isBadEgg == TRUE)
        sMonSummaryScreen->isEgg = TRUE;

    sMonSummaryScreen->unk3300[0] = 0xff;
    PSS_InitTilemapCache();
    SetMainCallback2(sub_8135C34);
}

void ShowSelectMovePokemonSummaryScreen(struct Pokemon * party, u8 cursorPos, u8 lastIdx, MainCallback savedCallback, u16 a4)
{
    PSS_ShowPokemonSummaryScreen(party, cursorPos, lastIdx, savedCallback, PSS_MODE_SELECT_MOVE);
    sMonSummaryScreen->currentMove[4] = a4;
}

void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    u8 pssMode = PSS_MODE_NORMAL;
    bool8 lockMoves = FALSE;

    switch (mode)
    {
    case SUMMARY_MODE_LOCK_MOVES:
        pssMode = PSS_MODE_NORMAL;
        lockMoves = TRUE;
        break;
    case SUMMARY_MODE_BOX:
    case SUMMARY_MODE_BOX_CURSOR:
        pssMode = PSS_MODE_BOX;
        lockMoves = (mode == SUMMARY_MODE_BOX_CURSOR);
        break;
    case SUMMARY_MODE_SELECT_MOVE:
    case SUMMARY_MODE_RELEARNER_BATTLE:
    case SUMMARY_MODE_RELEARNER_CONTEST:
        pssMode = PSS_MODE_SELECT_MOVE;
        lockMoves = TRUE;
        break;
    case SUMMARY_MODE_NORMAL:
    default:
        pssMode = PSS_MODE_NORMAL;
        break;
    }

    gInitialSummaryScreenCallback = callback;
    PSS_ShowPokemonSummaryScreen((struct Pokemon *)mons, monIndex, maxMonIndex, callback, pssMode);

    if (sMonSummaryScreen != NULL && lockMoves)
        sMonSummaryScreen->lockMovesFlag = TRUE;
}

void ShowPokemonSummaryScreenHandleDeoxys(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen(mode, mons, monIndex, maxMonIndex, callback);
}

static u8 PSS_GetSummaryModeForReturn(void)
{
    switch (sMonSummaryScreen->mode)
    {
    case PSS_MODE_BOX:
        return sMonSummaryScreen->lockMovesFlag ? SUMMARY_MODE_BOX_CURSOR : SUMMARY_MODE_BOX;
    case PSS_MODE_SELECT_MOVE:
    case PSS_MODE_FORGET_MOVE:
        return SUMMARY_MODE_SELECT_MOVE;
    case PSS_MODE_NORMAL:
    default:
        return sMonSummaryScreen->lockMovesFlag ? SUMMARY_MODE_LOCK_MOVES : SUMMARY_MODE_NORMAL;
    }
}

static void PSS_StoreEvIvContext(void)
{
    sEvIvContext.mons = sMonSummaryScreen->isBoxMon
        ? (void *)sMonSummaryScreen->monList.boxMons
        : (void *)sMonSummaryScreen->monList.mons;
    sEvIvContext.cursorPos = gLastViewedMonIndex;
    sEvIvContext.lastIdx = sMonSummaryScreen->lastIndex;
    sEvIvContext.savedCallback = sMonSummaryScreen->savedCallback;
    sEvIvContext.summaryMode = PSS_GetSummaryModeForReturn();
    sEvIvContext.isBoxMon = sMonSummaryScreen->isBoxMon;
    sEvIvContextActive = TRUE;
}

static void CB2_ShowEvIvFromSummary(void)
{
    if (!sEvIvContextActive)
    {
        SetMainCallback2(sEvIvContext.savedCallback);
        return;
    }

    Show_EvIv((struct Pokemon *)sEvIvContext.mons,
              sEvIvContext.cursorPos,
              sEvIvContext.lastIdx,
              sEvIvContext.savedCallback,
              sEvIvContext.isBoxMon,
              TRUE);
}

void SummaryScreen_ReturnFromEvIv(u8 cursorPos)
{
    if (!sEvIvContextActive)
        return;

    sSummaryScreenOverridePage = PSS_PAGE_SKILLS;
    sSummaryScreenOverridePageActive = TRUE;
    ShowPokemonSummaryScreen(sEvIvContext.summaryMode,
                             sEvIvContext.mons,
                             cursorPos,
                             sEvIvContext.lastIdx,
                             sEvIvContext.savedCallback);
    sEvIvContextActive = FALSE;
}

static void PSS_InitTilemapCache(void)
{
    u8 i;

    if (sSummaryTilemapCacheReady)
        return;

    for (i = 0; i < PSS_PAGE_COUNT; i++)
        sSummaryPageTilemaps[i] = AllocZeroed(SUMMARY_PAGE_TILEMAP_SIZE);

    sSummaryPageTilemapEgg = AllocZeroed(SUMMARY_PAGE_TILEMAP_SIZE);
    sSummaryMovesTilemap = AllocZeroed(SUMMARY_PAGE_TILEMAP_SIZE);
    sSummaryMovesInfoTilemap = AllocZeroed(SUMMARY_PAGE_TILEMAP_SIZE);

    for (i = 0; i < PSS_PAGE_COUNT; i++)
    {
        if (sSummaryPageTilemaps[i] == NULL)
        {
            PSS_FreeTilemapCache();
            return;
        }
    }

    if (sSummaryPageTilemapEgg == NULL || sSummaryMovesTilemap == NULL || sSummaryMovesInfoTilemap == NULL)
    {
        PSS_FreeTilemapCache();
        return;
    }

    LZ77UnCompWram(gMapSummaryScreenPokemonInfo, sSummaryPageTilemaps[PSS_PAGE_INFO]);
    LZ77UnCompWram(gMapSummaryScreenEgg, sSummaryPageTilemapEgg);
    LZ77UnCompWram(gMapSummaryScreenPokemonSkills, sSummaryPageTilemaps[PSS_PAGE_SKILLS]);
    LZ77UnCompWram(gMapSummaryScreenKnownMoves, sSummaryPageTilemaps[PSS_PAGE_MOVES]);
    LZ77UnCompWram(gMapSummaryScreenMovesInfo, sSummaryPageTilemaps[PSS_PAGE_MOVES_INFO]);
    LZ77UnCompWram(gMapSummaryScreenMoves2, sSummaryMovesTilemap);
    LZ77UnCompWram(gMapSummaryScreenMoves, sSummaryMovesInfoTilemap);

    sSummaryTilemapCacheReady = TRUE;
}

static void PSS_FreeTilemapCache(void)
{
    u8 i;

    for (i = 0; i < PSS_PAGE_COUNT; i++)
        FREE_AND_SET_NULL_IF_SET(sSummaryPageTilemaps[i]);

    FREE_AND_SET_NULL_IF_SET(sSummaryPageTilemapEgg);
    FREE_AND_SET_NULL_IF_SET(sSummaryMovesTilemap);
    FREE_AND_SET_NULL_IF_SET(sSummaryMovesInfoTilemap);

    sSummaryTilemapCacheReady = FALSE;
}

static bool8 PSS_CanRenameMon(void)
{
#if P_SUMMARY_SCREEN_RENAME
    if (sMonSummaryScreen->isEgg)
        return FALSE;
    if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW))
        return FALSE;
    if (sMonSummaryScreen->isEnemyParty)
        return FALSE;
    if (gMain.inBattle || gReceivedRemoteLinkPlayers)
        return FALSE;
    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE || sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
        return FALSE;
    if (!PSS_DoesMonOTMatchOwner())
        return FALSE;
    return TRUE;
#else
    return FALSE;
#endif
}

static void PSS_BeginRenameFromSummary(void)
{
    sRenameContext.mons = sMonSummaryScreen->isBoxMon
        ? (void *)sMonSummaryScreen->monList.boxMons
        : (void *)sMonSummaryScreen->monList.mons;
    sRenameContext.cursorPos = gLastViewedMonIndex;
    sRenameContext.lastIdx = sMonSummaryScreen->lastIndex;
    sRenameContext.savedCallback = sMonSummaryScreen->savedCallback;
    sRenameContext.summaryMode = PSS_GetSummaryModeForReturn();
    sRenameContext.isBoxMon = sMonSummaryScreen->isBoxMon;

    sSummaryScreenExitCallbackOverride = CB2_StartRenameFromSummary;
    sMonSummaryScreen->state3270 = PSS_STATE3270_4;
}

static void CB2_StartRenameFromSummary(void)
{
    if (sRenameContext.isBoxMon)
    {
        struct BoxPokemon *boxMon = &((struct BoxPokemon *)sRenameContext.mons)[sRenameContext.cursorPos];
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar3);
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar2);
        DoNamingScreen(NAMING_SCREEN_NICKNAME,
                       gStringVar2,
                       GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL),
                       GetBoxMonGender(boxMon),
                       GetBoxMonData(boxMon, MON_DATA_PERSONALITY, NULL),
                       GetBoxMonData(boxMon, MON_DATA_IS_SHADOW, NULL),
                       CB2_ReturnToSummaryFromRename);
    }
    else
    {
        struct Pokemon *mon = &((struct Pokemon *)sRenameContext.mons)[sRenameContext.cursorPos];
        GetMonData(mon, MON_DATA_NICKNAME, gStringVar3);
        GetMonData(mon, MON_DATA_NICKNAME, gStringVar2);
        DoNamingScreen(NAMING_SCREEN_NICKNAME,
                       gStringVar2,
                       GetMonData(mon, MON_DATA_SPECIES, NULL),
                       GetMonGender(mon),
                       GetMonData(mon, MON_DATA_PERSONALITY, NULL),
                       GetMonData(mon, MON_DATA_IS_SHADOW, NULL),
                       CB2_ReturnToSummaryFromRename);
    }
}

static void CB2_ReturnToSummaryFromRename(void)
{
    if (sRenameContext.isBoxMon)
    {
        struct BoxPokemon *boxMon = &((struct BoxPokemon *)sRenameContext.mons)[sRenameContext.cursorPos];
        SetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar2);
    }
    else
    {
        struct Pokemon *mon = &((struct Pokemon *)sRenameContext.mons)[sRenameContext.cursorPos];
        SetMonData(mon, MON_DATA_NICKNAME, gStringVar2);
    }

    sSummaryScreenOverridePage = PSS_PAGE_INFO;
    sSummaryScreenOverridePageActive = TRUE;
    ShowPokemonSummaryScreen(sRenameContext.summaryMode,
                             sRenameContext.mons,
                             sRenameContext.cursorPos,
                             sRenameContext.lastIdx,
                             sRenameContext.savedCallback);
}

static bool8 PSS_CanUseMoveRelearner(void)
{
#if P_SUMMARY_SCREEN_MOVE_RELEARNER
    if (sMonSummaryScreen->isEgg)
        return FALSE;
    if (sMonSummaryScreen->isEnemyParty || sMonSummaryScreen->isBoxMon)
        return FALSE;
    if (gMain.inBattle || gReceivedRemoteLinkPlayers)
        return FALSE;
    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE || sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
        return FALSE;
    if (GetNumberOfRelearnableMoves(&sMonSummaryScreen->currentMon) == 0)
        return FALSE;
    return TRUE;
#else
    return FALSE;
#endif
}

static void PSS_BeginMoveRelearnerFromSummary(void)
{
    gSpecialVar_0x8004 = gLastViewedMonIndex;
    gOriginSummaryScreenPage = PSS_PAGE_MOVES;
    sSummaryScreenExitCallbackOverride = CB2_StartMoveRelearnerFromSummary;
    sMonSummaryScreen->state3270 = PSS_STATE3270_4;
    gTasks[sMonSummaryScreen->task].func = sub_8134840;
}

static void CB2_StartMoveRelearnerFromSummary(void)
{
    SetMainCallback2(CB2_InitLearnMove);
}

static u8 sub_813476C(u8 a0)
{
    if (sMonSummaryScreen->unk301C == TRUE && sMonSummaryScreen->unk3224 != a0)
        return TRUE;

    return FALSE;
}

u32 sub_81347A4(u8 a0)
{
    if (sMonSummaryScreen->isEgg)
        return FALSE;

    if (sMonSummaryScreen->unk3300[0] != 0xff && sMonSummaryScreen->unk3300[0] == a0)
    {
        sMonSummaryScreen->unk3300[0] = 0xff;
        return TRUE;
    }

    if (sub_813476C(a0))
        return FALSE;

    switch (a0)
    {
    case 1:
        if (JOY_NEW(DPAD_RIGHT))
            return TRUE;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR && JOY_NEW(R_BUTTON))
            return TRUE;

        break;
    case 0:
        if (JOY_NEW(DPAD_LEFT))
            return TRUE;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR && JOY_NEW(L_BUTTON))
        {
            if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES
                && sMonSummaryScreen->unk3268 != TRUE
                && PSS_CanUseMoveRelearner())
                return FALSE;
            return TRUE;
        }

        break;
    }

    return FALSE;
}

static void sub_8134840(u8 taskId)
{
    switch (sMonSummaryScreen->state3270) {
    case PSS_STATE3270_0:
        BeginNormalPaletteFade(0xffffffff, 0, 16, 0, 0);
        sMonSummaryScreen->state3270 = PSS_STATE3270_1;
        break;
    case PSS_STATE3270_1:
        if (!gPaletteFade.active)
        {
            PSS_PlayMonCry();
            sMonSummaryScreen->state3270 = PSS_STATE3270_2;
            return;
        }

        sMonSummaryScreen->state3270 = PSS_STATE3270_1;
        break;
    case PSS_STATE3270_2:
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE)
            return;
        else if (MenuHelpers_IsLinkActive() == TRUE)
            return;
        else if (FuncIsActiveTask(sub_813B3F0))
            return;

        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
        {
            if (sub_81347A4(1) == TRUE)
            {
                if (FuncIsActiveTask(sub_8134BAC))
                {
                    sMonSummaryScreen->unk3300[0] = 1;
                    return;
                }
                else if (sMonSummaryScreen->curPageIndex < PSS_PAGE_MOVES)
                {
                    PlaySE(SE_SELECT);
                    sMonSummaryScreen->unk3224 = 1;
                    PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
                    sMonSummaryScreen->curPageIndex++;
                    PSS_ClearWindow2Tilemap();
                    PSS_SetMonSpritePositionForPage();
                    PSS_SetMonIconPositionForPage();
                    sMonSummaryScreen->state3270 = PSS_STATE3270_3;
                }
                return;
            }
            else if (sub_81347A4(0) == TRUE)
            {
                if (FuncIsActiveTask(sub_8134BAC))
                {
                    sMonSummaryScreen->unk3300[0] = 0;
                    return;
                }
                else if (sMonSummaryScreen->curPageIndex > PSS_PAGE_INFO)
                {
                    PlaySE(SE_SELECT);
                    sMonSummaryScreen->unk3224 = 0;
                    PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
                    sMonSummaryScreen->curPageIndex--;
                    PSS_ClearWindow2Tilemap();
                    PSS_SetMonSpritePositionForPage();
                    PSS_SetMonIconPositionForPage();
                    sMonSummaryScreen->state3270 = PSS_STATE3270_3;
                }
                return;
            }
        }

        if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES
            && JOY_NEW(L_BUTTON)
            && sMonSummaryScreen->unk3268 != TRUE
            && PSS_CanUseMoveRelearner())
        {
            PlaySE(SE_SELECT);
            PSS_BeginMoveRelearnerFromSummary();
            return;
        }

        if ((!FuncIsActiveTask(sub_8134BAC)) || FuncIsActiveTask(sub_813B3F0))
        {
            if (JOY_NEW(DPAD_UP))
            {
                sub_813B120(taskId, -1);
                return;
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                sub_813B120(taskId, 1);
                return;
            }
            else if (JOY_NEW(A_BUTTON))
            {
                if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO)
                {
                    PlaySE(SE_SELECT);
                    if (PSS_CanRenameMon())
                        PSS_BeginRenameFromSummary();
                    else
                        sMonSummaryScreen->state3270 = PSS_STATE3270_4;
                }
                else if (sMonSummaryScreen->curPageIndex == PSS_PAGE_SKILLS
                         && FlagGet(FLAG_EV_IV)
                         && sMonSummaryScreen->mode != PSS_MODE_SELECT_MOVE
                         && sMonSummaryScreen->mode != PSS_MODE_FORGET_MOVE)
                {
                    PlaySE(SE_RG_CARD_OPEN);
                    PSS_StoreEvIvContext();
                    sSummaryScreenExitCallbackOverride = CB2_ShowEvIvFromSummary;
                    sMonSummaryScreen->state3270 = PSS_STATE3270_4;
                }
                else if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES)
                {
                    PlaySE(SE_SELECT);
                    sMonSummaryScreen->unk3224 = 1;
                    PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
                    sMonSummaryScreen->curPageIndex++;
                    PSS_ClearWindow2Tilemap();
                    PSS_SetMonSpritePositionForPage();
                    PSS_SetMonIconPositionForPage();
                    sMonSummaryScreen->state3270 = PSS_STATE3270_3;
                }
                return;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                sMonSummaryScreen->state3270 = PSS_STATE3270_4;
            }
        }
        break;
    case PSS_STATE3270_3:
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
        {
            CreateTask(sub_8134BAC, 0);
            sMonSummaryScreen->state3270 = PSS_STATE3270_2;
        }
        else
        {
            gTasks[sMonSummaryScreen->task].func = sub_8134E84;
            sMonSummaryScreen->state3270 = PSS_STATE3270_2;
        }
        break;
    case PSS_STATE3270_4:
        BeginNormalPaletteFade(0xffffffff, 0, 0, 16, 0);
        sMonSummaryScreen->state3270 = PSS_STATE3270_5;
        break;
    case PSS_STATE3270_5:
		SetGpuReg(REG_OFFSET_BLDCNT, 0);
		SetGpuReg(REG_OFFSET_BLDALPHA, 0);

        if (GetLinkRecvQueueLength() > 2)
            return;
        else if (MenuHelpers_IsLinkActive() == TRUE)
            return;

        sMonSummaryScreen->state3270 = PSS_STATE3270_6;
        break;
    default:
        if (!gPaletteFade.active)
            sub_8137E64(taskId);

        break;
    }
}

static void sub_8134BAC(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        sub_8135638();
        sub_81356EC();
        sMonSummaryScreen->lockMovesFlag = TRUE;
        sMonSummaryScreen->unk301C = TRUE;
        sub_8138280(sMonSummaryScreen->curPageIndex);
        break;
    case 1:
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
        {
            if (!(sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES && sMonSummaryScreen->unk3224 == 0))
            {
				
            }
        }
        break;
    case 2:
        sub_8135AA4();
        sub_8135B90();
        sub_8138538();
        sub_8137D28(sMonSummaryScreen->curPageIndex);
        break;
    case 3:
        CopyWindowToVram(sMonSummaryScreen->window[0], 2);
        CopyWindowToVram(sMonSummaryScreen->window[1], 2);
        CopyWindowToVram(sMonSummaryScreen->window[2], 2);
        break;
    case 4:
        break;
    case 5:
        sub_8135514();
        sMonSummaryScreen->unk3244 = TRUE;
        break;
    case 6:
        if (!sub_81357A0(sMonSummaryScreen->unk3224))
            return;

        break;
    case 7:
        PSS_AddTextToWin3();
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
            PSS_AddTextToWin4();

        PSS_AddTextToWin5();
        PSS_DrawMonMoveIcon();
        break;
    case 8:
        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        break;
    case 9:
        HideBg(0);
		if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(0);
            ShowBg(0);
        }
        else
            return;

        break;
    default:
        PSS_SetHelpContext();

        if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
            gTasks[sMonSummaryScreen->task].func = sub_8138CD8;

        DestroyTask(taskId);
        data[0] = 0;
        sMonSummaryScreen->lockMovesFlag = FALSE;
        sMonSummaryScreen->unk301C = FALSE;
        return;
    }

    data[0]++;
}

static void sub_8134E84(u8 taskId)
{
    switch (sMonSummaryScreen->unk3284)
    {
    case 0:
        sMonSummaryScreen->lockMovesFlag = TRUE;
        sMonSummaryScreen->unk301C = TRUE;
        sub_8138280(sMonSummaryScreen->curPageIndex);
        break;
    case 1:
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
        {
            if (!(sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES && sMonSummaryScreen->unk3224 == 0))
            {
				
            }
        }
        break;
    case 2:
        sub_8135638();
        sub_8135B90();
        sub_8138538();
        sub_8135AA4();
        break;
    case 3:
		PSS_AddTextToWin0(gText_8419C39);

        if (!(gMain.inBattle || gReceivedRemoteLinkPlayers))
		{
			PSS_AddTextToWin1(gText_8419C45);
		}
        else
		{
			PSS_AddTextToWin1(gText_8419C45);
		}
        break;
    case 4:
        CopyWindowToVram(sMonSummaryScreen->window[0], 2);
        CopyWindowToVram(sMonSummaryScreen->window[1], 2);
        break;
    case 5:
        break;
    case 6:
        PSS_AddTextToWin3();
        PSS_AddTextToWin5();
        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        break;
    case 7:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(0);
            sub_8135514();
            sMonSummaryScreen->unk3244 = TRUE;
        }
        else
            return;
        break;
    case 8:
        if (!sub_81357A0(sMonSummaryScreen->unk3224))
            return;

        PSS_AddTextToWin4();
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        break;
    case 9:
        PSS_DrawMonMoveIcon();
        {
            const u8 *actionText;

            if (sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
                actionText = gText_8419CA9;
            else if (!gMain.inBattle)
                actionText = gText_8419C92;
            else
                actionText = gText_8419CA2;
            PSS_AddTextToWin2(actionText);
        }
        break;
    case 10:
        sub_81356EC();
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        CopyWindowToVram(sMonSummaryScreen->window[2], 2);
        break;
    case 11:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(0);
        }
        else
            return;
        break;
    default:
        PSS_SetHelpContext();
        gTasks[sMonSummaryScreen->task].func = sub_8138CD8;
        sMonSummaryScreen->unk3284 = 0;
        sMonSummaryScreen->lockMovesFlag = FALSE;
        sMonSummaryScreen->unk301C = FALSE;
        return;
    }

    sMonSummaryScreen->unk3284++;
    return;
}

static void sub_81351A0(u8 taskId)
{
    switch (sMonSummaryScreen->unk3284)
    {
    case 0:
        sMonSummaryScreen->lockMovesFlag = TRUE;
        sMonSummaryScreen->unk301C = TRUE;
        sub_8138280(sMonSummaryScreen->curPageIndex);
        break;
    case 1:
        break;
    case 2:
        sub_8135AA4();
        break;
    case 3:
        PSS_AddTextToWin3();
        PSS_AddTextToWin4();
        PSS_AddTextToWin5();
        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyBgTilemapBufferToVram(0);
        break;
    case 4:
		PSS_AddTextToWin0(gText_8419C39);
        if (PSS_CanUseMoveRelearner())
            PSS_AddTextToWin1(gText_8419C45);
        else
		    PSS_AddTextToWin1(gText_8419C45);
        break;
    case 5:
        CopyWindowToVram(sMonSummaryScreen->window[0], 2);
        CopyWindowToVram(sMonSummaryScreen->window[1], 2);
        break;
    case 6:
        sub_8135514();
        sMonSummaryScreen->unk3244 = TRUE;
        sub_8135638();
        PSS_DrawMonMoveIcon();
        break;
    case 7:
        break;
    case 8:
        if (sub_81357A0(sMonSummaryScreen->unk3224) == 0)
            return;

        {
            const u8 *actionText;

            if (PSS_CanUseMoveRelearner())
                actionText = gText_PSS_RelearnL;
            else
                actionText = gText_8419C82;
            PSS_AddTextToWin2(actionText);
        }
        break;
    case 9:
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        CopyWindowToVram(sMonSummaryScreen->window[2], 2);
        CopyBgTilemapBufferToVram(0);
        break;
    case 10:
        sub_8135B90();
        sub_8138538();
        sub_81356EC();
        break;
    default:
        PSS_SetHelpContext();
        gTasks[sMonSummaryScreen->task].func = sub_8134840;
        sMonSummaryScreen->unk3284 = 0;
        sMonSummaryScreen->lockMovesFlag = FALSE;
        sMonSummaryScreen->unk301C = FALSE;
        return;
    }

    sMonSummaryScreen->unk3284++;
    return;
}

static void sub_8135514(void)
{
    s8 pageDelta = 1;

    if (sMonSummaryScreen->unk3224 == 1)
        pageDelta = -1;

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
    {
        sMonSummaryScreen->unk324C = 240;
        return;
    }

    if ((sMonSummaryScreen->curPageIndex + pageDelta) == PSS_PAGE_MOVES_INFO)
    {
        sMonSummaryScreen->unk324C = 0;
        return;
    }
    if (sMonSummaryScreen->unk3224 == 1)
        sMonSummaryScreen->unk324C = 0;
    if (sMonSummaryScreen->curPageIndex != PSS_PAGE_SKILLS)
	{
		PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
	}
    else
	{
		PSS_SetInvisibleHpBar(0);
		PSS_SetInvisibleExpBar(0);
	}
}

static void sub_8135638(void)
{
    u8 newPage;

    if (sMonSummaryScreen->unk3224 == 1)
        newPage = sMonSummaryScreen->curPageIndex - 1;
    else
        newPage = sMonSummaryScreen->curPageIndex + 1;

    switch (newPage)
    {
    case PSS_PAGE_INFO:
        PSS_SetInvisibleHpBar(1);
        PSS_SetInvisibleExpBar(1);
        break;
    case PSS_PAGE_SKILLS:
        PSS_SetInvisibleHpBar(0);
        PSS_SetInvisibleExpBar(0);
        break;
    case PSS_PAGE_MOVES:
        if (sMonSummaryScreen->unk3224 == 1)
        {
            PSS_SetInvisibleMonSprite(1);
            PSS_SetInvisibleMarkings(1);
            PSS_SetInvisiblePokeball(1);
            PSS_SetInvisibleIconStatus(1);
            sub_813ACF8(1);
            sub_813AEB0(1);
			PSS_SetInvisibleHpBar(1);
			PSS_SetInvisibleExpBar(1);
        }

        break;
    case PSS_PAGE_MOVES_INFO:
        sub_813A0E8(1);
        sub_8139EE4(1);
        PSS_SetInvisibleIconStatus(1);
        sub_813ACF8(1);
        sub_813AEB0(1);
        PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
        break;
    }
}

static void sub_81356EC(void)
{
    u8 newPage;

    if (sMonSummaryScreen->unk3224 == 1)
        newPage = sMonSummaryScreen->curPageIndex - 1;
    else
        newPage = sMonSummaryScreen->curPageIndex + 1;

    switch (newPage)
    {
    case PSS_PAGE_INFO:
        PSS_SetInvisibleHpBar(1);
        PSS_SetInvisibleExpBar(1);
        break;
    case PSS_PAGE_SKILLS:
        break;
    case PSS_PAGE_MOVES:
        if (sMonSummaryScreen->unk3224 != 0)
        {
            sub_813A0E8(0);
            sub_813ACF8(0);
            sub_8139EE4(0);
            sub_813AEB0(0);
        }
        break;
    case PSS_PAGE_MOVES_INFO:
        PSS_SetInvisibleMonSprite(0);
        PSS_SetInvisibleMarkings(0);
        PSS_SetInvisibleIconStatus(0);
        PSS_SetInvisiblePokeball(0);
        sub_813ACF8(0);
        sub_813AEB0(0);
        break;
    }
}

static u8 sub_81357A0(u8 a0)
{
    s8 pageDelta = 1;

    if (sMonSummaryScreen->unk3224 == 1)
        pageDelta = -1;

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
        if (sMonSummaryScreen->unk324C <= 0)
        {
            sMonSummaryScreen->unk324C = 0;
            sMonSummaryScreen->unk3238 ^= 1;
            sMonSummaryScreen->unk3244 = FALSE;
            return TRUE;
        }

    if ((sMonSummaryScreen->curPageIndex + pageDelta) == PSS_PAGE_MOVES_INFO)
        if (sMonSummaryScreen->unk324C >= 240)
        {
            sMonSummaryScreen->unk324C = 240;
            sMonSummaryScreen->unk3238 ^= 1;
            sMonSummaryScreen->unk3244 = FALSE;
            return TRUE;
        }

    if (sMonSummaryScreen->unk3224 == 1)
    {
        if (sMonSummaryScreen->unk324C >= 240)
        {
            sMonSummaryScreen->unk324C = 240;
            sMonSummaryScreen->unk3238 ^= 1;
            sMonSummaryScreen->unk3244 = FALSE;
            return TRUE;
        }
    }
    else if (sMonSummaryScreen->unk324C <= 0)
    {
        sMonSummaryScreen->unk3238 ^= 1;
        sMonSummaryScreen->unk324C = 0;
        sMonSummaryScreen->unk3244 = FALSE;
        return TRUE;
    }

    return FALSE;
}

static void sub_8135AA4(void)
{
    u8 newPage;

    if (sMonSummaryScreen->unk3224 == 1)
        newPage = sMonSummaryScreen->curPageIndex - 1;
    else
        newPage = sMonSummaryScreen->curPageIndex + 1;

    switch (newPage)
    {
    case PSS_PAGE_INFO:
        break;
    case PSS_PAGE_SKILLS:
        break;
    case PSS_PAGE_MOVES:
        break;
    case PSS_PAGE_MOVES_INFO:
        break;
    }
}

static void sub_8135B90(void)
{
    u8 newPage;

    if (sMonSummaryScreen->unk3224 == 1)
        newPage = sMonSummaryScreen->curPageIndex - 1;
    else
        newPage = sMonSummaryScreen->curPageIndex + 1;

    switch (newPage)
    {
    case PSS_PAGE_INFO:
        break;
    case PSS_PAGE_SKILLS:
        break;
    case PSS_PAGE_MOVES:
        break;
    case PSS_PAGE_MOVES_INFO:
        break;
    }
}

static void sub_8135C34(void)
{
    switch (sMonSummaryScreen->state3274)
    {
    case 0:
        PSS_TurnOffScreen();
        break;
    case 1:
        PSS_InitDisplay();
        break;
    case 2:
        PSS_ResetAll();
        break;
    case 3:
        if (!PSS_LoadTilesAndMap())
            return;
        break;
    case 4:
        if (!PSS_LoadSpritesData())
            return;
        break;
    case 5:
        PSS_InitWindows();
        break;
    case 6:
        if (!sub_8136040())
            return;
        break;
    case 7:
        PSS_AddTextToWin3();
        break;
    case 8:
        PSS_AddTextToWin4();
        break;
    case 9:
        PSS_AddTextToWin5();
        PSS_DrawMonMoveIcon();
        break;
    case 10:
        sub_8138538();
        break;
    case 11:
        break;
    case 12:
        BlendPalettes(0xffffffff, 16, 0);
        sub_8137D28(sMonSummaryScreen->curPageIndex);
        sub_8137E28();
        break;
    case 13:
        BeginNormalPaletteFade(0xffffffff, 0, 16, 0, 0);
        CopyWindowToVram(sMonSummaryScreen->window[0], 2);
        CopyWindowToVram(sMonSummaryScreen->window[1], 2);
        CopyWindowToVram(sMonSummaryScreen->window[2], 2);
        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        break;
    case 14:
        CopyBgTilemapBufferToVram(0);
        break;
    case 15:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE || sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
        {
            sub_8139EE4(0);
            sub_813A0E8(0);
        }
        else
        {
            PSS_SetInvisibleMonSprite(0);
            PSS_SetInvisibleMarkings(0);
            PSS_SetInvisiblePokeball(0);
        }

		PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
        PSS_SetInvisibleIconStatus(0);
        sub_813ACF8(0);
        sub_813AEB0(0);
        break;
    default:
        sub_81381C0();
        sub_8136D54();
        return;
    }

    sMonSummaryScreen->state3274++;
}

static u8 PSS_LoadTilesAndMap(void)
{
    switch (sMonSummaryScreen->unk3278)
    {
    case 0:
        LoadPalette(gPalSummaryScreen, 0, 0x20);
        break;
    case 1:
        ListMenuLoadStdPalAt(0x60, 1);
        LoadPalette(sUnknown_84636C0, 0x70, 0x20);
        break;
    case 2:
        LZ77UnCompVram(gTilesSummaryScreen, (void *)(VRAM));
        break;
    case 3:
        LZ77UnCompVram(gMapSummaryScreenBg, (void *)(VRAM + 0xF800));
        break;
    case 4:
        LZ77UnCompVram(gMapSummaryScreenBg, (void *)(VRAM + 0xF800));
        break;
    case 5:
        LoadPalette(sUnknown_8463700, 0x80, 0x20);
        return TRUE;
    }

    sMonSummaryScreen->unk3278++;
    return FALSE;
}

static u8 sub_8136040(void)
{
    switch (sMonSummaryScreen->unk3280)
    {
    case 0:
        PSS_GetDataPokemon();
        if (sMonSummaryScreen->isEgg)
        {
            sMonSummaryScreen->unk3280 = 0;
            return TRUE;
        }

        break;
    case 1:
        if (sMonSummaryScreen->isEgg == 0)
            PSS_GetStatsPokemon();
        break;
    case 2:
        if (sMonSummaryScreen->isEgg == 0)
            sub_81367B0();
        break;
    default:
        sMonSummaryScreen->unk3280 = 0;
        return TRUE;
    }

    sMonSummaryScreen->unk3280++;
    return FALSE;
}

static void PSS_GetDataPokemon(void)
{
    u8 tempStr[20];
    u16 dexNum;
    u16 gender;
    u16 heldItem;
    u32 otId;

    dexNum = SpeciesToPokedexNum(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES));
    if (dexNum == 0xffff)
        StringCopy(sMonSummaryScreen->summary.dexNum, gText_8416202);
    else
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.dexNum, dexNum, STR_CONV_MODE_LEADING_ZEROS, 3);

    sUnknown_203B144->unk00 = 0;

    if (!sMonSummaryScreen->isEgg)
    {
        dexNum = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
        StringCopy(sMonSummaryScreen->summary.specieName, GetSpeciesName(dexNum));
    }
    else
    {
        StringCopy(sMonSummaryScreen->summary.specieName, gText_EggNickname);
		return;
    }

    sMonSummaryScreen->typeIcons[0] = gSpeciesInfo[dexNum].types[0];
    sMonSummaryScreen->typeIcons[1] = gSpeciesInfo[dexNum].types[1];

    GetMonNickname(&sMonSummaryScreen->currentMon, tempStr);
    StringCopyN_Multibyte(sMonSummaryScreen->summary.nickname, tempStr, POKEMON_NAME_LENGTH);
    sMonSummaryScreen->summary.nickname[POKEMON_NAME_LENGTH] = EOS;

    gender = GetMonGender(&sMonSummaryScreen->currentMon);
    dexNum = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);

    if (gender == MON_FEMALE)
        StringCopy(sMonSummaryScreen->summary.genderSymbol, gText_FemaleSymbol);
    else if (gender == MON_MALE)
        StringCopy(sMonSummaryScreen->summary.genderSymbol, gText_MaleSymbol);
    else
        StringCopy(sMonSummaryScreen->summary.genderSymbol, gText_StringDummy);

    if (dexNum == SPECIES_NIDORAN_M || dexNum == SPECIES_NIDORAN_F)
        if (StringCompare(sMonSummaryScreen->summary.nickname, gSpeciesInfo[dexNum].speciesName) == 0)
            StringCopy(sMonSummaryScreen->summary.genderSymbol, gText_StringDummy);

    {
        bool8 isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);

        if (isShadow)
        {
            StringCopy(sMonSummaryScreen->summary.ot_name, gText_FiveMarks);
            StringCopy(sMonSummaryScreen->summary.ot_id, gText_FiveMarks);
        }
        else
        {
            GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_NAME, tempStr);
            StringCopyN_Multibyte(sMonSummaryScreen->summary.ot_name, tempStr, PLAYER_NAME_LENGTH);

            ConvertInternationalString(sMonSummaryScreen->summary.ot_name, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LANGUAGE));

            otId = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_ID) & 0xffff;
            ConvertIntToDecimalStringN(sMonSummaryScreen->summary.ot_id, otId, STR_CONV_MODE_LEADING_ZEROS, 5);
        }
    }

    ConvertIntToDecimalStringN(tempStr, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LEVEL), STR_CONV_MODE_LEFT_ALIGN, 3);
	StringCopy(sMonSummaryScreen->summary.level, gText_Lv);
    StringAppendN(sMonSummaryScreen->summary.level, tempStr, 4);

    heldItem = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HELD_ITEM);

    if (heldItem == ITEM_NONE)
	{
		StringCopy(sMonSummaryScreen->summary.heldItem, gText_84161EF);
	}
    else
        CopyItemName(heldItem, sMonSummaryScreen->summary.heldItem);
}

#define MACRO_8136350_0(x) (63 - StringLength((x)) * 6)
#define MACRO_8136350_1(x) (27 - StringLength((x)) * 6)

static u8 PSS_GetLevelFromExp(u16 species, u32 exp)
{
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gSpeciesInfo[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

static void PSS_GetStatsPokemon(void)
{
    u8 tempStr[20];
    u8 level;
    u16 type;
    u16 species;
    u16 hp;
    u16 statValue;
    u32 exp;
    u32 expToNextLevel;

    hp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk3090, hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(sMonSummaryScreen->summary.unk3090, gText_Slash);

    hp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);
    ConvertIntToDecimalStringN(tempStr, hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(sMonSummaryScreen->summary.unk3090, tempStr);

    sUnknown_203B144->unk02 = MACRO_8136350_0(sMonSummaryScreen->summary.unk3090);

    statValue = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk309C[PSS_STAT_ATK], statValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    sUnknown_203B144->tileTag = MACRO_8136350_1(sMonSummaryScreen->summary.unk309C[PSS_STAT_ATK]);

    statValue = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk309C[PSS_STAT_DEF], statValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    sUnknown_203B144->palTag = MACRO_8136350_1(sMonSummaryScreen->summary.unk309C[PSS_STAT_DEF]);

    statValue = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPA], statValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    sUnknown_203B144->unk08 = MACRO_8136350_1(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPA]);

    statValue = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPD], statValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    sUnknown_203B144->unk0A = MACRO_8136350_1(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPD]);

    statValue = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED);
    ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPE], statValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    sUnknown_203B144->unk0C = MACRO_8136350_1(sMonSummaryScreen->summary.unk309C[PSS_STAT_SPE]);

    {
        bool8 isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
        exp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_EXP);

        if (isShadow)
        {
            u32 storedExp = Shadow_GetStoredExp(&sMonSummaryScreen->currentMon);
            u32 growthRate;
            u32 maxExp;
            u32 expAfter;
            u8 levelAfter;

            ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk31A4, storedExp, STR_CONV_MODE_LEFT_ALIGN, 7);
            sUnknown_203B144->unk0E = MACRO_8136350_0(sMonSummaryScreen->summary.unk31A4);

            species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
            growthRate = gSpeciesInfo[species].growthRate;
            maxExp = gExperienceTables[growthRate][MAX_LEVEL];
            expAfter = exp;
            if (expAfter < maxExp)
            {
                if (storedExp > maxExp - expAfter)
                    expAfter = maxExp;
                else
                    expAfter += storedExp;
            }

            levelAfter = PSS_GetLevelFromExp(species, expAfter);
            ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk31B0, levelAfter, STR_CONV_MODE_LEFT_ALIGN, 3);
            sUnknown_203B144->unk10 = MACRO_8136350_0(sMonSummaryScreen->summary.unk31B0);
        }
        else
        {
            ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk31A4, exp, STR_CONV_MODE_LEFT_ALIGN, 7);
            sUnknown_203B144->unk0E = MACRO_8136350_0(sMonSummaryScreen->summary.unk31A4);

            level = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LEVEL);
            expToNextLevel = 0;
            if (level < 100)
            {
                species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
                expToNextLevel = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - exp;
            }

            ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk31B0, expToNextLevel, STR_CONV_MODE_LEFT_ALIGN, 7);
            sUnknown_203B144->unk10 = MACRO_8136350_0(sMonSummaryScreen->summary.unk31B0);
        }
    }

    type = GetAbilityBySpecies(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES),
                               GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ABILITY_NUM));
    StringCopy(sMonSummaryScreen->summary.abilityName, gAbilitiesInfo[type].name);
    StringCopy(sMonSummaryScreen->summary.abilityDescription, gAbilitiesInfo[type].description);

    sMonSummaryScreen->monStatus = PSS_CheckMonStatus(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_STATUS));
    if (sMonSummaryScreen->monStatus == AILMENT_NONE)
        if (CheckPartyPokerus(&sMonSummaryScreen->currentMon, 0))
            sMonSummaryScreen->monStatus = AILMENT_PKRS;
}

static void sub_81367B0(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
        PSS_GetMoveNames(i);

    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        PSS_GetMoveNames(4);
}

#define MACRO_81367E8_0(a, b) ((6 * (a)) - StringLength((b)) * 6)

static void PSS_GetMoveNames(u8 i)
{
    if (i < 4)
        sMonSummaryScreen->currentMove[i] = PSS_GetMonMove(&sMonSummaryScreen->currentMon, i);

    if (sMonSummaryScreen->currentMove[i] == 0)
    {
        StringCopy(sMonSummaryScreen->summary.moveName[i], gText_841620E);
        StringCopy(sMonSummaryScreen->summary.unk30B8[i], gText_8416210);
        StringCopy(sMonSummaryScreen->summary.power[i], gText_ThreeHyphens);
        StringCopy(sMonSummaryScreen->summary.unk3188[i], gText_ThreeHyphens);
        sUnknown_203B144->unk12[i] = 0xff;
        sUnknown_203B144->unk1C[i] = 0xff;
        return;
    }

    sMonSummaryScreen->unk3264++;
    sMonSummaryScreen->move[i] = GetMoveType(sMonSummaryScreen->currentMove[i]);
    StringCopy(sMonSummaryScreen->summary.moveName[i], GetMoveName(sMonSummaryScreen->currentMove[i]));

    if (i >= 4 && sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
    {
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk30B8[i],
                                   GetMovePP(sMonSummaryScreen->currentMove[i]), STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk30F0[i],
                                   GetMovePP(sMonSummaryScreen->currentMove[i]), STR_CONV_MODE_LEFT_ALIGN, 3);
    }
    else
    {
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk30B8[i],
                                   PSS_GetMovePP(&sMonSummaryScreen->currentMon, i), STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk30F0[i],
                                   CalculatePPWithBonus(sMonSummaryScreen->currentMove[i], GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PP_BONUSES), i),
                                   STR_CONV_MODE_LEFT_ALIGN, 3);
    }

    sUnknown_203B144->unk12[i] = MACRO_81367E8_0(2, sMonSummaryScreen->summary.unk30B8[i]);
    sUnknown_203B144->unk1C[i] = MACRO_81367E8_0(2, sMonSummaryScreen->summary.unk30F0[i]);

    if (GetMovePower(sMonSummaryScreen->currentMove[i]) <= 1)
        StringCopy(sMonSummaryScreen->summary.power[i], gText_ThreeHyphens);
    else
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.power[i], GetMovePower(sMonSummaryScreen->currentMove[i]),
                                   STR_CONV_MODE_RIGHT_ALIGN, 3);

    if (GetMoveAccuracy(sMonSummaryScreen->currentMove[i]) == 0)
        StringCopy(sMonSummaryScreen->summary.unk3188[i], gText_ThreeHyphens);
    else
        ConvertIntToDecimalStringN(sMonSummaryScreen->summary.unk3188[i], GetMoveAccuracy(sMonSummaryScreen->currentMove[i]),
                                   STR_CONV_MODE_RIGHT_ALIGN, 3);
}

static u8 PSS_LoadSpritesData(void)
{
    switch (sMonSummaryScreen->state)
    {
    case 0:
        PSS_LoadShinyIndicator(TAG_PSS_UNK_A0, TAG_PSS_UNK_A0);
        break;
    case 1:
        PSS_LoadUnkPoint(TAG_PSS_UNK_96, TAG_PSS_UNK_96);
        break;
    case 2:
        PSS_LoadMarkings();
        break;
    case 3:
        PSS_LoadMovesSelectCursor(TAG_PSS_UNK_64, TAG_PSS_UNK_64);
        break;
    case 4:
        PSS_LoadIconStatus(TAG_PSS_UNK_6E, TAG_PSS_UNK_6E);
        break;
    case 5:
        PSS_LoadHpBar(TAG_PSS_UNK_78, TAG_PSS_UNK_78);
        break;
    case 6:
        PSS_LoadExpBar(TAG_PSS_UNK_82, TAG_PSS_UNK_82);
        break;
    case 7:
        PSS_LoadPokeball();
        break;
    case 8:
        PSS_LoadMonIcon();
        break;
    default:
        PSS_LoadMonSprite();
        return TRUE;
    }

    sMonSummaryScreen->state++;
    return FALSE;
}

static void PSS_ResetAll(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ScanlineEffect_Stop();
}

static void PSS_InitDisplay(void)
{
    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, SummayScreenBgTemplate, NELEMS(SummayScreenBgTemplate));

    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);

    DeactivateAllTextPrinters();
//Transparencia
	SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1 | BLDCNT_TGT2_BG2);
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(13, 16));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void sub_8136D54(void)
{
    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE || sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
        sMonSummaryScreen->task = CreateTask(sub_81393D4, 0);
    else
        sMonSummaryScreen->task = CreateTask(sub_8134840, 0);

	SetMainCallback2(sub_8137EE8);
}

static void PSS_AddTextToWin0(const u8 * str)
{
    FillWindowPixelBuffer(sMonSummaryScreen->window[0], 0);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[0], 2, 4, 1, sPSSTextColours[WHITE_TITLE], 0, str);
    PutWindowTilemap(sMonSummaryScreen->window[0]);
}

static void PSS_AddTextToWin1(const u8 * str)
{
    s32 width;
    u8 windowId;

    windowId = sMonSummaryScreen->window[1];
    FillWindowPixelBuffer(windowId, 0);
    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO || str == NULL || str[0] == EOS)
    {
        ClearWindowTilemap(windowId);
        ScheduleBgCopyTilemapToVram(0);
        return;
    }

    width = GetStringWidth(0, str, 0);
    AddTextPrinterParameterized3(windowId, 0, 0x54 - width, 0, sPSSTextColours[WHITE_TITLE], 0, str);
    PutWindowTilemap(windowId);
}

static void PSS_AddTextToWin2(const u8 * msg)
{
    FillWindowPixelBuffer(sMonSummaryScreen->window[2], 0);
    PSS_ClearWindow2Tilemap();
    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO)
        SetWindowAttribute(sMonSummaryScreen->window[2], WINDOW_TILEMAP_LEFT, 19);
    else
        SetWindowAttribute(sMonSummaryScreen->window[2], WINDOW_TILEMAP_LEFT, 21);
    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO)
        SetWindowAttribute(sMonSummaryScreen->window[2], WINDOW_TILEMAP_TOP, 0);
    else
        SetWindowAttribute(sMonSummaryScreen->window[2], WINDOW_TILEMAP_TOP, 0);

    if (!sMonSummaryScreen->isEgg)
    {
        if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO)
        {
            s16 genderX;
            s16 genderWidth;

            genderWidth = GetStringWidth(2, sMonSummaryScreen->summary.genderSymbol, 0);
            genderX = 80 - genderWidth;
            if (genderX < 0)
                genderX = 0;

            if (genderWidth > 0)
            {
                if (GetMonGender(&sMonSummaryScreen->currentMon) == MON_FEMALE)
                    AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 2, genderX, 0, sPSSTextColours[RED], 0, sMonSummaryScreen->summary.genderSymbol);
                else
                    AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 2, genderX, 0, sPSSTextColours[BLUE], 0, sMonSummaryScreen->summary.genderSymbol);
            }
        }
        else
        {
            s16 genderX;
            s16 genderWidth;

            genderWidth = GetStringWidth(2, sMonSummaryScreen->summary.genderSymbol, 0);
            genderX = 80 - genderWidth;
            if (genderX < 0)
                genderX = 0;

            if (genderWidth > 0)
            {
                if (GetMonGender(&sMonSummaryScreen->currentMon) == MON_FEMALE)
                    AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 2, genderX, 0, sPSSTextColours[RED], 0, sMonSummaryScreen->summary.genderSymbol);
                else
                    AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 2, genderX, 0, sPSSTextColours[BLUE], 0, sMonSummaryScreen->summary.genderSymbol);
            }
        }
        AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 2, 0, 0, sPSSTextColours[DARK], 0xff, sMonSummaryScreen->summary.nickname);
	}

    if (msg != NULL && msg[0] != EOS)
    {
        s32 width = GetStringWidth(0, msg, 0);
        s16 x = 80 - width - 28;
        s16 maxX = 80 - width;
        s16 y = 12;

        if (sMonSummaryScreen->curPageIndex == PSS_PAGE_INFO)
            x += 6;
        else if (msg == gText_PSS_EvIv || msg == gText_8419C82)
            x -= 6;
        else if (msg == gText_8419C92)
            x -= 4;

        if (x < 0)
            x = 0;
        if (x > maxX)
            x = maxX;
        AddTextPrinterParameterized3(sMonSummaryScreen->window[2], 0, x, y, sPSSTextColours[WHITE_TITLE], 0, msg);
    }

    PutWindowTilemap(sMonSummaryScreen->window[2]);
}

static void PSS_AddTextToWin3(void)
{
    FillWindowPixelBuffer(sMonSummaryScreen->window[3], 0);

    switch (sMonSummaryScreen->curPageIndex)
    {
    case PSS_PAGE_INFO:
        PSS_ShowInfoPokemon();
        break;
    case PSS_PAGE_SKILLS:
        PSS_ShowMonStats();
        break;
    case PSS_PAGE_MOVES:
    case PSS_PAGE_MOVES_INFO:
        PSS_PrintMoveNamesOrCancel();
        break;
    }

    PutWindowTilemap(sMonSummaryScreen->window[3]);
}

static void PSS_ShowInfoPokemon(void)
{
    const u8 labelX = 10;
    const u8 yOffset = 4;

    if (!sMonSummaryScreen->isEgg)
    {
        AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 15 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.specieName);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (3 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_DexNumber);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (15 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Name);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (27 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Type);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (39 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_OT);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (51 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_IDNumber);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, (63 - 1) + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Item);
		
		if ((HIHALF(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_ID)) ^ LOHALF(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_ID)) ^ HIHALF(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PERSONALITY)) ^ LOHALF(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PERSONALITY))) < 8)
			AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80 + sUnknown_203B144->unk00, 3 + yOffset, sPSSTextColours[RED], TEXT_SPEED_FF, sMonSummaryScreen->summary.dexNum);
		else	
			AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80 + sUnknown_203B144->unk00, 3 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.dexNum);
		{
			bool8 isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);

			if (isShadow)
			{
				AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 39 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_name);
				AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 51 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_id);
			}
			else if ((gSaveBlock2Ptr->playerTrainerId[0] | (gSaveBlock2Ptr->playerTrainerId[1] << 8) | (gSaveBlock2Ptr->playerTrainerId[2] << 16) | (gSaveBlock2Ptr->playerTrainerId[3] << 24)) == GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_ID))
			{
				if (gSaveBlock2Ptr->playerGender == FEMALE)
					AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 39 + yOffset, sPSSTextColours[RED], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_name);
				if (gSaveBlock2Ptr->playerGender == MALE)
					AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 39 + yOffset, sPSSTextColours[BLUE], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_name);
				AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 51 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_id);
			}
			else
			{
				AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 39 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_name);
				AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 51 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.ot_id);
			}
		}
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 63 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.heldItem);
    }
    else
    {
        const u8 statusYOffset = 28;

		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, 7 + yOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Name);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, labelX, 31 + yOffset + statusYOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Status);
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 80, 8 + yOffset, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.specieName);
    }
}

static void PSS_ShowMonStats(void)
{
    u8 nature = GetNature(&sMonSummaryScreen->currentMon);
    bool8 isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
    const u8 *expLabel = isShadow ? gText_PSS_StoredExp : gText_PSS_ExpPoints;
    const u8 *nextLabel = isShadow ? gText_PSS_LvAfterPure : gText_PSS_ToNextLv;

    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 4, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_HP);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 76, sPSSTextColours[WHITE], TEXT_SPEED_FF, expLabel);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 90, sPSSTextColours[WHITE], TEXT_SPEED_FF, nextLabel);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 16, sPSSTextColours[WHITE + sPSSNatureStatTable[nature][0]], TEXT_SPEED_FF, gText_PSS_Attack);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 28, sPSSTextColours[WHITE + sPSSNatureStatTable[nature][1]], TEXT_SPEED_FF, gText_PSS_Defense);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 40, sPSSTextColours[WHITE + sPSSNatureStatTable[nature][3]], TEXT_SPEED_FF, gText_PSS_SpAtk);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 52, sPSSTextColours[WHITE + sPSSNatureStatTable[nature][4]], TEXT_SPEED_FF, gText_PSS_SpDef);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 10, 64, sPSSTextColours[WHITE + sPSSNatureStatTable[nature][2]], TEXT_SPEED_FF, gText_PSS_Speed);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 68 + sUnknown_203B144->unk02, 4, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk3090);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 90 + sUnknown_203B144->tileTag, 17, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk309C[PSS_STAT_ATK]);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 90 + sUnknown_203B144->palTag, 29, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk309C[PSS_STAT_DEF]);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 90 + sUnknown_203B144->unk08, 41, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk309C[PSS_STAT_SPA]);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 90 + sUnknown_203B144->unk0A, 53, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk309C[PSS_STAT_SPD]);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 90 + sUnknown_203B144->unk0C, 65, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk309C[PSS_STAT_SPE]);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 55 + sUnknown_203B144->unk0E, 77, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk31A4);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 55 + sUnknown_203B144->unk10, 91, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk31B0);
}

#define MACRO_8137270(x) ((x) * 28 + 5)

static void PSS_PrintMoveNamesOrCancel(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
        PSS_PrintMoveNamesAndPP(i);

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
    {
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
            PSS_PrintMoveNamesAndPP(4);
        else
        {
            u8 width = GetStringWidth(2, gText_FameChecker_Cancel, 0);
            u8 x = (10 * 8 - width) / 2;

            AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, x, MACRO_8137270(4), sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_FameChecker_Cancel);
        }
    }
}

#define MACRO_81372E4(x) ((x) * 28 + 16)

static s8 PSS_GetMovesPageSlotYOffset(u8 i)
{
    if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES)
        return 0;

    switch (i)
    {
    case 1:
        return 4;
    case 2:
        return 8;
    case 3:
        return 12;
    default:
        return 0;
    }
}

static void PSS_PrintMoveNamesAndPP(u8 i)
{
    u8 color = WHITE;
    u8 curPP = PSS_GetMovePP(&sMonSummaryScreen->currentMon, i);
    u16 move = sMonSummaryScreen->currentMove[i];
    u8 ppBonuses = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PP_BONUSES);
    u8 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
    s8 movesPageYOffset = PSS_GetMovesPageSlotYOffset(i);

    if (i == 4)
        curPP = maxPP;
	//Add Move Names
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 3, MACRO_8137270(i) - 2 + movesPageYOffset, sPSSTextColours[WHITE], TEXT_SPEED_FF, sMonSummaryScreen->summary.moveName[i]);

    if (sMonSummaryScreen->currentMove[i] == 0 || (curPP == maxPP))
        color = WHITE;
    else if (curPP == 0)
        color = RED_2;
    else if (maxPP == 3)
    {
        if (curPP == 2)
            color = ORANGE;
        else if (curPP == 1)
            color = ORANGE;
    }
    else if (maxPP == 2)
    {
        if (curPP == 1)
            color = ORANGE;
    }
    else
    {
        if (curPP <= (maxPP / 4))
            color = ORANGE;
        else if (curPP <= (maxPP / 2))
            color = ORANGE;
    }
	//Add PP text
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 20, MACRO_81372E4(i) + movesPageYOffset, sPSSTextColours[color], TEXT_SPEED_FF, gText_8416238);
	// Add PP counter
    AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 40 + sUnknown_203B144->unk12[i], MACRO_81372E4(i) + movesPageYOffset, sPSSTextColours[color], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk30B8[i]);

    if (sMonSummaryScreen->currentMove[i] != MOVE_NONE)
    {
		// Add Slash
        AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 52, MACRO_81372E4(i) + movesPageYOffset, sPSSTextColours[color], TEXT_SPEED_FF, gText_Slash);
        // Add PP Max
		AddTextPrinterParameterized3(sMonSummaryScreen->window[3], 2, 58 + sUnknown_203B144->unk1C[i], MACRO_81372E4(i) + movesPageYOffset, sPSSTextColours[color], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk30F0[i]);
    }
}

static void PSS_AddTextToWin4(void)
{
    FillWindowPixelBuffer(sMonSummaryScreen->window[4], 0);

    switch (sMonSummaryScreen->curPageIndex)
    {
    case PSS_PAGE_INFO:
        PSS_CheckIfMonIsEgg();
        break;
    case PSS_PAGE_SKILLS:
        PSS_PrintExpPointAndNextLvTexts();
        break;
    case PSS_PAGE_MOVES_INFO:
        PSS_SetMovesInfoWindow4Position();
        PSS_ShowAttackInfo();
        break;
    case PSS_PAGE_MOVES:
        break;
    }

    PutWindowTilemap(sMonSummaryScreen->window[4]);
}

static void PSS_CheckIfMonIsEgg(void)
{
    if (sMonSummaryScreen->isEgg)
        PSS_ShowEggInfo();
    else
        PSS_ShowTrainerMemo();
}

static void PSS_BufferNatureString(void)
{
    if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW))
    {
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gText_FiveMarks);
    }
    else
    {
        u8 nature = GetNature(&sMonSummaryScreen->currentMon);

        DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNaturesInfo[nature].name);
    }
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gText_EmptyString5);
}

static void PSS_GetMetLevelString(u8 *output)
{
    u8 level = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MET_LEVEL);

    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 PSS_IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (gLastViewedMonIndex == 1 || gLastViewedMonIndex == 4 || gLastViewedMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

static bool8 PSS_DoesMonOTMatchOwner(void)
{
    u32 trainerId;
    u8 gender;
    u32 monOtId = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_ID) & 0xFFFF;
    u8 monOtGender = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_GENDER);
    u8 monOtName[PLAYER_NAME_LENGTH + 1];

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_OT_NAME, monOtName);

    if (gender != monOtGender || trainerId != monOtId || StringCompareWithoutExtCtrlCodes(gStringVar1, monOtName))
        return FALSE;
    else
        return TRUE;
}

static bool8 PSS_DidMonComeFromGBAGames(void)
{
    u8 metGame = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MET_GAME);
    if (metGame > 0 && metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static void PSS_BufferMonTrainerMemo(void)
{
    u16 metLocation = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MET_LOCATION);
    u8 metLevel = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MET_LEVEL);
    const u8 *text;
    u8 metLevelString[32];
    u8 metLocationString[32];

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sMemoNatureTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sMemoMiscTextColor);
    PSS_BufferNatureString();

    if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE || PSS_IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
        return;
    }

    PSS_GetMetLevelString(metLevelString);

    if (metLocation < MAPSEC_NONE)
    {
        GetMapName(metLocationString, metLocation, 0);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
    }

    if (PSS_DoesMonOTMatchOwner() == TRUE)
    {
        if (metLevel == 0)
            text = (metLocation >= MAPSEC_NONE) ? gText_XNatureHatchedSomewhereAt : gText_XNatureHatchedAtYZ;
        else
            text = (metLocation >= MAPSEC_NONE) ? gText_XNatureMetSomewhereAt : gText_XNatureMetAtYZ;
    }
    else if (metLocation == METLOC_FATEFUL_ENCOUNTER)
    {
        text = gText_XNatureFatefulEncounter;
    }
    else if (metLocation != METLOC_IN_GAME_TRADE && PSS_DidMonComeFromGBAGames())
    {
        text = (metLocation >= MAPSEC_NONE) ? gText_XNatureObtainedInTrade : gText_XNatureProbablyMetAt;
    }
    else
    {
        text = gText_XNatureObtainedInTrade;
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);
}

static void PSS_ShowTrainerMemo(void)
{
    const u8 memoYOffset = 8;
    const u8 memoTextY = 10 + memoYOffset;
    const s8 memoLineSpacing = -2;
    const s16 memoLineHeight = GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + memoLineSpacing;
    const s16 memoTextX = 20;
    const s8 memoLineOffsets[] = {6, 6, 6};
    u8 memoText[ARRAY_COUNT(gStringVar4)];
    u8 *lines[ARRAY_COUNT(memoLineOffsets)] = {0};
    u8 lineCount = 0;
    u8 *cursor;
    u8 i;

    PSS_BufferMonTrainerMemo();
    AddTextPrinterParameterized3(sMonSummaryScreen->window[4], 2, 6, 0, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_TrainerMemo);
    {
        u8 windowId = sMonSummaryScreen->window[4];
        s16 levelW = GetStringWidth(2, sMonSummaryScreen->summary.level, 0);
        s16 maxX = GetWindowAttribute(windowId, WINDOW_WIDTH) * 8;
        s16 levelX = maxX - levelW - 62;
        if (levelX < 0)
            levelX = 0;
        AddTextPrinterParameterized3(windowId, 2, levelX, 0, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.level);
    }

    StringCopy(memoText, gStringVar4);
    lines[lineCount++] = memoText;
    for (cursor = memoText; *cursor != EOS && lineCount < ARRAY_COUNT(lines); cursor++)
    {
        if (*cursor == CHAR_NEWLINE)
        {
            *cursor = EOS;
            lines[lineCount++] = cursor + 1;
        }
    }

    for (i = 0; i < lineCount; i++)
    {
        s16 y = memoTextY + memoLineHeight * i + memoLineOffsets[i];

        AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, memoTextX, y, 0, memoLineSpacing, sPSSTextColours[DARK], TEXT_SPEED_FF, lines[i]);
    }
}

static void PSS_ShowEggInfo(void)
{
    u8 eggCycles = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_FRIENDSHIP);
    u8 hatchMsgIndex;
    const u8 memoYOffset = 8;
    const u8 memoTextY = 10 + memoYOffset;

    if (eggCycles <= 5)
        hatchMsgIndex = 3;
    else if (eggCycles <= 10)
        hatchMsgIndex = 2;
    else if (eggCycles <= 40)
        hatchMsgIndex = 1;
    else
        hatchMsgIndex = 0;

    if (sMonSummaryScreen->isBadEgg)
        hatchMsgIndex = 0;

    AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, 16, memoTextY, 0, -2, sPSSTextColours[DARK], TEXT_SPEED_FF, sUnknown_8463EC4[hatchMsgIndex]);
}

static void PSS_PrintExpPointAndNextLvTexts(void)
{
    bool8 isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
    const u8 *expLabel = isShadow ? gText_PSS_StoredExp : gText_8419C4D;
    const u8 *nextLabel = isShadow ? gText_PSS_LvAfterPure : gText_8419C59;

	AddTextPrinterParameterized3(sMonSummaryScreen->window[4], 2, 26,  7, sPSSTextColours[DARK], TEXT_SPEED_FF, expLabel);
	AddTextPrinterParameterized3(sMonSummaryScreen->window[4], 2, 26, 20, sPSSTextColours[DARK], TEXT_SPEED_FF, nextLabel);
}

static void PSS_ShowAttackInfo(void)
{
    if (sUnknown_203B16D < 5)
    {
        u8 category;
        const u8 *moveDesc;

        if (sMonSummaryScreen->mode != PSS_MODE_SELECT_MOVE && sUnknown_203B16D == 4)
            return;
		//Add Category Icon
        category = GetMoveCategory(sMonSummaryScreen->currentMove[sUnknown_203B16D]);
		BlitMoveInfoIcon(sMonSummaryScreen->window[4], MOVE_CATEGORY_ICON_BASE + category, 85, 0);
		//Add Power
        AddTextPrinterParameterized3(sMonSummaryScreen->window[4], 2, 91, 18, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.power[sUnknown_203B16D]);
		//Add Accuracy
        AddTextPrinterParameterized3(sMonSummaryScreen->window[4], 2, 91, 33, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.unk3188[sUnknown_203B16D]);
		//Add Move Description
		AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, 14,  2, 0, -2, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Category);
		AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, 14, 17, 0, -2, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Power);
		AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, 14, 32, 0, -2, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Accuracy);
		AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2, 10, 48, 0, -2, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Effect);
        moveDesc = GetMoveDescription(sMonSummaryScreen->currentMove[sUnknown_203B16D]);
        PSS_CopyMoveDescriptionWrapped(gStringVar4, moveDesc);
		AddTextPrinterParameterized4(sMonSummaryScreen->window[4], PSS_MOVE_DESC_FONT_ID, PSS_MOVE_DESC_TEXT_X, PSS_MOVE_DESC_TEXT_Y, 0, -2, sPSSTextColours[DARK], TEXT_SPEED_FF, gStringVar4);

        PutWindowTilemap(sMonSummaryScreen->window[4]);
    }
}

static void PSS_CopyMoveDescriptionWrapped(u8 *dst, const u8 *src)
{
    u32 lineWidth = 0;
    u32 spaceWidth = GetStringWidth(PSS_MOVE_DESC_FONT_ID, gText_Space, 0);
    u8 wordBuf[PSS_MOVE_DESC_WORD_BUF_SIZE];

    while (*src != EOS)
    {
        if (*src == CHAR_NEWLINE)
        {
            *dst++ = *src++;
            lineWidth = 0;
            continue;
        }

        if (*src == CHAR_SPACE)
        {
            src++;
            continue;
        }

        u8 *wordPtr = wordBuf;

        while (*src != EOS && *src != CHAR_NEWLINE && *src != CHAR_SPACE)
        {
            if (*src == EXT_CTRL_CODE_BEGIN)
            {
                u8 code = src[1];
                u8 len = GetExtCtrlCodeLength(code);
                for (u8 i = 0; i < len + 1; i++)
                {
                    if ((u32)(wordPtr - wordBuf) < PSS_MOVE_DESC_WORD_BUF_SIZE - 1)
                        *wordPtr++ = *src;
                    src++;
                }
                continue;
            }
            if ((u32)(wordPtr - wordBuf) < PSS_MOVE_DESC_WORD_BUF_SIZE - 1)
                *wordPtr++ = *src;
            src++;
        }

        if (wordPtr == wordBuf)
            continue;

        *wordPtr = EOS;

        u32 wordWidth = GetStringWidth(PSS_MOVE_DESC_FONT_ID, wordBuf, 0);

        if (lineWidth != 0)
        {
            if (lineWidth + spaceWidth + wordWidth > PSS_MOVE_DESC_MAX_WIDTH_PX)
            {
                *dst++ = CHAR_NEWLINE;
                lineWidth = 0;
            }
            else
            {
                *dst++ = CHAR_SPACE;
                lineWidth += spaceWidth;
            }
        }

        for (u8 *word = wordBuf; *word != EOS; word++)
            *dst++ = *word;
        lineWidth += wordWidth;
    }

    *dst = EOS;
}

static void PSS_AddTextToWin5(void)
{
    switch (sMonSummaryScreen->curPageIndex)
    {
    case PSS_PAGE_INFO:
        break;
    case PSS_PAGE_SKILLS:
        PSS_PrintAbilityNameAndDescription();
        break;
    case PSS_PAGE_MOVES:
    case PSS_PAGE_MOVES_INFO:
        PSS_DrawMoveIcon();
        break;
    }

    PutWindowTilemap(sMonSummaryScreen->window[5]);
}

static void PSS_PrintAbilityNameAndDescription(void)
{
    FillWindowPixelBuffer(sMonSummaryScreen->window[5], 0);
	AddTextPrinterParameterized3(sMonSummaryScreen->window[5], 2, 11,  4, sPSSTextColours[WHITE], TEXT_SPEED_FF, gText_PSS_Ability);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[5], 2, 60,  4, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.abilityName);
    AddTextPrinterParameterized3(sMonSummaryScreen->window[5], 2, 20, 23, sPSSTextColours[DARK], TEXT_SPEED_FF, sMonSummaryScreen->summary.abilityDescription);
}

static void PSS_DrawMoveIcon(void)
{
    u8 i;

    FillWindowPixelBuffer(sMonSummaryScreen->window[5], 0);

    for (i = 0; i < 4; i++)
    {
        if (sMonSummaryScreen->currentMove[i] == MOVE_NONE)
            continue;

        BlitMoveInfoIcon(sMonSummaryScreen->window[5], sMonSummaryScreen->move[i], 8, MACRO_8137270(i) - 2 + PSS_GetMovesPageSlotYOffset(i));
    }

    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        BlitMoveInfoIcon(sMonSummaryScreen->window[5], sMonSummaryScreen->move[4], 8, MACRO_8137270(4) - 2);
}

static void sub_8137D28(u8 curPageIndex)
{
    switch (curPageIndex)
    {
    case PSS_PAGE_INFO:
        {
            const u8 *actionText;

            PSS_AddTextToWin0(gText_8419C1D);

            if (!sMonSummaryScreen->isEgg)
            {
                if (PSS_CanRenameMon())
                    actionText = gText_PSS_RenameA;
                else
                    actionText = gText_8419C62;
            }
            else
            {
                actionText = gText_8419C72;
            }

            PSS_AddTextToWin1(actionText);
            PSS_AddTextToWin2(actionText);
        }
        break;
    case PSS_PAGE_SKILLS:
        {
            const u8 *actionText;

        PSS_AddTextToWin0(gText_8419C2A);
        if (FlagGet(FLAG_EV_IV)
            && sMonSummaryScreen->mode != PSS_MODE_SELECT_MOVE
            && sMonSummaryScreen->mode != PSS_MODE_FORGET_MOVE)
            actionText = gText_PSS_EvIv;
        else
            actionText = gText_8419C7B;
        PSS_AddTextToWin1(gText_8419C45);
        PSS_AddTextToWin2(actionText);
        }
        break;
    case PSS_PAGE_MOVES:
        {
            const u8 *actionText;

        PSS_AddTextToWin0(gText_8419C39);
        if (PSS_CanUseMoveRelearner())
            actionText = gText_PSS_RelearnL;
        else
            actionText = gText_8419C82;
        PSS_AddTextToWin1(gText_8419C45);
        PSS_AddTextToWin2(actionText);
        }
        break;
    case PSS_PAGE_MOVES_INFO:
        {
            const u8 *actionText;

        PSS_AddTextToWin0(gText_8419C39);
        if (sMonSummaryScreen->mode == PSS_MODE_FORGET_MOVE)
            actionText = gText_8419CA9;
        else if (!gMain.inBattle)
            actionText = gText_8419C92;
        else
            actionText = gText_8419CA2;
        PSS_AddTextToWin1(gText_8419C45);
        PSS_AddTextToWin2(actionText);
        }
        break;
    default:
        break;
    }
}

static void sub_8137E28(void)
{
    PutWindowTilemap(sMonSummaryScreen->window[0]);
    PutWindowTilemap(sMonSummaryScreen->window[1]);
    PutWindowTilemap(sMonSummaryScreen->window[2]);
}

static void sub_8137E64(u8 taskId)
{
    sub_813AF90();
    FreeAllSpritePalettes();

    if (IsCryPlayingOrClearCrySongs() == TRUE)
        StopCryAndClearCrySongs();

    PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
    FreeAllWindowBuffers();
    DestroyTask(taskId);
    {
        MainCallback exitCallback = sSummaryScreenExitCallbackOverride != NULL
            ? sSummaryScreenExitCallbackOverride
            : sMonSummaryScreen->savedCallback;
        sSummaryScreenExitCallbackOverride = NULL;
        SetMainCallback2(exitCallback);
    }

    gLastViewedMonIndex = GetLastViewedMonIndex();

    PSS_FreeTilemapCache();
    FREE_AND_SET_NULL_IF_SET(sMonSummaryScreen);
    FREE_AND_SET_NULL_IF_SET(sUnknown_203B144);
}

static void sub_8137EE8(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
	PSS_ScrollPSSBackground();
}

static void sub_8137FF4(void)
{
    if (sMonSummaryScreen->unk324C < 240)
    {
        sMonSummaryScreen->unk324C += 240;
        if (sMonSummaryScreen->unk324C > 240)
            sMonSummaryScreen->unk324C = 240;
    }
}

static void sub_813805C(void)
{
    if (sMonSummaryScreen->unk324C >= 240)
    {
        sMonSummaryScreen->unk324C -= 240;
        if (sMonSummaryScreen->unk324C < 0)
            sMonSummaryScreen->unk324C = 0;
    }
}

static void sub_81380F0(void)
{
    if (sMonSummaryScreen->unk3224 == 1)
    {
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES_INFO)
            sub_8137FF4();
        else
            sub_813805C();
    }
    else
    {
        if (sMonSummaryScreen->curPageIndex != PSS_PAGE_MOVES)
            sub_813805C();
        else
            sub_8137FF4();
    }
}

static void sub_813817C(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();

    if (sMonSummaryScreen->unk3244 == FALSE)
        return;

    sub_81380F0();
}

static void PSS_TurnOffScreen(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void sub_81381C0(void)
{
    SetVBlankCallback(sub_813817C);
}

static void PSS_InitWindows(void)
{
    u8 i;

    InitWindows(sUnknown_8463F9C);

    for (i = 0; i < 3; i++)
        sMonSummaryScreen->window[i] = AddWindow(&WindowTemplatePokemonInfo[i]);

    for (i = 0; i < 4; i++)
        switch (sMonSummaryScreen->curPageIndex)
        {
        case PSS_PAGE_INFO:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sDataMonAndNatureWindowTemplate[i]);
            break;
        case PSS_PAGE_SKILLS:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sMonStatsAndAbilityWindowTemplate[i]);
            break;
        case PSS_PAGE_MOVES:
        case PSS_PAGE_MOVES_INFO:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sMovesInfoWindowTemplate[i]);
            break;
        default:
            break;
        }
}

static void sub_8138280(u8 curPageIndex)
{
    u8 i;
    for (i = 0; i < 3; i++)
		sMonSummaryScreen->window[i] = AddWindow(&WindowTemplatePokemonInfo[i]);
    for (i = 0; i < 4; i++)
        switch (curPageIndex)
        {
        case PSS_PAGE_INFO:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sDataMonAndNatureWindowTemplate[i]);
            break;
        case PSS_PAGE_SKILLS:
        default:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sMonStatsAndAbilityWindowTemplate[i]);
            break;
        case PSS_PAGE_MOVES:
        case PSS_PAGE_MOVES_INFO:
            sMonSummaryScreen->window[i + 3] = AddWindow(&sMovesInfoWindowTemplate[i]);
            break;
        }
}

static void PSS_RemoveAllWindows(u8 curPageIndex)
{
    u8 i;

    for (i = 0; i < 7; i++)
        RemoveWindow(sMonSummaryScreen->window[i]);
}

static void PSS_SetHelpContext(void)
{
    // Help system not used in pokeemerald-expansion.
}

static void sub_8138538(void)
{
    switch (sMonSummaryScreen->curPageIndex)
    {
    case PSS_PAGE_INFO:
        if (!sMonSummaryScreen->isEgg)
        {
            if (sSummaryTilemapCacheReady && sSummaryPageTilemaps[PSS_PAGE_INFO] != NULL)
                CpuCopy16(sSummaryPageTilemaps[PSS_PAGE_INFO], (void *)(VRAM + 0xF000), SUMMARY_PAGE_TILEMAP_SIZE);
            else
                LZ77UnCompVram(gMapSummaryScreenPokemonInfo, (void *)(VRAM + 0xF000));
        }
        else
        {
            if (sSummaryTilemapCacheReady && sSummaryPageTilemapEgg != NULL)
                CpuCopy16(sSummaryPageTilemapEgg, (void *)(VRAM + 0xF000), SUMMARY_PAGE_TILEMAP_SIZE);
            else
                LZ77UnCompVram(gMapSummaryScreenEgg, (void *)(VRAM + 0xF000));
        }
		PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
        break;
    case PSS_PAGE_SKILLS:
        if (sSummaryTilemapCacheReady && sSummaryPageTilemaps[PSS_PAGE_SKILLS] != NULL)
            CpuCopy16(sSummaryPageTilemaps[PSS_PAGE_SKILLS], (void *)(VRAM + 0xF000), SUMMARY_PAGE_TILEMAP_SIZE);
        else
            LZ77UnCompVram(gMapSummaryScreenPokemonSkills, (void *)(VRAM + 0xF000));
		PSS_SetInvisibleHpBar(0);
		PSS_SetInvisibleExpBar(0);
		HideBg(3);
        break;
    case PSS_PAGE_MOVES:
        if (sSummaryTilemapCacheReady && sSummaryPageTilemaps[PSS_PAGE_MOVES] != NULL)
            CpuCopy16(sSummaryPageTilemaps[PSS_PAGE_MOVES], (void *)(VRAM + 0xF000), SUMMARY_PAGE_TILEMAP_SIZE);
        else
            LZ77UnCompVram(gMapSummaryScreenKnownMoves, (void *)(VRAM + 0xF000));
        if (sSummaryTilemapCacheReady && sSummaryMovesTilemap != NULL)
            CpuCopy16(sSummaryMovesTilemap, (void *)(VRAM + 0xE000), SUMMARY_PAGE_TILEMAP_SIZE);
        else
            LZ77UnCompVram(gMapSummaryScreenMoves2, (void *)(VRAM + 0xE000));
		PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
		ShowBg(3);
        break;
    case PSS_PAGE_MOVES_INFO:
        if (sSummaryTilemapCacheReady && sSummaryPageTilemaps[PSS_PAGE_MOVES_INFO] != NULL)
            CpuCopy16(sSummaryPageTilemaps[PSS_PAGE_MOVES_INFO], (void *)(VRAM + 0xF000), SUMMARY_PAGE_TILEMAP_SIZE);
        else
		    LZ77UnCompVram(gMapSummaryScreenMovesInfo, (void *)(VRAM + 0xF000));
        if (sSummaryTilemapCacheReady && sSummaryMovesInfoTilemap != NULL)
            CpuCopy16(sSummaryMovesInfoTilemap, (void *)(VRAM + 0xE000), SUMMARY_PAGE_TILEMAP_SIZE);
        else
            LZ77UnCompVram(gMapSummaryScreenMoves, (void *)(VRAM + 0xE000));
		PSS_SetInvisibleHpBar(1);
		PSS_SetInvisibleExpBar(1);
		ShowBg(3);
        break;
    }
}

static void PSS_DrawMonMoveIcon(void)
{
    switch (sMonSummaryScreen->curPageIndex)
    {
    case PSS_PAGE_INFO:
        if (!sMonSummaryScreen->isEgg)
        {
            BlitMoveInfoIcon(sMonSummaryScreen->window[3], sMonSummaryScreen->typeIcons[0], 78, 32);

            if (sMonSummaryScreen->typeIcons[0] != sMonSummaryScreen->typeIcons[1])
            BlitMoveInfoIcon(sMonSummaryScreen->window[3], sMonSummaryScreen->typeIcons[1], 110, 32);
        }
        break;
    case PSS_PAGE_SKILLS:
        break;
    case PSS_PAGE_MOVES:
        break;
    case PSS_PAGE_MOVES_INFO:
        break;
    }
}

u8 GetLastViewedMonIndex(void)
{
    return gLastViewedMonIndex;
}

u8 GetMoveSlotToReplace(void)
{
    return sUnknown_203B16E;
}

void SummaryScreen_SetAnimDelayTaskId(u8 taskId)
{
    sAnimDelayTaskId = taskId;
}

void sub_8138B38(u8 mode)
{
    sMonSummaryScreen->mode = mode;
}

static void sub_8138B8C(struct Pokemon * mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon * partyMons = sMonSummaryScreen->monList.mons;
        *mon = partyMons[GetLastViewedMonIndex()];
    }
    else
    {
        struct BoxPokemon * boxMons = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMons[GetLastViewedMonIndex()], mon);
    }
}

static u16 PSS_GetMonMove(struct Pokemon * mon, u8 moveSlot)
{
    u16 move;

    switch (moveSlot)
    {
    case 0:
        move = GetMonData(mon, MON_DATA_MOVE1);
        break;
    case 1:
        move = GetMonData(mon, MON_DATA_MOVE2);
        break;
    case 2:
        move = GetMonData(mon, MON_DATA_MOVE3);
        break;
    default:
        move = GetMonData(mon, MON_DATA_MOVE4);
    }

    return move;
}

static u16 PSS_GetMovePP(struct Pokemon * mon, u8 moveSlot)
{
    u16 pp;

    switch (moveSlot)
    {
    case 0:
        pp = GetMonData(mon, MON_DATA_PP1);
        break;
    case 1:
        pp = GetMonData(mon, MON_DATA_PP2);
        break;
    case 2:
        pp = GetMonData(mon, MON_DATA_PP3);
        break;
    default:
        pp = GetMonData(mon, MON_DATA_PP4);
    }
    return pp;
}

static u8 PSS_CheckMonStatus(u32 status)
{
    if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP) == 0)
        return AILMENT_FNT;

    if ((status & STATUS1_PSN_ANY) != 0)
        return AILMENT_PSN;

    if ((status & STATUS1_PARALYSIS) != 0)
        return AILMENT_PRZ;

    if ((status & STATUS1_SLEEP) != 0)
        return AILMENT_SLP;

    if ((status & STATUS1_FREEZE) != 0)
        return AILMENT_FRZ;

    if ((status & STATUS1_BURN) != 0)
        return AILMENT_BRN;

    if (CheckPartyPokerus(&sMonSummaryScreen->currentMon, 0))
        return AILMENT_PKRS;

    return AILMENT_NONE;
}

static void sub_8138CD8(u8 id)
{
    u8 i;

    switch (sMonSummaryScreen->unk3288)
    {
    case 0:
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE || MenuHelpers_IsLinkActive() == TRUE)
            return;

        if (JOY_NEW(DPAD_UP))
        {
            if (sUnknown_203B16D > 0)
            {
                sMonSummaryScreen->unk3288 = 2;
                PlaySE(SE_SELECT);

                for (i = sUnknown_203B16D; i > 0; i--)
                    if (sMonSummaryScreen->currentMove[i - 1] != 0)
                    {
                        PlaySE(SE_SELECT);
                        sUnknown_203B16D = i - 1;
                        return;
                    }
            }
            else
            {
                sUnknown_203B16D = 4;
                sMonSummaryScreen->unk3288 = 2;
                PlaySE(SE_SELECT);

                if (sMonSummaryScreen->unk3268 == TRUE)
                    for (i = sUnknown_203B16D; i > 0; i--)
                        if (sMonSummaryScreen->currentMove[i - 1] != 0)
                        {
                            PlaySE(SE_SELECT);
                            sUnknown_203B16D = i - 1;
                            return;
                        }
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (sUnknown_203B16D < 4)
            {
                u8 v0 = 4;

                sMonSummaryScreen->unk3288 = 2;

                if (sMonSummaryScreen->unk3268 == TRUE)
                {
                    if (sUnknown_203B16D == 5 - 2)
                    {
                        sUnknown_203B16D = 0;
                        sMonSummaryScreen->unk3288 = 2;
                        PlaySE(SE_SELECT);
                        return;
                    }
                    v0--;
                }

                for (i = sUnknown_203B16D; i < v0; i++)
                    if (sMonSummaryScreen->currentMove[i + 1] != 0)
                    {
                        PlaySE(SE_SELECT);
                        sUnknown_203B16D = i + 1;
                        return;
                    }

                if (!sMonSummaryScreen->unk3268)
                {
                    PlaySE(SE_SELECT);
                    sUnknown_203B16D = i;
                }
                else
                {
                    PlaySE(SE_SELECT);
                    sUnknown_203B16D = 0;
                }

                return;
            }
            else if (sUnknown_203B16D == 4)
            {
                sUnknown_203B16D = 0;
                sMonSummaryScreen->unk3288 = 2;
                PlaySE(SE_SELECT);
                return;
            }
        }
        else if (JOY_NEW(L_BUTTON))
        {
            if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES
                && sMonSummaryScreen->unk3268 != TRUE
                && PSS_CanUseMoveRelearner())
            {
                PlaySE(SE_SELECT);
                PSS_BeginMoveRelearnerFromSummary();
                return;
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sUnknown_203B16D == 4)
            {
                sUnknown_203B16D = 0;
                sUnknown_203B16E = 0;
                sMonSummaryScreen->unk3268 = FALSE;
            sub_813A0E8(1);
            sMonSummaryScreen->unk3224 = 0;
            PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
            sMonSummaryScreen->curPageIndex--;
            PSS_ClearWindow2Tilemap();
            PSS_SetMonSpritePositionForPage();
            PSS_SetMonIconPositionForPage();
            sMonSummaryScreen->unk3288 = 1;
            return;
            }

            if (sMonSummaryScreen->unk3268 != TRUE)
            {
                if (sMonSummaryScreen->isEnemyParty == FALSE
                    && gMain.inBattle == 0
                    && gReceivedRemoteLinkPlayers == 0)
                {
                    sUnknown_203B16E = sUnknown_203B16D;
                    sMonSummaryScreen->unk3268 = TRUE;
                }
                return;
            }
            else
            {
                sMonSummaryScreen->unk3268 = FALSE;

                if (sUnknown_203B16D == sUnknown_203B16E)
                    return;

                if (sMonSummaryScreen->isBoxMon == 0)
                    sub_81390B0();
                else
                    sub_81391EC();

                sub_8139328(&sMonSummaryScreen->currentMon);
                sub_81367B0();
                sMonSummaryScreen->unk3288 = 2;
                return;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if (sMonSummaryScreen->unk3268 == TRUE)
            {
                sUnknown_203B16E = sUnknown_203B16D;
                sMonSummaryScreen->unk3268 = FALSE;
                return;
            }

            if (sUnknown_203B16D == 4)
            {
                sUnknown_203B16D = 0;
                sUnknown_203B16E = 0;
            }

            sub_813A0E8(1);
            sMonSummaryScreen->unk3224 = 0;
            PSS_RemoveAllWindows(sMonSummaryScreen->curPageIndex);
            sMonSummaryScreen->curPageIndex--;
            PSS_ClearWindow2Tilemap();
            PSS_SetMonSpritePositionForPage();
            PSS_SetMonIconPositionForPage();
            sMonSummaryScreen->unk3288 = 1;
        }
        break;
    case 1:
        gTasks[sMonSummaryScreen->task].func = sub_81351A0;
        sMonSummaryScreen->unk3288 = 0;
        break;
    case 2:
        PSS_AddTextToWin3();
        PSS_AddTextToWin4();
        PSS_AddTextToWin5();
        sMonSummaryScreen->unk3288 = 3;
        break;
    case 3:
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE || MenuHelpers_IsLinkActive() == TRUE)
            return;

        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        CopyBgTilemapBufferToVram(0);
        sMonSummaryScreen->unk3288 = 0;
        break;
    default:
        break;
    }
}

static void sub_81390B0(void)
{
    struct Pokemon * partyMons;
    struct Pokemon * mon;

    u16 move1, move2;
    u8 pp1, pp2;
    u8 allMovesPPBonuses;
    u8 move1ppBonus, move2ppBonus;

    partyMons = sMonSummaryScreen->monList.mons;
    mon = &partyMons[GetLastViewedMonIndex()];

    move1 = GetMonData(mon, MON_DATA_MOVE1 + sUnknown_203B16D);
    move2 = GetMonData(mon, MON_DATA_MOVE1 + sUnknown_203B16E);

    pp1 = GetMonData(mon, MON_DATA_PP1 + sUnknown_203B16D);
    pp2 = GetMonData(mon, MON_DATA_PP1 + sUnknown_203B16E);

    allMovesPPBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);

    move1ppBonus = (allMovesPPBonuses & gPPUpGetMask[sUnknown_203B16D]) >> (sUnknown_203B16D * 2);
    move2ppBonus = (allMovesPPBonuses & gPPUpGetMask[sUnknown_203B16E]) >> (sUnknown_203B16E * 2);

    allMovesPPBonuses &= ~gPPUpGetMask[sUnknown_203B16D];
    allMovesPPBonuses &= ~gPPUpGetMask[sUnknown_203B16E];
    allMovesPPBonuses |= (move1ppBonus << (sUnknown_203B16E * 2)) + (move2ppBonus << (sUnknown_203B16D * 2));

    SetMonData(mon, MON_DATA_MOVE1 + sUnknown_203B16D, (u8 *)&move2);
    SetMonData(mon, MON_DATA_MOVE1 + sUnknown_203B16E, (u8 *)&move1);
    SetMonData(mon, MON_DATA_PP1 + sUnknown_203B16D, &pp2);
    SetMonData(mon, MON_DATA_PP1 + sUnknown_203B16E, &pp1);
    SetMonData(mon, MON_DATA_PP_BONUSES, &allMovesPPBonuses);
}

static void sub_81391EC(void)
{
    struct BoxPokemon * boxMons;
    struct BoxPokemon * boxMon;

    u16 move1, move2;
    u8 pp1, pp2;
    u8 allMovesPPBonuses;
    u8 move1ppBonus, move2ppBonus;

    boxMons = sMonSummaryScreen->monList.boxMons;
    boxMon = &boxMons[GetLastViewedMonIndex()];

    move1 = GetBoxMonData(boxMon, MON_DATA_MOVE1 + sUnknown_203B16D);
    move2 = GetBoxMonData(boxMon, MON_DATA_MOVE1 + sUnknown_203B16E);

    pp1 = GetBoxMonData(boxMon, MON_DATA_PP1 + sUnknown_203B16D);
    pp2 = GetBoxMonData(boxMon, MON_DATA_PP1 + sUnknown_203B16E);

    allMovesPPBonuses = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES);

    move1ppBonus = (allMovesPPBonuses & gPPUpGetMask[sUnknown_203B16D]) >> (sUnknown_203B16D * 2);
    move2ppBonus = (allMovesPPBonuses & gPPUpGetMask[sUnknown_203B16E]) >> (sUnknown_203B16E * 2);

    allMovesPPBonuses &= ~gPPUpGetMask[sUnknown_203B16D];
    allMovesPPBonuses &= ~gPPUpGetMask[sUnknown_203B16E];
    allMovesPPBonuses |= (move1ppBonus << (sUnknown_203B16E * 2)) + (move2ppBonus << (sUnknown_203B16D * 2));

    SetBoxMonData(boxMon, MON_DATA_MOVE1 + sUnknown_203B16D, (u8 *)&move2);
    SetBoxMonData(boxMon, MON_DATA_MOVE1 + sUnknown_203B16E, (u8 *)&move1);
    SetBoxMonData(boxMon, MON_DATA_PP1 + sUnknown_203B16D, &pp2);
    SetBoxMonData(boxMon, MON_DATA_PP1 + sUnknown_203B16E, &pp1);
    SetBoxMonData(boxMon, MON_DATA_PP_BONUSES, &allMovesPPBonuses);
}

static void sub_8139328(struct Pokemon * mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon * partyMons;
        partyMons = sMonSummaryScreen->monList.mons;
        *mon = partyMons[GetLastViewedMonIndex()];
    }
    else
    {
        struct BoxPokemon * boxMons;
        boxMons = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMons[GetLastViewedMonIndex()], mon);
    }
}

static u8 sub_8139388(void)
{
    u16 move;

    move = PSS_GetMonMove(&sMonSummaryScreen->currentMon, sUnknown_203B16D);

    if (IsMoveHM(move) == TRUE && sMonSummaryScreen->mode != PSS_MODE_FORGET_MOVE)
        return FALSE;

    return TRUE;
}

static void sub_81393D4(u8 taskId)
{
    u8 i;

    switch (sMonSummaryScreen->unk3288)
    {
    case 0:
        BeginNormalPaletteFade(0xffffffff, 0, 16, 0, 0);
        sMonSummaryScreen->unk3288++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            PSS_PlayMonCry();
            sMonSummaryScreen->unk3288++;
        }
        break;
    case 2:
        if (JOY_NEW(DPAD_UP))
        {
            if (sUnknown_203B16D > 0)
            {
                sMonSummaryScreen->unk3288 = 3;
                PlaySE(SE_SELECT);
                for (i = sUnknown_203B16D; i > 0; i--)
                    if (sMonSummaryScreen->currentMove[i - 1] != 0)
                    {
                        PlaySE(SE_SELECT);
                        sUnknown_203B16D = i - 1;
                        return;
                    }
            }
            else
            {
                sUnknown_203B16D = 4;
                sMonSummaryScreen->unk3288 = 3;
                PlaySE(SE_SELECT);
                return;
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (sUnknown_203B16D < 4)
            {
                u8 v0 = 4;

                sMonSummaryScreen->unk3288 = 3;

                if (sMonSummaryScreen->unk3268 == TRUE)
                    v0--;

                for (i = sUnknown_203B16D; i < v0; i++)
                    if (sMonSummaryScreen->currentMove[i + 1] != 0)
                    {
                        PlaySE(SE_SELECT);
                        sUnknown_203B16D = i + 1;
                        return;
                    }

                if (!sMonSummaryScreen->unk3268)
                {
                    PlaySE(SE_SELECT);
                    sUnknown_203B16D = i;
                }

                return;
            }
            else if (sUnknown_203B16D == 4)
            {
                sUnknown_203B16D = 0;
                sMonSummaryScreen->unk3288 = 3;
                PlaySE(SE_SELECT);
                return;
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sub_8139388() == TRUE || sUnknown_203B16D == 4)
            {
                PlaySE(SE_SELECT);
                sUnknown_203B16E = sUnknown_203B16D;
                gSpecialVar_0x8005 = sUnknown_203B16E;
                sMonSummaryScreen->unk3288 = 6;
            }
            else
            {
                PlaySE(SE_FAILURE);
                sMonSummaryScreen->unk3288 = 5;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            sUnknown_203B16E = 4;
            gSpecialVar_0x8005 = (u16)sUnknown_203B16E;
            sMonSummaryScreen->unk3288 = 6;
        }
        break;
    case 3:
        PSS_AddTextToWin3();
        PSS_AddTextToWin4();
        PSS_AddTextToWin5();
        sMonSummaryScreen->unk3288 = 4;
        break;
    case 4:
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE || MenuHelpers_IsLinkActive() == TRUE)
            return;

        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        CopyBgTilemapBufferToVram(0);
        sMonSummaryScreen->unk3288 = 2;
        break;
    case 5:
        FillWindowPixelBuffer(sMonSummaryScreen->window[4], 0);
        AddTextPrinterParameterized4(sMonSummaryScreen->window[4], 2,
                                     7, 42,
                                     0, 0,
                                     sPSSTextColours[DARK], TEXT_SPEED_FF,
                                     gText_HMMovesCantBeForgotten2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyBgTilemapBufferToVram(0);
        sMonSummaryScreen->unk3288 = 2;
        break;
    case 6:
        BeginNormalPaletteFade(0xffffffff, 0, 0, 16, 0);
        sMonSummaryScreen->unk3288++;
        break;
    default:
        if (!gPaletteFade.active)
            sub_8137E64(taskId);
        break;
    }
}

static void sub_8139768(struct Sprite * sprite)
{
    if (sMonSummaryScreen->unk3020 >= 2)
        return;

    if (sUnknown_203B170->tileTag++ >= 2)
    {
        u8 v0;

        switch (sUnknown_203B170->unk08)
        {
        case 0:
            sprite->y += sUnknown_8463FBE[sUnknown_203B170->unk00++];
            v0 = NELEMS(sUnknown_8463FBE);
            break;
        case 1:
            sprite->y += sUnknown_8463FC1[sUnknown_203B170->unk00++];
            v0 = NELEMS(sUnknown_8463FC1);
            break;
        case 2:
            sprite->y += sUnknown_8463FC6[sUnknown_203B170->unk00++];
            v0 = NELEMS(sUnknown_8463FC6);
            break;
        case 3:
        default:
            sprite->y += sUnknown_8463FCD[sUnknown_203B170->unk00++];
            v0 = NELEMS(sUnknown_8463FCD);
            break;
        }

        if (sUnknown_203B170->unk00 >= v0)
        {
            sUnknown_203B170->unk00 = 0;
            sMonSummaryScreen->unk3020++;
        }

        sUnknown_203B170->tileTag = 0;
    }
}

static void sub_8139868(struct Sprite * sprite)
{
    if (sMonSummaryScreen->unk3020 >= 2)
        return;

    switch (sUnknown_203B170->unk08)
    {
    case 0:
    default:
        if (sUnknown_203B170->tileTag++ >= 120)
        {
            sprite->x += sUnknown_8463FD4[sUnknown_203B170->unk00];
            if (++sUnknown_203B170->unk00 >= NELEMS(sUnknown_8463FD4))
            {
                sUnknown_203B170->unk00 = 0;
                sUnknown_203B170->tileTag = 0;
                sMonSummaryScreen->unk3020++;
            }
        }
        break;
    case 1:
        if (sUnknown_203B170->tileTag++ >= 90)
        {
            sprite->x += sUnknown_8463FDF[sUnknown_203B170->unk00];
            if (++sUnknown_203B170->unk00 >= NELEMS(sUnknown_8463FDF))
            {
                sUnknown_203B170->unk00 = 0;
                sUnknown_203B170->tileTag = 0;
                sMonSummaryScreen->unk3020++;
            }
        }
        break;
    case 2:
        if (sUnknown_203B170->tileTag++ >= 60)
        {
            sprite->x += sUnknown_8463FEA[sUnknown_203B170->unk00];
            if (++sUnknown_203B170->unk00 >= NELEMS(sUnknown_8463FEA))
            {
                sUnknown_203B170->unk00 = 0;
                sUnknown_203B170->tileTag = 0;
                sMonSummaryScreen->unk3020++;
            }
        }
        break;
    }
}

static void nullsub_96(struct Sprite * sprite)
{
}

static void PSS_LoadMonSprite(void)
{
    u16 spriteId;
    u16 species;
    u32 personality;
    bool8 isShiny;
    bool8 isShadow;

    sUnknown_203B170 = AllocZeroed(sizeof(struct Struct203B170));

    species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
    personality = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PERSONALITY);
    isShiny = IsMonShiny(&sMonSummaryScreen->currentMon);
    isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);

    if (ShouldIgnoreDeoxysForm(3, gLastViewedMonIndex))
        species = SPECIES_DEOXYS;

    spriteId = CreateMonPicSprite_ShadowAware(species, isShiny, personality, TRUE, 204, 78, 12, TAG_NONE, isShadow);

    FreeSpriteOamMatrix(&gSprites[spriteId]);
    sMonSummaryScreen->spriteId_1 = spriteId;
    PSS_SetInvisibleMonSprite(1);
    sub_8139AAC(spriteId);
}

static void sub_8139AAC(u16 spriteId)
{
    u16 curHp;
    u16 maxHp;

    sMonSummaryScreen->unk3020 = 0;

    if (sMonSummaryScreen->isEgg == TRUE)
    {
        u8 friendship = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_FRIENDSHIP);

        if (friendship <= 5)
            sUnknown_203B170->unk08 = 2;
        else
        {
            if (friendship <= 10)
                sUnknown_203B170->unk08 = 1;
            else if (friendship <= 40)
                sUnknown_203B170->unk08 = 0;
        }

        gSprites[spriteId].callback = sub_8139868;
        return;
    }

    if (sMonSummaryScreen->monStatus != AILMENT_NONE && sMonSummaryScreen->monStatus != AILMENT_PKRS)
    {
        if (sMonSummaryScreen->monStatus == AILMENT_FNT)
            return;

        gSprites[spriteId].callback = nullsub_96;
        return;
    }

    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (curHp == maxHp)
        sUnknown_203B170->unk08 = 3;
    else if (maxHp * 0.8 <= curHp)
        sUnknown_203B170->unk08 = 2;
    else if (maxHp * 0.6 <= curHp)
        sUnknown_203B170->unk08 = 1;
    else
        sUnknown_203B170->unk08 = 0;

    gSprites[spriteId].callback = sub_8139768;
}

static void PSS_SetInvisibleMonSprite(u8 invisible)
{
    gSprites[sMonSummaryScreen->spriteId_1].invisible = invisible;
}

static void PSS_UnloadMonSprite(void)
{
    FreeAndDestroyMonPicSprite(sMonSummaryScreen->spriteId_1);
    FREE_AND_SET_NULL(sUnknown_203B170);
}

static void PSS_LoadPokeball(void)
{
    u16 ballItemId;
    u8 ballId;

    if (!sMonSummaryScreen->isEgg)
        ballItemId = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_POKEBALL);
    else
        ballItemId = 0;

    ballId = ItemIdToBallId(ballItemId);
    LoadBallGfx(ballId);

    sMonSummaryScreen->spriteId_0 = CreateSprite(&gBallSpriteTemplates[ballId], 232, 23, 0);
    gSprites[sMonSummaryScreen->spriteId_0].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteId_0].oam.priority = 0;

    PSS_SetInvisiblePokeball(1);
}

static void PSS_SetInvisiblePokeball(u8 invisible)
{
    gSprites[sMonSummaryScreen->spriteId_0].invisible = invisible;
}

static void PSS_ClearWindow2Tilemap(void)
{
    u8 windowId = sMonSummaryScreen->window[2];

    SetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT, 19);
    SetWindowAttribute(windowId, WINDOW_TILEMAP_TOP, 0);
    ClearWindowTilemap(windowId);

    SetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT, 21);
    SetWindowAttribute(windowId, WINDOW_TILEMAP_TOP, 0);
    ClearWindowTilemap(windowId);

    ScheduleBgCopyTilemapToVram(0);
}

static void PSS_SetMovesInfoWindow4Position(void)
{
    u8 windowId = sMonSummaryScreen->window[4];

    SetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT, 15);
    SetWindowAttribute(windowId, WINDOW_TILEMAP_TOP, 6);
    ClearWindowTilemap(windowId);

    SetWindowAttribute(windowId, WINDOW_TILEMAP_TOP, 4);
}

static void PSS_SetMonSpritePositionForPage(void)
{
    s16 y = 78;

    gSprites[sMonSummaryScreen->spriteId_1].y = y;
}

static void PSS_SetMonIconPositionForPage(void)
{
    s16 y = (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO) ? 14 : 28;

    gSprites[sMonSummaryScreen->spriteId_2].y = y;
}

static void sub_8139D90(void)
{
    DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteId_0]);
}

static void PSS_LoadMonIcon(void)
{
    u16 species;
    u32 personality;
    bool8 isShiny;
    bool8 isShadow;

    species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
    personality = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_PERSONALITY);
    isShiny = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHINY);
    isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);

    if (ShouldIgnoreDeoxysForm(3, gLastViewedMonIndex))
        species = SPECIES_DEOXYS;

    LoadMonIconPalette(species);
    sMonSummaryScreen->spriteId_2 = CreateMonIcon(species, SpriteCallbackDummy, 140, 28, 0, personality, isShiny, isShadow);

    if (!IsMonSpriteNotFlipped(species))
        gSprites[sMonSummaryScreen->spriteId_2].hFlip = FALSE;
    else
        gSprites[sMonSummaryScreen->spriteId_2].hFlip = TRUE;

    PSS_SetMonIconPositionForPage();
    sub_8139EE4(1);
}

static void sub_8139EE4(u8 invisible)
{
    gSprites[sMonSummaryScreen->spriteId_2].invisible = invisible;
}

static void sub_8139F20(void)
{
    u16 species;
    species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);
    if (ShouldIgnoreDeoxysForm(3, gLastViewedMonIndex))
        species = SPECIES_DEOXYS;
    SafeFreeMonIconPalette(species);
    FreeAndDestroyMonIconSprite(&gSprites[sMonSummaryScreen->spriteId_2]);
}

static void PSS_LoadMovesSelectCursor(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void * gfxBufferPtrs[2];
    gfxBufferPtrs[0] = AllocZeroed(0x20 * 64);
    gfxBufferPtrs[1] = AllocZeroed(0x20 * 64);

    sUnknown_203B148[0] = AllocZeroed(sizeof(struct Struct203B148));
    sUnknown_203B148[1] = AllocZeroed(sizeof(struct Struct203B148));
    sUnknown_203B148[2] = AllocZeroed(sizeof(struct Struct203B148));
    sUnknown_203B148[3] = AllocZeroed(sizeof(struct Struct203B148));

    LZ77UnCompWram(gSelectCursorGfxLeft, gfxBufferPtrs[0]);
    LZ77UnCompWram(gSelectCursorGfxRight, gfxBufferPtrs[1]);

    for (i = 0; i < 4; i++)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtrs[i % 2],
            .size = 0x20 * 64,
            .tag = tileTag + i
        };

        struct SpritePalette palette = {.data = gSelectCursorPalette, .tag = palTag};
        struct SpriteTemplate template = {
            .tileTag = tileTag + i,
            .paletteTag = palTag,
            .oam = &sUnknown_846398C,
            .anims = sUnknown_84639A4,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = sub_813A124,
        };

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);

        spriteId = CreateSprite(&template, 64 * (i % 2) + 32, sUnknown_203B16D * 28 + 34, i % 2);
        sUnknown_203B148[i]->sprite = &gSprites[spriteId];
        sUnknown_203B148[i]->tileTag = i;
        sUnknown_203B148[i]->palTag = tileTag + i;
        sUnknown_203B148[i]->unk08 = palTag;
        sUnknown_203B148[i]->sprite->subpriority = i;

        if (i > 1)
            StartSpriteAnim(sUnknown_203B148[i]->sprite, 1);
    }

    sub_813A0E8(1);

    FREE_AND_SET_NULL_IF_SET(gfxBufferPtrs[0]);
    FREE_AND_SET_NULL_IF_SET(gfxBufferPtrs[1]);
}

static void sub_813A0E8(u8 invisible)
{
    u8 i;
    for (i = 0; i < 4; i++)
        sUnknown_203B148[i]->sprite->invisible = invisible;
}

static void sub_813A124(struct Sprite * sprite)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (sMonSummaryScreen->unk3268 == TRUE && i > 1)
            continue;

        sUnknown_203B148[i]->sprite->y = sUnknown_203B16D * 28 + 34;
    }

    if (sMonSummaryScreen->unk3268 != TRUE)
    {
        if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
        {
            sUnknown_203B148[0]->sprite->invisible = FALSE;
            sUnknown_203B148[1]->sprite->invisible = FALSE;
        }
        return;
    }

    for (i = 0; i < 2; i++)
    {
        sprite = sUnknown_203B148[i]->sprite;
        sprite->data[0]++;

        if (sprite->invisible)
        {
            if (sprite->data[0] > 60)
            {
                sprite->invisible = FALSE;
                sprite->data[0] = 0;
            }
        }
        else if (sprite->data[0] > 60)
        {
            sprite->invisible = TRUE;
            sprite->data[0] = 0;
        }
    }
}

static void sub_813A21C(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (sUnknown_203B148[i]->sprite != NULL)
            DestroySpriteAndFreeResources(sUnknown_203B148[i]->sprite);

        FREE_AND_SET_NULL_IF_SET(sUnknown_203B148[i]);
    }
}

static void PSS_LoadIconStatus(u16 tileTag, u16 palTag)
{
    u16 spriteId;
    void * gfxBufferPtr;

    sStatusIconSummaryScreen = AllocZeroed(sizeof(struct Struct203B158));
    gfxBufferPtr = AllocZeroed(0x20 * 32);
	LZ77UnCompWram(gIconStatusSummaryScreen, gfxBufferPtr);

    if (sStatusIconSummaryScreen != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 32,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = gIconStatusPalSummaryScreen, .tag = palTag};
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sUnknown_84639AC,
            .anims = sUnknown_84639F4,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);

        spriteId = CreateSprite(&template, 0, 0, 0);
        sStatusIconSummaryScreen->sprite = &gSprites[spriteId];
        sStatusIconSummaryScreen->tileTag = tileTag;
        sStatusIconSummaryScreen->palTag = palTag;
    }

    PSS_SetInvisibleIconStatus(1);
    PSS_ShowIconStatus();
    FREE_AND_SET_NULL_IF_SET(gfxBufferPtr);
}

static void PSS_UnloadIconStatus(void)
{
    if (sStatusIconSummaryScreen->sprite != NULL)
        DestroySpriteAndFreeResources(sStatusIconSummaryScreen->sprite);

    FREE_AND_SET_NULL_IF_SET(sStatusIconSummaryScreen);
}

static void PSS_ShowIconStatus(void)
{
    sMonSummaryScreen->monStatus = PSS_CheckMonStatus(GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_STATUS));

    if (sMonSummaryScreen->monStatus == AILMENT_NONE)
    {
        PSS_SetInvisibleIconStatus(1);
        return;
    }

    StartSpriteAnim(sStatusIconSummaryScreen->sprite, sMonSummaryScreen->monStatus - 1);
    PSS_SetInvisibleIconStatus(0);
}

static void PSS_SetInvisibleIconStatus(u8 invisible)
{
    if (sMonSummaryScreen->monStatus == AILMENT_NONE || sMonSummaryScreen->isEgg)
        sStatusIconSummaryScreen->sprite->invisible = TRUE;
    else
        sStatusIconSummaryScreen->sprite->invisible = invisible;

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
    {
        if (sStatusIconSummaryScreen->sprite->y != 45)
        {
            sStatusIconSummaryScreen->sprite->x = 16;
            sStatusIconSummaryScreen->sprite->y = 45;
            return;
        }
    }
    else if (sStatusIconSummaryScreen->sprite->y != 38)
    {
        sStatusIconSummaryScreen->sprite->x = 214;
        sStatusIconSummaryScreen->sprite->y = 38;
        return;
    }
}

static void PSS_LoadHpBar(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void * gfxBufferPtr;
    u32 curHp;
    u32 maxHp;
    u8 hpBarPalTagOffset = 0;

    sHpBarSummaryScreen = AllocZeroed(sizeof(struct Struct203B15C));
    gfxBufferPtr = AllocZeroed(0x20 * 12);
	LZ77UnCompWram(gHpBarSummaryScreen, gfxBufferPtr);
    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (maxHp / 4 > curHp)
        hpBarPalTagOffset = 2;
    else if (maxHp / 2 > curHp)
        hpBarPalTagOffset = 1;

    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette palette1 = {.data = sHpBarPalettes[0], .tag = palTag};
        struct SpritePalette palette2 = {.data = sHpBarPalettes[1], .tag = palTag + 1};
        struct SpritePalette palette3 = {.data = sHpBarPalettes[2], .tag = palTag + 2};

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette1);
        LoadSpritePalette(&palette2);
        LoadSpritePalette(&palette3);
    }

    for (i = 0; i < 9; i++)
    {
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag + hpBarPalTagOffset,
            .oam = &sUnknown_8463A14,
            .anims = sUnknown_8463A7C,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        sHpBarSummaryScreen->cordX[i] = i * 8 + 81;
        spriteId = CreateSprite(&template, sHpBarSummaryScreen->cordX[i], 17, 0);
        sHpBarSummaryScreen->sprites[i] = &gSprites[spriteId];
        sHpBarSummaryScreen->sprites[i]->invisible = FALSE;
        sHpBarSummaryScreen->sprites[i]->oam.priority = 2;
        sHpBarSummaryScreen->unk3C = tileTag;
        sHpBarSummaryScreen->unk3E = palTag;
        StartSpriteAnim(sHpBarSummaryScreen->sprites[i], 8);
    }

    PSS_SetupHpBar();
    PSS_SetInvisibleHpBar(1);

    FREE_AND_SET_NULL_IF_SET(gfxBufferPtr);
}

static void PSS_SetupHpBar(void)
{
    u8 numWholeHpBarTiles = 0;
    u8 i;
    u8 animNum;
    u8 two = 2;
    u8 hpBarPalOffset = 0;
    u32 curHp;
    u32 maxHp;
    s64 v0;
    s64 v1;

    if (sMonSummaryScreen->isEgg)
        return;

    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (maxHp / 5 >= curHp)
        hpBarPalOffset = 2;
    else if (maxHp / 2 >= curHp)
        hpBarPalOffset = 1;

    switch (GetHPBarLevel(curHp, maxHp))
    {
    case 3:
    default:
        hpBarPalOffset = 0;
        break;
    case 2:
        hpBarPalOffset = 1;
        break;
    case 1:
        hpBarPalOffset = 2;
        break;
    }

    for (i = 0; i < 9; i++)
        sHpBarSummaryScreen->sprites[i]->oam.paletteNum = IndexOfSpritePaletteTag(TAG_PSS_UNK_78) + hpBarPalOffset;

    if (curHp == maxHp)
        for (i = two; i < 8; i++)
            StartSpriteAnim(sHpBarSummaryScreen->sprites[i], 8);

    else
    {
        v0 = (maxHp << 2) / 6;
        v1 = (curHp << 2);

        while (TRUE)
        {
            if (v1 <= v0)
                break;
            v1 -= v0;
            numWholeHpBarTiles++;
        }

        numWholeHpBarTiles += two;

        for (i = two; i < numWholeHpBarTiles; i++)
            StartSpriteAnim(sHpBarSummaryScreen->sprites[i], 8);

        animNum = (v1 * 6) / v0;
        StartSpriteAnim(sHpBarSummaryScreen->sprites[numWholeHpBarTiles], animNum);

        for (i = numWholeHpBarTiles + 1; i < 8; i++)
            StartSpriteAnim(sHpBarSummaryScreen->sprites[i], 0);
    }

    StartSpriteAnim(sHpBarSummaryScreen->sprites[0], 9);
    StartSpriteAnim(sHpBarSummaryScreen->sprites[1], 10);
    StartSpriteAnim(sHpBarSummaryScreen->sprites[8], 11);
}

static void PSS_UnloadHpBar(void)
{
    u8 i;

    for (i = 0; i < 9; i++)
        if (sHpBarSummaryScreen->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sHpBarSummaryScreen->sprites[i]);

    FREE_AND_SET_NULL_IF_SET(sHpBarSummaryScreen);
}

static void PSS_SetInvisibleHpBar(u8 invisible)
{
    u8 i;

    for (i = 0; i < 9; i++)
        sHpBarSummaryScreen->sprites[i]->invisible = invisible;
}

static void PSS_LoadExpBar(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void * gfxBufferPtr;
    const u32 *barGfx;
    bool8 isShadow;
    static struct SpriteTemplate sExpBarSpriteTemplate;

    sExpBarSummaryScreen = AllocZeroed(sizeof(struct Struct203B160));
    gfxBufferPtr = AllocZeroed(0x20 * 12);

    isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
    sExpBarIsShadow = isShadow;
    barGfx = isShadow ? gHeartBarSummaryScreen : gExpBarSummaryScreen;

    LZ77UnCompWram(barGfx, gfxBufferPtr);
    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = gPal0SummaryScreen, .tag = palTag};
        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);
    }

    sExpBarSpriteTemplate.tileTag = tileTag;
    sExpBarSpriteTemplate.paletteTag = palTag;
    sExpBarSpriteTemplate.oam = &sUnknown_8463A14;
    sExpBarSpriteTemplate.anims = sUnknown_8463A7C;
    sExpBarSpriteTemplate.images = NULL;
    sExpBarSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sExpBarSpriteTemplate.callback = SpriteCallbackDummy;

    for (i = 0; i < 11; i++)
    {
        sExpBarSummaryScreen->cordX[i] = i * 8 + 156;
        spriteId = CreateSprite(&sExpBarSpriteTemplate, sExpBarSummaryScreen->cordX[i], 130, 0);
        sExpBarSummaryScreen->sprites[i] = &gSprites[spriteId];
        sExpBarSummaryScreen->sprites[i]->oam.priority = 2;
        sExpBarSummaryScreen->tileTag = tileTag;
        sExpBarSummaryScreen->palTag = palTag;
    }

    PSS_SetupExpBar();
    PSS_SetInvisibleExpBar(1);

    FREE_AND_SET_NULL_IF_SET(gfxBufferPtr);
}

static void PSS_SetupExpBar(void)
{
    u8 numWholeExpBarTiles = 0;
    u8 i;
    u8 level;
    u32 exp;
    u32 totalExpToNextLevel;
    u32 curExpToNextLevel;
    u16 species;
    s64 v0;
    s64 v1;
    u8 animNum;
    u8 two = 2;
    bool8 isShadow;

    if (sMonSummaryScreen->isEgg)
        return;

    isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
    if (isShadow)
    {
        totalExpToNextLevel = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HEART_MAX);
        curExpToNextLevel = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HEART_VALUE);
        if (totalExpToNextLevel == 0)
            totalExpToNextLevel = SHADOW_HEART_GAUGE_MAX;
        if (curExpToNextLevel > totalExpToNextLevel)
            curExpToNextLevel = totalExpToNextLevel;
    }
    else
    {
        exp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_EXP);
        level = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LEVEL);
        species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);

        if (level >= 100)
        {
            for (i = two; i < 10; i++)
                StartSpriteAnim(sExpBarSummaryScreen->sprites[i], 0);

            StartSpriteAnim(sExpBarSummaryScreen->sprites[0], 9);
            StartSpriteAnim(sExpBarSummaryScreen->sprites[1], 10);
            StartSpriteAnim(sExpBarSummaryScreen->sprites[10], 11);
            return;
        }

        totalExpToNextLevel = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1]
            - gExperienceTables[gSpeciesInfo[species].growthRate][level];
        curExpToNextLevel = exp - gExperienceTables[gSpeciesInfo[species].growthRate][level];
    }

    v0 = ((totalExpToNextLevel << 2) / 8);
    if (v0 == 0)
        v0 = 1;
    v1 = (curExpToNextLevel << 2);

        while (TRUE)
        {
            if (v1 <= v0)
                break;
            v1 -= v0;
            numWholeExpBarTiles++;
        }

        numWholeExpBarTiles += two;

        for (i = two; i < numWholeExpBarTiles; i++)
            StartSpriteAnim(sExpBarSummaryScreen->sprites[i], 8);

        if (numWholeExpBarTiles >= 10)
        {
            if (totalExpToNextLevel == curExpToNextLevel)
                return;
            else
                StartSpriteAnim(sExpBarSummaryScreen->sprites[9], 7);
        }

        animNum = (v1 * 8) / v0;
        StartSpriteAnim(sExpBarSummaryScreen->sprites[numWholeExpBarTiles], animNum);

    for (i = numWholeExpBarTiles + 1; i < 10; i++)
        StartSpriteAnim(sExpBarSummaryScreen->sprites[i], 0);

    StartSpriteAnim(sExpBarSummaryScreen->sprites[0], 9);
    StartSpriteAnim(sExpBarSummaryScreen->sprites[1], 10);
    StartSpriteAnim(sExpBarSummaryScreen->sprites[10], 11);
}

static void sub_813AB38(void)
{
    u8 i;

    for (i = 0; i < 11; i++)
        if (sExpBarSummaryScreen->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sExpBarSummaryScreen->sprites[i]);

    FREE_AND_SET_NULL_IF_SET(sExpBarSummaryScreen);
}

static void PSS_SetInvisibleExpBar(u8 invisible)
{
    u8 i;

    for (i = 0; i < 11; i++)
        sExpBarSummaryScreen->sprites[i]->invisible = invisible;
}

static void PSS_LoadUnkPoint(u16 tileTag, u16 palTag)
{
    u16 spriteId;
    void * gfxBufferPtr;

    sUnknown_203B164 = AllocZeroed(sizeof(struct Struct203B164));
    gfxBufferPtr = AllocZeroed(0x20 * 1);

    LZ77UnCompWram(sUnknown_8463B20, gfxBufferPtr);

    if (sUnknown_203B164 != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 1,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = sUnknown_8463B00, .tag = palTag};
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sUnknown_8463AEC,
            .anims = sUnknown_8463AFC,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);

        spriteId = CreateSprite(&template, 114, 92, 0);
        sUnknown_203B164->sprite = &gSprites[spriteId];
        sUnknown_203B164->tileTag = tileTag;
        sUnknown_203B164->palTag = palTag;
    }

    sub_813ACF8(1);
    sub_813ACB4();

    FREE_AND_SET_NULL_IF_SET(gfxBufferPtr);
}

static void sub_813AC8C(void)
{
    if (sUnknown_203B164->sprite != NULL)
        DestroySpriteAndFreeResources(sUnknown_203B164->sprite);

    FREE_AND_SET_NULL_IF_SET(sUnknown_203B164);
}

static void sub_813ACB4(void)
{
    if (!CheckPartyPokerus(&sMonSummaryScreen->currentMon, 0)
        && CheckPartyHasHadPokerus(&sMonSummaryScreen->currentMon, 0))
        sub_813ACF8(0);
    else
        sub_813ACF8(1);
}

static void sub_813ACF8(u8 invisible)
{
    if (!CheckPartyPokerus(&sMonSummaryScreen->currentMon, 0)
        && CheckPartyHasHadPokerus(&sMonSummaryScreen->currentMon, 0))
    {
        sUnknown_203B164->sprite->invisible = invisible;
        return;
    }
    else
        sUnknown_203B164->sprite->invisible = TRUE;

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
    {
        sUnknown_203B164->sprite->invisible = TRUE;
        sUnknown_203B164->sprite->x = 16;
        sUnknown_203B164->sprite->y = 44;
    }
    else
    {
        sUnknown_203B164->sprite->x = 114;
        sUnknown_203B164->sprite->y = 92;
    }
}

static void PSS_LoadShinyIndicator(u16 tileTag, u16 palTag)
{
    u16 spriteId;
    void * gfxBufferPtr;

    sUnknown_203B168 = AllocZeroed(sizeof(struct Struct203B168));
    gfxBufferPtr = AllocZeroed(0x20 * 2);

    LZ77UnCompWram(gShinyIndicatorGfx, gfxBufferPtr);

    if (sUnknown_203B168 != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 2,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = gShinyIndicatorPalette, .tag = palTag};
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sUnknown_8463B30,
            .anims = sUnknown_8463B40,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);
        spriteId = CreateSprite(&template, 166, 50, 0);
        sUnknown_203B168->sprite = &gSprites[spriteId];
        sUnknown_203B168->tileTag = tileTag;
        sUnknown_203B168->palTag = palTag;
    }

    sub_813AEB0(1);
    sub_813AF50();

    FREE_AND_SET_NULL_IF_SET(gfxBufferPtr);
}

static void sub_813AE88(void)
{
    if (sUnknown_203B168->sprite != NULL)
        DestroySpriteAndFreeResources(sUnknown_203B168->sprite);

    FREE_AND_SET_NULL_IF_SET(sUnknown_203B168);
}

static void sub_813AEB0(u8 invisible)
{
    if (IsMonShiny(&sMonSummaryScreen->currentMon) == TRUE
        && !sMonSummaryScreen->isEgg)
        sUnknown_203B168->sprite->invisible = invisible;
    else
        sUnknown_203B168->sprite->invisible = TRUE;

    if (sMonSummaryScreen->curPageIndex == PSS_PAGE_MOVES_INFO)
    {
        sUnknown_203B168->sprite->x = 126;
        sUnknown_203B168->sprite->y = 20;
    }
    else
    {
        sUnknown_203B168->sprite->x = 166;
        sUnknown_203B168->sprite->y = 50;
    }
}

static void sub_813AF50(void)
{
    if (IsMonShiny(&sMonSummaryScreen->currentMon) == TRUE && !sMonSummaryScreen->isEgg)
        sub_813AEB0(0);
    else
        sub_813AEB0(1);
}

static void sub_813AF90(void)
{
    sub_813A21C();
    PSS_UnloadHpBar();
    sub_813AB38();
    PSS_UnloadMonSprite();
    sub_8139F20();
    sub_8139D90();
    PSS_UnloadMarkings();
    PSS_UnloadIconStatus();
    sub_813AC8C();
    sub_813AE88();
    ResetSpriteData();
}

static void sub_813AFC4(void)
{
    PSS_LoadPokeball();
    PSS_SetInvisiblePokeball(0);
    PSS_LoadMonIcon();
    PSS_LoadMonSprite();
    PSS_SetMonSpritePositionForPage();
    PSS_SetMonIconPositionForPage();
    PSS_SetInvisibleMonSprite(0);
    PSS_SetupHpBar();
    PSS_SetupExpBar();
    PSS_GetMarkings();
    PSS_ShowIconStatus();
    sub_813ACB4();
    sub_813AF50();
}

static void PSS_LoadMarkings(void)
{
    u32 markings = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MARKINGS);

    DestroySpriteAndFreeResources(sMonSummaryScreen->markingSprite);
    sMonSummaryScreen->markingSprite = CreateMonMarkingAllCombosSprite(TAG_PSS_UNK_8C, TAG_PSS_UNK_8C, sUnknown_84636E0);

    if (sMonSummaryScreen->markingSprite != NULL)
    {
        StartSpriteAnim(sMonSummaryScreen->markingSprite, markings);
        sMonSummaryScreen->markingSprite->x = 208;
        sMonSummaryScreen->markingSprite->y = 114;
    }

    PSS_SetInvisibleMarkings(1);
}

static void PSS_UnloadMarkings(void)
{
    DestroySpriteAndFreeResources(sMonSummaryScreen->markingSprite);
}

static void PSS_SetInvisibleMarkings(u8 invisible)
{
    u32 markings = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MARKINGS);

    if (markings == 0)
        sMonSummaryScreen->markingSprite->invisible = TRUE;
    else
        sMonSummaryScreen->markingSprite->invisible = invisible;
}

static void PSS_GetMarkings(void)
{
    u32 markings = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MARKINGS);

    StartSpriteAnim(sMonSummaryScreen->markingSprite, markings);
    PSS_SetInvisibleMarkings(0);
}

static void sub_813B120(u8 taskId, s8 a1)
{
    s8 v0 = -1;

    if (sMonSummaryScreen->isBoxMon == TRUE)
    {
        if (sMonSummaryScreen->curPageIndex != 0)
        {
            if (a1 == 1)
                a1 = 0;
            else
                a1 = 2;
        }
        else
        {
            if (a1 == 1)
                a1 = 1;
            else
                a1 = 3;
        }

        v0 = SeekToNextMonInBox(sMonSummaryScreen->monList.boxMons, GetLastViewedMonIndex(), sMonSummaryScreen->lastIndex, (u8)a1);
    }
    else
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() == FALSE
            && gReceivedRemoteLinkPlayers == 1
            && IsMultiBattle() == TRUE)
            v0 = sub_813B38C(a1);
        else
            v0 = sub_813B20C(a1);
    }

    if (v0 == -1)
        return;

    gLastViewedMonIndex = v0;
    CreateTask(sub_813B3F0, 0);
    sMonSummaryScreen->unk328C = 0;
}

static s16 SeekToNextMonInBox(struct BoxPokemon * boxMons, u8 curIndex, u8 maxIndex, u8 flags)
{
    s8 dir = (flags == 0 || flags == 1) ? 1 : -1;
    bool8 allowEggs = (flags == 1 || flags == 3);
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

static s8 sub_813B20C(s8 a0)
{
    struct Pokemon * partyMons = sMonSummaryScreen->monList.mons;
    s8 v1 = 0;

    if (sMonSummaryScreen->curPageIndex == 0)
    {
        if (a0 == -1 && gLastViewedMonIndex == 0)
            return -1;
        else if (a0 == 1 && gLastViewedMonIndex >= sMonSummaryScreen->lastIndex)
            return -1;
        else
            return gLastViewedMonIndex + a0;
    }

    while (TRUE)
    {
        v1 += a0;
        if (0 > gLastViewedMonIndex + v1 || gLastViewedMonIndex + v1 > sMonSummaryScreen->lastIndex)
            return -1;

        if (GetMonData(&partyMons[gLastViewedMonIndex + v1], MON_DATA_IS_EGG) == 0)
            return gLastViewedMonIndex + v1;
    }

    return -1;
}

static u8 sub_813B2C8(struct Pokemon * partyMons)
{
    if (GetMonData(partyMons, MON_DATA_SPECIES) != 0 && (sMonSummaryScreen->curPageIndex != 0 || GetMonData(partyMons, MON_DATA_IS_EGG) == 0))
        return TRUE;

    return FALSE;
}

static s8 sub_813B304(u8 a0)
{
    while (TRUE)
    {
        a0++;

        if (a0 == 6)
            return -1;
        if (sub_813B2C8(&gPlayerParty[sUnknown_8463FB8[a0]]) == TRUE)
            break;
    }

    return (s8)sUnknown_8463FB8[a0];
}

static s8 sub_813B348(u8 a0)
{
    while (1)
    {
        if (a0 == 0)
            return -1;

        a0--;

        if (sub_813B2C8(&gPlayerParty[sUnknown_8463FB8[a0]]) == TRUE)
            break;
    }

    return (s8)(sUnknown_8463FB8[a0]);
}

static s8 sub_813B38C(s8 a0)
{
    u8 v0 = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (sUnknown_8463FB8[i] == GetLastViewedMonIndex())
        {
            v0 = i;
            break;
        }

    if ((a0 == -1 && v0 == 0)
        || (a0 == 1 && v0 == 5))
        return -1;

    if (a0 == 1)
        return sub_813B304(v0);
    else
        return sub_813B348(v0);
}

static void sub_813B3F0(u8 id)
{
    bool8 isShadow;

    switch (sMonSummaryScreen->unk328C)
    {
    case 0:
        StopCryAndClearCrySongs();
        sUnknown_203B16D = 0;
        sUnknown_203B16E = 0;
        sMonSummaryScreen->unk328C++;
        break;
    case 1:
        PSS_UnloadMonSprite();
        sub_8139F20();
        sub_8139D90();
        sMonSummaryScreen->unk328C++;
        break;
    case 2:
        sub_8138B8C(&sMonSummaryScreen->currentMon);

        sMonSummaryScreen->isEgg = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_EGG);
        sMonSummaryScreen->isBadEgg = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sMonSummaryScreen->isBadEgg == TRUE)
            sMonSummaryScreen->isEgg = TRUE;

        if (sExpBarSummaryScreen != NULL)
        {
            isShadow = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_SHADOW);
            if (sExpBarIsShadow != isShadow)
            {
                sub_813AB38();
                PSS_LoadExpBar(TAG_PSS_UNK_82, TAG_PSS_UNK_82);
            }
        }

        sMonSummaryScreen->unk328C++;
        break;
    case 3:
        sMonSummaryScreen->unk328C++;
        break;
    case 4:
        sMonSummaryScreen->unk328C++;
        break;
    case 5:
        PSS_GetDataPokemon();
        sMonSummaryScreen->unk328C++;
        break;
    case 6:
        if (!sMonSummaryScreen->isEgg)
            PSS_GetStatsPokemon();

        sMonSummaryScreen->unk328C++;
        break;
    case 7:
        if (!sMonSummaryScreen->isEgg)
            sub_81367B0();

        sMonSummaryScreen->unk328C++;
        break;
    case 8:
        PSS_AddTextToWin3();
        PSS_AddTextToWin4();
        PSS_AddTextToWin5();
        sMonSummaryScreen->unk328C++;
        break;
    case 9:
        PSS_DrawMonMoveIcon();
        sub_8138538();
        sub_8137D28(sMonSummaryScreen->curPageIndex);
        sMonSummaryScreen->unk328C++;
        break;
    case 10:
        CopyWindowToVram(sMonSummaryScreen->window[0], 2);
        CopyWindowToVram(sMonSummaryScreen->window[1], 2);
        CopyWindowToVram(sMonSummaryScreen->window[2], 2);
        CopyWindowToVram(sMonSummaryScreen->window[3], 2);
        CopyWindowToVram(sMonSummaryScreen->window[4], 2);
        CopyWindowToVram(sMonSummaryScreen->window[5], 2);
        CopyWindowToVram(sMonSummaryScreen->window[6], 2);
        CopyBgTilemapBufferToVram(0);
        sMonSummaryScreen->unk328C++;
        break;
    case 11:
        if (GetLinkRecvQueueLength() <= 2 && !MenuHelpers_IsLinkActive())
        {
            sub_813AFC4();
            PSS_PlayMonCry();
            sMonSummaryScreen->unk328C++;
        }
        break;
    default:
        sMonSummaryScreen->unk328C = 0;
        DestroyTask(id);
        break;
    }
}

static void PSS_PlayMonCry(void)
{
    if (!GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_IS_EGG))
    {
        u16 species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);

        PlayCry_ByMode(species, 0, CRY_MODE_NORMAL);
    }
}

static void PSS_ScrollPSSBackground(void)
{
    ChangeBgX(2, 80, 1);
    ChangeBgY(2, 80, 1);
}
