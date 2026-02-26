Route32_MapScripts::
	.byte 0

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

@ =========================================================
@ NPCS
@ =========================================================

Route32_EventScript_FatMan::
	faceplayer
	msgbox Route32_Text_FatMan, MSGBOX_NPC
	end

Route32_EventScript_Camper::
	faceplayer
	msgbox Route32_Text_Camper, MSGBOX_NPC
	end

Route32_EventScript_YoungsterNPC::
	faceplayer
	msgbox Route32_Text_YoungsterNPC, MSGBOX_NPC
	end

Route32_EventScript_Cooltrainer::
	faceplayer
	msgbox Route32_Text_Cooltrainer, MSGBOX_NPC
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

Route32_Text_YoungsterNPC:
	.string "The RUINS nearby are full of old\n"
	.string "mysteries.$"

Route32_Text_Cooltrainer:
	.string "I keep my team ready for the cave.\n"
	.string "It's rough down there.$"

Route32_Text_SignRuins:
	.string "RUINS OF ALPH AHEAD.$"

Route32_Text_SignRoute32:
	.string "ROUTE 32\n"
	.string "VIOLET CITY - AZALEA TOWN$"

Route32_Text_SignUnionCave:
	.string "UNION CAVE AHEAD.$"
