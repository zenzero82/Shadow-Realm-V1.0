SproutTower_2F_MapScripts::
	.byte 0

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end


SproutTower_Text_2F_Statue:
	.string "A POKéMON statue…\p"
	.string "It looks very distinguished.$"
