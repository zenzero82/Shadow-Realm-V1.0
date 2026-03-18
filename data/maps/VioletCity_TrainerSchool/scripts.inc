VioletCity_TrainerSchool_MapScripts::
	.byte 0

VioletCity_TrainerSchool_Speaker_ScientistF:
	.string "AVA$"

VioletCity_TrainerSchool_Speaker_SuperNerd:
	.string "DEX$"

VioletCity_TrainerSchool_Speaker_LittleBoy:
	.string "JAY$"

VioletCity_TrainerSchool_Speaker_Twin:
	.string "LILY$"

VioletCity_TrainerSchool_Speaker_LittleBoy2:
	.string "BEN$"

VioletCity_TrainerSchool_Speaker_LittleGirl2:
	.string "MAY$"

VioletCity_TrainerSchool_Speaker_Lass:
	.string "NORA$"

VioletCity_TrainerSchool_Speaker_Youngster:
	.string "KYLE$"

VioletCity_TrainerSchool_EventScript_BlackBoard::
	msgbox VioletCity_TrainerSchool_EventScript_BlackBoard_Text, MSGBOX_SIGN
	end

VioletCity_TrainerSchool_EventScript_BlackBoard_Text:
	.string "Trainer tips are written here.$"

VioletCity_TrainerSchool_EventScript_ScientistF::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_ScientistF
	msgbox VioletCity_TrainerSchool_Text_ScientistF, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_SCIENTIST
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_SuperNerd::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_SuperNerd
	msgbox VioletCity_TrainerSchool_Text_SuperNerd, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_SUPER_NERD
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_LittleBoy::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_LittleBoy
	msgbox VioletCity_TrainerSchool_Text_LittleBoy, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_BOY
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_Twin::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_Twin
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_TWIN
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_LittleBoy2::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_LittleBoy2
	msgbox VioletCity_TrainerSchool_Text_LittleBoy2, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_BOY2
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_LittleGirl2::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_LittleGirl2
	msgbox VioletCity_TrainerSchool_Text_LittleGirl2, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_GIRL2
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_Lass::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_Lass
	msgbox VioletCity_TrainerSchool_Text_Lass, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LASS
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_EventScript_Youngster::
	faceplayer
	setspeaker VioletCity_TrainerSchool_Speaker_Youngster
	msgbox VioletCity_TrainerSchool_Text_Youngster, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_SCHOOL_YOUNGSTER
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_TrainerSchool_Text_ScientistF:
	.string "Remember: FLYING hits hard against\n"
	.string "GRASS, FIGHTING and BUG types.$"

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
