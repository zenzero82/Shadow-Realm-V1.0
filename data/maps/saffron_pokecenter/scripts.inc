saffron_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, saffron_pokecenter_OnTransition
	.byte 0

saffron_pokecenter_Speaker_Boy:
	.string "Gabe$"

saffron_pokecenter_Speaker_Worker:
	.string "Dorian$"

saffron_pokecenter_Speaker_Hiker:
	.string "Cliff$"

saffron_pokecenter_Speaker_Lass:
	.string "Tessa$"

saffron_pokecenter_Speaker_Chansey:
	.string "CHANSEY$"

saffron_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	setspeaker saffron_pokecenter_Speaker_Chansey
	release
	end

saffron_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

saffron_pokecenter_EventScript_Boy::
	faceplayer
	setspeaker saffron_pokecenter_Speaker_Boy
	msgbox saffron_pokecenter_Text_Boy, MSGBOX_NPC
	end

saffron_pokecenter_EventScript_Worker::
	faceplayer
	setspeaker saffron_pokecenter_Speaker_Worker
	msgbox saffron_pokecenter_Text_Worker, MSGBOX_NPC
	end

saffron_pokecenter_EventScript_Hiker::
	faceplayer
	setspeaker saffron_pokecenter_Speaker_Hiker
	msgbox saffron_pokecenter_Text_Hiker, MSGBOX_NPC
	end

saffron_pokecenter_EventScript_Lass::
	faceplayer
	setspeaker saffron_pokecenter_Speaker_Lass
	msgbox saffron_pokecenter_Text_Lass, MSGBOX_NPC
	end

saffron_pokecenter_EventScript_Bookshelf1::
	msgbox saffron_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

saffron_pokecenter_EventScript_Bookshelf2::
	msgbox saffron_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

saffron_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

saffron_pokecenter_Text_Bookshelf1:
	.string "A SILPH CO. handbook.$"

saffron_pokecenter_Text_Bookshelf2:
	.string "A guide to the SAFFRON DOJO.$"

saffron_pokecenter_Text_Boy:
	.string "My POKéMON got nervous near\n"
	.string "SILPH CO.\p"
	.string "I brought it here so it could\n"
	.string "rest.$"

saffron_pokecenter_Text_Worker:
	.string "SILPH workers keep calling,\n"
	.string "but nobody can get inside.\p"
	.string "Those CIPHER guards are\n"
	.string "blocking the front door.$"

saffron_pokecenter_Text_Hiker:
	.string "I crossed KANTO on foot\n"
	.string "because the train is down.\p"
	.string "Good exercise, bad timing.$"

saffron_pokecenter_Text_Lass:
	.string "The nurse says to stay calm,\n"
	.string "but everyone is talking about\l"
	.string "GOLDENROD's radio.$"
