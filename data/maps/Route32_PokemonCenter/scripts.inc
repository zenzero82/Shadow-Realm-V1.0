Route32_PokemonCenter_MapScripts::
	.byte 0

Route32_PokemonCenter_Speaker_Fisherman:
	.string "MARLIN$"

Route32_PokemonCenter_Speaker_Lass:
	.string "JOSIE$"

Route32_PokemonCenter_EventScript_Fisherman::
	faceplayer
	setspeaker Route32_PokemonCenter_Speaker_Fisherman
	msgbox Route32_PokemonCenter_Text_Fisherman, MSGBOX_NPC
	end

Route32_PokemonCenter_EventScript_Lass::
	faceplayer
	setspeaker Route32_PokemonCenter_Speaker_Lass
	msgbox Route32_PokemonCenter_Text_Lass, MSGBOX_NPC
	end

Route32_PokemonCenter_Text_Fisherman:
	.string "I rest here before fishing down\n"
	.string "the coast.$"

Route32_PokemonCenter_Text_Lass:
	.string "The route gets long. Healing here\n"
	.string "saves a lot of time.$"
