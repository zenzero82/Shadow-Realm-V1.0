GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_RadioTower_5F_OnTransition
	.byte 0

GoldenrodCity_RadioTower_5F_OnTransition::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

GoldenrodCity_RadioTower_5F_Speaker_Venus:
	.string "VENUS$"

GoldenrodCity_RadioTower_5F_Speaker_Grunt1:
	.string "CIPHER GRUNT$"

GoldenrodCity_RadioTower_5F_Speaker_Grunt2:
	.string "CIPHER GRUNT$"

GoldenrodCity_RadioTower_5F_EventScript_Venus::
	lock
	faceplayer
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_double TRAINER_VENUS, GoldenrodCity_RadioTower_5F_Text_Venus_Seen, GoldenrodCity_RadioTower_5F_Text_Venus_Defeat, GoldenrodCity_RadioTower_5F_Text_Venus_NotEnoughMons
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_5F_EventScript_Venus_Release
	goto GoldenrodCity_RadioTower_5F_EventScript_Venus_After
	end

GoldenrodCity_RadioTower_5F_EventScript_Venus_After::
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_After, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Venus_Release::
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Grunt1::
	lock
	faceplayer
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Grunt1
	msgbox GoldenrodCity_RadioTower_5F_Text_Grunt1, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Grunt2::
	lock
	faceplayer
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Grunt2
	msgbox GoldenrodCity_RadioTower_5F_Text_Grunt2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_5F_Text_Venus_Intro:
	.string "Goldenrod keeps pretending it's still\n"
	.string "free. That will pass soon enough.$"

GoldenrodCity_RadioTower_5F_Text_Venus_Seen:
	.string "Let's see how long your confidence lasts.$"

GoldenrodCity_RadioTower_5F_Text_Venus_Defeat:
	.string "Irritating.$"

GoldenrodCity_RadioTower_5F_Text_Venus_NotEnoughMons:
	.string "You're not ready for me. Bring at\n"
	.string "least two POKeMON.$"

GoldenrodCity_RadioTower_5F_Text_Venus_After:
	.string "A city only needs one weak point.\n"
	.string "We'll find Goldenrod's soon enough.$"

GoldenrodCity_RadioTower_5F_Text_Grunt1:
	.string "Orders are simple: hold the tower and\n"
	.string "make the city feel small.$"

GoldenrodCity_RadioTower_5F_Text_Grunt2:
	.string "The broadcasts changed first.\n"
	.string "People obey faster when hope gets quiet.$"
