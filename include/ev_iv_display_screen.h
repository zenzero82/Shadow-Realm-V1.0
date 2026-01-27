#ifndef GUARD_EV_IV_DISPLAY_SCREEN_H
#define GUARD_EV_IV_DISPLAY_SCREEN_H

#include "main.h"
#include "constants/flags.h"

struct Pokemon;

void Show_EvIv(struct Pokemon *party, u8 cursorPos, u8 lastIdx, MainCallback savedCallback, bool8 isBoxMon, bool8 returnSummary);
void CB2_ShowEvIv_PlayerParty(void);
void EvIv_PlayerParty(void);

#ifndef FLAG_EV_IV
#define FLAG_EV_IV FLAG_SYS_POKEMON_GET
#endif

#endif // GUARD_EV_IV_DISPLAY_SCREEN_H
