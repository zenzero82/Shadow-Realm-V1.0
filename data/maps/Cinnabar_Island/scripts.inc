Cinnabar_Island_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cinnabar_Island_OnTransition
	.byte 0

Cinnabar_Island_OnTransition::
	setflag FLAG_VISITED_CINNABAR_ISLAND
	end
