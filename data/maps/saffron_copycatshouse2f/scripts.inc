saffron_copycatshouse2f_MapScripts::
	.byte 0

saffron_copycatshouse2f_Speaker_Doll:
	.string "MIMI DOLL$"

saffron_copycatshouse2f_Speaker_Copycat:
	.string "COPYCAT$"

saffron_copycatshouse2f_EventScript_Doll::
	setspeaker saffron_copycatshouse2f_Speaker_Doll
	msgbox saffron_copycatshouse2f_Text_Doll, MSGBOX_NPC
	end

saffron_copycatshouse2f_EventScript_Copycat::
	faceplayer
	setspeaker saffron_copycatshouse2f_Speaker_Copycat
	msgbox saffron_copycatshouse2f_Text_Copycat, MSGBOX_NPC
	end

saffron_copycatshouse2f_Text_Doll:
	.string "It's a carefully kept doll.\p"
	.string "It looks like COPYCAT has\n"
	.string "been staying inside lately.$"

saffron_copycatshouse2f_Text_Copycat:
	.string "I can copy people,\n"
	.string "but I can't copy those scary\l"
	.string "CIPHER voices.\p"
	.string "They keep talking about the\n"
	.string "radio... Creepy! Creepy!$"
