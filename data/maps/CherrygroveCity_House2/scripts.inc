CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_Speaker_Youngster:
	.string "CALEB$"

CherrygroveCity_House2_Speaker_BattleGirl:
	.string "SARA$"

CherrygroveCity_House2_EventScript_Youngster::
	faceplayer
	setspeaker CherrygroveCity_House2_Speaker_Youngster
	msgbox CherrygroveCity_House2_Text_Youngster, MSGBOX_NPC
	end

CherrygroveCity_House2_EventScript_BattleGirl::
	faceplayer
	setspeaker CherrygroveCity_House2_Speaker_BattleGirl
	msgbox CherrygroveCity_House2_Text_BattleGirl, MSGBOX_NPC
	end

CherrygroveCity_House2_Text_Youngster:
	.string "I jog between here and VIOLET.\n"
	.string "It keeps me in shape.$"

CherrygroveCity_House2_Text_BattleGirl:
	.string "FALKNER'S GYM is tough, but I\n"
	.string "want to challenge it someday.$"
