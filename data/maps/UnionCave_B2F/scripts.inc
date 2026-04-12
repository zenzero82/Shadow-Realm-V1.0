UnionCave_B2F_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	setwildbattle SPECIES_LAPRAS, 30
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, UnionCave_B2F_EventScript_LaprasDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, UnionCave_B2F_EventScript_LaprasDefeated
	release
	end

UnionCave_B2F_EventScript_LaprasDefeated::
	setflag FLAG_HIDE_UNION_CAVE_B2F_LAPRAS
	goto Common_EventScript_RemoveStaticPokemon
	end
