Route5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
	.byte 0

Route5_OnTransition::
	call_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, Route5_EventScript_ClearBlockade
	end

Route5_Speaker_Policeman:
	.string "OFFICER$"

Route5_EventScript_ClearBlockade::
	setflag FLAG_HIDE_CERULEAN_ROUTE5_BLOCKADE
	return

Route5_EventScript_Policeman::
	faceplayer
	setspeaker Route5_Speaker_Policeman
	msgbox Route5_Text_Policeman_BlockTunnel, MSGBOX_NPC
	end

Route5_EventScript_UndergroundPathSign::
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route5_Text_UndergroundPathSign:
	.string "UNDERGROUND PATH\p"
	.string "CERULEAN CITY - VERMILION CITY$"

Route5_Text_Policeman_BlockTunnel:
	.string "There's an investigation in the\n"
	.string "tunnels right now.\p"
	.string "You can't pass through at this\n"
	.string "time.$"
