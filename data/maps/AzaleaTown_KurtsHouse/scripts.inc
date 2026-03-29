AzaleaTown_KurtsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, AzaleaTown_KurtsHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

.set LOCALID_KURT, 1
.set LOCALID_MARAUDER, 2
.set LOCALID_SKARMORY, 3

AzaleaTown_KurtsHouse_OnLoad::
	goto AzaleaTown_KurtsHouse_OnTransition

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_set FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE, AzaleaTown_KurtsHouse_OnTransition_MarauderDone
	goto_if_set FLAG_HIDE_KURTS_HOUSE_SKARMORY, AzaleaTown_KurtsHouse_OnTransition_HideSkarmory
	end

AzaleaTown_KurtsHouse_OnTransition_HideSkarmory:
	hideobjectat LOCALID_SKARMORY, MAP_AZALEA_TOWN_KURTS_HOUSE
	removeobject LOCALID_SKARMORY
	end

AzaleaTown_KurtsHouse_OnTransition_MarauderDone:
	hideobjectat LOCALID_SKARMORY, MAP_AZALEA_TOWN_KURTS_HOUSE
	removeobject LOCALID_SKARMORY
	setobjectmovementtype LOCALID_KURT, MOVEMENT_TYPE_FACE_UP
	turnobject LOCALID_KURT, DIR_NORTH
	compare VAR_KURT_ORDER_STATE, 1
	goto_if_eq AzaleaTown_KurtsHouse_OnTransition_SetOrderReady
	end

AzaleaTown_KurtsHouse_OnTransition_SetOrderReady:
	setvar VAR_KURT_ORDER_STATE, 2
	end

AzaleaTown_KurtsHouse_Speaker_Kurt:
	.string "KURT$"

AzaleaTown_KurtsHouse_EventScript_Kurt::
	faceplayer
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	goto_if_set FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE, AzaleaTown_KurtsHouse_EventScript_Kurt_Apricorn
	msgbox AzaleaTown_KurtsHouse_Text_Kurt, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_KURTS_HOUSE_KURT
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_KurtsHouse_EventScript_Kurt_Apricorn:
	compare VAR_KURT_ORDER_STATE, 2
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Kurt_OrderReady
	compare VAR_KURT_ORDER_STATE, 1
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Kurt_OrderPending
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_ApricornIntro, MSGBOX_NPC
	special Special_KurtApricornMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_OrderPlaced, MSGBOX_NPC
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd

AzaleaTown_KurtsHouse_EventScript_Kurt_OrderReady:
	checkitemspace VAR_KURT_ORDER_ITEM, VAR_KURT_ORDER_COUNT
	goto_if_eq VAR_RESULT, 0, AzaleaTown_KurtsHouse_EventScript_Kurt_OrderNoSpace
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_OrderReady, MSGBOX_NPC
	giveitem VAR_KURT_ORDER_ITEM, VAR_KURT_ORDER_COUNT
	setvar VAR_KURT_ORDER_STATE, 0
	setvar VAR_KURT_ORDER_ITEM, 0
	setvar VAR_KURT_ORDER_COUNT, 0
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd

AzaleaTown_KurtsHouse_EventScript_Kurt_OrderNoSpace:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_OrderNoSpace, MSGBOX_NPC
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd

AzaleaTown_KurtsHouse_EventScript_Kurt_OrderPending:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_OrderPending, MSGBOX_NPC
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornEnd:
	setflag FLAG_QUEST_AZALEA_NPC_KURTS_HOUSE_KURT
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_KurtsHouse_Speaker_IronMask:
	.string "MARAUDER$"

AzaleaTown_KurtsHouse_EventScript_IronMask::
	goto AzaleaTown_KurtsHouse_EventScript_MarauderScene

AzaleaTown_KurtsHouse_EventScript_MarauderScene::
	goto_if_set FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE, AzaleaTown_KurtsHouse_EventScript_MarauderScene_Done
	lockall
	setvar VAR_TEMP_0, 1

	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	msgbox AzaleaTown_KurtsHouse_Text_Marauder_Demand1, MSGBOX_NPC
	closemessage
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_Refuse1, MSGBOX_NPC
	closemessage
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	msgbox AzaleaTown_KurtsHouse_Text_Marauder_Demand2, MSGBOX_NPC
	closemessage
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_Refuse2, MSGBOX_NPC
	closemessage

	playse SE_PIN
	applymovement LOCALID_MARAUDER, AzaleaTown_KurtsHouse_Movement_Marauder_ExclaimFaceDown
	applymovement LOCALID_SKARMORY, AzaleaTown_KurtsHouse_Movement_Skarmory_ExclaimFaceDown
	waitmovement 0
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	trainerbattle_single TRAINER_KURTS_HOUSE_IRONMASK, AzaleaTown_KurtsHouse_Text_IronMask_Intro, AzaleaTown_KurtsHouse_Text_IronMask_Defeat, AzaleaTown_KurtsHouse_EventScript_Marauder_After
	end

AzaleaTown_KurtsHouse_EventScript_MarauderScene_Done::
	end

AzaleaTown_KurtsHouse_EventScript_Marauder_After::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, AzaleaTown_KurtsHouse_EventScript_MarauderScene_Done
	setflag FLAG_HIDE_KURTS_HOUSE_SKARMORY
	hideobjectat LOCALID_SKARMORY, MAP_AZALEA_TOWN_KURTS_HOUSE
	removeobject LOCALID_SKARMORY
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	msgbox AzaleaTown_KurtsHouse_Text_IronMask_After, MSGBOX_NPC
	closemessage

	special StorePlayerCoordsInVars
	goto_if_eq VAR_0x8004, 16, AzaleaTown_KurtsHouse_EventScript_MarauderExitLeft
	applymovement LOCALID_MARAUDER, AzaleaTown_KurtsHouse_Movement_MarauderExitRight
	waitmovement 0
	goto AzaleaTown_KurtsHouse_EventScript_MarauderExitDone

AzaleaTown_KurtsHouse_EventScript_MarauderExitLeft::
	applymovement LOCALID_MARAUDER, AzaleaTown_KurtsHouse_Movement_MarauderExitLeft
	waitmovement 0

AzaleaTown_KurtsHouse_EventScript_MarauderExitDone::
	playse SE_EXIT
	hideobjectat LOCALID_MARAUDER, MAP_AZALEA_TOWN_KURTS_HOUSE
	removeobject LOCALID_MARAUDER

	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_Thanks, MSGBOX_NPC
	closemessage
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_CipherInfo, MSGBOX_NPC
	closemessage
	giveitem ITEM_DARK_BALL, 15
	turnobject LOCALID_PLAYER, DIR_NORTH
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_DarkBalls, MSGBOX_NPC
	closemessage
	checkflag FLAG_QUEST_KURT_APRICOT_COMPLETED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestDone
	checkflag FLAG_QUEST_KURT_APRICOT_STARTED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestMarkComplete
	setflag FLAG_QUEST_KURT_APRICOT_STARTED
AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestMarkComplete:
	setflag FLAG_QUEST_KURT_APRICOT_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestDone:
	checkflag FLAG_QUEST_DEFEAT_BUGSY_STARTED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_BugsyQuestDone
	checkflag FLAG_QUEST_DEFEAT_BUGSY_COMPLETED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_BugsyQuestDone
	setflag FLAG_QUEST_DEFEAT_BUGSY_STARTED
	call QuestJournal_EventScript_NewQuestAlert
AzaleaTown_KurtsHouse_EventScript_Marauder_BugsyQuestDone:
	setflag FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE
	setflag FLAG_HIDE_AZALEA_AQUA_GRUNTS
	clearflag FLAG_HIDE_AZALEA_ILEX_OFFICER
	releaseall
	end

AzaleaTown_KurtsHouse_Text_IronMask_Intro:
	.string "Who are you?\p"
	.string "Get out of my way, kid.$"

AzaleaTown_KurtsHouse_Text_IronMask_Defeat:
	.string "So this is JOHTO's spirit...$"

AzaleaTown_KurtsHouse_Text_IronMask_After:
	.string "...tch.$"

AzaleaTown_KurtsHouse_Text_Marauder_Demand1:
	.string "Hand over the blueprints and the\n"
	.string "DARK BALL stock. Now.$"

AzaleaTown_KurtsHouse_Text_Kurt_Refuse1:
	.string "No. I don't answer to thieves.$"

AzaleaTown_KurtsHouse_Text_Marauder_Demand2:
	.string "Then I'll take them myself.$"

AzaleaTown_KurtsHouse_Text_Kurt_Refuse2:
	.string "Over my dead body.$"

AzaleaTown_KurtsHouse_Text_Kurt:
	.string "Take these 15 DARK BALLS.\p"
	.string "A team will be dispatching them\n"
	.string "around KANTO, JOHTO, and HOENN soon.\p"
	.string "I can also make more for you but they\n"
	.string "require APRICORNs to create them.\p"
	.string "There are many trees around Johto which\n"
	.string "can't be found anywhere else that have\l"
	.string "them.\p"
	.string "Be sure to come back here if you find\n"
	.string "APRICORNs along your journey.$"

AzaleaTown_KurtsHouse_Text_Kurt_Thanks:
	.string "Thank you for driving him off.$"

AzaleaTown_KurtsHouse_Text_Kurt_CipherInfo:
	.string "CIPHER learned I made DARK BALLS\n"
	.string "to counter the XD conversion.\p"
	.string "They make snagging shadow POKEMON\n"
	.string "easier, but they remove the effect\l"
	.string "that keeps their hearts closed.\p"
	.string "CIPHER can't allow that, so they\n"
	.string "want production stopped.$"

AzaleaTown_KurtsHouse_Text_Kurt_DarkBalls:
	.string "Take these 15 DARK BALLS.\p"
	.string "A team will be dispatching them\n"
	.string "around KANTO, JOHTO, and HOENN soon.\p"
	.string "I can also make more for you but they\n"
	.string "require APRICORNs to create them.\p"
	.string "There are many trees around Johto which\n"
	.string "can't be found anywhere else that have\l"
	.string "them.\p"
	.string "Be sure to come back here if you find\n"
	.string "APRICORNs along your journey.$"

AzaleaTown_KurtsHouse_Text_Kurt_ApricornIntro:
	.string "I can make POKéBALLS from APRICORNs.\p"
	.string "If you want me to make a DARK BALL,\n"
	.string "You'll need at least 1 of each APRICORN.\p"
	.string "Which BALL should I make?$"

AzaleaTown_KurtsHouse_Text_Kurt_OrderPlaced:
	.string "Got it. Come back later and\n"
	.string "they will be ready.$"

AzaleaTown_KurtsHouse_Text_Kurt_OrderReady:
	.string "Your order is finished. Here\n"
	.string "you go.$"

AzaleaTown_KurtsHouse_Text_Kurt_OrderPending:
	.string "I am still working on your\n"
	.string "order. Come back later.$"

AzaleaTown_KurtsHouse_Text_Kurt_OrderNoSpace:
	.string "Make some room in your BAG\n"
	.string "and come back.$"

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text, MSGBOX_SIGN
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text:
	.string "A mysterious statue.$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text, MSGBOX_SIGN
	end

AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text:
	.string "A photo of OAK.$"

@ =========================
@ MOVEMENTS
@ =========================

AzaleaTown_KurtsHouse_Movement_Marauder_ExclaimFaceDown:
	emote_exclamation_mark
	face_down
	step_end

AzaleaTown_KurtsHouse_Movement_Skarmory_ExclaimFaceDown:
	face_down
	step_end

AzaleaTown_KurtsHouse_Movement_MarauderExitRight:
	walk_right
	walk_down
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
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_KurtsHouse_Movement_MarauderExitLeft:
	walk_left
	walk_down
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
	walk_left
	step_end
