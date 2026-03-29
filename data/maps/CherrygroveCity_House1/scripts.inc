CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_Speaker_Man:
	.string "DAN$"

CherrygroveCity_House1_Speaker_Boy:
	.string "RYAN$"

CherrygroveCity_House1_EventScript_Man::
	faceplayer
	setspeaker CherrygroveCity_House1_Speaker_Man
	msgbox CherrygroveCity_House1_Text_Man, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE1_MAN
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_House1_EventScript_Boy::
	faceplayer
	setspeaker CherrygroveCity_House1_Speaker_Boy
	msgbox CherrygroveCity_House1_Text_Boy, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE1_BOY
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_House1_Text_Man:
	.string "The sea keeps our town cool.\n"
	.string "I like the quiet here.$"

CherrygroveCity_House1_Text_Boy:
	.string "I want to visit MR. POKéMON someday.\n"
	.string "He has rare things!$"
