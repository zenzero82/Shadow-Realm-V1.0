celadon_departmentroofnight_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_departmentroofnight_OnTransition
	.byte 0

celadon_departmentroofnight_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq celadon_departmentroofnight_SetNight
	goto celadon_departmentroofnight_SetDay

celadon_departmentroofnight_SetNight::
	setmaplayoutindex LAYOUT_CELADON_DEPARTMENTROOFNIGHT
	return

celadon_departmentroofnight_SetDay::
	setmaplayoutindex LAYOUT_CELADON_DEPARTMENTROOFDAY
	return

celadon_departmentroofnight_Speaker_HexManiac:
	.string "MARA$"

celadon_departmentroofnight_Speaker_Haunter:
	.string "HAUNTER$"

celadon_departmentroofnight_EventScript_HexManiac::
	setspeaker celadon_departmentroofnight_Speaker_HexManiac
	trainerbattle_single TRAINER_CELADON_ODD_KEYSTONE, celadon_departmentroofnight_Text_HexManiac_Intro, celadon_departmentroofnight_Text_HexManiac_Defeat, celadon_departmentroofnight_EventScript_HexManiac_After
	end

celadon_departmentroofnight_EventScript_HexManiac_After::
	setspeaker celadon_departmentroofnight_Speaker_HexManiac
	msgbox celadon_departmentroofnight_Text_HexManiac_After, MSGBOX_NPC
	closemessage
	release
	end

celadon_departmentroofnight_EventScript_Haunter::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HAUNTER, CRY_MODE_NORMAL
	setspeaker celadon_departmentroofnight_Speaker_Haunter
	msgbox celadon_departmentroofnight_Text_Haunter, MSGBOX_NPC
	waitmoncry
	release
	end

celadon_departmentroofnight_EventScript_Directory::
	msgbox celadon_departmentroofnight_Text_Directory, MSGBOX_SIGN
	end

celadon_departmentroofnight_Text_HexManiac_Intro:
	.string "The keystone's whisper brought you\n"
	.string "here too, didn't it?\p"
	.string "Then let the spirits judge you!$"

celadon_departmentroofnight_Text_HexManiac_Defeat:
	.string "So the whisper chose you...$"

celadon_departmentroofnight_Text_HexManiac_After:
	.string "The voice mentioned another rooftop.\p"
	.string "Maybe GOLDENROD is listening too.$"

celadon_departmentroofnight_Text_Haunter:
	.string "HAUNTER: Ghaaah!$"

celadon_departmentroofnight_Text_Directory:
	.string "6F: ROOFTOP SQUARE VENDING\n"
	.string "MACHINES$"
