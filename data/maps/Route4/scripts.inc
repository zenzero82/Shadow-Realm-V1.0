Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_EventScript_SetHikerVisibility
	.byte 0

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Route4_Speaker_BlackBelt:
	.string "RYU$"

Route4_Speaker_Rocker:
	.string "AMP$"

Route4_Speaker_Picnicker1:
	.string "LILY$"

Route4_Speaker_Picnicker2:
	.string "MIA$"

Route4_Speaker_Brendan:
	.string "BRENDAN$"

Route4_Speaker_Hiker:
	.string "HIKER$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_EventScript_BlackBelt::
	setspeaker Route4_Speaker_BlackBelt
	trainerbattle_single TRAINER_RT4_BLACK_BELT, Route4_Text_BlackBelt_Intro, Route4_Text_BlackBelt_Defeat, Route4_EventScript_BlackBelt_After
	end

Route4_EventScript_BlackBelt_After::
	setspeaker Route4_Speaker_BlackBelt
	msgbox Route4_Text_BlackBelt_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Rocker::
	setspeaker Route4_Speaker_Rocker
	trainerbattle_single TRAINER_RT4_ROCKER, Route4_Text_Rocker_Intro, Route4_Text_Rocker_Defeat, Route4_EventScript_Rocker_After
	end

Route4_EventScript_Rocker_After::
	setspeaker Route4_Speaker_Rocker
	msgbox Route4_Text_Rocker_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Picnicker1::
	setspeaker Route4_Speaker_Picnicker1
	trainerbattle_single TRAINER_RT4_PICNICKER1, Route4_Text_Picnicker1_Intro, Route4_Text_Picnicker1_Defeat, Route4_EventScript_Picnicker1_After
	end

Route4_EventScript_Picnicker1_After::
	setspeaker Route4_Speaker_Picnicker1
	msgbox Route4_Text_Picnicker1_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Picnicker2::
	setspeaker Route4_Speaker_Picnicker2
	trainerbattle_single TRAINER_RT4_PICNICKER2, Route4_Text_Picnicker2_Intro, Route4_Text_Picnicker2_Defeat, Route4_EventScript_Picnicker2_After
	end

Route4_EventScript_Picnicker2_After::
	setspeaker Route4_Speaker_Picnicker2
	msgbox Route4_Text_Picnicker2_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Brendan1::
	setspeaker Route4_Speaker_Brendan
	trainerbattle_single TRAINER_RT4_BRENDAN1, Route4_Text_Brendan1_Intro, Route4_Text_Brendan1_Defeat, Route4_EventScript_Brendan1_After
	end

Route4_EventScript_Brendan1_After::
	setspeaker Route4_Speaker_Brendan
	msgbox Route4_Text_Brendan1_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Brendan2::
	setspeaker Route4_Speaker_Brendan
	trainerbattle_single TRAINER_RT4_BRENDAN2, Route4_Text_Brendan2_Intro, Route4_Text_Brendan2_Defeat, Route4_EventScript_Brendan2_After
	end

Route4_EventScript_Brendan2_After::
	setspeaker Route4_Speaker_Brendan
	msgbox Route4_Text_Brendan2_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_Brendan3::
	setspeaker Route4_Speaker_Brendan
	trainerbattle_single TRAINER_RT4_BRENDAN3, Route4_Text_Brendan3_Intro, Route4_Text_Brendan3_Defeat, Route4_EventScript_Brendan3_After
	end

Route4_EventScript_Brendan3_After::
	setspeaker Route4_Speaker_Brendan
	msgbox Route4_Text_Brendan3_After, MSGBOX_NPC
	closemessage
	release
	end

Route4_EventScript_SetHikerVisibility::
	checkflag FLAG_BADGE09_GET
	goto_if_eq Route4_EventScript_HikerHide
	clearflag FLAG_HIDE_ROUTE4_HIKER
	return

Route4_EventScript_HikerHide::
	setflag FLAG_HIDE_ROUTE4_HIKER
	return

Route4_EventScript_Hiker::
	lock
	faceplayer
	checkflag FLAG_BADGE09_GET
	goto_if_eq Route4_EventScript_HikerEnd
	setspeaker Route4_Speaker_Hiker
	msgbox Route4_Text_Hiker_Block, MSGBOX_NPC
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
Route4_EventScript_HikerEnd:
	release
	end

@ =========================================================
@ TEXT
@ =========================================================

Route4_Text_BlackBelt_Intro:
	.string "Route 4 is the perfect place to\n"
	.string "train!$"

Route4_Text_BlackBelt_Defeat:
	.string "My focus slipped!$"

Route4_Text_BlackBelt_After:
	.string "Back to training.$"

Route4_Text_Rocker_Intro:
	.string "Turn the volume up!\p"
	.string "Battle time!$"

Route4_Text_Rocker_Defeat:
	.string "That was a bad note.$"

Route4_Text_Rocker_After:
	.string "I'll write a better riff.$"

Route4_Text_Picnicker1_Intro:
	.string "It's such a nice day for a battle!$"

Route4_Text_Picnicker1_Defeat:
	.string "Aww, you won.$"

Route4_Text_Picnicker1_After:
	.string "Maybe next time.$"

Route4_Text_Picnicker2_Intro:
	.string "I love training out here!$"

Route4_Text_Picnicker2_Defeat:
	.string "That stings!$"

Route4_Text_Picnicker2_After:
	.string "I'll keep practicing.$"

Route4_Text_Brendan1_Intro:
	.string "Oh! Let's battle right here.$"

Route4_Text_Brendan1_Defeat:
	.string "You're strong!$"

Route4_Text_Brendan1_After:
	.string "I'll get stronger too.$"

Route4_Text_Brendan2_Intro:
	.string "Nice timing. Battle me!$"

Route4_Text_Brendan2_Defeat:
	.string "No way!$"

Route4_Text_Brendan2_After:
	.string "I'll win the next one.$"

Route4_Text_Brendan3_Intro:
	.string "Let's see how you handle this.$"

Route4_Text_Brendan3_Defeat:
	.string "You got me...$"

Route4_Text_Brendan3_After:
	.string "I'll keep training on Route 4.$"

Route4_Text_Hiker_Block:
	.string "Hold it! MT. MOON is dangerous.\p"
	.string "Come back after you've earned the\n"
	.string "BOULDER BADGE.$"

Route4_Text_MtMoonSquareSign:
	.string "MT.MOON NEW ENTRANCE\n"
	.string "DUE TO CAVE-IN\p"
	.string "WATCH YOUR STEP$"

