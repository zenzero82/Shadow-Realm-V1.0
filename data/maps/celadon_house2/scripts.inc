celadon_house2_MapScripts::
	.byte 0

celadon_house2_Speaker_Gentleman:
	.string "REGINALD$"

celadon_house2_EventScript_Gentleman::
	lock
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_HOUSE2_GENTLEMAN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker celadon_house2_Speaker_Gentleman
	checkflag FLAG_CELADON_HOUSE2_GIFT_GIVEN
	goto_if_set FLAG_CELADON_HOUSE2_GIFT_GIVEN, celadon_house2_EventScript_Gentleman_AfterGift
	msgbox celadon_house2_Text_Gentleman_Intro, MSGBOX_DEFAULT
	giveitem ITEM_FULL_RESTORE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_CELADON_HOUSE2_GIFT_GIVEN
	msgbox celadon_house2_Text_Gentleman_GiveGift, MSGBOX_DEFAULT
	release
	end

celadon_house2_EventScript_Gentleman_AfterGift::
	msgbox celadon_house2_Text_Gentleman_AfterGift, MSGBOX_DEFAULT
	release
	end

celadon_house2_EventScript_Bookshelf::
	msgbox celadon_house2_Text_Bookshelf, MSGBOX_SIGN
	end

celadon_house2_EventScript_TV::
	msgbox celadon_house2_Text_TV, MSGBOX_SIGN
	end

celadon_house2_Text_Gentleman_Intro:
	.string "CELADON trainers come and go all day.\p"
	.string "If you're aiming for the GYM or the\n"
	.string "road beyond it, you'll want something\l"
	.string "reliable in reserve.$"

celadon_house2_Text_Gentleman_GiveGift:
	.string "Take this FULL RESTORE.\p"
	.string "A proper trainer knows that staying\n"
	.string "calm and recovering at the right moment\l"
	.string "wins matches.$"

celadon_house2_Text_Gentleman_AfterGift:
	.string "That FULL RESTORE could save a battle\n"
	.string "once the pressure starts building.$"

celadon_house2_Text_Bookshelf:
	.string "A shelf of gardening books.\p"
	.string "Several chapters are marked on caring\n"
	.string "for rare flowers.$"

celadon_house2_Text_TV:
	.string "A travel program is featuring the\n"
	.string "CELADON DEPT. STORE rooftop view.$"
