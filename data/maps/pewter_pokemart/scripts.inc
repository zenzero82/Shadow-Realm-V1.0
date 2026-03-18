pewter_pokemart_MapScripts::
	.byte 0

pewter_pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart pewter_pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
pewter_pokemart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

pewter_pokemart_Speaker_Lass:
	.string "KARA$"

pewter_pokemart_Speaker_Youngster:
	.string "JOSH$"

pewter_pokemart_EventScript_Lass::
	lock
	faceplayer
	setspeaker pewter_pokemart_Speaker_Lass
	msgbox pewter_pokemart_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_POKEMART_LASS
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_pokemart_EventScript_Youngster::
	lock
	faceplayer
	setspeaker pewter_pokemart_Speaker_Youngster
	msgbox pewter_pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_POKEMART_YOUNGSTER
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_pokemart_Text_Lass:
	.string "Pewter stays pretty calm.\n"
	.string "Even with the rumors, people\l"
	.string "still say hello.$"

pewter_pokemart_Text_Youngster:
	.string "I'm saving for REPELS.$"
