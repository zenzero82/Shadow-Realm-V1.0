Lavender_Town_MapScripts::
	.byte 0

#define LOCALID_LYRA 5
#define LOCALID_MEGANIUM 10

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Lavender_Town_Speaker_Lyra:
	.string "LYRA$"

Lavender_Town_Speaker_Birch:
	.string "PROF. BIRCH$"

@ =========================================================
@ TRIGGERS
@ =========================================================

Lavender_Town_EventScript_LyraTrigger_Left::
	goto_if_set FLAG_LAVENDER_LYRA_SCENE_DONE, Lavender_Town_EventScript_LyraTrigger_Done
	lockall
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraToPlayer_Left
	applymovement LOCALID_MEGANIUM, Lavender_Town_Movement_LyraToPlayer_Left
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Lavender_Town_EventScript_LyraScene

Lavender_Town_EventScript_LyraTrigger_Right::
	goto_if_set FLAG_LAVENDER_LYRA_SCENE_DONE, Lavender_Town_EventScript_LyraTrigger_Done
	lockall
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraToPlayer_Right
	applymovement LOCALID_MEGANIUM, Lavender_Town_Movement_LyraToPlayer_Right
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Lavender_Town_EventScript_LyraScene

Lavender_Town_EventScript_LyraScene::
	setspeaker Lavender_Town_Speaker_Lyra
	msgbox Lavender_Town_Text_LyraIntro, MSGBOX_DEFAULT
	setspeaker Lavender_Town_Speaker_Lyra
	msgbox Lavender_Town_Text_LyraPlasma, MSGBOX_DEFAULT
	setspeaker Lavender_Town_Speaker_Lyra
	msgbox Lavender_Town_Text_LyraShadow, MSGBOX_DEFAULT
	setspeaker Lavender_Town_Speaker_Birch
	pokenavcall Lavender_Town_Text_BirchCall
	waitmessage
	setspeaker Lavender_Town_Speaker_Lyra
	msgbox Lavender_Town_Text_LyraReturn, MSGBOX_DEFAULT
	setflag FLAG_LAVENDER_LYRA_SCENE_DONE
	setflag FLAG_WES_HIDEOUT_LYRA_SCENE
	fadescreen FADE_TO_BLACK
	warp MAP_WES_HIDEOUT_UNDERGROUND, 25, 12
	waitstate
	end

Lavender_Town_EventScript_LyraTrigger_Done::
	end

@ =========================================================
@ MOVEMENTS
@ =========================================================

Lavender_Town_Movement_LyraToPlayer_Left:
	walk_right
	walk_right
	walk_up
	face_up
	step_end

Lavender_Town_Movement_LyraToPlayer_Right:
	walk_right
	walk_right
	walk_right
	walk_up
	face_up
	step_end

@ =========================================================
@ TEXT
@ =========================================================

Lavender_Town_Text_LyraIntro:
	.string "Hey! I'm LYRA.\p"
	.string "Prof. Rowan told me you were\n"
	.string "heading this way.$"

Lavender_Town_Text_LyraPlasma:
	.string "I just took out a member of\n"
	.string "TEAM PLASMA here in LAVENDER.\p"
	.string "Seems like they setup a base nearby.\p"
	.string "... Oh! You're saying you took them\n"
	.string "on by yourself?!\p" 
	.string "That's incredible, you must be a\n"
	.string "crazy strong trainer.$"

Lavender_Town_Text_LyraShadow:
	.string "I'm heading back to the lab now to\n"
	.string "drop off some SHADOW POKéMON I\l"
	.string "snagged.$"

Lavender_Town_Text_BirchCall:
	.string "This is an emergency.\p"
	.string "Return to the lab immediately!$"

Lavender_Town_Text_LyraReturn:
	.string "We should head back ASAP!$"
