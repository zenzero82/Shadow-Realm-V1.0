cerulean_gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, cerulean_gym_OnTransition
	.byte 0

cerulean_gym_OnTransition:
	goto_if_unset FLAG_BADGE10_GET, cerulean_gym_OnTransition_End
	call cerulean_gym_EventScript_SetGymTrainers
cerulean_gym_OnTransition_End:
	end

cerulean_gym_Speaker_Misty:
	.string "MISTY$"

cerulean_gym_Speaker_GymGuy:
	.string "GUIDE$"

cerulean_gym_Speaker_SwimmerM:
	.string "TYLER$"

cerulean_gym_Speaker_SwimmerF1:
	.string "MAYA$"

cerulean_gym_Speaker_SwimmerF2:
	.string "KARA$"

cerulean_gym_EventScript_Misty::
	lock
	faceplayer
	setspeaker cerulean_gym_Speaker_Misty
	goto_if_set FLAG_BADGE10_GET, cerulean_gym_EventScript_Misty_Defeated

	msgbox cerulean_gym_Text_Misty_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY, cerulean_gym_Text_Misty_WinLoss

	message cerulean_gym_Text_Misty_ReceivedCascadeBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare

	setspeaker cerulean_gym_Speaker_Misty
	msgbox cerulean_gym_Text_Misty_After, MSGBOX_DEFAULT
	setflag FLAG_BADGE10_GET
	checkflag FLAG_QUEST_DEFEAT_MISTY_COMPLETED
	goto_if_eq cerulean_gym_EventScript_Misty_StartGuardsQuest
	setflag FLAG_QUEST_DEFEAT_MISTY_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
cerulean_gym_EventScript_Misty_StartGuardsQuest:
	checkflag FLAG_QUEST_ROUTE9_GUARDS_STARTED
	goto_if_eq cerulean_gym_EventScript_Misty_QuestDone
	setflag FLAG_QUEST_ROUTE9_GUARDS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	call QuestJournal_EventScript_CheckRoute9Guards
cerulean_gym_EventScript_Misty_QuestDone:
	call cerulean_gym_EventScript_SetGymTrainers
	closemessage
	release
	end

cerulean_gym_EventScript_Misty_Defeated::
	setspeaker cerulean_gym_Speaker_Misty
	msgbox cerulean_gym_Text_Misty_After, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_gym_EventScript_SetGymTrainers::
	settrainerflag TRAINER_CERULEAN_GYM_SWIMMER_M
	settrainerflag TRAINER_CERULEAN_GYM_SWIMMER_F1
	settrainerflag TRAINER_CERULEAN_GYM_SWIMMER_F2
	return

cerulean_gym_EventScript_GymGuy::
	lock
	faceplayer
	setspeaker cerulean_gym_Speaker_GymGuy
	goto_if_set FLAG_BADGE10_GET, cerulean_gym_EventScript_GymGuy_After
	msgbox cerulean_gym_Text_GymGuy_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_gym_EventScript_GymGuy_After::
	msgbox cerulean_gym_Text_GymGuy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_gym_EventScript_SwimmerM::
	setspeaker cerulean_gym_Speaker_SwimmerM
	trainerbattle_single TRAINER_CERULEAN_GYM_SWIMMER_M, cerulean_gym_Text_SwimmerM_Intro, cerulean_gym_Text_SwimmerM_Defeat, cerulean_gym_EventScript_SwimmerM_After
	end

cerulean_gym_EventScript_SwimmerM_After::
	setspeaker cerulean_gym_Speaker_SwimmerM
	msgbox cerulean_gym_Text_SwimmerM_After, MSGBOX_NPC
	closemessage
	release
	end

cerulean_gym_EventScript_SwimmerF1::
	setspeaker cerulean_gym_Speaker_SwimmerF1
	trainerbattle_single TRAINER_CERULEAN_GYM_SWIMMER_F1, cerulean_gym_Text_SwimmerF1_Intro, cerulean_gym_Text_SwimmerF1_Defeat, cerulean_gym_EventScript_SwimmerF1_After
	end

cerulean_gym_EventScript_SwimmerF1_After::
	setspeaker cerulean_gym_Speaker_SwimmerF1
	msgbox cerulean_gym_Text_SwimmerF1_After, MSGBOX_NPC
	closemessage
	release
	end

cerulean_gym_EventScript_SwimmerF2::
	setspeaker cerulean_gym_Speaker_SwimmerF2
	trainerbattle_single TRAINER_CERULEAN_GYM_SWIMMER_F2, cerulean_gym_Text_SwimmerF2_Intro, cerulean_gym_Text_SwimmerF2_Defeat, cerulean_gym_EventScript_SwimmerF2_After
	end

cerulean_gym_EventScript_SwimmerF2_After::
	setspeaker cerulean_gym_Speaker_SwimmerF2
	msgbox cerulean_gym_Text_SwimmerF2_After, MSGBOX_NPC
	closemessage
	release
	end

cerulean_gym_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

cerulean_gym_EventScript_Sign_Left::
	goto cerulean_gym_EventScript_GymStatue
	end

cerulean_gym_EventScript_Sign_Right::
	goto cerulean_gym_EventScript_GymStatue
	end

cerulean_gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE10_GET, cerulean_gym_EventScript_GymStatuePostVictory
	msgbox cerulean_gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

cerulean_gym_EventScript_GymStatuePostVictory::
	msgbox cerulean_gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

cerulean_gym_Text_Misty_Intro:
	.string "I'm MISTY, the CERULEAN GYM\n"
	.string "LEADER.\p"
	.string "My WATER POKéMON are strong and fast.\n"
	.string "Let's see what you've got!$"

cerulean_gym_Text_Misty_WinLoss:
	.string "Wow! You're too much!\p"
	.string "You can have the CASCADEBADGE.$"

cerulean_gym_Text_Misty_ReceivedCascadeBadge:
	.string "{PLAYER} received the CASCADEBADGE!$"

cerulean_gym_Text_Misty_After:
	.string "Michael was right after all.\n"
	.string "You did manage to kick my butt!\p"
	.string "This whole SHADOW POKéMON mess is\n"
	.string "stressing me out.\p"
	.string "I hate the thought of stealing\n"
	.string "trainers POKéMON, but I understand\l"
	.string "that it's to help them.\p"
	.string "Just please take care of the POKéMON.\p"
	.string "Also just so you know, when defeating\n"
	.string "one of us GYM LEADERS, your POKéMON\l"
	.string "get stronger and you'll be able to\l"
	.string "increase their strength more with each\l"
	.string "badge.\p"
	.string "If it were in terms of levels, I'd say\n"
	.string "you would be able to go to level 24 now.$"

cerulean_gym_Text_GymGuy_Intro:
	.string "Yo! CHAMP in the making!\p"
	.string "MISTY's WATER types move fast.\n"
	.string "Try your best to keep up!$"

cerulean_gym_Text_GymGuy_After:
	.string "What a battle! That CASCADE BADGE\n"
	.string "looks good on you!$"

cerulean_gym_Text_SwimmerM_Intro:
	.string "You think you can swim circles\n"
	.string "around me?$"

cerulean_gym_Text_SwimmerM_Defeat:
	.string "Wiped out!$"

cerulean_gym_Text_SwimmerM_After:
	.string "Even the pool feels tense today.\n"
	.string "Police outside are on edge.$"

cerulean_gym_Text_SwimmerF1_Intro:
	.string "Let's make a splash!$"

cerulean_gym_Text_SwimmerF1_Defeat:
	.string "You outpaced me!$"

cerulean_gym_Text_SwimmerF1_After:
	.string "I'm still training, but it feels like\n"
	.string "the whole city is holding its breath.$"

cerulean_gym_Text_SwimmerF2_Intro:
	.string "Hope you're ready for a chilly\n"
	.string "battle!$"

cerulean_gym_Text_SwimmerF2_Defeat:
	.string "Brr... that hurt.$"

cerulean_gym_Text_SwimmerF2_After:
	.string "Water helps me relax... usually.\n"
	.string "Not with all these rumors.$"

cerulean_gym_Text_Sign_Left:
	.string "CERULEAN GYM\n"
	.string "LEADER: MISTY$"

cerulean_gym_Text_Sign_Right:
	.string "Tip: Water types are weak to\n"
	.string "Electric- and Grass-type moves.$"

cerulean_gym_Text_GymStatue:
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, BLUE, WES$"

cerulean_gym_Text_GymStatuePlayerWon:
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, BLUE, WES, {PLAYER}$"
