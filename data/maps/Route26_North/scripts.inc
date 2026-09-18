Route26_North_MapScripts::
	.byte 0

Route26_North_Speaker_CooltrainerF1:
	.string "LENA$"

Route26_North_Speaker_CooltrainerM:
	.string "BRETT$"

Route26_North_Speaker_CooltrainerF2:
	.string "NIA$"

Route26_North_EventScript_CooltrainerF1::
	setspeaker Route26_North_Speaker_CooltrainerF1
	trainerbattle_single TRAINER_ROUTE26N_COOLTRAINER_F1, Route26_North_Text_CooltrainerF1_Intro, Route26_North_Text_CooltrainerF1_Defeat, Route26_North_EventScript_CooltrainerF1_After
	end

Route26_North_EventScript_CooltrainerF1_After::
	setspeaker Route26_North_Speaker_CooltrainerF1
	msgbox Route26_North_Text_CooltrainerF1_After, MSGBOX_NPC
	closemessage
	release
	end

Route26_North_EventScript_CooltrainerM::
	setspeaker Route26_North_Speaker_CooltrainerM
	trainerbattle_single TRAINER_ROUTE26N_COOLTRAINER_M, Route26_North_Text_CooltrainerM_Intro, Route26_North_Text_CooltrainerM_Defeat, Route26_North_EventScript_CooltrainerM_After
	end

Route26_North_EventScript_CooltrainerM_After::
	setspeaker Route26_North_Speaker_CooltrainerM
	msgbox Route26_North_Text_CooltrainerM_After, MSGBOX_NPC
	closemessage
	release
	end

Route26_North_EventScript_CooltrainerF2::
	setspeaker Route26_North_Speaker_CooltrainerF2
	trainerbattle_single TRAINER_ROUTE26N_COOLTRAINER_F2, Route26_North_Text_CooltrainerF2_Intro, Route26_North_Text_CooltrainerF2_Defeat, Route26_North_EventScript_CooltrainerF2_After
	end

Route26_North_EventScript_CooltrainerF2_After::
	setspeaker Route26_North_Speaker_CooltrainerF2
	msgbox Route26_North_Text_CooltrainerF2_After, MSGBOX_NPC
	closemessage
	release
	end

Route26_North_Text_CooltrainerF1_Intro:
	.string "Anyone reaching this far should know\n"
	.string "how to keep a team composed.\p"
	.string "Let's see yours.$"

Route26_North_Text_CooltrainerF1_Defeat:
	.string "Your rhythm never slipped!$"

Route26_North_Text_CooltrainerF1_After:
	.string "The best trainers stay graceful even\n"
	.string "when the path gets steep.$"

Route26_North_Text_CooltrainerM_Intro:
	.string "These cliffs separate prepared trainers\n"
	.string "from the rest.\p"
	.string "Battle me!$"

Route26_North_Text_CooltrainerM_Defeat:
	.string "You handled the climb.$"

Route26_North_Text_CooltrainerM_After:
	.string "A strong team needs offense, defense,\n"
	.string "and the nerve to push onward.$"

Route26_North_Text_CooltrainerF2_Intro:
	.string "I test my team here before I head for\n"
	.string "the LEAGUE.\p"
	.string "You can be my next match.$"

Route26_North_Text_CooltrainerF2_Defeat:
	.string "That was a solid test.$"

Route26_North_Text_CooltrainerF2_After:
	.string "If you can stay sharp on ROUTE 26,\n"
	.string "you're ready for the next step.$"
