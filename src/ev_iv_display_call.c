#include "global.h"
#include "main.h"
#include "script.h"
#include "sound.h"
#include "constants/songs.h"
#include "ev_iv_display_screen.h"

void EvIv_PlayerParty(void)
{
    PlaySE(SE_RG_CARD_OPEN);
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_ShowEvIv_PlayerParty);
    ScriptContext_Enable();
}
