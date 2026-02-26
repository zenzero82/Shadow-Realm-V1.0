AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_PokemonCenter_OnTransition
	.byte 0

AzaleaTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaTown_PokemonCenter_EventScript_Fisherman::
	faceplayer
	msgbox AzaleaTown_PokemonCenter_Text_Fisherman, MSGBOX_NPC
	end

AzaleaTown_PokemonCenter_EventScript_Gentleman::
	faceplayer
	msgbox AzaleaTown_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	end

AzaleaTown_PokemonCenter_EventScript_Woman::
	faceplayer
	msgbox AzaleaTown_PokemonCenter_Text_Woman, MSGBOX_NPC
	end

AzaleaTown_PokemonCenter_Text_Fisherman:
	.string "I was headed for the WELL, but I'm\n"
	.string "taking a breather first.$"

AzaleaTown_PokemonCenter_Text_Gentleman:
	.string "A steady rest keeps your team ready\n"
	.string "for any challenge.$"

AzaleaTown_PokemonCenter_Text_Woman:
	.string "AZALEA feels calm again. I hope it\n"
	.string "stays that way.$"
