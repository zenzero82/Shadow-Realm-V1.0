GoldenrodCity_DepartmentStore_5F_MapScripts::
	.byte 0

GoldenrodDeptStore5_Speaker_ClerkF:
	.string "CLERK$"

GoldenrodDeptStore5_Speaker_ClerkM:
	.string "CLERK$"

GoldenrodDeptStore5_Speaker_Hugh:
	.string "HUGH$"

GoldenrodDeptStore5_Speaker_Penny:
	.string "PENNY$"

GoldenrodDeptStore5_EventScript_ClerkF::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore5_Speaker_ClerkF
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart_Female
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_EventScript_ClerkM::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore5_Speaker_ClerkM
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart_Male
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_EventScript_Hugh::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore5_Speaker_Hugh
	msgbox GoldenrodCity_DepartmentStore_5F_Text_Hugh, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_EventScript_Penny::
	lock
	faceplayer
	setspeaker GoldenrodDeptStore5_Speaker_Penny
	msgbox GoldenrodCity_DepartmentStore_5F_Text_Penny, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	msgbox GoldenrodCity_DepartmentStore_5F_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_DepartmentStore_5F_Text_Sign:
	.string "5F: TM CORNER$"

GoldenrodCity_DepartmentStore_5F_Text_ClerkF:
	.string "Strong moves are popular, but smart\n"
	.string "trainers still buy utility first.$"

GoldenrodCity_DepartmentStore_5F_Text_ClerkM:
	.string "I keep hearing the same question:\n"
	.string "'What breaks through a Miltank?'$"

GoldenrodCity_DepartmentStore_5F_Text_Hugh:
	.string "If a TM can end a fight quickly,\n"
	.string "that's the one I want.$"

GoldenrodCity_DepartmentStore_5F_Text_Penny:
	.string "I want a cute move and a strong move.\n"
	.string "There is no reason to choose.$"

	.align 2
GoldenrodDeptStore5_Pokemart_Female:
	.2byte ITEM_CALCIUM
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_IRON
	.2byte ITEM_PP_UP
	.2byte ITEM_PROTEIN
	pokemartlistend

GoldenrodDeptStore5_Pokemart_Male:
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_GALARICA_CUFF
	.2byte ITEM_GALARICA_WREATH
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_REAPER_CLOTH
	pokemartlistend
