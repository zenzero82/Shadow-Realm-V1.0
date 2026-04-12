Celadon_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Celadon_City_OnTransition
	.byte 0

Celadon_City_OnTransition::
	setflag FLAG_VISITED_CELADON_CITY
	end

#define LOCALID_LILLIE 7
#define LOCALID_GLADION 20
#define LOCALID_AETHER_GRUNT_1 21
#define LOCALID_AETHER_GRUNT_2 22

CeladonCity_Speaker_Gladion:
	.string "GLADION$"

CeladonCity_Speaker_Lillie:
	.string "LILLIE$"

CeladonCity_EventScript_GladionScene_Trigger0::
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger0_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger0_Start
	goto CeladonCity_EventScript_GladionScene_Done
CeladonCity_EventScript_GladionScene_Trigger0_Start::
	lockall
	call CeladonCity_EventScript_GladionScene_Intro
	call CeladonCity_EventScript_GladionScene_FacePlayer
	call CeladonCity_EventScript_GladionScene_Confront
	applymovement LOCALID_AETHER_GRUNT_2, CeladonCity_Movement_Grunt2_ToPlayer_Trigger0
	waitmovement 0
	goto CeladonCity_EventScript_GladionScene_StartBattle

CeladonCity_EventScript_GladionScene_Trigger1::
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger1_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger1_Start
	goto CeladonCity_EventScript_GladionScene_Done
CeladonCity_EventScript_GladionScene_Trigger1_Start::
	lockall
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
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger2_Start
	checktrainerflag TRAINER_CELADON_AETHER_GRUNT_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_EventScript_GladionScene_Trigger2_Start
	goto CeladonCity_EventScript_GladionScene_Done
CeladonCity_EventScript_GladionScene_Trigger2_Start::
	lockall
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
	setspeaker SP_NAME_PLAYER
	msgbox CeladonCity_Text_Player_Silent, MSGBOX_DEFAULT
	setspeaker CeladonCity_Speaker_Gladion
	msgbox CeladonCity_Text_Gladion_HandleThis, MSGBOX_DEFAULT
	return

CeladonCity_EventScript_GladionScene_StartBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CeladonCity_EventScript_GladionScene_NotEnoughMons
	msgbox CeladonCity_Text_AetherGrunts_Seen, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_CELADON_AETHER_GRUNT_1, CeladonCity_Text_AetherGrunt1_Beaten, TRAINER_CELADON_AETHER_GRUNT_2, CeladonCity_Text_AetherGrunt2_Beaten
	releaseall
	end

CeladonCity_EventScript_GladionScene_NotEnoughMons::
	msgbox CeladonCity_Text_AetherGrunts_NotEnoughMons, MSGBOX_DEFAULT
	releaseall
	end

CeladonCity_EventScript_GladionScene_Done::
	end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger0:
	walk_right
	walk_right
	walk_down
	face_down
	step_end

CeladonCity_Movement_Grunt1_ToPlayer_Trigger1:
	walk_right
	face_up
	step_end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger1:
	walk_right
	walk_right
	face_down
	step_end

CeladonCity_Movement_Grunt2_ToPlayer_Trigger2:
	walk_right
	face_right
	step_end

CeladonCity_Movement_Grunt1_ToPlayer_Trigger2:
	walk_right
	walk_up
	face_up
	step_end

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
	.string "against SPECIAL attacks such as\n"
	.string "fire and water.\p"
	.string "Get your items at CELADON DEPT.\n"
	.string "STORE!$"

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

CeladonCity_Text_Player_Silent:
	.string "... ...$"

CeladonCity_Text_Gladion_HandleThis:
	.string "Whatever, stay out of our business.\p"
	.string "You two handle this.$"

CeladonCity_Text_AetherGrunts_Seen:
	.string "AETHER GRUNTS: You're in the way!$"

CeladonCity_Text_AetherGrunts_NotEnoughMons:
	.string "AETHER GRUNTS: Bring two POKéMON\l"
	.string "if you want to fight!$"

CeladonCity_Text_AetherGrunt1_Beaten:
	.string "AETHER GRUNT: We lost?!$"

CeladonCity_Text_AetherGrunt2_Beaten:
	.string "AETHER GRUNT: We lost?!$"
