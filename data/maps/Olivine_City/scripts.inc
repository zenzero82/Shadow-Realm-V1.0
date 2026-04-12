Olivine_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Olivine_City_OnTransition
	.byte 0

Olivine_City_OnTransition::
	setflag FLAG_VISITED_OLIVINE_CITY
	end

OlivineCity_EventScript_GymSign::
	msgbox OlivineCity_EventScript_GymSign_Text, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

OlivineCity_EventScript_LighthouseSign::
	msgbox OlivineCity_EventScript_LighthouseSign_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

OlivineCity_EventScript_LighthouseSign_Text:
	.string "OLIVINE LIGHTHOUSE.$"

OlivineCity_EventScript_PortSign::
	msgbox OlivineCity_EventScript_PortSign_Text, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign_Text:
	.string "OLIVINE PORT.$"

OlivineCity_EventScript_Sign::
	msgbox OlivineCity_EventScript_Sign_Text, MSGBOX_SIGN
	end

OlivineCity_EventScript_Sign_Text:
	.string "It's a sign.$"

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_EventScript_CafeSign_Text, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign_Text:
	.string "OLIVINE CAFE.$"

OlivineCity_Text_CafeSign:
	.string "OLIVINE CAFE\n"
	.string "WHERE STRONG SAILORS ENJOY\l"
	.string "HEARTY MEALS OF STRENGTH$"


OlivineCity_Text_Sign:
	.string "OLIVINE CITY\p"
	.string "The Port Closest to Foreign Lands$"


OlivineCity_Text_PortSign:
	.string "OLIVINE PORT\n"
	.string "FAST SHIP PIER$"


OlivineCity_Text_GymSign:
	.string "OLIVINE CITY POKéMON GYM\n"
	.string "LEADER: JASMINE\p"
	.string "The Steel-Clad Defense Girl$"


OlivineCity_Text_LighthouseSign:
	.string "OLIVINE LIGHTHOUSE\n"
	.string "Also known as the GLITTER\l"
	.string "LIGHTHOUSE$"

