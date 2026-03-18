cerulean_bikeshop_MapScripts::
	.byte 0

.set LOCALID_LOOKER, 1

CeruleanBikeShop_Speaker_Looker:
	.string "LOOKER$"

CeruleanBikeShop_EventScript_LookerTrigger::
	checktrainerflag TRAINER_LOOKER_CERULEAN
	goto_if_eq CeruleanBikeShop_EventScript_LookerTrigger_Done
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Approach
CeruleanBikeShop_EventScript_LookerTrigger_Done::
	end

CeruleanBikeShop_EventScript_LookerTrigger_Left::
	checktrainerflag TRAINER_LOOKER_CERULEAN
	goto_if_eq CeruleanBikeShop_EventScript_LookerTrigger_Done
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Approach

CeruleanBikeShop_EventScript_LookerTrigger_Right::
	checktrainerflag TRAINER_LOOKER_CERULEAN
	goto_if_eq CeruleanBikeShop_EventScript_LookerTrigger_Done
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Approach

CeruleanBikeShop_EventScript_Looker::
	lockall
	setvar VAR_TEMP_1, 3
	faceplayer
	goto CeruleanBikeShop_EventScript_Looker_Start

CeruleanBikeShop_EventScript_Looker_Approach::
	compare VAR_TEMP_1, 0
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ApproachLeft
	compare VAR_TEMP_1, 2
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ApproachRight
	goto CeruleanBikeShop_EventScript_Looker_ApproachCenter

CeruleanBikeShop_EventScript_Looker_ApproachLeft::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ApproachLeft
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Start

CeruleanBikeShop_EventScript_Looker_ApproachCenter::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ApproachCenter
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Start

CeruleanBikeShop_EventScript_Looker_ApproachRight::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ApproachRight
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_Start

CeruleanBikeShop_EventScript_Looker_Start::
	faceplayer
	setspeaker CeruleanBikeShop_Speaker_Looker
	trainerbattle_single TRAINER_LOOKER_CERULEAN, CeruleanBikeShop_Text_Looker_Intro, CeruleanBikeShop_Text_Looker_Defeat, CeruleanBikeShop_EventScript_Looker_After
	end

CeruleanBikeShop_EventScript_Looker_After::
	setspeaker CeruleanBikeShop_Speaker_Looker
	msgbox CeruleanBikeShop_Text_Looker_After, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CERULEAN_NPC_BIKESHOP_LOOKER
	call QuestJournal_EventScript_CheckCeruleanCityNPCs
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 5
	goto_if_ne CeruleanBikeShop_EventScript_Looker_ExitCheckDone
	compare VAR_0x8005, 6
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ExitAround
	compare VAR_0x8005, 7
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ExitAround
CeruleanBikeShop_EventScript_Looker_ExitCheckDone::
	compare VAR_TEMP_1, 0
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ExitLeft
	compare VAR_TEMP_1, 2
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ExitRight
	compare VAR_TEMP_1, 3
	goto_if_eq CeruleanBikeShop_EventScript_Looker_ExitDirect
	goto CeruleanBikeShop_EventScript_Looker_ExitCenter

CeruleanBikeShop_EventScript_Looker_ExitLeft::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ExitLeft
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_ExitDone

CeruleanBikeShop_EventScript_Looker_ExitCenter::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ExitCenter
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_ExitDone

CeruleanBikeShop_EventScript_Looker_ExitRight::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ExitRight
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_ExitDone

CeruleanBikeShop_EventScript_Looker_ExitDirect::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ExitDirect
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_ExitDone

CeruleanBikeShop_EventScript_Looker_ExitAround::
	applymovement LOCALID_LOOKER, CeruleanBikeShop_Movement_Looker_ExitAround
	waitmovement 0
	goto CeruleanBikeShop_EventScript_Looker_ExitDone

CeruleanBikeShop_EventScript_Looker_ExitDone::
	turnobject LOCALID_LOOKER, DIR_SOUTH
	setflag FLAG_HIDE_CERULEAN_BIKESHOP_LOOKER
	removeobject LOCALID_LOOKER
	playse SE_EXIT
	waitse
	releaseall
	end

CeruleanBikeShop_Text_Looker_Intro:
	.string "Hold it!\p"
	.string "Your look... your timing...\n"
	.string "Are you with CIPHER?\p"
	.string "Prove you're not. Show me\n"
	.string "your battle skill!$"

CeruleanBikeShop_Text_Looker_Defeat:
	.string "Hmm. Not a CIPHER agent.$"

CeruleanBikeShop_Text_Looker_After:
	.string "I am Looker of the International\n"
	.string "Police.\p"
	.string "I chased a TEAM GALACTIC grunt\n"
	.string "who tried to bomb LAKE VALOR.\p"
	.string "Some distortion pulled me here...\n"
	.string "a different time, a different KANTO.\p"
	.string "Until I find a way back, I will\n"
	.string "keep watch. Stay sharp.$"

CeruleanBikeShop_Movement_Looker_ApproachLeft:
	walk_down
	walk_down
	walk_left
	face_down
	step_end

CeruleanBikeShop_Movement_Looker_ApproachCenter:
	walk_down
	face_down
	step_end

CeruleanBikeShop_Movement_Looker_ApproachRight:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

CeruleanBikeShop_Movement_Looker_ExitLeft:
	walk_right
	walk_down
	step_end

CeruleanBikeShop_Movement_Looker_ExitCenter:
	walk_down
	walk_down
	step_end

CeruleanBikeShop_Movement_Looker_ExitRight:
	walk_left
	walk_down
	step_end

CeruleanBikeShop_Movement_Looker_ExitDirect:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanBikeShop_Movement_Looker_ExitAround:
	walk_left
	walk_down
	walk_down
	walk_right
	step_end
