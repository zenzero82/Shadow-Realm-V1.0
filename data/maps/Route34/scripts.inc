Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route34_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route34_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route34_OnFrame
	.byte 0

#define ROUTE34_LOCALID_HOOPA_RING 6
#define ROUTE34_LOCALID_VICTOR 5
#define ROUTE34_LOCALID_OFFICER 11

Route34_OnTransition:
	setflag FLAG_HIDE_ROUTE34_HOOPA_RING
	goto_if_unset FLAG_ROUTE34_HOOPA_SCENE, Route34_OnTransition_Done
	hideobjectat LOCALID_PLAYER, MAP_ROUTE34
	hideobjectat ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34
	removeobject ROUTE34_LOCALID_HOOPA_RING
Route34_OnTransition_Done:
	end

Route34_OnLoad:
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setflag FLAG_HIDE_ROUTE34_HOOPA_RING
	goto_if_unset FLAG_ROUTE34_HOOPA_SCENE, Route34_OnLoad_Done
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	hideobjectat LOCALID_PLAYER, MAP_ROUTE34
	hideobjectat ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34
	removeobject ROUTE34_LOCALID_HOOPA_RING
Route34_OnLoad_Done:
	end

Route34_OnWarp::
	map_script_2 VAR_TEMP_2, 0, Route34_EventScript_HidePlayerOnWarp
	.2byte 0

Route34_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Route34_EventScript_PlayerEmerges
	.2byte 0

Route34_EventScript_HidePlayerOnWarp::
	goto_if_unset FLAG_ROUTE34_HOOPA_SCENE, Route34_EventScript_HidePlayerOnWarp_Done
	hideobjectat LOCALID_PLAYER, MAP_ROUTE34
Route34_EventScript_HidePlayerOnWarp_Done:
	end

Route34_EventScript_PlayerEmerges::
	lockall
	setvar VAR_TEMP_1, 1
	clearflag FLAG_ROUTE34_HOOPA_SCENE
	hideobjectat LOCALID_PLAYER, MAP_ROUTE34
	setobjectxy LOCALID_PLAYER, 36, 55
	setobjectxyperm LOCALID_PLAYER, 36, 55
	clearflag FLAG_HIDE_ROUTE34_HOOPA_RING
	addobject ROUTE34_LOCALID_HOOPA_RING
	hideobjectat ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34
	setobjectxy ROUTE34_LOCALID_HOOPA_RING, 36, 55
	setobjectxyperm ROUTE34_LOCALID_HOOPA_RING, 36, 55
	showobjectat ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34
	setobjectsubpriority ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34, 1
	setvar VAR_0x8004, ROUTE34_LOCALID_HOOPA_RING
	setvar VAR_0x8001, 36
	setvar VAR_0x8002, 55
	special Special_HoopaRingSpawnGrow
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	setobjectsubpriority LOCALID_PLAYER, MAP_ROUTE34, 0
	showobjectat LOCALID_PLAYER, MAP_ROUTE34
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventEmerge
	applymovement LOCALID_PLAYER, Route34_Movement_StepFromPortal_First
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_StepFromPortal_Second
	waitmovement 0
	setvar VAR_0x8004, ROUTE34_LOCALID_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat ROUTE34_LOCALID_HOOPA_RING, MAP_ROUTE34
	setflag FLAG_HIDE_ROUTE34_HOOPA_RING
	removeobject ROUTE34_LOCALID_HOOPA_RING
	resetobjectsubpriority LOCALID_PLAYER, MAP_ROUTE34
	goto_if_set FLAG_ROUTE34_VICTOR_SCENE_DONE, Route34_EventScript_PlayerEmerges_Done
	call Route34_EventScript_VictorScene
Route34_EventScript_PlayerEmerges_Done:
	releaseall
	end

Route34_EventScript_HoopaRing::
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_DoorLocked, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_VictorScene::
	playse SE_PIN
	applymovement ROUTE34_LOCALID_VICTOR, Common_Movement_ExclamationMark
	waitmovement 0
	special StorePlayerCoordsInVars
	compare VAR_0x8005, 57
	goto_if_eq Route34_EventScript_Victor_ToPlayer_LeftSame
	compare VAR_0x8005, 56
	goto_if_eq Route34_EventScript_Victor_ToPlayer_LeftUp1
	compare VAR_0x8005, 55
	goto_if_eq Route34_EventScript_Victor_ToPlayer_LeftUp2
	goto Route34_EventScript_Victor_ToPlayer_LeftSame
Route34_EventScript_Victor_ToPlayer_LeftSame:
	applymovement ROUTE34_LOCALID_VICTOR, Route34_Movement_Victor_LeftSame
	goto Route34_EventScript_Victor_ToPlayer_Done
Route34_EventScript_Victor_ToPlayer_LeftUp1:
	applymovement ROUTE34_LOCALID_VICTOR, Route34_Movement_Victor_LeftUp1
	goto Route34_EventScript_Victor_ToPlayer_Done
Route34_EventScript_Victor_ToPlayer_LeftUp2:
	applymovement ROUTE34_LOCALID_VICTOR, Route34_Movement_Victor_LeftUp2
Route34_EventScript_Victor_ToPlayer_Done:
	waitmovement 0
	setspeaker Route34_Speaker_Victor
	msgbox Route34_Text_Victor_Portal, MSGBOX_DEFAULT
	setspeaker Route34_Speaker_Birch
	pokenavcall Route34_Text_Birch_VictorCall
	waitmessage
	closemessage
	setspeaker Route34_Speaker_Victor
	msgbox Route34_Text_Victor_Dynamax, MSGBOX_DEFAULT
	giveitem ITEM_DYNAMAX_BAND
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	setspeaker Route34_Speaker_Victor
	msgbox Route34_Text_Victor_Dynamax_After, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_VICTOR, Route34_Movement_Victor_Leave
	waitmovement 0
	setflag FLAG_ROUTE34_VICTOR_SCENE_DONE
	removeobject ROUTE34_LOCALID_VICTOR
	return

Route34_EventScript_OfficerBlock_0::
	lockall
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Approach0
	waitmovement 0
	faceplayer
	setspeaker Route34_Speaker_Officer
	msgbox Route34_Text_Officer_Block, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Return0
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

Route34_EventScript_OfficerBlock_1::
	lockall
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Approach1
	waitmovement 0
	faceplayer
	setspeaker Route34_Speaker_Officer
	msgbox Route34_Text_Officer_Block, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Return1
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

Route34_EventScript_OfficerBlock_2::
	lockall
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Approach2
	waitmovement 0
	faceplayer
	setspeaker Route34_Speaker_Officer
	msgbox Route34_Text_Officer_Block, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Return2
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

Route34_EventScript_OfficerBlock_3::
	lockall
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Approach3
	waitmovement 0
	faceplayer
	setspeaker Route34_Speaker_Officer
	msgbox Route34_Text_Officer_Block, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Return3
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

Route34_EventScript_OfficerBlock_4::
	lockall
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Approach4
	waitmovement 0
	faceplayer
	setspeaker Route34_Speaker_Officer
	msgbox Route34_Text_Officer_Block, MSGBOX_DEFAULT
	applymovement ROUTE34_LOCALID_OFFICER, Route34_Movement_Officer_Return4
	waitmovement 0
	applymovement LOCALID_PLAYER, Route34_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

Route34_Movement_StepFromPortal_First:
	walk_down
	step_end

Route34_Movement_StepFromPortal_Second:
	walk_down
	step_end

Route34_Movement_Victor_LeftSame:
	face_right
	step_end

Route34_Movement_Victor_LeftUp1:
	walk_up
	face_right
	step_end

Route34_Movement_Victor_LeftUp2:
	walk_up
	walk_up
	face_right
	step_end

Route34_Movement_Victor_Leave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route34_Movement_Officer_Approach0:
	face_right
	step_end

Route34_Movement_Officer_Approach1:
	walk_right
	face_right
	step_end

Route34_Movement_Officer_Approach2:
	walk_right
	walk_right
	face_right
	step_end

Route34_Movement_Officer_Approach3:
	walk_right
	walk_right
	walk_right
	face_right
	step_end

Route34_Movement_Officer_Approach4:
	walk_right
	walk_right
	walk_right
	walk_right
	face_right
	step_end

Route34_Movement_Officer_Return0:
	face_right
	step_end

Route34_Movement_Officer_Return1:
	walk_left
	face_right
	step_end

Route34_Movement_Officer_Return2:
	walk_left
	walk_left
	face_right
	step_end

Route34_Movement_Officer_Return3:
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route34_Movement_Officer_Return4:
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route34_Movement_Player_StepDown:
	walk_down
	step_end

Route34_Speaker_Victor:
	.string "VICTOR$"

Route34_Speaker_Birch:
	.string "BIRCH$"

Route34_Speaker_None:
	.string "$"

Route34_Speaker_Officer:
	.string "OFFICER$"

Route34_Text_Victor_Portal:
	.string "Whoa this is my first time seeing\n"
	.string "the portal thing. So cool.\p"
	.string "You must be {PLAYER} right?\p"
	.string "I was going to make my way over to\n"
	.string "Ilex Forest but...$"

Route34_Text_Birch_VictorCall:
	.string "... Hey Victor, I sent {PLAYER} over\n"
	.string "to check out Ilex Forest.\p"
	.string "Michael and Ethan got their hands\n"
	.string "full right now so I need you to\l"
	.string "head towards Ecruteak and get the\l"
	.string "scoop.$"

Route34_Text_Victor_Dynamax:
	.string "Well so much for that.\p"
	.string "Hey before I forget take this\n"
	.string "DYNAMAX BRACELET.$"

Route34_Text_Victor_Dynamax_After:
	.string "You won't be able to use that just\n"
	.string "yet but in due time it will be very\l"
	.string "helpful against Cipher and even the\l"
	.string "League challenge.\p"
	.string "I'll catch you later {PLAYER}!$"

Route34_Text_Officer_Block:
	.string "Sorry but I can't let you into\n"
	.string "Goldenrod right now. It's just not\l"
	.string "safe.$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route34_Speaker_Camper:
	.string "NATE$"

Route34_Speaker_Gentleman:
	.string "ALFRED$"

Route34_Speaker_Youngster:
	.string "TIM$"

Route34_EventScript_Camper::
	setspeaker Route34_Speaker_Camper
	trainerbattle_single TRAINER_ROUTE34_CAMPER, Route34_Text_Camper_Intro, Route34_Text_Camper_Defeat, Route34_EventScript_Camper_After
	end

Route34_EventScript_Camper_After::
	setspeaker Route34_Speaker_Camper
	msgbox Route34_Text_Camper_After, MSGBOX_NPC
	closemessage
	release
	end

Route34_EventScript_Gentleman::
	setspeaker Route34_Speaker_Gentleman
	trainerbattle_single TRAINER_ROUTE34_GENTLEMAN, Route34_Text_Gentleman_Intro, Route34_Text_Gentleman_Defeat, Route34_EventScript_Gentleman_After
	end

Route34_EventScript_Gentleman_After::
	setspeaker Route34_Speaker_Gentleman
	msgbox Route34_Text_Gentleman_After, MSGBOX_NPC
	closemessage
	release
	end

Route34_EventScript_Youngster::
	setspeaker Route34_Speaker_Youngster
	trainerbattle_single TRAINER_ROUTE34_YOUNGSTER, Route34_Text_Youngster_Intro, Route34_Text_Youngster_Defeat, Route34_EventScript_Youngster_After
	end

Route34_EventScript_Youngster_After::
	setspeaker Route34_Speaker_Youngster
	msgbox Route34_Text_Youngster_After, MSGBOX_NPC
	closemessage
	release
	end

Route34_Text_Sign_IlexForest:
	.string "ILEX FOREST\n"
	.string "THROUGH THE GATE$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\n"
	.string "GOLDENROD CITY - AZALEA TOWN\p"
	.string "ILEX FOREST SOMEWHERE BETWEEN$"
	
Route34_Text_Sign_DayCare:
	.string "DAY-CARE\p"
	.string "LET US RAISE YOUR POKéMON FOR YOU!$"

Route34_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "BERRY trees grow new BERRIES\n"
	.string "several times a day.\p"
	.string "Note which trees bear which\n"
	.string "BERRIES.$"

Route34_Text_DoorLocked:
	.string "The Door is locked.$"

@ =========================================================
@ TRAINER TEXT
@ =========================================================

Route34_Text_Camper_Intro:
	.string "Route 34's got a good mix of\n"
	.string "POKéMON. Let's see yours!$"

Route34_Text_Camper_Defeat:
	.string "That's a solid team!$"

Route34_Text_Camper_After:
	.string "I'm going to train around here\n"
	.string "a bit longer.$"

Route34_Text_Gentleman_Intro:
	.string "A refined battle is a battle\n"
	.string "well fought.$"

Route34_Text_Gentleman_Defeat:
	.string "Splendid form!$"

Route34_Text_Gentleman_After:
	.string "The forest nearby feels calm.\n"
	.string "I may take a stroll.$"

Route34_Text_Youngster_Intro:
	.string "Wild POKéMON here are strong!\p"
	.string "So am I!$"

Route34_Text_Youngster_Defeat:
	.string "No way!$"

Route34_Text_Youngster_After:
	.string "Okay, I need more training.$"
