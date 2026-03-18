NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_Speaker_Woman:
	.string "LEAH$"

NewBarkTown_House1_Speaker_Lass:
	.string "MAYA$"

NewBarkTown_House1_EventScript_Woman::
	faceplayer
	setspeaker NewBarkTown_House1_Speaker_Woman
	msgbox NewBarkTown_House1_Text_Woman, MSGBOX_NPC
	end

NewBarkTown_House1_EventScript_Lass::
	faceplayer
	setspeaker NewBarkTown_House1_Speaker_Lass
	msgbox NewBarkTown_House1_Text_Lass, MSGBOX_NPC
	end

NewBarkTown_House1_Text_Woman:
	.string "I heard a lot of noise outside\n"
	.string "earlier. Things feel calmer now.$"

NewBarkTown_House1_Text_Lass:
	.string "I want to visit CHERRYGROVE soon,\n"
	.string "but I am waiting for the roads to\l"
	.string "feel safe again.$"
