RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	faceplayer
	setspeaker RustboroCity_House3_Speaker_Vernon
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	faceplayer
	setspeaker RustboroCity_House3_Speaker_Mabel
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	setspeaker RustboroCity_House3_Speaker_Pekachu
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Speaker_Vernon:
	.string "Vernon$"

RustboroCity_House3_Speaker_Mabel:
	.string "Mabel$"

RustboroCity_House3_Speaker_Pekachu:
	.string "PEKACHU$"

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"
