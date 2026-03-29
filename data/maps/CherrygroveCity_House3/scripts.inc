CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_Speaker_OldMan:
	.string "HUGH$"

CherrygroveCity_House3_EventScript_OldMan::
	faceplayer
	setspeaker CherrygroveCity_House3_Speaker_OldMan
	msgbox CherrygroveCity_House3_Text_OldMan, MSGBOX_NPC
	closemessage
	setflag FLAG_QUEST_CHERRYGROVE_NPC_HOUSE3_OLD_MAN
	call QuestJournal_EventScript_CheckCherrygroveNPCs
	end

CherrygroveCity_House3_Text_OldMan:
	.string "CHERRYGROVE may be small, but it\n"
	.string "is a good place to start a journey.$"
