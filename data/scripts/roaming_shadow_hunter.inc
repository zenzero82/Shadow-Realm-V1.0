@ Roaming shadow hunter shared field script.

RoamingHunter_OnMapLoad::
RoamingHunter_CheckSpawn::
	special RoamingHunter_TryCreateNpcOnMap
	goto_if_eq VAR_RESULT, 0, RoamingHunter_HideNpc
	clearflag FLAG_ROAMING_HUNTER_NPC_HIDE
	end

RoamingHunter_HideNpc::
	setflag FLAG_ROAMING_HUNTER_NPC_HIDE
	end

RoamingHunter_NpcScript::
	lock
	faceplayer
	call RoamingHunter_SetSpeaker
	special RoamingHunter_LoadIntroText
	msgbox gStringVar4, MSGBOX_DEFAULT
	special PlayTrainerEncounterMusic
	special RoamingHunter_StartBattle
	waitstate
	specialvar VAR_RESULT, RoamingHunter_DidPlayerWinBattle
	goto_if_eq VAR_RESULT, FALSE, RoamingHunter_End
	call RoamingHunter_SetSpeaker
	special RoamingHunter_LoadDefeatText
	msgbox gStringVar4, MSGBOX_DEFAULT
	call RoamingHunter_SetSpeaker
	special RoamingHunter_LoadOutroText
	msgbox gStringVar4, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	special RoamingHunter_DespawnNpc
	special RoamingHunter_OnBattleWon
	fadescreenswapbuffers FADE_FROM_BLACK
RoamingHunter_End::
	release
	end

RoamingHunter_SetSpeaker::
	specialvar VAR_RESULT, RoamingHunter_GetActiveTrainerId
	compare VAR_RESULT, TRAINER_CASSIDY_HUNTER
	goto_if_eq RoamingHunter_SetSpeaker_Cassidy
	compare VAR_RESULT, TRAINER_BUTCH_HUNTER
	goto_if_eq RoamingHunter_SetSpeaker_Butch
	compare VAR_RESULT, TRAINER_SILVER_HUNTER
	goto_if_eq RoamingHunter_SetSpeaker_Silver
	compare VAR_RESULT, TRAINER_HEX_RESIX
	goto_if_eq RoamingHunter_SetSpeaker_Resix
	compare VAR_RESULT, TRAINER_HEX_BLUSIX
	goto_if_eq RoamingHunter_SetSpeaker_Blusix
	compare VAR_RESULT, TRAINER_HEX_GREESIX
	goto_if_eq RoamingHunter_SetSpeaker_Greesix
	compare VAR_RESULT, TRAINER_HEX_PURPSIX
	goto_if_eq RoamingHunter_SetSpeaker_Purpsix
	compare VAR_RESULT, TRAINER_HEX_BROWSIX
	goto_if_eq RoamingHunter_SetSpeaker_Browsix
	compare VAR_RESULT, TRAINER_HEX_YELLOSIX
	goto_if_eq RoamingHunter_SetSpeaker_Yellosix
	setspeaker RoamingHunter_Speaker_ShadowHunter
	return

RoamingHunter_SetSpeaker_Cassidy::
	setspeaker RoamingHunter_Speaker_Cassidy
	return

RoamingHunter_SetSpeaker_Butch::
	setspeaker RoamingHunter_Speaker_Butch
	return

RoamingHunter_SetSpeaker_Silver::
	setspeaker RoamingHunter_Speaker_Silver
	return

RoamingHunter_SetSpeaker_Resix::
	setspeaker RoamingHunter_Speaker_Resix
	return

RoamingHunter_SetSpeaker_Blusix::
	setspeaker RoamingHunter_Speaker_Blusix
	return

RoamingHunter_SetSpeaker_Greesix::
	setspeaker RoamingHunter_Speaker_Greesix
	return

RoamingHunter_SetSpeaker_Purpsix::
	setspeaker RoamingHunter_Speaker_Purpsix
	return

RoamingHunter_SetSpeaker_Browsix::
	setspeaker RoamingHunter_Speaker_Browsix
	return

RoamingHunter_SetSpeaker_Yellosix::
	setspeaker RoamingHunter_Speaker_Yellosix
	return

RoamingHunter_Speaker_ShadowHunter:
	.string "SHADOW HUNTER$"

RoamingHunter_Speaker_Cassidy:
	.string "CASSIDY$"

RoamingHunter_Speaker_Butch:
	.string "BUTCH$"

RoamingHunter_Speaker_Silver:
	.string "SILVER$"

RoamingHunter_Speaker_Resix:
	.string "RESIX$"

RoamingHunter_Speaker_Blusix:
	.string "BLUSIX$"

RoamingHunter_Speaker_Greesix:
	.string "GREESIX$"

RoamingHunter_Speaker_Purpsix:
	.string "PURPSIX$"

RoamingHunter_Speaker_Browsix:
	.string "BROWSIX$"

RoamingHunter_Speaker_Yellosix:
	.string "YELLOSIX$"
