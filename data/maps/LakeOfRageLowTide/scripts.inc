LakeOfRageLowTide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRageLowTide_OnTransition
	.byte 0

LakeOfRageLowTide_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	end

LakeOfRageLowTide_EventScript_Sign1::
	msgbox LakeOfRageLowTide_Text_Sign, MSGBOX_SIGN
	end


LakeOfRageLowTide_EventScript_Sign2::
	msgbox LakeOfRageLowTide_Text_FishingGuruSign, MSGBOX_SIGN
	end


LakeOfRageLowTide_Text_Sign:
    .string "LAKE OF RAGE,\n"
    .string "also known as GYARADOS LAKE.$"


LakeOfRageLowTide_Text_FishingGuruSign:
    .string "FISHING GURU'S HOUSE$"
