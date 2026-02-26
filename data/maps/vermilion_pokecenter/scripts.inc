vermilion_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, vermilion_pokecenter_OnTransition
	.byte 0
vermilion_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

vermilion_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

vermilion_pokecenter_EventScript_Bookshelf1::
	msgbox vermilion_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

vermilion_pokecenter_EventScript_Bookshelf2::
	msgbox vermilion_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

vermilion_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

vermilion_pokecenter_Text_Bookshelf1:
	.string "A brochure for the S.S. ANNE.$"

vermilion_pokecenter_Text_Bookshelf2:
	.string "VERMILION PORT schedules.$"
