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
