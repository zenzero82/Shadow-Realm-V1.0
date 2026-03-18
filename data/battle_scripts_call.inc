    .pushsection .rodata.battle_scripts, "a", %progbits
    .align 2

 .global gBattleScript_PlayerCall_Shadow_Normal
    .type gBattleScript_PlayerCall_Shadow_Normal, %object
gBattleScript_PlayerCall_Shadow_Normal:
    printstring STRINGID_TRAINERCALLEDTOMON
    waitmessage B_WAIT_TIME_SHORT
    printstring STRINGID_SHADOWCALMEDSLIGHTLY
    waitmessage B_WAIT_TIME_SHORT
    call BattleScript_PlayerCall_TryClearConfusion
    end2
    .size gBattleScript_PlayerCall_Shadow_Normal, .-gBattleScript_PlayerCall_Shadow_Normal

    .align 2
    .global gBattleScript_PlayerCall_Shadow_ReverseEnded
    .type gBattleScript_PlayerCall_Shadow_ReverseEnded, %object
gBattleScript_PlayerCall_Shadow_ReverseEnded:
    printstring STRINGID_TRAINERCALLEDTOMON
    waitmessage B_WAIT_TIME_SHORT
    playanimation BS_ATTACKER B_ANIM_CALL_REVERSE_MODE
    printstring STRINGID_SHADOWCAMETOSENSES
    waitmessage B_WAIT_TIME_SHORT
    callnative BS_ClearReverseModeAfterCall
    call BattleScript_PlayerCall_TryClearConfusion
    end2
    .size gBattleScript_PlayerCall_Shadow_ReverseEnded, .-gBattleScript_PlayerCall_Shadow_ReverseEnded

    .align 2
    .global gBattleScript_PlayerCall_NonShadow
    .type gBattleScript_PlayerCall_NonShadow, %object
gBattleScript_PlayerCall_NonShadow:
    printstring STRINGID_TRAINERCALLEDTOMON
    waitmessage B_WAIT_TIME_SHORTEST
    setstatchanger STAT_ACC, 1, FALSE
    statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_PlayerCall_NonShadow_End
    jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_PlayerCall_NonShadow_End
    setgraphicalstatchangevalues
    playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
    setbyte gBattleCommunication STAT_ACC
    stattextbuffer BS_ATTACKER
    printstring STRINGID_ATTACKERSSTATROSE
    waitmessage B_WAIT_TIME_LONG
    printstring STRINGID_TRAINERENCOURAGEDMON
    waitmessage B_WAIT_TIME_SHORT
    call BattleScript_PlayerCall_TryClearConfusion
    end2

BattleScript_PlayerCall_NonShadow_End:
    pause B_WAIT_TIME_SHORTEST
    printstring STRINGID_STATSWONTINCREASE
    waitmessage B_WAIT_TIME_LONG
    call BattleScript_PlayerCall_TryClearConfusion
    end2
    .size gBattleScript_PlayerCall_NonShadow, .-gBattleScript_PlayerCall_NonShadow

BattleScript_PlayerCall_TryClearConfusion:
    jumpifstatus2 BS_ATTACKER, STATUS2_CONFUSION, BattleScript_PlayerCall_ClearConfusion
    return

BattleScript_PlayerCall_ClearConfusion:
    clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_CONFUSION
    printstring STRINGID_PKMNHEALEDCONFUSION
    waitmessage B_WAIT_TIME_LONG
    updatestatusicon BS_ATTACKER
    return

    .align 2
.global BattleScript_ShadowPokemonHint
.type BattleScript_ShadowPokemonHint, %object
BattleScript_ShadowPokemonHint:
    printstring STRINGID_SHADOW_POKEMON_SPOTTED
    waitmessage B_WAIT_TIME_UNTIL_PRESS
    end2
.size BattleScript_ShadowPokemonHint, .-BattleScript_ShadowPokemonHint

    .popsection

gBattleScript_ReverseModeTurnDmg::
    printstring STRINGID_REVERSEMODE_DAMAGE
    waitmessage B_WAIT_TIME_SHORT
    datahpupdate BS_SCRIPTING
    healthbarupdate BS_SCRIPTING
    waitstate
    return
