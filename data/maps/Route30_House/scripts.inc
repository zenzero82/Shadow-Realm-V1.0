Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_Man::
	faceplayer
	msgbox Route30_House_Text_Man, MSGBOX_NPC
	end

Route30_House_Text_Man:
	.string "I get a lot of visitors from\n"
	.string "CHERRYGROVE and VIOLET.$"
