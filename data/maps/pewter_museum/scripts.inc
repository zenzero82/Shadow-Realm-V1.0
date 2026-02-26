pewter_museum_MapScripts::
	.byte 0

pewter_museum_Speaker_Scientist1:
	.string "Dr. Hale$"

pewter_museum_Speaker_Scientist2:
	.string "Dr. Mira$"

pewter_museum_Speaker_Attendant:
	.string "Attendant$"

pewter_museum_Speaker_Hiker:
	.string "Rowan$"

pewter_museum_Speaker_OldMan:
	.string "Archie$"

pewter_museum_EventScript_Scientist1::
	lock
	faceplayer
	setspeaker pewter_museum_Speaker_Scientist1
	msgbox pewter_museum_Text_Scientist1, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_museum_EventScript_Scientist2::
	lock
	faceplayer
	setspeaker pewter_museum_Speaker_Scientist2
	msgbox pewter_museum_Text_Scientist2, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_museum_EventScript_Attendant::
	lock
	faceplayer
	setspeaker pewter_museum_Speaker_Attendant
	msgbox pewter_museum_Text_Attendant, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_museum_EventScript_Hiker::
	lock
	faceplayer
	setspeaker pewter_museum_Speaker_Hiker
	msgbox pewter_museum_Text_Hiker, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_museum_EventScript_OldMan::
	lock
	faceplayer
	setspeaker pewter_museum_Speaker_OldMan
	msgbox pewter_museum_Text_OldMan, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_museum_EventScript_Sign_Aerodactyl::
	msgbox pewter_museum_Text_Sign_Aerodactyl, MSGBOX_SIGN
	end

pewter_museum_EventScript_Sign_MoonStone::
	msgbox pewter_museum_Text_Sign_MoonStone, MSGBOX_SIGN
	end

pewter_museum_Text_Scientist1:
	.string "We're open again, even if it's a bit\n"
	.string "quieter than usual.\p"
	.string "These fossils are proof that POKéMON\n"
	.string "have survived ages of change.$"

pewter_museum_Text_Scientist2:
	.string "Some rocks from MT. MOON carry odd\n"
	.string "energy signatures.\p"
	.string "We keep an eye on anything unusual.$"

pewter_museum_Text_Attendant:
	.string "Please enjoy the exhibits.\p"
	.string "No touching the displays, and please\n"
	.string "watch your POKéMON.$"

pewter_museum_Text_Hiker:
	.string "The trails up to MT. MOON are rough.\p"
	.string "This museum makes the climb worth it.$"

pewter_museum_Text_OldMan:
	.string "I used to come here as a boy.\p"
	.string "It's good to see PEWTER keeping its\n"
	.string "history safe.$"

pewter_museum_Text_Sign_Aerodactyl:
	.string "AERODACTYL FOSSIL\n"
	.string "A fierce flier of ancient skies.$"

pewter_museum_Text_Sign_MoonStone:
	.string "MT. MOON MINERALS\n"
	.string "Strange stones collected from the\n"
	.string "mountain caves.$"
