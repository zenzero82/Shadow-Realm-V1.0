Viridian_City_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
    .byte 0

@ ==============================
@ SPEAKER DEFINITIONS (namebox)
@ ==============================

Viridian_Speaker_Gramps:
    .string "Old Man Dexter$"

Viridian_Speaker_Youngster:
    .string "Youngster Milo$"

Viridian_Speaker_OldMan_Exile:
    .string "Old Man Harlan$"

Viridian_Speaker_Jessie:
    .string "Jessie$"

Viridian_Speaker_James:
    .string "James$"

Viridian_Speaker_Meowth:
    .string "Meowth$"

Viridian_Speaker_Gonzap:
    .string "Gonzap$"

Viridian_Speaker_JJ_Unison:
    .string "Jessie&James$"

Viridian_Speaker_GymGrunt:
    .string "Grunt Slate$"

Viridian_Speaker_Grunt1:
    .string "Grunt Vex$"
Viridian_Speaker_Grunt2:
    .string "Grunt Rook$"
Viridian_Speaker_Grunt3:
    .string "Grunt Sable$"
Viridian_Speaker_Grunt4:
    .string "Grunt Kline$"
Viridian_Speaker_Grunt5:
    .string "Grunt Mako$"
Viridian_Speaker_Grunt6:
    .string "Grunt Cinder$"
Viridian_Speaker_Grunt7:
    .string "Grunt Warden$"
Viridian_Speaker_Grunt8:
    .string "Grunt Hex$"

@ ==============================
@ MAP ENTER
@ ==============================

ViridianCity_EventScript_CityEnter::
    setflag FLAG_VISITED_VIRIDIAN_CITY
    @ Do NOT touch Gonzap here – his visibility is controlled
    @ by FLAG_HIDE_VIRIDIAN_GONZAP and the gym scene.
    end

@ ==============================
@ ORIGINAL NPCS / SIGNS
@ ==============================

ViridianCity_EventScript_Gramps::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Gramps
    msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
    setspeaker Viridian_Speaker_Gramps
    msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_GrampsDoubted::
    setspeaker Viridian_Speaker_Gramps
    msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
    closemessage
    release
    end

VirianCity_EventScript_GymGrampsBlue::
    setspeaker Viridian_Speaker_Gramps
    msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_DEFAULT
    end

ViridianCity_EventScript_Youngster::
    setspeaker Viridian_Speaker_Youngster
    msgbox ViridianCity_Text_Youngster, MSGBOX_DEFAULT
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

@ ==============================
@ NEW NPC: Old Man driven out
@ (Assign this script to your new NPC object in Porymap)
@ ==============================

ViridianCity_EventScript_ExileOldMan::
    lock
    faceplayer
    setspeaker Viridian_Speaker_OldMan_Exile
    msgbox ViridianCity_Text_ExileOldMan, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_Text_ExileOldMan:
    .string "I lived here my whole life...\p"
    .string "Then Team Rocket rolled in and started\n"
    .string "kicking folks out like we were trash.\p"
    .string "My home? Gone.\n"
    .string "My neighbors? Hiding behind locked doors.\p"
    .string "If you're strong enough...\n"
    .string "please bring Viridian back.$"

@ ==============================
@ JESSIE & JAMES + MEOWTH
@ ==============================

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
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Move_Player_JJ_FaceNorth
    waitmovement 0
    goto ViridianCity_EventScript_JJ_Encounter

ViridianCity_EventScript_JJ_Trigger_Done::
    end

ViridianCity_EventScript_JJ_Talk::
    checkflag FLAG_VIRIDIAN_JJ_BATTLE_DONE
    goto_if_eq ViridianCity_EventScript_JJ_Trigger_Done
    lockall
    goto ViridianCity_EventScript_JJ_Encounter

ViridianCity_EventScript_JJ_Encounter::
    playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
    playse SE_PIN
    applymovement 1, ViridianCity_Move_Jessie_Exclaim
    applymovement 2, ViridianCity_Move_Jessie_Exclaim
    waitmovement 0

    setspeaker Viridian_Speaker_JJ_Unison
    msgbox ViridianCity_Text_JJ_BattleIntro, MSGBOX_DEFAULT
    closemessage
    trainerbattle_no_intro TRAINER_JJ_VIRIDIAN, ViridianCity_Text_JJ_Defeated
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Move_Player_JJ_FaceNorth
    waitmovement 0
    goto ViridianCity_EventScript_JJ_AfterBattle

ViridianCity_EventScript_HideJJGroup::
    setflag FLAG_HIDE_VIRIDIAN_JJ_GROUP
    removeobject 1      @ Jessie
    removeobject 2      @ James
    removeobject 3      @ Meowth
    return

ViridianCity_EventScript_JJ_AfterBattle::
    @ Split again for speaker correctness
    setspeaker Viridian_Speaker_Jessie
    msgbox ViridianCity_Text_Jessie_PostBattle, MSGBOX_DEFAULT
    closemessage

    setspeaker Viridian_Speaker_James
    msgbox ViridianCity_Text_James_PostBattle, MSGBOX_DEFAULT
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

ViridianCity_Move_Player_JJ_FaceNorth:
    face_up
    step_end

@ ==============================
@ VIRIDIAN GYM GRUNT & GONZAP
@ ==============================

ViridianCity_EventScript_GymTrigger2::
    checkflag FLAG_VIRIDIAN_GONZAP_SCENE_DONE
    goto_if_eq ViridianCity_GymTrigger_Done

    lockall
    setvar VAR_0x8004, 0   @ Trigger 2
    goto ViridianCity_EventScript_GymScene

ViridianCity_EventScript_GymTrigger3::
    checkflag FLAG_VIRIDIAN_GONZAP_SCENE_DONE
    goto_if_eq ViridianCity_GymTrigger_Done

    lockall
    setvar VAR_0x8004, 1   @ Trigger 3
    goto ViridianCity_EventScript_GymScene

ViridianCity_GymTrigger_Done::
    end

ViridianCity_EventScript_Gym_Already::
    lock
    faceplayer
    setspeaker Viridian_Speaker_GymGrunt
    msgbox ViridianCity_Text_GymGrunt_After, MSGBOX_DEFAULT
    closemessage
    release
    end

@ Your map object is pointing at this label, so it MUST exist:
ViridianCity_EventScript_GymGrunt_AfterScene::
    goto ViridianCity_EventScript_Gym_Already

ViridianCity_EventScript_GymScene::
    setspeaker Viridian_Speaker_GymGrunt
    msgbox ViridianCity_Text_GymGrunt_Before, MSGBOX_DEFAULT
    closemessage

    playse SE_PIN
    applymovement 4, ViridianCity_Move_Grunt_Exclaim
    waitmovement 0

    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_Open_T2
    goto ViridianCity_GymScene_Open_T3

ViridianCity_GymScene_Open_T2::
    applymovement 4, ViridianCity_Move_Grunt_T2_Open
    goto ViridianCity_GymScene_SpawnGonzap

ViridianCity_GymScene_Open_T3::
    applymovement 4, ViridianCity_Move_Grunt_T3_Open
    goto ViridianCity_GymScene_SpawnGonzap

ViridianCity_GymScene_SpawnGonzap::
    waitmovement 0

    clearflag FLAG_HIDE_VIRIDIAN_GONZAP
    showobjectat 5, MAP_VIRIDIAN_CITY    @ LOCALID 5 = Gonzap
    applymovement 5, ViridianCity_Move_Gonzap_ExitGym
    waitmovement 0

    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_FaceGonzap_T2
    goto ViridianCity_GymScene_FaceGonzap_T3

ViridianCity_GymScene_FaceGonzap_T2::
    turnobject 4, DIR_WEST
    turnobject 5, DIR_WEST
    turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
    goto ViridianCity_GymScene_Gonzap_Talk

ViridianCity_GymScene_FaceGonzap_T3::
    turnobject 4, DIR_EAST
    turnobject 5, DIR_EAST
    turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST

ViridianCity_GymScene_Gonzap_Talk::
    playbgm MUS_CIPHER_ENCOUNTER, FALSE
    setspeaker Viridian_Speaker_Gonzap
    msgbox ViridianCity_Text_Gonzap_Intro, MSGBOX_DEFAULT
    closemessage

    setspeaker Viridian_Speaker_Gonzap
    msgbox ViridianCity_Text_Gonzap_Threat, MSGBOX_DEFAULT
    closemessage

    compare VAR_0x8004, 0
    goto_if_eq ViridianCity_GymScene_Shift_T2
    goto ViridianCity_GymScene_Shift_T3

ViridianCity_GymScene_Shift_T2::
    applymovement 4, ViridianCity_Move_Grunt_T2_Shift
    waitmovement 0
    applymovement 5, ViridianCity_Move_Gonzap_Leave_T2
    waitmovement 0
    goto ViridianCity_GymScene_AfterGonzap

ViridianCity_GymScene_Shift_T3::
    applymovement 4, ViridianCity_Move_Grunt_T3_Shift
    waitmovement 0
    applymovement 5, ViridianCity_Move_Gonzap_Leave_T3
    waitmovement 0
    goto ViridianCity_GymScene_AfterGonzap

ViridianCity_GymScene_AfterGonzap::
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_VIRIDIAN_GONZAP
    removeobject 5
    fadescreenswapbuffers FADE_FROM_BLACK
    fadedefaultbgm

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

@ ---- Gym / Gonzap Movements ----

ViridianCity_Move_Grunt_Exclaim:
    emote_exclamation_mark
    step_end

ViridianCity_Move_Grunt_T2_Open:
    walk_right
    face_left
    step_end

ViridianCity_Move_Grunt_T3_Open:
    walk_left
    face_right
    step_end

ViridianCity_Move_Grunt_T2_Shift:
    walk_right
    walk_right
    walk_right
    walk_right
    face_left
    step_end

ViridianCity_Move_Grunt_T3_Shift:
    walk_left
    walk_left
    walk_left
    walk_left
    face_right
    step_end

ViridianCity_Move_Grunt_T2_Return:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    face_down
    step_end

ViridianCity_Move_Grunt_T3_Return:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    face_down
    step_end

ViridianCity_Move_Gonzap_ExitGym:
    walk_down
    walk_down
    step_end

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

@ ==============================
@ EXTRA ROCKET GRUNTS (namebox)
@ ==============================

ViridianCity_EventScript_Grunt1::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt1
    msgbox ViridianCity_Text_Grunt1, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt2::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt2
    msgbox ViridianCity_Text_Grunt2, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt3::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt3
    msgbox ViridianCity_Text_Grunt3, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt4::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt4
    msgbox ViridianCity_Text_Grunt4, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt5::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt5
    msgbox ViridianCity_Text_Grunt5, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt6::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt6
    msgbox ViridianCity_Text_Grunt6, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt7::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt7
    msgbox ViridianCity_Text_Grunt7, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Grunt8::
    lock
    faceplayer
    setspeaker Viridian_Speaker_Grunt8
    msgbox ViridianCity_Text_Grunt8, MSGBOX_DEFAULT
    closemessage
    release
    end

@ ==================
@ TEXT – ORIGINALS
@ (labels kept for linker)
@ ==================

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

@ ==================
@ TEXT – JJ & GONZAP + GRUNTS
@ (labels kept; content updated to remove name prefixes)
@ ==================

@ Old label kept, but now unused (we split into Jessie/James)
ViridianCity_Text_JJ_Intro:
    .string "Hold it right there!$"

ViridianCity_Text_Jessie_Intro:
    .string "Hold it right there!$"

ViridianCity_Text_James_Intro:
    .string "This city is under new\n"
    .string "management, twerp.$"

ViridianCity_Text_JJ_BattleIntro:
    .string "Prepare for trouble!\n"
    .string "And make it double!\p"
    .string "To protect the world from devastation!\n"
    .string "To unite all peoples within our nation!\p"
    .string "To denounce the evils of truth and love!\n"
    .string "To extend our reach to the stars above!\p"
    .string "Jessie!\n"
    .string "James!\p"
    .string "Team Rocket blasts off at the speed of\n"
    .string "light!\p"
    .string "Surrender now or prepare to fight!$"

ViridianCity_Text_JJ_BattleCue:
    .string "Surrender now or prepare to fight!$"

ViridianCity_Text_JJ_Defeated:
    .string "How did we lose to a twerp?!\p"
    .string "Maybe Meowth needs to convert.$"

@ Old label kept, but now unused (we split into Jessie/James)
ViridianCity_Text_JJ_PostBattle:
    .string "Just you wait, twerp.$"

ViridianCity_Text_James_PostBattle:
    .string "Hmph! Don't get used to this.$"

ViridianCity_Text_Jessie_PostBattle:
    .string "We're TEAM ROCKETS newest recruits,\n"
    .string "we can't go to the boss with a\l"
    .string "bad report already.\p"
    .string "We will get stronger and take\n"
    .string "you down!\p"
    .string "Just you wait, twerp.$"

ViridianCity_Text_GymGrunt_Before:
    .string "Scram, kid.\n"
    .string "The boss is in an intense meeting.$"

ViridianCity_Text_GymGrunt_After:
    .string "The boss has no time for\n"
    .string "weaklings like you, hahaha.$"

ViridianCity_Text_Gonzap_Intro:
    .string "So this is the KANTO branch\n"
    .string "everyone's fussing over?\p"
    .string "You don't look like Rocket material,\n"
    .string "kid... but you've got some fight in you.$"

ViridianCity_Text_Gonzap_Threat:
    .string "Remember this face.\p"
    .string "When Shadow Pokemon start showing up in\n"
    .string "your League matches, you'll know who\l"
    .string "gave the order.\p"
    .string "Enjoy the calm while it lasts.$"

ViridianCity_Text_Grunt1:
    .string "This place used to be full of sleepy\n"
    .string "old timers and fresh faced kids.\p"
    .string "We cleared them out in one night.\n"
    .string "Now Viridian belongs to TEAM ROCKET.$"

ViridianCity_Text_Grunt2:
    .string "Orders are simply this, nobody in or out\n"
    .string "unless the boss says so.$"

ViridianCity_Text_Grunt3:
    .string "You are wondering where everyone went?\p"
    .string "Some ran. Some were escorted out.\n"
    .string "A few are hiding in their houses.\p"
    .string "Smart ones stay out of our way.$"

ViridianCity_Text_Grunt4:
    .string "Big guys from other regions came in\n"
    .string "talking about shadow potential.\p"
    .string "I don't get it.\n"
    .string "I just follow the paycheck.$"

ViridianCity_Text_Grunt5:
    .string "There was a Gym here once.\n"
    .string "People lined up to battle.\p"
    .string "Now look at it.\n"
    .string "Locked down, guarded, off limits.\p"
    .string "Call it... a change in management.$"

ViridianCity_Text_Grunt6:
    .string "Keep walking, kid.\p"
    .string "If the boss wanted random trainers\n"
    .string "poking around, we would not be here.$"

ViridianCity_Text_Grunt7:
    .string "Heard a rumor that some ROCKET labs\n"
    .string "are testing hearts of Pokemon.\p"
    .string "Whatever that means.$"

ViridianCity_Text_Grunt8:
    .string "You look confused.\n"
    .string "Like you just dropped in from nowhere.\p"
    .string "Bad time to get lost in Kanto, kid.$"
