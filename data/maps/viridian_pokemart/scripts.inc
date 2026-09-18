viridian_pokemart_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, viridian_pokemart_OnTransition
	.byte 0

viridian_pokemart_Speaker_Youngster:
	.string "Owen$"

viridian_pokemart_Speaker_Lass:
	.string "Nora$"

viridian_pokemart_Speaker_Woman:
	.string "Elise$"

viridian_pokemart_OnTransition:
	checkflag FLAG_QUEST_BACK_TO_HQ_STARTED
	goto_if_eq VAR_RESULT, FALSE, viridian_pokemart_HideCivilians
	clearflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_pokemart_HideCivilians:
	setflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_pokemart_EventScript_Youngster::
	lock
	faceplayer
	setspeaker viridian_pokemart_Speaker_Youngster
	msgbox viridian_pokemart_Text_Youngster, MSGBOX_DEFAULT
	release
	end

viridian_pokemart_EventScript_Lass::
	lock
	faceplayer
	setspeaker viridian_pokemart_Speaker_Lass
	msgbox viridian_pokemart_Text_Lass, MSGBOX_DEFAULT
	release
	end

viridian_pokemart_EventScript_Woman::
	lock
	faceplayer
	setspeaker viridian_pokemart_Speaker_Woman
	msgbox viridian_pokemart_Text_Woman, MSGBOX_DEFAULT
	release
	end

viridian_pokemart_Text_Youngster:
	.string "My mom dragged me out of Viridian\n"
	.string "the second Team Rocket showed up.\p"
	.string "I hated leaving, but she was\n"
	.string "right.$"

viridian_pokemart_Text_Lass:
	.string "I came back for supplies, but I\n"
	.string "still keep expecting grunts to\l"
	.string "burst through the door.$"

viridian_pokemart_Text_Woman:
	.string "We all fled in such a hurry that\n"
	.string "I left half my groceries behind.\p"
	.string "At least the market is peaceful\n"
	.string "again.$"
