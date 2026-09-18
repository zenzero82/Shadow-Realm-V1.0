#include "global.h"
#include "data.h"
#include "move.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "shadow_heart.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

#define SHADOW_HEART_STEP_THRESHOLD 256

static u16 Shadow_GetQuarterUnlockMoveById(u16 shadowId)
{
    u32 difficulty;
    u32 trainerId;

    if (shadowId == 0 || shadowId > MAX_SHADOW_MON_IDS)
        return MOVE_NONE;

    for (difficulty = 0; difficulty < DIFFICULTY_COUNT; difficulty++)
    {
        for (trainerId = 0; trainerId < TRAINERS_COUNT; trainerId++)
        {
            const struct Trainer *trainer = &gTrainers[difficulty][trainerId];
            u32 partyIndex;

            if (trainer->party == NULL)
                continue;

            for (partyIndex = 0; partyIndex < trainer->partySize; partyIndex++)
            {
                const struct TrainerMon *partyMon = &trainer->party[partyIndex];

                if (!partyMon->isShadow)
                    continue;
                if (partyMon->shadowID != shadowId)
                    continue;
                return partyMon->shadowUnlockMove;
            }
        }
    }

    return MOVE_NONE;
}

void Shadow_SyncQuarterUnlockMove(struct Pokemon *mon)
{
    u16 shadowId;
    u16 unlockMove;
    u16 heartValue;
    u16 heartMax;
    u16 currentMove;
    u32 i;

    if (!GetMonData(mon, MON_DATA_IS_SHADOW, NULL))
        return;

    shadowId = GetMonData(mon, MON_DATA_SHADOW_ID, NULL);
    unlockMove = Shadow_GetQuarterUnlockMoveById(shadowId);
    if (unlockMove == MOVE_NONE)
        return;

    heartValue = GetMonData(mon, MON_DATA_HEART_VALUE, NULL);
    heartMax = GetMonData(mon, MON_DATA_HEART_MAX, NULL);
    if (heartMax == 0)
        return;

    if (heartValue > heartMax / 4)
    {
        if (GetMonData(mon, MON_DATA_MOVE4, NULL) == unlockMove)
        {
            u16 move = MOVE_NONE;
            u8 pp = 0;

            SetMonData(mon, MON_DATA_MOVE4, &move);
            SetMonData(mon, MON_DATA_PP4, &pp);
        }
        return;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        currentMove = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);
        if (currentMove == unlockMove)
            return;
    }

    if (GetMonData(mon, MON_DATA_MOVE4, NULL) != MOVE_NONE)
        return;

    u8 pp = GetMovePP(unlockMove);
    SetMonData(mon, MON_DATA_MOVE4, &unlockMove);
    SetMonData(mon, MON_DATA_PP4, &pp);
}

static void Shadow_DecayPartyHeartValues(u16 amount)
{
    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            continue;
        if (!GetMonData(mon, MON_DATA_IS_SHADOW, NULL))
            continue;
        if (!GetMonData(mon, MON_DATA_SNAGGED, NULL))
            continue;

        u16 heartValue = GetMonData(mon, MON_DATA_HEART_VALUE, NULL);
        if (heartValue == 0)
            continue;

        u16 newValue = (heartValue > amount) ? heartValue - amount : 0;
        SetMonHeartValue(mon, newValue);
    }
}

static void Shadow_HandlePCShadowHeartDecay(u16 amount)
{
    // Stub: no PC decay for now, keeping the hook for future behavior.
    (void)amount;
}

void Shadow_HandleStepHeartDecay(void)
{
    static u16 sStepCounter;

    if (++sStepCounter >= SHADOW_HEART_STEP_THRESHOLD)
    {
        Shadow_DecayPartyHeartValues(1);
        sStepCounter -= SHADOW_HEART_STEP_THRESHOLD;
    }

    Shadow_HandlePCShadowHeartDecay(1);
    Shdw_UpdatePurifyReadyFlag();
}

u16 Shadow_GetJoyScentHeartReduction(u8 nature)
{
    switch (nature)
    {
    case NATURE_HARDY:   return 90;
    case NATURE_LONELY:  return 130;
    case NATURE_BRAVE:   return 80;
    case NATURE_ADAMANT: return 80;
    case NATURE_NAUGHTY: return 70;
    case NATURE_BOLD:    return 100;
    case NATURE_DOCILE:  return 120;
    case NATURE_RELAXED: return 100;
    case NATURE_IMPISH:  return 80;
    case NATURE_LAX:     return 110;
    case NATURE_TIMID:   return 120;
    case NATURE_HASTY:   return 100;
    case NATURE_SERIOUS: return 90;
    case NATURE_JOLLY:   return 90;
    case NATURE_NAIVE:   return 80;
    case NATURE_MODEST:  return 110;
    case NATURE_MILD:    return 120;
    case NATURE_QUIET:   return 100;
    case NATURE_BASHFUL: return 130;
    case NATURE_RASH:    return 120;
    case NATURE_CALM:    return 110;
    case NATURE_GENTLE:  return 100;
    case NATURE_SASSY:   return 70;
    case NATURE_CAREFUL: return 110;
    case NATURE_QUIRKY:  return 90;
    default:             return 90;
    }
}

u16 Shadow_GetCologneHeartReduction(struct Pokemon *mon, u16 itemId)
{
    u16 amount = Shadow_GetJoyScentHeartReduction(GetNature(mon));

    switch (itemId)
    {
    case ITEM_EXCITE_SCENT:
        return amount * 2;
    case ITEM_VIVID_SCENT:
        return amount * 3;
    case ITEM_JOY_SCENT:
    default:
        return amount;
    }
}
