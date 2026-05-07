GoldenrodCity_DepartmentStore_3F_MapScripts::
	.byte 0

GoldenrodDeptStore3_Speaker_Clerk:
	.string "CLERK$"

GoldenrodDeptStore3_Speaker_Iris:
	.string "IRIS$"

GoldenrodDeptStore3_Speaker_Vin:
	.string "VIN$"

GoldenrodDeptStore3_EventScript_Clerk::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore3_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore3_EventScript_Iris::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore3_Speaker_Iris
	msgbox GoldenrodCity_DepartmentStore_3F_Text_Iris, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore3_EventScript_Vin::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore3_Speaker_Vin
	msgbox GoldenrodCity_DepartmentStore_3F_Text_Vin, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore3_EventScript_Sign::
	msgbox GoldenrodCity_DepartmentStore_3F_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_3F_Text_Sign:
	.string "3F: BATTLE COLLECTION$"

GoldenrodCity_DepartmentStore_3F_Text_Clerk:
	.string "Protective gear sells out fast when\n"
	.string "people expect trouble.$"

GoldenrodCity_DepartmentStore_3F_Text_Iris:
	.string "If CIPHER wants this city, they'll\n"
	.string "have to get past every trainer here.$"

GoldenrodCity_DepartmentStore_3F_Text_Vin:
	.string "I came for punch gloves.\n"
	.string "Staying angry is easier than scared.$"

	.align 2
GoldenrodDeptStore3_Pokemart:
	.2byte ITEM_TM_PSYCHIC
	.2byte ITEM_TM_SHADOW_BALL
	.2byte ITEM_TM_TAUNT
	pokemartlistend
