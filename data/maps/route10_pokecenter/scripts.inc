route10_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, route10_pokecenter_OnTransition
	.byte 0

route10_pokecenter_Speaker_Engineer1:
	.string "MILES$"

route10_pokecenter_Speaker_Engineer2:
	.string "KENT$"

route10_pokecenter_Speaker_Engineer3:
	.string "ADA$"

route10_pokecenter_Speaker_Engineer4:
	.string "ROLF$"

route10_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

route10_pokecenter_EventScript_Engineer1::
	faceplayer
	setspeaker route10_pokecenter_Speaker_Engineer1
	msgbox route10_pokecenter_Text_Engineer1, MSGBOX_NPC
	end

route10_pokecenter_EventScript_Engineer2::
	faceplayer
	setspeaker route10_pokecenter_Speaker_Engineer2
	msgbox route10_pokecenter_Text_Engineer2, MSGBOX_NPC
	end

route10_pokecenter_EventScript_Engineer3::
	faceplayer
	setspeaker route10_pokecenter_Speaker_Engineer3
	msgbox route10_pokecenter_Text_Engineer3, MSGBOX_NPC
	end

route10_pokecenter_EventScript_Engineer4::
	faceplayer
	setspeaker route10_pokecenter_Speaker_Engineer4
	msgbox route10_pokecenter_Text_Engineer4, MSGBOX_NPC
	end

route10_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE10
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

route10_pokecenter_EventScript_Bookshelf1::
	msgbox route10_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

route10_pokecenter_EventScript_Bookshelf2::
	msgbox route10_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

route10_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

route10_pokecenter_Text_Bookshelf1:
	.string "POWER PLANT safety tips.$"

route10_pokecenter_Text_Bookshelf2:
	.string "ROUTE 10 lookout notes.$"

route10_pokecenter_Text_Engineer1:
	.string "POWER PLANT checks never end.\n"
	.string "We keep the grid stable.$"

route10_pokecenter_Text_Engineer2:
	.string "ROCK TUNNEL still eats light.\n"
	.string "Bring FLASH if you're heading in.$"

route10_pokecenter_Text_Engineer3:
	.string "A strong trainer sprinted past.\n"
	.string "Something must be going on.$"

route10_pokecenter_Text_Engineer4:
	.string "ROUTE 10 stays bright thanks to\n"
	.string "steady work.$"
