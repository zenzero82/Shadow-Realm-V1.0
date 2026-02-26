Route31_MapScripts::
	.byte 0

Route31_EventScript_Youngster::
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_NPC
	end

Route31_EventScript_BugCatcher::
	faceplayer
	msgbox Route31_Text_BugCatcher, MSGBOX_NPC
	end

Route31_EventScript_FatMan::
	faceplayer
	msgbox Route31_Text_FatMan, MSGBOX_NPC
	end

Route31_EventScript_Boy::
	faceplayer
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
