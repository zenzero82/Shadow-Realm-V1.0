Route38_MapScripts::
	.byte 0

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end


Route38_Text_Sign:
	.string "ROUTE 38\p"
	.string "OLIVINE CITY - ECRUTEAK CITY$"


Route38_Text_WaterSign:
	.string "NO SWIMMING OR FISHING.\n"
	.string "WATER FOR FARMING ONLY.\p"
	.string "-ECRUTEAK COUNCIL$"
