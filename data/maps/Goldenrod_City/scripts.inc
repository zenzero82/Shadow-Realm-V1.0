Goldenrod_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Goldenrod_City_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Goldenrod_City_OnFrame
	.byte 0

GoldenrodCity_Speaker_Celia:
	.string "CELIA$"

GoldenrodCity_Speaker_Gus:
	.string "GUS$"

GoldenrodCity_Speaker_CipherGrunt:
	.string "CIPHER GRUNT$"

GoldenrodCity_Speaker_Marvin:
	.string "MARVIN$"

GoldenrodCity_Speaker_Eli:
	.string "ELI$"

GoldenrodCity_Speaker_Toby:
	.string "TOBY$"

GoldenrodCity_Speaker_Harold:
	.string "HAROLD$"

GoldenrodCity_Speaker_CipherPeonM:
	.string "CIPHER PEON$"

#define LOCALID_GOLDENROD_CITY_RADIO_GUARD 9
#define LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2 14

Goldenrod_City_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setflag FLAG_VISITED_GOLDENROD_CITY
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, Goldenrod_City_OnTransition_ApplyCipherDisguise
	end

Goldenrod_City_OnTransition_ApplyCipherDisguise:
	special Special_ApplyCipherDisguise
	end

Goldenrod_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, GoldenrodCity_EventScript_CityEnterQuest
	.2byte 0

GoldenrodCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	checkflag FLAG_QUEST_GOLDENROD_NPCS_STARTED
	goto_if_eq GoldenrodCity_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_GOLDENROD_NPCS_COMPLETED
	goto_if_eq GoldenrodCity_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_GOLDENROD_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
GoldenrodCity_EventScript_CityEnterQuest_End:
	end

GoldenrodCity_EventScript_Celia::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Celia
	msgbox GoldenrodCity_Text_Celia, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Gus::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Gus
	msgbox GoldenrodCity_Text_Gus, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CipherGrunt::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_CipherGrunt
	msgbox GoldenrodCity_Text_CipherGrunt, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Marvin::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Marvin
	msgbox GoldenrodCity_Text_Marvin, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Eli::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Eli
	msgbox GoldenrodCity_Text_Eli, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Toby::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Toby
	msgbox GoldenrodCity_Text_Toby, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Harold::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_Harold
	msgbox GoldenrodCity_Text_Harold, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CipherPeonM2::
	lock
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_CipherPeonM2_Disguised
	setspeaker GoldenrodCity_Speaker_CipherPeonM
	msgbox GoldenrodCity_Text_CipherPeonM2_Line1, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, DIR_SOUTH
	msgbox GoldenrodCity_Text_CipherPeonM2_Line2, MSGBOX_DEFAULT
	turnobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_CipherPeonM2_Disguised::
	faceplayer
	setspeaker GoldenrodCity_Speaker_CipherPeonM
	msgbox GoldenrodCity_Text_CipherPeonM2_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_RadioGuardTriggerLeft::
	goto_if_unset FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	goto_if_set FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_EventScript_RadioGuardScene

GoldenrodCity_EventScript_RadioGuardTriggerFront::
	goto_if_unset FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	goto_if_set FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_EventScript_RadioGuardScene

GoldenrodCity_EventScript_RadioGuardTriggerRight::
	goto_if_unset FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	goto_if_set FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_EventScript_RadioGuardScene

GoldenrodCity_EventScript_RadioGuardTrigger_End:
	end

GoldenrodCity_EventScript_UndergroundDoorApproach::
	goto_if_set FLAG_GOLDENROD_BASEMENT_KEY_GIVEN, GoldenrodCity_EventScript_UndergroundDoorApproach_End
	lockall
	msgbox GoldenrodCity_Text_LockedDoor, MSGBOX_SIGN
	releaseall
	end

GoldenrodCity_EventScript_UndergroundDoorApproach_End:
	end

GoldenrodCity_EventScript_RadioGuardScene::
	setspeaker GoldenrodCity_Speaker_CipherPeonM
	msgbox GoldenrodCity_Text_RadioGuard_Intro, MSGBOX_DEFAULT
	switch VAR_0x8004
	case 0, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Left
	case 1, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Front
	case 2, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Right

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Left:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ToLeftTrigger
	goto GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Front:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ToFrontTrigger
	goto GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Right:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ToRightTrigger

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done:
	waitmovement 0
	faceplayer
	msgbox GoldenrodCity_Text_CipherPeonM2_RadioScene, MSGBOX_DEFAULT
	turnobject LOCALID_GOLDENROD_CITY_RADIO_GUARD, DIR_SOUTH
	msgbox GoldenrodCity_Text_RadioGuard_After1, MSGBOX_DEFAULT
	msgbox GoldenrodCity_Text_RadioGuard_After2, MSGBOX_DEFAULT
	switch VAR_0x8004
	case 0, GoldenrodCity_EventScript_RadioGuard_ExitLeft
	case 1, GoldenrodCity_EventScript_RadioGuard_ExitFront
	case 2, GoldenrodCity_EventScript_RadioGuard_ExitRight

GoldenrodCity_EventScript_RadioGuard_ExitLeft:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitLeft
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ExitLeft
	goto GoldenrodCity_EventScript_RadioGuard_ExitDone

GoldenrodCity_EventScript_RadioGuard_ExitFront:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitFront
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ExitFront
	goto GoldenrodCity_EventScript_RadioGuard_ExitDone

GoldenrodCity_EventScript_RadioGuard_ExitRight:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitRight
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, GoldenrodCity_Movement_CipherPeonM2_ExitRight

GoldenrodCity_EventScript_RadioGuard_ExitDone:
	waitmovement 0
	setflag FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE
	removeobject LOCALID_GOLDENROD_CITY_RADIO_GUARD
	removeobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2
	releaseall
	end

GoldenrodCity_EventScript_LockedDoor::
	lock
	goto_if_set FLAG_GOLDENROD_BASEMENT_KEY_GIVEN, GoldenrodCity_EventScript_LockedDoor_Open
	msgbox GoldenrodCity_Text_LockedDoor, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_LockedDoor_Open:
	opendoor 21, 38
	waitdooranim
	warp MAP_GOLDENROD_CITY_UNDERGROUND_ENTRANCE, 22, 7
	waitstate
	release
	end

GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignRadio_Text:
	.string "GOLDENROD CITY RADIO TOWER$"

GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignGameCorner_Text:
	.string "Your Playground!\p"
	.string "GOLDENROD CITY GAME CORNER$"

GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignTrain_Text:
	.string "GOLDENROD CITY STATION$"

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignUnderground_Text:
	.string "UNDERGROUND ENTRANCE$"

GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignBike_Text:
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"

GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignGym_Text:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"

GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignFlower_Text:
	.string "Blooming Beautiful FLOWER SHOP$"

GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_SignDept_Text:
	.string "Full Selection of POKéMON Goods!\p"
	.string "GOLDENROD CITY DEPT.STORE$"

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_NameRaterSign_Text:
	.string "NAME RATER\p"
	.string "Get Your POKéMON Nicknames Rated$"

GoldenrodCity_Text_Celia:
	.string "Everybody keeps their heads down\n"
	.string "when CIPHER patrols the square.$"

GoldenrodCity_Text_Gus:
	.string "The UNDERGROUND used to feel lively.\n"
	.string "Now it feels like a tunnel for crooks.$"

GoldenrodCity_Text_CipherGrunt:
	.string "This city already belongs to CIPHER.\n"
	.string "Get lost kid.$"

GoldenrodCity_Text_Marvin:
	.string "The DEPT. STORE still opens, but the\n"
	.string "best stock disappears upstairs fast.$"

GoldenrodCity_Text_Eli:
	.string "WHITNEY kept the GYM open.\n"
	.string "She says GOLDENROD still needs spirit.$"

GoldenrodCity_Text_Toby:
	.string "Mom says not to go near the RADIO\n"
	.string "TOWER after dark.$"

GoldenrodCity_Text_Harold:
	.string "The station went quiet, then CIPHER\n"
	.string "started marching around like owners.$"

GoldenrodCity_Text_CipherPeonM2_Line1:
	.string "Where is he.\n"
	.string "He went to check on them so long ago.$"

GoldenrodCity_Text_CipherPeonM2_Line2:
	.string "Get lost kid, I'm busy right now.$"

GoldenrodCity_Text_CipherPeonM2_Disguised:
	.string "Finally! You took forever.\p"
	.string "Go swap positions with KANE in\n"
	.string "front of the RADIO TOWER.$"

GoldenrodCity_Text_RadioGuard_Intro:
	.string "Jeez, I never thought you were\n"
	.string "coming back here!\p"
	.string "What took so long?$"

GoldenrodCity_Text_CipherPeonM2_RadioScene:
	.string "Who cares! Let's go get some\n"
	.string "food I'm starving.\p"
	.string "I hear CELADON has a nice cafe,\n"
	.string "we can steal some stuff from it.$"

GoldenrodCity_Text_RadioGuard_After1:
	.string "Right, on that note let's get\n"
	.string "out of here.\p"
	.string "You're on duty now, make sure\n"
	.string "those dweebs don't get in here.$"

GoldenrodCity_Text_RadioGuard_After2:
	.string "Also make sure you lock the\n"
	.string "door at the tunnel entrance.\p"
	.string "I think I forgot.\n"
	.string "See ya later!$"

GoldenrodCity_Text_LockedDoor:
	.string "The door is locked.$"

GoldenrodCity_Movement_CipherPeonM2_ToLeftTrigger:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_Movement_CipherPeonM2_ToFrontTrigger:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_Movement_CipherPeonM2_ToRightTrigger:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_Movement_RadioGuardExitLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Movement_CipherPeonM2_ExitLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Movement_RadioGuardExitFront:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Movement_CipherPeonM2_ExitFront:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Movement_RadioGuardExitRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Movement_CipherPeonM2_ExitRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_Text_StationSign:
	.string "GOLDENROD CITY STATION$"

GoldenrodCity_Text_RadioTowerSign:
	.string "GOLDENROD CITY RADIO TOWER$"

GoldenrodCity_Text_DeptStoreSign:
	.string "Full Selection of POKéMON Goods!\p"
	.string "GOLDENROD CITY DEPT.STORE$"

GoldenrodCity_Text_GymSign:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"

GoldenrodCity_Text_BikeShopSign:
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"

GoldenrodCity_Text_GameCornerSign:
	.string "Your Playground!\p"
	.string "GOLDENROD CITY GAME CORNER$"

GoldenrodCity_Text_NameRaterSign:
	.string "NAME RATER\p"
	.string "Get Your POKéMON Nicknames Rated$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "UNDERGROUND ENTRANCE$"

GoldenrodCity_Text_FlowerShopSign:
	.string "Blooming Beautiful FLOWER SHOP$"
