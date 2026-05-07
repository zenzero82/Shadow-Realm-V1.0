Saffron_City_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Saffron_City_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Saffron_City_OnFrame
	.byte 0

.set LOCALID_SAFFRON_CITY_EIN, 2
.set LOCALID_SAFFRON_CITY_GRUNT_1, 3
.set LOCALID_SAFFRON_CITY_GRUNT_2, 4
.set LOCALID_SAFFRON_CITY_GRUNT_3, 5
.set LOCALID_SAFFRON_CITY_GRUNT_4, 6
.set LOCALID_SAFFRON_CITY_GRUNT_5, 7
.set LOCALID_SAFFRON_CITY_LOOKER, 17
.set LOCALID_SAFFRON_CITY_BONSLY, 18
.set LOCALID_SAFFRON_CITY_SUPER_NERD, 19

Saffron_City_OnTransition::
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, Saffron_City_OnTransition_LookerSceneDone
	setvar VAR_TEMP_0, 0
	goto Saffron_City_OnTransition_Continue

Saffron_City_OnTransition_LookerSceneDone:
	setvar VAR_TEMP_0, 1
	setobjectmovementtype LOCALID_SAFFRON_CITY_GRUNT_1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SAFFRON_CITY_GRUNT_2, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SAFFRON_CITY_GRUNT_3, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SAFFRON_CITY_GRUNT_4, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SAFFRON_CITY_GRUNT_5, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SAFFRON_CITY_BONSLY, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_SAFFRON_CITY_BONSLY, 48, 27
	setobjectxy LOCALID_SAFFRON_CITY_BONSLY, 48, 27
Saffron_City_OnTransition_Continue:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setflag FLAG_VISITED_SAFFRON_CITY
	end

Saffron_City_OnFrame:
	map_script_2 VAR_TEMP_1, 0, SaffronCity_EventScript_CityEnterQuest
	.2byte 0

SaffronCity_EventScript_CityEnterQuest::
	setvar VAR_TEMP_1, 1
	checkflag FLAG_QUEST_SAFFRON_NPCS_STARTED
	goto_if_eq SaffronCity_EventScript_CityEnterQuest_End
	checkflag FLAG_QUEST_SAFFRON_NPCS_COMPLETED
	goto_if_eq SaffronCity_EventScript_CityEnterQuest_End
	lockall
	setflag FLAG_QUEST_SAFFRON_NPCS_STARTED
	call QuestJournal_EventScript_NewQuestAlert
	releaseall
SaffronCity_EventScript_CityEnterQuest_End:
	end

SaffronCity_EventScript_Looker::
	faceplayer
	setspeaker SaffronCity_Speaker_Looker
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, SaffronCity_EventScript_Looker_AfterScene
	msgbox SaffronCity_Text_LookerStealthRepeat, MSGBOX_NPC
	end

SaffronCity_EventScript_Looker_AfterScene::
	setspeaker SaffronCity_Speaker_Looker
	msgbox SaffronCity_Text_LookerLookAfterBonsly, MSGBOX_NPC
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FaceLeft
	waitmovement 0
	end

SaffronCity_EventScript_CipherPeon::
	faceplayer
	compare VAR_LAST_TALKED, LOCALID_SAFFRON_CITY_GRUNT_1
	goto_if_eq SaffronCity_EventScript_CipherPeon_1
	compare VAR_LAST_TALKED, LOCALID_SAFFRON_CITY_GRUNT_2
	goto_if_eq SaffronCity_EventScript_CipherPeon_2
	compare VAR_LAST_TALKED, LOCALID_SAFFRON_CITY_GRUNT_3
	goto_if_eq SaffronCity_EventScript_CipherPeon_3
	compare VAR_LAST_TALKED, LOCALID_SAFFRON_CITY_GRUNT_4
	goto_if_eq SaffronCity_EventScript_CipherPeon_4
	setspeaker SaffronCity_Speaker_CipherPeon5
	msgbox SaffronCity_Text_CipherPeon5, MSGBOX_NPC
	end

SaffronCity_EventScript_CipherPeon_1::
	setspeaker SaffronCity_Speaker_CipherPeon1
	msgbox SaffronCity_Text_CipherPeon1, MSGBOX_NPC
	end

SaffronCity_EventScript_CipherPeon_2::
	setspeaker SaffronCity_Speaker_CipherPeon2
	msgbox SaffronCity_Text_CipherPeon2, MSGBOX_NPC
	end

SaffronCity_EventScript_CipherPeon_3::
	setspeaker SaffronCity_Speaker_CipherPeon3
	msgbox SaffronCity_Text_CipherPeon3, MSGBOX_NPC
	end

SaffronCity_EventScript_CipherPeon_4::
	setspeaker SaffronCity_Speaker_CipherPeon4
	msgbox SaffronCity_Text_CipherPeon4, MSGBOX_NPC
	end

SaffronCity_EventScript_GymGuy::
	faceplayer
	setspeaker SaffronCity_Speaker_GymGuy
	msgbox SaffronCity_Text_GymGuy, MSGBOX_NPC
	end

SaffronCity_EventScript_BlackBelt::
	faceplayer
	setspeaker SaffronCity_Speaker_BlackBelt
	msgbox SaffronCity_Text_BlackBelt, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	faceplayer
	setspeaker SaffronCity_Speaker_Boy
	msgbox SaffronCity_Text_Boy, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	faceplayer
	setspeaker SaffronCity_Speaker_Lass
	msgbox SaffronCity_Text_Lass, MSGBOX_NPC
	end

SaffronCity_EventScript_Woman::
	faceplayer
	setspeaker SaffronCity_Speaker_Woman
	msgbox SaffronCity_Text_Woman, MSGBOX_NPC
	end

SaffronCity_EventScript_BugCatcher::
	faceplayer
	setspeaker SaffronCity_Speaker_BugCatcher
	msgbox SaffronCity_Text_BugCatcher, MSGBOX_NPC
	end

SaffronCity_EventScript_FatMan::
	faceplayer
	setspeaker SaffronCity_Speaker_FatMan
	msgbox SaffronCity_Text_FatMan, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	faceplayer
	setspeaker SaffronCity_Speaker_Youngster
	msgbox SaffronCity_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_EventScript_Hiker::
	faceplayer
	setspeaker SaffronCity_Speaker_Hiker
	msgbox SaffronCity_Text_Hiker, MSGBOX_NPC
	end

SaffronCity_EventScript_SuperNerd::
	faceplayer
	setspeaker SaffronCity_Speaker_SuperNerd
	goto_if_set FLAG_CELADON_LILLIE_JOINED, SaffronCity_EventScript_SuperNerd_AfterLillie
	msgbox SaffronCity_Text_SuperNerd, MSGBOX_NPC
	end

SaffronCity_EventScript_SuperNerdTrigger::
	goto_if_set FLAG_CELADON_LILLIE_JOINED, SaffronCity_EventScript_SuperNerdTrigger_Done
	lockall
	turnobject LOCALID_SAFFRON_CITY_SUPER_NERD, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker SaffronCity_Speaker_SuperNerd
	msgbox SaffronCity_Text_SuperNerd, MSGBOX_DEFAULT
	releaseall
	end

SaffronCity_EventScript_SuperNerdTrigger_Done::
	end

SaffronCity_EventScript_SuperNerd_AfterLillie::
	msgbox SaffronCity_Text_SuperNerd_AfterLillie, MSGBOX_NPC
	end

SaffronCity_EventScript_LookerSceneTrigger_Middle::
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, SaffronCity_EventScript_LookerSceneTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, SaffronCity_Movement_PlayerToLooker_Middle
	waitmovement 0
	goto SaffronCity_EventScript_LookerScene_Common

SaffronCity_EventScript_LookerSceneTrigger_Upper::
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, SaffronCity_EventScript_LookerSceneTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, SaffronCity_Movement_PlayerToLooker_Upper
	waitmovement 0
	goto SaffronCity_EventScript_LookerScene_Common

SaffronCity_EventScript_LookerSceneTrigger_Lower::
	goto_if_set FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE, SaffronCity_EventScript_LookerSceneTrigger_Done
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, SaffronCity_Movement_PlayerToLooker_Lower
	waitmovement 0

SaffronCity_EventScript_LookerScene_Common::
	applymovement LOCALID_SAFFRON_CITY_BONSLY, SaffronCity_Movement_BonslyToLooker
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker SaffronCity_Speaker_Looker
	msgbox SaffronCity_Text_LookerBonslyDecoy, MSGBOX_DEFAULT
	applymovement LOCALID_SAFFRON_CITY_BONSLY, SaffronCity_Movement_BonslyHideBehindPlayer
	waitmovement 0
	getobjectcurrentxy LOCALID_SAFFRON_CITY_BONSLY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_SAFFRON_CITY_BONSLY, VAR_0x8004, VAR_0x8005
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FaceRight
	waitmovement 0
	setspeaker SaffronCity_Speaker_Looker
	msgbox SaffronCity_Text_LookerStealthIntro, MSGBOX_DEFAULT
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SaffronCity_Movement_CameraToSilphCo
	waitmovement 0
	setspeaker SaffronCity_Speaker_EinUnknown
	msgbox SaffronCity_Text_EinOrders, MSGBOX_DEFAULT
	setspeaker SaffronCity_Speaker_Grunts
	msgbox SaffronCity_Text_GruntsYesSir, MSGBOX_DEFAULT
	opendoor 25, 30
	waitdooranim
	applymovement LOCALID_SAFFRON_CITY_EIN, SaffronCity_Movement_EinEnterSilphCo
	waitmovement 0
	setflag FLAG_HIDE_SAFFRON_CITY_EIN
	removeobject LOCALID_SAFFRON_CITY_EIN
	closedoor 25, 30
	waitdooranim
	applymovement LOCALID_SAFFRON_CITY_GRUNT_1, Common_Movement_FaceDown
	applymovement LOCALID_SAFFRON_CITY_GRUNT_2, Common_Movement_FaceDown
	applymovement LOCALID_SAFFRON_CITY_GRUNT_3, Common_Movement_FaceDown
	applymovement LOCALID_SAFFRON_CITY_GRUNT_4, Common_Movement_FaceDown
	applymovement LOCALID_SAFFRON_CITY_GRUNT_5, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_CAMERA, SaffronCity_Movement_CameraBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FaceRight
	waitmovement 0
	setspeaker SaffronCity_Speaker_Looker
	msgbox SaffronCity_Text_LookerGoldenrodWarning, MSGBOX_DEFAULT
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox SaffronCity_Text_BonslyTerrified, MSGBOX_DEFAULT
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FacePlayer
	waitmovement 0
	setspeaker SaffronCity_Speaker_Looker
	msgbox SaffronCity_Text_LookerLookAfterBonsly, MSGBOX_DEFAULT
	applymovement LOCALID_SAFFRON_CITY_LOOKER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_SAFFRON_CITY_BONSLY, Common_Movement_FaceLeft
	waitmovement 0
	getobjectcurrentxy LOCALID_SAFFRON_CITY_BONSLY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_SAFFRON_CITY_BONSLY, VAR_0x8004, VAR_0x8005
	setflag FLAG_SAFFRON_CITY_LOOKER_SCENE_DONE
	releaseall
	end

SaffronCity_EventScript_LookerSceneTrigger_Done::
	setvar VAR_TEMP_0, 1
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end


SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	goto EventScript_GimmighoulSignpost


SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end


SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_Movement_PlayerToLooker_Middle:
	walk_left
	walk_left
	face_left
	step_end

SaffronCity_Movement_PlayerToLooker_Upper:
	walk_down
	walk_left
	walk_left
	walk_left
	face_left
	step_end

SaffronCity_Movement_PlayerToLooker_Lower:
	walk_up
	walk_left
	walk_left
	walk_left
	face_left
	step_end

SaffronCity_Movement_BonslyToLooker:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_faster_right
	face_right
	step_end

SaffronCity_Movement_BonslyHideBehindPlayer:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

SaffronCity_Movement_EinEnterSilphCo:
	walk_up
	step_end

SaffronCity_Movement_CameraToSilphCo:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SaffronCity_Movement_CameraBackToPlayer:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SaffronCity_Speaker_Looker:
	.string "LOOKER$"

SaffronCity_Speaker_EinUnknown:
	.string "???$"

SaffronCity_Speaker_Grunts:
	.string "GRUNTS$"

SaffronCity_Speaker_CipherPeon1:
	.string "Peon Voss$"

SaffronCity_Speaker_CipherPeon2:
	.string "Peon Raze$"

SaffronCity_Speaker_CipherPeon3:
	.string "Peon Myka$"

SaffronCity_Speaker_CipherPeon4:
	.string "Peon Dren$"

SaffronCity_Speaker_CipherPeon5:
	.string "Peon Holt$"

SaffronCity_Speaker_GymGuy:
	.string "Gym Guy$"

SaffronCity_Speaker_BlackBelt:
	.string "Daichi$"

SaffronCity_Speaker_Boy:
	.string "Tobin$"

SaffronCity_Speaker_Lass:
	.string "Mina$"

SaffronCity_Speaker_Woman:
	.string "Celine$"

SaffronCity_Speaker_BugCatcher:
	.string "Ned$"

SaffronCity_Speaker_FatMan:
	.string "Harold$"

SaffronCity_Speaker_Youngster:
	.string "Nico$"

SaffronCity_Speaker_Hiker:
	.string "Bram$"

SaffronCity_Speaker_SuperNerd:
	.string "Miles$"

SaffronCity_Text_LookerBonslyDecoy:
	.string "What's this? A troubled\n"
	.string "POKéMON?\p"
	.string "Or are you a decoy!!$"

SaffronCity_Text_LookerStealthIntro:
	.string "Ah, you again.\p"
	.string "Cipher is up to no good.\n"
	.string "I am in stealth mode.\p"
	.string "You seen nothing!\p"
	.string "Take a look child,\n"
	.string "something peculiar is\l"
	.string "happening here.$"

SaffronCity_Text_EinOrders:
	.string "We have had countless\n"
	.string "interuptions by those\l"
	.string "darn kids!\p"
	.string "They can not mess with\n"
	.string "our plans any longer.\p"
	.string "I'm placing you all on\n"
	.string "watch.\p"
	.string "Do not let anyone that\n"
	.string "is unauthorized in this\l"
	.string "building.\p"
	.string "You got that!!$"

SaffronCity_Text_GruntsYesSir:
	.string "Yes Sir!$"

SaffronCity_Text_LookerGoldenrodWarning:
	.string "This is not the only\n"
	.string "problem.\p"
	.string "Rumors are they have\n"
	.string "infiltrated Goldenrod...\p"
	.string "We need your help.\p"
	.string "Leave this investigation\n"
	.string "to me for now.$"

SaffronCity_Text_LookerStealthRepeat:
	.string "Cipher is up to no good.\p"
	.string "I am in stealth mode.\n"
	.string "You seen nothing!$"

SaffronCity_Text_LookerLookAfterBonsly:
	.string "No worries, kid.\p"
	.string "I will look after the small\n"
	.string "creature.$"

SaffronCity_Text_BonslyTerrified:
	.string "BONSLY looks terrified.$"

SaffronCity_Text_CipherPeon1:
	.string "No one unauthorized gets\n"
	.string "inside SILPH CO.\p"
	.string "We're standing watch until\n"
	.string "the radio signal says\l"
	.string "otherwise.$"

SaffronCity_Text_CipherPeon2:
	.string "Orders are simple.\p"
	.string "Keep watch on SILPH CO and\n"
	.string "stop anyone who looks like\l"
	.string "trouble.$"

SaffronCity_Text_CipherPeon3:
	.string "We are not letting anyone\n"
	.string "through.\p"
	.string "Until Cipher gives the word,\n"
	.string "this building stays sealed.$"

SaffronCity_Text_CipherPeon4:
	.string "Stay back.\p"
	.string "SILPH CO is under Cipher\n"
	.string "control, and we are watching\l"
	.string "every approach.$"

SaffronCity_Text_CipherPeon5:
	.string "Nobody gets past us.\p"
	.string "We guard SILPH CO until the\n"
	.string "signal changes, and not one\l"
	.string "step sooner.$"

SaffronCity_Text_GymGuy:
	.string "SABRINA has been missing\n"
	.string "for quite some time.\p"
	.string "The GYM is closed.\n"
	.string "It hasn't felt right without\l"
	.string "her around.$"

SaffronCity_Text_BlackBelt:
	.string "We've closed the DOJO for\n"
	.string "now.\p"
	.string "With CIPHER around, we\n"
	.string "don't feel safe letting\l"
	.string "anyone inside.$"

SaffronCity_Text_Boy:
	.string "My mom told me to stay far\n"
	.string "away from SILPH CO.\p"
	.string "Those weird guards give me\n"
	.string "the creeps.$"

SaffronCity_Text_Lass:
	.string "The city feels tense...\p"
	.string "Even the MAGNET TRAIN\n"
	.string "being down feels connected\l"
	.string "to all this.$"

SaffronCity_Text_Woman:
	.string "I heard a strange broadcast\n"
	.string "on the radio last night.\p"
	.string "It mentioned GOLDENROD.\n"
	.string "That can't be good.$"

SaffronCity_Text_BugCatcher:
	.string "I wanted to check out\n"
	.string "SILPH CO., but those men\l"
	.string "blocked the door.$"

SaffronCity_Text_FatMan:
	.string "Business usually keeps this\n"
	.string "city moving.\p"
	.string "Now everyone is whispering\n"
	.string "about CIPHER and the radio.$"

SaffronCity_Text_Youngster:
	.string "The guards said they were\n"
	.string "waiting for orders from\l"
	.string "the radio tower.\p"
	.string "Which radio tower do they\n"
	.string "mean?$"

SaffronCity_Text_Hiker:
	.string "I came to ride the MAGNET\n"
	.string "TRAIN, but it's still down.\p"
	.string "Guess I'm walking back.$"

SaffronCity_Text_SuperNerd:
	.string "Wait! I dropped some TCG\n"
	.string "cards all over the floor on\l"
	.string "my way in for VERMILION\l"
	.string "CITY.\p"
	.string "I don't want them to get\n"
	.string "messed up in case I got some\l"
	.string "PSA 10's!\p"
	.string "Sorry but you can't go this\n"
	.string "way yet.$"

SaffronCity_Text_SuperNerd_AfterLillie:
	.string "I found all my cards,\n"
	.string "sadly they are all scuffed.\p"
	.string "There goes my chances of\n"
	.string "getting rich...$"


SaffronCity_Text_Sign:
	.string "SAFFRON CITY\p"
	.string "Shining, Golden Land of Commerce$"


SaffronCity_Text_GymSign:
	.string "SAFFRON CITY\n"
	.string "POKéMON GYM\l"
	.string "LEADER: SABRINA\p"
	.string "The Master of Psychic POKéMON!$"


SaffronCity_Text_FightingDojoSign:
	.string "Everyone Welcome!\n"
	.string "FIGHTING DOJO$"


SaffronCity_Text_SilphCoSign:
	.string "SILPH CO.\n"
	.string "OFFICE BUILDING$"


SaffronCity_Text_MrPsychicHouseSign:
	.string "MR.PSYCHIC'S\n"
	.string "HOUSE$"


SaffronCity_Text_MagnetTrainStationSign:
	.string "SAFFRON CITY\n"
	.string "MAGNET TRAIN STATION$"
