Maxie_Lair_MapScripts::
	.byte 0

Maxie_Lair_Speaker_Maxie:
	.string "MAXIE.$"

Maxie_Lair_EventScript_Maxie::
	lock
	faceplayer
	setspeaker Maxie_Lair_Speaker_Maxie
	msgbox Maxie_Lair_Text_Maxie_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_MAXIE_SHADOW_REALM, Maxie_Lair_Text_Maxie_Seen, Maxie_Lair_Text_Maxie_Defeat, Maxie_Lair_EventScript_Maxie_After
	end

Maxie_Lair_EventScript_Maxie_After::
	setspeaker Maxie_Lair_Speaker_Maxie
	msgbox Maxie_Lair_Text_Maxie_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Maxie_Lair_Text_Maxie_Intro:
	.string "The land itself answers my command.$"

Maxie_Lair_Text_Maxie_Seen:
	.string "Witness the world's true expansion!$"

Maxie_Lair_Text_Maxie_Defeat:
	.string "So the earth rejected me...? $"

Maxie_Lair_Text_Maxie_After:
	.string "Even shadows couldn't force your path\n"
	.string "to yield.$"
