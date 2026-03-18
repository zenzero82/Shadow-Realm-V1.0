VioletCity_House2_MapScripts::
	.byte 0

VioletCity_House2_Speaker_Woman:
	.string "LISA$"

VioletCity_House2_Speaker_LittleBoy:
	.string "NICK$"

VioletCity_House2_EventScript_Woman::
	faceplayer
	setspeaker VioletCity_House2_Speaker_Woman
	msgbox VioletCity_House2_Text_Woman, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_HOUSE2_WOMAN
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_House2_EventScript_LittleBoy::
	faceplayer
	setspeaker VioletCity_House2_Speaker_LittleBoy
	msgbox VioletCity_House2_Text_LittleBoy, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_HOUSE2_LITTLE_BOY
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_House2_Text_Woman:
	.string "SPROUT TOWER is peaceful. I like\n"
	.string "hearing the bells from here.$"

VioletCity_House2_Text_LittleBoy:
	.string "I'm training hard to challenge\n"
	.string "FALKNER someday.$"
