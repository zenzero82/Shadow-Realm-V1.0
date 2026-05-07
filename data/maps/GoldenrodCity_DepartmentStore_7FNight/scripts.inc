GoldenrodCity_DepartmentStore_7FNight_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7FNight_OnTransition
	.byte 0

GoldenrodDeptStore7Night_Speaker_Mina:
	.string "MINA$"

GoldenrodCity_DepartmentStore_7FNight_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq GoldenrodCity_DepartmentStore_7FNight_SetNight
	goto GoldenrodCity_DepartmentStore_7FNight_SetDay

GoldenrodCity_DepartmentStore_7FNight_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT
	return

GoldenrodCity_DepartmentStore_7FNight_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F
	return

GoldenrodDeptStore7Night_EventScript_Mina::
	setspeaker GoldenrodDeptStore7Night_Speaker_Mina
	trainerbattle_single TRAINER_GOLDENROD_ODD_KEYSTONE, GoldenrodCity_DepartmentStore_7FNight_Text_Mina_Intro, GoldenrodCity_DepartmentStore_7FNight_Text_Mina_Defeat, GoldenrodDeptStore7Night_EventScript_Mina_After
	end

GoldenrodDeptStore7Night_EventScript_Mina_After::
	setspeaker GoldenrodDeptStore7Night_Speaker_Mina
	msgbox GoldenrodCity_DepartmentStore_7FNight_Text_Mina_After, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_DepartmentStore_7FNight_Text_Mina_Intro:
	.string "Even here, the keystone won't stop\n"
	.string "whispering.\p"
	.string "If you want answers, beat them out\n"
	.string "of the dark!$"

GoldenrodCity_DepartmentStore_7FNight_Text_Mina_Defeat:
	.string "The rooftop fell silent... for now.$"

GoldenrodCity_DepartmentStore_7FNight_Text_Mina_After:
	.string "There are more voices out there.\p"
	.string "The keystone is far from satisfied.$"
