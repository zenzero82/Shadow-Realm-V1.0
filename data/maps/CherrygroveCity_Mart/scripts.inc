CherrygroveCity_Mart_MapScripts::
	.byte 0

CherrygroveCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CherrygroveCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CherrygroveCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

CherrygroveCity_Mart_EventScript_Youngster::
	faceplayer
	msgbox CherrygroveCity_Mart_Text_Youngster, MSGBOX_NPC
	end

CherrygroveCity_Mart_EventScript_BugCatcher::
	faceplayer
	msgbox CherrygroveCity_Mart_Text_BugCatcher, MSGBOX_NPC
	end

CherrygroveCity_Mart_Text_Youngster:
	.string "I stock up before heading north.\n"
	.string "The routes are busy lately.$"

CherrygroveCity_Mart_Text_BugCatcher:
	.string "They finally have GREAT BALLS here.\n"
	.string "That makes a big difference.$"
