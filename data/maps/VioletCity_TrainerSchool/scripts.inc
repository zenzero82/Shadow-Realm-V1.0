VioletCity_TrainerSchool_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_BlackBoard::
	msgbox VioletCity_TrainerSchool_EventScript_BlackBoard_Text, MSGBOX_SIGN
	end

VioletCity_TrainerSchool_EventScript_BlackBoard_Text:
	.string "Trainer tips are written here.$"

VioletCity_TrainerSchool_EventScript_ScientistF::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_ScientistF, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_SuperNerd::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_SuperNerd, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_LittleBoy::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_LittleBoy, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_Twin::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_LittleBoy2::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_LittleBoy2, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_LittleGirl2::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_LittleGirl2, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_Lass::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Lass, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_Youngster::
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster, MSGBOX_NPC
	end

VioletCity_TrainerSchool_Text_ScientistF:
	.string "Remember: Flying hits hard against\n"
	.string "GRASS and BUG types.$"

VioletCity_TrainerSchool_Text_SuperNerd:
	.string "Status moves can swing a battle.\n"
	.string "I keep notes on them.$"

VioletCity_TrainerSchool_Text_LittleBoy:
	.string "I'm practicing quick menus.\n"
	.string "Speed helps everywhere.$"

VioletCity_TrainerSchool_Text_Twin:
	.string "We quiz each other on matchups.\n"
	.string "It's fun!$"

VioletCity_TrainerSchool_Text_LittleBoy2:
	.string "I want to be a GYM LEADER someday.\n"
	.string "I'm starting small.$"

VioletCity_TrainerSchool_Text_LittleGirl2:
	.string "I'm learning how to care for\n"
	.string "POKEMON, not just battle.$"

VioletCity_TrainerSchool_Text_Lass:
	.string "The trainer school feels safe.\n"
	.string "I like studying here.$"

VioletCity_TrainerSchool_Text_Youngster:
	.string "Type advantage is huge! One good\n"
	.string "hit can end it.$"
