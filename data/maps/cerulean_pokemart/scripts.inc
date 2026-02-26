cerulean_pokemart_MapScripts::
	.byte 0

cerulean_pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart cerulean_pokemart_Pokemart_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
cerulean_pokemart_Pokemart_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	pokemartlistend

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
