Route36_MapScripts::
	.byte 0

.set LOCALID_ROUTE36_SUDOWOODO, 2

Route36_Speaker_FatMan:
	.string "HERMAN$"

Route36_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudowoodoShake
	waitmovement 0
	release
	end

Route36_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_EventScript_FatMan::
	lock
	faceplayer
	setspeaker Route36_Speaker_FatMan
	goto_if_set FLAG_HERMAN_WEEKLY_REWARDS_UNLOCKED, Route36_EventScript_HermanWeeklyReward
	msgbox Route36_Text_HermanGuessFavoriteDay, MSGBOX_DEFAULT

Route36_EventScript_HermanChooseDay:
	multichoice 17, 0, MULTI_WEEKDAYS, TRUE
	goto_if_eq VAR_RESULT, 6, Route36_EventScript_HermanCorrectGuess
	msgbox Route36_Text_HermanWrongGuess, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanChooseDay

Route36_EventScript_HermanCorrectGuess:
	msgbox Route36_Text_HermanCorrectGuess, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HERMAN_WEEKLY_REWARDS_UNLOCKED
	setflag FLAG_DAILY_HERMAN_REWARD
	setvar VAR_HERMAN_WEEKLY_REWARD_STATE, 1
	msgbox Route36_Text_HermanComeBackSunday, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_HermanWeeklyReward:
	dotimebasedevents
	specialvar VAR_RESULT, GetDayOfWeek
	goto_if_ne VAR_RESULT, WEEKDAY_SUN, Route36_EventScript_HermanNotSunday
	goto_if_set FLAG_DAILY_HERMAN_REWARD, Route36_EventScript_HermanAlreadyReceived
	goto_if_ge VAR_HERMAN_WEEKLY_REWARD_STATE, 10, Route36_EventScript_HermanAllRewardsReceived
	random 9
	switch VAR_RESULT
	case 0, Route36_EventScript_HermanScriptureTrust
	case 1, Route36_EventScript_HermanScriptureStrength
	case 2, Route36_EventScript_HermanScriptureRejoice
	case 3, Route36_EventScript_HermanScriptureRenew
	case 4, Route36_EventScript_HermanScripturePersevere
	case 5, Route36_EventScript_HermanScriptureWisdom
	case 6, Route36_EventScript_HermanScriptureHope
	case 7, Route36_EventScript_HermanScriptureWork
	case 8, Route36_EventScript_HermanScriptureLight

Route36_EventScript_HermanScriptureTrust:
	msgbox Route36_Text_HermanScriptureTrust, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureStrength:
	msgbox Route36_Text_HermanScriptureStrength, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureRejoice:
	msgbox Route36_Text_HermanScriptureRejoice, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureRenew:
	msgbox Route36_Text_HermanScriptureRenew, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScripturePersevere:
	msgbox Route36_Text_HermanScripturePersevere, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureWisdom:
	msgbox Route36_Text_HermanScriptureWisdom, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureHope:
	msgbox Route36_Text_HermanScriptureHope, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureWork:
	msgbox Route36_Text_HermanScriptureWork, MSGBOX_DEFAULT
	goto Route36_EventScript_HermanSelectReward

Route36_EventScript_HermanScriptureLight:
	msgbox Route36_Text_HermanScriptureLight, MSGBOX_DEFAULT

Route36_EventScript_HermanSelectReward:
	switch VAR_HERMAN_WEEKLY_REWARD_STATE
	case 1, Route36_EventScript_HermanRewardPPMax
	case 2, Route36_EventScript_HermanRewardLuckyEgg
	case 3, Route36_EventScript_HermanRewardRareCandy
	case 4, Route36_EventScript_HermanRewardBeastBall
	case 5, Route36_EventScript_HermanRewardSportBall
	case 6, Route36_EventScript_HermanRewardSafariBall
	case 7, Route36_EventScript_HermanRewardDreamBall
	case 8, Route36_EventScript_HermanRewardCherishBall
	case 9, Route36_EventScript_HermanRewardMasterBall

Route36_EventScript_HermanRewardPPMax:
	setvar VAR_0x8000, ITEM_PP_MAX
	setvar VAR_0x8001, 5
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardLuckyEgg:
	setvar VAR_0x8000, ITEM_LUCKY_EGG
	setvar VAR_0x8001, 1
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardRareCandy:
	setvar VAR_0x8000, ITEM_RARE_CANDY
	setvar VAR_0x8001, 5
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardBeastBall:
	setvar VAR_0x8000, ITEM_BEAST_BALL
	setvar VAR_0x8001, 20
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardSportBall:
	setvar VAR_0x8000, ITEM_SPORT_BALL
	setvar VAR_0x8001, 20
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardSafariBall:
	setvar VAR_0x8000, ITEM_SAFARI_BALL
	setvar VAR_0x8001, 20
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardDreamBall:
	setvar VAR_0x8000, ITEM_DREAM_BALL
	setvar VAR_0x8001, 20
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardCherishBall:
	setvar VAR_0x8000, ITEM_CHERISH_BALL
	setvar VAR_0x8001, 20
	goto Route36_EventScript_HermanGiveWeeklyReward

Route36_EventScript_HermanRewardMasterBall:
	setvar VAR_0x8000, ITEM_MASTER_BALL
	setvar VAR_0x8001, 1

Route36_EventScript_HermanGiveWeeklyReward:
	callstd STD_OBTAIN_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_HERMAN_REWARD
	addvar VAR_HERMAN_WEEKLY_REWARD_STATE, 1
	msgbox Route36_Text_HermanComeBackSunday, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_HermanNotSunday:
	msgbox Route36_Text_HermanNotSunday, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_HermanAlreadyReceived:
	msgbox Route36_Text_HermanAlreadyReceived, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_HermanAllRewardsReceived:
	msgbox Route36_Text_HermanAllRewardsReceived, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end


Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end


Route36_Text_Sign_RuinsNorth:
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"


Route36_Text_Tips1:
	.string "TRAINER TIPS\n"
	.string "POKéMON stats vary--even within\l"
	.string "the same species.\p"
	.string "Their stats may be similar at first.\p"
	.string "However, differences will become\n"
	.string "pronounced as the POKéMON grow.$"

Route36_Text_HermanGuessFavoriteDay:
	.string "Can you guess my favorite day\n"
	.string "of the week?$"

Route36_Text_HermanWrongGuess:
	.string "Nope! Keep guessing!$"

Route36_Text_HermanCorrectGuess:
	.string "You got that right! Nothing better\n"
	.string "than praising the Lord at Grace\l"
	.string "Nation on a lovely Sunday morning.\p"
	.string "Apostle Gerry bring that fire word!!\p"
	.string "For getting it right, here is a gift\n"
	.string "for you.$"

Route36_Text_HermanComeBackSunday:
	.string "Come talk to me next Sunday and\n"
	.string "I'll share something with you!$"

Route36_Text_HermanNotSunday:
	.string "Hey {PLAYER}, can't wait to hear\n"
	.string "the word this Sunday!$"

Route36_Text_HermanAlreadyReceived:
	.string "That word was a blessing today!\p"
	.string "Come talk to me next Sunday and\n"
	.string "I'll share something with you!$"

Route36_Text_HermanAllRewardsReceived:
	.string "You have received every gift I had\n"
	.string "to share, {PLAYER}.\p"
	.string "Keep walking in faith and carrying\n"
	.string "the word with you!$"

Route36_Text_HermanScriptureTrust:
	.string "PROVERBS 3:5 says,\n"
	.string "“Trust in the LORD with all your\l"
	.string "heart.”\p"
	.string "I learned to trust God's direction,\n"
	.string "even when I cannot see the path.$"

Route36_Text_HermanScriptureStrength:
	.string "PHILIPPIANS 4:13 says,\n"
	.string "“I can do all things through Christ\l"
	.string "who strengthens me.”\p"
	.string "I learned that true strength comes\n"
	.string "from Christ, not pride.$"

Route36_Text_HermanScriptureRejoice:
	.string "PSALM 118:24 says,\n"
	.string "“This is the day the LORD has made;\l"
	.string "we will rejoice and be glad in it.”\p"
	.string "I learned to greet every new day\n"
	.string "with gratitude and joy.$"

Route36_Text_HermanScriptureRenew:
	.string "ISAIAH 40:31 says,\n"
	.string "“Those who wait on the LORD shall\l"
	.string "renew their strength.”\p"
	.string "I learned that patient faith gives\n"
	.string "us strength to keep moving.$"

Route36_Text_HermanScripturePersevere:
	.string "GALATIANS 6:9 says,\n"
	.string "“Let us not grow weary while doing\l"
	.string "good.”\p"
	.string "I learned to keep doing what is\n"
	.string "right, even when it is difficult.$"

Route36_Text_HermanScriptureWisdom:
	.string "JAMES 1:5 says,\n"
	.string "“If any of you lacks wisdom, let him\l"
	.string "ask of God.”\p"
	.string "I learned to pray for wisdom before\n"
	.string "making important choices.$"

Route36_Text_HermanScriptureHope:
	.string "ROMANS 12:12 says,\n"
	.string "“Rejoicing in hope, patient in\l"
	.string "tribulation, continuing steadfastly\l"
	.string "in prayer.”\p"
	.string "I learned that hope and prayer help\n"
	.string "us endure every trial.$"

Route36_Text_HermanScriptureWork:
	.string "COLOSSIANS 3:23 says,\n"
	.string "“Whatever you do, do it heartily,\l"
	.string "as to the Lord.”\p"
	.string "I learned to give my best effort,\n"
	.string "even when nobody else is watching.$"

Route36_Text_HermanScriptureLight:
	.string "MATTHEW 5:16 says,\n"
	.string "“Let your light so shine before\l"
	.string "men.”\p"
	.string "I learned that good works can point\n"
	.string "others toward God.$"
