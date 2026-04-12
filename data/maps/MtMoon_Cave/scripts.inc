MtMoon_Cave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RoamingHunter_OnMapLoad
	.byte 0

MtMoon_Cave_EventScript_Sign::
	msgbox MtMoon_Cave_Text_Sign, MSGBOX_SIGN
	end

MtMoon_Cave_Text_Sign:
	.string "MT.MOON NEW ENTRANCE\n"
	.string "DUE TO CAVE-IN\p"
	.string "WATCH YOUR STEP$"

