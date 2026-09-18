celadon_department2f_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

celadon_department2f_Speaker_AttendantM:
	.string "PARKER$"

celadon_department2f_EventScript_AttendantM::
	lock
	faceplayer
	setspeaker celadon_department2f_Speaker_AttendantM
	message gText_HowMayIServeYou
	waitmessage
	pokemart celadon_department2f_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

celadon_department2f_EventScript_Directory::
	msgbox celadon_department2f_Text_Directory, MSGBOX_SIGN
	end

	.align 2
celadon_department2f_Pokemart:
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	pokemartlistend

celadon_department2f_Text_Directory:
	.string "Top Grade Items for Trainers!\p"
	.string "2F: TRAINER'S MARKET$"
