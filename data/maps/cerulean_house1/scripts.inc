cerulean_house1_MapScripts::
	.byte 0

cerulean_house1_Speaker_BaldingMan:
	.string "MILES$"

cerulean_house1_Speaker_Woman:
	.string "SARA$"

cerulean_house1_EventScript_BaldingMan::
	lock
	faceplayer
	setspeaker cerulean_house1_Speaker_BaldingMan
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE1_BALDING
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	goto_if_set FLAG_CERULEAN_HOUSE1_GREAT_BALLS_GIVEN, cerulean_house1_EventScript_BaldingMan_Repeat
	msgbox cerulean_house1_Text_BaldingMan_GiveItem, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_GREAT_BALL, 3
	goto_if_eq VAR_RESULT, FALSE, cerulean_house1_EventScript_BaldingMan_BagFull
	setflag FLAG_CERULEAN_HOUSE1_GREAT_BALLS_GIVEN
	msgbox cerulean_house1_Text_BaldingMan_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house1_EventScript_BaldingMan_Repeat::
	msgbox cerulean_house1_Text_BaldingMan_Repeat, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house1_EventScript_BaldingMan_BagFull::
	msgbox cerulean_house1_Text_BaldingMan_BagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house1_EventScript_Woman::
	lock
	faceplayer
	setspeaker cerulean_house1_Speaker_Woman
	msgbox cerulean_house1_Text_Woman, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE1_WOMAN
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	release
	end

cerulean_house1_EventScript_Spearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	waitmoncry
	release
	end

cerulean_house1_EventScript_Minccino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MINCCINO, CRY_MODE_NORMAL
	waitmoncry
	release
	end

cerulean_house1_EventScript_Bookshelf::
	msgbox cerulean_house1_Text_Bookshelf, MSGBOX_SIGN
	end

cerulean_house1_EventScript_TV::
	msgbox cerulean_house1_Text_TV, MSGBOX_SIGN
	end

cerulean_house1_Text_BaldingMan_GiveItem:
	.string "I heard the police sealed off the\n"
	.string "CAVE route. It must be serious.\p"
	.string "If you're still heading out, take\n"
	.string "these GREAT BALLS with you.$"

cerulean_house1_Text_BaldingMan_AfterItem:
	.string "The CAPE and ROUTE 9 have been full\n"
	.string "of rumors lately.\p"
	.string "Better to be ready if a strong wild\n"
	.string "POKeMON shows up.$"

cerulean_house1_Text_BaldingMan_Repeat:
	.string "Keep those GREAT BALLS handy.\p"
	.string "CERULEAN's too tense to travel\n"
	.string "unprepared.$"

cerulean_house1_Text_BaldingMan_BagFull:
	.string "Your BAG is packed tight.\p"
	.string "Make some space and I'll hand over\n"
	.string "those GREAT BALLS.$"

cerulean_house1_Text_Woman:
	.string "We keep our POKeMON close at night.\n"
	.string "Too many break-ins lately.$"

cerulean_house1_Text_Bookshelf:
	.string "A stack of home magazines.\p"
	.string "One page is folded over on keeping\n"
	.string "travel supplies near the door.$"

cerulean_house1_Text_TV:
	.string "A news bulletin is covering police\n"
	.string "activity around CERULEAN.$"
