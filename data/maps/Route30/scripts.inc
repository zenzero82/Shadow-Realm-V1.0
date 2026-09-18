Route30_MapScripts::
	.byte 0

Route30_Speaker_LittleBoy:
	.string "BEN$"

Route30_Speaker_Youngster:
	.string "KYLE$"

Route30_Speaker_BugCatcher:
	.string "MILO$"

Route30_EventScript_LittleBoy::
	faceplayer
	setspeaker Route30_Speaker_LittleBoy
	msgbox Route30_Text_LittleBoy, MSGBOX_NPC
	end

Route30_EventScript_Youngster::
	setspeaker Route30_Speaker_Youngster
	trainerbattle_single TRAINER_ROUTE30_YOUNGSTER, Route30_Text_Youngster_Intro, Route30_Text_Youngster_Defeat, Route30_EventScript_Youngster_After
	end

Route30_EventScript_BugCatcher::
	setspeaker Route30_Speaker_BugCatcher
	trainerbattle_single TRAINER_ROUTE30_BUG_CATCHER, Route30_Text_BugCatcher_Intro, Route30_Text_BugCatcher_Defeat, Route30_EventScript_BugCatcher_After
	end

Route30_EventScript_Youngster_After::
	setspeaker Route30_Speaker_Youngster
	msgbox Route30_Text_Youngster_After, MSGBOX_NPC
	closemessage
	release
	end

Route30_EventScript_BugCatcher_After::
	setspeaker Route30_Speaker_BugCatcher
	msgbox Route30_Text_BugCatcher_After, MSGBOX_NPC
	closemessage
	release
	end

Route30_EventScript_SignRoute30::
	msgbox Route30_Text_SignRoute30, MSGBOX_SIGN
	end

Route30_EventScript_SignTrainerTips::
	msgbox Route30_Text_SignTrainerTips, MSGBOX_SIGN
	end

Route30_EventScript_SignMrPokemon::
	msgbox Route30_Text_SignMrPokemon, MSGBOX_SIGN
	end

Route30_Text_LittleBoy:
	.string "I ran into a researcher heading\n"
	.string "to MR. POKEMON'S house.$"

Route30_Text_Youngster_Intro:
	.string "I train out here every day.\p"
	.string "Let's see your ROUTE 30 team!$"

Route30_Text_Youngster_Defeat:
	.string "Back to training for me...$"

Route30_Text_Youngster_After:
	.string "The grass here is great for\n"
	.string "training early teams.$"

Route30_Text_BugCatcher_Intro:
	.string "Bugs love the trees on ROUTE 30!\p"
	.string "Come on, battle me!$"

Route30_Text_BugCatcher_Defeat:
	.string "My bugs got blown away!$"

Route30_Text_BugCatcher_After:
	.string "I'm always looking around for\n"
	.string "more bug POKéMON.$"

Route30_Text_SignRoute30:
	.string "ROUTE 30\n"
	.string "CHERRYGROVE CITY - VIOLET CITY$"

Route30_Text_SignTrainerTips:
	.string "TRAINER TIPS\n"
	.string "BERRIES heal POKéMON on the go.$"

Route30_Text_SignMrPokemon:
	.string "MR. POKEMON'S HOUSE$"

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end


Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	


Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end


Route30_Text_Mailbox:
	.string "MR.POKéMON's House$"


Route30_Text_Sign:
	.string "ROUTE 30\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"


Route30_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "No stealing other people's\n"
	.string "POKéMON!\p"
	.string "POKé BALLS are to be thrown\n"
	.string "only at wild POKéMON!$"
