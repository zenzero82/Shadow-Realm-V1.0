Cherrygrove_City_MapScripts::
	.byte 0

@ ================================
@ CHERRYGROVE PORTAL WARP (MIROR B)
@ Attach this script to your portal object in Porymap:
@   Script: Cherrygrove_City_EventScript_Portal_ToMirorb

Cherrygrove_City_EventScript_Portal_ToMirorb::
	lock
	faceplayer
	msgbox Cherrygrove_City_Text_PortalAsk_Mirorb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Cherrygrove_City_PortalNo

	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	warp MAP_MIRORB_LAIR, WARP_ID_NONE, 3, 3

	waitstate
	end

Cherrygrove_City_PortalNo::
	closemessage
	release
	end

Cherrygrove_City_Text_PortalAsk_Mirorb:
	.string "The portal is humming...\p"
	.string "Warp to MIROR B'S LAIR?$"
