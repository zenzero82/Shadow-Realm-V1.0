route2_house_MapScripts::
	.byte 0

route2_house_Speaker_OldMan:
	.string "OLD MAN$"

route2_house_EventScript_OldMan::
	faceplayer
	setspeaker route2_house_Speaker_OldMan
	msgbox route2_house_Text_OldMan_Intro, MSGBOX_NPC
	setvar VAR_0x8004, SCROLL_MULTI_ROUTE2_GUIDE
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, route2_house_EventScript_OldMan_Dexnav
	case 1, route2_house_EventScript_OldMan_EvIv
	case 2, route2_house_EventScript_OldMan_PokeballSwap
	case MULTI_B_PRESSED, route2_house_EventScript_OldMan_Cancel
	end

route2_house_EventScript_OldMan_Dexnav::
	setspeaker route2_house_Speaker_OldMan
	msgbox route2_house_Text_OldMan_Dexnav, MSGBOX_NPC
	end

route2_house_EventScript_OldMan_EvIv::
	setspeaker route2_house_Speaker_OldMan
	msgbox route2_house_Text_OldMan_EvIv, MSGBOX_NPC
	end

route2_house_EventScript_OldMan_PokeballSwap::
	setspeaker route2_house_Speaker_OldMan
	msgbox route2_house_Text_OldMan_PokeballSwap, MSGBOX_NPC
	end

route2_house_EventScript_OldMan_Cancel::
	end

route2_house_Text_OldMan_Intro:
	.string "Howdy! I'm the ROUTE 2 guide.\p"
	.string "What would you like to know about?$"

route2_house_Text_OldMan_Dexnav:
	.string "DEXNAV helps you search for wild\n"
	.string "POKéMON nearby.\p"
	.string "Press R on a route to open it, then\n"
	.string "choose a target to start searching.$"

route2_house_Text_OldMan_EvIv:
	.string "EVs and IVs shape your POKéMON's\n"
	.string "stats.\p"
	.string "Check the EV/IV page in the summary\n"
	.string "screen for details.\p"
	.string "If EV/IV Editor is ON, press A there\n"
	.string "to adjust values.$"

route2_house_Text_OldMan_PokeballSwap:
	.string "POKeBALL SWAP lets you change the\n"
	.string "ball your POKéMON is stored in.\p"
	.string "Open the bag menu and pick a new\n"
	.string "ball to apply.$"
