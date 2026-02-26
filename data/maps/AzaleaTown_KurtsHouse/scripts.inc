AzaleaTown_KurtsHouse_MapScripts::
	.byte 0

AzaleaTown_KurtsHouse_EventScript_Kurt::
	faceplayer
	msgbox AzaleaTown_KurtsHouse_Text_Kurt, MSGBOX_NPC
	end

AzaleaTown_KurtsHouse_Speaker_IronMask:
	.string "MARAUDER$"

AzaleaTown_KurtsHouse_EventScript_IronMask::
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	trainerbattle_single TRAINER_KURTS_HOUSE_IRONMASK, AzaleaTown_KurtsHouse_Text_IronMask_Intro, AzaleaTown_KurtsHouse_Text_IronMask_Defeat, AzaleaTown_KurtsHouse_EventScript_IronMask_After
	end

AzaleaTown_KurtsHouse_EventScript_IronMask_After::
	setspeaker AzaleaTown_KurtsHouse_Speaker_IronMask
	msgbox AzaleaTown_KurtsHouse_Text_IronMask_After, MSGBOX_NPC
	closemessage
	release
	end

AzaleaTown_KurtsHouse_Text_IronMask_Intro:
	.string "KURT won't hand over his work.\n"
	.string "I'll take it by force.$"

AzaleaTown_KurtsHouse_Text_IronMask_Defeat:
	.string "So this is JOHTO's spirit...$"

AzaleaTown_KurtsHouse_Text_IronMask_After:
	.string "This isn't over. The shadows\n"
	.string "will find you.$"

AzaleaTown_KurtsHouse_Text_Kurt:
	.string "I'm KURT. I turn APRICORNS into\n"
	.string "special POKEMON BALLS.\p"
	.string "Bring me any APRICORNS you find.$"

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
