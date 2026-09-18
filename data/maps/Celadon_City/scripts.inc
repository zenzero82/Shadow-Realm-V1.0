Celadon_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Celadon_City_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Celadon_City_OnFrame
	.byte 0

Celadon_City_OnTransition::
	setvar VAR_TEMP_1, 0
	setflag FLAG_VISITED_CELADON_CITY
	call CeladonCity_EventScript_CheckNPCQuestState
	call_if_set FLAG_CELADON_GLADION_EXITED, CeladonCity_EventScript_GladionScene_RemoveObjects
	call_if_set FLAG_CELADON_GLADION_SCENE_DONE, CeladonCity_EventScript_GladionScene_RemoveObjects
	call_if_set FLAG_CELADON_LILLIE_JOINED, CeladonCity_EventScript_GladionScene_RemoveObjects
	end

Celadon_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, CeladonCity_EventScript_CityEnterQuest
	.2byte 0

CeladonCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	checkflag FLAG_QUEST_CELADON_NPCS_STARTED
	goto_if_eq CeladonCity_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_CELADON_NPCS_COMPLETED
	goto_if_eq CeladonCity_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_CELADON_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
CeladonCity_EventScript_CityEnterQuest_End:
	end

#define LOCALID_LILLIE 7
#define LOCALID_COSMOG 8
#define LOCALID_GLADION 20
#define LOCALID_AETHER_GRUNT_1 21
#define LOCALID_AETHER_GRUNT_2 22

CeladonCity_Speaker_Gladion:
	.string "GLADION$"

CeladonCity_Speaker_Lillie:
	.string "LILLIE$"

CeladonCity_Speaker_Poliwrath:
	.string "POLIWRATH$"

CeladonCity_Speaker_FatMan:
	.string "GORDON$"

CeladonCity_Speaker_OldMan:
	.string "HAROLD$"

CeladonCity_Speaker_Boy:
	.string "SEAN$"

CeladonCity_Speaker_Lass:
	.string "MIA$"

CeladonCity_Speaker_BattleGirl:
	.string "KARA$"

CeladonCity_Speaker_BaldingMan:
	.string "EUGENE$"

CeladonCity_Speaker_Twin:
	.string "LOLA$"

CeladonCity_Speaker_LittleBoy:
	.string "TIMMY$"

CeladonCity_EventScript_GladionScene_Trigger0::
	goto_if_set FLAG_CELADON_GLADION_SCENE_DONE, CeladonCity_EventScript_GladionScene_Done
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger0_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger0_Start
	goto CeladonCity_EventScript_GladionScene_GladionOnly
CeladonCity_EventScript_GladionScene_Trigger0_Start::
	lockall
	setvar VAR_TEMP_1, 0
	call CeladonCity_EventScript_GladionScene_Intro
	call CeladonCity_EventScript_GladionScene_FacePlayer
	call CeladonCity_EventScript_GladionScene_Confront
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_ToPlayer_Trigger0
	waitmovement 0
	goto CeladonCity_EventScript_GladionScene_StartBattle

CeladonCity_EventScript_GladionScene_Trigger1::
	goto_if_set FLAG_CELADON_GLADION_SCENE_DONE, CeladonCity_EventScript_GladionScene_Done
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger1_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger1_Start
	goto CeladonCity_EventScript_GladionScene_GladionOnly
CeladonCity_EventScript_GladionScene_Trigger1_Start::
	lockall
	setvar VAR_TEMP_1, 1
	call CeladonCity_EventScript_GladionScene_Intro
	playse SE_PIN
	applymovement LOCALID_GLADION, Common_Movement_ExclamationMark
	waitmovement LOCALID_GLADION
	call CeladonCity_EventScript_GladionScene_FacePlayer
	call CeladonCity_EventScript_GladionScene_Confront
	applymovement LOCALID_AETHER_GRUNT_1, CeladonCity_Movement_Grunt1_ToPlayer_Trigger1
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_ToPlayer_Trigger1
	waitmovement 0
	goto CeladonCity_EventScript_GladionScene_StartBattle

CeladonCity_EventScript_GladionScene_Trigger2::
	goto_if_set FLAG_CELADON_GLADION_SCENE_DONE, CeladonCity_EventScript_GladionScene_Done
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger2_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger2_Start
	goto CeladonCity_EventScript_GladionScene_GladionOnly
CeladonCity_EventScript_GladionScene_Trigger2_Start::
	lockall
	setvar VAR_TEMP_1, 2
	call CeladonCity_EventScript_GladionScene_Intro
	call CeladonCity_EventScript_GladionScene_FacePlayer
	call CeladonCity_EventScript_GladionScene_Confront
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_ToPlayer_Trigger2
	applymovement LOCALID_AETHER_GRUNT_1, CeladonCity_Movement_Grunt1_ToPlayer_Trigger2
	waitmovement 0
	goto CeladonCity_EventScript_GladionScene_StartBattle

CeladonCity_EventScript_GladionScene_Intro::
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_LillieGiveItUp, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_NoNebby, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_BrotherLine, MSGBOX_DEFAULT
	return

CeladonCity_EventScript_GladionScene_FacePlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_GLADION, Common_Movement_FacePlayer
	applymovement LOCALID_AETHER_GRUNT_1, Common_Movement_FacePlayer
	applymovement LOCALID_AETHER_GRUNT_2, Common_Movement_FacePlayer
	waitmovement 0
	return

CeladonCity_EventScript_GladionScene_Confront::
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_WhoAreYou, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_HandleThis, MSGBOX_DEFAULT
	return

CeladonCity_EventScript_GladionScene_StartBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CeladonCity_EventScript_GladionScene_NotEnoughMons
	msgbox CeladonCity_Text_AetherGrunts_Seen, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_CELADON_AETHER_GRUNT_1, CeladonCity_Text_AetherGrunt1_Beaten, TRAINER_CELADON_AETHER_GRUNT_2, CeladonCity_Text_AetherGrunt2_Beaten
	call CeladonCity_EventScript_GladionScene_ReturnGrunts
	goto CeladonCity_EventScript_GladionScene_GladionBattle

CeladonCity_EventScript_GladionScene_NotEnoughMons::
	msgbox CeladonCity_Text_AetherGrunts_NotEnoughMons, MSGBOX_DEFAULT
	releaseall
	end

CeladonCity_EventScript_GladionScene_GladionOnly::
	lockall
	call CeladonCity_EventScript_GladionScene_FacePlayer
	goto CeladonCity_EventScript_GladionScene_GladionBattle

CeladonCity_EventScript_GladionScene_GladionBattle::
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_Pain, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_CELADON_GLADION, CeladonCity_Text_Gladion_Defeat
	goto CeladonCity_EventScript_GladionScene_After

CeladonCity_EventScript_GladionScene_After::
	lockall
	setflag FLAG_CELADON_GLADION_SCENE_DONE
	applymovement LOCALID_GLADION, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_SisLine, MSGBOX_DEFAULT
	closemessage
	call CeladonCity_EventScript_GladionScene_Exit
	call CeladonCity_EventScript_Lillie_AfterGladion
	releaseall
	end

CeladonCity_EventScript_GladionScene_ReturnGrunts::
	switch VAR_TEMP_1
	case 0, CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger0
	case 1, CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger1
	case 2, CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger2
	return

CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger0::
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_Return_Trigger0
	waitmovement 0
	return

CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger1::
	applymovement LOCALID_AETHER_GRUNT_1, CeladonCity_Movement_Grunt1_Return_Trigger1
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_Return_Trigger1
	waitmovement 0
	return

CeladonCity_EventScript_GladionScene_ReturnGrunts_Trigger2::
	applymovement LOCALID_AETHER_GRUNT_1, CeladonCity_Movement_Grunt1_Return_Trigger2
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_Return_Trigger2
	waitmovement 0
	return

CeladonCity_EventScript_GladionScene_Exit::
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_ClearPath
	waitmovement 0
	applymovement LOCALID_GLADION, CeladonCity_Movement_Gladion_Exit
	applymovement LOCALID_AETHER_GRUNT_1, CeladonCity_Movement_Grunt1_Exit
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_Exit
	waitmovement 0
	call CeladonCity_EventScript_GladionScene_RemoveObjects
	return

CeladonCity_EventScript_GladionScene_RemoveObjects::
	setflag FLAG_CELADON_GLADION_SCENE_DONE
	setflag FLAG_CELADON_GLADION_EXITED
	hideobjectat LOCALID_GLADION, MAP_CELADON_CITY
	hideobjectat LOCALID_AETHER_GRUNT_1, MAP_CELADON_CITY
	hideobjectat LOCALID_AETHER_GRUNT_2, MAP_CELADON_CITY
	removeobject LOCALID_GLADION
	removeobject LOCALID_AETHER_GRUNT_1
	removeobject LOCALID_AETHER_GRUNT_2
	return

CeladonCity_EventScript_Lillie::
	faceplayer
	goto_if_set FLAG_CELADON_LILLIE_JOINED, CeladonCity_EventScript_Lillie_Done
	goto_if_set FLAG_CELADON_GLADION_SCENE_DONE, CeladonCity_EventScript_Lillie_AskAgain
	end

CeladonCity_EventScript_Lillie_AskAgain::
	call CeladonCity_EventScript_Lillie_AskToJoin
	end

CeladonCity_EventScript_Lillie_Done::
	end

CeladonCity_EventScript_Lillie_AfterGladion::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_LILLIE, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_Thanks, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_Timeline, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_GladionChase, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_VermilionHelp, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_SSAnneAlola, MSGBOX_DEFAULT
	call CeladonCity_EventScript_Lillie_AskToJoin
	return

CeladonCity_EventScript_Lillie_AskToJoin::
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_Ask, MSGBOX_DEFAULT
	goto CeladonCity_EventScript_Lillie_JoinYes

CeladonCity_EventScript_Lillie_JoinYes::
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_JoinYes, MSGBOX_DEFAULT
	msgbox CeladonCity_Text_Lillie_JoinedPlayer, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Lillie
	msgbox CeladonCity_Text_Lillie_NebbyBag, MSGBOX_DEFAULT
	applymovement LOCALID_COSMOG, CeladonCity_Movement_Cosmog_JumpIntoLillie
	waitmovement 0
	removeobject LOCALID_COSMOG
	setflag FLAG_CELADON_LILLIE_JOINED
	setfollowernpc LOCALID_LILLIE, FNPC_BIKE, EventScript_Follower_Lillie
	checkflag FLAG_QUEST_ALOLA_LILLIE_STARTED
	goto_if_eq CeladonCity_EventScript_Lillie_JoinYes_QuestDone
	setflag FLAG_QUEST_ALOLA_LILLIE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
CeladonCity_EventScript_Lillie_JoinYes_QuestDone:
	return

CeladonCity_EventScript_GladionScene_Done::
	end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger0:
	walk_right
	walk_right
	walk_down
	face_down
	step_end

CeladonCity_Movement_Grunt2_Return_Trigger0:
	walk_up
	walk_left
	walk_left
	face_down
	step_end

CeladonCity_Movement_Grunt1_ToPlayer_Trigger1:
	walk_right
	face_up
	step_end

CeladonCity_Movement_Grunt1_Return_Trigger1:
	walk_left
	face_left
	step_end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger1:
	walk_right
	walk_right
	face_down
	step_end

CeladonCity_Movement_Grunt2_Return_Trigger1:
	walk_left
	walk_left
	face_down
	step_end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger2:
	walk_right
	face_right
	step_end

CeladonCity_Movement_Grunt2_Return_Trigger2:
	walk_left
	face_down
	step_end

CeladonCity_Movement_Grunt1_ToPlayer_Trigger2:
	walk_right
	walk_up
	face_up
	step_end

CeladonCity_Movement_Grunt1_Return_Trigger2:
	walk_down
	walk_left
	face_left
	step_end

CeladonCity_Movement_Grunt2_Exit:
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_Gladion_Exit:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_Grunt1_Exit:
	delay_16
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_Grunt2_ClearPath:
	walk_right
	walk_right
	step_end

CeladonCity_Movement_Cosmog_JumpIntoLillie:
	jump_up
	step_end

@ =========================================================
@ NPCS
@ =========================================================

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	setspeaker CeladonCity_Speaker_Poliwrath
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_NPC
	waitmoncry
	release
	end

CeladonCity_EventScript_CheckNPCQuestState::
	goto_if_unset FLAG_QUEST_CELADON_NPCS_STARTED, CeladonCity_EventScript_CheckNPCQuestState_End
	clearflag FLAG_QUEST_CELADON_NPCS_COMPLETED
	goto_if_unset FLAG_QUEST_CELADON_NPC_FATMAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_OLD_MAN1, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_OLD_MAN2, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_BOY, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_LITTLE_BOY, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_LASS, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_BATTLE_GIRL, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_BALDING_MAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_TWIN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_POKECENTER_GENTLEMAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_POKECENTER_BATTLE_GIRL, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_HOUSE2_GENTLEMAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_APARTMENT_OLD_WOMAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_APARTMENTROOF_FATMAN, CeladonCity_EventScript_CheckNPCQuestState_End
	goto_if_unset FLAG_QUEST_CELADON_NPC_ROOFHOUSE_BLACKBELT, CeladonCity_EventScript_CheckNPCQuestState_End
	setflag FLAG_QUEST_CELADON_NPCS_COMPLETED
CeladonCity_EventScript_CheckNPCQuestState_End:
	return

CeladonCity_EventScript_FatMan::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_FATMAN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_FatMan
	msgbox CeladonCity_Text_FatMan, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_OLD_MAN1
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_OldMan
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_EventScript_OldMan1_After
	goto_if_set FLAG_RECEIVED_COIN_CASE, CeladonCity_EventScript_OldMan1_After
	msgbox CeladonCity_Text_OldMan1_Intro, MSGBOX_DEFAULT
	msgbox CeladonCity_Text_OldMan1_AskCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_EventScript_OldMan1_GiveCoinCase
	goto CeladonCity_EventScript_OldMan1_Decline
	end

CeladonCity_EventScript_OldMan1_GiveCoinCase::
	msgbox CeladonCity_Text_OldMan1_GiveCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_COIN_CASE
	msgbox CeladonCity_Text_OldMan1_GaveCoinCase, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1_Decline::
	msgbox CeladonCity_Text_OldMan1_Decline, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1_After::
	msgbox CeladonCity_Text_OldMan1_After, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_OLD_MAN2
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_OldMan
	msgbox CeladonCity_Text_OldMan2, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_BOY
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_Boy
	msgbox CeladonCity_Text_Boy, MSGBOX_NPC
	end

CeladonCity_EventScript_LittleBoy::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_LITTLE_BOY
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_LittleBoy
	msgbox CeladonCity_Text_LittleBoy, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_LASS
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_Lass
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_BattleGirl::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_BATTLE_GIRL
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_BattleGirl
	msgbox CeladonCity_Text_BattleGirl, MSGBOX_NPC
	end

CeladonCity_EventScript_BaldingMan::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_BALDING_MAN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_BaldingMan
	msgbox CeladonCity_Text_BaldingMan, MSGBOX_NPC
	end

CeladonCity_EventScript_Twin::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_TWIN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker CeladonCity_Speaker_Twin
	msgbox CeladonCity_Text_Twin, MSGBOX_NPC
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end


CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end


CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end


CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end


CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost


CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end


CeladonCity_Text_Sign:
	.string "CELADON CITY\p"
	.string "The City of Rainbow Dreams$"


CeladonGym_Text_Sign:
	.string "CELADON CITY POKéMON GYM LEADER:\n"
	.string "ERIKA\p"
	.string "The Nature-Loving Princess$"


CeladonCity_Text_DeptStoreSign:
	.string "Find What You Need at CELADON\n"
	.string "DEPT.STORE!$"


CeladonCity_Text_MansionSign:
	.string "CELADON MANSION$"


CeladonCity_Text_GameCornerSign:
	.string "The Playground for Everybody--\n"
	.string "CELADON GAME CORNER$"


CeladonCity_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "GUARD SPEC. protects POKéMON\n"
	.string "against SPECIAL attacks such as\l"
	.string "fire and water.\p"
	.string "Get your items at CELADON DEPT.\n"
	.string "STORE!$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: Croak!$"

CeladonCity_Text_FatMan:
	.string "This POLIWRATH is my partner.\p"
	.string "I wonder if it'll ever evolve\n"
	.string "into a frog POKéMON.$"

CeladonCity_Text_OldMan1_Intro:
	.string "Since GRIMER started appearing in\n"
	.string "the water, I won't even go to the\l"
	.string "GAME CORNER anymore. I don't even\l"
	.string "want to leave my house.$"

CeladonCity_Text_OldMan1_AskCoinCase:
	.string "Do you want a COIN CASE?$"

CeladonCity_Text_OldMan1_GiveCoinCase:
	.string "If you're going, take mine.$"

CeladonCity_Text_OldMan1_GaveCoinCase:
	.string "That COIN CASE can be used at the\n"
	.string "GAME CORNER.$"

CeladonCity_Text_OldMan1_Decline:
	.string "Come back if you change your mind.$"

CeladonCity_Text_OldMan1_After:
	.string "I still won't go outside while\n"
	.string "GRIMER are in the water.$"

CeladonCity_Text_OldMan2:
	.string "Nihihi! This GYM is great! Only\n"
	.string "girls are allowed here!$"

CeladonCity_Text_Boy:
	.string "Want to know a secret?\p"
	.string "CELADON MANSION has a hidden back\n"
	.string "door.$"

CeladonCity_Text_LittleBoy:
	.string "They're holding an eating contest\n"
	.string "at the restaurant.\p"
	.string "Just watching them go at it makes\n"
	.string "me feel bloated...$"

CeladonCity_Text_Lass:
	.string "Looking at the ground while I was\n"
	.string "walking made me dizzy.$"

CeladonCity_Text_BattleGirl:
	.string "ERIKA's GYM only accepts girls.\n"
	.string "Good thing I'm training hard.$"

CeladonCity_Text_BaldingMan:
	.string "CELADON DEPT.STORE has the biggest\n"
	.string "and best selection of merchandise.\p"
	.string "If you can't get it there, you\n"
	.string "can't get it anywhere.$"

CeladonCity_Text_Twin:
	.string "My sister and I are saving up for\n"
	.string "GAME CORNER coins.$"

CeladonCity_Text_Gladion_LillieGiveItUp:
	.string "Lillie just give it up, it doesn't\n"
	.string "matter the place, the timeline,\l"
	.string "whatever, we can't stop her!$"

CeladonCity_Text_Lillie_NoNebby:
	.string "No! I won't do it, she can't have\n"
	.string "Nebby. She only wants to use it\l"
	.string "for the wrong reasons and I will\l"
	.string "not let her do it!$"

CeladonCity_Text_Gladion_BrotherLine:
	.string "You're making this so much harder\n"
	.string "than it needs to be. Just because\l"
	.string "I'm your brother does not mean I'm\l"
	.string "going to go easy on you.$"

CeladonCity_Text_Gladion_WhoAreYou:
	.string "Who the heck are you??$"

CeladonCity_Text_Gladion_HandleThis:
	.string "Whatever, stay out of our business.\p"
	.string "You two handle this.$"

CeladonCity_Text_Gladion_Pain:
	.string "This is such a pain.\p"
	.string "You're wasting my time!$"

CeladonCity_Text_Gladion_Defeat:
	.string "There's no way I can be defeated!\p"
	.string "You will regret this, I promise you.$"

CeladonCity_Text_Gladion_SisLine:
	.string "It's not over sis, I'm taking that\n"
	.string "stupid POKéMON and getting her to\l"
	.string "leave us alone for good. Mark my\l"
	.string "words.$"

CeladonCity_Text_Lillie_Thanks:
	.string "Thank you for helping me.\p"
	.string "I've been on the run since I got\n"
	.string "here.$"

CeladonCity_Text_Lillie_Timeline:
	.string "I'm from a timeline where I had a\n"
	.string "friend named Elio. He helped me\l"
	.string "keep Nebby safe.$"

CeladonCity_Text_Lillie_GladionChase:
	.string "Gladion was much less of a jerk\n"
	.string "there, but this Gladion keeps\l"
	.string "chasing me down.$"

CeladonCity_Text_Lillie_Ask:
	.string "Can I accompany you for a while,\n"
	.string "until I can find some help?$"

CeladonCity_Text_Lillie_JoinNo:
	.string "Oh okay, if you change your mind\n"
	.string "please let me know. I could use\l"
	.string "some help.$"

CeladonCity_Text_Lillie_JoinYes:
	.string "Really?? Thank you so much!\n"
	.string "I'll be sure to help any way\l"
	.string "I can.$"

CeladonCity_Text_Lillie_JoinedPlayer:
	.string "Lillie has joined {PLAYER}.$"

CeladonCity_Text_Lillie_NebbyBag:
	.string "Okay Nebby, in the bag you go.$"

CeladonCity_Text_Lillie_VermilionHelp:
	.string "Actually... could you also help me\n"
	.string "get to VERMILION CITY safely?$"

CeladonCity_Text_Lillie_SSAnneAlola:
	.string "I want to see if the S.S. ANNE is\n"
	.string "available so I might be able to\l"
	.string "take it back to the ALOLA region.$"

CeladonCity_Text_AetherGrunts_Seen:
	.string "AETHER GRUNTS: You're in the way!$"

CeladonCity_Text_AetherGrunts_NotEnoughMons:
	.string "AETHER GRUNTS: Bring two POKéMON\l"
	.string "if you want to fight!$"

CeladonCity_Text_AetherGrunt1_Beaten:
	.string "AETHER GRUNT: We lost?!$"

CeladonCity_Text_AetherGrunt2_Beaten:
	.string "AETHER GRUNT: We lost?!$"
