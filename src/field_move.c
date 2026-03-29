#include "global.h"
#include "event_data.h"
#include "field_move.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "surf_ow.h"
#include "string_util.h"
#include "constants/field_move.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/species.h"

EWRAM_DATA struct FieldMoveMonInfo gFieldMoveMonInfo = {0};

struct SurfBoxCache
{
    bool8 dirty;
    bool8 initialized;
    u16 owCount;
    u16 anyCount;
    u16 owSlots[TOTAL_BOXES_COUNT * IN_BOX_COUNT];
    u16 anySlots[TOTAL_BOXES_COUNT * IN_BOX_COUNT];
};

static EWRAM_DATA struct SurfBoxCache sSurfBoxCache;

void FieldMove_MarkSurfBoxCacheDirty(void)
{
    sSurfBoxCache.dirty = TRUE;
}

static void RebuildSurfBoxCache(void)
{
    u8 boxId;
    u8 boxPos;

    sSurfBoxCache.owCount = 0;
    sSurfBoxCache.anyCount = 0;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            if (!GetBoxMonDataAt(boxId, boxPos, MON_DATA_SANITY_HAS_SPECIES))
                continue;
            if (GetBoxMonDataAt(boxId, boxPos, MON_DATA_SANITY_IS_EGG))
                continue;

            u16 monSpecies = GetBoxMonDataAt(boxId, boxPos, MON_DATA_SPECIES);
            if (monSpecies == SPECIES_NONE)
                continue;
            if (!CanLearnTeachableMove(monSpecies, MOVE_SURF))
                continue;

            u16 slot = (boxId * IN_BOX_COUNT) + boxPos;
            sSurfBoxCache.anySlots[sSurfBoxCache.anyCount++] = slot;
            if (SurfOw_IsSpeciesEligible(monSpecies))
                sSurfBoxCache.owSlots[sSurfBoxCache.owCount++] = slot;
        }
    }

    sSurfBoxCache.dirty = FALSE;
    sSurfBoxCache.initialized = TRUE;
}

static bool8 GetRandomSurfBoxSlot(const u16 *slots, u16 count, u8 *boxId, u8 *boxPos)
{
    if (count == 0)
        return FALSE;

    u16 slot = slots[Random() % count];
    *boxId = slot / IN_BOX_COUNT;
    *boxPos = slot % IN_BOX_COUNT;
    return TRUE;
}

static bool8 GetRandomSurfBoxSlot_Ow(u8 *boxId, u8 *boxPos)
{
    if (!sSurfBoxCache.initialized || sSurfBoxCache.dirty)
        RebuildSurfBoxCache();

    return GetRandomSurfBoxSlot(sSurfBoxCache.owSlots, sSurfBoxCache.owCount, boxId, boxPos);
}

static bool8 GetRandomSurfBoxSlot_Any(u8 *boxId, u8 *boxPos)
{
    if (!sSurfBoxCache.initialized || sSurfBoxCache.dirty)
        RebuildSurfBoxCache();

    return GetRandomSurfBoxSlot(sSurfBoxCache.anySlots, sSurfBoxCache.anyCount, boxId, boxPos);
}

void ClearFieldMoveMonInfo(void)
{
    gFieldMoveMonInfo.valid = FALSE;
    gFieldMoveMonInfo.species = SPECIES_NONE;
    gFieldMoveMonInfo.move = MOVE_NONE;
    gFieldMoveMonInfo.personality = 0;
    gFieldMoveMonInfo.isShiny = FALSE;
    gFieldMoveMonInfo.boxId = 0;
    gFieldMoveMonInfo.boxPos = 0;
    gFieldMoveMonInfo.partyIndex = PARTY_SIZE;
    gFieldMoveMonInfo.fromBox = FALSE;
    gFieldMoveMonInfo.nickname[0] = '\0';
}

const struct FieldMoveMonInfo *GetFieldMoveMonInfo(void)
{
    return &gFieldMoveMonInfo;
}

bool8 FindFieldMoveMonForMove(u16 move, u8 *partyIndex, bool8 *fromBox, u16 *species)
{
    u32 i;
    struct FieldMoveMonInfo pick = {0};

    ClearFieldMoveMonInfo();
    *partyIndex = PARTY_SIZE;
    *fromBox = FALSE;
    *species = SPECIES_NONE;

    if (move == MOVE_SURF)
    {
        for (i = PARTY_SIZE; i-- > 0;)
        {
            u16 monSpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

            if (monSpecies == SPECIES_NONE)
                continue;
            if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                continue;
            if (!SurfOw_IsSpeciesEligible(monSpecies))
                continue;
            if (CanLearnTeachableMove(monSpecies, move))
            {
                gFieldMoveMonInfo.valid = TRUE;
                gFieldMoveMonInfo.fromBox = FALSE;
                gFieldMoveMonInfo.partyIndex = i;
                gFieldMoveMonInfo.species = monSpecies;
                gFieldMoveMonInfo.move = move;
                gFieldMoveMonInfo.personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
                gFieldMoveMonInfo.isShiny = GetMonData(&gPlayerParty[i], MON_DATA_IS_SHINY);
                GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, gFieldMoveMonInfo.nickname);
                StringGet_Nickname(gFieldMoveMonInfo.nickname);
                *partyIndex = i;
                *species = monSpecies;
                return TRUE;
            }
        }

        u8 boxId;
        u8 boxPos;
        if (GetRandomSurfBoxSlot_Ow(&boxId, &boxPos))
        {
            u16 monSpecies = GetBoxMonDataAt(boxId, boxPos, MON_DATA_SPECIES);

            pick.valid = TRUE;
            pick.boxId = boxId;
            pick.boxPos = boxPos;
            pick.partyIndex = PARTY_SIZE;
            pick.fromBox = TRUE;
            pick.species = monSpecies;
            pick.move = move;
            pick.personality = GetBoxMonDataAt(boxId, boxPos, MON_DATA_PERSONALITY);
            pick.isShiny = GetBoxMonDataAt(boxId, boxPos, MON_DATA_IS_SHINY);
            GetBoxMonNickAt(boxId, boxPos, pick.nickname);
            StringGet_Nickname(pick.nickname);
        }

        if (pick.valid)
        {
            gFieldMoveMonInfo = pick;
            *fromBox = TRUE;
            *species = pick.species;
            return TRUE;
        }
    }

    for (i = PARTY_SIZE; i-- > 0;)
    {
        u16 monSpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        if (monSpecies == SPECIES_NONE)
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            continue;
        if (CanLearnTeachableMove(monSpecies, move))
        {
            gFieldMoveMonInfo.valid = TRUE;
            gFieldMoveMonInfo.fromBox = FALSE;
            gFieldMoveMonInfo.partyIndex = i;
            gFieldMoveMonInfo.species = monSpecies;
            gFieldMoveMonInfo.move = move;
            gFieldMoveMonInfo.personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            gFieldMoveMonInfo.isShiny = GetMonData(&gPlayerParty[i], MON_DATA_IS_SHINY);
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, gFieldMoveMonInfo.nickname);
            StringGet_Nickname(gFieldMoveMonInfo.nickname);
            *partyIndex = i;
            *species = monSpecies;
            return TRUE;
        }
    }

    if (move == MOVE_SURF)
    {
        u8 boxId;
        u8 boxPos;
        if (GetRandomSurfBoxSlot_Any(&boxId, &boxPos))
        {
            u16 monSpecies = GetBoxMonDataAt(boxId, boxPos, MON_DATA_SPECIES);

            pick.valid = TRUE;
            pick.boxId = boxId;
            pick.boxPos = boxPos;
            pick.partyIndex = PARTY_SIZE;
            pick.fromBox = TRUE;
            pick.species = monSpecies;
            pick.move = move;
            pick.personality = GetBoxMonDataAt(boxId, boxPos, MON_DATA_PERSONALITY);
            pick.isShiny = GetBoxMonDataAt(boxId, boxPos, MON_DATA_IS_SHINY);
            GetBoxMonNickAt(boxId, boxPos, pick.nickname);
            StringGet_Nickname(pick.nickname);
        }
    }
    else
    {
        u32 boxCount = 0;
        pick = (struct FieldMoveMonInfo){0};
        for (u8 boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
        {
            for (u8 boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
            {
                if (!GetBoxMonDataAt(boxId, boxPos, MON_DATA_SANITY_HAS_SPECIES))
                    continue;
                if (GetBoxMonDataAt(boxId, boxPos, MON_DATA_SANITY_IS_EGG))
                    continue;
                u16 monSpecies = GetBoxMonDataAt(boxId, boxPos, MON_DATA_SPECIES);

                if (monSpecies == SPECIES_NONE)
                    continue;
                if (!CanLearnTeachableMove(monSpecies, move))
                    continue;

                boxCount++;
                if ((Random() % boxCount) == 0)
                {
                    pick.valid = TRUE;
                    pick.boxId = boxId;
                    pick.boxPos = boxPos;
                    pick.partyIndex = PARTY_SIZE;
                    pick.fromBox = TRUE;
                    pick.species = monSpecies;
                    pick.move = move;
                    pick.personality = GetBoxMonDataAt(boxId, boxPos, MON_DATA_PERSONALITY);
                    pick.isShiny = GetBoxMonDataAt(boxId, boxPos, MON_DATA_IS_SHINY);
                    GetBoxMonNickAt(boxId, boxPos, pick.nickname);
                    StringGet_Nickname(pick.nickname);
                }
            }
        }
    }

    if (pick.valid)
    {
        gFieldMoveMonInfo = pick;
        *fromBox = TRUE;
        *species = pick.species;
        return TRUE;
    }

    return FALSE;
}

static bool32 IsFieldMoveUnlocked_Cut(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Flash(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_RockSmash(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Strength(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Surf(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Fly(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Dive(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Waterfall(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Teleport(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Dig(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SecretPower(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_MilkDrink(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SoftBoiled(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SweetScent(void)
{
    return TRUE;
}

#if OW_DEFOG_FIELD_MOVE == TRUE
static bool32 IsFieldMoveUnlocked_Defog(void)
{
    return TRUE;
}
#endif

const struct FieldMoveInfo gFieldMoveInfo[FIELD_MOVES_COUNT] =
{
    [FIELD_MOVE_CUT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Cut,
        .isUnlockedFunc = IsFieldMoveUnlocked_Cut,
        .moveID = MOVE_CUT,
        .partyMsgID = PARTY_MSG_NOTHING_TO_CUT,
    },

    [FIELD_MOVE_FLASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Flash,
        .isUnlockedFunc = IsFieldMoveUnlocked_Flash,
        .moveID = MOVE_FLASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_ROCK_SMASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockSmash,
        .isUnlockedFunc = IsFieldMoveUnlocked_RockSmash,
        .moveID = MOVE_ROCK_SMASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_STRENGTH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Strength,
        .isUnlockedFunc = IsFieldMoveUnlocked_Strength,
        .moveID = MOVE_STRENGTH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SURF] =
    {
        .fieldMoveFunc = SetUpFieldMove_Surf,
        .isUnlockedFunc = IsFieldMoveUnlocked_Surf,
        .moveID = MOVE_SURF,
        .partyMsgID = PARTY_MSG_CANT_SURF_HERE,
    },

    [FIELD_MOVE_FLY] =
    {
        .fieldMoveFunc = SetUpFieldMove_Fly,
        .isUnlockedFunc = IsFieldMoveUnlocked_Fly,
        .moveID = MOVE_FLY,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIVE] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dive,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dive,
        .moveID = MOVE_DIVE,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_WATERFALL] =
    {
        .fieldMoveFunc = SetUpFieldMove_Waterfall,
        .isUnlockedFunc = IsFieldMoveUnlocked_Waterfall,
        .moveID = MOVE_WATERFALL,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_TELEPORT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Teleport,
        .isUnlockedFunc = IsFieldMoveUnlocked_Teleport,
        .moveID = MOVE_TELEPORT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dig,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dig,
        .moveID = MOVE_DIG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SECRET_POWER] =
    {
        .fieldMoveFunc = SetUpFieldMove_SecretPower,
        .isUnlockedFunc = IsFieldMoveUnlocked_SecretPower,
        .moveID = MOVE_SECRET_POWER,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_MILK_DRINK] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_MilkDrink,
        .moveID = MOVE_MILK_DRINK,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SOFT_BOILED] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_SoftBoiled,
        .moveID = MOVE_SOFT_BOILED,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SWEET_SCENT] =
    {
        .fieldMoveFunc = SetUpFieldMove_SweetScent,
        .isUnlockedFunc = IsFieldMoveUnlocked_SweetScent,
        .moveID = MOVE_SWEET_SCENT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

#if OW_DEFOG_FIELD_MOVE == TRUE
    [FIELD_MOVE_DEFOG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Defog,
        .isUnlockedFunc = IsFieldMoveUnlocked_Defog,
        .moveID = MOVE_DEFOG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
#endif

};
