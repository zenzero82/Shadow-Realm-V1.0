Viridian_City_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
    .byte 0

ViridianCity_EventScript_CityEnter::
    setflag FLAG_VISITED_VIRIDIAN_CITY
    @ Do NOT touch Gonzap here – his visibility is controlled
    @ by FLAG_HIDE_VIRIDIAN_GONZAP and the gym scene.
    end

ViridianCity_EventScript_Gramps::
    lock
    faceplayer
    msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
    msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_GrampsDoubted::
    msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
    closemessage
    release
    end

VirianCity_EventScript_GymGrampsBlue::
    msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
    end

ViridianCity_EventScript_Youngster::
    msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
    end

ViridianCity_EventScript_CitySign::
    msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
    end

ViridianCity_EventScript_CitySign2::
    msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
    end

ViridianCity_EventScript_GymSign::
    msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
    end

ViridianCity_Text_CoffeeGramps_Question:
    .string "Hey, kid! I just had a double shot\n"
    .string "of espresso, and I am wired!\p"
    .string "I need to talk to someone, so you'll\n"
    .string "have to do!\p"
    .string "I might not look like much now, but\n"
    .string "I was an expert at catching POKEMON.\p"
    .string "Do you believe me?$"

ViridianCity_Text_CoffeeGramps_Believed:
    .string "Good, good. Yes, I was something\n"
    .string "out of the ordinary, let me tell\l"
    .string "you!$"

ViridianCity_Text_CoffeeGramps_Doubted:
    .string "What? You little whelp!\p"
    .string "If I were just a bit younger, I'd\n"
    .string "show you a thing or two. Humph!$"

ViridianCity_Text_GrampsNearGym:
    .string "This GYM didn't have a LEADER\n"
    .string "until recently.\p"
    .string "A young man from PALLET became\n"
    .string "the LEADER, but he's often away.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
    .string "Are you going to battle the\n"
    .string "LEADER?\p"
    .string "Good luck to you. You'll need it.$"

ViridianCity_Text_DreamEaterFisherNew:
    .string "…Zzzzz…\p"
    .string "Yawn!\p"
    .string "I must have dozed off in the sun.\p"
    .string "What? I remind you of somebody?\p"
    .string "I don't know, here, have this.$"

ViridianCity_Text_DreamEaterFisher_GotTM::
    .string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
    .string "Yawn!\p"
    .string "I must have dozed off in the sun.\p"
    .string "…I had this dream about a DROWZEE\n"
    .string "eating my dream. Weird, huh?\p"
    .string "Huh? What's this?\p"
    .string "Where did this TM come from?\p"
    .string "This is spooky! Here, you can have\n"
    .string "this TM.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
    .string "TM42 contains DREAM EATER…\p"
    .string "…Zzzzz…$"

ViridianCity_Text_Youngster:
    .string "I heard that there are many items\n"
    .string "on the ground in VIRIDIAN FOREST.$"

ViridianCity_Text_Sign:
    .string "VIRIDIAN CITY\p"
    .string "The Eternally Green Paradise$"

ViridianCity_Text_GymSign:
    .string "VIRIDIAN CITY POKEMON GYM\n"
    .string "LEADER: …\p"
    .string "The rest of the text is illegible…$"

ViridianCity_Text_WelcomeSign:
    .string "WELCOME TO VIRIDIAN CITY,\p"
    .string "THE GATEWAY TO INDIGO PLATEAU$"

ViridianCity_Text_TrainerHouseSign:
    .string "TRAINER HOUSE\p"
    .string "The Club for Top Trainer Battles$"


@ =================================================
@ JESSIE & JAMES + MEOWTH AT ROUTE 1 ENTRANCE
@ =================================================

ViridianCity_EventScript_JJ_Trigger0::
    checkflag FLAG_VIRIDIAN_JJ_BATTLE_DONE
    goto_if_eq ViridianCity_EventScript_JJ_Trigger_Done

    lockall
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Move_Player_JJ_FromDown
    waitmovement 0
    goto ViridianCity_EventScript_JJ_Encounter

ViridianCity_EventScript_JJ_Trigger1::
    checkflag FLAG_VIRIDIAN_JJ_BATTLE_DONE
    goto_if_eq ViridianCity_EventScript_JJ_Trigger_Done

    lockall
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Move_Player_JJ_Stay
    waitmovement 0
    goto ViridianCity_EventScript_JJ_Encounter

ViridianCity_EventScript_JJ_Trigger_Done::
    end

ViridianCity_EventScript_JJ_Encounter::
    playse SE_PIN
    applymovement 1, ViridianCity_Move_Jessie_Exclaim
    waitmovement 0

    @ DIR_SOUTH = 1
    turnobject 1, 1
    turnobject 2, 1

    msgbox ViridianCity_Text_JJ_Intro, MSGBOX_DEFAULT
    closemessage

    trainerbattle_single TRAINER_JESSIE_AND_JAMES, ViridianCity_Text_JJ_BattleIntro, ViridianCity_Text_JJ_Defeated, ViridianCity_EventScript_JJ_AfterBattle
    end

ViridianCity_EventScript_HideJJGroup::
    setflag FLAG_HIDE_VIRIDIAN_JJ_GROUP
    removeobject 1      @ Jessie
    removeobject 2      @ James
    removeobject 3      @ Meowth
    return

ViridianCity_EventScript_JJ_AfterBattle::
    msgbox ViridianCity_Text_JJ_PostBattle, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_VIRIDIAN_JJ_BATTLE_DONE
    call ViridianCity_EventScript_HideJJGroup

    fadescreenswapbuffers FADE_TO_BLACK
    fadescreenswapbuffers FADE_FROM_BLACK
    releaseall
    end

@ ---- JJ Movements ----

ViridianCity_Move_Jessie_Exclaim:
    emote_exclamation_mark
    step_end

ViridianCity_Move_Player_JJ_FromDown:
    walk_up
    step_end

ViridianCity_Move_Player_JJ_Stay:
    step_end


@ =================================
@ VIRIDIAN GYM GRUNT & GONZAP
@ =================================

ViridianCity_EventScript_GymTrigger2::
    checkflag FLAG_VIRIDIAN_GONZAP_SCENE_DONE
    goto_if_eq ViridianCity_EventScript_Gym_Already

    lockall
    setvar VAR_0x8004, 0   @ Trigger 2
    goto ViridianCity_EventScript_GymScene

ViridianCity_EventScript_GymTrigger3::
    checkflag FLAG_VIRIDIAN_GONZAP_SCENE_DONE
    goto_if_eq ViridianCity_EventScript_Gym_Already

    lockall
    setvar VAR_0x8004, 1   @ Trigger 3
    goto ViridianCity_EventScript_GymScene

ViridianCity_EventScript_Gym_Already::
    lock
    faceplayer
    msgbox ViridianCity_Text_GymGrunt_After, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_GymScene::
    msgbox ViridianCity_Text_GymGrunt_Before, MSGBOX_DEFAULT
    closemessage

    playse SE_PIN
    applymovement 4, ViridianCity_Move_Grunt_Exclaim
    waitmovement 0

    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_Open_T2
    goto ViridianCity_GymScene_Open_T3

ViridianCity_GymScene_Open_T2::
    @ Trigger 2: grunt step right once to open door
    applymovement 4, ViridianCity_Move_Grunt_T2_Open
    goto ViridianCity_GymScene_SpawnGonzap

ViridianCity_GymScene_Open_T3::
    @ Trigger 3: grunt step left once to open door
    applymovement 4, ViridianCity_Move_Grunt_T3_Open
    goto ViridianCity_GymScene_SpawnGonzap

ViridianCity_GymScene_SpawnGonzap::
    waitmovement 0

    @ Gonzap starts hidden via FLAG_HIDE_VIRIDIAN_GONZAP on his object.
    @ As the door finishes opening, reveal him and have him step out.
    clearflag FLAG_HIDE_VIRIDIAN_GONZAP
    showobjectat 5, MAP_VIRIDIAN_CITY    @ LOCALID 5 = Gonzap
    applymovement 5, ViridianCity_Move_Gonzap_ExitGym
    waitmovement 0

    @ DIR_SOUTH = 1
    turnobject 5, 1
    msgbox ViridianCity_Text_Gonzap_Intro, MSGBOX_DEFAULT
    closemessage

    msgbox ViridianCity_Text_Gonzap_Threat, MSGBOX_DEFAULT
    closemessage

    @ Now grunt shifts further aside depending on which trigger
    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_Shift_T2
    goto ViridianCity_GymScene_Shift_T3

ViridianCity_GymScene_Shift_T2::
    @ Extra 4 steps right (total 5 from start), then Gonzap leaves via T2 path
    applymovement 4, ViridianCity_Move_Grunt_T2_Shift
    waitmovement 0
    applymovement 5, ViridianCity_Move_Gonzap_Leave_T2
    waitmovement 0
    goto ViridianCity_GymScene_AfterGonzap

ViridianCity_GymScene_Shift_T3::
    @ Extra 4 steps left (total 5 from start), then Gonzap leaves via T3 path
    applymovement 4, ViridianCity_Move_Grunt_T3_Shift
    waitmovement 0
    applymovement 5, ViridianCity_Move_Gonzap_Leave_T3
    waitmovement 0
    goto ViridianCity_GymScene_AfterGonzap

ViridianCity_GymScene_AfterGonzap::
    @ Make Gonzap gone for this visit and future reloads
    setflag FLAG_HIDE_VIRIDIAN_GONZAP
    removeobject 5

    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_GruntReturn_T2
    goto ViridianCity_GymScene_GruntReturn_T3

ViridianCity_GymScene_GruntReturn_T2::
    applymovement 4, ViridianCity_Move_Grunt_T2_Return
    waitmovement 0
    goto ViridianCity_GymScene_End

ViridianCity_GymScene_GruntReturn_T3::
    applymovement 4, ViridianCity_Move_Grunt_T3_Return
    waitmovement 0
    goto ViridianCity_GymScene_End

ViridianCity_GymScene_End::
    setflag FLAG_VIRIDIAN_GONZAP_SCENE_DONE
    releaseall
    end

ViridianCity_EventScript_GymGrunt_AfterScene::
    lock
    faceplayer
    msgbox ViridianCity_Text_GymGrunt_After, MSGBOX_DEFAULT
    closemessage
    release
    end


@ ---- Gym / Gonzap Movements ----

ViridianCity_Move_Grunt_Exclaim:
    emote_exclamation_mark
    step_end

@ Trigger 2: grunt step right once to open (then face toward door)
ViridianCity_Move_Grunt_T2_Open:
    walk_right
    face_left
    step_end

@ Trigger 3: grunt step left once to open (then face toward door)
ViridianCity_Move_Grunt_T3_Open:
    walk_left
    face_right
    step_end

@ Trigger 2: extra 4 tiles right before Gonzap walks off
ViridianCity_Move_Grunt_T2_Shift:
    walk_right
    walk_right
    walk_right
    walk_right
    face_left
    step_end

@ Trigger 3: extra 4 tiles left before Gonzap walks off
ViridianCity_Move_Grunt_T3_Shift:
    walk_left
    walk_left
    walk_left
    walk_left
    face_right
    step_end

@ Trigger 2 return: from shifted position, go left 5 & face down
ViridianCity_Move_Grunt_T2_Return:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    face_down
    step_end

@ Trigger 3 return: from shifted position, go right 5 & face down
ViridianCity_Move_Grunt_T3_Return:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    face_down
    step_end

@ Gonzap exits gym: two tiles down from doorway
ViridianCity_Move_Gonzap_ExitGym:
    walk_down
    walk_down
    step_end

@ Gonzap leave path – Trigger 2
@ right 4, up 6, left 9, down 2, left 4
ViridianCity_Move_Gonzap_Leave_T2:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

@ Gonzap leave path – Trigger 3
@ left 4, up 4, left 4
ViridianCity_Move_Gonzap_Leave_T3:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    step_end


@ ==================
@ TEXT – JJ & GONZAP
@ ==================

ViridianCity_Text_JJ_Intro:
    .string "JESSIE: Hold it right there!\p"
    .string "JAMES: This city is under new\n"
    .string "management, twerp.$"

ViridianCity_Text_JJ_BattleIntro:
    .string "JESSIE: We may be new to Team Rocket,\n"
    .string "but we have already perfected our work!\p"
    .string "JAMES: And you'll be our first\n"
    .string "demonstration.\p"
    .string "Prepare yourself!$"

ViridianCity_Text_JJ_Defeated:
    .string "JESSIE: How did we lose to a rookie?!\p"
    .string "JAMES: Even Meowth can't believe it...$"

ViridianCity_Text_JJ_PostBattle:
    .string "JESSIE: Hmph! Don't get used to this.\p"
    .string "JAMES: That darn OAK and his meddling\n"
    .string "research...\p"
    .string "Team Rocket will fix everything in\n"
    .string "our favor.\p"
    .string "JESSIE: Just you wait, twerp.$"

ViridianCity_Text_GymGrunt_Before:
    .string "TEAM ROCKET GRUNT: Scram, kid.\n"
    .string "The boss is in an intense meeting.$"

ViridianCity_Text_GymGrunt_After:
    .string "TEAM ROCKET GRUNT: The boss has no time\n"
    .string "for weaklings.\p"
    .string "Come back when this city actually belongs\n"
    .string "to the League again... if that ever\n"
    .string "happens.$"

ViridianCity_Text_Gonzap_Intro:
    .string "GONZAP: So this is the KANTO branch\n"
    .string "everyone's fussing over?\p"
    .string "You don't look like Rocket material,\n"
    .string "kid... but you've got some fight in you.$"

ViridianCity_Text_Gonzap_Threat:
    .string "GONZAP: Remember this face.\p"
    .string "When Shadow Pokemon start showing up in\n"
    .string "your League matches, you'll know who\l"
    .string "gave the order.\p"
    .string "Enjoy the calm while it lasts.$"


@ ================================
@ EXTRA VIRIDIAN CITY ROCKET GRUNTS
@ ================================

ViridianCity_EventScript_Grunt1::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt1, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt1:
    .string "This place used to be full of sleepy\n"
    .string "old timers and fresh faced kids.\p"
    .string "We cleared them out in one night.\n"
    .string "Now Viridian belongs to Team Rocket.$"

ViridianCity_EventScript_Grunt2::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt2, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt2:
    .string "Orders are simple: nobody in or out\n"
    .string "unless the boss says so.\p"
    .string "The League can whine all they want.\n"
    .string "They are not getting past us this time.$"

ViridianCity_EventScript_Grunt3::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt3, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt3:
    .string "You are wondering where everyone went?\p"
    .string "Some ran. Some were escorted out.\n"
    .string "A few are hiding in their houses.\p"
    .string "Smart ones stay out of our way.$"

ViridianCity_EventScript_Grunt4::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt4, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt4:
    .string "Giovanni is not the only one giving\n"
    .string "orders anymore.\p"
    .string "Big guys from other regions came in\n"
    .string "talking about shadow potential.\p"
    .string "I do not get it.\n"
    .string "I just follow the paycheck.$"

ViridianCity_EventScript_Grunt5::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt5, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt5:
    .string "There was a Gym here once.\n"
    .string "People lined up to battle.\p"
    .string "Now look at it.\n"
    .string "Locked down, guarded, off limits.\p"
    .string "Call it... a change in management.$"

ViridianCity_EventScript_Grunt6::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt6, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt6:
    .string "Keep walking, kid.\p"
    .string "If the boss wanted random trainers\n"
    .string "poking around, we would not be here.\p"
    .string "Go train on Route 2 or something.$"

ViridianCity_EventScript_Grunt7::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt7, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt7:
    .string "Heard a rumor that some Rocket labs\n"
    .string "are testing hearts of Pokemon.\p"
    .string "I do not ask questions.\n"
    .string "If you do, you do not last long.$"

ViridianCity_EventScript_Grunt8::
    lock
    faceplayer
    msgbox ViridianCity_Text_Grunt8, MSGBOX_NPC
    closemessage
    release
    end

ViridianCity_Text_Grunt8:
    .string "You look confused.\n"
    .string "Like you just dropped in from nowhere.\p"
    .string "Bad time to get lost in Kanto, kid.\n"
    .string "The world is changing, and not for you.$"
