NewBarkTown_Lab_MapScripts::
	.byte 0

@ =================================================
@ LOCAL IDS
@ =================================================

#define LOCALID_SILVER 1

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

NewBarkTown_Lab_Speaker_Silver:
	.string "SILVER$"

@ =================================================
@ SILVER
@ =================================================

NewBarkTown_Lab_EventScript_Silver::
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_Familiar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SILVER, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_GetLost, MSGBOX_NPC
	end

@ =================================================
@ TEXT
@ =================================================

NewBarkTown_Lab_Text_Silver_Familiar:
	.string "This place feels familiar for\n"
	.string "some reason...$"

NewBarkTown_Lab_Text_Silver_GetLost:
	.string "Get lost, kid. This script\n"
	.string "isn't ready yet.$"
