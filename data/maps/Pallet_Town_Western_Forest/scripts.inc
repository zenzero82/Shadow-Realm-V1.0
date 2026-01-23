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

    @ First bit of inner monologue (PLAYER)
    setspeaker SP_NAME_PLAYER
    msgbox Pallet_Town_Western_Forest_Text_Player_IntroThought1, MSGBOX_DEFAULT
    closemessage

    @ Exclamation + sound, then face up toward the portal
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Pallet_Town_Western_Forest_Mov_Exclaim_FaceUp
    waitmovement 0

    @ Second bit of inner monologue (PLAYER)
    setspeaker SP_NAME_PLAYER
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
@ Gives once:
@   - Hoenn Badge 1  -> FLAG_BADGE01_GET
@   - Kanto Badge 1  -> FLAG_BADGE09_GET
@   - PokéNav unlock -> FLAG_SYS_POKENAV_GET (and friends)
@ Tracked by:
@   FLAG_WEST_FOREST_BADGE_TEST_DONE

WestForest_EventScript_BadgeTester::
    lock
    faceplayer

    msgbox WestForest_Text_BadgeTester_Intro, MSGBOX_DEFAULT
    closemessage

    @ Hoenn Badge 1
    setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
    setflag FLAG_BADGE07_GET
    setflag FLAG_BADGE08_GET


    @ Kanto Badge 1
    setflag FLAG_BADGE09_GET
    setflag FLAG_BADGE10_GET
    setflag FLAG_BADGE11_GET
    setflag FLAG_BADGE12_GET
    setflag FLAG_BADGE13_GET
    setflag FLAG_BADGE14_GET
    setflag FLAG_BADGE15_GET
    setflag FLAG_BADGE16_GET
    setflag FLAG_BADGE17_GET
    setflag FLAG_BADGE18_GET
    setflag FLAG_BADGE19_GET
    setflag FLAG_BADGE20_GET
    setflag FLAG_BADGE21_GET
    setflag FLAG_BADGE22_GET
    setflag FLAG_BADGE23_GET
    setflag FLAG_BADGE24_GET
	setflag FLAG_RECEIVED_HM_FLY 
    giveitem ITEM_HM02

    @ PokéNav
	setflag FLAG_SYS_POKENAV_GET
    setflag FLAG_RECEIVED_POKENAV

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
    .string "I'll also register your POKENAV so\n"
    .string "you can check things easier.\p"
    .string "Ready?$"

WestForest_Text_BadgeTester_Given:
    .string "Done.\p"
    .string "Your TRAINER CARD should now show one\n"
    .string "badge from HOENN and one from KANTO.\p"
    .string "And your POKENAV is now active.\p"
    .string "Try flipping between regions to test\n"
    .string "the badge display.$"

WestForest_Text_BadgeTester_After:
    .string "Your BADGE data and POKENAV are already\n"
    .string "registered.\p"
    .string "Check your TRAINER CARD to see how the\n"
    .string "regions rotate.$"


@ ================================
@ WEST FOREST – PORTAL WARP (TEMP)
@ ================================
@ Attach this script to your portal object in Porymap:
@   Script: Pallet_Town_Western_Forest_EventScript_Portal_ToNewBark

Pallet_Town_Western_Forest_EventScript_Portal_ToNewBark::
    lock
    faceplayer
    msgbox Pallet_Town_Western_Forest_Text_PortalAsk, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, Pallet_Town_Western_Forest_PortalNo

    closemessage
    fadescreenswapbuffers FADE_TO_BLACK

    @ REPLACE THIS with the real MAP_* constant you find in maps.h
    warp MAP_NEW_BARK_TOWN, WARP_ID_NONE, 21, 17

    waitstate
    end

Pallet_Town_Western_Forest_PortalNo::
    closemessage
    release
    end

Pallet_Town_Western_Forest_Text_PortalAsk:
    .string "The portal is humming...\p"
    .string "Warp to NEW BARK TOWN?$"

@ ================================
@ WEST FOREST – PORTAL WARP (HOENN)
@ ================================
@ Attach this script to your 2nd portal object in Porymap:
@   Script: Pallet_Town_Western_Forest_EventScript_Portal_ToLittleroot

Pallet_Town_Western_Forest_EventScript_Portal_ToLittleroot::
    lock
    faceplayer
    msgbox Pallet_Town_Western_Forest_Text_PortalAsk_Littleroot, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, Pallet_Town_Western_Forest_PortalNo_Littleroot

    closemessage
    fadescreenswapbuffers FADE_TO_BLACK

    @ Warp to Littleroot Town (Hoenn) at (11, 15)
    @ If MAP_LITTLEROOT_TOWN isn't your constant name, swap it to your maps.h name.
    warp MAP_LITTLEROOT_TOWN, WARP_ID_NONE, 11, 15

    waitstate
    end

Pallet_Town_Western_Forest_PortalNo_Littleroot::
    closemessage
    release
    end

Pallet_Town_Western_Forest_Text_PortalAsk_Littleroot:
    .string "The portal feels different...\p"
    .string "Warp to LITTLEROOT TOWN?$"


@==============================================

Speaker_Jeremy:
    .string "JEREMY$"

TestNameboxNPC::
    lock
    faceplayer
    setspeaker Speaker_Jeremy
    checkflag FLAG_RECEIVED_SHADOW_MONITOR
    goto_if_eq ShadowMonitorAlreadyHas

    msgbox TestText, MSGBOX_NPC
    closemessage
    giveitem ITEM_SHADOW_MONITOR
    setflag FLAG_RECEIVED_SHADOW_MONITOR
    msgbox ShadowMonitor_Text_Given, MSGBOX_NPC
    closemessage
    checkflag FLAG_HAS_SNAG_MACHINE
    goto_if_eq SnagMachineAlreadyHas
    goto GiveSnagMachine

ShadowMonitorAlreadyHas::
    msgbox ShadowMonitor_Text_AlreadyHave, MSGBOX_NPC
    closemessage
    checkflag FLAG_RECEIVED_SNAG_MACHINE
    goto_if_eq SnagMachineAlreadyHas
    goto GiveSnagMachine

GiveSnagMachine::
    giveitem ITEM_SNAG_MACHINE
    setflag FLAG_HAS_SNAG_MACHINE
    msgbox SnagMachine_Text_Given, MSGBOX_NPC
    closemessage
    release
    end

SnagMachineAlreadyHas::
    msgbox SnagMachine_Text_AlreadyHave, MSGBOX_NPC
    closemessage
    release
    end

TestText:
    .string "Yo wassup!$"

ShadowMonitor_Text_Given:
    .string "Here's the Shadow Monitor I found.\pIt keeps track of every Shadow\nPokémon you snag.$"

ShadowMonitor_Text_AlreadyHave:
    .string "You already grabbed the Shadow\nMonitor, but thanks for checking!$"

SnagMachine_Text_Given:
    .string "The Snag Machine is yours now.\pIt logs every Shadow\nPokemon you capture.$"

SnagMachine_Text_AlreadyHave:
    .string "You already have the Snag\nMachine, so I can't give it again!$"

