@ Pallet Town Western Forest – intro monologue triggered by coord events
@ Uses FLAG_WEST_FOREST_INTRO_DONE (define in flags.h)

Pallet_Town_Western_Forest_MapScripts::
    .byte 0

@ ---------------- INTRO SEQUENCE (called by coord events) ----------------

Pallet_Town_Western_Forest_EventScript_Intro::
    @ Only run once per save
    checkflag FLAG_WEST_FOREST_INTRO_DONE
    goto_if_eq Pallet_Town_Western_Forest_Intro_Done

    setflag FLAG_WEST_FOREST_INTRO_DONE
	setflag FLAG_HIDE_OAKS_LAB_LEO
    lock
    faceplayer

    @ First bit of inner monologue
    msgbox Pallet_Town_Western_Forest_Text_Player_IntroThought1, MSGBOX_DEFAULT
    closemessage

    @ Exclamation + sound, then face up toward the portal
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Pallet_Town_Western_Forest_Mov_Exclaim_FaceUp
    waitmovement 0

    @ Second bit of inner monologue
    msgbox Pallet_Town_Western_Forest_Text_Player_IntroThought2, MSGBOX_DEFAULT
    closemessage

    @ Give running shoes here since this is the true spawn area
    setflag FLAG_SYS_B_DASH
    setflag FLAG_RECEIVED_RUNNING_SHOES

    release
Pallet_Town_Western_Forest_Intro_Done:
    end

@ ---------------- MOVEMENTS ----------------

Pallet_Town_Western_Forest_Mov_Exclaim_FaceUp:
    emote_exclamation_mark
    face_up
    step_end

@ ---------------- TEXT ----------------

Pallet_Town_Western_Forest_Text_Player_IntroThought1:
    .string "What happened...?\p"
    .string "The last thing I remember is...\n"
    .string "No... it's all a blur.\p"
    .string "Where am I?$"

Pallet_Town_Western_Forest_Text_Player_IntroThought2:
    .string "That portal behind me...\n"
    .string "Did I come through that?\p"
    .string "Well... I guess I can go ask around\n"
    .string "to see if anyone knows anything.$"

@ ================================
@ WEST FOREST – BADGE TEST NPC
@ ================================
@ Attach this script to an NPC in Porymap:
@   Script: WestForest_EventScript_BadgeTester
@
@ It will give:
@   - Hoenn Badge 1  -> FLAG_BADGE01_GET
@   - Kanto Badge 1  -> FLAG_BADGE09_GET
@ and only run once, tracked by FLAG_WEST_FOREST_BADGE_TEST_DONE.

WestForest_EventScript_BadgeTester::
    lock
    faceplayer

    @ If we've already done the test, just say a short line.
   
    @ First time: explain and give badges.
    msgbox WestForest_Text_BadgeTester_Intro, MSGBOX_DEFAULT
    closemessage

    @ Give Hoenn Badge 1 (Stone Badge in most setups)

    @ Give Kanto Badge 1 (Boulder Badge – HNS uses FLAG_BADGE09_GET)
    setflag FLAG_BADGE09_GET

    msgbox WestForest_Text_BadgeTester_Given, MSGBOX_DEFAULT
    closemessage
    release
    end

WestForest_EventScript_BadgeTester_After::
    msgbox WestForest_Text_BadgeTester_After, MSGBOX_DEFAULT
    closemessage
    release
    end


@ --------- TEXT ---------

WestForest_Text_BadgeTester_Intro:
    .string "Hey there.\p"
    .string "I'm helping the LEAGUE test how\n"
    .string "BADGES show up on TRAINER CARDS.\p"
    .string "Here, I'll register the first HOENN\n"
    .string "BADGE and the first KANTO BADGE for\n"
    .string "you as a special test.$"

WestForest_Text_BadgeTester_Given:
    .string "There.\p"
    .string "Your TRAINER CARD should now show one\n"
    .string "badge from HOENN and one from KANTO.\p"
    .string "Try flipping between regions and see\n"
    .string "how it looks.$"

WestForest_Text_BadgeTester_After:
    .string "Your BADGE data is already registered.\p"
    .string "Check your TRAINER CARD if you want to\n"
    .string "see how the regions rotate.$"
