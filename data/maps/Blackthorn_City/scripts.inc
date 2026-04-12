Blackthorn_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Blackthorn_City_OnTransition
	.byte 0

Blackthorn_City_OnTransition::
	setflag FLAG_VISITED_BLACKTHORN_CITY
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_EventScript_DragonsDenSign_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

BlackthornCity_EventScript_DragonsDenSign_Text:
	.string "It's a sign.$"

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornCity_EventScript_GymSign_Text, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_EventScript_MoveHouseSign_Text, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign_Text:
	.string "It's a sign.$"

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCity_EventScript_CitySign_Text, MSGBOX_SIGN
	end

BlackthornCity_EventScript_CitySign_Text:
	.string "Welcome to town.$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MOVE BROS' HOUSE$"


BlackthornCity_Text_DragonDenSign:
	.string "DRAGON'S DEN AHEAD$"

