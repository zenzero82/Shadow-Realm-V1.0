#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "battle_message.h"
#include "pokemon.h"
#include "battle_script_commands.h"

// Texts: declare only (actual defs live in battle_message.c)
extern const u8 gText_TrainerEncouragedMon[];
extern const u8 gText_ShadowCameToSenses[];
extern const u8 gText_ShadowCalmedSlightly[];
extern const u8 gText_TrainerCalledToMon[];

// Battle scripts: declare only (actual defs live in data/battle_scripts_call.inc)
extern const u8 gBattleScript_PlayerCall_Shadow_Normal[];
extern const u8 gBattleScript_PlayerCall_Shadow_ReverseEnded[];
extern const u8 gBattleScript_PlayerCall_NonShadow[];

