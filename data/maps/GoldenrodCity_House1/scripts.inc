GoldenrodCity_House1_MapScripts::
	.byte 0

GoldenrodCity_House1_Speaker_Ernest:
	.string "ERNEST$"

GoldenrodCity_House1_EventScript_Ernest::
	lock
	faceplayer
	setspeaker GoldenrodCity_House1_Speaker_Ernest
	msgbox GoldenrodCity_House1_Text_Ernest, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House1_Text_Ernest:
	.string "I've lived in Goldenrod long enough to\n"
	.string "know bullies don't last forever.$"
