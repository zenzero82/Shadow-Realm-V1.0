Route26_MapScripts::
	.byte 0

Route26_Speaker_Psychic:
	.string "SEER$"

Route26_Speaker_CooltrainerM:
	.string "GARRETT$"

Route26_EventScript_Psychic::
	setspeaker Route26_Speaker_Psychic
	trainerbattle_single TRAINER_ROUTE26_PSYCHIC, Route26_Text_Psychic_Intro, Route26_Text_Psychic_Defeat, Route26_EventScript_Psychic_After
	end

Route26_EventScript_Psychic_After::
	setspeaker Route26_Speaker_Psychic
	msgbox Route26_Text_Psychic_After, MSGBOX_NPC
	closemessage
	release
	end

Route26_EventScript_CooltrainerM::
	setspeaker Route26_Speaker_CooltrainerM
	trainerbattle_single TRAINER_ROUTE26_COOLTRAINER_M, Route26_Text_CooltrainerM_Intro, Route26_Text_CooltrainerM_Defeat, Route26_EventScript_CooltrainerM_After
	end

Route26_EventScript_CooltrainerM_After::
	setspeaker Route26_Speaker_CooltrainerM
	msgbox Route26_Text_CooltrainerM_After, MSGBOX_NPC
	closemessage
	release
	end

Route26_EventScript_GymSign::
	msgbox Route26_Text_GymSign, MSGBOX_SIGN
	end


Route26_EventScript_CitySign::
	msgbox Route26_Text_CitySign, MSGBOX_SIGN
	end


Route26_EventScript_WallyHouseSign::
	msgbox Route26_Text_WallyHouseSign, MSGBOX_SIGN
	end


Route26_Text_GymSign:
	.string "PETALBURG CITY POKéMON GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"


Route26_Text_CitySign:
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"


Route26_Text_WallyHouseSign:
	.string "WALLY'S HOUSE$"

Route26_Text_Psychic_Intro:
	.string "The waves below are noisy, but a calm\n"
	.string "mind can still hear what matters.\p"
	.string "Show me yours.$"

Route26_Text_Psychic_Defeat:
	.string "Your focus cut right through mine.$"

Route26_Text_Psychic_After:
	.string "A steady heart carries a trainer farther\n"
	.string "than any prediction.$"

Route26_Text_CooltrainerM_Intro:
	.string "This stretch to the LEAGUE is no place\n"
	.string "for a sloppy team.\p"
	.string "Let's battle!$"

Route26_Text_CooltrainerM_Defeat:
	.string "You fought like someone ready to climb.$"

Route26_Text_CooltrainerM_After:
	.string "Around here, endurance matters just as\n"
	.string "much as raw power.$"
