Cyrus_Lair_MapScripts::
	.byte 0

Cyrus_Lair_Speaker_Cyrus:
	.string "CYRUS.$"

Cyrus_Lair_EventScript_Cyrus::
	lock
	faceplayer
	setspeaker Cyrus_Lair_Speaker_Cyrus
	msgbox Cyrus_Lair_Text_Cyrus_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_CYRUS_SHADOW_REALM, Cyrus_Lair_Text_Cyrus_Seen, Cyrus_Lair_Text_Cyrus_Defeat, Cyrus_Lair_EventScript_Cyrus_After
	end

Cyrus_Lair_EventScript_Cyrus_After::
	setspeaker Cyrus_Lair_Speaker_Cyrus
	msgbox Cyrus_Lair_Text_Cyrus_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Cyrus_Lair_Text_Cyrus_Intro:
	.string "Emotion, spirit, will...\n"
	.string "All of it is unnecessary.$"

Cyrus_Lair_Text_Cyrus_Seen:
	.string "I will create a perfect universe.$"

Cyrus_Lair_Text_Cyrus_Defeat:
	.string "So spirit cannot be erased...$"

Cyrus_Lair_Text_Cyrus_After:
	.string "You remain a flaw I cannot explain.$"
