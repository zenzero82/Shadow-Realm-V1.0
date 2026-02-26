CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Man::
	faceplayer
	msgbox CherrygroveCity_House1_Text_Man, MSGBOX_NPC
	end

CherrygroveCity_House1_EventScript_Boy::
	faceplayer
	msgbox CherrygroveCity_House1_Text_Boy, MSGBOX_NPC
	end

CherrygroveCity_House1_Text_Man:
	.string "The sea keeps our town cool.\n"
	.string "I like the quiet here.$"

CherrygroveCity_House1_Text_Boy:
	.string "I want to visit MR. POKéMON someday.\n"
	.string "He has rare things!$"
