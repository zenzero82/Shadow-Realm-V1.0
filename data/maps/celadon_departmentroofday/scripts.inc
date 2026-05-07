celadon_departmentroofday_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_departmentroofday_OnTransition
	.byte 0

celadon_departmentroofday_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq celadon_departmentroofday_SetNight
	goto celadon_departmentroofday_SetDay

celadon_departmentroofday_SetNight::
	setmaplayoutindex LAYOUT_CELADON_DEPARTMENTROOFNIGHT
	return

celadon_departmentroofday_SetDay::
	setmaplayoutindex LAYOUT_CELADON_DEPARTMENTROOFDAY
	return

celadon_departmentroofday_Speaker_SuperNerd:
	.string "KYLE$"

celadon_departmentroofday_Speaker_Beauty:
	.string "SOPHIE$"

celadon_departmentroofday_Speaker_Boy:
	.string "JAMIE$"

celadon_departmentroofday_EventScript_SuperNerd::
	faceplayer
	setspeaker celadon_departmentroofday_Speaker_SuperNerd
	msgbox celadon_departmentroofday_Text_SuperNerd, MSGBOX_NPC
	end

celadon_departmentroofday_EventScript_Beauty::
	faceplayer
	setspeaker celadon_departmentroofday_Speaker_Beauty
	msgbox celadon_departmentroofday_Text_Beauty, MSGBOX_NPC
	end

celadon_departmentroofday_EventScript_Boy::
	faceplayer
	setspeaker celadon_departmentroofday_Speaker_Boy
	msgbox celadon_departmentroofday_Text_Boy, MSGBOX_NPC
	end

celadon_departmentroofday_EventScript_Directory::
	msgbox celadon_departmentroofday_Text_Directory, MSGBOX_SIGN
	end

celadon_departmentroofday_Text_SuperNerd:
	.string "A vending machine on the roof?\n"
	.string "That's classic CELADON.$"

celadon_departmentroofday_Text_Beauty:
	.string "The view is worth the climb.\n"
	.string "It's so calm up here.$"

celadon_departmentroofday_Text_Boy:
	.string "No games on the roof...\p"
	.string "I'll settle for a drink.$"

celadon_departmentroofday_Text_Directory:
	.string "6F: ROOFTOP SQUARE VENDING\n"
	.string "MACHINES$"
