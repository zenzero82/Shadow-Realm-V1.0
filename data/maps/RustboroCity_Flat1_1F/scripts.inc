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

RustboroCity_Flat1_1F_EventScript_Expert::
	faceplayer
	setspeaker RustboroCity_Flat1_1F_Speaker_Elias
	msgbox RustboroCity_Flat1_1F_Text_DevonAndSchool, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Skitty::
	lock
	faceplayer
	setspeaker RustboroCity_Flat1_1F_Speaker_Skitty
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat1_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat1_1F_Speaker_Gideon:
	.string "Gideon$"

RustboroCity_Flat1_1F_Speaker_Nora:
	.string "Nora$"

RustboroCity_Flat1_1F_Speaker_Elias:
	.string "Elias$"

RustboroCity_Flat1_1F_Speaker_Skitty:
	.string "Skitty$"

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Every POKéMON has an ABILITY.\p"
	.string "The TRAINER'S SCHOOL teaches the\n"
	.string "basics, but living with POKéMON\l"
	.string "teaches the details.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "RUSTBORO blends stone, science, and\n"
	.string "nature better than anywhere else.\p"
	.string "That balance feels more important\n"
	.string "now, with SHADOW POKéMON appearing.$"

RustboroCity_Flat1_1F_Text_DevonAndSchool:
	.string "DEVON turns ideas into inventions,\n"
	.string "and ROXANNE turns students into\l"
	.string "TRAINERS.\p"
	.string "This city is built for people who\n"
	.string "want to learn.$"

RustboroCity_Flat1_1F_Text_Skitty:
	.string "SKITTY: Mrowr!$"
