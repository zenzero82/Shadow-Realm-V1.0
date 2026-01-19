Reds_House_MapScripts::
	.byte 0

Speaker_RedsMom:
	.string "Red's Mom$"

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter

	setspeaker Speaker_RedsMom
	playse SE_PIN
	dofieldeffect FLDEFF_EXCLAMATION_MARK_ICON
	waitfieldeffect FLDEFF_EXCLAMATION_MARK_ICON

	msgbox RedsHouse_Text_MomShocked, MSGBOX_DEFAULT
	closemessage

	msgbox RedsHouse_Text_MomThoughtItWasRed, MSGBOX_DEFAULT
	closemessage

	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage

	msgbox RedsHouse_Text_MomAskTime, MSGBOX_DEFAULT
	closemessage

	checkplayergender
	copyvar VAR_TEMP_4, VAR_TEMP_0
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate

	setvar VAR_TEMP_0, 1
	call PalletTown_RedsHouse_1F_EventScript_MomAfterMessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	call PalletTown_RedsHouse_1F_EventScript_MomAfterMessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfterMessage::
	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	return

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

RedsHouse_Text_MomShocked:
	.string "Is that you, RED?!$"

RedsHouse_Text_MomThoughtItWasRed:
	.string "Oh, I thought you were my son for a second!$"

RedsHouse_Text_Mom2:
	.string "I worry about RED getting caught up in\n"
	.string "all this chaos, but he's very strong.\p"
	.string "I'm proud he's out there doing what he\n"
	.string "believes in…\p"
	.string "I just hope he remembers he still has\n"
	.string "a home to come back to.$"

RedsHouse_Text_MomAskTime:
	.string "By the way, do you know what time\n"
	.string "it is?\p"
	.string "I should check the clock before\n"
	.string "you head back out.$"

RedsHouse_Text_TV:
	.string "The news is talking about strange\n"
	.string "portals and suspicious\l"
	.string "people appearing in KANTO…\p"
	.string "It's hard to understand what's going on.$"
