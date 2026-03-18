AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_Speaker_Clerk:
	.string "CLERK$"

AzaleaTown_Mart_Speaker_Rocker:
	.string "JAX$"

AzaleaTown_Mart_Speaker_BugCatcher:
	.string "CAL$"

AzaleaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	setspeaker AzaleaTown_Mart_Speaker_Clerk
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
	setspeaker AzaleaTown_Mart_Speaker_Rocker
	msgbox AzaleaTown_Mart_Text_Rocker, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_MART_ROCKER
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_Mart_EventScript_BugCatcher::
	faceplayer
	setspeaker AzaleaTown_Mart_Speaker_BugCatcher
	msgbox AzaleaTown_Mart_Text_BugCatcher, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_MART_BUG_CATCHER
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_Mart_Text_Rocker:
	.string "Supplies are back in. Even REPELS\n"
	.string "are moving fast.$"

AzaleaTown_Mart_Text_BugCatcher:
	.string "GREAT BALLS help with the bugs in\n"
	.string "ILEX FOREST.$"
