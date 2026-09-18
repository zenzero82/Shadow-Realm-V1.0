celadon_apartment2f_MapScripts::
	.byte 0

celadon_apartment2f_EventScript_Bookshelf::
	msgbox celadon_apartment2f_Text_Bookshelf, MSGBOX_SIGN
	end

celadon_apartment2f_EventScript_TV::
	msgbox celadon_apartment2f_Text_TV, MSGBOX_SIGN
	end

celadon_apartment2f_Text_Bookshelf:
	.string "A stack of decorating magazines.\p"
	.string "One issue ranks the coziest apartments\n"
	.string "in KANTO.$"

celadon_apartment2f_Text_TV:
	.string "A variety show is visiting cafés and\n"
	.string "tea shops around CELADON CITY.$"
