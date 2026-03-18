NewBarkTown_House2_MapScripts::
	.byte 0

NewBarkTown_House2_Speaker_Woman:
	.string "ROSE$"

NewBarkTown_House2_Speaker_Girl:
	.string "LILA$"

NewBarkTown_House2_EventScript_Woman::
	faceplayer
	setspeaker NewBarkTown_House2_Speaker_Woman
	msgbox NewBarkTown_House2_Text_Woman, MSGBOX_NPC
	end

NewBarkTown_House2_EventScript_Girl::
	faceplayer
	setspeaker NewBarkTown_House2_Speaker_Girl
	msgbox NewBarkTown_House2_Text_Girl, MSGBOX_NPC
	end

NewBarkTown_House2_Text_Woman:
	.string "ETHAN has been checking on everyone.\n"
	.string "It helps to see a friendly face.$"

NewBarkTown_House2_Text_Girl:
	.string "I saw a bright ring outside!\n"
	.string "It was gone in a blink.$"
