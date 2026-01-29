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
