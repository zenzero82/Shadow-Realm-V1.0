route5_gate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route5Gate_OnTransition
	.byte 0

Route5Gate_OnTransition::
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, Route5Gate_OnTransition_SceneDone
	setvar VAR_TEMP_0, 0
	end

Route5Gate_OnTransition_SceneDone:
	setflag FLAG_HIDE_CERULEAN_ROUTE5_BLOCKADE
	setvar VAR_TEMP_0, 1
	end

Gate_SaffronCity_Route5_EventScript_Guard::
	faceplayer
	setspeaker Route5Gate_Speaker_Policeman
	msgbox Route5_Text_SaffronGateOfficer, MSGBOX_NPC
	end

Gate_SaffronCity_Route5_EventScript_BlockPassage::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route5Gate_Movement_PlayerStepBack
	waitmovement 0
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker Route5Gate_Speaker_Policeman
	msgbox Route5_Text_SaffronGateOfficer_BlockPassage, MSGBOX_DEFAULT
	releaseall
	end

Route5Gate_Movement_PlayerStepBack:
	walk_fast_up
	step_end

Route5Gate_Speaker_Policeman:
	.string "OFFICER$"

Route5_Text_SaffronGateOfficer:
	.string "SAFFRON is tense right now.\p"
	.string "SILPH CO. is being watched,\n"
	.string "and the MAGNET TRAIN still\l"
	.string "isn't running.$"

Route5_Text_SaffronGateOfficer_BlockPassage:
	.string "Hold it.\p"
	.string "There's an investigation in the\n"
	.string "tunnels right now.\p"
	.string "You can't pass through at this\n"
	.string "time.$"
