@ =================================================
@ CERULEAN CITY (Shadow Realm storyline version)
@ - Based on HNS structure
@ - Removed / stubbed Slowbro + woman scene (since you don't have those objects yet)
@ - Dialogue updated: Rocket + Cipher + "Team Snagem" rumors
@ - Keeps the same overall event script names so you can wire easily in Porymap
@ =================================================

Cerulean_City_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
    .byte 0

CeruleanCity_EventScript_CityEnter::
    setflag FLAG_VISITED_CERULEAN_CITY
    end

@ =================================================
@ LOCAL IDS
@ =================================================

#define LOCALID_MISTY 1
#define LOCALID_MICHAEL 2

@ =================================================
@ SPEAKER DEFINITIONS
@ =================================================

CeruleanCity_Speaker_Misty:
    .string "MISTY$"

CeruleanCity_Speaker_Michael:
    .string "MICHAEL$"

CeruleanCity_Speaker_CooltrainerM:
    .string "DARREN$"

CeruleanCity_Speaker_Boy:
    .string "KYLE$"

CeruleanCity_Speaker_Guard:
    .string "GARRETT$"

CeruleanCity_Speaker_Slowbro:
    .string "SLOWBRO$"

CeruleanCity_Speaker_SlowbroWoman:
    .string "TRINA$"

CeruleanCity_Speaker_Fisher:
    .string "HANK$"

CeruleanCity_Speaker_Youngster:
    .string "JOSH$"

CeruleanCity_Speaker_BugCatcher:
    .string "LEO$"

CeruleanCity_Speaker_Boy2:
    .string "NICK$"

CeruleanCity_Speaker_RocketGruntF:
    .string "ROCKET$"

CeruleanCity_Speaker_RocketGruntM:
    .string "ROCKET$"

CeruleanCity_Speaker_PlasmaGruntF:
    .string "PLASMA$"

CeruleanCity_Speaker_PlasmaGruntM:
    .string "PLASMA$"

CeruleanCity_Speaker_Policeman1:
    .string "OFFICER$"

CeruleanCity_Speaker_Policeman2:
    .string "OFFICER$"

@ =================================================
@ MISTY + MICHAEL SCENE
@ =================================================

CeruleanCity_EventScript_Misty::
    lockall
    checkflag FLAG_CERULEAN_MISTY_MICHAEL_SCENE_DONE
    goto_if_eq CeruleanCity_EventScript_Misty_After
    setvar VAR_0x8004, 4
    goto CeruleanCity_EventScript_MistyMichael_Scene

CeruleanCity_EventScript_Michael::
    lockall
    checkflag FLAG_CERULEAN_MISTY_MICHAEL_SCENE_DONE
    goto_if_eq CeruleanCity_EventScript_Michael_After
    setvar VAR_0x8004, 4
    goto CeruleanCity_EventScript_MistyMichael_Scene

CeruleanCity_EventScript_MistyMichael_Trigger_West_North::
    setvar VAR_0x8004, 0
    goto CeruleanCity_EventScript_MistyMichael_Trigger

CeruleanCity_EventScript_MistyMichael_Trigger_West_South::
    setvar VAR_0x8004, 1
    goto CeruleanCity_EventScript_MistyMichael_Trigger

CeruleanCity_EventScript_MistyMichael_Trigger_East_North::
    setvar VAR_0x8004, 2
    goto CeruleanCity_EventScript_MistyMichael_Trigger

CeruleanCity_EventScript_MistyMichael_Trigger_East_South::
    setvar VAR_0x8004, 3
    goto CeruleanCity_EventScript_MistyMichael_Trigger

CeruleanCity_EventScript_MistyMichael_Trigger_South::
    setvar VAR_0x8004, 4
    goto CeruleanCity_EventScript_MistyMichael_Trigger

CeruleanCity_EventScript_MistyMichael_Trigger::
    lockall
    checkflag FLAG_CERULEAN_MISTY_MICHAEL_SCENE_DONE
    goto_if_eq CeruleanCity_EventScript_MistyMichael_Trigger_End
    goto CeruleanCity_EventScript_MistyMichael_Scene

CeruleanCity_EventScript_MistyMichael_Trigger_End::
    releaseall
    end

CeruleanCity_EventScript_MistyMichael_Scene::
    call CeruleanCity_EventScript_MistyMichael_FaceFromTrigger
    setspeaker CeruleanCity_Speaker_Misty
    msgbox CeruleanCity_Text_Misty_Argue, MSGBOX_NPC
    closemessage
    setspeaker CeruleanCity_Speaker_Michael
    msgbox CeruleanCity_Text_Michael_Argue, MSGBOX_NPC
    closemessage
    playse SE_PIN
    applymovement LOCALID_MISTY, Common_Movement_ExclamationMark
    applymovement LOCALID_MICHAEL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_MISTY, Common_Movement_FacePlayer
    applymovement LOCALID_MICHAEL, Common_Movement_FacePlayer
    waitmovement 0
    setspeaker CeruleanCity_Speaker_Michael
    msgbox CeruleanCity_Text_Michael_Player, MSGBOX_NPC
    closemessage
    turnobject LOCALID_MICHAEL, DIR_NORTH
    turnobject LOCALID_MISTY, DIR_SOUTH
    setspeaker CeruleanCity_Speaker_Michael
    msgbox CeruleanCity_Text_Michael_ToMisty, MSGBOX_NPC
    closemessage
    fadescreen FADE_TO_BLACK
    setflag FLAG_HIDE_CERULEAN_MICHAEL
    hideobjectat LOCALID_MICHAEL, MAP_CERULEAN_CITY
    removeobject LOCALID_MICHAEL
    fadescreen FADE_FROM_BLACK
    call CeruleanCity_EventScript_PlayerWalkToMistyFromTrigger
    applymovement LOCALID_MISTY, Common_Movement_FacePlayer
    waitmovement 0
    setspeaker CeruleanCity_Speaker_Misty
    msgbox CeruleanCity_Text_Misty_AfterScene, MSGBOX_NPC
    closemessage
    setflag FLAG_CERULEAN_MISTY_MICHAEL_SCENE_DONE
    releaseall
    end

CeruleanCity_EventScript_Misty_After::
    checkflag FLAG_HAS_SNAG_MACHINE
    goto_if_eq CeruleanCity_EventScript_Misty_Hide
    faceplayer
    setspeaker CeruleanCity_Speaker_Misty
    msgbox CeruleanCity_Text_Misty_Repeat, MSGBOX_NPC
    closemessage
    releaseall
    end

CeruleanCity_EventScript_Misty_Hide::
    setflag FLAG_HIDE_CERULEAN_MISTY
    hideobjectat LOCALID_MISTY, MAP_CERULEAN_CITY
    removeobject LOCALID_MISTY
    releaseall
    end

CeruleanCity_EventScript_Michael_After::
    faceplayer
    setspeaker CeruleanCity_Speaker_Michael
    msgbox CeruleanCity_Text_Michael_Repeat, MSGBOX_NPC
    closemessage
    releaseall
    end

CeruleanCity_EventScript_MistyMichael_FaceFromTrigger::
    compare VAR_0x8004, 0
    goto_if_eq CeruleanCity_EventScript_MistyMichael_FaceWest
    compare VAR_0x8004, 1
    goto_if_eq CeruleanCity_EventScript_MistyMichael_FaceWest
    compare VAR_0x8004, 2
    goto_if_eq CeruleanCity_EventScript_MistyMichael_FaceEast
    compare VAR_0x8004, 3
    goto_if_eq CeruleanCity_EventScript_MistyMichael_FaceEast
    goto CeruleanCity_EventScript_MistyMichael_FaceSouth

CeruleanCity_EventScript_MistyMichael_FaceWest::
    turnobject LOCALID_MISTY, DIR_WEST
    turnobject LOCALID_MICHAEL, DIR_WEST
    return

CeruleanCity_EventScript_MistyMichael_FaceEast::
    turnobject LOCALID_MISTY, DIR_EAST
    turnobject LOCALID_MICHAEL, DIR_EAST
    return

CeruleanCity_EventScript_MistyMichael_FaceSouth::
    turnobject LOCALID_MISTY, DIR_SOUTH
    turnobject LOCALID_MICHAEL, DIR_SOUTH
    return

CeruleanCity_EventScript_PlayerWalkToMistyFromTrigger::
    compare VAR_0x8004, 0
    goto_if_eq CeruleanCity_EventScript_PlayerWalkToMisty_WestNorth
    compare VAR_0x8004, 1
    goto_if_eq CeruleanCity_EventScript_PlayerWalkToMisty_WestSouth
    compare VAR_0x8004, 2
    goto_if_eq CeruleanCity_EventScript_PlayerWalkToMisty_EastNorth
    compare VAR_0x8004, 3
    goto_if_eq CeruleanCity_EventScript_PlayerWalkToMisty_EastSouth
    goto CeruleanCity_EventScript_PlayerWalkToMisty_South

CeruleanCity_EventScript_PlayerWalkToMisty_WestNorth::
    applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerToMisty_WestNorth
    waitmovement 0
    return

CeruleanCity_EventScript_PlayerWalkToMisty_WestSouth::
    applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerToMisty_WestSouth
    waitmovement 0
    return

CeruleanCity_EventScript_PlayerWalkToMisty_EastNorth::
    applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerToMisty_EastNorth
    waitmovement 0
    return

CeruleanCity_EventScript_PlayerWalkToMisty_EastSouth::
    applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerToMisty_EastSouth
    waitmovement 0
    return

CeruleanCity_EventScript_PlayerWalkToMisty_South::
    applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerToMisty_South
    waitmovement 0
    return

CeruleanCity_Movement_PlayerToMisty_WestNorth:
    walk_down
    walk_down
    walk_right
    walk_up
    step_end

CeruleanCity_Movement_PlayerToMisty_WestSouth:
    walk_down
    walk_right
    walk_up
    step_end

CeruleanCity_Movement_PlayerToMisty_EastNorth:
    walk_down
    walk_down
    walk_left
    walk_up
    step_end

CeruleanCity_Movement_PlayerToMisty_EastSouth:
    walk_down
    walk_left
    walk_up
    step_end

CeruleanCity_Movement_PlayerToMisty_South:
    walk_up
    step_end


@ =================================================
@ NPC: Cooltrainer M (Power Plant info becomes "odd activity east")
@ =================================================

CeruleanCity_EventScript_CooltrainerM1::
    @ If you still have FLAG_RETURNED_MACHINE_PART in your project, keep this.
    @ Otherwise, swap it to your own story flag (or remove the goto_if_set block).
    @goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
    setspeaker CeruleanCity_Speaker_CooltrainerM
    msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
    end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
    setspeaker CeruleanCity_Speaker_CooltrainerM
    msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
    end


@ =================================================
@ NPC: Super Nerd / Boy (Cape becomes "reports + hidden entrance rumors")
@ =================================================

CeruleanCity_EventScript_Boy::
    setspeaker CeruleanCity_Speaker_Boy
    msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
    end


@ =================================================
@ NPC: Guard at Cerulean Cave (story-appropriate warning)
@ =================================================

CeruleanCity_EventScript_Guard::
    setspeaker CeruleanCity_Speaker_Guard
    msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
    end


@ =================================================
@ REMOVED (for now): Slowbro + Woman scripts
@ You said you don't have the pokemon objects right now.
@ If any object in Porymap is still pointing at these, you can:
@   - change that object’s script to a generic NPC script
@   - or keep these stubs so it still compiles safely
@ =================================================

CeruleanCity_EventScript_Slowbro::
    setspeaker CeruleanCity_Speaker_Slowbro
    msgbox CeruleanCity_Text_Slowbro_Stub, MSGBOX_NPC
    end

CeruleanCity_EventScript_SlowbroWoman::
    setspeaker CeruleanCity_Speaker_SlowbroWoman
    msgbox CeruleanCity_Text_SlowbroWoman_Stub, MSGBOX_NPC
    end


@ =================================================
@ NPC: Fisher (Rocket tip -> Cipher/Rocket “men in black” tip)
@ =================================================

CeruleanCity_EventScript_Fisher::
    @ If you use VAR_CERULEAN_CITY_STATE in your project, keep this.
    @ Otherwise remove the goto_if_eq and just show the normal text.
    @goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
    setspeaker CeruleanCity_Speaker_Fisher
    msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
    end

CeruleanCity_EventScript_FisherDuringRocket::
    setspeaker CeruleanCity_Speaker_Fisher
    msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
    end


@ =================================================
@ NPC: Youngster (leans into "shadow rumors")
@ =================================================

CeruleanCity_EventScript_Youngster::
    setspeaker CeruleanCity_Speaker_Youngster
    msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
    end


@ =================================================
@ NPCs: Additional story stubs
@ =================================================

CeruleanCity_EventScript_BugCatcher::
    setspeaker CeruleanCity_Speaker_BugCatcher
    msgbox CeruleanCity_Text_BugCatcher, MSGBOX_NPC
    end

CeruleanCity_EventScript_Boy2::
    setspeaker CeruleanCity_Speaker_Boy2
    msgbox CeruleanCity_Text_Boy2, MSGBOX_NPC
    end

CeruleanCity_EventScript_RocketGruntF::
    setspeaker CeruleanCity_Speaker_RocketGruntF
    msgbox CeruleanCity_Text_RocketGruntF, MSGBOX_NPC
    end

CeruleanCity_EventScript_RocketGruntM::
    setspeaker CeruleanCity_Speaker_RocketGruntM
    msgbox CeruleanCity_Text_RocketGruntM, MSGBOX_NPC
    end

CeruleanCity_EventScript_PlasmaGruntF::
    setspeaker CeruleanCity_Speaker_PlasmaGruntF
    msgbox CeruleanCity_Text_PlasmaGruntF, MSGBOX_NPC
    end

CeruleanCity_EventScript_PlasmaGruntM::
    setspeaker CeruleanCity_Speaker_PlasmaGruntM
    msgbox CeruleanCity_Text_PlasmaGruntM, MSGBOX_NPC
    end

CeruleanCity_EventScript_Policeman1::
    setspeaker CeruleanCity_Speaker_Policeman1
    msgbox CeruleanCity_Text_Policeman1, MSGBOX_NPC
    end

CeruleanCity_EventScript_Policeman2::
    setspeaker CeruleanCity_Speaker_Policeman2
    msgbox CeruleanCity_Text_Policeman2, MSGBOX_NPC
    end

CeruleanCity_EventScript_Light::
    msgbox CeruleanCity_Text_Light, MSGBOX_SIGN
    end


@ =================================================
@ Pokemon: Cry scripts
@ =================================================

CeruleanCity_EventScript_Pokemon_Koffing::
    lock
    faceplayer
    playmoncry SPECIES_KOFFING, CRY_MODE_NORMAL
    waitmoncry
    release
    end

CeruleanCity_EventScript_Pokemon_Grimer::
    lock
    faceplayer
    playmoncry SPECIES_GRIMER, CRY_MODE_NORMAL
    waitmoncry
    release
    end

CeruleanCity_EventScript_Pokemon_Trubbish::
    lock
    faceplayer
    playmoncry SPECIES_TRUBBISH, CRY_MODE_NORMAL
    waitmoncry
    release
    end

CeruleanCity_EventScript_Pokemon_Scraggy::
    lock
    faceplayer
    playmoncry SPECIES_SCRAGGY, CRY_MODE_NORMAL
    waitmoncry
    release
    end

CeruleanCity_EventScript_Pokemon_Slowpoke::
    lock
    faceplayer
    playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
    waitmoncry
    release
    end

CeruleanCity_EventScript_Pokemon_Diglett::
    lock
    faceplayer
    playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
    waitmoncry
    release
    end


@ =================================================
@ Signs (unchanged, slight tone tweaks if you want)
@ =================================================

CeruleanCity_EventScript_Sign::
    msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_GymSign::
    msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_BikeShopSign::
    msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_PoliceSign::
    msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_CapeSign::
    msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
    end


@ =================================================
@ TEXT (Shadow Realm storyline)
@ =================================================

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "This is CERULEAN CAVE.\p"
    .string "Strong POKeMON live inside...\n"
    .string "but that's not the only danger.\p"
    .string "People keep reporting POKeMON with a\n"
    .string "strange 'shadow' look in the area.\p"
    .string "Until the LEAGUE clears it, nobody\n"
    .string "is allowed in.$"

CeruleanCity_Text_CooltrainerM1:
    .string "ROUTE 9 to the east?\p"
    .string "Yeah... something weird happened near\n"
    .string "the POWER PLANT.\p"
    .string "Not an accident.\n"
    .string "More like... a cover-up.\p"
    .string "I saw men in black uniforms.\n"
    .string "Not regular ROCKETS either.$"

CeruleanCity_Text_CooltrainerM2:
    .string "People keep vanishing toward the CAPE.\p"
    .string "And whenever MISTY goes to investigate,\n"
    .string "someone calls her back to the GYM.\p"
    .string "It feels like somebody is steering\n"
    .string "everything from the shadows.$"

CeruleanCity_Text_SuperNerd:
    .string "CERULEAN CAPE is usually for dates...\p"
    .string "But lately?\n"
    .string "It's just rumors.\p"
    .string "They say a 'TEAM SNAGEM' guy was seen\n"
    .string "talking to MISTY up there.\p"
    .string "Sounds fake...\n"
    .string "but I swear I heard the name.$"

CeruleanCity_Text_Slowbro_Stub:
    .string "A trainer and their POKeMON are\n"
    .string "resting here.\p"
    .string "Something about them feels... off.$"

CeruleanCity_Text_SlowbroWoman_Stub:
    .string "This trainer keeps glancing north.\p"
    .string "Like they're waiting for someone...$"

CeruleanCity_Text_Fisher:
    .string "I'm a huge fan of CERULEAN GYM's\n"
    .string "MISTY.\p"
    .string "But she's been stressed.\n"
    .string "Not like normal Gym stuff.$"

CeruleanCity_Text_Fisher_RocketTip:
    .string "If you're looking for trouble...\p"
    .string "I saw a shady guy head toward the CAPE.\p"
    .string "Not just ROCKET.\n"
    .string "Different vibe. Quiet. Cold.\p"
    .string "Like he was scouting something.$"

CeruleanCity_Text_Youngster1:
    .string "The cave north of town has strong\n"
    .string "POKeMON...\p"
    .string "But my cousin says he saw one with a\n"
    .string "dark aura.\p"
    .string "He ran so fast he dropped his items!$"

CeruleanCity_Text_Sign:
    .string "CERULEAN CITY\p"
    .string "A Mysterious Blue Aura Surrounds It$"

CeruleanCity_Text_GymSign:
    .string "CERULEAN CITY\n"
    .string "POKeMON GYM\l"
    .string "LEADER: MISTY\p"
    .string "The Tomboyish Mermaid$"

CeruleanCity_Text_BikeShopSign:
    .string "There's a notice here...\p"
    .string "The BIKE SHOP has moved to\n"
    .string "GOLDENROD CITY in JOHTO...$"

CeruleanCity_Text_PoliceSign:
    .string "There's a notice here...\p"
    .string "CERULEAN POLICE:\n"
    .string "Report suspicious activity.\p"
    .string "Keep the CAPE trail clear at night.$"

CeruleanCity_Text_CapeSign:
    .string "CERULEAN CAPE\n"
    .string "AHEAD$"

CeruleanCity_Text_LockedDoor:
    .string "It's locked...$"

CeruleanCity_Text_Misty_Argue:
    .string "I don't care what you say!\n"
    .string "Stealing trainers' POKeMON\l"
    .string "is not cool!!$"

CeruleanCity_Text_Michael_Argue:
    .string "MISTY, you have to understand,\n"
    .string "they're not good people!\l"
    .string "They're only going to torture\l"
    .string "them!$"

CeruleanCity_Text_Michael_Player:
    .string "You must be the one WES has\n"
    .string "been all giddy about.\p"
    .string "You should head over to the CAPE\n"
    .string "on ROUTE 25 next to BILL'S house.\l"
    .string "That's where we set up camp.\p"
    .string "By the way, name's MICHAEL.\n"
    .string "I probably know the most about\l"
    .string "what's going on these days, haha.$"

CeruleanCity_Text_Michael_ToMisty:
    .string "MISTY, I hope you understand,\n"
    .string "I have to go.\p"
    .string "By the way, this kid is probably\n"
    .string "going to kick your butt later.\l"
    .string "See ya!$"

CeruleanCity_Text_Misty_AfterScene:
    .string "He's got some nerve!!\n"
    .string "You should probably head to the\l"
    .string "CAPE before you think about\l"
    .string "challenging me.\p"
    .string "I need to cool off and think\n"
    .string "about some things for a bit.$"

CeruleanCity_Text_Misty_Repeat:
    .string "You should probably head to the\n"
    .string "CAPE before you think about\l"
    .string "challenging me.\p"
    .string "I need to cool off and think\n"
    .string "about some things for a bit.$"

CeruleanCity_Text_Michael_Repeat:
    .string "I'll be at the CAPE on ROUTE 25.\n"
    .string "Come find me near BILL'S house.$"

CeruleanCity_Text_BugCatcher:
    .string "Even the bugs are hiding lately.\n"
    .string "The air feels... wrong.\l"
    .string "CIPHER must be close.$"

CeruleanCity_Text_Boy2:
    .string "MISTY hasn't been in the GYM.\n"
    .string "Everyone's whispering about the\l"
    .string "CAPE and some new group.$"

CeruleanCity_Text_RocketGruntF:
    .string "Don't lump us in with CIPHER.\n"
    .string "They're worse than ROCKET.\l"
    .string "Way worse.$"

CeruleanCity_Text_RocketGruntM:
    .string "Orders came down to stand by.\n"
    .string "Those guys in black? Not ours.\l"
    .string "Not anymore.$"

CeruleanCity_Text_PlasmaGruntF:
    .string "The SAGES told us to hold this\n"
    .string "street. No questions.$"

CeruleanCity_Text_PlasmaGruntM:
    .string "We are securing the perimeter.\n"
    .string "Move along.$"

CeruleanCity_Text_Policeman1:
    .string "Keep the CAPE trail clear at\n"
    .string "night. We're stretched thin.$"

CeruleanCity_Text_Policeman2:
    .string "If you see anything strange,\n"
    .string "report it immediately.$"

CeruleanCity_Text_Light:
    .string "Portable lights. Someone set\n"
    .string "up camp nearby.$"
