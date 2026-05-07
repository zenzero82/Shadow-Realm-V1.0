RuinsOfAlph_B1F_MapScripts::
	.byte 0

RuinsOfAlph_B1F_EventScript_Gimmighoul::
	call Common_EventScript_GimmighoulStaticEncounter
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RuinsOfAlph_B1F_EventScript_GimmighoulDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, RuinsOfAlph_B1F_EventScript_GimmighoulDefeated
	release
	end

RuinsOfAlph_B1F_EventScript_GimmighoulDefeated::
	setflag FLAG_HIDE_RUINS_OF_ALPH_B1F_GIMMIGHOUL
	setvar VAR_0x8000, 75
	additem ITEM_GIMMIGHOUL_COIN, 75
	buffernumberstring STR_VAR_1, VAR_0x8000
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_GimmighoulCoinsObtained, MSGBOX_DEFAULT
	waitfanfare
	goto Common_EventScript_RemoveStaticPokemon
	end
