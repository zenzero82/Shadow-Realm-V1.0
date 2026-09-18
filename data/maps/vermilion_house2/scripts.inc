vermilion_house2_MapScripts::
	.byte 0

vermilion_house2_Speaker_Woman:
	.string "MIRA$"

vermilion_house2_Speaker_Boy:
	.string "TOBY$"

vermilion_house2_EventScript_Woman::
	lock
	faceplayer
	setspeaker vermilion_house2_Speaker_Woman
	msgbox vermilion_house2_Text_Woman, MSGBOX_NPC
	release
	end

vermilion_house2_EventScript_Boy::
	lock
	faceplayer
	setspeaker vermilion_house2_Speaker_Boy
	msgbox vermilion_house2_Text_Boy, MSGBOX_NPC
	release
	end

vermilion_house2_Text_Woman:
	.string "My son dreams about the S.S. ANNE\n"
	.string "every single day.\p"
	.string "One voyage and he'd probably decide\n"
	.string "to live on a ship forever.$"

vermilion_house2_Text_Boy:
	.string "Someday I'm going to ride the\n"
	.string "S.S. ANNE and see every region.$"
