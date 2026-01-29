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
