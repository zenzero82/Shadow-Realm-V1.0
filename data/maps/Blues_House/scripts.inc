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

PalletTown_House2_Text_Hello:
	.string "Hi!\p"
	.string "My kid brother BLUE is the GYM LEADER\n"
	.string "in VIRIDIAN CITY.\p"
	.string "Lately, the news has been talking about\n"
	.string "TEAM ROCKET sightings near his GYM…\p"
	.string "The GYM's been closed for days, and I\n"
	.string "haven't heard from him at all.\p"
	.string "If you head that way, could you check\n"
	.string "on him for me?$"
