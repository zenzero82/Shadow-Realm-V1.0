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

cinnabar_pokecenter_EventScript_Bookshelf1::
	msgbox cinnabar_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

cinnabar_pokecenter_EventScript_Bookshelf2::
	msgbox cinnabar_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

cinnabar_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap

cinnabar_pokecenter_Text_Bookshelf1:
	.string "Research notes from CINNABAR LAB.$"

cinnabar_pokecenter_Text_Bookshelf2:
	.string "A ferry schedule to SEAFOAM.$"
