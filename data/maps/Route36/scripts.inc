Route36_MapScripts::
	.byte 0

Route36_Speaker_FatMan:
	.string "HERMAN$"

Route36_EventScript_FatMan::
	faceplayer
	setspeaker Route36_Speaker_FatMan
	msgbox Route36_Text_FatMan, MSGBOX_NPC
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end


Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end


Route36_Text_Sign_RuinsNorth:
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"


Route36_Text_Tips1:
	.string "TRAINER TIPS\n"
	.string "POKéMON stats vary--even within\l"
	.string "the same species.\p"
	.string "Their stats may be similar at first.\p"
	.string "However, differences will become\n"
	.string "pronounced as the POKéMON grow.$"

Route36_Text_FatMan:
	.string "Soon I'll be offering valuable\n"
	.string "items.\p"
	.string "That is, if you can guess my\n"
	.string "favorite day of the week!$"
