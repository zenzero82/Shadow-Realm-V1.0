pewter_museum2fl_MapScripts::
	.byte 0

pewter_museum2fl_Speaker_Nerd:
	.string "Dexter$"

pewter_museum2fl_Speaker_Balding:
	.string "Harold$"

pewter_museum2fl_Speaker_Twin:
	.string "Pip$"

pewter_museum2fl_EventScript_Nerd::
	lock
	faceplayer
	setspeaker pewter_museum2fl_Speaker_Nerd
	msgbox pewter_museum2fl_Text_Nerd, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_NERD
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_museum2fl_EventScript_Balding::
	lock
	faceplayer
	setspeaker pewter_museum2fl_Speaker_Balding
	msgbox pewter_museum2fl_Text_Balding, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_BALDING
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_museum2fl_EventScript_Twin::
	lock
	faceplayer
	setspeaker pewter_museum2fl_Speaker_Twin
	msgbox pewter_museum2fl_Text_Twin, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_TWIN
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_museum2fl_EventScript_Sign_MoonStone::
	msgbox pewter_museum2fl_Text_Sign_MoonStone, MSGBOX_SIGN
	end

pewter_museum2fl_EventScript_Sign_SpaceProbe::
	msgbox pewter_museum2fl_Text_Sign_SpaceProbe, MSGBOX_SIGN
	end

pewter_museum2fl_EventScript_Sign_AstroChart::
	msgbox pewter_museum2fl_Text_Sign_AstroChart, MSGBOX_SIGN
	end

pewter_museum2fl_EventScript_Sign_FossilLab::
	msgbox pewter_museum2fl_Text_Sign_FossilLab, MSGBOX_SIGN
	end

pewter_museum2fl_Text_Nerd:
	.string "If we map every star, we might find\n"
	.string "where the meteors came from.$"

pewter_museum2fl_Text_Balding:
	.string "This place used to be my weekend trip.\p"
	.string "Feels smaller now, but it's still\n"
	.string "wonderful.$"

pewter_museum2fl_Text_Twin:
	.string "I like the shiny rocks upstairs!\n"
	.string "They sparkle like candy.$"

pewter_museum2fl_Text_Sign_MoonStone:
	.string "MOON STONE DISPLAY\n"
	.string "Rare stones found deep in MT. MOON.$"

pewter_museum2fl_Text_Sign_SpaceProbe:
	.string "SPACE PROBE MODEL\n"
	.string "A miniature craft used for sky scans.$"

pewter_museum2fl_Text_Sign_AstroChart:
	.string "ASTRONOMY CHART\n"
	.string "A map of constellations over KANTO.$"

pewter_museum2fl_Text_Sign_FossilLab:
	.string "FOSSIL RESTORATION NOTES\n"
	.string "Work continues on revived specimens.$"
