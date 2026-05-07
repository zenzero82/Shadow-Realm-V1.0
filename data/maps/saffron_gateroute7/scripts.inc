saffron_gateroute7_MapScripts::
	.byte 0

#define LOCALID_ROUTE7_GATE_GUARD 1
#define LOCALID_ROUTE7_GATE_CIPHER_GRUNT 2
#define LOCALID_ROUTE7_GATE_BONSLY 3

Gate_SaffronCity_Route7_Speaker_Guard:
	.string "Officer Lane$"

Gate_SaffronCity_Route7_Speaker_CipherGrunt:
	.string "CIPHER PEON$"

Gate_SaffronCity_Route7_EventScript_Guard::
	setspeaker Gate_SaffronCity_Route7_Speaker_Guard
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_BonslyIntercept::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, Gate_SaffronCity_Route7_EventScript_BonslyIntercept_End
	checkflag FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE
	goto_if_eq Gate_SaffronCity_Route7_EventScript_BonslyIntercept_End
	checkflag FLAG_HIDE_SAFFRON_CITY_BONSLY
	goto_if_eq Gate_SaffronCity_Route7_EventScript_BonslyIntercept_End
	setvar VAR_TEMP_0, 1
	lockall
	setspeaker Gate_SaffronCity_Route7_Speaker_CipherGrunt
	msgbox Gate_SaffronCity_Route7_Text_CipherGruntThereItIs, MSGBOX_NPC
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	getobjectcurrentxy OBJ_EVENT_ID_NPC_FOLLOWER, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	destroyfollowernpc
	clearflag FLAG_HIDE_SAFFRON_ROUTE7_INTERCEPT_BONSLY
	setobjectxy LOCALID_ROUTE7_GATE_BONSLY, VAR_0x8004, VAR_0x8005
	showobjectat LOCALID_ROUTE7_GATE_BONSLY, MAP_SAFFRON_GATEROUTE7
	applymovement LOCALID_ROUTE7_GATE_BONSLY, Gate_SaffronCity_Route7_Movement_BonslyEscape
	waitmovement 0
	setflag FLAG_HIDE_SAFFRON_CITY_BONSLY
	setflag FLAG_HIDE_SAFFRON_ROUTE7_INTERCEPT_BONSLY
	hideobjectat LOCALID_ROUTE7_GATE_BONSLY, MAP_SAFFRON_GATEROUTE7
	removeobject LOCALID_ROUTE7_GATE_BONSLY
	clearflag FLAG_HIDE_SAFFRON_ROUTE7_INTERCEPT_GRUNT
	showobjectat LOCALID_ROUTE7_GATE_CIPHER_GRUNT, MAP_SAFFRON_GATEROUTE7
	applymovement LOCALID_ROUTE7_GATE_CIPHER_GRUNT, Gate_SaffronCity_Route7_Movement_CipherGruntChaseBonsly
	waitmovement 0
	setflag FLAG_HIDE_SAFFRON_ROUTE7_INTERCEPT_GRUNT
	hideobjectat LOCALID_ROUTE7_GATE_CIPHER_GRUNT, MAP_SAFFRON_GATEROUTE7
	removeobject LOCALID_ROUTE7_GATE_CIPHER_GRUNT
	releaseall
	end

Gate_SaffronCity_Route7_EventScript_BonslyIntercept_End::
	end

Gate_SaffronCity_Route7_Movement_BonslyEscape:
	walk_fast_left
	walk_fast_left
	step_end

Gate_SaffronCity_Route7_Movement_CipherGruntChaseBonsly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route7_Text_SaffronGuard_PowerPlant:
	.string "Did you hear about the trouble\n"
	.string "at the POWER PLANT?\p"
	.string "If it is connected to SILPH,\n"
	.string "SAFFRON could be in danger.$"

Gate_SaffronCity_Route7_Text_CipherGruntThereItIs:
	.string "There it is!\p"
	.string "You're not getting away!$"
