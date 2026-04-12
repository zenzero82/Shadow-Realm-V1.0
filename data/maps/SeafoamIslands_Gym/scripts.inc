SeafoamIslands_Gym_MapScripts::
	.byte 0

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SeafoamIslands_Gym_Text_GymStatue::
    .string "CINNABAR POKéMON GYM\n"
    .string "LEADER: BLAINE\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "CINNABAR POKéMON GYM\n"
    .string "LEADER: BLAINE\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
