#ifndef GUARD_OVERWORLD_WILD_ENCOUNTERS_H
#define GUARD_OVERWORLD_WILD_ENCOUNTERS_H

#include "global.h"

void OverworldWildEncounters_OnMapLoad(void);
void OverworldWildEncounters_OnReturnToField(void);
void OverworldWildEncounters_TrySpawn(void);
bool8 OverworldWildEncounters_TryStartBattleAtCoords(s16 x, s16 y, u8 elevation);
bool8 OverworldWildEncounters_SpawnDexNavMon(u16 species, u8 level, u8 potential, u8 abilityNum, u16 item, const u16 *moves,
                                             s16 x, s16 y, u8 elevation, u8 *outLocalId);

#endif // GUARD_OVERWORLD_WILD_ENCOUNTERS_H
