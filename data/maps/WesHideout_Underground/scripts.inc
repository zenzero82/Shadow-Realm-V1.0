WesHideout_Underground_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WesHideout_Underground_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, WesHideout_Underground_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WesHideout_Underground_OnFrame
	.byte 0

#undef LOCALID_LYRA
#undef LOCALID_MEGANIUM

#define LOCALID_BIRCH 1
#define LOCALID_ELM 2
#define LOCALID_KUKUI 3
#define LOCALID_SYCAMORE 4
#define LOCALID_MAGNOLIA 5
#define LOCALID_ROWAN 6
#define LOCALID_JUNIPER 7
#define LOCALID_LYRA 8
#define LOCALID_MEGANIUM 9
#define LOCALID_HOOPA_RING 10

WesHideout_Underground_OnTransition::
	setflag FLAG_HIDE_WES_HIDEOUT_HOOPA_RING
	hideobjectat LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND
	removeobject LOCALID_HOOPA_RING
	goto_if_set FLAG_WES_HIDEOUT_LYRA_SCENE, WesHideout_Underground_OnTransition_Scene
	setflag FLAG_HIDE_WES_HIDEOUT_LYRA
	setflag FLAG_HIDE_WES_HIDEOUT_MEGANIUM
	hideobjectat LOCALID_LYRA, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_MEGANIUM, MAP_WES_HIDEOUT_UNDERGROUND
	setvar VAR_TEMP_2, 1
	end

WesHideout_Underground_OnTransition_Scene::
	clearflag FLAG_HIDE_WES_HIDEOUT_LYRA
	clearflag FLAG_HIDE_WES_HIDEOUT_MEGANIUM
	hideobjectat LOCALID_PLAYER, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_LYRA, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_MEGANIUM, MAP_WES_HIDEOUT_UNDERGROUND
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_TEMP_2, 0
	end

WesHideout_Underground_OnLoad::
	goto_if_set FLAG_WES_HIDEOUT_LYRA_SCENE, WesHideout_Underground_OnLoad_Scene
	end

WesHideout_Underground_OnLoad_Scene::
	hideobjectat LOCALID_PLAYER, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_LYRA, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_MEGANIUM, MAP_WES_HIDEOUT_UNDERGROUND
	hideobjectat LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND
	setflag FLAG_HIDE_WES_HIDEOUT_HOOPA_RING
	removeobject LOCALID_HOOPA_RING
	end

WesHideout_Underground_OnFrame::
	map_script_2 VAR_TEMP_2, 0, WesHideout_Underground_EventScript_LyraScene
	.2byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

WesHideout_Underground_Speaker_Birch:
	.string "BIRCH$"

WesHideout_Underground_Speaker_Elm:
	.string "ELM$"

WesHideout_Underground_Speaker_Kukui:
	.string "KUKUI$"

WesHideout_Underground_Speaker_Sycamore:
	.string "SYCAMORE$"

WesHideout_Underground_Speaker_Magnolia:
	.string "MAGNOLIA$"

WesHideout_Underground_Speaker_Rowan:
	.string "ROWAN$"

WesHideout_Underground_Speaker_Juniper:
	.string "JUNIPER$"

WesHideout_Underground_EventScript_LyraScene::
	lockall
	setvar VAR_TEMP_2, 1
	clearflag FLAG_WES_HIDEOUT_LYRA_SCENE
	clearflag FLAG_HIDE_WES_HIDEOUT_LYRA
	clearflag FLAG_HIDE_WES_HIDEOUT_MEGANIUM
	setflag FLAG_HIDE_WES_HIDEOUT_HOOPA_RING
	hideobjectat LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND
	removeobject LOCALID_HOOPA_RING
	setobjectxy LOCALID_PLAYER, 25, 12
	setobjectxyperm LOCALID_PLAYER, 25, 12
	setobjectxy LOCALID_LYRA, 27, 12
	setobjectxyperm LOCALID_LYRA, 27, 12
	setobjectxy LOCALID_MEGANIUM, 27, 13
	setobjectxyperm LOCALID_MEGANIUM, 27, 13
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_LYRA, DIR_NORTH
	turnobject LOCALID_MEGANIUM, DIR_NORTH
	showobjectat LOCALID_PLAYER, MAP_WES_HIDEOUT_UNDERGROUND
	showobjectat LOCALID_LYRA, MAP_WES_HIDEOUT_UNDERGROUND
	showobjectat LOCALID_MEGANIUM, MAP_WES_HIDEOUT_UNDERGROUND
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setspeaker WesHideout_Underground_Speaker_Birch
	msgbox WesHideout_Underground_Text_Birch_TimeMachine, MSGBOX_DEFAULT
	closemessage

	clearflag FLAG_HIDE_WES_HIDEOUT_HOOPA_RING
	addobject LOCALID_HOOPA_RING
	setobjectxy LOCALID_HOOPA_RING, 25, 11
	setobjectxyperm LOCALID_HOOPA_RING, 25, 11
	showobjectat LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND
	setobjectsubpriority LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND, 0

	setvar VAR_0x8004, LOCALID_HOOPA_RING
	setvar VAR_0x8001, 25
	setvar VAR_0x8002, 11
	special Special_HoopaRingSpawnGrow
	waitstate

	applymovement LOCALID_PLAYER, WesHideout_Underground_Movement_PlayerIntoRing
	waitmovement 0
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventAbsorb
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	hideobjectat LOCALID_PLAYER, MAP_WES_HIDEOUT_UNDERGROUND

	setvar VAR_0x8004, LOCALID_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_HOOPA_RING, MAP_WES_HIDEOUT_UNDERGROUND
	setflag FLAG_HIDE_WES_HIDEOUT_HOOPA_RING
	removeobject LOCALID_HOOPA_RING

	setflag FLAG_VIOLET_HOOPA_SCENE
	releaseall
	warp MAP_VIOLET_CITY, 14, 38
	waitstate
	end

@ =========================================================
@ PROFESSORS
@ =========================================================

WesHideout_Underground_EventScript_Birch::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Birch
	checkflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	goto_if_eq WesHideout_Underground_EventScript_Birch_After
	msgbox WesHideout_Underground_Text_Birch_Intro, MSGBOX_NPC
	closemessage
	call WesHideout_Underground_EventScript_Birch_GivePokenav
	setspeaker WesHideout_Underground_Speaker_Birch
	msgbox WesHideout_Underground_Text_Birch_Intro_Final, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Birch_After::
	msgbox WesHideout_Underground_Text_Birch_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Birch_GivePokenav::
	checkflag FLAG_RECEIVED_POKENAV
	goto_if_eq WesHideout_Underground_EventScript_Birch_GivePokenav_Done
	setspeaker WesHideout_Underground_Speaker_Birch
	msgbox WesHideout_Underground_Text_Birch_Pokenav, MSGBOX_NPC
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message WesHideout_Underground_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
WesHideout_Underground_EventScript_Birch_GivePokenav_Done::
	return

WesHideout_Underground_EventScript_Elm::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Elm
	checkflag FLAG_WES_HIDEOUT_TALKED_ELM
	goto_if_eq WesHideout_Underground_EventScript_Elm_After
	msgbox WesHideout_Underground_Text_Elm_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_ELM
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Elm_After::
	msgbox WesHideout_Underground_Text_Elm_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Kukui
	checkflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	goto_if_eq WesHideout_Underground_EventScript_Kukui_After
	msgbox WesHideout_Underground_Text_Kukui_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	checkflag FLAG_QUEST_KUKUI_SHADOW_STARTED
	goto_if_eq WesHideout_Underground_EventScript_Kukui_QuestStartDone
	setflag FLAG_QUEST_KUKUI_SHADOW_STARTED
	call QuestJournal_EventScript_NewQuestAlert
WesHideout_Underground_EventScript_Kukui_QuestStartDone:
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Kukui_After::
	checkflag FLAG_QUEST_KUKUI_SHADOW_STARTED
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest
	msgbox WesHideout_Underground_Text_Kukui_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest:
	checkflag FLAG_QUEST_KUKUI_SHADOW_COMPLETED
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_Completed
	msgbox WesHideout_Underground_Text_Kukui_AskShadow, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_CheckMeowth
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_CheckMeowth:
	special Special_Kukui_CheckShadowMeowthInParty
	compare VAR_RESULT, TRUE
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_Meowth
	msgbox WesHideout_Underground_Text_Kukui_NotMeowth, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_Meowth:
	msgbox WesHideout_Underground_Text_Kukui_Meowth_Request, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_TakeMeowth
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_TakeMeowth:
	special Special_Kukui_TakeShadowMeowth
	setflag FLAG_KUKUI_SHADOW_MEOWTH_TAKEN
	setflag FLAG_QUEST_KUKUI_SHADOW_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
	checkflag FLAG_QUEST_SNAG_MACHINE_STARTED
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_TakeMeowth_End
	setflag FLAG_QUEST_SNAG_MACHINE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
WesHideout_Underground_EventScript_Kukui_Quest_TakeMeowth_End:
	msgbox WesHideout_Underground_Text_Kukui_Meowth_Taken, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_Completed:
	checkflag FLAG_KUKUI_SHADOW_MEOWTH_TAKEN
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_Testing
	msgbox WesHideout_Underground_Text_Kukui_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_Testing:
	checkflag FLAG_BADGE08_GET
	goto_if_eq WesHideout_Underground_EventScript_Kukui_Quest_Return
	msgbox WesHideout_Underground_Text_Kukui_Meowth_Testing, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui_Quest_Return:
	special Special_Kukui_ReturnShadowMeowth
	setflag FLAG_KUKUI_SHADOW_MEOWTH_RETURNED
	clearflag FLAG_KUKUI_SHADOW_MEOWTH_TAKEN
	msgbox WesHideout_Underground_Text_Kukui_Meowth_Returned, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Sycamore::
	lockall
	setvar VAR_TEMP_1, 1
	checkflag FLAG_RECEIVED_SNAG_MACHINE
	goto_if_eq WesHideout_Underground_EventScript_Sycamore_AfterSnag
	checkflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	goto_if_eq WesHideout_Underground_EventScript_Sycamore_After
	call WesHideout_Underground_EventScript_MagnoliaSycamore_Intro
	call WesHideout_Underground_EventScript_GiveShadowMonitor
	setflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	setflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	call WesHideout_Underground_EventScript_StartSnagMachineQuest
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Sycamore_After::
	call WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_Sycamore_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Sycamore_AfterSnag::
	call WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_Sycamore_AfterSnag, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Magnolia::
	lockall
	setvar VAR_TEMP_1, 1
	checkflag FLAG_RECEIVED_SNAG_MACHINE
	goto_if_eq WesHideout_Underground_EventScript_Magnolia_AfterSnag
	checkflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	goto_if_eq WesHideout_Underground_EventScript_Magnolia_After
	call WesHideout_Underground_EventScript_MagnoliaSycamore_Intro
	call WesHideout_Underground_EventScript_GiveShadowMonitor
	setflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	setflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	call WesHideout_Underground_EventScript_StartSnagMachineQuest
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Magnolia_After::
	call WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_Magnolia_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Magnolia_AfterSnag::
	call WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_Magnolia_AfterSnag, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Rowan::
	lock
	faceplayer
	goto WesHideout_Underground_EventScript_Rowan_Talk_Object

WesHideout_Underground_EventScript_GiveShadowMonitor::
	checkflag FLAG_RECEIVED_SHADOW_MONITOR
	goto_if_eq WesHideout_Underground_EventScript_GiveShadowMonitor_Done
	giveitem ITEM_SHADOW_MONITOR
	setflag FLAG_RECEIVED_SHADOW_MONITOR
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_Sycamore_ShadowMonitor_Given, MSGBOX_NPC
	closemessage
WesHideout_Underground_EventScript_GiveShadowMonitor_Done::
	return

WesHideout_Underground_EventScript_StartSnagMachineQuest::
	checkflag FLAG_QUEST_SNAG_MACHINE_STARTED
	goto_if_eq WesHideout_Underground_EventScript_StartSnagMachineQuest_Done
	setflag FLAG_QUEST_SNAG_MACHINE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
WesHideout_Underground_EventScript_StartSnagMachineQuest_Done::
	return

WesHideout_Underground_EventScript_Rowan_Talk_Object::
	setspeaker WesHideout_Underground_Speaker_Rowan
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_Rowan_Talk_Object_After
	call WesHideout_Underground_EventScript_Rowan_IntroSequence
	setflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Rowan_Talk_Object_After::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Juniper::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Juniper
	checkflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	goto_if_eq WesHideout_Underground_EventScript_Juniper_After
	msgbox WesHideout_Underground_Text_Juniper_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Juniper_After::
	msgbox WesHideout_Underground_Text_Juniper_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_HoopaRing::
	end

@ =========================================================
@ ROWAN TRIGGERS
@ =========================================================

WesHideout_Underground_EventScript_RowanTrigger_0::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_0
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_RowanTrigger_1::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_1
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_RowanTrigger_2::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_2
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_Rowan_Talk_Trigger::
	call WesHideout_Underground_EventScript_FaceRowanAndPlayer
	setspeaker WesHideout_Underground_Speaker_Rowan
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_Rowan_Talk_Trigger_After
	call WesHideout_Underground_EventScript_Rowan_IntroSequence
	setflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Rowan_IntroSequence::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_1, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_2, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_3, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_4, MSGBOX_NPC
	closemessage
	return

WesHideout_Underground_EventScript_Rowan_Talk_Trigger_After::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_RowanTrigger_Done::
	end

@ =========================================================
@ MAGNOLIA + SYCAMORE INTRO
@ =========================================================

WesHideout_Underground_EventScript_MagnoliaSycamore_Intro::
	turnobject LOCALID_MAGNOLIA, DIR_EAST
	turnobject LOCALID_SYCAMORE, DIR_WEST
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Prep1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_MAGNOLIA, DIR_EAST
	turnobject LOCALID_SYCAMORE, DIR_WEST
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Prep2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	applymovement LOCALID_SYCAMORE, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectmovementtype LOCALID_MAGNOLIA, MOVEMENT_TYPE_NONE
	setobjectmovementtype LOCALID_SYCAMORE, MOVEMENT_TYPE_NONE
	call WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player1, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player2, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player3, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player4, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player5, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player6, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player7, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player8, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player9, MSGBOX_NPC
	closemessage
	return

@ =========================================================
@ FACE ROWAN + PLAYER
@ =========================================================

WesHideout_Underground_EventScript_FaceRowanAndPlayer::
	getplayerxy VAR_0x8000, VAR_0x8001
	getobjectcurrentxy LOCALID_ROWAN, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
	goto_if_lt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_PlayerAboveRowan
	goto_if_gt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_PlayerBelowRowan
	goto_if_lt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_PlayerLeftRowan
	goto_if_gt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_PlayerRightRowan
	return

WesHideout_Underground_EventScript_PlayerAboveRowan::
	turnobject LOCALID_ROWAN, DIR_NORTH
	turnobject LOCALID_PLAYER, DIR_SOUTH
	return

WesHideout_Underground_EventScript_PlayerBelowRowan::
	turnobject LOCALID_ROWAN, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH
	return

WesHideout_Underground_EventScript_PlayerLeftRowan::
	turnobject LOCALID_ROWAN, DIR_WEST
	turnobject LOCALID_PLAYER, DIR_EAST
	return

WesHideout_Underground_EventScript_PlayerRightRowan::
	turnobject LOCALID_ROWAN, DIR_EAST
	turnobject LOCALID_PLAYER, DIR_WEST
	return

@ =========================================================
@ FACE MAGNOLIA + SYCAMORE
@ =========================================================

WesHideout_Underground_EventScript_FaceMagSycamoreAndPlayer::
	getplayerxy VAR_0x8000, VAR_0x8001
	getobjectcurrentxy LOCALID_MAGNOLIA, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
	goto_if_lt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_MagnoliaFaceNorth
	goto_if_gt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_MagnoliaFaceSouth
	goto_if_lt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_MagnoliaFaceWest
	goto_if_gt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_MagnoliaFaceEast
	goto WesHideout_Underground_EventScript_MagnoliaFaceDone

WesHideout_Underground_EventScript_MagnoliaFaceNorth::
	turnobject LOCALID_MAGNOLIA, DIR_NORTH
	goto WesHideout_Underground_EventScript_MagnoliaFaceDone

WesHideout_Underground_EventScript_MagnoliaFaceSouth::
	turnobject LOCALID_MAGNOLIA, DIR_SOUTH
	goto WesHideout_Underground_EventScript_MagnoliaFaceDone

WesHideout_Underground_EventScript_MagnoliaFaceWest::
	turnobject LOCALID_MAGNOLIA, DIR_WEST
	goto WesHideout_Underground_EventScript_MagnoliaFaceDone

WesHideout_Underground_EventScript_MagnoliaFaceEast::
	turnobject LOCALID_MAGNOLIA, DIR_EAST

WesHideout_Underground_EventScript_MagnoliaFaceDone::
	getobjectcurrentxy LOCALID_SYCAMORE, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
	goto_if_lt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_SycamoreFaceNorth
	goto_if_gt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_SycamoreFaceSouth
	goto_if_lt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_SycamoreFaceWest
	goto_if_gt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_SycamoreFaceEast
	goto WesHideout_Underground_EventScript_SycamoreFaceDone

WesHideout_Underground_EventScript_SycamoreFaceNorth::
	turnobject LOCALID_SYCAMORE, DIR_NORTH
	goto WesHideout_Underground_EventScript_SycamoreFaceDone

WesHideout_Underground_EventScript_SycamoreFaceSouth::
	turnobject LOCALID_SYCAMORE, DIR_SOUTH
	goto WesHideout_Underground_EventScript_SycamoreFaceDone

WesHideout_Underground_EventScript_SycamoreFaceWest::
	turnobject LOCALID_SYCAMORE, DIR_WEST
	goto WesHideout_Underground_EventScript_SycamoreFaceDone

WesHideout_Underground_EventScript_SycamoreFaceEast::
	turnobject LOCALID_SYCAMORE, DIR_EAST

WesHideout_Underground_EventScript_SycamoreFaceDone::
	turnobject LOCALID_PLAYER, DIR_SOUTH
	return

@ =========================================================
@ MOVEMENTS
@ =========================================================

WesHideout_Underground_Movement_RowanApproach_0:
	walk_right
	walk_up
	step_end

WesHideout_Underground_Movement_RowanApproach_1:
	walk_right
	step_end

WesHideout_Underground_Movement_RowanApproach_2:
	walk_right
	walk_right
	step_end

WesHideout_Underground_Movement_PlayerIntoRing:
	walk_up
	step_end

@ =========================================================
@ FLAGS: CHECK ALL PROFESSORS
@ =========================================================

WesHideout_Underground_EventScript_CheckAllProfessors::
	checkflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_ELM
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	goto_if_ne WesHideout_Underground_EventScript_CheckAllProfessors_Done
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	checkflag FLAG_QUEST_TALK_TEAM_STARTED
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Quest
	goto WesHideout_Underground_EventScript_CheckAllProfessors_Done
WesHideout_Underground_EventScript_CheckAllProfessors_Quest:
	checkflag FLAG_QUEST_TALK_TEAM_COMPLETED
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	setflag FLAG_QUEST_TALK_TEAM_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
	checkflag FLAG_QUEST_KUKUI_SHADOW_STARTED
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	setflag FLAG_QUEST_KUKUI_SHADOW_STARTED
	call QuestJournal_EventScript_NewQuestAlert
WesHideout_Underground_EventScript_CheckAllProfessors_Done::
	return

@ =========================================================
@ TEXT
@ =========================================================

WesHideout_Underground_Text_Birch_Intro:
	.string "Hey there kid! Name's PROF. BIRCH.\n"
	.string "I'm known to talk a lot, hahaha.\p"
	.string "Lucky for you I'm fixing the machine\n"
	.string "that brought you here.\p"
	.string "We managed to replicate the portals\n"
	.string "with a special POKéMON named CELEBI.\p"
	.string "When we opened your portal, CELEBI\n"
	.string "freaked out and disappeared.\p"
	.string "It left this thing in shambles.\n"
	.string "We still have no clue where it went.\p"
	.string "We don't know why it was alarmed.\n"
	.string "It likely has to do with CIPHER.\p"
	.string "Can you do me a favor and track it\n"
	.string "down? MICHAEL said CELEBI was used\p"
	.string "in WES's timeline to help purify\n"
	.string "Shadow POKéMON.\p"
	.string "It has been helping us since we\n"
	.string "learned of the problem.\p"
	.string "While researching POKéMON habitats,\n"
	.string "I found CELEBI wounded in a forest.\p"
	.string "It was scrambling as CIPHER captured\n"
	.string "forest POKéMON.\p"
	.string "We helped it recover, and it began\n"
	.string "to aid us by opening a portal\p"
	.string "that let us communicate with PROF.\n"
	.string "TURO in the future.\p"
	.string "Before we lost contact, something\n"
	.string "seemed to happen to him.\p"
	.string "We need to get CELEBI back and fix\n"
	.string "things before CIPHER gets it.\p"
	.string "MAY and BRENDAN are out scouting\n"
	.string "as well so you're not alone in this.$"

WesHideout_Underground_Text_Birch_Pokenav:
	.string "You should also take this POKéNAV so\n"
	.string "we can stay in touch.$"

WesHideout_Underground_Text_ReceivedPokenav:
	.string "{PLAYER} received a POKéNAV.$"

WesHideout_Underground_Text_Birch_Intro_Final:
	.string "Please do your best!$"

WesHideout_Underground_Text_Birch_After:
	.string "Please keep an eye out for CELEBI.\n"
	.string "We need it back.$"

WesHideout_Underground_Text_Birch_TimeMachine:
	.string "We managed to get the TIME MACHINE\n"
	.string "working again! Sort of...\p"
	.string "We can't travel through different\n"
	.string "time periods as we did before, but\l"
	.string "we can now create portals to\l"
	.string "transport you across KANTO, JOHTO,\l"
	.string "and HOENN.\p"
	.string "As you know, MICHAEL went to see\n"
	.string "KURT some time ago, but something\l"
	.string "came up with TEAM AQUA in VIOLET\n"
	.string "CITY.\p"
	.string "Before he left, I gave MICHAEL a\n"
	.string "TIME AMULET which allows us to warp\l"
	.string "you straight to his location.\p"
	.string "Lets test it out!$"

WesHideout_Underground_Text_Elm_Intro:
	.string "This is a disaster!\p"
	.string "Sorry, I'm PROF. ELM\p"
	.string "I'm a little overwhelmed these days.\p"
	.string "I specialize in breeding POKéMON\n"
	.string "eggs, but I'm not much use here.\p"
	.string "Shadow POKéMON can't seem to breed,\n"
	.string "but we need to conduct more research.\p"
	.string "PROF. OAK was so close to solving\n"
	.string "the Shadow POKéMON origins\l"
	.string "and then BOOM, gone.\p"
	.string "There's a professor named KRANE\n"
	.string "in MICHAEL's timeline.\p"
	.string "He knew a lot about Shadow POKéMON\n"
	.string "and even built a system to purify.\p"
	.string "It can open the closed heart of\n"
	.string "even legendary POKéMON!\p"
	.string "The problem is KRANE is missing\n"
	.string "from this timeline, and our\l"
	.string "TIME MACHINE is busted!\p"
	.string "We planned to pull him in after\n"
	.string "you, but the device failed.\p"
	.string "The KRANE of this timeline never\n"
	.string "met Shadow POKéMON, so he's useless.\p"
	.string "Taking POKéMON from trainers is bad,\n"
	.string "but closing their hearts is worse!\p"
	.string "We must capture every Shadow POKéMON\n"
	.string "CIPHER created.\p"
	.string "We must restore their hearts.\p"
	.string "ETHAN and LYRA are hunting trainers\n"
	.string "as we speak.\p"
	.string "They're sending over data they find\n"
	.string "so we can add them to the SHADOW MONITOR.\p"
	.string "So far it seems there is 70 types of\n"
	.string "SHADOW POKéMON that are not identified.\p"
	.string "Prof. SYCAMORE should have the device\n"
	.string "ready now. We need you to help fill it.\p"
	.string "They're taking a beating out there.\n"
	.string "Please help them!$"

WesHideout_Underground_Text_Elm_After:
	.string "Please help ETHAN and LYRA.\n"
	.string "We need more Shadow data.$"

WesHideout_Underground_Text_Kukui_Intro:
	.string "Alola! Good to finally meet you,\n"
	.string "champ! We know more about you,\l"
	.string "than you likely know about yourself!\n"
	.string "I'm PROF. KUKUI, a move researcher.\p"
	.string "Nobody in this timeline has heard\n"
	.string "of Z MOVES. Can you believe it?!\p"
	.string "Luckily I know all about them.\n"
	.string "We'll roll out Z CRYSTALS soon.\p"
	.string "They'll help us take down CIPHER.\p"
	.string "I've researched Shadow POKéMON,\n"
	.string "and their movepools are bizarre.\p"
	.string "If you can snag some, bring me one.\p"
	.string "Oh, nobody explained snagging yet?\n"
	.string "Yeah... you're basically a thief.\p"
	.string "But it's for the right reasons.\n"
	.string "We'll be here, so stop by again!$"

WesHideout_Underground_Text_Kukui_After:
	.string "Stop by again! We'll be here.\n"
	.string "for some time.$"

WesHideout_Underground_Text_Kukui_AskShadow:
	.string "Alola! Do you have a Shadow POKéMON\n"
	.string "you want to show me?$"

WesHideout_Underground_Text_Kukui_NotMeowth:
	.string "Hmm, I don't think we need to study\n"
	.string "this one right now. Keep bringing\l"
	.string "me some.$"

WesHideout_Underground_Text_Kukui_Meowth_Request:
	.string "Oh, there is something that is quite\n"
	.string "different with this POKéMON. Do you\l"
	.string "mind leaving it with me for some\l"
	.string "time?$"

WesHideout_Underground_Text_Kukui_Meowth_Taken:
	.string "Thanks! I'll let you know when we're\n"
	.string "done with our tests.$"

WesHideout_Underground_Text_Kukui_Meowth_Testing:
	.string "Alola! We are still running some tests\n"
	.string "on MEOWTH. Come back some other time.\p"
	.string "If I had to guess, it would be by the\n"
	.string "time you got 8 badges.$"

WesHideout_Underground_Text_Kukui_Meowth_Returned:
	.string "Alola! We learned a lot from this\n"
	.string "POKéMON. Here it is back.$"

WesHideout_Underground_Text_Sycamore_After:
	.string "Use the SHADOW MONITOR to track\n"
	.string "Shadow POKéMON you snag.\p"
	.string "Bring me data when you can.\n"
	.string "It will help us refine it.$"

WesHideout_Underground_Text_Sycamore_AfterSnag:
	.string "You will likely bump into CALEM or\n"
	.string "SERENA during your journey.\p"
	.string "Be sure to ask them for a MEGA\n"
	.string "BRACELET!$"

WesHideout_Underground_Text_Magnolia_After:
	.string "It's about time to take CIPHER down!\n"
	.string "Go see WES upstairs.\p"
	.string "I believe he has something special\n"
	.string "for you.$"

WesHideout_Underground_Text_Magnolia_AfterSnag:
	.string "If you see VICTOR or GLORIA,\n"
	.string "be sure to ask them for a DYNAMAX\n"
	.string "BAND.$"

WesHideout_Underground_Text_Rowan_Intro_1:
	.string "Oh, you finally made it.\p"
	.string "The email sent to OAK was\n"
	.string "actually sent by me.\p"
	.string "Truth is, we don't know where he is.\p"
	.string "CIPHER is on the move and likely\n"
	.string "kidnapped him for his Shadow work.\p"
	.string "Sorry, I got ahead of myself.\n"
	.string "I'm PROF. ROWAN from SINNOH.\p"
	.string "Everyone here was pulled into this\n"
	.string "bizarre timeline from another one.\p"
	.string "It took us quite a while to wrap\n"
	.string "our heads around it.$"

WesHideout_Underground_Text_Rowan_Intro_2:
	.string "WES and MICHAEL have helped,\n"
	.string "fill us in on the situation.\p"
	.string "WES called us here after talking\n"
	.string "with GARY OAK, who also later vanished.\p"
	.string "The two of them located all of us\n"
	.string "to combine our research and face\l"
	.string "the threat known as CIPHER.\p"
	.string "CIPHER has been recruiting Team's\n"
	.string "from different timelines and regions\l"
	.string "including TEAM ROCKET and PLASMA.\p"
	.string "Reports suggest TEAM AQUA and MAGMA\n"
	.string "are involved now and we cannot allow it.\p"
	.string "We can't let them corrupt POKéMON.\p"
	.string "Their hearts must be saved.$"

WesHideout_Underground_Text_Rowan_Intro_3:
	.string "We've made progress on a way to\n"
	.string "restore Shadow POKéMON hearts.\p"
	.string "According to MICHAEL, they've begun\n"
	.string "something called the XD conversion.\p"
	.string "Whatever that means, he's panicked.\p"
	.string "You're wondering why we chose you.\p"
	.string "You may not know this, but you're\n"
	.string "one of the greatest trainers ever.\p"
	.string "PROF. TURO's text confirms it.\p"
	.string "He's from the future.\p"
	.string "I know it makes no sense but\n"
	.string "nothing about our situation does.$"

WesHideout_Underground_Text_Rowan_Intro_4:
	.string "We learned to manipulate the portals\n"
	.string "that keep appearing everywhere.\p"
	.string "We tried to pull you here, but we\n"
	.string "misfired and got a younger you.\p"
	.string "You hadn't even battled yet, hahaha.\n"
	.string "So you must prove PROF. TURO right!\p"
	.string "With our research and your skill,\n"
	.string "we can prevail.\p"
	.string "You will not be alone out there.\n"
	.string "LUCAS and DAWN are also helping us.\p"
	.string "Speak to the other professors.\p"
	.string "PROF. SYCAMORE should be done now!$"

WesHideout_Underground_Text_Rowan_After:
	.string "Speak to the other professors.\p"
	.string "PROF. SYCAMORE should be done now!$"

WesHideout_Underground_Text_Juniper_Intro:
	.string "Hey there, you finally joined us.\n"
	.string "I'm PROF. JUNIPER.\p"
	.string "I study POKéMON origins.\p"
	.string "I'm here to study Shadow POKéMON.\p"
	.string "CIPHER is corrupting POKéMON hearts,\n"
	.string "but how did this start?\p"
	.string "We believe a deeper force is behind\n"
	.string "this plan.\p"
	.string "With your help, we'll bring CIPHER\n"
	.string "down once and for all!$"

WesHideout_Underground_Text_Juniper_After:
	.string "Let's bring CIPHER down once and\n"
	.string "for all!$"

WesHideout_Underground_Text_MagSycamore_Prep1:
	.string "So you're telling me this bracelet\n"
	.string "and stone can change a POKéMON form?$"

WesHideout_Underground_Text_MagSycamore_Prep2:
	.string "Yup! It's called MEGA EVOLUTION.\n"
	.string "I can't believe GALAR has DYNAMAX.\p"
	.string "A POKéMON getting that large is\n"
	.string "mind blowing, honestly!$"

WesHideout_Underground_Text_MagSycamore_Player1:
	.string "Ah, {PLAYER}.\n"
	.string "Glad you could join us.$"

WesHideout_Underground_Text_MagSycamore_Player2:
	.string "HEY! We have been waiting for you\n"
	.string "for quite some time!\p"
	.string "The TIME MACHINE was supposed to\n"
	.string "bring you here, but it sent you off\l"
	.string "somewhere west of PALLET TOWN.\n"
	.string "Blame BIRCH for that one, hahaha.$"

WesHideout_Underground_Text_MagSycamore_Player3:
	.string "I'm PROF. MAGNOLIA.\n"
	.string "I study DYNAMAX POKéMON in GALAR.$"

WesHideout_Underground_Text_MagSycamore_Player4:
	.string "I'm PROF. SYCAMORE from KALOS.\n"
	.string "I'm an expert in MEGA EVOLUTION!$"

WesHideout_Underground_Text_MagSycamore_Player5:
	.string "To our surprise, this timeline\n"
	.string "never saw MEGA EVOLUTION or Z MOVES.\p"
	.string "It hasn't seen DYNAMAX either.\p"
	.string "Luckily we arrived prepared.\p"
	.string "We can stop CIPHER.\p"
	.string "ELIO and SERENA have MEGA BRACELETS.\p"
	.string "They'll provide them to GYM LEADERS\n"
	.string "and ELITE FOUR to strengthen them.$"

WesHideout_Underground_Text_MagSycamore_Player6:
	.string "VICTOR and GLORIA are handing out\n"
	.string "DYNAMAX BANDS across the region.\p"
	.string "We also see power spots appearing.\n"
	.string "Stay alert!$"

WesHideout_Underground_Text_MagSycamore_Player7:
	.string "With help from WES, MICHAEL, ETHAN,\n"
	.string "and LYRA, we built a SHADOW MONITOR.\p"
	.string "It's ready now.\p"
	.string "It will track Shadow POKéMON.\p"
	.string "It will also track the trainers who\n"
	.string "have them.$"

WesHideout_Underground_Text_MagSycamore_Player8:
	.string "As we gather more data and intel,\n"
	.string "we can keep adding to the monitor.\p"
	.string "We'll snag every Shadow POKéMON.\p"
	.string "With everyone helping, CIPHER falls.$"

WesHideout_Underground_Text_Sycamore_ShadowMonitor_Given:
	.string "Here, take the SHADOW MONITOR.\p"
	.string "It will help you track Shadow POKéMON\n"
	.string "and the trainers who hold them.$"

WesHideout_Underground_Text_MagSycamore_Player9:
	.string "It's about time to take CIPHER down!\n"
	.string "Go see WES upstairs.\p"
	.string "I believe he has something special\n"
	.string "for you.$"
