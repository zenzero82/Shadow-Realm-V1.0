Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_EventScript_SetZanderVisibility
	.byte 0

Route10_EventScript_SetZanderVisibility::
	setvar VAR_TEMP_0, 1
	checkflag FLAG_ROUTE_24_ZANDER_DEFEATED
	goto_if_eq Route10_EventScript_SetZanderVisibility_Done
	checkflag FLAG_HAS_SNAG_MACHINE
	goto_if_eq Route10_EventScript_ShowZander
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route10_EventScript_ShowZander::
	clearflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route10_EventScript_SetZanderVisibility_Done::
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	end

Route10_EventScript_PlasmaGrunt::
	lock
	faceplayer
	setspeaker Route10_Speaker_Plasma
	msgbox Route10_Text_PlasmaGrunt_Exit, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route10_Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_ROUTE10_PLASMA_GRUNT, Route10_Movement_PlasmaEnterCave
	waitmovement 0
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	release
	end

Route10_Speaker_Zander:
	.string "Zander$"

Route10_EventScript_Zander::
	checkflag FLAG_HIDE_ROUTE_24_ZANDER
	goto_if_eq Route10_EventScript_Zander_Done

	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker Route10_Speaker_Zander
	msgbox Route10_Text_Zander_Intro, MSGBOX_DEFAULT
	closemessage

	trainerbattle_no_intro TRAINER_ROCKET_GRUNT_M_1, Route10_Text_Zander_Defeated
	goto Route10_EventScript_Zander_AfterBattle

Route10_EventScript_Zander_AfterBattle::
	msgbox Route10_Text_Zander_PostBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ROUTE_24_ZANDER_DEFEATED
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	fadescreenswapbuffers FADE_TO_BLACK
	hideobjectat LOCALID_ROUTE10_ZANDER, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_ZANDER
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

Route10_EventScript_Zander_Done::
	end

Route10_Movement_PlayerStepLeft:
	walk_left
	step_end

Route10_Movement_PlasmaEnterCave:
	walk_up
	walk_up
	step_end

Route10_Speaker_Plasma:
	.string "PLASMA$"

Route10_Text_PlasmaGrunt_Exit:
	.string "Out of my way! I need to let the\n"
	.string "others know a really strong trainer\l"
	.string "is about to crush us!\p"
	.string "...Wait, you already defeated them?\p"
	.string "...This is so sad...\n"
	.string "Now I have to tell the Sages.\p"
	.string "MOVE!$"

@ ======================
@ TEXT – ZANDER
@ ======================

Route10_Text_Zander_Intro:
	.string "You look sharp, but you still smell\n"
	.string "like a rookie.\p"
	.string "Team Rocket brought a Shadow POKéMON\n"
	.string "up to these hills.\p"
	.string "Defeat me and you earn the first real\n"
	.string "shot to snag it.\p"
	.string "This is the only window before\n"
	.string "we lock it away.$"

Route10_Text_Zander_Defeated:
	.string "You beat me, but Shadow POKéMON\n"
	.string "won't leave our side yet.\p"
	.string "You're stepping into deep water, kid.$"

Route10_Text_Zander_PostBattle:
	.string "My boss is going to be furious!$"
