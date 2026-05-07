Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_Speaker_Randy:
	.string "RANDY$"

Gate_GoldenrodCity_Route35_Speaker_Miles:
	.string "MILES$"

Gate_GoldenrodCity_Route35_Speaker_Lena:
	.string "LENA$"

Gate_GoldenrodCity_Route35_Speaker_Otis:
	.string "OTIS$"

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	setspeaker Gate_GoldenrodCity_Route35_Speaker_Randy
	msgbox Gate_GoldenrodCity_Route35_Text_Randy, MSGBOX_DEFAULT
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Miles::
	lock
	faceplayer
	setspeaker Gate_GoldenrodCity_Route35_Speaker_Miles
	msgbox Gate_GoldenrodCity_Route35_Text_Miles, MSGBOX_DEFAULT
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	setspeaker Gate_GoldenrodCity_Route35_Speaker_Lena
	msgbox Gate_GoldenrodCity_Route35_Text_Lena, MSGBOX_DEFAULT
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	setspeaker Gate_GoldenrodCity_Route35_Speaker_Otis
	msgbox Gate_GoldenrodCity_Route35_Text_Otis, MSGBOX_DEFAULT
	release
	end

Gate_GoldenrodCity_Route35_Text_Randy:
	.string "Goldenrod's north gate stays open,\n"
	.string "but we're checking everyone twice.$"

Gate_GoldenrodCity_Route35_Text_Miles:
	.string "If CIPHER pushes farther north,\n"
	.string "we'll know before they do.$"

Gate_GoldenrodCity_Route35_Text_Lena:
	.string "I was headed for the PARK, but all\n"
	.string "these uniforms ruined the trip.$"

Gate_GoldenrodCity_Route35_Text_Otis:
	.string "The bug catching crowd stopped\n"
	.string "coming through once CIPHER arrived.$"
