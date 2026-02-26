Blues_House_MapScripts:: 
	.byte 0

Speaker_Daisy:
	.string "Daisy$"

PalletTown_House2_EventScript_Blue::
	lock
	faceplayer

	setspeaker Speaker_Daisy
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage

	release
	end

PalletTown_BluesHouse_EventScript_TV::
	msgbox PalletTown_BluesHouse_Text_TV, MSGBOX_SIGN
	end

PalletTown_BluesHouse_EventScript_Bookshelf1::
	msgbox PalletTown_BluesHouse_Text_Bookshelf1, MSGBOX_SIGN
	end

PalletTown_BluesHouse_EventScript_Bookshelf2::
	msgbox PalletTown_BluesHouse_Text_Bookshelf2, MSGBOX_SIGN
	end

PalletTown_House2_Text_Hello:
	.string "Hi!\p"
	.string "My kid brother GARY is the GYM LEADER\n"
	.string "in VIRIDIAN CITY.\p"
	.string "Lately, the news has been talking about\n"
	.string "TEAM ROCKET sightings near his GYM…\p"
	.string "The GYM's been closed for days, and I\n"
	.string "haven't heard from him at all.\p"
	.string "If you head that way, could you check\n"
	.string "on him for me?$"

PalletTown_BluesHouse_Text_TV:
	.string "A TV show about POKéMON battles\p"
	.string "is playing in the background.$"

PalletTown_BluesHouse_Text_Bookshelf1:
	.string "There are books on strategy,\n"
	.string "battle theory, and gym history.$"

PalletTown_BluesHouse_Text_Bookshelf2:
	.string "A well-worn guide titled:\n"
	.string "Winning with Type Advantage.$"
