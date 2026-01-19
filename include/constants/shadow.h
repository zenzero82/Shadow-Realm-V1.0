#ifndef GUARD_CONSTANTS_SHADOW_H
#define GUARD_CONSTANTS_SHADOW_H

#define MAX_SHADOW_MON_IDS 200  
#define SHADOW_HEART_GAUGE_MAX 10000

enum {
    SHDW_STATE_NEVER_SEEN = 0,
    SHDW_STATE_SEEN,       // encountered in battle
    SHDW_STATE_SNAGGED,    // snagged by player
    SHDW_STATE_PURIFIED,   // (later)
    SHDW_STATE_FAILED,     // KO’d without snagging (optional, future)
};

#endif // GUARD_CONSTANTS_SHADOW_H
