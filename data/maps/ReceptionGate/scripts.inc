ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ReceptionGate_OnTransition
	.byte 0

.set LOCALID_RECEPTION_GATE_LEAGUE_GUIDE,   1
.set LOCALID_RECEPTION_GATE_LUCAS_PIDGEY,   2
.set LOCALID_RECEPTION_GATE_LUCAS,          3
.set LOCALID_RECEPTION_GATE_MT_SILVER_GUARD, 4

ReceptionGate_OnTransition::
	checkflag FLAG_QUEST_FIREBIRD_STARTED
	goto_if_eq ReceptionGate_OnTransition_HideMtSilverGuard
	showobjectat LOCALID_RECEPTION_GATE_MT_SILVER_GUARD, MAP_RECEPTION_GATE
	end

ReceptionGate_OnTransition_HideMtSilverGuard::
	hideobjectat LOCALID_RECEPTION_GATE_MT_SILVER_GUARD, MAP_RECEPTION_GATE
	removeobject LOCALID_RECEPTION_GATE_MT_SILVER_GUARD
	end

ReceptionGate_Speaker_LeagueGuide:
	.string "GUIDE$"

ReceptionGate_Speaker_MtSilverGuard:
	.string "GUARD$"

ReceptionGate_Speaker_Lucas:
	.string "LUCAS$"

ReceptionGate_EventScript_LeagueGuide::
	lock
	faceplayer
	setspeaker ReceptionGate_Speaker_LeagueGuide
	msgbox ReceptionGate_Text_LeagueGuide, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_MtSilverGuard::
	lock
	faceplayer
	setspeaker ReceptionGate_Speaker_MtSilverGuard
	msgbox ReceptionGate_Text_MtSilverGuard, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_Lucas::
	lock
	faceplayer
	setspeaker ReceptionGate_Speaker_Lucas
	goto_if_unset FLAG_BADGE09_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE10_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE11_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE12_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE13_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE14_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE15_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE16_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE17_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE18_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE19_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE20_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE21_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE22_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE23_GET, ReceptionGate_EventScript_LucasIntro
	goto_if_unset FLAG_BADGE24_GET, ReceptionGate_EventScript_LucasIntro
	msgbox ReceptionGate_Text_LucasChallengeStub, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_LucasIntro::
	msgbox ReceptionGate_Text_LucasIntro, MSGBOX_DEFAULT
	setflag FLAG_RECEPTION_GATE_LUCAS_INTRO_DONE
	release
	end

ReceptionGate_EventScript_LucasRepeat::
	msgbox ReceptionGate_Text_LucasRepeat, MSGBOX_DEFAULT
	release
	end

ReceptionGate_Text_LeagueGuide:
	.string "This RECEPTION GATE is what branches\n"
	.string "KANTO and JOHTO together.\p"
	.string "It also connects the path to the\n"
	.string "POKéMON LEAGUE and to MT. SILVER.$"

ReceptionGate_Text_MtSilverGuard:
	.string "You're not quite ready to explore\n"
	.string "MT. SILVER yet.\p"
	.string "It's a dangerous place for even\n"
	.string "seasoned trainers.$"

ReceptionGate_Text_LucasIntro:
	.string "Hey! Are you {PLAYER}?\p"
	.string "... ... Cool!\p"
	.string "My name is Lucas. I guess you probably\n"
	.string "didn't think you would run into me\l"
	.string "here of all places hahaha.\p"
	.string "But yeah, I'm here to ensure trainers\n"
	.string "have obtained all KANTO badges and\l"
	.string "JOHTO badges before taking their shot\l"
	.string "at the league.\p"
	.string "I'm also on surveillance for any\n"
	.string "criminal activity to help prevent\l"
	.string "anyone from disrupting league matches.\p"
	.string "I guess that makes me somewhat of a\n"
	.string "strong trainer?\p"
	.string "I don't know, I'm just doing my job\n"
	.string "until this is over and I can go back\l"
	.string "home to SINNOH.\p"
	.string "Well good to meet you {PLAYER}, come\n"
	.string "back when you got those badges and we\l"
	.string "can see if you're ready for the\l"
	.string "league!$"

ReceptionGate_Text_LucasRepeat:
	.string "Well good to meet you {PLAYER}, come\n"
	.string "back when you got those badges and we\l"
	.string "can see if you're ready for the\l"
	.string "league!$"

ReceptionGate_Text_LucasChallengeStub:
	.string "Looks like you've got all the badges.\p"
	.string "I'd normally challenge you right here\n"
	.string "to see if you're ready for the league,\l"
	.string "but that battle isn't set up yet.$"
