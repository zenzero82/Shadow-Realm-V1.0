Route43_MapScripts::
	.byte 0

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end


Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_Sign2:
	.string "ROUTE 43\p"
	.string "LAKE OF RAGE - MAHOGANY TOWN$"

Route43_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "All POKéMON have pros and cons\n"
	.string "depending on their types.\p"
	.string "If their types differ, a higher-\n"
	.string "level POKéMON may lose in battle.\p"
	.string "Learn which types are strong and\n"
	.string "weak against your POKéMON's type.$"
