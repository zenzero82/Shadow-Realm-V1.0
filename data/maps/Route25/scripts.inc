Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_EventScript_OnTransition
	.byte 0

@ =================================================
@ LOCAL IDS
@ =================================================

#define LOCALID_MICHAEL 1
#define LOCALID_SYLVEON 2
#define LOCALID_WES 3

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

Route25_Speaker_Michael:
	.string "MICHAEL$"

Route25_Speaker_Wes:
	.string "WES$"

@ =================================================
@ MAP STATE
@ =================================================

Route25_EventScript_OnTransition::
	checkflag FLAG_HAS_SNAG_MACHINE
	goto_if_eq Route25_EventScript_HideMichaelAndSylveon
	checkflag FLAG_CERULEAN_MISTY_MICHAEL_SCENE_DONE
	goto_if_eq Route25_EventScript_ShowMichaelAndSylveon
	setflag FLAG_HIDE_ROUTE_25_MICHAEL
	setflag FLAG_HIDE_ROUTE_25_SYLVEON
	end

Route25_EventScript_ShowMichaelAndSylveon::
	clearflag FLAG_HIDE_ROUTE_25_MICHAEL
	clearflag FLAG_HIDE_ROUTE_25_SYLVEON
	checkflag FLAG_ROUTE_25_MICHAEL_INTRO_DONE
	goto_if_eq Route25_EventScript_SetMichaelPositions
	end

Route25_EventScript_HideMichaelAndSylveon::
	setflag FLAG_HIDE_ROUTE_25_MICHAEL
	setflag FLAG_HIDE_ROUTE_25_SYLVEON
	end

Route25_EventScript_SetMichaelPositions::
	setobjectxyperm LOCALID_MICHAEL, 66, 7
	setobjectmovementtype LOCALID_MICHAEL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_SYLVEON, 66, 8
	setobjectmovementtype LOCALID_SYLVEON, MOVEMENT_TYPE_FACE_LEFT
	end

@ =================================================
@ MICHAEL + SYLVEON
@ =================================================

Route25_EventScript_Michael::
	lock
	faceplayer
	setspeaker Route25_Speaker_Michael
	checkflag FLAG_ROUTE_25_MICHAEL_INTRO_DONE
	goto_if_eq Route25_EventScript_Michael_Repeat
	msgbox Route25_Text_Michael_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MICHAEL, Route25_Movement_Michael_StepRightFaceLeft
	applymovement LOCALID_SYLVEON, Route25_Movement_Sylveon_StepDownFaceLeft
	waitmovement 0
	setobjectmovementtype LOCALID_MICHAEL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_MICHAEL, 66, 7
	setobjectxyperm LOCALID_SYLVEON, 66, 8
	setspeaker Route25_Speaker_Michael
	msgbox Route25_Text_Michael_Intro2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ROUTE_25_MICHAEL_INTRO_DONE
	goto Route25_EventScript_Michael_End

Route25_EventScript_Michael_Repeat::
	setspeaker Route25_Speaker_Michael
	msgbox Route25_Text_Michael_Repeat, MSGBOX_DEFAULT
	closemessage

Route25_EventScript_Michael_End::
	release
	end

Route25_EventScript_Sylveon::
	lock
	faceplayer
	playmoncry SPECIES_SYLVEON, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ =================================================
@ WES
@ =================================================

Route25_EventScript_Wes::
	lock
	faceplayer
	setspeaker Route25_Speaker_Wes
	msgbox Route25_Text_Wes, MSGBOX_DEFAULT
	closemessage
	release
	end

@ =================================================
@ MOVEMENTS
@ =================================================

Route25_Movement_Michael_StepRightFaceLeft:
	walk_right
	face_left
	step_end

Route25_Movement_Sylveon_StepDownFaceLeft:
	walk_down
	face_left
	step_end

@ =================================================
@ TEXT
@ =================================================

Route25_Text_Michael_Intro1:
	.string "Hey you made it! Sorry for the\n"
	.string "brief introduction earlier,\l"
	.string "but we're kind of in a rush\l"
	.string "to get things situated.\p"
	.string "I have to run to AZALEA\n"
	.string "TOWN so I can't explain\l"
	.string "much, but WES is inside.\p"
	.string "We have a hideout behind the\n"
	.string "gate and tree behind me.$"

Route25_Text_Michael_Intro2:
	.string "If you walk through there WES\n"
	.string "can fill you in. CLEMONT had\l"
	.string "some cool tech to really blend\l"
	.string "the entrance in!$"

Route25_Text_Michael_Repeat:
	.string "If you walk through there WES\n"
	.string "can fill you in. CLEMONT had\l"
	.string "some cool tech to really blend\l"
	.string "the entrance in!$"

Route25_Text_Wes:
	.string "Let's talk inside. There's not\n"
	.string "much time and the hideout is\l"
	.string "better than talking out here.$"
