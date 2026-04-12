Route12_MapScripts::
	.byte 0

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "ROUTE 12\p"
	.string "NORTH TO LAVENDER TOWN$"

Route12_Text_FishingSpotSign:
	.string "FISHING SPOT$"
