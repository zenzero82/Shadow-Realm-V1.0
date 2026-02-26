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

NewBarkTown_Lab_Speaker_Rowan:
	.string "ROWAN$"

@ =================================================
@ SILVER
@ =================================================

NewBarkTown_Lab_EventScript_Silver::
	goto_if_set FLAG_SHADOW_TRACKER_UNLOCKED, NewBarkTown_Lab_EventScript_Silver_After
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_Familiar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SILVER, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_GetLost, MSGBOX_NPC
	setflag FLAG_SHADOW_TRACKER_UNLOCKED
	call NewBarkTown_Lab_EventScript_RowanCall
	end

NewBarkTown_Lab_EventScript_Silver_After::
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_GetLost, MSGBOX_NPC
	end

NewBarkTown_Lab_EventScript_RowanCall::
	setspeaker NewBarkTown_Lab_Speaker_Rowan
	pokenavcall NewBarkTown_Lab_Text_Rowan_Call
	waitmessage
	return

@ =================================================
@ TEXT
@ =================================================

NewBarkTown_Lab_Text_Silver_Familiar:
	.string "This place feels familiar for\n"
	.string "some reason...$"

NewBarkTown_Lab_Text_Silver_GetLost:
	.string "Get lost, kid. This script\n"
	.string "isn't ready yet.$"

NewBarkTown_Lab_Text_Rowan_Call:
	.string "Hello there! Lucas and Dawn\n"
	.string "managed to place tracking\n"
	.string "devices on trainers whose\n"
	.string "shadow pokemon fled.\p"
	.string "Your Shadow Tracker should\n"
	.string "pick up their signals.$"

NewBarkTown_Lab_EventScript_HealingMachine1::
	msgbox NewBarkTown_Lab_EventScript_HealingMachine1_Text, MSGBOX_SIGN
	end

NewBarkTown_Lab_EventScript_HealingMachine1_Text:
	.string "It's a healing machine.$"
