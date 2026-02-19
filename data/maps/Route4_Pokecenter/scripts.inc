Route4_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_Pokecenter_OnTransition
	.byte 0
Route4_Pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

Route4_Pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE4
	end

Route4_Pokecenter_EventScript_Bookshelf1::
	msgbox Route4_Pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

Route4_Pokecenter_EventScript_Bookshelf2::
	msgbox Route4_Pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

Route4_Pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap

Route4_Pokecenter_Text_Bookshelf1:
	.string "MT. MOON trail guide.$"

Route4_Pokecenter_Text_Bookshelf2:
	.string "ROUTE 4 wild POKEMON.$"
