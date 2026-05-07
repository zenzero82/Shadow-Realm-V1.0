Route9_MapScripts::
	.byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Route9_Speaker_Camper1:
	.string "MARK$"

Route9_Speaker_Camper2:
	.string "TROY$"

Route9_Speaker_Picnicker1:
	.string "RINA$"

Route9_Speaker_Picnicker2:
	.string "MEL$"

Route9_Speaker_Hiker1:
	.string "GABE$"

Route9_Speaker_Hiker2:
	.string "RUSTY$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route9_EventScript_Camper1::
	setspeaker Route9_Speaker_Camper1
	trainerbattle_single TRAINER_ROUTE9_CAMPER_1, Route9_Text_Camper1_Intro, Route9_Text_Camper1_Defeat, Route9_EventScript_Camper1_After
	end

Route9_EventScript_Camper1_After::
	setspeaker Route9_Speaker_Camper1
	msgbox Route9_Text_Camper1_After, MSGBOX_NPC
	closemessage
	release
	end

Route9_EventScript_Camper2::
	setspeaker Route9_Speaker_Camper2
	trainerbattle_single TRAINER_ROUTE9_CAMPER_2, Route9_Text_Camper2_Intro, Route9_Text_Camper2_Defeat, Route9_EventScript_Camper2_After
	end

Route9_EventScript_Camper2_After::
	setspeaker Route9_Speaker_Camper2
	msgbox Route9_Text_Camper2_After, MSGBOX_NPC
	closemessage
	release
	end

Route9_EventScript_Picnicker1::
	setspeaker Route9_Speaker_Picnicker1
	trainerbattle_single TRAINER_ROUTE9_PICNICKER_1, Route9_Text_Picnicker1_Intro, Route9_Text_Picnicker1_Defeat, Route9_EventScript_Picnicker1_After
	end

Route9_EventScript_Picnicker1_After::
	setspeaker Route9_Speaker_Picnicker1
	msgbox Route9_Text_Picnicker1_After, MSGBOX_NPC
	closemessage
	release
	end

Route9_EventScript_Picnicker2::
	setspeaker Route9_Speaker_Picnicker2
	trainerbattle_single TRAINER_ROUTE9_PICNICKER_2, Route9_Text_Picnicker2_Intro, Route9_Text_Picnicker2_Defeat, Route9_EventScript_Picnicker2_After
	end

Route9_EventScript_Picnicker2_After::
	setspeaker Route9_Speaker_Picnicker2
	msgbox Route9_Text_Picnicker2_After, MSGBOX_NPC
	closemessage
	release
	end

Route9_EventScript_Hiker1::
	setspeaker Route9_Speaker_Hiker1
	trainerbattle_single TRAINER_ROUTE9_HIKER_1, Route9_Text_Hiker1_Intro, Route9_Text_Hiker1_Defeat, Route9_EventScript_Hiker1_After
	end

Route9_EventScript_Hiker1_After::
	setspeaker Route9_Speaker_Hiker1
	msgbox Route9_Text_Hiker1_After, MSGBOX_NPC
	closemessage
	release
	end

Route9_EventScript_Hiker2::
	setspeaker Route9_Speaker_Hiker2
	trainerbattle_single TRAINER_ROUTE9_HIKER_2, Route9_Text_Hiker2_Intro, Route9_Text_Hiker2_Defeat, Route9_EventScript_Hiker2_After
	end

Route9_EventScript_Hiker2_After::
	setspeaker Route9_Speaker_Hiker2
	msgbox Route9_Text_Hiker2_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ TEXT
@ =========================================================

Route9_Text_Camper1_Intro:
	.string "ROCK TUNNEL is ahead.\p"
	.string "Let's see how strong you are!$"

Route9_Text_Camper1_Defeat:
	.string "You packed a punch!$"

Route9_Text_Camper1_After:
	.string "I'll stock up before the tunnel.$"

Route9_Text_Camper2_Intro:
	.string "I like the breeze up here.\p"
	.string "Battle me!$"

Route9_Text_Camper2_Defeat:
	.string "Wind knocked out of me!$"

Route9_Text_Camper2_After:
	.string "I'll camp by the gates for a while.$"

Route9_Text_Picnicker1_Intro:
	.string "This route feels quiet.\p"
	.string "A battle will wake me up!$"

Route9_Text_Picnicker1_Defeat:
	.string "Wide awake now!$"

Route9_Text_Picnicker1_After:
	.string "I'll keep my team ready.$"

Route9_Text_Picnicker2_Intro:
	.string "I came for a walk.\p"
	.string "Don't hold back!$"

Route9_Text_Picnicker2_Defeat:
	.string "That was fun!$"

Route9_Text_Picnicker2_After:
	.string "CERULEAN is close, right?$"

Route9_Text_Hiker1_Intro:
	.string "These rocks are perfect\n"
	.string "for training!$"

Route9_Text_Hiker1_Defeat:
	.string "You broke through!$"

Route9_Text_Hiker1_After:
	.string "Back to the trail.$"

Route9_Text_Hiker2_Intro:
	.string "I can see the tunnel from here.\p"
	.string "Let's battle!$"

Route9_Text_Hiker2_Defeat:
	.string "Steady... I slipped.$"

Route9_Text_Hiker2_After:
	.string "I'll work on my footing.$"
