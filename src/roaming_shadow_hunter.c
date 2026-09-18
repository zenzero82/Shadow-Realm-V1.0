#include "global.h"
#include "roaming_shadow_hunter.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "shadow_monitor_species.h"
#include "string_util.h"
#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/pokemon.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/opponents.h"
#include "constants/shadow.h"
#include "constants/vars.h"

#define ROAMING_HUNTER_MIN_MAP_LOADS 10
#define ROAMING_HUNTER_LEGACY_MAGIC_0 'R'
#define ROAMING_HUNTER_LEGACY_MAGIC_1 'S'
#define ROAMING_HUNTER_LEGACY_MAGIC_2 'H'

enum RoamingHunterTextPhase
{
    ROAMING_HUNTER_TEXT_INTRO,
    ROAMING_HUNTER_TEXT_DEFEAT,
    ROAMING_HUNTER_TEXT_OUTRO,
};

static bool8 PushMissedShadow(u8 region, u16 species, u8 level, u16 shadowId);

static const struct HunterSpawnPoint sHunterSpawnPoints_Kanto[] =
{
    {MAP_GROUP(MAP_ROCK_TUNNEL_B1F),     MAP_NUM(MAP_ROCK_TUNNEL_B1F),     24, 19},
    {MAP_GROUP(MAP_MT_MOON_CAVE),        MAP_NUM(MAP_MT_MOON_CAVE),        7, 7},
    {MAP_GROUP(MAP_DIGLETTS_CAVE_TUNNEL), MAP_NUM(MAP_DIGLETTS_CAVE_TUNNEL), 44, 37},
    {MAP_GROUP(MAP_DIGLETTS_CAVE_TUNNEL), MAP_NUM(MAP_DIGLETTS_CAVE_TUNNEL), 45, 37},
};

static const struct HunterSpawnPoint sHunterSpawnPoints_Johto[] =
{
    {MAP_GROUP(MAP_DARK_CAVE_SOUTH_SIDE), MAP_NUM(MAP_DARK_CAVE_SOUTH_SIDE), 17, 10},
    {MAP_GROUP(MAP_DARK_CAVE_NORTH_SIDE), MAP_NUM(MAP_DARK_CAVE_NORTH_SIDE), 6, 7},
    {MAP_GROUP(MAP_UNION_CAVE_1F),        MAP_NUM(MAP_UNION_CAVE_1F),        22, 55},
    {MAP_GROUP(MAP_UNION_CAVE_B1F),       MAP_NUM(MAP_UNION_CAVE_B1F),       23, 25},
    {MAP_GROUP(MAP_ILEX_FOREST),          MAP_NUM(MAP_ILEX_FOREST),          10, 24},
};

static const struct HunterSpawnPoint sHunterSpawnPoints_Hoenn[] =
{
    {MAP_GROUP(MAP_METEOR_FALLS_1F_1R),          MAP_NUM(MAP_METEOR_FALLS_1F_1R),          8, 9},
    {MAP_GROUP(MAP_MT_PYRE_1F),                  MAP_NUM(MAP_MT_PYRE_1F),                  7, 8},
    {MAP_GROUP(MAP_DESERT_RUINS),                MAP_NUM(MAP_DESERT_RUINS),                6, 7},
    {MAP_GROUP(MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM), MAP_NUM(MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM), 8, 7},
    {MAP_GROUP(MAP_RUSTURF_TUNNEL),              MAP_NUM(MAP_RUSTURF_TUNNEL),              9, 6},
};

static const struct HunterSpawnPoint *const sHunterSpawnPoints[ROAMING_SHADOW_HUNTER_REGION_COUNT] =
{
    sHunterSpawnPoints_Kanto,
    sHunterSpawnPoints_Johto,
    sHunterSpawnPoints_Hoenn,
};

static const u8 sHunterSpawnPointCounts[ROAMING_SHADOW_HUNTER_REGION_COUNT] =
{
    ARRAY_COUNT(sHunterSpawnPoints_Kanto),
    ARRAY_COUNT(sHunterSpawnPoints_Johto),
    ARRAY_COUNT(sHunterSpawnPoints_Hoenn),
};

static const u8 sHunterText_Cassidy_Intro0[] = _("Well, well. You really thought I'd\nbeat you to this shadow prize?");
static const u8 sHunterText_Cassidy_Intro1[] = _("Stand aside. That shadow POKéMON is\nfar too valuable for you.");
static const u8 sHunterText_Cassidy_Defeat0[] = _("Unbelievable. You actually got in my way.");
static const u8 sHunterText_Cassidy_Defeat1[] = _("Tch. This hunt was supposed to be easy.");
static const u8 sHunterText_Cassidy_Outro0[] = _("Keep it warm for me. I'll be taking it later.");
static const u8 sHunterText_Cassidy_Outro1[] = _("Enjoy your moment. I always come back for what's mine.");

static const u8 sHunterText_Butch_Intro0[] = _("Outta the way! That shadow POKéMON is my score.");
static const u8 sHunterText_Butch_Intro1[] = _("Heh! Found you before anyone else could. Bad luck for you.");
static const u8 sHunterText_Butch_Defeat0[] = _("What?! No way! I had this one locked down!");
static const u8 sHunterText_Butch_Defeat1[] = _("Gah! You smashed my whole setup!");
static const u8 sHunterText_Butch_Outro0[] = _("Fine! I'll track that shadow down again myself!");
static const u8 sHunterText_Butch_Outro1[] = _("This isn't over! I don't quit just because I lost once!");

static const u8 sHunterText_Silver_Intro0[] = _("If you can't take control of a shadow POKéMON,\nyou shouldn't chase one.");
static const u8 sHunterText_Silver_Intro1[] = _("I don't need your help. I just need you\nto stay out of my way.");
static const u8 sHunterText_Silver_Defeat0[] = _("...So you're not weak after all.");
static const u8 sHunterText_Silver_Defeat1[] = _("Hmph. Fine. You earned this one.");
static const u8 sHunterText_Silver_Outro0[] = _("Don't lose it. A shadow POKéMON punishes hesitation.");
static const u8 sHunterText_Silver_Outro1[] = _("Next time, be ready before I am.");

static const u8 sHunterText_Resix_Intro0[] = _("The red trace burns hot. I follow fire to the source.");
static const u8 sHunterText_Resix_Intro1[] = _("Resix sees the ember in every shadow. This one is mine.");
static const u8 sHunterText_Resix_Defeat0[] = _("The flame... slipped through my hands.");
static const u8 sHunterText_Resix_Defeat1[] = _("You smothered the trail.");
static const u8 sHunterText_Resix_Outro0[] = _("Even cooled ash remembers its spark.");
static const u8 sHunterText_Resix_Outro1[] = _("I'll follow that heat again.");

static const u8 sHunterText_Blusix_Intro0[] = _("Quiet now. The blue current leads straight to that shadow.");
static const u8 sHunterText_Blusix_Intro1[] = _("Blusix doesn't miss the cold shimmer around a shadow POKéMON.");
static const u8 sHunterText_Blusix_Defeat0[] = _("So the tide turned against me.");
static const u8 sHunterText_Blusix_Defeat1[] = _("The current broke...");
static const u8 sHunterText_Blusix_Outro0[] = _("Water always circles back. So will I.");
static const u8 sHunterText_Blusix_Outro1[] = _("That signal won't stay hidden forever.");

static const u8 sHunterText_Greesix_Intro0[] = _("The green echo in this place is alive. I can feel it.");
static const u8 sHunterText_Greesix_Intro1[] = _("A shadow POKéMON leaves a scar in the land. I follow scars.");
static const u8 sHunterText_Greesix_Defeat0[] = _("The forest went silent...");
static const u8 sHunterText_Greesix_Defeat1[] = _("You cut through the whole echo.");
static const u8 sHunterText_Greesix_Outro0[] = _("Roots spread farther than you think.");
static const u8 sHunterText_Greesix_Outro1[] = _("If that shadow stirs again, I'll hear it.");

static const u8 sHunterText_Purpsix_Intro0[] = _("That violet pulse is thick here. Deliciously dark.");
static const u8 sHunterText_Purpsix_Intro1[] = _("Purpsix follows the haze that shadow POKéMON leave behind.");
static const u8 sHunterText_Purpsix_Defeat0[] = _("Mm... the haze parted too soon.");
static const u8 sHunterText_Purpsix_Defeat1[] = _("You saw through the dark after all.");
static const u8 sHunterText_Purpsix_Outro0[] = _("Shadow always gathers again.");
static const u8 sHunterText_Purpsix_Outro1[] = _("When the haze thickens, I'll return.");

static const u8 sHunterText_Browsix_Intro0[] = _("Stone, dust, ruins... perfect places for a shadow to hide.");
static const u8 sHunterText_Browsix_Intro1[] = _("Browsix digs up every buried trail. This one ends here.");
static const u8 sHunterText_Browsix_Defeat0[] = _("Buried... by my own mistake.");
static const u8 sHunterText_Browsix_Defeat1[] = _("You cracked the whole trail wide open.");
static const u8 sHunterText_Browsix_Outro0[] = _("Old stone keeps secrets. I'll pull this one out yet.");
static const u8 sHunterText_Browsix_Outro1[] = _("That shadow isn't lost. Just hidden again.");

static const u8 sHunterText_Yellosix_Intro0[] = _("There it is. A bright little flicker in all this dark.");
static const u8 sHunterText_Yellosix_Intro1[] = _("Yellosix chases every spark until it burns out.");
static const u8 sHunterText_Yellosix_Defeat0[] = _("The spark jumped away from me...");
static const u8 sHunterText_Yellosix_Defeat1[] = _("You grounded me. Hah.");
static const u8 sHunterText_Yellosix_Outro0[] = _("Lightning never strikes just once.");
static const u8 sHunterText_Yellosix_Outro1[] = _("That flicker will shine again, and I'll be there.");
static const u8 sHunterText_Fallback[] = "...";

static const u8 *const sHunterIntroTexts[HUNTER_COUNT][2] =
{
    [HUNTER_CASSIDY] = {sHunterText_Cassidy_Intro0, sHunterText_Cassidy_Intro1},
    [HUNTER_BUTCH]   = {sHunterText_Butch_Intro0,   sHunterText_Butch_Intro1},
    [HUNTER_SILVER]  = {sHunterText_Silver_Intro0,  sHunterText_Silver_Intro1},
    [HUNTER_HEX_1]   = {sHunterText_Resix_Intro0,   sHunterText_Resix_Intro1},
    [HUNTER_HEX_2]   = {sHunterText_Blusix_Intro0,  sHunterText_Blusix_Intro1},
    [HUNTER_HEX_3]   = {sHunterText_Greesix_Intro0, sHunterText_Greesix_Intro1},
    [HUNTER_HEX_4]   = {sHunterText_Purpsix_Intro0, sHunterText_Purpsix_Intro1},
    [HUNTER_HEX_5]   = {sHunterText_Browsix_Intro0, sHunterText_Browsix_Intro1},
    [HUNTER_HEX_6]   = {sHunterText_Yellosix_Intro0, sHunterText_Yellosix_Intro1},
};

static const u8 *const sHunterDefeatTexts[HUNTER_COUNT][2] =
{
    [HUNTER_CASSIDY] = {sHunterText_Cassidy_Defeat0, sHunterText_Cassidy_Defeat1},
    [HUNTER_BUTCH]   = {sHunterText_Butch_Defeat0,   sHunterText_Butch_Defeat1},
    [HUNTER_SILVER]  = {sHunterText_Silver_Defeat0,  sHunterText_Silver_Defeat1},
    [HUNTER_HEX_1]   = {sHunterText_Resix_Defeat0,   sHunterText_Resix_Defeat1},
    [HUNTER_HEX_2]   = {sHunterText_Blusix_Defeat0,  sHunterText_Blusix_Defeat1},
    [HUNTER_HEX_3]   = {sHunterText_Greesix_Defeat0, sHunterText_Greesix_Defeat1},
    [HUNTER_HEX_4]   = {sHunterText_Purpsix_Defeat0, sHunterText_Purpsix_Defeat1},
    [HUNTER_HEX_5]   = {sHunterText_Browsix_Defeat0, sHunterText_Browsix_Defeat1},
    [HUNTER_HEX_6]   = {sHunterText_Yellosix_Defeat0, sHunterText_Yellosix_Defeat1},
};

static const u8 *const sHunterOutroTexts[HUNTER_COUNT][2] =
{
    [HUNTER_CASSIDY] = {sHunterText_Cassidy_Outro0, sHunterText_Cassidy_Outro1},
    [HUNTER_BUTCH]   = {sHunterText_Butch_Outro0,   sHunterText_Butch_Outro1},
    [HUNTER_SILVER]  = {sHunterText_Silver_Outro0,  sHunterText_Silver_Outro1},
    [HUNTER_HEX_1]   = {sHunterText_Resix_Outro0,   sHunterText_Resix_Outro1},
    [HUNTER_HEX_2]   = {sHunterText_Blusix_Outro0,  sHunterText_Blusix_Outro1},
    [HUNTER_HEX_3]   = {sHunterText_Greesix_Outro0, sHunterText_Greesix_Outro1},
    [HUNTER_HEX_4]   = {sHunterText_Purpsix_Outro0, sHunterText_Purpsix_Outro1},
    [HUNTER_HEX_5]   = {sHunterText_Browsix_Outro0, sHunterText_Browsix_Outro1},
    [HUNTER_HEX_6]   = {sHunterText_Yellosix_Outro0, sHunterText_Yellosix_Outro1},
};

static s8 RegionToIndex(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return 0;
    case REGION_JOHTO:
        return 1;
    case REGION_HOENN:
        return 2;
    default:
        return -1;
    }
}

static u8 ChooseHunterId(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return HUNTER_CASSIDY;
    case REGION_JOHTO:
        return HUNTER_SILVER;
    case REGION_HOENN:
        return HUNTER_HEX_1 + (Random() % 6);
    default:
        return HUNTER_CASSIDY;
    }
}

static u16 GetRegionActiveFlag(u8 region)
{
    switch (region)
    {
    case REGION_KANTO:
        return FLAG_ROAMING_HUNTER_KANTO_ACTIVE;
    case REGION_JOHTO:
        return FLAG_ROAMING_HUNTER_JOHTO_ACTIVE;
    case REGION_HOENN:
        return FLAG_ROAMING_HUNTER_HOENN_ACTIVE;
    default:
        return FLAG_ROAMING_HUNTER_KANTO_ACTIVE;
    }
}

static u16 GetHunterTrainerId(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
    case HUNTER_BUTCH:
        return TRAINER_CASSIDY_HUNTER;
    case HUNTER_SILVER:
        return TRAINER_SILVER_HUNTER;
    case HUNTER_HEX_1:
        return TRAINER_HEX_RESIX;
    case HUNTER_HEX_2:
        return TRAINER_HEX_BLUSIX;
    case HUNTER_HEX_3:
        return TRAINER_HEX_GREESIX;
    case HUNTER_HEX_4:
        return TRAINER_HEX_PURPSIX;
    case HUNTER_HEX_5:
        return TRAINER_HEX_BROWSIX;
    case HUNTER_HEX_6:
        return TRAINER_HEX_YELLOSIX;
    default:
        return TRAINER_NONE;
    }
}

static u8 GetHunterIdFromTrainer(u16 trainerId)
{
    switch (trainerId)
    {
    case TRAINER_CASSIDY_HUNTER:
        return HUNTER_CASSIDY;
    case TRAINER_BUTCH_HUNTER:
        return HUNTER_BUTCH;
    case TRAINER_SILVER_HUNTER:
        return HUNTER_SILVER;
    case TRAINER_HEX_RESIX:
        return HUNTER_HEX_1;
    case TRAINER_HEX_BLUSIX:
        return HUNTER_HEX_2;
    case TRAINER_HEX_GREESIX:
        return HUNTER_HEX_3;
    case TRAINER_HEX_PURPSIX:
        return HUNTER_HEX_4;
    case TRAINER_HEX_BROWSIX:
        return HUNTER_HEX_5;
    case TRAINER_HEX_YELLOSIX:
        return HUNTER_HEX_6;
    default:
        return HUNTER_COUNT;
    }
}

static u8 GetHunterRegionForId(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
    case HUNTER_BUTCH:
        return REGION_KANTO;
    case HUNTER_SILVER:
        return REGION_JOHTO;
    case HUNTER_HEX_1:
    case HUNTER_HEX_2:
    case HUNTER_HEX_3:
    case HUNTER_HEX_4:
    case HUNTER_HEX_5:
    case HUNTER_HEX_6:
        return REGION_HOENN;
    default:
        return REGION_KANTO;
    }
}

static u16 GetHunterObjectGfx(u8 hunterId)
{
    switch (hunterId)
    {
    case HUNTER_CASSIDY:
        return OBJ_EVENT_GFX_CASSIDY;
    case HUNTER_BUTCH:
        return OBJ_EVENT_GFX_BUTCH;
    case HUNTER_SILVER:
        return OBJ_EVENT_GFX_SILVER_GEN2;
    case HUNTER_HEX_1:
        return OBJ_EVENT_GFX_RESIX;
    case HUNTER_HEX_2:
        return OBJ_EVENT_GFX_BLUSIX;
    case HUNTER_HEX_3:
        return OBJ_EVENT_GFX_GREESIX;
    case HUNTER_HEX_4:
        return OBJ_EVENT_GFX_PURPSIX;
    case HUNTER_HEX_5:
        return OBJ_EVENT_GFX_BROWSIX;
    case HUNTER_HEX_6:
        return OBJ_EVENT_GFX_YELLOSIX;
    default:
        return OBJ_EVENT_GFX_HEX_MANIAC;
    }
}

static struct RoamingShadowHunterSave *GetRoamingHunterSave(void)
{
    return &gSaveBlock1Ptr->roamingShadowHunter;
}

static const struct ActiveHunterState *GetActiveHunterForCurrentMap(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);

    if (active == NULL || !active->active)
        return NULL;
    if (active->mapGroup != gSaveBlock1Ptr->location.mapGroup
     || active->mapNum != gSaveBlock1Ptr->location.mapNum)
        return NULL;
    return active;
}

static const u8 *GetHunterTextForPhase(u8 hunterId, u8 phase)
{
    if (hunterId >= HUNTER_COUNT)
        return NULL;

    switch (phase)
    {
    case ROAMING_HUNTER_TEXT_INTRO:
        return sHunterIntroTexts[hunterId][Random() % ARRAY_COUNT(sHunterIntroTexts[hunterId])];
    case ROAMING_HUNTER_TEXT_DEFEAT:
        return sHunterDefeatTexts[hunterId][Random() % ARRAY_COUNT(sHunterDefeatTexts[hunterId])];
    case ROAMING_HUNTER_TEXT_OUTRO:
        return sHunterOutroTexts[hunterId][Random() % ARRAY_COUNT(sHunterOutroTexts[hunterId])];
    default:
        return NULL;
    }
}

static void LoadHunterTextForPhase(u8 phase)
{
    const struct ActiveHunterState *active = GetActiveHunterForCurrentMap();
    const u8 *text = NULL;

    gStringVar4[0] = EOS;
    if (active != NULL)
        text = GetHunterTextForPhase(active->hunterId, phase);
    if (text == NULL)
        text = sHunterText_Fallback;
    StringCopy(gStringVar4, text);
}

static u32 Crc32B_RoamingHunter(const u8 *data, u32 size)
{
    s32 i;
    s32 j;
    u32 byte;
    u32 crc = 0xFFFFFFFF;
    u32 mask;

    for (i = 0; i < size; ++i)
    {
        byte = data[i];
        crc ^= byte;
        for (j = 7; j >= 0; --j)
        {
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
    }

    return ~crc;
}

static u32 GeneratePartyHash_RoamingHunter(const struct Trainer *trainer, u32 index)
{
    const u8 *buffer = (const u8 *)&trainer->party[index];
    return Crc32B_RoamingHunter(buffer, sizeof(*trainer->party));
}

static const struct TrainerMon *FindTrainerShadowPartyEntry(u16 trainerId, u16 shadowId, u32 *partyIndex)
{
    const struct Trainer *trainer;
    u32 i;

    if (trainerId == TRAINER_NONE)
        return NULL;

    trainer = GetTrainerStructFromId(trainerId);
    if (trainer == NULL || trainer->party == NULL)
        return NULL;

    for (i = 0; i < trainer->partySize; i++)
    {
        if (trainer->party[i].shadowID != shadowId)
            continue;
        if (partyIndex != NULL)
            *partyIndex = i;
        return &trainer->party[i];
    }

    return NULL;
}

static bool8 BuildRoamingHunterShadowMon(struct Pokemon *mon, u16 trainerId, u16 shadowId, u16 fallbackSpecies, u8 fallbackLevel)
{
    const struct Trainer *trainer;
    const struct TrainerMon *partyEntry;
    u32 partyIndex = 0;
    u32 personalityValue;
    u32 personalityHash;
    u32 otIdType = OT_ID_PLAYER_ID;
    u32 fixedOtId = 0;
    u32 abilityNum = 0;
    u8 ball = BALL_DARK;
    u8 isShadow = TRUE;
    u8 snagged = FALSE;
    u8 levelBoost = 0;

    trainer = GetTrainerStructFromId(trainerId);
    partyEntry = FindTrainerShadowPartyEntry(trainerId, shadowId, &partyIndex);
    if (trainer == NULL || partyEntry == NULL)
    {
        CreateMon(mon, fallbackSpecies, fallbackLevel, USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
        SetMonData(mon, MON_DATA_IS_SHADOW, &isShadow);
        SetMonData(mon, MON_DATA_SNAGGED, &snagged);
        SetMonData(mon, MON_DATA_POKEBALL, &ball);
        SetMonData(mon, MON_DATA_SHADOW_ID, &shadowId);
        SetMonHeartMax(mon, SHADOW_HEART_GAUGE_MAX);
        SetMonHeartValue(mon, SHADOW_HEART_GAUGE_MAX);
        abilityNum = 0;
        SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
        abilityNum = Shdw_GetAggroForNature(GetNature(mon));
        SetMonData(mon, MON_DATA_SHADOW_AGGRO, &abilityNum);
        CalculateMonStats(mon, 0);
        return FALSE;
    }

    if (trainer->battleType != TRAINER_BATTLE_TYPE_SINGLES)
        personalityValue = 0x80;
    else if (trainer->encounterMusic_gender & F_TRAINER_FEMALE)
        personalityValue = 0x78;
    else
        personalityValue = 0x88;

    personalityHash = GeneratePartyHash_RoamingHunter(trainer, partyIndex);
    personalityValue += personalityHash << 8;
    if (partyEntry->gender == TRAINER_MON_MALE)
        personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender(MON_MALE, partyEntry->species);
    else if (partyEntry->gender == TRAINER_MON_FEMALE)
        personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender(MON_FEMALE, partyEntry->species);
    else if (partyEntry->gender == TRAINER_MON_RANDOM_GENDER)
        personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender((personalityHash & 1) ? MON_MALE : MON_FEMALE, partyEntry->species);

    ModifyPersonalityForNature(&personalityValue, partyEntry->nature);
    CreateMon(mon, partyEntry->species, partyEntry->lvl, 0, TRUE, personalityValue, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_HELD_ITEM, &partyEntry->heldItem);
    CustomTrainerPartyAssignMoves(mon, partyEntry);
    SetMonData(mon, MON_DATA_IVS, &partyEntry->iv);
    if (partyEntry->ev != NULL)
    {
        SetMonData(mon, MON_DATA_HP_EV, &(partyEntry->ev[0]));
        SetMonData(mon, MON_DATA_ATK_EV, &(partyEntry->ev[1]));
        SetMonData(mon, MON_DATA_DEF_EV, &(partyEntry->ev[2]));
        SetMonData(mon, MON_DATA_SPATK_EV, &(partyEntry->ev[3]));
        SetMonData(mon, MON_DATA_SPDEF_EV, &(partyEntry->ev[4]));
        SetMonData(mon, MON_DATA_SPEED_EV, &(partyEntry->ev[5]));
    }

    if (partyEntry->ability != ABILITY_NONE)
    {
        const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[partyEntry->species];
        u32 maxAbilityNum = ARRAY_COUNT(speciesInfo->abilities);
        for (abilityNum = 0; abilityNum < maxAbilityNum; ++abilityNum)
        {
            if (speciesInfo->abilities[abilityNum] == partyEntry->ability)
                break;
        }
        if (abilityNum >= maxAbilityNum)
            abilityNum = 0;
    }
    else if (B_TRAINER_MON_RANDOM_ABILITY)
    {
        const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[partyEntry->species];
        abilityNum = personalityHash % 3;
        while (speciesInfo->abilities[abilityNum] == ABILITY_NONE)
            abilityNum--;
    }

    SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &partyEntry->friendship);
    if (partyEntry->ball != ITEM_NONE)
    {
        ball = ItemIdToBallId(partyEntry->ball);
        SetMonData(mon, MON_DATA_POKEBALL, &ball);
    }

    SetMonData(mon, MON_DATA_IS_SHADOW, &isShadow);
    SetMonData(mon, MON_DATA_SHADOW_ID, &partyEntry->shadowID);
    if (partyEntry->shadowAggro != SHADOW_AGGRO_NONE)
        abilityNum = partyEntry->shadowAggro;
    else
        abilityNum = Shdw_GetAggroForNature(GetNature(mon));
    SetMonData(mon, MON_DATA_SHADOW_AGGRO, &abilityNum);
    SetMonHeartValue(mon, partyEntry->heartGauge);
    SetMonHeartMax(mon, partyEntry->heartGauge);
    SetMonData(mon, MON_DATA_SNAGGED, &snagged);
    ball = BALL_DARK;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    levelBoost = partyEntry->boostLevel;
    CalculateMonStats(mon, levelBoost);
    return TRUE;
}

static u8 GetFallbackHunterLevel(void)
{
    u8 i;
    u8 highest = 1;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE)
            continue;

        if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) > highest)
            highest = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
    }

    return highest;
}

static bool8 IsShadowIdQueued(u8 regionIndex, u16 shadowId)
{
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    u8 i;
    u8 pos;

    if (regionIndex >= ROAMING_SHADOW_HUNTER_REGION_COUNT)
        return FALSE;

    pos = save->queueHead[regionIndex];
    for (i = 0; i < save->queueCount[regionIndex]; i++)
    {
        if (save->queue[regionIndex][pos].shadowId == shadowId)
            return TRUE;
        pos = (pos + 1) % ROAMING_SHADOW_QUEUE_SIZE;
    }

    return FALSE;
}

static void ScanLegacyFailedShadows(u8 region)
{
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    s8 regionIndex = RegionToIndex(region);
    u16 shadowId;
    u8 level;

    if (save->legacyScanMagic[0] != ROAMING_HUNTER_LEGACY_MAGIC_0
     || save->legacyScanMagic[1] != ROAMING_HUNTER_LEGACY_MAGIC_1
     || save->legacyScanMagic[2] != ROAMING_HUNTER_LEGACY_MAGIC_2)
    {
        save->legacyScanMagic[0] = ROAMING_HUNTER_LEGACY_MAGIC_0;
        save->legacyScanMagic[1] = ROAMING_HUNTER_LEGACY_MAGIC_1;
        save->legacyScanMagic[2] = ROAMING_HUNTER_LEGACY_MAGIC_2;
        save->legacyScanDone = FALSE;
    }

    if (save->legacyScanDone == TRUE)
        return;
    save->legacyScanDone = TRUE;

    if (regionIndex < 0)
        return;

    level = GetFallbackHunterLevel();

    // TODO: map shadowId to its original region if needed.
    for (shadowId = 1; shadowId <= MAX_SHADOW_MON_IDS; shadowId++)
    {
        u16 species;

        if (Shdw_GetState(shadowId) != SHDW_STATE_FAILED)
            continue;
        if (IsShadowIdQueued(regionIndex, shadowId))
            continue;
        if (save->active[regionIndex].active && save->active[regionIndex].shadowId == shadowId)
            continue;

        species = GetShadowMonitorSpecies(shadowId);
        if (species == SPECIES_NONE)
            continue;

        if (!PushMissedShadow(region, species, level, shadowId))
            break;
    }

    if (!save->active[regionIndex].active && save->queueCount[regionIndex] != 0)
        save->mapLoadCounter[regionIndex] = 0;
}

static void UpdateHunterHideFlagForMap(const struct ActiveHunterState *active)
{
    if (active != NULL
     && active->active
     && !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING)
     && active->mapGroup == gSaveBlock1Ptr->location.mapGroup
     && active->mapNum == gSaveBlock1Ptr->location.mapNum)
    {
        VarSet(VAR_OBJ_GFX_ID_0, GetHunterObjectGfx(active->hunterId));
        VarSet(VAR_ROAMING_HUNTER_X, active->x);
        VarSet(VAR_ROAMING_HUNTER_Y, active->y);
        FlagClear(FLAG_ROAMING_HUNTER_NPC_HIDE);
    }
    else
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
}

bool8 RoamingHunter_IsUnlocked(void)
{
    return FlagGet(FLAG_SHADOW_TRACKER_UNLOCKED);
}

static bool8 PushMissedShadow(u8 region, u16 species, u8 level, u16 shadowId)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct MissedShadowEntry *entry;
    u8 insertIndex;

    if (regionIndex < 0)
        return FALSE;
    if (save->queueCount[regionIndex] >= ROAMING_SHADOW_QUEUE_SIZE)
        return FALSE;

    insertIndex = (save->queueHead[regionIndex] + save->queueCount[regionIndex]) % ROAMING_SHADOW_QUEUE_SIZE;
    entry = &save->queue[regionIndex][insertIndex];
    entry->species = species;
    entry->shadowId = shadowId;
    entry->level = level;
    entry->region = region;
    entry->resolved = FALSE;
    entry->padding = 0;
    save->queueCount[regionIndex]++;
    return TRUE;
}

static bool8 PopMissedShadow(u8 region, struct MissedShadowEntry *out)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct MissedShadowEntry *entry;
    u8 head;

    if (regionIndex < 0)
        return FALSE;
    if (save->queueCount[regionIndex] == 0)
        return FALSE;

    head = save->queueHead[regionIndex];
    entry = &save->queue[regionIndex][head];
    if (out != NULL)
        *out = *entry;
    save->queueHead[regionIndex] = (head + 1) % ROAMING_SHADOW_QUEUE_SIZE;
    save->queueCount[regionIndex]--;
    return TRUE;
}

static void SpawnHunterForRegion(u8 region)
{
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save = GetRoamingHunterSave();
    struct ActiveHunterState *active;
    struct MissedShadowEntry entry;
    const struct HunterSpawnPoint *spawnPoint;
    u8 spawnIndex;

    if (regionIndex < 0)
        return;
    if (!RoamingHunter_IsUnlocked())
        return;

    active = &save->active[regionIndex];
    if (active->active)
        return;
    if (!PopMissedShadow(region, &entry))
        return;

    spawnIndex = Random() % sHunterSpawnPointCounts[regionIndex];
    spawnPoint = &sHunterSpawnPoints[regionIndex][spawnIndex];

    active->active = TRUE;
    active->region = region;
    active->hunterId = ChooseHunterId(region);
    active->shadowId = entry.shadowId;
    if (entry.shadowId != 0 && entry.shadowId <= MAX_SHADOW_MON_IDS)
        active->species = GetShadowMonitorSpecies(entry.shadowId);
    else
        active->species = entry.species;
    active->level = entry.level;
    active->mapGroup = spawnPoint->mapGroup;
    active->mapNum = spawnPoint->mapNum;
    active->x = spawnPoint->x;
    active->y = spawnPoint->y;
    save->mapLoadCounter[regionIndex] = 0;
    FlagSet(GetRegionActiveFlag(region));
    FlagSet(FLAG_ROAMING_HUNTER_ALERT_PENDING);
}

void RoamingHunter_OnShadowSnagFailed(struct Pokemon *mon, u8 region)
{
    struct RoamingShadowHunterSave *save;
    s8 regionIndex;
    u16 species;
    u8 level;
    u16 shadowId;

    if (!RoamingHunter_IsUnlocked())
        return;
    if (mon == NULL)
        return;

    species = GetMonData(mon, MON_DATA_SPECIES);
    level = GetMonData(mon, MON_DATA_LEVEL);
    shadowId = GetMonData(mon, MON_DATA_SHADOW_ID);
    if (species == SPECIES_NONE)
        return;
    if (level == 0)
        level = 1;
    if (!PushMissedShadow(region, species, level, shadowId))
        return;

    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return;

    save = GetRoamingHunterSave();
    if (!save->active[regionIndex].active && save->queueCount[regionIndex] == 1)
        save->mapLoadCounter[regionIndex] = 0;
}

const struct ActiveHunterState *RoamingHunter_GetActiveForRegion(u8 region)
{
    s8 regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return NULL;
    if (!RoamingHunter_IsUnlocked())
        return NULL;
    return &GetRoamingHunterSave()->active[regionIndex];
}

u16 RoamingHunter_TryCreateNpcOnMap(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);

    if (!RoamingHunter_IsUnlocked())
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }
    if (active == NULL || !active->active)
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }
    if (FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING))
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    if (active->mapGroup != gSaveBlock1Ptr->location.mapGroup
     || active->mapNum != gSaveBlock1Ptr->location.mapNum)
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    VarSet(VAR_ROAMING_HUNTER_X, active->x);
    VarSet(VAR_ROAMING_HUNTER_Y, active->y);
    VarSet(VAR_OBJ_GFX_ID_0, GetHunterObjectGfx(active->hunterId));
    gSpecialVar_Result = 1;
    return gSpecialVar_Result;
}

void RoamingHunter_OnMapTransition(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    s8 regionIndex = RegionToIndex(region);
    struct RoamingShadowHunterSave *save;
    struct ActiveHunterState *active;

    if (!RoamingHunter_IsUnlocked())
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }
    if (regionIndex < 0)
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }

    save = GetRoamingHunterSave();
    ScanLegacyFailedShadows(region);
    active = &save->active[regionIndex];
    if (!active->active)
    {
        if (save->queueCount[regionIndex] == 0)
        {
            save->mapLoadCounter[regionIndex] = 0;
            UpdateHunterHideFlagForMap(active);
            return;
        }

        if (save->mapLoadCounter[regionIndex] < 0xFF)
            save->mapLoadCounter[regionIndex]++;
        if (save->mapLoadCounter[regionIndex] < ROAMING_HUNTER_MIN_MAP_LOADS)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }
        if ((Random() & 1) == 0)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }

        SpawnHunterForRegion(region);
        active = &save->active[regionIndex];
        if (!active->active)
        {
            UpdateHunterHideFlagForMap(active);
            return;
        }
    }

    UpdateHunterHideFlagForMap(active);
}

void RoamingHunter_PrepareMapLoad(u8 mapGroup, u8 mapNum)
{
    u8 region = RegionMap_GetRegionFromMapGroup(mapGroup);
    const struct ActiveHunterState *active;

    if (!RoamingHunter_IsUnlocked())
    {
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
        return;
    }

    active = RoamingHunter_GetActiveForRegion(region);
    if (active != NULL
     && active->active
     && !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING)
     && active->mapGroup == mapGroup
     && active->mapNum == mapNum)
        FlagClear(FLAG_ROAMING_HUNTER_NPC_HIDE);
    else
        FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
}

u16 RoamingHunter_TryConsumeAlert(void)
{
    if (!RoamingHunter_IsUnlocked() || !FlagGet(FLAG_ROAMING_HUNTER_ALERT_PENDING))
    {
        gSpecialVar_Result = 0;
        return gSpecialVar_Result;
    }

    FlagClear(FLAG_ROAMING_HUNTER_ALERT_PENDING);
    UpdateHunterHideFlagForMap(RoamingHunter_GetActiveForRegion(
        RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup)));
    gSpecialVar_Result = 1;
    return gSpecialVar_Result;
}

u16 RoamingHunter_StartBattle(void)
{
    u8 region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    const struct ActiveHunterState *active = RoamingHunter_GetActiveForRegion(region);
    u16 trainerId;

    if (active == NULL || !active->active)
        return 0;
    if (!RoamingHunter_IsUnlocked())
        return 0;
    if (active->mapGroup != gSaveBlock1Ptr->location.mapGroup
     || active->mapNum != gSaveBlock1Ptr->location.mapNum)
        return 0;

    trainerId = GetHunterTrainerId(active->hunterId);
    if (trainerId == TRAINER_NONE)
        return 0;

    memset(gTrainerBattleParameter.data, 0, sizeof(gTrainerBattleParameter));
    TRAINER_BATTLE_PARAM.mode = TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT;
    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    TRAINER_BATTLE_PARAM.objEventLocalIdA = gSpecialVar_LastTalked;
    BattleSetup_StartTrainerBattle();
    return 1;
}

u16 RoamingHunter_OnBattleWon(void)
{
    u8 region;
    s8 regionIndex;
    struct RoamingShadowHunterSave *save;
    struct ActiveHunterState *active;

    if (!(gBattleOutcome & B_OUTCOME_WON))
        return 0;
    if (!RoamingHunter_IsUnlocked())
        return 0;

    region = RegionMap_GetRegionFromMapGroup(gSaveBlock1Ptr->location.mapGroup);
    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return 0;

    save = GetRoamingHunterSave();
    active = &save->active[regionIndex];
    if (!active->active)
        return 0;

    memset(active, 0, sizeof(*active));
    save->mapLoadCounter[regionIndex] = 0;
    FlagClear(GetRegionActiveFlag(region));
    return 1;
}

void RoamingHunter_TryOverrideTrainerParty(u16 trainerId, struct Pokemon *party)
{
    u8 hunterId = GetHunterIdFromTrainer(trainerId);
    u8 region;
    s8 regionIndex;
    struct ActiveHunterState *active;

    if (hunterId == HUNTER_COUNT)
        return;
    if (!RoamingHunter_IsUnlocked())
        return;
    if (party < gEnemyParty || party >= gEnemyParty + PARTY_SIZE)
        return;

    region = GetHunterRegionForId(hunterId);
    regionIndex = RegionToIndex(region);
    if (regionIndex < 0)
        return;

    active = &GetRoamingHunterSave()->active[regionIndex];
    if (!active->active)
        return;
    if (active->hunterId != hunterId)
    {
        u8 activeId = active->hunterId;
        if (activeId != HUNTER_BUTCH || hunterId != HUNTER_CASSIDY)
            return;
    }

    BuildRoamingHunterShadowMon(
        &party[0],
        GetShadowMonitorTrainerId(active->shadowId),
        active->shadowId,
        active->species,
        active->level
    );
}

u16 RoamingHunter_DidPlayerWinBattle(void)
{
    gSpecialVar_Result = ((gBattleOutcome & B_OUTCOME_WON) != 0);
    return gSpecialVar_Result;
}

u16 RoamingHunter_GetActiveTrainerId(void)
{
    const struct ActiveHunterState *active = GetActiveHunterForCurrentMap();

    if (active == NULL)
        gSpecialVar_Result = TRAINER_NONE;
    else
        gSpecialVar_Result = GetHunterTrainerId(active->hunterId);
    return gSpecialVar_Result;
}

u16 RoamingHunter_LoadIntroText(void)
{
    LoadHunterTextForPhase(ROAMING_HUNTER_TEXT_INTRO);
    return 1;
}

u16 RoamingHunter_LoadDefeatText(void)
{
    LoadHunterTextForPhase(ROAMING_HUNTER_TEXT_DEFEAT);
    return 1;
}

u16 RoamingHunter_LoadOutroText(void)
{
    LoadHunterTextForPhase(ROAMING_HUNTER_TEXT_OUTRO);
    return 1;
}

u16 RoamingHunter_DespawnNpc(void)
{
    FlagSet(FLAG_ROAMING_HUNTER_NPC_HIDE);
    RemoveObjectEventByLocalIdAndMap(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    gSpecialVar_Result = 1;
    return gSpecialVar_Result;
}
