#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "constants/item.h"
#include "constants/items.h"
#include "constants/tms_hms.h"

typedef void (*ItemUseFunc)(u8);

struct Item
{
    u32 price;
    u16 secondaryId;
    ItemUseFunc fieldUseFunc;
    const u8 *description;
    const u8 *effect;
    u8 name[ITEM_NAME_LENGTH];
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH];
    u8 holdEffect;
    u8 holdEffectParam;
    u8 importance:2;
    u8 notConsumed:1;
    u8 padding:5;
    u8 pocket;
    u8 type;
    u8 battleUsage;
    u8 flingPower;
    const u32 *iconPic;
    const u16 *iconPalette;
};

struct BagPocket
{
    struct ItemSlot *itemSlots;
    u8 capacity;
};

extern const struct Item gItemsInfo[];
extern struct BagPocket gBagPockets[];

void ApplyNewEncryptionKeyToBagItems(u32 newKey);
void ApplyNewEncryptionKeyToBagItems_(u32 newKey);
void SetBagItemsPointers(void);
u8 *CopyItemName(u16 itemId, u8 *dst);
u8 *CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity);
bool8 IsBagPocketNonEmpty(u8 pocket);
bool8 CheckBagHasItem(u16 itemId, u16 count);
bool8 HasAtLeastOneBerry(void);
bool8 HasAtLeastOnePokeBall(void);
bool8 CheckBagHasSpace(u16 itemId, u16 count);
u32 GetFreeSpaceForItemInBag(u16 itemId);
bool8 AddBagItem(u16 itemId, u16 count);
bool8 RemoveBagItem(u16 itemId, u16 count);
u8 GetPocketByItemId(u16 itemId);
void ClearItemSlots(struct ItemSlot *itemSlots, u8 itemCount);
u8 CountUsedPCItemSlots(void);
bool8 CheckPCHasItem(u16 itemId, u16 count);
bool8 AddPCItem(u16 itemId, u16 count);
void RemovePCItem(u8 index, u16 count);
void CompactPCItems(void);
void SwapRegisteredBike(void);
u16 BagGetItemIdByPocketPosition(u8 pocketId, u16 pocketPos);
u16 BagGetQuantityByPocketPosition(u8 pocketId, u16 pocketPos);
void CompactItemsInBagPocket(struct BagPocket *bagPocket);
void SortBerriesOrTMHMs(struct BagPocket *bagPocket);
void MoveItemSlotInList(struct ItemSlot *itemSlots_, u32 from, u32 to_);
void ClearBag(void);
u16 CountTotalItemQuantityInBag(u16 itemId);
bool8 AddPyramidBagItem(u16 itemId, u16 count);
bool8 RemovePyramidBagItem(u16 itemId, u16 count);
const u8 *GetItemName(u16 itemId);
u32 GetItemPrice(u16 itemId);
const u8 *GetItemEffect(u32 itemId);
u32 GetItemHoldEffect(u32 itemId);
u32 GetItemHoldEffectParam(u32 itemId);
const u8 *GetItemDescription(u16 itemId);
u8 GetItemImportance(u16 itemId);
u8 GetItemConsumability(u16 itemId);
u8 GetItemPocket(u16 itemId);
u8 GetItemType(u16 itemId);
ItemUseFunc GetItemFieldFunc(u16 itemId);
u8 GetItemBattleUsage(u16 itemId);
u32 GetItemSecondaryId(u32 itemId);
u32 GetItemFlingPower(u32 itemId);
u32 GetItemStatus1Mask(u16 itemId);
u32 GetItemStatus2Mask(u16 itemId);

/* Expands to:
 * enum
 * {
 *   ITEM_TM_TAKE_DOWN,
 *   ...
 * }; */
#define ENUM_TM(id) CAT(ITEM_TM_, id),
enum
{
    ENUM_TM_START_ = ITEM_TM01 - 1,
    FOREACH_TM(ENUM_TM)
};
#undef ENUM_TM

// Hoenn's overworld moves are retained as key-item field manuals, not HMs.
#define ITEM_HM01 ITEM_FIELD_MANUAL_CUT
#define ITEM_HM02 ITEM_TM_FLY
#define ITEM_HM03 ITEM_TM_SURF
#define ITEM_HM04 ITEM_FIELD_MANUAL_STRENGTH
#define ITEM_HM05 ITEM_FIELD_MANUAL_FLASH
#define ITEM_HM06 ITEM_FIELD_MANUAL_ROCK_SMASH
#define ITEM_HM07 ITEM_FIELD_MANUAL_WATERFALL
#define ITEM_HM08 ITEM_FIELD_MANUAL_DIVE
#define ITEM_HM_CUT ITEM_FIELD_MANUAL_CUT
#define ITEM_HM_FLY ITEM_TM_FLY
#define ITEM_HM_SURF ITEM_TM_SURF
#define ITEM_HM_STRENGTH ITEM_FIELD_MANUAL_STRENGTH
#define ITEM_HM_FLASH ITEM_FIELD_MANUAL_FLASH
#define ITEM_HM_ROCK_SMASH ITEM_FIELD_MANUAL_ROCK_SMASH
#define ITEM_HM_WATERFALL ITEM_FIELD_MANUAL_WATERFALL
#define ITEM_HM_DIVE ITEM_FIELD_MANUAL_DIVE

// Rewards from the original TM distribution that no longer exist as Gen 9 TMs.
#define ITEM_TM_HAIL ITEM_TM_SNOWSCAPE
#define ITEM_TM_HIDDEN_POWER ITEM_TM_TERA_BLAST
#define ITEM_TM_SAFEGUARD ITEM_TM_LIGHT_SCREEN
#define ITEM_TM_FRUSTRATION ITEM_TM_FACADE
#define ITEM_TM_IRON_TAIL ITEM_TM_SMART_STRIKE
#define ITEM_TM_RETURN ITEM_TM_DOUBLE_EDGE
#define ITEM_TM_DOUBLE_TEAM ITEM_TM_AGILITY
#define ITEM_TM_SHOCK_WAVE ITEM_TM_CHARGE_BEAM
#define ITEM_TM_TORMENT ITEM_TM_TAUNT
#define ITEM_TM_SECRET_POWER ITEM_TM_TERA_BLAST
#define ITEM_TM_ATTRACT ITEM_TM_CHARM
#define ITEM_TM_STEEL_WING ITEM_TM_SMART_STRIKE
#define ITEM_TM_SNATCH ITEM_TM_THIEF

#endif // GUARD_ITEM_H
