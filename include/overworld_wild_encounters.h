#ifndef GUARD_OVERWORLD_WILD_ENCOUNTERS_H
#define GUARD_OVERWORLD_WILD_ENCOUNTERS_H

#include "global.h"

void OverworldWildEncounters_OnMapLoad(void);
void OverworldWildEncounters_TrySpawn(void);
bool8 OverworldWildEncounters_TryStartBattleAtCoords(s16 x, s16 y, u8 elevation);

#endif // GUARD_OVERWORLD_WILD_ENCOUNTERS_H
