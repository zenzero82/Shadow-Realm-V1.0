GoldenrodCity_DepartmentStore_2F_MapScripts::
	.byte 0

GoldenrodDeptStore2_Speaker_Clerk:
	.string "CLERK$"

GoldenrodDeptStore2_Speaker_Bram:
	.string "BRAM$"

GoldenrodDeptStore2_Speaker_Ryan:
	.string "RYAN$"

GoldenrodDeptStore2_Speaker_Jules:
	.string "JULES$"

GoldenrodDeptStore2_EventScript_Clerk::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore2_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore2_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore2_EventScript_Bram::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore2_Speaker_Bram
	msgbox GoldenrodCity_DepartmentStore_2F_Text_Bram, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore2_EventScript_Ryan::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore2_Speaker_Ryan
	msgbox GoldenrodCity_DepartmentStore_2F_Text_Ryan, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore2_EventScript_Jules::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore2_Speaker_Jules
	msgbox GoldenrodCity_DepartmentStore_2F_Text_Jules, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	msgbox GoldenrodCity_DepartmentStore_2F_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_2F_Text_Sign:
	.string "2F: TRAINER'S MARKET$"

GoldenrodCity_DepartmentStore_2F_Text_Clerk:
	.string "Battle items move fast whenever the\n"
	.string "city feels cornered.$"

GoldenrodCity_DepartmentStore_2F_Text_Bram:
	.string "I used to browse for fun.\n"
	.string "Now I shop like I'm preparing.$"

GoldenrodCity_DepartmentStore_2F_Text_Ryan:
	.string "If I beat WHITNEY, maybe Mom will\n"
	.string "stop calling me little.$"

GoldenrodCity_DepartmentStore_2F_Text_Jules:
	.string "Even now, trainers come in looking\n"
	.string "for anything that hits hard.$"

	.align 2
GoldenrodDeptStore2_Pokemart:
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_SUPER_REPEL
	pokemartlistend
