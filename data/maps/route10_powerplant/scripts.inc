route10_powerplant_MapScripts::
	.byte 0

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
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer1, MSGBOX_NPC
	end

route10_powerplant_EventScript_Engineer2::
	faceplayer
	setspeaker route10_powerplant_Speaker_Engineer
	msgbox route10_powerplant_Text_Engineer2, MSGBOX_NPC
	end

route10_powerplant_EventScript_Engineer3::
	faceplayer
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
	.string "ZINZOLIN's already got the\l"
	.string "generator hooked. We just\l"
	.string "need ZAPDOS to bite.$"

route10_powerplant_Text_PlasmaGrunt1_Defeat:
	.string "Ngh... you're slowing things\l"
	.string "down!$"

route10_powerplant_Text_PlasmaGrunt1_After:
	.string "TEAM PLASMA will control every\l"
	.string "watt from here on.$"

route10_powerplant_Text_PlasmaGrunt2_Intro:
	.string "The POWER PLANT is ours.\l"
	.string "ZINZOLIN says the capture\l"
	.string "will be swift.$"

route10_powerplant_Text_PlasmaGrunt2_Defeat:
	.string "So much for a perfect\l"
	.string "takeover...$"

route10_powerplant_Text_PlasmaGrunt2_After:
	.string "Once the bird appears,\l"
	.string "the region bows to PLASMA.$"

route10_powerplant_Text_Engineer1:
	.string "They stormed in and locked us out.\l"
	.string "ZINZOLIN's crew is messing with\l"
	.string "our equipment.$"

route10_powerplant_Text_Engineer2:
	.string "They're trying to lure the\l"
	.string "LEGENDARY ZAPDOS here.\l"
	.string "This place won't survive it.$"

route10_powerplant_Text_Engineer3:
	.string "TEAM PLASMA took over the plant.\l"
	.string "We can't stop them without help.$"

route10_powerplant_Speaker_PlasmaGrunt:
	.string "PLASMA GRUNT$"

route10_powerplant_Speaker_Engineer:
	.string "ENGINEER$"
