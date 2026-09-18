celadon_apartmentroofday_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, celadon_apartmentroofday_OnTransition
	.byte 0

celadon_apartmentroofday_OnTransition:
	gettimeofday
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq celadon_apartmentroofday_SetNight
	goto celadon_apartmentroofday_SetDay

celadon_apartmentroofday_SetNight::
	setmaplayoutindex LAYOUT_CELADON_APARTMENTROOFNIGHT
	return

celadon_apartmentroofday_SetDay::
	setmaplayoutindex LAYOUT_CELADON_APARTMENTROOFDAY
	return

celadon_apartmentroofday_Speaker_FatMan:
	.string "STAN$"

celadon_apartmentroofday_EventScript_FatMan::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_APARTMENTROOF_FATMAN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker celadon_apartmentroofday_Speaker_FatMan
	msgbox celadon_apartmentroofday_Text_FatMan, MSGBOX_NPC
	end

celadon_apartmentroofday_EventScript_RooftopSign1::
	msgbox celadon_apartmentroofday_Text_RooftopSign1, MSGBOX_SIGN
	end

celadon_apartmentroofday_EventScript_RooftopSign2::
	msgbox celadon_apartmentroofday_Text_RooftopSign2, MSGBOX_SIGN
	end

celadon_apartmentroofday_Text_FatMan:
	.string "The breeze up here is perfect for\n"
	.string "clearing your head.$"

celadon_apartmentroofday_Text_RooftopSign1:
	.string "A rooftop notice advertises fresh tea,\n"
	.string "shaved ice, and boxed lunches.$"

celadon_apartmentroofday_Text_RooftopSign2:
	.string "A bright poster reads:\n"
	.string "Take a break and enjoy\l"
	.string "the CELADON skyline!$"
