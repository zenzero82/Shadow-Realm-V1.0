Route2_MapScripts::
	.byte 0


Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"

