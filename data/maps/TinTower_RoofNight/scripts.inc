TinTower_RoofNight_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_RoofNight_OnTransition
	.byte 0

TinTower_RoofNight_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq TinTower_RoofNight_SetNight
	goto TinTower_RoofNight_SetDay

TinTower_RoofNight_SetNight::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_NIGHT
	return

TinTower_RoofNight_SetDay::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_DAY
	return
