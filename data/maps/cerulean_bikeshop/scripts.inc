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
