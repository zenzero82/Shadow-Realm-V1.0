Goldenrod_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Goldenrod_City_OnTransition
	.byte 0

Goldenrod_City_OnTransition::
	setflag FLAG_VISITED_GOLDENROD_CITY
	end

GoldenrodCity_EventScript_SignRadio::
	msgbox GoldenrodCity_EventScript_SignRadio_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignRadio_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignGameCorner::
	msgbox GoldenrodCity_EventScript_SignGameCorner_Text, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost

GoldenrodCity_EventScript_SignGameCorner_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignTrain::
	msgbox GoldenrodCity_EventScript_SignTrain_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignTrain_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignUnderground::
	msgbox GoldenrodCity_EventScript_SignUnderground_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignUnderground_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignBike::
	msgbox GoldenrodCity_EventScript_SignBike_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignBike_Text:
	.string "A bicycle is on display.$"

GoldenrodCity_EventScript_SignGym::
	msgbox GoldenrodCity_EventScript_SignGym_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignGym_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignFlower::
	msgbox GoldenrodCity_EventScript_SignFlower_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignFlower_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_SignDept::
	msgbox GoldenrodCity_EventScript_SignDept_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_SignDept_Text:
	.string "It's a sign.$"

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_EventScript_NameRaterSign_Text, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_NameRaterSign_Text:
	.string "NAME RATER.$"

GoldenrodCity_Text_StationSign:
	.string "GOLDENROD CITY STATION$"


GoldenrodCity_Text_RadioTowerSign:
	.string "GOLDENROD CITY RADIO TOWER$"


GoldenrodCity_Text_DeptStoreSign:
	.string "Full Selection of POKéMON Goods!\p"
	.string "GOLDENROD CITY DEPT.STORE$"


GoldenrodCity_Text_GymSign:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"


GoldenrodCity_Text_BikeShopSign:
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"


GoldenrodCity_Text_GameCornerSign:
	.string "Your Playground!\p"
	.string "GOLDENROD CITY GAME CORNER$"


GoldenrodCity_Text_NameRaterSign:
	.string "NAME RATER\p"
	.string "Get Your POKéMON Nicknames Rated$"


GoldenrodCity_Text_UndergroundSouthSign:
	.string "UNDERGROUND ENTRANCE$"



GoldenrodCity_Text_FlowerShopSign:
	.string "Blooming Beautiful FLOWER SHOP$"

