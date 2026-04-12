WhirlIslands_B1F_MapScripts::
	.byte 0

WhirlIslands_B1F_EventScript_Gimmighoul::
	call Common_EventScript_GimmighoulStaticEncounter
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands_B1F_EventScript_GimmighoulDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, WhirlIslands_B1F_EventScript_GimmighoulDefeated
	release
	end

WhirlIslands_B1F_EventScript_GimmighoulDefeated::
	setflag FLAG_HIDE_WHIRL_ISLANDS_B1F_GIMMIGHOUL
	setvar VAR_0x8000, 75
	additem ITEM_GIMMIGHOUL_COIN, 75
	buffernumberstring STR_VAR_1, VAR_0x8000
	msgbox gText_GimmighoulCoinsObtained, MSGBOX_DEFAULT
	goto Common_EventScript_RemoveStaticPokemon
	end
