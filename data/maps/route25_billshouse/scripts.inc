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
	.string "Hey, I'm BILL. I developed the\n"
	.string "POKEMON STORAGE SYSTEM. These\l"
	.string "guys came from a different\l"
	.string "timeline, but boy are they\l"
	.string "smart!$"

Route25BillsHouse_Text_Sophocles:
	.string "I've been testing BILL's system\n"
	.string "with all kinds of hardware.\l"
	.string "Optimization is everything if we\l"
	.string "want it fast and reliable!$"

Route25BillsHouse_Text_Molayne:
	.string "I'm helping BILL design access\n"
	.string "from the player's bag. It should\l"
	.string "make storage management way more\l"
	.string "convenient!$"
