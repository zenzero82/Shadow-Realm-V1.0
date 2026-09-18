route9_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, route9_pokecenter_OnTransition
	.byte 0

route9_pokecenter_OnTransition:
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

route9_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

route9_pokecenter_EventScript_Bookshelf1::
	msgbox route9_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

route9_pokecenter_EventScript_Bookshelf2::
	msgbox route9_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

route9_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

route9_pokecenter_Text_Bookshelf1:
	.string "A ROCK TUNNEL map.$"

route9_pokecenter_Text_Bookshelf2:
	.string "ROUTE 9 hiking notes.$"
