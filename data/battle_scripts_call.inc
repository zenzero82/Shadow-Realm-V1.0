    .pushsection .rodata.battle_scripts, "a", %progbits
    .align 2

 .global gBattleScript_PlayerCall_Shadow_Normal
    .type gBattleScript_PlayerCall_Shadow_Normal, %object
gBattleScript_PlayerCall_Shadow_Normal:
    printstring STRINGID_TRAINERCALLEDTOMON
    waitmessage B_WAIT_TIME_SHORT
    printstring STRINGID_SHADOWCALMEDSLIGHTLY
    waitmessage B_WAIT_TIME_SHORT
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
    end2
    .size gBattleScript_PlayerCall_Shadow_ReverseEnded, .-gBattleScript_PlayerCall_Shadow_ReverseEnded

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
