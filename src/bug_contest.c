#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "fieldmap.h"
#include "item.h"
#include "main.h"
#include "overworld.h"
#include "event_object_movement.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "safari_zone.h"
#include "script.h"
#include "string_util.h"
#include "bug_contest.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/species.h"

static bool32 IsPlayerDefeated(u32 battleOutcome);
static u16 GetBugContestSelectedMonIndex(void);
static u16 GetBugContestChosenDisplayIndex(void);
static u16 GetBugContestMonGraphicsId(struct Pokemon *mon);

static u32 sBugContestStartTime;
static bool8 sBugContestTimerActive;

#define BUG_CONTEST_PLAYER_MON_LOCAL_ID 22

bool32 GetBugContestFlag(void)
{
    return FlagGet(FLAG_SYS_BUG_CONTEST_MODE);
}

void PreparePartyForBugContest(void)
{
    u8 i;
    struct Pokemon *leadMon = &gPlayerParty[0];

    if (GetMonData(leadMon, MON_DATA_SPECIES) == SPECIES_NONE
        || GetMonData(leadMon, MON_DATA_IS_EGG)
        || GetMonData(leadMon, MON_DATA_HP) == 0)
    {
        gSpecialVar_Result = MON_CANT_GIVE;
        return;
    }

    for (i = 1; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);

    CompactPartySlots();
    gSpecialVar_Result = 0;
}

void BugContestRetirePrompt(void)
{
    ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
}

void EnterBugContestMode(void)
{
    FlagClear(FLAG_ADVENTURE_STARTED);
    FlagSet(FLAG_SYS_BUG_CONTEST_MODE);
    gNumSafariBalls = BUG_CONTEST_BALL_COUNT;
    sBugContestStartTime = gMain.vblankCounter1;
    sBugContestTimerActive = TRUE;
}

void ExitBugContestMode(void)
{
    FlagSet(FLAG_ADVENTURE_STARTED);
    FlagClear(FLAG_SYS_BUG_CONTEST_MODE);
    gNumSafariBalls = 0;
    sBugContestTimerActive = FALSE;
}

bool8 BugContestCheckTimeLimit(void)
{
    u32 elapsed;

    if (!FlagGet(FLAG_SYS_BUG_CONTEST_MODE) || !sBugContestTimerActive)
        return FALSE;

    elapsed = gMain.vblankCounter1 - sBugContestStartTime;
    if (elapsed >= BUG_CONTEST_TIME_LIMIT_FRAMES)
    {
        sBugContestTimerActive = FALSE;
        ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
        return TRUE;
    }

    return FALSE;
}

bool8 TransferBugContestMon(void)
{
    u8 monIndex = GetBugContestSelectedMonIndex();
    struct Pokemon *mon = &gPlayerParty[monIndex];

    if (CopyMonToPC(mon) == MON_GIVEN_TO_PC)
    {
        CompactPartySlots();
        gSpecialVar_Result = MON_GIVEN_TO_PC;
    }
    else
    {
        gSpecialVar_Result = MON_CANT_GIVE;
    }

    return FALSE;
}

bool8 JudgeBugContestMon(void)
{
    static const u16 sFirstPlaceRewards[] = {
        ITEM_MOON_STONE, ITEM_SUN_STONE, ITEM_LEAF_STONE
    };
    static const u16 sSecondPlaceRewards[] = {
        ITEM_FIRE_STONE, ITEM_THUNDER_STONE, ITEM_WATER_STONE
    };
    static const u16 sThirdPlaceRewards[] = {
        ITEM_ORAN_BERRY, ITEM_CHERI_BERRY, ITEM_PERSIM_BERRY,
        ITEM_PECHA_BERRY, ITEM_RAWST_BERRY, ITEM_ASPEAR_BERRY, ITEM_CHESTO_BERRY
    };

    u16 monIndex = GetBugContestSelectedMonIndex();
    u8 maxHP = GetMonData(&gPlayerParty[monIndex], MON_DATA_MAX_HP);
    u16 rand = Random() % 100;
    u16 placement;

    if (maxHP < 41)
        placement = 3;
    else if (maxHP <= 46)
        placement = (rand < 50) ? 2 : 3;
    else if (maxHP <= 47)
        placement = (rand < 75) ? 1 : 2;
    else
        placement = 1;

    gSpecialVar_Result = placement;
    switch (placement)
    {
    case 1:
        VarSet(VAR_0x8005, sFirstPlaceRewards[Random() % ARRAY_COUNT(sFirstPlaceRewards)]);
        break;
    case 2:
        VarSet(VAR_0x8005, sSecondPlaceRewards[Random() % ARRAY_COUNT(sSecondPlaceRewards)]);
        break;
    case 3:
        VarSet(VAR_0x8005, sThirdPlaceRewards[Random() % ARRAY_COUNT(sThirdPlaceRewards)]);
        break;
    default:
        VarSet(VAR_0x8005, ITEM_NONE);
        break;
    }

    return FALSE;
}

static bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_LOST:
    case B_OUTCOME_DREW:
        return TRUE;
    case B_OUTCOME_WON:
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
    case B_OUTCOME_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

void CB2_EndBugContestBattle(void)
{
    u8 i;
    u8 partyCount = 0;

    CpuFill16(0, (void *)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
            partyCount++;
    }

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_BugContestWhiteOut);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        if (partyCount == PARTY_SIZE)
        {
            ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        else
        {
            SetMainCallback2(CB2_ReturnToField);
            gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
        }
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
    }
}

bool8 RemoveSafariBalls(void)
{
    u16 count = CountTotalItemQuantityInBag(ITEM_SAFARI_BALL);

    if (count > 0)
        RemoveBagItem(ITEM_SAFARI_BALL, count);

    count = CountTotalItemQuantityInBag(ITEM_SPORT_BALL);

    if (count > 0)
        RemoveBagItem(ITEM_SPORT_BALL, count);

    return FALSE;
}

bool8 ShowBugContestChosenMon(void)
{
    u8 objectEventId;
    u16 monIndex = GetBugContestChosenDisplayIndex();
    struct Pokemon *mon = &gPlayerParty[monIndex];
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    StringCopy(gStringVar1, GetSpeciesName(species));
    gSpecialVar_Result = BUG_CONTEST_PLAYER_MON_LOCAL_ID;

    if (!TryGetObjectEventIdByLocalIdAndMap(BUG_CONTEST_PLAYER_MON_LOCAL_ID,
                                            gSaveBlock1Ptr->location.mapNum,
                                            gSaveBlock1Ptr->location.mapGroup,
                                            &objectEventId))
    {
        ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], GetBugContestMonGraphicsId(mon));
    }

    return FALSE;
}

static u16 GetBugContestSelectedMonIndex(void)
{
    u16 monIndex = VarGet(VAR_0x800A);

    if (monIndex < PARTY_SIZE
        && monIndex != 0
        && GetMonData(&gPlayerParty[monIndex], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        return monIndex;
    }

    monIndex = VarGet(VAR_0x8004);
    if (monIndex < PARTY_SIZE
        && monIndex != 0
        && GetMonData(&gPlayerParty[monIndex], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        return monIndex;
    }

    return GetBugContestChosenDisplayIndex();
}

static u16 GetBugContestChosenDisplayIndex(void)
{
    s32 i;

    for (i = PARTY_SIZE - 1; i >= 1; i--)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
            return i;
    }

    return 0;
}

static u16 GetBugContestMonGraphicsId(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u16 graphicsId = species + OBJ_EVENT_MON;

    if (IsMonShiny(mon))
        graphicsId |= OBJ_EVENT_MON_SHINY;
    if (GetMonGender(mon) == MON_FEMALE)
        graphicsId |= OBJ_EVENT_MON_FEMALE;
    if (GetMonData(mon, MON_DATA_IS_SHADOW))
        graphicsId |= OBJ_EVENT_MON_SHADOW;

    return graphicsId;
}
