saffron_copycatshouse1f_MapScripts::
	.byte 0

saffron_copycatshouse1f_Speaker_Man:
	.string "Marlow$"

saffron_copycatshouse1f_Speaker_Woman:
	.string "Elise$"

saffron_copycatshouse1f_EventScript_Man::
	faceplayer
	setspeaker saffron_copycatshouse1f_Speaker_Man
	msgbox saffron_copycatshouse1f_Text_Man, MSGBOX_NPC
	end

saffron_copycatshouse1f_EventScript_Woman::
	faceplayer
	setspeaker saffron_copycatshouse1f_Speaker_Woman
	msgbox saffron_copycatshouse1f_Text_Woman, MSGBOX_NPC
	end

saffron_copycatshouse1f_Text_Man:
	.string "COPYCAT has been upstairs\n"
	.string "listening to every odd sound\l"
	.string "outside.\p"
	.string "SILPH CO. being guarded has\n"
	.string "everyone on edge.$"

saffron_copycatshouse1f_Text_Woman:
	.string "The MAGNET TRAIN being down\n"
	.string "has made SAFFRON feel cut\l"
	.string "off from JOHTO.$"
