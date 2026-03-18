VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_Speaker_Clerk:
	.string "CLERK$"

VioletCity_Mart_Speaker_OldWoman:
	.string "EDNA$"

VioletCity_Mart_Speaker_Rocker:
	.string "JAX$"

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	setspeaker VioletCity_Mart_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart VioletCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VioletCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

VioletCity_Mart_EventScript_OldWoman::
	faceplayer
	setspeaker VioletCity_Mart_Speaker_OldWoman
	msgbox VioletCity_Mart_Text_OldWoman, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_MART_OLD_WOMAN
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_Mart_EventScript_Rocker::
	faceplayer
	setspeaker VioletCity_Mart_Speaker_Rocker
	msgbox VioletCity_Mart_Text_Rocker, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_MART_ROCKER
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_Mart_Text_OldWoman:
	.string "I keep POTIONS handy. You never\n"
	.string "know when a battle pops up.$"

VioletCity_Mart_Text_Rocker:
	.string "The gym crowd keeps this place\n"
	.string "busy all day.$"
