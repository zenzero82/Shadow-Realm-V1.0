celadon_apartmentroofhouse_MapScripts::
	.byte 0

celadon_apartmentroofhouse_Speaker_BlackBelt:
	.string "KENJI$"

celadon_apartmentroofhouse_EventScript_PokeBall::
	faceplayer
	msgbox celadon_apartmentroofhouse_Text_PokeBall, MSGBOX_NPC
	end

celadon_apartmentroofhouse_EventScript_BlackBelt::
	lock
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_ROOFHOUSE_BLACKBELT
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker celadon_apartmentroofhouse_Speaker_BlackBelt
	checkflag FLAG_CELADON_ROOFHOUSE_TYROGUE_TAKEN
	goto_if_set FLAG_CELADON_ROOFHOUSE_TYROGUE_TAKEN, celadon_apartmentroofhouse_EventScript_BlackBelt_AfterGift
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_Intro, MSGBOX_DEFAULT
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_Offer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, celadon_apartmentroofhouse_EventScript_BlackBelt_GiveTyrogue
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_No, MSGBOX_DEFAULT
	release
	end

celadon_apartmentroofhouse_EventScript_BlackBelt_GiveTyrogue::
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_Yes, MSGBOX_DEFAULT
	givemon SPECIES_TYROGUE, 5
	setflag FLAG_CELADON_ROOFHOUSE_TYROGUE_TAKEN
	removeobject 2
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_EvolutionInfo, MSGBOX_DEFAULT
	release
	end

celadon_apartmentroofhouse_EventScript_BlackBelt_AfterGift::
	msgbox celadon_apartmentroofhouse_Text_BlackBelt_AfterGift, MSGBOX_DEFAULT
	release
	end

celadon_apartmentroofhouse_Text_PokeBall:
	.string "It seems like there is a POKeMON\n"
	.string "inside!$"

celadon_apartmentroofhouse_Text_BlackBelt_Intro:
	.string "I left my HITMONTOP at the DAY CARE\n"
	.string "for a while.\p"
	.string "When I came back, the attendants told\n"
	.string "me they found an EGG. This little one\l"
	.string "hatched from it.$"

celadon_apartmentroofhouse_Text_BlackBelt_Offer:
	.string "Do you want the POKeMON that hatched\n"
	.string "from that EGG?$"

celadon_apartmentroofhouse_Text_BlackBelt_No:
	.string "Fair enough. If you change your mind,\n"
	.string "come talk to me again.$"

celadon_apartmentroofhouse_Text_BlackBelt_Yes:
	.string "Then raise this TYROGUE well.\p"
	.string "A fighter's potential means nothing\n"
	.string "without discipline.$"

celadon_apartmentroofhouse_Text_BlackBelt_EvolutionInfo:
	.string "TYROGUE has three evolutions.\p"
	.string "At level 20, if its ATTACK is higher\n"
	.string "than its DEFENSE, it becomes\l"
	.string "HITMONLEE.\p"
	.string "If its DEFENSE is higher than its\n"
	.string "ATTACK, it becomes HITMONCHAN.\p"
	.string "If ATTACK and DEFENSE are equal at\n"
	.string "level 20, it becomes HITMONTOP.$"

celadon_apartmentroofhouse_Text_BlackBelt_AfterGift:
	.string "Remember TYROGUE's path at level 20:\n"
	.string "ATTACK for HITMONLEE, DEFENSE for\l"
	.string "HITMONCHAN, balance for HITMONTOP.$"
