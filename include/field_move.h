#ifndef GUARD_FIELD_MOVE_H
#define GUARD_FIELD_MOVE_H

#include "global.h"
#include "constants/field_move.h"

#define FIELD_MOVE_MON_FROM_BOX 0x8000

struct FieldMoveInfo
{
    bool32 (*fieldMoveFunc)(void);
    bool32 (*isUnlockedFunc)(void);
    u16 moveID;
    u8 partyMsgID;
};

struct FieldMoveMonInfo
{
    bool8 valid;
    u8 boxId;
    u8 boxPos;
    u8 partyIndex;
    bool8 fromBox;
    u16 species;
    u16 move;
    u32 personality;
    bool8 isShiny;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
};

extern const struct FieldMoveInfo gFieldMoveInfo[];
extern struct FieldMoveMonInfo gFieldMoveMonInfo;

bool8 FindFieldMoveMonForMove(u16 move, u8 *partyIndex, bool8 *fromBox, u16 *species);
void ClearFieldMoveMonInfo(void);
const struct FieldMoveMonInfo *GetFieldMoveMonInfo(void);
void FieldMove_MarkSurfBoxCacheDirty(void);

static inline bool32 SetUpFieldMove(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].fieldMoveFunc();
}

static inline bool32 IsFieldMoveUnlocked(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].isUnlockedFunc();
}

static inline u32 FieldMove_GetMoveId(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].moveID;
}

static inline u32 FieldMove_GetPartyMsgID(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].partyMsgID;
}

#endif //GUARD_FIELD_MOVE_H
