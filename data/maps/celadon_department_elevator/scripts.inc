celadon_department_elevator_MapScripts::
	.byte 0

CeladonDeptElevator_EventScript_Elevator::
	lock
	msgbox CeladonDeptElevator_Text_Welcome, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	special SetDeptStoreFloor
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowDeptStoreElevatorFloorSelect
	message gText_WhichFloorWouldYouLike
	waitmessage
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
	switch VAR_RESULT
	case 0, CeladonDeptElevator_EventScript_ChooseFloorFrom5th
	case 1, CeladonDeptElevator_EventScript_ChooseFloorFrom4th
	case 2, CeladonDeptElevator_EventScript_ChooseFloorFrom3rd
	case 3, CeladonDeptElevator_EventScript_ChooseFloorFrom2nd
	case 4, CeladonDeptElevator_EventScript_ChooseFloorFrom1st
	end

CeladonDeptElevator_EventScript_ChooseFloorFrom5th::
	multichoicedefault 0, 0, MULTI_5FLOORS, 0, FALSE
	goto CeladonDeptElevator_EventScript_ChooseFloor
	end

CeladonDeptElevator_EventScript_ChooseFloorFrom4th::
	multichoicedefault 0, 0, MULTI_5FLOORS, 1, FALSE
	goto CeladonDeptElevator_EventScript_ChooseFloor
	end

CeladonDeptElevator_EventScript_ChooseFloorFrom3rd::
	multichoicedefault 0, 0, MULTI_5FLOORS, 2, FALSE
	goto CeladonDeptElevator_EventScript_ChooseFloor
	end

CeladonDeptElevator_EventScript_ChooseFloorFrom2nd::
	multichoicedefault 0, 0, MULTI_5FLOORS, 3, FALSE
	goto CeladonDeptElevator_EventScript_ChooseFloor
	end

CeladonDeptElevator_EventScript_ChooseFloorFrom1st::
	multichoicedefault 0, 0, MULTI_5FLOORS, 4, FALSE
	goto CeladonDeptElevator_EventScript_ChooseFloor
	end

CeladonDeptElevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, CeladonDeptElevator_EventScript_F5
	case 1, CeladonDeptElevator_EventScript_F4
	case 2, CeladonDeptElevator_EventScript_F3
	case 3, CeladonDeptElevator_EventScript_F2
	case 4, CeladonDeptElevator_EventScript_F1
	case 5, CeladonDeptElevator_EventScript_ExitFloorSelect
	case MULTI_B_PRESSED, CeladonDeptElevator_EventScript_ExitFloorSelect
	release
	end

CeladonDeptElevator_EventScript_F1::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
	setdynamicwarp MAP_CELADON_DEPARTMENT1F, 6, 0
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, CeladonDeptElevator_EventScript_ExitFloorSelect
	call CeladonDeptElevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 1
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
	goto CeladonDeptElevator_EventScript_ExitFloorSelect
	end

CeladonDeptElevator_EventScript_F2::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
	setdynamicwarp MAP_CELADON_DEPARTMENT2F, 6, 0
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, CeladonDeptElevator_EventScript_ExitFloorSelect
	call CeladonDeptElevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 1
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
	goto CeladonDeptElevator_EventScript_ExitFloorSelect
	end

CeladonDeptElevator_EventScript_F3::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
	setdynamicwarp MAP_CELADON_DEPARTMENT3F, 6, 0
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, CeladonDeptElevator_EventScript_ExitFloorSelect
	call CeladonDeptElevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 1
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
	goto CeladonDeptElevator_EventScript_ExitFloorSelect
	end

CeladonDeptElevator_EventScript_F4::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
	setdynamicwarp MAP_CELADON_DEPARTMENT4F, 6, 0
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F, CeladonDeptElevator_EventScript_ExitFloorSelect
	call CeladonDeptElevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 1
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
	goto CeladonDeptElevator_EventScript_ExitFloorSelect
	end

CeladonDeptElevator_EventScript_F5::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
	setdynamicwarp MAP_CELADON_DEPARTMENT5F, 6, 0
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F, CeladonDeptElevator_EventScript_ExitFloorSelect
	call CeladonDeptElevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 1
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
	goto CeladonDeptElevator_EventScript_ExitFloorSelect
	end

CeladonDeptElevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end

CeladonDeptElevator_EventScript_MoveElevator::
	special CloseDeptStoreElevatorWindow
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	special MoveElevator
	waitstate
	return

CeladonDeptElevator_Text_Welcome:
	.string "Welcome to the CELADON DEPARTMENT\n"
	.string "STORE.$"
