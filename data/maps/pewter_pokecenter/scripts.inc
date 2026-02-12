pewter_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, pewter_pokecenter_OnTransition
	.byte 0

pewter_pokecenter_EventScript_Nurse::
	lock
	faceplayer
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, pewter_pokecenter_EventScript_Nurse_Goodbye

	setvar VAR_0x800B, 1
	applymovement VAR_0x800B, pewter_pokecenter_Move_Nurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, pewter_pokecenter_Move_Nurse_Return
	waitmovement 0
	special HealPlayerParty
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	applymovement VAR_0x800B, pewter_pokecenter_Move_Nurse_Bow
	waitmovement 0
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
	release
	end

pewter_pokecenter_EventScript_Nurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	waitmessage
	release
	end

pewter_pokecenter_Move_Nurse_Turn:
	face_left
	step_end

pewter_pokecenter_Move_Nurse_Return:
	face_down
	step_end

pewter_pokecenter_Move_Nurse_Bow:
	face_down
	delay_4
	step_end
pewter_pokecenter_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

pewter_pokecenter_Speaker_Mel:
	.string "Mel$"

pewter_pokecenter_Speaker_Toby:
	.string "Toby$"

pewter_pokecenter_EventScript_Beauty::
	lock
	faceplayer
	setspeaker pewter_pokecenter_Speaker_Mel
	msgbox pewter_pokecenter_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_pokecenter_EventScript_BugCatcher::
	lock
	faceplayer
	setspeaker pewter_pokecenter_Speaker_Toby
	msgbox pewter_pokecenter_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

pewter_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

pewter_pokecenter_Text_Beauty:
	.string "The NURSE here is the best.\p"
	.string "Everyone comes back from ROUTE 3\n"
	.string "tired and dusty.$"

pewter_pokecenter_Text_BugCatcher:
	.string "I wanted to see the MUSEUM, but they\n"
	.string "say it's still being fixed up.\p"
	.string "Guess I'll train my bugs in the city\n"
	.string "for now.$"
