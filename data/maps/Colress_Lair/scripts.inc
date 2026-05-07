Colress_Lair_MapScripts::
	.byte 0

Colress_Lair_Speaker_Colress:
	.string "COLRESS.$"

Colress_Lair_EventScript_Colress::
	lock
	faceplayer
	setspeaker Colress_Lair_Speaker_Colress
	msgbox Colress_Lair_Text_Colress_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_COLRESS_SHADOW_REALM, Colress_Lair_Text_Colress_Seen, Colress_Lair_Text_Colress_Defeat, Colress_Lair_EventScript_Colress_After
	end

Colress_Lair_EventScript_Colress_After::
	setspeaker Colress_Lair_Speaker_Colress
	msgbox Colress_Lair_Text_Colress_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Colress_Lair_Text_Colress_Intro:
	.string "I seek the limit of a shadow Pokémon's\n"
	.string "strength.$"

Colress_Lair_Text_Colress_Seen:
	.string "Allow me to observe the result.$"

Colress_Lair_Text_Colress_Defeat:
	.string "Fascinating... truly fascinating.$"

Colress_Lair_Text_Colress_After:
	.string "Your bond exceeded my calculations.$"
