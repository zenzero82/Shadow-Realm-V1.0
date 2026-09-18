#ifndef GUARD_SHADOW_HEART_H
#define GUARD_SHADOW_HEART_H

#include "global.h"
#include "pokemon.h"

void Shadow_HandleStepHeartDecay(void);
u16 Shadow_GetJoyScentHeartReduction(u8 nature);
u16 Shadow_GetCologneHeartReduction(struct Pokemon *mon, u16 itemId);
void Shadow_SyncQuarterUnlockMove(struct Pokemon *mon);

#endif // GUARD_SHADOW_HEART_H
