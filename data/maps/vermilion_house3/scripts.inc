vermilion_house3_MapScripts::
	.byte 0

vermilion_house3_Speaker_Gentleman:
	.string "ARTHUR$"

vermilion_house3_EventScript_Gentleman::
	lock
	faceplayer
	setspeaker vermilion_house3_Speaker_Gentleman
	msgbox vermilion_house3_Text_Gentleman, MSGBOX_NPC
	release
	end

vermilion_house3_Text_Gentleman:
	.string "VERMILION thrives on movement.\p"
	.string "Ships come and go, but a city only\n"
	.string "keeps its charm if people stay kind.$"
