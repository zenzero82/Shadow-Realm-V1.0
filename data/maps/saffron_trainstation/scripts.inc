saffron_trainstation_MapScripts::
	.byte 0

saffron_trainstation_Speaker_Policeman:
	.string "Officer Bram$"

saffron_trainstation_Speaker_Lass:
	.string "Ivy$"

saffron_trainstation_Speaker_BattleGirl:
	.string "Noelle$"

saffron_trainstation_Speaker_SuperNerd:
	.string "Cyril$"

saffron_trainstation_EventScript_Policeman::
	faceplayer
	setspeaker saffron_trainstation_Speaker_Policeman
	msgbox saffron_trainstation_Text_Policeman, MSGBOX_NPC
	end

saffron_trainstation_EventScript_Lass::
	faceplayer
	setspeaker saffron_trainstation_Speaker_Lass
	msgbox saffron_trainstation_Text_Lass, MSGBOX_NPC
	end

saffron_trainstation_EventScript_BattleGirl::
	faceplayer
	setspeaker saffron_trainstation_Speaker_BattleGirl
	msgbox saffron_trainstation_Text_BattleGirl, MSGBOX_NPC
	end

saffron_trainstation_EventScript_SuperNerd::
	faceplayer
	setspeaker saffron_trainstation_Speaker_SuperNerd
	msgbox saffron_trainstation_Text_SuperNerd, MSGBOX_NPC
	end

saffron_trainstation_Text_Policeman:
	.string "Sorry, the MAGNET TRAIN is\n"
	.string "still down.\p"
	.string "Until the missing power part\n"
	.string "is found, no trains can run.$"

saffron_trainstation_Text_Lass:
	.string "I was hoping to visit\n"
	.string "GOLDENROD today.\p"
	.string "Now the train is down and\n"
	.string "the radio sounds scary.$"

saffron_trainstation_Text_BattleGirl:
	.string "If CIPHER thinks they can\n"
	.string "scare everyone, they're\l"
	.string "wrong.\p"
	.string "But I still wish the train\n"
	.string "was running.$"

saffron_trainstation_Text_SuperNerd:
	.string "The MAGNET TRAIN needs a\n"
	.string "specific machine part.\p"
	.string "Without it, the whole system\n"
	.string "stays offline.$"
