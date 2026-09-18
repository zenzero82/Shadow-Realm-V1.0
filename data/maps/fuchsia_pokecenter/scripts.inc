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
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

fuchsia_pokecenter_EventScript_Bookshelf1::
	msgbox fuchsia_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

fuchsia_pokecenter_EventScript_Bookshelf2::
	msgbox fuchsia_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

fuchsia_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

fuchsia_pokecenter_Text_Bookshelf1:
	.string "A SAFARI ZONE guide.$"

fuchsia_pokecenter_Text_Bookshelf2:
	.string "Notes on the FUCHSIA WARDEN.$"
