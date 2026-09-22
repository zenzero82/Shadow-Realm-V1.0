AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_Speaker_BlackBelt:
	.string "KAI$"

AzaleaTown_House1_Speaker_LittleBoy:
	.string "NOAH$"

AzaleaTown_House1_EventScript_BlackBelt::
	faceplayer
	setspeaker AzaleaTown_House1_Speaker_BlackBelt
	msgbox AzaleaTown_House1_Text_BlackBelt, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_HOUSE1_BLACK_BELT
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_House1_EventScript_LittleBoy::
	faceplayer
	setspeaker AzaleaTown_House1_Speaker_LittleBoy
	msgbox AzaleaTown_House1_Text_LittleBoy, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_HOUSE1_LITTLE_BOY
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_House1_Text_BlackBelt:
	.string "I train here to stay sharp.\n"
	.string "Quiet towns still need guardians.$"

AzaleaTown_House1_Text_LittleBoy:
	.string "I want to explore every corner of\n"
	.string "town when I'm older.$"
