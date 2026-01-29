fuchsia_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, fuchsia_pokecenter_OnTransition
	.byte 0
fuchsia_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

fuchsia_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end
