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
	clearflag FLAG_HIDE_VIOLET_MICHAEL
	addobject VIOLET_LOCALID_MICHAEL
	setobjectxy VIOLET_LOCALID_MICHAEL, 14, 40
	setobjectxyperm VIOLET_LOCALID_MICHAEL, 14, 40
	showobjectat VIOLET_LOCALID_MICHAEL, MAP_VIOLET_CITY
	turnobject VIOLET_LOCALID_MICHAEL, DIR_NORTH
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
	checkflag FLAG_QUEST_VIOLET_NPCS_STARTED
	goto_if_eq Violet_City_EventScript_MichaelScene_QuestNPCs_Done
	setflag FLAG_QUEST_VIOLET_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	call Violet_City_EventScript_CheckVioletQuest
Violet_City_EventScript_MichaelScene_QuestNPCs_Done:
	checkflag FLAG_QUEST_DEFEAT_FALKNER_STARTED
	goto_if_eq Violet_City_EventScript_MichaelScene_QuestFalkner_Done
	setflag FLAG_QUEST_DEFEAT_FALKNER_STARTED
	call QuestJournal_EventScript_NewQuestAlert
Violet_City_EventScript_MichaelScene_QuestFalkner_Done:
	checkflag FLAG_QUEST_KURT_APRICOT_STARTED
	goto_if_eq Violet_City_EventScript_MichaelScene_QuestKurt_Done
	checkflag FLAG_QUEST_KURT_APRICOT_COMPLETED
	goto_if_eq Violet_City_EventScript_MichaelScene_QuestKurt_Done
	setflag FLAG_QUEST_KURT_APRICOT_STARTED
	call QuestJournal_EventScript_NewQuestAlert
Violet_City_EventScript_MichaelScene_QuestKurt_Done:
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

Violet_City_Speaker_Sage:
	.string "SAGE KAZU$"

Violet_City_Speaker_Policeman:
	.string "OFFICER ROSS$"

Violet_City_Speaker_PolicemanGate:
	.string "OFFICER$"

Violet_City_Speaker_Woman:
	.string "MARA$"

Violet_City_Speaker_OldMan:
	.string "GILES$"

Violet_City_Speaker_Boy:
	.string "TOM$"

Violet_City_Speaker_SuperNerd:
	.string "LEO$"

Violet_City_Text_Michael_Intro:
	.string "{PLAYER} hey!\n"
	.string "That's so cool. Looks like PROF.\l"
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
    .string "VIOLET CITY POKéMON GYM\n"
    .string "LEADER: FALKNER\p"
    .string "The Flying Type POKéMON Trainer$"

Violet_City_EventScript_Sage::
	faceplayer
	setspeaker Violet_City_Speaker_Sage
	msgbox Violet_City_Text_Sage, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_SAGE
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_Policeman::
	faceplayer
	setspeaker Violet_City_Speaker_Policeman
	msgbox Violet_City_Text_Policeman, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_POLICEMAN
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_PolicemanGate::
	faceplayer
	setspeaker Violet_City_Speaker_PolicemanGate
	msgbox Violet_City_Text_PolicemanGate, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_POLICEMAN_GATE
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_Woman::
	faceplayer
	setspeaker Violet_City_Speaker_Woman
	msgbox Violet_City_Text_Woman, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_WOMAN
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_OldMan::
	faceplayer
	setspeaker Violet_City_Speaker_OldMan
	msgbox Violet_City_Text_OldMan, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_OLD_MAN
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_Boy::
	faceplayer
	setspeaker Violet_City_Speaker_Boy
	msgbox Violet_City_Text_Boy, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_BOY
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_SuperNerd::
	faceplayer
	setspeaker Violet_City_Speaker_SuperNerd
	msgbox Violet_City_Text_SuperNerd, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_VIOLET_NPC_SUPER_NERD
	call Violet_City_EventScript_CheckVioletQuest
	end

Violet_City_EventScript_CheckVioletQuest::
	checkflag FLAG_QUEST_VIOLET_NPCS_STARTED
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckCompleted
	return
Violet_City_EventScript_CheckVioletQuest_CheckCompleted:
	checkflag FLAG_QUEST_VIOLET_NPCS_COMPLETED
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_Done
	checkflag FLAG_QUEST_VIOLET_NPC_SAGE
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckPoliceman
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckPoliceman:
	checkflag FLAG_QUEST_VIOLET_NPC_POLICEMAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckPolicemanGate
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckPolicemanGate:
	checkflag FLAG_QUEST_VIOLET_NPC_POLICEMAN_GATE
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckWoman
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckWoman:
	checkflag FLAG_QUEST_VIOLET_NPC_WOMAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckOldMan
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckOldMan:
	checkflag FLAG_QUEST_VIOLET_NPC_OLD_MAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckBoy
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckBoy:
	checkflag FLAG_QUEST_VIOLET_NPC_BOY
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSuperNerd
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSuperNerd:
	checkflag FLAG_QUEST_VIOLET_NPC_SUPER_NERD
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckHouse1Hiker
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckHouse1Hiker:
	checkflag FLAG_QUEST_VIOLET_NPC_HOUSE1_HIKER
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckHouse2Woman
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckHouse2Woman:
	checkflag FLAG_QUEST_VIOLET_NPC_HOUSE2_WOMAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckHouse2LittleBoy
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckHouse2LittleBoy:
	checkflag FLAG_QUEST_VIOLET_NPC_HOUSE2_LITTLE_BOY
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckMartOldWoman
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckMartOldWoman:
	checkflag FLAG_QUEST_VIOLET_NPC_MART_OLD_WOMAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckMartRocker
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckMartRocker:
	checkflag FLAG_QUEST_VIOLET_NPC_MART_ROCKER
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckPokecenterGameboyKid
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckPokecenterGameboyKid:
	checkflag FLAG_QUEST_VIOLET_NPC_POKECENTER_GAMEBOY_KID
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckPokecenterGentleman
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckPokecenterGentleman:
	checkflag FLAG_QUEST_VIOLET_NPC_POKECENTER_GENTLEMAN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckPokecenterBeauty
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckPokecenterBeauty:
	checkflag FLAG_QUEST_VIOLET_NPC_POKECENTER_BEAUTY
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolScientist
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolScientist:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_SCIENTIST
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolSuperNerd
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolSuperNerd:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_SUPER_NERD
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleBoy
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleBoy:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_BOY
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolTwin
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolTwin:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_TWIN
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleBoy2
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleBoy2:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_BOY2
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleGirl2
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolLittleGirl2:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LITTLE_GIRL2
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolLass
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolLass:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_LASS
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_CheckSchoolYoungster
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_CheckSchoolYoungster:
	checkflag FLAG_QUEST_VIOLET_NPC_SCHOOL_YOUNGSTER
	goto_if_eq Violet_City_EventScript_CheckVioletQuest_AllDone
	goto Violet_City_EventScript_CheckVioletQuest_Done
Violet_City_EventScript_CheckVioletQuest_AllDone:
	setflag FLAG_QUEST_VIOLET_NPCS_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Violet_City_EventScript_CheckVioletQuest_Done:
	return

Violet_City_EventScript_Michael::
	faceplayer
	setspeaker Violet_City_Speaker_Michael
	msgbox Violet_City_Text_Michael, MSGBOX_NPC
	end

Violet_City_Text_Sage:
	.string "The tower's bells calm the heart.\n"
	.string "Show respect when you climb.$"

Violet_City_Text_Policeman:
	.string "Traffic's light today. Enjoy the\n"
	.string "walk, but stay aware.$"

Violet_City_Text_PolicemanGate:
	.string "Nobody can pass until the game is\n"
	.string "finished.$"

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
