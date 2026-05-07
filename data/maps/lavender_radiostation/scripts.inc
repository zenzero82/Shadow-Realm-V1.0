lavender_radiostation_MapScripts::
	.byte 0

lavender_radiostation_Speaker_WorkerM:
	.string "TECH$"

lavender_radiostation_Speaker_Officer:
	.string "OFFICER$"

lavender_radiostation_Speaker_WorkerF:
	.string "PRODUCER$"

lavender_radiostation_Speaker_Gentleman:
	.string "LISTENER$"

lavender_radiostation_Speaker_Youngster:
	.string "TOMMY$"

lavender_radiostation_EventScript_WorkerM::
	faceplayer
	setspeaker lavender_radiostation_Speaker_WorkerM
	msgbox lavender_radiostation_Text_WorkerM, MSGBOX_NPC
	end

lavender_radiostation_EventScript_Officer::
	faceplayer
	setspeaker lavender_radiostation_Speaker_Officer
	msgbox lavender_radiostation_Text_Officer, MSGBOX_NPC
	end

lavender_radiostation_EventScript_WorkerF::
	faceplayer
	setspeaker lavender_radiostation_Speaker_WorkerF
	msgbox lavender_radiostation_Text_WorkerF, MSGBOX_NPC
	end

lavender_radiostation_EventScript_Gentleman::
	faceplayer
	setspeaker lavender_radiostation_Speaker_Gentleman
	msgbox lavender_radiostation_Text_Gentleman, MSGBOX_NPC
	end

lavender_radiostation_EventScript_Youngster::
	faceplayer
	setspeaker lavender_radiostation_Speaker_Youngster
	msgbox lavender_radiostation_Text_Youngster, MSGBOX_NPC
	end

lavender_radiostation_Text_WorkerM:
	.string "We're checking every room twice.\p"
	.string "If someone tried to use this station\n"
	.string "for another takeover, we'd know.$"

lavender_radiostation_Text_Officer:
	.string "I'm keeping watch until we're sure\n"
	.string "nobody's sneaking through here.\p"
	.string "LAVENDER has had enough trouble.$"

lavender_radiostation_Text_WorkerF:
	.string "The broadcasts are back to normal,\n"
	.string "but everyone sounds more serious\l"
	.string "than before.$"

lavender_radiostation_Text_Gentleman:
	.string "I come here for the music, not the\n"
	.string "rumors.\p"
	.string "Unfortunately, LAVENDER seems to\n"
	.string "have both in abundance.$"

lavender_radiostation_Text_Youngster:
	.string "I thought radio stations were\n"
	.string "supposed to be fun.\p"
	.string "Why are there so many grown-ups\n"
	.string "whispering in here?$"

LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end

LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
	
LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Perk Up POKéMON with Mellow\n"
	.string "Sounds of the POKé FLUTE on\l"
	.string "CHANNEL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Wow! A full rack of POKéMON CDs\n"
	.string "and videos.\p"
	.string "This must be the reference\n"
	.string "library.$"

LavenderTown_RadioStation_Text_Directory:
	.string "1F RECEPTION 2F SALES\p"
	.string "3F PERSONNEL 4F PRODUCTION\p"
	.string "5F DIRECTOR'S OFFICE$"