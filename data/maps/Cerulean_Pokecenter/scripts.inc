Cerulean_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cerulean_Pokecenter_OnTransition
	.byte 0
Cerulean_Pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

Cerulean_Pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end
