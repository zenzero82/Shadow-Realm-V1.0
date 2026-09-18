Route2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route2_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	.byte 0

Route2_OnLoad::
	call Route2_EventScript_UpdateDiglettsCaveHiker
	end

Route2_OnTransition::
	call Route2_EventScript_UpdateDiglettsCaveHiker
	end

Route2_EventScript_UpdateDiglettsCaveHiker::
	checkflag FLAG_NEBBY_FOLLOWER_ACTIVE
	goto_if_eq Route2_EventScript_HideDiglettsCaveHiker
	clearflag FLAG_HIDE_ROUTE2_DIGLETTS_CAVE_HIKER
	return

Route2_EventScript_HideDiglettsCaveHiker::
	setflag FLAG_HIDE_ROUTE2_DIGLETTS_CAVE_HIKER
	return

Route2_Speaker_Hiker:
	.string "HIKER$"

Route2_Speaker_Psychic:
	.string "PSYCHIC$"

Route2_EventScript_Hiker::
	faceplayer
	setspeaker Route2_Speaker_Hiker
	msgbox Route2_Text_Hiker_Block, MSGBOX_NPC
	end

Route2_EventScript_Psychic::
	lock
	faceplayer
	setspeaker Route2_Speaker_Psychic
	goto_if_set FLAG_RECEIVED_EXP_SHARE, Route2_EventScript_Psychic_AfterGift
	msgbox Route2_Text_Psychic_OfferExpShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route2_EventScript_Psychic_GiveExpShare
	setspeaker Route2_Speaker_Psychic
	msgbox Route2_Text_Psychic_DeclineExpShare, MSGBOX_DEFAULT
	release
	end

Route2_EventScript_Psychic_GiveExpShare::
	setspeaker Route2_Speaker_Psychic
	msgbox Route2_Text_Psychic_GiveExpShare, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	setflag FLAG_EXP_SHARE_ALWAYS_ON
	setspeaker Route2_Speaker_Psychic
	msgbox Route2_Text_Psychic_ExplainExpShare, MSGBOX_DEFAULT
	release
	end

Route2_EventScript_Psychic_AfterGift::
	setspeaker Route2_Speaker_Psychic
	msgbox Route2_Text_Psychic_AfterGift, MSGBOX_DEFAULT
	release
	end


Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_TrainerTips::
	msgbox Route2_Text_TrainerTips, MSGBOX_SIGN
	end

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"

Route2_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Field Moves are now available to use\n"
	.string "if you have a POKeMON that has the\l"
	.string "ability to learn the move in your PC\l"
	.string "or Party.\p"
	.string "They don't even need to actually know\n"
	.string "the move!\p"
	.string "You will have to defeat some\n"
	.string "opponents to use them.\p"
	.string "BROCK will permit the use of the\n"
	.string "Field Move CUT, for example.$"

Route2_Text_Hiker_Block:
	.string "Sorry, you can't pass through\n"
	.string "yet.$"

Route2_Text_Psychic_OfferExpShare:
	.string "Hey there! It looks like you're just\n"
	.string "getting started on your journey.\p"
	.string "Would you be interested in the modern\n"
	.string "EXP. SHARE system?$"

Route2_Text_Psychic_GiveExpShare:
	.string "Awesome! Here, take this.$"

Route2_Text_Psychic_ExplainExpShare:
	.string "The EXP. SHARE works the same as it\n"
	.string "does from Gen 6+ and will award 50%\l"
	.string "EXP. to all non battling mons while\l"
	.string "the mon that won the battle retains\l"
	.string "100% EXP.!\p"
	.string "It will definitely help you grow at a\n"
	.string "faster pace.$"

Route2_Text_Psychic_DeclineExpShare:
	.string "Ah, I see you like to be challenged!\p"
	.string "No worries, come see me again if you\n"
	.string "change your mind.\p"
	.string "I'm not going anywhere...\n"
	.string "I literally am stuck here... forever...$"

Route2_Text_Psychic_AfterGift:
	.string "Hope your team gets really strong!\p"
	.string "Maybe one day you can face ZEN or as\n"
	.string "some call him Jin... something,\l"
	.string "I forget.$"
