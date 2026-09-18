lavender_house2_MapScripts::
	.byte 0

lavender_house2_Speaker_Channeler:
	.string "SAYO$"

lavender_house2_EventScript_Channeler::
	faceplayer
	setspeaker lavender_house2_Speaker_Channeler
	msgbox lavender_house2_Text_Channeler, MSGBOX_NPC
	setvar VAR_0x8000, 2
	call Lavender_Town_EventScript_RecordInteriorNPC
	end

lavender_house2_Text_Channeler:
	.string "The spirits here are quieter now,\n"
	.string "but not at peace.\p"
	.string "Dark hearts stir them more than\n"
	.string "ghosts ever could.$"
