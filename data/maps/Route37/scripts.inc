Route37_MapScripts::
	.byte 0

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"
