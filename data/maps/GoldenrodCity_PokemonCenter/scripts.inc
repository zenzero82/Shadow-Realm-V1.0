GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_Speaker_Edna:
	.string "EDNA$"

GoldenrodCity_PokemonCenter_Speaker_Nora:
	.string "NORA$"

GoldenrodCity_PokemonCenter_Speaker_Ken:
	.string "KEN$"

GoldenrodCity_PokemonCenter_Speaker_Leo:
	.string "LEO$"

GoldenrodCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_OnTransition_ApplyCipherDisguise
	end

GoldenrodCity_PokemonCenter_OnTransition_ApplyCipherDisguise:
	special Special_ApplyCipherDisguise
	end

GoldenrodCity_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_EventScript_Nurse_Disguised
	call Common_EventScript_PkmnCenterNurse
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Nurse_Disguised:
	msgbox GoldenrodCity_PokemonCenter_Text_Nurse_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Edna::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_EventScript_Edna_Disguised
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Edna
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_PokemonCenter_EventScript_Edna_AfterWhitney
	msgbox GoldenrodCity_PokemonCenter_Text_Edna, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Edna_AfterWhitney:
	msgbox GoldenrodCity_PokemonCenter_Text_Edna_AfterWhitney, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Edna_Disguised:
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Edna
	msgbox GoldenrodCity_PokemonCenter_Text_Edna_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Nora::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_EventScript_Nora_Disguised
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Nora
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_PokemonCenter_EventScript_Nora_AfterWhitney
	msgbox GoldenrodCity_PokemonCenter_Text_Nora, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Nora_AfterWhitney:
	msgbox GoldenrodCity_PokemonCenter_Text_Nora_AfterWhitney, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Nora_Disguised:
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Nora
	msgbox GoldenrodCity_PokemonCenter_Text_Nora_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Ken::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_EventScript_Ken_Disguised
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Ken
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_PokemonCenter_EventScript_Ken_AfterWhitney
	msgbox GoldenrodCity_PokemonCenter_Text_Ken, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Ken_AfterWhitney:
	msgbox GoldenrodCity_PokemonCenter_Text_Ken_AfterWhitney, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Ken_Disguised:
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Ken
	msgbox GoldenrodCity_PokemonCenter_Text_Ken_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Leo::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, GoldenrodCity_PokemonCenter_EventScript_Leo_Disguised
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Leo
	goto_if_set FLAG_BADGE19_GET, GoldenrodCity_PokemonCenter_EventScript_Leo_AfterWhitney
	msgbox GoldenrodCity_PokemonCenter_Text_Leo, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Leo_AfterWhitney:
	msgbox GoldenrodCity_PokemonCenter_Text_Leo_AfterWhitney, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Leo_Disguised:
	setspeaker GoldenrodCity_PokemonCenter_Speaker_Leo
	msgbox GoldenrodCity_PokemonCenter_Text_Leo_Disguised, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_PokemonCenter_Text_Nurse_Disguised:
	.string "We don't treat CIPHER here.\p"
	.string "Take your uniforms and leave.$"

GoldenrodCity_PokemonCenter_Text_Edna:
	.string "Every trainer in town is waiting for\n"
	.string "bad news, so the CENTER has been\n"
	.string "packed since morning.$"

GoldenrodCity_PokemonCenter_Text_Edna_AfterWhitney:
	.string "Even with the city in chaos, the\n"
	.string "CENTER never gets to slow down.$"

GoldenrodCity_PokemonCenter_Text_Edna_Disguised:
	.string "I knew you'd come sniffing around.\n"
	.string "Nobody here wants you in this CENTER.$"

GoldenrodCity_PokemonCenter_Text_Nora:
	.string "People keep asking if the RADIO TOWER\n"
	.string "is okay.\p"
	.string "Nobody knows anything for sure yet,\n"
	.string "and that makes it worse.$"

GoldenrodCity_PokemonCenter_Text_Nora_AfterWhitney:
	.string "I heal up here, then head right back\n"
	.string "out. Goldenrod still needs help.$"

GoldenrodCity_PokemonCenter_Text_Nora_Disguised:
	.string "You're seriously barging into the\n"
	.string "CENTER dressed like that?$"

GoldenrodCity_PokemonCenter_Text_Ken:
	.string "Link battles feel silly right now,\n"
	.string "but they keep our minds sharp.$"

GoldenrodCity_PokemonCenter_Text_Ken_AfterWhitney:
	.string "Link battles feel silly right now,\n"
	.string "but they keep our minds sharp.$"

GoldenrodCity_PokemonCenter_Text_Ken_Disguised:
	.string "If CIPHER touches my team, I'm\n"
	.string "throwing hands before Poké Balls.$"

GoldenrodCity_PokemonCenter_Text_Leo:
	.string "Those black uniforms give me a bad\n"
	.string "feeling.\p"
	.string "If CIPHER starts something, Goldenrod\n"
	.string "will push back.$"

GoldenrodCity_PokemonCenter_Text_Leo_AfterWhitney:
	.string "If CIPHER wants a city full of scared\n"
	.string "trainers, they're going to be upset.$"

GoldenrodCity_PokemonCenter_Text_Leo_Disguised:
	.string "Good. Be upset.\p"
	.string "Goldenrod hates CIPHER.$"
