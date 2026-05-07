GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_Speaker_Edna:
	.string "EDNA$"

GoldenrodCity_PokemonCenter_Speaker_Nora:
	.string "NORA$"

GoldenrodCity_PokemonCenter_Speaker_Ken:
	.string "KEN$"

GoldenrodCity_PokemonCenter_Speaker_Leo:
	.string "LEO$"

GoldenrodCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_Edna::
	lock
	faceplayer
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Edna
	msgbox GoldenrodCity_PokemonCenter_Text_Edna, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Nora::
	lock
	faceplayer
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Nora
	msgbox GoldenrodCity_PokemonCenter_Text_Nora, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Ken::
	lock
	faceplayer
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Ken
	msgbox GoldenrodCity_PokemonCenter_Text_Ken, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Leo::
	lock
	faceplayer
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Leo
	msgbox GoldenrodCity_PokemonCenter_Text_Leo, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_Text_Edna:
	.string "Even with the city in chaos, the\n"
	.string "CENTER never gets to slow down.$"

GoldenrodCity_PokemonCenter_Text_Nora:
	.string "I heal up here, then head right back\n"
	.string "out. Goldenrod still needs help.$"

GoldenrodCity_PokemonCenter_Text_Ken:
	.string "Link battles feel silly right now,\n"
	.string "but they keep our minds sharp.$"

GoldenrodCity_PokemonCenter_Text_Leo:
	.string "If CIPHER wants a city full of scared\n"
	.string "trainers, they're going to be upset.$"
