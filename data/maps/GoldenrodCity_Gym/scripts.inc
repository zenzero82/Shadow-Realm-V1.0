GoldenrodCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_Gym_OnTransition
	.byte 0

GoldenrodCity_Gym_Speaker_Whitney:
	.string "WHITNEY$"

GoldenrodCity_Gym_Speaker_GymGuy:
	.string "Gym Guy$"

GoldenrodCity_Gym_Speaker_Carrie:
	.string "CARRIE$"

GoldenrodCity_Gym_Speaker_Leah:
	.string "LEAH$"

GoldenrodCity_Gym_Speaker_Brooke:
	.string "BROOKE$"

GoldenrodCity_Gym_Speaker_Mara:
	.string "MARA$"

GoldenrodCity_Gym_Speaker_Miltank:
	.string "MILTANK$"

#define LOCALID_GOLDENROD_CITY_GYM_GYM_GUY 2
#define LOCALID_GOLDENROD_CITY_GYM_MARA 6

GoldenrodCity_Gym_OnTransition:
	setvar VAR_TEMP_0, 0
	goto_if_unset FLAG_BADGE19_GET, GoldenrodCity_Gym_OnTransition_Done
	call GoldenrodCity_Gym_EventScript_SetGymTrainers
GoldenrodCity_Gym_OnTransition_Done:
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_Gym_EventScript_Whitney_After
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	setspeaker GoldenrodCity_Gym_Speaker_Whitney
	msgbox GoldenrodCity_Gym_Text_Whitney_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, GoldenrodCity_Gym_Text_Whitney_Defeat
	turnobject LOCALID_PLAYER, DIR_SOUTH
	applymovement LOCALID_GOLDENROD_CITY_GYM_MARA, GoldenrodCity_Gym_Movement_MaraStepUp
	waitmovement 0
	setspeaker GoldenrodCity_Gym_Speaker_Mara
	msgbox GoldenrodCity_Gym_Text_Mara_Alert, MSGBOX_DEFAULT
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker GoldenrodCity_Gym_Speaker_Whitney
	msgbox GoldenrodCity_Gym_Text_Whitney_Badge, MSGBOX_DEFAULT
	message GoldenrodCity_Gym_Text_ReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM_HYPER_VOICE
	setflag FLAG_BADGE19_GET
	setflag FLAG_QUEST_WHITNEY_COMPLETED
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 19
	call GoldenrodCity_Gym_EventScript_SetGymTrainers
	setspeaker GoldenrodCity_Gym_Speaker_Whitney
	msgbox GoldenrodCity_Gym_Text_Whitney_After, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney_After::
	setspeaker GoldenrodCity_Gym_Speaker_Whitney
	msgbox GoldenrodCity_Gym_Text_Whitney_After, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_Gym_EventScript_GymGuy_After
	setspeaker GoldenrodCity_Gym_Speaker_GymGuy
	msgbox GoldenrodCity_Gym_Text_GymGuy_Intro, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Gym_EventScript_GymGuy_After::
	setspeaker GoldenrodCity_Gym_Speaker_GymGuy
	msgbox GoldenrodCity_Gym_Text_GymGuy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_ExitTriggerLeft::
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_Gym_EventScript_ExitTrigger

GoldenrodCity_Gym_EventScript_ExitTriggerCenter::
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_Gym_EventScript_ExitTrigger

GoldenrodCity_Gym_EventScript_ExitTriggerRight::
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_Gym_EventScript_ExitTrigger

GoldenrodCity_Gym_EventScript_ExitTrigger::
	goto_if_unset FLAG_BADGE19_GET, GoldenrodCity_Gym_EventScript_ExitTrigger_End
	goto_if_set FLAG_GOLDENROD_BASEMENT_KEY_GIVEN, GoldenrodCity_Gym_EventScript_ExitTrigger_End
	setvar VAR_TEMP_0, 1
	switch VAR_0x8004
	case 0, GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyLeft
	case 1, GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyCenter
	case 2, GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyRight

GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyLeft:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyApproachLeft
	goto GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyDone

GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyCenter:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyApproachCenter
	goto GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyDone

GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyRight:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyApproachRight

GoldenrodCity_Gym_EventScript_ExitTrigger_MoveGymGuyDone:
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, DIR_SOUTH
	setspeaker GoldenrodCity_Gym_Speaker_GymGuy
	msgbox GoldenrodCity_Gym_Text_GymGuy_BasementKey1, MSGBOX_DEFAULT
	msgbox GoldenrodCity_Gym_Text_GymGuy_BasementKey2, MSGBOX_DEFAULT
	setflag FLAG_GOLDENROD_BASEMENT_KEY_GIVEN
	setflag FLAG_QUEST_GOLDENROD_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	switch VAR_0x8004
	case 0, GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyLeft
	case 1, GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyCenter
	case 2, GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyRight

GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyLeft:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyReturnLeft
	goto GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyDone

GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyCenter:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyReturnCenter
	goto GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyDone

GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyRight:
	applymovement LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, GoldenrodCity_Gym_Movement_GymGuyReturnRight

GoldenrodCity_Gym_EventScript_ExitTrigger_ReturnGymGuyDone:
	waitmovement 0
	turnobject LOCALID_GOLDENROD_CITY_GYM_GYM_GUY, DIR_SOUTH
	releaseall
	end

GoldenrodCity_Gym_EventScript_ExitTrigger_End:
	releaseall
	end

GoldenrodCity_Gym_EventScript_Carrie::
	setspeaker GoldenrodCity_Gym_Speaker_Carrie
	trainerbattle_single TRAINER_GOLDENROD_GYM_CARRIE, GoldenrodCity_Gym_Text_Carrie_Intro, GoldenrodCity_Gym_Text_Carrie_Defeat, GoldenrodCity_Gym_EventScript_Carrie_After
	end

GoldenrodCity_Gym_EventScript_Carrie_After::
	setspeaker GoldenrodCity_Gym_Speaker_Carrie
	msgbox GoldenrodCity_Gym_Text_Carrie_After, MSGBOX_NPC
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Leah::
	setspeaker GoldenrodCity_Gym_Speaker_Leah
	trainerbattle_single TRAINER_GOLDENROD_GYM_LEAH, GoldenrodCity_Gym_Text_Leah_Intro, GoldenrodCity_Gym_Text_Leah_Defeat, GoldenrodCity_Gym_EventScript_Leah_After
	end

GoldenrodCity_Gym_EventScript_Leah_After::
	setspeaker GoldenrodCity_Gym_Speaker_Leah
	msgbox GoldenrodCity_Gym_Text_Leah_After, MSGBOX_NPC
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Brooke::
	setspeaker GoldenrodCity_Gym_Speaker_Brooke
	trainerbattle_single TRAINER_GOLDENROD_GYM_BROOKE, GoldenrodCity_Gym_Text_Brooke_Intro, GoldenrodCity_Gym_Text_Brooke_Defeat, GoldenrodCity_Gym_EventScript_Brooke_After
	end

GoldenrodCity_Gym_EventScript_Brooke_After::
	setspeaker GoldenrodCity_Gym_Speaker_Brooke
	msgbox GoldenrodCity_Gym_Text_Brooke_After, MSGBOX_NPC
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Mara::
	setspeaker GoldenrodCity_Gym_Speaker_Mara
	trainerbattle_single TRAINER_GOLDENROD_GYM_MARA, GoldenrodCity_Gym_Text_Mara_Intro, GoldenrodCity_Gym_Text_Mara_Defeat, GoldenrodCity_Gym_EventScript_Mara_After
	end

GoldenrodCity_Gym_EventScript_Mara_After::
	setspeaker GoldenrodCity_Gym_Speaker_Mara
	msgbox GoldenrodCity_Gym_Text_Mara_After, MSGBOX_NPC
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Miltank::
	lock
	faceplayer
	setspeaker GoldenrodCity_Gym_Speaker_Miltank
	msgbox GoldenrodCity_Gym_Text_Miltank, MSGBOX_DEFAULT
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	waitmoncry
	release
	end

GoldenrodCity_Gym_EventScript_SetGymTrainers::
	settrainerflag TRAINER_GOLDENROD_GYM_CARRIE
	settrainerflag TRAINER_GOLDENROD_GYM_LEAH
	settrainerflag TRAINER_GOLDENROD_GYM_BROOKE
	settrainerflag TRAINER_GOLDENROD_GYM_MARA
	return

GoldenrodCity_Gym_Text_GymGuy_Intro:
	.string "Yo! This GYM stayed open even with\n"
	.string "CIPHER leaning on the city. Respect.\n"
	.string "WHITNEY hits hard and fast.$"

GoldenrodCity_Gym_Text_GymGuy_After:
	.string "That PLAINBADGE means a lot right now.\n"
	.string "Goldenrod needed a win.$"

GoldenrodCity_Gym_Text_GymGuy_BasementKey1:
	.string "Hey kid! The RADIO TOWER,\n"
	.string "CIPHER has taken it over and they\l"
	.string "are preparing for a broadcast!\p"
	.string "WHITNEY's POKeMON are much\n"
	.string "too weak right now, so she needs\l"
	.string "to stay here and make sure the \n"
	.string "people of the city are safe.\p"
	.string "{PLAYER}, can you go see if you can\n"
	.string "figure out what is going on over\l"
	.string "there?$"

GoldenrodCity_Gym_Text_GymGuy_BasementKey2:
	.string "The RADIO TOWER CEO\n"
	.string "and their workers were spotted being\l"
	.string "moved through the underground tunnels.\p"
	.string "Some are saying that the doors are\n"
	.string "locked!\p"
	.string "There's a connection in\n"
	.string "the GOLDENROD DEPARTMENT STORE.\p"
	.string "In the basement, there's a storage\n"
	.string "area that links to the tunnel.\p"
	.string "That has to be where they\n"
	.string "were moved.\p"
	.string "Can you go check that out and see if\n"
	.string "you find anything? Maybe there's a\l"
	.string "clue if nothing else.$"

GoldenrodCity_Gym_Text_Carrie_Intro:
	.string "If Goldenrod's under pressure, we just\n"
	.string "train harder. Come on!$"

GoldenrodCity_Gym_Text_Carrie_Defeat:
	.string "Still not cute enough...$"

GoldenrodCity_Gym_Text_Carrie_After:
	.string "WHITNEY says strength doesn't have to\n"
	.string "look stern.$"

GoldenrodCity_Gym_Text_Leah_Intro:
	.string "You don't get to meet WHITNEY unless\n"
	.string "you can break through us first!$"

GoldenrodCity_Gym_Text_Leah_Defeat:
	.string "You broke through...$"

GoldenrodCity_Gym_Text_Leah_After:
	.string "The city's tense, so every battle in\n"
	.string "here feels serious now.$"

GoldenrodCity_Gym_Text_Brooke_Intro:
	.string "Cute POKéMON can still flatten you.\n"
	.string "Don't forget it.$"

GoldenrodCity_Gym_Text_Brooke_Defeat:
	.string "Flattened instead...$"

GoldenrodCity_Gym_Text_Brooke_After:
	.string "WHITNEY keeps us smiling so CIPHER\n"
	.string "doesn't think fear won.$"

GoldenrodCity_Gym_Text_Mara_Intro:
	.string "I came from the DEPT. STORE to train.\n"
	.string "Now let's battle.$"

GoldenrodCity_Gym_Text_Mara_Defeat:
	.string "That was a clean hit.$"

GoldenrodCity_Gym_Text_Mara_After:
	.string "This GYM reminds people Goldenrod can\n"
	.string "still push back.$"

GoldenrodCity_Gym_Text_Whitney_Intro:
	.string "I'm WHITNEY!\p"
	.string "The city is being taken over you say?\p"
	.string "You're just trying to distract me,\n"
	.string "I've been listening to the radio and\l"
	.string "I haven't heard a thing!\p"
	.string "Now lets battle!$"

GoldenrodCity_Gym_Text_Whitney_Defeat:
	.string "Wow... You really are the real deal.$"

GoldenrodCity_Gym_Text_ReceivedPlainBadge:
	.string "{PLAYER} received the PLAINBADGE!$"

GoldenrodCity_Gym_Text_Whitney_Badge:
	.string "Oh no! They must have been running a\n"
	.string "different program to the city as I\l"
	.string "heard nothing on the airwaves.\p"
	.string "{PLAYER} since you defeated me I know\n"
	.string "you have what it takes to run those\l"
	.string "guys out. Here take this badge.$"

GoldenrodCity_Gym_Text_Whitney_After:
	.string "By the way your POKéMON should be able\n"
	.string "to continue getting stronger.\p"
	.string "In terms of level I would say 44 is\n"
	.string "the bar now. Be careful {PLAYER},\l"
	.string "I'll do my best to lend some help!$"

GoldenrodCity_Gym_Text_Mara_Alert:
	.string "WHITNEY he's telling the truth!\n"
	.string "While you were battling I took a walk\l"
	.string "over to the RADIO TOWER and it's been\l"
	.string "hijacked!$"

GoldenrodCity_Gym_Text_Miltank:
	.string "Miltank looks ready to charge into\n"
	.string "another battle.$"

GoldenrodCity_Gym_Movement_MaraStepUp:
	walk_up
	step_end

GoldenrodCity_Gym_Movement_GymGuyApproachLeft:
	walk_down
	walk_left
	walk_left
	step_end

GoldenrodCity_Gym_Movement_GymGuyApproachCenter:
	walk_left
	step_end

GoldenrodCity_Gym_Movement_GymGuyApproachRight:
	walk_down
	step_end

GoldenrodCity_Gym_Movement_GymGuyReturnLeft:
	walk_right
	walk_right
	walk_up
	step_end

GoldenrodCity_Gym_Movement_GymGuyReturnCenter:
	walk_right
	step_end

GoldenrodCity_Gym_Movement_GymGuyReturnRight:
	walk_up
	step_end

GoldenrodCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_Gym_EventScript_StatuePostVictory
	msgbox GoldenrodCity_Gym_Text_Statue, MSGBOX_SIGN
	releaseall
	end

GoldenrodCity_Gym_EventScript_StatuePostVictory::
	msgbox GoldenrodCity_Gym_Text_StatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

GoldenrodCity_Gym_Text_Statue:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, GARY, GOLD$"

GoldenrodCity_Gym_Text_StatuePlayerWon:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "WINNING TRAINERS:\n"
	.string "RED, GARY, GOLD, {PLAYER}$"
