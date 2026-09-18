Route7_MapScripts::
	.byte 0

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

Route7_Text_UndergroundPathSign:
	.string "Underground Tunnel:\p"
	.string "Route 7 {RIGHT_ARROW} Route 8$"

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end


Route7_Text_LockedDoor:
	.string "It's locked…$"
