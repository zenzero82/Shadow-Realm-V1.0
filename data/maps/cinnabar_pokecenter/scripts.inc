cinnabar_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, cinnabar_pokecenter_OnTransition
	.byte 0
cinnabar_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

cinnabar_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end
