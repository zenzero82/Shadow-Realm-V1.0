Route39_MapScripts::
	.byte 0

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVINE CITY - ECRUTEAK CITY$"


Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end


Route39_Text_MoomooFarmSign:
	.string "MOOMOO FARM\p"
	.string "Enjoy Our Fresh and Tasty Milk$"


Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end


Route39_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Use HEADBUTT on trees to shake\n"
	.string "POKéMON out.\p"
	.string "Different kinds of POKéMON\n"
	.string "drop out of trees.\p"
	.string "Use HEADBUTT on any tree\n"
	.string "you see!$"
