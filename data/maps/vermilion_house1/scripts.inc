vermilion_house1_MapScripts::
	.byte 0

vermilion_house1_Speaker_Fisherman:
	.string "HANK$"

vermilion_house1_EventScript_Fisherman::
	lock
	faceplayer
	setspeaker vermilion_house1_Speaker_Fisherman
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_house1_EventScript_Fisherman_After
	msgbox vermilion_house1_Text_Fisherman_Before, MSGBOX_NPC
	release
	end

vermilion_house1_EventScript_Fisherman_After::
	msgbox vermilion_house1_Text_Fisherman_After, MSGBOX_NPC
	release
	end

vermilion_house1_Text_Fisherman_Before:
	.string "You can tell when the port is tense.\p"
	.string "Even the sea outside sounds different.$"

vermilion_house1_Text_Fisherman_After:
	.string "The harbor's quieting down again.\p"
	.string "Now everyone can go back to worrying\n"
	.string "about that sleeping SNORLAX.$"
