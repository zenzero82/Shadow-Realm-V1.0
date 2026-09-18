Nothing_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Nothing_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Nothing_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Nothing_OnFrame
	.byte 0

Nothing_Speaker_MysteriousVoice:
	.string "Mysterious Voice$"

Nothing_OnLoad::
	setvar VAR_TEMP_1, 0
	setflag FLAG_HIDE_NOTHING_HOOPA_RING
	hideobjectat LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING
	removeobject LOCALID_NOTHING_HOOPA_RING
	end

Nothing_OnTransition::
	setflag FLAG_HIDE_NOTHING_HOOPA_RING
	hideobjectat LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING
	removeobject LOCALID_NOTHING_HOOPA_RING
	end

Nothing_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Nothing_EventScript_MysteriousVoice
	.2byte 0

Nothing_EventScript_MysteriousVoice::
	setvar VAR_TEMP_1, 1
	lockall
	setspeaker Nothing_Speaker_MysteriousVoice
	msgbox Nothing_Text_MysteriousVoice, MSGBOX_DEFAULT
	closemessage
	special StorePlayerCoordsInVars
	clearflag FLAG_HIDE_NOTHING_HOOPA_RING
	addobject LOCALID_NOTHING_HOOPA_RING
	hideobjectat LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING
	setobjectxy LOCALID_NOTHING_HOOPA_RING, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_NOTHING_HOOPA_RING, VAR_0x8004, VAR_0x8005
	showobjectat LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING
	setobjectsubpriority LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_NOTHING, 1
	setvar VAR_0x8004, LOCALID_NOTHING_HOOPA_RING
	special Special_HoopaRingSpawnGrow
	waitstate
	delay 30
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventAbsorb
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	hideobjectat LOCALID_PLAYER, MAP_NOTHING
	setvar VAR_0x8004, LOCALID_NOTHING_HOOPA_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_NOTHING_HOOPA_RING, MAP_NOTHING
	setflag FLAG_HIDE_NOTHING_HOOPA_RING
	removeobject LOCALID_NOTHING_HOOPA_RING
	resetobjectsubpriority LOCALID_PLAYER, MAP_NOTHING
	setflag FLAG_AGATE_VILLAGE_HOOPA_EMERGE
	releaseall
	warp MAP_AGATE_VILLAGE, WARP_ID_NONE, 21, 24
	waitstate
	end

Nothing_Text_MysteriousVoice:
	.string "... You... The Child from the future...\p"
	.string "No you're not him....\p"
	.string "You disturb my plans...\p"
	.string "Yet you see this is your future...\p"
	.string "There is no hope....\p"
	.string "We already succeeded...\p"
	.string "... I already succeeded....\p"
	.string "Find me at your best and I will\n"
	.string "make you see the worst...$"
