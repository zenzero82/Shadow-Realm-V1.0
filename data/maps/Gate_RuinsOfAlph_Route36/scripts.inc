Gate_RuinsOfAlph_Route36_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_Speaker_Officer:
	.string "OFFICER$"

Gate_RuinsOfAlph_Route36_Speaker_PokefanM:
	.string "FRANK$"

Gate_RuinsOfAlph_Route36_Speaker_Youngster:
	.string "NICK$"

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	setspeaker Gate_RuinsOfAlph_Route36_Speaker_Officer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	setspeaker Gate_RuinsOfAlph_Route36_Speaker_PokefanM
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	setspeaker Gate_RuinsOfAlph_Route36_Speaker_Youngster
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "RUINS OF ALPH\p"
	.string "A Look-and-Touch Tourist Site\p"
	.string "Try the sliding stone panels!$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "You're studying the RUINS?\p"
	.string "I see a scientist in the making.$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "There are drawings on stone\n"
	.string "panels.\p"
	.string "I tried moving them.\n"
	.string "I wonder what they are.$"
