Gate_NationalPark_MapScripts::
	.byte 0

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_Attendant::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Attendant, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_BAttendant::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Attendant, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BugCatcher1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BugCatcher2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Policeman:
	.string "The BUG-CATCHING CONTEST\n"
	.string "is held in the PARK.$"

Route35NationalParkGate_Text_Attendant:
	.string "The BUG-CATCHING CONTEST\n"
	.string "is on today. Good luck!$"

Route35NationalParkGate_Text_Rocker:
	.string "I can't wait to see who wins\n"
	.string "the contest today.$"

Route35NationalParkGate_Text_BugCatcher1:
	.string "I'm going to catch the strongest\n"
	.string "bug POKEMON!$"

Route35NationalParkGate_Text_BugCatcher2:
	.string "I love big, tough bug POKEMON.$"

Route35NationalParkGate_Text_Beauty:
	.string "Bug POKEMON are full of surprises.$"

