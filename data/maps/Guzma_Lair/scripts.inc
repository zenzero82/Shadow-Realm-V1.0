Guzma_Lair_MapScripts::
	.byte 0

Guzma_Lair_Speaker_Guzma:
	.string "GUZMA.$"

Guzma_Lair_EventScript_Guzma::
	lock
	faceplayer
	setspeaker Guzma_Lair_Speaker_Guzma
	msgbox Guzma_Lair_Text_Guzma_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GUZMA_SHADOW_REALM, Guzma_Lair_Text_Guzma_Seen, Guzma_Lair_Text_Guzma_Defeat, Guzma_Lair_EventScript_Guzma_After
	end

Guzma_Lair_EventScript_Guzma_After::
	setspeaker Guzma_Lair_Speaker_Guzma
	msgbox Guzma_Lair_Text_Guzma_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Guzma_Lair_Text_Guzma_Intro:
	.string "Ya crashed into the boss's turf now.$"

Guzma_Lair_Text_Guzma_Seen:
	.string "Let's see if you can survive my swarm\n"
	.string "of shadows!$"

Guzma_Lair_Text_Guzma_Defeat:
	.string "What?! The boss got busted?$"

Guzma_Lair_Text_Guzma_After:
	.string "Heh. You really are something else.$"
