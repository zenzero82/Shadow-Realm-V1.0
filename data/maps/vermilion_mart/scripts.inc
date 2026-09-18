vermilion_mart_MapScripts::
	.byte 0

vermilion_mart_Speaker_Clerk:
	.string "Clerk Mina$"

vermilion_mart_Speaker_Rocker:
	.string "VINCE$"

vermilion_mart_Speaker_Lass:
	.string "KELLY$"

vermilion_mart_EventScript_Clerk::
	lock
	faceplayer
	setspeaker vermilion_mart_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart vermilion_mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

vermilion_mart_EventScript_Rocker::
	lock
	faceplayer
	setspeaker vermilion_mart_Speaker_Rocker
	msgbox vermilion_mart_Text_Rocker, MSGBOX_NPC
	release
	end

vermilion_mart_EventScript_Lass::
	lock
	faceplayer
	setspeaker vermilion_mart_Speaker_Lass
	msgbox vermilion_mart_Text_Lass, MSGBOX_NPC
	release
	end

	.align 2
vermilion_mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

vermilion_mart_Text_Rocker:
	.string "If you're heading out toward ROUTE 11,\n"
	.string "bring extra supplies.\p"
	.string "That stretch always wears me down.$"

vermilion_mart_Text_Lass:
	.string "VERMILION always feels busy, so I like\n"
	.string "shopping early.\p"
	.string "Less waiting, more training.$"
