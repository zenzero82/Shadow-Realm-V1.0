.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID, VAR_0x8004
.set SWITCH2_ID, VAR_0x8005
.set TRASH_CAN_ID, VAR_0x8008

vermilion_gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_OnLoad_BeamsOff
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_OnLoad_OneBeamOff
	call VermilionCity_Gym_EventScript_SetBeamsOn
	end

VermilionCity_Gym_OnLoad_OneBeamOff::
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	end

VermilionCity_Gym_OnLoad_BeamsOff::
	call VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	goto_if_unset FLAG_BADGE11_GET, VermilionCity_Gym_OnTransition_End
	call VermilionCity_Gym_EventScript_SetGymTrainers
VermilionCity_Gym_OnTransition_End:
	end

VermilionCity_Gym_Speaker_Surge:
	.string "LT. SURGE$"

VermilionCity_Gym_Speaker_GymGuy:
	.string "GYM GUY$"

VermilionCity_Gym_Speaker_Juggler:
	.string "LEO$"

VermilionCity_Gym_Speaker_Gentleman:
	.string "EDGAR$"

VermilionCity_Gym_Speaker_Rocker:
	.string "AXEL$"

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, TRUE
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, TRUE
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, TRUE
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, TRUE
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, TRUE
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, TRUE
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, TRUE
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, TRUE
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, TRUE
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, TRUE
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, TRUE
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, FALSE
	setmetatile 5, 6, METATILE_VermilionGym_Floor, FALSE
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, FALSE
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, TRUE
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, TRUE
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, FALSE
	setmetatile 5, 7, METATILE_VermilionGym_Floor, FALSE
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, FALSE
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, TRUE
	return

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, TRUE
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, TRUE
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, TRUE
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, TRUE
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, TRUE
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, TRUE
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, TRUE
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, TRUE
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, TRUE
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, TRUE
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	setspeaker VermilionCity_Gym_Speaker_Surge
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_Surge_Defeated
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox VermilionCity_Gym_Text_Surge_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SURGE, VermilionCity_Gym_Text_Surge_WinLoss
	message VermilionCity_Gym_Text_Surge_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM_EERIE_IMPULSE
	setspeaker VermilionCity_Gym_Speaker_Surge
	msgbox VermilionCity_Gym_Text_Surge_After, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	call VermilionCity_Gym_EventScript_SetGymTrainers
	closemessage
	release
	end

VermilionCity_Gym_EventScript_Surge_Defeated::
	setspeaker VermilionCity_Gym_Speaker_Surge
	msgbox VermilionCity_Gym_Text_Surge_After, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_Gym_EventScript_SetGymTrainers::
	settrainerflag TRAINER_VERMILION_GYM_JUGGLER
	settrainerflag TRAINER_VERMILION_GYM_GENTLEMAN
	settrainerflag TRAINER_VERMILION_GYM_ROCKER
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	setspeaker VermilionCity_Gym_Speaker_GymGuy
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymGuy_After
	msgbox VermilionCity_Gym_Text_GymGuy_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GymGuy_After::
	msgbox VermilionCity_Gym_Text_GymGuy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_Gym_EventScript_Juggler::
	setspeaker VermilionCity_Gym_Speaker_Juggler
	trainerbattle_single TRAINER_VERMILION_GYM_JUGGLER, VermilionCity_Gym_Text_Juggler_Intro, VermilionCity_Gym_Text_Juggler_Defeat, VermilionCity_Gym_EventScript_Juggler_After
	end

VermilionCity_Gym_EventScript_Juggler_After::
	setspeaker VermilionCity_Gym_Speaker_Juggler
	msgbox VermilionCity_Gym_Text_Juggler_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_Gym_EventScript_Gentleman::
	setspeaker VermilionCity_Gym_Speaker_Gentleman
	trainerbattle_single TRAINER_VERMILION_GYM_GENTLEMAN, VermilionCity_Gym_Text_Gentleman_Intro, VermilionCity_Gym_Text_Gentleman_Defeat, VermilionCity_Gym_EventScript_Gentleman_After
	end

VermilionCity_Gym_EventScript_Gentleman_After::
	setspeaker VermilionCity_Gym_Speaker_Gentleman
	msgbox VermilionCity_Gym_Text_Gentleman_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_Gym_EventScript_Rocker::
	setspeaker VermilionCity_Gym_Speaker_Rocker
	trainerbattle_single TRAINER_VERMILION_GYM_ROCKER, VermilionCity_Gym_Text_Rocker_Intro, VermilionCity_Gym_Text_Rocker_Defeat, VermilionCity_Gym_EventScript_Rocker_After
	end

VermilionCity_Gym_EventScript_Rocker_After::
	setspeaker VermilionCity_Gym_Speaker_Rocker
	msgbox VermilionCity_Gym_Text_Rocker_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	end

VermilionCity_Gym_Text_GymStatue:
	.string "VERMILION GYM\n"
	.string "LEADER: LT. SURGE$"

VermilionCity_Gym_Text_GymStatuePlayerWon:
	.string "WINNING TRAINERS:\n"
	.string "RED, BLUE, WES, {PLAYER}$"

VermilionCity_Gym_Text_Surge_Intro:
	.string "Hey, kid! I'm LT. SURGE, the\n"
	.string "VERMILION GYM LEADER.\p"
	.string "Electricity is my specialty.\n"
	.string "Prepare to get shocked!$"

VermilionCity_Gym_Text_Surge_WinLoss:
	.string "Whoa! That was a jolt!\p"
	.string "You earned the THUNDERBADGE.$"

VermilionCity_Gym_Text_Surge_ReceivedThunderBadge:
	.string "{PLAYER} received the THUNDERBADGE!$"

VermilionCity_Gym_Text_Surge_After:
	.string "With the THUNDERBADGE, your POKéMON\n"
	.string "can push past the next power limit.\p"
	.string "If it were levels, I'd say you could\n"
	.string "go to level 40 now.$"

VermilionCity_Gym_Text_GymGuy_Intro:
	.string "Yo! CHAMP in the making!\p"
	.string "LT. SURGE's ELECTRIC types are fast\n"
	.string "and love to paralyze. Be ready!$"

VermilionCity_Gym_Text_GymGuy_After:
	.string "You lit him up! That THUNDERBADGE\n"
	.string "looks great on you!$"

VermilionCity_Gym_Text_Juggler_Intro:
	.string "My VOLTORB are quick on the draw!$"

VermilionCity_Gym_Text_Juggler_Defeat:
	.string "Overloaded!$"

VermilionCity_Gym_Text_Juggler_After:
	.string "Guess I dropped the ball.$"

VermilionCity_Gym_Text_Gentleman_Intro:
	.string "Refined strategy beats raw power!$"

VermilionCity_Gym_Text_Gentleman_Defeat:
	.string "How shocking!$"

VermilionCity_Gym_Text_Gentleman_After:
	.string "I concede to your form.$"

VermilionCity_Gym_Text_Rocker_Intro:
	.string "Turn up the voltage!$"

VermilionCity_Gym_Text_Rocker_Defeat:
	.string "Blown out!$"

VermilionCity_Gym_Text_Rocker_After:
	.string "You really rocked me.$"

VermilionCity_Gym_Text_NopeOnlyTrashHere:
	.string "Nope!\n"
	.string "There's only trash here.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened:
	.string "Hey! There's a switch under the\n"
	.string "trash! Turn it on!\p"
	.string "The first electric lock opened!$"

VermilionCity_Gym_Text_SecondLockOpened:
	.string "The second electric lock opened!\n"
	.string "The motorized door opened!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset:
	.string "Nope!\n"
	.string "There's only trash here.\p"
	.string "Hey!\n"
	.string "The electric locks were reset!$"
