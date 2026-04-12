CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end


CliffEdgeGate_Text_SignOpen:
	.string "Everything Is Thrilling!\n"
	.string "Explore to Find Wild POKéMON!\l"
	.string "Warden BAOBA's SAFARI ZONE\l"
	.string "Up and Running!$"
