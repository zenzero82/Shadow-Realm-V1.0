celadon_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_pokecenter_OnTransition
	.byte 0

celadon_pokecenter_Speaker_Gentleman:
	.string "ALFRED$"

celadon_pokecenter_Speaker_BattleGirl:
	.string "RINA$"

celadon_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

celadon_pokecenter_EventScript_Gentleman::
	faceplayer
	setspeaker celadon_pokecenter_Speaker_Gentleman
	msgbox celadon_pokecenter_Text_Gentleman, MSGBOX_NPC
	end

celadon_pokecenter_EventScript_BattleGirl::
	faceplayer
	setspeaker celadon_pokecenter_Speaker_BattleGirl
	msgbox celadon_pokecenter_Text_BattleGirl, MSGBOX_NPC
	end

celadon_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

celadon_pokecenter_EventScript_Bookshelf1::
	msgbox celadon_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

celadon_pokecenter_EventScript_Bookshelf2::
	msgbox celadon_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

celadon_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

celadon_pokecenter_Text_Bookshelf1:
	.string "A CELADON DEPT. STORE catalog.$"

celadon_pokecenter_Text_Bookshelf2:
	.string "A tea menu from CELADON CITY.$"

celadon_pokecenter_Text_Gentleman:
	.string "CELADON is busy all day long.\p"
	.string "The DEPT.STORE keeps it lively.$"

celadon_pokecenter_Text_BattleGirl:
	.string "ERIKA's GYM is calm, but her\n"
	.string "POKEMON aren't. Be prepared.$"
