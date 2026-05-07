GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_Speaker_Naomi:
	.string "NAOMI$"

GoldenrodCity_BillsHouse_Speaker_Keira:
	.string "KEIRA$"

GoldenrodCity_BillsHouse_EventScript_Naomi::
	lock
	faceplayer
	setspeaker GoldenrodCity_BillsHouse_Speaker_Naomi
	msgbox GoldenrodCity_BillsHouse_Text_Naomi, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_BillsHouse_EventScript_Keira::
	lock
	faceplayer
	setspeaker GoldenrodCity_BillsHouse_Speaker_Keira
	msgbox GoldenrodCity_BillsHouse_Text_Keira, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_BillsHouse_Text_Naomi:
	.string "BILL's out again. He always vanishes\n"
	.string "when things in the city get strange.$"

GoldenrodCity_BillsHouse_Text_Keira:
	.string "I like when uncle BILL visits.\n"
	.string "He makes the PC feel magical.$"
