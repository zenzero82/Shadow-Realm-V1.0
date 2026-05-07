vermilion_portinside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, vermilion_portinside_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, vermilion_portinside_OnWarp
	.byte 0

.set LOCALID_PORTINSIDE_SS_TIDAL, 1
.set LOCALID_PORTINSIDE_SAILOR, 2
.set LOCALID_PORTINSIDE_BURNET, 3
.set LOCALID_PORTINSIDE_WOMAN, 4
.set LOCALID_PORTINSIDE_SUPER_NERD, 5
.set LOCALID_PORTINSIDE_LILLIE, 6
.set LOCALID_PORTINSIDE_COSMOG, 7

vermilion_portinside_OnTransition::
	setvar VAR_TEMP_1, 0
	end

vermilion_portinside_OnWarp:
	map_script_2 VAR_TEMP_1, 0, vermilion_portinside_OnWarp_SetLillieVisibility
	.2byte 0

vermilion_portinside_OnWarp_SetLillieVisibility::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_portinside_OnWarp_ShowLillie
	hideobjectat LOCALID_PORTINSIDE_LILLIE, MAP_VERMILION_PORTINSIDE
	end

vermilion_portinside_OnWarp_ShowLillie::
	showobjectat LOCALID_PORTINSIDE_LILLIE, MAP_VERMILION_PORTINSIDE
	turnobject LOCALID_PORTINSIDE_BURNET, DIR_WEST
	end

VermilionPortInside_Speaker_Burnet:
	.string "PROF. BURNET$"

VermilionPortInside_Speaker_Sailor:
	.string "SAILOR$"

VermilionPortInside_Speaker_Lillie:
	.string "LILLIE$"

VermilionPortInside_Speaker_Woman:
	.string "TESS$"

VermilionPortInside_Speaker_SuperNerd:
	.string "GAVIN$"

VermilionPortInside_Speaker_Ship:
	.string "S.S. TIDAL$"

VermilionPortInside_EventScript_Burnet::
	lock
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, VermilionPortInside_EventScript_Burnet_After
	goto_if_unset FLAG_CELADON_LILLIE_JOINED, VermilionPortInside_EventScript_Burnet_NoLillie
	hideobjectat LOCALID_PORTINSIDE_LILLIE, MAP_VERMILION_PORTINSIDE
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_SailToJohto, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Sailor
	msgbox VermilionPortInside_Text_Sailor_JohtoReady, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_Thanks, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_PORTINSIDE_BURNET, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PORTINSIDE_BURNET, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_GreetPlayer, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_NoticeLillie, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, VermilionPortInside_Movement_Player_StepLeftFaceRight
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, VermilionPortInside_Movement_Lillie_ToBurnet
	waitmovement 0
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_DontKnow, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_AlternateTimeline, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_PORTINSIDE_BURNET, VermilionPortInside_Movement_DoubleExclamation
	waitmovement 0
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_AskCosmog, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_Nebby, MSGBOX_DEFAULT
	getobjectcurrentxy OBJ_EVENT_ID_NPC_FOLLOWER, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	setobjectxy LOCALID_PORTINSIDE_COSMOG, VAR_0x8004, VAR_0x8005
	showobjectat LOCALID_PORTINSIDE_COSMOG, MAP_VERMILION_PORTINSIDE
	applymovement LOCALID_PORTINSIDE_COSMOG, VermilionPortInside_Movement_Cosmog_JumpRight
	waitmovement 0
	playmoncry SPECIES_COSMOG, CRY_MODE_NORMAL
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_LendNebby, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_Resist, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_LookToPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_PORTINSIDE_LILLIE, VermilionPortInside_Movement_Lillie_LookToPlayerThenBurnet
	waitmovement 0
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_PlayerTakesCare, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_TakeToBirch, MSGBOX_DEFAULT
	msgbox VermilionPortInside_Text_NebbyJoined, MSGBOX_DEFAULT
	applymovement LOCALID_PORTINSIDE_COSMOG, VermilionPortInside_Movement_Cosmog_ToPlayerSide
	waitmovement 0
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_InviteJohto, MSGBOX_DEFAULT
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_JoinJohto, MSGBOX_DEFAULT
	applymovement LOCALID_PORTINSIDE_BURNET, Common_Movement_FaceUp
	waitmovement 0
	getobjectcurrentxy OBJ_EVENT_ID_NPC_FOLLOWER, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	destroyfollowernpc
	setobjectxy LOCALID_PORTINSIDE_LILLIE, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_PORTINSIDE_LILLIE, VAR_0x8004, VAR_0x8005
	showobjectat LOCALID_PORTINSIDE_LILLIE, MAP_VERMILION_PORTINSIDE
	applymovement LOCALID_PORTINSIDE_LILLIE, Common_Movement_FaceDown
	waitmovement 0
	setfollowernpc LOCALID_PORTINSIDE_COSMOG, FNPC_BIKE, EventScript_Follower_Nebby
	setflag FLAG_NEBBY_FOLLOWER_ACTIVE
	setflag FLAG_HIDE_ROUTE2_DIGLETTS_CAVE_HIKER
	checkflag FLAG_QUEST_ALOLA_LILLIE_COMPLETED
	goto_if_eq VermilionPortInside_EventScript_LillieScene_QuestDone
	setflag FLAG_QUEST_ALOLA_LILLIE_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
VermilionPortInside_EventScript_LillieScene_QuestDone:
	setflag FLAG_QUEST_NEBBY_POWERHOUSE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	setflag FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE
	release
	end

VermilionPortInside_EventScript_Burnet_NoLillie::
	faceplayer
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_NoLillie, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Burnet_After::
	faceplayer
	setspeaker VermilionPortInside_Speaker_Burnet
	msgbox VermilionPortInside_Text_Burnet_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Sailor::
	lock
	faceplayer
	setspeaker VermilionPortInside_Speaker_Sailor
	msgbox VermilionPortInside_Text_Sailor_Default, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Woman::
	lock
	faceplayer
	setspeaker VermilionPortInside_Speaker_Woman
	msgbox VermilionPortInside_Text_Woman, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_SuperNerd::
	lock
	faceplayer
	setspeaker VermilionPortInside_Speaker_SuperNerd
	msgbox VermilionPortInside_Text_SuperNerd, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Lillie::
	lock
	faceplayer
	setspeaker VermilionPortInside_Speaker_Lillie
	msgbox VermilionPortInside_Text_Lillie_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Ship::
	lock
	faceplayer
	setspeaker VermilionPortInside_Speaker_Ship
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, VermilionPortInside_EventScript_Ship_After
	msgbox VermilionPortInside_Text_Ship_Before, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_EventScript_Ship_After::
	msgbox VermilionPortInside_Text_Ship_After, MSGBOX_NPC
	closemessage
	release
	end

VermilionPortInside_Movement_DoubleExclamation:
	emote_double_exclamation_mark
	step_end

VermilionPortInside_Movement_Player_StepLeftFaceRight:
	walk_left
	face_right
	step_end

VermilionPortInside_Movement_Lillie_ToBurnet:
	walk_down
	face_down
	step_end

VermilionPortInside_Movement_Cosmog_JumpRight:
	jump_right
	face_down
	step_end

VermilionPortInside_Movement_Cosmog_ToPlayerSide:
	walk_left
	walk_up
	walk_up
	face_down
	step_end

VermilionPortInside_Movement_Lillie_LookToPlayerThenBurnet:
	face_left
	delay_16
	face_down
	step_end

VermilionPortInside_Text_Burnet_SailToJohto:
	.string "Excuse me, sailor.\p"
	.string "Are you still setting sail for\n"
	.string "JOHTO today?$"

VermilionPortInside_Text_Sailor_JohtoReady:
	.string "Aye, Professor.\p"
	.string "We'll be ready to depart once the\n"
	.string "passengers are aboard.$"

VermilionPortInside_Text_Burnet_Thanks:
	.string "Wonderful. Thank you.$"

VermilionPortInside_Text_Burnet_GreetPlayer:
	.string "Oh! Hello there.\p"
	.string "I'm Professor Burnet, the wife of\n"
	.string "Professor Kukui.$"

VermilionPortInside_Text_Burnet_NoticeLillie:
	.string "Wait... Lillie? I'm so glad to\n"
	.string "see you!$"

VermilionPortInside_Text_Lillie_DontKnow:
	.string "I'm sorry, but I don't think\n"
	.string "I've met you before.$"

VermilionPortInside_Text_Burnet_AlternateTimeline:
	.string "Ah, you must be from another\n"
	.string "timeline... That explains so much.$"

VermilionPortInside_Text_Burnet_AskCosmog:
	.string "Wait!! Lillie, do you still have a\n"
	.string "Cosmog by chance??$"

VermilionPortInside_Text_Lillie_Nebby:
	.string "You mean my Nebby?$"

VermilionPortInside_Text_Burnet_LendNebby:
	.string "This is exciting news!\n"
	.string "Lillie, can you lend Cosmog--er,\n"
	.string "Nebby--so we can try to fix the\n"
	.string "Time Machine?$"

VermilionPortInside_Text_Lillie_Resist:
	.string "I... I don't know. I'm still not\n"
	.string "sure if I can trust you.$"

VermilionPortInside_Text_Lillie_LookToPlayer:
	.string "Lillie looks to {PLAYER} for\n"
	.string "reassurance.$"

VermilionPortInside_Text_Lillie_PlayerTakesCare:
	.string "Okay, but {PLAYER} has to be the\n"
	.string "one that takes care of Nebby.\p"
	.string "I'm not giving it to anyone else.$"

VermilionPortInside_Text_Burnet_TakeToBirch:
	.string "I understand.\n"
	.string "Please take Nebby to the hideout\l"
	.string "and let Professor Birch see if it\n"
	.string "can be of any help.$"

VermilionPortInside_Text_NebbyJoined:
	.string "Nebby will follow you!$"

VermilionPortInside_Text_Burnet_InviteJohto:
	.string "Lillie, come with me to JOHTO.\p"
	.string "I'll help you understand the\n"
	.string "version of you I know.$"

VermilionPortInside_Text_Lillie_JoinJohto:
	.string "Okay, Professor. I'll come with\n"
	.string "you.$"

VermilionPortInside_Text_Burnet_NoLillie:
	.string "I'm waiting to meet someone very\n"
	.string "important. She should arrive soon.$"

VermilionPortInside_Text_Burnet_After:
	.string "Cosmog might be the piece we need\n"
	.string "to get the TIME MACHINE working\l"
	.string "again!$"

VermilionPortInside_Text_Sailor_Default:
	.string "The ship's ready for JOHTO.\n"
	.string "We're just waiting on a few\l"
	.string "passengers.$"

VermilionPortInside_Text_Woman:
	.string "I love watching the ships come and\n"
	.string "go from here.$"

VermilionPortInside_Text_SuperNerd:
	.string "The S.S Anne does not come around\n"
	.string "often. I can't miss it!$"

VermilionPortInside_Text_Lillie_After:
	.string "I'm nervous, but I trust your\n"
	.string "judgment, {PLAYER}.$"

VermilionPortInside_Text_Ship_Before:
	.string "A sleek vessel is moored here.\p"
	.string "The dockhands seem to be waiting for\n"
	.string "something before boarding begins.$"

VermilionPortInside_Text_Ship_After:
	.string "The ship is ready for travelers once\n"
	.string "more.\p"
	.string "The terminal feels far less tense now.$"
