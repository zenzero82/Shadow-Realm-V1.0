pewter_house1_MapScripts::
	.byte 0

pewter_house1_Speaker_Tim:
	.string "Tim$"

pewter_house1_EventScript_Boy::
	lock
	faceplayer
	setspeaker pewter_house1_Speaker_Tim
	dotimebasedevents
	goto_if_set FLAG_DAILY_PEWTER_CRUNCHIES, pewter_house1_EventScript_Boy_AlreadyReceivedToday
	goto_if_set FLAG_QUEST_PEWTER_NPC_HOUSE1_BOY, pewter_house1_EventScript_Boy_GiveDailyCrunchies
	msgbox pewter_house1_Text_Boy_FirstTime, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PEWTER_CRUNCHIES
	goto_if_eq VAR_RESULT, FALSE, pewter_house1_EventScript_Boy_BagFull
	setflag FLAG_DAILY_PEWTER_CRUNCHIES
	setflag FLAG_QUEST_PEWTER_NPC_HOUSE1_BOY
	call QuestJournal_EventScript_CheckPewterCityNPCs
	msgbox pewter_house1_Text_Boy_ReceivedCrunchies, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house1_EventScript_Boy_GiveDailyCrunchies:
	msgbox pewter_house1_Text_Boy_DailyOffer, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PEWTER_CRUNCHIES
	goto_if_eq VAR_RESULT, FALSE, pewter_house1_EventScript_Boy_BagFull
	setflag FLAG_DAILY_PEWTER_CRUNCHIES
	msgbox pewter_house1_Text_Boy_ReceivedCrunchies, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house1_EventScript_Boy_AlreadyReceivedToday:
	msgbox pewter_house1_Text_Boy_AlreadyReceivedToday, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house1_EventScript_Boy_BagFull:
	msgbox pewter_house1_Text_Boy_BagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house1_Text_Boy_FirstTime:
	.string "Dad brings home PEWTER CRUNCHIES\n"
	.string "every day from the shop.\p"
	.string "Here, take a fresh bag before you\n"
	.string "head out. They're great on hikes!$"

pewter_house1_Text_Boy_DailyOffer:
	.string "Fresh PEWTER CRUNCHIES came in!\p"
	.string "Take a bag for the road.$"

pewter_house1_Text_Boy_ReceivedCrunchies:
	.string "Nothing beats a bag of PEWTER\n"
	.string "CRUNCHIES after a tough walk.$"

pewter_house1_Text_Boy_AlreadyReceivedToday:
	.string "That's all the extra CRUNCHIES I\n"
	.string "can spare today.\p"
	.string "Come back tomorrow for another bag.$"

pewter_house1_Text_Boy_BagFull:
	.string "Your BAG's stuffed.\p"
	.string "Make room and I'll save you a bag of\n"
	.string "PEWTER CRUNCHIES.$"
