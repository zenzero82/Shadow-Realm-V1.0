lavender_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, lavender_pokecenter_OnTransition
	.byte 0

lavender_pokecenter_Speaker_Chansey:
	.string "CHANSEY$"

lavender_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	setspeaker lavender_pokecenter_Speaker_Chansey
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	msgbox lavender_pokecenter_Text_Chansey, MSGBOX_NPC
	release
	end

lavender_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

lavender_pokecenter_EventScript_Bookshelf1::
	msgbox lavender_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

lavender_pokecenter_EventScript_Bookshelf2::
	msgbox lavender_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

lavender_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

lavender_pokecenter_Text_Bookshelf1:
	.string "A booklet about POKéMON TOWER.$"

lavender_pokecenter_Text_Bookshelf2:
	.string "Notes from the SOUL HOUSE.$"

lavender_pokecenter_Text_Chansey:
	.string "CHANSEY gently pats the counter.\p"
	.string "It looks used to comforting worried\n"
	.string "TRAINERS.$"
