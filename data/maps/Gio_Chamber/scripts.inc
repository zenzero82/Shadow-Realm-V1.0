Gio_Chamber_MapScripts::
	.byte 0

Gio_Chamber_Speaker_Giovanni:
	.string "GIOVANNI.$"

Gio_Chamber_EventScript_Giovanni::
	lock
	faceplayer
	setspeaker Gio_Chamber_Speaker_Giovanni
	msgbox Gio_Chamber_Text_Giovanni_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GIOVANNI_SHADOW_REALM, Gio_Chamber_Text_Giovanni_Seen, Gio_Chamber_Text_Giovanni_Defeat, Gio_Chamber_EventScript_Giovanni_After
	end

Gio_Chamber_EventScript_Giovanni_After::
	setspeaker Gio_Chamber_Speaker_Giovanni
	msgbox Gio_Chamber_Text_Giovanni_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Gio_Chamber_Text_Giovanni_Intro:
	.string "You've come a long way to stand before me.$"

Gio_Chamber_Text_Giovanni_Seen:
	.string "Power decides everything. Witness mine.$"

Gio_Chamber_Text_Giovanni_Defeat:
	.string "So even this power was not enough...$"

Gio_Chamber_Text_Giovanni_After:
	.string "Those shadows answered your strength.\n"
	.string "Interesting.$"
