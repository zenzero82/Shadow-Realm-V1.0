Vermilion_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Vermilion_City_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Vermilion_City_OnFrame
	.byte 0

.set LOCALID_SNORLAX, 18
.set LOCALID_BATTLE_GIRL, 20
.set LOCALID_BOY, 21
.set LOCALID_OLD_MAN, 22
.set LOCALID_SURGE, 27
.set LOCALID_AQUA_GRUNT, 28
.set LOCALID_RAICHU, 29
.set LOCALID_CARVANHA, 30
.set LOCALID_GYM_GUY, 31

Vermilion_City_OnTransition::
	goto_if_set FLAG_QUEST_LT_SURGE_STARTED, Vermilion_City_OnTransition_SurgeSceneDone
	setvar VAR_TEMP_0, 0
	goto Vermilion_City_OnTransition_Continue

Vermilion_City_OnTransition_SurgeSceneDone:
	setvar VAR_TEMP_0, 1

Vermilion_City_OnTransition_Continue:
	setvar VAR_TEMP_1, 0
	setflag FLAG_VISITED_VERMILLION_CITY
	end

Vermilion_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, VermilionCity_EventScript_CityEnterQuest
	.2byte 0

VermilionCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	checkflag FLAG_QUEST_VERMILION_NPCS_STARTED
	goto_if_eq VermilionCity_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_VERMILION_NPCS_COMPLETED
	goto_if_eq VermilionCity_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_VERMILION_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
VermilionCity_EventScript_CityEnterQuest_End:
	end

VermilionCity_Speaker_BattleGirl:
	.string "RINA$"

VermilionCity_Speaker_Boy:
	.string "JAMIE$"

VermilionCity_Speaker_OldMan:
	.string "WALTER$"

VermilionCity_Speaker_Surge:
	.string "LT.SURGE$"

VermilionCity_Speaker_AquaGrunt:
	.string "Aqua Grunt$"

VermilionCity_Speaker_GymGuy:
	.string "GUIDE$"

VermilionCity_EventScript_BattleGirl::
	lock
	faceplayer
	setspeaker VermilionCity_Speaker_BattleGirl
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, VermilionCity_EventScript_BattleGirl_AfterPort
	msgbox VermilionCity_Text_BattleGirl_BeforePort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_BattleGirl_AfterPort::
	msgbox VermilionCity_Text_BattleGirl_AfterPort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_Boy::
	lock
	faceplayer
	setspeaker VermilionCity_Speaker_Boy
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, VermilionCity_EventScript_Boy_AfterPort
	msgbox VermilionCity_Text_Boy_BeforePort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_Boy_AfterPort::
	msgbox VermilionCity_Text_Boy_AfterPort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_OldMan::
	lock
	faceplayer
	setspeaker VermilionCity_Speaker_OldMan
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, VermilionCity_EventScript_OldMan_AfterPort
	msgbox VermilionCity_Text_OldMan_BeforePort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_OldMan_AfterPort::
	msgbox VermilionCity_Text_OldMan_AfterPort, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_GymGuy::
	lock
	faceplayer
	setspeaker VermilionCity_Speaker_GymGuy
	msgbox VermilionCity_Text_GymGuy, MSGBOX_NPC
	closemessage
	release
	end

VermilionCity_EventScript_SurgeScene_Left::
	lockall
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraToSurgeScene_Left
	waitmovement 0
	goto VermilionCity_EventScript_SurgeScene_Common

VermilionCity_EventScript_SurgeScene_Middle::
	lockall
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, 1
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraToSurgeScene_Middle
	waitmovement 0
	goto VermilionCity_EventScript_SurgeScene_Common

VermilionCity_EventScript_SurgeScene_Right::
	lockall
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, 2
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraToSurgeScene_Right
	waitmovement 0

VermilionCity_EventScript_SurgeScene_Common::
	setspeaker VermilionCity_Speaker_Surge
	msgbox VermilionCity_Text_SurgeScene_BodySlam, MSGBOX_DEFAULT
	applymovement LOCALID_RAICHU, VermilionCity_Movement_RaichuBodySlam
	waitmovement 0
	playse SE_BALL_THROW
	applymovement LOCALID_AQUA_GRUNT, VermilionCity_Movement_AquaGruntRecall
	waitmovement 0
	playse SE_BALL_OPEN
	setflag FLAG_HIDE_VERMILION_CITY_CARVANHA
	removeobject LOCALID_CARVANHA
	setspeaker VermilionCity_Speaker_Surge
	msgbox VermilionCity_Text_SurgeScene_GetOut, MSGBOX_DEFAULT
	setspeaker VermilionCity_Speaker_AquaGrunt
	msgbox VermilionCity_Text_SurgeScene_AquaRetreat, MSGBOX_DEFAULT
	compare VAR_0x8004, 2
	goto_if_eq VermilionCity_EventScript_SurgeScene_AquaRetreat_Right
	applymovement LOCALID_AQUA_GRUNT, VermilionCity_Movement_AquaGruntEscape
	waitmovement 0
	goto VermilionCity_EventScript_SurgeScene_AquaRetreat_Done
VermilionCity_EventScript_SurgeScene_AquaRetreat_Right::
	applymovement LOCALID_AQUA_GRUNT, VermilionCity_Movement_AquaGruntEscape_Right
	waitmovement 0
VermilionCity_EventScript_SurgeScene_AquaRetreat_Done:
	setflag FLAG_HIDE_VERMILION_CITY_AQUA_GRUNT
	removeobject LOCALID_AQUA_GRUNT
	compare VAR_0x8004, 0
	call_if_eq VermilionCity_EventScript_SurgeScene_ReturnCamera_Left
	compare VAR_0x8004, 1
	call_if_eq VermilionCity_EventScript_SurgeScene_ReturnCamera_Middle
	compare VAR_0x8004, 2
	call_if_eq VermilionCity_EventScript_SurgeScene_ReturnCamera_Right
	special RemoveCameraObject
	playse SE_PIN
	applymovement LOCALID_SURGE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SURGE, VermilionCity_Movement_SurgeApproach
	applymovement LOCALID_RAICHU, VermilionCity_Movement_RaichuApproach
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_SURGE, Common_Movement_FaceUp
	applymovement LOCALID_RAICHU, Common_Movement_FaceUp
	waitmovement 0
	setspeaker VermilionCity_Speaker_Surge
	msgbox VermilionCity_Text_SurgeScene_PlayerWarning, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8004, 0
	call_if_eq VermilionCity_EventScript_SurgeScene_Exit_Left
	compare VAR_0x8004, 1
	call_if_eq VermilionCity_EventScript_SurgeScene_Exit_Middle
	compare VAR_0x8004, 2
	call_if_eq VermilionCity_EventScript_SurgeScene_Exit_Right
	setflag FLAG_HIDE_VERMILION_CITY_SURGE
	setflag FLAG_HIDE_VERMILION_CITY_RAICHU
	removeobject LOCALID_SURGE
	removeobject LOCALID_RAICHU
	checkflag FLAG_QUEST_LT_SURGE_STARTED
	goto_if_eq VermilionCity_EventScript_SurgeScene_QuestDone
	setflag FLAG_QUEST_LT_SURGE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
VermilionCity_EventScript_SurgeScene_QuestDone:
	releaseall
	end

VermilionCity_EventScript_SurgeScene_ReturnCamera_Left::
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraBackToPlayer_Left
	waitmovement 0
	return

VermilionCity_EventScript_SurgeScene_ReturnCamera_Middle::
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraBackToPlayer_Middle
	waitmovement 0
	return

VermilionCity_EventScript_SurgeScene_ReturnCamera_Right::
	applymovement LOCALID_CAMERA, VermilionCity_Movement_CameraBackToPlayer_Right
	waitmovement 0
	return

VermilionCity_EventScript_SurgeScene_Exit_Left::
	applymovement LOCALID_SURGE, VermilionCity_Movement_SurgeExit_Left
	applymovement LOCALID_RAICHU, VermilionCity_Movement_RaichuExit_Left
	waitmovement 0
	return

VermilionCity_EventScript_SurgeScene_Exit_Middle::
	applymovement LOCALID_SURGE, VermilionCity_Movement_SurgeExit_Middle
	applymovement LOCALID_RAICHU, VermilionCity_Movement_RaichuExit_Middle
	waitmovement 0
	return

VermilionCity_EventScript_SurgeScene_Exit_Right::
	applymovement LOCALID_SURGE, VermilionCity_Movement_SurgeExit_Right
	applymovement LOCALID_RAICHU, VermilionCity_Movement_RaichuExit_Right
	waitmovement 0
	return

VermilionCity_EventScript_Snorlax::
	lock
	setfieldeffectargument 1, MAP_NUM(MAP_VERMILION_CITY)
	setfieldeffectargument 2, MAP_GROUP(MAP_VERMILION_CITY)
	setfieldeffectargument 7, 5
	setfieldeffectargument 0, LOCALID_SNORLAX
	dofieldeffect FLDEFF_EMOTE
	waitfieldeffect FLDEFF_EMOTE
	msgbox VermilionCity_Text_SnorlaxSleeping, MSGBOX_NPC
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

VermilionCity_Movement_CameraToSurgeScene_Left:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

VermilionCity_Movement_CameraToSurgeScene_Middle:
	walk_fast_down
	walk_fast_down
	step_end

VermilionCity_Movement_CameraToSurgeScene_Right:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

VermilionCity_Movement_CameraBackToPlayer_Left:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

VermilionCity_Movement_CameraBackToPlayer_Middle:
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Movement_CameraBackToPlayer_Right:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	step_end

VermilionCity_Movement_RaichuBodySlam:
	walk_fast_right
	jump_in_place_right
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_fast_left
	face_right
	step_end

VermilionCity_Movement_AquaGruntRecall:
	walk_in_place_faster_left
	delay_8
	face_left
	step_end

VermilionCity_Movement_AquaGruntEscape:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Movement_AquaGruntEscape_Right:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Movement_SurgeApproach:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

VermilionCity_Movement_RaichuApproach:
	walk_fast_right
	step_end

VermilionCity_Movement_SurgeExit_Left:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_RaichuExit_Left:
	delay_8
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_SurgeExit_Middle:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_RaichuExit_Middle:
	delay_8
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_SurgeExit_Right:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_RaichuExit_Right:
	walk_right
	delay_8
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


VermilionCity_Text_Sign:
	.string "VERMILION CITY\p"
	.string "The Port of Exquisite Sunsets$"


VermilionCity_Text_GymSign:
	.string "VERMILION CITY\n"
	.string "POKéMON GYM\p"
	.string "LEADER: LT.SURGE\p"
	.string "The Lightning American$"


VermilionCity_Text_GymGuy:
	.string "LT. SURGE is very upset right now.\p"
	.string "It's best to come back later.$"


VermilionCity_Text_FanClubSign:
	.string "POKéMON FAN CLUB\p"
	.string "All POKéMON Fans Welcome!$"


VermilionCity_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"

VermilionCity_Text_BattleGirl_BeforePort:
	.string "Everyone near the port has been\n"
	.string "talking about a strange professor\l"
	.string "and a nervous girl.$"

VermilionCity_Text_BattleGirl_AfterPort:
	.string "The port finally feels calmer.\p"
	.string "Now the only real problem is that\n"
	.string "sleeping SNORLAX blocking the road.$"

VermilionCity_Text_OldMan_BeforePort:
	.string "My POKéMON is preparing the land\n"
	.string "for construction.\p"
	.string "But between harbor rumors and that\n"
	.string "blocked road, nobody wants to invest.$"

VermilionCity_Text_OldMan_AfterPort:
	.string "At least the harbor panic settled\n"
	.string "down.\p"
	.string "If that SNORLAX moved too, maybe my\n"
	.string "project would finally start.$"

VermilionCity_Text_Boy_BeforePort:
	.string "There are eight GYMS in KANTO.\p"
	.string "But right now everyone in VERMILION\n"
	.string "only wants to talk about the port.$"

VermilionCity_Text_Boy_AfterPort:
	.string "That big building is VERMILION's\n"
	.string "POKéMON GYM.\p"
	.string "Maybe people will care about badges\n"
	.string "again once the harbor excitement\l"
	.string "wears off.$"

VermilionCity_Text_SnorlaxSleeping:
	.string "Looks like this POKeMON\n"
	.string "is dead asleep.\p"
	.string "Maybe there's something that\n"
	.string "can wake it up.$"

VermilionCity_Text_SurgeScene_BodySlam:
	.string "Now RAICHU, use BODY SLAM!$"

VermilionCity_Text_SurgeScene_GetOut:
	.string "Now get out of my city scum!$"

VermilionCity_Text_SurgeScene_AquaRetreat:
	.string "You haven't seen the last of us.\p"
	.string "This is merely just the\n"
	.string "beginning!$"

VermilionCity_Text_SurgeScene_PlayerWarning:
	.string "WHAT?! You want some too??\p"
	.string "... ...\p"
	.string "Oh you're not with them huh?\p"
	.string "I'm on 1,000 right now as these\n"
	.string "theives appeared out of nowhere\l"
	.string "trying to steal POKéMON from\l"
	.string "trainers.\p"
	.string "I ran them all out one by one.\p"
	.string "I need some time to cool off,\n"
	.string "maybe ditch the lady and come\l"
	.string "challenge me if you dare.\p"
	.string "I'm too hot headed right now and\n"
	.string "I might not hold back.$"
