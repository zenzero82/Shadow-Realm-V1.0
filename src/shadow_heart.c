#include "global.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "shadow_heart.h"
#include "constants/species.h"

#define SHADOW_HEART_STEP_THRESHOLD 100

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
