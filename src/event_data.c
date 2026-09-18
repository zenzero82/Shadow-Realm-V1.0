#include "global.h"
#include "event_data.h"
#include "pokedex.h"

#define SPECIAL_FLAGS_SIZE  (NUM_SPECIAL_FLAGS / 8)  // 8 flags per byte
#define TEMP_FLAGS_SIZE     (NUM_TEMP_FLAGS / 8)
#define DAILY_FLAGS_SIZE    (NUM_DAILY_FLAGS / 8)
#define TEMP_VARS_SIZE      (NUM_TEMP_VARS * 2)      // 1/2 var per byte

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_Result = 0;
EWRAM_DATA u16 gSpecialVar_LastTalked = 0;
EWRAM_DATA u16 gSpecialVar_Facing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA u16 gSpecialVar_Unused_0x8014 = 0;
EWRAM_DATA static u8 sSpecialFlags[SPECIAL_FLAGS_SIZE] = {0};

#if TESTING
#define TEST_FLAGS_SIZE     1
#define TEST_VARS_SIZE      8
EWRAM_DATA static u8 sTestFlags[TEST_FLAGS_SIZE] = {0};
EWRAM_DATA static u16 sTestVars[TEST_VARS_SIZE] = {0};
#endif // TESTING

extern u16 *const gSpecialVars[];

#define CUSTOM_FLAGS_MAGIC       0x51535446 // "QSTF"
#define CUSTOM_FLAGS_VERSION     1

struct LegacyQuestFlagMigration
{
    u16 legacyId;
    u16 customId;
};

// Keep this table forever. It is used once to preserve quest state when an
// existing save first gains the protected custom flag bank.
static const struct LegacyQuestFlagMigration sLegacyQuestFlagMigrations[] =
{
    { 0x26E, FLAG_QUEST_PALLET_TOWN_STARTED },
    { 0x26F, FLAG_QUEST_PALLET_TOWN_COMPLETED },
    { 0x272, FLAG_QUEST_VIOLET_NPCS_STARTED },
    { 0x273, FLAG_QUEST_VIOLET_NPCS_COMPLETED },
    { 0x276, FLAG_QUEST_VIRIDIAN_GYM_STARTED },
    { 0x277, FLAG_QUEST_VIRIDIAN_GYM_COMPLETED },
    { 0x278, FLAG_QUEST_BROCK_STARTED },
    { 0x279, FLAG_QUEST_BROCK_COMPLETED },
    { 0x27A, FLAG_QUEST_CERULEAN_WES_STARTED },
    { 0x27B, FLAG_QUEST_CERULEAN_WES_COMPLETED },
    { 0x27C, FLAG_QUEST_CAPE_WES_STARTED },
    { 0x27D, FLAG_QUEST_CAPE_WES_COMPLETED },
    { 0x27F, FLAG_QUEST_PEWTER_NPCS_STARTED },
    { 0x280, FLAG_QUEST_PEWTER_NPCS_COMPLETED },
    { 0x285, FLAG_QUEST_MT_MOON_STARTED },
    { 0x286, FLAG_QUEST_MT_MOON_COMPLETED },
    { 0x28D, FLAG_QUEST_CERULEAN_NPCS_STARTED },
    { 0x28E, FLAG_QUEST_CERULEAN_NPCS_COMPLETED },
    { 0x29E, FLAG_QUEST_TALK_WES_STARTED },
    { 0x29F, FLAG_QUEST_TALK_WES_COMPLETED },
    { 0x2A0, FLAG_QUEST_TALK_TEAM_STARTED },
    { 0x2A1, FLAG_QUEST_TALK_TEAM_COMPLETED },
    { 0x2A2, FLAG_QUEST_SNAG_MACHINE_STARTED },
    { 0x2A3, FLAG_QUEST_SNAG_MACHINE_COMPLETED },
    { 0x2A4, FLAG_QUEST_SHADOW_TRAINER_STARTED },
    { 0x2A5, FLAG_QUEST_SHADOW_TRAINER_COMPLETED },
    { 0x2A6, FLAG_QUEST_DEFEAT_MISTY_STARTED },
    { 0x2A7, FLAG_QUEST_DEFEAT_MISTY_COMPLETED },
    { 0x2A8, FLAG_QUEST_ROUTE9_GUARDS_STARTED },
    { 0x2A9, FLAG_QUEST_ROUTE9_GUARDS_COMPLETED },
    { 0x2AC, FLAG_QUEST_KUKUI_SHADOW_STARTED },
    { 0x2AD, FLAG_QUEST_KUKUI_SHADOW_COMPLETED },
    { 0x2BA, FLAG_QUEST_PLASMA_TUNNEL_STARTED },
    { 0x2BB, FLAG_QUEST_PLASMA_TUNNEL_COMPLETED },
    { 0x468, FLAG_QUEST_DEFEAT_FALKNER_STARTED },
    { 0x470, FLAG_QUEST_DEFEAT_FALKNER_COMPLETED },
    { 0x472, FLAG_QUEST_SLOWPOKE_WELL_FLARE_STARTED },
    { 0x479, FLAG_QUEST_SLOWPOKE_WELL_FLARE_COMPLETED },
    { 0x4E2, FLAG_QUEST_KURT_APRICOT_STARTED },
    { 0x4E3, FLAG_QUEST_KURT_APRICOT_COMPLETED },
    { 0x4E4, FLAG_QUEST_AZALEA_NPCS_STARTED },
    { 0x4E5, FLAG_QUEST_AZALEA_NPCS_COMPLETED },
    { 0x4E6, FLAG_QUEST_DEFEAT_BUGSY_STARTED },
    { 0x4E7, FLAG_QUEST_DEFEAT_BUGSY_COMPLETED },
    { 0x5CE, FLAG_QUEST_CHERRYGROVE_NPCS_STARTED },
    { 0x5CF, FLAG_QUEST_CHERRYGROVE_NPCS_COMPLETED },
    { 0x5DC, FLAG_QUEST_NEW_BARK_NPCS_STARTED },
    { 0x5DD, FLAG_QUEST_NEW_BARK_NPCS_COMPLETED },
    { 0x5E6, FLAG_QUEST_GOLDS_MOM_STARTED },
    { 0x5E7, FLAG_QUEST_GOLDS_MOM_COMPLETED },
    { 0x53F, FLAG_QUEST_BACK_TO_HQ_STARTED },
    { 0x540, FLAG_QUEST_BACK_TO_HQ_COMPLETED },
    { 0x542, FLAG_QUEST_THUNDERBIRD_STARTED },
    { 0x543, FLAG_QUEST_THUNDERBIRD_COMPLETED },
    { 0x544, FLAG_QUEST_ICEBIRD_STARTED },
    { 0x545, FLAG_QUEST_ICEBIRD_COMPLETED },
    { 0x546, FLAG_QUEST_FIREBIRD_STARTED },
    { 0x547, FLAG_QUEST_FIREBIRD_COMPLETED },
    { 0x548, FLAG_QUEST_PHOENIX_STARTED },
    { 0x549, FLAG_QUEST_PHOENIX_COMPLETED },
    { 0x54A, FLAG_QUEST_SHINING_BEAST_STARTED },
    { 0x54B, FLAG_QUEST_SHINING_BEAST_COMPLETED },
    { 0x560, FLAG_QUEST_GIMMI_MY_MONEY_STARTED },
    { 0x561, FLAG_QUEST_GIMMI_MY_MONEY_COMPLETED },
    { 0x565, FLAG_QUEST_LAVENDER_NPCS_STARTED },
    { 0x566, FLAG_QUEST_LAVENDER_NPCS_COMPLETED },
    { 0x567, FLAG_QUEST_CELADON_NPCS_STARTED },
    { 0x568, FLAG_QUEST_CELADON_NPCS_COMPLETED },
    { 0x569, FLAG_QUEST_SAFFRON_NPCS_STARTED },
    { 0x56A, FLAG_QUEST_SAFFRON_NPCS_COMPLETED },
    { 0x56B, FLAG_QUEST_VERMILION_NPCS_STARTED },
    { 0x56C, FLAG_QUEST_VERMILION_NPCS_COMPLETED },
    { 0x56D, FLAG_QUEST_GOLDENROD_NPCS_STARTED },
    { 0x56E, FLAG_QUEST_GOLDENROD_NPCS_COMPLETED },
    { 0x56F, FLAG_QUEST_RUSTBORO_NPCS_STARTED },
    { 0x570, FLAG_QUEST_RUSTBORO_NPCS_COMPLETED },
    { 0x571, FLAG_QUEST_ODD_KEYSTONE_STARTED },
    { 0x572, FLAG_QUEST_ODD_KEYSTONE_COMPLETED },
    { 0x58E, FLAG_QUEST_ERICA_STARTED },
    { 0x58F, FLAG_QUEST_ERICA_COMPLETED },
    { 0x590, FLAG_QUEST_MEGA_MOMENTS_STARTED },
    { 0x591, FLAG_QUEST_MEGA_MOMENTS_COMPLETED },
    { 0x592, FLAG_QUEST_MACHINE_PART_STARTED },
    { 0x593, FLAG_QUEST_MACHINE_PART_COMPLETED },
    { 0x594, FLAG_QUEST_ALOLA_LILLIE_STARTED },
    { 0x595, FLAG_QUEST_ALOLA_LILLIE_COMPLETED },
    { 0x596, FLAG_QUEST_NEBBY_POWERHOUSE_STARTED },
    { 0x597, FLAG_QUEST_NEBBY_POWERHOUSE_COMPLETED },
    { 0x59A, FLAG_QUEST_WHITNEY_STARTED },
    { 0x59B, FLAG_QUEST_WHITNEY_COMPLETED },
    { 0x59C, FLAG_QUEST_CIPHER_TAKEOVER_STARTED },
    { 0x59D, FLAG_QUEST_CIPHER_TAKEOVER_COMPLETED },
    { 0x5A2, FLAG_QUEST_100_POWER_STARTED },
    { 0x5A3, FLAG_QUEST_100_POWER_COMPLETED },
    { 0x5AD, FLAG_QUEST_LT_SURGE_STARTED },
    { 0x5AE, FLAG_QUEST_LT_SURGE_COMPLETED },
    { 0x5B7, FLAG_QUEST_STARTERS_STOLEN_STARTED },
    { 0x5B8, FLAG_QUEST_STARTERS_STOLEN_COMPLETED },
    { 0x5C0, FLAG_QUEST_ROCKY_ROXY_STARTED },
    { 0x5C1, FLAG_QUEST_ROCKY_ROXY_COMPLETED },
    { 0x5C2, FLAG_QUEST_FIND_BRENDAN_MAY_STARTED },
    { 0x5C3, FLAG_QUEST_FIND_BRENDAN_MAY_COMPLETED },
    { 0x5E8, FLAG_QUEST_MORE_TO_COME_STARTED },
    { 0x5E9, FLAG_QUEST_MORE_TO_COME_COMPLETED },
    { 0x9D3, FLAG_QUEST_GOLDENROD_CITY_INFO_STARTED },
    { 0x9D4, FLAG_QUEST_GOLDENROD_CITY_INFO_COMPLETED },
};

STATIC_ASSERT(CUSTOM_FLAGS_START % 8 == 0, CustomFlagsStartMustBeByteAligned);
STATIC_ASSERT(CUSTOM_FLAGS_COUNT % 8 == 0, CustomFlagsCountMustBeByteAligned);
STATIC_ASSERT(CUSTOM_FLAGS_ALLOCATED <= CUSTOM_FLAGS_COUNT, TooManyCustomFlags);

static bool8 GetLegacyPersistentFlag(u16 id)
{
    return (gSaveBlock1Ptr->flags[id / 8] >> (id & 7)) & 1;
}

static void InitCustomFlagData(bool8 migrateLegacyQuestFlags)
{
    u16 i;

    memset(gSaveBlock3Ptr->customFlags, 0, sizeof(gSaveBlock3Ptr->customFlags));
    gSaveBlock3Ptr->customFlagsMagic = CUSTOM_FLAGS_MAGIC;
    gSaveBlock3Ptr->customFlagsVersion = CUSTOM_FLAGS_VERSION;
    gSaveBlock3Ptr->customFlagsVersionXor = ~CUSTOM_FLAGS_VERSION;

    if (!migrateLegacyQuestFlags)
        return;

    for (i = 0; i < ARRAY_COUNT(sLegacyQuestFlagMigrations); i++)
    {
        u16 customIndex;

        if (!GetLegacyPersistentFlag(sLegacyQuestFlagMigrations[i].legacyId))
            continue;

        customIndex = sLegacyQuestFlagMigrations[i].customId - CUSTOM_FLAGS_START;
        gSaveBlock3Ptr->customFlags[customIndex / 8] |= 1 << (customIndex & 7);
    }
}

void EnsureCustomFlagData(void)
{
    if (gSaveBlock3Ptr->customFlagsMagic == CUSTOM_FLAGS_MAGIC
     && gSaveBlock3Ptr->customFlagsVersion == CUSTOM_FLAGS_VERSION
     && gSaveBlock3Ptr->customFlagsVersionXor == (u16)~CUSTOM_FLAGS_VERSION)
        return;

    InitCustomFlagData(TRUE);
}

const u16 gBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
    FLAG_BADGE09_GET,
    FLAG_BADGE10_GET,
    FLAG_BADGE11_GET,
    FLAG_BADGE12_GET,
    FLAG_BADGE13_GET,
    FLAG_BADGE14_GET,
    FLAG_BADGE15_GET,
    FLAG_BADGE16_GET,
    FLAG_BADGE17_GET,
    FLAG_BADGE18_GET,
    FLAG_BADGE19_GET,
    FLAG_BADGE20_GET,
    FLAG_BADGE21_GET,
    FLAG_BADGE22_GET,
    FLAG_BADGE23_GET,
    FLAG_BADGE24_GET,
};

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(sSpecialFlags, 0, sizeof(sSpecialFlags));
    InitCustomFlagData(FALSE);
}

void ClearTempFieldEventData(void)
{
    memset(&gSaveBlock1Ptr->flags[TEMP_FLAGS_START / 8], 0, TEMP_FLAGS_SIZE);
    memset(&gSaveBlock1Ptr->vars[TEMP_VARS_START - VARS_START], 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
    FlagClear(FLAG_NURSE_UNION_ROOM_REMINDER);
}

void ClearDailyFlags(void)
{
    memset(&gSaveBlock1Ptr->flags[DAILY_FLAGS_START / 8], 0, DAILY_FLAGS_SIZE);
}

void DisableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    *nationalDexVar = 0;
    FlagClear(FLAG_SYS_NATIONAL_DEX);
}

void EnableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0xDA;
    *nationalDexVar = 0x302;
    FlagSet(FLAG_SYS_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_NATIONAL;
    gSaveBlock2Ptr->pokedex.order = 0;
    ResetPokedexScrollPositions();
}

bool32 IsNationalPokedexEnabled(void)
{
    if (gSaveBlock2Ptr->pokedex.nationalMagic == 0xDA && VarGet(VAR_NATIONAL_DEX) == 0x302 && FlagGet(FLAG_SYS_NATIONAL_DEX))
        return TRUE;
    else
        return FALSE;
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

bool32 IsMysteryEventEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

bool32 IsMysteryGiftEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void ClearMysteryGiftFlags(void)
{
    FlagClear(FLAG_MYSTERY_GIFT_DONE);
    FlagClear(FLAG_MYSTERY_GIFT_1);
    FlagClear(FLAG_MYSTERY_GIFT_2);
    FlagClear(FLAG_MYSTERY_GIFT_3);
    FlagClear(FLAG_MYSTERY_GIFT_4);
    FlagClear(FLAG_MYSTERY_GIFT_5);
    FlagClear(FLAG_MYSTERY_GIFT_6);
    FlagClear(FLAG_MYSTERY_GIFT_7);
    FlagClear(FLAG_MYSTERY_GIFT_8);
    FlagClear(FLAG_MYSTERY_GIFT_9);
    FlagClear(FLAG_MYSTERY_GIFT_10);
    FlagClear(FLAG_MYSTERY_GIFT_11);
    FlagClear(FLAG_MYSTERY_GIFT_12);
    FlagClear(FLAG_MYSTERY_GIFT_13);
    FlagClear(FLAG_MYSTERY_GIFT_14);
    FlagClear(FLAG_MYSTERY_GIFT_15);
}

void ClearMysteryGiftVars(void)
{
    VarSet(VAR_GIFT_PICHU_SLOT, 0);
    VarSet(VAR_GIFT_UNUSED_1, 0);
    VarSet(VAR_GIFT_UNUSED_2, 0);
    VarSet(VAR_GIFT_UNUSED_3, 0);
    VarSet(VAR_GIFT_UNUSED_4, 0);
    VarSet(VAR_GIFT_UNUSED_5, 0);
    VarSet(VAR_GIFT_UNUSED_6, 0);
    VarSet(VAR_GIFT_UNUSED_7, 0);
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < VARS_START)
        return NULL;
    else if (id < SPECIAL_VARS_START)
        return &gSaveBlock1Ptr->vars[id - VARS_START];
#if TESTING
    else if (id >= TESTING_VARS_START)
        return &sTestVars[id - TESTING_VARS_START];
#endif // TESTING
    else
        return gSpecialVars[id - SPECIAL_VARS_START];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

u16 VarGetIfExist(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return 65535;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u16 VarGetObjectEventGraphicsId(u8 id)
{
    return VarGet(VAR_OBJ_GFX_ID_0 + id);
}

u8 *GetFlagPointer(u16 id)
{
    if (id == 0)
        return NULL;
    else if (id < FLAGS_COUNT)
        return &gSaveBlock1Ptr->flags[id / 8];
    else if (id >= CUSTOM_FLAGS_START && id <= CUSTOM_FLAGS_END)
        return &gSaveBlock3Ptr->customFlags[(id - CUSTOM_FLAGS_START) / 8];
#if TESTING
    else if (id >= TESTING_FLAGS_START && id < TESTING_FLAGS_START + TEST_FLAGS_SIZE * 8)
        return &sTestFlags[(id - TESTING_FLAGS_START) / 8];
#endif // TESTING
    else if (id >= SPECIAL_FLAGS_START && id <= SPECIAL_FLAGS_END)
        return &sSpecialFlags[(id - SPECIAL_FLAGS_START) / 8];
    else
        return NULL;
}

u8 FlagSet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 FlagToggle(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr ^= 1 << (id & 7);
    return 0;
}

u8 FlagClear(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 FlagGet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}
