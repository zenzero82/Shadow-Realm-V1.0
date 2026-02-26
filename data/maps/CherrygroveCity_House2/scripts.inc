CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_Youngster::
	faceplayer
	msgbox CherrygroveCity_House2_Text_Youngster, MSGBOX_NPC
	end

CherrygroveCity_House2_EventScript_BattleGirl::
	faceplayer
	msgbox CherrygroveCity_House2_Text_BattleGirl, MSGBOX_NPC
	end

CherrygroveCity_House2_Text_Youngster:
	.string "I jog between here and VIOLET.\n"
	.string "It keeps me in shape.$"

CherrygroveCity_House2_Text_BattleGirl:
	.string "FALKNER'S GYM is tough, but I\n"
	.string "want to challenge it someday.$"
