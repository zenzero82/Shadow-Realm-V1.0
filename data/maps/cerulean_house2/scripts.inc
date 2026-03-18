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
	setspeaker cerulean_house2_Speaker_OldWoman
	msgbox cerulean_house2_Text_OldWoman, MSGBOX_NPC
	setflag FLAG_QUEST_CERULEAN_NPC_HOUSE2_OLD_WOMAN
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	end

cerulean_house2_Text_OldMan:
	.string "CERULEAN's a peaceful place, but\n"
	.string "there's always someone passing\l"
	.string "through with a story.$"

cerulean_house2_Text_OldWoman:
	.string "I keep a cup of tea ready in case\n"
	.string "a traveler needs a rest.$"
