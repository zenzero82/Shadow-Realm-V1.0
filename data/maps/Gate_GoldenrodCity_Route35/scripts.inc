Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Excuse me, kid! Can you do a guy\n"
	.string "a favor?\p"
	.string "Can you take this POKéMON with MAIL\n"
	.string "to my friend?\p"
	.string "He's on ROUTE 31.$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "A strange tree is blocking the road.\p"
	.string "It wriggles around if you talk to it.\p"
	.string "I heard it became wild when someone\n"
	.string "watered it with a SQUIRTBOTTLE.$"

Route35GoldenrodGate_Text_Fisher:
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "Three years ago, PROF. OAK said that\n"
	.string "there were 150 different kinds.\p"
	.string "But recently I heard there's\n"
	.string "over 400!$"

