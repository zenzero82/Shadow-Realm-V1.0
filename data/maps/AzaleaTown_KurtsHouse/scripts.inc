AzaleaTown_KurtsHouse_MapScripts::
	.byte 0

.set LOCALID_KURT, 1
.set LOCALID_MARAUDER, 2

AzaleaTown_KurtsHouse_Speaker_Kurt:
	.string "KURT$"

AzaleaTown_KurtsHouse_EventScript_Kurt::
	faceplayer
	setspeaker AzaleaTown_KurtsHouse_Speaker_Kurt
	msgbox AzaleaTown_KurtsHouse_Text_Kurt, MSGBOX_NPC
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
	waitmovement 0
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	trainerbattle_single TRAINER_KURTS_HOUSE_IRONMASK, AzaleaTown_KurtsHouse_Text_IronMask_Intro, AzaleaTown_KurtsHouse_Text_IronMask_Defeat, AzaleaTown_KurtsHouse_EventScript_Marauder_After
	end

AzaleaTown_KurtsHouse_EventScript_MarauderScene_Done::
	end

AzaleaTown_KurtsHouse_EventScript_Marauder_After::
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
	checkflag FLAG_QUEST_KURT_APRICOT_STARTED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestDone
	checkflag FLAG_QUEST_KURT_APRICOT_COMPLETED
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Marauder_KurtQuestDone
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
	.string "A team will be dispatching them\n"
	.string "around KANTO, JOHTO, and HOENN soon.$"

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
	.string "around KANTO, JOHTO, and HOENN soon.$"

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
