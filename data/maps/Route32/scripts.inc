Route32_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	.byte 0

Route32_OnTransition:
	checkflag FLAG_ILEX_BIRCH_CALL_DONE
	goto_if_eq VAR_RESULT, FALSE, Route32_OnTransition_Done
	setflag FLAG_HIDE_ROUTE32_AQUA_GRUNT
Route32_OnTransition_Done:
	end

@ =========================================================
@ SPEAKER DEFINITIONS (Namebox)
@ =========================================================

Route32_Speaker_Youngster:
	.string "TIM$"

Route32_Speaker_Picnicker:
	.string "LINA$"

Route32_Speaker_Fisherman1:
	.string "RAY$"

Route32_Speaker_Fisherman2:
	.string "NED$"

Route32_Speaker_Fisherman3:
	.string "LEO$"

Route32_Speaker_BirdKeeper:
	.string "MILO$"

Route32_Speaker_AquaGrunt:
	.string "MASON$"

Route32_Speaker_FatMan:
	.string "HANK$"

Route32_Speaker_Camper:
	.string "CALEB$"

Route32_Speaker_YoungsterNPC:
	.string "OLLIE$"

Route32_Speaker_Cooltrainer:
	.string "KARA$"

@ =========================================================
@ TRAINERS
@ =========================================================

Route32_EventScript_Youngster::
	setspeaker Route32_Speaker_Youngster
	trainerbattle_single TRAINER_ROUTE32_YOUNGSTER, Route32_Text_Youngster_Intro, Route32_Text_Youngster_Defeat, Route32_EventScript_Youngster_After
	end

Route32_EventScript_Youngster_After::
	setspeaker Route32_Speaker_Youngster
	msgbox Route32_Text_Youngster_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_Picnicker::
	setspeaker Route32_Speaker_Picnicker
	trainerbattle_single TRAINER_ROUTE32_PICNICKER, Route32_Text_Picnicker_Intro, Route32_Text_Picnicker_Defeat, Route32_EventScript_Picnicker_After
	end

Route32_EventScript_Picnicker_After::
	setspeaker Route32_Speaker_Picnicker
	msgbox Route32_Text_Picnicker_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_Fisherman1::
	setspeaker Route32_Speaker_Fisherman1
	trainerbattle_single TRAINER_ROUTE32_FISHERMAN_1, Route32_Text_Fisherman1_Intro, Route32_Text_Fisherman1_Defeat, Route32_EventScript_Fisherman1_After
	end

Route32_EventScript_Fisherman1_After::
	setspeaker Route32_Speaker_Fisherman1
	msgbox Route32_Text_Fisherman1_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_Fisherman2::
	setspeaker Route32_Speaker_Fisherman2
	trainerbattle_single TRAINER_ROUTE32_FISHERMAN_2, Route32_Text_Fisherman2_Intro, Route32_Text_Fisherman2_Defeat, Route32_EventScript_Fisherman2_After
	end

Route32_EventScript_Fisherman2_After::
	setspeaker Route32_Speaker_Fisherman2
	msgbox Route32_Text_Fisherman2_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_Fisherman3::
	setspeaker Route32_Speaker_Fisherman3
	trainerbattle_single TRAINER_ROUTE32_FISHERMAN_3, Route32_Text_Fisherman3_Intro, Route32_Text_Fisherman3_Defeat, Route32_EventScript_Fisherman3_After
	end

Route32_EventScript_Fisherman3_After::
	setspeaker Route32_Speaker_Fisherman3
	msgbox Route32_Text_Fisherman3_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_BirdKeeper::
	setspeaker Route32_Speaker_BirdKeeper
	trainerbattle_single TRAINER_ROUTE32_BIRD_KEEPER, Route32_Text_BirdKeeper_Intro, Route32_Text_BirdKeeper_Defeat, Route32_EventScript_BirdKeeper_After
	end

Route32_EventScript_BirdKeeper_After::
	setspeaker Route32_Speaker_BirdKeeper
	msgbox Route32_Text_BirdKeeper_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_Youngster2::
	setspeaker Route32_Speaker_YoungsterNPC
	trainerbattle_single TRAINER_ROUTE32_YOUNGSTER_2, Route32_Text_Youngster2_Intro, Route32_Text_Youngster2_Defeat, Route32_EventScript_Youngster2_After
	end

Route32_EventScript_Youngster2_After::
	setspeaker Route32_Speaker_YoungsterNPC
	msgbox Route32_Text_Youngster2_After, MSGBOX_NPC
	closemessage
	release
	end

Route32_EventScript_CooltrainerTrainer::
	setspeaker Route32_Speaker_Cooltrainer
	trainerbattle_single TRAINER_ROUTE32_COOLTRAINER, Route32_Text_Cooltrainer_Intro, Route32_Text_Cooltrainer_Defeat, Route32_EventScript_CooltrainerTrainer_After
	end

Route32_EventScript_CooltrainerTrainer_After::
	setspeaker Route32_Speaker_Cooltrainer
	msgbox Route32_Text_Cooltrainer_After, MSGBOX_NPC
	closemessage
	release
	end

@ =========================================================
@ NPCS
@ =========================================================

Route32_EventScript_FatMan::
	faceplayer
	setspeaker Route32_Speaker_FatMan
	msgbox Route32_Text_FatMan, MSGBOX_NPC
	end

Route32_EventScript_Camper::
	faceplayer
	setspeaker Route32_Speaker_Camper
	msgbox Route32_Text_Camper, MSGBOX_NPC
	end

Route32_EventScript_YoungsterNPC::
	faceplayer
	setspeaker Route32_Speaker_YoungsterNPC
	msgbox Route32_Text_Youngster2_After, MSGBOX_NPC
	end

Route32_EventScript_Cooltrainer::
	faceplayer
	setspeaker Route32_Speaker_Cooltrainer
	msgbox Route32_Text_Cooltrainer_After, MSGBOX_NPC
	end

Route32_EventScript_AquaGrunt::
	faceplayer
	setspeaker Route32_Speaker_AquaGrunt
	msgbox Route32_Text_AquaGrunt, MSGBOX_NPC
	end

@ =========================================================
@ SIGNS
@ =========================================================

Route32_EventScript_SignRuins::
	msgbox Route32_Text_SignRuins, MSGBOX_SIGN
	end

Route32_EventScript_SignRoute32::
	msgbox Route32_Text_SignRoute32, MSGBOX_SIGN
	end

Route32_EventScript_SignUnionCave::
	msgbox Route32_Text_SignUnionCave, MSGBOX_SIGN
	end

@ =========================================================
@ TEXT
@ =========================================================

Route32_Text_Youngster_Intro:
	.string "I walked all the way from VIOLET!\p"
	.string "Let's battle!$"

Route32_Text_Youngster_Defeat:
	.string "I need a rest...$"

Route32_Text_Youngster_After:
	.string "This route is longer than it looks.$"

Route32_Text_Picnicker_Intro:
	.string "I came for the fresh air.\p"
	.string "A quick battle?$"

Route32_Text_Picnicker_Defeat:
	.string "Whew, you're strong!$"

Route32_Text_Picnicker_After:
	.string "I still love this view.$"

Route32_Text_Fisherman1_Intro:
	.string "I'm fishing, but a battle sounds\n"
	.string "fun.$"

Route32_Text_Fisherman1_Defeat:
	.string "No bite!$"

Route32_Text_Fisherman1_After:
	.string "I'll keep my line in the water.$"

Route32_Text_Fisherman2_Intro:
	.string "I'll reel you in!$"

Route32_Text_Fisherman2_Defeat:
	.string "You slipped away!$"

Route32_Text_Fisherman2_After:
	.string "Maybe the lake is luckier.$"

Route32_Text_Fisherman3_Intro:
	.string "Fishing takes patience.\p"
	.string "So does battling.$"

Route32_Text_Fisherman3_Defeat:
	.string "You waited me out.$"

Route32_Text_Fisherman3_After:
	.string "I'll try again.$"

Route32_Text_BirdKeeper_Intro:
	.string "The wind carries my birds.\p"
	.string "Let's see yours!$"

Route32_Text_BirdKeeper_Defeat:
	.string "Down to earth...$"

Route32_Text_BirdKeeper_After:
	.string "I'll train them to fly higher.$"

Route32_Text_FatMan:
	.string "ROUTE 32 is a long walk.\n"
	.string "Take breaks when you can.$"

Route32_Text_Camper:
	.string "I'm waiting before heading into\n"
	.string "UNION CAVE.$"

Route32_Text_Youngster2_Intro:
	.string "I train by the RUINS every day.\p"
	.string "Let's see what you've got!$"

Route32_Text_Youngster2_Defeat:
	.string "Whoa, that's ancient power!$"

Route32_Text_Youngster2_After:
	.string "The RUINS nearby are full of old\n"
	.string "mysteries.$"

Route32_Text_Cooltrainer_Intro:
	.string "Before I enter UNION CAVE, I test\n"
	.string "my team on every challenger.$"

Route32_Text_Cooltrainer_Defeat:
	.string "So much for my warm-up.$"

Route32_Text_Cooltrainer_After:
	.string "I keep my team ready for the cave.\n"
	.string "It's rough down there.$"

Route32_Text_AquaGrunt:
	.string "Can't let you through this way.\n"
	.string "Scram.$"

Route32_Text_SignRuins:
	.string "RUINS OF ALPH AHEAD.$"

Route32_Text_SignRoute32:
	.string "ROUTE 32\n"
	.string "VIOLET CITY - AZALEA TOWN$"

Route32_Text_SignUnionCave:
	.string "UNION CAVE AHEAD.$"

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end


Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end


Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end


Route32_Text_Sign1:
	.string "ROUTE 32\p"
	.string "VIOLET CITY - AZALEA TOWN$"


Route32_Text_Sign2:
	.string "RUINS OF ALPH\n"
	.string "EAST ENTRANCE$"


Route32_Text_Sign3:
	.string "UNION CAVE\n"
	.string "AHEAD$"
