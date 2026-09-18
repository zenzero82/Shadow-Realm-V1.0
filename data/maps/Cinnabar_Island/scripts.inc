Cinnabar_Island_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cinnabar_Island_OnTransition
	.byte 0

Cinnabar_Island_Speaker_SnagemGrunt2:
	.string "GRUNT$"

Cinnabar_Island_Speaker_SnagemGrunt3:
	.string "GRUNT$"

Cinnabar_Island_OnTransition::
	setflag FLAG_VISITED_CINNABAR_ISLAND
	end

Cinnabar_Island_EventScript_SnagemGrunt2::
	lock
	faceplayer
	setspeaker Cinnabar_Island_Speaker_SnagemGrunt2
	msgbox Cinnabar_Island_Text_SnagemGrunt2, MSGBOX_NPC
	closemessage
	release
	end

Cinnabar_Island_EventScript_SnagemGrunt3::
	lock
	faceplayer
	setspeaker Cinnabar_Island_Speaker_SnagemGrunt3
	msgbox Cinnabar_Island_Text_SnagemGrunt3, MSGBOX_NPC
	closemessage
	release
	end

Cinnabar_Island_Text_SnagemGrunt2:
	.string "Beat it, kid.\p"
	.string "TEAM SNAGEM runs Cinnabar now,\n"
	.string "and we don't need tourists getting\l"
	.string "in our way.$"

Cinnabar_Island_Text_SnagemGrunt3:
	.string "You picked the wrong island to\n"
	.string "wander onto.\p"
	.string "CINNABAR belongs to us for now,\n"
	.string "so get lost before this turns ugly.$"
