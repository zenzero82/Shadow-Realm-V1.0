pewter_house2_MapScripts::
	.byte 0

pewter_house2_Speaker_Gordon:
	.string "Gordon$"

pewter_house2_EventScript_OldMan::
	lock
	faceplayer
	setspeaker pewter_house2_Speaker_Gordon
	msgbox pewter_house2_Text_OldMan, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_HOUSE2_OLD_MAN
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_house2_Text_OldMan:
	.string "My daughter Tess is obsessed with\n"
	.string "those GIMMIGHOUL COINS.\p"
	.string "If she spots even one glittering on a\n"
	.string "signpost, she'll talk about it for\l"
	.string "hours.\p"
	.string "Can't blame her, though.\n"
	.string "Anything that strange is worth\l"
	.string "paying attention to.$"
