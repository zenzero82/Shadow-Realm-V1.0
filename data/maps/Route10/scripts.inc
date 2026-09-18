Route10_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route10_EventScript_SetZanderVisibility
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_EventScript_SetZanderVisibility
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route10_MapScripts_OnFrame
	.byte 0

Route10_MapScripts_OnFrame:
	map_script_2 VAR_TEMP_0, 1, Route10_EventScript_PlasmaGrunt_Auto
	map_script_2 VAR_TEMP_0, 2, Route10_EventScript_SycamoreCall_Auto
	.2byte 0

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_SetZanderVisibility::
	setvar VAR_TEMP_0, 0
	call Route10_EventScript_SetZinzolinVisibility
	call Route10_EventScript_SyncPowerPlantRocket
	checkflag FLAG_ROUTE_24_ZANDER_DEFEATED
	goto_if_eq Route10_EventScript_SetZanderVisibility_Done
	checkflag FLAG_HAS_SNAG_MACHINE
	goto_if_eq Route10_EventScript_ShowZander
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_ShowZander::
	clearflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_SetZanderVisibility_Done::
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	call Route10_EventScript_TryPlasmaExit
	end

Route10_EventScript_SetZinzolinVisibility::
	checktrainerflag TRAINER_ZINZOLIN_POWER_PLANT
	goto_if_eq Route10_EventScript_SetZinzolinVisibility_Hide
	setflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto Route10_EventScript_SetZinzolinVisibility_Show

Route10_EventScript_SetZinzolinVisibility_Hide:
	clearflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	setflag FLAG_HIDE_ROUTE10_ZINZOLIN
	hideobjectat LOCALID_ROUTE10_ZINZOLIN, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_ZINZOLIN
	call Route10_EventScript_TryQueueSycamoreCall
Route10_EventScript_SetZinzolinVisibility_Done::
	return

Route10_EventScript_SetZinzolinVisibility_Show::
	clearflag FLAG_ROUTE10_SYCAMORE_CALL_DONE
	clearflag FLAG_QUEST_MEGA_MOMENTS_STARTED
	clearflag FLAG_QUEST_MEGA_MOMENTS_COMPLETED
	clearflag FLAG_HIDE_ROUTE10_ZINZOLIN
	addobject LOCALID_ROUTE10_ZINZOLIN
	showobjectat LOCALID_ROUTE10_ZINZOLIN, MAP_ROUTE10
	return

Route10_EventScript_TryQueueSycamoreCall:
	checkflag FLAG_ROUTE10_SYCAMORE_CALL_DONE
	goto_if_eq Route10_EventScript_TryQueueSycamoreCall_Done
	setvar VAR_TEMP_0, 2
Route10_EventScript_TryQueueSycamoreCall_Done:
	return

Route10_EventScript_SyncPowerPlantRocket::
	checkflag FLAG_QUEST_BACK_TO_HQ_COMPLETED
	goto_if_eq Route10_EventScript_SyncPowerPlantRocket_Hide
	clearflag FLAG_HIDE_ROUTE10_POWERPLANT_ROCKET_GRUNT
	return

Route10_EventScript_SyncPowerPlantRocket_Hide::
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_ROCKET_GRUNT
	return

Route10_EventScript_TryPlasmaExit::
	checkflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	goto_if_eq Route10_EventScript_TryPlasmaExit_Done
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	goto_if_ne VAR_TEMP_1, 16, Route10_EventScript_TryPlasmaExit_Done
	goto_if_ne VAR_TEMP_2, 57, Route10_EventScript_TryPlasmaExit_Done
	setvar VAR_TEMP_0, 1
Route10_EventScript_TryPlasmaExit_Done::
	return

Route10_EventScript_PlasmaGrunt::
	lock
	faceplayer
	setspeaker Route10_Speaker_PlasmaGrunt
	msgbox Route10_Text_PlasmaGrunt_Exit, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	goto_if_eq Route10_EventScript_PlasmaGrunt_CompleteQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_PlasmaGrunt_CompleteQuest_Done:
	applymovement LOCALID_PLAYER, Route10_Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_ROUTE10_PLASMA_GRUNT, Route10_Movement_PlasmaEnterCave
	waitmovement 0
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	release
	end

Route10_EventScript_PlasmaGrunt_Auto::
	setvar VAR_TEMP_0, 0
	lockall
	faceplayer
	setspeaker Route10_Speaker_PlasmaGrunt
	msgbox Route10_Text_PlasmaGrunt_Exit, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	goto_if_eq Route10_EventScript_PlasmaGrunt_Auto_CompleteQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_PlasmaGrunt_Auto_CompleteQuest_Done:
	applymovement LOCALID_PLAYER, Route10_Movement_PlayerStepLeft
	waitmovement 0
	applymovement LOCALID_ROUTE10_PLASMA_GRUNT, Route10_Movement_PlasmaEnterCave
	waitmovement 0
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	releaseall
	end

Route10_EventScript_Zinzolin::
	setspeaker Route10_Speaker_Zinzolin
	trainerbattle_single TRAINER_ZINZOLIN_POWER_PLANT, Route10_Text_Zinzolin_Intro, Route10_Text_Zinzolin_Defeat, Route10_EventScript_Zinzolin_After
	goto Route10_EventScript_Zinzolin_After
	end

Route10_EventScript_HoopaRing::
	end

Route10_EventScript_PowerPlantRocketGrunt::
	lock
	checkflag FLAG_QUEST_BACK_TO_HQ_COMPLETED
	goto_if_eq Route10_EventScript_PowerPlantRocketGrunt_Gone
	setspeaker Route10_Speaker_PowerPlantRocketGrunt
	msgbox Route10_Text_PowerPlantRocketGrunt_SelfTalk, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	setspeaker Route10_Speaker_PowerPlantRocketGrunt
	msgbox Route10_Text_PowerPlantRocketGrunt_PlayerCaught, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Route10_EventScript_PowerPlantRocketGrunt_Gone:
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_ROCKET_GRUNT
	release
	end

Route10_EventScript_Zinzolin_After::
	settrainerflag TRAINER_ZINZOLIN_POWER_PLANT
	setspeaker Route10_Speaker_Zinzolin
	msgbox Route10_Text_Zinzolin_After, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROUTE10_HOOPA_RING
	addobject LOCALID_ROUTE10_HOOPA_RING
	hideobjectat LOCALID_ROUTE10_HOOPA_RING, MAP_ROUTE10
	setobjectsubpriority LOCALID_ROUTE10_ZINZOLIN, MAP_ROUTE10, 0
	setobjectsubpriority LOCALID_ROUTE10_HOOPA_RING, MAP_ROUTE10, 1
	showobjectat LOCALID_ROUTE10_HOOPA_RING, MAP_ROUTE10
	setvar VAR_0x8004, LOCALID_ROUTE10_HOOPA_RING
	setvar VAR_0x8001, 4
	setvar VAR_0x8002, 35
	special Special_HoopaRingSpawnGrow
	waitstate
	setvar VAR_0x8000, LOCALID_ROUTE10_ZINZOLIN
	special Special_ObjectEventAbsorb
	waitstate
	hideobjectat LOCALID_ROUTE10_ZINZOLIN, MAP_ROUTE10
	setflag FLAG_HIDE_ROUTE10_ZINZOLIN
	removeobject LOCALID_ROUTE10_ZINZOLIN
	clearflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	setflag FLAG_HIDE_ROCK_TUNNEL_PLASMA
	hideobjectat LOCALID_ROUTE10_PLASMA_GRUNT, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_PLASMA_GRUNT
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_1
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_2
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_3
	setvar VAR_0x8004, LOCALID_ROUTE10_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_ROUTE10_HOOPA_RING, MAP_ROUTE10
	setflag FLAG_HIDE_ROUTE10_HOOPA_RING
	removeobject LOCALID_ROUTE10_HOOPA_RING
	checkflag FLAG_QUEST_THUNDERBIRD_COMPLETED
	goto_if_eq Route10_EventScript_ThunderbirdQuestDone
	call Route10_EventScript_CompleteThunderbirdQuest
Route10_EventScript_ThunderbirdQuestDone:
	call Route10_EventScript_SycamoreCall
	releaseall
	end

Route10_EventScript_CompleteThunderbirdQuest:
	setflag FLAG_QUEST_THUNDERBIRD_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
	return

Route10_EventScript_SycamoreCall_Auto::
	setvar VAR_TEMP_0, 0
	lockall
	call Route10_EventScript_SycamoreCall
	releaseall
	end

Route10_EventScript_SycamoreCall:
	checkflag FLAG_ROUTE10_SYCAMORE_CALL_DONE
	goto_if_eq Route10_EventScript_SycamoreCall_Done
	playfanfare MUS_REGISTER_MATCH_CALL
	setspeaker Route10_Speaker_Sycamore
	pokenavcall Route10_Text_Sycamore_Call
	waitmessage
	closemessage
	setflag FLAG_ROUTE10_SYCAMORE_CALL_DONE
	clearflag FLAG_QUEST_MEGA_MOMENTS_COMPLETED
	setflag FLAG_QUEST_MEGA_MOMENTS_STARTED
	checkflag FLAG_QUEST_ERICA_STARTED
	goto_if_eq Route10_EventScript_SycamoreCall_OneNewQuest
	setflag FLAG_QUEST_ERICA_STARTED
	call QuestJournal_EventScript_NewQuestsAlert
	return

Route10_EventScript_SycamoreCall_OneNewQuest:
	call QuestJournal_EventScript_NewQuestAlert
Route10_EventScript_SycamoreCall_Done:
	return

Route10_Speaker_Zander:
	.string "Zander$"

Route10_EventScript_Zander::
	checkflag FLAG_HIDE_ROUTE_24_ZANDER
	goto_if_eq Route10_EventScript_Zander_Done

	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker Route10_Speaker_Zander
	msgbox Route10_Text_Zander_Intro, MSGBOX_DEFAULT
	closemessage

	trainerbattle_no_intro TRAINER_ROCKET_GRUNT_M_1, Route10_Text_Zander_Defeated
	goto Route10_EventScript_Zander_AfterBattle

Route10_EventScript_Zander_AfterBattle::
	setspeaker Route10_Speaker_Zander
	msgbox Route10_Text_Zander_PostBattle, MSGBOX_DEFAULT
	closemessage
	checkflag FLAG_QUEST_PLASMA_TUNNEL_STARTED
	goto_if_eq Route10_EventScript_Zander_StartPlasmaQuest_Done
	setflag FLAG_QUEST_PLASMA_TUNNEL_STARTED
	call QuestJournal_EventScript_NewQuestAlert
Route10_EventScript_Zander_StartPlasmaQuest_Done:
	setflag FLAG_ROUTE_24_ZANDER_DEFEATED
	checkflag FLAG_QUEST_SHADOW_TRAINER_COMPLETED
	goto_if_eq Route10_EventScript_Zander_QuestDone
	checkflag FLAG_QUEST_SHADOW_TRAINER_STARTED
	goto_if_eq Route10_EventScript_Zander_QuestComplete
	goto Route10_EventScript_Zander_QuestDone
Route10_EventScript_Zander_QuestComplete:
	setflag FLAG_QUEST_SHADOW_TRAINER_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
Route10_EventScript_Zander_QuestDone:
	setflag FLAG_HIDE_ROUTE_24_ZANDER
	fadescreenswapbuffers FADE_TO_BLACK
	hideobjectat LOCALID_ROUTE10_ZANDER, MAP_ROUTE10
	removeobject LOCALID_ROUTE10_ZANDER
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

Route10_EventScript_Zander_Done::
	end

Route10_Movement_PlayerStepLeft:
	walk_left
	step_end

Route10_Movement_PlasmaEnterCave:
	walk_up
	walk_up
	step_end

Route10_Speaker_PlasmaGrunt:
	.string "FAYE$"

Route10_Speaker_Zinzolin:
	.string "ZINZOLIN$"

Route10_Speaker_Sycamore:
	.string "Prof. Sycamore$"

Route10_Speaker_PowerPlantRocketGrunt:
	.string "ROCKET GRUNT$"

Route10_Text_PlasmaGrunt_Exit:
	.string "Out of my way! I need to let the\n"
	.string "others know a really strong trainer\l"
	.string "is about to crush us!\p"
	.string "...Wait, you already defeated them?\p"
	.string "...This is so sad...\n"
	.string "Now I have to tell the Sages.\p"
	.string "MOVE!$"

Route10_Text_PowerPlantRocketGrunt_SelfTalk:
	.string "Heh... helping swipe those starter\n"
	.string "POKéMON was easy enough.\p"
	.string "Once the survey's done, this old\n"
	.string "POWER PLANT is next on the list.$"

Route10_Text_PowerPlantRocketGrunt_PlayerCaught:
	.string "What!? How long have you been\n"
	.string "standing there!?\p"
	.string "Get lost, we're in the middle of a\n"
	.string "survey here.$"

@ ======================
@ TEXT – ZANDER
@ ======================

Route10_Text_Zander_Intro:
	.string "Perfect! I was just thinking to\n"
	.string "myself about stomping a twerp haha.$"

Route10_Text_Zander_Defeated:
	.string "You beat me, but {COLOR BLUE}Shadow POKéMON{COLOR WHITE}\n"
	.string "won't leave our side yet.\p"
	.string "You're stepping into\n"
	.string "deep water, kid.$"

Route10_Text_Zander_PostBattle:
	.string "Our associates have taken over\n"
	.string "Rock Tunnel. You're going to have a\l"
	.string "real tough time getting\l"
	.string "through there.$"

Route10_Text_Zinzolin_Intro:
	.string "You're too late. The THUNDERBIRD\n"
	.string "has already been secured.\p"
	.string "Now, allow me to test your skill\n"
	.string "in battle.$"

Route10_Text_Zinzolin_Defeat:
	.string "Hmph... perhaps you're more capable\n"
	.string "than I assumed.$"

Route10_Text_Zinzolin_After:
	.string "Enjoy your fleeting victory.\n"
	.string "TEAM PLASMA's plans are inevitable.$"

Route10_Text_Sycamore_Call:
	.string "Hey {PLAYER}, I know you're busy\n"
	.string "hunting down the Legendaries right\l"
	.string "now but I just heard from\l"
	.string "Calem and Serena and it sounds\l"
	.string "like they'll be around Celadon City\l"
	.string "soon.\p"
	.string "Maybe you should drop by. Heck,\n"
	.string "you can even challenge Erica to a\l"
	.string "battle to see if you got what\l"
	.string "it takes!$"

Route10_Text_PowerPlant:
	.string "POWER PLANT$"

Route10_Text_Sign:
	.string "ROUTE 10\p"
	.string "CERULEAN CITY - LAVENDER TOWN$"
