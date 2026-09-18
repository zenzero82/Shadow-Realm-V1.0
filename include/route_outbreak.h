#ifndef GUARD_ROUTE_OUTBREAK_H
#define GUARD_ROUTE_OUTBREAK_H

#include "global.h"

void RouteHouse_TV_TryStartBroadcast(void);
u32 RouteOutbreak_ModifyShinyThreshold(u16 species, u32 shinyThreshold);
void RouteOutbreak_ApplyEncounterBonuses(struct Pokemon *mon);

#endif // GUARD_ROUTE_OUTBREAK_H
