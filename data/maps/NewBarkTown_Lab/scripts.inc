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
	lock
	goto_if_set FLAG_SHADOW_TRACKER_UNLOCKED, NewBarkTown_Lab_EventScript_Silver_After
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_Familiar, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SILVER, NewBarkTown_Lab_Movement_Silver_Exclaim
	waitmovement 0
	applymovement LOCALID_SILVER, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_Leave, MSGBOX_NPC
	closemessage
	applymovement LOCALID_SILVER, NewBarkTown_Lab_Movement_Silver_Exit
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SILVER
	setflag FLAG_SHADOW_TRACKER_UNLOCKED
	setflag FLAG_QUEST_NEW_BARK_NPC_SILVER
	call QuestJournal_EventScript_CheckNewBarkNPCs
	call NewBarkTown_Lab_EventScript_RowanCall
	release
	end

NewBarkTown_Lab_EventScript_Silver_After::
	setspeaker NewBarkTown_Lab_Speaker_Silver
	msgbox NewBarkTown_Lab_Text_Silver_Leave, MSGBOX_NPC
	release
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
	.string "This place is familiar...$"

NewBarkTown_Lab_Text_Silver_Leave:
	.string "Who are you?\p"
	.string "Whatever, I came looking for\n"
	.string "Prof. Elm but doesn't seem like\l"
	.string "he's around. Not really like I\l"
	.string "care much for taking orders.\l"
	.string "Even from family...\p"
	.string "Out of my way.$"

NewBarkTown_Lab_Text_Rowan_Call:
	.string "Hello there! Lucas and Dawn\n"
	.string "managed to place tracking\l"
	.string "devices on trainers whose\l"
	.string "shadow pokemon fled.\p"
	.string "Your Shadow Tracker should\n"
	.string "pick up their signals.$"

NewBarkTown_Lab_Movement_Silver_Exclaim:
	emote_exclamation_mark
	step_end

NewBarkTown_Lab_Movement_Silver_Exit:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_EventScript_HealingMachine1::
	msgbox NewBarkTown_Lab_EventScript_HealingMachine1_Text, MSGBOX_SIGN
	end

NewBarkTown_Lab_EventScript_HealingMachine1_Text:
	.string "It's a healing machine.$"
