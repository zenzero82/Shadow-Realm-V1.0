Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_EventScript_SetZanderVisibility
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route10_MapScripts_OnFrame
	.byte 0

Route10_MapScripts_OnFrame:
	map_script_2 VAR_TEMP_0, 1, Route10_EventScript_PlasmaGrunt_Auto
	.2byte 0

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_SetZanderVisibility::
	setvar VAR_TEMP_0, 0
	checkflag FLAG_ROUTE_24_ZANDER_DEFEATED
	goto_if_eq Route10_EventScript_SetZanderVisibility_Done
	checkflag FLAG_HAS_SNAG_MACHINE
	goto_if_eq Route10_EventScript_ShowZander
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_ShowZander::
	clearflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_SetZanderVisibility_Done::
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_TryPlasmaExit::
	checkflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	goto_if_eq Route10_EventScript_TryPlasmaExit_Done
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	goto_if_ne VAR_TEMP_1, 16, Route10_EventScript_TryPlasmaExit_Done
	goto_if_ne VAR_TEMP_2, 57, Route10_EventScript_TryPlasmaExit_Done
	setvar VAR_TEMP_0, 1
Route10_EventScript_TryPlasmaExit_Done::
	return

Route10_EventScript_PlasmaGrunt::
	lock
	faceplayer
	setspeaker Route10_Speaker_PlasmaGrunt
	msgbox Route10_Text_PlasmaGrunt_Exit, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	goto_if_eq Route10_EventScript_PlasmaGrunt_CompleteQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_PlasmaGrunt_CompleteQuest_Done:
	applymovement LOCALID_PLAYER, Route10_Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_ROUTE10_PLASMA_GRUNT, Route10_Movement_PlasmaEnterCave
	waitmovement 0
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	release
	end

Route10_EventScript_PlasmaGrunt_Auto::
	setvar VAR_TEMP_0, 0
	lockall
	faceplayer
	setspeaker Route10_Speaker_PlasmaGrunt
	msgbox Route10_Text_PlasmaGrunt_Exit, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	goto_if_eq Route10_EventScript_PlasmaGrunt_Auto_CompleteQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_PlasmaGrunt_Auto_CompleteQuest_Done:
	applymovement LOCALID_PLAYER, Route10_Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_ROUTE10_PLASMA_GRUNT, Route10_Movement_PlasmaEnterCave
	waitmovement 0
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	releaseall
	end

Route10_Speaker_Zander:
	.string "Zander$"

Route10_EventScript_Zander::
	checkflag FLAG_HIDE_ROUTE_24_ZANDER
	goto_if_eq Route10_EventScript_Zander_Done

	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker Route10_Speaker_Zander
	msgbox Route10_Text_Zander_Intro, MSGBOX_DEFAULT
	closemessage

	trainerbattle_no_intro TRAINER_ROCKET_GRUNT_M_1, Route10_Text_Zander_Defeated
	goto Route10_EventScript_Zander_AfterBattle

Route10_EventScript_Zander_AfterBattle::
	msgbox Route10_Text_Zander_PostBattle, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_STARTED
	goto_if_eq Route10_EventScript_Zander_StartPlasmaQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_STARTED
	call QuestJournal_EventScript_NewQuestAlert
Route10_EventScript_Zander_StartPlasmaQuest_Done:
	setflag FLAG_ROUTE_24_ZANDER_DEFEATED
	checkflag FLAG_QUEST_SHADOW_TRAINER_COMPLETED
	goto_if_eq Route10_EventScript_Zander_QuestDone
	checkflag FLAG_QUEST_SHADOW_TRAINER_STARTED
	goto_if_eq Route10_EventScript_Zander_QuestComplete
	goto Route10_EventScript_Zander_QuestDone
Route10_EventScript_Zander_QuestComplete:
	setflag FLAG_QUEST_SHADOW_TRAINER_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_Zander_QuestDone:
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	fadescreenswapbuffers FADE_TO_BLACK
	hideobjectat LOCALID_ROUTE10_ZANDER, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_ZANDER
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

Route10_EventScript_Zander_Done::
	end

Route10_Movement_PlayerStepLeft:
	walk_left
	step_end

Route10_Movement_PlasmaEnterCave:
	walk_up
	walk_up
	step_end

Route10_Speaker_PlasmaGrunt:
	.string "FAYE$"

Route10_Text_PlasmaGrunt_Exit:
	.string "Out of my way! I need to let the\n"
	.string "others know a really strong trainer\l"
	.string "is about to crush us!\p"
	.string "...Wait, you already defeated them?\p"
	.string "...This is so sad...\n"
	.string "Now I have to tell the Sages.\p"
	.string "MOVE!$"

@ ======================
@ TEXT – ZANDER
@ ======================

Route10_Text_Zander_Intro:
	.string "Perfect! I was just thinking to\n"
	.string "myself about stomping a twerp haha.$"

Route10_Text_Zander_Defeated:
	.string "You beat me, but Shadow POKéMON\n"
	.string "won't leave our side yet.\p"
	.string "You're stepping into deep water, kid.$"

Route10_Text_Zander_PostBattle:
	.string "Our associates have taken over\n"
	.string "Rock Tunnel. You're going to have a\l"
	.string "real tough time getting through there.$"

Route10_Text_PowerPlant:
	.string "POWER PLANT$"

Route10_Text_Sign:
	.string "ROUTE 10\p"
	.string "CERULEAN CITY - LAVENDER TOWN$"
