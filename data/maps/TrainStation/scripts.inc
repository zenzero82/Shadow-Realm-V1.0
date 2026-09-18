TrainStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrainStation_OnTransition
	.byte 0

#define LOCALID_TRAIN_STATION_OFFICER 1
#define LOCALID_TRAIN_STATION_OLD_MAN 2
#define LOCALID_TRAIN_STATION_LASS    3

TrainStation_Speaker_Officer:
	.string "OFFICER REED$"

TrainStation_Speaker_OldMan:
	.string "MORTY$"

TrainStation_Speaker_Lass:
	.string "SARA$"

TrainStation_OnTransition:
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, TrainStation_OnTransition_ApplyCipherDisguise
	end

TrainStation_OnTransition_ApplyCipherDisguise:
	special Special_ApplyCipherDisguise
	end

TrainStation_EventScript_Officer::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, TrainStation_EventScript_Officer_Disguised
	setspeaker TrainStation_Speaker_Officer
	msgbox TrainStation_Text_Officer, MSGBOX_DEFAULT
	release
	end

TrainStation_EventScript_Officer_Disguised:
	setspeaker TrainStation_Speaker_Officer
	msgbox TrainStation_Text_Officer_Disguised, MSGBOX_DEFAULT
	release
	end

TrainStation_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, TrainStation_EventScript_OldMan_Disguised
	setspeaker TrainStation_Speaker_OldMan
	msgbox TrainStation_Text_OldMan, MSGBOX_DEFAULT
	release
	end

TrainStation_EventScript_OldMan_Disguised:
	setspeaker TrainStation_Speaker_OldMan
	msgbox TrainStation_Text_OldMan_Disguised, MSGBOX_DEFAULT
	release
	end

TrainStation_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_CIPHER_DISGUISE_ACTIVE, TrainStation_EventScript_Lass_Disguised
	setspeaker TrainStation_Speaker_Lass
	msgbox TrainStation_Text_Lass, MSGBOX_DEFAULT
	release
	end

TrainStation_EventScript_Lass_Disguised:
	setspeaker TrainStation_Speaker_Lass
	msgbox TrainStation_Text_Lass_Disguised, MSGBOX_DEFAULT
	release
	end

TrainStation_Text_Officer:
	.string "We have had reports of rough-looking\n"
	.string "men hanging around the platforms.\p"
	.string "Until I know what they're planning,\n"
	.string "I am watching everyone closely.$"

TrainStation_Text_Officer_Disguised:
	.string "That uniform answers enough questions.\p"
	.string "Stay away from the passengers.$"

TrainStation_Text_OldMan:
	.string "Goldenrod Station used to sound lively.\p"
	.string "Now people lower their voices whenever\n"
	.string "those black uniforms pass by.$"

TrainStation_Text_OldMan_Disguised:
	.string "I've seen enough trouble in my life\n"
	.string "to recognize it on sight.$"

TrainStation_Text_Lass:
	.string "I was excited to visit the station,\n"
	.string "but now it just feels tense.$"

TrainStation_Text_Lass_Disguised:
	.string "I knew those uniforms were bad news.\n"
	.string "Don't come near me.$"
