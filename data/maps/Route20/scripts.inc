Route20_MapScripts::
	.byte 0

Route20_Speaker_Fisherman:
	.string "WADE$"

Route20_Speaker_SwimmerF1:
	.string "MARINA$"

Route20_Speaker_SwimmerF2:
	.string "SELENE$"

Route20_Speaker_SwimmerM:
	.string "BROOKS$"

Route20_Speaker_PlasmaF:
	.string "RHEA$"

Route20_Speaker_PlasmaM:
	.string "ZANE$"

Route20_EventScript_Fisherman::
	setspeaker Route20_Speaker_Fisherman
	trainerbattle_single TRAINER_ROUTE20_FISHERMAN, Route20_Text_Fisherman_Intro, Route20_Text_Fisherman_Defeat, Route20_EventScript_Fisherman_After
	end

Route20_EventScript_SwimmerF1::
	setspeaker Route20_Speaker_SwimmerF1
	trainerbattle_single TRAINER_ROUTE20_SWIMMER_F1, Route20_Text_SwimmerF1_Intro, Route20_Text_SwimmerF1_Defeat, Route20_EventScript_SwimmerF1_After
	end

Route20_EventScript_SwimmerF2::
	setspeaker Route20_Speaker_SwimmerF2
	trainerbattle_single TRAINER_ROUTE20_SWIMMER_F2, Route20_Text_SwimmerF2_Intro, Route20_Text_SwimmerF2_Defeat, Route20_EventScript_SwimmerF2_After
	end

Route20_EventScript_SwimmerM::
	setspeaker Route20_Speaker_SwimmerM
	trainerbattle_single TRAINER_ROUTE20_SWIMMER_M, Route20_Text_SwimmerM_Intro, Route20_Text_SwimmerM_Defeat, Route20_EventScript_SwimmerM_After
	end

Route20_EventScript_Fisherman_After::
	setspeaker Route20_Speaker_Fisherman
	msgbox Route20_Text_Fisherman_After, MSGBOX_NPC
	closemessage
	release
	end

Route20_EventScript_SwimmerF1_After::
	setspeaker Route20_Speaker_SwimmerF1
	msgbox Route20_Text_SwimmerF1_After, MSGBOX_NPC
	closemessage
	release
	end

Route20_EventScript_SwimmerF2_After::
	setspeaker Route20_Speaker_SwimmerF2
	msgbox Route20_Text_SwimmerF2_After, MSGBOX_NPC
	closemessage
	release
	end

Route20_EventScript_SwimmerM_After::
	setspeaker Route20_Speaker_SwimmerM
	msgbox Route20_Text_SwimmerM_After, MSGBOX_NPC
	closemessage
	release
	end

Route20_EventScript_PlasmaF::
	lock
	faceplayer
	setspeaker Route20_Speaker_PlasmaF
	msgbox Route20_Text_PlasmaF, MSGBOX_DEFAULT
	release
	end

Route20_EventScript_PlasmaM::
	lock
	faceplayer
	setspeaker Route20_Speaker_PlasmaM
	msgbox Route20_Text_PlasmaM, MSGBOX_DEFAULT
	release
	end

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_Text_SeafoamSign:
	.string "SEAFOAM ISLANDS$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "What does this sign say?\p"
	.string "CINNABAR GYM LEADER: BLAINE$"

Route20_Text_Fisherman_Intro:
	.string "These waters toughened up my team.\p"
	.string "Let's see if you can handle ROUTE 20!$"

Route20_Text_Fisherman_Defeat:
	.string "My line came up empty...$"

Route20_Text_Fisherman_After:
	.string "The sea around here raises strong\n"
	.string "WATER POKéMON fast.$"

Route20_Text_SwimmerF1_Intro:
	.string "The currents out here are rough,\n"
	.string "so my team learned to keep up!$"

Route20_Text_SwimmerF1_Defeat:
	.string "I got swept away...$"

Route20_Text_SwimmerF1_After:
	.string "If you can swim ROUTE 20, you can\n"
	.string "battle almost anywhere.$"

Route20_Text_SwimmerF2_Intro:
	.string "Everyone training near SEAFOAM\n"
	.string "gets stronger sooner or later!$"

Route20_Text_SwimmerF2_Defeat:
	.string "Guess today was your turn.$"

Route20_Text_SwimmerF2_After:
	.string "My team loves these cold currents.\n"
	.string "They never stay still for long.$"

Route20_Text_SwimmerM_Intro:
	.string "I patrol this stretch every day.\p"
	.string "A trainer battle keeps me sharp!$"

Route20_Text_SwimmerM_Defeat:
	.string "You outswam me there.$"

Route20_Text_SwimmerM_After:
	.string "The sea by Cinnabar looks calm,\n"
	.string "but it can turn brutal fast.$"

Route20_Text_PlasmaF:
	.string "Not another step.\p"
	.string "TEAM PLASMA won't allow anyone to\n"
	.string "enter from this side.$"

Route20_Text_PlasmaM:
	.string "Turn around and get lost.\p"
	.string "This area is under TEAM PLASMA's\n"
	.string "control right now.$"
