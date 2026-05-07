VioletCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Gym_OnTransition
	.byte 0

VioletCity_Gym_Speaker_Falkner:
	.string "FALKNER$"

VioletCity_Gym_Speaker_GymGuy:
	.string "GUIDE$"

VioletCity_Gym_Speaker_BirdKeeper1:
	.string "ROBIN$"

VioletCity_Gym_Speaker_BirdKeeper2:
	.string "KYLE$"

VioletCity_Gym_OnTransition:
	goto_if_unset FLAG_BADGE17_GET, VioletCity_Gym_OnTransition_Done
	call VioletCity_Gym_EventScript_SetGymTrainers
VioletCity_Gym_OnTransition_Done:
	end

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE17_GET, VioletCity_Gym_EventScript_GymGuy_After
	setspeaker VioletCity_Gym_Speaker_GymGuy
	msgbox VioletCity_Gym_Text_GymGuy_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_GymGuy_After::
	setspeaker VioletCity_Gym_Speaker_GymGuy
	msgbox VioletCity_Gym_Text_GymGuy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_BirdKeeper1::
	setspeaker VioletCity_Gym_Speaker_BirdKeeper1
	trainerbattle_single TRAINER_VIOLET_GYM_BIRD_KEEPER_1, VioletCity_Gym_Text_BirdKeeper1_Intro, VioletCity_Gym_Text_BirdKeeper1_Defeat, VioletCity_Gym_EventScript_BirdKeeper1_After
	end

VioletCity_Gym_EventScript_BirdKeeper1_After::
	setspeaker VioletCity_Gym_Speaker_BirdKeeper1
	msgbox VioletCity_Gym_Text_BirdKeeper1_After, MSGBOX_NPC
	closemessage
	release
	end

VioletCity_Gym_EventScript_BirdKeeper2::
	setspeaker VioletCity_Gym_Speaker_BirdKeeper2
	trainerbattle_single TRAINER_VIOLET_GYM_BIRD_KEEPER_2, VioletCity_Gym_Text_BirdKeeper2_Intro, VioletCity_Gym_Text_BirdKeeper2_Defeat, VioletCity_Gym_EventScript_BirdKeeper2_After
	end

VioletCity_Gym_EventScript_BirdKeeper2_After::
	setspeaker VioletCity_Gym_Speaker_BirdKeeper2
	msgbox VioletCity_Gym_Text_BirdKeeper2_After, MSGBOX_NPC
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_BADGE17_GET, VioletCity_Gym_EventScript_Falkner_After
	setspeaker VioletCity_Gym_Speaker_Falkner
	msgbox VioletCity_Gym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, VioletCity_Gym_Text_Falkner_Defeat
	message VioletCity_Gym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletCity_Gym_Text_Falkner_After, MSGBOX_DEFAULT
	setflag FLAG_BADGE17_GET
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 17
	call VioletCity_Gym_EventScript_SetGymTrainers
	checkflag FLAG_QUEST_DEFEAT_FALKNER_COMPLETED
	goto_if_eq VioletCity_Gym_EventScript_Falkner_QuestCheck_Done
	setflag FLAG_QUEST_DEFEAT_FALKNER_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
VioletCity_Gym_EventScript_Falkner_QuestCheck_Done:
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_After::
	setspeaker VioletCity_Gym_Speaker_Falkner
	msgbox VioletCity_Gym_Text_Falkner_After, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_SetGymTrainers::
	settrainerflag TRAINER_VIOLET_GYM_BIRD_KEEPER_1
	settrainerflag TRAINER_VIOLET_GYM_BIRD_KEEPER_2
	return

VioletCity_Gym_Text_GymGuy_Intro:
	.string "Yo, challenger!\p"
	.string "FALKNER watches the skies for\n"
	.string "trouble. His birds strike fast.\p"
	.string "Don't let them control the air!$"

VioletCity_Gym_Text_GymGuy_After:
	.string "Nice! VIOLET can breathe easier\n"
	.string "with you around.$"

VioletCity_Gym_Text_BirdKeeper1_Intro:
	.string "FALKNER says the skies have been\n"
	.string "uneasy. I'll test you.$"

VioletCity_Gym_Text_BirdKeeper1_Defeat:
	.string "My wings failed!$"

VioletCity_Gym_Text_BirdKeeper1_After:
	.string "He trains us to stay sharp for\n"
	.string "shadow threats.$"

VioletCity_Gym_Text_BirdKeeper2_Intro:
	.string "Birds can sense danger before\n"
	.string "anyone else. Ready?$"

VioletCity_Gym_Text_BirdKeeper2_Defeat:
	.string "Downed...$"

VioletCity_Gym_Text_BirdKeeper2_After:
	.string "If shadows show up, FALKNER will\n"
	.string "drive them out.$"

VioletCity_Gym_Text_Falkner_Intro:
	.string "I'm FALKNER, the VIOLET GYM\n"
	.string "LEADER.\p"
	.string "The winds have been strange lately.\n"
	.string "Still, my birds won't falter.\p"
	.string "Show me your resolve!$"

VioletCity_Gym_Text_Falkner_Defeat:
	.string "Impressive. Your will soared\n"
	.string "higher than mine.$"

VioletCity_Gym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} received the ZEPHYRBADGE!$"

VioletCity_Gym_Text_Falkner_After:
	.string "Keep your eyes on the skies.\n"
	.string "Shadows move swiftly.\p"
	.string "When you beat a GYM LEADER, your\n"
	.string "POKéMON can grow stronger. Each badge\l"
	.string "raises the limit.\p"
	.string "If we're talking levels, you can\n"
	.string "reach level 28 now.$"

VioletCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE17_GET, VioletCity_Gym_EventScript_StatuePostVictory
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

VioletCity_Gym_EventScript_StatuePostVictory::
	msgbox VioletCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

VioletCity_Gym_Text_GymStatue:
	.string "VIOLET POKéMON GYM\n"
	.string "LEADER: FALKNER\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, GARY, GOLD$"

VioletCity_Gym_Text_GymStatuePlayerWon:
	.string "VIOLET POKéMON GYM\n"
	.string "LEADER: FALKNER\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, GARY, GOLD, {PLAYER}$"

VioletCity_Gym_EventScript_Honchkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HONCHKROW, CRY_MODE_NORMAL
	waitmoncry
	release
	end
