lavender_house1_MapScripts::
	.byte 0

lavender_house1_Speaker_Woman:
	.string "MARA$"

lavender_house1_Speaker_Boy:
	.string "NIKO$"

lavender_house1_EventScript_Woman::
	faceplayer
	setspeaker lavender_house1_Speaker_Woman
	msgbox lavender_house1_Text_Woman, MSGBOX_NPC
	end

lavender_house1_EventScript_Boy::
	faceplayer
	setspeaker lavender_house1_Speaker_Boy
	msgbox lavender_house1_Text_Boy, MSGBOX_NPC
	end

lavender_house1_Text_Woman:
	.string "LAVENDER finally feels a little\n"
	.string "calmer again.\p"
	.string "Still, with all that trouble around\n"
	.string "the RADIO STATION, nobody here\l"
	.string "wants to relax just yet.$"

lavender_house1_Text_Boy:
	.string "I keep listening for strange noises\n"
	.string "from the TOWER.\p"
	.string "Mom says it's only the wind, but\n"
	.string "LAVENDER still feels spooky.$"
