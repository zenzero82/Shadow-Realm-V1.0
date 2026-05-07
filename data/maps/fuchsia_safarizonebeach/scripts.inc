fuchsia_safarizonebeach_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, fuchsia_safarizonebeach_OnFrame
	.byte 0

fuchsia_safarizonebeach_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, fuchsia_safarizonebeach_EventScript_EnterSafariZone
	.2byte 0

fuchsia_safarizonebeach_EventScript_EnterSafariZone::
	setvar VAR_SAFARI_ZONE_STATE, 0
	end

fuchsia_safarizonebeach_EventScript_ExitSafariZone::
	lockall
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	warp MAP_FUCHSIA_SAFARIZONEENTRANCE, 5, 2
	waitstate
	end
