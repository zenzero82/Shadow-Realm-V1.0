New_Bark_Town_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, New_Bark_Town_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, New_Bark_Town_OnFrame
	.byte 0

@ Local IDs from map.json:
@   1 = Resix
@   2 = Greesix
@   3 = Yellosix
@   4 = Browsix
@   5 = Blusix
.set LOCALID_RESIX, 1
.set LOCALID_GREESIX, 2
.set LOCALID_YELLOSIX, 3
.set LOCALID_BROWSIX, 4
.set LOCALID_BLUSIX, 5
.set LOCALID_HOOPA_RING, 6

@ Legacy Snagem Grunt placeholders (not placed on map)
.set LOCALID_SNAGEM_GRUNT_1, 7
.set LOCALID_SNAGEM_GRUNT_2, 8
.set LOCALID_SNAGEM_GRUNT_3, 9

@ ================================
@ HEXAGON BROS SCENE
@ ================================

New_Bark_Town_OnLoad:
	setflag FLAG_VISITED_NEW_BARK_TOWN
	setvar VAR_TEMP_1, 0
	end

New_Bark_Town_OnFrame:
	map_script_2 VAR_TEMP_1, 0, New_Bark_Town_EventScript_OnEnter
	.2byte 0

New_Bark_Town_EventScript_OnEnter::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_NEW_BARK_HOOPA_RING
	checkflag FLAG_BIRCH_TIME_AMULET_CALL_DONE
	goto_if_eq VAR_RESULT, TRUE, New_Bark_Town_OnTransition_BirchDone
	goto_if_ne VAR_BIRCH_TIME_AMULET_CALL_PENDING, 1, New_Bark_Town_OnTransition_BirchDone
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 20, New_Bark_Town_OnTransition_BirchDone
	goto_if_eq VAR_0x8005, 11, New_Bark_Town_EventScript_BirchCallWarp
	goto_if_eq VAR_0x8005, 12, New_Bark_Town_EventScript_BirchCallWarp
	goto New_Bark_Town_OnTransition_BirchDone
New_Bark_Town_OnTransition_BirchDone:
	checkflag FLAG_HEXAGON_BROS_SCENE_DONE
	goto_if_eq VAR_RESULT, TRUE, New_Bark_Town_OnTransition_HideBros
	call New_Bark_Town_EventScript_ShowHexagonBros
	goto New_Bark_Town_OnTransition_QuestStart

New_Bark_Town_OnTransition_HideBros:
	call New_Bark_Town_EventScript_HideHexagonBros
New_Bark_Town_OnTransition_QuestStart:
	checkflag FLAG_QUEST_NEW_BARK_NPCS_STARTED
	goto_if_eq New_Bark_Town_OnTransition_End
	checkflag FLAG_QUEST_NEW_BARK_NPCS_COMPLETED
	goto_if_eq New_Bark_Town_OnTransition_End
	lockall
	setflag FLAG_QUEST_NEW_BARK_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	call QuestJournal_EventScript_CheckNewBarkNPCs
	releaseall
New_Bark_Town_OnTransition_End:
	end

New_Bark_Town_EventScript_BirchCallWarp::
	lockall
	setflag FLAG_BIRCH_TIME_AMULET_CALL_DONE
	setvar VAR_BIRCH_TIME_AMULET_CALL_PENDING, 0
	setspeaker New_Bark_Town_Speaker_Birch
	pokenavcall New_Bark_Town_Text_Birch_Call
	waitmessage
	closemessage

	clearflag FLAG_HIDE_NEW_BARK_HOOPA_RING
	addobject LOCALID_HOOPA_RING
	hideobjectat LOCALID_HOOPA_RING, MAP_NEW_BARK_TOWN
	setobjectxy LOCALID_HOOPA_RING, 20, 12
	setobjectxyperm LOCALID_HOOPA_RING, 20, 12
	showobjectat LOCALID_HOOPA_RING, MAP_NEW_BARK_TOWN
	setobjectsubpriority LOCALID_HOOPA_RING, MAP_NEW_BARK_TOWN, 1
	setobjectsubpriority LOCALID_PLAYER, MAP_NEW_BARK_TOWN, 0
	setvar VAR_0x8004, LOCALID_HOOPA_RING
	setvar VAR_0x8001, 20
	setvar VAR_0x8002, 12
	special Special_HoopaRingSpawnGrow
	waitstate
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventAbsorb
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	hideobjectat LOCALID_PLAYER, MAP_NEW_BARK_TOWN
	setvar VAR_0x8004, LOCALID_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_HOOPA_RING, MAP_NEW_BARK_TOWN
	setflag FLAG_HIDE_NEW_BARK_HOOPA_RING
	removeobject LOCALID_HOOPA_RING
	resetobjectsubpriority LOCALID_PLAYER, MAP_NEW_BARK_TOWN

	setflag FLAG_ROUTE34_HOOPA_SCENE
	releaseall
	warp MAP_ROUTE34, 36, 55
	waitstate
	end

New_Bark_Town_EventScript_HexagonBros::
	goto_if_set FLAG_HEXAGON_BROS_SCENE_DONE, New_Bark_Town_EventScript_HexagonBros_Done
	lockall
	setvar VAR_TEMP_0, 1
	playbgm MUS_HEXAGONBROS, TRUE

	special SpawnCameraObject
	special StorePlayerCoordsInVars
	goto_if_eq VAR_0x8005, 11, New_Bark_Town_EventScript_CameraPan_Y11
	goto_if_eq VAR_0x8005, 12, New_Bark_Town_EventScript_CameraPan_Y12
	goto_if_eq VAR_0x8005, 14, New_Bark_Town_EventScript_CameraPan_Y14
	goto New_Bark_Town_EventScript_CameraPan_Y13

New_Bark_Town_EventScript_CameraPan_Y11:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Camera_PanToResix_Y11
	goto New_Bark_Town_EventScript_CameraPan_Done

New_Bark_Town_EventScript_CameraPan_Y12:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Camera_PanToResix_Y12
	goto New_Bark_Town_EventScript_CameraPan_Done

New_Bark_Town_EventScript_CameraPan_Y14:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Camera_PanToResix_Y14
	goto New_Bark_Town_EventScript_CameraPan_Done

New_Bark_Town_EventScript_CameraPan_Y13:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Camera_PanToResix_Y13

New_Bark_Town_EventScript_CameraPan_Done:
	waitmovement 0
	goto New_Bark_Town_EventScript_CameraDone

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
	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Purpsix, MSGBOX_DEFAULT
	closemessage

	@ Use follower sad emote (FOLLOWER_EMOTION_SAD = 2)
	setfieldeffectargument 1, MAP_NUM(MAP_NEW_BARK_TOWN)
	setfieldeffectargument 2, MAP_GROUP(MAP_NEW_BARK_TOWN)
	setfieldeffectargument 7, 2
	setfieldeffectargument 0, LOCALID_RESIX
	dofieldeffect FLDEFF_EMOTE
	setfieldeffectargument 0, LOCALID_BLUSIX
	dofieldeffect FLDEFF_EMOTE
	setfieldeffectargument 0, LOCALID_GREESIX
	dofieldeffect FLDEFF_EMOTE
	setfieldeffectargument 0, LOCALID_YELLOSIX
	dofieldeffect FLDEFF_EMOTE
	setfieldeffectargument 0, LOCALID_BROWSIX
	dofieldeffect FLDEFF_EMOTE
	waitfieldeffect FLDEFF_EMOTE

	setspeaker New_Bark_Town_Speaker_Greesix
	msgbox New_Bark_Town_Text_Greesix_Pirate, MSGBOX_DEFAULT
	closemessage

	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Hoenn, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_BLUSIX, New_Bark_Town_Mov_Line_Bros_Lead
	applymovement LOCALID_GREESIX, New_Bark_Town_Mov_Line_Bros_Delay4
	applymovement LOCALID_YELLOSIX, New_Bark_Town_Mov_Line_Bros_Delay8
	applymovement LOCALID_BROWSIX, New_Bark_Town_Mov_Line_Bros_Delay16

	special StorePlayerCoordsInVars
	goto_if_eq VAR_0x8005, 11, New_Bark_Town_EventScript_Resix_ToPlayer_Y11
	goto_if_eq VAR_0x8005, 12, New_Bark_Town_EventScript_Resix_ToPlayer_Y12
	goto_if_eq VAR_0x8005, 14, New_Bark_Town_EventScript_Resix_ToPlayer_Y14
	goto New_Bark_Town_EventScript_Resix_ToPlayer_Y13

New_Bark_Town_EventScript_Resix_ToPlayer_Y11:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Resix_ToPlayer_Y11_Delayed
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_ToPlayer_Y11_Delayed
	goto New_Bark_Town_EventScript_Resix_ToPlayer_Done

New_Bark_Town_EventScript_Resix_ToPlayer_Y12:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Resix_ToPlayer_Y12_Delayed
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_ToPlayer_Y12_Delayed
	goto New_Bark_Town_EventScript_Resix_ToPlayer_Done

New_Bark_Town_EventScript_Resix_ToPlayer_Y14:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Resix_ToPlayer_Y14_Delayed
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_ToPlayer_Y14_Delayed
	goto New_Bark_Town_EventScript_Resix_ToPlayer_Done

New_Bark_Town_EventScript_Resix_ToPlayer_Y13:
	applymovement LOCALID_CAMERA, New_Bark_Town_Mov_Resix_ToPlayer_Y13_Delayed
	applymovement LOCALID_RESIX, New_Bark_Town_Mov_Resix_ToPlayer_Y13_Delayed

New_Bark_Town_EventScript_Resix_ToPlayer_Done:
	waitmovement LOCALID_RESIX
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
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
	hideobjectat LOCALID_BLUSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_GREESIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_YELLOSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_BROWSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_RESIX, MAP_NEW_BARK_TOWN

	special StorePlayerCoordsInVars
	special RemoveCameraObject
	special SetCameraFocusCoordsFromVars
	setflag FLAG_HEXAGON_BROS_SCENE_DONE
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	fadenewbgm MUS_HG_NEW_BARK
	releaseall
	end

New_Bark_Town_EventScript_HexagonBros_Done::
	releaseall
	end

New_Bark_Town_EventScript_HexagonBros_Trigger::
	goto_if_set FLAG_HEXAGON_BROS_SCENE_DONE, New_Bark_Town_EventScript_HexagonBros_Trigger_Done
	call New_Bark_Town_EventScript_ShowHexagonBros
	goto New_Bark_Town_EventScript_HexagonBros

New_Bark_Town_EventScript_HexagonBros_Trigger_Done:
	end

New_Bark_Town_EventScript_ShowHexagonBros:
	showobjectat LOCALID_RESIX, MAP_NEW_BARK_TOWN
	showobjectat LOCALID_GREESIX, MAP_NEW_BARK_TOWN
	showobjectat LOCALID_YELLOSIX, MAP_NEW_BARK_TOWN
	showobjectat LOCALID_BROWSIX, MAP_NEW_BARK_TOWN
	showobjectat LOCALID_BLUSIX, MAP_NEW_BARK_TOWN
	return

New_Bark_Town_EventScript_HideHexagonBros:
	hideobjectat LOCALID_RESIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_GREESIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_YELLOSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_BROWSIX, MAP_NEW_BARK_TOWN
	hideobjectat LOCALID_BLUSIX, MAP_NEW_BARK_TOWN
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
	setspeaker New_Bark_Town_Speaker_SnagemGrunt1
	msgbox New_Bark_Town_Text_Grunt1, MSGBOX_NPC
	closemessage
	release
	end

New_Bark_Town_EventScript_SnagemGrunt2_Wanderer::
	lock
	faceplayer
	setspeaker New_Bark_Town_Speaker_SnagemGrunt2
	msgbox New_Bark_Town_Text_Grunt2_AskWanderer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, New_Bark_Town_EventScript_Grunt2_No

	closemessage
	setspeaker New_Bark_Town_Speaker_SnagemGrunt2
	msgbox New_Bark_Town_Text_Grunt2_EasterEgg, MSGBOX_NPC
	closemessage
	setspeaker New_Bark_Town_Speaker_SnagemGrunt2
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
	setspeaker New_Bark_Town_Speaker_SnagemGrunt3
	msgbox New_Bark_Town_Text_Grunt3, MSGBOX_NPC
	closemessage
	release
	end

New_Bark_Town_Mov_Grunt2_StepAside:
	walk_left
	walk_left
	walk_up
	step_end

New_Bark_Town_Mov_Camera_PanToResix_Y11:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

New_Bark_Town_Mov_Camera_PanToResix_Y12:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

New_Bark_Town_Mov_Camera_PanToResix_Y13:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

New_Bark_Town_Mov_Camera_PanToResix_Y14:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

New_Bark_Town_Mov_Camera_ReturnToPlayer:
	walk_left
	step_end

New_Bark_Town_Mov_PlayerIntoRing:
	walk_up
	step_end

New_Bark_Town_Mov_Line_Bros_Lead:
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
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Line_Bros_Delay4:
	delay_4
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
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Line_Bros_Delay8:
	delay_8
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
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Line_Bros_Delay16:
	delay_16
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
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y11:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y11_Delayed:
	delay_16
	delay_8
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y12:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y12_Delayed:
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y13:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y13_Delayed:
	delay_16
	delay_8
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y14:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_ToPlayer_Y14_Delayed:
	delay_16
	delay_8
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

New_Bark_Town_Mov_Resix_Exclaim:
	emote_exclamation_mark
	step_end

New_Bark_Town_Mov_Resix_FacePlayer:
	face_left
	step_end

New_Bark_Town_Mov_Resix_Exit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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

New_Bark_Town_Speaker_SnagemGrunt1:
	.string "GRUNT$"

New_Bark_Town_Speaker_SnagemGrunt2:
	.string "GRUNT$"

New_Bark_Town_Speaker_SnagemGrunt3:
	.string "GRUNT$"

New_Bark_Town_Speaker_Birch:
	.string "BIRCH$"

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
	.string "PURPSIX.$"

New_Bark_Town_Text_Resix_Purpsix:
	.string "... ...\p"
	.string "I miss PURPSIX!!$"

New_Bark_Town_Text_Greesix_Pirate:
	.string "Remember what the Pirate said!$"

New_Bark_Town_Text_Resix_Hoenn:
	.string "Oh right, he said he seen one\n"
	.string "of us morons in Hoenn.\p"
	.string "We haven't been there yet so it\n"
	.string "has to be PURPSIX!\p"
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

New_Bark_Town_EventScript_HoopaRing::
	end

NewBarkTown_EventScript_Door_Text:
	.string "It's locked.$"

New_Bark_Town_Text_Birch_Call:
	.string "Hey Champ! How did things go with\n"
	.string "Kurt? ... ... Ah I see. Sorry you\l"
	.string "had to deal with that.\p"
	.string "Are you still in Azalea Town? ...\l"
	.string "... Huh?? New Bark Town!\p"
	.string "Geez I was hoping you could check\n"
	.string "out Ilex Forest to see if Celebi\l"
	.string "was there.\p"
	.string "Oh wait! Victor is on Route 34 and\n"
	.string "he has a TIME AMULET.\p"
	.string "I can warp you over to him.\n"
	.string "Doing it now!$"

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
	setspeaker New_Bark_Town_Speaker_Resix
	msgbox New_Bark_Town_Text_Resix_Talk, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	call QuestJournal_EventScript_CheckNewBarkNPCs
	end

New_Bark_Town_EventScript_Blusix_Talk::
	faceplayer
	setspeaker New_Bark_Town_Speaker_Blusix
	msgbox New_Bark_Town_Text_Blusix_Talk, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	call QuestJournal_EventScript_CheckNewBarkNPCs
	end

New_Bark_Town_EventScript_Greesix_Talk::
	faceplayer
	setspeaker New_Bark_Town_Speaker_Greesix
	msgbox New_Bark_Town_Text_Greesix_Talk, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	call QuestJournal_EventScript_CheckNewBarkNPCs
	end

New_Bark_Town_EventScript_Yellosix_Talk::
	faceplayer
	setspeaker New_Bark_Town_Speaker_Yellosix
	msgbox New_Bark_Town_Text_Yellosix_Talk, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	call QuestJournal_EventScript_CheckNewBarkNPCs
	end

New_Bark_Town_EventScript_Browsix_Talk::
	faceplayer
	setspeaker New_Bark_Town_Speaker_Browsix
	msgbox New_Bark_Town_Text_Browsix_Talk, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	call QuestJournal_EventScript_CheckNewBarkNPCs
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

QuestJournal_EventScript_CheckNewBarkNPCs::
	checkflag FLAG_QUEST_NEW_BARK_NPCS_COMPLETED
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_End
	checkflag FLAG_QUEST_NEW_BARK_NPCS_STARTED
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_AutoFlags
	return
QuestJournal_EventScript_CheckNewBarkNPCs_AutoFlags:
	checkflag FLAG_HEXAGON_BROS_SCENE_DONE
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_CheckSilver
	setflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
QuestJournal_EventScript_CheckNewBarkNPCs_CheckSilver:
	checkflag FLAG_SHADOW_TRACKER_UNLOCKED
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_HexagonBros
	setflag FLAG_QUEST_NEW_BARK_NPC_SILVER
QuestJournal_EventScript_CheckNewBarkNPCs_HexagonBros:
	checkflag FLAG_QUEST_NEW_BARK_NPC_HEXAGON_BROS
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_Silver
	return
QuestJournal_EventScript_CheckNewBarkNPCs_Silver:
	checkflag FLAG_QUEST_NEW_BARK_NPC_SILVER
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_House1Woman
	return
QuestJournal_EventScript_CheckNewBarkNPCs_House1Woman:
	checkflag FLAG_QUEST_NEW_BARK_NPC_HOUSE1_WOMAN
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_House1Lass
	return
QuestJournal_EventScript_CheckNewBarkNPCs_House1Lass:
	checkflag FLAG_QUEST_NEW_BARK_NPC_HOUSE1_LASS
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_House2Woman
	return
QuestJournal_EventScript_CheckNewBarkNPCs_House2Woman:
	checkflag FLAG_QUEST_NEW_BARK_NPC_HOUSE2_WOMAN
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_House2Girl
	return
QuestJournal_EventScript_CheckNewBarkNPCs_House2Girl:
	checkflag FLAG_QUEST_NEW_BARK_NPC_HOUSE2_GIRL
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_PlayersHouseMom
	return
QuestJournal_EventScript_CheckNewBarkNPCs_PlayersHouseMom:
	checkflag FLAG_QUEST_NEW_BARK_NPC_PLAYERS_HOUSE_MOM
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_PlayersHouseFriend
	return
QuestJournal_EventScript_CheckNewBarkNPCs_PlayersHouseFriend:
	checkflag FLAG_QUEST_NEW_BARK_NPC_PLAYERS_HOUSE_FRIEND
	goto_if_eq QuestJournal_EventScript_CheckNewBarkNPCs_Done
	return
QuestJournal_EventScript_CheckNewBarkNPCs_Done:
	setflag FLAG_QUEST_NEW_BARK_NPCS_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
QuestJournal_EventScript_CheckNewBarkNPCs_End:
	return

NewBarkTown_Text_LabSign:
	.string "PROF.ELM's LAB$"


NewBarkTown_Text_Door:
	.string "The door is locked.$"


NewBarkTown_Text_Sign:
	.string "NEW BARK TOWN\p"
	.string "The Town Where the Winds of\n"
	.string "a New Beginning Blow$"


NewBarkTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"


NewBarkTown_Text_ElmsHouse:
	.string "PROF.ELM's House$"

