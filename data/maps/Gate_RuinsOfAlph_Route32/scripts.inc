Gate_RuinsOfAlph_Route32_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route32_Speaker_Youngster:
	.string "Bruno$"

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	setspeaker Gate_RuinsOfAlph_Route32_Speaker_Youngster
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "There are drawings on stone\n"
	.string "panels.\p"
	.string "I tried moving them.\n"
	.string "I wonder what they are.$"
