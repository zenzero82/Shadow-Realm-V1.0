SlowpokeWell_B2F_MapScripts::
	.byte 0

SlowpokeWell_B2F_Speaker_Slowking:
	.string "SLOWKING$"

SlowpokeWell_B2F_EventScript_Slowking::
	faceplayer
	setspeaker SlowpokeWell_B2F_Speaker_Slowking
	msgbox SlowpokeWell_B2F_Text_Slowking, MSGBOX_NPC
	end

SlowpokeWell_B2F_Text_Slowking:
	.string "Greetings, traveler.\p"
	.string "I am SLOWKING, guardian of\n"
	.string "SHAMOUTI SHRINE.\p"
	.string "A strange portal pulled me from\n"
	.string "my world and stranded me here.\p"
	.string "I am distressed by what I sense.\n"
	.string "This timeline's future is unclear.\p"
	.string "I sense a terrible danger.\n"
	.string "The LEGENDARY BIRDS may be\l"
	.string "in danger.\p"
	.string "ARTICUNO, ZAPDOS, and MOLTRES\n"
	.string "may need help.\p"
	.string "I must return to SHAMOUTI\n"
	.string "SHRINE, but I cannot find\l"
	.string "the way.\p"
	.string "Please, {PLAYER}. Help me\n"
	.string "return before it begins.$"
