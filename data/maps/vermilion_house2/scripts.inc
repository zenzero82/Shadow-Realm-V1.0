vermilion_house2_MapScripts::
	.byte 0

vermilion_house2_Speaker_Woman:
	.string "MIRA$"

vermilion_house2_Speaker_Boy:
	.string "TOBY$"

vermilion_house2_EventScript_Woman::
	lock
	faceplayer
	setspeaker vermilion_house2_Speaker_Woman
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_house2_EventScript_Woman_After
	msgbox vermilion_house2_Text_Woman_Before, MSGBOX_NPC
	release
	end

vermilion_house2_EventScript_Woman_After::
	msgbox vermilion_house2_Text_Woman_After, MSGBOX_NPC
	release
	end

vermilion_house2_EventScript_Boy::
	lock
	faceplayer
	setspeaker vermilion_house2_Speaker_Boy
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_house2_EventScript_Boy_After
	msgbox vermilion_house2_Text_Boy_Before, MSGBOX_NPC
	release
	end

vermilion_house2_EventScript_Boy_After::
	msgbox vermilion_house2_Text_Boy_After, MSGBOX_NPC
	release
	end

vermilion_house2_Text_Woman_Before:
	.string "My son keeps peeking toward the docks.\p"
	.string "Something about the harbor has the\n"
	.string "whole city unsettled.$"

vermilion_house2_Text_Woman_After:
	.string "Whatever happened at the port,\n"
	.string "I'm relieved it ended peacefully.$"

vermilion_house2_Text_Boy_Before:
	.string "I saw a pretty girl near the ship,\n"
	.string "but she looked really scared.$"

vermilion_house2_Text_Boy_After:
	.string "Mom says not to pry, but I still want\n"
	.string "to know what happened at the port.$"
