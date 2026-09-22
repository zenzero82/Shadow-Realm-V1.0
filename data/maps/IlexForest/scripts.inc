IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, IlexForest_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, IlexForest_OnResume
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

IlexForest_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IlexForest_EventScript_TryRemoveShadowMeowth
	end

IlexForest_OnFrame::
	map_script_2 VAR_TEMP_1, 0, IlexForest_EventScript_KeepHoopaRingHidden
	.2byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

IlexForest_Speaker_JJ:
	.string "JESS&JAMES$"

IlexForest_Speaker_RocketF1:
	.string "SABRINA$"

IlexForest_Speaker_RocketM1:
	.string "RORY$"

IlexForest_Speaker_RocketF2:
	.string "LANA$"

IlexForest_Speaker_RocketM2:
	.string "MARK$"

IlexForest_Speaker_RocketM3:
	.string "TODD$"

IlexForest_Speaker_RocketF3:
	.string "RINA$"

IlexForest_Speaker_BugCatcher:
	.string "BEN$"

IlexForest_Speaker_Charon:
	.string "CHARON$"

IlexForest_Speaker_Jessie:
	.string "JESSIE$"

IlexForest_Speaker_James:
	.string "JAMES$"

IlexForest_Speaker_Birch:
	.string "BIRCH$"

@ =========================================================
@ TRAINERS
@ =========================================================

IlexForest_EventScript_JJ_Talk::
	special Special_OverworldWildEncounters_OnMapLoad
	setspeaker IlexForest_Speaker_JJ
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	trainerbattle_single TRAINER_JJ_ILEX, IlexForest_Text_JJ_Intro, IlexForest_Text_JJ_Defeat, IlexForest_EventScript_JJ_After
	end

IlexForest_EventScript_JJ_After::
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setspeaker IlexForest_Speaker_JJ
	msgbox IlexForest_Text_JJ_After, MSGBOX_NPC
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_ILEX_OFFICER
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
	call IlexForest_EventScript_TryBirchCall
	special Special_OverworldWildEncounters_OnReturnToField
	release
	end

IlexForest_EventScript_TryRemoveShadowMeowth::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, Common_EventScript_NopReturn
	removeobject LOCALID_ILEX_SHADOW_MEOWTH
	return

IlexForest_EventScript_BirchCallAfterJJ::
	goto_if_set FLAG_ILEX_BIRCH_CALL_DONE, IlexForest_EventScript_BirchCallAfterJJ_Done
	goto_if_unset FLAG_HIDE_ILEX_JJ_GROUP, IlexForest_EventScript_BirchCallAfterJJ_KeepChecking
	special StorePlayerCoordsInVars
	compare VAR_TEMP_5, 0
	goto_if_eq IlexForest_EventScript_BirchCallAfterJJ_InitCoords
	compare VAR_0x8004, VAR_TEMP_3
	goto_if_eq IlexForest_EventScript_BirchCallAfterJJ_CheckY
	goto IlexForest_EventScript_BirchCallAfterJJ_Start
IlexForest_EventScript_BirchCallAfterJJ_CheckY::
	compare VAR_0x8005, VAR_TEMP_4
	goto_if_eq IlexForest_EventScript_BirchCallAfterJJ_KeepChecking
	goto IlexForest_EventScript_BirchCallAfterJJ_Start
IlexForest_EventScript_BirchCallAfterJJ_InitCoords::
	copyvar VAR_TEMP_3, VAR_0x8004
	copyvar VAR_TEMP_4, VAR_0x8005
	setvar VAR_TEMP_5, 1
	end
IlexForest_EventScript_BirchCallAfterJJ_KeepChecking::
	setvar VAR_TEMP_2, 0
	end
IlexForest_EventScript_BirchCallAfterJJ_Start::
	lockall
	call IlexForest_EventScript_TryBirchCall
	releaseall
IlexForest_EventScript_BirchCallAfterJJ_Done::
	setvar VAR_TEMP_2, 1
	end

IlexForest_EventScript_TryBirchCall::
	goto_if_set FLAG_ILEX_BIRCH_CALL_DONE, IlexForest_EventScript_TryBirchCall_Done
	setflag FLAG_ILEX_BIRCH_CALL_DONE
	setspeaker IlexForest_Speaker_Birch
	pokenavcall IlexForest_Text_Birch_Call
	waitmessage
	closemessage
	clearflag FLAG_QUEST_BACK_TO_HQ_COMPLETED
	setflag FLAG_QUEST_BACK_TO_HQ_STARTED
	call QuestJournal_EventScript_NewQuestAlert
IlexForest_EventScript_TryBirchCall_Done::
	end

IlexForest_EventScript_ShrineSign::
	msgbox IlexForest_Text_ShrineSign, MSGBOX_SIGN
	goto_if_set FLAG_ITEM_ILEX_FOREST_RELIC_TABLET, IlexForest_EventScript_ShrineSign_Done
	msgbox IlexForest_Text_ShrinePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, IlexForest_EventScript_ShrineSign_No
	giveitem ITEM_RELIC_TABLET
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_ILEX_FOREST_RELIC_TABLET
	closemessage
	goto IlexForest_EventScript_ShrineSign_Done
IlexForest_EventScript_ShrineSign_No::
	closemessage
IlexForest_EventScript_ShrineSign_Done::
	end

IlexForest_EventScript_RocketGrunt_F1::
	setspeaker IlexForest_Speaker_RocketF1
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketF1_After
	end

IlexForest_EventScript_RocketGrunt_M1::
	setspeaker IlexForest_Speaker_RocketM1
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketM1_After
	end

IlexForest_EventScript_RocketGrunt_F2::
	setspeaker IlexForest_Speaker_RocketF2
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketF2_After
	end

IlexForest_EventScript_RocketGrunt_M2::
	setspeaker IlexForest_Speaker_RocketM2
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketM2_After
	end

IlexForest_EventScript_RocketGrunt_M3::
	setspeaker IlexForest_Speaker_RocketM3
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketM3_After
	end

IlexForest_EventScript_RocketGrunt_F3::
	setspeaker IlexForest_Speaker_RocketF3
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_RocketF3_After
	end

IlexForest_EventScript_RocketF1_After::
	setspeaker IlexForest_Speaker_RocketF1
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_RocketM1_After::
	setspeaker IlexForest_Speaker_RocketM1
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_RocketF2_After::
	setspeaker IlexForest_Speaker_RocketF2
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_RocketM2_After::
	setspeaker IlexForest_Speaker_RocketM2
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_RocketM3_After::
	setspeaker IlexForest_Speaker_RocketM3
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_RocketF3_After::
	setspeaker IlexForest_Speaker_RocketF3
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
	special Special_OverworldWildEncounters_OnMapLoad
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
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	trainerbattle_no_intro TRAINER_JJ_ILEX, IlexForest_Text_JJ_Defeat
	goto IlexForest_EventScript_JJ_After

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
	.string "can stop us.\p"
	.string "That MEOWTH of yours looks\n"
	.string "real good, how much for it?\p"
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

IlexForest_Text_Birch_Call:
	.string "Hey did you find CELEBI?\p"
	.string "... ...\p"
	.string "WHAT?! you're saying CIPHER has\n"
	.string "captured it??\p"
	.string "This is not good. Not good at all.\n"
	.string "We need to strategize. I'm going\l"
	.string "to pull you back to the lab.\p"
	.string "... ...\p"
	.string "Uh the machine is not working!\n"
	.string "Could it be that CELEBI has been\l"
	.string "somehow lending its power even\l"
	.string "when it wasn't here??\p"
	.string "This is so bad, {PLAYER} can you\n"
	.string "please try to find another way\l"
	.string "back to the lab?\p"
	.string "I hate to send you back to\n"
	.string "New Bark but perhaps you could\l"
	.string "take the long road back.\p"
	.string "Or if you have a POKéMON that\n"
	.string "can fly maybe the trip won't\l"
	.string "be so bad...\p"
	.string "I don't know I'm scrambling...\p"
	.string "Please try to find a way back\n"
	.string "as fast as you can.$"

IlexForest_Text_ShrineSign:
	.string "ILEX FOREST SHRINE...\p"
	.string "It's in honor of the forest's\n"
	.string "protector...$"

IlexForest_Text_ShrinePrompt:
	.string "It seems like there is something\n"
	.string "inside of the shrine.\p"
	.string "Do you want to reach in and\n"
	.string "grab it?$"

IlexForest_EventScript_Shrine::
	lock
	goto_if_set FLAG_ITEM_ILEX_FOREST_RELIC_TABLET, IlexForest_EventScript_Shrine_CheckCelebi
	msgbox IlexForest_Text_ShrinePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, IlexForest_EventScript_Shrine_CheckCelebi
	giveitem ITEM_RELIC_TABLET
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_ILEX_FOREST_RELIC_TABLET
	closemessage
IlexForest_EventScript_Shrine_CheckCelebi::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, IlexForest_EventScript_Celebi_Event
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Celebi_Event::
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
	closemessage
	release
	end


IlexForest_EventScript_Sign::
	lock
	msgbox IlexForest_Text_Signpost MSGBOX_SIGN
	closemessage
	release
	goto EventScript_GimmighoulSignpost


IlexForest_Text_Signpost:
	.string "ILEX FOREST is so overgrown with\n"
	.string "trees that you can't see the sky.\p"
	.string "Please watch out for items that may\n"
	.string "have been dropped.$"


IlexForest_Text_Shrine:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…$"
