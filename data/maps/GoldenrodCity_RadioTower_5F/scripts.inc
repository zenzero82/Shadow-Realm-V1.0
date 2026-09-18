GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_RadioTower_5F_OnTransition
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	checktrainerflag TRAINER_GOLDENROD_RADIO_MARNIE
	goto_if_eq GoldenrodCity_RadioTower_5F_OnLoad_MarnieHide
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_MARNIE
	addobject LOCALID_GOLDENROD_RADIO_5F_MARNIE
	showobjectat LOCALID_GOLDENROD_RADIO_5F_MARNIE, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	goto GoldenrodCity_RadioTower_5F_OnLoad_MarnieEnd
GoldenrodCity_RadioTower_5F_OnLoad_MarnieHide:
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_MARNIE
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_MARNIE, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_MARNIE
GoldenrodCity_RadioTower_5F_OnLoad_MarnieEnd:
	goto_if_set FLAG_AGATE_VILLAGE_HOOPA_EMERGE, GoldenrodCity_RadioTower_5F_OnLoad_VenusHide
	cleartrainerflag TRAINER_VENUS
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUS
	addobject LOCALID_GOLDENROD_RADIO_5F_VENUS
	showobjectat LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_GOODRA
	addobject LOCALID_GOLDENROD_RADIO_5F_GOODRA
	showobjectat LOCALID_GOLDENROD_RADIO_5F_GOODRA, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUSAUR
	addobject LOCALID_GOLDENROD_RADIO_5F_VENUSAUR
	showobjectat LOCALID_GOLDENROD_RADIO_5F_VENUSAUR, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	goto GoldenrodCity_RadioTower_5F_OnLoad_End
GoldenrodCity_RadioTower_5F_OnLoad_VenusHide:
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUS
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUS
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_GOODRA
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_GOODRA, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_GOODRA
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUSAUR
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUSAUR, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUSAUR
GoldenrodCity_RadioTower_5F_OnLoad_End:
	end

GoldenrodCity_RadioTower_5F_OnTransition::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	checktrainerflag TRAINER_GOLDENROD_RADIO_MARNIE
	goto_if_eq GoldenrodCity_RadioTower_5F_OnTransition_MarnieHide
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_MARNIE
	addobject LOCALID_GOLDENROD_RADIO_5F_MARNIE
	showobjectat LOCALID_GOLDENROD_RADIO_5F_MARNIE, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	goto GoldenrodCity_RadioTower_5F_OnTransition_MarnieEnd
GoldenrodCity_RadioTower_5F_OnTransition_MarnieHide:
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_MARNIE
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_MARNIE, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_MARNIE
GoldenrodCity_RadioTower_5F_OnTransition_MarnieEnd:
	goto_if_set FLAG_AGATE_VILLAGE_HOOPA_EMERGE, GoldenrodCity_RadioTower_5F_OnTransition_VenusHide
	cleartrainerflag TRAINER_VENUS
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUS
	addobject LOCALID_GOLDENROD_RADIO_5F_VENUS
	showobjectat LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_GOODRA
	addobject LOCALID_GOLDENROD_RADIO_5F_GOODRA
	showobjectat LOCALID_GOLDENROD_RADIO_5F_GOODRA, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUSAUR
	addobject LOCALID_GOLDENROD_RADIO_5F_VENUSAUR
	showobjectat LOCALID_GOLDENROD_RADIO_5F_VENUSAUR, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	goto GoldenrodCity_RadioTower_5F_OnTransition_End
GoldenrodCity_RadioTower_5F_OnTransition_VenusHide:
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUS
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUS
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_GOODRA
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_GOODRA, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_GOODRA
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUSAUR
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUSAUR, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUSAUR
GoldenrodCity_RadioTower_5F_OnTransition_End:
	end

GoldenrodCity_RadioTower_5F_Speaker_Venus:
	.string "VENUS$"

GoldenrodCity_RadioTower_5F_Speaker_Grunt1:
	.string "CIPHER GRUNT$"

GoldenrodCity_RadioTower_5F_Speaker_Grunt2:
	.string "CIPHER GRUNT$"

GoldenrodCity_RadioTower_5F_Speaker_Cameraman:
	.string "CAMERAMAN$"

GoldenrodCity_RadioTower_5F_Speaker_Marnie:
	.string "MARNIE$"

GoldenrodCity_RadioTower_5F_EventScript_HoopaTrap::
	checktrainerflag TRAINER_VENUS
	goto_if_ne GoldenrodCity_RadioTower_5F_EventScript_HoopaTrap_Done
	lockall
	special StorePlayerCoordsInVars
	copyvar VAR_TEMP_3, VAR_0x8004
	copyvar VAR_TEMP_4, VAR_0x8005
	subvar VAR_TEMP_4, 1
	copyvar VAR_0x8001, VAR_TEMP_3
	copyvar VAR_0x8002, VAR_TEMP_4
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	addobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setobjectxy LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, VAR_TEMP_3, VAR_TEMP_4
	setobjectxyperm LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, VAR_TEMP_3, VAR_TEMP_4
	showobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setobjectsubpriority LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F, 1
	setobjectsubpriority LOCALID_PLAYER, MAP_GOLDENROD_CITY_RADIO_TOWER_5F, 0
	setvar VAR_0x8004, LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	special Special_HoopaRingSpawnGrow
	waitstate
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventAbsorb
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	hideobjectat LOCALID_PLAYER, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setvar VAR_0x8004, LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	removeobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	resetobjectsubpriority LOCALID_PLAYER, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	releaseall
	warp MAP_NOTHING, WARP_ID_NONE, 39, 45
	waitstate
	end

GoldenrodCity_RadioTower_5F_EventScript_HoopaTrap_Done::
	end

GoldenrodCity_RadioTower_5F_EventScript_MarnieTriggerLeft::
	checktrainerflag TRAINER_GOLDENROD_RADIO_MARNIE
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_MarnieTrigger_Done
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_RadioTower_5F_EventScript_MarnieScene

GoldenrodCity_RadioTower_5F_EventScript_MarnieTriggerDownLeft::
	checktrainerflag TRAINER_GOLDENROD_RADIO_MARNIE
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_MarnieTrigger_Done
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_RadioTower_5F_EventScript_MarnieScene

GoldenrodCity_RadioTower_5F_EventScript_MarnieTriggerDown::
	checktrainerflag TRAINER_GOLDENROD_RADIO_MARNIE
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_MarnieTrigger_Done
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_RadioTower_5F_EventScript_MarnieScene

GoldenrodCity_RadioTower_5F_EventScript_MarnieTrigger_Done::
	end

GoldenrodCity_RadioTower_5F_EventScript_MarnieScene::
	setvar VAR_LAST_TALKED, LOCALID_GOLDENROD_RADIO_5F_MARNIE
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Marnie
	msgbox GoldenrodCity_RadioTower_5F_Text_Marnie_Broadcast, MSGBOX_DEFAULT
	message GoldenrodCity_RadioTower_5F_Text_Marnie_BroadcastEnded
	waitbuttonpress
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIO_5F_MARNIE, Common_Movement_ExclamationMark
	waitmovement 0
	switch VAR_0x8004
	case 0, GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_TurnLeft
	case 1, GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_TurnDown
	case 2, GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_TurnDown

GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_TurnLeft:
	turnobject LOCALID_GOLDENROD_RADIO_5F_MARNIE, DIR_WEST
	goto GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_Speak

GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_TurnDown:
	turnobject LOCALID_GOLDENROD_RADIO_5F_MARNIE, DIR_SOUTH

GoldenrodCity_RadioTower_5F_EventScript_MarnieScene_Speak:
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Marnie
	msgbox GoldenrodCity_RadioTower_5F_Text_Marnie_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GOLDENROD_RADIO_MARNIE, GoldenrodCity_RadioTower_5F_Text_Marnie_Seen, GoldenrodCity_RadioTower_5F_Text_Marnie_Defeat, GoldenrodCity_RadioTower_5F_EventScript_Marnie_After
	end

GoldenrodCity_RadioTower_5F_EventScript_Marnie_After::
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Marnie
	msgbox GoldenrodCity_RadioTower_5F_Text_Marnie_AfterBattle, MSGBOX_DEFAULT
	checkitem ITEM_CARD_KEY_RADIOTOWER
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_5F_EventScript_Marnie_SkipGive
	giveitem ITEM_CARD_KEY_RADIOTOWER
GoldenrodCity_RadioTower_5F_EventScript_Marnie_SkipGive:
	msgbox GoldenrodCity_RadioTower_5F_Text_Marnie_GoodLuck, MSGBOX_DEFAULT
	switch VAR_0x8004
	case 1, GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitTrigger7
	goto GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitDefault

GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitTrigger7:
	applymovement LOCALID_GOLDENROD_RADIO_5F_MARNIE, GoldenrodCity_RadioTower_5F_Movement_MarnieExitTrigger7
	goto GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitDone

GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitDefault:
	applymovement LOCALID_GOLDENROD_RADIO_5F_MARNIE, GoldenrodCity_RadioTower_5F_Movement_MarnieExitDefault

GoldenrodCity_RadioTower_5F_EventScript_Marnie_ExitDone:
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_MARNIE
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_MARNIE, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_MARNIE
	releaseall
	end

GoldenrodCity_RadioTower_5F_EventScript_Venus::
	checktrainerflag TRAINER_VENUS
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_Venus_Done
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_RadioTower_5F_EventScript_VenusScene

GoldenrodCity_RadioTower_5F_EventScript_VenusTriggerRight::
	checktrainerflag TRAINER_VENUS
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_Venus_Done
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_RadioTower_5F_EventScript_VenusScene

GoldenrodCity_RadioTower_5F_EventScript_VenusTriggerLeft::
	checktrainerflag TRAINER_VENUS
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_Venus_Done
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_RadioTower_5F_EventScript_VenusScene

GoldenrodCity_RadioTower_5F_EventScript_Venus_Done::
	end

GoldenrodCity_RadioTower_5F_EventScript_VenusScene::
	setvar VAR_LAST_TALKED, LOCALID_GOLDENROD_RADIO_5F_VENUS
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_LiveCheck, MSGBOX_DEFAULT
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Cameraman
	msgbox GoldenrodCity_RadioTower_5F_Text_Cameraman_PracticeRun, MSGBOX_DEFAULT
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_UghFine, MSGBOX_DEFAULT
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_PracticeSpeech, MSGBOX_DEFAULT
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_Ready, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIO_5F_VENUS, GoldenrodCity_RadioTower_5F_Movement_VenusSpinFast
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIO_5F_VENUS, GoldenrodCity_RadioTower_5F_Movement_VenusDoubleExclamation
	waitmovement 0
	switch VAR_0x8004
	case 0, GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnToPlayer
	case 1, GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnRight
	case 2, GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnLeft

GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnRight:
	turnobject LOCALID_GOLDENROD_RADIO_5F_VENUS, DIR_EAST
	goto GoldenrodCity_RadioTower_5F_EventScript_Venus_Speak

GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnLeft:
	turnobject LOCALID_GOLDENROD_RADIO_5F_VENUS, DIR_WEST
	goto GoldenrodCity_RadioTower_5F_EventScript_Venus_Speak

GoldenrodCity_RadioTower_5F_EventScript_Venus_TurnToPlayer:
	faceplayer

GoldenrodCity_RadioTower_5F_EventScript_Venus_Speak:
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_double TRAINER_VENUS, GoldenrodCity_RadioTower_5F_Text_Venus_Seen, GoldenrodCity_RadioTower_5F_Text_Venus_Defeat, GoldenrodCity_RadioTower_5F_Text_Venus_NotEnoughMons, GoldenrodCity_RadioTower_5F_EventScript_Venus_Outro
	end

GoldenrodCity_RadioTower_5F_EventScript_Venus_Outro::
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Venus
	msgbox GoldenrodCity_RadioTower_5F_Text_Venus_Outro, MSGBOX_DEFAULT
	closemessage
	goto GoldenrodCity_RadioTower_5F_EventScript_Venus_Remove
	end

GoldenrodCity_RadioTower_5F_EventScript_Venus_Remove::
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_GOODRA
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_GOODRA, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_GOODRA
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUSAUR
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUSAUR, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUSAUR
	clearflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	addobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setobjectsubpriority LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F, 0
	setobjectsubpriority LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F, 1
	showobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setvar VAR_0x8004, LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	setvar VAR_0x8001, 11
	setvar VAR_0x8002, 10
	special Special_HoopaRingSpawnGrow
	waitstate
	setvar VAR_0x8000, LOCALID_GOLDENROD_RADIO_5F_VENUS
	special Special_ObjectEventAbsorb
	waitstate
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_VENUS
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_VENUS, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	removeobject LOCALID_GOLDENROD_RADIO_5F_VENUS
	setvar VAR_0x8004, LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING, MAP_GOLDENROD_CITY_RADIO_TOWER_5F
	setflag FLAG_HIDE_GOLDENROD_RADIO_5F_HOOPA_RING
	removeobject LOCALID_GOLDENROD_RADIO_5F_HOOPA_RING
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Grunt1::
	lock
	faceplayer
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Grunt1
	msgbox GoldenrodCity_RadioTower_5F_Text_Grunt1, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Cameraman::
	lock
	faceplayer
	setspeaker GoldenrodCity_RadioTower_5F_Speaker_Cameraman
	msgbox GoldenrodCity_RadioTower_5F_Text_Cameraman, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_5F_Text_Venus_Intro:
	.string "So you're the intruder who forced\n"
	.string "their way up here.\p"
	.string "How bold of you to step right into\n"
	.string "my spotlight.\p"
	.string "You just had to wander in while I\n"
	.string "was preparing to introduce Johto to\l"
	.string "its future.\p"
	.string "This city needs someone glamorous,\n"
	.string "someone decisive, someone strong\l"
	.string "enough to make people obey.\p"
	.string "That someone is me.\n"
	.string "I am Lady Venus, and when Cipher\l"
	.string "is finished here, Johto will answer\l"
	.string "to my every word.\p"
	.string "If you want to challenge that,\n"
	.string "then prove you are more than just\l"
	.string "another inconvenience.$"

GoldenrodCity_RadioTower_5F_Text_Venus_LiveCheck:
	.string "Are we live yet?!$"

GoldenrodCity_RadioTower_5F_Text_Cameraman_PracticeRun:
	.string "Not yet Lady Venus, we should do a\n"
	.string "practice run to make sure you have\l"
	.string "your lines.$"

GoldenrodCity_RadioTower_5F_Text_Venus_UghFine:
	.string "Ugh, fine.$"

GoldenrodCity_RadioTower_5F_Text_Venus_PracticeSpeech:
	.string "People of Goldenrod, look closely\n"
	.string "at the city below and remember this\l"
	.string "moment.\p"
	.string "When Cipher tightens its grip around\n"
	.string "Johto, you will say you witnessed\l"
	.string "the rise of the woman who took\l"
	.string "control.\p"
	.string "I will be the new leader in charge\n"
	.string "of this region, and Goldenrod will\l"
	.string "become the jewel in my empire.\p"
	.string "Every broadcast, every street, every\n"
	.string "citizen will hear my voice and know\l"
	.string "exactly who rules Johto now.$"

GoldenrodCity_RadioTower_5F_Text_Venus_Ready:
	.string "Okay! I am ready!$"

GoldenrodCity_RadioTower_5F_Text_Venus_Seen:
	.string "Let's see how long your confidence lasts.$"

GoldenrodCity_RadioTower_5F_Text_Venus_Defeat:
	.string "Irritating.$"

GoldenrodCity_RadioTower_5F_Text_Venus_NotEnoughMons:
	.string "You're not ready for me. Bring at\n"
	.string "least two POKeMON.$"

GoldenrodCity_RadioTower_5F_Text_Venus_Outro:
	.string "A city only needs one weak point.\n"
	.string "We'll find Goldenrod's soon enough.\p"
	.string "Until then, try not to blink.\n"
	.string "You might miss me.$"

GoldenrodCity_RadioTower_5F_Text_Grunt1:
	.string "You should not be here.\n"
	.string "But since you've made it this far,\l"
	.string "Lady Venus will handle you.$"

GoldenrodCity_RadioTower_5F_Text_Cameraman:
	.string "Lady Venus is paying me a lot of\n"
	.string "money to record her broadcast.\p"
	.string "I know it isn't right, but I've got\n"
	.string "bills to pay.$"

GoldenrodCity_RadioTower_5F_Text_Marnie_Broadcast:
	.string "People of Goldenrod, people all over\n"
	.string "the world, if you're hearing my voice\l"
	.string "right now then you're hearing the\l"
	.string "warning of impending world\l"
	.string "domination.\p"
	.string "Cipher has successfully obtained\l"
	.string "control of everything that can\l"
	.string "possibly try to halt us. We have\l"
	.string "successfully taken control of the\l"
	.string "Radio Tower as well as Silph Co.\p"
	.string "It won't be long before Mosdeep's\l"
	.string "Space Station is ours as well.\l"
	.string "Know there is nowhere to run.\l"
	.string "There is nowhere to hide.\p"
	.string "Shadow POKeMON are here to take\l"
	.string "over. We are your worst nightmare.\l"
	.string "We, are Cipher.$"

GoldenrodCity_RadioTower_5F_Text_Marnie_BroadcastEnded:
	.string "Broadcast has ended.$"

GoldenrodCity_RadioTower_5F_Text_Marnie_Intro:
	.string "How did you get in here!?\n"
	.string "Those good-for-nothing grunts are\l"
	.string "so weak, they don't even deserve\l"
	.string "to represent the Cipher name.\p"
	.string "I take it you heard my speech,\n"
	.string "pretty solid, no? I meant every\l"
	.string "last word.\p"
	.string "You see I used to be a member of\n"
	.string "a team full of nobodies. They were\l"
	.string "so weak, so boring.\p"
	.string "Then Lady Venus found me when I\n"
	.string "was brought into this bizarre\l"
	.string "timeline and she showed me\l"
	.string "everything I needed to know to\l"
	.string "be strong.\p"
	.string "Unfortunately for you, that means\n"
	.string "you will BOW TO THE ALMIGHTY\l"
	.string "MARNIE!$"

GoldenrodCity_RadioTower_5F_Text_Marnie_Seen:
	.string "BOW TO THE ALMIGHTY MARNIE!$"

GoldenrodCity_RadioTower_5F_Text_Marnie_Defeat:
	.string "No! This isn't how my big moment\n"
	.string "was supposed to go!$"

GoldenrodCity_RadioTower_5F_Text_Marnie_AfterBattle:
	.string "I underestimated you greatly.\n"
	.string "No matter, even if you're slightly\l"
	.string "stronger than me, you'll never be\l"
	.string "able to defeat Lady Venus.\p"
	.string "I'll even give you the CARD KEY to\n"
	.string "get to her. See if you can handle\l"
	.string "her strength.$"

GoldenrodCity_RadioTower_5F_Text_Marnie_GoodLuck:
	.string "Good luck, loser.$"

GoldenrodCity_RadioTower_5F_Movement_MarnieExitDefault:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_MarnieExitTrigger7:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_VenusSpinFast:
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	step_end

GoldenrodCity_RadioTower_5F_Movement_VenusDoubleExclamation:
	emote_double_exclamation_mark
	step_end
