mtmoon_shop_MapScripts::
	.byte 0

MtMoon_Shop_MapScripts::
	.byte 0

MtMoon_Shop_Speaker_Clyde:
	.string "Clyde$"

MtMoon_Shop_Speaker_Mira:
	.string "Mira$"

MtMoon_Shop_EventScript_Lass::
	setspeaker MtMoon_Shop_Speaker_Mira
	msgbox MtMoon_Shop_Text_GiftShopLass, MSGBOX_NPC
	setflag FLAG_QUEST_MT_MOON_NPC_LASS
	call QuestJournal_EventScript_CheckMtMoonNPCs
	end

MtMoon_Shop_EventScript_Clerk::
	lock
	faceplayer
	setspeaker MtMoon_Shop_Speaker_Clyde
	message gText_HowMayIServeYou
	waitmessage
	pokemart MtMoon_Shop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	setflag FLAG_QUEST_MT_MOON_NPC_CLERK
	call QuestJournal_EventScript_CheckMtMoonNPCs
	release
	end

	.align 2
MtMoon_Shop_Pokemart:
	.2byte ITEM_MOON_STONE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

MtMoon_Shop_Text_GiftShopLass:
	.string "When the sun goes down, CLEFAIRY\n"
	.string "come out to play.$"
