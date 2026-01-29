Route3_MapScripts::
	.byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Route3_Speaker_Youngster:
	.string "YOUNGSTER$"

Route3_Speaker_Lass:
	.string "LASS$"

Route3_Speaker_Firebreather:
	.string "FIREBREATHER$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route3_EventScript_Youngster1::
	setspeaker Route3_Speaker_Youngster
	trainerbattle_single TRAINER_RT3_YOUNGSTER1, Route3_Text_Youngster1_Intro, Route3_Text_Youngster1_Defeat, Route3_EventScript_Youngster1_After
	end

Route3_EventScript_Youngster1_After::
	setspeaker Route3_Speaker_Youngster
	msgbox Route3_Text_Youngster1_After, MSGBOX_NPC
	closemessage
	release
	end

Route3_EventScript_Youngster2::
	setspeaker Route3_Speaker_Youngster
	trainerbattle_single TRAINER_RT3_YOUNGSTER2, Route3_Text_Youngster2_Intro, Route3_Text_Youngster2_Defeat, Route3_EventScript_Youngster2_After
	end

Route3_EventScript_Youngster2_After::
	setspeaker Route3_Speaker_Youngster
	msgbox Route3_Text_Youngster2_After, MSGBOX_NPC
	closemessage
	release
	end

Route3_EventScript_Lass::
	setspeaker Route3_Speaker_Lass
	trainerbattle_single TRAINER_RT3_LASS, Route3_Text_Lass_Intro, Route3_Text_Lass_Defeat, Route3_EventScript_Lass_After
	end

Route3_EventScript_Lass_After::
	setspeaker Route3_Speaker_Lass
	msgbox Route3_Text_Lass_After, MSGBOX_NPC
	closemessage
	release
	end

Route3_EventScript_Firebreather::
	trainerbattle_single TRAINER_RT3_FIREBREATHER, Route3_Text_Firebreather_Intro, Route3_Text_Firebreather_Defeat, Route3_EventScript_Firebreather_After
	end

Route3_EventScript_Firebreather_After::
	setspeaker Route3_Speaker_Firebreather
	msgbox Route3_Text_Firebreather_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ TEXT
@ =========================================================

Route3_Text_Youngster1_Intro:
	.string "ROUTE 3 is a great warm-up!\p"
	.string "Let's battle!$"

Route3_Text_Youngster1_Defeat:
	.string "Whoa! You got me!$"

Route3_Text_Youngster1_After:
	.string "Guess I need more training.$"

Route3_Text_Youngster2_Intro:
	.string "I'm raising my team out here.\p"
	.string "Let's go!$"

Route3_Text_Youngster2_Defeat:
	.string "No way...$"

Route3_Text_Youngster2_After:
	.string "I won't forget this loss.$"

Route3_Text_Lass_Intro:
	.string "Cute doesn't mean weak!\p"
	.string "Here I come!$"

Route3_Text_Lass_Defeat:
	.string "Aww, I lost!$"

Route3_Text_Lass_After:
	.string "I need a new strategy.$"

Route3_Text_Firebreather_Intro:
	.string "Feel the heat!\p"
	.string "Let's battle!$"

Route3_Text_Firebreather_Defeat:
	.string "My flames fizzled...$"

Route3_Text_Firebreather_After:
	.string "I'll stoke the fire next time.$"
