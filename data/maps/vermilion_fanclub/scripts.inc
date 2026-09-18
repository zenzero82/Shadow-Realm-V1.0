vermilion_fanclub_MapScripts::
	.byte 0

vermilion_fanclub_Speaker_Chairman:
	.string "EDGAR$"

vermilion_fanclub_Speaker_Secretary:
	.string "SHEILA$"

vermilion_fanclub_Speaker_FanM:
	.string "BRUCE$"

vermilion_fanclub_Speaker_FanF:
	.string "LANA$"

vermilion_fanclub_EventScript_Chairman::
	lock
	faceplayer
	setspeaker vermilion_fanclub_Speaker_Chairman
	msgbox vermilion_fanclub_Text_Chairman, MSGBOX_NPC
	release
	end

vermilion_fanclub_EventScript_Secretary::
	lock
	faceplayer
	setspeaker vermilion_fanclub_Speaker_Secretary
	msgbox vermilion_fanclub_Text_Secretary, MSGBOX_NPC
	release
	end

vermilion_fanclub_EventScript_FanM::
	lock
	faceplayer
	setspeaker vermilion_fanclub_Speaker_FanM
	msgbox vermilion_fanclub_Text_FanM, MSGBOX_NPC
	release
	end

vermilion_fanclub_EventScript_FanF::
	lock
	faceplayer
	setspeaker vermilion_fanclub_Speaker_FanF
	msgbox vermilion_fanclub_Text_FanF, MSGBOX_NPC
	release
	end

vermilion_fanclub_Text_Chairman:
	.string "A true fan club can survive any rumor\n"
	.string "storm, as long as POKeMON are loved.$"

vermilion_fanclub_Text_Secretary:
	.string "People visit from all over KANTO.\p"
	.string "A few minutes with their favorite\n"
	.string "POKeMON usually fixes any bad mood.$"

vermilion_fanclub_Text_FanM:
	.string "I heard a giant SNORLAX is blocking\n"
	.string "the road.\p"
	.string "That's inconvenient, but also a\n"
	.string "little amazing.$"

vermilion_fanclub_Text_FanF:
	.string "VERMILION is never quiet for long.\p"
	.string "That is why the fan club is perfect.\n"
	.string "It gives us one happy thing to share.$"
