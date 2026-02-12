.set LOCALID_ARIANA, 9
.set LOCALID_ITEMBALL_MOON_STONE, 10

MtMoon_Outside_MapScripts::
	.byte 0

MtMoon_Outside_EventScript_Ariana::
	lock
	faceplayer
	setspeaker MtMoon_Outside_Speaker_Ariana
	msgbox MtMoon_Outside_Text_Ariana_Capture, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARIANA, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	setspeaker MtMoon_Outside_Speaker_Ariana
	msgbox MtMoon_Outside_Text_Ariana_Threat, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MT_MOON_OUTSIDE_ARIANA
	hideobjectat LOCALID_ARIANA, MAP_MT_MOON_OUTSIDE
	removeobject LOCALID_ARIANA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtMoon_Outside_EventScript_ClefairyCry::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

MtMoon_Outside_EventScript_Item_MoonStone::
	finditem ITEM_MOON_STONE
	goto_if_eq VAR_0x8007, FALSE, MtMoon_Outside_EventScript_Item_Done
	removeobject LOCALID_ITEMBALL_MOON_STONE
MtMoon_Outside_EventScript_Item_Done::
	end

MtMoon_Outside_Text_Ariana_Capture:
	.string "That was an easier capture than\n"
	.string "I thought.$"

MtMoon_Outside_Text_Ariana_Threat:
	.string "Who are you? No matter, you're too\n"
	.string "late if you wanted to stop our plans.\p"
	.string "We got what we needed here. Soon our\n"
	.string "grand scheme will be in full effect.\p"
	.string "Count your days of peace, kid.\n"
	.string "You don't have many more left.$"

MtMoon_Outside_Speaker_Ariana:
	.string "ARIANA$"
