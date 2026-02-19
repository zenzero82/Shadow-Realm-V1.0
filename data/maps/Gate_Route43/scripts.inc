Gate_Route43_MapScripts::
	.byte 0

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Route43Gate_Text_OfficerFoundTM:
	.string "I got chased from my post by these\n"
	.string "thugs in black.\p"
	.string "They left this behind.\p"
	.string "It makes me uncomfortable. Could\n"
	.string "you take it away?$"

Gate_Route43_Rocket_Text_MakingABundle:
	.string "He-he-he. We're making a bundle.\p"
	.string "Everyone wants to see what's going\n"
	.string "on up at LAKE OF RAGE.$"

