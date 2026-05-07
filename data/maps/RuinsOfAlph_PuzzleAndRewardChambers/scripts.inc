RuinsOfAlph_PuzzleAndRewardChambers_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_PuzzleAndRewardChambers_OnLoad
	.byte 0

RuinsOfAlph_PuzzleAndRewardChambers_OnLoad::
	call_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole
	call_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteHole
	call_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole
	call_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole

	call_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor
	call_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDoor
	call_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor
	call_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor
	special RuinsOfAlph_ReloadHoOhGuardianMons
	end

RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole::
	setmetatile 20, 5, 0x282, FALSE
	setmetatile 21, 5, 0x283, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteHole::
	setmetatile 4, 22, 0x282, FALSE
	setmetatile 5, 22, 0x283, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole::
	setmetatile 20, 22, 0x282, FALSE
	setmetatile 21, 22, 0x283, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole::
	setmetatile 4, 5, 0x282, FALSE
	setmetatile 5, 5, 0x283, FALSE
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor::
	setmetatile 20, 1, 0x288, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDoor::
	setmetatile 4, 18, 0x288, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor::
	setmetatile 20, 18, 0x288, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor::
	setmetatile 4, 1, 0x288, FALSE
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDescripton::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Omanyte, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_UnownText::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_Speaker_Receptionist:
	.string "RECEPTIONIST$"

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist::
	lock
	faceplayer
	setspeaker RuinsOfAlph_PuzzleAndRewardChambers_Speaker_Receptionist
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2::
	setspeaker RuinsOfAlph_PuzzleAndRewardChambers_Speaker_Receptionist
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3::
	setspeaker RuinsOfAlph_PuzzleAndRewardChambers_Speaker_Receptionist
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess::
	setflag FLAG_COMPLETED_KABUTO_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 5, 0x282, FALSE
	setmetatile 21, 5, 0x283, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	clearflag FLAG_ITEM_DOME_FOSSIL
	setvar VAR_RUINSOFALPH_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_OMANYTE
	goto_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteSuccess::
	setflag FLAG_COMPLETED_OMANYTE_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 22, 0x282, FALSE
	setmetatile 5, 22, 0x283, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	clearflag FLAG_ITEM_HELIX_FOSSIL
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_AERODACTYL
	goto_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess::
	setflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 22, 0x282, FALSE
	setmetatile 21, 22, 0x283, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	clearflag FLAG_ITEM_OLD_AMBER
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HooHPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_HO_OH
	goto_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess::
	setflag FLAG_COMPLETED_HOOH_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 5, 0x282, FALSE
	setmetatile 5, 5, 0x283, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	clearflag FLAG_ITEM_GS_BALL
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckHooh::
	lock
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohHint, MSGBOX_DEFAULT
	specialvar VAR_RESULT, RuinsOfAlph_HasThreeHoOhGuardianMons
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohScan
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohNeedThree, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohScan::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohScan, MSGBOX_DEFAULT
	specialvar VAR_RESULT, RuinsOfAlph_CheckHoOhGuardianMons
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohConfirmed
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohFailed, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special RuinsOfAlph_ClearHoOhGuardianMons
	fadescreen FADE_FROM_BLACK
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohConfirmed::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohConfirmed, MSGBOX_DEFAULT
	closemessage
	special RuinsOfAlph_ClearHoOhGuardianMons
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 4, 1, 0x288, FALSE
	special DrawWholeMapView
	setflag FLAG_HOOH_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckAerodactyl::
	lock
	goto_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 20, 18, 0x288, FALSE
	special DrawWholeMapView
	setflag FLAG_AERODACTYL_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckKabuto::
	lock
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoHint
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoHint::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoHint, MSGBOX_DEFAULT
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoScan::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoScan, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_SIGILYPH, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoConfirmed
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoDenied, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoConfirmed::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoConfirmed, MSGBOX_DEFAULT
	closemessage
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 20, 1, 0x288, FALSE
	special DrawWholeMapView
	setflag FLAG_KABUTO_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckOmanyte::
	lock
	goto_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardOmanyte
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardOmanyte::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 4, 18, 0x288, FALSE
	special DrawWholeMapView
	setflag FLAG_OMANYTE_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardian1::
	setvar VAR_0x8005, 0
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardianCommon

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardian2::
	setvar VAR_0x8005, 1
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardianCommon

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardian3::
	setvar VAR_0x8005, 2
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardianCommon

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPlaceGuardianCommon::
	lock
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianDoorAlreadyOpen
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohPlacePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEgg
	specialvar VAR_RESULT, RuinsOfAlph_PlaceHoOhGuardianMon
	goto_if_eq VAR_RESULT, 2, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianDuplicate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianPlaced
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianFailedToPlace, MSGBOX_DEFAULT
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianPlaced::
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianPlaced, MSGBOX_DEFAULT
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEgg::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianEgg, MSGBOX_DEFAULT
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianDuplicate::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianDuplicate, MSGBOX_DEFAULT
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianDoorAlreadyOpen::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved, MSGBOX_DEFAULT

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianEnd::
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit::
	lockall
	specialvar VAR_RESULT, RuinsOfAlph_HasAnyHoOhGuardianMons
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExitEnd
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianBlockExit, MSGBOX_DEFAULT
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_TEMP_0, 4, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_LeftSide
	goto_if_eq VAR_TEMP_0, 20, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_RightSide
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_Down
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_LeftSide::
	goto_if_eq VAR_TEMP_1, 8, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_LeftTop
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_LeftUp
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_LeftTop::
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_LeftDown
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_RightSide::
	goto_if_eq VAR_TEMP_1, 8, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_RightTop
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_RightUp
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_RightTop::
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_RightDown
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExit_Wait::
	waitmovement 0
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohGuardianBlockExitEnd::
	releaseall
	end

RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_Down:
	walk_down
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_LeftDown:
	walk_left
	walk_down
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_RightDown:
	walk_right
	walk_down
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_LeftUp:
	walk_left
	walk_up
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_Movement_BlockExit_RightUp:
	walk_right
	walk_up
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward:
	.string "The chamber reacts!\n"
	.string "The way is open.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Mon:
	.string "Some kind of ancient sensor.\n"
	.string "What is it looking for?$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoHint:
	.string "It's UNOWN text...\p"
	.string "ANCIENT GUARDIAN.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohHint:
	.string "It's UNOWN text...\p"
	.string "THE RAINBOWS GLORY.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohNeedThree:
	.string "The chamber awaits three guardians.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohScan:
	.string "Scanning the chamber...$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohConfirmed:
	.string "Guardian trio confirmed.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohFailed:
	.string "Challenge failed.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohPlacePrompt:
	.string "Do you want to place a POKéMON\n"
	.string "from the party?$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianPlaced:
	.string "{STR_VAR_1} took its place.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianEgg:
	.string "An EGG cannot answer the chamber.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianDuplicate:
	.string "That POKéMON is already guarding\n"
	.string "another tile.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianFailedToPlace:
	.string "The chamber rejected that offering.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohGuardianBlockExit:
	.string "I can't leave my POKéMON behind.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoScan:
	.string "Scanning for the ancient\n"
	.string "guardian...$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoDenied:
	.string "Guardian not found.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_KabutoConfirmed:
	.string "Guardian confirmed.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved:
	.string "The way is open.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1:
	.string "Welcome to this chamber.\p"
	.string "There are sliding panels that depict\n"
	.string "a POKéMON drawn by the ancients.\p"
	.string "Slide the panels around to form\n"
	.string "the picture.\p"
	.string "To the left is a description of\n"
	.string "the POKéMON.\p"
	.string "Scientists in the lab are examin-\n"
	.string "-ing some newly found patterns.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2:
	.string "A hole just opened up in the floor!\n"
	.string "I'd better tell the others.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3:
	.string "Now a hole in the wall too?!\n"
	.string "This is getting spooky.$"


RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto:
	.string "A POKéMON that hid on the sea floor.\n"
	.string "Eyes on its back scanned the area.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText:
	.string "It's UNOWN text!$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue:
	.string "It's a replica of an ancient\n"
	.string "POKéMON.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl:
	.string "This flying POKéMON attacked its\n"
	.string "prey with saw-like fangs.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Omanyte:
	.string "This POKéMON drifted in the sea\n"
	.string "by twisting its ten tentacles.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh:
	.string "A POKéMON that flew gracefully on\n"
	.string "rainbow-colored wings.$"

@==========================================================================================================================================================
@ Hooh
RuinsOfAlph_EventScript_Item_LumBerry1::
	finditem ITEM_LUM_BERRY
	end

RuinsOfAlph_EventScript_Item_Charcoal::
	finditem ITEM_CHARCOAL
	end

RuinsOfAlph_EventScript_Item_MaxRevive1::
	finditem ITEM_MAX_REVIVE
	end

RuinsOfAlph_EventScript_Item_SacredAsh::
	finditem ITEM_SACRED_ASH
	end

@ Aero
RuinsOfAlph_EventScript_Item_HealPowder1::
	finditem ITEM_HEAL_POWDER
	end

RuinsOfAlph_EventScript_Item_EnergyRoot::
	finditem ITEM_ENERGY_ROOT
	end

RuinsOfAlph_EventScript_Item_SitrusBerry2::
	finditem ITEM_SITRUS_BERRY
	end

RuinsOfAlph_EventScript_Item_MoonStone::
	finditem ITEM_MOON_STONE
	end

@ Kabuto
RuinsOfAlph_EventScript_Item_HealPowder2::
	finditem ITEM_HEAL_POWDER
	end

RuinsOfAlph_EventScript_Item_EnergyPowder::
	finditem ITEM_ENERGY_POWDER
	end

RuinsOfAlph_EventScript_Item_OranBerry::
	finditem ITEM_ORAN_BERRY
	end

RuinsOfAlph_EventScript_Item_PechaBerry::
	finditem ITEM_PECHA_BERRY
	end

@ Omanyte
RuinsOfAlph_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

RuinsOfAlph_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

RuinsOfAlph_EventScript_Item_LumBerry2::
	finditem ITEM_LUM_BERRY
	end

RuinsOfAlph_EventScript_Item_WaterStone::
	finditem ITEM_WATER_STONE
	end
