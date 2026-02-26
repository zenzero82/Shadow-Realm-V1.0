Route30_MapScripts::
	.byte 0

Route30_EventScript_LittleBoy::
	faceplayer
	msgbox Route30_Text_LittleBoy, MSGBOX_NPC
	end

Route30_EventScript_Youngster::
	faceplayer
	msgbox Route30_Text_Youngster, MSGBOX_NPC
	end

Route30_EventScript_BugCatcher::
	faceplayer
	msgbox Route30_Text_BugCatcher, MSGBOX_NPC
	end

Route30_EventScript_SignRoute30::
	msgbox Route30_Text_SignRoute30, MSGBOX_SIGN
	end

Route30_EventScript_SignTrainerTips::
	msgbox Route30_Text_SignTrainerTips, MSGBOX_SIGN
	end

Route30_EventScript_SignMrPokemon::
	msgbox Route30_Text_SignMrPokemon, MSGBOX_SIGN
	end

Route30_Text_LittleBoy:
	.string "I ran into a researcher heading\n"
	.string "to MR. POKEMON'S house.$"

Route30_Text_Youngster:
	.string "The grass here is great for\n"
	.string "training early teams.$"

Route30_Text_BugCatcher:
	.string "Bugs love the trees on ROUTE 30.\n"
	.string "I'm always looking around.$"

Route30_Text_SignRoute30:
	.string "ROUTE 30\n"
	.string "CHERRYGROVE CITY - VIOLET CITY$"

Route30_Text_SignTrainerTips:
	.string "TRAINER TIPS\n"
	.string "BERRIES heal POKéMON on the go.$"

Route30_Text_SignMrPokemon:
	.string "MR. POKEMON'S HOUSE$"
