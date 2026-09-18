Route31_MapScripts::
	.byte 0

Route31_Speaker_Youngster:
	.string "JARED$"

Route31_Speaker_BugCatcher:
	.string "ELI$"

Route31_Speaker_FatMan:
	.string "ARTHUR$"

Route31_Speaker_Boy:
	.string "NOAH$"

Route31_EventScript_Youngster::
	setspeaker Route31_Speaker_Youngster
	trainerbattle_single TRAINER_ROUTE31_YOUNGSTER, Route31_Text_Youngster_Intro, Route31_Text_Youngster_Defeat, Route31_EventScript_Youngster_After
	end

Route31_EventScript_BugCatcher::
	setspeaker Route31_Speaker_BugCatcher
	trainerbattle_single TRAINER_ROUTE31_BUG_CATCHER, Route31_Text_BugCatcher_Intro, Route31_Text_BugCatcher_Defeat, Route31_EventScript_BugCatcher_After
	end

Route31_EventScript_Youngster_After::
	setspeaker Route31_Speaker_Youngster
	msgbox Route31_Text_Youngster_After, MSGBOX_NPC
	closemessage
	release
	end

Route31_EventScript_BugCatcher_After::
	setspeaker Route31_Speaker_BugCatcher
	msgbox Route31_Text_BugCatcher_After, MSGBOX_NPC
	closemessage
	release
	end

Route31_EventScript_FatMan::
	faceplayer
	setspeaker Route31_Speaker_FatMan
	msgbox Route31_Text_FatMan, MSGBOX_NPC
	end

Route31_EventScript_Boy::
	faceplayer
	setspeaker Route31_Speaker_Boy
	msgbox Route31_Text_Boy, MSGBOX_NPC
	end

Route31_EventScript_SignRoute31::
	msgbox Route31_Text_SignRoute31, MSGBOX_SIGN
	end

Route31_EventScript_SignDarkCave::
	msgbox Route31_Text_SignDarkCave, MSGBOX_SIGN
	end

Route31_Text_Youngster_Intro:
	.string "I came out to train before DARK\n"
	.string "CAVE. Battle me first!$"

Route31_Text_Youngster_Defeat:
	.string "Guess I'll train a bit longer...$"

Route31_Text_Youngster_After:
	.string "DARK CAVE is scary without FLASH.\n"
	.string "I'm staying outside for now.$"

Route31_Text_BugCatcher_Intro:
	.string "I saw some strange bugs near the\n"
	.string "cave. They move fast!\p"
	.string "Let's battle!$"

Route31_Text_BugCatcher_Defeat:
	.string "Too quick for my bugs...$"

Route31_Text_BugCatcher_After:
	.string "The bugs around here are stronger\n"
	.string "than the ones on ROUTE 30.$"

Route31_Text_FatMan:
	.string "The breeze from VIOLET CITY is\n"
	.string "refreshing on this route.$"

Route31_Text_Boy:
	.string "People say the RUINS nearby hide\n"
	.string "old secrets.$"

Route31_Text_SignRoute31:
	.string "ROUTE 31\n"
	.string "CHERRYGROVE CITY - VIOLET CITY$"

Route31_Text_SignDarkCave:
	.string "DARK CAVE AHEAD.$"

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end


Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route31_Text_Sign:
	.string "ROUTE 31\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"


Route31_Text_DarkCaveSign:
	.string "DARK CAVE$"
