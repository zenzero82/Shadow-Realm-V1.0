Route46_MapScripts::
	.byte 0


Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	goto EventScript_GimmighoulSignpost

Route46_Text_Sign:
	.string "ROUTE 46\n"
	.string "MOUNTAIN RD. AHEAD$"


