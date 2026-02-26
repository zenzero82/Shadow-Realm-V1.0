route2_entrance1_MapScripts::
	.byte 0

route2_entrance1_EventScript_Officer::
	lock
	faceplayer
	msgbox route2_entrance1_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

route2_entrance1_Text_Officer:
	.string "We're on alert after reports of\n"
	.string "strange POKéMON in VIRIDIAN FOREST.\p"
	.string "If you see anything odd, report it.$"
