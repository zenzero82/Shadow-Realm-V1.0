#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "money.h"
#include "overworld.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokenav.h"
#include "region_map.h"
#include "roaming_shadow_hunter.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"
#include "constants/flags.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_WALLY,
    MC_TYPE_BIRCH,
    MC_TYPE_RIVAL,
    MC_TYPE_LEADER
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u16 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u16 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    u16 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u16 mapSec;
};

struct MatchCallWally {
    u8 type;
    u16 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallBirch {
    u8 type;
    u16 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u8 playerGender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallWally *wally;
    const struct MatchCallBirch *birch;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 trainerPic;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCall_GetEnabled_NPC(match_call_t);
static bool32 MatchCall_GetEnabled_Trainer(match_call_t);
static bool32 MatchCall_GetEnabled_Wally(match_call_t);
static bool32 MatchCall_GetEnabled_Birch(match_call_t);
static bool32 MatchCall_GetEnabled_Rival(match_call_t);

static u16 MatchCall_GetMapSec_NPC(match_call_t);
static u16 MatchCall_GetMapSec_Trainer(match_call_t);
static u16 MatchCall_GetMapSec_Wally(match_call_t);
static u16 MatchCall_GetMapSec_Birch(match_call_t);
static u16 MatchCall_GetMapSec_Rival(match_call_t);

static bool32 MatchCall_IsRematchable_NPC(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer(match_call_t);
static bool32 MatchCall_IsRematchable_Wally(match_call_t);
static bool32 MatchCall_IsRematchable_Birch(match_call_t);
static bool32 MatchCall_IsRematchable_Rival(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t);
static bool32 MatchCall_HasCheckPage_Wally(match_call_t);
static bool32 MatchCall_HasCheckPage_Birch(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t);

static void MatchCall_GetMessage_NPC(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer(match_call_t, u8 *);
static void MatchCall_GetMessage_Wally(match_call_t, u8 *);
static void MatchCall_GetMessage_Birch(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_NPC(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Wally(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Birch(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival(match_call_t, const u8 **, const u8 **);

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);
static void MatchCall_GetMessage_ProfessorBirch(u8 *dest);
static void MatchCall_GetMessage_ProfessorRowan(u8 *dest);
static void MatchCall_GetMessage_Wes(u8 *dest);
static void MatchCall_BufferRowanDexRecommendation(u8 *dest);
static u16 MatchCall_CountSnaggedShadowMons(void);
static u16 MatchCall_CountSeenShadowMons(void);
static const struct MatchCallCheckPageOverride *MatchCall_GetCheckPageOverride(u32 idx);

// .rodata

static const match_call_text_data_t sMrStoneTextScripts[] = {
    { MatchCall_Text_MrStone1,  0xFFFF,                              FLAG_ENABLE_MR_STONE_POKENAV },
    { MatchCall_Text_MrStone2,  FLAG_ENABLE_MR_STONE_POKENAV,        0xFFFF },
    { MatchCall_Text_MrStone3,  FLAG_DELIVERED_STEVEN_LETTER,        0xFFFF },
    { MatchCall_Text_MrStone4,  FLAG_RECEIVED_EXP_SHARE,             0xFFFF },
    { MatchCall_Text_MrStone5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_MrStone6,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_MrStone7,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_MrStone8,  FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_MrStone9,  FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_MrStone10, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_MrStone11, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStructNPC sMrStoneMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = 0xFFFF,
    .desc = COMPOUND_STRING("DEVON PRES"),
    .name = COMPOUND_STRING("MR. STONE"),
    .textData = sMrStoneTextScripts
};

static const match_call_text_data_t sNormanTextScripts[] = {
    { MatchCall_Text_Norman1, FLAG_ENABLE_NORMAN_MATCH_CALL, 0xFFFF },
    { MatchCall_Text_Norman2, FLAG_DEFEATED_DEWFORD_GYM,     0xFFFF },
    { MatchCall_Text_Norman3, FLAG_DEFEATED_LAVARIDGE_GYM,   0xFFFF },
    { MatchCall_Text_Norman4, FLAG_DEFEATED_PETALBURG_GYM,   0xFFFF },
    { MatchCall_Text_Norman5, FLAG_RECEIVED_RED_OR_BLUE_ORB, 0xFFFF },
    { MatchCall_Text_Norman6, 0xFFFE,                        0xFFFF },
    { MatchCall_Text_Norman7, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman8, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman9, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { NULL,                   0xFFFF,                        0xFFFF }
};

static const struct MatchCallStructTrainer sNormanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_PETALBURG_CITY,
    .flag = FLAG_ENABLE_NORMAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_NORMAN,
    .desc = COMPOUND_STRING("RELIABLE ONE"),
    .name = COMPOUND_STRING("DAD"),
    .textData = sNormanTextScripts
};

static const struct MatchCallBirch sProfBirchMatchCallHeader =
{
    .type = MC_TYPE_BIRCH,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_BIRCH_MATCH_CALL,
    .desc = COMPOUND_STRING("{PKMN} PROF."),
    .name = COMPOUND_STRING("PROF. BIRCH")
};

static const match_call_text_data_t sBrockTextScripts[] = {
    { COMPOUND_STRING("BROCK: Tough battles are won by trainers\nwho stay steady from the first hit.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sMistyTextScripts[] = {
    { COMPOUND_STRING("MISTY: Keep your team moving.\nA battle gets messy when you go stiff.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sSurgeTextScripts[] = {
    { COMPOUND_STRING("LT. SURGE: Hit hard, hit fast,\nand never give the other side room to breathe!$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sErikaTextScripts[] = {
    { COMPOUND_STRING("ERIKA: Patience matters.\nA calm trainer notices what reckless ones miss.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sSabrinaTextScripts[] = {
    { COMPOUND_STRING("SABRINA: Read the pace of the battle.\nIntent becomes obvious to a focused mind.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sKogaTextScripts[] = {
    { COMPOUND_STRING("KOGA: Leave nothing obvious.\nThe best move is often the one your foe ignores.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sBlaineTextScripts[] = {
    { COMPOUND_STRING("BLAINE: Keep that fire burning!\nPressure wins fights when you control the heat.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sBlueTextScripts[] = {
    { COMPOUND_STRING("BLUE: If you're calling me,\nyou'd better still be training like it matters.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sFalknerTextScripts[] = {
    { COMPOUND_STRING("FALKNER: Positioning decides everything.\nA clean angle can win before the clash starts.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sBugsyTextScripts[] = {
    { COMPOUND_STRING("BUGSY: Tiny details matter!\nA smart trainer learns patterns other people skip.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sWhitneyTextScripts[] = {
    { COMPOUND_STRING("WHITNEY: Cute doesn't mean soft!\nIf your team has confidence, lean into it.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sMortyTextScripts[] = {
    { COMPOUND_STRING("MORTY: Don't rush every turn.\nSometimes a battle opens up if you wait and watch.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sChuckTextScripts[] = {
    { COMPOUND_STRING("CHUCK: Train with intent!\nIf your team can keep swinging, you'll break through.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sJasmineTextScripts[] = {
    { COMPOUND_STRING("JASMINE: Reliability matters.\nA sturdy team gives you time to make the right call.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sPryceTextScripts[] = {
    { COMPOUND_STRING("PRYCE: Experience wins battles.\nStudy old routes again and you'll see new answers.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const match_call_text_data_t sClairTextScripts[] = {
    { COMPOUND_STRING("CLAIR: Hold yourself to a higher standard.\nStrong trainers do not settle for sloppy wins.$"), 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructNPC sBrockMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_PEWTER_CITY,
    .flag = FLAG_BADGE09_GET,
    .desc = COMPOUND_STRING("PEWTER GYM"),
    .name = COMPOUND_STRING("BROCK"),
    .textData = sBrockTextScripts,
};

static const struct MatchCallStructNPC sMistyMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_CERULEAN_CITY,
    .flag = FLAG_BADGE10_GET,
    .desc = COMPOUND_STRING("CERULEAN GYM"),
    .name = COMPOUND_STRING("MISTY"),
    .textData = sMistyTextScripts,
};

static const struct MatchCallStructNPC sSurgeMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_VERMILION_CITY,
    .flag = FLAG_BADGE11_GET,
    .desc = COMPOUND_STRING("VERMILION GYM"),
    .name = COMPOUND_STRING("LT. SURGE"),
    .textData = sSurgeTextScripts,
};

static const struct MatchCallStructNPC sErikaMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_CELADON_CITY,
    .flag = FLAG_BADGE12_GET,
    .desc = COMPOUND_STRING("CELADON GYM"),
    .name = COMPOUND_STRING("ERIKA"),
    .textData = sErikaTextScripts,
};

static const struct MatchCallStructNPC sSabrinaMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_SAFFRON_CITY,
    .flag = FLAG_BADGE13_GET,
    .desc = COMPOUND_STRING("SAFFRON GYM"),
    .name = COMPOUND_STRING("SABRINA"),
    .textData = sSabrinaTextScripts,
};

static const struct MatchCallStructNPC sKogaMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_FUCHSIA_CITY,
    .flag = FLAG_BADGE14_GET,
    .desc = COMPOUND_STRING("FUCHSIA GYM"),
    .name = COMPOUND_STRING("KOGA"),
    .textData = sKogaTextScripts,
};

static const struct MatchCallStructNPC sBlaineMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_CINNABAR_ISLAND,
    .flag = FLAG_BADGE15_GET,
    .desc = COMPOUND_STRING("CINNABAR GYM"),
    .name = COMPOUND_STRING("BLAINE"),
    .textData = sBlaineTextScripts,
};

static const struct MatchCallStructNPC sBlueMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_VIRIDIAN_CITY,
    .flag = FLAG_BADGE16_GET,
    .desc = COMPOUND_STRING("VIRIDIAN GYM"),
    .name = COMPOUND_STRING("BLUE"),
    .textData = sBlueTextScripts,
};

static const struct MatchCallStructNPC sFalknerMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_VIOLET_CITY,
    .flag = FLAG_BADGE17_GET,
    .desc = COMPOUND_STRING("VIOLET GYM"),
    .name = COMPOUND_STRING("FALKNER"),
    .textData = sFalknerTextScripts,
};

static const struct MatchCallStructNPC sBugsyMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_AZALEA_TOWN,
    .flag = FLAG_BADGE18_GET,
    .desc = COMPOUND_STRING("AZALEA GYM"),
    .name = COMPOUND_STRING("BUGSY"),
    .textData = sBugsyTextScripts,
};

static const struct MatchCallStructNPC sWhitneyMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_GOLDENROD_CITY,
    .flag = FLAG_BADGE19_GET,
    .desc = COMPOUND_STRING("GOLDENROD GYM"),
    .name = COMPOUND_STRING("WHITNEY"),
    .textData = sWhitneyTextScripts,
};

static const struct MatchCallStructNPC sMortyMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_ECRUTEAK_CITY,
    .flag = FLAG_BADGE20_GET,
    .desc = COMPOUND_STRING("ECRUTEAK GYM"),
    .name = COMPOUND_STRING("MORTY"),
    .textData = sMortyTextScripts,
};

static const struct MatchCallStructNPC sChuckMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_CIANWOOD_CITY,
    .flag = FLAG_BADGE21_GET,
    .desc = COMPOUND_STRING("CIANWOOD GYM"),
    .name = COMPOUND_STRING("CHUCK"),
    .textData = sChuckTextScripts,
};

static const struct MatchCallStructNPC sJasmineMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_OLIVINE_CITY,
    .flag = FLAG_BADGE22_GET,
    .desc = COMPOUND_STRING("OLIVINE GYM"),
    .name = COMPOUND_STRING("JASMINE"),
    .textData = sJasmineTextScripts,
};

static const struct MatchCallStructNPC sPryceMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_MAHOGANY_TOWN,
    .flag = FLAG_BADGE23_GET,
    .desc = COMPOUND_STRING("MAHOGANY GYM"),
    .name = COMPOUND_STRING("PRYCE"),
    .textData = sPryceTextScripts,
};

static const struct MatchCallStructNPC sClairMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_BLACKTHORN_CITY,
    .flag = FLAG_BADGE24_GET,
    .desc = COMPOUND_STRING("BLACKTHORN GYM"),
    .name = COMPOUND_STRING("CLAIR"),
    .textData = sClairTextScripts,
};

static const struct MatchCallStructNPC sWesMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_RECEIVED_SHADOW_MONITOR,
    .desc = COMPOUND_STRING("SNAG MASTER"),
    .name = COMPOUND_STRING("WES"),
    .textData = NULL,
};

static const struct MatchCallStructNPC sProfessorBirchContactHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_WES_HIDEOUT_TALKED_BIRCH,
    .desc = COMPOUND_STRING("{PKMN} PROF."),
    .name = COMPOUND_STRING("PROF. BIRCH"),
    .textData = NULL,
};

static const struct MatchCallStructNPC sProfessorRowanContactHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_WES_HIDEOUT_TALKED_ROWAN,
    .desc = COMPOUND_STRING("{PKMN} PROF."),
    .name = COMPOUND_STRING("PROF. ROWAN"),
    .textData = NULL,
};

static const struct MatchCallCheckPageOverride sMatchCallCheckPageOverrides[] =
{
    {
        .idx = MC_HEADER_BROCK,
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .flag = FLAG_BADGE09_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Steady pressure."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Rock-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Pewter's leader keeps"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("his team grounded."),
        },
    },
    {
        .idx = MC_HEADER_MISTY,
        .trainerPic = TRAINER_PIC_MISTY,
        .flag = FLAG_BADGE10_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Fast repositioning."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Water-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Cerulean's leader hates"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("stiff, predictable play."),
        },
    },
    {
        .idx = MC_HEADER_SURGE,
        .trainerPic = TRAINER_PIC_SURGE,
        .flag = FLAG_BADGE11_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Relentless offense."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Electric-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("The Lightning American"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("likes fast KOs."),
        },
    },
    {
        .idx = MC_HEADER_ERIKA,
        .trainerPic = TRAINER_PIC_ERIKA,
        .flag = FLAG_BADGE12_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Measured control."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Grass-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Celadon's leader wins"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("by staying composed."),
        },
    },
    {
        .idx = MC_HEADER_SABRINA,
        .trainerPic = TRAINER_PIC_SABRINA,
        .flag = FLAG_BADGE13_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Reads battle tempo."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Psychic-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Saffron's leader punishes"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("obvious patterns."),
        },
    },
    {
        .idx = MC_HEADER_KOGA,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KOGA,
        .flag = FLAG_BADGE14_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Hidden setup lines."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Poison-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Fuchsia's leader values"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("tricks over noise."),
        },
    },
    {
        .idx = MC_HEADER_BLAINE,
        .trainerPic = TRAINER_PIC_BLAINE,
        .flag = FLAG_BADGE15_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Heat and pressure."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Fire-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Cinnabar's quiz master"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("likes hot streaks."),
        },
    },
    {
        .idx = MC_HEADER_BLUE,
        .trainerPic = TRAINER_PIC_LEADER_BLUE,
        .flag = FLAG_BADGE16_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Adaptive offense."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Mixed team."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Viridian's leader expects"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("sharp play at all times."),
        },
    },
    {
        .idx = MC_HEADER_FALKNER,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .flag = FLAG_BADGE17_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Wins on angles."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Flying-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Violet's leader values"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("clean positioning."),
        },
    },
    {
        .idx = MC_HEADER_BUGSY,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .flag = FLAG_BADGE18_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Pattern study."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Bug-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Azalea's leader spots"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("small battle details."),
        },
    },
    {
        .idx = MC_HEADER_WHITNEY,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .flag = FLAG_BADGE19_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Confidence first."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Normal-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Goldenrod's leader hits"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("hard through momentum."),
        },
    },
    {
        .idx = MC_HEADER_MORTY,
        .trainerPic = TRAINER_PIC_LEADER_MORTY,
        .flag = FLAG_BADGE20_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Patient reads."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Ghost-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Ecruteak's leader waits"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("for openings to show."),
        },
    },
    {
        .idx = MC_HEADER_CHUCK,
        .trainerPic = TRAINER_PIC_LEADER_CHUCK,
        .flag = FLAG_BADGE21_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Break through walls."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Fighting-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Cianwood's leader values"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("stamina and force."),
        },
    },
    {
        .idx = MC_HEADER_JASMINE,
        .trainerPic = TRAINER_PIC_LEADER_JASMINE,
        .flag = FLAG_BADGE22_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Reliable defense."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Steel-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Olivine's leader trusts"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("steady teams."),
        },
    },
    {
        .idx = MC_HEADER_PRYCE,
        .trainerPic = TRAINER_PIC_LEADER_PRYCE,
        .flag = FLAG_BADGE23_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Experience first."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Ice-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Mahogany's elder wins"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("through field wisdom."),
        },
    },
    {
        .idx = MC_HEADER_CLAIR,
        .trainerPic = TRAINER_PIC_LEADER_CLAIR,
        .flag = FLAG_BADGE24_GET,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("High standards."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Dragon-type core."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Blackthorn's leader hates"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("sloppy victories."),
        },
    },
    {
        .idx = MC_HEADER_WES,
        .trainerPic = TRAINER_PIC_WES,
        .flag = FLAG_RECEIVED_SHADOW_MONITOR,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Snag first, survive."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Anti-shadow team."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Wes tracks rescued"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("shadow Pokemon."),
        },
    },
    {
        .idx = MC_HEADER_PROF_BIRCH,
        .trainerPic = TRAINER_PIC_PROF_BIRCHFP,
        .flag = FLAG_WES_HIDEOUT_TALKED_BIRCH,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Field research."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Regional ecology."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Birch studies strange"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("activity in the wild."),
        },
    },
    {
        .idx = MC_HEADER_PROF_ROWAN,
        .trainerPic = TRAINER_PIC_PROF_ROWAN,
        .flag = FLAG_WES_HIDEOUT_TALKED_ROWAN,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = COMPOUND_STRING("Track the data."),
            [CHECK_PAGE_POKEMON]  = COMPOUND_STRING("Dex analysis."),
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("Rowan monitors hunters"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("and Dex progress."),
        },
    },
};

static const match_call_text_data_t sMomTextScripts[] = {
    { MatchCall_Text_Mom1, 0xFFFF,                      0xFFFF },
    { MatchCall_Text_Mom2, FLAG_DEFEATED_PETALBURG_GYM, 0xFFFF },
    { MatchCall_Text_Mom3, FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sMomMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NEW_BARK_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = COMPOUND_STRING("CALM & KIND"),
    .name = COMPOUND_STRING("MOM"),
    .textData = sMomTextScripts
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { MatchCall_Text_Steven1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Steven3, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Steven4, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Steven5, FLAG_DEFEATED_MOSSDEEP_GYM,          0xFFFF },
    { MatchCall_Text_Steven6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Steven7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF },
};

static const struct MatchCallStructNPC sStevenMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = COMPOUND_STRING("HARD AS ROCK"),
    .name = COMPOUND_STRING("STEVEN"),
    .textData = sStevenTextScripts
};

static const u8 gText_MayBrendanMatchCallDesc[] = _("RAD NEIGHBOR");

static const match_call_text_data_t sMayTextScripts[] = {
    { MatchCall_Text_May1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_May2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_May3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_May4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_May5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_May6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_May7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_May8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_May9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_May10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_May11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_May12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_May13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_May14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_May15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                 0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sMayMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = MALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_May,
    .textData = sMayTextScripts
};

static const match_call_text_data_t sBrendanTextScripts[] = {
    { MatchCall_Text_Brendan1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_Brendan2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_Brendan3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_Brendan4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_Brendan5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_Brendan6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Brendan7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_Brendan8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Brendan9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Brendan10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Brendan11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_Brendan12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Brendan13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Brendan14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Brendan15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sBrendanMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = FEMALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts
};

static const match_call_text_data_t sWallyTextScripts[] = {
    { MatchCall_Text_Wally1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Wally2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Wally3, FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Wally4, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Wally5, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Wally6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Wally7, FLAG_DEFEATED_WALLY_VICTORY_ROAD,    0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};

static const struct MatchCallLocationOverride sWallyLocationData[] = {
    { FLAG_HIDE_MAUVILLE_CITY_WALLY,          MAPSEC_VERDANTURF_TOWN },
    { FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,    MAPSEC_NONE },
    { FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY,  MAPSEC_VICTORY_ROAD },
    { 0xFFFF,                                 MAPSEC_NONE }
};

static const struct MatchCallWally sWallyMatchCallHeader =
{
    .type = MC_TYPE_WALLY,
    .mapSec = 0,
    .flag = FLAG_ENABLE_WALLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_WALLY_VR,
    .desc = COMPOUND_STRING("{PKMN} LOVER"),
    .textData = sWallyTextScripts,
    .locationData = sWallyLocationData
};

static const match_call_text_data_t sScottTextScripts[] = {
    { MatchCall_Text_Scott1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott2, FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY,  0xFFFF },
    { MatchCall_Text_Scott3, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Scott4, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Scott5, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Scott6, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Scott7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};


static const struct MatchCallStructNPC sScottMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = COMPOUND_STRING("ELUSIVE EYES"),
    .name = COMPOUND_STRING("SCOTT"),
    .textData = sScottTextScripts
};

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { MatchCall_Text_Roxanne1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Roxanne2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sRoxanneMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = REMATCH_ROXANNE,
    .desc = COMPOUND_STRING("ROCKIN' WHIZ"),
    .name = NULL,
    .textData = sRoxanneTextScripts
};

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { MatchCall_Text_Brawly1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Brawly2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBrawlyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_DEWFORD_TOWN,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_BRAWLY,
    .desc = COMPOUND_STRING("THE BIG HIT"),
    .name = NULL,
    .textData = sBrawlyTextScripts
};

static const match_call_text_data_t sWattsonTextScripts[] = {
    { MatchCall_Text_Wattson1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Wattson2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWattsonMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_MAUVILLE_CITY,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = REMATCH_WATTSON,
    .desc = COMPOUND_STRING("SWELL SHOCK"),
    .name = NULL,
    .textData = sWattsonTextScripts
};

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { MatchCall_Text_Flannery1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Flannery2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sFlanneryMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_LAVARIDGE_TOWN,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = REMATCH_FLANNERY,
    .desc = COMPOUND_STRING("PASSION BURN"),
    .name = NULL,
    .textData = sFlanneryTextScripts
};

static const match_call_text_data_t sWinonaTextScripts[] = {
    { MatchCall_Text_Winona1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Winona2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWinonaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FORTREE_CITY,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = REMATCH_WINONA,
    .desc = COMPOUND_STRING("SKY TAMER"),
    .name = NULL,
    .textData = sWinonaTextScripts
};

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { MatchCall_Text_TateLiza1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_TateLiza2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sTateLizaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_MOSSDEEP_CITY,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = REMATCH_TATE_AND_LIZA,
    .desc = COMPOUND_STRING("MYSTIC DUO"),
    .name = NULL,
    .textData = sTateLizaTextScripts
};

static const match_call_text_data_t sJuanTextScripts[] = {
    { MatchCall_Text_Juan1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Juan2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                 0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sJuanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_SOOTOPOLIS_CITY,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_JUAN,
    .desc = COMPOUND_STRING("DANDY CHARM"),
    .name = NULL,
    .textData = sJuanTextScripts
};

static const u8 gText_EliteFourMatchCallDesc[] = _("ELITE FOUR");

static const match_call_text_data_t sSidneyTextScripts[] = {
    { MatchCall_Text_Sidney, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sSidneyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_SIDNEY,
    .rematchTableIdx = REMATCH_SIDNEY,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sSidneyTextScripts
};

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { MatchCall_Text_Phoebe, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sPhoebeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_PHOEBE,
    .rematchTableIdx = REMATCH_PHOEBE,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sPhoebeTextScripts
};

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { MatchCall_Text_Glacia, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sGlaciaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_GLACIA,
    .rematchTableIdx = REMATCH_GLACIA,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sGlaciaTextScripts
};

static const match_call_text_data_t sDrakeTextScripts[] = {
    { MatchCall_Text_Drake, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sDrakeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_DRAKE,
    .rematchTableIdx = REMATCH_DRAKE,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sDrakeTextScripts
};

static const match_call_text_data_t sWallaceTextScripts[] = {
    { MatchCall_Text_Wallace, 0xFFFF, 0xFFFF },
    { NULL,                   0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sWallaceMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_WALLACE,
    .rematchTableIdx = REMATCH_WALLACE,
    .desc = COMPOUND_STRING("CHAMPION"),
    .name = NULL,
    .textData = sWallaceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    [MC_HEADER_BROCK]      = {.npc = &sBrockMatchCallHeader},
    [MC_HEADER_MISTY]      = {.npc = &sMistyMatchCallHeader},
    [MC_HEADER_SURGE]      = {.npc = &sSurgeMatchCallHeader},
    [MC_HEADER_ERIKA]      = {.npc = &sErikaMatchCallHeader},
    [MC_HEADER_SABRINA]    = {.npc = &sSabrinaMatchCallHeader},
    [MC_HEADER_KOGA]       = {.npc = &sKogaMatchCallHeader},
    [MC_HEADER_BLAINE]     = {.npc = &sBlaineMatchCallHeader},
    [MC_HEADER_BLUE]       = {.npc = &sBlueMatchCallHeader},
    [MC_HEADER_FALKNER]    = {.npc = &sFalknerMatchCallHeader},
    [MC_HEADER_BUGSY]      = {.npc = &sBugsyMatchCallHeader},
    [MC_HEADER_WHITNEY]    = {.npc = &sWhitneyMatchCallHeader},
    [MC_HEADER_MORTY]      = {.npc = &sMortyMatchCallHeader},
    [MC_HEADER_CHUCK]      = {.npc = &sChuckMatchCallHeader},
    [MC_HEADER_JASMINE]    = {.npc = &sJasmineMatchCallHeader},
    [MC_HEADER_PRYCE]      = {.npc = &sPryceMatchCallHeader},
    [MC_HEADER_CLAIR]      = {.npc = &sClairMatchCallHeader},
    [MC_HEADER_WES]        = {.npc = &sWesMatchCallHeader},
    [MC_HEADER_PROF_BIRCH] = {.npc = &sProfessorBirchContactHeader},
    [MC_HEADER_PROF_ROWAN] = {.npc = &sProfessorRowanContactHeader},
    [MC_HEADER_MOM]        = {.npc = &sMomMatchCallHeader},
};

static bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t) = {
    MatchCall_GetEnabled_NPC,
    MatchCall_GetEnabled_Trainer,
    MatchCall_GetEnabled_Wally,
    MatchCall_GetEnabled_Rival,
    MatchCall_GetEnabled_Birch
};

static u16 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCall_GetMapSec_NPC,
    MatchCall_GetMapSec_Trainer,
    MatchCall_GetMapSec_Wally,
    MatchCall_GetMapSec_Rival,
    MatchCall_GetMapSec_Birch
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_NPC,
    MatchCall_IsRematchable_Trainer,
    MatchCall_IsRematchable_Wally,
    MatchCall_IsRematchable_Rival,
    MatchCall_IsRematchable_Birch
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_NPC,
    MatchCall_HasCheckPage_Trainer,
    MatchCall_HasCheckPage_Wally,
    MatchCall_HasCheckPage_Rival,
    MatchCall_HasCheckPage_Birch
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_NPC,
    MatchCall_GetRematchTableIdx_Trainer,
    MatchCall_GetRematchTableIdx_Wally,
    MatchCall_GetRematchTableIdx_Rival,
    MatchCall_GetRematchTableIdx_Birch
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_NPC,
    MatchCall_GetMessage_Trainer,
    MatchCall_GetMessage_Wally,
    MatchCall_GetMessage_Rival,
    MatchCall_GetMessage_Birch
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_NPC,
    MatchCall_GetNameAndDesc_Trainer,
    MatchCall_GetNameAndDesc_Wally,
    MatchCall_GetNameAndDesc_Rival,
    MatchCall_GetNameAndDesc_Birch
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_WALLY:
            return 2;
        case MC_TYPE_RIVAL:
            return 3;
        case MC_TYPE_BIRCH:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetEnabledFuncs[i](matchCall);
}

static bool32 MatchCall_GetEnabled_NPC(match_call_t matchCall)
{
    if (!FlagGet(FLAG_RECEIVED_POKENAV))
        return FALSE;
    if (matchCall.npc->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}

static bool32 MatchCall_GetEnabled_Trainer(match_call_t matchCall)
{
    if (!FlagGet(FLAG_RECEIVED_POKENAV))
        return FALSE;
    if (matchCall.trainer->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}

static bool32 MatchCall_GetEnabled_Wally(match_call_t matchCall)
{
    if (!FlagGet(FLAG_RECEIVED_POKENAV))
        return FALSE;
    if (matchCall.wally->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.wally->flag);
}

static bool32 MatchCall_GetEnabled_Rival(match_call_t matchCall)
{
    if (matchCall.rival->playerGender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (!FlagGet(FLAG_RECEIVED_POKENAV))
        return FALSE;
    if (matchCall.rival->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}

static bool32 MatchCall_GetEnabled_Birch(match_call_t matchCall)
{
    if (!FlagGet(FLAG_RECEIVED_POKENAV))
        return FALSE;
    return FlagGet(matchCall.birch->flag);
}

u16 MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u16 MatchCall_GetMapSec_NPC(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}

static u16 MatchCall_GetMapSec_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}

static u16 MatchCall_GetMapSec_Wally(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.wally->locationData[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.wally->locationData[i].flag))
            break;
    }
    return matchCall.wally->locationData[i].mapSec;
}

static u16 MatchCall_GetMapSec_Rival(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

static u16 MatchCall_GetMapSec_Birch(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Trainer(match_call_t matchCall)
{
#if FREE_MATCH_CALL == FALSE
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
#else
    return FALSE;
#endif //FREE_MATCH_CALL
}

static bool32 MatchCall_IsRematchable_Wally(match_call_t matchCall)
{
#if FREE_MATCH_CALL == FALSE
    return gSaveBlock1Ptr->trainerRematches[matchCall.wally->rematchTableIdx] ? TRUE : FALSE;
#else
    return FALSE;
#endif //FREE_MATCH_CALL
}

static bool32 MatchCall_IsRematchable_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Birch(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_HasCheckPageFunctions[i](matchCall);
}

static bool32 MatchCall_HasCheckPage_NPC(match_call_t matchCall)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallHeaders[sMatchCallCheckPageOverrides[i].idx].npc == matchCall.npc
         && (sMatchCallCheckPageOverrides[i].flag == 0xFFFF || FlagGet(sMatchCallCheckPageOverrides[i].flag)))
            return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Trainer(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Wally(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Birch(match_call_t matchCall)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t matchCall)
{
    return matchCall.wally->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_NPC(match_call_t matchCall, u8 *dest)
{
    if (matchCall.npc->flag == FLAG_ENABLE_MOM_MATCH_CALL)
        ConvertIntToDecimalStringN(gStringVar1, GetGoldMomSavings(), STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);

    if (matchCall.npc->flag == FLAG_WES_HIDEOUT_TALKED_BIRCH)
    {
        MatchCall_GetMessage_ProfessorBirch(dest);
        return;
    }

    if (matchCall.npc->flag == FLAG_WES_HIDEOUT_TALKED_ROWAN)
    {
        MatchCall_GetMessage_ProfessorRowan(dest);
        return;
    }

    if (matchCall.npc->flag == FLAG_RECEIVED_SHADOW_MONITOR)
    {
        MatchCall_GetMessage_Wes(dest);
        return;
    }

    MatchCall_BufferCallMessageText(matchCall.npc->textData, dest);
}

// This is the one functional difference between MC_TYPE_TRAINER and MC_TYPE_LEADER
static void MatchCall_GetMessage_Trainer(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != MC_TYPE_LEADER)
        MatchCall_BufferCallMessageText(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Wally(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.wally->textData, dest);
}

static void MatchCall_GetMessage_Rival(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.rival->textData, dest);
}

static void MatchCall_GetMessage_Birch(match_call_t matchCall, u8 *dest)
{
    BufferPokedexRatingForMatchCall(dest);
}

static void MatchCall_GetMessage_ProfessorBirch(u8 *dest)
{
    static const u8 sBirchIntroText[] = _("BIRCH: That POKENAV should\nkeep us in touch.\pCall if anything strange\nturns up in the field.$");
    static const u8 sBirchBriefingText[] = _("BIRCH: We're nearly ready\non our end.\pCheck in with the other\nprofessors next.$");
    static const u8 sBirchMonitorText[] = _("BIRCH: Watch the SHADOW\nMONITOR for changes.\pFresh field data helps\nmore than guesswork.$");
    static const u8 sBirchNebbyText[] = _("BIRCH: Nebby's readings\nchanged everything.\pWe're learning how these\nportals behave.$");
    static const u8 sBirchReturnText[] = _("BIRCH: Swing back through\nHQ when you can.\pWe're lining up the next\nmove underground.$");
    static const u8 sBirchLegendaryText[] = _("BIRCH: Keep logging those\nlegendary sightings.\pTheir habitat shifts are\ntoo important to miss.$");

    if (FlagGet(FLAG_WES_HIDEOUT_LEGENDARY_QUESTS_REVEALED))
        StringExpandPlaceholders(dest, sBirchLegendaryText);
    else if (FlagGet(FLAG_QUEST_BACK_TO_HQ_STARTED))
        StringExpandPlaceholders(dest, sBirchReturnText);
    else if (FlagGet(FLAG_WES_HIDEOUT_NEBBY_SCENE_DONE))
        StringExpandPlaceholders(dest, sBirchNebbyText);
    else if (FlagGet(FLAG_RECEIVED_SHADOW_MONITOR))
        StringExpandPlaceholders(dest, sBirchMonitorText);
    else if (FlagGet(FLAG_WES_HIDEOUT_TEAM_BRIEFED))
        StringExpandPlaceholders(dest, sBirchBriefingText);
    else
        StringExpandPlaceholders(dest, sBirchIntroText);
}

static void MatchCall_GetMessage_ProfessorRowan(u8 *dest)
{
    static const u8 sRowanHunterText[] = _("ROWAN: Your tracker is\nspiking near {STR_VAR_1}.\pA shadow hunter is active\nthere right now.$");
    static const u8 sRowanUnknownAreaText[] = _("that area");

    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);

    if (active != NULL && active->active)
    {
        const struct MapHeader *mapHeader = Overworld_GetMapHeaderByGroupAndId(active->mapGroup, active->mapNum);

        if (mapHeader != NULL)
            GetMapNameGeneric(gStringVar1, mapHeader->regionMapSectionId);
        else
            StringCopy(gStringVar1, sRowanUnknownAreaText);

        StringExpandPlaceholders(dest, sRowanHunterText);
        return;
    }

    MatchCall_BufferRowanDexRecommendation(dest);
}

static void MatchCall_GetMessage_Wes(u8 *dest)
{
    static const u8 sWesIntroText[] = _("WES: The monitor shows\n{STR_VAR_1} logged and {STR_VAR_2} snagged.\pGood start. Keep taking\nshadows away from CIPHER.$");
    static const u8 sWesMidText[] = _("WES: {STR_VAR_2} successful\nsnags so far.\pStay sharp and don't pass\non clean snag chances.$");
    static const u8 sWesLateText[] = _("WES: {STR_VAR_2} shadow\nPokemon rescued.\pThat's real pressure on\nCIPHER. Keep moving.$");
    static const u8 sWesPurifiedText[] = _("WES: {STR_VAR_2} snagged and\nsome are purified.\pThat's how we win this,\none heart at a time.$");

    u16 seen = MatchCall_CountSeenShadowMons();
    u16 snagged = MatchCall_CountSnaggedShadowMons();
    ConvertIntToDecimalStringN(gStringVar1, seen, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, snagged, STR_CONV_MODE_LEFT_ALIGN, 3);

    if (snagged >= 40)
        StringExpandPlaceholders(dest, sWesPurifiedText);
    else if (snagged >= 20)
        StringExpandPlaceholders(dest, sWesLateText);
    else if (snagged >= 5)
        StringExpandPlaceholders(dest, sWesMidText);
    else
        StringExpandPlaceholders(dest, sWesIntroText);
}

static void MatchCall_BufferRowanDexRecommendation(u8 *dest)
{
    static const u8 sRowanDexIntro[] = _("ROWAN: Your Dex stands at\n{STR_VAR_1} seen and {STR_VAR_2} caught.\p");
    static const u8 sRowanDexEarly[] = _("Broaden your fieldwork.\nRevisit early routes,\ncaves, and side paths.$");
    static const u8 sRowanDexMidSeen[] = _("You're seeing enough,\nbut not catching enough.\nStop passing entries by.$");
    static const u8 sRowanDexMidCaught[] = _("Good progress.\nCheck fishing, surf,\nand time-based slots.$");
    static const u8 sRowanDexLate[] = _("Strong catalog.\nHunt evolutions, trades,\nand odd encounter methods.$");

    u16 seen = GetNationalPokedexCount(FLAG_GET_SEEN);
    u16 caught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    u8 *str;

    ConvertIntToDecimalStringN(gStringVar1, seen, STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar2, caught, STR_CONV_MODE_LEFT_ALIGN, 4);
    str = StringExpandPlaceholders(dest, sRowanDexIntro);

    if (caught < 25)
        StringCopy(str, sRowanDexEarly);
    else if (seen > caught + 40)
        StringCopy(str, sRowanDexMidSeen);
    else if (caught < 120)
        StringCopy(str, sRowanDexMidCaught);
    else
        StringCopy(str, sRowanDexLate);
}

static u16 MatchCall_CountSnaggedShadowMons(void)
{
    u16 count = 0;
    u16 shadowId;

    for (shadowId = 1; shadowId <= MAX_SHADOW_MON_IDS; shadowId++)
    {
        u8 state = Shdw_GetState(shadowId);

        if (state == SHDW_STATE_SNAGGED || state == SHDW_STATE_PURIFIED)
            count++;
    }

    return count;
}

static u16 MatchCall_CountSeenShadowMons(void)
{
    u16 count = 0;
    u16 shadowId;

    for (shadowId = 1; shadowId <= MAX_SHADOW_MON_IDS; shadowId++)
    {
        if (Shdw_GetState(shadowId) != SHDW_STATE_NEVER_SEEN)
            count++;
    }

    return count;
}

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (textData[i].flag != 0xFFFF && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    if (textData[i].flag2 != 0xFFFF)
        FlagSet(textData[i].flag2);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
#if FREE_MATCH_CALL == FALSE
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].flag == 0xFFFE)
            break;
        if (textData[i].flag != 0xFFFF && !FlagGet(textData[i].flag))
            break;
    }
    if (textData[i].flag != 0xFFFE)
    {
        if (i)
            i--;
        if (textData[i].flag2 != 0xFFFF)
            FlagSet(textData[i].flag2);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, textData[i].text);
    }
#endif //FREE_MATCH_CALL
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_NPC(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}

static void MatchCall_GetNameAndDesc_Trainer(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}

static void MatchCall_GetNameAndDesc_Wally(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    MatchCall_GetNameAndDescByRematchIdx(matchCall.wally->rematchTableIdx, desc, name);
    *desc = matchCall.wally->desc;
}

static void MatchCall_GetNameAndDesc_Rival(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = matchCall.rival->name;
}

static void MatchCall_GetNameAndDesc_Birch(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.birch->desc;
    *name = matchCall.birch->name;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = GetTrainerStructFromId(GetTrainerIdxByRematchIdx(idx));
    *desc = gTrainerClasses[trainer->trainerClass].name;
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    const struct MatchCallCheckPageOverride *override = MatchCall_GetCheckPageOverride(idx);

    if (override == NULL || offset >= CHECK_PAGE_ENTRY_COUNT)
        return NULL;

    return override->flavorTexts[offset];
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    (void)idx;
    return -1;
}

int MatchCall_GetOverrideTrainerPic(u32 idx)
{
    const struct MatchCallCheckPageOverride *override = MatchCall_GetCheckPageOverride(idx);

    if (override == NULL)
        return -1;

    return override->trainerPic;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
        FlagSet(TRAINER_REGISTERED_FLAGS_START + index);
}

static const struct MatchCallCheckPageOverride *MatchCall_GetCheckPageOverride(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx
         && (sMatchCallCheckPageOverrides[i].flag == 0xFFFF || FlagGet(sMatchCallCheckPageOverrides[i].flag)))
            return &sMatchCallCheckPageOverrides[i];
    }

    return NULL;
}
