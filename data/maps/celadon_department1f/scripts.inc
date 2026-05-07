celadon_department1f_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

celadon_department1f_Speaker_WorkerF:
	.string "IRIS$"

celadon_department1f_EventScript_WorkerF::
	faceplayer
	setspeaker celadon_department1f_Speaker_WorkerF
	msgbox celadon_department1f_Text_WorkerF, MSGBOX_NPC
	end

celadon_department1f_EventScript_Directory::
	msgbox celadon_department1f_Text_Directory, MSGBOX_SIGN
	end

celadon_department1f_Text_WorkerF:
	.string "Welcome to the CELADON DEPT.STORE.\p"
	.string "Take the stairs or the elevator.$"

celadon_department1f_Text_Directory:
	.string "1F: SERVICE COUNTER\p"
	.string "2F: TRAINER'S MARKET\p"
	.string "3F: TM SHOP\p"
	.string "4F: WISEMAN GIFTS\p"
	.string "5F: DRUG STORE\p"
	.string "6F: ROOFTOP SQUARE$"

CeladonDeptElevator_OnFrame::
	map_script_2 VAR_TEMP_0, 1, CeladonDeptElevator_EventScript_Exit
	.2byte 0

CeladonDeptElevator_EventScript_Exit::
	opendoor 6, 1
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, CeladonDeptElevator_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CeladonDeptElevator_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CeladonDeptElevator_Movement_WalkDown1
	waitmovement 0
	closedoor 6, 1
	closedoor 10, 6
	waitdooranim
	waitdooranim
	setvar VAR_TEMP_0, 0
	release
	end

CeladonDeptElevator_Movement_WalkDown1:
	walk_down
	step_end
