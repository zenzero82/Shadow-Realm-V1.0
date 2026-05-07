Lusamine_Lair_MapScripts::
	.byte 0

Lusamine_Lair_Speaker_Lusamine:
	.string "LUSAMINE.$"

Lusamine_Lair_EventScript_Lusamine::
	lock
	faceplayer
	setspeaker Lusamine_Lair_Speaker_Lusamine
	msgbox Lusamine_Lair_Text_Lusamine_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_LUSAMINE_SHADOW_REALM, Lusamine_Lair_Text_Lusamine_Seen, Lusamine_Lair_Text_Lusamine_Defeat, Lusamine_Lair_EventScript_Lusamine_After
	end

Lusamine_Lair_EventScript_Lusamine_After::
	setspeaker Lusamine_Lair_Speaker_Lusamine
	msgbox Lusamine_Lair_Text_Lusamine_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Lusamine_Lair_Text_Lusamine_Intro:
	.string "Beautiful, aren't they?\n"
	.string "Perfect shadows without flaw.$"

Lusamine_Lair_Text_Lusamine_Seen:
	.string "Come, my lovely darlings.$"

Lusamine_Lair_Text_Lusamine_Defeat:
	.string "My beauty... broken...$"

Lusamine_Lair_Text_Lusamine_After:
	.string "Even now, they still shine so brightly...$"
