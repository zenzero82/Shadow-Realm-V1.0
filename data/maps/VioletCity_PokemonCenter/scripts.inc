VioletCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_PokemonCenter_OnTransition
	.byte 0

VioletCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end

VioletCity_PokemonCenter_EventScript_GameboyKid::
	faceplayer
	msgbox VioletCity_PokemonCenter_Text_GameboyKid, MSGBOX_NPC
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	faceplayer
	msgbox VioletCity_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	end

VioletCity_PokemonCenter_EventScript_Beauty::
	faceplayer
	msgbox VioletCity_PokemonCenter_Text_Beauty, MSGBOX_NPC
	end

VioletCity_PokemonCenter_Text_GameboyKid:
	.string "I like to compare notes with other\n"
	.string "trainers here.$"

VioletCity_PokemonCenter_Text_Gentleman:
	.string "A quiet rest keeps your team ready\n"
	.string "for the next road.$"

VioletCity_PokemonCenter_Text_Beauty:
	.string "BLISSEY has a calming presence.\n"
	.string "It helps everyone relax.$"
