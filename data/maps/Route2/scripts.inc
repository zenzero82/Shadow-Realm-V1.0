Route2_MapScripts::
	.byte 0

Route2_Speaker_Hiker:
	.string "HIKER$"

Route2_EventScript_Hiker::
	faceplayer
	setspeaker Route2_Speaker_Hiker
	msgbox Route2_Text_Hiker_Block, MSGBOX_NPC
	end


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

Route2_Text_Hiker_Block:
	.string "Sorry, you can't pass through\n"
	.string "yet.$"
