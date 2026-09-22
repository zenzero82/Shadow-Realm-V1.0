celadon_gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_gym_OnTransition
	.byte 0

celadon_gym_OnTransition:
	goto_if_unset FLAG_BADGE12_GET, celadon_gym_OnTransition_End
	call celadon_gym_EventScript_SetGymTrainers
celadon_gym_OnTransition_End:
	end

@ =========================================================
@ SPEAKERS
@ =========================================================

celadon_gym_Speaker_Erika:
	.string "ERIKA$"

celadon_gym_Speaker_GymGuy:
	.string "GYM GUY$"

celadon_gym_Speaker_Michelle:
	.string "MICHELLE$"

celadon_gym_Speaker_Tanya:
	.string "TANYA$"

celadon_gym_Speaker_Julia:
	.string "JULIA$"

celadon_gym_Speaker_Jo:
	.string "JO$"

celadon_gym_Speaker_Zoe:
	.string "ZOE$"

celadon_gym_Speaker_Bellossom:
	.string "BELLOSSOM$"

celadon_gym_Speaker_Vileplume:
	.string "VILEPLUME$"

@ =========================================================
@ LEADER + GYM GUY
@ =========================================================

celadon_gym_EventScript_Erika::
	lock
	faceplayer
	setspeaker celadon_gym_Speaker_Erika
	goto_if_set FLAG_BADGE12_GET, celadon_gym_EventScript_Erika_Defeated
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox celadon_gym_Text_Erika_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, celadon_gym_Text_Erika_WinLoss
	message celadon_gym_Text_ReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM_BULLET_SEED
	setspeaker celadon_gym_Speaker_Erika
	msgbox celadon_gym_Text_Erika_After, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	call celadon_gym_EventScript_SetGymTrainers
	closemessage
	release
	end

celadon_gym_EventScript_Erika_Defeated::
	setspeaker celadon_gym_Speaker_Erika
	msgbox celadon_gym_Text_Erika_After, MSGBOX_DEFAULT
	closemessage
	release
	end

celadon_gym_EventScript_GymGuy::
	faceplayer
	setspeaker celadon_gym_Speaker_GymGuy
	goto_if_set FLAG_BADGE12_GET, celadon_gym_EventScript_GymGuy_After
	msgbox celadon_gym_Text_GymGuy_Intro, MSGBOX_NPC
	end

celadon_gym_EventScript_GymGuy_After::
	msgbox celadon_gym_Text_GymGuy_After, MSGBOX_NPC
	end

celadon_gym_EventScript_SetGymTrainers::
	settrainerflag TRAINER_CELADON_GYM_MICHELLE
	settrainerflag TRAINER_CELADON_GYM_TANYA
	settrainerflag TRAINER_CELADON_GYM_JULIA
	settrainerflag TRAINER_CELADON_GYM_JO_AND_ZOE
	return

@ =========================================================
@ TRAINERS
@ =========================================================

celadon_gym_EventScript_Michelle::
	setspeaker celadon_gym_Speaker_Michelle
	trainerbattle_single TRAINER_CELADON_GYM_MICHELLE, celadon_gym_Text_Michelle_Intro, celadon_gym_Text_Michelle_Defeat, celadon_gym_EventScript_Michelle_After
	end

celadon_gym_EventScript_Michelle_After::
	setspeaker celadon_gym_Speaker_Michelle
	msgbox celadon_gym_Text_Michelle_After, MSGBOX_AUTOCLOSE
	end

celadon_gym_EventScript_Tanya::
	setspeaker celadon_gym_Speaker_Tanya
	trainerbattle_single TRAINER_CELADON_GYM_TANYA, celadon_gym_Text_Tanya_Intro, celadon_gym_Text_Tanya_Defeat, celadon_gym_EventScript_Tanya_After
	end

celadon_gym_EventScript_Tanya_After::
	setspeaker celadon_gym_Speaker_Tanya
	msgbox celadon_gym_Text_Tanya_After, MSGBOX_AUTOCLOSE
	end

celadon_gym_EventScript_Julia::
	setspeaker celadon_gym_Speaker_Julia
	trainerbattle_single TRAINER_CELADON_GYM_JULIA, celadon_gym_Text_Julia_Intro, celadon_gym_Text_Julia_Defeat, celadon_gym_EventScript_Julia_After
	end

celadon_gym_EventScript_Julia_After::
	setspeaker celadon_gym_Speaker_Julia
	msgbox celadon_gym_Text_Julia_After, MSGBOX_AUTOCLOSE
	end

celadon_gym_EventScript_Jo::
	call celadon_gym_EventScript_MoveTwinPartnerBeforeBattle
	setspeaker celadon_gym_Speaker_Jo
	trainerbattle_double TRAINER_CELADON_GYM_JO_AND_ZOE, celadon_gym_Text_Jo_Intro, celadon_gym_Text_Jo_Defeat, celadon_gym_Text_Twins_NotEnoughMons, celadon_gym_EventScript_Jo_After
	end

celadon_gym_EventScript_Jo_After::
	setspeaker celadon_gym_Speaker_Jo
	msgbox celadon_gym_Text_Jo_After, MSGBOX_NPC
	closemessage
	release
	end

celadon_gym_EventScript_Zoe::
	call celadon_gym_EventScript_MoveTwinPartnerBeforeBattle
	setspeaker celadon_gym_Speaker_Zoe
	trainerbattle_double TRAINER_CELADON_GYM_JO_AND_ZOE, celadon_gym_Text_Zoe_Intro, celadon_gym_Text_Zoe_Defeat, celadon_gym_Text_Twins_NotEnoughMons, celadon_gym_EventScript_Zoe_After
	end

celadon_gym_EventScript_Zoe_After::
	setspeaker celadon_gym_Speaker_Zoe
	msgbox celadon_gym_Text_Zoe_After, MSGBOX_NPC
	closemessage
	release
	end

celadon_gym_EventScript_MoveTwinPartnerBeforeBattle::
	checktrainerflag TRAINER_CELADON_GYM_JO_AND_ZOE
	goto_if_eq celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_End
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 6
	goto_if_ne celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_End
	compare VAR_LAST_TALKED, 6
	goto_if_eq celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_MoveZoe
	compare VAR_LAST_TALKED, 7
	goto_if_eq celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_MoveJo
	goto celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_End

celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_MoveZoe:
	applymovement 7, celadon_gym_Movement_TwinStepRight
	waitmovement 0
	goto celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_End

celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_MoveJo:
	applymovement 6, celadon_gym_Movement_TwinStepRight
	waitmovement 0

celadon_gym_EventScript_MoveTwinPartnerBeforeBattle_End:
	return

@ =========================================================
@ POKEMON
@ =========================================================

celadon_gym_EventScript_Bellossom::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLOSSOM, CRY_MODE_NORMAL
	setspeaker celadon_gym_Speaker_Bellossom
	msgbox celadon_gym_Text_Bellossom, MSGBOX_NPC
	waitmoncry
	release
	end

celadon_gym_EventScript_Vileplume::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VILEPLUME, CRY_MODE_NORMAL
	setspeaker celadon_gym_Speaker_Vileplume
	msgbox celadon_gym_Text_Vileplume, MSGBOX_NPC
	waitmoncry
	release
	end

@ =========================================================
@ GYM STATUES
@ =========================================================

celadon_gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, celadon_gym_EventScript_GymStatuePostVictory
	msgbox celadon_gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

celadon_gym_EventScript_GymStatuePostVictory::
	msgbox celadon_gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

celadon_gym_Movement_TwinStepRight:
	walk_right
	step_end

@ =========================================================
@ TEXT
@ =========================================================

celadon_gym_Text_Erika_Intro:
	.string "Welcome to CELADON GYM.\p"
	.string "May the fragrance of our flowers\n"
	.string "calm your spirit.$"

celadon_gym_Text_Erika_WinLoss:
	.string "Oh... You are strong.\p"
	.string "Please accept the RAINBOWBADGE.$"

celadon_gym_Text_ReceivedRainbowBadge:
	.string "{PLAYER} received the RAINBOWBADGE!$"

celadon_gym_Text_Erika_After:
	.string "Our garden is always open to those\n"
	.string "who respect it.$"

celadon_gym_Text_GymGuy_Intro:
	.string "Yo! CHAMP in the making!\p"
	.string "Grass types can drain you fast.\n"
	.string "Keep your wits about you.$"

celadon_gym_Text_GymGuy_After:
	.string "That RAINBOWBADGE suits you!$"

celadon_gym_Text_Michelle_Intro:
	.string "Flowers are pretty, but my POKEMON\n"
	.string "aren't just for show!$"

celadon_gym_Text_Michelle_Defeat:
	.string "Oh no!$"

celadon_gym_Text_Michelle_After:
	.string "I still love this garden.$"

celadon_gym_Text_Tanya_Intro:
	.string "I'll protect ERIKA's honor!$"

celadon_gym_Text_Tanya_Defeat:
	.string "You got me...$"

celadon_gym_Text_Tanya_After:
	.string "You should go easy on the plants.$"

celadon_gym_Text_Julia_Intro:
	.string "Do you think you're ready for a\n"
	.string "real test?$"

celadon_gym_Text_Julia_Defeat:
	.string "How annoying!$"

celadon_gym_Text_Julia_After:
	.string "Maybe I should train harder...$"

celadon_gym_Text_Jo_Intro:
	.string "We battle together!$"

celadon_gym_Text_Jo_Defeat:
	.string "We lost...$"

celadon_gym_Text_Jo_After:
	.string "ERIKA won't lose to you!$"

celadon_gym_Text_Zoe_Intro:
	.string "We protect ERIKA!$"

celadon_gym_Text_Zoe_Defeat:
	.string "We couldn't win...$"

celadon_gym_Text_Zoe_After:
	.string "ERIKA is much stronger!$"

celadon_gym_Text_Twins_NotEnoughMons:
	.string "You need two POKEMON for a double\n"
	.string "battle!$"

celadon_gym_Text_Bellossom:
	.string "BELLOSSOM: Belloo!$"

celadon_gym_Text_Vileplume:
	.string "VILEPLUME: Pluuume!$"

celadon_gym_Text_GymStatue:
	.string "CELADON POKEMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

celadon_gym_Text_GymStatuePlayerWon:
	.string "CELADON POKEMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
