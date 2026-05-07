lavender_mart_MapScripts::
	.byte 0

lavender_mart_Speaker_Clerk:
	.string "CLERK$"

lavender_mart_Speaker_Juggler:
	.string "MILO$"

lavender_mart_Speaker_FatMan:
	.string "GREG$"

lavender_mart_EventScript_Clerk::
	faceplayer
	setspeaker lavender_mart_Speaker_Clerk
	msgbox lavender_mart_Text_Clerk, MSGBOX_NPC
	end

lavender_mart_EventScript_Juggler::
	faceplayer
	setspeaker lavender_mart_Speaker_Juggler
	msgbox lavender_mart_Text_Juggler, MSGBOX_NPC
	end

lavender_mart_EventScript_FatMan::
	faceplayer
	setspeaker lavender_mart_Speaker_FatMan
	msgbox lavender_mart_Text_FatMan, MSGBOX_NPC
	end

lavender_mart_Text_Clerk:
	.string "We sold out of a lot of supplies\n"
	.string "when people heard about the trouble.\p"
	.string "Now everyone keeps buying REPELS,\n"
	.string "just in case.$"

lavender_mart_Text_Juggler:
	.string "LAVENDER feels quieter now, but\n"
	.string "nobody has really relaxed yet.\p"
	.string "People still glance toward the tower\n"
	.string "before they head home.$"

lavender_mart_Text_FatMan:
	.string "I fled town when things started\n"
	.string "getting strange around here.\p"
	.string "Now I'm stocking up before I settle\n"
	.string "back into my routine.$"
