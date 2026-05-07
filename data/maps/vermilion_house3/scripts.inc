vermilion_house3_MapScripts::
	.byte 0

vermilion_house3_Speaker_Gentleman:
	.string "ARTHUR$"

vermilion_house3_EventScript_Gentleman::
	lock
	faceplayer
	setspeaker vermilion_house3_Speaker_Gentleman
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_house3_EventScript_Gentleman_After
	msgbox vermilion_house3_Text_Gentleman_Before, MSGBOX_NPC
	release
	end

vermilion_house3_EventScript_Gentleman_After::
	msgbox vermilion_house3_Text_Gentleman_After, MSGBOX_NPC
	release
	end

vermilion_house3_Text_Gentleman_Before:
	.string "A port city hears every rumor first.\p"
	.string "That is not always a blessing.$"

vermilion_house3_Text_Gentleman_After:
	.string "Now the rumors have moved on from the\n"
	.string "harbor to the SNORLAX on the road.$"
