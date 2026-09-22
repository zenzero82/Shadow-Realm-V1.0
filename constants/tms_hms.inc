#ifndef GUARD_CONSTANTS_TMS_HMS_INC
#define GUARD_CONSTANTS_TMS_HMS_INC

#include "constants/tms_hms.h"

/* Expands to:
* enum_start ITEM_TM01
* enum ITEM_TM_TAKE_DOWN
* ...
*/
#define EQUIV_TM(id) enum ITEM_TM_ ## id;
	enum_start ITEM_TM01
FOREACH_TM(EQUIV_TM)
#undef EQUIV_TM

// Hoenn field-move rewards are field manuals, except Fly and Surf, which are
// Gen 9 TMs. These aliases are needed by assembly map scripts.
#define ITEM_HM01 844
#define ITEM_HM02 678
#define ITEM_HM03 704
#define ITEM_HM04 1018
#define ITEM_HM05 1019
#define ITEM_HM06 1020
#define ITEM_HM07 1021
#define ITEM_HM08 1022
#define ITEM_HM_CUT ITEM_HM01
#define ITEM_HM_FLY ITEM_HM02
#define ITEM_HM_SURF ITEM_HM03
#define ITEM_HM_STRENGTH ITEM_HM04
#define ITEM_HM_FLASH ITEM_HM05
#define ITEM_HM_ROCK_SMASH ITEM_HM06
#define ITEM_HM_WATERFALL ITEM_HM07
#define ITEM_HM_DIVE ITEM_HM08

#endif @ GUARD_CONSTANTS_TMS_HMS_INC
