SlowpokeWell_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlowpokeWell_B1F_EventScript_Enter
	.byte 0

SlowpokeWell_B1F_EventScript_Enter::
	setvar VAR_TEMP_1, 0
	setflag FLAG_HIDE_SLOWPOKE_WELL_BARRY
	hideobjectat LOCALID_SLOWPOKE_WELL_BARRY, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_BARRY
	setflag FLAG_HIDE_SLOWPOKE_WELL_BARRY_POKEBALL
	hideobjectat LOCALID_SLOWPOKE_WELL_BARRY_BALL, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_BARRY_BALL
	checkflag FLAG_HIDE_SLOWPOKE_WELL_FLARES
	goto_if_eq SlowpokeWell_B1F_EventScript_Enter_HideFlares
	checkflag FLAG_SLOWPOKE_WELL_FLARE1_MOVED
	goto_if_eq SlowpokeWell_B1F_EventScript_Enter_Flare1Moved
	checkflag FLAG_ETHAN_CALL_AFTER_BRYONY
	goto_if_eq SlowpokeWell_B1F_EventScript_Enter_SetHideFlares
	end

SlowpokeWell_B1F_EventScript_Enter_Flare1Moved::
	setobjectxyperm LOCALID_SLOWPOKE_WELL_FLARE1, 27, 24
	checkflag FLAG_ETHAN_CALL_AFTER_BRYONY
	goto_if_eq SlowpokeWell_B1F_EventScript_Enter_SetHideFlares
	end

SlowpokeWell_B1F_EventScript_Enter_SetHideFlares::
	setflag FLAG_HIDE_SLOWPOKE_WELL_FLARES
	goto SlowpokeWell_B1F_EventScript_Enter_HideFlares

SlowpokeWell_B1F_EventScript_Enter_HideFlares::
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE1, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE2, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE3, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_BRYONY, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_FLARE1
	removeobject LOCALID_SLOWPOKE_WELL_FLARE2
	removeobject LOCALID_SLOWPOKE_WELL_FLARE3
	removeobject LOCALID_SLOWPOKE_WELL_BRYONY
	end

SlowpokeWell_B1F_Speaker_Flare1:
	.string "VESPER$"

SlowpokeWell_B1F_Speaker_Flare2:
	.string "ORLA$"

SlowpokeWell_B1F_Speaker_Flare3:
	.string "KADE$"

SlowpokeWell_B1F_Speaker_Bryony:
	.string "BRYONY$"

SlowpokeWell_B1F_Speaker_Ethan:
	.string "ETHAN$"

SlowpokeWell_B1F_Speaker_Barry:
	.string "Barry$"

SlowpokeWell_B1F_EventScript_Flare1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE18_GET, SlowpokeWell_B1F_EventScript_Flare1_Battle
	setspeaker SlowpokeWell_B1F_Speaker_Flare1
	msgbox SlowpokeWell_B1F_Text_Flare1_Block, MSGBOX_DEFAULT
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Flare1_Battle::
	setspeaker SlowpokeWell_B1F_Speaker_Flare1
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_1, SlowpokeWell_B1F_Text_Flare1_Intro, SlowpokeWell_B1F_Text_Flare1_Defeat, SlowpokeWell_B1F_EventScript_Flare1_After
	end

SlowpokeWell_B1F_EventScript_Flare1_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare1
	msgbox SlowpokeWell_B1F_Text_Flare1_After, MSGBOX_NPC
	closemessage
	checkflag FLAG_SLOWPOKE_WELL_FLARE1_MOVED
	goto_if_eq SlowpokeWell_B1F_EventScript_Flare1_After_Done
	applymovement 1, SlowpokeWell_B1F_Movement_Flare1_StepRight
	waitmovement 1
	setflag FLAG_SLOWPOKE_WELL_FLARE1_MOVED
SlowpokeWell_B1F_EventScript_Flare1_After_Done::
	release
	end

SlowpokeWell_B1F_EventScript_Flare2::
	setspeaker SlowpokeWell_B1F_Speaker_Flare2
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_2, SlowpokeWell_B1F_Text_Flare2_Intro, SlowpokeWell_B1F_Text_Flare2_Defeat, SlowpokeWell_B1F_EventScript_Flare2_After
	end

SlowpokeWell_B1F_EventScript_Flare2_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare2
	msgbox SlowpokeWell_B1F_Text_Flare2_After, MSGBOX_NPC
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Flare3::
	setspeaker SlowpokeWell_B1F_Speaker_Flare3
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_3, SlowpokeWell_B1F_Text_Flare3_Intro, SlowpokeWell_B1F_Text_Flare3_Defeat, SlowpokeWell_B1F_EventScript_Flare3_After
	end

SlowpokeWell_B1F_EventScript_Flare3_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare3
	msgbox SlowpokeWell_B1F_Text_Flare3_After, MSGBOX_NPC
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_GalarSlowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE_GALAR, CRY_MODE_NORMAL
	waitmoncry
	release
	end

SlowpokeWell_B1F_EventScript_Bryony::
	goto SlowpokeWell_B1F_EventScript_BryonyScene

SlowpokeWell_B1F_EventScript_BryonyScene::
	goto_if_set FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_BryonyScene_Done
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_PlayerFaceDownLock
	waitmovement 0
	special Special_LockPlayerFacingDown
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SlowpokeWell_B1F_Movement_CameraToBryony
	waitmovement 0
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	msgbox SlowpokeWell_B1F_Text_Bryony_GalarSlowpoke, MSGBOX_NPC
	closemessage
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	msgbox SlowpokeWell_B1F_Text_Bryony_Xerosic, MSGBOX_NPC
	closemessage
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE_WELL_BRYONY, SlowpokeWell_B1F_Movement_Bryony_Exclaim
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BRYONY, SlowpokeWell_B1F_Movement_Bryony_ToPlayer
	applymovement LOCALID_CAMERA, SlowpokeWell_B1F_Movement_CameraFollowBryony
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_SLOWPOKE_WELL_BRYONY, TRAINER_SLOWPOKEWELL_BRYONY, SlowpokeWell_B1F_Text_Bryony_Intro, SlowpokeWell_B1F_Text_Bryony_Defeat, SlowpokeWell_B1F_EventScript_Bryony_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

SlowpokeWell_B1F_EventScript_BryonyScene_Done::
	end

SlowpokeWell_B1F_Movement_Bryony_Exclaim:
	emote_exclamation_mark
	step_end

SlowpokeWell_B1F_Movement_Bryony_ToPlayer:
	walk_right
	walk_up
	walk_up
	walk_right
	face_up
	step_end

SlowpokeWell_B1F_Movement_CameraToBryony:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

SlowpokeWell_B1F_Movement_CameraFollowBryony:
	walk_right
	walk_up
	walk_up
	walk_right
	step_end

SlowpokeWell_B1F_Movement_PlayerFaceDownLock:
	face_down
	lock_facing_direction
	step_end

SlowpokeWell_B1F_Movement_PlayerUnlockFacing:
	unlock_facing_direction
	step_end

SlowpokeWell_B1F_Movement_Barry_RunIn_North:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	step_end

SlowpokeWell_B1F_Movement_Barry_RunIn_West:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

SlowpokeWell_B1F_Movement_Barry_RunIn_South:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	step_end

SlowpokeWell_B1F_Movement_Barry_RunOff_North:
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	step_end

SlowpokeWell_B1F_Movement_Barry_RunOff_West:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	step_end

SlowpokeWell_B1F_Movement_Barry_RunOff_South:
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

SlowpokeWell_B1F_Movement_BumpReact:
	emote_exclamation_mark
	jump_in_place_down
	step_end

SlowpokeWell_B1F_Movement_Player_BumpReact_Right:
	emote_exclamation_mark
	jump_in_place_right
	step_end

SlowpokeWell_B1F_Movement_Player_BumpReact_Left:
	emote_exclamation_mark
	jump_in_place_left
	step_end

SlowpokeWell_B1F_Movement_Barry_BumpReact_Left:
	emote_exclamation_mark
	jump_in_place_left
	step_end

SlowpokeWell_B1F_Movement_Barry_BumpReact_Right:
	emote_exclamation_mark
	jump_in_place_right
	step_end

SlowpokeWell_B1F_Movement_Player_BumpShift_North:
	walk_left
	step_end

SlowpokeWell_B1F_Movement_Player_BumpShift_West:
	walk_left
	step_end

SlowpokeWell_B1F_Movement_Player_BumpShift_South:
	walk_right
	step_end

SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Down:
	walk_fast_down
	step_end

SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Right:
	walk_fast_right
	step_end

SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Up:
	walk_fast_up
	step_end

SlowpokeWell_B1F_EventScript_BarryScene::
	lockall
	setvar VAR_TEMP_1, 0
	call SlowpokeWell_B1F_EventScript_BarryScene_Core
	releaseall
	end

SlowpokeWell_B1F_EventScript_BarryTrigger_North::
	goto_if_unset FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	goto_if_set FLAG_HIDE_SLOWPOKE_WELL_SLOWPOKE, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	lockall
	setvar VAR_TEMP_1, 0
	call SlowpokeWell_B1F_EventScript_BarryScene_Core
	releaseall
	end

SlowpokeWell_B1F_EventScript_BarryTrigger_West::
	goto_if_unset FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	goto_if_set FLAG_HIDE_SLOWPOKE_WELL_SLOWPOKE, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	lockall
	setvar VAR_TEMP_1, 1
	call SlowpokeWell_B1F_EventScript_BarryScene_Core
	releaseall
	end

SlowpokeWell_B1F_EventScript_BarryTrigger_South::
	goto_if_unset FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	goto_if_set FLAG_HIDE_SLOWPOKE_WELL_SLOWPOKE, SlowpokeWell_B1F_EventScript_BarryTrigger_End
	lockall
	setvar VAR_TEMP_1, 2
	call SlowpokeWell_B1F_EventScript_BarryScene_Core
	releaseall
	end

SlowpokeWell_B1F_EventScript_BarryTrigger_End::
	end

SlowpokeWell_B1F_EventScript_BarryScene_Core::
	goto_if_set FLAG_HIDE_SLOWPOKE_WELL_SLOWPOKE, SlowpokeWell_B1F_EventScript_BarryScene_Core_Done
	removeobject 0xF8
	removeobject 0xF9
	removeobject 0xFA
	playbgm MUS_ENCOUNTER_INTENSE, FALSE
	clearflag FLAG_HIDE_SLOWPOKE_WELL_BARRY
	addobject LOCALID_SLOWPOKE_WELL_BARRY
	setobjectxy LOCALID_SLOWPOKE_WELL_BARRY, 26, 11
	showobjectat LOCALID_SLOWPOKE_WELL_BARRY, MAP_SLOWPOKE_WELL_B1F
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_RunIn_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_RunIn_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_RunIn_South

SlowpokeWell_B1F_EventScript_BarryScene_RunIn_North::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunIn_North
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceDown
	goto SlowpokeWell_B1F_EventScript_BarryScene_Bump

SlowpokeWell_B1F_EventScript_BarryScene_RunIn_West::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunIn_West
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceRight
	goto SlowpokeWell_B1F_EventScript_BarryScene_Bump

SlowpokeWell_B1F_EventScript_BarryScene_RunIn_South::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunIn_South
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceUp
	goto SlowpokeWell_B1F_EventScript_BarryScene_Bump

SlowpokeWell_B1F_EventScript_BarryScene_Bump::
	waitmovement 0
	playse SE_PIN
	goto_if_eq VAR_TEMP_1, 2, SlowpokeWell_B1F_EventScript_BarryScene_Bump_South
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_Player_BumpReact_Right
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_BumpReact_Left
	goto SlowpokeWell_B1F_EventScript_BarryScene_Bump_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Bump_South::
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_Player_BumpReact_Left
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_BumpReact_Right
	goto SlowpokeWell_B1F_EventScript_BarryScene_Bump_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Bump_Wait::
	waitmovement 0
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_Shift_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_Shift_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_Shift_South

SlowpokeWell_B1F_EventScript_BarryScene_Shift_North::
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_Player_BumpShift_North
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceLeft
	goto SlowpokeWell_B1F_EventScript_BarryScene_AfterShift

SlowpokeWell_B1F_EventScript_BarryScene_Shift_West::
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_Player_BumpShift_West
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceLeft
	goto SlowpokeWell_B1F_EventScript_BarryScene_AfterShift

SlowpokeWell_B1F_EventScript_BarryScene_Shift_South::
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_Player_BumpShift_South
	waitmovement 0
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceRight
	goto SlowpokeWell_B1F_EventScript_BarryScene_AfterShift

SlowpokeWell_B1F_EventScript_BarryScene_AfterShift::
	waitmovement 0
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_Face_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_Face_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_Face_South

SlowpokeWell_B1F_EventScript_BarryScene_Face_North::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceLeft
	goto SlowpokeWell_B1F_EventScript_BarryScene_Face_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Face_West::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceLeft
	goto SlowpokeWell_B1F_EventScript_BarryScene_Face_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Face_South::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceRight
	goto SlowpokeWell_B1F_EventScript_BarryScene_Face_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Face_Wait::
	waitmovement 0
	setspeaker SlowpokeWell_B1F_Speaker_Barry
	msgbox SlowpokeWell_B1F_Text_Barry_Intro, MSGBOX_NPC
	closemessage
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_South

SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_North::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceDown
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw

SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_West::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceRight
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw

SlowpokeWell_B1F_EventScript_BarryScene_ToSlowpoke_South::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, Common_Movement_FaceUp
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw

SlowpokeWell_B1F_EventScript_BarryScene_Throw::
	waitmovement 0
	playse SE_BALL_THROW
	clearflag FLAG_HIDE_SLOWPOKE_WELL_BARRY_POKEBALL
	addobject LOCALID_SLOWPOKE_WELL_BARRY_BALL
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_Throw_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_Throw_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw_South

SlowpokeWell_B1F_EventScript_BarryScene_Throw_North::
	setobjectxy LOCALID_SLOWPOKE_WELL_BARRY_BALL, 20, 4
	showobjectat LOCALID_SLOWPOKE_WELL_BARRY_BALL, MAP_SLOWPOKE_WELL_B1F
	applymovement LOCALID_SLOWPOKE_WELL_BARRY_BALL, SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Down
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Throw_West::
	setobjectxy LOCALID_SLOWPOKE_WELL_BARRY_BALL, 19, 5
	showobjectat LOCALID_SLOWPOKE_WELL_BARRY_BALL, MAP_SLOWPOKE_WELL_B1F
	applymovement LOCALID_SLOWPOKE_WELL_BARRY_BALL, SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Right
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Throw_South::
	setobjectxy LOCALID_SLOWPOKE_WELL_BARRY_BALL, 20, 6
	showobjectat LOCALID_SLOWPOKE_WELL_BARRY_BALL, MAP_SLOWPOKE_WELL_B1F
	applymovement LOCALID_SLOWPOKE_WELL_BARRY_BALL, SlowpokeWell_B1F_Movement_BarryBall_ToSlowpoke_Up
	goto SlowpokeWell_B1F_EventScript_BarryScene_Throw_Wait

SlowpokeWell_B1F_EventScript_BarryScene_Throw_Wait::
	waitmovement 0
	delay 16
	playse SE_BALL_OPEN
	hideobjectat LOCALID_SLOWPOKE_WELL_GALAR_SLOWPOKE, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_GALAR_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_SLOWPOKE
	delay 16
	playse SE_BALL
	hideobjectat LOCALID_SLOWPOKE_WELL_BARRY_BALL, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_BARRY_BALL
	setflag FLAG_HIDE_SLOWPOKE_WELL_BARRY_POKEBALL
	delay 16
	setspeaker SlowpokeWell_B1F_Speaker_Barry
	msgbox SlowpokeWell_B1F_Text_Barry_Exit, MSGBOX_NPC
	closemessage
	goto_if_eq VAR_TEMP_1, 0, SlowpokeWell_B1F_EventScript_BarryScene_RunOff_North
	goto_if_eq VAR_TEMP_1, 1, SlowpokeWell_B1F_EventScript_BarryScene_RunOff_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_RunOff_South

SlowpokeWell_B1F_EventScript_BarryScene_RunOff_North::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunOff_North
	goto SlowpokeWell_B1F_EventScript_BarryScene_RunOff_Wait

SlowpokeWell_B1F_EventScript_BarryScene_RunOff_West::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunOff_West
	goto SlowpokeWell_B1F_EventScript_BarryScene_RunOff_Wait

SlowpokeWell_B1F_EventScript_BarryScene_RunOff_South::
	applymovement LOCALID_SLOWPOKE_WELL_BARRY, SlowpokeWell_B1F_Movement_Barry_RunOff_South
	goto SlowpokeWell_B1F_EventScript_BarryScene_RunOff_Wait

SlowpokeWell_B1F_EventScript_BarryScene_RunOff_Wait::
	waitmovement 0
	hideobjectat LOCALID_SLOWPOKE_WELL_BARRY, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_BARRY
	setflag FLAG_HIDE_SLOWPOKE_WELL_BARRY
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_PlayerUnlockFacing
	waitmovement 0
	fadedefaultbgm
	special Special_OverworldWildEncounters_OnReturnToField
SlowpokeWell_B1F_EventScript_BarryScene_Core_Done::
	return

SlowpokeWell_B1F_EventScript_Bryony_After::
	special Special_ClearPlayerFacingOverride
	applymovement LOCALID_PLAYER, SlowpokeWell_B1F_Movement_PlayerUnlockFacing
	waitmovement 0
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	msgbox SlowpokeWell_B1F_Text_Bryony_After, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_FLARES
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE1, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE2, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_FLARE3, MAP_SLOWPOKE_WELL_B1F
	hideobjectat LOCALID_SLOWPOKE_WELL_BRYONY, MAP_SLOWPOKE_WELL_B1F
	removeobject LOCALID_SLOWPOKE_WELL_FLARE1
	removeobject LOCALID_SLOWPOKE_WELL_FLARE2
	removeobject LOCALID_SLOWPOKE_WELL_FLARE3
	removeobject LOCALID_SLOWPOKE_WELL_BRYONY
	setflag FLAG_HIDE_VIOLET_ROSS
	hideobjectat 6, MAP_VIOLET_CITY
	fadescreen FADE_FROM_BLACK
	checkflag FLAG_QUEST_SLOWPOKE_WELL_FLARE_STARTED
	goto_if_eq SlowpokeWell_B1F_EventScript_Bryony_CheckQuestComplete
	goto SlowpokeWell_B1F_EventScript_Bryony_QuestDone
SlowpokeWell_B1F_EventScript_Bryony_CheckQuestComplete::
	checkflag FLAG_QUEST_SLOWPOKE_WELL_FLARE_COMPLETED
	goto_if_eq SlowpokeWell_B1F_EventScript_Bryony_QuestDone
	setflag FLAG_QUEST_SLOWPOKE_WELL_FLARE_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
SlowpokeWell_B1F_EventScript_Bryony_QuestDone::
	goto_if_set FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_Bryony_After_Done
	setspeaker SlowpokeWell_B1F_Speaker_Ethan
	pokenavcall SlowpokeWell_B1F_Text_Ethan_Call
	waitmessage
	checkflag FLAG_QUEST_GOLDS_MOM_STARTED
	goto_if_eq SlowpokeWell_B1F_EventScript_GoldsMom_QuestDone
	checkflag FLAG_QUEST_GOLDS_MOM_COMPLETED
	goto_if_eq SlowpokeWell_B1F_EventScript_GoldsMom_QuestDone
	setflag FLAG_QUEST_GOLDS_MOM_STARTED
	call QuestJournal_EventScript_NewQuestAlert
SlowpokeWell_B1F_EventScript_GoldsMom_QuestDone::
	setflag FLAG_ETHAN_CALL_AFTER_BRYONY
	setflag FLAG_HIDE_VIOLET_GATE_POLICEMAN
SlowpokeWell_B1F_EventScript_Bryony_After_Done::
	release
	end

SlowpokeWell_B1F_Text_Flare1_Intro:
	.string "TEAM FLARE is studying this well.\n"
	.string "Leave at once.$"

SlowpokeWell_B1F_Text_Flare1_Block:
	.string "Get lost. This well is off-limits.$"

SlowpokeWell_B1F_Text_Flare1_Defeat:
	.string "Our gauges...$"

SlowpokeWell_B1F_Text_Flare1_After:
	.string "BRYONY will make short\n"
	.string "work of you.$"

SlowpokeWell_B1F_Movement_Flare1_StepRight:
	walk_right
	face_down
	step_end

SlowpokeWell_B1F_Text_Flare2_Intro:
	.string "SLOWPOKE tails are a cover.\p"
	.string "We're after shadow traces.$"

SlowpokeWell_B1F_Text_Flare2_Defeat:
	.string "The trail slipped!$"

SlowpokeWell_B1F_Text_Flare2_After:
	.string "We still have samples.\n"
	.string "Don't get in the way.$"

SlowpokeWell_B1F_Text_Flare3_Intro:
	.string "This is TEAM FLARE territory.\n"
	.string "Turn back.$"

SlowpokeWell_B1F_Text_Flare3_Defeat:
	.string "So much for secrecy.$"

SlowpokeWell_B1F_Text_Flare3_After:
	.string "We'll move deeper.\n"
	.string "You can't stop us.$"

SlowpokeWell_B1F_Text_Bryony_Intro:
	.string "You look like one of the brats\n"
	.string "that keeps ruining our plans.\p"
	.string "Looks like I get to send you\n"
	.string "home crying.$"

SlowpokeWell_B1F_Text_Bryony_Defeat:
	.string "Impossible...$"

SlowpokeWell_B1F_Text_Bryony_After:
	.string "This is the last known Galarian\n"
	.string "Slowpoke around and you just ruined\l"
	.string "my chances of nabbing it!\p"
	.string "My boss will be furious...\p"
	.string "But TEAM FLARE will crush WES,\n"
	.string "MICHAEL, and your whole team.\p"
	.string "You can count on it!$" 

SlowpokeWell_B1F_Text_Bryony_GalarSlowpoke:
	.string "At last... a GALARIAN SLOWPOKE.\p"
	.string "A perfect specimen.$"

SlowpokeWell_B1F_Text_Bryony_Xerosic:
	.string "XEROSIC needs it to study its\n"
	.string "resistance to XD conversion.$"

SlowpokeWell_B1F_Text_Ethan_Call:
	.string "Hello? Hey this is Ethan.\p"
	.string "I got your contact from Michael.\p"
	.string "He gave me the run down of you\n"
	.string "helping us out!\p"
	.string "How is everything in Azalea?\p"
	.string "... ... I see, you faced Team\n"
	.string "Rocket and Team Flare.\p"
	.string "Jeez. These guys are spreading\n"
	.string "like wildfire.\p"
	.string "Since you are in the area, can you\n"
	.string "do me a favor and head out to\l"
	.string "New Bark Town to check on my\l"
	.string "mo... err I mean Gold's mom?\p"
	.string "This timeline nonsense is really\n"
	.string "confusing hahah.\p"
	.string "But yeah, can you just make sure\n"
	.string "she is okay, its been a while\l"
	.string "since I visited.\p"
	.string "Thanks!$"

SlowpokeWell_B1F_Text_Barry_Intro:
	.string "Ouch! Bump into me again and im\n"
	.string "fining you 1 million Pokedollars!\p"
	.string "Oh, are you {PLAYER} by chance?\n"
	.string "Nice! good to meet you, I'm Barry.\p"
	.string "Sorry but i'm in a big rush, I was\n"
	.string "supposed to come by the well and\l"
	.string "bring a few Galarian Slowpoke back\l"
	.string "to old man ROWAN.\p"
	.string "I ended up stopping at an old friends.\n"
	.string "Turns out we both no different\l"
	.string "versions of each other. Insane!!\p"
	.string "Anyway, is this the only Galarian\n"
	.string "Slowpoke here?? Makes my life easier.$"

SlowpokeWell_B1F_Text_Barry_Exit:
	.string "Easy peasy! I'm off {PLAYER},\n"
	.string "catch you later!$"
