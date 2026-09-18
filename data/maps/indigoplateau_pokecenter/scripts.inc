indigoplateau_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, indigoplateau_pokecenter_OnTransition
	.byte 0

indigoplateau_pokecenter_OnTransition:
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

indigoplateau_pokecenter_EventScript_Bookshelf1::
	msgbox indigoplateau_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

indigoplateau_pokecenter_EventScript_Bookshelf2::
	msgbox indigoplateau_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

indigoplateau_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

indigoplateau_pokecenter_Text_Bookshelf1:
	.string "Elite Four profiles.$"

indigoplateau_pokecenter_Text_Bookshelf2:
	.string "CHAMPION battle records.$"
