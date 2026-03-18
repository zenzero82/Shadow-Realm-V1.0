route25_billshouse_MapScripts::
	.byte 0

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

Route25BillsHouse_Speaker_Bill:
	.string "BILL$"

Route25BillsHouse_Speaker_Sophocles:
	.string "SOPHOCLES$"

Route25BillsHouse_Speaker_Molayne:
	.string "MOLAYNE$"

@ =================================================
@ NPC SCRIPTS
@ =================================================

Route25BillsHouse_EventScript_Bill::
	faceplayer
	setspeaker Route25BillsHouse_Speaker_Bill
	msgbox Route25BillsHouse_Text_Bill, MSGBOX_NPC
	setflag FLAG_SYS_NOT_SOMEONES_PC
	end

Route25BillsHouse_EventScript_Sophocles::
	faceplayer
	setspeaker Route25BillsHouse_Speaker_Sophocles
	msgbox Route25BillsHouse_Text_Sophocles, MSGBOX_NPC
	end

Route25BillsHouse_EventScript_Molayne::
	faceplayer
	setspeaker Route25BillsHouse_Speaker_Molayne
	msgbox Route25BillsHouse_Text_Molayne, MSGBOX_NPC
	end

@ =================================================
@ TEXT
@ =================================================

Route25BillsHouse_Text_Bill:
	.string "Hey, I'm BILL. We just boosted\n"
	.string "the PC STORAGE SYSTEM with bigger\l"
	.string "boxes and smarter indexing - thanks\l"
	.string "to SOPHOCLES, MOLAYNE, and ZEN!\p"
	.string "Oh you met EUSINE? Yeah, he's been\n"
	.string "looking for this special POKéMON for\l"
	.string "a while now. I think I might have\l"
	.string "seen it one time in the area, but\l"
	.string "we can never know for sure.$"

Route25BillsHouse_Text_Sophocles:
	.string "I've been stress-testing the new\n"
	.string "box grid and the search cache.\l"
	.string "ZEN's prefetch idea kept it snappy\l"
	.string "even with tons more POKéMON!$"

Route25BillsHouse_Text_Molayne:
	.string "I'm wiring the interface so the\n"
	.string "expansion feels seamless in the\l"
	.string "field. ZEN suggested quick-swap\l"
	.string "flows to make it feel smooth!$"
