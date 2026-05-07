GoldenrodCity_UndergroundTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_UndergroundTunnel_OnTransition
	.byte 0

#define LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_CIPHER_PEON 1
#define LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY 2

GoldenrodCity_UndergroundTunnel_Speaker_CipherPeon:
	.string "CIPHER PEON$"

GoldenrodCity_UndergroundTunnel_Speaker_Boy:
	.string "BOY$"

GoldenrodCity_UndergroundTunnel_OnTransition::
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_TUNNEL_BOY
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_UndergroundTunnel_OnTransition_ApplyDisguise
	end

GoldenrodCity_UndergroundTunnel_OnTransition_ApplyDisguise:
	special Special_ApplyCipherDisguise
	end

GoldenrodCity_UndergroundTunnel_EventScript_CipherPeon::
	lockall
	setspeaker GoldenrodCity_UndergroundTunnel_Speaker_CipherPeon
	msgbox GoldenrodCity_UndergroundTunnel_Text_CipherPeon_Before, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_CIPHER_PEON, GoldenrodCity_UndergroundTunnel_Movement_DoubleExclamation
	waitmovement 0
	faceplayer
	copyvar VAR_0x8004, VAR_FACING
	msgbox GoldenrodCity_UndergroundTunnel_Text_CipherPeon_Confession, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_TUNNEL_CIPHER_PEON
	removeobject LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_CIPHER_PEON
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_TUNNEL_BOY
	setobjectxy LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, 12, 13
	setobjectxyperm LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, 12, 13
	addobject LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY
	setflag FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE
	special Special_ApplyCipherDisguise
	fadescreen FADE_FROM_BLACK
	setspeaker GoldenrodCity_UndergroundTunnel_Speaker_Boy
	msgbox GoldenrodCity_UndergroundTunnel_Text_Boy_After, MSGBOX_DEFAULT
	switch VAR_0x8004
	case DIR_NORTH, GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromFront
	case DIR_SOUTH, GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromBehind
	case DIR_EAST, GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromLeft
	case DIR_WEST, GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromRight
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromFront
	goto GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeDone

GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromFront:
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromFront
	goto GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeDone

GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromBehind:
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromBehind
	goto GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeDone

GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromLeft:
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromLeft
	goto GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeDone

GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeFromRight:
	applymovement LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY, GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromRight

GoldenrodCity_UndergroundTunnel_EventScript_BoyEscapeDone:
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_TUNNEL_BOY
	removeobject LOCALID_GOLDENROD_UNDERGROUND_TUNNEL_BOY
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	msgbox GoldenrodCity_UndergroundTunnel_EventScript_Door_Text, MSGBOX_SIGN
	end

GoldenrodCity_UndergroundTunnel_Movement_DoubleExclamation:
	emote_double_exclamation_mark
	step_end

GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromFront:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromBehind:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromLeft:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

GoldenrodCity_UndergroundTunnel_Movement_BoyEscapeFromRight:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Text_CipherPeon_Before:
	.string "I.. I just can't do it anymore...$"

GoldenrodCity_UndergroundTunnel_Text_CipherPeon_Confession:
	.string "You there?? How did you... when\n"
	.string "did you... sigh..\p"
	.string "Look kid I don't want to be part\n"
	.string "of CIPHER anymore.\p"
	.string "Things are starting to get real\n"
	.string "bad. There are so many POKéMON\l"
	.string "we have tortured and now we're\l"
	.string "kidnapping people and taking\l"
	.string "them away from their loved ones.\p"
	.string "I heard some stuff that I\n"
	.string "shouldn't have in her office...\p"
	.string "I want out! I was supposed to\n"
	.string "come down here and check on the\l"
	.string "people we kidnapped from the\l"
	.string "RADIO TOWER but I left the key\l"
	.string "on the 5th floor.\p"
	.string "The CARD KEY is in her office...\n"
	.string "I'm making a run for it.\p"
	.string "If you want to sneak in the\n"
	.string "building be my guest, you'll\l"
	.string "have to wear this uniform or\l"
	.string "they will not let you enter.$"

GoldenrodCity_UndergroundTunnel_Text_Boy_After:
	.string "Don't let them corrupt you as\n"
	.string "well. I'll sneak out the back\l"
	.string "entrance. Be careful kid.$"

GoldenrodCity_UndergroundTunnel_EventScript_Door_Text:
	.string "It's locked.$"
