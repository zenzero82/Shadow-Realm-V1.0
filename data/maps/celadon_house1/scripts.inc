.set LOCALID_TIERNO, 2
.set LOCALID_SERENA, 3
.set LOCALID_SHAUNA, 4
.set LOCALID_TREVOR, 5
.set LOCALID_CALEM, 6

celadon_house1_MapScripts::
	.byte 0

celadon_house1_Speaker_Calem:
	.string "Calem$"

celadon_house1_Speaker_Serena:
	.string "Serena$"

celadon_house1_Speaker_Shauna:
	.string "Shauna$"

celadon_house1_Speaker_Trevor:
	.string "Trevor$"

celadon_house1_Speaker_Tierno:
	.string "Tierno$"

celadon_house1_EventScript_Calem::
	faceplayer
	goto_if_set FLAG_CELADON_HOUSE1_REWARD_GIVEN, celadon_house1_EventScript_Calem_RewardGate
celadon_house1_EventScript_Calem_Main::
	goto_if_set FLAG_CELADON_HOUSE1_CHALLENGE_STARTED, celadon_house1_EventScript_Calem_ChallengeResume
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Intro1, MSGBOX_NPC
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Intro2, MSGBOX_NPC
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, celadon_house1_EventScript_Calem_Accept
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Decline, MSGBOX_NPC
	end

celadon_house1_EventScript_Calem_RewardGate::
	checktrainerflag TRAINER_CELADON_CALEM
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_Done_Text
	clearflag FLAG_CELADON_HOUSE1_REWARD_GIVEN
	goto celadon_house1_EventScript_Calem_Main

celadon_house1_EventScript_Calem_Accept::
	cleartrainerflag TRAINER_CELADON_TIERNO
	cleartrainerflag TRAINER_CELADON_SHAUNA
	cleartrainerflag TRAINER_CELADON_TREVOR
	cleartrainerflag TRAINER_CELADON_SERENA
	cleartrainerflag TRAINER_CELADON_CALEM
	clearflag FLAG_CELADON_HOUSE1_TIERNO_DONE
	clearflag FLAG_CELADON_HOUSE1_SHAUNA_DONE
	clearflag FLAG_CELADON_HOUSE1_TREVOR_DONE
	clearflag FLAG_CELADON_HOUSE1_SERENA_DONE
	clearflag FLAG_CELADON_HOUSE1_BREAK_PENDING
	clearflag FLAG_CELADON_HOUSE1_REWARD_GIVEN
	setflag FLAG_CELADON_HOUSE1_CHALLENGE_STARTED
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_ChallengeGate::
	checktrainerflag TRAINER_CELADON_CALEM
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_GiveReward
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_ChallengeResume::
	goto_if_set FLAG_CELADON_HOUSE1_BREAK_PENDING, celadon_house1_EventScript_Calem_ReadyForSerena
	goto_if_set FLAG_CELADON_HOUSE1_SERENA_DONE, celadon_house1_EventScript_Challenge_Calem
	goto_if_set FLAG_CELADON_HOUSE1_TREVOR_DONE, celadon_house1_EventScript_Challenge_BreakPrompt
	goto_if_set FLAG_CELADON_HOUSE1_SHAUNA_DONE, celadon_house1_EventScript_Challenge_Trevor
	goto_if_set FLAG_CELADON_HOUSE1_TIERNO_DONE, celadon_house1_EventScript_Challenge_Shauna
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_ResetEarlyFights::
	clearflag FLAG_CELADON_HOUSE1_TIERNO_DONE
	clearflag FLAG_CELADON_HOUSE1_SHAUNA_DONE
	clearflag FLAG_CELADON_HOUSE1_TREVOR_DONE
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_ChallengePrompt::
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_ContinuePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, celadon_house1_EventScript_Calem_ContinueChallenge
	goto celadon_house1_EventScript_Calem_RestartChallenge

celadon_house1_EventScript_Calem_ContinueChallenge::
	goto_if_set FLAG_CELADON_HOUSE1_BREAK_PENDING, celadon_house1_EventScript_Calem_ReadyForSerena
	goto_if_set FLAG_CELADON_HOUSE1_SERENA_DONE, celadon_house1_EventScript_Challenge_Calem
	goto_if_set FLAG_CELADON_HOUSE1_TIERNO_DONE, celadon_house1_EventScript_Calem_ContinueChallenge_CheckShauna
	goto celadon_house1_EventScript_Challenge_Start
celadon_house1_EventScript_Calem_ContinueChallenge_CheckShauna::
	goto_if_set FLAG_CELADON_HOUSE1_SHAUNA_DONE, celadon_house1_EventScript_Calem_ContinueChallenge_CheckTrevor
	goto celadon_house1_EventScript_Challenge_Start
celadon_house1_EventScript_Calem_ContinueChallenge_CheckTrevor::
	goto_if_set FLAG_CELADON_HOUSE1_TREVOR_DONE, celadon_house1_EventScript_Challenge_BreakPrompt
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_RestartChallenge::
	cleartrainerflag TRAINER_CELADON_TIERNO
	cleartrainerflag TRAINER_CELADON_SHAUNA
	cleartrainerflag TRAINER_CELADON_TREVOR
	cleartrainerflag TRAINER_CELADON_SERENA
	clearflag FLAG_CELADON_HOUSE1_BREAK_PENDING
	goto celadon_house1_EventScript_Challenge_Start

celadon_house1_EventScript_Calem_Done_Text::
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Done, MSGBOX_NPC
	end

celadon_house1_EventScript_Serena::
	faceplayer
	setspeaker celadon_house1_Speaker_Serena
	msgbox celadon_house1_Text_Serena_Talk, MSGBOX_NPC
	end

celadon_house1_EventScript_Shauna::
	faceplayer
	setspeaker celadon_house1_Speaker_Shauna
	msgbox celadon_house1_Text_Shauna_Talk, MSGBOX_NPC
	end

celadon_house1_EventScript_Trevor::
	faceplayer
	setspeaker celadon_house1_Speaker_Trevor
	msgbox celadon_house1_Text_Trevor_Talk, MSGBOX_NPC
	end

celadon_house1_EventScript_Tierno::
	faceplayer
	setspeaker celadon_house1_Speaker_Tierno
	msgbox celadon_house1_Text_Tierno_Talk, MSGBOX_NPC
	end

celadon_house1_EventScript_Challenge_Start::
	goto_if_set FLAG_CELADON_HOUSE1_TIERNO_DONE, celadon_house1_EventScript_Challenge_Shauna
	setspeaker celadon_house1_Speaker_Tierno
	cleartrainerflag TRAINER_CELADON_TIERNO
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_TIERNO, TRAINER_CELADON_TIERNO, celadon_house1_Text_Tierno_Intro, celadon_house1_Text_Tierno_Defeat, celadon_house1_EventScript_Tierno_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

celadon_house1_EventScript_Tierno_After::
	setflag FLAG_CELADON_HOUSE1_TIERNO_DONE
	goto celadon_house1_EventScript_Challenge_Shauna

celadon_house1_EventScript_Challenge_Shauna::
	goto_if_set FLAG_CELADON_HOUSE1_SHAUNA_DONE, celadon_house1_EventScript_Challenge_Trevor
	setspeaker celadon_house1_Speaker_Shauna
	cleartrainerflag TRAINER_CELADON_SHAUNA
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_SHAUNA, TRAINER_CELADON_SHAUNA, celadon_house1_Text_Shauna_Intro, celadon_house1_Text_Shauna_Defeat, celadon_house1_EventScript_Shauna_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

celadon_house1_EventScript_Shauna_After::
	setflag FLAG_CELADON_HOUSE1_SHAUNA_DONE
	goto celadon_house1_EventScript_Challenge_Trevor

celadon_house1_EventScript_Challenge_Trevor::
	goto_if_set FLAG_CELADON_HOUSE1_TREVOR_DONE, celadon_house1_EventScript_Challenge_BreakPrompt
	setspeaker celadon_house1_Speaker_Trevor
	cleartrainerflag TRAINER_CELADON_TREVOR
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_TREVOR, TRAINER_CELADON_TREVOR, celadon_house1_Text_Trevor_Intro, celadon_house1_Text_Trevor_Defeat, celadon_house1_EventScript_Trevor_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

celadon_house1_EventScript_Trevor_After::
	setflag FLAG_CELADON_HOUSE1_TREVOR_DONE
	goto celadon_house1_EventScript_Challenge_BreakPrompt

celadon_house1_EventScript_Challenge_BreakPrompt::
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_BreakPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, celadon_house1_EventScript_Calem_BreakYes
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_BreakNo, MSGBOX_NPC
	goto celadon_house1_EventScript_Challenge_Serena

celadon_house1_EventScript_Calem_BreakYes::
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_BreakYes, MSGBOX_NPC
	setflag FLAG_CELADON_HOUSE1_BREAK_PENDING
	end

celadon_house1_EventScript_Calem_ReadyForSerena::
	clearflag FLAG_CELADON_HOUSE1_BREAK_PENDING
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_BreakReady, MSGBOX_NPC

celadon_house1_EventScript_Challenge_Serena::
	goto_if_set FLAG_CELADON_HOUSE1_SERENA_DONE, celadon_house1_EventScript_Challenge_Calem
	setspeaker celadon_house1_Speaker_Serena
	cleartrainerflag TRAINER_CELADON_SERENA
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_SERENA, TRAINER_CELADON_SERENA, celadon_house1_Text_Serena_Intro, celadon_house1_Text_Serena_Defeat, celadon_house1_EventScript_Serena_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

celadon_house1_EventScript_Serena_After::
	setflag FLAG_CELADON_HOUSE1_SERENA_DONE
	goto celadon_house1_EventScript_Challenge_Calem

celadon_house1_EventScript_Challenge_Calem::
	checktrainerflag TRAINER_CELADON_CALEM
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_GiveReward
	setspeaker celadon_house1_Speaker_Calem
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_CALEM, TRAINER_CELADON_CALEM, celadon_house1_Text_Calem_IntroBattle, celadon_house1_Text_Calem_Defeat, celadon_house1_EventScript_Calem_After, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

celadon_house1_EventScript_Calem_After::
	goto celadon_house1_EventScript_Calem_GiveReward

celadon_house1_EventScript_Calem_GiveReward::
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_Reward, MSGBOX_NPC
	checkitem ITEM_MEGA_RING, 1
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_GiveReward_Stone
	giveitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
celadon_house1_EventScript_Calem_GiveReward_Stone:
	checkitem ITEM_CHESNAUGHTITE, 1
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_GiveReward_Serena
	giveitem ITEM_CHESNAUGHTITE
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
celadon_house1_EventScript_Calem_GiveReward_Serena:
	setspeaker celadon_house1_Speaker_Calem
	msgbox celadon_house1_Text_Calem_RewardExplain, MSGBOX_NPC
	setspeaker celadon_house1_Speaker_Serena
	msgbox celadon_house1_Text_Serena_Reward, MSGBOX_NPC
	checkitem ITEM_DELPHOXITE, 1
	goto_if_eq VAR_RESULT, TRUE, celadon_house1_EventScript_Calem_GiveReward_Done
	giveitem ITEM_DELPHOXITE
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
celadon_house1_EventScript_Calem_GiveReward_Done:
	setflag FLAG_CELADON_HOUSE1_REWARD_GIVEN
	end

celadon_house1_Text_Calem_Intro1:
	.string "Hey! I'm Calem. You're the one\n"
	.string "who met Professor Sycamore,\l"
	.string "right?$"

celadon_house1_Text_Calem_Intro2:
	.string "We're from Kalos. A strange\n"
	.string "portal pulled us here early in\lab"
	.string "our journey.\p"
	.string "We're taking a break in Celadon\n"
	.string "and trying to make sense of it.$"

celadon_house1_Text_Calem_Challenge:
	.string "I have a challenge for you. If\n"
	.string "you win, I'll give you a MEGA\l"
	.string "RING.\p"
	.string "You'll face Tierno, Shauna, and\n"
	.string "Trevor back to back, then Serena,\l"
	.string "then me. Want to try?$"

celadon_house1_Text_Calem_Decline:
	.string "No worries. Come back if you\n"
	.string "change your mind.$"

celadon_house1_Text_Calem_BreakPrompt:
	.string "You beat Tierno, Shauna, and\n"
	.string "Trevor. Want a break before\l"
	.string "Serena?$"

celadon_house1_Text_Calem_BreakYes:
	.string "Okay. Come talk to me when\n"
	.string "you're ready to battle.$"

celadon_house1_Text_Calem_BreakNo:
	.string "Nice! Next up you'll face Serena.\n"
	.string "Good luck!$"

celadon_house1_Text_Calem_BreakReady:
	.string "Ready? Serena is up. Good luck!$"

celadon_house1_Text_Calem_IntroBattle:
	.string "All right. Let's see what you're\n"
	.string "really made of.$"

celadon_house1_Text_Calem_Defeat:
	.string "Well done. You earned that win.$"

celadon_house1_Text_Calem_Reward:
	.string "You earned this. Take my\n"
	.string "MEGA RING.$"

celadon_house1_Text_Calem_RewardExplain:
	.string "And take this CHESNAUGHTITE.\n"
	.string "MEGA EVOLUTION can turn a battle\l"
	.string "around fast.$"

celadon_house1_Text_Calem_Done:
	.string "Keep training. MEGA EVOLUTION will\n"
	.string "help, but your bond matters more.$"

celadon_house1_Text_Calem_ContinuePrompt:
	.string "You already started this challenge.\n"
	.string "Do you want to continue?$"

celadon_house1_Text_Calem_RestartPrompt:
	.string "Want to restart the challenge from\n"
	.string "the beginning?$"

celadon_house1_Text_Serena_Talk:
	.string "I'm Serena. We were barely\n"
	.string "starting out when a portal pulled\l"
	.string "us into Kanto.$"

celadon_house1_Text_Shauna_Talk:
	.string "Kalos to Kanto is such a big\n"
	.string "lifestyle shift. It's exciting\l"
	.string "and scary at the same time.$"

celadon_house1_Text_Trevor_Talk:
	.string "I keep thinking about home.\n"
	.string "I miss Kalos, but I'm trying to\l"
	.string "stay focused.$"

celadon_house1_Text_Tierno_Talk:
	.string "The food here is incredible!\n"
	.string "Kanto cuisine is my favorite so\l"
	.string "far.$"

celadon_house1_Text_Shauna_Intro:
	.string "Let's have a fun battle!$"

celadon_house1_Text_Shauna_Defeat:
	.string "You're really strong!$"

celadon_house1_Text_Trevor_Intro:
	.string "I'll analyze your style as we go.$"

celadon_house1_Text_Trevor_Defeat:
	.string "That was a smart battle.$"

celadon_house1_Text_Tierno_Intro:
	.string "Time to dance through this fight!$"

celadon_house1_Text_Tierno_Defeat:
	.string "You kept the tempo!$"

celadon_house1_Text_Serena_Intro:
	.string "All right. Let's do this.$"

celadon_house1_Text_Serena_Defeat:
	.string "That was intense...$"

celadon_house1_Text_Serena_Reward:
	.string "Here, take this DELPHOXITE.\n"
	.string "You've earned it.$"
