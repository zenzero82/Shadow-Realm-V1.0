RockTunnel_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	.byte 0

RockTunnel_B1F_Speaker_Plasma1:
	.string "FAYE$"

RockTunnel_B1F_Speaker_Plasma2:
	.string "ORIN$"

RockTunnel_B1F_Speaker_Plasma3:
	.string "GAGE$"

RockTunnel_B1F_Speaker_Plasma4:
	.string "NYX$"

RockTunnel_B1F_Speaker_Plasma5:
	.string "KADE$"

RockTunnel_B1F_Speaker_Plasma6:
	.string "VOSS$"

RockTunnel_B1F_Speaker_Plasma7:
	.string "IRIS$"

RockTunnel_B1F_Speaker_Plasma8:
	.string "SERA$"

RockTunnel_B1F_EventScript_Plasma1::
	setspeaker RockTunnel_B1F_Speaker_Plasma1
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_1, RockTunnel_B1F_Text_Plasma1_Intro, RockTunnel_B1F_Text_Plasma1_Defeat, RockTunnel_B1F_EventScript_Plasma1_After
	end

RockTunnel_B1F_EventScript_Plasma1_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma1
	msgbox RockTunnel_B1F_Text_Plasma1_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma2::
	setspeaker RockTunnel_B1F_Speaker_Plasma2
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_2, RockTunnel_B1F_Text_Plasma2_Intro, RockTunnel_B1F_Text_Plasma2_Defeat, RockTunnel_B1F_EventScript_Plasma2_After
	end

RockTunnel_B1F_EventScript_Plasma2_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma2
	msgbox RockTunnel_B1F_Text_Plasma2_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma3::
	setspeaker RockTunnel_B1F_Speaker_Plasma3
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_3, RockTunnel_B1F_Text_Plasma3_Intro, RockTunnel_B1F_Text_Plasma3_Defeat, RockTunnel_B1F_EventScript_Plasma3_After
	end

RockTunnel_B1F_EventScript_Plasma3_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma3
	msgbox RockTunnel_B1F_Text_Plasma3_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma4::
	setspeaker RockTunnel_B1F_Speaker_Plasma4
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_4, RockTunnel_B1F_Text_Plasma4_Intro, RockTunnel_B1F_Text_Plasma4_Defeat, RockTunnel_B1F_EventScript_Plasma4_After
	end

RockTunnel_B1F_EventScript_Plasma4_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma4
	msgbox RockTunnel_B1F_Text_Plasma4_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma5::
	setspeaker RockTunnel_B1F_Speaker_Plasma5
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_5, RockTunnel_B1F_Text_Plasma5_Intro, RockTunnel_B1F_Text_Plasma5_Defeat, RockTunnel_B1F_EventScript_Plasma5_After
	end

RockTunnel_B1F_EventScript_Plasma5_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma5
	msgbox RockTunnel_B1F_Text_Plasma5_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma6::
	setspeaker RockTunnel_B1F_Speaker_Plasma6
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_6, RockTunnel_B1F_Text_Plasma6_Intro, RockTunnel_B1F_Text_Plasma6_Defeat, RockTunnel_B1F_EventScript_Plasma6_After
	end

RockTunnel_B1F_EventScript_Plasma6_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma6
	msgbox RockTunnel_B1F_Text_Plasma6_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma7::
	setspeaker RockTunnel_B1F_Speaker_Plasma7
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_7, RockTunnel_B1F_Text_Plasma7_Intro, RockTunnel_B1F_Text_Plasma7_Defeat, RockTunnel_B1F_EventScript_Plasma7_After
	end

RockTunnel_B1F_EventScript_Plasma7_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma7
	msgbox RockTunnel_B1F_Text_Plasma7_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_EventScript_Plasma8::
	setspeaker RockTunnel_B1F_Speaker_Plasma8
	trainerbattle_single TRAINER_ROCK_TUNNEL_B1F_PLASMA_8, RockTunnel_B1F_Text_Plasma8_Intro, RockTunnel_B1F_Text_Plasma8_Defeat, RockTunnel_B1F_EventScript_Plasma8_After
	end

RockTunnel_B1F_EventScript_Plasma8_After::
	setspeaker RockTunnel_B1F_Speaker_Plasma8
	msgbox RockTunnel_B1F_Text_Plasma8_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_B1F_Text_Plasma1_Intro:
	.string "Our scanners spike down here.\n"
	.string "You're not supposed to be here.$"

RockTunnel_B1F_Text_Plasma1_Defeat:
	.string "Readings collapsed!$"

RockTunnel_B1F_Text_Plasma1_After:
	.string "The signal jumped again.$"

RockTunnel_B1F_Text_Plasma2_Intro:
	.string "We traced a trainer into this\n"
	.string "cave. Out of our way.$"

RockTunnel_B1F_Text_Plasma2_Defeat:
	.string "You derailed the mission.$"

RockTunnel_B1F_Text_Plasma2_After:
	.string "We'll regroup outside.$"

RockTunnel_B1F_Text_Plasma3_Intro:
	.string "This layer is restricted. PLASMA\n"
	.string "orders.$"

RockTunnel_B1F_Text_Plasma3_Defeat:
	.string "Gah!$"

RockTunnel_B1F_Text_Plasma3_After:
	.string "Our maps don't match these\n"
	.string "tunnels.$"

RockTunnel_B1F_Text_Plasma4_Intro:
	.string "N wants proof these rumors are\n"
	.string "real. You're a problem.$"

RockTunnel_B1F_Text_Plasma4_Defeat:
	.string "N won't be happy...$"

RockTunnel_B1F_Text_Plasma4_After:
	.string "Maybe the tracker was wrong.$"

RockTunnel_B1F_Text_Plasma5_Intro:
	.string "We heard a strange cry echoing\n"
	.string "from below.$"

RockTunnel_B1F_Text_Plasma5_Defeat:
	.string "It vanished...$"

RockTunnel_B1F_Text_Plasma5_After:
	.string "That wasn't a normal POKéMON.$"

RockTunnel_B1F_Text_Plasma6_Intro:
	.string "No intruders! This is a research\n"
	.string "site.$"

RockTunnel_B1F_Text_Plasma6_Defeat:
	.string "Research ruined.$"

RockTunnel_B1F_Text_Plasma6_After:
	.string "If the boss asks, tell him nothing.$"

RockTunnel_B1F_Text_Plasma7_Intro:
	.string "Stay back! We're collecting\n"
	.string "samples.$"

RockTunnel_B1F_Text_Plasma7_Defeat:
	.string "Sample lost!$"

RockTunnel_B1F_Text_Plasma7_After:
	.string "You'll hear from PLASMA again.$"

RockTunnel_B1F_Text_Plasma8_Intro:
	.string "Don't touch the equipment!$"

RockTunnel_B1F_Text_Plasma8_Defeat:
	.string "All scrambled...$"

RockTunnel_B1F_Text_Plasma8_After:
	.string "We'll rebuild the scanner.$"
