vermilion_house1_MapScripts::
	.byte 0

vermilion_house1_Speaker_Fisherman:
	.string "HANK$"

vermilion_house1_EventScript_Fisherman::
	lock
	faceplayer
	setspeaker vermilion_house1_Speaker_Fisherman
	msgbox vermilion_house1_Text_Fisherman, MSGBOX_NPC
	release
	end

vermilion_house1_Text_Fisherman:
	.string "The sea air here is good for the soul.\p"
	.string "If the docks get too noisy, I just sit\n"
	.string "here and listen to the waves instead.$"
