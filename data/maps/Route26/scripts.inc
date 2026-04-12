Route26_MapScripts::
	.byte 0

Route26_EventScript_GymSign::
	msgbox Route26_Text_GymSign, MSGBOX_SIGN
	end


Route26_EventScript_CitySign::
	msgbox Route26_Text_CitySign, MSGBOX_SIGN
	end


Route26_EventScript_WallyHouseSign::
	msgbox Route26_Text_WallyHouseSign, MSGBOX_SIGN
	end


Route26_Text_GymSign:
	.string "PETALBURG CITY POKéMON GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"


Route26_Text_CitySign:
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"


Route26_Text_WallyHouseSign:
	.string "WALLY'S HOUSE$"
