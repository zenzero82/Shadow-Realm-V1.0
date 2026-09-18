Route30_MrPokemonsHouse_MapScripts::
	.byte 0

Route30_MrPokemonsHouse_Speaker_MrPokemon:
	.string "Mr. POKéMON$"

Route30_MrPokemonsHouse_EventScript_Gentleman::
	lock
	faceplayer
	setspeaker Route30_MrPokemonsHouse_Speaker_MrPokemon
	msgbox Route30_MrPokemonsHouse_Text_Gentleman_Intro, MSGBOX_DEFAULT
	setspeaker Route30_MrPokemonsHouse_Speaker_MrPokemon
	msgbox Route30_MrPokemonsHouse_Text_Gentleman_ShadowResearch, MSGBOX_DEFAULT
	setspeaker Route30_MrPokemonsHouse_Speaker_MrPokemon
	msgbox Route30_MrPokemonsHouse_Text_Gentleman_Cipher, MSGBOX_DEFAULT
	setspeaker Route30_MrPokemonsHouse_Speaker_MrPokemon
	msgbox Route30_MrPokemonsHouse_Text_Gentleman_EggResearch, MSGBOX_DEFAULT
	setspeaker Route30_MrPokemonsHouse_Speaker_MrPokemon
	msgbox Route30_MrPokemonsHouse_Text_Gentleman_Warning, MSGBOX_DEFAULT
	release
	end

Route30_MrPokemonsHouse_EventScript_Bookshelf_ShadowNotes::
	msgbox Route30_MrPokemonsHouse_Text_Bookshelf_ShadowNotes, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_EventScript_Bookshelf_EggResearch::
	msgbox Route30_MrPokemonsHouse_Text_Bookshelf_EggResearch, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_EventScript_Bookshelf_CipherFile::
	msgbox Route30_MrPokemonsHouse_Text_Bookshelf_CipherFile, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_EventScript_Bookshelf_OakClipping::
	msgbox Route30_MrPokemonsHouse_Text_Bookshelf_OakClipping, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_Text_Gentleman_Intro:
	.string "I've worked alongside Professor ELM\n"
	.string "and Professor OAK for quite some time.\p"
	.string "Before Professor OAK disappeared, the\n"
	.string "three of us compared notes here often.$"

Route30_MrPokemonsHouse_Text_Gentleman_ShadowResearch:
	.string "Lately my attention has turned to\n"
	.string "SHADOW POKeMON.\p"
	.string "Their behavior, their aura, and the\n"
	.string "way their hearts are closed off...\l"
	.string "it's deeply troubling research.$"

Route30_MrPokemonsHouse_Text_Gentleman_Cipher:
	.string "I've also uncovered new information\n"
	.string "on CIPHER.\p"
	.string "In this timeline, three Admins stand\n"
	.string "above the rest. They are powerful,\l"
	.string "dangerous, and not to be underestimated.$"

Route30_MrPokemonsHouse_Text_Gentleman_EggResearch:
	.string "My egg research has been forced to a\n"
	.string "halt because of all this.\p"
	.string "That had been my main focus, but these\n"
	.string "recent discoveries are too urgent to\l"
	.string "ignore.$"

Route30_MrPokemonsHouse_Text_Gentleman_Warning:
	.string "If you're getting drawn into this,\n"
	.string "be careful.\p"
	.string "What we're dealing with now is far more\n"
	.string "serious than an ordinary POKeMON mystery.$"

Route30_MrPokemonsHouse_Text_Bookshelf_ShadowNotes:
	.string "There are notebooks full of aura\n"
	.string "readings from SHADOW POKeMON.\p"
	.string "Several pages are marked URGENT.$"

Route30_MrPokemonsHouse_Text_Bookshelf_EggResearch:
	.string "This shelf is packed with notes on\n"
	.string "POKeMON EGGS and hatch patterns.\p"
	.string "A tag reads: MAIN RESEARCH - PAUSED.$"

Route30_MrPokemonsHouse_Text_Bookshelf_CipherFile:
	.string "A folder labeled CIPHER contains\n"
	.string "reports on three dangerous Admins.\p"
	.string "Most of the names are redacted.$"

Route30_MrPokemonsHouse_Text_Bookshelf_OakClipping:
	.string "There is a clipping about Professor\n"
	.string "OAK'S disappearance.\p"
	.string "Someone wrote, Keep searching, in the\n"
	.string "margin.$"
