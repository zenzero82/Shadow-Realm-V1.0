Sada_Turo_Lair_MapScripts::
	.byte 0

Sada_Turo_Lair_Speaker_Turo:
	.string "TURO.$"

Sada_Turo_Lair_Speaker_Sada:
	.string "SADA.$"

Sada_Turo_Lair_EventScript_Turo::
	lock
	faceplayer
	setspeaker Sada_Turo_Lair_Speaker_Turo
	msgbox Sada_Turo_Lair_Text_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_SADA_TURO_SHADOW_REALM, Sada_Turo_Lair_Text_Seen, Sada_Turo_Lair_Text_Defeat, Sada_Turo_Lair_EventScript_After_Turo
	end

Sada_Turo_Lair_EventScript_Sada::
	lock
	faceplayer
	setspeaker Sada_Turo_Lair_Speaker_Sada
	msgbox Sada_Turo_Lair_Text_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_SADA_TURO_SHADOW_REALM, Sada_Turo_Lair_Text_Seen, Sada_Turo_Lair_Text_Defeat, Sada_Turo_Lair_EventScript_After_Sada
	end

Sada_Turo_Lair_EventScript_After_Turo::
	setspeaker Sada_Turo_Lair_Speaker_Turo
	msgbox Sada_Turo_Lair_Text_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Sada_Turo_Lair_EventScript_After_Sada::
	setspeaker Sada_Turo_Lair_Speaker_Sada
	msgbox Sada_Turo_Lair_Text_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Sada_Turo_Lair_Text_Intro:
	.string "Past and future converge here in shadow.$"

Sada_Turo_Lair_Text_Seen:
	.string "Now observe the ultimate paradox!$"

Sada_Turo_Lair_Text_Defeat:
	.string "The paradox collapsed...$"

Sada_Turo_Lair_Text_After:
	.string "Even our ideal world could not surpass\n"
	.string "your resolve.$"
