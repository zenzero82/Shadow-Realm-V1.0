#ifndef GUARD_CONSTANTS_SHADOW_H
#define GUARD_CONSTANTS_SHADOW_H

#define MAX_SHADOW_MON_IDS 200  // or 256 if you want a ton

enum {
    SHDW_STATE_NEVER_SEEN = 0,
    SHDW_STATE_SEEN,       // encountered in battle
    SHDW_STATE_SNAGGED,    // caught by player
    SHDW_STATE_PURIFIED,   // (later)
    SHDW_STATE_FAILED,     // KO’d without snagging (optional, future)
};

#endif // GUARD_CONSTANTS_SHADOW_H
