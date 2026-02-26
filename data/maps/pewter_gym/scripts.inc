	.align 2
pewter_gym_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PewterGym_EventScript_OnEnter
    .byte 0

PewterGym_EventScript_OnEnter::
    setflag FLAG_HIDE_PEWTER_GYM_BROCK_BALL
    setflag FLAG_HIDE_PEWTER_GYM_BROCK_CROAGUNK
    goto_if_unset FLAG_BADGE09_GET, PewterGym_EventScript_OnEnter_End
    call PewterCity_Gym_EventScript_SetGymTrainers
PewterGym_EventScript_OnEnter_End::
    end

PewterGym_Speaker_Brock:
    .string "BROCK$"

PewterGym_Speaker_Jerry:
    .string "JERRY$"

PewterGym_Speaker_GymGuy:
    .string "Gym Guy$"

@ Local IDs from map.json:
@   1 = Brock
@   2 = Jerry
@   3 = Gym Guy
@   4 = Brock's Poke Ball
@   5 = Brock's Croagunk
.set LOCALID_BROCK,          1
.set LOCALID_JERRY,          2
.set LOCALID_GYM_GUY,        3
.set LOCALID_BROCK_BALL,     4
.set LOCALID_BROCK_CROAGUNK, 5


PewterCity_Gym_EventScript_Jerry::
    setspeaker PewterGym_Speaker_Jerry
    trainerbattle_single TRAINER_CAMPER_KANTO, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten, PewterCity_Gym_EventScript_Jerry_After
    end

PewterCity_Gym_EventScript_Jerry_After::
    setspeaker PewterGym_Speaker_Jerry
    msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
    closemessage
    releaseall
    end

PewterCity_Gym_EventScript_Brock::
    lock
    faceplayer
    setspeaker PewterGym_Speaker_Brock
    goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_Brock_Defeated

    msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
    call PewterCity_Gym_EventScript_Brock_CroagunkIntro
    turnobject LOCALID_BROCK, DIR_SOUTH
    msgbox PewterCity_Gym_Text_Brock_Apology, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_BROCK_KANTO, PewterCity_Gym_Text_Brock_WinLoss

    message PewterCity_Gym_Text_ReceivedBoulderBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare

    msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
    setflag FLAG_BADGE09_GET
    call PewterCity_Gym_EventScript_SetGymTrainers

    closemessage
    release
    end

PewterCity_Gym_EventScript_SetGymTrainers::
    settrainerflag TRAINER_CAMPER_KANTO
    return

PewterCity_Gym_EventScript_Brock_CroagunkIntro::
    clearflag FLAG_HIDE_PEWTER_GYM_BROCK_CROAGUNK
    addobject LOCALID_BROCK_CROAGUNK
    showobjectat LOCALID_BROCK_CROAGUNK, MAP_PEWTER_GYM
    playse SE_BALL_OPEN
    applymovement LOCALID_BROCK_CROAGUNK, PewterGym_Move_Croagunk_ExitBall
    waitmovement 0
    turnobject LOCALID_BROCK_CROAGUNK, DIR_SOUTH
    waitse
    playmoncry SPECIES_CROAGUNK, CRY_MODE_NORMAL
    waitmoncry

    turnobject LOCALID_BROCK, DIR_EAST
    msgbox PewterCity_Gym_Text_Brock_Croagunk, MSGBOX_DEFAULT

    applymovement LOCALID_BROCK_CROAGUNK, PewterGym_Move_Croagunk_ReturnBall
    waitmovement 0
    turnobject LOCALID_BROCK, DIR_SOUTH
    removeobject LOCALID_BROCK_CROAGUNK
    setflag FLAG_HIDE_PEWTER_GYM_BROCK_CROAGUNK
    return

PewterGym_Move_Croagunk_ExitBall:
    exit_pokeball
    step_end

PewterGym_Move_Croagunk_ReturnBall:
    enter_pokeball
    step_end

PewterCity_Gym_EventScript_Brock_Defeated::
    setspeaker PewterGym_Speaker_Brock
    msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_Gym_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ ============================
@ GYM GUIDE
@ ============================

PewterCity_Gym_EventScript_GymGuy::
    setspeaker PewterGym_Speaker_GymGuy
    goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymGuyAfter
    msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
    end

PewterCity_Gym_EventScript_GymGuyAfter::
    setspeaker PewterGym_Speaker_GymGuy
    msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
    end

@ ============================
@ GYM STATUES
@ ============================

PewterCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
    msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_SIGN
    releaseall
    end

PewterCity_Gym_EventScript_GymStatuePostVictory::
    msgbox PewterCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
    releaseall
    end


@ ============================
@ TEXT – BROCK / JERRY / GYM GUY
@ ============================

PewterCity_Gym_Text_Brock_Intro:
    .string "So you're the trainer WES\n"
    .string "mentioned.\p"
    .string "I'm BROCK, the PEWTER GYM LEADER.\p"
    .string "In times like these, we need trainers\n"
    .string "who won't back down.\p"
    .string "Show me you can stand strong against\n"
    .string "what CIPHER and ROCKET are planning.$"

PewterCity_Gym_Text_Brock_Croagunk:
    .string "Hey! I told you to stop doing that!$"

PewterCity_Gym_Text_Brock_Apology:
    .string "Sorry about that. Now, let's battle.$"

PewterCity_Gym_Text_Brock_WinLoss:
    .string "Your POKéMON's power and resolve\n"
    .string "broke right through my rock-solid\n"
    .string "defense…\p"
    .string "Looks like KANTO has another trainer\n"
    .string "ready to stand up to CIPHER.\p"
    .string "Take this BOULDERBADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
    .string "{PLAYER} received the BOULDERBADGE!$"

PewterCity_Gym_Text_Brock_FightDone:
    .string "The world is huge. There are\n"
    .string "many strong trainers out there.\p"
    .string "If you keep growing like this, you'll\n"
    .string "be ready for whatever CIPHER throws\l"
    .string "our way.\p"
    .string "Also, a bit off topic but the\n"
    .string "GYM GUY here seems to be from a\l"
    .string "different timeline.\p"
    .string "He keeps saying that BLUE defeated\n"
    .string "me before but I don't know\l"
    .string "who that is...$"

PewterCity_Gym_Text_CamperJerry_Seen:
    .string "The trainers in this GYM usually use\n"
    .string "rock-type POKéMON.\p"
    .string "We've been training for any threats.\p"
    .string "Battles here can go long.\n"
    .string "You ready for that?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
    .string "I… I still can't keep up…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
    .string "Hey, you! BROCK doesn't just test power.\n"
    .string "He's watching for trainers who won't\l"
    .string "run when CIPHER or ROCKET show up.$"

PewterCity_Gym_Text_Guide:
    .string "Yo! CHAMP in the making!\n"
    .string "KANTO's in a bad way right now.\p"
    .string "BROCK's still here holding the line.\n"
    .string "If you can match his resolve, you'll be\l"
    .string "a real contender.$"

PewterCity_Gym_Text_Guide_Win:
    .string "Yo! CHAMP in the making!\p"
    .string "The way you handled BROCK…\n"
    .string "that's the kind of strength KANTO\l"
    .string "needs right now.$"

PewterCity_Gym_Text_GymStatue:
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "RED, BLUE, WES$"

PewterCity_Gym_Text_GymStatuePlayerWon:
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "RED, BLUE, WES, {PLAYER}$"


PewterGym_Move_Croagunk_Appear:
    jump_in_place_down
    step_end
