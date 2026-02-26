Route29_MapScripts::
	.byte 0

Route29_EventScript_Youngster::
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_NPC
	end

Route29_EventScript_Lass::
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_NPC
	end

Route29_EventScript_FatMan::
	faceplayer
	msgbox Route29_Text_FatMan, MSGBOX_NPC
	end

Route29_EventScript_Boy::
	faceplayer
	msgbox Route29_Text_Boy, MSGBOX_NPC
	end

Route29_EventScript_SignRoute29::
	msgbox Route29_Text_SignRoute29, MSGBOX_SIGN
	end

Route29_EventScript_SignCherrygrove::
	msgbox Route29_Text_SignCherrygrove, MSGBOX_SIGN
	end

Route29_Text_Youngster:
	.string "I like training on ROUTE 29.\n"
	.string "It's quiet and safe.$"

Route29_Text_Lass:
	.string "People say MR. POKEMON lives up\n"
	.string "north on ROUTE 30.$"

Route29_Text_FatMan:
	.string "I take breaks on this route.\n"
	.string "It's a nice walk between towns.$"

Route29_Text_Boy:
	.string "BERRIES grow here. I bring some\n"
	.string "home when I can.$"

Route29_Text_SignRoute29:
	.string "ROUTE 29\n"
	.string "NEW BARK TOWN - CHERRYGROVE CITY$"

Route29_Text_SignCherrygrove:
	.string "CHERRYGROVE CITY AHEAD.$"
