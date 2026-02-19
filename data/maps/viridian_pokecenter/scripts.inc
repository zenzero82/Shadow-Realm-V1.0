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
	end

viridian_pokecenter_EventScript_Bookshelf1::
	msgbox viridian_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

viridian_pokecenter_EventScript_Bookshelf2::
	msgbox viridian_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

viridian_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap

viridian_pokecenter_Text_Bookshelf1:
	.string "A guide to VIRIDIAN FOREST.$"

viridian_pokecenter_Text_Bookshelf2:
	.string "Notes on ROUTE 22 battles.$"
