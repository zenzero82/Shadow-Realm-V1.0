WesHideout_Entrance_MapScripts::
	.byte 0

#define LOCALID_WES 1

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

WesHideout_Entrance_Speaker_Wes:
	.string "WES$"

WesHideout_Entrance_EventScript_Nop::
	end

@ =========================================================
@ WES
@ =========================================================

WesHideout_Entrance_EventScript_Wes::
	lock
	faceplayer
	call WesHideout_Entrance_EventScript_Wes_Talk
	release
	end

WesHideout_Entrance_EventScript_Wes_Talk::
	setspeaker WesHideout_Entrance_Speaker_Wes
	checkflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	goto_if_eq WesHideout_Entrance_EventScript_Wes_Briefed
	msgbox WesHideout_Entrance_Text_Wes_Intro, MSGBOX_DEFAULT
	closemessage
	return

WesHideout_Entrance_EventScript_Wes_Briefed::
	checkflag FLAG_RECEIVED_SNAG_MACHINE
	goto_if_eq WesHideout_Entrance_EventScript_Wes_AfterGift
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Gift_Part1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SNAG_MACHINE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	playse SE_USE_ITEM
	waitse
	setflag FLAG_HAS_SNAG_MACHINE
	setflag FLAG_RECEIVED_SNAG_MACHINE
	setflag FLAG_HIDE_CERULEAN_MISTY
	setflag FLAG_HIDE_ROUTE_25_MICHAEL
	setflag FLAG_HIDE_ROUTE_25_SYLVEON
	setspeaker WesHideout_Entrance_Speaker_Wes
	msgbox WesHideout_Entrance_Text_Wes_Gift_Part2, MSGBOX_DEFAULT
	closemessage
	return

WesHideout_Entrance_EventScript_Wes_AfterGift::
	msgbox WesHideout_Entrance_Text_Wes_AfterGift, MSGBOX_DEFAULT
	closemessage
	return

@ =========================================================
@ WES TRIGGERS
@ =========================================================

WesHideout_Entrance_EventScript_WesTrigger_0::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, WesHideout_Entrance_Movement_PlayerToWes_FromLeft
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

WesHideout_Entrance_EventScript_WesTrigger_1::
	lockall
	setvar VAR_TEMP_0, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

WesHideout_Entrance_EventScript_WesTrigger_2::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, WesHideout_Entrance_Movement_PlayerToWes_FromRight
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_NORTH
	turnobject LOCALID_WES, DIR_SOUTH
	call WesHideout_Entrance_EventScript_Wes_Talk
	releaseall
	end

@ =========================================================
@ MOVEMENTS
@ =========================================================

WesHideout_Entrance_Movement_PlayerToWes_FromLeft:
	walk_up
	walk_right
	step_end

WesHideout_Entrance_Movement_PlayerToWes_FromRight:
	walk_up
	walk_left
	step_end

@ =========================================================
@ TEXT
@ =========================================================

WesHideout_Entrance_Text_Wes_Intro:
	.string "Ah you made it! Seems like you were\n"
	.string "able to best BROCK after all.\p"
	.string "Maybe TURO was right...\p"
	.string "Don't mind me just thinking out loud.\n"
	.string "Anyway, now that you're here you can\l"
	.string "get a proper explanation of what's\l"
	.string "going on.\p"
	.string "We made a base here for research\n"
	.string "purposes. Go downstairs and talk to\l"
	.string "the team. They can give you some\l"
	.string "insight. Then come back and see me\l"
	.string "before you leave.$"

WesHideout_Entrance_Text_Wes_Gift_Part1:
	.string "Now that the team was able to give\n"
	.string "you some insight, you have a better\l"
	.string "understanding of what we're up\l"
	.string "against.\p"
	.string "I want to give you something. I have\n"
	.string "this SNAG MACHINE that I stole from\l"
	.string "TEAM SNAGEM before the explosion.\l"
	.string "I want you to have it.$"

WesHideout_Entrance_Text_Wes_Gift_Part2:
	.string "With that device you can snag\n"
	.string "trainers' POKEMON, if they are\l"
	.string "Shadow's... We are not thieves so we\l"
	.string "only take them away so we can purify\l"
	.string "them.\p"
	.string "I have a friend over in JOHTO who is\n"
	.string "currently modifying POKEBALLS that\l"
	.string "CIPHER has been using for their\l"
	.string "conversion process. They have a\l"
	.string "better catch rate for Shadow's and\l"
	.string "once they are purified, the effects\l"
	.string "will be removed and they will function\l"
	.string "like a normal POKEBALL would.\p"
	.string "Now your first assignment, there has\n"
	.string "been a trainer spotted near the grass\l"
	.string "on the other side of the bridge on\l"
	.string "ROUTE 24. Find him and see if he has\l"
	.string "a Shadow POKEMON. Our reports say he\l"
	.string "does.$"

WesHideout_Entrance_Text_Wes_AfterGift:
	.string "Head to ROUTE 24 and find that\n"
	.string "trainer. Be ready to snag if you\l"
	.string "see a Shadow POKEMON.$"
