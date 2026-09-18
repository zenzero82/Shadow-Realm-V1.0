RuinsOfAlph_WordsRoom2_MapScripts::
	.byte 0

RuinsOfAlph_WordsRoom2_EventScript_Door::
	lockall
	goto_if_set FLAG_RUINSOFALPH_OMANYTE_CAMERA_PUZZLE_SOLVED, RuinsOfAlph_WordsRoom2_EventScript_DoorOpen
	msgbox RuinsOfAlph_WordsRoom2_Text_Hint, MSGBOX_DEFAULT
	releaseall
	end

RuinsOfAlph_WordsRoom2_EventScript_DoorOpen::
	msgbox RuinsOfAlph_WordsRoom2_Text_DoorOpen, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUINS_OF_ALPH_PUZZLE_AND_REWARD_CHAMBERS, 20, 5
	waitstate
	releaseall
	end

RuinsOfAlph_WordsRoom2_EventScript_CameraPuzzleSolved::
	lockall
	goto_if_set FLAG_RUINSOFALPH_OMANYTE_CAMERA_PUZZLE_SOLVED, RuinsOfAlph_WordsRoom2_EventScript_AlreadySolved
	setflag FLAG_RUINSOFALPH_OMANYTE_CAMERA_PUZZLE_SOLVED
	msgbox RuinsOfAlph_WordsRoom2_Text_CameraSolved, MSGBOX_DEFAULT
	releaseall
	end

RuinsOfAlph_WordsRoom2_EventScript_AlreadySolved::
	msgbox RuinsOfAlph_WordsRoom2_Text_AlreadySolved, MSGBOX_DEFAULT
	releaseall
	end

RuinsOfAlph_WordsRoom2_EventScript_CameraPuzzleFailed::
	lockall
	msgbox RuinsOfAlph_WordsRoom2_Text_CameraFailed, MSGBOX_DEFAULT
	releaseall
	end

RuinsOfAlph_WordsRoom2_Text_Hint:
	.string "It's UNOWN text...\p"
	.string "HELIX IN A MOMENT.$"

RuinsOfAlph_WordsRoom2_Text_DoorOpen:
	.string "The way is open.$"

RuinsOfAlph_WordsRoom2_Text_CameraSolved:
	.string "The chamber reacts!\p"
	.string "The way is open.$"

RuinsOfAlph_WordsRoom2_Text_AlreadySolved:
	.string "The chamber has already opened\n"
	.string "the way.$"

RuinsOfAlph_WordsRoom2_Text_CameraFailed:
	.string "Nothing happened.$"
