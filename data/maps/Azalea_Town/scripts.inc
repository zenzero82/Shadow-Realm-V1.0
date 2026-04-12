Azalea_Town_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

#define LOCALID_AZALEA_AQUA_GRUNT_ILEX 4
#define LOCALID_AZALEA_AQUA_GRUNT_GYM 5
#define LOCALID_AZALEA_ILEX_OFFICER 6

Azalea_Town_Speaker_Youngster:
	.string "TIM$"

Azalea_Town_Speaker_Lass:
	.string "LUCY$"

Azalea_Town_Speaker_Rocket:
	.string "GRUNT$"

Azalea_Town_Speaker_Officer:
	.string "OFFICER$"

AzaleaTown_OnFrame:
	map_script_2 VAR_TEMP_1, 0, AzaleaTown_EventScript_CityEnter
	.2byte 0

AzaleaTown_EventScript_CityEnter::
	setvar VAR_TEMP_1, 1
	setflag FLAG_VISITED_AZALEA_TOWN
	checkflag FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE
	goto_if_eq AzaleaTown_EventScript_CityEnter_AfterMarauder
	clearflag FLAG_HIDE_AZALEA_AQUA_GRUNTS
	setflag FLAG_HIDE_AZALEA_ILEX_OFFICER
	goto AzaleaTown_EventScript_CityEnter_CheckOfficer
AzaleaTown_EventScript_CityEnter_AfterMarauder:
	setflag FLAG_HIDE_AZALEA_AQUA_GRUNTS
	clearflag FLAG_HIDE_AZALEA_ILEX_OFFICER
AzaleaTown_EventScript_CityEnter_CheckOfficer:
	checkflag FLAG_HIDE_ILEX_JJ_GROUP
	goto_if_eq AzaleaTown_EventScript_CityEnter_OfficerHidden
	goto AzaleaTown_EventScript_CityEnter_QuestStart
AzaleaTown_EventScript_CityEnter_OfficerHidden:
	setflag FLAG_HIDE_AZALEA_ILEX_OFFICER
AzaleaTown_EventScript_CityEnter_QuestStart:
	checkflag FLAG_QUEST_AZALEA_NPCS_STARTED
	goto_if_eq AzaleaTown_EventScript_CityEnter_QuestSkip
	checkflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	goto_if_eq AzaleaTown_EventScript_CityEnter_QuestSkip
	lockall
	setflag FLAG_QUEST_AZALEA_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
AzaleaTown_EventScript_CityEnter_QuestSkip:
	end


__stub_Azalea_Town::
	end


AzaleaTown_EventScript_GymSign::
	msgbox AzaleaTown_EventScript_GymSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_GymSign_Text:
	.string "AZALEA TOWN\n"
	.string "POKéMON GYM\p"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"

AzaleaTown_EventScript_KurtSign::
	msgbox AzaleaTown_EventScript_KurtSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtSign_Text:
	.string "KURT'S HOUSE.$"

AzaleaTown_EventScript_IlexSign::
	msgbox AzaleaTown_EventScript_IlexSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_IlexSign_Text:
	.string "ILEX FOREST AHEAD.$"

AzaleaTown_EventScript_KilnSign::
	msgbox AzaleaTown_EventScript_KilnSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KilnSign_Text:
	.string "KURT'S CHARCOAL KILN.$"

AzaleaTown_EventScript_WellSign::
	msgbox AzaleaTown_EventScript_WellSign_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

AzaleaTown_EventScript_WellSign_Text:
	.string "SLOWPOKE WELL.$"

AzaleaTown_EventScript_AzaleaSign::
	msgbox AzaleaTown_EventScript_AzaleaSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_AzaleaSign_Text:
	.string "It's a sign.$"

AzaleaTown_EventScript_Youngster::
	faceplayer
	setspeaker Azalea_Town_Speaker_Youngster
	msgbox AzaleaTown_Text_Youngster, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_AZALEA_NPC_YOUNGSTER
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_EventScript_Lass::
	faceplayer
	setspeaker Azalea_Town_Speaker_Lass
	msgbox AzaleaTown_Text_Lass, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_AZALEA_NPC_LASS
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_EventScript_Rocket::
	faceplayer
	setspeaker Azalea_Town_Speaker_Rocket
	msgbox AzaleaTown_Text_Rocket, MSGBOX_NPC
	closemessage
	end

AzaleaTown_EventScript_AquaGruntGym::
	faceplayer
	setspeaker Azalea_Town_Speaker_Rocket
	msgbox AzaleaTown_Text_AquaGruntGym, MSGBOX_NPC
	end

AzaleaTown_EventScript_IlexOfficer::
	faceplayer
	setspeaker Azalea_Town_Speaker_Officer
	msgbox AzaleaTown_Text_IlexOfficer, MSGBOX_NPC
	end

AzaleaTown_EventScript_CheckAzaleaQuest::
	checkflag FLAG_QUEST_AZALEA_NPCS_STARTED
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckCompleted
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckCompleted:
	checkflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_Done
	checkflag FLAG_QUEST_AZALEA_NPC_YOUNGSTER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckLass
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckLass:
	checkflag FLAG_QUEST_AZALEA_NPC_LASS
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1BlackBelt
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1BlackBelt:
	checkflag FLAG_QUEST_AZALEA_NPC_HOUSE1_BLACK_BELT
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1LittleBoy
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1LittleBoy:
	checkflag FLAG_QUEST_AZALEA_NPC_HOUSE1_LITTLE_BOY
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckKurtsHouseKurt
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckKurtsHouseKurt:
	checkflag FLAG_QUEST_AZALEA_NPC_KURTS_HOUSE_KURT
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartRocker
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartRocker:
	checkflag FLAG_QUEST_AZALEA_NPC_MART_ROCKER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartBugCatcher
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartBugCatcher:
	checkflag FLAG_QUEST_AZALEA_NPC_MART_BUG_CATCHER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterFisherman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterFisherman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_FISHERMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterGentleman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterGentleman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_GENTLEMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterWoman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterWoman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_WOMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_AllDone
	return
AzaleaTown_EventScript_CheckAzaleaQuest_AllDone:
	setflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
AzaleaTown_EventScript_CheckAzaleaQuest_Done:
	return

AzaleaTown_Text_Youngster:
	.string "BUGSY's gym is buzzing.\n"
	.string "I'm training up before I go in.$"

AzaleaTown_Text_Lass:
	.string "KURT's work keeps this town going.\n"
	.string "His balls are the best.$"

AzaleaTown_Text_Rocket:
	.string "Can't let you pass kid.$"

AzaleaTown_Text_AquaGruntGym:
	.string "We're taking care of business\n"
	.string "here. Savvy?$"

AzaleaTown_Text_IlexOfficer:
	.string "A little late but I managed to\n"
	.string "drive those grunts out of town\l"
	.string "with the help of Bugsy!$"

AzaleaTown_Text_Sign:
	.string "AZALEA TOWN\n"
	.string "Where People and POKéMON Live in\l"
	.string "Happy Harmony.$"


AzaleaTown_Text_KurtsHouseSign:
	.string "KURT'S HOUSE$"


AzaleaTown_Text_GymSign:
	.string "AZALEA TOWN\n"
	.string "POKéMON GYM\p"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"


AzaleaTown_Text_SlowpokeWellSign:
	.string "SLOWPOKE WELL\p"
	.string "Also known as the RAINMAKER WELL.\p"
	.string "Locals believe that a SLOWPOKE's\n"
	.string "yawn summons rain.\p"
	.string "Records show that a SLOWPOKE's\n"
	.string "yawn ended a drought 400 years ago.$"


AzaleaTown_Text_CharcoalKilnSign:
	.string "CHARCOAL KILN$"


AzaleaTown_Text_IlexForestSign:
	.string "ILEX FOREST\p"
	.string "Enter through the gate.$"

