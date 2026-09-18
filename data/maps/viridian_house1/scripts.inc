viridian_house1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, viridian_house1_OnTransition
	.byte 0

viridian_house1_Speaker_Engineer:
	.string "Cole$"

viridian_house1_Speaker_OldWoman:
	.string "Mabel$"

viridian_house1_OnTransition:
	checkflag FLAG_QUEST_BACK_TO_HQ_STARTED
	goto_if_eq VAR_RESULT, FALSE, viridian_house1_HideCivilians
	clearflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_house1_HideCivilians:
	setflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_house1_EventScript_Engineer::
	lock
	faceplayer
	setspeaker viridian_house1_Speaker_Engineer
	msgbox viridian_house1_Text_Engineer, MSGBOX_DEFAULT
	release
	end

viridian_house1_EventScript_OldWoman::
	lock
	faceplayer
	setspeaker viridian_house1_Speaker_OldWoman
	msgbox viridian_house1_Text_OldWoman, MSGBOX_DEFAULT
	release
	end

viridian_house1_Text_Engineer:
	.string "When Team Rocket marched in, we\n"
	.string "grabbed what we could and ran.\p"
	.string "I only just came back to see what\n"
	.string "they left standing.$"

viridian_house1_Text_OldWoman:
	.string "I hid with relatives outside the\n"
	.string "city until the shouting stopped.\p"
	.string "Even now, coming home feels\n"
	.string "strange.$"
