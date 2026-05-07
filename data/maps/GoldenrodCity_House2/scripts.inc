GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_Speaker_Gerald:
	.string "GERALD$"

GoldenrodCity_House2_EventScript_Gerald::
	lock
	faceplayer
	setspeaker GoldenrodCity_House2_Speaker_Gerald
	msgbox GoldenrodCity_House2_Text_Gerald, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House2_Text_Gerald:
	.string "The city sounds louder these days,\n"
	.string "but somehow less alive.$"
