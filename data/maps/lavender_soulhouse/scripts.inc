lavender_soulhouse_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, lavender_soulhouse_OnResume
	.byte 0

lavender_soulhouse_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, lavender_soulhouse_EventScript_TryRemoveGimmighoul
	end

lavender_soulhouse_EventScript_TryRemoveGimmighoul::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, lavender_soulhouse_EventScript_RemoveGimmighoul
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, lavender_soulhouse_EventScript_RemoveGimmighoul
	return

lavender_soulhouse_EventScript_RemoveGimmighoul::
	removeobject VAR_LAST_TALKED
	return

lavender_soulhouse_Speaker_MrFuji:
	.string "Mr. Fuji$"

lavender_soulhouse_EventScript_Gimmighoul::
	call Common_EventScript_GimmighoulStaticEncounter
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, lavender_soulhouse_EventScript_GimmighoulDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, lavender_soulhouse_EventScript_GimmighoulDefeated
	release
	end

lavender_soulhouse_EventScript_GimmighoulDefeated::
	setflag FLAG_HIDE_LAVENDER_SOULHOUSE_GIMMIGHOUL
	setvar VAR_0x8000, 75
	additem ITEM_GIMMIGHOUL_COIN, 75
	buffernumberstring STR_VAR_1, VAR_0x8000
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_GimmighoulCoinsObtained, MSGBOX_DEFAULT
	waitfanfare
	release
	end

lavender_soulhouse_EventScript_MrFuji::
	lock
	faceplayer
	setvar VAR_0x8000, 11
	call Lavender_Town_EventScript_RecordInteriorNPC
	goto_if_eq VAR_LAVENDER_SOULHOUSE_ODD_KEYSTONE_STATE, 2, lavender_soulhouse_EventScript_MrFuji_GaveOddKeystone
	goto_if_eq VAR_LAVENDER_SOULHOUSE_ODD_KEYSTONE_STATE, 1, lavender_soulhouse_EventScript_MrFuji_AskAgain
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_Intro, MSGBOX_NPC
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_OfferOddKeystone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, lavender_soulhouse_EventScript_MrFuji_Decline
	goto lavender_soulhouse_EventScript_MrFuji_GiveOddKeystone

lavender_soulhouse_EventScript_MrFuji_AskAgain::
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_AskAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, lavender_soulhouse_EventScript_MrFuji_Decline
	goto lavender_soulhouse_EventScript_MrFuji_GiveOddKeystone

lavender_soulhouse_EventScript_MrFuji_GiveOddKeystone::
	giveitem ITEM_ODD_KEYSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_LAVENDER_SOULHOUSE_ODD_KEYSTONE_STATE, 2
	checkflag FLAG_QUEST_ODD_KEYSTONE_STARTED
	goto_if_eq lavender_soulhouse_EventScript_MrFuji_GiveOddKeystone_Message
	setflag FLAG_QUEST_ODD_KEYSTONE_STARTED
	call QuestJournal_EventScript_NewQuestAlert
lavender_soulhouse_EventScript_MrFuji_GiveOddKeystone_Message:
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_GaveOddKeystone, MSGBOX_NPC
	release
	end

lavender_soulhouse_EventScript_MrFuji_Decline::
	setvar VAR_LAVENDER_SOULHOUSE_ODD_KEYSTONE_STATE, 1
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_Decline, MSGBOX_NPC
	release
	end

lavender_soulhouse_EventScript_MrFuji_GaveOddKeystone::
	setspeaker lavender_soulhouse_Speaker_MrFuji
	msgbox lavender_soulhouse_Text_MrFuji_GaveOddKeystone, MSGBOX_NPC
	release
	end

lavender_soulhouse_Text_MrFuji_Intro:
	.string "People go to the SOUL HOUSE to\n"
	.string "pay their respects to departed\l"
	.string "POKEMON.\p"
	.string "Strangely, new POKEMON started\n"
	.string "appearing around the region about\l"
	.string "six months ago.\p"
	.string "I found this odd rock, and from time\n"
	.string "to time I can hear it make sounds.$"

lavender_soulhouse_Text_MrFuji_OfferOddKeystone:
	.string "Would you like to take it?$"

lavender_soulhouse_Text_MrFuji_GaveOddKeystone:
	.string "It seems like that thing is more\n"
	.string "responsive here than anywhere else I\l"
	.string "have brought it.\p"
	.string "Maybe you can come by again with it\n"
	.string "sometime to see if it reacts\l"
	.string "differently.$"

lavender_soulhouse_Text_MrFuji_Decline:
	.string "Oh okay, it is a little sketchy after\n"
	.string "all.\p"
	.string "Come see me again if you change your\n"
	.string "mind.$"

lavender_soulhouse_Text_MrFuji_AskAgain:
	.string "Did you change your mind about the\n"
	.string "odd stone?$"
