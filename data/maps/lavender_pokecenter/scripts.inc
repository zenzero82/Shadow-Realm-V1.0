lavender_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, lavender_pokecenter_OnTransition
	.byte 0
lavender_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

lavender_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

lavender_pokecenter_EventScript_Bookshelf1::
	msgbox lavender_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

lavender_pokecenter_EventScript_Bookshelf2::
	msgbox lavender_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

lavender_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap

lavender_pokecenter_Text_Bookshelf1:
	.string "A booklet about POKEMON TOWER.$"

lavender_pokecenter_Text_Bookshelf2:
	.string "Notes from the SOUL HOUSE.$"
