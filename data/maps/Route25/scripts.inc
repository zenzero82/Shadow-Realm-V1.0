Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_EventScript_OnTransition
	.byte 0

@ =================================================
@ LOCAL IDS
@ =================================================

#define LOCALID_ROUTE25_MICHAEL 1
#define LOCALID_ROUTE25_SYLVEON 2
#define LOCALID_ROUTE25_WES 3
#define LOCALID_ROUTE25_EUSINE 11

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

Route25_Speaker_Michael:
	.string "MICHAEL$"

Route25_Speaker_Wes:
	.string "WES$"

Route25_Speaker_Youngster1:
	.string "TIM$"

Route25_Speaker_Lady:
	.string "MARIE$"

Route25_Speaker_CooltrainerF:
	.string "KARA$"

Route25_Speaker_Youngster2:
	.string "BEN$"

Route25_Speaker_Camper:
	.string "COLE$"

Route25_Speaker_Lass:
	.string "NINA$"

Route25_Speaker_SuperNerd:
	.string "DEX$"

Route25_Speaker_Eusine:
	.string "EUSINE$"

@ =================================================
@ MAP STATE
@ =================================================

Route25_EventScript_OnTransition::
	setvar VAR_TEMP_0, 0
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
	setobjectxyperm LOCALID_ROUTE25_MICHAEL, 66, 7
	setobjectmovementtype LOCALID_ROUTE25_MICHAEL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_ROUTE25_SYLVEON, 66, 8
	setobjectmovementtype LOCALID_ROUTE25_SYLVEON, MOVEMENT_TYPE_FACE_LEFT
	end

@ =================================================
@ MICHAEL + SYLVEON
@ =================================================

Route25_EventScript_Michael::
	lock
	faceplayer
	setspeaker Route25_Speaker_Michael
	checkflag FLAG_BADGE01_GET
	goto_if_eq Route25_EventScript_Michael_HasBoulderBadge
	msgbox Route25_Text_Michael_NeedBoulderBadge, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_Michael_HasBoulderBadge:
	checkflag FLAG_ROUTE_25_MICHAEL_INTRO_DONE
	goto_if_eq Route25_EventScript_Michael_Repeat
	msgbox Route25_Text_Michael_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_MICHAEL, Route25_Movement_Michael_StepRightFaceLeft
	applymovement LOCALID_ROUTE25_SYLVEON, Route25_Movement_Sylveon_StepDownFaceLeft
	waitmovement 0
	setobjectmovementtype LOCALID_ROUTE25_MICHAEL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_ROUTE25_MICHAEL, 66, 7
	setobjectxyperm LOCALID_ROUTE25_SYLVEON, 66, 8
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
	waitse
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
@ EUSINE
@ =================================================

Route25_EventScript_Eusine::
	lockall
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_Eusine_Step
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_Player_FaceRight
	waitmovement 0
	setspeaker Route25_Speaker_Eusine
	msgbox Route25_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	releaseall
	end

@ =================================================
@ ROUTE 25 TRAINERS
@ =================================================

Route25_EventScript_Youngster1::
	setspeaker Route25_Speaker_Youngster1
	trainerbattle_single TRAINER_RT25_YOUNGSTER1, Route25_Text_Youngster1_Intro, Route25_Text_Youngster1_Defeat, Route25_EventScript_Youngster1_After
	end

Route25_EventScript_Youngster1_After::
	setspeaker Route25_Speaker_Youngster1
	msgbox Route25_Text_Youngster1_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_Lady::
	setspeaker Route25_Speaker_Lady
	trainerbattle_single TRAINER_RT25_LADY, Route25_Text_Lady_Intro, Route25_Text_Lady_Defeat, Route25_EventScript_Lady_After
	end

Route25_EventScript_Lady_After::
	setspeaker Route25_Speaker_Lady
	msgbox Route25_Text_Lady_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_CooltrainerF::
	setspeaker Route25_Speaker_CooltrainerF
	trainerbattle_single TRAINER_RT25_COOLTRAINER_F, Route25_Text_CooltrainerF_Intro, Route25_Text_CooltrainerF_Defeat, Route25_EventScript_CooltrainerF_After
	end

Route25_EventScript_CooltrainerF_After::
	setspeaker Route25_Speaker_CooltrainerF
	msgbox Route25_Text_CooltrainerF_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_Youngster2::
	setspeaker Route25_Speaker_Youngster2
	trainerbattle_single TRAINER_RT25_YOUNGSTER2, Route25_Text_Youngster2_Intro, Route25_Text_Youngster2_Defeat, Route25_EventScript_Youngster2_After
	end

Route25_EventScript_Youngster2_After::
	setspeaker Route25_Speaker_Youngster2
	msgbox Route25_Text_Youngster2_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_Camper::
	setspeaker Route25_Speaker_Camper
	trainerbattle_single TRAINER_RT25_CAMPER, Route25_Text_Camper_Intro, Route25_Text_Camper_Defeat, Route25_EventScript_Camper_After
	end

Route25_EventScript_Camper_After::
	setspeaker Route25_Speaker_Camper
	msgbox Route25_Text_Camper_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_Lass::
	setspeaker Route25_Speaker_Lass
	trainerbattle_single TRAINER_RT25_LASS, Route25_Text_Lass_Intro, Route25_Text_Lass_Defeat, Route25_EventScript_Lass_After
	end

Route25_EventScript_Lass_After::
	setspeaker Route25_Speaker_Lass
	msgbox Route25_Text_Lass_After, MSGBOX_NPC
	closemessage
	release
	end

Route25_EventScript_SuperNerd::
	setspeaker Route25_Speaker_SuperNerd
	trainerbattle_single TRAINER_RT25_SUPER_NERD, Route25_Text_SuperNerd_Intro, Route25_Text_SuperNerd_Defeat, Route25_EventScript_SuperNerd_After
	end

Route25_EventScript_SuperNerd_After::
	setspeaker Route25_Speaker_SuperNerd
	msgbox Route25_Text_SuperNerd_After, MSGBOX_NPC
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

Route25_Movement_Eusine_Step:
	walk_right
	walk_left
	face_left
	step_end

Route25_Movement_Player_FaceRight:
	face_right
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

Route25_Text_Michael_NeedBoulderBadge:
	.string "Looks like you haven't bested BROCK\n"
	.string "in battle. You should defeat him before\n"
	.string "coming to see WES.$"

Route25_Text_Wes:
	.string "Let's talk inside. There's not\n"
	.string "much time and the hideout is\l"
	.string "better than talking out here.$"

Route25_Text_Youngster1_Intro:
	.string "I found a great spot for a\n"
	.string "battle!$"

Route25_Text_Youngster1_Defeat:
	.string "Aw man!$"

Route25_Text_Youngster1_After:
	.string "I'll keep training here.$"

Route25_Text_Lady_Intro:
	.string "Lovely weather for a stroll...\n"
	.string "and a battle!$"

Route25_Text_Lady_Defeat:
	.string "Oh dear!$"

Route25_Text_Lady_After:
	.string "That was refreshing.$"

Route25_Text_CooltrainerF_Intro:
	.string "Route 25 is where I sharpen\n"
	.string "my skills.$"

Route25_Text_CooltrainerF_Defeat:
	.string "Nicely done!$"

Route25_Text_CooltrainerF_After:
	.string "Keep pushing yourself.$"

Route25_Text_Youngster2_Intro:
	.string "Bet you can't beat me!$"

Route25_Text_Youngster2_Defeat:
	.string "No way!$"

Route25_Text_Youngster2_After:
	.string "I'll get you next time.$"

Route25_Text_Camper_Intro:
	.string "I camp here to train every\n"
	.string "day.$"

Route25_Text_Camper_Defeat:
	.string "My tent luck ran out.$"

Route25_Text_Camper_After:
	.string "I'll try again tomorrow.$"

Route25_Text_Lass_Intro:
	.string "Let's have a quick battle!$"

Route25_Text_Lass_Defeat:
	.string "You won!$"

Route25_Text_Lass_After:
	.string "Maybe next time.$"

Route25_Text_SuperNerd_Intro:
	.string "My calculations say I win.$"

Route25_Text_SuperNerd_Defeat:
	.string "Error...$"

Route25_Text_SuperNerd_After:
	.string "Back to the drawing board.$"

Route25_Text_Eusine:
	.string "I came here looking for the\n"
	.string "legendary beast, but to my\l"
	.string "surprise a kid with red hair\l"
	.string "has taken over the area.\p"
	.string "He told me there has been major\n"
	.string "changes happening in this\l"
	.string "timeline and now I wonder, am\l"
	.string "I not in my own timeline?\p"
	.string "No matter, my search for SUICUNE\n"
	.string "resumes. If you find any clues\l"
	.string "I want you to tell BILL. He is\l"
	.string "a good friend of mine. Till we\l"
	.string "meet again!$"
