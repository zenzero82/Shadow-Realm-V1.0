Ghetsis_Lair_MapScripts::
	.byte 0

Ghetsis_Lair_Speaker_Ghetsis:
	.string "GHETSIS.$"

Ghetsis_Lair_EventScript_Ghetsis::
	lock
	faceplayer
	setspeaker Ghetsis_Lair_Speaker_Ghetsis
	msgbox Ghetsis_Lair_Text_Ghetsis_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GHETSIS_SHADOW_REALM, Ghetsis_Lair_Text_Ghetsis_Seen, Ghetsis_Lair_Text_Ghetsis_Defeat, Ghetsis_Lair_EventScript_Ghetsis_After
	end

Ghetsis_Lair_EventScript_Ghetsis_After::
	setspeaker Ghetsis_Lair_Speaker_Ghetsis
	msgbox Ghetsis_Lair_Text_Ghetsis_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Ghetsis_Lair_Text_Ghetsis_Intro:
	.string "At last. A worthy audience for true\n"
	.string "dominion.$"

Ghetsis_Lair_Text_Ghetsis_Seen:
	.string "I will crush you with dragons and dark.$"

Ghetsis_Lair_Text_Ghetsis_Defeat:
	.string "You dare...!$"

Ghetsis_Lair_Text_Ghetsis_After:
	.string "This is not the end of my designs.$"
