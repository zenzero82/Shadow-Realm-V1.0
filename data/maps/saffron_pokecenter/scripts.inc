saffron_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, saffron_pokecenter_OnTransition
	.byte 0
saffron_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

saffron_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

saffron_pokecenter_EventScript_Bookshelf1::
	msgbox saffron_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

saffron_pokecenter_EventScript_Bookshelf2::
	msgbox saffron_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

saffron_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

saffron_pokecenter_Text_Bookshelf1:
	.string "A SILPH CO. handbook.$"

saffron_pokecenter_Text_Bookshelf2:
	.string "A guide to the SAFFRON DOJO.$"
