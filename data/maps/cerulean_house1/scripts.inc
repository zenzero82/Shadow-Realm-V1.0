cerulean_house1_MapScripts::
	.byte 0

cerulean_house1_Speaker_BaldingMan:
	.string "MILES$"

cerulean_house1_Speaker_Woman:
	.string "SARA$"

cerulean_house1_EventScript_BaldingMan::
	lock
	faceplayer
	setspeaker cerulean_house1_Speaker_BaldingMan
	msgbox cerulean_house1_Text_BaldingMan, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house1_EventScript_Woman::
	lock
	faceplayer
	setspeaker cerulean_house1_Speaker_Woman
	msgbox cerulean_house1_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

cerulean_house1_Text_BaldingMan:
	.string "I heard the police sealed off the\n"
	.string "CAVE route. It must be serious.$"

cerulean_house1_Text_Woman:
	.string "We keep our POKeMON close at night.\n"
	.string "Too many break-ins lately.$"
