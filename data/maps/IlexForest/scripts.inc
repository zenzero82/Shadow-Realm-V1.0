IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	.byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

IlexForest_Speaker_JJ:
	.string "Jessie&James$"

IlexForest_Speaker_Rocket:
	.string "ROCKET$"

IlexForest_Speaker_BugCatcher:
	.string "BUG CATCHER$"

@ =========================================================
@ TRAINERS
@ =========================================================

IlexForest_EventScript_JJ_Talk::
	setspeaker IlexForest_Speaker_JJ
	trainerbattle_single TRAINER_JJ_ILEX, IlexForest_Text_JJ_Intro, IlexForest_Text_JJ_Defeat, IlexForest_EventScript_JJ_After
	end

IlexForest_EventScript_JJ_After::
	setspeaker IlexForest_Speaker_JJ
	msgbox IlexForest_Text_JJ_After, MSGBOX_NPC
	closemessage
	setflag FLAG_HIDE_ILEX_JJ_GROUP
	removeobject LOCALID_ILEX_JESSIE
	removeobject LOCALID_ILEX_JAMES
	release
	end

IlexForest_EventScript_RocketGrunt_F1::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M1::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M1, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_F2::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M2::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M2, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_M3::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_M3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_RocketGrunt_F3::
	setspeaker IlexForest_Speaker_Rocket
	trainerbattle_single TRAINER_ILEX_ROCKET_GRUNT_F3, IlexForest_Text_Rocket_Intro, IlexForest_Text_Rocket_Defeat, IlexForest_EventScript_Rocket_After
	end

IlexForest_EventScript_Rocket_After::
	setspeaker IlexForest_Speaker_Rocket
	msgbox IlexForest_Text_Rocket_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_BugCatcher::
	setspeaker IlexForest_Speaker_BugCatcher
	trainerbattle_single TRAINER_ILEX_BUG_CATCHER, IlexForest_Text_BugCatcher_Intro, IlexForest_Text_BugCatcher_Defeat, IlexForest_EventScript_BugCatcher_After
	end

IlexForest_EventScript_BugCatcher_After::
	setspeaker IlexForest_Speaker_BugCatcher
	msgbox IlexForest_Text_BugCatcher_After, MSGBOX_NPC
	closemessage
	release
	end

IlexForest_EventScript_HoopaRing::
	end

IlexForest_EventScript_CharonScene::
	end

@ =========================================================
@ TEXT
@ =========================================================

IlexForest_Text_JJ_Intro:
	.string "We found a strange MEOWTH in these\n"
	.string "woods! Hand it over!$"

IlexForest_Text_JJ_Defeat:
	.string "We're blasting off again!$"

IlexForest_Text_JJ_After:
	.string "TEAM ROCKET will be back for that\n"
	.string "MEOWTH!$"

IlexForest_Text_Rocket_Intro:
	.string "We're busy in this forest.\n"
	.string "Stay out of the way!$"

IlexForest_Text_Rocket_Defeat:
	.string "Tch...$"

IlexForest_Text_Rocket_After:
	.string "You didn't see anything.$"

IlexForest_Text_BugCatcher_Intro:
	.string "Team Rocket's everywhere...\n"
	.string "Don't get caught!$"

IlexForest_Text_BugCatcher_Defeat:
	.string "I tried!$"

IlexForest_Text_BugCatcher_After:
	.string "I just want to keep my bugs safe.$"
