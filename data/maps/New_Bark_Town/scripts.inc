New_Bark_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, New_Bark_Town_OnTransition
	.byte 0

@ Local IDs from map.json:
@   1 = Hoopa Ring
@   2 = Resix
@   3 = Greesix
@   4 = Yellosix
@   5 = Browsix
@   6 = Blusix
.set LOCALID_RESIX, 2
.set LOCALID_GREESIX, 3
.set LOCALID_YELLOSIX, 4
.set LOCALID_BROWSIX, 5
.set LOCALID_BLUSIX, 6

@ Legacy Snagem Grunt placeholders (not placed on map)
.set LOCALID_SNAGEM_GRUNT_1, 2
.set LOCALID_SNAGEM_GRUNT_2, 3
.set LOCALID_SNAGEM_GRUNT_3, 4

@ ================================
@ HEXAGON BROS SCENE
@ ================================

New_Bark_Town_OnTransition:
	checkflag FLAG_HEXAGON_BROS_SCENE_DONE
	goto_if_eq VAR_RESULT, TRUE, New_Bark_Town_OnTransition_HideBros
	goto New_Bark_Town_EventScript_HexagonBros

New_Bark_Town_OnTransition_HideBros:
	call New_Bark_Town_EventScript_HideHexagonBros
	end

New_Bark_Town_EventScript_HexagonBros::
	lockall
	fadeoutbgm 4
	delay 20
	playbgm MUS_HEXAGONBROS, TRUE

	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0

	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 7, New_Bark_Town_EventScript_CameraSnap
	goto_if_ne VAR_0x8005, 21, New_Bark_Town_EventScript_CameraSnap
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Camera_PanToResix
	waitmovement 0
	goto New_Bark_Town_EventScript_CameraDone

New_Bark_Town_EventScript_CameraSnap:
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 13
	special SpawnCameraObjectAtVars
	special SetCameraFocusCoordsFromVars

New_Bark_Town_EventScript_CameraDone:
	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_SoundOff, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Blusix
	msgbox New_Bark_Town_Text_Blusix_Name, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Greesix
	msgbox New_Bark_Town_Text_Greesix_Name, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Yellosix
	msgbox New_Bark_Town_Text_Yellosix_Name, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Browsix
	msgbox New_Bark_Town_Text_Browsix_Name, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Objectives, MSGBOX_DEFAULT
	closemessage
	msgbox New_Bark_Town_Text_Resix_Purpsix, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Emote_Sad
	applymovement LOCALID_BLUSIX, New_Bark_Town_Mov_Emote_Sad
	applymovement LOCALID_GREESIX, New_Bark_Town_Mov_Emote_Sad
	applymovement LOCALID_YELLOSIX, New_Bark_Town_Mov_Emote_Sad
	applymovement LOCALID_BROWSIX, New_Bark_Town_Mov_Emote_Sad
	waitmovement 0

	setspeaker New_Bark_Town_Speaker_Greesix
	msgbox New_Bark_Town_Text_Greesix_Pirate, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Hoenn, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_BLUSIX, New_Bark_Town_Mov_Line_Blusix
	waitmovement 0
	hideobjectat LOCALID_BLUSIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_BLUSIX

	applymovement LOCALID_GREESIX, New_Bark_Town_Mov_Line_Greesix
	waitmovement 0
	hideobjectat LOCALID_GREESIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_GREESIX

	applymovement LOCALID_YELLOSIX, New_Bark_Town_Mov_Line_Yellosix
	waitmovement 0
	hideobjectat LOCALID_YELLOSIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_YELLOSIX

	applymovement LOCALID_BROWSIX, New_Bark_Town_Mov_Line_Browsix
	waitmovement 0
	hideobjectat LOCALID_BROWSIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_BROWSIX

	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_ToPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_Exclaim
	waitmovement 0
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_FacePlayer
	waitmovement 0

	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Player, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_Exit
	waitmovement 0
	hideobjectat LOCALID_RESIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_RESIX

	setflag FLAG_HEXAGON_BROS_SCENE_DONE
	special RemoveCameraObject
	fadenewbgm MUS_HG_NEW_BARK
	releaseall
	end

New_Bark_Town_EventScript_HexagonBros_Done::
	releaseall
	end

New_Bark_Town_EventScript_HideHexagonBros:
	hideobjectat LOCALID_RESIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_GREESIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_YELLOSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_BROWSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_BLUSIX, MAP_NEW_BARK_TOWN
	removeobject LOCALID_RESIX
	removeobject LOCALID_GREESIX
	removeobject LOCALID_YELLOSIX
	removeobject LOCALID_BROWSIX
	removeobject LOCALID_BLUSIX
	return

@ ================================
@ NEW BARK PORTAL WARP (PALLET)
@ Attach this script to your portal object in Porymap:
@   Script: New_Bark_Town_EventScript_Portal_ToPalletForest

New_Bark_Town_EventScript_Portal_ToPalletForest::
	lock
	faceplayer
	msgbox New_Bark_Town_Text_PortalAsk_Pallet, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, New_Bark_Town_PortalNo

	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	@ Warp back to Pallet Town Western Forest (below the portal)
	warp MAP_PALLET_TOWN_WESTERN_FOREST, WARP_ID_NONE, 5, 5

	waitstate
	end

New_Bark_Town_PortalNo::
	closemessage
	release
	end

New_Bark_Town_Text_PortalAsk_Pallet:
	.string "The portal is humming...\p"
	.string "Warp to PALLET TOWN WESTERN FOREST?$"

@ ================================
@ SNAGEM GRUNTS (TEMP)
@ ================================

New_Bark_Town_EventScript_SnagemGrunt1::
	lock
	faceplayer
	msgbox New_Bark_Town_Text_Grunt1, MSGBOX_NPC
	closemessage
	release
	end

New_Bark_Town_EventScript_SnagemGrunt2_Wanderer::
	lock
	faceplayer
	msgbox New_Bark_Town_Text_Grunt2_AskWanderer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, New_Bark_Town_EventScript_Grunt2_No

	closemessage
	msgbox New_Bark_Town_Text_Grunt2_EasterEgg, MSGBOX_NPC
	closemessage
	msgbox New_Bark_Town_Text_Grunt2_Destroyed, MSGBOX_NPC
	closemessage

	applymovement LOCALID_SNAGEM_GRUNT_2, New_Bark_Town_Mov_Grunt2_StepAside
	waitmovement 0
	setobjectmovementtype LOCALID_SNAGEM_GRUNT_2, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_SNAGEM_GRUNT_2, 1, 11
	release
	end

New_Bark_Town_EventScript_Grunt2_No::
	closemessage
	release
	end

New_Bark_Town_EventScript_SnagemGrunt3::
	lock
	faceplayer
	msgbox New_Bark_Town_Text_Grunt3, MSGBOX_NPC
	closemessage
	release
	end

New_Bark_Town_Mov_Grunt2_StepAside:
	walk_left
	walk_left
	walk_up
	step_end

New_Bark_Town_Mov_Camera_PanToResix:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

New_Bark_Town_Mov_Emote_Sad:
	emote_x
	step_end

New_Bark_Town_Mov_Line_Blusix:
	walk_right
	walk_right
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
	step_end

New_Bark_Town_Mov_Line_Greesix:
	walk_right
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
	step_end

New_Bark_Town_Mov_Line_Yellosix:
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
	step_end

New_Bark_Town_Mov_Line_Browsix:
	walk_left
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
	step_end

New_Bark_Town_Mov_Resix_ToPlayer:
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

New_Bark_Town_Mov_Resix_Exclaim:
	emote_exclamation_mark
	step_end

New_Bark_Town_Mov_Resix_FacePlayer:
	face_left
	step_end

New_Bark_Town_Mov_Resix_Exit:
	face_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

New_Bark_Town_Text_Grunt1:
	.string "We're keeping an eye on the ring.\p"
	.string "Too many weird things have happened.$"

New_Bark_Town_Text_Grunt2_AskWanderer:
	.string "Want to meet the wanderer?$"

New_Bark_Town_Text_Grunt2_EasterEgg:
	.string "Tester-only easter egg.\p"
	.string "You're about to see something wild.$"

New_Bark_Town_Text_Grunt2_Destroyed:
	.string "Fair warning: you'll get destroyed.$"

New_Bark_Town_Text_Grunt3:
	.string "Orders are to hold this spot.\p"
	.string "Don't make this harder than it is.$"

@ ---------- SPEAKERS ----------

New_Bark_Town_Speaker_Resix:
	.string "RESIX$"

New_Bark_Town_Speaker_Blusix:
	.string "BLUSIX$"

New_Bark_Town_Speaker_Greesix:
	.string "GREESIX$"

New_Bark_Town_Speaker_Yellosix:
	.string "YELLOSIX$"

New_Bark_Town_Speaker_Browsix:
	.string "BROWSIX$"

@ ---------- TEXT (Hexagon Bros) ----------

New_Bark_Town_Text_Resix_SoundOff:
	.string "Sound off!\p"
	.string "RESIX!$"

New_Bark_Town_Text_Blusix_Name:
	.string "BLUSIX!$"

New_Bark_Town_Text_Greesix_Name:
	.string "GREESIX!$"

New_Bark_Town_Text_Yellosix_Name:
	.string "YELLOSIX!$"

New_Bark_Town_Text_Browsix_Name:
	.string "BROWSIX!$"

New_Bark_Town_Text_Resix_Objectives:
	.string "Objective check. Stay together,\n"
	.string "keep a clear head, and find\l"
	.string "Purpsix.$"

New_Bark_Town_Text_Resix_Purpsix:
	.string "... ...\p"
	.string "I miss Purpsix!!$"

New_Bark_Town_Text_Greesix_Pirate:
	.string "Remember what the Pirate said!$"

New_Bark_Town_Text_Resix_Hoenn:
	.string "Oh right, he said he seen one\n"
	.string "of us morons in Hoenn.\p"
	.string "We haven't been there yet so it\n"
	.string "has to be Purpsix!\p"
	.string "That's it, we head to Hoenn.\p"
	.string "Move out!$"

New_Bark_Town_Text_Resix_Player:
	.string "... ....\p"
	.string "hmph.$"

NewBarkTown_EventScript_TownSign::
	msgbox NewBarkTown_EventScript_TownSign_Text, MSGBOX_SIGN
	end

NewBarkTown_EventScript_TownSign_Text:
	.string "Welcome to town.$"

NewBarkTown_EventScript_Door::
	msgbox NewBarkTown_EventScript_Door_Text, MSGBOX_SIGN
	end

NewBarkTown_EventScript_Door_Text:
	.string "It's locked.$"

NewBarkTown_EventScript_PlayersHouseMailbox::
	msgbox NewBarkTown_EventScript_PlayersHouseMailbox_Text, MSGBOX_SIGN
	end

NewBarkTown_EventScript_PlayersHouseMailbox_Text:
	.string "It's a mailbox.$"

NewBarkTown_EventScript_ElmsHouseMailbox::
	msgbox NewBarkTown_EventScript_ElmsHouseMailbox_Text, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouseMailbox_Text:
	.string "It's a mailbox.$"

NewBarkTown_EventScript_LabSign::
	msgbox NewBarkTown_EventScript_LabSign_Text, MSGBOX_SIGN
	end

NewBarkTown_EventScript_LabSign_Text:
	.string "POKéMON LAB.$"

New_Bark_Town_EventScript_Resix_Talk::
	faceplayer
	msgbox New_Bark_Town_Text_Resix_Talk, MSGBOX_NPC
	end

New_Bark_Town_EventScript_Blusix_Talk::
	faceplayer
	msgbox New_Bark_Town_Text_Blusix_Talk, MSGBOX_NPC
	end

New_Bark_Town_EventScript_Greesix_Talk::
	faceplayer
	msgbox New_Bark_Town_Text_Greesix_Talk, MSGBOX_NPC
	end

New_Bark_Town_EventScript_Yellosix_Talk::
	faceplayer
	msgbox New_Bark_Town_Text_Yellosix_Talk, MSGBOX_NPC
	end

New_Bark_Town_EventScript_Browsix_Talk::
	faceplayer
	msgbox New_Bark_Town_Text_Browsix_Talk, MSGBOX_NPC
	end

New_Bark_Town_Text_Resix_Talk:
	.string "Stay focused. We move soon.$"

New_Bark_Town_Text_Blusix_Talk:
	.string "Orders are orders. Keep the line.$"

New_Bark_Town_Text_Greesix_Talk:
	.string "If the Hoenn lead is real, we\n"
	.string "cannot waste time.$"

New_Bark_Town_Text_Yellosix_Talk:
	.string "No chatter. Eyes up.$"

New_Bark_Town_Text_Browsix_Talk:
	.string "We will find our brother. We do\n"
	.string "not linger.$"
