route2_entrance3_MapScripts::
	.byte 0

route2_entrance3_EventScript_Officer::
	lock
	faceplayer
	msgbox route2_entrance3_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

route2_entrance3_Text_Officer:
	.string "Some trainers reported their\n"
	.string "POKéMON acting strange near the\n"
	.string "forest entrance. Stay cautious.$"
