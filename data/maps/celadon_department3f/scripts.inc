celadon_department3f_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

celadon_department3f_Speaker_AttendantM:
	.string "OWEN$"

celadon_department3f_EventScript_AttendantM::
	lock
	faceplayer
	setspeaker celadon_department3f_Speaker_AttendantM
	message gText_HowMayIServeYou
	waitmessage
	pokemart celadon_department3f_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

celadon_department3f_EventScript_Directory::
	msgbox celadon_department3f_Text_Directory, MSGBOX_SIGN
	end

	.align 2
celadon_department3f_Pokemart:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_DIG
	.2byte ITEM_TM_U_TURN
	.2byte ITEM_TM_POISON_JAB
	.2byte ITEM_TM_ROCK_SLIDE
	pokemartlistend

celadon_department3f_Text_Directory:
	.string "3F: TM SHOP\p"
	.string "Make Your POKeMON Stronger!$"
