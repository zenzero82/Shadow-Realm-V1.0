RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnFrame:
	map_script_2 VAR_TEMP_1, 0, RustboroCity_EventScript_CityEnterQuest
	.2byte 0

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
	.string "“The ROCK-loving honors student!”$"

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
