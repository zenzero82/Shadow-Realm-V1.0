NewBarkTown_PlayersHouse_1F_MapScripts::
	.byte 0

NewBarkTown_PlayersHouse_1F_Speaker_Mom:
	.string "GOLD'S MOM$"

NewBarkTown_PlayersHouse_1F_Speaker_MomsFriend:
	.string "MOM'S FRIEND$"

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_MomsFriend
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_NEW_BARK_NPC_PLAYERS_HOUSE_FRIEND
	call QuestJournal_EventScript_CheckNewBarkNPCs
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_ENABLE_GOLD_MOM_SAVINGS, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom, MSGBOX_DEFAULT
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsNo
	setflag FLAG_ENABLE_GOLD_MOM_SAVINGS
	special GoldMomSavingsInit
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsYes, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete
	call NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsNo::
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsNo, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete
	call NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu::
	special BufferGoldMomSavings
	specialvar VAR_RESULT, GoldMomSavingsHasMoney
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsEmpty
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsBalance, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsKeep
	special GoldMomSavingsWithdrawAll
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsWithdrawn, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsKeep::
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsKeep, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsEmpty::
	setspeaker NewBarkTown_PlayersHouse_1F_Speaker_Mom
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsEmpty, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_RecordMomNpc::
	setflag FLAG_QUEST_NEW_BARK_NPC_PLAYERS_HOUSE_MOM
	call QuestJournal_EventScript_CheckNewBarkNPCs
	return

NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete::
	checkflag FLAG_QUEST_GOLDS_MOM_COMPLETED
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete_Done
	checkflag FLAG_QUEST_GOLDS_MOM_STARTED
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete_Do
	setflag FLAG_QUEST_GOLDS_MOM_STARTED
	call QuestJournal_EventScript_NewQuestAlert
NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete_Do::
	setflag FLAG_QUEST_GOLDS_MOM_COMPLETED
	call QuestJournal_EventScript_QuestCompleteAlert
NewBarkTown_PlayersHouse_1F_EventScript_GoldsMomQuestComplete_Done::
	call NewBarkTown_PlayersHouse_1F_EventScript_SetBirchCallPending
	return

NewBarkTown_PlayersHouse_1F_EventScript_SetBirchCallPending::
	checkflag FLAG_BIRCH_TIME_AMULET_CALL_DONE
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_SetBirchCallPending_Done
	setvar VAR_BIRCH_TIME_AMULET_CALL_PENDING, 1
NewBarkTown_PlayersHouse_1F_EventScript_SetBirchCallPending_Done:
	return

NewBarkTown_PlayersHouse_1F_Text_Mom:
	.string "Hello, and who might you be?\p"
	.string "I see, so Ethan sent you to\n"
	.string "check on me.\p"
	.string "He is such a sweet boy.\p"
	.string "Ethan looks just like my son\n"
	.string "Gold, but Gold is nowhere to be\l"
	.string "found.\p"
	.string "I have been treating Ethan like\n"
	.string "my son these past few months.\p"
	.string "It seems like you are helping him\n"
	.string "and the Team in these crazy times.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsOffer:
	.string "I have been holding accounts for\n"
	.string "the Team so they do not spend all\l"
	.string "their money.\p"
	.string "Want me to save some of your\n"
	.string "battle money?$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsYes:
	.string "Okay. I will save a third of what\n"
	.string "you earn in battle.\p"
	.string "You can come see me anytime, or\n"
	.string "call me to send it to you.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsNo:
	.string "Come see me if you change your\n"
	.string "mind.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsEmpty:
	.string "I do not have any of your money\n"
	.string "saved yet.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsBalance:
	.string "I have {STR_VAR_1} saved for you.\p"
	.string "Do you want me to send it now?$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsWithdrawn:
	.string "Sent {STR_VAR_1} to you.\n"
	.string "Spend it wisely.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsKeep:
	.string "All right. I will keep saving it\n"
	.string "for you.$"

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
	.string "There was so much noise outside\n"
	.string "just before you walked in.\p"
	.string "Seems like we finally got some\n"
	.string "peace and quiet now.$"
