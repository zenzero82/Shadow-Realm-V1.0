Lysandre_Lair_MapScripts::
	.byte 0

Lysandre_Lair_Speaker_Lysandre:
	.string "LYSANDRE.$"

Lysandre_Lair_EventScript_Lysandre::
	lock
	faceplayer
	setspeaker Lysandre_Lair_Speaker_Lysandre
	msgbox Lysandre_Lair_Text_Lysandre_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_LYSANDRE_SHADOW_REALM, Lysandre_Lair_Text_Lysandre_Seen, Lysandre_Lair_Text_Lysandre_Defeat, Lysandre_Lair_EventScript_Lysandre_After
	end

Lysandre_Lair_EventScript_Lysandre_After::
	setspeaker Lysandre_Lair_Speaker_Lysandre
	msgbox Lysandre_Lair_Text_Lysandre_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Lysandre_Lair_Text_Lysandre_Intro:
	.string "This world is ugly. Shadows only make\n"
	.string "that truth clearer.$"

Lysandre_Lair_Text_Lysandre_Seen:
	.string "I will burn away all that is impure!$"

Lysandre_Lair_Text_Lysandre_Defeat:
	.string "How can beauty lose to this...? $"

Lysandre_Lair_Text_Lysandre_After:
	.string "Your will... is brighter than mine.$"
