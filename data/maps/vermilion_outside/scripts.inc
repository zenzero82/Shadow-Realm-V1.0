vermilion_outside_MapScripts::
	.byte 0

vermilion_outside_Speaker_Fisherman:
	.string "GILL$"

vermilion_outside_EventScript_Fisherman::
	lock
	faceplayer
	setspeaker vermilion_outside_Speaker_Fisherman
	goto_if_set FLAG_VERMILION_PORTINSIDE_BURNET_SCENE_DONE, vermilion_outside_EventScript_Fisherman_After
	msgbox vermilion_outside_Text_Fisherman_Before, MSGBOX_NPC
	release
	end

vermilion_outside_EventScript_Fisherman_After::
	msgbox vermilion_outside_Text_Fisherman_After, MSGBOX_NPC
	release
	end

vermilion_outside_Text_Fisherman_Before:
	.string "Folks keep hurrying into the terminal\n"
	.string "like something important's about to\l"
	.string "happen.$"

vermilion_outside_Text_Fisherman_After:
	.string "The terminal finally settled down.\p"
	.string "Now it's just the sea and the usual\n"
	.string "harbor noise again.$"
