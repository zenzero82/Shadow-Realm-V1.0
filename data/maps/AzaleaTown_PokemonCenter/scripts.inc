AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_PokemonCenter_OnTransition
	.byte 0

AzaleaTown_PokemonCenter_Speaker_Fisherman:
	.string "RYAN$"

AzaleaTown_PokemonCenter_Speaker_Gentleman:
	.string "EDGAR$"

AzaleaTown_PokemonCenter_Speaker_Woman:
	.string "SOPHIE$"

AzaleaTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

AzaleaTown_PokemonCenter_EventScript_Fisherman::
	faceplayer
	setspeaker AzaleaTown_PokemonCenter_Speaker_Fisherman
	msgbox AzaleaTown_PokemonCenter_Text_Fisherman, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_POKECENTER_FISHERMAN
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_PokemonCenter_EventScript_Gentleman::
	faceplayer
	setspeaker AzaleaTown_PokemonCenter_Speaker_Gentleman
	msgbox AzaleaTown_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_POKECENTER_GENTLEMAN
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_PokemonCenter_EventScript_Woman::
	faceplayer
	setspeaker AzaleaTown_PokemonCenter_Speaker_Woman
	msgbox AzaleaTown_PokemonCenter_Text_Woman, MSGBOX_NPC
	setflag FLAG_QUEST_AZALEA_NPC_POKECENTER_WOMAN
	call AzaleaTown_EventScript_CheckAzaleaQuest
	end

AzaleaTown_PokemonCenter_Text_Fisherman:
	.string "I was headed for the WELL, but I'm\n"
	.string "taking a breather first.$"

AzaleaTown_PokemonCenter_Text_Gentleman:
	.string "A steady rest keeps your team ready\n"
	.string "for any challenge.$"

AzaleaTown_PokemonCenter_Text_Woman:
	.string "AZALEA feels calm again. I hope it\n"
	.string "stays that way.$"
