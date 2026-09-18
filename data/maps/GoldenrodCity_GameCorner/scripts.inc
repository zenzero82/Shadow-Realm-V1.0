GoldenrodCity_GameCorner_MapScripts::
	.byte 0

	.set LOCALID_GOLDENROD_GAME_CORNER_ELIO, 10
	.set Z_CRYSTAL_COINS, 5000
	.set EVOLUTION_ITEM_COINS, 5000

GoldenrodCity_GameCorner_Speaker_OldMan:
	.string "WILBUR$"

GoldenrodCity_GameCorner_Speaker_Gentleman:
	.string "EDGAR$"

GoldenrodCity_GameCorner_Speaker_BaldingMan:
	.string "MARTY$"

GoldenrodCity_GameCorner_Speaker_Rocker:
	.string "AXEL$"

GoldenrodCity_GameCorner_Speaker_Woman:
	.string "NINA$"

GoldenrodCity_GameCorner_Speaker_Hiker:
	.string "BRUNO$"

GoldenrodCity_GameCorner_Speaker_AttendantF:
	.string "ATTENDANT$"

GoldenrodCity_GameCorner_Speaker_AttendantM:
	.string "ATTENDANT$"

GoldenrodCity_GameCorner_Speaker_GameBoyKid:
	.string "KIP$"

GoldenrodCity_GameCorner_Speaker_Elio:
	.string "ELIO$"

GoldenrodCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_OldMan
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_Welcome, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_CoinsClerk_NeedCoinCase
	message GoldenrodCity_GameCorner_Text_CoinsClerk_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto GoldenrodCity_GameCorner_EventScript_CoinsClerk_ChooseCoinsDefault50
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_EventScript_CoinsClerk_Buy50Coins
	case 1, GoldenrodCity_GameCorner_EventScript_CoinsClerk_Buy500Coins
	goto GoldenrodCity_GameCorner_EventScript_CoinsClerk_CancelBuyCoins
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), GoldenrodCity_GameCorner_EventScript_CoinsClerk_NoRoomForCoins
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_CoinsClerk_NotEnoughMoney
	addcoins 50
	removemoney 1000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), GoldenrodCity_GameCorner_EventScript_CoinsClerk_NoRoomForCoins
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_CoinsClerk_NotEnoughMoney
	addcoins 500
	removemoney 10000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_NeedCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_NotEnoughMoney::
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_CancelBuyCoins::
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_GameCorner_EventScript_CoinsClerk_NoRoomForCoins::
	msgbox GoldenrodCity_GameCorner_Text_CoinsClerk_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_Gentleman
	msgbox GoldenrodCity_GameCorner_Text_Gentleman, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_BaldingMan::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_BaldingMan
	msgbox GoldenrodCity_GameCorner_Text_BaldingMan, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_Rocker::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_Rocker
	msgbox GoldenrodCity_GameCorner_Text_Rocker, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_Woman
	msgbox GoldenrodCity_GameCorner_Text_Woman, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_Hiker::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_Hiker
	msgbox GoldenrodCity_GameCorner_Text_Hiker, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_AttendantF::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_AttendantF
	msgbox GoldenrodCity_GameCorner_Text_AttendantF, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_NeedCoinCase
	message GoldenrodCity_GameCorner_Text_WhichPrize
	waitmessage
	coinmart GoldenrodCity_GameCorner_CoinMart_ZCrystals
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_NeedCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_NeedCoinCase, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_AttendantM::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_AttendantM
	msgbox GoldenrodCity_GameCorner_Text_AttendantM, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_NeedCoinCase
	message GoldenrodCity_GameCorner_Text_WhichPrize
	waitmessage
	coinmart GoldenrodCity_GameCorner_Pokemart_EvolutionItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_GameBoyKid::
	lock
	faceplayer
	setspeaker GoldenrodCity_GameCorner_Speaker_GameBoyKid
	msgbox GoldenrodCity_GameCorner_Text_GameBoyKid, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_GameCorner_EventScript_ElioTrigger0::
	setvar VAR_TEMP_1, 0
	goto GoldenrodCity_GameCorner_EventScript_Elio

GoldenrodCity_GameCorner_EventScript_ElioTrigger1::
	setvar VAR_TEMP_1, 1
	goto GoldenrodCity_GameCorner_EventScript_Elio

GoldenrodCity_GameCorner_EventScript_ElioTrigger2::
	setvar VAR_TEMP_1, 2
	goto GoldenrodCity_GameCorner_EventScript_Elio

GoldenrodCity_GameCorner_EventScript_ElioTalk::
	setvar VAR_TEMP_1, 1
	goto GoldenrodCity_GameCorner_EventScript_Elio

GoldenrodCity_GameCorner_EventScript_Elio::
	goto_if_set FLAG_GOLDENROD_GAME_CORNER_ELIO_GIFT, GoldenrodCity_GameCorner_EventScript_ElioDone
	lockall
	setspeaker GoldenrodCity_GameCorner_Speaker_Elio
	msgbox GoldenrodCity_GameCorner_Text_ElioOffering, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, Common_Movement_ExclamationMark
	waitmovement 0
	switch VAR_TEMP_1
	case 0, GoldenrodCity_GameCorner_EventScript_ElioFaceLeft
	case 1, GoldenrodCity_GameCorner_EventScript_ElioFaceDown
	case 2, GoldenrodCity_GameCorner_EventScript_ElioFaceRight
	goto GoldenrodCity_GameCorner_EventScript_ElioFaceDown

GoldenrodCity_GameCorner_EventScript_ElioFaceLeft::
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, Common_Movement_FaceLeft
	waitmovement 0
	goto GoldenrodCity_GameCorner_EventScript_ElioDialogue

GoldenrodCity_GameCorner_EventScript_ElioFaceDown::
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, Common_Movement_FaceDown
	waitmovement 0
	goto GoldenrodCity_GameCorner_EventScript_ElioDialogue

GoldenrodCity_GameCorner_EventScript_ElioFaceRight::
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, Common_Movement_FaceRight
	waitmovement 0
	goto GoldenrodCity_GameCorner_EventScript_ElioDialogue

GoldenrodCity_GameCorner_EventScript_ElioDialogue::
	setspeaker GoldenrodCity_GameCorner_Speaker_Elio
	msgbox GoldenrodCity_GameCorner_Text_ElioIntro, MSGBOX_DEFAULT
	checkitemspace ITEM_PSYCHIUM_Z
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_ElioBagFull
	giveitem ITEM_PSYCHIUM_Z
	setflag FLAG_GOLDENROD_GAME_CORNER_ELIO_GIFT
	setspeaker GoldenrodCity_GameCorner_Speaker_Elio
	msgbox GoldenrodCity_GameCorner_Text_ElioAfterGift, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	switch VAR_TEMP_1
	case 0, GoldenrodCity_GameCorner_EventScript_ElioExitTrigger0
	case 1, GoldenrodCity_GameCorner_EventScript_ElioExitLeft
	case 2, GoldenrodCity_GameCorner_EventScript_ElioExitLeft
	goto GoldenrodCity_GameCorner_EventScript_ElioExitLeft

GoldenrodCity_GameCorner_EventScript_ElioBagFull::
	call Common_EventScript_BagIsFull
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_ElioExitTrigger0::
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, GoldenrodCity_GameCorner_Movement_ElioExitDownRight
	waitmovement 0
	hideobjectat LOCALID_GOLDENROD_GAME_CORNER_ELIO, MAP_GOLDENROD_CITY_GAME_CORNER
	removeobject LOCALID_GOLDENROD_GAME_CORNER_ELIO
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_ElioExitLeft::
	applymovement LOCALID_GOLDENROD_GAME_CORNER_ELIO, GoldenrodCity_GameCorner_Movement_ElioExitLeft
	waitmovement 0
	hideobjectat LOCALID_GOLDENROD_GAME_CORNER_ELIO, MAP_GOLDENROD_CITY_GAME_CORNER
	removeobject LOCALID_GOLDENROD_GAME_CORNER_ELIO
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_ElioDone::
	end

GoldenrodCity_GameCorner_Text_OldMan:
	.string "The reels used to be the main draw.\p"
	.string "These days, trainers come here for\n"
	.string "coins and rare prizes.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_Welcome:
	.string "Welcome to the GOLDENROD GAME CORNER.\p"
	.string "We sell COINS here.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_WereYouLookingForCoins:
	.string "Were you looking for COINS?$"

GoldenrodCity_GameCorner_Text_CoinsClerk_NeedCoinCaseForCoins:
	.string "You'll need a COIN CASE to buy\n"
	.string "COINS.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_ThankYouHereAreYourCoins:
	.string "Thank you. Here are your COINS.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_DontHaveEnoughMoney:
	.string "You don't have enough money.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_CoinCaseIsFull:
	.string "Your COIN CASE is full.$"

GoldenrodCity_GameCorner_Text_CoinsClerk_DontNeedCoinsThen:
	.string "Come back if you want COINS.$"

GoldenrodCity_GameCorner_Text_Gentleman:
	.string "Mega Stones are legal, rare, and very\n"
	.string "expensive.\p"
	.string "That combination keeps this place\n"
	.string "standing.$"

GoldenrodCity_GameCorner_Text_BaldingMan:
	.string "I saw one of those black-uniformed\n"
	.string "thugs counting coins near the prize\n"
	.string "counter.\p"
	.string "Even crooks love a discount.$"

GoldenrodCity_GameCorner_Text_Rocker:
	.string "I came for the noise, stayed for the\n"
	.string "odds, and left with a headache.$"

GoldenrodCity_GameCorner_Text_Woman:
	.string "Those rare evolution items are tempting,\n"
	.string "but I still need money for Potions.$"

GoldenrodCity_GameCorner_Text_Hiker:
	.string "I don't gamble. I just like watching\n"
	.string "people explain why they almost won.$"

GoldenrodCity_GameCorner_Text_AttendantF:
	.string "This counter handles Z-Crystals.\n"
	.string "Bring enough coins and they're yours.$"

GoldenrodCity_GameCorner_Text_AttendantM:
	.string "This counter carries rare evolution\n"
	.string "items from outside Johto.$"

GoldenrodCity_GameCorner_Text_GameBoyKid:
	.string "My strategy is simple: stop playing\n"
	.string "before the machine learns my name.$"

GoldenrodCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

GoldenrodCity_GameCorner_Text_NeedCoinCase:
	.string "You'll need a COIN CASE before you\n"
	.string "can exchange coins for prizes.$"

GoldenrodCity_GameCorner_Text_ElioOffering:
	.string "Yeah so here are the Z-Crystals\n"
	.string "that I am offering.\p"
	.string "I believe that's around\n"
	.string "15,000 coins?$"

GoldenrodCity_GameCorner_Text_ElioIntro:
	.string "Uh... Hey... Who are you?\p"
	.string "Oh, you're {PLAYER}. I didn't think\n"
	.string "I would run into you here!\p"
	.string "Could you do me a favor and not tell\n"
	.string "anyone you saw me here?\p"
	.string "Haha, I may have picked up a gambling\n"
	.string "addiction while I was away from home...\p"
	.string "My name is ELIO, and I have been\n"
	.string "traveling across HOENN and JOHTO\l"
	.string "supplying the GYM LEADERS and high\l"
	.string "ranked trainers with Z-Crystals to\l"
	.string "help deal with the threat of\l"
	.string "Shadow POKéMON.\p"
	.string "Professor KUKUI sort of thinks I'm\n"
	.string "in VIOLET CITY right now, so let's\l"
	.string "just say you met me there.\p"
	.string "I know! Why don't you take this\n"
	.string "Z-Crystal as a little gift.$"

GoldenrodCity_GameCorner_Text_ElioAfterGift:
	.string "Unfortunately, you will need a\n"
	.string "Z-Bracelet to use it, but I don't\l"
	.string "have any extras at the moment.\p"
	.string "SELENE may have one, though.\n"
	.string "I think she is somewhere in HOENN.\p"
	.string "Well, I have to get going.\n"
	.string "Nice meeting you!$"

	.align 2
GoldenrodCity_GameCorner_CoinMart_ZCrystals:
	.2byte ITEM_NORMALIUM_Z, Z_CRYSTAL_COINS
	.2byte ITEM_FIRIUM_Z, Z_CRYSTAL_COINS
	.2byte ITEM_WATERIUM_Z, Z_CRYSTAL_COINS
	.2byte ITEM_ELECTRIUM_Z, Z_CRYSTAL_COINS
	.2byte ITEM_GRASSIUM_Z, Z_CRYSTAL_COINS
	.2byte ITEM_FIGHTINIUM_Z, Z_CRYSTAL_COINS
	coinmartlistend

GoldenrodCity_GameCorner_Pokemart_EvolutionItems:
	.2byte ITEM_AUSPICIOUS_ARMOR, EVOLUTION_ITEM_COINS
	.2byte ITEM_MALICIOUS_ARMOR, EVOLUTION_ITEM_COINS
	.2byte ITEM_BLACK_AUGURITE, EVOLUTION_ITEM_COINS
	.2byte ITEM_LINKING_CORD, EVOLUTION_ITEM_COINS
	.2byte ITEM_PEAT_BLOCK, EVOLUTION_ITEM_COINS
	.2byte ITEM_SYRUPY_APPLE, EVOLUTION_ITEM_COINS
	coinmartlistend

GoldenrodCity_GameCorner_Movement_ElioExitDownRight:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_GameCorner_Movement_ElioExitLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
