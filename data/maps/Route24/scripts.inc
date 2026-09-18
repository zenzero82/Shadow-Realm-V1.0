.set LOCALID_ROUTE24_CAMPER, 3
.set LOCALID_ROUTE24_WIMPOD, 4

Route24_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route24_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	.byte 0

Route24_OnLoad:
	call Route24_EventScript_UpdateWimpodVisibility
	end

Route24_OnTransition:
	dotimebasedevents
	call Route24_EventScript_UpdateWimpodVisibility
	end

Route24_EventScript_UpdateWimpodVisibility:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_ne Route24_HideWimpod
	goto_if_set FLAG_ROUTE24_WIMPOD_DEFEATED, Route24_HideWimpod
	goto_if_set FLAG_DAILY_ROUTE24_WIMPOD_FLED, Route24_HideWimpod
	goto Route24_ShowWimpod

Route24_ShowWimpod:
	clearflag FLAG_HIDE_ROUTE24_WIMPOD
	addobject LOCALID_ROUTE24_WIMPOD
	showobjectat LOCALID_ROUTE24_WIMPOD, MAP_ROUTE24
	return

Route24_HideWimpod:
	setflag FLAG_HIDE_ROUTE24_WIMPOD
	hideobjectat LOCALID_ROUTE24_WIMPOD, MAP_ROUTE24
	removeobject LOCALID_ROUTE24_WIMPOD
	return

Route24_Speaker_Camper:
	.string "COLIN$"

Route24_Speaker_Wimpod:
	.string "WIMPOD$"

Route24_EventScript_Camper::
	lock
	faceplayer
	setspeaker Route24_Speaker_Camper
	msgbox Route24_Text_Camper, MSGBOX_NPC
	release
	end

Route24_EventScript_CaveSign::
	msgbox Route24_Text_CaveSign, MSGBOX_SIGN
	end

Route24_EventScript_Wimpod::
	lock
	setspeaker Route24_Speaker_Wimpod
	waitse
	playmoncry SPECIES_WIMPOD, CRY_MODE_NORMAL
	setwildbattle SPECIES_WIMPOD, 15
	delay 40
	waitmoncry
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route24_EventScript_WimpodDrivenOff
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route24_EventScript_WimpodCaught
	release
	end

Route24_EventScript_WimpodCaught::
	setflag FLAG_ROUTE24_WIMPOD_DEFEATED
	hideobjectat LOCALID_ROUTE24_WIMPOD, MAP_ROUTE24
	removeobject LOCALID_ROUTE24_WIMPOD
	release
	end

Route24_EventScript_WimpodDrivenOff::
	setflag FLAG_DAILY_ROUTE24_WIMPOD_FLED
	hideobjectat LOCALID_ROUTE24_WIMPOD, MAP_ROUTE24
	removeobject LOCALID_ROUTE24_WIMPOD
	release
	end

Route24_EventScript_WimpodSpotted::
	lockall
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_ne Route24_EventScript_WimpodSpotted_End
	goto_if_set FLAG_ROUTE24_WIMPOD_DEFEATED, Route24_EventScript_WimpodSpotted_End
	goto_if_set FLAG_DAILY_ROUTE24_WIMPOD_FLED, Route24_EventScript_WimpodSpotted_End
	specialvar VAR_RESULT, IsHoldingAButton
	goto_if_eq VAR_RESULT, TRUE, Route24_EventScript_WimpodSpotted_End
	playse SE_PIN
	applymovement LOCALID_ROUTE24_WIMPOD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE24_WIMPOD, Route24_Movement_WimpodFlees
	waitmovement 0
	hideobjectat LOCALID_ROUTE24_WIMPOD, MAP_ROUTE24
	removeobject LOCALID_ROUTE24_WIMPOD
	setflag FLAG_DAILY_ROUTE24_WIMPOD_FLED
Route24_EventScript_WimpodSpotted_End::
	releaseall
	end

Route24_Movement_WimpodFlees:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route24_Text_Camper:
	.string "There is a POKéMON that comes out of\n"
	.string "the cave nearby only at night.\p"
	.string "It gets scared easily and runs off\n"
	.string "fast if it spots you.$"

Route24_Text_CaveSign:
	.string "There is a ton of rocks blocking the\n"
	.string "entrance. I can't fit through there.$"
