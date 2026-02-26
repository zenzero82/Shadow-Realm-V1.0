AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart AzaleaTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
AzaleaTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

AzaleaTown_Mart_EventScript_Rocker::
	faceplayer
	msgbox AzaleaTown_Mart_Text_Rocker, MSGBOX_NPC
	end

AzaleaTown_Mart_EventScript_BugCatcher::
	faceplayer
	msgbox AzaleaTown_Mart_Text_BugCatcher, MSGBOX_NPC
	end

AzaleaTown_Mart_Text_Rocker:
	.string "Supplies are back in. Even REPELS\n"
	.string "are moving fast.$"

AzaleaTown_Mart_Text_BugCatcher:
	.string "GREAT BALLS help with the bugs in\n"
	.string "ILEX FOREST.$"
