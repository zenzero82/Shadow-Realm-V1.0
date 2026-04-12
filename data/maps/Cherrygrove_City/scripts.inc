Cherrygrove_City_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Cherrygrove_City_OnFrame
	.byte 0

Cherrygrove_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Cherrygrove_City_EventScript_CityEnter
	.2byte 0

Cherrygrove_City_EventScript_CityEnter::
	setvar VAR_TEMP_1, 1
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	checkflag FLAG_QUEST_CHERRYGROVE_NPCS_STARTED
	goto_if_eq Cherrygrove_City_EventScript_CityEnter_End
	checkflag FLAG_QUEST_CHERRYGROVE_NPCS_COMPLETED
	goto_if_eq Cherrygrove_City_EventScript_CityEnter_End
	lockall
	setflag FLAG_QUEST_CHERRYGROVE_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	releaseall
Cherrygrove_City_EventScript_CityEnter_End:
	end

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

Cherrygrove_City_Speaker_Flare:
	.string "FLARE$"

Cherrygrove_City_Speaker_Boy:
	.string "BOY$"

Cherrygrove_City_Speaker_Lass:
	.string "LASS$"

@ =================================================
@ FLARE GRUNTS
@ =================================================

Cherrygrove_City_EventScript_FlareGrunt1::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt1, MSGBOX_NPC
	end

Cherrygrove_City_EventScript_FlareGrunt2::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt2, MSGBOX_NPC
	end

Cherrygrove_City_EventScript_FlareGrunt3::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt3, MSGBOX_NPC
	end

@ ================================
@ CHERRYGROVE PORTAL WARP (MIROR B)
@ Attach this script to your portal object in Porymap:
@   Script: Cherrygrove_City_EventScript_Portal_ToMirorb

Cherrygrove_City_EventScript_Portal_ToMirorb::
	lock
	faceplayer
	msgbox Cherrygrove_City_Text_PortalAsk_Mirorb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Cherrygrove_City_PortalNo

	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	warp MAP_MIRORB_LAIR, WARP_ID_NONE, 3, 3

	waitstate
	end

Cherrygrove_City_PortalNo::
	closemessage
	release
	end

Cherrygrove_City_Text_PortalAsk_Mirorb:
	.string "The portal is humming...\p"
	.string "Warp to MIROR B'S LAIR?$"

Cherrygrove_City_Text_FlareGrunt1:
	.string "Move along. This area is under\n"
	.string "observation for TEAM FLARE.$"

Cherrygrove_City_Text_FlareGrunt2:
	.string "We're searching for abnormal\n"
	.string "energy readings in JOHTO.$"

Cherrygrove_City_Text_FlareGrunt3:
	.string "Some tech around here is too\n"
	.string "advanced to ignore.$"

CherryGroveCity_EventScript_Sign::
	msgbox CherryGroveCity_EventScript_Sign_Text, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Sign_Text:
	.string "CHERRYGROVE CITY\p"
	.string "The City of Cute, Fragrant\n"
	.string "Flowers$"

Cherrygrove_City_EventScript_Boy::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Boy
	msgbox Cherrygrove_City_Text_Boy, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_BOY
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

Cherrygrove_City_EventScript_Lass::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Lass
	msgbox Cherrygrove_City_Text_Lass, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_LASS
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

Cherrygrove_City_Text_Boy:
	.string "MR. POKéMON lives past ROUTE 30.\n"
	.string "I want to see his rare finds.$"

Cherrygrove_City_Text_Lass:
	.string "This town feels calm, but travelers\n"
	.string "keep whispering about strange teams.$"

QuestJournal_EventScript_CheckCherrygroveNPCs::
	checkflag FLAG_QUEST_CHERRYGROVE_NPCS_COMPLETED
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_End
	checkflag FLAG_QUEST_CHERRYGROVE_NPCS_STARTED
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_Boy
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_Boy:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_BOY
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_Lass
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_Lass:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_LASS
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterFisherman
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterFisherman:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_FISHERMAN
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterLass
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterLass:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_LASS
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterGentleman
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_PokecenterGentleman:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_GENTLEMAN
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_MartYoungster
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_MartYoungster:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_MART_YOUNGSTER
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_MartBugCatcher
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_MartBugCatcher:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_MART_BUG_CATCHER
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_House1Man
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_House1Man:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE1_MAN
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_House1Boy
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_House1Boy:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE1_BOY
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_House2Youngster
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_House2Youngster:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE2_YOUNGSTER
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_House2BattleGirl
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_House2BattleGirl:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE2_BATTLE_GIRL
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_House3OldMan
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_House3OldMan:
	checkflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE3_OLD_MAN
	goto_if_eq QuestJournal_EventScript_CheckCherrygroveNPCs_Done
	return
QuestJournal_EventScript_CheckCherrygroveNPCs_Done:
	setflag FLAG_QUEST_CHERRYGROVE_NPCS_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
QuestJournal_EventScript_CheckCherrygroveNPCs_End:
	return

CherrygroveCity_Text_CitySign:
	.string "CHERRYGROVE CITY\p"
	.string "The City of Cute, Fragrant\n"
	.string "Flowers$"

