route10_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, route10_pokecenter_OnTransition
	.byte 0
route10_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

route10_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE10
	end

route10_pokecenter_EventScript_Bookshelf1::
	msgbox route10_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

route10_pokecenter_EventScript_Bookshelf2::
	msgbox route10_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

route10_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

route10_pokecenter_Text_Bookshelf1:
	.string "POWER PLANT safety tips.$"

route10_pokecenter_Text_Bookshelf2:
	.string "ROUTE 10 lookout notes.$"
