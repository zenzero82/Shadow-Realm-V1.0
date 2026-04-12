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
	faceplayer
	setspeaker Route31_Speaker_Youngster
	msgbox Route31_Text_Youngster, MSGBOX_NPC
	end

Route31_EventScript_BugCatcher::
	faceplayer
	setspeaker Route31_Speaker_BugCatcher
	msgbox Route31_Text_BugCatcher, MSGBOX_NPC
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

Route31_Text_Youngster:
	.string "DARK CAVE is scary without FLASH.\n"
	.string "I'm staying outside for now.$"

Route31_Text_BugCatcher:
	.string "I saw some strange bugs near the\n"
	.string "cave. They move fast.$"

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
