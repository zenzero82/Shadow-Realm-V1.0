Azalea_Town_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

#define LOCALID_AZALEA_AQUA_GRUNT_ILEX 4
#define LOCALID_AZALEA_AQUA_GRUNT_GYM 5
#define LOCALID_AZALEA_ILEX_OFFICER 6

Azalea_Town_Speaker_Youngster:
	.string "TIM$"

Azalea_Town_Speaker_Lass:
	.string "LUCY$"

Azalea_Town_Speaker_Rocket:
	.string "GRUNT$"

Azalea_Town_Speaker_Officer:
	.string "OFFICER$"

Azalea_Town_Speaker_Birch:
	.string "BIRCH$"

AzaleaTown_OnFrame:
	map_script_2 VAR_TEMP_1, 0, AzaleaTown_EventScript_CityEnter
	.2byte 0

AzaleaTown_EventScript_CityEnter::
	setvar VAR_TEMP_1, 1
	setflag FLAG_VISITED_AZALEA_TOWN
	checkflag FLAG_KURTS_HOUSE_MARAUDER_SCENE_DONE
	goto_if_eq AzaleaTown_EventScript_CityEnter_AfterMarauder
	clearflag FLAG_HIDE_AZALEA_AQUA_GRUNTS
	setflag FLAG_HIDE_AZALEA_ILEX_OFFICER
	goto AzaleaTown_EventScript_CityEnter_CheckOfficer
AzaleaTown_EventScript_CityEnter_AfterMarauder:
	setflag FLAG_HIDE_AZALEA_AQUA_GRUNTS
	clearflag FLAG_HIDE_AZALEA_ILEX_OFFICER
AzaleaTown_EventScript_CityEnter_CheckOfficer:
	checkflag FLAG_HIDE_ILEX_JJ_GROUP
	goto_if_eq AzaleaTown_EventScript_CityEnter_OfficerHidden
	goto AzaleaTown_EventScript_CityEnter_QuestStart
AzaleaTown_EventScript_CityEnter_OfficerHidden:
	setflag FLAG_HIDE_AZALEA_ILEX_OFFICER
AzaleaTown_EventScript_CityEnter_QuestStart:
	checkflag FLAG_QUEST_AZALEA_NPCS_STARTED
	goto_if_eq AzaleaTown_EventScript_CityEnter_QuestSkip
	checkflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	goto_if_eq AzaleaTown_EventScript_CityEnter_QuestSkip
	lockall
	setflag FLAG_QUEST_AZALEA_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
AzaleaTown_EventScript_CityEnter_QuestSkip:
	checkflag FLAG_AZALEA_BIRCH_CALL_AFTER_NEBBY_READY
	goto_if_ne AzaleaTown_EventScript_CityEnter_End
	checkflag FLAG_AZALEA_BIRCH_CALL_AFTER_GOLD_DONE
	goto_if_eq AzaleaTown_EventScript_CityEnter_End
	setflag FLAG_AZALEA_BIRCH_CALL_AFTER_GOLD_DONE
	setspeaker Azalea_Town_Speaker_Birch
	pokenavcall AzaleaTown_Text_Birch_CallAfterGold
	waitmessage
	closemessage
AzaleaTown_EventScript_CityEnter_End:
	end


__stub_Azalea_Town::
	end


AzaleaTown_EventScript_GymSign::
	msgbox AzaleaTown_EventScript_GymSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_GymSign_Text:
	.string "AZALEA TOWN\n"
	.string "POKéMON GYM\p"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"

AzaleaTown_EventScript_KurtSign::
	msgbox AzaleaTown_EventScript_KurtSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtSign_Text:
	.string "KURT'S HOUSE.$"

AzaleaTown_EventScript_IlexSign::
	msgbox AzaleaTown_EventScript_IlexSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_IlexSign_Text:
	.string "ILEX FOREST AHEAD.$"

AzaleaTown_EventScript_KilnSign::
	msgbox AzaleaTown_EventScript_KilnSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KilnSign_Text:
	.string "KURT'S CHARCOAL KILN.$"

AzaleaTown_EventScript_WellSign::
	msgbox AzaleaTown_EventScript_WellSign_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

AzaleaTown_EventScript_WellSign_Text:
	.string "SLOWPOKE WELL.$"

AzaleaTown_EventScript_AzaleaSign::
	msgbox AzaleaTown_EventScript_AzaleaSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_AzaleaSign_Text:
	.string "AZALEA TOWN\n"
	.string "Where People and POKéMON Live in\l"
	.string "Happy Harmony.$"

AzaleaTown_EventScript_LevelBallCache::
	lockall
	goto_if_set FLAG_ITEM_AZALEA_TOWN_LEVEL_BALL, AzaleaTown_EventScript_ItemCacheEmpty
	checkitemspace ITEM_LEVEL_BALL
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ItemCacheBagFull
	giveitem ITEM_LEVEL_BALL
	setflag FLAG_ITEM_AZALEA_TOWN_LEVEL_BALL
	releaseall
	end

AzaleaTown_EventScript_ApricornCache::
	lockall
	goto_if_set FLAG_ITEM_AZALEA_TOWN_APRICORN_SET, AzaleaTown_EventScript_ItemCacheEmpty
	additem ITEM_RED_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_BagFull
	additem ITEM_BLUE_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoRed
	additem ITEM_YELLOW_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoBlue
	additem ITEM_GREEN_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoYellow
	additem ITEM_PINK_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoGreen
	additem ITEM_WHITE_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoPink
	additem ITEM_BLACK_APRICORN
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_EventScript_ApricornCache_UndoWhite
	setflag FLAG_ITEM_AZALEA_TOWN_APRICORN_SET
	playfanfare MUS_OBTAIN_ITEM
	msgbox AzaleaTown_Text_FoundApricornSet, MSGBOX_DEFAULT
	waitfanfare
	releaseall
	end

AzaleaTown_EventScript_ApricornCache_UndoWhite:
	removeitem ITEM_WHITE_APRICORN
AzaleaTown_EventScript_ApricornCache_UndoPink:
	removeitem ITEM_PINK_APRICORN
AzaleaTown_EventScript_ApricornCache_UndoGreen:
	removeitem ITEM_GREEN_APRICORN
AzaleaTown_EventScript_ApricornCache_UndoYellow:
	removeitem ITEM_YELLOW_APRICORN
AzaleaTown_EventScript_ApricornCache_UndoBlue:
	removeitem ITEM_BLUE_APRICORN
AzaleaTown_EventScript_ApricornCache_UndoRed:
	removeitem ITEM_RED_APRICORN
AzaleaTown_EventScript_ApricornCache_BagFull:
	msgbox AzaleaTown_Text_NoRoomForApricornSet, MSGBOX_DEFAULT
	releaseall
	end

AzaleaTown_EventScript_ItemCacheEmpty:
	msgbox AzaleaTown_Text_ItemCacheEmpty, MSGBOX_DEFAULT
	releaseall
	end

AzaleaTown_EventScript_ItemCacheBagFull:
	msgbox AzaleaTown_Text_ItemCacheBagFull, MSGBOX_DEFAULT
	releaseall
	end

AzaleaTown_EventScript_Youngster::
	faceplayer
	setspeaker Azalea_Town_Speaker_Youngster
	msgbox AzaleaTown_Text_Youngster, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_AZALEA_NPC_YOUNGSTER
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_EventScript_Lass::
	faceplayer
	setspeaker Azalea_Town_Speaker_Lass
	msgbox AzaleaTown_Text_Lass, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_AZALEA_NPC_LASS
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_EventScript_Rocket::
	faceplayer
	setspeaker Azalea_Town_Speaker_Rocket
	msgbox AzaleaTown_Text_Rocket, MSGBOX_NPC
	closemessage
	end

AzaleaTown_EventScript_AquaGruntGym::
	faceplayer
	setspeaker Azalea_Town_Speaker_Rocket
	msgbox AzaleaTown_Text_AquaGruntGym, MSGBOX_NPC
	end

AzaleaTown_EventScript_IlexOfficer::
	faceplayer
	setspeaker Azalea_Town_Speaker_Officer
	msgbox AzaleaTown_Text_IlexOfficer, MSGBOX_NPC
	end

AzaleaTown_EventScript_CheckAzaleaQuest::
	checkflag FLAG_QUEST_AZALEA_NPCS_STARTED
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckCompleted
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckCompleted:
	checkflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_Done
	checkflag FLAG_QUEST_AZALEA_NPC_YOUNGSTER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckLass
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckLass:
	checkflag FLAG_QUEST_AZALEA_NPC_LASS
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1BlackBelt
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1BlackBelt:
	checkflag FLAG_QUEST_AZALEA_NPC_HOUSE1_BLACK_BELT
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1LittleBoy
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckHouse1LittleBoy:
	checkflag FLAG_QUEST_AZALEA_NPC_HOUSE1_LITTLE_BOY
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckKurtsHouseKurt
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckKurtsHouseKurt:
	checkflag FLAG_QUEST_AZALEA_NPC_KURTS_HOUSE_KURT
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartRocker
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartRocker:
	checkflag FLAG_QUEST_AZALEA_NPC_MART_ROCKER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartBugCatcher
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckMartBugCatcher:
	checkflag FLAG_QUEST_AZALEA_NPC_MART_BUG_CATCHER
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterFisherman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterFisherman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_FISHERMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterGentleman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterGentleman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_GENTLEMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterWoman
	return
AzaleaTown_EventScript_CheckAzaleaQuest_CheckPokecenterWoman:
	checkflag FLAG_QUEST_AZALEA_NPC_POKECENTER_WOMAN
	goto_if_eq AzaleaTown_EventScript_CheckAzaleaQuest_AllDone
	return
AzaleaTown_EventScript_CheckAzaleaQuest_AllDone:
	setflag FLAG_QUEST_AZALEA_NPCS_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
AzaleaTown_EventScript_CheckAzaleaQuest_Done:
	return

AzaleaTown_Text_Youngster:
	.string "BUGSY's gym is buzzing.\n"
	.string "I'm training up before I go in.$"

AzaleaTown_Text_Lass:
	.string "KURT's work keeps this town going.\n"
	.string "His balls are the best.$"

AzaleaTown_Text_Rocket:
	.string "Can't let you pass kid.$"

AzaleaTown_Text_AquaGruntGym:
	.string "We're taking care of business\n"
	.string "here. Savvy?$"

AzaleaTown_Text_IlexOfficer:
	.string "A little late but I managed to\n"
	.string "drive those grunts out of town\l"
	.string "with the help of Bugsy!$"

AzaleaTown_Text_Birch_CallAfterGold:
	.string "Hey.. uh, so the TIME MACHINE\n"
	.string "works.\p"
	.string "However, COSMOG or NEBBY rather,\n"
	.string "fell asleep...\p"
	.string "Seems like this thing puts a lot\n"
	.string "of strain on it.\p"
	.string "Might be a little bit before the\n"
	.string "machine works but I think we have\l"
	.string "a plan.\p"
	.string "Professor KUKUI says this thing\n"
	.string "can evolve!\p"
	.string "I think we will have you train it\n"
	.string "and get it to evolve so we can\l"
	.string "see if it would be willing to\l"
	.string "still help us out.\p"
	.string "I'm hearing GOLDENROD is dealing\n"
	.string "with some trouble though, take\l"
	.string "care of that first and maybe we\l"
	.string "can revisit this situation.\p"
	.string "Be safe, {PLAYER}!$"

AzaleaTown_Text_FoundApricornSet:
	.string "You found an APRICORN SET!\p"
	.string "One of each color was put in your\n"
	.string "ITEMS POCKET.$"

AzaleaTown_Text_NoRoomForApricornSet:
	.string "There's no room for all seven\n"
	.string "APRICORNS in your BAG.$"

AzaleaTown_Text_ItemCacheEmpty:
	.string "There's nothing else hidden here.$"

AzaleaTown_Text_ItemCacheBagFull:
	.string "There's no room in your BAG.$"

AzaleaTown_Text_Sign:
	.string "AZALEA TOWN\n"
	.string "Where People and POKéMON Live in\l"
	.string "Happy Harmony.$"


AzaleaTown_Text_KurtsHouseSign:
	.string "KURT'S HOUSE$"


AzaleaTown_Text_GymSign:
	.string "AZALEA TOWN\n"
	.string "POKéMON GYM\p"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"


AzaleaTown_Text_SlowpokeWellSign:
	.string "SLOWPOKE WELL\p"
	.string "Also known as the RAINMAKER WELL.\p"
	.string "Locals believe that a SLOWPOKE's\n"
	.string "yawn summons rain.\p"
	.string "Records show that a SLOWPOKE's\n"
	.string "yawn ended a drought 400 years ago.$"


AzaleaTown_Text_CharcoalKilnSign:
	.string "CHARCOAL KILN$"


AzaleaTown_Text_IlexForestSign:
	.string "ILEX FOREST\p"
	.string "Enter through the gate.$"
