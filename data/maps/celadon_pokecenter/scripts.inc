celadon_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_pokecenter_OnTransition
	.byte 0
celadon_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

celadon_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_CELADON_CITY
	end
