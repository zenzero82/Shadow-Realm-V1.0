saffron_gym_MapScripts::
	.byte 0

saffron_gym_Speaker_GymGuy:
	.string "Guide Owen$"

saffron_gym_Speaker_SabrinaIllusion:
	.string "SABRINA?$"

saffron_gym_Speaker_Channeler:
	.string "Ayame$"

saffron_gym_Speaker_Psychic:
	.string "Merritt$"

saffron_gym_Speaker_Alakazam:
	.string "ALAKAZAM$"

saffron_gym_EventScript_GymGuy::
	faceplayer
	setspeaker saffron_gym_Speaker_GymGuy
	msgbox saffron_gym_Text_GymGuy, MSGBOX_NPC
	end

saffron_gym_EventScript_SabrinaIllusion::
	faceplayer
	setspeaker saffron_gym_Speaker_SabrinaIllusion
	msgbox saffron_gym_Text_SabrinaIllusion, MSGBOX_NPC
	end

saffron_gym_EventScript_Channeler::
	faceplayer
	setspeaker saffron_gym_Speaker_Channeler
	msgbox saffron_gym_Text_Channeler, MSGBOX_NPC
	end

saffron_gym_EventScript_Psychic::
	faceplayer
	setspeaker saffron_gym_Speaker_Psychic
	msgbox saffron_gym_Text_Psychic, MSGBOX_NPC
	end

saffron_gym_EventScript_Alakazam::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
	waitmoncry
	setspeaker saffron_gym_Speaker_Alakazam
	msgbox saffron_gym_Text_Alakazam, MSGBOX_DEFAULT
	release
	end

saffron_gym_Text_GymGuy:
	.string "Yo! CHAMP in making...\p"
	.string "I wish I could say SABRINA\n"
	.string "was ready for you.\p"
	.string "She has been missing for\n"
	.string "quite some time.$"

saffron_gym_Text_SabrinaIllusion:
	.string "The image of SABRINA flickers.\p"
	.string "It feels more like a psychic\n"
	.string "echo than a real person.$"

saffron_gym_Text_Channeler:
	.string "A psychic pressure hangs\n"
	.string "over this GYM.\p"
	.string "Something outside the city is\n"
	.string "disturbing the spirits.$"

saffron_gym_Text_Psychic:
	.string "SABRINA left to investigate\n"
	.string "something only she could feel.\p"
	.string "Then CIPHER appeared at\n"
	.string "SILPH CO.$"

saffron_gym_Text_Alakazam:
	.string "ALAKAZAM is silently watching\n"
	.string "the entrance.$"
