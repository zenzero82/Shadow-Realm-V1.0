MauvilleCity_BikeShop_MapScripts::
	.byte 0

#define BIKE_MOD_MACH 0
#define BIKE_MOD_ACRO 1

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AlreadyGotBike
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	msgbox MauvilleCity_BikeShop_Text_ExplainBicycle, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BIKE
	special SwapRegisteredBike
	goto MauvilleCity_BikeShop_EventScript_ChooseFirstMod

MauvilleCity_BikeShop_EventScript_AlreadyGotBike::
	compare VAR_BICYCLE_MOD, BIKE_MOD_ACRO
	goto_if_eq MauvilleCity_BikeShop_EventScript_AlreadyGotBikeAcro
	msgbox MauvilleCity_BikeShop_Text_AlreadyGotBikeMach, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_OfferModSwap

MauvilleCity_BikeShop_EventScript_AlreadyGotBikeAcro::
	msgbox MauvilleCity_BikeShop_Text_AlreadyGotBikeAcro, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_OfferModSwap

MauvilleCity_BikeShop_EventScript_OfferModSwap::
	msgbox MauvilleCity_BikeShop_Text_OfferModSwap, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_ChooseMod
	release
	end

MauvilleCity_BikeShop_EventScript_ChooseFirstMod::
	msgbox MauvilleCity_BikeShop_Text_EnjoyBicycle, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_ChooseMod

MauvilleCity_BikeShop_EventScript_ChooseMod::
	msgbox MauvilleCity_BikeShop_Text_ChooseMod, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_BIKE, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_InstallMachMod
	case 1, MauvilleCity_BikeShop_EventScript_InstallAcroMod
	end

MauvilleCity_BikeShop_EventScript_InstallMachMod::
	setvar VAR_BICYCLE_MOD, BIKE_MOD_MACH
	msgbox MauvilleCity_BikeShop_Text_MachModInstalled, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_InstallAcroMod::
	setvar VAR_BICYCLE_MOD, BIKE_MOD_ACRO
	msgbox MauvilleCity_BikeShop_Text_AcroModInstalled, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"

MauvilleCity_BikeShop_Text_ExplainBicycle:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you my latest BICYCLE!\p"
	.string "It's a fine machine, and I can tune it\n"
	.string "with special mods to handle like a\l"
	.string "MACH BIKE or an ACRO BIKE.\p"
	.string "For now, take this BICYCLE and enjoy\n"
	.string "the ride!$"

MauvilleCity_BikeShop_Text_EnjoyBicycle:
	.string "{PLAYER} received the BICYCLE!\p"
	.string "RYDEL: Now then, let's talk mods.\p"
	.string "I'll set this BICYCLE up the way\n"
	.string "you want it.$"

MauvilleCity_BikeShop_Text_AlreadyGotBikeMach:
	.string "RYDEL: Ah, your BICYCLE is currently\n"
	.string "set up with MACH BIKE mods.\p"
	.string "Need me to swap anything?$"

MauvilleCity_BikeShop_Text_AlreadyGotBikeAcro:
	.string "RYDEL: Ah, your BICYCLE is currently\n"
	.string "set up with ACRO BIKE mods.\p"
	.string "Need me to swap anything?$"

MauvilleCity_BikeShop_Text_OfferModSwap:
	.string "RYDEL: Want me to switch out the mods\n"
	.string "on your BICYCLE?$"

MauvilleCity_BikeShop_Text_ChooseMod:
	.string "RYDEL: Which bike mod do you want me\n"
	.string "to install?$"

MauvilleCity_BikeShop_Text_MachModInstalled:
	.string "RYDEL: All done!\p"
	.string "Your BICYCLE is now tuned with MACH\n"
	.string "BIKE mods.\p"
	.string "Come back anytime if you want me to\n"
	.string "swap it over.$"

MauvilleCity_BikeShop_Text_AcroModInstalled:
	.string "RYDEL: All done!\p"
	.string "Your BICYCLE is now tuned with ACRO\n"
	.string "BIKE mods.\p"
	.string "Come back anytime if you want me to\n"
	.string "swap it over.$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "It's a handbook on the MACH BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "It's a handbook on the ACRO BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"
