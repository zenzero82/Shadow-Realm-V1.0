Lavender_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Lavender_Town_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Lavender_Town_OnFrame
	.byte 0

Lavender_Town_OnTransition::
	setvar VAR_TEMP_1, 0
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

Lavender_Town_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Lavender_Town_EventScript_CityEnterQuest
	.2byte 0

Lavender_Town_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	checkflag FLAG_QUEST_LAVENDER_NPCS_STARTED
	goto_if_eq Lavender_Town_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_LAVENDER_NPCS_COMPLETED
	goto_if_eq Lavender_Town_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_LAVENDER_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
Lavender_Town_EventScript_CityEnterQuest_End:
	end

#define LOCALID_LYRA 1
#define LOCALID_MEGANIUM 6

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Lavender_Town_Speaker_Lyra:
	.string "LYRA$"

Lavender_Town_Speaker_Birch:
	.string "PROF. BIRCH$"

Lavender_Town_Speaker_LittleBoy:
	.string "BOY$"

Lavender_Town_Speaker_BaldingMan:
	.string "BALDING MAN$"

Lavender_Town_Speaker_BattleGirl:
	.string "BATTLE GIRL$"

Lavender_Town_Speaker_OldMan:
	.string "OLD MAN$"

@ =========================================================
@ TRIGGERS
@ =========================================================

Lavender_Town_EventScript_LyraTrigger_Left::
	goto_if_set FLAG_LAVENDER_LYRA_SCENE_DONE, Lavender_Town_EventScript_LyraTrigger_Done
	lockall
	playse SE_PIN
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraExclaim
	waitmovement LOCALID_LYRA
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraToPlayer_Left
	applymovement LOCALID_MEGANIUM, Lavender_Town_Movement_LyraToPlayer_Left
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	waitmovement LOCALID_MEGANIUM
	goto Lavender_Town_EventScript_LyraScene

Lavender_Town_EventScript_LyraTrigger_Right::
	goto_if_set FLAG_LAVENDER_LYRA_SCENE_DONE, Lavender_Town_EventScript_LyraTrigger_Done
	lockall
	playse SE_PIN
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraExclaim
	waitmovement LOCALID_LYRA
	applymovement LOCALID_LYRA, Lavender_Town_Movement_LyraToPlayer_Right
	applymovement LOCALID_MEGANIUM, Lavender_Town_Movement_LyraToPlayer_Right
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	waitmovement LOCALID_MEGANIUM
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
	turnobject LOCALID_PLAYER, DIR_NORTH
	fadescreen FADE_TO_BLACK
	warp MAP_WES_HIDEOUT_UNDERGROUND, 25, 12
	waitstate
	end

Lavender_Town_EventScript_LyraTrigger_Done::
	end

@ =========================================================
@ NPCS
@ =========================================================

Lavender_Town_EventScript_LittleBoy::
	faceplayer
	setspeaker Lavender_Town_Speaker_LittleBoy
	msgbox Lavender_Town_Text_LittleBoy, MSGBOX_NPC
	end

Lavender_Town_EventScript_BaldingMan::
	faceplayer
	setspeaker Lavender_Town_Speaker_BaldingMan
	msgbox Lavender_Town_Text_BaldingMan, MSGBOX_NPC
	end

Lavender_Town_EventScript_BattleGirl::
	faceplayer
	setspeaker Lavender_Town_Speaker_BattleGirl
	msgbox Lavender_Town_Text_BattleGirl, MSGBOX_NPC
	end

Lavender_Town_EventScript_OldMan::
	faceplayer
	setspeaker Lavender_Town_Speaker_OldMan
	msgbox Lavender_Town_Text_OldMan, MSGBOX_NPC
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

Lavender_Town_Movement_LyraExclaim:
	emote_exclamation_mark
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

Lavender_Town_Text_LittleBoy:
	.string "A girl with a MEGANIUM chased a\n"
	.string "TEAM PLASMA grunt through town!$"

Lavender_Town_Text_BaldingMan:
	.string "I come here for peace, but lately\n"
	.string "it's been full of rumors.$"

Lavender_Town_Text_BattleGirl:
	.string "The RADIO TOWER keeps everyone\n"
	.string "calm. I hope it stays that way.$"

Lavender_Town_Text_OldMan:
	.string "The SOUL HOUSE reminds us to honor\n"
	.string "our POKéMON.$"

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end


LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end


LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end


LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end


LavenderTown_Text_Sign:
	.string "LAVENDER TOWN\p"
	.string "The Noble Purple Town$"


LavenderTown_Text_KantoRadioStationSign:
	.string "KANTO RADIO STATION\p"
	.string "Your Favorite Programs On-Air\n"
	.string "Around the Clock!$"


LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "LAVENDER VOLUNTEER POKéMON\n"
	.string "HOUSE$"


LavenderTown_Text_SoulHouseSign:
	.string "SOUL HOUSE\p"
	.string "May the Souls of POKéMON Rest\n"
	.string "Easy$"
