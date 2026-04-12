Vermilion_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Vermilion_City_OnTransition
	.byte 0

Vermilion_City_OnTransition::
	setflag FLAG_VISITED_VERMILLION_CITY
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end


VermilionCity_Text_Sign:
	.string "VERMILION CITY\p"
	.string "The Port of Exquisite Sunsets$"


VermilionCity_Text_GymSign:
	.string "VERMILION CITY\n"
	.string "POKéMON GYM\p"
	.string "LEADER: LT.SURGE\p"
	.string "The Lightning American$"


VermilionCity_Text_FanClubSign:
	.string "POKéMON FAN CLUB\p"
	.string "All POKéMON Fans Welcome!$"


VermilionCity_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"
