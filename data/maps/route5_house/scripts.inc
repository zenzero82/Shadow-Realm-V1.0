route5_house_MapScripts::
	.byte 0

route5_house_Speaker_OldWoman:
	.string "OLD WOMAN$"

route5_house_EventScript_OldWoman::
	lock
	faceplayer
	setspeaker route5_house_Speaker_OldWoman
	checkflag FLAG_RECEIVED_ROUTE5_HOUSE_CLEANSE_TAG
	goto_if_set FLAG_RECEIVED_ROUTE5_HOUSE_CLEANSE_TAG, route5_house_EventScript_OldWoman_AfterGift
	msgbox route5_house_Text_OldWoman_GiveItem, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, route5_house_EventScript_OldWoman_BagFull
	setflag FLAG_RECEIVED_ROUTE5_HOUSE_CLEANSE_TAG
	msgbox route5_house_Text_OldWoman_AfterItem, MSGBOX_DEFAULT
	release
	end

route5_house_EventScript_OldWoman_BagFull::
	msgbox route5_house_Text_OldWoman_BagFull, MSGBOX_DEFAULT
	release
	end

route5_house_EventScript_OldWoman_AfterGift::
	msgbox route5_house_Text_OldWoman_Repeat, MSGBOX_DEFAULT
	release
	end

route5_house_Text_OldWoman_GiveItem:
	.string "The city road is noisy, but wild\n"
	.string "POKéMON still wander near here.\p"
	.string "Take this CLEANSE TAG.\n"
	.string "If your lead partner holds it,\l"
	.string "you'll draw less unwanted trouble.$"

route5_house_Text_OldWoman_AfterItem:
	.string "A calm heart keeps wild POKéMON at\n"
	.string "a respectful distance.\p"
	.string "That CLEANSE TAG helps with the rest.$"

route5_house_Text_OldWoman_BagFull:
	.string "Your BAG is too full right now.\p"
	.string "Make some room and I'll hand over\n"
	.string "the CLEANSE TAG.$"

route5_house_Text_OldWoman_Repeat:
	.string "Let the lead POKéMON hold that\n"
	.string "CLEANSE TAG if you want a quieter walk.$"
