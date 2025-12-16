Route1_MapScripts::
    .byte 0
	
@ Route 1 – Cipher Peon Torkin scripted encounter
@ ---------------------------
@ Coord events (set these in Porymap):
@   (10,34) -> Route1_EventScript_TorkinTrigger0
@   (10,33) -> Route1_EventScript_TorkinTrigger1
@   (10,32) -> Route1_EventScript_TorkinTrigger2
@
@ Torkin overworld object:
@   Local ID 1 at (9,33), with flag FLAG_HIDE_ROUTE1_TORKIN

Route1_EventScript_Sign::
    msgbox Route1_Text_Sign, MSGBOX_SIGN
    end

Route1_EventScript_TorkinTrigger0::
    checkflag FLAG_HIDE_ROUTE1_TORKIN
    goto_if_eq Route1_EventScript_TorkinTrigger_Done

    lockall
    @ From (10,34) -> (10,33), then face left
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FromTrigger0
    waitmovement 0
    goto Route1_EventScript_Torkin

Route1_EventScript_TorkinTrigger1::
    checkflag FLAG_HIDE_ROUTE1_TORKIN
    goto_if_eq Route1_EventScript_TorkinTrigger_Done

    lockall
    @ Already on (10,33), just face left
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FromTrigger1
    waitmovement 0
    goto Route1_EventScript_Torkin

Route1_EventScript_TorkinTrigger2::
    checkflag FLAG_HIDE_ROUTE1_TORKIN
    goto_if_eq Route1_EventScript_TorkinTrigger_Done

    lockall
    @ From (10,32) -> (10,33), face left
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FromTrigger2
    waitmovement 0
    goto Route1_EventScript_Torkin

Route1_EventScript_TorkinTrigger_Done::
    end

@ ---------------- Core scripted event ----------------
@ Exclamation -> intro text -> battle (no-intro) -> post-battle -> retreat

Route1_EventScript_Torkin::
    @ Player is now at (10,33) facing left
    @ Torkin (local ID 1) is at (9,33)

    playse SE_PIN
    applymovement 1, Route1_Move_Torkin_ExclaimTurn
    waitmovement 0

    @ Manual intro text (since we're using trainerbattle_no_intro)
    msgbox Route1_Text_TorkinIntro, MSGBOX_DEFAULT
    closemessage

    @ No-intro battle: shows defeat text automatically if you win
    trainerbattle_no_intro TRAINER_TORKIN, Route1_Text_TorkinDefeated

    @ Ensure player is still facing Torkin after battle
    applymovement OBJ_EVENT_ID_PLAYER, Route1_Move_Player_FaceLeft
    waitmovement 0

    @ Now do your post-battle monologue
    msgbox Route1_Text_TorkinPostBattle, MSGBOX_DEFAULT
    closemessage

    @ Torkin retreats: your custom path, then vanish + flag
    applymovement 1, Route1_Move_Torkin_Leave
    waitmovement 0
    setflag FLAG_HIDE_ROUTE1_TORKIN
    removeobject 1

    releaseall
    end

@ -------- Movements --------

Route1_Move_Torkin_ExclaimTurn:
    emote_exclamation_mark
    face_right           @ turn to face the player on the right
    step_end

@ Player: just face left in place
Route1_Move_Player_FaceLeft:
    face_left
    step_end

@ From (10,34) -> (10,33), face left
Route1_Move_Player_FromTrigger0:
    walk_up
    face_left
    step_end

@ From (10,33) -> stay, face left
Route1_Move_Player_FromTrigger1:
    face_left
    step_end

@ From (10,32) -> (10,33), face left
Route1_Move_Player_FromTrigger2:
    walk_down
    face_left
    step_end

@ From (9,33): your leave path
Route1_Move_Torkin_Leave:
    walk_left
    walk_left
    walk_left
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

Route1_Text_Sign:
    .string "ROUTE 1\p"
    .string "PALLET TOWN - VIRIDIAN CITY$"
