celadon_apartment1f_MapScripts::
	.byte 0

celadon_apartment1f_Speaker_OldWoman:
	.string "DORIS$"

celadon_apartment1f_EventScript_OldWoman::
	faceplayer
	setflag FLAG_QUEST_CELADON_NPC_APARTMENT_OLD_WOMAN
	call CeladonCity_EventScript_CheckNPCQuestState
	setspeaker celadon_apartment1f_Speaker_OldWoman
	msgbox celadon_apartment1f_Text_OldWoman, MSGBOX_NPC
	end

celadon_apartment1f_Text_OldWoman:
	.string "The city never sleeps.\p"
	.string "At least the roof is quiet.$"
