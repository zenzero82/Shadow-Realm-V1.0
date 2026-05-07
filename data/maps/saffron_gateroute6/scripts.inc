saffron_gateroute6_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_Speaker_Guard:
	.string "Officer Penn$"

Gate_SaffronCity_Route6_EventScript_Guard::
	setspeaker Gate_SaffronCity_Route6_Speaker_Guard
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end

Gate_SaffronCity_Route6_EventScript_Guard2::
	setspeaker Gate_SaffronCity_Route6_Speaker_Guard
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Welcome to SAFFRON CITY, home of\n"
	.string "the MAGNET TRAIN!\p"
	.string "...That's what I'd normally say,\n"
	.string "but the MAGNET TRAIN isn't\l"
	.string "running now.\p"
	.string "It's not getting any electricity\n"
	.string "because there's something wrong\l"
	.string "with the POWER PLANT.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "The MAGNET TRAIN is still\n"
	.string "down.\p"
	.string "People keep mentioning a\n"
	.string "missing machine part.$"
