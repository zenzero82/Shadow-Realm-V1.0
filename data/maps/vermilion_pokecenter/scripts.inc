vermilion_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, vermilion_pokecenter_OnTransition
	.byte 0

vermilion_pokecenter_Speaker_Chansey:
	.string "CHANSEY$"

vermilion_pokecenter_Speaker_Fisherman:
	.string "GUS$"

vermilion_pokecenter_Speaker_Cook:
	.string "MARCO$"

vermilion_pokecenter_Speaker_BugCatcher:
	.string "LEO$"

vermilion_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	setspeaker vermilion_pokecenter_Speaker_Chansey
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

vermilion_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_VERMILION_CITY
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

vermilion_pokecenter_EventScript_Fisherman::
	lock
	faceplayer
	setspeaker vermilion_pokecenter_Speaker_Fisherman
	msgbox vermilion_pokecenter_Text_Fisherman, MSGBOX_NPC
	release
	end

vermilion_pokecenter_EventScript_Cook::
	lock
	faceplayer
	setspeaker vermilion_pokecenter_Speaker_Cook
	msgbox vermilion_pokecenter_Text_Cook, MSGBOX_NPC
	release
	end

vermilion_pokecenter_EventScript_BugCatcher::
	lock
	faceplayer
	setspeaker vermilion_pokecenter_Speaker_BugCatcher
	msgbox vermilion_pokecenter_Text_BugCatcher, MSGBOX_NPC
	release
	end

vermilion_pokecenter_EventScript_Bookshelf1::
	msgbox vermilion_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

vermilion_pokecenter_EventScript_Bookshelf2::
	msgbox vermilion_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

vermilion_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

vermilion_pokecenter_Text_Bookshelf1:
	.string "A brochure for the S.S. ANNE.$"

vermilion_pokecenter_Text_Bookshelf2:
	.string "A map of the KANTO ferry routes.$"

vermilion_pokecenter_Text_Fisherman:
	.string "I was hoping to head through the cave,\n"
	.string "but everything around that route feels\l"
	.string "blocked lately.$"

vermilion_pokecenter_Text_Cook:
	.string "The nurses hear every rumor in town.\p"
	.string "Around here it is usually LT. SURGE,\n"
	.string "the S.S. ANNE, or both.$"

vermilion_pokecenter_Text_BugCatcher:
	.string "I wanted to visit DIGLETT'S CAVE,\n"
	.string "but the SNORLAX on the road is making\l"
	.string "me stay put.$"
