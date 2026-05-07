Route12_MapScripts::
	.byte 0

Route12_Speaker_Fisherman_Bridge:
	.string "MORRIS$"

Route12_Speaker_Fisherman_1:
	.string "CAL$"

Route12_Speaker_Fisherman_2:
	.string "DANE$"

Route12_Speaker_Fisherman_3:
	.string "OTIS$"

Route12_Speaker_Fisherman_4:
	.string "REID$"

Route12_Speaker_Fisherman_5:
	.string "GLENN$"

Route12_EventScript_Fisherman_Bridge::
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, Route12_EventScript_Fisherman_Bridge_AfterRod
	setspeaker Route12_Speaker_Fisherman_Bridge
	msgbox Route12_Text_Fisherman_Bridge_BlockingSnorlax, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	setspeaker Route12_Speaker_Fisherman_Bridge
	msgbox Route12_Text_Fisherman_Bridge_GaveOldRod, MSGBOX_DEFAULT
	end

Route12_EventScript_Fisherman_Bridge_AfterRod::
	setspeaker Route12_Speaker_Fisherman_Bridge
	msgbox Route12_Text_Fisherman_Bridge_AfterRod, MSGBOX_NPC
	end

Route12_EventScript_Fisherman_1::
	faceplayer
	setspeaker Route12_Speaker_Fisherman_1
	msgbox Route12_Text_Fisherman_1, MSGBOX_NPC
	end

Route12_EventScript_Fisherman_2::
	faceplayer
	setspeaker Route12_Speaker_Fisherman_2
	msgbox Route12_Text_Fisherman_2, MSGBOX_NPC
	end

Route12_EventScript_Fisherman_3::
	faceplayer
	setspeaker Route12_Speaker_Fisherman_3
	msgbox Route12_Text_Fisherman_3, MSGBOX_NPC
	end

Route12_EventScript_Fisherman_4::
	faceplayer
	setspeaker Route12_Speaker_Fisherman_4
	msgbox Route12_Text_Fisherman_4, MSGBOX_NPC
	end

Route12_EventScript_Fisherman_5::
	faceplayer
	setspeaker Route12_Speaker_Fisherman_5
	msgbox Route12_Text_Fisherman_5, MSGBOX_NPC
	end

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "ROUTE 12\p"
	.string "NORTH TO LAVENDER TOWN$"

Route12_Text_FishingSpotSign:
	.string "FISHING SPOT$"

Route12_Text_Fisherman_Bridge_BlockingSnorlax:
	.string "I've been trying to get to my\n"
	.string "brother's house, but this giant\l"
	.string "SNORLAX fell asleep on the bridge.\p"
	.string "Here, take this OLD ROD.\n"
	.string "See if you can find a way to wake\l"
	.string "that SNORLAX up.\p"
	.string "If you do, I'll be sure to tell my\n"
	.string "brother to give you a reward.$"

Route12_Text_Fisherman_Bridge_GaveOldRod:
	.string "An OLD ROD's not much, but it might\n"
	.string "help you figure something out.\p"
	.string "If you wake that SNORLAX, my brother\n"
	.string "will hear about it.$"

Route12_Text_Fisherman_Bridge_AfterRod:
	.string "Any luck waking that SNORLAX?\p"
	.string "My brother will want to thank anyone\n"
	.string "who clears the bridge.$"

Route12_Text_Fisherman_1:
	.string "These waters are calm, but you still\n"
	.string "need patience if you want a bite.$"

Route12_Text_Fisherman_2:
	.string "ROUTE 12's a good place to fish,\n"
	.string "as long as nobody blocks the bridge.$"

Route12_Text_Fisherman_3:
	.string "Sometimes I think the fish here are\n"
	.string "smarter than the trainers.$"

Route12_Text_Fisherman_4:
	.string "I could spend all day fishing out\n"
	.string "here and never get bored.$"

Route12_Text_Fisherman_5:
	.string "If the water's moving, the fish are\n"
	.string "thinking. That's when you cast.$"
