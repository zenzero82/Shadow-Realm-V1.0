NewBarkTown_PlayersHouse_1F_MapScripts::
	.byte 0

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	end

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	faceplayer
	goto_if_set FLAG_ENABLE_GOLD_MOM_SAVINGS, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom, MSGBOX_DEFAULT
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsNo
	setflag FLAG_ENABLE_GOLD_MOM_SAVINGS
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	special GoldMomSavingsInit
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsYes, MSGBOX_DEFAULT
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsNo::
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsNo, MSGBOX_DEFAULT
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu::
	special BufferGoldMomSavings
	specialvar VAR_RESULT, GoldMomSavingsHasMoney
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsEmpty
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsBalance, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsKeep
	special GoldMomSavingsWithdrawAll
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsWithdrawn, MSGBOX_DEFAULT
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsKeep::
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsKeep, MSGBOX_DEFAULT
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsEmpty::
	msgbox NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsEmpty, MSGBOX_DEFAULT
	end

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
	.string "It seems like you are helping the\n"
	.string "Team in these crazy times.$"

NewBarkTown_PlayersHouse_1F_Text_Mom_SavingsOffer:
	.string "I have been holding accounts for\n"
	.string "the Team so they do not spend all\n"
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
	.string "Seems like we finally got some\l"
	.string "peace and queit now.$"
