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

cerulean_house3_EventScript_Bookshelf::
	msgbox cerulean_house3_Text_Bookshelf, MSGBOX_SIGN
	end

cerulean_house3_EventScript_TV::
	msgbox cerulean_house3_Text_TV, MSGBOX_SIGN
	end

cerulean_house3_Text_Hiker:
	.string "I was headed for the CAPE, but the\n"
	.string "police turned me back.$"

cerulean_house3_Text_Bookshelf:
	.string "Camping guides are lined up neatly.\p"
	.string "A bookmark sits on a page about cave\n"
	.string "safety and packed lunches.$"

cerulean_house3_Text_TV:
	.string "A travel show is running a feature\n"
	.string "on CERULEAN CAPE.\p"
	.string "The host keeps warning viewers to\n"
	.string "respect police barricades.$"
