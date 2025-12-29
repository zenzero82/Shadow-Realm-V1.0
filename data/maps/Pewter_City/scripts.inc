Pewter_City_MapScripts::
    .byte 0

@ ==============================
@ SPEAKER STRINGS
@ ==============================

PewterCity_Speaker_Unknown:
    .string "?$"

PewterCity_Speaker_Brock_Unknown:
    .string "?$"
PewterCity_Speaker_Wes_Unknown:
    .string "?$"

PewterCity_Speaker_Brock:
    .string "BROCK$"
PewterCity_Speaker_Wes:
    .string "WES$"

@ Random Pewter NPC names
PewterCity_Speaker_Clara:
    .string "Clara$"
PewterCity_Speaker_Hank:
    .string "Hank$"
PewterCity_Speaker_Mila:
    .string "Mila$"


@ --------------------
@ Signs / existing NPCs
@ --------------------

PewterCity_EventScript_CityEnter::
    setflag FLAG_VISITED_PEWTER_CITY
    end

PewterCity_EventScript_CitySign::
    msgbox PewterCity_Text_Sign, MSGBOX_NPC
    end

PewterCity_EventScript_GymSign::
    msgbox PewterCity_Text_GymSign, MSGBOX_NPC
    end

PewterCity_EventScript_MuseumSign::
    msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
    end

PewterCity_EventScript_MtMoonSign::
    msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
    end

PewterCity_EventScript_WelcomeSign::
    msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
    end

@ Example “random named” NPCs
PewterCity_EventScript_Woman::
    lock
    faceplayer
    setspeaker PewterCity_Speaker_Clara
    msgbox PewterCity_Text_Woman, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_Fatman::
    lock
    faceplayer
    setspeaker PewterCity_Speaker_Hank
    msgbox PewterCity_Text_Fatman, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_Kid::
    lock
    faceplayer
    setspeaker PewterCity_Speaker_Mila
    msgbox PewterCity_Text_Kid, MSGBOX_DEFAULT
    closemessage
    release
    end


PewterCity_Text_Sign:
    .string "PEWTER CITY\n"
    .string "A Stone Gray City$"

PewterCity_Text_GymSign:
    .string "PEWTER CITY POKEMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "The Rock Solid POKEMON Trainer$"

PewterCity_Text_MuseumSign:
    .string "There's a notice here...\p"
    .string "PEWTER MUSEUM OF SCIENCE is closed for\n"
    .string "renovations...$"

PewterCity_Text_MtMoonGiftShopSign:
    .string "There's a notice here...\p"
    .string "MT.MOON GIFT SHOP NOW OPEN!$"

PewterCity_Text_WelcomeSign:
    .string "WELCOME TO PEWTER CITY!$"

PewterCity_Text_Woman:
    .string "The city feels tense lately.\p"
    .string "People whisper about TEAM ROCKET again...\p"
    .string "If they're really back, I hope the GYM\n"
    .string "LEADER can keep PEWTER safe.$"

PewterCity_Text_Fatman:
    .string "I heard the road toward MT. MOON has had\n"
    .string "strange sightings at night...\p"
    .string "Not just wild Pokemon - something else.$"

PewterCity_Text_Kid:
    .string "My dad says the TV glitches like it's\n"
    .string "showing a different world.\p"
    .string "That sounds scary... but kinda cool too.$"


@ =====================================================
@ BROCK + WES INTRO SCENE AT PEWTER ENTRANCE
@ =====================================================
@ Coord event:
@   Trigger 0 -> PewterCity_EventScript_BrockWesTrigger0
@
@ Objects:
@   LOCALID 1 = Brock
@   LOCALID 2 = Wes
@
@ Flags (define in flags.h):
@   FLAG_PEWTER_BROCK_WES_SCENE_DONE
@   FLAG_HIDE_PEWTER_CITY_BROCK
@   FLAG_HIDE_PEWTER_CITY_WES

PewterCity_EventScript_BrockWesTrigger0::
    checkflag FLAG_PEWTER_BROCK_WES_SCENE_DONE
    goto_if_eq PewterCity_EventScript_BrockWesTrigger_Done

    lockall
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Move_Player_FaceUp
    waitmovement 0

    goto PewterCity_EventScript_BrockWesScene

PewterCity_EventScript_BrockWesTrigger_Done::
    end

@ ----------------------
@ Main Brock + Wes scene
@ ----------------------

PewterCity_EventScript_BrockWesScene::
    @ Before they introduce themselves: show "?" for both
    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_BrockWes_PrePlayer_Brock, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Wes_Unknown
    msgbox PewterCity_Text_BrockWes_PrePlayer_Wes, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_BrockWes_PrePlayer_Brock2, MSGBOX_DEFAULT
    closemessage

    playse SE_PIN
    applymovement 1, PewterCity_Move_Brock_Exclaim
    applymovement 2, PewterCity_Move_Wes_Exclaim
    waitmovement 0

    turnobject 1, DIR_SOUTH
    turnobject 2, DIR_SOUTH

    setspeaker PewterCity_Speaker_Wes_Unknown
    msgbox PewterCity_Text_Wes_SeePlayer, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_Brock_SeePlayer, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Wes_Unknown
    msgbox PewterCity_Text_Wes_Interrogate, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_Brock_TrustsPlayer, MSGBOX_DEFAULT
    closemessage

    @ Wes introduces himself here -> switch speaker to WES after this line
    setspeaker PewterCity_Speaker_Wes_Unknown
    msgbox PewterCity_Text_Wes_IntroName, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Wes
    msgbox PewterCity_Text_Wes_Backstory, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Wes
    msgbox PewterCity_Text_Wes_Challenge, MSGBOX_DEFAULT
    closemessage

    @ Brock introduces himself here -> switch speaker to BROCK after this line
    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_Brock_IntroName, MSGBOX_DEFAULT
    closemessage

    setspeaker PewterCity_Speaker_Brock
    msgbox PewterCity_Text_Brock_ToGym, MSGBOX_DEFAULT
    closemessage

    applymovement 1, PewterCity_Move_Brock_ToGym
    waitmovement 0
    setflag FLAG_HIDE_PEWTER_CITY_BROCK
    removeobject 1

    setspeaker PewterCity_Speaker_Wes
    msgbox PewterCity_Text_Wes_HeadOut, MSGBOX_DEFAULT
    closemessage

    applymovement 2, PewterCity_Move_Wes_Leave
    waitmovement 0
    setflag FLAG_HIDE_PEWTER_CITY_WES
    removeobject 2

    setflag FLAG_PEWTER_BROCK_WES_SCENE_DONE

    releaseall
    end


@ ---------------
@ Movements
@ ---------------

PewterCity_Move_Player_FaceUp:
    face_up
    step_end

PewterCity_Move_Brock_Exclaim:
    emote_exclamation_mark
    step_end

PewterCity_Move_Wes_Exclaim:
    emote_exclamation_mark
    step_end

PewterCity_Move_Brock_ToGym:
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

PewterCity_Move_Wes_Leave:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end


@ ---------------------
@ TEXT – Brock & Wes
@ ---------------------

PewterCity_Text_BrockWes_PrePlayer_Brock:
    .string "Team Rocket's activity in KANTO is\n"
    .string "getting worse by the day.\p"
    .string "Ever since PROF. OAK vanished, the\n"
    .string "League's been scrambling.$"

PewterCity_Text_BrockWes_PrePlayer_Wes:
    .string "And every time someone gets close to\n"
    .string "Cipher, the trail goes cold.$"

PewterCity_Text_BrockWes_PrePlayer_Brock2:
    .string "If Cipher and Rocket are working together...\p"
    .string "Then innocent Pokemon are the ones who\n"
    .string "pay the price.$"

PewterCity_Text_Wes_SeePlayer:
    .string "Hm?$"

PewterCity_Text_Brock_SeePlayer:
    .string "You there!$"

PewterCity_Text_Wes_Interrogate:
    .string "I haven't seen you around PEWTER.\p"
    .string "You with TEAM ROCKET... or Cipher?$"

PewterCity_Text_Brock_TrustsPlayer:
    .string "Answer carefully.\p"
    .string "Pokemon are already in enough danger.\p"
    .string "...\p"
    .string "I see.\p"
    .string "Sorry for the suspicion.\n"
    .string "These days, we can't be too careful.$"

PewterCity_Text_Wes_IntroName:
    .string "Name's WES.\p"
    .string "Used to run with TEAM SNAGEM.$"

PewterCity_Text_Wes_Backstory:
    .string "We helped steal Pokemon so Cipher could\n"
    .string "twist their hearts.\p"
    .string "I walked away from all that.\p"
    .string "Then one day, everything shifted.\p"
    .string "One battle, one explosion... and when I\n"
    .string "came to, I was here in KANTO.\p"
    .string "RED and a kid named MICHAEL helped me\n"
    .string "get my bearings.\p"
    .string "We set up a base near CERULEAN CITY to\n"
    .string "watch what Cipher and Rocket are doing.$"

PewterCity_Text_Wes_Challenge:
    .string "If you really want to help stop Cipher,\n"
    .string "I need to know you can handle yourself.\p"
    .string "PEWTER's GYM LEADER is strong.\n"
    .string "Beat him, and I'll take you seriously.\p"
    .string "Once you've earned his BADGE, find me\n"
    .string "at the hideout near CERULEAN.\p"
    .string "We'll talk about what comes next.$"

PewterCity_Text_Brock_IntroName:
    .string "I'm BROCK, PEWTER CITY's GYM LEADER.\p"
    .string "If you want to stand against Cipher,\n"
    .string "show me your resolve.$"

PewterCity_Text_Brock_ToGym:
    .string "I've battled RED, BLUE, and plenty of\n"
    .string "strong trainers.\p"
    .string "When you're ready, come to the GYM.\n"
    .string "I'll be waiting.$"

PewterCity_Text_Wes_HeadOut:
    .string "Don't keep me waiting, kid.\p"
    .string "Beat BROCK, then head for CERULEAN.\p"
    .string "If you can handle that, maybe we can\n"
    .string "fight Cipher together.$"


@ -------------------------------
@ EXTRA PEWTER NPCS CAN GO BELOW
@ -------------------------------
