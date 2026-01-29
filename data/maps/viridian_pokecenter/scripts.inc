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
