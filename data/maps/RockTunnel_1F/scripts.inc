RockTunnel_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	.byte 0

RockTunnel_1F_Speaker_Plasma:
	.string "PLASMA$"

RockTunnel_1F_EventScript_Plasma1::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_1, RockTunnel_1F_Text_Plasma1_Intro, RockTunnel_1F_Text_Plasma1_Defeat, RockTunnel_1F_EventScript_Plasma1_After
	end

RockTunnel_1F_EventScript_Plasma1_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma1_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_EventScript_Plasma2::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_2, RockTunnel_1F_Text_Plasma2_Intro, RockTunnel_1F_Text_Plasma2_Defeat, RockTunnel_1F_EventScript_Plasma2_After
	end

RockTunnel_1F_EventScript_Plasma2_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma2_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_EventScript_Plasma3::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_3, RockTunnel_1F_Text_Plasma3_Intro, RockTunnel_1F_Text_Plasma3_Defeat, RockTunnel_1F_EventScript_Plasma3_After
	end

RockTunnel_1F_EventScript_Plasma3_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma3_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_EventScript_Plasma4::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_4, RockTunnel_1F_Text_Plasma4_Intro, RockTunnel_1F_Text_Plasma4_Defeat, RockTunnel_1F_EventScript_Plasma4_After
	end

RockTunnel_1F_EventScript_Plasma4_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma4_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_EventScript_Plasma5::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_5, RockTunnel_1F_Text_Plasma5_Intro, RockTunnel_1F_Text_Plasma5_Defeat, RockTunnel_1F_EventScript_Plasma5_After
	end

RockTunnel_1F_EventScript_Plasma5_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma5_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_EventScript_Plasma6::
	setspeaker RockTunnel_1F_Speaker_Plasma
	trainerbattle_single TRAINER_ROCK_TUNNEL_1F_PLASMA_6, RockTunnel_1F_Text_Plasma6_Intro, RockTunnel_1F_Text_Plasma6_Defeat, RockTunnel_1F_EventScript_Plasma6_After
	end

RockTunnel_1F_EventScript_Plasma6_After::
	setspeaker RockTunnel_1F_Speaker_Plasma
	msgbox RockTunnel_1F_Text_Plasma6_After, MSGBOX_NPC
	closemessage
	release
	end

RockTunnel_1F_Text_Plasma1_Intro:
	.string "PLASMA patrol. No sightseeing.\n"
	.string "Turn back.$"

RockTunnel_1F_Text_Plasma1_Defeat:
	.string "Patrol broken!$"

RockTunnel_1F_Text_Plasma1_After:
	.string "We were told to hold this route.\n"
	.string "No questions.$"

RockTunnel_1F_Text_Plasma2_Intro:
	.string "TEAM PLASMA sealed this route.\n"
	.string "No one passes.$"

RockTunnel_1F_Text_Plasma2_Defeat:
	.string "You broke our line!$"

RockTunnel_1F_Text_Plasma2_After:
	.string "Orders are strict. We hold the\n"
	.string "cave.$"

RockTunnel_1F_Text_Plasma3_Intro:
	.string "We picked up odd signals here.\n"
	.string "Don't interfere.$"

RockTunnel_1F_Text_Plasma3_Defeat:
	.string "So much for stealth.$"

RockTunnel_1F_Text_Plasma3_After:
	.string "Our charts don't match these\n"
	.string "halls.$"

RockTunnel_1F_Text_Plasma4_Intro:
	.string "Fossils, data, samples... PLASMA\n"
	.string "claims it all.$"

RockTunnel_1F_Text_Plasma4_Defeat:
	.string "The data...!$"

RockTunnel_1F_Text_Plasma4_After:
	.string "GHETSIS won't like this.$"

RockTunnel_1F_Text_Plasma5_Intro:
	.string "If anything's hiding here, we'll\n"
	.string "flush it out!$"

RockTunnel_1F_Text_Plasma5_Defeat:
	.string "Urgh... back to scouting.$"

RockTunnel_1F_Text_Plasma5_After:
	.string "Reports say the route shifted\n"
	.string "overnight.$"

RockTunnel_1F_Text_Plasma6_Intro:
	.string "This tunnel is under PLASMA\n"
	.string "control.$"

RockTunnel_1F_Text_Plasma6_Defeat:
	.string "Tch... you don't quit.$"

RockTunnel_1F_Text_Plasma6_After:
	.string "Someone on B1F should handle\n"
	.string "you.$"
