Route22_MapScripts::
	.byte 0

Route22_Speaker_Rowan:
	.string "ROWAN$"

Route22_EventScript_RowanStarterTheftTrigger::
	lockall
	checkflag FLAG_OAKS_LAB_STARTERS_STOLEN
	goto_if_eq Route22_EventScript_RowanStarterTheftTrigger_Done
	setvar VAR_TEMP_0, 1
	setspeaker Route22_Speaker_Rowan
	pokenavcall Route22_Text_RowanStarterTheftCall
	waitmessage
	setflag FLAG_OAKS_LAB_STARTERS_STOLEN
	setflag FLAG_HIDE_OAKS_LAB_RALTSBALL
	setflag FLAG_HIDE_OAKS_LAB_HONEDGEBALL
	setflag FLAG_HIDE_OAKS_LAB_ZORUABALL
	checkflag FLAG_QUEST_STARTERS_STOLEN_STARTED
	goto_if_eq Route22_EventScript_RowanStarterTheftTrigger_Done
	setflag FLAG_QUEST_STARTERS_STOLEN_STARTED
	call QuestJournal_EventScript_NewQuestAlert
Route22_EventScript_RowanStarterTheftTrigger_Done::
	releaseall
	end

Route22_EventScript_Sign::
	msgbox Route22_Text_VictoryRoadEntranceSign, MSGBOX_NPC
	end

Route22_Text_RowanStarterTheftCall:
	.string "Emergency! The two POKeMON left\n"
	.string "behind in OAK'S LAB have been\l"
	.string "stolen!\p"
	.string "I need you to stop by PALLET TOWN\n"
	.string "at once and see what happened.\p"
	.string "Leo and Nia should have more\n"
	.string "information for you.$"

Route22_Text_VictoryRoadEntranceSign:
	.string "POKéMON LEAGUE\p"
	.string "VICTORY ROAD ENTRANCE$"
