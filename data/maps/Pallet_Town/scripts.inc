Pallet_Town_MapScripts::
    .byte 0

@ Runs when you enter Pallet (wired in the map header)
PalletTown_EventScript_CityEnter::
    setflag FLAG_VISITED_PALLET_TOWN

    @ Before the Route 1 scene: hide lab-Leo, show Pallet-Leo (no hide flag)
    @ After the Route 1 scene: show lab-Leo, hide Pallet-Leo.
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_CityEnter_Route1Done

    @ Route 1 aide event NOT done yet
    setflag FLAG_HIDE_OAKS_LAB_LEO      @ keep Leo hidden in the lab
    goto PalletTown_CityEnter_End

PalletTown_CityEnter_Route1Done:
    @ Route 1 aide event IS done
    clearflag FLAG_HIDE_OAKS_LAB_LEO    @ allow Leo to appear in Oak's Lab
    setflag FLAG_HIDE_PALLET_LEO        @ permanently hide Pallet Leo

PalletTown_CityEnter_End:
    end

@ ---------------- OUTSIDE NPCS ----------------

PalletTown_EventScript_Woman::
    msgbox PalletTown_Text_Teacher, MSGBOX_NPC
    end

PalletTown_EventScript_Fatman::
    msgbox PalletTown_Text_Fisher, MSGBOX_NPC
    end

PalletTown_EventScript_TownSign::
    msgbox PalletTown_Text_Sign, MSGBOX_SIGN
    end

PalletTown_EventScript_RedsHouseSign::
    msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
    end

PalletTown_EventScript_BluesHouseSign::
    msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
    end

PalletTown_EventScript_OaksLabSign::
    msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
    end

@ ---------------- ROUTE 1 AIDE (LEO) ----------------
@ Leo is local ID 1 at (12,0), hidden with FLAG_HIDE_PALLET_LEO.
@ Coord events:
@   (12,1) -> PalletTown_EventScript_Route1AideTrigger0
@   (13,1) -> PalletTown_EventScript_Route1AideTrigger1

PalletTown_EventScript_Route1AideTalk::
    lock
    faceplayer
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_EventScript_Route1AideTalk_After

    msgbox PalletTown_Text_Route1Aide_Intro, MSGBOX_DEFAULT
    closemessage
    release
    end

PalletTown_EventScript_Route1AideTalk_After::
    msgbox PalletTown_Text_Route1Aide_After, MSGBOX_DEFAULT
    closemessage
    release
    end

@ Trigger "0" at (12,1) – player already directly under Leo
PalletTown_EventScript_Route1AideTrigger0::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_EventScript_Route1AideTrigger0_Done

    lockall

    playse SE_PIN
    applymovement 1, PalletTown_Move_Leo_Exclaim
    waitmovement 0
    applymovement 1, PalletTown_Move_Leo_Approach_Top
    waitmovement 0

    msgbox PalletTown_Text_Route1Aide_SawMan, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_MET_ROUTE1_AIDE
    setflag FLAG_HIDE_PALLET_LEO

    @ Escort into lab (Leo in front, player behind)
    applymovement 1,                  PalletTown_Move_Leo_Path
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_Path
    waitmovement 0

    clearflag FLAG_HIDE_OAKS_LAB_LEO   @ show Leo in the lab now
    warp MAP_OAKS_LAB, 5, 12

    releaseall
    end

PalletTown_EventScript_Route1AideTrigger0_Done::
    end

@ Trigger "1" at (13,1) – player steps left & faces up to look at Leo
PalletTown_EventScript_Route1AideTrigger1::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_EventScript_Route1AideTrigger1_Done

    lockall

    playse SE_PIN
    applymovement 1, PalletTown_Move_Leo_Exclaim
    waitmovement 0

    @ Move player left to (12,1) and face up at Leo
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_T1_PreAlign
    waitmovement 0

    applymovement 1, PalletTown_Move_Leo_Approach_Bottom
    waitmovement 0

    msgbox PalletTown_Text_Route1Aide_SawMan, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_MET_ROUTE1_AIDE
    setflag FLAG_HIDE_PALLET_LEO

    @ Now in same formation as trigger 0: Leo at (12,0), player at (12,1)
    applymovement 1,                  PalletTown_Move_Leo_Path
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_Path
    waitmovement 0

    clearflag FLAG_HIDE_OAKS_LAB_LEO   @ show Leo in the lab now
    warp MAP_OAKS_LAB, 5, 12

    releaseall
    end

PalletTown_EventScript_Route1AideTrigger1_Done::
    end

@ ---------------- MOVEMENTS ----------------

PalletTown_Move_Leo_Exclaim:
    emote_exclamation_mark
    step_end

@ Trigger 0: Leo is already above the player; just face down
PalletTown_Move_Leo_Approach_Top:
    face_down
    step_end

@ Trigger 1: after player shifts left, just face down
PalletTown_Move_Leo_Approach_Bottom:
    face_down
    step_end

@ Trigger 1 pre-align: player moves left from (13,1) to (12,1) and faces up
PalletTown_Move_Player_T1_PreAlign:
    walk_left
    face_up
    step_end

@ Final movement paths you tested and liked

PalletTown_Move_Leo_Path:
    @ Down 14 steps: y 0 -> 14
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    @ Then right 4
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

PalletTown_Move_Player_Path:
    @ Same steps as Leo; because player starts at y+1, Leo stays in front.
    walk_right
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

@ ---------------- TEXT ----------------

PalletTown_Text_Teacher:
    .string "I'm a teacher here in town.\p"
    .string "Lately my students keep talking about\n"
    .string "portals opening and Pokemon on the\l"
    .string "news that should not even exist in KANTO.\p"
    .string "I just hope all these anomalies do not\n"
    .string "reach our quiet little town.$"

PalletTown_Text_Fisher:
    .string "Technology is incredible... and a little\n"
    .string "terrifying right now.\p"
    .string "The news shows footage from all over the\n"
    .string "world - Gyms, evil teams, even other\l"
    .string "regions bleeding into each other.\p"
    .string "Sometimes the broadcast glitches like it\n"
    .string "is coming from more than one timeline.$"

PalletTown_Text_Sign:
    .string "PALLET TOWN\p"
    .string "A Tranquil Setting of Peace\n"
    .string "& Purity$"

PalletTown_Text_RedsHouseSign:
    .string "RED'S HOUSE$"

PalletTown_Text_OaksLabSign:
    .string "OAK POKEMON\n"
    .string "RESEARCH LAB$"

PalletTown_Text_BluesHouseSign:
    .string "BLUE'S HOUSE$"

PalletTown_Text_Route1Aide_Intro:
    .string "ASSISTANT LEO: Route 1 is just ahead.\p"
    .string "It is usually a quiet path to\n"
    .string "VIRIDIAN CITY.\p"
    .string "With all these portals showing up on\n"
    .string "the news, I am a little on edge.$"

PalletTown_Text_Route1Aide_SawMan:
    .string "ASSISTANT LEO: Hey, you there!\p"
    .string "I just saw something terrifying on\n"
    .string "Route 1.\p"
    .string "A strange man caught a Pokemon and\n"
    .string "clamped some device onto it.\p"
    .string "Its eyes went empty and it started\n"
    .string "glowing a dark purple before it went\l"
    .string "wild.\p"
    .string "That was not normal training at all.\p"
    .string "ASSISTANT LEO: I do not want to panic\n"
    .string "the whole town yet.\p"
    .string "Come with me to the lab.\n"
    .string "The other aide needs to hear this, and\l"
    .string "maybe the Professor's notes can help us\l"
    .string "understand what is going on.$"

PalletTown_Text_Route1Aide_After:
    .string "ASSISTANT LEO: I told the lab what I\n"
    .string "saw, but with the Professor missing,\l"
    .string "I do not know what else to do.\p"
    .string "If you are heading out, please be\n"
    .string "careful on Route 1.$"
