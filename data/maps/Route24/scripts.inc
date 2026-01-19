Route24_MapScripts::
	.byte 0

Route24_Speaker_Zander:
	.string "Zander$"

Route24_EventScript_Zander::
	checkflag FLAG_HIDE_ROUTE_24_ZANDER
	goto_if_eq Route24_EventScript_Zander_Done

	lock
	faceplayer
	setspeaker Route24_Speaker_Zander
	msgbox Route24_Text_Zander_Intro, MSGBOX_DEFAULT
	closemessage

	trainerbattle_single TRAINER_ROCKET_GRUNT_M_1, Route24_Text_Zander_BattleCue, Route24_Text_Zander_Defeated, Route24_EventScript_Zander_AfterBattle
	end

Route24_EventScript_Zander_AfterBattle::
	msgbox Route24_Text_Zander_PostBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	removeobject 2
	releaseall
	end

Route24_EventScript_Zander_Done::
	end

@ ======================
@ TEXT – ZANDER
@ ======================

Route24_Text_Zander_Intro:
	.string "You look sharp, but you still smell like a rookie.\p"
	.string "Team Rocket brought a Shadow POKEMON up to these hills.\p"
	.string "Defeat me and you earn the first real shot to snag it.\p"
	.string "This is the only window before we lock it away.$"

Route24_Text_Zander_BattleCue:
	.string "We don't hand our Shadow POKEMON to amateurs!\p"
	.string "Take it, {PLAYER}!$"

Route24_Text_Zander_Defeated:
	.string "You beat me, but that Shadow POKEMON won't leave our side yet.\p"
	.string "You're stepping into deep water, kid.$"

Route24_Text_Zander_PostBattle:
	.string "My boss is going to be furious.\p"
	.string "You just unlocked a chance to snag that Shadow POKEMON.\p"
	.string "Keep the Snag Machine ready and don't let it vanish.$"
