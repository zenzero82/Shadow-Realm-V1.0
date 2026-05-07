RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	faceplayer
	setspeaker RustboroCity_House2_Speaker_Elise
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl::
	faceplayer
	setspeaker RustboroCity_House2_Speaker_Faye
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Speaker_Elise:
	.string "Elise$"

RustboroCity_House2_Speaker_Faye:
	.string "Faye$"

RustboroCity_House2_Text_TrainerSchoolExcellent:
	.string "The TRAINER'S SCHOOL is excellent.\p"
	.string "If you study there, you could even\n"
	.string "become a GYM LEADER.$"

RustboroCity_House2_Text_RoxanneKnowsALot:
	.string "ROXANNE, the GYM LEADER, really knows\n"
	.string "a lot about POKéMON.\p"
	.string "She's really strong, too!$"
