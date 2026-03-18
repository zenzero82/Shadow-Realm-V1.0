.set LOCALID_ARIANA, 9
.set LOCALID_ITEMBALL_MOON_STONE, 10

MtMoon_Outside_MapScripts::
	.byte 0

MtMoon_Outside_EventScript_Sign::
	msgbox MtMoon_Outside_Text_DontLitterSign, MSGBOX_SIGN
	end

MtMoon_Outside_EventScript_Ariana::
	lock
	goto_if_set FLAG_HIDE_MT_MOON_OUTSIDE_ARIANA, MtMoon_Outside_EventScript_Ariana_Done
	setspeaker MtMoon_Outside_Speaker_Ariana
	msgbox MtMoon_Outside_Text_Ariana_Capture, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ARIANA, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject LOCALID_ARIANA, DIR_NORTH
	setspeaker MtMoon_Outside_Speaker_Ariana
	msgbox MtMoon_Outside_Text_Ariana_Threat, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_MT_MOON_NPC_ARIANA
	call QuestJournal_EventScript_CheckMtMoonNPCs
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MT_MOON_OUTSIDE_ARIANA
	hideobjectat LOCALID_ARIANA, MAP_MT_MOON_OUTSIDE
	removeobject LOCALID_ARIANA
	fadescreenswapbuffers FADE_FROM_BLACK
MtMoon_Outside_EventScript_Ariana_Done:
	release
	end

MtMoon_Outside_EventScript_ClefairyCry::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

MtMoon_Outside_EventScript_Item_MoonStone::
	finditem ITEM_MOON_STONE
	goto_if_eq VAR_0x8007, FALSE, MtMoon_Outside_EventScript_Item_Done
	removeobject LOCALID_ITEMBALL_MOON_STONE
MtMoon_Outside_EventScript_Item_Done::
	end

QuestJournal_EventScript_CheckMtMoonNPCs::
	checkflag FLAG_QUEST_MT_MOON_COMPLETED
	goto_if_eq QuestJournal_EventScript_CheckMtMoonNPCs_End
	checkflag FLAG_QUEST_MT_MOON_STARTED
	goto_if_eq QuestJournal_EventScript_CheckMtMoonNPCs_Clerk
	return
QuestJournal_EventScript_CheckMtMoonNPCs_Clerk:
	checkflag FLAG_QUEST_MT_MOON_NPC_CLERK
	goto_if_eq QuestJournal_EventScript_CheckMtMoonNPCs_Lass
	return
QuestJournal_EventScript_CheckMtMoonNPCs_Lass:
	checkflag FLAG_QUEST_MT_MOON_NPC_LASS
	goto_if_eq QuestJournal_EventScript_CheckMtMoonNPCs_Ariana
	return
QuestJournal_EventScript_CheckMtMoonNPCs_Ariana:
	checkflag FLAG_QUEST_MT_MOON_NPC_ARIANA
	goto_if_eq QuestJournal_EventScript_CheckMtMoonNPCs_Done
	return
QuestJournal_EventScript_CheckMtMoonNPCs_Done:
	setflag FLAG_QUEST_MT_MOON_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
QuestJournal_EventScript_CheckMtMoonNPCs_End:
	return

MtMoon_Outside_Text_Ariana_Capture:
	.string "That was an easier capture than\n"
	.string "I thought.$"

MtMoon_Outside_Text_Ariana_Threat:
	.string "Who are you? No matter, you're too\n"
	.string "late if you wanted to stop our plans.\p"
	.string "We got what we needed here. Soon our\n"
	.string "grand scheme will be in full effect.\p"
	.string "Count your days of peace, kid.\n"
	.string "You don't have many more left.$"

MtMoon_Outside_Speaker_Ariana:
	.string "ARIANA$"

MtMoon_Outside_Text_DontLitterSign:
	.string "MT.MOON SQUARE\n"
	.string "DON'T LITTER$"
	
