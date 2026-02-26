NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Woman::
	faceplayer
	msgbox NewBarkTown_House1_Text_Woman, MSGBOX_NPC
	end

NewBarkTown_House1_EventScript_Lass::
	faceplayer
	msgbox NewBarkTown_House1_Text_Lass, MSGBOX_NPC
	end

NewBarkTown_House1_Text_Woman:
	.string "I heard a lot of noise outside\n"
	.string "earlier. Things feel calmer now.$"

NewBarkTown_House1_Text_Lass:
	.string "I want to visit CHERRYGROVE soon,\n"
	.string "but I am waiting for the roads to\n"
	.string "feel safe again.$"
