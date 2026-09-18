RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustboroCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0
RustboroCity_OnLoad::
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 1
	setflag FLAG_HIDE_RUSTBORO_CITY_TIME_RING
	hideobjectat LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY
	removeobject LOCALID_RUSTBORO_CITY_TIME_RING
	goto_if_unset FLAG_RUSTBORO_CITY_TIME_RING_EMERGE, RustboroCity_OnLoad_Done
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	hideobjectat LOCALID_PLAYER, MAP_RUSTBORO_CITY
RustboroCity_OnLoad_Done:
	end

RustboroCity_OnTransition::
	setflag FLAG_HIDE_RUSTBORO_CITY_TIME_RING
	hideobjectat LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY
	removeobject LOCALID_RUSTBORO_CITY_TIME_RING
	goto_if_unset FLAG_RUSTBORO_CITY_TIME_RING_EMERGE, RustboroCity_OnTransition_Done
	hideobjectat LOCALID_PLAYER, MAP_RUSTBORO_CITY
RustboroCity_OnTransition_Done:
	end

RustboroCity_OnWarp::
	map_script_2 VAR_TEMP_3, 0, RustboroCity_EventScript_HidePlayerOnWarp
	.2byte 0

RustboroCity_OnFrame:
	map_script_2 VAR_TEMP_1, 0, RustboroCity_EventScript_CityEnterQuest
	map_script_2 VAR_TEMP_2, 0, RustboroCity_EventScript_PlayerEmerges
	.2byte 0

RustboroCity_EventScript_HidePlayerOnWarp::
	goto_if_unset FLAG_RUSTBORO_CITY_TIME_RING_EMERGE, RustboroCity_EventScript_HidePlayerOnWarp_Done
	hideobjectat LOCALID_PLAYER, MAP_RUSTBORO_CITY
RustboroCity_EventScript_HidePlayerOnWarp_Done:
	end

RustboroCity_EventScript_PlayerEmerges::
	lockall
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 1
	clearflag FLAG_RUSTBORO_CITY_TIME_RING_EMERGE
	hideobjectat LOCALID_PLAYER, MAP_RUSTBORO_CITY
	setobjectxy LOCALID_PLAYER, 16, 55
	setobjectxyperm LOCALID_PLAYER, 16, 55
	clearflag FLAG_HIDE_RUSTBORO_CITY_TIME_RING
	addobject LOCALID_RUSTBORO_CITY_TIME_RING
	hideobjectat LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY
	setobjectxy LOCALID_RUSTBORO_CITY_TIME_RING, 16, 55
	setobjectxyperm LOCALID_RUSTBORO_CITY_TIME_RING, 16, 55
	showobjectat LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY
	setobjectsubpriority LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY, 1
	setvar VAR_0x8001, 16
	setvar VAR_0x8002, 55
	setvar VAR_0x8004, LOCALID_RUSTBORO_CITY_TIME_RING
	special Special_HoopaRingSpawnGrow
	waitstate
	playse SE_LAVARIDGE_FALL_WARP
	setobjectsubpriority LOCALID_PLAYER, MAP_RUSTBORO_CITY, 0
	showobjectat LOCALID_PLAYER, MAP_RUSTBORO_CITY
	setvar VAR_0x8000, LOCALID_PLAYER
	special Special_ObjectEventEmerge
	applymovement LOCALID_PLAYER, RustboroCity_Movement_StepFromPortal_First
	waitmovement 0
	applymovement LOCALID_PLAYER, RustboroCity_Movement_StepFromPortal_Second
	waitmovement 0
	setvar VAR_0x8004, LOCALID_RUSTBORO_CITY_TIME_RING
	special Special_HoopaRingShrinkDespawn
	waitstate
	hideobjectat LOCALID_RUSTBORO_CITY_TIME_RING, MAP_RUSTBORO_CITY
	setflag FLAG_HIDE_RUSTBORO_CITY_TIME_RING
	removeobject LOCALID_RUSTBORO_CITY_TIME_RING
	resetobjectsubpriority LOCALID_PLAYER, MAP_RUSTBORO_CITY
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 57
	special SetCameraFocusCoordsFromVars
	setvar VAR_TEMP_1, 0
	releaseall
	end

RustboroCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	setflag FLAG_VISITED_RUSTBORO_CITY
	checkflag FLAG_QUEST_RUSTBORO_NPCS_STARTED
	goto_if_eq RustboroCity_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_RUSTBORO_NPCS_COMPLETED
	goto_if_eq RustboroCity_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_RUSTBORO_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
RustboroCity_EventScript_CityEnterQuest_End:
	end

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_Movement_StepFromPortal_First:
	walk_down
	step_end

RustboroCity_Movement_StepFromPortal_Second:
	walk_down
	step_end

RustboroCity_EventScript_MayTriggerTop::
	checkflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	goto_if_eq RustboroCity_EventScript_MayTrigger_Done
	goto_if_unset FLAG_QUEST_FIND_BRENDAN_MAY_STARTED, RustboroCity_EventScript_MayTrigger_Done
	checkflag FLAG_QUEST_FIND_BRENDAN_MAY_COMPLETED
	goto_if_eq RustboroCity_EventScript_MayTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	waitse
	goto RustboroCity_EventScript_MayScene

RustboroCity_EventScript_MayTriggerBottom::
	checkflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	goto_if_eq RustboroCity_EventScript_MayTrigger_Done
	goto_if_unset FLAG_QUEST_FIND_BRENDAN_MAY_STARTED, RustboroCity_EventScript_MayTrigger_Done
	checkflag FLAG_QUEST_FIND_BRENDAN_MAY_COMPLETED
	goto_if_eq RustboroCity_EventScript_MayTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	playse SE_PIN
	waitse
	goto RustboroCity_EventScript_MayScene

RustboroCity_EventScript_MayScene::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setspeaker RustboroCity_Speaker_May
	msgbox RustboroCity_Text_MayFindBrendanMayQuest, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_FIND_BRENDAN_MAY_COMPLETED
	setflag FLAG_QUEST_MORE_TO_COME_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	releaseall
	end

RustboroCity_EventScript_MayTrigger_Done:
	end

RustboroCity_Movement_MayApproachTop:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_Movement_BlazikenApproachTop:
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_right
	step_end

RustboroCity_Movement_MayApproachBottom:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_Movement_BlazikenApproachBottom:
	walk_up
	walk_right
	walk_in_place_faster_right
	step_end

RustboroCity_Movement_MayExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_Movement_BlazikenExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_CooltrainerF::
	faceplayer
	setspeaker RustboroCity_Speaker_Naomi
	msgbox RustboroCity_Text_CooltrainerF, MSGBOX_NPC
	end

RustboroCity_EventScript_FatMan::
	faceplayer
	setspeaker RustboroCity_Speaker_Gordon
	msgbox RustboroCity_Text_FatMan, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	faceplayer
	setspeaker RustboroCity_Speaker_Taro
	msgbox RustboroCity_Text_NinjaBoy, MSGBOX_NPC
	end

RustboroCity_EventScript_Twin::
	faceplayer
	setspeaker RustboroCity_Speaker_Mina
	msgbox RustboroCity_Text_Twin, MSGBOX_NPC
	end

RustboroCity_EventScript_BreederM::
	faceplayer
	setspeaker RustboroCity_Speaker_Silas
	msgbox RustboroCity_Text_BreederM, MSGBOX_NPC
	end

RustboroCity_EventScript_CooltrainerM::
	faceplayer
	setspeaker RustboroCity_Speaker_Grant
	msgbox RustboroCity_Text_CooltrainerM, MSGBOX_NPC
	end

RustboroCity_EventScript_LittleBoy::
	faceplayer
	setspeaker RustboroCity_Speaker_Ollie
	msgbox RustboroCity_Text_LittleBoy, MSGBOX_NPC
	end

RustboroCity_EventScript_LittleGirl::
	faceplayer
	setspeaker RustboroCity_Speaker_Poppy
	msgbox RustboroCity_Text_LittleGirl, MSGBOX_NPC
	end

RustboroCity_EventScript_RuinManiac::
	faceplayer
	setspeaker RustboroCity_Speaker_Bram
	msgbox RustboroCity_Text_RuinManiac, MSGBOX_NPC
	end

RustboroCity_EventScript_DragonTamer::
	faceplayer
	setspeaker RustboroCity_Speaker_Darius
	msgbox RustboroCity_Text_DragonTamer, MSGBOX_NPC
	end

RustboroCity_EventScript_Boy1::
	faceplayer
	setspeaker RustboroCity_Speaker_Evan
	msgbox RustboroCity_Text_Boy1, MSGBOX_NPC
	end

RustboroCity_EventScript_Rival::
	faceplayer
	setspeaker RustboroCity_Speaker_Rival
	msgbox RustboroCity_Text_Rival, MSGBOX_NPC
	end

RustboroCity_EventScript_May::
	faceplayer
	setspeaker RustboroCity_Speaker_May
	msgbox RustboroCity_Text_MayTalk, MSGBOX_NPC
	end

RustboroCity_EventScript_Blaziken::
	lock
	faceplayer
	setspeaker RustboroCity_Speaker_Blaziken
	waitse
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_Blaziken, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Speaker_Naomi:
	.string "Naomi$"

RustboroCity_Speaker_Gordon:
	.string "Gordon$"

RustboroCity_Speaker_Taro:
	.string "Taro$"

RustboroCity_Speaker_Mina:
	.string "Mina$"

RustboroCity_Speaker_Silas:
	.string "Silas$"

RustboroCity_Speaker_Grant:
	.string "Grant$"

RustboroCity_Speaker_Ollie:
	.string "Ollie$"

RustboroCity_Speaker_Poppy:
	.string "Poppy$"

RustboroCity_Speaker_Bram:
	.string "Bram$"

RustboroCity_Speaker_Darius:
	.string "Darius$"

RustboroCity_Speaker_Evan:
	.string "Evan$"

RustboroCity_Speaker_May:
	.string "May$"

RustboroCity_Speaker_Rival:
	.string "Rival$"

RustboroCity_Speaker_Blaziken:
	.string "Blaziken$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”\p"
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“For all your living needs, we make\n"
	.string "it all.”$"

RustboroCity_Text_GymSign:
	.string "RUSTBORO CITY POKéMON GYM\n"
	.string "LEADER: ROXANNE\p"
	.string "“The GROUND-loving honors student!”$"

RustboroCity_Text_CitySign:
	.string "RUSTBORO CITY\p"
	.string "“The city probing the integration of\n"
	.string "nature and science.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“We'll teach you anything about\n"
	.string "POKéMON!”$"

RustboroCity_Text_CuttersHouse:
	.string "CUTTER'S HOUSE$"

RustboroCity_Text_CooltrainerF:
	.string "The TRAINER'S SCHOOL in this city is\n"
	.string "why so many people in RUSTBORO know\l"
	.string "their stuff.$"

RustboroCity_Text_FatMan:
	.string "DEVON and the GYM keep this city busy.\n"
	.string "There's always someone hurrying\l"
	.string "somewhere.$"

RustboroCity_Text_NinjaBoy:
	.string "I practice sneaking through town\n"
	.string "without startling anyone.\p"
	.string "A true ninja should move like a gust\n"
	.string "of wind.$"

RustboroCity_Text_Twin:
	.string "I like peeking into the TRAINER'S\n"
	.string "SCHOOL windows.\p"
	.string "It makes me want to study harder.$"

RustboroCity_Text_BreederM:
	.string "If you raise POKéMON with patience,\n"
	.string "they'll surprise you before long.$"

RustboroCity_Text_CooltrainerM:
	.string "ROXANNE is tough, but she teaches at\n"
	.string "the school, too.\p"
	.string "That says a lot about this city.$"

RustboroCity_Text_LittleBoy:
	.string "I want to be the kind of TRAINER who\n"
	.string "gets invited into DEVON someday.$"

RustboroCity_Text_LittleGirl:
	.string "Everyone says ROXANNE is strict, but\n"
	.string "I think that just means she cares.$"

RustboroCity_Text_RuinManiac:
	.string "RUSTBORO was built by people who knew\n"
	.string "how to pull value out of stone.$"

RustboroCity_Text_DragonTamer:
	.string "A city full of rock and steel still\n"
	.string "dreams about dragons sometimes.$"

RustboroCity_Text_Boy1:
	.string "The DEVON people make all sorts of\n"
	.string "gadgets.\p"
	.string "I wish I knew how any of them worked.$"

RustboroCity_Text_Rival:
	.string "RUSTBORO's quiet on the surface, but\n"
	.string "everyone here is watching the roads.$"

RustboroCity_Text_MayTalk:
	.string "I'm heading north once I'm done here.\p"
	.string "If Cipher is moving around LAVARIDGE,\n"
	.string "we need to know why.$"

RustboroCity_Text_Blaziken:
	.string "BLAZIKEN: Shaaah!$"

RustboroCity_Text_MayFindBrendanMayQuest:
	.string "Hi! You must be {PLAYER}.\p"
	.string "I just got off a call with Wes, and\n"
	.string "he gave me a very quick run down.\p"
	.string "Seems like you were looking for me\n"
	.string "and Brendan to see what we're up to.\p"
	.string "Well honestly...\n"
	.string "We're kinda trying to figure it out\l"
	.string "too haha.\p"
	.string "We have been hearing a lot of strange\n"
	.string "things happening in the Hoenn region,\l"
	.string "including Cipher activity north of\l"
	.string "Lavaridge Town.\p"
	.string "I'm heading that way myself.\p"
	.string "Brendan is in a meeting with Steven\n"
	.string "and Mr. Stone right now.\p"
	.string "You should go see what's going on!\p"
	.string "I'll catch you later, {PLAYER}.$"
