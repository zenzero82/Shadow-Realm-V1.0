VioletCity_House2_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Woman::
	faceplayer
	msgbox VioletCity_House2_Text_Woman, MSGBOX_NPC
	end

VioletCity_House2_EventScript_LittleBoy::
	faceplayer
	msgbox VioletCity_House2_Text_LittleBoy, MSGBOX_NPC
	end

VioletCity_House2_Text_Woman:
	.string "SPROUT TOWER is peaceful. I like\n"
	.string "hearing the bells from here.$"

VioletCity_House2_Text_LittleBoy:
	.string "I'm training hard to challenge\n"
	.string "FALKNER someday.$"
