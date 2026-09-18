Route30_House_MapScripts::
	.byte 0

Route30_House_Speaker_Man:
	.string "HANK$"

Route30_House_EventScript_Man::
	lock
	faceplayer
	dotimebasedevents
	setspeaker Route30_House_Speaker_Man
	goto_if_set FLAG_DAILY_ROUTE30_BERRY_MASTER, Route30_House_EventScript_Man_AlreadyReceived
	msgbox Route30_House_Text_Man_Intro, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE30_BERRY_MASTER
	msgbox Route30_House_Text_Man_GiveBerry, MSGBOX_DEFAULT
	release
	end

Route30_House_EventScript_Man_AlreadyReceived::
	msgbox Route30_House_Text_Man_Repeat, MSGBOX_DEFAULT
	release
	end

Route30_House_Text_Man_Intro:
	.string "People call me the BERRY MASTER of\n"
	.string "ROUTE 30.\p"
	.string "I like sending travelers off with\n"
	.string "something fresh from my berry stock.$"

Route30_House_Text_Man_GiveBerry:
	.string "Here, take this berry for the road.\p"
	.string "Come by tomorrow and I'll have\n"
	.string "another one ready for you.$"

Route30_House_Text_Man_Repeat:
	.string "I've already shared today's berry.\p"
	.string "Drop by again tomorrow and I'll pick\n"
	.string "out another one for you.$"
