IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, IlexForest_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IlexForest_OnFrame
	.byte 0

IlexForest_OnTransition:
	setflag FLAG_HIDE_ILEX_HOOPA_RING
	hideobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	removeobject LOCALID_ILEX_HOOPA_RING
	setvar VAR_TEMP_1, 0
	end

IlexForest_OnLoad:
	setflag FLAG_HIDE_ILEX_HOOPA_RING
	hideobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	removeobject LOCALID_ILEX_HOOPA_RING
	goto_if_set FLAG_HIDE_ILEX_JJ_GROUP, IlexForest_OnLoad_SceneDone
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	end

IlexForest_OnLoad_SceneDone:
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, 0
	end

IlexForest_OnFrame::
	map_script_2 VAR_TEMP_1, 0, IlexForest_EventScript_KeepHoopaRingHidden
	.2byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

IlexForest_Speaker_JJ:
	.string "Jessie&James$"

IlexForest_Speaker_Rocket:
	.string "ROCKET$"

IlexForest_Speaker_BugCatcher:
	.string "BUG CATCHER$"

IlexForest_Speaker_Charon:
	.string "CHARON$"

IlexForest_Speaker_Jessie:
	.string "JESSIE$"

IlexForest_Speaker_James:
	.string "JAMES$"

@ =========================================================
@ TRAINERS
@ =========================================================

IlexForest_EventScript_JJ_Talk::
	setspeaker IlexForest_Speaker_JJ
	trainerbattle_single TRAINER_JJ_ILEX, IlexForest_Text_JJ_Intro, IlexForest_Text_JJ_Defeat, IlexForest_EventScript_JJ_After
	end

IlexForest_EventScript_JJ_After::
	setspeaker IlexForest_Speaker_JJ
	msgbox IlexForest_Text_JJ_After, MSGBOX_NPC
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_ILEX_JJ_GROUP
	removeobject LOCALID_ILEX_JESSIE
	removeobject LOCALID_ILEX_JAMES
	removeobject LOCALID_ILEX_SHADOW_MEOWTH
	removeobject LOCALID_ILEX_ROCKET_F1
	removeobject LOCALID_ILEX_ROCKET_M1
	removeobject LOCALID_ILEX_ROCKET_F2
	removeobject LOCALID_ILEX_ROCKET_M2
	removeobject LOCALID_ILEX_ROCKET_M3
	removeobject LOCALID_ILEX_ROCKET_F3
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

IlexForest_EventScript_RocketGrunt_F1::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M1::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_F2::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M2::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M3::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_F3::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_Rocket_After::
	setspeaker IlexForest_Speaker_Rocket
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_BugCatcher::
	setspeaker IlexForest_Speaker_BugCatcher
	trainerbattle_single TRAINER_ILEX_BUG_CATCHER, IlexForest_Text_BugCatcher_Intro, IlexForest_Text_BugCatcher_Defeat, IlexForest_EventScript_BugCatcher_After
	end

IlexForest_EventScript_BugCatcher_After::
	setspeaker IlexForest_Speaker_BugCatcher
	msgbox IlexForest_Text_BugCatcher_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_HoopaRing::
	end

IlexForest_EventScript_KeepHoopaRingHidden::
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_HIDE_ILEX_HOOPA_RING, IlexForest_EventScript_KeepHoopaRingHidden_Done
	hideobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	removeobject LOCALID_ILEX_HOOPA_RING
IlexForest_EventScript_KeepHoopaRingHidden_Done::
	end

IlexForest_EventScript_CharonScene::
	goto_if_set FLAG_HIDE_ILEX_JJ_GROUP, IlexForest_EventScript_CharonScene_Done
	lockall
	setvar VAR_TEMP_0, 1
	playbgm MUS_CIPHER_ENCOUNTER, FALSE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, IlexForest_Movement_CameraToCharon
	waitmovement 0
	setspeaker IlexForest_Speaker_Charon
	msgbox IlexForest_Text_Charon_Intro, MSGBOX_DEFAULT
	closemessage
	setspeaker IlexForest_Speaker_James
	msgbox IlexForest_Text_James_Response, MSGBOX_DEFAULT
	closemessage
	setspeaker IlexForest_Speaker_Jessie
	msgbox IlexForest_Text_Jessie_Response, MSGBOX_DEFAULT
	closemessage
	setspeaker IlexForest_Speaker_Charon
	msgbox IlexForest_Text_Charon_Exit, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ILEX_HOOPA_RING
	addobject LOCALID_ILEX_HOOPA_RING
	hideobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	setobjectsubpriority LOCALID_ILEX_CHARON, MAP_ILEX_FOREST, 0
	setobjectsubpriority LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST, 1
	showobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	setvar VAR_0x8004, LOCALID_ILEX_HOOPA_RING
	setvar VAR_0x8001, 32
	setvar VAR_0x8002, 37
	special Special_HoopaRingSpawnGrow
	waitstate
	setvar VAR_0x8000, LOCALID_ILEX_CHARON
	special Special_ObjectEventAbsorb
	waitstate
	hideobjectat LOCALID_ILEX_CHARON, MAP_ILEX_FOREST
	removeobject LOCALID_ILEX_CHARON
	setvar VAR_0x8004, LOCALID_ILEX_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_ILEX_HOOPA_RING, MAP_ILEX_FOREST
	setflag FLAG_HIDE_ILEX_HOOPA_RING
	removeobject LOCALID_ILEX_HOOPA_RING
	applymovement LOCALID_CAMERA, IlexForest_Movement_CameraFromCharon
	waitmovement 0
	special RemoveCameraObject
	playse SE_PIN
	applymovement LOCALID_ILEX_JESSIE, Common_Movement_ExclamationMark
	applymovement LOCALID_ILEX_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ILEX_JESSIE, Common_Movement_FacePlayer
	applymovement LOCALID_ILEX_JAMES, Common_Movement_FacePlayer
	applymovement LOCALID_ILEX_SHADOW_MEOWTH, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ILEX_JAMES, IlexForest_Movement_James_ToPlayer
	waitmovement 0
	fadeoutbgm 0
	delay 20
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker IlexForest_Speaker_James
	msgbox IlexForest_Text_James_Challenge, MSGBOX_DEFAULT
	closemessage
	setspeaker IlexForest_Speaker_Jessie
	msgbox IlexForest_Text_Jessie_Challenge, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_JJ_ILEX, gText_EmptyString2, IlexForest_Text_JJ_Defeat, IlexForest_EventScript_JJ_After
	end

IlexForest_EventScript_CharonScene_Done::
	end

IlexForest_Movement_CameraToCharon:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

IlexForest_Movement_CameraFromCharon:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Movement_James_ToPlayer:
	walk_left
	walk_left
	step_end

@ =========================================================
@ TEXT
@ =========================================================

IlexForest_Text_JJ_Intro:
	.string "We found a strange MEOWTH in these\n"
	.string "woods! Hand it over!$"

IlexForest_Text_JJ_Defeat:
	.string "We're blasting off again!$"

IlexForest_Text_JJ_After:
	.string "TEAM ROCKET will be back for that\n"
	.string "MEOWTH!$"

IlexForest_Text_Rocket_Intro:
	.string "We're busy in this forest.\n"
	.string "Stay out of the way!$"

IlexForest_Text_Rocket_Defeat:
	.string "Tch...$"

IlexForest_Text_Rocket_After:
	.string "You didn't see anything.$"

IlexForest_Text_BugCatcher_Intro:
	.string "Team Rocket's everywhere...\n"
	.string "Don't get caught!$"

IlexForest_Text_BugCatcher_Defeat:
	.string "I tried!$"

IlexForest_Text_BugCatcher_After:
	.string "I just want to keep my bugs safe.$"

IlexForest_Text_Charon_Intro:
	.string "The forest protector is now ours.\p"
	.string "Once the SAGES finish with the\n"
	.string "Birds then there will be none who\l"
	.string "can stop us. That MEOWTH of yours\l"
	.string "looks real good, how much for it?\p"
	.string "Hahaha$"

IlexForest_Text_James_Response:
	.string "Sir! We cannot sell our beloved\n"
	.string "MEOWTH. The conversion enough was\l"
	.string "already a lot.$"

IlexForest_Text_Jessie_Response:
	.string "Zip it James! How much are we\n"
	.string "talking?$"

IlexForest_Text_Charon_Exit:
	.string "HAHAHA. You're both fools.\p"
	.string "Make sure that nobody interferes\n"
	.string "with our agenda. I'm heading back\l"
	.string "to the Boss to share the good\l"
	.string "news.$"

IlexForest_Text_James_Challenge:
	.string "You again twerp! This time we will\n"
	.string "not be defeated!$"

IlexForest_Text_Jessie_Challenge:
	.string "For what we had to do to MEOWTH,\n"
	.string "we will make sure happens to all of\l"
	.string "your POKéMON!$"
