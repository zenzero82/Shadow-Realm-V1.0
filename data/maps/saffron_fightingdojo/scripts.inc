saffron_fightingdojo_MapScripts::
	.byte 0

saffron_fightingdojo_Speaker_Trainer:
	.string "Takeshi$"

saffron_fightingdojo_Speaker_Cooltrainer:
	.string "Riona$"

saffron_fightingdojo_EventScript_Trainer::
	faceplayer
	setspeaker saffron_fightingdojo_Speaker_Trainer
	msgbox saffron_fightingdojo_Text_Trainer, MSGBOX_NPC
	end

saffron_fightingdojo_EventScript_Cooltrainer::
	faceplayer
	setspeaker saffron_fightingdojo_Speaker_Cooltrainer
	msgbox saffron_fightingdojo_Text_Cooltrainer, MSGBOX_NPC
	end

saffron_fightingdojo_Text_Trainer:
	.string "The DOJO is open only for\n"
	.string "members right now.\p"
	.string "CIPHER showing up near SILPH\n"
	.string "has everyone watching the\l"
	.string "doors.$"

saffron_fightingdojo_Text_Cooltrainer:
	.string "We train to be fearless,\n"
	.string "but reckless is different.\p"
	.string "Until this city calms down,\n"
	.string "we're keeping outsiders away.$"
