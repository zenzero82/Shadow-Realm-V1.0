pewter_pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, pewter_pokecenter_OnTransition
	.byte 0

pewter_pokecenter_EventScript_Nurse::
	lock
	faceplayer
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, pewter_pokecenter_EventScript_Nurse_Goodbye

	hidefollower 1
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
	setflag FLAG_QUEST_PEWTER_NPC_POKECENTER_BEAUTY
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_pokecenter_EventScript_BugCatcher::
	lock
	faceplayer
	setspeaker pewter_pokecenter_Speaker_Toby
	msgbox pewter_pokecenter_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_QUEST_PEWTER_NPC_POKECENTER_BUG_CATCHER
	call QuestJournal_EventScript_CheckPewterCityNPCs
	release
	end

pewter_pokecenter_OnTransition:
	setrespawn HEAL_LOCATION_PEWTER_CITY
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

pewter_pokecenter_Text_Beauty:
	.string "The NURSE here is the best.\p"
	.string "Everyone comes back from ROUTE 3\n"
	.string "tired and dusty.$"

pewter_pokecenter_Text_BugCatcher:
	.string "The MUSEUM is open again.\p"
	.string "I want to see the fossils after I\n"
	.string "heal up my bugs.$"

pewter_pokecenter_EventScript_Bookshelf1::
	msgbox pewter_pokecenter_Text_Bookshelf1, MSGBOX_SIGN
	end

pewter_pokecenter_EventScript_Bookshelf2::
	msgbox pewter_pokecenter_Text_Bookshelf2, MSGBOX_SIGN
	end

pewter_pokecenter_EventScript_WallMap::
	goto EventScript_RegionMap_Kanto

pewter_pokecenter_Text_Bookshelf1:
	.string "A MUSEUM guidebook on fossils.$"

pewter_pokecenter_Text_Bookshelf2:
	.string "Notes on ROUTE 3 trainers.$"
