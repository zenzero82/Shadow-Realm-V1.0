Reds_House_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Oh, hello!\p"
	.string "My son RED left on his POKEMON\n"
	.string "journey and eventually became the\l"
	.string "Champion of KANTO.\p"
	.string "Ever since then, he almost never\n"
	.string "comes home.\p"
	.string "With all these strange things on the\n"
	.string "news lately, I can't help but worry\l"
	.string "about him…$"

RedsHouse_Text_Mom2:
	.string "I worry about RED getting caught up in\n"
	.string "all this chaos, but he's very strong.\p"
	.string "I'm proud he's out there doing what he\n"
	.string "believes in…\p"
	.string "I just hope he remembers he still has\n"
	.string "a home to come back to.$"

RedsHouse_Text_TV:
	.string "The news is talking about strange\n"
	.string "portals and suspicious\l"
	.string "people appearing in KANTO…\p"
	.string "It's hard to understand what's going on.$"
