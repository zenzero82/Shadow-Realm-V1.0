cerulean_pokemart_MapScripts::
	.byte 0

cerulean_pokemart_Speaker_BattleGirl:
	.string "NINA$"

cerulean_pokemart_Speaker_Juggler:
	.string "DEVON$"

cerulean_pokemart_EventScript_BattleGirl::
	lock
	faceplayer
	setspeaker cerulean_pokemart_Speaker_BattleGirl
	msgbox cerulean_pokemart_Text_BattleGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_pokemart_EventScript_Juggler::
	lock
	faceplayer
	setspeaker cerulean_pokemart_Speaker_Juggler
	msgbox cerulean_pokemart_Text_Juggler, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_pokemart_Text_BattleGirl:
	.string "I'm stocking up on HEALING items.\n"
	.string "The streets feel tense today.$"

cerulean_pokemart_Text_Juggler:
	.string "The clerk says the supply truck was\n"
	.string "delayed by a police checkpoint.$"
