Greevil_Lair_MapScripts::
	.byte 0

Greevil_Lair_Speaker_Greevil:
	.string "GREEVIL.$"

Greevil_Lair_EventScript_Greevil::
	lock
	faceplayer
	setspeaker Greevil_Lair_Speaker_Greevil
	msgbox Greevil_Lair_Text_Greevil_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GREEVIL_SHADOW_REALM, Greevil_Lair_Text_Greevil_Seen, Greevil_Lair_Text_Greevil_Defeat, Greevil_Lair_EventScript_Greevil_After
	end

Greevil_Lair_EventScript_Greevil_After::
	setspeaker Greevil_Lair_Speaker_Greevil
	msgbox Greevil_Lair_Text_Greevil_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Greevil_Lair_Text_Greevil_Intro:
	.string "You stand where all shadow power gathers.$"

Greevil_Lair_Text_Greevil_Seen:
	.string "Bow before the true king of shadow!$"

Greevil_Lair_Text_Greevil_Defeat:
	.string "No... impossible...$"

Greevil_Lair_Text_Greevil_After:
	.string "So this is the strength that overturns\n"
	.string "darkness itself...$"
