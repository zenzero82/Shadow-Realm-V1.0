Route30_House_MapScripts::
	.byte 0

Route30_House_Speaker_Man:
	.string "HANK$"

Route30_House_EventScript_Man::
	faceplayer
	setspeaker Route30_House_Speaker_Man
	msgbox Route30_House_Text_Man, MSGBOX_NPC
	end

Route30_House_Text_Man:
	.string "I get a lot of visitors from\n"
	.string "CHERRYGROVE and VIOLET.$"
