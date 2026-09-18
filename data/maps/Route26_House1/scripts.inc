Route26_House1_MapScripts::
	.byte 0

Route26_House1_Speaker_Woman:
	.string "HOSTESS$"

Route26_House1_EventScript_Woman::
	lock
	faceplayer
	setspeaker Route26_House1_Speaker_Woman
	checkflag FLAG_RECEIVED_ROUTE26_HOUSE1_MAX_REVIVE
	goto_if_set FLAG_RECEIVED_ROUTE26_HOUSE1_MAX_REVIVE, Route26_House1_EventScript_Woman_AfterGift
	msgbox Route26_House1_Text_Woman_Intro, MSGBOX_DEFAULT
	giveitem ITEM_MAX_REVIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_ROUTE26_HOUSE1_MAX_REVIVE
	msgbox Route26_House1_Text_Woman_GiveGift, MSGBOX_DEFAULT
	release
	end

Route26_House1_EventScript_Woman_AfterGift::
	msgbox Route26_House1_Text_Woman_AfterGift, MSGBOX_DEFAULT
	release
	end

Route26_House1_Text_Woman_Intro:
	.string "Trainers crossing ROUTE 26 always look\n"
	.string "like they've had a hard climb.\p"
	.string "Keep this with you. It can turn a bad\n"
	.string "moment back around.$"

Route26_House1_Text_Woman_GiveGift:
	.string "A MAX REVIVE is too valuable to waste,\n"
	.string "but the right trainer knows when to use\l"
	.string "it.$"

Route26_House1_Text_Woman_AfterGift:
	.string "The road ahead tests every trainer.\p"
	.string "Save that MAX REVIVE for when it truly\n"
	.string "matters.$"
