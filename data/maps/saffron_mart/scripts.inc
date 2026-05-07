saffron_mart_MapScripts::
	.byte 0

saffron_mart_Speaker_Clerk:
	.string "Clerk Reva$"

saffron_mart_Speaker_BugCatcher:
	.string "Ollie$"

saffron_mart_Speaker_Woman:
	.string "Maris$"

saffron_mart_EventScript_Clerk::
	lock
	faceplayer
	setspeaker saffron_mart_Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart saffron_mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

saffron_mart_EventScript_BugCatcher::
	faceplayer
	setspeaker saffron_mart_Speaker_BugCatcher
	msgbox saffron_mart_Text_BugCatcher, MSGBOX_NPC
	end

saffron_mart_EventScript_Woman::
	faceplayer
	setspeaker saffron_mart_Speaker_Woman
	msgbox saffron_mart_Text_Woman, MSGBOX_NPC
	end

	.align 2
saffron_mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

saffron_mart_Text_BugCatcher:
	.string "I came here for supplies\n"
	.string "before checking out SILPH.\p"
	.string "Then I saw the guards and\n"
	.string "changed my mind.$"

saffron_mart_Text_Woman:
	.string "The radio said everything is\n"
	.string "under control.\p"
	.string "That only made me more\n"
	.string "nervous.$"
