Reds_House_2ndFL_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_Bookshelf1::
	msgbox RedsHouse_Text_Bookshelf1, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_Bookshelf2::
	msgbox RedsHouse_Text_Bookshelf2, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_Rest::
	msgbox RedsHouse_Text_Rest_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RedsHouse_2F_EventScript_Rest_No
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreenswapbuffers FADE_FROM_BLACK
	end

PalletTown_RedsHouse_2F_EventScript_Rest_No::
	closemessage
	end

RedsHouse_Text_NES:
	.string "{PLAYER} played the NES.\p"
	.string "Better get going--no time to lose!$"

RedsHouse_Text_PC:
	.string "It looks like it hasn't been used\n"
	.string "in a long time…$"

RedsHouse_Text_Bookshelf1:
	.string "Old comic books line the shelf.\p"
	.string "They're dusty, but neatly stacked.$"

RedsHouse_Text_Bookshelf2:
	.string "These issues are faded and worn.\p"
	.string "Someone must have read them a lot.$"

RedsHouse_Text_Rest_Ask:
	.string "Take a quick rest?$"
