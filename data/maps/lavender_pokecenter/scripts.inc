lavender_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, lavender_pokecenter_OnTransition
	.byte 0
lavender_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

lavender_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end
