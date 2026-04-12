Indigo_Plateau_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Indigo_Plateau_OnTransition
	.byte 0

Indigo_Plateau_OnTransition::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	end

IndigoPlateau_Sign::
	msgbox IndigoPlateau_Text_Sign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost


IndigoPlateau_Text_Sign:
	.string "INDIGO PLATEAU\p"
	.string "The Ultimate Goal for Trainers!\p"
	.string "POKéMON LEAGUE HQ$"
