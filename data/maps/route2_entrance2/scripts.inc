route2_entrance2_MapScripts::
	.byte 0

route2_entrance2_EventScript_Officer::
	lock
	faceplayer
	msgbox route2_entrance2_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

route2_entrance2_Text_Officer:
	.string "Route 2 has been quiet, but we're\n"
	.string "keeping an eye out for trouble.\p"
	.string "Keep your POKéMON close, alright?$"
