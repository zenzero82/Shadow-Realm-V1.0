WesHideout_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, WesHideout_Entrance_OnLoad
	.byte 0

#define LOCALID_WES 1
#define LOCALID_UMBREON 2
#define LOCALID_ESPEON 3

WesHideout_Entrance_OnLoad::
	checkflag FLAG_QUEST_BACK_TO_HQ_STARTED
	goto_if_eq WesHideout_Entrance_OnLoad_HideWes
	end

WesHideout_Entrance_OnLoad_HideWes::
	setvar VAR_TEMP_0, 1
	hideobjectat LOCALID_WES, MAP_WES_HIDEOUT_ENTRANCE
	hideobjectat LOCALID_UMBREON, MAP_WES_HIDEOUT_ENTRANCE
	hideobjectat LOCALID_ESPEON, MAP_WES_HIDEOUT_ENTRANCE
	end

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

WesHideout_Entrance_Speaker_Wes:
	.string "WES$"

WesHideout_Entrance_EventScript_Nop::
	end

@ =========================================================
@ WES
@ =========================================================

WesHideout_Entrance_EventScript_Wes::
	lock
	faceplayer
	call WesHideout_Entrance_EventScript_Wes_Talk
	release
	end

WesHideout_Entrance_EventScript_Wes_Talk::
	setspeaker WesHideout_Entrance_Speaker_Wes
WesHideout_Entrance_EventScript_Wes_Talk_QuestSkip:
	checkflag FLAG_ROUTE_24_ZANDER_DEFEATED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Talk_ZanderCheck
	goto WesHideout_Entrance_EventScript_Wes_Talk_ZanderDone
WesHideout_Entrance_EventScript_Wes_Talk_ZanderCheck:
	checkflag FLAG_WES_ZANDER_REPORT_DONE
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Talk_ZanderDone
	setflag FLAG_WES_ZANDER_REPORT_DONE
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Zander_Report, MSGBOX_DEFAULT
	closemessage
	return
WesHideout_Entrance_EventScript_Wes_Talk_ZanderDone:
	checkflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Briefed
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Intro, MSGBOX_DEFAULT
	closemessage
	call WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro
	return

WesHideout_Entrance_EventScript_Wes_Briefed::
	checkflag FLAG_RECEIVED_SNAG_MACHINE
	goto_if_eq WesHideout_Entrance_EventScript_Wes_AfterGift
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Gift_Part1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SNAG_MACHINE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	playse SE_USE_ITEM
	waitse
	setflag FLAG_HAS_SNAG_MACHINE
	setflag FLAG_RECEIVED_SNAG_MACHINE
	setflag FLAG_HIDE_CERULEAN_MISTY
	setflag FLAG_HIDE_ROUTE_25_MICHAEL
	setflag FLAG_HIDE_ROUTE_25_SYLVEON
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Gift_Part2, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_SNAG_MACHINE_COMPLETED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestDone
	goto WesHideout_Entrance_EventScript_Wes_SnagQuestComplete
WesHideout_Entrance_EventScript_Wes_SnagQuestComplete:
	checkflag FLAG_QUEST_SNAG_MACHINE_STARTED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestComplete_HasStart
	setflag FLAG_QUEST_SNAG_MACHINE_STARTED
WesHideout_Entrance_EventScript_Wes_SnagQuestComplete_HasStart:
	setflag FLAG_QUEST_SNAG_MACHINE_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
	setvar VAR_TEMP_1, 0
	checkflag FLAG_QUEST_DEFEAT_MISTY_STARTED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestCheckShadow
	setflag FLAG_QUEST_DEFEAT_MISTY_STARTED
	addvar VAR_TEMP_1, 1
WesHideout_Entrance_EventScript_Wes_SnagQuestCheckShadow:
	checkflag FLAG_QUEST_SHADOW_TRAINER_STARTED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestAlert
	setflag FLAG_QUEST_SHADOW_TRAINER_STARTED
	addvar VAR_TEMP_1, 1
WesHideout_Entrance_EventScript_Wes_SnagQuestAlert:
	compare VAR_TEMP_1, 0
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestDone
	compare VAR_TEMP_1, 1
	goto_if_eq WesHideout_Entrance_EventScript_Wes_SnagQuestOneNew
	call QuestJournal_EventScript_NewQuestsAlert
	goto WesHideout_Entrance_EventScript_Wes_SnagQuestDone
WesHideout_Entrance_EventScript_Wes_SnagQuestOneNew:
	call QuestJournal_EventScript_NewQuestAlert
	goto WesHideout_Entrance_EventScript_Wes_SnagQuestDone
WesHideout_Entrance_EventScript_Wes_SnagQuestDone:
	return

WesHideout_Entrance_EventScript_Wes_AfterGift::
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_AfterGift, MSGBOX_DEFAULT
	closemessage
	return

WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro:
	checkflag FLAG_QUEST_TALK_WES_COMPLETED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Done
	checkflag FLAG_QUEST_TALK_WES_STARTED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Do
	goto WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Done
WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Do:
	setflag FLAG_QUEST_TALK_WES_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
	checkflag FLAG_QUEST_TALK_TEAM_STARTED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Done
	setflag FLAG_QUEST_TALK_TEAM_STARTED
	call QuestJournal_EventScript_NewQuestAlert
WesHideout_Entrance_EventScript_Wes_Talk_QuestCompleteAfterIntro_Done:
	return

@ =========================================================
@ WES TRIGGERS
@ =========================================================

WesHideout_Entrance_EventScript_WesTrigger_0::
	lockall
	checkflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	goto_if_eq WesHideout_Entrance_EventScript_WesTrigger_Done
	setflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, WesHideout_Entrance_Movement_PlayerToWes_FromLeft
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

WesHideout_Entrance_EventScript_WesTrigger_1::
	lockall
	checkflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	goto_if_eq WesHideout_Entrance_EventScript_WesTrigger_Done
	setflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	setvar VAR_TEMP_0, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

WesHideout_Entrance_EventScript_WesTrigger_2::
	lockall
	checkflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	goto_if_eq WesHideout_Entrance_EventScript_WesTrigger_Done
	setflag FLAG_WES_HIDEOUT_WES_TRIGGERED
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, WesHideout_Entrance_Movement_PlayerToWes_FromRight
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

WesHideout_Entrance_EventScript_WesTrigger_Done::
	releaseall
	end

@ =========================================================
@ MOVEMENTS
@ =========================================================

WesHideout_Entrance_Movement_PlayerToWes_FromLeft:
	walk_up
	walk_right
	step_end

WesHideout_Entrance_Movement_PlayerToWes_FromRight:
	walk_up
	walk_left
	step_end

@ =========================================================
@ TEXT
@ =========================================================

WesHideout_Entrance_Text_Wes_Intro:
	.string "Ah you made it! Seems like you were\n"
	.string "able to best BROCK after all.\p"
	.string "Maybe TURO was right...\p"
	.string "Don't mind me just thinking out loud.\n"
	.string "Anyway, now that you're here you can\l"
	.string "get a proper explanation of what's\l"
	.string "going on.\p"
	.string "We made a base here for research\n"
	.string "purposes. Go downstairs and talk to\l"
	.string "the team. They can give you some\l"
	.string "insight. Then come back and see me\l"
	.string "before you leave.$"

WesHideout_Entrance_Text_Wes_Gift_Part1:
	.string "Now that the team was able to give\n"
	.string "you some insight, you have a better\l"
	.string "understanding of what we're up\l"
	.string "against.\p"
	.string "I want to give you something. I have\n"
	.string "this SNAG MACHINE that I stole from\l"
	.string "TEAM SNAGEM before the explosion.\l"
	.string "I want you to have it.$"

WesHideout_Entrance_Text_Wes_Gift_Part2:
	.string "With that device you can snag\n"
	.string "trainers' POKéMON, if they are\l"
	.string "Shadow's... We are not thieves so we\l"
	.string "only take them away so we can purify\l"
	.string "them.\p"
	.string "I have a friend over in JOHTO who is\n"
	.string "currently modifying POKé BALLS that\l"
	.string "CIPHER has been using for their\l"
	.string "conversion process. They have a\l"
	.string "better catch rate for Shadow's and\l"
	.string "once they are purified, the effects\l"
	.string "will be removed and they will function\l"
	.string "like a normal POKé BALL would.\p"
	.string "Now your first assignment, there has\n"
	.string "been a trainer spotted near the water\l"
	.string "just before the POWER PLANT on\l"
	.string "ROUTE 10. Find him and see if he has\l"
	.string "a {COLOR PURPLE}Shadow POKéMON{COLOR DARK_GRAY}. Our reports say he\l"
	.string "does.$"

WesHideout_Entrance_Text_Wes_AfterGift:
	.string "Head to ROUTE 10 and find that\n"
	.string "trainer. Be ready to snag if you\l"
	.string "see a {COLOR PURPLE}Shadow POKéMON{COLOR DARK_GRAY}.$"

WesHideout_Entrance_Text_Wes_Zander_Report:
	.string "Right on! Looks like you were able to\n"
	.string "find and defeat a member of TEAM\n"
	.string "ROCKET. We will keep collecting info\n"
	.string "here at HQ. Keep exploring until we\n"
	.string "contact you.$"
