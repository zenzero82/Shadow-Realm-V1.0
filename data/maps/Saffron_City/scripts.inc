Saffron_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Saffron_City_OnTransition
	.byte 0

Saffron_City_OnTransition::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end


SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost


SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end


SaffronCity_Text_Sign:
	.string "SAFFRON CITY\p"
	.string "Shining, Golden Land of Commerce$"


SaffronCity_Text_GymSign:
	.string "SAFFRON CITY\n"
	.string "POKéMON GYM\l"
	.string "LEADER: SABRINA\p"
	.string "The Master of Psychic POKéMON!$"


SaffronCity_Text_FightingDojoSign:
	.string "Everyone Welcome!\n"
	.string "FIGHTING DOJO$"


SaffronCity_Text_SilphCoSign:
	.string "SILPH CO.\n"
	.string "OFFICE BUILDING$"


SaffronCity_Text_MrPsychicHouseSign:
	.string "MR.PSYCHIC'S\n"
	.string "HOUSE$"


SaffronCity_Text_MagnetTrainStationSign:
	.string "SAFFRON CITY\n"
	.string "MAGNET TRAIN STATION$"
