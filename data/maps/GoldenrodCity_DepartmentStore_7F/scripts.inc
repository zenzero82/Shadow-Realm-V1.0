GoldenrodCity_DepartmentStore_7F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodDeptStore7_Speaker_Gabe:
	.string "GABE$"

GoldenrodDeptStore7_Speaker_Theo:
	.string "THEO$"

GoldenrodDeptStore7_Speaker_Cora:
	.string "CORA$"

GoldenrodCity_DepartmentStore_7F_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq GoldenrodCity_DepartmentStore_7F_SetNight
	goto GoldenrodCity_DepartmentStore_7F_SetDay

GoldenrodCity_DepartmentStore_7F_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT
	return

GoldenrodCity_DepartmentStore_7F_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F
	return

GoldenrodDeptStore7_EventScript_Gabe::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore7_Speaker_Gabe
	msgbox GoldenrodCity_DepartmentStore_7F_Text_Gabe, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore7_EventScript_Theo::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore7_Speaker_Theo
	msgbox GoldenrodCity_DepartmentStore_7F_Text_Theo, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore7_EventScript_Cora::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore7_Speaker_Cora
	msgbox GoldenrodCity_DepartmentStore_7F_Text_Cora, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_7F_Text_Gabe:
	.string "The lookout here used to be romantic.\n"
	.string "Now I keep counting patrols.$"

GoldenrodCity_DepartmentStore_7F_Text_Theo:
	.string "I can see half the city from here.\n"
	.string "That makes the Radio Tower worse.$"

GoldenrodCity_DepartmentStore_7F_Text_Cora:
	.string "Sunset almost makes Goldenrod feel\n"
	.string "normal again. Almost.$"
