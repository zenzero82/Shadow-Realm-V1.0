GoldenrodCity_House3_MapScripts::
	.byte 0

GoldenrodCity_House3_Speaker_Barton:
	.string "BARTON$"

GoldenrodCity_House3_Speaker_Claire:
	.string "CLAIRE$"

GoldenrodCity_House3_Speaker_Mina:
	.string "MINA$"

GoldenrodCity_House3_EventScript_Barton::
	lock
	faceplayer
	setspeaker GoldenrodCity_House3_Speaker_Barton
	msgbox GoldenrodCity_House3_Text_Barton, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_Claire::
	lock
	faceplayer
	setspeaker GoldenrodCity_House3_Speaker_Claire
	msgbox GoldenrodCity_House3_Text_Claire, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_Mina::
	lock
	faceplayer
	setspeaker GoldenrodCity_House3_Speaker_Mina
	msgbox GoldenrodCity_House3_Text_Mina, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_Text_Barton:
	.string "We eat dinner earlier now.\n"
	.string "No one likes being outside late.$"

GoldenrodCity_House3_Text_Claire:
	.string "I keep the curtains open on purpose.\n"
	.string "I refuse to hide in my own home.$"

GoldenrodCity_House3_Text_Mina:
	.string "Dad says brave people can still be\n"
	.string "scared. I think that's true.$"
