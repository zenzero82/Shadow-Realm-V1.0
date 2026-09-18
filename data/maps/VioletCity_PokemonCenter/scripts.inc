VioletCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_PokemonCenter_OnTransition
	.byte 0

VioletCity_PokemonCenter_Speaker_GameboyKid:
	.string "SETH$"

VioletCity_PokemonCenter_Speaker_Gentleman:
	.string "ALAN$"

VioletCity_PokemonCenter_Speaker_Beauty:
	.string "MIA$"

VioletCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_VIOLET_CITY
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

VioletCity_PokemonCenter_EventScript_GameboyKid::
	faceplayer
	setspeaker VioletCity_PokemonCenter_Speaker_GameboyKid
	msgbox VioletCity_PokemonCenter_Text_GameboyKid, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_POKECENTER_GAMEBOY_KID
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	faceplayer
	setspeaker VioletCity_PokemonCenter_Speaker_Gentleman
	msgbox VioletCity_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_POKECENTER_GENTLEMAN
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_PokemonCenter_EventScript_Beauty::
	faceplayer
	setspeaker VioletCity_PokemonCenter_Speaker_Beauty
	msgbox VioletCity_PokemonCenter_Text_Beauty, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_POKECENTER_BEAUTY
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_PokemonCenter_Text_GameboyKid:
	.string "I like to compare notes with other\n"
	.string "trainers here.$"

VioletCity_PokemonCenter_Text_Gentleman:
	.string "A quiet rest keeps your team ready\n"
	.string "for the next road.$"

VioletCity_PokemonCenter_Text_Beauty:
	.string "BLISSEY has a calming presence.\n"
	.string "It helps everyone relax.$"
