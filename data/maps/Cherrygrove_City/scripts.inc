Cherrygrove_City_MapScripts::
	.byte 0

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

Cherrygrove_City_Speaker_Flare:
	.string "FLARE$"

@ =================================================
@ FLARE GRUNTS
@ =================================================

Cherrygrove_City_EventScript_FlareGrunt1::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt1, MSGBOX_NPC
	end

Cherrygrove_City_EventScript_FlareGrunt2::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt2, MSGBOX_NPC
	end

Cherrygrove_City_EventScript_FlareGrunt3::
	faceplayer
	setspeaker Cherrygrove_City_Speaker_Flare
	msgbox Cherrygrove_City_Text_FlareGrunt3, MSGBOX_NPC
	end

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

Cherrygrove_City_Text_FlareGrunt1:
	.string "Move along. This area is under\n"
	.string "observation for TEAM FLARE.$"

Cherrygrove_City_Text_FlareGrunt2:
	.string "We're searching for abnormal\n"
	.string "energy readings in JOHTO.$"

Cherrygrove_City_Text_FlareGrunt3:
	.string "Some tech around here is too\n"
	.string "advanced to ignore.$"

CherryGroveCity_EventScript_Sign::
	msgbox CherryGroveCity_EventScript_Sign_Text, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Sign_Text:
	.string "It's a sign.$"

Cherrygrove_City_EventScript_Boy::
	faceplayer
	msgbox Cherrygrove_City_Text_Boy, MSGBOX_NPC
	end

Cherrygrove_City_EventScript_Lass::
	faceplayer
	msgbox Cherrygrove_City_Text_Lass, MSGBOX_NPC
	end

Cherrygrove_City_Text_Boy:
	.string "MR. POKéMON lives past ROUTE 30.\n"
	.string "I want to see his rare finds.$"

Cherrygrove_City_Text_Lass:
	.string "This town feels calm, but travelers\n"
	.string "keep whispering about strange teams.$"
