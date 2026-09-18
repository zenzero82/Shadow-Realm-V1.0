Goldenrod_City_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Goldenrod_City_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Goldenrod_City_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Goldenrod_City_OnFrame
	.byte 0

GoldenrodCity_Speaker_Celia:
	.string "CELIA$"

GoldenrodCity_Speaker_Gus:
	.string "GUS$"

GoldenrodCity_Speaker_PeonKane:
	.string "PEON KANE$"

GoldenrodCity_Speaker_Marvin:
	.string "MARVIN$"

GoldenrodCity_Speaker_Eli:
	.string "ELI$"

GoldenrodCity_Speaker_Toby:
	.string "TOBY$"

GoldenrodCity_Speaker_Harold:
	.string "HAROLD$"

GoldenrodCity_Speaker_PeonLud:
	.string "PEON LUD$"

#define LOCALID_GOLDENROD_CITY_RADIO_GUARD 9
#define LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2 14
#define LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3 15

Goldenrod_City_OnLoad::
	call GoldenrodCity_EventScript_SyncUndergroundDoorTile
	setflag FLAG_HIDE_GOLDENROD_CITY_CIPHER_PEON_M_3
	removeobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3
	end

Goldenrod_City_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setflag FLAG_VISITED_GOLDENROD_CITY
	call GoldenrodCity_EventScript_SyncUndergroundDoorTile
	setflag FLAG_HIDE_GOLDENROD_CITY_CIPHER_PEON_M_3
	removeobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, Goldenrod_City_OnTransition_ApplyCipherDisguise
	end

Goldenrod_City_OnTransition_ApplyCipherDisguise:
	special Special_ApplyCipherDisguise
	end

Goldenrod_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, GoldenrodCity_EventScript_CityEnterQuest
	.2byte 0

GoldenrodCity_EventScript_SyncUndergroundDoorTile::
	checkflag FLAG_GOLDENROD_TUNNEL_DOOR_UNLOCKED
	goto_if_eq TRUE, GoldenrodCity_EventScript_SyncUndergroundDoorTile_Unlocked
	goto GoldenrodCity_EventScript_SyncUndergroundDoorTile_Locked

GoldenrodCity_EventScript_SyncUndergroundDoorTile_Locked:
	setmetatile 21, 38, METATILE_goldenrod_city_IntactDoor_Bottom_Locked, TRUE
	return

GoldenrodCity_EventScript_SyncUndergroundDoorTile_Unlocked:
	setmetatile 21, 38, METATILE_johto_general_og_IntactDoor_Bottom_Unlocked, TRUE
	return

GoldenrodCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
GoldenrodCity_EventScript_CityEnterQuest_End:
	end

GoldenrodCity_EventScript_Celia::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Celia_Disguised
	setspeaker GoldenrodCity_Speaker_Celia
	msgbox GoldenrodCity_Text_Celia, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Celia_Disguised:
	setspeaker GoldenrodCity_Speaker_Celia
	msgbox GoldenrodCity_Text_Celia_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Gus::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Gus_Disguised
	setspeaker GoldenrodCity_Speaker_Gus
	msgbox GoldenrodCity_Text_Gus, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Gus_Disguised:
	setspeaker GoldenrodCity_Speaker_Gus
	msgbox GoldenrodCity_Text_Gus_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CipherGrunt::
	lock
	faceplayer
	setspeaker GoldenrodCity_Speaker_PeonKane
	msgbox GoldenrodCity_Text_CipherGrunt, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Marvin::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Marvin_Disguised
	setspeaker GoldenrodCity_Speaker_Marvin
	msgbox GoldenrodCity_Text_Marvin, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Marvin_Disguised:
	setspeaker GoldenrodCity_Speaker_Marvin
	msgbox GoldenrodCity_Text_Marvin_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Eli::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Eli_Disguised
	setspeaker GoldenrodCity_Speaker_Eli
	msgbox GoldenrodCity_Text_Eli, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Eli_Disguised:
	setspeaker GoldenrodCity_Speaker_Eli
	msgbox GoldenrodCity_Text_Eli_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Toby::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Toby_Disguised
	setspeaker GoldenrodCity_Speaker_Toby
	msgbox GoldenrodCity_Text_Toby, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Toby_Disguised:
	setspeaker GoldenrodCity_Speaker_Toby
	msgbox GoldenrodCity_Text_Toby_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Harold::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_Harold_Disguised
	setspeaker GoldenrodCity_Speaker_Harold
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_EventScript_Harold_AfterWhitney
	msgbox GoldenrodCity_Text_Harold, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Harold_AfterWhitney:
	msgbox GoldenrodCity_Text_Harold_AfterWhitney, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Harold_Disguised:
	setspeaker GoldenrodCity_Speaker_Harold
	msgbox GoldenrodCity_Text_Harold_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CipherPeonM2::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_CipherPeonM2_Disguised
	setspeaker GoldenrodCity_Speaker_PeonLud
	msgbox GoldenrodCity_Text_CipherPeonM2_Line1, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	msgbox GoldenrodCity_Text_CipherPeonM2_Line2, MSGBOX_DEFAULT
	turnobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_2, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_CipherPeonM2_Disguised::
	faceplayer
	setspeaker GoldenrodCity_Speaker_PeonLud
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

GoldenrodCity_EventScript_RadioGuardScene::
	setspeaker GoldenrodCity_Speaker_PeonKane
	msgbox GoldenrodCity_Text_RadioGuard_Intro, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_GOLDENROD_CITY_CIPHER_PEON_M_3
	addobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3
	switch VAR_0x8004
	case 0, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Left
	case 1, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Front
	case 2, GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Right

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Left:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ToLeftTrigger
	goto GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Front:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ToFrontTrigger
	goto GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Right:
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ToRightTrigger

GoldenrodCity_EventScript_RadioGuard_MovePeonM2_Done:
	waitmovement 0
	setvar VAR_LAST_TALKED, LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3
	setspeaker GoldenrodCity_Speaker_PeonLud
	faceplayer
	msgbox GoldenrodCity_Text_CipherPeonM2_RadioScene, MSGBOX_DEFAULT
	setvar VAR_LAST_TALKED, LOCALID_GOLDENROD_CITY_RADIO_GUARD
	setspeaker GoldenrodCity_Speaker_PeonKane
	turnobject LOCALID_GOLDENROD_CITY_RADIO_GUARD, DIR_SOUTH
	switch VAR_0x8004
	case 0, GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneLeft
	case 1, GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneFront
	case 2, GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneRight

GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneLeft:
	turnobject LOCALID_PLAYER, DIR_EAST
	goto GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneDone

GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneFront:
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneDone

GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneRight:
	turnobject LOCALID_PLAYER, DIR_WEST

GoldenrodCity_EventScript_RadioGuard_PlayerFaceKaneDone:
	msgbox GoldenrodCity_Text_RadioGuard_After1, MSGBOX_DEFAULT
	setspeaker GoldenrodCity_Speaker_PeonLud
	turnobject LOCALID_PLAYER, DIR_SOUTH
	msgbox GoldenrodCity_Text_RadioGuard_After2, MSGBOX_DEFAULT
	switch VAR_0x8004
	case 0, GoldenrodCity_EventScript_RadioGuard_ExitLeft
	case 1, GoldenrodCity_EventScript_RadioGuard_ExitFront
	case 2, GoldenrodCity_EventScript_RadioGuard_ExitRight

GoldenrodCity_EventScript_RadioGuard_ExitLeft:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitLeft
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ExitLeft
	goto GoldenrodCity_EventScript_RadioGuard_ExitDone

GoldenrodCity_EventScript_RadioGuard_ExitFront:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitFront
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ExitFront
	goto GoldenrodCity_EventScript_RadioGuard_ExitDone

GoldenrodCity_EventScript_RadioGuard_ExitRight:
	applymovement LOCALID_GOLDENROD_CITY_RADIO_GUARD, GoldenrodCity_Movement_RadioGuardExitTrigger2
	applymovement LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3, GoldenrodCity_Movement_CipherPeonM3_ExitRight

GoldenrodCity_EventScript_RadioGuard_ExitDone:
	waitmovement 0
	setflag FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE
	setflag FLAG_HIDE_GOLDENROD_CITY_CIPHER_PEON_M_3
	removeobject LOCALID_GOLDENROD_CITY_RADIO_GUARD
	removeobject LOCALID_GOLDENROD_CITY_CIPHER_PEON_M_3
	releaseall
	end

GoldenrodCity_EventScript_ExitBlockerNorth::
	goto_if_unset FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	goto_if_set FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	lockall
	msgbox GoldenrodCity_Text_ExitBlocker, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, GoldenrodCity_Movement_PlayerStepBackSouth
	waitmovement 0
	releaseall
	end

GoldenrodCity_EventScript_ExitBlockerSouth::
	goto_if_unset FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	goto_if_set FLAG_GOLDENROD_CITY_RADIO_SHIFT_DONE, GoldenrodCity_EventScript_RadioGuardTrigger_End
	lockall
	msgbox GoldenrodCity_Text_ExitBlocker, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, GoldenrodCity_Movement_PlayerStepBackNorth
	waitmovement 0
	releaseall
	end

GoldenrodCity_EventScript_LockedDoor::
	lock
	goto_if_set FLAG_GOLDENROD_TUNNEL_DOOR_UNLOCKED, GoldenrodCity_EventScript_LockedDoor_Unlocked
	checkitem ITEM_TUNNEL_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_EventScript_LockedDoor_Unlock
	msgbox GoldenrodCity_Text_LockedDoor, MSGBOX_SIGN
	release
	end

GoldenrodCity_EventScript_LockedDoor_Unlock:
	setflag FLAG_GOLDENROD_TUNNEL_DOOR_UNLOCKED
	setmetatile 21, 38, METATILE_johto_general_og_IntactDoor_Bottom_Unlocked, TRUE
	special DrawWholeMapView
	msgbox GoldenrodCity_Text_UnlockedDoor, MSGBOX_SIGN
	release
	end

GoldenrodCity_EventScript_LockedDoor_Unlocked:
	msgbox GoldenrodCity_Text_DoorIsOpen, MSGBOX_SIGN
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

GoldenrodCity_Text_Celia_Disguised:
	.string "D-don't hurt me... I didn't say\n"
	.string "anything about the RADIO TOWER.$"

GoldenrodCity_Text_Gus:
	.string "The UNDERGROUND used to feel lively.\n"
	.string "Now it feels like a tunnel for crooks.$"

GoldenrodCity_Text_Gus_Disguised:
	.string "You creeps already took the city.\n"
	.string "What more do you want from us?$"

GoldenrodCity_Text_CipherGrunt:
	.string "This city already belongs to CIPHER.\n"
	.string "Get lost kid.$"

GoldenrodCity_Text_Marvin:
	.string "The DEPT. STORE still opens, but the\n"
	.string "best stock disappears upstairs fast.$"

GoldenrodCity_Text_Marvin_Disguised:
	.string "No sale. Not to CIPHER.\p"
	.string "Go loot somebody else.$"

GoldenrodCity_Text_Eli:
	.string "WHITNEY kept the GYM open.\n"
	.string "She says GOLDENROD still needs spirit.$"

GoldenrodCity_Text_Eli_Disguised:
	.string "Tell your bosses WHITNEY isn't\n"
	.string "scared of a bunch of thugs.$"

GoldenrodCity_Text_Toby:
	.string "Mom says not to go near the RADIO\n"
	.string "TOWER after dark.$"

GoldenrodCity_Text_Toby_Disguised:
	.string "I-I'm not telling you where my mom\n"
	.string "went! Leave me alone!$"

GoldenrodCity_Text_Harold:
	.string "The station has been tense all day.\n"
	.string "Those black uniforms have everyone\n"
	.string "watching their backs.$"

GoldenrodCity_Text_Harold_AfterWhitney:
	.string "The station went quiet, then CIPHER\n"
	.string "started marching around like owners.$"

GoldenrodCity_Text_Harold_Disguised:
	.string "You can wear that uniform all you want.\n"
	.string "Goldenrod still won't respect CIPHER.$"

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

GoldenrodCity_Text_ExitBlocker:
	.string "I should really go and check out\n"
	.string "the RADIO TOWER before heading\l"
	.string "anywhere else.$"

GoldenrodCity_Text_LockedDoor:
	.string "The door is locked.$"

GoldenrodCity_Text_UnlockedDoor:
	.string "{PLAYER} used the TUNNEL KEY\n"
	.string "to unlock the door.$"

GoldenrodCity_Text_DoorIsOpen:
	.string "The door is open.$"

GoldenrodCity_Movement_CipherPeonM3_ToLeftTrigger:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_Movement_CipherPeonM3_ToFrontTrigger:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

GoldenrodCity_Movement_CipherPeonM3_ToRightTrigger:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	step_end

GoldenrodCity_Movement_CipherPeonM3_ExitLeft:
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
	step_end

GoldenrodCity_Movement_CipherPeonM3_ExitFront:
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

GoldenrodCity_Movement_RadioGuardExitTrigger2:
	walk_down
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

GoldenrodCity_Movement_CipherPeonM3_ExitRight:
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

GoldenrodCity_Movement_PlayerStepBackSouth:
	walk_down
	face_down
	step_end

GoldenrodCity_Movement_PlayerStepBackNorth:
	walk_up
	face_up
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
