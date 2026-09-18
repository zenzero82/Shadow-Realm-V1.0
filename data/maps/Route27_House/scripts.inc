Route27_House_MapScripts::
	.byte 0

Route27_House_EventScript_Smeargle::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
	waitmoncry
	release
	end
