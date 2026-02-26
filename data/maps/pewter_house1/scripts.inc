pewter_house1_MapScripts::
	.byte 0

pewter_house1_Speaker_Tim:
	.string "Tim$"

pewter_house1_EventScript_Boy::
	lock
	faceplayer
	setspeaker pewter_house1_Speaker_Tim
	msgbox pewter_house1_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house1_Text_Boy:
	.string "I want to see a real GYM battle!\p"
	.string "They say BROCK's POKéMON are like\n"
	.string "living boulders.$"
