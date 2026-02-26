Violet_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Violet_City_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Violet_City_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Violet_City_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Violet_City_OnFrame
	.byte 0

#define VIOLET_LOCALID_MICHAEL 4
#define VIOLET_LOCALID_HOOPA_RING 5

Violet_City_OnTransition::
	setflag FLAG_HIDE_VIOLET_MICHAEL
	hideobjectat VIOLET_LOCALID_MICHAEL, MAP_VIOLET_CITY
	removeobject VIOLET_LOCALID_MICHAEL
	goto_if_unset FLAG_VIOLET_HOOPA_SCENE, Violet_City_OnTransition_Done
	hideobjectat LOCALID_PLAYER, MAP_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_HOOPA_RING
	hideobjectat VIOLET_LOCALID_HOOPA_RING, MAP_VIOLET_CITY
	removeobject VIOLET_LOCALID_HOOPA_RING
Violet_City_OnTransition_Done:
	end

Violet_City_OnLoad::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setflag FLAG_HIDE_VIOLET_MICHAEL
	hideobjectat VIOLET_LOCALID_MICHAEL, MAP_VIOLET_CITY
	removeobject VIOLET_LOCALID_MICHAEL
	goto_if_unset FLAG_VIOLET_HOOPA_SCENE, Violet_City_OnLoad_Done
	goto_if_set FLAG_VIOLET_MICHAEL_SCENE_DONE, Violet_City_OnLoad_Done
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	hideobjectat LOCALID_PLAYER, MAP_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_HOOPA_RING
	hideobjectat VIOLET_LOCALID_HOOPA_RING, MAP_VIOLET_CITY
	removeobject VIOLET_LOCALID_HOOPA_RING
Violet_City_OnLoad_Done:
	end

Violet_City_OnWarp::
	map_script_2 VAR_TEMP_2, 0, Violet_City_EventScript_HidePlayerOnWarp
	.2byte 0

Violet_City_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Violet_City_EventScript_PlayerEmerges
	.2byte 0

Violet_City_EventScript_HidePlayerOnWarp::
	goto_if_unset FLAG_VIOLET_HOOPA_SCENE, Violet_City_EventScript_HidePlayerOnWarp_Done
	hideobjectat LOCALID_PLAYER, MAP_VIOLET_CITY
Violet_City_EventScript_HidePlayerOnWarp_Done:
	end

Violet_City_EventScript_PlayerEmerges::
	lockall
	goto_if_set FLAG_VIOLET_MICHAEL_SCENE_DONE, Violet_City_EventScript_PlayerEmerges_Done
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	clearflag FLAG_VIOLET_HOOPA_SCENE
	hideobjectat LOCALID_PLAYER, MAP_VIOLET_CITY
	setobjectxy LOCALID_PLAYER, 14, 38
	setobjectxyperm LOCALID_PLAYER, 14, 38
	clearflag FLAG_HIDE_VIOLET_HOOPA_RING
	addobject VIOLET_LOCALID_HOOPA_RING
	hideobjectat VIOLET_LOCALID_HOOPA_RING, MAP_VIOLET_CITY
	setobjectxy VIOLET_LOCALID_HOOPA_RING, 14, 38
	setobjectxyperm VIOLET_LOCALID_HOOPA_RING, 14, 38
	showobjectat VIOLET_LOCALID_HOOPA_RING, MAP_VIOLET_CITY
	setvar VAR_0x8004, VIOLET_LOCALID_HOOPA_RING
	setvar VAR_0x8001, 14
	setvar VAR_0x8002, 38
	special Special_HoopaRingSpawnGrow
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	showobjectat LOCALID_PLAYER, MAP_VIOLET_CITY
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventEmerge
	applymovement LOCALID_PLAYER, Violet_City_Movement_StepFromPortal_First
	waitmovement 0
	applymovement LOCALID_PLAYER, Violet_City_Movement_StepFromPortal_Second
	waitmovement 0
	setvar VAR_0x8004, VIOLET_LOCALID_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat VIOLET_LOCALID_HOOPA_RING, MAP_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_HOOPA_RING
	removeobject VIOLET_LOCALID_HOOPA_RING
	call Violet_City_EventScript_MichaelScene
Violet_City_EventScript_PlayerEmerges_Done:
	releaseall
	end

Violet_City_EventScript_MichaelScene::
	clearflag FLAG_HIDE_VIOLET_MICHAEL
	addobject VIOLET_LOCALID_MICHAEL
	setobjectxy VIOLET_LOCALID_MICHAEL, 14, 40
	setobjectxyperm VIOLET_LOCALID_MICHAEL, 14, 40
	showobjectat VIOLET_LOCALID_MICHAEL, MAP_VIOLET_CITY
	turnobject VIOLET_LOCALID_MICHAEL, DIR_NORTH
	playse SE_PIN
	applymovement VIOLET_LOCALID_MICHAEL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VIOLET_LOCALID_MICHAEL, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker Violet_City_Speaker_Michael
	msgbox Violet_City_Text_Michael_Intro, MSGBOX_DEFAULT
	playse SE_RG_CARD_OPEN
	waitse
	setflag FLAG_TRAINER_CARD_JOHTO_UNLOCKED
	closemessage
	applymovement VIOLET_LOCALID_MICHAEL, Violet_City_Movement_Michael_Leave
	waitmovement 0
	setflag FLAG_HIDE_VIOLET_MICHAEL
	hideobjectat VIOLET_LOCALID_MICHAEL, MAP_VIOLET_CITY
	removeobject VIOLET_LOCALID_MICHAEL
	setflag FLAG_VIOLET_MICHAEL_SCENE_DONE
	return

Violet_City_EventScript_HoopaRing::
	end

Violet_City_Movement_StepFromPortal_First:
	walk_down
	step_end

Violet_City_Movement_StepFromPortal_Second:
	walk_down
	step_end

Violet_City_Movement_Michael_Leave:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Violet_City_Speaker_Michael:
	.string "MICHAEL$"

Violet_City_Text_Michael_Intro:
	.string "{PLAYER} hey!\n"
	.string "That's so cool. Looks like PROF.\n"
	.string "BIRCH got this thing working pretty\l"
	.string "quickly.\p"
	.string "I think we can try to make more of\n"
	.string "these time amulets shared with the\l"
	.string "others so we can warp to each other\l"
	.string "quickly.\p"
	.string "Anyway, I'm sure you heard TEAM AQUA\n"
	.string "is on the move right now.\p"
	.string "We really need to get some inventory\n"
	.string "from KURT, so I need you to go see\l"
	.string "him.\p"
	.string "I have to head toward ECRUTEAK CITY\n"
	.string "to help ETHAN.\p"
	.string "While you're in VIOLET, you should\n"
	.string "try challenging FALKNER. It might\l"
	.string "help you get stronger.\p"
	.string "Also before I forget, let me upgrade\n"
	.string "your TRAINER CARD so you can see your\l"
	.string "badges from JOHTO.\p"
	.string "There, now you can toggle between\n"
	.string "KANTO cards and JOHTO cards with the\l"
	.string "D-PAD!\p"
	.string "I have to go now, see you soon!$"

VioletCity_EventScript_GymSign::
	msgbox VioletCity_EventScript_GymSign_Text, MSGBOX_SIGN
	end

VioletCity_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

Violet_City_EventScript_Sage::
	faceplayer
	msgbox Violet_City_Text_Sage, MSGBOX_NPC
	end

Violet_City_EventScript_Policeman::
	faceplayer
	msgbox Violet_City_Text_Policeman, MSGBOX_NPC
	end

Violet_City_EventScript_Woman::
	faceplayer
	msgbox Violet_City_Text_Woman, MSGBOX_NPC
	end

Violet_City_EventScript_OldMan::
	faceplayer
	msgbox Violet_City_Text_OldMan, MSGBOX_NPC
	end

Violet_City_EventScript_Boy::
	faceplayer
	msgbox Violet_City_Text_Boy, MSGBOX_NPC
	end

Violet_City_EventScript_SuperNerd::
	faceplayer
	msgbox Violet_City_Text_SuperNerd, MSGBOX_NPC
	end

Violet_City_EventScript_Michael::
	faceplayer
	msgbox Violet_City_Text_Michael, MSGBOX_NPC
	end

Violet_City_Text_Sage:
	.string "The tower's bells calm the heart.\n"
	.string "Show respect when you climb.$"

Violet_City_Text_Policeman:
	.string "Traffic's light today. Enjoy the\n"
	.string "walk, but stay aware.$"

Violet_City_Text_Woman:
	.string "VIOLET is small, but travelers keep\n"
	.string "it lively.$"

Violet_City_Text_OldMan:
	.string "I've watched this city grow.\n"
	.string "Treat your POKEMON with care.$"

Violet_City_Text_Boy:
	.string "I want a flying POKEMON to soar over\n"
	.string "SPROUT TOWER.$"

Violet_City_Text_SuperNerd:
	.string "The trainer school notes are handy.\n"
	.string "Type matchups make battles easy.$"

Violet_City_Text_Michael:
	.string "I'm headed for ECRUTEAK.\n"
	.string "See KURT when you can.$"
