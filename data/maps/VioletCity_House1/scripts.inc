VioletCity_House1_MapScripts::
	.byte 0

VioletCity_House1_Speaker_Hiker:
	.string "BRUCE$"

VioletCity_House1_EventScript_Hiker::
	faceplayer
	setspeaker VioletCity_House1_Speaker_Hiker
	msgbox VioletCity_House1_Text_Hiker, MSGBOX_NPC
	setflag FLAG_QUEST_VIOLET_NPC_HOUSE1_HIKER
	call Violet_City_EventScript_CheckVioletQuest
	end

VioletCity_House1_Text_Hiker:
	.string "DARK CAVE is cold and damp.\n"
	.string "Bring supplies if you head in.$"
