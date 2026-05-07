GoldenrodCity_DepartmentStore_1F_MapScripts::
	.byte 0

GoldenrodDeptStore1_Speaker_Clerk:
	.string "CLERK$"

GoldenrodDeptStore1_Speaker_Mara:
	.string "MARA$"

GoldenrodDeptStore1_Speaker_Nico:
	.string "NICO$"

GoldenrodDeptStore1_EventScript_Clerk::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore1_Speaker_Clerk
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Clerk, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Mara::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore1_Speaker_Mara
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Mara, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Nico::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore1_Speaker_Nico
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Nico, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Directory, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_1F_Text_Directory:
	.string "GOLDENROD DEPT. STORE\p"
	.string "1F: SERVICE COUNTER$"

GoldenrodCity_DepartmentStore_1F_Text_Clerk:
	.string "We still greet every customer.\n"
	.string "Goldenrod has not given up.$"

GoldenrodCity_DepartmentStore_1F_Text_Mara:
	.string "The lines are longer now.\n"
	.string "Everyone's stocking up on supplies.$"

GoldenrodCity_DepartmentStore_1F_Text_Nico:
	.string "Mom says one ESCAPE ROPE is smart.\n"
	.string "I think two is smarter.$"
