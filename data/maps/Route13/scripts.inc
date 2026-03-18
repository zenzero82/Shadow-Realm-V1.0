Route13_MapScripts::
	.byte 0

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end	

Route13_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Look! Right there, at the left\n"
	.string "side of the post.$"

	Route13_Text_Sign:
	.string "ROUTE 13\p"
	.string "NORTH TO SILENCE BRIDGE$"

Route13_Text_DirectionsSign:
	.string "NORTH TO LAVENDER TOWN\p"
	.string "WEST TO FUCHSIA CITY$"

