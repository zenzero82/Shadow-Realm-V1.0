Fuchsia_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Fuchsia_City_OnTransition
	.byte 0

Fuchsia_City_OnTransition::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end


FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end


FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end


FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	goto EventScript_GimmighoulSignpost


FuchsiaCity_Text_Sign:
	.string "FUCHSIA CITY\p"
	.string "Behold! It's Passion Pink!$"


FuchsiaCity_Text_GymSign:
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "The Poisonous Ninja Master$"


FuchsiaCity_Text_SafariZone:
	.string "SAFARI ZONE\n"
	.string "NOW OWNED BY\l"
	.string "DEVON CORP.$"
