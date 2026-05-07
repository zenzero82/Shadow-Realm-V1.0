viridian_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, viridian_pokecenter_OnTransition
	.byte 0
viridian_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

viridian_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	checkflag FLAG_QUEST_BACK_TO_HQ_STARTED
	goto_if_eq VAR_RESULT, FALSE, viridian_pokecenter_HideCivilians
	clearflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_pokecenter_HideCivilians:
	setflag FLAG_HIDE_VIRIDIAN_POST_ROCKET_NPCS
	end

viridian_pokecenter_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox viridian_pokecenter_Text_BugCatcher, MSGBOX_DEFAULT
	release
	end

viridian_pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox viridian_pokecenter_Text_Lass, MSGBOX_DEFAULT
	release
	end

viridian_pokecenter_EventScript_Bookshelf1::
	msgbox viridian_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

viridian_pokecenter_EventScript_Bookshelf2::
	msgbox viridian_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

viridian_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

viridian_pokecenter_Text_Bookshelf1:
	.string "A guide to VIRIDIAN FOREST.$"

viridian_pokecenter_Text_Bookshelf2:
	.string "Notes on ROUTE 22 battles.$"

viridian_pokecenter_Text_BugCatcher:
	.string "The POKeMON CENTER stayed open,\n"
	.string "but I still fled the city.\p"
	.string "I wasn't sticking around while\n"
	.string "Team Rocket took over.$"

viridian_pokecenter_Text_Lass:
	.string "I spent nights worrying whether\n"
	.string "I'd ever come back here.\p"
	.string "Now that Team Rocket is gone, I'm\n"
	.string "finally sleeping again.$"
