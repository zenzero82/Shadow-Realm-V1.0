pewter_house2_MapScripts::
	.byte 0

pewter_house2_Speaker_Gordon:
	.string "Gordon$"

pewter_house2_EventScript_OldMan::
	lock
	faceplayer
	setspeaker pewter_house2_Speaker_Gordon
	msgbox pewter_house2_Text_OldMan, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_house2_Text_OldMan:
	.string "ROUTE 3 is rough for new trainers.\p"
	.string "Pack a few POTIONS before you head\n"
	.string "toward MT. MOON.$"
