route2_house_MapScripts::
	.byte 0

route2_house_Speaker_OldMan:
	.string "OLD MAN$"

route2_house_EventScript_OldMan::
	lock
	faceplayer
	setspeaker route2_house_Speaker_OldMan
	checkflag FLAG_RECEIVED_ROUTE2_HOUSE_RARE_CANDY
	goto_if_eq route2_house_EventScript_OldMan_AfterGift
	msgbox route2_house_Text_OldMan_GiftIntro, MSGBOX_DEFAULT
	setvar VAR_0x8000, ITEM_RARE_CANDY
	setvar VAR_0x8001, 1
	call Std_ObtainItem
	goto_if_eq VAR_RESULT, FALSE, route2_house_EventScript_OldMan_BagFull
	setflag FLAG_RECEIVED_ROUTE2_HOUSE_RARE_CANDY
	msgbox route2_house_Text_OldMan_GiftOutro, MSGBOX_DEFAULT
	release
	end

route2_house_EventScript_OldMan_BagFull::
	msgbox route2_house_Text_OldMan_BagFull, MSGBOX_DEFAULT
	release
	end

route2_house_EventScript_OldMan_AfterGift::
	msgbox route2_house_Text_OldMan_AfterGift, MSGBOX_DEFAULT
	release
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

route2_house_Text_OldMan_GiftIntro:
	.string "Most folks never bother cutting\n"
	.string "through to this old house.\p"
	.string "That kind of curiosity ought to be\n"
	.string "rewarded.\p"
	.string "Here, take this RARE CANDY.\n"
	.string "Save it for a POKéMON you really\l"
	.string "believe in.$"

route2_house_Text_OldMan_GiftOutro:
	.string "A quick burst of strength can turn a\n"
	.string "close battle in your favor.\p"
	.string "Don't waste it on just any partner.$"

route2_house_Text_OldMan_BagFull:
	.string "Your bag's packed tight.\p"
	.string "Make some space and I'll hand over\n"
	.string "that RARE CANDY.$"

route2_house_Text_OldMan_AfterGift:
	.string "That RARE CANDY is a rare find out\n"
	.string "here.\p"
	.string "Use it when the right moment comes.$"
