CherrygroveCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_PokemonCenter_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CherrygroveCity_PokemonCenter_OnTransition
	.byte 0

CherrygroveCity_PokemonCenter_OnLoad:
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CherrygroveCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CherrygroveCity_PokemonCenter_Speaker_Fisherman:
	.string "BRUCE$"

CherrygroveCity_PokemonCenter_Speaker_Lass:
	.string "KARA$"

CherrygroveCity_PokemonCenter_Speaker_Gentleman:
	.string "EDWARD$"

CherrygroveCity_PokemonCenter_EventScript_Fisherman::
	faceplayer
	setspeaker CherrygroveCity_PokemonCenter_Speaker_Fisherman
	msgbox CherrygroveCity_PokemonCenter_Text_Fisherman, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_FISHERMAN
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_PokemonCenter_EventScript_Lass::
	faceplayer
	setspeaker CherrygroveCity_PokemonCenter_Speaker_Lass
	msgbox CherrygroveCity_PokemonCenter_Text_Lass, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_LASS
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_PokemonCenter_EventScript_Gentleman::
	faceplayer
	setspeaker CherrygroveCity_PokemonCenter_Speaker_Gentleman
	msgbox CherrygroveCity_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_POKECENTER_GENTLEMAN
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_PokemonCenter_Text_Fisherman:
	.string "The sea is calm today, but the\n"
	.string "roads feel a bit tense.$"

CherrygroveCity_PokemonCenter_Text_Lass:
	.string "I am resting before heading to\n"
	.string "VIOLET CITY.$"

CherrygroveCity_PokemonCenter_Text_Gentleman:
	.string "Take care of your POKéMON, and\n"
	.string "they will take care of you.$"
