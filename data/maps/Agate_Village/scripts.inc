Agate_Village_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Agate_Village_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Agate_Village_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Agate_Village_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Agate_Village_OnFrame
	.byte 0
Agate_Village_Speaker_Wes:
	.string "WES$"

Agate_Village_OnLoad::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	call Agate_Village_EventScript_InitMapState
	goto_if_unset FLAG_AGATE_VILLAGE_HOOPA_EMERGE, Agate_Village_OnLoad_Done
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	hideobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
	hideobjectat 1, MAP_AGATE_VILLAGE
	removeobject 1
	hideobjectat 2, MAP_AGATE_VILLAGE
	removeobject 2
Agate_Village_OnLoad_Done:
	end

Agate_Village_OnTransition::
	call Agate_Village_EventScript_InitMapState
	goto_if_unset FLAG_AGATE_VILLAGE_HOOPA_EMERGE, Agate_Village_OnTransition_Done
	hideobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
	hideobjectat 1, MAP_AGATE_VILLAGE
	removeobject 1
	hideobjectat 2, MAP_AGATE_VILLAGE
	removeobject 2
Agate_Village_OnTransition_Done:
	end

Agate_Village_OnWarp::
	map_script_2 VAR_TEMP_2, 0, Agate_Village_EventScript_HidePlayerOnWarp
	.2byte 0

Agate_Village_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Agate_Village_EventScript_PlayerEmerges
	.2byte 0

Agate_Village_EventScript_InitMapState::
	setflag FLAG_HIDE_AGATE_VILLAGE_HOOPA_RING
	hideobjectat 1, MAP_AGATE_VILLAGE
	removeobject 1
	setflag FLAG_HIDE_AGATE_VILLAGE_TIME_RING
	hideobjectat 2, MAP_AGATE_VILLAGE
	removeobject 2
	checkflag FLAG_AGATE_VILLAGE_WES_CALL_DONE
	goto_if_ne Agate_Village_EventScript_InitMapState_ArmWesCall
	checkflag FLAG_RUSTBORO_CITY_TIME_RING_EMERGE
	goto_if_eq Agate_Village_EventScript_InitMapState_Done
	clearflag FLAG_AGATE_VILLAGE_WES_CALL_DONE

Agate_Village_EventScript_InitMapState_ArmWesCall:
	setvar VAR_AGATE_VILLAGE_WES_CALL_STATE, 0
	return

Agate_Village_EventScript_InitMapState_Done:
	setvar VAR_AGATE_VILLAGE_WES_CALL_STATE, 1
	return

Agate_Village_EventScript_Sign::
	msgbox Agate_Village_Text_Sign, MSGBOX_SIGN
	end

Agate_Village_EventScript_HidePlayerOnWarp::
	goto_if_unset FLAG_AGATE_VILLAGE_HOOPA_EMERGE, Agate_Village_EventScript_HidePlayerOnWarp_Done
	hideobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
Agate_Village_EventScript_HidePlayerOnWarp_Done:
	end

Agate_Village_EventScript_PlayerEmerges::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setvar VAR_AGATE_VILLAGE_WES_CALL_STATE, 0
	clearflag FLAG_AGATE_VILLAGE_HOOPA_EMERGE
	hideobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
	setobjectxy LOCALID_PLAYER, 21, 24
	setobjectxyperm LOCALID_PLAYER, 21, 24
	clearflag FLAG_HIDE_AGATE_VILLAGE_HOOPA_RING
	addobject 1
	hideobjectat 1, MAP_AGATE_VILLAGE
	setobjectxy 1, 21, 24
	setobjectxyperm 1, 21, 24
	showobjectat 1, MAP_AGATE_VILLAGE
	setobjectsubpriority 1, MAP_AGATE_VILLAGE, 1
	setobjectsubpriority LOCALID_PLAYER, MAP_AGATE_VILLAGE, 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8001, 21
	setvar VAR_0x8002, 24
	special Special_HoopaRingSpawnGrow
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	showobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventEmerge
	applymovement LOCALID_PLAYER, Agate_Village_Movement_StepFromPortal_First
	waitmovement 0
	applymovement LOCALID_PLAYER, Agate_Village_Movement_StepFromPortal_Second
	waitmovement 0
	setvar VAR_0x8004, 1
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat 1, MAP_AGATE_VILLAGE
	setflag FLAG_HIDE_AGATE_VILLAGE_HOOPA_RING
	removeobject 1
	resetobjectsubpriority LOCALID_PLAYER, MAP_AGATE_VILLAGE
	releaseall
	end

Agate_Village_EventScript_WesCallTrigger::
	checkflag FLAG_AGATE_VILLAGE_WES_CALL_DONE
	goto_if_eq Agate_Village_EventScript_WesCallTrigger_End
	lockall
	setspeaker Agate_Village_Speaker_Wes
	pokenavcall Agate_Village_Text_WesCall
	waitmessage
	closemessage
	setflag FLAG_AGATE_VILLAGE_WES_CALL_DONE
	setvar VAR_AGATE_VILLAGE_WES_CALL_STATE, 1
	checkflag FLAG_QUEST_ROCKY_ROXY_STARTED
	goto_if_eq Agate_Village_EventScript_WesCallTrigger_Quest2
	setflag FLAG_QUEST_ROCKY_ROXY_STARTED
Agate_Village_EventScript_WesCallTrigger_Quest2:
	checkflag FLAG_QUEST_FIND_BRENDAN_MAY_STARTED
	goto_if_eq Agate_Village_EventScript_WesCallTrigger_QuestAlert
	setflag FLAG_QUEST_FIND_BRENDAN_MAY_STARTED
Agate_Village_EventScript_WesCallTrigger_QuestAlert:
	call QuestJournal_EventScript_NewQuestsAlert
	special StorePlayerCoordsInVars
	copyvar VAR_TEMP_3, VAR_0x8004
	copyvar VAR_TEMP_4, VAR_0x8005
	subvar VAR_TEMP_4, 1
	copyvar VAR_0x8001, VAR_TEMP_3
	copyvar VAR_0x8002, VAR_TEMP_4
	clearflag FLAG_HIDE_AGATE_VILLAGE_TIME_RING
	addobject 2
	hideobjectat 2, MAP_AGATE_VILLAGE
	setobjectxy 2, VAR_TEMP_3, VAR_TEMP_4
	setobjectxyperm 2, VAR_TEMP_3, VAR_TEMP_4
	showobjectat 2, MAP_AGATE_VILLAGE
	setobjectsubpriority 2, MAP_AGATE_VILLAGE, 1
	setobjectsubpriority LOCALID_PLAYER, MAP_AGATE_VILLAGE, 0
	setvar VAR_0x8004, 2
	special Special_HoopaRingSpawnGrow
	waitstate
	delay 20
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventAbsorb
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	hideobjectat LOCALID_PLAYER, MAP_AGATE_VILLAGE
	setvar VAR_0x8004, 2
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat 2, MAP_AGATE_VILLAGE
	setflag FLAG_HIDE_AGATE_VILLAGE_TIME_RING
	removeobject 2
	resetobjectsubpriority LOCALID_PLAYER, MAP_AGATE_VILLAGE
	setflag FLAG_RUSTBORO_CITY_TIME_RING_EMERGE
	releaseall
	warp MAP_RUSTBORO_CITY, WARP_ID_NONE, 16, 56
	waitstate
	end

Agate_Village_EventScript_WesCallTrigger_End::
	releaseall
	end

Agate_Village_Text_WesCall:
	.string "Hello? Hey Zen! What happened??\p"
	.string "... ... That's insane, sounds like\n"
	.string "a dream!\p"
	.string "It seems like the threat is much\n"
	.string "bigger than just Cipher after all...\p"
	.string "The Time Machine started going crazy\n"
	.string "when you were removed from GOLDENROD\l"
	.string "CITY.\p"
	.string "It must have been trying to sync to\n"
	.string "the TIME AMULET you have.\p"
	.string "By the way, great job taking down one\n"
	.string "of Cipher's Admins.\p"
	.string "We're hearing reports from Looker\n"
	.string "that SILPH CO. is experiencing the\l"
	.string "same issue.\p"
	.string "If Cipher's Admins are the same from\n"
	.string "my timeline, it's very likely that\l"
	.string "the shady guy in SAFFRON was EIN.\p"
	.string "Which means that DAKIM is likely in\n"
	.string "this timeline too.\p"
	.string "Michael filled me in as I personally\n"
	.string "never met them.\p"
	.string "Enough of my rambling, let's see if we\n"
	.string "can pull you back to the lab as Nebby\l"
	.string "is awake for the time being.\p"
	.string ".... ....\p"
	.string "Uh, it says you're in... ORRE?!\n"
	.string "How did that even happen??\p"
	.string "Geez I'm not sure we can even bring\n"
	.string "you all the way back here.\p"
	.string "Hoenn looks like the closest\n"
	.string "coordinates I can warp you.\p"
	.string "I'll have Birch send you over to\n"
	.string "RUSTBORO CITY which means you'll be\l"
	.string "stuck out there for some time as\l"
	.string "Nebby will likely pass out again.\p"
	.string "Brendan and May have been working out\n"
	.string "there, maybe find them and get the\l"
	.string "scoop.\p"
	.string "Also, might as well take a shot at the\n"
	.string "Gym Leader there, I hear she's pretty\l"
	.string "tough.\p"
	.string "Birch is going to warp you now,\n"
	.string "sit tight.$"

Agate_Village_Text_Sign:
	.string "Agate Village: This is only a\n"
	.string "temporary design.\p"
	.string "The full map will be available and\n"
	.string "play an important role in the story\l"
	.string "on the game's release!\p"
	.string "- Zenwoo$"

Agate_Village_Movement_StepFromPortal_First:
	walk_down
	step_end

Agate_Village_Movement_StepFromPortal_Second:
	walk_down
	step_end
