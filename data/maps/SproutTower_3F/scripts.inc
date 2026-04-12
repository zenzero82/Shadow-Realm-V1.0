SproutTower_3F_MapScripts::
	.byte 0

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end


SproutTower_Text_3F_Painting:
	.string "It's a powerful painting of a\n"
	.string "BELLSPROUT.$"
