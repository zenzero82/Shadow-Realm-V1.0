Cianwood_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cianwood_City_OnTransition
	.byte 0

Cianwood_City_OnTransition::
	setflag FLAG_VISITED_CIANWOOD_CITY
	end

CianwoodCity_EventScript_CitySign::
	msgbox CianwoodCity_EventScript_CitySign_Text, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CitySign_Text:
	.string "Welcome to town.$"

CianwoodCity_EventScript_Pharmacy::
	msgbox CianwoodCity_EventScript_Pharmacy_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

CianwoodCity_EventScript_Pharmacy_Text:
	.string "Cianwood Pharmacy.$"

CianwoodCity_EventScript_GymSign::
	msgbox CianwoodCity_EventScript_GymSign_Text, MSGBOX_SIGN
	end

CianwoodCity_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

CianwoodCity_EventScript_CaveSign::
	msgbox CianwoodCity_EventScript_CaveSign_Text, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CaveSign_Text:
	.string "To the cave.$"

CianwoodCity_Text_Sign:
	.string "CIANWOOD CITY\p"
	.string "A Port Surrounded by Rough Seas$"


CianwoodCity_Text_GymSign:
	.string "CIANWOOD CITY POKéMON GYM\p"
	.string "LEADER: CHUCK\p"
	.string "His Roaring Fists Do the Talking$"


CianwoodCity_Text_PharmacySign:
	.string "500 Years of Tradition\p"
	.string "CIANWOOD CITY PHARMACY\p"
	.string "We Await Your Medicinal Queries$"


CianwoodCity_Text_Safari:
	.string "CLIFF EDGE CAVE\n"
	.string "Road to the SAFARI ZONE.$"

