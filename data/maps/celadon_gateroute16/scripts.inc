celadon_gateroute16_MapScripts::
	.byte 0

#define LOCALID_POLICEMAN 1

CeladonGateRoute16_Speaker_Policeman:
	.string "OFFICER$"

CeladonGateRoute16_EventScript_BikeBlock::
	lockall
	checkitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, 0, CeladonGateRoute16_EventScript_NoBike
	releaseall
	end

CeladonGateRoute16_EventScript_NoBike::
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	turnobject LOCALID_POLICEMAN, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker CeladonGateRoute16_Speaker_Policeman
	msgbox CeladonGateRoute16_Text_NoBike, MSGBOX_NPC
	closemessage
	goto_if_eq VAR_TEMP_1, DIR_EAST, CeladonGateRoute16_EventScript_PushLeft
	goto_if_eq VAR_TEMP_1, DIR_WEST, CeladonGateRoute16_EventScript_PushRight
	goto_if_eq VAR_TEMP_1, DIR_NORTH, CeladonGateRoute16_EventScript_PushDown
	goto_if_eq VAR_TEMP_1, DIR_SOUTH, CeladonGateRoute16_EventScript_PushUp
	goto CeladonGateRoute16_EventScript_PushDown

CeladonGateRoute16_EventScript_PushLeft::
	call CeladonGateRoute16_EventScript_PushFollowerLeft
	applymovement LOCALID_PLAYER, CeladonGateRoute16_Movement_Player_StepLeft
	waitmovement 0
	releaseall
	end

CeladonGateRoute16_EventScript_PushRight::
	call CeladonGateRoute16_EventScript_PushFollowerRight
	applymovement LOCALID_PLAYER, CeladonGateRoute16_Movement_Player_StepRight
	waitmovement 0
	releaseall
	end

CeladonGateRoute16_EventScript_PushUp::
	call CeladonGateRoute16_EventScript_PushFollowerUp
	applymovement LOCALID_PLAYER, CeladonGateRoute16_Movement_Player_StepUp
	waitmovement 0
	releaseall
	end

CeladonGateRoute16_EventScript_PushDown::
	call CeladonGateRoute16_EventScript_PushFollowerDown
	applymovement LOCALID_PLAYER, CeladonGateRoute16_Movement_Player_StepDown
	waitmovement 0
	releaseall
	end

CeladonGateRoute16_EventScript_Policeman::
	faceplayer
	checkitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, 0, CeladonGateRoute16_EventScript_Policeman_NoBike
	setspeaker CeladonGateRoute16_Speaker_Policeman
	msgbox CeladonGateRoute16_Text_Policeman, MSGBOX_NPC
	end

CeladonGateRoute16_EventScript_Policeman_NoBike::
	setspeaker CeladonGateRoute16_Speaker_Policeman
	msgbox CeladonGateRoute16_Text_NoBike, MSGBOX_NPC
	end

CeladonGateRoute16_EventScript_PushFollowerLeft::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CeladonGateRoute16_EventScript_PushFollower_Return
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, CeladonGateRoute16_Movement_Player_StepLeft
	waitmovement 0
	goto CeladonGateRoute16_EventScript_PushFollower_Return

CeladonGateRoute16_EventScript_PushFollowerRight::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CeladonGateRoute16_EventScript_PushFollower_Return
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, CeladonGateRoute16_Movement_Player_StepRight
	waitmovement 0
	goto CeladonGateRoute16_EventScript_PushFollower_Return

CeladonGateRoute16_EventScript_PushFollowerUp::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CeladonGateRoute16_EventScript_PushFollower_Return
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, CeladonGateRoute16_Movement_Player_StepUp
	waitmovement 0
	goto CeladonGateRoute16_EventScript_PushFollower_Return

CeladonGateRoute16_EventScript_PushFollowerDown::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CeladonGateRoute16_EventScript_PushFollower_Return
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, CeladonGateRoute16_Movement_Player_StepDown
	waitmovement 0

CeladonGateRoute16_EventScript_PushFollower_Return::
	return

CeladonGateRoute16_Movement_Player_StepLeft:
	walk_left
	step_end

CeladonGateRoute16_Movement_Player_StepRight:
	walk_right
	step_end

CeladonGateRoute16_Movement_Player_StepUp:
	walk_up
	step_end

CeladonGateRoute16_Movement_Player_StepDown:
	walk_down
	step_end

CeladonGateRoute16_Text_NoBike:
	.string "Hey there, ROUTE 16 leads to\n"
	.string "CYCLING ROAD. It doesn't seem\l"
	.string "like you have a BICYCLE so\n"
	.string "unfortunately I can't let you pass.\p"
	.string "Please come back when you have\n"
	.string "a BIKE.$"

CeladonGateRoute16_Text_Policeman:
	.string "CYCLING ROAD lies ahead, try not\n"
	.string "to crash, kid.$"
