viridian_contesthall_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, viridian_contesthall_OnTransition
	.byte 0

viridian_contesthall_Speaker_Judge:
	.string "Rowan$"

viridian_contesthall_Speaker_Attendant:
	.string "Mira$"

viridian_contesthall_Speaker_Woman:
	.string "Celia$"

viridian_contesthall_Speaker_Beauty:
	.string "Lana$"

viridian_contesthall_OnTransition:
	checkflag FLAG_QUEST_BACK_TO_HQ_STARTED
	goto_if_eq VAR_RESULT, FALSE, viridian_contesthall_HideCivilians
	clearflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_contesthall_HideCivilians:
	setflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_contesthall_EventScript_Judge::
	lock
	faceplayer
	setspeaker viridian_contesthall_Speaker_Judge
	msgbox viridian_contesthall_Text_Judge, MSGBOX_DEFAULT
	release
	end

viridian_contesthall_EventScript_Attendant::
	lock
	faceplayer
	setspeaker viridian_contesthall_Speaker_Attendant
	msgbox viridian_contesthall_Text_Attendant, MSGBOX_DEFAULT
	release
	end

viridian_contesthall_EventScript_Woman::
	lock
	faceplayer
	setspeaker viridian_contesthall_Speaker_Woman
	msgbox viridian_contesthall_Text_Woman, MSGBOX_DEFAULT
	release
	end

viridian_contesthall_EventScript_Beauty::
	lock
	faceplayer
	setspeaker viridian_contesthall_Speaker_Beauty
	msgbox viridian_contesthall_Text_Beauty, MSGBOX_DEFAULT
	release
	end

viridian_contesthall_Text_Judge:
	.string "We shut this place down and fled\n"
	.string "when Team Rocket started prowling\l"
	.string "the city.\p"
	.string "It will take time to feel normal\n"
	.string "again.$"

viridian_contesthall_Text_Attendant:
	.string "I spent the whole occupation\n"
	.string "wondering if we'd ever reopen.\p"
	.string "Even empty halls feel safer than\n"
	.string "streets full of grunts.$"

viridian_contesthall_Text_Woman:
	.string "My family ran the moment we heard\n"
	.string "Team Rocket was taking homes.$\p"
	.string "Coming back was the hard part.$"

viridian_contesthall_Text_Beauty:
	.string "I thought hiding outside the city\n"
	.string "for a few days would be enough.\p"
	.string "Then the days kept piling up.$"
