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

UnionCave_1F_Speaker_Firebreather:
	.string "BO$"

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

UnionCave_1F_EventScript_FirebreatherTrainer::
	setspeaker UnionCave_1F_Speaker_Firebreather
	trainerbattle_single TRAINER_UNION_CAVE_FIREBREATHER, UnionCave_1F_Text_Firebreather_Intro, UnionCave_1F_Text_Firebreather_Defeat, UnionCave_1F_EventScript_Firebreather_After
	end

UnionCave_1F_EventScript_Firebreather_After::
	setspeaker UnionCave_1F_Speaker_Firebreather
	msgbox UnionCave_1F_Text_Firebreather_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ NPCS
@ =========================================================

UnionCave_1F_EventScript_FirebreatherNPC::
	faceplayer
	msgbox UnionCave_1F_Text_FirebreatherNPC, MSGBOX_NPC
	end

UnionCave_1F_EventScript_Matt::
	faceplayer
	msgbox UnionCave_1F_Text_Matt, MSGBOX_NPC
	end

@ =========================================================
@ EVENTS
@ =========================================================

UnionCave_1F_EventScript_MattCallTrigger::
	goto_if_set FLAG_HIDE_UNION_CAVE_MATT, UnionCave_1F_EventScript_MattCallTrigger_End
	lockall
	pokenavcall MatchCall_Text_MattUnionCave
	waitmessage
	closemessage
	applymovement LOCALID_UNION_CAVE_1F_MATT, UnionCave_1F_Movement_MattExit
	waitmovement 0
	setflag FLAG_HIDE_UNION_CAVE_MATT
	removeobject LOCALID_UNION_CAVE_1F_MATT
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

@ =========================================================
@ TEXT
@ =========================================================

UnionCave_1F_Text_Hiker_Intro:
	.string "These tunnels are my training\l"
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

UnionCave_1F_Text_Firebreather_Intro:
	.string "My flames light the way.\p"
	.string "Let's go!$"

UnionCave_1F_Text_Firebreather_Defeat:
	.string "Burned out...$"

UnionCave_1F_Text_Firebreather_After:
	.string "The heat keeps ZUBAT away.\n"
	.string "Mostly.$"

UnionCave_1F_Text_FirebreatherNPC:
	.string "I rest between flame tricks.\n"
	.string "This cave never sleeps.$"

UnionCave_1F_Text_Matt:
	.string "MATT: Stay out of this.$"
