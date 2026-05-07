Nascour_Lair_MapScripts::
	.byte 0

Nascour_Lair_Speaker_Nascour:
	.string "NASCOUR.$"

Nascour_Lair_EventScript_Nascour::
	lock
	faceplayer
	setspeaker Nascour_Lair_Speaker_Nascour
	msgbox Nascour_Lair_Text_Nascour_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_NASCOUR_SHADOW_REALM, Nascour_Lair_Text_Nascour_Seen, Nascour_Lair_Text_Nascour_Defeat, Nascour_Lair_EventScript_Nascour_After
	end

Nascour_Lair_EventScript_Nascour_After::
	setspeaker Nascour_Lair_Speaker_Nascour
	msgbox Nascour_Lair_Text_Nascour_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Nascour_Lair_Text_Nascour_Intro:
	.string "The shadows are perfection made real.$"

Nascour_Lair_Text_Nascour_Seen:
	.string "Kneel before the future I created!$"

Nascour_Lair_Text_Nascour_Defeat:
	.string "Impossible...$"

Nascour_Lair_Text_Nascour_After:
	.string "So this is the will that shattered\n"
	.string "Cipher's ambition...$"
