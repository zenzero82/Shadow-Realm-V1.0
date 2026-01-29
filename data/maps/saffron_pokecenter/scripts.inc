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
