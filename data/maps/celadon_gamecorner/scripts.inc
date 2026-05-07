celadon_gamecorner_MapScripts::
	.byte 0

@ Game Corner prices
	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

@ =========================================================
@ SPEAKERS
@ =========================================================

celadon_gamecorner_Speaker_OldMan:
	.string "MORRIS$"

celadon_gamecorner_Speaker_AttendantF:
	.string "NINA$"

celadon_gamecorner_Speaker_AttendantM:
	.string "DEVIN$"

celadon_gamecorner_Speaker_Juggler:
	.string "PAOLO$"

celadon_gamecorner_Speaker_Engineer:
	.string "CLARK$"

celadon_gamecorner_Speaker_GymGuy:
	.string "LEON$"

celadon_gamecorner_Speaker_OldWoman:
	.string "EDNA$"

celadon_gamecorner_Speaker_Beauty:
	.string "FIONA$"

celadon_gamecorner_Speaker_BaldingMan:
	.string "WALTER$"

@ =========================================================
@ NPCS
@ =========================================================

celadon_gamecorner_EventScript_CoinsClerk::
	lock
	faceplayer
	setspeaker celadon_gamecorner_Speaker_OldMan
	msgbox celadon_gamecorner_Text_CoinsClerk_Welcome, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, celadon_gamecorner_EventScript_CoinsClerk_NeedCoinCase
	message celadon_gamecorner_Text_CoinsClerk_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto celadon_gamecorner_EventScript_CoinsClerk_ChooseCoinsDefault50

celadon_gamecorner_EventScript_CoinsClerk_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, celadon_gamecorner_EventScript_CoinsClerk_Buy50Coins
	case 1, celadon_gamecorner_EventScript_CoinsClerk_Buy500Coins
	goto celadon_gamecorner_EventScript_CoinsClerk_CancelBuyCoins
	end

celadon_gamecorner_EventScript_CoinsClerk_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), celadon_gamecorner_EventScript_CoinsClerk_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, celadon_gamecorner_EventScript_CoinsClerk_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox celadon_gamecorner_Text_CoinsClerk_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

celadon_gamecorner_EventScript_CoinsClerk_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), celadon_gamecorner_EventScript_CoinsClerk_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, celadon_gamecorner_EventScript_CoinsClerk_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox celadon_gamecorner_Text_CoinsClerk_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

celadon_gamecorner_EventScript_CoinsClerk_NeedCoinCase::
	msgbox celadon_gamecorner_Text_CoinsClerk_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

celadon_gamecorner_EventScript_CoinsClerk_NotEnoughMoney::
	msgbox celadon_gamecorner_Text_CoinsClerk_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

celadon_gamecorner_EventScript_CoinsClerk_CancelBuyCoins::
	msgbox celadon_gamecorner_Text_CoinsClerk_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

celadon_gamecorner_EventScript_CoinsClerk_NoRoomForCoins::
	msgbox celadon_gamecorner_Text_CoinsClerk_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

celadon_gamecorner_EventScript_AttendantF::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_AttendantF
	msgbox celadon_gamecorner_Text_AttendantF, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_AttendantM::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_AttendantM
	msgbox celadon_gamecorner_Text_AttendantM, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_Juggler::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_Juggler
	msgbox celadon_gamecorner_Text_Juggler, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_Engineer::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_Engineer
	msgbox celadon_gamecorner_Text_Engineer, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_GymGuy::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_GymGuy
	msgbox celadon_gamecorner_Text_GymGuy, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_OldWoman::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_OldWoman
	msgbox celadon_gamecorner_Text_OldWoman, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_Beauty::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_Beauty
	msgbox celadon_gamecorner_Text_Beauty, MSGBOX_NPC
	end

celadon_gamecorner_EventScript_BaldingMan::
	faceplayer
	setspeaker celadon_gamecorner_Speaker_BaldingMan
	msgbox celadon_gamecorner_Text_BaldingMan, MSGBOX_NPC
	end

@ =========================================================
@ TEXT
@ =========================================================

celadon_gamecorner_Text_CoinsClerk_Welcome:
	.string "Welcome to the CELADON GAME CORNER.\p"
	.string "We sell COINS here.$"

celadon_gamecorner_Text_CoinsClerk_WereYouLookingForCoins:
	.string "Were you looking for COINS?$"

celadon_gamecorner_Text_CoinsClerk_NeedCoinCaseForCoins:
	.string "You'll need a COIN CASE to buy\n"
	.string "COINS.$"

celadon_gamecorner_Text_CoinsClerk_ThankYouHereAreYourCoins:
	.string "Thank you. Here are your COINS.$"

celadon_gamecorner_Text_CoinsClerk_DontHaveEnoughMoney:
	.string "You don't have enough money.$"

celadon_gamecorner_Text_CoinsClerk_CoinCaseIsFull:
	.string "Your COIN CASE is full.$"

celadon_gamecorner_Text_CoinsClerk_DontNeedCoinsThen:
	.string "Come back if you want COINS.$"

celadon_gamecorner_Text_AttendantF:
	.string "Prizes are exchanged next door.\n"
	.string "Stock up on COINS first.$"

celadon_gamecorner_Text_AttendantM:
	.string "Each slot machine has different\n"
	.string "odds. Pick carefully.$"

celadon_gamecorner_Text_Juggler:
	.string "Timing is everything on these\n"
	.string "slots.$"

celadon_gamecorner_Text_Engineer:
	.string "These machines run on old wiring,\n"
	.string "but they still pay out.$"

celadon_gamecorner_Text_GymGuy:
	.string "Hey dude, you can't play anything\n"
	.string "until you get a coin case.\p"
	.string "Lucky for you it's so easy to\n"
	.string "get one these days.\p"
	.string "Like... so easy.\p"
	.string "Like you can probably go next door\n"
	.string "and get one...\p"
	.string "Why you still here?$"

celadon_gamecorner_Text_OldWoman:
	.string "I'm saving up for something rare.\n"
	.string "Don't distract me.$"

celadon_gamecorner_Text_Beauty:
	.string "I only play when I'm feeling lucky.$"

celadon_gamecorner_Text_BaldingMan:
	.string "Don't tell my wife I'm here...$"
