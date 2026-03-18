Gate_Route29_Route46_MapScripts::
	.byte 0

Gate_Route29_Route46_Speaker_Officer:
	.string "OFFICER$"

Gate_Route29_Route46_Speaker_Youngster:
	.string "DEREK$"

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	setspeaker Gate_Route29_Route46_Speaker_Officer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	setspeaker Gate_Route29_Route46_Speaker_Youngster
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "You can't climb ledges.\p"
	.string "But you can jump down from\n"
	.string "them to take a shortcut.$"

Gate_Route29_Route46_Text_Youngster:
	.string "Different kinds of POKéMON\n"
	.string "appear past here.\p"
	.string "If you want to catch them all,\n"
	.string "you have to look everywhere.$"
