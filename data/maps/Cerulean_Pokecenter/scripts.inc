Cerulean_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cerulean_Pokecenter_OnTransition
	.byte 0
Cerulean_Pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

Cerulean_Pokecenter_Speaker_SuperNerd:
	.string "EDDIE$"

Cerulean_Pokecenter_Speaker_Gentleman:
	.string "ARTHUR$"

Cerulean_Pokecenter_EventScript_SuperNerd::
	lock
	faceplayer
	setspeaker Cerulean_Pokecenter_Speaker_SuperNerd
	msgbox Cerulean_Pokecenter_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

Cerulean_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	setspeaker Cerulean_Pokecenter_Speaker_Gentleman
	msgbox Cerulean_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

Cerulean_Pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

Cerulean_Pokecenter_Text_SuperNerd:
	.string "The police are everywhere outside.\p"
	.string "I just wanted to heal my team and\n"
	.string "get out of the way.$"

Cerulean_Pokecenter_Text_Gentleman:
	.string "CERULEAN used to feel calm.\n"
	.string "Now it's all sirens and rumors.$"

Cerulean_Pokecenter_EventScript_Bookshelf1::
	msgbox Cerulean_Pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

Cerulean_Pokecenter_EventScript_Bookshelf2::
	msgbox Cerulean_Pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

Cerulean_Pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap

Cerulean_Pokecenter_Text_Bookshelf1:
	.string "A travel guide to NUGGET BRIDGE.$"

Cerulean_Pokecenter_Text_Bookshelf2:
	.string "Warnings about CERULEAN CAVE.$"
