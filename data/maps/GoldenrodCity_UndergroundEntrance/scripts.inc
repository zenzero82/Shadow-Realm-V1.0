GoldenrodCity_UndergroundEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_UndergroundEntrance_OnTransition
	.byte 0

GoldenrodCity_UndergroundEntrance_Speaker_FormerPeon:
	.string "FORMER PEON$"

#define LOCALID_GOLDENROD_UNDERGROUND_ENTRANCE_FORMER_PEON 1

GoldenrodCity_UndergroundEntrance_OnTransition::
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_UndergroundEntrance_OnTransition_ApplyDisguise
	end

GoldenrodCity_UndergroundEntrance_OnTransition_ApplyDisguise:
	special Special_ApplyCipherDisguise
	end

GoldenrodCity_UndergroundEntrance_EventScript_FormerPeon::
	lock
	faceplayer
	setspeaker GoldenrodCity_UndergroundEntrance_Speaker_FormerPeon
	msgbox GoldenrodCity_UndergroundEntrance_Text_FormerPeon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_UndergroundEntrance_Text_FormerPeon:
	.string "Doesn't seem like I can go out just\n"
	.string "yet, I think Lud is on the other side\l"
	.string "of this door!\p"
	.string "Can you go the other way and\n"
	.string "distract him so I can get away?$"
