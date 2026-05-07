RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	faceplayer
	setspeaker RustboroCity_Flat1_1F_Speaker_Gideon
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	faceplayer
	setspeaker RustboroCity_Flat1_1F_Speaker_Nora
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Speaker_Gideon:
	.string "Gideon$"

RustboroCity_Flat1_1F_Speaker_Nora:
	.string "Nora$"

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Every POKéMON has a special ability\n"
	.string "that it can use.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "POKéMON are such strange creatures.$"
