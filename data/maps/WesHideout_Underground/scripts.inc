WesHideout_Underground_MapScripts::
	.byte 0

#define LOCALID_BIRCH 1
#define LOCALID_ELM 2
#define LOCALID_KUKUI 3
#define LOCALID_SYCAMORE 4
#define LOCALID_MAGNOLIA 5
#define LOCALID_ROWAN 6
#define LOCALID_JUNIPER 7

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

WesHideout_Underground_Speaker_Birch:
	.string "BIRCH$"

WesHideout_Underground_Speaker_Elm:
	.string "ELM$"

WesHideout_Underground_Speaker_Kukui:
	.string "KUKUI$"

WesHideout_Underground_Speaker_Sycamore:
	.string "SYCAMORE$"

WesHideout_Underground_Speaker_Magnolia:
	.string "MAGNOLIA$"

WesHideout_Underground_Speaker_Rowan:
	.string "ROWAN$"

WesHideout_Underground_Speaker_Juniper:
	.string "JUNIPER$"

@ =========================================================
@ PROFESSORS
@ =========================================================

WesHideout_Underground_EventScript_Birch::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Birch
	checkflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	goto_if_eq WesHideout_Underground_EventScript_Birch_After
	msgbox WesHideout_Underground_Text_Birch_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Birch_After::
	msgbox WesHideout_Underground_Text_Birch_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Elm::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Elm
	checkflag FLAG_WES_HIDEOUT_TALKED_ELM
	goto_if_eq WesHideout_Underground_EventScript_Elm_After
	msgbox WesHideout_Underground_Text_Elm_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_ELM
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Elm_After::
	msgbox WesHideout_Underground_Text_Elm_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Kukui::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Kukui
	checkflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	goto_if_eq WesHideout_Underground_EventScript_Kukui_After
	msgbox WesHideout_Underground_Text_Kukui_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Kukui_After::
	msgbox WesHideout_Underground_Text_Kukui_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Sycamore::
	lockall
	checkflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	goto_if_eq WesHideout_Underground_EventScript_Sycamore_After
	call WesHideout_Underground_EventScript_MagnoliaSycamore_Intro
	call WesHideout_Underground_EventScript_GiveShadowMonitor
	setflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	setflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Sycamore_After::
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_Sycamore_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Magnolia::
	lockall
	checkflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	goto_if_eq WesHideout_Underground_EventScript_Magnolia_After
	call WesHideout_Underground_EventScript_MagnoliaSycamore_Intro
	call WesHideout_Underground_EventScript_GiveShadowMonitor
	setflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	setflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Magnolia_After::
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_Magnolia_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_Rowan::
	lock
	faceplayer
	goto WesHideout_Underground_EventScript_Rowan_Talk_Object

WesHideout_Underground_EventScript_GiveShadowMonitor::
	checkflag FLAG_RECEIVED_SHADOW_MONITOR
	goto_if_eq WesHideout_Underground_EventScript_GiveShadowMonitor_Done
	setspeaker WesHideout_Underground_Speaker_Sycamore
	giveitem ITEM_SHADOW_MONITOR
	setflag FLAG_RECEIVED_SHADOW_MONITOR
	msgbox WesHideout_Underground_Text_Sycamore_ShadowMonitor_Given, MSGBOX_NPC
	closemessage
WesHideout_Underground_EventScript_GiveShadowMonitor_Done::
	return

WesHideout_Underground_EventScript_Rowan_Talk_Object::
	setspeaker WesHideout_Underground_Speaker_Rowan
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_Rowan_Talk_Object_After
	call WesHideout_Underground_EventScript_Rowan_IntroSequence
	setflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Rowan_Talk_Object_After::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_After, MSGBOX_NPC
	closemessage
	release
	end

WesHideout_Underground_EventScript_Juniper::
	lock
	faceplayer
	setspeaker WesHideout_Underground_Speaker_Juniper
	checkflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	goto_if_eq WesHideout_Underground_EventScript_Juniper_After
	msgbox WesHideout_Underground_Text_Juniper_Intro, MSGBOX_NPC
	closemessage
	setflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	call WesHideout_Underground_EventScript_CheckAllProfessors
	release
	end

WesHideout_Underground_EventScript_Juniper_After::
	msgbox WesHideout_Underground_Text_Juniper_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ ROWAN TRIGGERS
@ =========================================================

WesHideout_Underground_EventScript_RowanTrigger_0::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_0
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_RowanTrigger_1::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_1
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_RowanTrigger_2::
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_RowanTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	applymovement LOCALID_ROWAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROWAN, WesHideout_Underground_Movement_RowanApproach_2
	waitmovement 0
	goto WesHideout_Underground_EventScript_Rowan_Talk_Trigger

WesHideout_Underground_EventScript_Rowan_Talk_Trigger::
	call WesHideout_Underground_EventScript_FaceRowanAndPlayer
	setspeaker WesHideout_Underground_Speaker_Rowan
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_Rowan_Talk_Trigger_After
	call WesHideout_Underground_EventScript_Rowan_IntroSequence
	setflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	call WesHideout_Underground_EventScript_CheckAllProfessors
	releaseall
	end

WesHideout_Underground_EventScript_Rowan_IntroSequence::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_1, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_2, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_3, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_Intro_4, MSGBOX_NPC
	closemessage
	return

WesHideout_Underground_EventScript_Rowan_Talk_Trigger_After::
	setspeaker WesHideout_Underground_Speaker_Rowan
	msgbox WesHideout_Underground_Text_Rowan_After, MSGBOX_NPC
	closemessage
	releaseall
	end

WesHideout_Underground_EventScript_RowanTrigger_Done::
	end

@ =========================================================
@ MAGNOLIA + SYCAMORE INTRO
@ =========================================================

WesHideout_Underground_EventScript_MagnoliaSycamore_Intro::
	turnobject LOCALID_MAGNOLIA, DIR_EAST
	turnobject LOCALID_SYCAMORE, DIR_WEST
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Prep1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_MAGNOLIA, DIR_EAST
	turnobject LOCALID_SYCAMORE, DIR_WEST
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Prep2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	applymovement LOCALID_SYCAMORE, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectmovementtype LOCALID_MAGNOLIA, MOVEMENT_TYPE_NONE
	setobjectmovementtype LOCALID_SYCAMORE, MOVEMENT_TYPE_NONE
	applymovement LOCALID_MAGNOLIA, Common_Movement_FacePlayer
	applymovement LOCALID_SYCAMORE, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player1, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player2, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player3, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player4, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player5, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player6, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player7, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Sycamore
	msgbox WesHideout_Underground_Text_MagSycamore_Player8, MSGBOX_NPC
	closemessage
	setspeaker WesHideout_Underground_Speaker_Magnolia
	msgbox WesHideout_Underground_Text_MagSycamore_Player9, MSGBOX_NPC
	closemessage
	return

@ =========================================================
@ FACE ROWAN + PLAYER
@ =========================================================

WesHideout_Underground_EventScript_FaceRowanAndPlayer::
	getplayerxy VAR_0x8000, VAR_0x8001
	getobjectcurrentxy LOCALID_ROWAN, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
	goto_if_lt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_PlayerAboveRowan
	goto_if_gt VAR_0x8001, VAR_0x8003, WesHideout_Underground_EventScript_PlayerBelowRowan
	goto_if_lt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_PlayerLeftRowan
	goto_if_gt VAR_0x8000, VAR_0x8002, WesHideout_Underground_EventScript_PlayerRightRowan
	return

WesHideout_Underground_EventScript_PlayerAboveRowan::
	turnobject LOCALID_ROWAN, DIR_NORTH
	turnobject LOCALID_PLAYER, DIR_SOUTH
	return

WesHideout_Underground_EventScript_PlayerBelowRowan::
	turnobject LOCALID_ROWAN, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH
	return

WesHideout_Underground_EventScript_PlayerLeftRowan::
	turnobject LOCALID_ROWAN, DIR_WEST
	turnobject LOCALID_PLAYER, DIR_EAST
	return

WesHideout_Underground_EventScript_PlayerRightRowan::
	turnobject LOCALID_ROWAN, DIR_EAST
	turnobject LOCALID_PLAYER, DIR_WEST
	return

@ =========================================================
@ MOVEMENTS
@ =========================================================

WesHideout_Underground_Movement_RowanApproach_0:
	walk_right
	walk_up
	step_end

WesHideout_Underground_Movement_RowanApproach_1:
	walk_right
	step_end

WesHideout_Underground_Movement_RowanApproach_2:
	walk_right
	walk_right
	step_end

@ =========================================================
@ FLAGS: CHECK ALL PROFESSORS
@ =========================================================

WesHideout_Underground_EventScript_CheckAllProfessors::
	checkflag FLAG_WES_HIDEOUT_TALKED_BIRCH
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_ELM
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_KUKUI
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_SYCAMORE
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_MAGNOLIA
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_ROWAN
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	checkflag FLAG_WES_HIDEOUT_TALKED_JUNIPER
	goto_if_eq WesHideout_Underground_EventScript_CheckAllProfessors_Done
	setflag FLAG_WES_HIDEOUT_TEAM_BRIEFED
WesHideout_Underground_EventScript_CheckAllProfessors_Done::
	return

@ =========================================================
@ TEXT
@ =========================================================

WesHideout_Underground_Text_Birch_Intro:
	.string "Hey there kid! Name's PROF. BIRCH.\n"
	.string "I'm known to talk a lot, hahaha.\p"
	.string "Lucky for you I'm fixing the machine\n"
	.string "that brought you here.\p"
	.string "We managed to replicate the portals\n"
	.string "with a special POKEMON, CELEBI.\p"
	.string "When we opened your portal, CELEBI\n"
	.string "freaked out and dipped out.\p"
	.string "It left this thing in shambles.\n"
	.string "We still have no clue where it went.\p"
	.string "We don't know why it was alarmed.\n"
	.string "It likely has to do with CIPHER.\p"
	.string "Can you do me a favor and track it\n"
	.string "down? MICHAEL said CELEBI was used.\p"
	.string "In WES's timeline it helped purify\n"
	.string "Shadow POKEMON and has helped us.\p"
	.string "It has been helping us since we\n"
	.string "learned of the problem.\p"
	.string "I research POKEMON habitats.\n"
	.string "I found CELEBI wounded in a forest.\p"
	.string "It was scrambling as CIPHER captured\n"
	.string "forest POKEMON.\p"
	.string "We helped it recover, and it began\n"
	.string "to aid us by opening a portal.\p"
	.string "That let us communicate with PROF.\n"
	.string "TURO in the future.\p"
	.string "Before we lost contact, something\n"
	.string "seemed to happen to him.\p"
	.string "We need to get CELEBI back and fix\n"
	.string "things before CIPHER gets it.\p"
	.string "Please do your best!\n"
	.string "MAY and BRENDAN are out scouting.$"

WesHideout_Underground_Text_Birch_After:
	.string "Please keep an eye out for CELEBI.\n"
	.string "We need it back.$"

WesHideout_Underground_Text_Elm_Intro:
	.string "This is a disaster! Sorry, I'm PROF.\n"
	.string "ELM, and I'm a little overwhelmed.\p"
	.string "PROF. OAK was close to solving\n"
	.string "the Shadow POKEMON origins!\p"
	.string "There's a professor named KRANE\n"
	.string "in MICHAEL's timeline.\p"
	.string "He knew a lot about Shadow POKEMON\n"
	.string "and even built a system to purify.\p"
	.string "It can open the closed heart of\n"
	.string "even legendary POKEMON!\p"
	.string "The problem is KRANE is missing\n"
	.string "and our time machine is busted!\p"
	.string "We planned to pull him in after\n"
	.string "you, but the device failed.\p"
	.string "The KRANE of this timeline never\n"
	.string "met Shadow POKEMON, so he's useless.\p"
	.string "I specialize in breeding POKEMON\n"
	.string "eggs, but I'm not much use here.\p"
	.string "Shadow POKEMON can't seem to breed.\n"
	.string "We need to secure one for research.\p"
	.string "Taking POKEMON from trainers is bad,\n"
	.string "but closing their hearts is worse!\p"
	.string "We must capture every Shadow POKEMON\n"
	.string "CIPHER created.\p"
	.string "We must restore their hearts.\n"
	.string "ETHAN and LYRA are hunting trainers.\p"
	.string "They're adding them to the SHADOW\n"
	.string "MONITOR. We have at least 70 kinds.\p"
	.string "They're taking a beating out there.\n"
	.string "Please help them!$"

WesHideout_Underground_Text_Elm_After:
	.string "Please help ETHAN and LYRA.\n"
	.string "We need more Shadow data.$"

WesHideout_Underground_Text_Kukui_Intro:
	.string "Alola! Good to finally meet you,\n"
	.string "champ! We know more about you.\p"
	.string "We know more about you than you do.\n"
	.string "I'm PROF. KUKUI, a move researcher.\p"
	.string "Nobody in this timeline has heard\n"
	.string "of Z MOVES. Can you believe it?!\p"
	.string "Luckily I know all about them.\n"
	.string "We'll roll out Z CRYSTALS soon.\p"
	.string "They'll help us take down CIPHER.\n"
	.string "I've researched Shadow POKEMON.\p"
	.string "Their movepools are bizarre.\n"
	.string "If you can snag some, bring me one.\p"
	.string "Oh, nobody explained snagging yet?\n"
	.string "Yeah... you're basically a thief.\p"
	.string "But it's for the right reasons.\n"
	.string "We'll be here, so stop by again!$"

WesHideout_Underground_Text_Kukui_After:
	.string "Stop by again! We'll be here.\n"
	.string "for some time.$"

WesHideout_Underground_Text_Sycamore_After:
	.string "Use the SHADOW MONITOR to track\n"
	.string "Shadow POKeMON you snag.\p"
	.string "Bring me data when you can.\n"
	.string "It will help us refine it.$"

WesHideout_Underground_Text_Magnolia_After:
	.string "It's about time to take CIPHER down!\n"
	.string "Go see WES upstairs.\p"
	.string "I believe he has something special\n"
	.string "for you.$"

WesHideout_Underground_Text_Rowan_Intro_1:
	.string "Oh, you finally made it.\n"
	.string "That email wasn't from PROF. OAK.\p"
	.string "It was actually sent by me.\n"
	.string "Truth is, we don't know where he is.\p"
	.string "CIPHER is on the move and likely\n"
	.string "kidnapped him for his Shadow work.\p"
	.string "Sorry, I got ahead of myself.\n"
	.string "I'm PROF. ROWAN from SINNOH.\p"
	.string "Everyone here was pulled into this\n"
	.string "bizarre timeline from another one.\p"
	.string "It took us quite a while to wrap\n"
	.string "our heads around it.$"

WesHideout_Underground_Text_Rowan_Intro_2:
	.string "WES and MICHAEL have been a help.\n"
	.string "They filled us in on the situation.\p"
	.string "WES called us here after talking\n"
	.string "with GARY OAK, who later vanished.\p"
	.string "The two of them located all of us.\n"
	.string "We combined our research to face it.\p"
	.string "CIPHER recruited teams everywhere.\n"
	.string "Including TEAM ROCKET and PLASMA.\p"
	.string "Reports suggest TEAM AQUA and MAGMA\n"
	.string "are involved. We cannot allow it.\p"
	.string "We can't let them corrupt POKEMON.\n"
	.string "Their hearts must be saved.$"

WesHideout_Underground_Text_Rowan_Intro_3:
	.string "We've made progress on a way to\n"
	.string "restore Shadow POKEMON hearts.\p"
	.string "According to MICHAEL, they've begun\n"
	.string "something called conversion XD.\p"
	.string "Whatever that means, he's panicked.\n"
	.string "You're wondering why we chose you.\p"
	.string "You may not know this, but you're\n"
	.string "one of the greatest trainers ever.\p"
	.string "PROF. TURO's text confirms it.\n"
	.string "He's in the future.\p"
	.string "I know it makes no sense.\n"
	.string "Nothing about our situation does.$"

WesHideout_Underground_Text_Rowan_Intro_4:
	.string "We learned to manipulate the portals\n"
	.string "that keep appearing everywhere.\p"
	.string "We tried to pull you here, but we\n"
	.string "misfired and got a younger you.\p"
	.string "You hadn't even battled yet, hahaha.\n"
	.string "So you must prove PROF. TURO right!\p"
	.string "With our research and your skill,\n"
	.string "we can prevail.\p"
	.string "You will not be alone out there.\n"
	.string "LUCAS and DAWN are helping us.\p"
	.string "Speak to the other professors.\n"
	.string "PROF. SYCAMORE should be done now!$"

WesHideout_Underground_Text_Rowan_After:
	.string "Speak to the other professors.\n"
	.string "PROF. SYCAMORE should be done now!$"

WesHideout_Underground_Text_Juniper_Intro:
	.string "Hey there, you finally joined us.\n"
	.string "I'm PROF. JUNIPER.\p"
	.string "I study POKEMON origins.\n"
	.string "I'm here to study Shadow POKEMON.\p"
	.string "CIPHER is corrupting POKEMON hearts.\n"
	.string "But how did this start?\p"
	.string "We believe a deeper force is behind\n"
	.string "this plan.\p"
	.string "With your help, we'll bring CIPHER\n"
	.string "down once and for all!$"

WesHideout_Underground_Text_Juniper_After:
	.string "Let's bring CIPHER down once and\n"
	.string "for all!$"

WesHideout_Underground_Text_MagSycamore_Prep1:
	.string "So you're telling me this bracelet\n"
	.string "and stone can change a POKEMON form?$"

WesHideout_Underground_Text_MagSycamore_Prep2:
	.string "Yup! It's called MEGA EVOLUTION.\n"
	.string "I can't believe GALAR has DYNAMAX.\p"
	.string "A POKEMON getting that large is\n"
	.string "mind blowing, honestly!$"

WesHideout_Underground_Text_MagSycamore_Player1:
	.string "Ah, {PLAYER}.\n"
	.string "Glad you could join us.$"

WesHideout_Underground_Text_MagSycamore_Player2:
	.string "HEY! We have been waiting for you\n"
	.string "for quite some time!\p"
	.string "The time machine was supposed to\n"
	.string "bring you here, but it sent you off.\p"
	.string "Somewhere west of PALLET TOWN.\n"
	.string "Blame BIRCH for that one, hahaha.$"

WesHideout_Underground_Text_MagSycamore_Player3:
	.string "I'm PROF. MAGNOLIA.\n"
	.string "I study DYNAMAX POKEMON in GALAR.$"

WesHideout_Underground_Text_MagSycamore_Player4:
	.string "I'm PROF. SYCAMORE from KALOS.\n"
	.string "I'm an expert in MEGA EVOLUTION!$"

WesHideout_Underground_Text_MagSycamore_Player5:
	.string "To our surprise, this timeline\n"
	.string "never saw MEGA EVOLUTION or Z MOVES.\p"
	.string "It hasn't seen DYNAMAX either.\n"
	.string "Luckily we arrived prepared.\p"
	.string "We can stop CIPHER.\n"
	.string "ELIO and SERENA have MEGA BRACELETS.\p"
	.string "They'll provide them to GYM LEADERS\n"
	.string "and ELITE FOUR if they meet CIPHER.$"

WesHideout_Underground_Text_MagSycamore_Player6:
	.string "VICTOR and GLORIA are handing out\n"
	.string "DYNAMAX BANDS across the region.\p"
	.string "We also see power spots appear.\n"
	.string "Stay alert!$"

WesHideout_Underground_Text_MagSycamore_Player7:
	.string "With help from WES, MICHAEL, ETHAN,\n"
	.string "and LYRA, we built a SHADOW MONITOR.\p"
	.string "It's ready now.\n"
	.string "It will track Shadow POKeMON.\p"
	.string "It will also track the trainers who\n"
	.string "have them.$"

WesHideout_Underground_Text_MagSycamore_Player8:
	.string "As we gather more data and intel,\n"
	.string "we can keep adding to the monitor.\p"
	.string "We'll snag every Shadow POKEMON.\n"
	.string "With everyone helping, CIPHER falls.$"

WesHideout_Underground_Text_Sycamore_ShadowMonitor_Given:
	.string "Here, take the SHADOW MONITOR.\p"
	.string "It will help you track Shadow POKeMON\n"
	.string "and the trainers who hold them.$"

WesHideout_Underground_Text_MagSycamore_Player9:
	.string "It's about time to take CIPHER down!\n"
	.string "Go see WES upstairs.\p"
	.string "I believe he has something special\n"
	.string "for you.$"
