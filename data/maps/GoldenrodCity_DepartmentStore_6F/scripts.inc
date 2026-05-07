GoldenrodCity_DepartmentStore_6F_MapScripts::
	.byte 0

GoldenrodDeptStore6_Speaker_Frank:
	.string "FRANK$"

GoldenrodDeptStore6_Speaker_Ollie:
	.string "OLLIE$"

GoldenrodDeptStore6_Speaker_Tessa:
	.string "TESSA$"

GoldenrodDeptStore6_Speaker_Dawn:
	.string "DAWN$"

GoldenrodDeptStore6_EventScript_Frank::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore6_Speaker_Frank
	msgbox GoldenrodCity_DepartmentStore_6F_Text_Frank, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore6_EventScript_Ollie::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore6_Speaker_Ollie
	msgbox GoldenrodCity_DepartmentStore_6F_Text_Ollie, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore6_EventScript_Tessa::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore6_Speaker_Tessa
	msgbox GoldenrodCity_DepartmentStore_6F_Text_Tessa, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore6_EventScript_Dawn::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore6_Speaker_Dawn
	msgbox GoldenrodCity_DepartmentStore_6F_Text_Dawn, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_6F_Text_Sign:
	.string "6F: ROOFTOP PLAZA$"

GoldenrodCity_DepartmentStore_6F_Text_Frank:
	.string "Fresh air helps. You can almost forget\n"
	.string "who's marching in the streets.$"

GoldenrodCity_DepartmentStore_6F_Text_Ollie:
	.string "I used to battle up here for fun.\n"
	.string "Now I train because I have to.$"

GoldenrodCity_DepartmentStore_6F_Text_Tessa:
	.string "Even under pressure, Goldenrod keeps\n"
	.string "its rooftop open. That's stubborn.$"

GoldenrodCity_DepartmentStore_6F_Text_Dawn:
	.string "Cities show their heart on bad days.\n"
	.string "Goldenrod's still standing.$"
