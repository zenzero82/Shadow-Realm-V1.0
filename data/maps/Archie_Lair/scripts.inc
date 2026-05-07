Archie_Lair_MapScripts::
	.byte 0

Archie_Lair_Speaker_Archie:
	.string "ARCHIE.$"

Archie_Lair_EventScript_Archie::
	lock
	faceplayer
	setspeaker Archie_Lair_Speaker_Archie
	msgbox Archie_Lair_Text_Archie_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_ARCHIE_SHADOW_REALM, Archie_Lair_Text_Archie_Seen, Archie_Lair_Text_Archie_Defeat, Archie_Lair_EventScript_Archie_After
	end

Archie_Lair_EventScript_Archie_After::
	setspeaker Archie_Lair_Speaker_Archie
	msgbox Archie_Lair_Text_Archie_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Archie_Lair_Text_Archie_Intro:
	.string "The sea's depth is endless.\n"
	.string "So is my ambition.$"

Archie_Lair_Text_Archie_Seen:
	.string "Let's drown this world in power!$"

Archie_Lair_Text_Archie_Defeat:
	.string "What?! You sank my whole plan!$"

Archie_Lair_Text_Archie_After:
	.string "Heh. You really can ride the tide.$"
