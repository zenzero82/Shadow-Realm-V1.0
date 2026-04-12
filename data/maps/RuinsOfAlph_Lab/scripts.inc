RuinsOfAlph_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

#define RUINSOFALPH_LAB_LOCALID_AETHER_GRUNT_F 1
#define RUINSOFALPH_LAB_LOCALID_FABA 2
#define RUINSOFALPH_LAB_LOCALID_AETHER_GRUNT_M 3
#define RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE 4

RuinsOfAlph_Lab_OnTransition::
	checkitem ITEM_ZYGARDE_CUBE
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_OnTransition_HideCube
	clearflag FLAG_HIDE_RUINS_OF_ALPH_LAB_ZYGARDE_CUBE
	showobjectat RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE, MAP_RUINS_OF_ALPH_LAB
	end

RuinsOfAlph_Lab_OnTransition_HideCube::
	setflag FLAG_HIDE_RUINS_OF_ALPH_LAB_ZYGARDE_CUBE
	hideobjectat RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE, MAP_RUINS_OF_ALPH_LAB
	removeobject RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE
	end

RuinsOfAlph_Lab_EventScript_FabaTrigger::
	lockall
	call RuinsOfAlph_Lab_EventScript_PlayerWalkToFaba
	turnobject LOCALID_PLAYER, DIR_NORTH
	call RuinsOfAlph_Lab_EventScript_FabaTalk_NoLock
	closemessage
	setvar VAR_RUINSOFALPH_ZYGARDE_QUEST, 1
	releaseall
	end

RuinsOfAlph_Lab_EventScript_PlayerWalkToFaba::
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 1
	goto_if_eq RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromLeft
	compare VAR_0x8004, 3
	goto_if_eq RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromRight
	goto RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromCenter

RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromLeft::
	applymovement LOCALID_PLAYER, RuinsOfAlph_Lab_Movement_PlayerToFaba_FromLeft
	waitmovement 0
	return

RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromRight::
	applymovement LOCALID_PLAYER, RuinsOfAlph_Lab_Movement_PlayerToFaba_FromRight
	waitmovement 0
	return

RuinsOfAlph_Lab_EventScript_PlayerToFaba_FromCenter::
	applymovement LOCALID_PLAYER, RuinsOfAlph_Lab_Movement_PlayerToFaba_FromCenter
	waitmovement 0
	return

RuinsOfAlph_Lab_EventScript_FabaTalk::
	lock
	faceplayer
	call RuinsOfAlph_Lab_EventScript_FabaTalk_NoLock
	closemessage
	release
	end

RuinsOfAlph_Lab_EventScript_FabaTalk_NoLock::
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_eq VAR_RUINSOFALPH_ZYGARDE_QUEST, 1, RuinsOfAlph_Lab_EventScript_FabaReminder
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_Intro1, MSGBOX_DEFAULT
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_Intro2, MSGBOX_DEFAULT
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_Intro3, MSGBOX_DEFAULT
RuinsOfAlph_Lab_EventScript_FabaAskLoop::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_Ask, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RuinsOfAlph_Lab_EventScript_FabaAskNo
	goto RuinsOfAlph_Lab_EventScript_FabaAskYes

RuinsOfAlph_Lab_EventScript_FabaAskNo::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_No, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_FabaAskLoop

RuinsOfAlph_Lab_EventScript_FabaAskYes::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_Yes, MSGBOX_DEFAULT
	setvar VAR_RUINSOFALPH_ZYGARDE_QUEST, 1
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_PickUp, MSGBOX_DEFAULT
	return

RuinsOfAlph_Lab_EventScript_FabaReminder::
	checkitem ITEM_ZYGARDE_CUBE
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_FabaReminder_HaveCube
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_ReminderPickUp, MSGBOX_DEFAULT
	return

RuinsOfAlph_Lab_EventScript_FabaReminder_HaveCube::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker RuinsOfAlph_Lab_Speaker_Faba
	msgbox RuinsOfAlph_Lab_Text_Faba_ReminderSearch, MSGBOX_DEFAULT
	return

RuinsOfAlph_Lab_EventScript_ZygardeCube::
	goto_if_eq VAR_RUINSOFALPH_ZYGARDE_QUEST, 0, RuinsOfAlph_Lab_EventScript_ZygardeCube_NotReady
	lock
	giveitem ITEM_ZYGARDE_CUBE
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_ZygardeCube_BagFull
	setflag FLAG_HIDE_RUINS_OF_ALPH_LAB_ZYGARDE_CUBE
	hideobjectat RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE, MAP_RUINS_OF_ALPH_LAB
	removeobject RUINSOFALPH_LAB_LOCALID_ZYGARDE_CUBE
	msgbox ZygardeCube_Text_GotCube, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_ZygardeCube_BagFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_ZygardeCube_NotReady::
	lock
	msgbox RuinsOfAlph_Lab_Text_ZygardeCube_NotReady, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Lab_EventScript_AetherGruntF::
	lock
	faceplayer
	setspeaker RuinsOfAlph_Lab_Speaker_AetherGrunt
	msgbox RuinsOfAlph_Lab_Text_AetherGruntF, MSGBOX_NPC
	closemessage
	release
	end

RuinsOfAlph_Lab_EventScript_AetherGruntM::
	lock
	faceplayer
	setspeaker RuinsOfAlph_Lab_Speaker_AetherGrunt
	msgbox RuinsOfAlph_Lab_Text_AetherGruntM, MSGBOX_NPC
	closemessage
	release
	end

RuinsOfAlph_Lab_Movement_PlayerToFaba_FromLeft:
	walk_right
	walk_up
	walk_up
	step_end

RuinsOfAlph_Lab_Movement_PlayerToFaba_FromRight:
	walk_left
	walk_up
	walk_up
	step_end

RuinsOfAlph_Lab_Movement_PlayerToFaba_FromCenter:
	walk_up
	step_end

RuinsOfAlph_Lab_Speaker_Faba:
	.string "FABA$"

RuinsOfAlph_Lab_Speaker_AetherGrunt:
	.string "AETHER GRUNT$"

RuinsOfAlph_Lab_Text_Faba_Intro1:
	.string "Hello. I'm FABA.\p"
	.string "I'm a scientist working with\n"
	.string "PROFESSOR OAK.$"

RuinsOfAlph_Lab_Text_Faba_Intro2:
	.string "I've been researching the legendary\n"
	.string "ZYGARDE since it appeared in the\l"
	.string "HOENN region.$"

RuinsOfAlph_Lab_Text_Faba_Intro3:
	.string "It split itself and scattered Cells\n"
	.string "and Cores across KANTO,\l"
	.string "JOHTO, and HOENN.$"

RuinsOfAlph_Lab_Text_Faba_Ask:
	.string "Will you help me find the Cells\n"
	.string "and Cores?$"

RuinsOfAlph_Lab_Text_Faba_No:
	.string "Please, I need your help.\n"
	.string "Will you search for them?$"

RuinsOfAlph_Lab_Text_Faba_Yes:
	.string "Excellent!$"

RuinsOfAlph_Lab_Text_Faba_PickUp:
	.string "Please take the ZYGARDE CUBE on\n"
	.string "the table. It will store the Cells\l"
	.string "and Cores until we find them all.$"

RuinsOfAlph_Lab_Text_Faba_ReminderPickUp:
	.string "The ZYGARDE CUBE is on the table.\n"
	.string "Please take it.$"

RuinsOfAlph_Lab_Text_Faba_ReminderSearch:
	.string "Please search for ZYGARDE Cells\n"
	.string "and Cores across the regions.$"

RuinsOfAlph_Lab_Text_ZygardeCube_NotReady:
	.string "It's a strange device on the table.$"

RuinsOfAlph_Lab_Text_AetherGruntF:
	.string "FABA's research is top priority.\n"
	.string "Please don't touch the equipment.$"

RuinsOfAlph_Lab_Text_AetherGruntM:
	.string "We're cataloging the ruins and\n"
	.string "tracking ZYGARDE signals.$"
