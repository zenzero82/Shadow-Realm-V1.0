Evice_Lair_MapScripts::
	.byte 0

Evice_Lair_Speaker_Evice:
	.string "EVICE.$"

Evice_Lair_EventScript_Evice::
	lock
	faceplayer
	setspeaker Evice_Lair_Speaker_Evice
	msgbox Evice_Lair_Text_Evice_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_EVICE_SHADOW_REALM, Evice_Lair_Text_Evice_Seen, Evice_Lair_Text_Evice_Defeat, Evice_Lair_EventScript_Evice_After
	end

Evice_Lair_EventScript_Evice_After::
	setspeaker Evice_Lair_Speaker_Evice
	msgbox Evice_Lair_Text_Evice_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Evice_Lair_Text_Evice_Intro:
	.string "My shadows are flawless weapons.$"

Evice_Lair_Text_Evice_Seen:
	.string "I will show you the meaning of terror.$"

Evice_Lair_Text_Evice_Defeat:
	.string "How could I be defeated...? $"

Evice_Lair_Text_Evice_After:
	.string "The shadows chose poorly this time.$"
