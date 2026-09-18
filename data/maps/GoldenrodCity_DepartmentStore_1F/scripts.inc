GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_1F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_1F_OnTransition:
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_DepartmentStore_1F_OnTransition_ApplyCipherDisguise
	end

GoldenrodCity_DepartmentStore_1F_OnTransition_ApplyCipherDisguise:
	special Special_ApplyCipherDisguise
	end

GoldenrodDeptStore1_Speaker_Clerk:
	.string "CLERK$"

GoldenrodDeptStore1_Speaker_Mara:
	.string "MARA$"

GoldenrodDeptStore1_Speaker_Nico:
	.string "NICO$"

GoldenrodDeptStore1_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodDeptStore1_EventScript_Clerk_Disguised
	setspeaker GoldenrodDeptStore1_Speaker_Clerk
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Clerk, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Clerk_Disguised:
	setspeaker GoldenrodDeptStore1_Speaker_Clerk
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Clerk_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Mara::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodDeptStore1_EventScript_Mara_Disguised
	setspeaker GoldenrodDeptStore1_Speaker_Mara
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Mara, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Mara_Disguised:
	setspeaker GoldenrodDeptStore1_Speaker_Mara
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Mara_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Nico::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodDeptStore1_EventScript_Nico_Disguised
	setspeaker GoldenrodDeptStore1_Speaker_Nico
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Nico, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore1_EventScript_Nico_Disguised:
	setspeaker GoldenrodDeptStore1_Speaker_Nico
	msgbox GoldenrodCity_DepartmentStore_1F_Text_Nico_Disguised, MSGBOX_DEFAULT
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

GoldenrodCity_DepartmentStore_1F_Text_Clerk_Disguised:
	.string "Service is denied to CIPHER.\p"
	.string "Get out of this store.$"

GoldenrodCity_DepartmentStore_1F_Text_Mara:
	.string "The lines are longer now.\n"
	.string "Everyone's stocking up on supplies.$"

GoldenrodCity_DepartmentStore_1F_Text_Mara_Disguised:
	.string "Look at that uniform.\n"
	.string "You make the whole floor feel dirty.$"

GoldenrodCity_DepartmentStore_1F_Text_Nico:
	.string "Mom says one ESCAPE ROPE is smart.\n"
	.string "I think two is smarter.$"

GoldenrodCity_DepartmentStore_1F_Text_Nico_Disguised:
	.string "Dad said if I see CIPHER, I should\n"
	.string "stay close and not trust a word.$"
