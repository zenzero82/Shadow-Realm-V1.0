EventScript_UseSurf::
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_UseSurf_CheckBox
EventScript_UseSurf_AfterCheck:
	call EventScript_BufferFieldMoveUserName
	setfieldeffectargument 0, VAR_0x8006
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_UseSurf_CheckBox:
	goto_if_eq VAR_0x8005, TRUE, EventScript_UseSurf_AfterCheck
	goto EventScript_EndUseSurf
