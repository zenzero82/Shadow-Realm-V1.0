SafariZone_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_Entrance_OnFrame
	.byte 0

SafariZone_Entrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_Entrance_EventScript_EnterSafariZone
	.2byte 0

SafariZone_Entrance_EventScript_EnterSafariZone::
	setvar VAR_SAFARI_ZONE_STATE, 0
	end

SafariZone_Entrance_EventScript_ExitSafariZone::
	lockall
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 1
	waitstate
	end
