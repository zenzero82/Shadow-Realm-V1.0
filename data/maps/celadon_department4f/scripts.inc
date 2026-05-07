celadon_department4f_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

celadon_department4f_Speaker_AttendantM:
	.string "MILES$"

celadon_department4f_Speaker_AttendantF:
	.string "TALIA$"

celadon_department4f_EventScript_AttendantM::
	lock
	faceplayer
	setspeaker celadon_department4f_Speaker_AttendantM
	message gText_HowMayIServeYou
	waitmessage
	pokemart celadon_department4f_Pokemart_Male
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

celadon_department4f_EventScript_AttendantF::
	lock
	faceplayer
	setspeaker celadon_department4f_Speaker_AttendantF
	message gText_HowMayIServeYou
	waitmessage
	pokemart celadon_department4f_Pokemart_Female
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

celadon_department4f_EventScript_Directory::
	msgbox celadon_department4f_Text_Directory, MSGBOX_SIGN
	end

	.align 2
celadon_department4f_Pokemart_Female:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	pokemartlistend

celadon_department4f_Pokemart_Male:
	.2byte ITEM_AMULET_COIN
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_SOOTHE_BELL
	pokemartlistend

celadon_department4f_Text_Directory:
	.string "Express Yourself With Gifts!\p"
	.string "4F: WISEMAN GIFTS$"
