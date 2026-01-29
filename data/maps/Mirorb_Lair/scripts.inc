Mirorb_Lair_MapScripts::
	.byte 0

@ Local IDs from map.json:
@   1 = Hoopa Ring
@   2 = Miror B
.set LOCALID_MIROR_B, 2

@ ================================
@ MIROR B LAIR PORTAL WARP (CHERRYGROVE)
@ Attach this script to your portal object in Porymap:
@   Script: Mirorb_Lair_EventScript_Portal_ToCherrygrove

Mirorb_Lair_EventScript_Portal_ToCherrygrove::
	lock
	faceplayer
	msgbox Mirorb_Lair_Text_PortalAsk_Cherrygrove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Mirorb_Lair_PortalNo

	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	warp MAP_CHERRYGROVE_CITY, WARP_ID_NONE, 34, 7

	waitstate
	end

Mirorb_Lair_PortalNo::
	closemessage
	release
	end

Mirorb_Lair_Text_PortalAsk_Cherrygrove:
	.string "The portal is humming...\p"
	.string "Warp to CHERRYGROVE CITY?$"

@ ================================
@ MIROR B (TEMP)
@ ================================

Mirorb_Lair_Speaker_MirorB:
	.string "MIROR B.$"

Mirorb_Lair_EventScript_MirorB::
	lock
	faceplayer
	setspeaker Mirorb_Lair_Speaker_MirorB
	msgbox Mirorb_Lair_Text_MirorB_Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_TEMP_MIROR_B, Mirorb_Lair_Text_MirorB_Seen, Mirorb_Lair_Text_MirorB_Defeat, Mirorb_Lair_EventScript_MirorB_After
	end

Mirorb_Lair_EventScript_MirorB_After::
	setspeaker Mirorb_Lair_Speaker_MirorB
	msgbox Mirorb_Lair_Text_MirorB_After, MSGBOX_DEFAULT
	closemessage
	release
	end

Mirorb_Lair_Text_MirorB_Intro:
	.string "Ahahaha! You're in MIROR B.'s\n"
	.string "lair now, kid!$"

Mirorb_Lair_Text_MirorB_Seen:
	.string "Let the rhythm take you!\n"
	.string "It's time to battle!$"

Mirorb_Lair_Text_MirorB_Defeat:
	.string "No! My groove!$"

Mirorb_Lair_Text_MirorB_After:
	.string "You've got some moves!\p"
	.string "Come back when you're ready to dance\n"
	.string "again.$"
