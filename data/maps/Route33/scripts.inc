Route33_MapScripts::
	.byte 0

Route33_Speaker_Hiker:
	.string "DUKE$"

Route33_EventScript_Hiker::
	setspeaker Route33_Speaker_Hiker
	trainerbattle_single TRAINER_ROUTE33_HIKER, Route33_Text_Hiker_Intro, Route33_Text_Hiker_Defeat, Route33_EventScript_Hiker_After
	end

Route33_EventScript_Hiker_After::
	setspeaker Route33_Speaker_Hiker
	msgbox Route33_Text_Hiker_After, MSGBOX_NPC
	closemessage
	release
	end

Route33_Text_Hiker_Intro:
	.string "These cliffs are my training\n"
	.string "ground!$"

Route33_Text_Hiker_Defeat:
	.string "That was a steady climb...$"

Route33_Text_Hiker_After:
	.string "UNION CAVE is rough. Be ready\n"
	.string "before you go in.$"
