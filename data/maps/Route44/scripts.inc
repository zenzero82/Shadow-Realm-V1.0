Route44_MapScripts::
	.byte 0

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end


Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end


Route44_Text_Sign1:
    .string "ROUTE 44\n"
    .string "ICE PATH AHEAD$"


Route44_Text_Sign2:
    .string "ROUTE 44\p"
    .string "MAHOGANY TOWN - BLACKTHORN CITY$"
