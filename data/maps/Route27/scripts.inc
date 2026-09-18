Route27_MapScripts::
	.byte 0

@ =========================================================
@ SPEAKERS
@ =========================================================

Route27_Speaker_FatMan:
	.string "GUIDE$"

Route27_Speaker_CooltrainerF1:
	.string "MARA$"

Route27_Speaker_CooltrainerM:
	.string "RYAN$"

Route27_Speaker_Rocker:
	.string "VINCE$"

Route27_Speaker_Fisherman1:
	.string "NOLAN$"

Route27_Speaker_Psychic:
	.string "ELI$"

Route27_Speaker_CooltrainerF2:
	.string "TESSA$"

Route27_Speaker_Fisherman2:
	.string "BRODY$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route27_EventScript_CooltrainerF1::
	setspeaker Route27_Speaker_CooltrainerF1
	trainerbattle_single TRAINER_ROUTE27_COOLTRAINER_F1, Route27_Text_CooltrainerF1_Intro, Route27_Text_CooltrainerF1_Defeat, Route27_EventScript_CooltrainerF1_After
	end

Route27_EventScript_CooltrainerF1_After::
	setspeaker Route27_Speaker_CooltrainerF1
	msgbox Route27_Text_CooltrainerF1_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_CooltrainerM::
	setspeaker Route27_Speaker_CooltrainerM
	trainerbattle_single TRAINER_ROUTE27_COOLTRAINER_M, Route27_Text_CooltrainerM_Intro, Route27_Text_CooltrainerM_Defeat, Route27_EventScript_CooltrainerM_After
	end

Route27_EventScript_CooltrainerM_After::
	setspeaker Route27_Speaker_CooltrainerM
	msgbox Route27_Text_CooltrainerM_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_Rocker::
	setspeaker Route27_Speaker_Rocker
	trainerbattle_single TRAINER_ROUTE27_ROCKER, Route27_Text_Rocker_Intro, Route27_Text_Rocker_Defeat, Route27_EventScript_Rocker_After
	end

Route27_EventScript_Rocker_After::
	setspeaker Route27_Speaker_Rocker
	msgbox Route27_Text_Rocker_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_Fisherman1::
	setspeaker Route27_Speaker_Fisherman1
	trainerbattle_single TRAINER_ROUTE27_FISHERMAN_1, Route27_Text_Fisherman1_Intro, Route27_Text_Fisherman1_Defeat, Route27_EventScript_Fisherman1_After
	end

Route27_EventScript_Fisherman1_After::
	setspeaker Route27_Speaker_Fisherman1
	msgbox Route27_Text_Fisherman1_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_Psychic::
	setspeaker Route27_Speaker_Psychic
	trainerbattle_single TRAINER_ROUTE27_PSYCHIC, Route27_Text_Psychic_Intro, Route27_Text_Psychic_Defeat, Route27_EventScript_Psychic_After
	end

Route27_EventScript_Psychic_After::
	setspeaker Route27_Speaker_Psychic
	msgbox Route27_Text_Psychic_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_CooltrainerF2::
	setspeaker Route27_Speaker_CooltrainerF2
	trainerbattle_single TRAINER_ROUTE27_COOLTRAINER_F2, Route27_Text_CooltrainerF2_Intro, Route27_Text_CooltrainerF2_Defeat, Route27_EventScript_CooltrainerF2_After
	end

Route27_EventScript_CooltrainerF2_After::
	setspeaker Route27_Speaker_CooltrainerF2
	msgbox Route27_Text_CooltrainerF2_After, MSGBOX_NPC
	closemessage
	release
	end

Route27_EventScript_Fisherman2::
	setspeaker Route27_Speaker_Fisherman2
	trainerbattle_single TRAINER_ROUTE27_FISHERMAN_2, Route27_Text_Fisherman2_Intro, Route27_Text_Fisherman2_Defeat, Route27_EventScript_Fisherman2_After
	end

Route27_EventScript_Fisherman2_After::
	setspeaker Route27_Speaker_Fisherman2
	msgbox Route27_Text_Fisherman2_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ NPCS
@ =========================================================

Route27_EventScript_FatMan::
	faceplayer
	setspeaker Route27_Speaker_FatMan
	msgbox Route27_Text_FatMan, MSGBOX_NPC
	end

@ =========================================================
@ SIGNS
@ =========================================================

Route27_EventScript_TohjoFallsSign::
	msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
	end

@ =========================================================
@ TEXT
@ =========================================================

Route27_Text_FatMan:
	.string "ROUTE 27 is what brings KANTO\n"
	.string "and JOHTO together.$"

Route27_Text_CooltrainerF1_Intro:
	.string "The road changes here.\p"
	.string "Let's see if your team can keep up!$"

Route27_Text_CooltrainerF1_Defeat:
	.string "You kept pace just fine!$"

Route27_Text_CooltrainerF1_After:
	.string "Strong trainers pass through here\n"
	.string "from both regions.$"

Route27_Text_CooltrainerM_Intro:
	.string "I train where the routes get rough.\p"
	.string "Battle me!$"

Route27_Text_CooltrainerM_Defeat:
	.string "You handled the pressure!$"

Route27_Text_CooltrainerM_After:
	.string "A balanced team matters when the\n"
	.string "path starts testing you.$"

Route27_Text_Rocker_Intro:
	.string "Hear that current?\p"
	.string "My team fights to that beat!$"

Route27_Text_Rocker_Defeat:
	.string "You drowned out my set...$"

Route27_Text_Rocker_After:
	.string "Electric sound, hard rhythm,\n"
	.string "and still you broke through.$"

Route27_Text_Fisherman1_Intro:
	.string "These waters keep good battlers busy.\p"
	.string "Let's cast off!$"

Route27_Text_Fisherman1_Defeat:
	.string "That catch slipped away!$"

Route27_Text_Fisherman1_After:
	.string "Patience works for fishing.\n"
	.string "Maybe I need more in battle too.$"

Route27_Text_Psychic_Intro:
	.string "I sensed you'd come this way.\p"
	.string "Now I want to test that vision.$"

Route27_Text_Psychic_Defeat:
	.string "My foresight failed me...$"

Route27_Text_Psychic_After:
	.string "Your focus overwhelmed the future\n"
	.string "I thought I saw.$"

Route27_Text_CooltrainerF2_Intro:
	.string "A trainer this far out should be\n"
	.string "ready for a real fight!$"

Route27_Text_CooltrainerF2_Defeat:
	.string "You were ready, all right!$"

Route27_Text_CooltrainerF2_After:
	.string "That kind of composure will take\n"
	.string "you a long way.$"

Route27_Text_Fisherman2_Intro:
	.string "I battle between bites.\p"
	.string "Show me your technique!$"

Route27_Text_Fisherman2_Defeat:
	.string "You reeled me in!$"

Route27_Text_Fisherman2_After:
	.string "The best anglers know when to wait\n"
	.string "and when to strike.$"

TohjoFalls_Text_Sign:
	.string "TOHJO FALLS\p"
	.string "THE LINK BETWEEN KANTO AND JOHTO$"
