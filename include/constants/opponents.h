#ifndef GUARD_CONSTANTS_OPPONENTS_H
#define GUARD_CONSTANTS_OPPONENTS_H

#include "constants/battle_partner.h"

// Start non-vanilla IDs
#define TRAINER_SHADOW_TEST              0
#define TRAINER_TORKIN                   1   // NEW
#define TRAINER_ROCKET_GRUNT_M_1         2
#define TRAINER_ROCKET_GRUNT_F_1         3
#define TRAINER_JJ_VIRIDIAN              4
#define TRAINER_GIOVANNI_1               5
#define TRAINER_BROCK_KANTO              6
#define TRAINER_CAMPER_KANTO             7
#define TRAINER_ARCHER                   8
#define TRAINER_ARIANA                   9
#define TRAINER_BIKER                    10
#define TRAINER_BLAINE                   11
#define TRAINER_BURGLAR                  12
#define TRAINER_CHAMPION_LANCE           13
#define TRAINER_ELITE_FOUR_BRUNO         14
#define TRAINER_ELITE_FOUR_KAREN         15
#define TRAINER_ELITE_FOUR_KOGA          16
#define TRAINER_ELITE_FOUR_WILL          17
#define TRAINER_ENGINEER                 18
#define TRAINER_ERIKA                    19
#define TRAINER_EUSINE                   20
#define TRAINER_FIREBREATHER             21
#define TRAINER_GOLD                     22
#define TRAINER_JANINE                   23
#define TRAINER_JUGGLER                  24
#define TRAINER_KIMONO_GIRL              25
#define TRAINER_LEADER_BLUE              26
#define TRAINER_LEADER_BUGSY             27
#define TRAINER_LEADER_CHUCK             28
#define TRAINER_LEADER_CLAIR             29
#define TRAINER_LEADER_FALKNER           30
#define TRAINER_LEADER_JASMINE           31
#define TRAINER_LEADER_MORTY             32
#define TRAINER_LEADER_PRYCE             33
#define TRAINER_LEADER_WHITNEY           34
#define TRAINER_LYRA                     35
#define TRAINER_MISTY                    36
#define TRAINER_NURSE                    37
#define TRAINER_OFFICER                  38
#define TRAINER_PETREL                   39
#define TRAINER_PROTON                   40
#define TRAINER_PSYCHIC_M2               41
#define TRAINER_SABRINA                  42
#define TRAINER_SAGE                     43
#define TRAINER_SAGE_LEADER              44
#define TRAINER_SILVER                   45
#define TRAINER_SUPER_NERD               46
#define TRAINER_SURGE                    47
#define TRAINER_TWINS2                   48
#define TRAINER_YOUNGSTER2               49
#define TRAINER_VF_BUGCATCHER1           50
#define TRAINER_VF_BUGCATCHER2           51
#define TRAINER_VF_BUGCATCHER3           52
#define TRAINER_VF_ROCKET                53
#define TRAINER_VF_PLASMA                54
#define TRAINER_RT3_YOUNGSTER1           55
#define TRAINER_RT3_YOUNGSTER2           56
#define TRAINER_RT3_LASS                 57
#define TRAINER_RT3_FIREBREATHER         58
#define TRAINER_TEMP_MIROR_B             59
#define TRAINER_RT4_BLACK_BELT           60
#define TRAINER_RT4_ROCKER               61
#define TRAINER_RT4_PICNICKER1           62
#define TRAINER_RT4_PICNICKER2           63
#define TRAINER_RT4_BRENDAN1             64
#define TRAINER_RT4_BRENDAN2             65
#define TRAINER_RT4_BRENDAN3             66
#define TRAINER_LOOKER_CERULEAN          67
#define TRAINER_RT25_YOUNGSTER1          68
#define TRAINER_RT25_LADY                69
#define TRAINER_RT25_COOLTRAINER_F       70
#define TRAINER_RT25_YOUNGSTER2          71
#define TRAINER_RT25_CAMPER              72
#define TRAINER_RT25_LASS                73
#define TRAINER_RT25_SUPER_NERD          74
#define TRAINER_RT25_COOLTRAINER_M       75
#define TRAINER_CERULEAN_GYM_SWIMMER_M   76
#define TRAINER_CERULEAN_GYM_SWIMMER_F1  77
#define TRAINER_CERULEAN_GYM_SWIMMER_F2  78
#define TRAINER_EIN                      79



// NOTE: Because each Trainer uses a flag to determine when they are defeated, there is only space for 9 additional trainers before trainer flag space overflows
//       More space can be made by shifting flags around in constants/flags.h or changing how trainer flags are handled
//       MAX_TRAINERS_COUNT can be increased but will take up additional saveblock space
#define TRAINERS_COUNT                      80
#define MAX_TRAINERS_COUNT                  1000
#define TRAINER_PARTNER(partner)           (MAX_TRAINERS_COUNT + partner)

#endif  // GUARD_CONSTANTS_OPPONENTS_H
