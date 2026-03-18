cerulean_house3_MapScripts::
	.byte 0

cerulean_house3_Speaker_Hiker:
	.string "GRANT$"

cerulean_house3_EventScript_Hiker::
	lock
	faceplayer
	setspeaker cerulean_house3_Speaker_Hiker
	msgbox cerulean_house3_Text_Hiker, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE3_HIKER
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	release
	end

cerulean_house3_Text_Hiker:
	.string "I was headed for the CAPE, but the\n"
	.string "police turned me back.$"
