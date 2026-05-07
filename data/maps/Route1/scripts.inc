Route1_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Route1_OnLoad
    .byte 0

Route1_OnLoad:
    setflag FLAG_HIDE_ROUTE1_LEO
    end

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Route1_Speaker_Torkin:
    .string "TORKIN$"

Route1_Speaker_OldMan:
    .string "Old Man Harlo$"

Route1_Speaker_Leo:
    .string "Prof. Aide Leo$"

.set LOCALID_LEO_ROUTE1, 5

@ =========================================================
@ Route 1 – Sign
@ =========================================================

Route1_EventScript_Sign::
    msgbox Route1_Text_Sign, MSGBOX_SIGN
    end

@ =========================================================
@ Route 1 – Old Man driven out of Viridian
@ (Assign this script to an Old Man NPC object in Porymap)
@ =========================================================

Route1_EventScript_OldManDrivenOut::
    lock
    faceplayer
    setspeaker Route1_Speaker_OldMan
    msgbox Route1_Text_OldManDrivenOut, MSGBOX_DEFAULT
    closemessage
    release
    end

@ =========================================================
@ Route 1 – Cipher Peon Torkin scripted encounter
@ ---------------------------------------------------------
@ Coord events (set these in Porymap):
@   (12,35) -> Route1_EventScript_TorkinTrigger0
@   (13,35) -> Route1_EventScript_TorkinTrigger1
@
@ Torkin overworld object:
@   Local ID 3 at (11,33), with flag FLAG_HIDE_ROUTE1_TORKIN
@ =========================================================

Route1_EventScript_TorkinTrigger0::
    checkflag FLAG_HIDE_ROUTE1_TORKIN
    goto_if_eq Route1_EventScript_TorkinTrigger_Done

    lockall
    setvar VAR_TEMP_0, 0
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FaceNorth
    waitmovement 0
    goto Route1_EventScript_Torkin

Route1_EventScript_TorkinTrigger1::
    checkflag FLAG_HIDE_ROUTE1_TORKIN
    goto_if_eq Route1_EventScript_TorkinTrigger_Done

    lockall
    setvar VAR_TEMP_0, 1
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FaceNorth
    waitmovement 0
    goto Route1_EventScript_Torkin

Route1_EventScript_TorkinTrigger_Done::
    end

@ ---------------- Core scripted event ----------------
@ Exclamation -> intro text -> battle (no-intro) -> post-battle -> retreat

Route1_EventScript_Torkin::
    @ Player is at the trigger tile, facing north
    @ Torkin (local ID 3) is at (11,33)

    playbgm MUS_CIPHER_ENCOUNTER, FALSE
    setspeaker Route1_Speaker_Torkin
    msgbox Route1_Text_TorkinPreApproach, MSGBOX_DEFAULT
    closemessage

    playse SE_PIN
    goto_if_eq VAR_TEMP_0, 0, Route1_EventScript_Torkin_ApproachFromTrigger0
    goto_if_eq VAR_TEMP_0, 1, Route1_EventScript_Torkin_ApproachFromTrigger1
    applymovement 3, Route1_Move_Torkin_ExclaimTurn
    waitmovement 0
    goto Route1_EventScript_Torkin_AfterApproach

Route1_EventScript_Torkin_ApproachFromTrigger0::
    applymovement 3, Route1_Move_Torkin_Approach_FromTrigger0
    waitmovement 0
    goto Route1_EventScript_Torkin_AfterApproach

Route1_EventScript_Torkin_ApproachFromTrigger1::
    applymovement 3, Route1_Move_Torkin_Approach_FromTrigger1
    waitmovement 0

Route1_EventScript_Torkin_AfterApproach::
    setspeaker Route1_Speaker_Torkin
    msgbox Route1_Text_TorkinIntro, MSGBOX_DEFAULT
    closemessage

    @ No-intro battle: shows defeat text automatically if you win
    trainerbattle_no_intro TRAINER_TORKIN, Route1_Text_TorkinDefeated

    @ Ensure player is still facing Torkin after battle
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FaceNorth
    waitmovement 0

    setspeaker Route1_Speaker_Torkin
    msgbox Route1_Text_TorkinPostBattle, MSGBOX_DEFAULT
    closemessage

    @ Torkin retreats: your custom path, then vanish + flag
    applymovement 3, Route1_Move_Torkin_Leave
    waitmovement 0
    setflag FLAG_HIDE_ROUTE1_TORKIN
    removeobject 3

    goto Route1_EventScript_Leo_AfterTorkin

Route1_EventScript_Leo_AfterTorkin::
    clearflag FLAG_HIDE_ROUTE1_LEO
    addobject LOCALID_LEO_ROUTE1
    goto_if_eq VAR_TEMP_0, 1, Route1_EventScript_Leo_SetPosTrigger1

Route1_EventScript_Leo_SetPosTrigger0::
    setobjectxy LOCALID_LEO_ROUTE1, 12, 41
    goto Route1_EventScript_Leo_Start

Route1_EventScript_Leo_SetPosTrigger1::
    setobjectxy LOCALID_LEO_ROUTE1, 13, 41

Route1_EventScript_Leo_Start::
    applymovement LOCALID_LEO_ROUTE1, Route1_Move_Leo_Approach
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FaceSouth
    waitmovement 0

    setspeaker Route1_Speaker_Leo
    msgbox Route1_Text_Leo_PokeBallsIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_POKE_BALL, 5
    setspeaker Route1_Speaker_Leo
    msgbox Route1_Text_Leo_PokeBallsOutro, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_LEO_ROUTE1, Route1_Move_Leo_Leave
    waitmovement 0
    setflag FLAG_HIDE_ROUTE1_LEO
    removeobject LOCALID_LEO_ROUTE1

    releaseall
    end

@ =========================================================
@ Movements
@ =========================================================

Route1_Move_Torkin_ExclaimTurn:
    emote_exclamation_mark
    face_right           @ turn to face the player on the right
    step_end

@ From (11,33) -> (12,34), face down
Route1_Move_Torkin_Approach_FromTrigger0:
    emote_exclamation_mark
    walk_right
    walk_down
    face_down
    step_end

@ From (11,33) -> (13,34), face down
Route1_Move_Torkin_Approach_FromTrigger1:
    emote_exclamation_mark
    walk_right
    walk_right
    walk_down
    face_down
    step_end

@ Player: just face north in place
Route1_Move_Player_FaceNorth:
    face_up
    step_end

Route1_Move_Player_FaceSouth:
    face_down
    step_end

@ From (9,33): your leave path
Route1_Move_Torkin_Leave:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

Route1_Move_Leo_Approach:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

Route1_Move_Leo_Leave:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

@ =========================================================
@ Text
@ =========================================================

Route1_Text_Sign:
    .string "ROUTE 1\p"
    .string "PALLET TOWN - VIRIDIAN CITY$"

@ Old Man
Route1_Text_OldManDrivenOut:
    .string "I used to live in VIRIDIAN CITY.\p"
    .string "Then TEAM ROCKET came back...\n"
    .string "and they didn't come alone.\p"
    .string "They blocked the streets, pushed folks\n"
    .string "out, and turned the GYM into a fortress.\p"
    .string "I grabbed what I could and ran.\p"
    .string "If you're headed north...\n"
    .string "keep your eyes open, kid.$"

Route1_Text_TorkinPreApproach:
    .string "Finally I got my own.\p"
    .string "Now I will be unstoppable!$"

Route1_Text_Leo_PokeBallsIntro:
    .string "Wow you managed to defeat that guy in\n"
    .string "battle! Maybe there is hope after all.\p"
    .string "I forgot to give you these before you\n"
    .string "left.$"

Route1_Text_Leo_PokeBallsOutro:
    .string "These should help you catch some\n"
    .string "Pokemon to help you prepare for whats\l"
    .string "ahead.\p"
    .string "If you need to heal them I know RED's\n"
    .string "mom is very nice and may let you rest\l"
    .string "there.\p"
    .string "Not sure the state of VIRIDIAN CITY\n"
    .string "right now... Be careful {PLAYER}.$"
