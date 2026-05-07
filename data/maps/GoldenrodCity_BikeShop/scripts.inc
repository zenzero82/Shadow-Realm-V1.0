GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_Speaker_Galen:
	.string "GALEN$"

GoldenrodCity_BikeShop_EventScript_Galen::
	lock
	faceplayer
	setspeaker GoldenrodCity_BikeShop_Speaker_Galen
	checkitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_AlreadyHasBike
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_AlreadyHasBike
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_AlreadyHasBike
	checkitem ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_UseVoucher
	showmoneybox 0, 0
	msgbox GoldenrodCity_BikeShop_Text_OfferBike, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_BikeShop_EventScript_BuyBike
	msgbox GoldenrodCity_BikeShop_Text_MaybeLater, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

GoldenrodCity_BikeShop_EventScript_BuyBike::
	checkmoney 1000000
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BikeShop_EventScript_NotEnoughMoney
	msgbox GoldenrodCity_BikeShop_Text_ThatWillBeOneMillion, MSGBOX_DEFAULT
	removemoney 1000000
	updatemoneybox
	giveitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BikeShop_EventScript_BagFull
	msgbox GoldenrodCity_BikeShop_Text_ReceivedBike, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

GoldenrodCity_BikeShop_EventScript_UseVoucher::
	msgbox GoldenrodCity_BikeShop_Text_UseVoucher, MSGBOX_DEFAULT
	removeitem ITEM_BIKE_VOUCHER
	giveitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BikeShop_EventScript_BagFullVoucher
	msgbox GoldenrodCity_BikeShop_Text_ReceivedBikeWithVoucher, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_BikeShop_EventScript_BagFullVoucher::
	additem ITEM_BIKE_VOUCHER
	goto Common_EventScript_ShowBagIsFull
	end

GoldenrodCity_BikeShop_EventScript_BagFull::
	hidemoneybox
	addmoney 1000000
	goto Common_EventScript_ShowBagIsFull
	end

GoldenrodCity_BikeShop_EventScript_NotEnoughMoney::
	msgbox GoldenrodCity_BikeShop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

GoldenrodCity_BikeShop_EventScript_AlreadyHasBike::
	msgbox GoldenrodCity_BikeShop_Text_AlreadyHasBike, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	msgbox GoldenrodCity_BikeShop_EventScript_Bike_Text, MSGBOX_SIGN
	end

GoldenrodCity_BikeShop_EventScript_Bike_Text:
	.string "A bicycle is on display.$"

GoldenrodCity_BikeShop_Text_OfferBike:
	.string "Bicycles aren't cheap anymore.\p"
	.string "One will cost you ¥1,000,000.\p"
	.string "A BIKE VOUCHER is rare to come by,\n"
	.string "but maybe someone around GOLDENROD\l"
	.string "CITY still has one.\p"
	.string "Want to buy a BICYCLE?$"

GoldenrodCity_BikeShop_Text_ThatWillBeOneMillion:
	.string "That'll be ¥1,000,000.\n"
	.string "No refunds once you ride off.$"

GoldenrodCity_BikeShop_Text_ReceivedBike:
	.string "{PLAYER} received the BICYCLE!\p"
	.string "Take care of it. Parts like these are\n"
	.string "hard to replace nowadays.$"

GoldenrodCity_BikeShop_Text_UseVoucher:
	.string "Hold on... That's a BIKE VOUCHER!\p"
	.string "Those are rare these days.\n"
	.string "I'll honor it right now.$"

GoldenrodCity_BikeShop_Text_ReceivedBikeWithVoucher:
	.string "{PLAYER} exchanged the BIKE VOUCHER\n"
	.string "for a BICYCLE!$"

GoldenrodCity_BikeShop_Text_NotEnoughMoney:
	.string "Come back when you've got the cash,\n"
	.string "or better yet, a BIKE VOUCHER.$"

GoldenrodCity_BikeShop_Text_MaybeLater:
	.string "Fair enough.\n"
	.string "If you find a BIKE VOUCHER, bring it in.$"

GoldenrodCity_BikeShop_Text_AlreadyHasBike:
	.string "You've already got a bike.\p"
	.string "If you find a BIKE VOUCHER, hang onto it.\n"
	.string "Those things are hard to come by.$"
