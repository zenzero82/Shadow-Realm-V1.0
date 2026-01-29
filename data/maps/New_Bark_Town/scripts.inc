New_Bark_Town_MapScripts::
	.byte 0

@ Local IDs from map.json:
@   1 = Hoopa Ring
@   2 = Snagem Grunt (north)
@   3 = Snagem Grunt (middle)
@   4 = Snagem Grunt (south)
.set LOCALID_SNAGEM_GRUNT_1, 2
.set LOCALID_SNAGEM_GRUNT_2, 3
.set LOCALID_SNAGEM_GRUNT_3, 4

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
