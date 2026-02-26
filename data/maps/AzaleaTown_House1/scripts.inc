AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_BlackBelt::
	faceplayer
	msgbox AzaleaTown_House1_Text_BlackBelt, MSGBOX_NPC
	end

AzaleaTown_House1_EventScript_LittleBoy::
	faceplayer
	msgbox AzaleaTown_House1_Text_LittleBoy, MSGBOX_NPC
	end

AzaleaTown_House1_Text_BlackBelt:
	.string "I train here to stay sharp.\n"
	.string "Quiet towns still need guardians.$"

AzaleaTown_House1_Text_LittleBoy:
	.string "I heard the WELL is safe again.\n"
	.string "Maybe I can visit someday.$"
