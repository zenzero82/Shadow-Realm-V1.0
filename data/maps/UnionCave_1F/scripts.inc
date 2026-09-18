UnionCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	.byte 0

.set LOCALID_UNION_CAVE_1F_MATT, 9

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

UnionCave_1F_Speaker_Hiker:
	.string "GUS$"

UnionCave_1F_Speaker_SuperNerd:
	.string "TREV$"

UnionCave_1F_Speaker_FirebreatherBo:
	.string "BO$"

UnionCave_1F_Speaker_FirebreatherWalt:
	.string "WALT$"

UnionCave_1F_Speaker_Unknown:
	.string "???$"

UnionCave_1F_Speaker_Matt:
	.string "MATT$"

@ =========================================================
@ TRAINERS
@ =========================================================

UnionCave_1F_EventScript_Hiker::
	setspeaker UnionCave_1F_Speaker_Hiker
	trainerbattle_single TRAINER_UNION_CAVE_HIKER, UnionCave_1F_Text_Hiker_Intro, UnionCave_1F_Text_Hiker_Defeat, UnionCave_1F_EventScript_Hiker_After
	end

UnionCave_1F_EventScript_Hiker_After::
	setspeaker UnionCave_1F_Speaker_Hiker
	msgbox UnionCave_1F_Text_Hiker_After, MSGBOX_NPC
	closemessage
	release
	end

UnionCave_1F_EventScript_SuperNerd::
	setspeaker UnionCave_1F_Speaker_SuperNerd
	trainerbattle_single TRAINER_UNION_CAVE_SUPER_NERD, UnionCave_1F_Text_SuperNerd_Intro, UnionCave_1F_Text_SuperNerd_Defeat, UnionCave_1F_EventScript_SuperNerd_After
	end

UnionCave_1F_EventScript_SuperNerd_After::
	setspeaker UnionCave_1F_Speaker_SuperNerd
	msgbox UnionCave_1F_Text_SuperNerd_After, MSGBOX_NPC
	closemessage
	release
	end

UnionCave_1F_EventScript_FirebreatherTrainerBo::
	setspeaker UnionCave_1F_Speaker_FirebreatherBo
	trainerbattle_single TRAINER_UNION_CAVE_FIREBREATHER, UnionCave_1F_Text_FirebreatherBo_Intro, UnionCave_1F_Text_FirebreatherBo_Defeat, UnionCave_1F_EventScript_FirebreatherBo_After
	end

UnionCave_1F_EventScript_FirebreatherBo_After::
	setspeaker UnionCave_1F_Speaker_FirebreatherBo
	msgbox UnionCave_1F_Text_FirebreatherBo_After, MSGBOX_NPC
	closemessage
	release
	end

UnionCave_1F_EventScript_FirebreatherTrainerWalt::
	setspeaker UnionCave_1F_Speaker_FirebreatherWalt
	trainerbattle_single TRAINER_UNION_CAVE_FIREBREATHER_WALT, UnionCave_1F_Text_FirebreatherWalt_Intro, UnionCave_1F_Text_FirebreatherWalt_Defeat, UnionCave_1F_EventScript_FirebreatherWalt_After
	end

UnionCave_1F_EventScript_FirebreatherWalt_After::
	setspeaker UnionCave_1F_Speaker_FirebreatherWalt
	msgbox UnionCave_1F_Text_FirebreatherWalt_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ NPCS
@ =========================================================

UnionCave_1F_EventScript_FirebreatherNPC::
	faceplayer
	setspeaker UnionCave_1F_Speaker_FirebreatherBo
	msgbox UnionCave_1F_Text_FirebreatherNPC, MSGBOX_NPC
	end

UnionCave_1F_EventScript_Matt::
	faceplayer
	setspeaker UnionCave_1F_Speaker_Matt
	msgbox UnionCave_1F_Text_Matt, MSGBOX_NPC
	end

@ =========================================================
@ EVENTS
@ =========================================================

UnionCave_1F_EventScript_MattCallTrigger::
	goto_if_set FLAG_HIDE_UNION_CAVE_MATT, UnionCave_1F_EventScript_MattCallTrigger_End
	lockall
	special StorePlayerCoordsInVars
	goto_if_eq VAR_0x8004, 31, UnionCave_1F_EventScript_MattCallTrigger_FromLeft
UnionCave_1F_EventScript_MattCallTrigger_FromRight::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, UnionCave_1F_Movement_CameraToMatt_Right
	waitmovement 0
	goto UnionCave_1F_EventScript_MattCallTrigger_Call

UnionCave_1F_EventScript_MattCallTrigger_FromLeft::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, UnionCave_1F_Movement_CameraToMatt_Left
	waitmovement 0
	goto UnionCave_1F_EventScript_MattCallTrigger_Call

UnionCave_1F_EventScript_MattCallTrigger_Call::
	setspeaker UnionCave_1F_Speaker_Unknown
	msgbox UnionCave_1F_Text_MattCall_Full, MSGBOX_POKENAV
	applymovement LOCALID_UNION_CAVE_1F_MATT, UnionCave_1F_Movement_MattExit
	waitmovement 0
	setflag FLAG_HIDE_UNION_CAVE_MATT
	removeobject LOCALID_UNION_CAVE_1F_MATT
	goto_if_eq VAR_0x8004, 31, UnionCave_1F_EventScript_MattCallTrigger_CameraBackLeft
	applymovement LOCALID_CAMERA, UnionCave_1F_Movement_CameraToPlayer_Right
	waitmovement 0
	goto UnionCave_1F_EventScript_MattCallTrigger_CameraDone

UnionCave_1F_EventScript_MattCallTrigger_CameraBackLeft::
	applymovement LOCALID_CAMERA, UnionCave_1F_Movement_CameraToPlayer_Left
	waitmovement 0

UnionCave_1F_EventScript_MattCallTrigger_CameraDone::
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	releaseall
	end

UnionCave_1F_EventScript_MattCallTrigger_End::
	end

@ =========================================================
@ MOVEMENT
@ =========================================================

UnionCave_1F_Movement_MattExit:
	walk_down
	walk_down
	step_end

UnionCave_1F_Movement_CameraToMatt_Right:
	walk_down
	walk_down
	walk_down
	step_end

UnionCave_1F_Movement_CameraToMatt_Left:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

UnionCave_1F_Movement_CameraToPlayer_Right:
	walk_up
	walk_up
	walk_up
	step_end

UnionCave_1F_Movement_CameraToPlayer_Left:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

@ =========================================================
@ TEXT
@ =========================================================

UnionCave_1F_Text_Hiker_Intro:
	.string "These tunnels are my training\n"
	.string "ground!\p"
	.string "Let's battle!$"

UnionCave_1F_Text_Hiker_Defeat:
	.string "Solid hit...$"

UnionCave_1F_Text_Hiker_After:
	.string "Caves build tough teams.$"

UnionCave_1F_Text_SuperNerd_Intro:
	.string "Caves are perfect for experiments.\p"
	.string "Show me your team!$"

UnionCave_1F_Text_SuperNerd_Defeat:
	.string "My data...$"

UnionCave_1F_Text_SuperNerd_After:
	.string "I'll keep studying these tunnels.$"

UnionCave_1F_Text_FirebreatherBo_Intro:
	.string "My flames light the way.\p"
	.string "Let's go!$"

UnionCave_1F_Text_FirebreatherBo_Defeat:
	.string "Burned out...$"

UnionCave_1F_Text_FirebreatherBo_After:
	.string "The heat keeps ZUBAT away.\n"
	.string "Mostly.$"

UnionCave_1F_Text_FirebreatherWalt_Intro:
	.string "A cave needs more than one fire.\p"
	.string "Let's see your spark!$"

UnionCave_1F_Text_FirebreatherWalt_Defeat:
	.string "Snuffed out...$"

UnionCave_1F_Text_FirebreatherWalt_After:
	.string "Even with fire, these tunnels stay\n"
	.string "cold and damp.$"

UnionCave_1F_Text_FirebreatherNPC:
	.string "I rest between flame tricks.\n"
	.string "This cave never sleeps.$"

UnionCave_1F_Text_Matt:
	.string "Stay out of this.$"

UnionCave_1F_Text_MattCall_Intro:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "We were able to lure MICHAEL out\n"
	.string "of VIOLET. The MARAUDER should be\l"
	.string "finishing up getting the\l"
	.string "blueprints from that old man.\p"
	.string "Make your way over to OLIVINE CITY.\n"
	.string "We got somethings to take care of.$"

UnionCave_1F_Text_MattCall_Response:
	.string "Aye aye, Cap.$"

UnionCave_1F_Text_MattCall_End:
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

UnionCave_1F_Text_MattCall_Full:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "We were able to lure MICHAEL out\n"
	.string "of VIOLET.\p"
	.string "The MARAUDER should be\n"
	.string "finishing up getting the\l"
	.string "blueprints from that old man.\p"
	.string "Make your way over to OLIVINE.\n"
	.string "We got somethings to take care of.\p"
	.string "MATT: Aye aye, Cap.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
