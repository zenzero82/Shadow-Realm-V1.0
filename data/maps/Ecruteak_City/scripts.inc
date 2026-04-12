Ecruteak_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Ecruteak_City_OnTransition
	.byte 0

Ecruteak_City_OnTransition::
	setflag FLAG_VISITED_ECRUTEAK_CITY
	end

EcruteakCity_EventScript_GymSign::
	msgbox EcruteakCity_EventScript_GymSign_Text, MSGBOX_SIGN
	end

EcruteakCity_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

EcruteakCity_EventScript_TheaterSign::
	msgbox EcruteakCity_EventScript_TheaterSign_Text, MSGBOX_SIGN
	end

EcruteakCity_EventScript_TheaterSign_Text:
	.string "It's a sign.$"

EcruteakCity_EventScript_OfficeSign::
	msgbox EcruteakCity_EventScript_OfficeSign_Text, MSGBOX_SIGN
	end

EcruteakCity_EventScript_OfficeSign_Text:
	.string "It's a sign.$"

EcruteakCity_EventScript_BurnedSign::
	msgbox EcruteakCity_EventScript_BurnedSign_Text, MSGBOX_SIGN
	end

EcruteakCity_EventScript_BurnedSign_Text:
	.string "It's a sign.$"

EcruteakCity_EventScript_CitySign::
	msgbox EcruteakCity_EventScript_CitySign_Text, MSGBOX_SIGN
	end

EcruteakCity_EventScript_CitySign_Text:
	.string "Welcome to town.$"

EcruteakCity_Text_Sign:
	.string "ECRUTEAK CITY\n"
	.string "A Historical City\p"
	.string "Where the Past Meets the Present$"


EcruteakCity_Text_OfficeSign:
	.string "Barrier Station to TIN TOWER\p"
	.string "No Trespassing by the Unworthy.$"


EcruteakCity_Text_GymSign:
	.string "ECRUTEAK CITY POKéMON GYM\n"
	.string "LEADER: MORTY\p"
	.string "The Mystic Seer of the Future$"


EcruteakCity_Text_DanceTheaterSign:
	.string "ECRUTEAK DANCE THEATER$"


EcruteakCity_Text_BurnedTowerSign:
	.string "BURNED TOWER\p"
	.string "It was destroyed by a mysterious\n"
	.string "fire.\p"
	.string "Please stay away, as it is unsafe.$"

