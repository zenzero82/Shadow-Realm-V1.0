GoldenrodCity_DepartmentStore_4F_MapScripts::
	.byte 0

GoldenrodDeptStore4_Speaker_Clerk:
	.string "CLERK$"

GoldenrodDeptStore4_Speaker_Ollie:
	.string "OLLIE$"

GoldenrodDeptStore4_Speaker_Reed:
	.string "REED$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore4_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore4_EventScript_Ollie::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore4_Speaker_Ollie
	msgbox GoldenrodCity_DepartmentStore_4F_Text_Ollie, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore4_EventScript_Reed::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore4_Speaker_Reed
	msgbox GoldenrodCity_DepartmentStore_4F_Text_Reed, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	msgbox GoldenrodCity_DepartmentStore_4F_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_4F_Text_Sign:
	.string "4F: MEDICINE BOX$"

GoldenrodCity_DepartmentStore_4F_Text_Clerk:
	.string "We doubled our stock of status cures.\n"
	.string "Stress does half of CIPHER's work.$"

GoldenrodCity_DepartmentStore_4F_Text_Ollie:
	.string "My bug POKéMON get jumpy around the\n"
	.string "Radio Tower. They know something.$"

GoldenrodCity_DepartmentStore_4F_Text_Reed:
	.string "Revives are expensive, but regret is\n"
	.string "more expensive.$"

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_WISE_GLASSES
	pokemartlistend
