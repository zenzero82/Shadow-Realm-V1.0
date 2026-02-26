SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_Speaker_Flare:
	.string "FLARE$"

SlowpokeWell_B1F_Speaker_Bryony:
	.string "BRYONY$"

SlowpokeWell_B1F_Speaker_Ethan:
	.string "ETHAN$"

SlowpokeWell_B1F_EventScript_Flare1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE18_GET, SlowpokeWell_B1F_EventScript_Flare1_Battle
	msgbox SlowpokeWell_B1F_Text_Flare1_Block, MSGBOX_DEFAULT
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Flare1_Battle::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_1, SlowpokeWell_B1F_Text_Flare1_Intro, SlowpokeWell_B1F_Text_Flare1_Defeat, SlowpokeWell_B1F_EventScript_Flare1_After
	end

SlowpokeWell_B1F_EventScript_Flare1_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	msgbox SlowpokeWell_B1F_Text_Flare1_After, MSGBOX_NPC
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Flare2::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_2, SlowpokeWell_B1F_Text_Flare2_Intro, SlowpokeWell_B1F_Text_Flare2_Defeat, SlowpokeWell_B1F_EventScript_Flare2_After
	end

SlowpokeWell_B1F_EventScript_Flare2_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	msgbox SlowpokeWell_B1F_Text_Flare2_After, MSGBOX_NPC
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Flare3::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	trainerbattle_single TRAINER_SLOWPOKEWELL_FLARE_3, SlowpokeWell_B1F_Text_Flare3_Intro, SlowpokeWell_B1F_Text_Flare3_Defeat, SlowpokeWell_B1F_EventScript_Flare3_After
	end

SlowpokeWell_B1F_EventScript_Flare3_After::
	setspeaker SlowpokeWell_B1F_Speaker_Flare
	msgbox SlowpokeWell_B1F_Text_Flare3_After, MSGBOX_NPC
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Bryony::
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	trainerbattle_single TRAINER_SLOWPOKEWELL_BRYONY, SlowpokeWell_B1F_Text_Bryony_Intro, SlowpokeWell_B1F_Text_Bryony_Defeat, SlowpokeWell_B1F_EventScript_Bryony_After
	end

SlowpokeWell_B1F_EventScript_Bryony_After::
	setspeaker SlowpokeWell_B1F_Speaker_Bryony
	msgbox SlowpokeWell_B1F_Text_Bryony_After, MSGBOX_NPC
	closemessage
	goto_if_set FLAG_ETHAN_CALL_AFTER_BRYONY, SlowpokeWell_B1F_EventScript_Bryony_After_Done
	setspeaker SlowpokeWell_B1F_Speaker_Ethan
	pokenavcall SlowpokeWell_B1F_Text_Ethan_Call
	waitmessage
	setflag FLAG_ETHAN_CALL_AFTER_BRYONY
	setflag FLAG_HIDE_VIOLET_GATE_POLICEMAN
SlowpokeWell_B1F_EventScript_Bryony_After_Done::
	release
	end

SlowpokeWell_B1F_Text_Flare1_Intro:
	.string "TEAM FLARE is studying this well.\n"
	.string "Leave at once.$"

SlowpokeWell_B1F_Text_Flare1_Block:
	.string "Get lost. This well is off-limits.$"

SlowpokeWell_B1F_Text_Flare1_Defeat:
	.string "Our gauges...$"

SlowpokeWell_B1F_Text_Flare1_After:
	.string "BRYONY wants clean readings,\n"
	.string "not chaos.$"

SlowpokeWell_B1F_Text_Flare2_Intro:
	.string "SLOWPOKE tails are a cover.\p"
	.string "We're after shadow traces.$"

SlowpokeWell_B1F_Text_Flare2_Defeat:
	.string "The trail slipped!$"

SlowpokeWell_B1F_Text_Flare2_After:
	.string "We still have samples.\n"
	.string "Don't get in the way.$"

SlowpokeWell_B1F_Text_Flare3_Intro:
	.string "This is TEAM FLARE territory.\n"
	.string "Turn back.$"

SlowpokeWell_B1F_Text_Flare3_Defeat:
	.string "So much for secrecy.$"

SlowpokeWell_B1F_Text_Flare3_After:
	.string "We'll move deeper.\n"
	.string "You can't stop us.$"

SlowpokeWell_B1F_Text_Bryony_Intro:
	.string "I'm BRYONY. This well hides a\n"
	.string "shadow signature.\p"
	.string "You will not interfere.$"

SlowpokeWell_B1F_Text_Bryony_Defeat:
	.string "Impossible...$"

SlowpokeWell_B1F_Text_Bryony_After:
	.string "TEAM FLARE will return with\n"
	.string "better data.$"

SlowpokeWell_B1F_Text_Ethan_Call:
	.string "Hello? Hey this is Ethan.\p"
	.string "I got your contact from Michael.\p"
	.string "He gave me the run down of you\n"
	.string "helping us out!\p"
	.string "How is everything in Azalea?\p"
	.string "... ... I see, you faced Team\n"
	.string "Rocketa and Team Flare.\p"
	.string "Jeez. These guys are spreading\n"
	.string "like wildfire.\p"
	.string "Since you are in the area, can you\n"
	.string "do me a favor and head out to\n"
	.string "New Bark Town to check on my\n"
	.string "mo... err I mean Gold's mom?\p"
	.string "This timeline nonsense is really\n"
	.string "confusing hahah.\p"
	.string "But yeah, can you just make sure\n"
	.string "she is okay, its been a while\n"
	.string "since I visited.\p"
	.string "Thanks!$"
