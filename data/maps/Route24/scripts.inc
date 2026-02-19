Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_EventScript_SetZanderVisibility
	.byte 0

Route24_EventScript_SetZanderVisibility::
	setvar VAR_TEMP_0, 1
	checkflag FLAG_ROUTE_24_ZANDER_DEFEATED
	goto_if_eq Route24_EventScript_SetZanderVisibility_Done
	checkflag FLAG_HAS_SNAG_MACHINE
	goto_if_eq Route24_EventScript_ShowZander
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route24_EventScript_ShowZander::
	clearflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route24_EventScript_SetZanderVisibility_Done::
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route24_Speaker_Zander:
	.string "Zander$"

Route24_EventScript_Zander::
	checkflag FLAG_HIDE_ROUTE_24_ZANDER
	goto_if_eq Route24_EventScript_Zander_Done

	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker Route24_Speaker_Zander
	msgbox Route24_Text_Zander_Intro, MSGBOX_DEFAULT
	closemessage

	trainerbattle_no_intro TRAINER_ROCKET_GRUNT_M_1, Route24_Text_Zander_Defeated
	goto Route24_EventScript_Zander_AfterBattle

Route24_EventScript_Zander_AfterBattle::
	msgbox Route24_Text_Zander_PostBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ROUTE_24_ZANDER_DEFEATED
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

Route24_EventScript_Zander_Done::
	end

@ ======================
@ TEXT – ZANDER
@ ======================

Route24_Text_Zander_Intro:
	.string "You look sharp, but you still smell\n"
	.string "like a rookie.\p"
	.string "Team Rocket brought a Shadow POKEMON\n"
	.string "up to these hills.\p"
	.string "Defeat me and you earn the first real\n"
	.string "shot to snag it.\p"
	.string "This is the only window before\n"
	.string "we lock it away.$"

Route24_Text_Zander_BattleCue:
	.string "We don't hand our Shadow POKEMON to amateurs!\p"
	.string "Take it, {PLAYER}!$"

Route24_Text_Zander_Defeated:
	.string "You beat me, but Shadow POKEMON\n"
	.string "won't leave our side yet.\p"
	.string "You're stepping into deep water, kid.$"

Route24_Text_Zander_PostBattle:
	.string "My boss is going to be furious!$"
