TinTower_RoofDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_RoofDay_OnTransition
	.byte 0

TinTower_RoofDay_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq TinTower_RoofDay_SetNight
	goto TinTower_RoofDay_SetDay

TinTower_RoofDay_SetNight::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_NIGHT
	return

TinTower_RoofDay_SetDay::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_DAY
	return
