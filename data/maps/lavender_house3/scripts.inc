lavender_house3_MapScripts::
	.byte 0

lavender_house3_Speaker_OldMan:
	.string "HAROLD$"

lavender_house3_EventScript_OldMan::
	faceplayer
	setspeaker lavender_house3_Speaker_OldMan
	msgbox lavender_house3_Text_OldMan, MSGBOX_NPC
	end

lavender_house3_Text_OldMan:
	.string "When LAVENDER gets uneasy, people\n"
	.string "start whispering ghost stories.\p"
	.string "These days I'm more worried about\n"
	.string "the living than the dead.$"
