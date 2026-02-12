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
