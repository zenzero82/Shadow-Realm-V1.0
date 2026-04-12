Route35_MapScripts::
	.byte 0

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end


Route35_Text_Sign:
	.string "ROUTE 35$"


Route35_Text_Sign2:
	.string "NATIONAL PARK GATE$"
