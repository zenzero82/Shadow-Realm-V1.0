Pallet_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	.byte 0

PalletTown_OnTransition::
	call PalletTown_EventScript_CityEnter
	end

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
    setflag FLAG_QUEST_PALLET_TOWN_NPC_WOMAN
    call QuestJournal_EventScript_CheckPalletTownNPCs
    release
    end

PalletTown_EventScript_Fatman::
    lock
    faceplayer
    setspeaker Speaker_Gus
    msgbox PalletTown_Text_Fisher, MSGBOX_NPC
    closemessage
    setflag FLAG_QUEST_PALLET_TOWN_NPC_FATMAN
    call QuestJournal_EventScript_CheckPalletTownNPCs
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

PalletTown_EventScript_Pidgey::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
    waitmoncry
    release
    end

PalletTown_EventScript_Pikipek::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_PIKIPEK, CRY_MODE_NORMAL
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

QuestJournal_EventScript_CheckPalletTownNPCs::
    checkflag FLAG_QUEST_PALLET_TOWN_COMPLETED
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_End
    checkflag FLAG_QUEST_PALLET_TOWN_STARTED
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_Woman
    return
QuestJournal_EventScript_CheckPalletTownNPCs_Woman:
    checkflag FLAG_QUEST_PALLET_TOWN_NPC_WOMAN
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_Fatman
    return
QuestJournal_EventScript_CheckPalletTownNPCs_Fatman:
    checkflag FLAG_QUEST_PALLET_TOWN_NPC_FATMAN
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_RedsMom
    return
QuestJournal_EventScript_CheckPalletTownNPCs_RedsMom:
    checkflag FLAG_QUEST_PALLET_TOWN_NPC_REDS_MOM
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_Daisy
    return
QuestJournal_EventScript_CheckPalletTownNPCs_Daisy:
    checkflag FLAG_QUEST_PALLET_TOWN_NPC_DAISY
    goto_if_eq QuestJournal_EventScript_CheckPalletTownNPCs_Done
    return
QuestJournal_EventScript_CheckPalletTownNPCs_Done:
    setflag FLAG_QUEST_PALLET_TOWN_COMPLETED
    call QuestJournal_EventScript_QuestCompleteAlert
QuestJournal_EventScript_CheckPalletTownNPCs_End:
    return

QuestJournal_EventScript_NewQuestAlert::
    playse SE_DING_DONG
    msgbox QuestJournal_Text_NewQuest, MSGBOX_DEFAULT
    closemessage
    return

QuestJournal_EventScript_NewQuestsAlert::
    playse SE_DING_DONG
    msgbox QuestJournal_Text_NewQuests, MSGBOX_DEFAULT
    closemessage
    return

QuestJournal_EventScript_QuestCompleteAlert::
    playse SE_DING_DONG
    msgbox QuestJournal_Text_QuestComplete, MSGBOX_DEFAULT
    closemessage
    return


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

    playse SE_DOOR
    opendoor 16, 13
    waitdooranim

    applymovement 1, PalletTown_Move_Leo_EnterLab
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_EnterLab
    waitmovement 0

    closedoor 16, 13
    waitdooranim

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

    playse SE_DOOR
    opendoor 16, 13
    waitdooranim

    applymovement 1, PalletTown_Move_Leo_EnterLab
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Move_Player_EnterLab
    waitmovement 0

    closedoor 16, 13
    waitdooranim

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
    step_end

PalletTown_Move_Leo_EnterLab:
    walk_up
    step_end

PalletTown_Move_Player_EnterLab:
    walk_right
    walk_up
    step_end

@ ==============================
@ TEXT
@ ==============================

PalletTown_Text_Teacher:
    .string "I'm a teacher here in town.\p"
    .string "Lately my students keep talking about\n"
    .string "POKéMON on the news that should\l"
    .string "not even exist in KANTO.$"

PalletTown_Text_Fisher:
    .string "Technology is incredible... and a little\n"
    .string "terrifying right now.\p"
    .string "The news has been covering a lot\n"
    .string "of strange stories lately.\p"
    .string "Sometimes the broadcast glitches like it\n"
    .string "was being hacked.$"

PalletTown_Text_Sign:
    .string "PALLET TOWN\p"
    .string "A Tranquil Setting of Peace\n"
    .string "& Purity$"

PalletTown_Text_RedsHouseSign:
    .string "RED'S HOUSE$"

PalletTown_Text_BluesHouseSign:
    .string "GARY'S HOUSE$"

PalletTown_Text_OaksLabSign:
    .string "OAK POKéMON\n"
    .string "RESEARCH LAB$"

QuestJournal_Text_NewQuest:
    .string "New Quest added to the\n"
    .string "Quest Journal!$"

QuestJournal_Text_NewQuests:
    .string "New Quests have been added\n"
    .string "to the Quest Journal!$"

QuestJournal_Text_QuestComplete:
    .string "Quest fulfilled!$"

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
    .string "an innocent POKéMON with some strange\l"
    .string "looking POKé BALL.\p"
    .string "He sent it back out and it looks weird!\p"
    .string "It started to give off a strange aura\n"
    .string "and even changed colors!\p"
    .string "Its behavior seems like it's different\n"
    .string "as well...\p"
    .string "I have to inform Nia. Please come with\n"
    .string "me quickly!$"
