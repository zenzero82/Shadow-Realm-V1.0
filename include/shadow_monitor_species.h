#ifndef GUARD_SHADOW_MONITOR_SPECIES_H
#define GUARD_SHADOW_MONITOR_SPECIES_H

#include "global.h"
#include "constants/shadow.h"

extern const u16 gShadowMonitorSpeciesList[MAX_SHADOW_MON_IDS];
extern const u16 gShadowMonitorIdList[MAX_SHADOW_MON_IDS];
u16 GetShadowMonitorSpecies(u16 shadowId);

#endif // GUARD_SHADOW_MONITOR_SPECIES_H
