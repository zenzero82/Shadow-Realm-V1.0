saffron_gateroute8_MapScripts::
	.byte 0

Gate_SaffronCity_Route8_Speaker_Guard:
	.string "Officer Mace$"

Gate_SaffronCity_Route8_EventScript_Guard::
	setspeaker Gate_SaffronCity_Route8_Speaker_Guard
	msgbox Route8_Text_SaffronGateOfficer, MSGBOX_NPC
	end

Route8_Text_SaffronGateOfficer:
	.string "Have you been to LAVENDER\n"
	.string "TOWN?\p"
	.string "Keep an ear on the radio.\n"
	.string "CIPHER may be using the\l"
	.string "airwaves.$"
