	.align 2
pewter_gym_MapScripts::
    .byte 0

@ ============================
@ JERRY (GYM TRAINER)
@ ============================

PewterCity_Gym_EventScript_Jerry::
    trainerbattle_single TRAINER_CAMPER_KANTO, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
    msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
    end

@ ============================
@ BROCK – REAL GYM BATTLE
@ ============================

PewterCity_Gym_EventScript_Brock::
    lock
    faceplayer
    @ If Boulder Badge (Kanto) already obtained, skip straight to “after” text
    goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_Brock_Defeated

    msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT

    @ Actual gym battle: uses your TRAINER_BROCK_KANTO
    trainerbattle_no_intro TRAINER_BROCK_KANTO, PewterCity_Gym_Text_Brock_WinLoss

    @ Give Boulder Badge + fanfare
    message PewterCity_Gym_Text_ReceivedBoulderBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare

    @ Post-battle story text
    msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT

    @ Mark Boulder Badge as obtained – this is also our “gym cleared” flag
    setflag FLAG_BADGE09_GET

    closemessage
    release
    end

PewterCity_Gym_EventScript_Brock_Defeated::
    @ Called if FLAG_BADGE09_GET is already set
    msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
    closemessage
    release
    end

@ ============================
@ GYM GUIDE
@ ============================

PewterCity_Gym_EventScript_GymGuy::
    goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymGuyAfter
    msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
    end

PewterCity_Gym_EventScript_GymGuyAfter::
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
    .string "BROCK: So you're the trainer WES\n"
    .string "mentioned.\p"
    .string "I'm BROCK, the PEWTER GYM LEADER.\p"
    .string "In times like these, we need trainers\n"
    .string "who won't back down.\p"
    .string "Show me you can stand strong against\n"
    .string "what CIPHER and ROCKET are planning.$"

PewterCity_Gym_Text_Brock_WinLoss:
    .string "BROCK: Your POKEMON's power and resolve\n"
    .string "broke right through my rock-solid\n"
    .string "defense…\p"
    .string "Looks like KANTO has another trainer\n"
    .string "ready to stand up to CIPHER.\p"
    .string "Take this BOULDERBADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
    .string "{PLAYER} received the BOULDERBADGE!$"

PewterCity_Gym_Text_Brock_FightDone:
    .string "BROCK: The world is huge. There are\n"
    .string "many strong trainers out there.\p"
    .string "If you keep growing like this, you'll\n"
    .string "be ready for whatever CIPHER throws\n"
    .string "at this region.$"

PewterCity_Gym_Text_CamperJerry_Seen:
    .string "The trainers in this GYM usually use\n"
    .string "rock-type POKEMON.\p"
    .string "But lately, we've been training for\n"
    .string "stranger threats.\p"
    .string "Battles here can go long.\n"
    .string "You ready for that?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
    .string "I… I still can't keep up…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
    .string "Hey, you! BROCK doesn't just test power.\n"
    .string "He's watching for trainers who won't\l"
    .string "run when CIPHER or ROCKET show up.$"

PewterCity_Gym_Text_Guide:
    .string "Yo! CHAMP in the making!\p"
    .string "ROCKET in VIRIDIAN, portals, CIPHER…\n"
    .string "KANTO's in a bad way right now.\p"
    .string "BROCK's still here holding the line.\n"
    .string "If you can match his resolve, you'll be\n"
    .string "a real contender.$"

PewterCity_Gym_Text_Guide_Win:
    .string "Yo! CHAMP in the making!\p"
    .string "The way you handled BROCK…\n"
    .string "that's the kind of strength KANTO\l"
    .string "needs right now.$"

PewterCity_Gym_Text_GymStatue:
    .string "PEWTER POKEMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "RED, BLUE$"

PewterCity_Gym_Text_GymStatuePlayerWon:
    .string "PEWTER POKEMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "RED, BLUE, {PLAYER}$"
