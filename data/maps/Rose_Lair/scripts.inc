Rose_Lair_MapScripts::
	.byte 0

Rose_Lair_Speaker_Rose:
	.string "ROSE.$"

Rose_Lair_EventScript_Rose::
	lock
	faceplayer
	setspeaker Rose_Lair_Speaker_Rose
	msgbox Rose_Lair_Text_Rose_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_ROSE_SHADOW_REALM, Rose_Lair_Text_Rose_Seen, Rose_Lair_Text_Rose_Defeat, Rose_Lair_EventScript_Rose_After
	end

Rose_Lair_EventScript_Rose_After::
	setspeaker Rose_Lair_Speaker_Rose
	msgbox Rose_Lair_Text_Rose_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Rose_Lair_Text_Rose_Intro:
	.string "A crisis always demands bold action.$"

Rose_Lair_Text_Rose_Seen:
	.string "I will secure the future myself.$"

Rose_Lair_Text_Rose_Defeat:
	.string "It seems my projections were flawed.$"

Rose_Lair_Text_Rose_After:
	.string "Perhaps strength cannot be engineered\n"
	.string "so simply.$"
