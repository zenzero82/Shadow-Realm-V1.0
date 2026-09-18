cerulean_house2_MapScripts::
	.byte 0

cerulean_house2_Speaker_OldMan:
	.string "HENRY$"

cerulean_house2_Speaker_OldWoman:
	.string "EDNA$"

cerulean_house2_EventScript_OldMan::
	setspeaker cerulean_house2_Speaker_OldMan
	msgbox cerulean_house2_Text_OldMan, MSGBOX_NPC
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE2_OLD_MAN
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	end

cerulean_house2_EventScript_OldWoman::
	lock
	faceplayer
	setspeaker cerulean_house2_Speaker_OldWoman
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE2_OLD_WOMAN
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	goto_if_set FLAG_CERULEAN_HOUSE2_REPELS_GIVEN, cerulean_house2_EventScript_OldWoman_Repeat
	msgbox cerulean_house2_Text_OldWoman_GiveItem, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_REPEL, 2
	goto_if_eq VAR_RESULT, FALSE, cerulean_house2_EventScript_OldWoman_BagFull
	setflag FLAG_CERULEAN_HOUSE2_REPELS_GIVEN
	msgbox cerulean_house2_Text_OldWoman_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house2_EventScript_OldWoman_Repeat::
	msgbox cerulean_house2_Text_OldWoman_Repeat, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house2_EventScript_OldWoman_BagFull::
	msgbox cerulean_house2_Text_OldWoman_BagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house2_Text_OldMan:
	.string "CERULEAN's a peaceful place, but\n"
	.string "there's always someone passing\l"
	.string "through with a story.$"

cerulean_house2_Text_OldWoman_GiveItem:
	.string "Travelers keep complaining about\n"
	.string "wild POKeMON swarming the trails.\p"
	.string "Take these REPELS before you head\n"
	.string "toward the CAPE or the cave roads.$"

cerulean_house2_Text_OldWoman_AfterItem:
	.string "A quiet walk is easier when the wild\n"
	.string "POKeMON leave you be.$"

cerulean_house2_Text_OldWoman_Repeat:
	.string "Use those REPELS when the path gets\n"
	.string "too noisy.$"

cerulean_house2_Text_OldWoman_BagFull:
	.string "Your BAG is already full.\p"
	.string "Make some room and I'll set those\n"
	.string "REPELS aside for you.$"
