Pallet_Town_MapScripts::
    .byte 0

@ ==============================
@ SPEAKER DEFINITIONS
@ ==============================

Speaker_Leo:
    .string "Prof. Aide Leo$"

Speaker_Mara:
    .string "Mara$"

Speaker_Gus:
    .string "Gus$"

@ ==============================
@ CITY ENTER LOGIC
@ ==============================

PalletTown_EventScript_CityEnter::
    setflag FLAG_VISITED_PALLET_TOWN

    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_CityEnter_Route1Done

    setflag FLAG_HIDE_OAKS_LAB_LEO
    goto PalletTown_CityEnter_End

PalletTown_CityEnter_Route1Done::
    clearflag FLAG_HIDE_OAKS_LAB_LEO
    setflag FLAG_HIDE_PALLET_LEO

PalletTown_CityEnter_End::
    end

@ ==============================
@ OUTSIDE NPCS
@ ==============================

PalletTown_EventScript_Woman::
    lock
    faceplayer
    setspeaker Speaker_Mara
    msgbox PalletTown_Text_Teacher, MSGBOX_NPC
    closemessage
    release
    end

PalletTown_EventScript_Fatman::
    lock
    faceplayer
    setspeaker Speaker_Gus
    msgbox PalletTown_Text_Fisher, MSGBOX_NPC
    closemessage
    release
    end

PalletTown_EventScript_Yungoos::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_YUNGOOS, CRY_MODE_NORMAL
    waitmoncry
    release
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

@ ==============================
@ ROUTE 1 AIDE - LEO
@ ==============================

PalletTown_EventScript_Route1AideTalk::
    lock
    faceplayer
    checkflag FLAG_MET_ROUTE1_AIDE

    setspeaker Speaker_Leo
    msgbox PalletTown_Text_Route1Aide_Intro, MSGBOX_DEFAULT
    closemessage
    release
    end


@ -------- TRIGGER 0 --------

PalletTown_EventScript_Route1AideTrigger0::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_EventScript_Route1AideTrigger0_Done

    lockall
    playse SE_PIN
    applymovement 1, PalletTown_Move_Leo_Exclaim
    waitmovement 0
    applymovement 1, PalletTown_Move_Leo_Approach_Top
    waitmovement 0

    setspeaker Speaker_Leo
    msgbox PalletTown_Text_Route1Aide_SawMan, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_MET_ROUTE1_AIDE
    setflag FLAG_HIDE_PALLET_LEO
    setflag FLAG_OAKS_LAB_FORCE_INTRO

    applymovement 1, PalletTown_Move_Leo_Path
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_Path
    waitmovement 0

    clearflag FLAG_HIDE_OAKS_LAB_LEO
    warp MAP_OAKS_LAB, 5, 12
    waitstate

    releaseall
    end

PalletTown_EventScript_Route1AideTrigger0_Done::
    end

@ -------- TRIGGER 1 --------

PalletTown_EventScript_Route1AideTrigger1::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq PalletTown_EventScript_Route1AideTrigger1_Done

    lockall
    playse SE_PIN
    applymovement 1, PalletTown_Move_Leo_Exclaim
    waitmovement 0

    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_T1_PreAlign
    waitmovement 0

    applymovement 1, PalletTown_Move_Leo_Approach_Bottom
    waitmovement 0

    setspeaker Speaker_Leo
    msgbox PalletTown_Text_Route1Aide_SawMan, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_MET_ROUTE1_AIDE
    setflag FLAG_HIDE_PALLET_LEO
    setflag FLAG_OAKS_LAB_FORCE_INTRO

    applymovement 1, PalletTown_Move_Leo_Path
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_Path
    waitmovement 0

    clearflag FLAG_HIDE_OAKS_LAB_LEO
    warp MAP_OAKS_LAB, 5, 12
    waitstate

    releaseall
    end

PalletTown_EventScript_Route1AideTrigger1_Done::
    end

@ ==============================
@ MOVEMENTS
@ ==============================

PalletTown_Move_Leo_Exclaim:
    emote_exclamation_mark
    step_end

PalletTown_Move_Leo_Approach_Top:
    face_down
    step_end

PalletTown_Move_Leo_Approach_Bottom:
    face_down
    step_end

PalletTown_Move_Player_T1_PreAlign:
    walk_left
    face_up
    step_end

PalletTown_Move_Leo_Path:
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
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

PalletTown_Move_Player_Path:
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

@ ==============================
@ TEXT
@ ==============================

PalletTown_Text_Teacher:
    .string "I'm a teacher here in town.\p"
    .string "Lately my students keep talking about\n"
    .string "portals opening and POKEMON on the\l"
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

PalletTown_Text_BluesHouseSign:
    .string "BLUE'S HOUSE$"

PalletTown_Text_OaksLabSign:
    .string "OAK POKEMON\n"
    .string "RESEARCH LAB$"

PalletTown_Text_Route1Aide_Intro:
    .string "Route 1 is just ahead.\p"
    .string "It is usually a quiet path to\n"
    .string "VIRIDIAN CITY.\p"
    .string "With all these portals showing up on\n"
    .string "the news, I am a little on edge.$"

PalletTown_Text_Route1Aide_SawMan:
    .string "NO WAY!\p"
    .string "I have no idea who you are, but did\n"
    .string "you see what just happened?!\p"
    .string "A strange man on Route 1 just captured\n"
    .string "an innocent POKEMON and clamped some\l"
    .string "strange device to it.\p"
    .string "It started to give off a strange aura\n"
    .string "and even changed colors!\p"
    .string "Its behavior is starting to change\n"
    .string "as well...\p"
    .string "I have to inform Nia. Please come with\n"
    .string "me quickly!$"
