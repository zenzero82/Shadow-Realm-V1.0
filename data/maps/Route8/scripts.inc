Route8_MapScripts::
	.byte 0

Route8_EventScript_Sign::
	msgbox Route8_Text_UndergroundTunnelSign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

@ =========================================================
@ SPEAKER DEFINITIONS
@ =========================================================

Route8_Speaker_Biker1:
	.string "ZEKE$"

Route8_Speaker_Biker2:
	.string "AXEL$"

Route8_Speaker_Biker3:
	.string "DUKE$"

Route8_Speaker_Biker4:
	.string "ROCCO$"

Route8_Speaker_Biker5:
	.string "JETT$"

Route8_Speaker_SuperNerd1:
	.string "MILO$"

Route8_Speaker_SuperNerd2:
	.string "ORIN$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route8_EventScript_Biker1::
	setspeaker Route8_Speaker_Biker1
	trainerbattle_single TRAINER_ROUTE8_BIKER_1, Route8_Text_Biker1_Intro, Route8_Text_Biker1_Defeat, Route8_EventScript_Biker1_After
	end

Route8_EventScript_Biker1_After::
	setspeaker Route8_Speaker_Biker1
	msgbox Route8_Text_Biker1_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_Biker2::
	setspeaker Route8_Speaker_Biker2
	trainerbattle_single TRAINER_ROUTE8_BIKER_2, Route8_Text_Biker2_Intro, Route8_Text_Biker2_Defeat, Route8_EventScript_Biker2_After
	end

Route8_EventScript_Biker2_After::
	setspeaker Route8_Speaker_Biker2
	msgbox Route8_Text_Biker2_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_Biker3::
	setspeaker Route8_Speaker_Biker3
	trainerbattle_single TRAINER_ROUTE8_BIKER_3, Route8_Text_Biker3_Intro, Route8_Text_Biker3_Defeat, Route8_EventScript_Biker3_After
	end

Route8_EventScript_Biker3_After::
	setspeaker Route8_Speaker_Biker3
	msgbox Route8_Text_Biker3_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_Biker4::
	setspeaker Route8_Speaker_Biker4
	trainerbattle_single TRAINER_ROUTE8_BIKER_4, Route8_Text_Biker4_Intro, Route8_Text_Biker4_Defeat, Route8_EventScript_Biker4_After
	end

Route8_EventScript_Biker4_After::
	setspeaker Route8_Speaker_Biker4
	msgbox Route8_Text_Biker4_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_Biker5::
	setspeaker Route8_Speaker_Biker5
	trainerbattle_single TRAINER_ROUTE8_BIKER_5, Route8_Text_Biker5_Intro, Route8_Text_Biker5_Defeat, Route8_EventScript_Biker5_After
	end

Route8_EventScript_Biker5_After::
	setspeaker Route8_Speaker_Biker5
	msgbox Route8_Text_Biker5_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_SuperNerd1::
	setspeaker Route8_Speaker_SuperNerd1
	trainerbattle_single TRAINER_ROUTE8_SUPER_NERD_1, Route8_Text_SuperNerd1_Intro, Route8_Text_SuperNerd1_Defeat, Route8_EventScript_SuperNerd1_After
	end

Route8_EventScript_SuperNerd1_After::
	setspeaker Route8_Speaker_SuperNerd1
	msgbox Route8_Text_SuperNerd1_After, MSGBOX_NPC
	closemessage
	release
	end

Route8_EventScript_SuperNerd2::
	setspeaker Route8_Speaker_SuperNerd2
	trainerbattle_single TRAINER_ROUTE8_SUPER_NERD_2, Route8_Text_SuperNerd2_Intro, Route8_Text_SuperNerd2_Defeat, Route8_EventScript_SuperNerd2_After
	end

Route8_EventScript_SuperNerd2_After::
	setspeaker Route8_Speaker_SuperNerd2
	msgbox Route8_Text_SuperNerd2_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ TEXT
@ =========================================================

Route8_Text_Biker1_Intro:
	.string "We own this stretch of road!\p"
	.string "Let's see if you can hang!$"

Route8_Text_Biker1_Defeat:
	.string "You knocked me off rhythm!$"

Route8_Text_Biker1_After:
	.string "My crew needs tougher exhaust\n"
	.string "and tougher Pokemon.$"

Route8_Text_Biker2_Intro:
	.string "You cut through our line?\p"
	.string "Then you battle me!$"

Route8_Text_Biker2_Defeat:
	.string "Ran out of fumes...$"

Route8_Text_Biker2_After:
	.string "Poison types are mean, but your\n"
	.string "team was meaner.$"

Route8_Text_Biker3_Intro:
	.string "My road, my rules.\p"
	.string "Show me what you've got!$"

Route8_Text_Biker3_Defeat:
	.string "Rules changed fast...$"

Route8_Text_Biker3_After:
	.string "I like rough Pokemon.\n"
	.string "They match the route.$"

Route8_Text_Biker4_Intro:
	.string "I tuned this team for street fights!\p"
	.string "Bring it on!$"

Route8_Text_Biker4_Defeat:
	.string "Tuning wasn't enough!$"

Route8_Text_Biker4_After:
	.string "Steel, poison, attitude...\n"
	.string "I thought I had it covered.$"

Route8_Text_Biker5_Intro:
	.string "The last rider in the pack is\n"
	.string "the toughest!$"

Route8_Text_Biker5_Defeat:
	.string "Guess I wasn't the last boss...$"

Route8_Text_Biker5_After:
	.string "I should mix in more dirty tricks\n"
	.string "next time.$"

Route8_Text_SuperNerd1_Intro:
	.string "My calculations say this battle\n"
	.string "will be efficient.$"

Route8_Text_SuperNerd1_Defeat:
	.string "Error in the formula!$"

Route8_Text_SuperNerd1_After:
	.string "Magnetism and precision usually\n"
	.string "get better results.$"

Route8_Text_SuperNerd2_Intro:
	.string "I built a team around clever tech.\p"
	.string "Test it with me!$"

Route8_Text_SuperNerd2_Defeat:
	.string "System failure!$"

Route8_Text_SuperNerd2_After:
	.string "Back to debugging my strategy.$"

Route8_Text_UndergroundTunnelSign:
	.string "Underground Tunnel:\p"
	.string "Route 8 {RIGHT_ARROW} Route 7$"
