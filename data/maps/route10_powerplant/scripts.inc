route10_powerplant_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, route10_powerplant_EventScript_SyncPlasmaCleanup
	map_script MAP_SCRIPT_ON_TRANSITION, route10_powerplant_EventScript_SyncPlasmaCleanup
	.byte 0

route10_powerplant_EventScript_SyncPlasmaCleanup::
	checktrainerflag TRAINER_ZINZOLIN_POWER_PLANT
	goto_if_eq route10_powerplant_EventScript_SyncPlasmaCleanup_Hide
	setflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto route10_powerplant_EventScript_SyncPlasmaCleanup_Show

route10_powerplant_EventScript_SyncPlasmaCleanup_Hide::
	clearflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_1
	setflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_2
	hideobjectat LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_1, MAP_ROUTE10_POWERPLANT
	removeobject LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_1
	hideobjectat LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_2, MAP_ROUTE10_POWERPLANT
	removeobject LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_2
route10_powerplant_EventScript_SyncPlasmaCleanup_Done::
	end

route10_powerplant_EventScript_SyncPlasmaCleanup_Show::
	clearflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_1
	clearflag FLAG_HIDE_ROUTE10_POWERPLANT_PLASMA_2
	addobject LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_1
	showobjectat LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_1, MAP_ROUTE10_POWERPLANT
	addobject LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_2
	showobjectat LOCALID_ROUTE10_POWERPLANT_PLASMA_GRUNT_2, MAP_ROUTE10_POWERPLANT
	end

route10_powerplant_EventScript_PlasmaGrunt1::
	setspeaker route10_powerplant_Speaker_PlasmaGrunt
	trainerbattle_single TRAINER_POWERPLANT_PLASMA_1, route10_powerplant_Text_PlasmaGrunt1_Intro, route10_powerplant_Text_PlasmaGrunt1_Defeat, route10_powerplant_EventScript_PlasmaGrunt1_After
	goto route10_powerplant_EventScript_PlasmaGrunt1_After
	end

route10_powerplant_EventScript_PlasmaGrunt1_After::
	settrainerflag TRAINER_POWERPLANT_PLASMA_1
	setspeaker route10_powerplant_Speaker_PlasmaGrunt
	msgbox route10_powerplant_Text_PlasmaGrunt1_After, MSGBOX_DEFAULT
	releaseall
	end

route10_powerplant_EventScript_PlasmaGrunt2::
	setspeaker route10_powerplant_Speaker_PlasmaGrunt
	trainerbattle_single TRAINER_POWERPLANT_PLASMA_2, route10_powerplant_Text_PlasmaGrunt2_Intro, route10_powerplant_Text_PlasmaGrunt2_Defeat, route10_powerplant_EventScript_PlasmaGrunt2_After
	goto route10_powerplant_EventScript_PlasmaGrunt2_After
	end

route10_powerplant_EventScript_PlasmaGrunt2_After::
	settrainerflag TRAINER_POWERPLANT_PLASMA_2
	setspeaker route10_powerplant_Speaker_PlasmaGrunt
	msgbox route10_powerplant_Text_PlasmaGrunt2_After, MSGBOX_DEFAULT
	releaseall
	end

route10_powerplant_EventScript_Engineer1::
	faceplayer
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer1_Before
	checkflag FLAG_QUEST_THUNDERBIRD_COMPLETED
	goto_if_eq route10_powerplant_EventScript_Engineer1_After
	goto route10_powerplant_EventScript_Engineer1_Before
route10_powerplant_EventScript_Engineer1_PreQuest:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer1_PreQuest, MSGBOX_NPC
	end
route10_powerplant_EventScript_Engineer1_After:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer1_After, MSGBOX_NPC
	end
route10_powerplant_EventScript_Engineer1_Before:
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer1_Before_ShowInvasion
	goto route10_powerplant_EventScript_Engineer1_PreQuest
route10_powerplant_EventScript_Engineer1_Before_ShowInvasion:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer1, MSGBOX_NPC
	end

route10_powerplant_EventScript_Engineer2::
	faceplayer
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer2_Before
	checkflag FLAG_QUEST_THUNDERBIRD_COMPLETED
	goto_if_eq route10_powerplant_EventScript_Engineer2_After
	goto route10_powerplant_EventScript_Engineer2_Before
route10_powerplant_EventScript_Engineer2_PreQuest:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer2_PreQuest, MSGBOX_NPC
	end
route10_powerplant_EventScript_Engineer2_After:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer2_After, MSGBOX_NPC
	setflag FLAG_QUEST_MACHINE_PART_REVEALED
	checkflag FLAG_QUEST_MACHINE_PART_STARTED
	goto_if_eq route10_powerplant_EventScript_Engineer2_After_Done
	setflag FLAG_QUEST_MACHINE_PART_STARTED
	call QuestJournal_EventScript_NewQuestAlert
route10_powerplant_EventScript_Engineer2_After_Done:
	end
route10_powerplant_EventScript_Engineer2_Before:
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer2_Before_ShowInvasion
	goto route10_powerplant_EventScript_Engineer2_PreQuest
route10_powerplant_EventScript_Engineer2_Before_ShowInvasion:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer2, MSGBOX_NPC
	end

route10_powerplant_EventScript_Engineer3::
	faceplayer
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer3_Before
	checkflag FLAG_QUEST_THUNDERBIRD_COMPLETED
	goto_if_eq route10_powerplant_EventScript_Engineer3_After
	goto route10_powerplant_EventScript_Engineer3_Before
route10_powerplant_EventScript_Engineer3_PreQuest:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer3_PreQuest, MSGBOX_NPC
	end
route10_powerplant_EventScript_Engineer3_After:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer3_After, MSGBOX_NPC
	end
route10_powerplant_EventScript_Engineer3_Before:
	checkflag FLAG_ROUTE10_POWERPLANT_INVASION_ACTIVE
	goto_if_eq route10_powerplant_EventScript_Engineer3_Before_ShowInvasion
	goto route10_powerplant_EventScript_Engineer3_PreQuest
route10_powerplant_EventScript_Engineer3_Before_ShowInvasion:
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer3, MSGBOX_NPC
	end

route10_powerplant_EventScript_Item_Thunderstone::
	finditem ITEM_THUNDERSTONE
	goto_if_eq VAR_0x8007, FALSE, route10_powerplant_EventScript_Item_Done
	setflag FLAG_HIDE_POWERPLANT_THUNDERSTONE
	removeobject VAR_LAST_TALKED
route10_powerplant_EventScript_Item_Done::
	end

route10_powerplant_Text_PlasmaGrunt1_Intro:
	.string "ZINZOLIN's already got the\n"
	.string "generator hooked. We just\l"
	.string "need ZAPDOS to bite.$"

route10_powerplant_Text_PlasmaGrunt1_Defeat:
	.string "Ngh... you're slowing things\n"
	.string "down!$"

route10_powerplant_Text_PlasmaGrunt1_After:
	.string "TEAM PLASMA will control every\n"
	.string "watt from here on.$"

route10_powerplant_Text_PlasmaGrunt2_Intro:
	.string "The POWER PLANT is ours.\n"
	.string "ZINZOLIN says the capture\l"
	.string "will be swift.$"

route10_powerplant_Text_PlasmaGrunt2_Defeat:
	.string "So much for a perfect\n"
	.string "takeover...$"

route10_powerplant_Text_PlasmaGrunt2_After:
	.string "Once the bird appears,\n"
	.string "the region bows to PLASMA.$"

route10_powerplant_Text_Engineer1:
	.string "They stormed in and locked us out.\n"
	.string "ZINZOLIN's crew is messing with\l"
	.string "our equipment.$"

route10_powerplant_Text_Engineer1_PreQuest:
	.string "A few rough-looking ROCKET grunts\n"
	.string "showed up earlier and started\l"
	.string "surveying the plant.$"

route10_powerplant_Text_Engineer2:
	.string "They're trying to lure the\n"
	.string "LEGENDARY ZAPDOS here.\l"
	.string "This place won't survive it.$"

route10_powerplant_Text_Engineer2_PreQuest:
	.string "They didn't steal anything.\n"
	.string "Just stared at our systems and\l"
	.string "kept whispering to each other.$"

route10_powerplant_Text_Engineer3:
	.string "TEAM PLASMA took over the plant.\n"
	.string "We can't stop them without help.$"

route10_powerplant_Text_Engineer3_PreQuest:
	.string "Before leaving, I heard one of\n"
	.string "them mutter about a takeover.\p"
	.string "Then the whole group just walked\n"
	.string "out like they were planning ahead.$"

route10_powerplant_Text_Engineer1_After:
	.string "You drove TEAM PLASMA out!\n"
	.string "We can finally get the POWER PLANT\l"
	.string "stable again. Thanks, kid.$"

route10_powerplant_Text_Engineer2_After:
	.string "One of those grunts swiped a part\n"
	.string "that helps power the MAGNET TRAIN.\p"
	.string "That line runs passengers between\n"
	.string "SAFFRON and GOLDENROD.$"

route10_powerplant_Text_Engineer3_After:
	.string "I saw that ZINZOLIN creep vanish\n"
	.string "into some kind of ring...\p"
	.string "Still, you beat TEAM PLASMA,\n"
	.string "and that's what matters.$"

route10_powerplant_Speaker_PlasmaGrunt:
	.string "PLASMA GRUNT$"

route10_powerplant_Speaker_Engineer:
	.string "ENGINEER$"
