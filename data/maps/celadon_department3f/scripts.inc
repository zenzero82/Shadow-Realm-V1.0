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
	.2byte ITEM_TM_BRICK_BREAK
	.2byte ITEM_TM_CALM_MIND
	.2byte ITEM_TM_FLAMETHROWER
	.2byte ITEM_TM_ICE_BEAM
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_ROCK_TOMB
	.2byte ITEM_TM_THUNDERBOLT
	pokemartlistend

celadon_department3f_Text_Directory:
	.string "3F: TM SHOP\p"
	.string "Make Your POKeMON Stronger!$"
