@ ============================================================
@ VIRIDIAN FOREST (KANTO) Scene + Items + Trainers
@ Local IDs from your events.inc:
@   1 = Proton
@   2 = Zinzolin
@   3 = Rocket Grunt (Trainer)
@   4 = Plasma Grunt (Trainer)
@   5,6,7 = Bug Catchers (Trainers)
@   8-13 = Poke Ball objects (item balls)
@ ============================================================

.set LOCALID_PROTON,          1
.set LOCALID_ZINZOLIN,        2
.set LOCALID_ROCKET_GRUNT,    3
.set LOCALID_PLASMA_GRUNT,    4
.set LOCALID_BUGCATCHER_5,    5
.set LOCALID_BUGCATCHER_6,    6
.set LOCALID_BUGCATCHER_7,    7

.set LOCALID_ITEMBALL_1,      8
.set LOCALID_ITEMBALL_2,      9
.set LOCALID_ITEMBALL_3,     10
.set LOCALID_ITEMBALL_4,     11
.set LOCALID_ITEMBALL_5,     12
.set LOCALID_ITEMBALL_6,     13

@ -------------------------
@ Map Scripts
@ -------------------------

viridian_forest_MapScripts::
ViridianForest_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_EventScript_Enter
    .byte 0

ViridianForest_EventScript_Enter::
    setflag FLAG_VISITED_VIRIDIAN_FOREST

    @ If scene already happened, keep them gone on reload
    checkflag FLAG_VIRIDIAN_FOREST_PLASMA_SCENE_DONE
    goto_if_eq ViridianForest_Enter_Done
    end

ViridianForest_Enter_Done::
    hideobjectat LOCALID_PROTON,   MAP_VIRIDIAN_FOREST
    hideobjectat LOCALID_ZINZOLIN, MAP_VIRIDIAN_FOREST
    removeobject LOCALID_PROTON
    removeobject LOCALID_ZINZOLIN
    end


@ ============================================================
@ COORD TRIGGERS (3 triggers -> same script)
@ Set the coord event script in Porymap to:
@   ViridianForest_EventScript_TriggerScene
@ ============================================================

ViridianForest_EventScript_TriggerScene::
    checkflag FLAG_VIRIDIAN_FOREST_PLASMA_SCENE_DONE
    goto_if_eq ViridianForest_EventScript_TriggerScene_Done

    lockall

    call ViridianForest_EventScript_ZinzolinProtonTalk

    releaseall
ViridianForest_EventScript_TriggerScene_Done::
    end


@ ============================================================
@ ZINZOLIN + PROTON CONVERSATION
@ After talk: walk 3 steps forward (down) and vanish forever
@ ============================================================

ViridianForest_EventScript_ZinzolinProtonTalk::
    setspeaker ViridianForest_Speaker_Zinzolin
    msgbox ViridianForest_Text_Zinzolin_1, MSGBOX_DEFAULT
    closemessage

    setspeaker ViridianForest_Speaker_Proton
    msgbox ViridianForest_Text_Proton_1, MSGBOX_DEFAULT
    closemessage

    setspeaker ViridianForest_Speaker_Zinzolin
    msgbox ViridianForest_Text_Zinzolin_2, MSGBOX_DEFAULT
    closemessage

    setspeaker ViridianForest_Speaker_Proton
    msgbox ViridianForest_Text_Proton_2, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_PROTON,   ViridianForest_Mov_WalkDown3
    applymovement LOCALID_ZINZOLIN, ViridianForest_Mov_WalkDown3
    waitmovement 0

    setflag FLAG_VIRIDIAN_FOREST_PLASMA_SCENE_DONE
    hideobjectat LOCALID_PROTON,   MAP_VIRIDIAN_FOREST
    hideobjectat LOCALID_ZINZOLIN, MAP_VIRIDIAN_FOREST
    removeobject LOCALID_PROTON
    removeobject LOCALID_ZINZOLIN
    return


ViridianForest_Mov_WalkDown3:
    walk_down
    walk_down
    walk_down
    step_end


@ ---------- SPEAKERS ----------

ViridianForest_Speaker_Zinzolin:
    .string "ZINZOLIN$"

ViridianForest_Speaker_Proton:
    .string "PROTON$"

ViridianForest_Speaker_BugCatcher:
    .string "BUG CATCHER$"

ViridianForest_Speaker_GruntRocket:
    .string "GRUNT$"

ViridianForest_Speaker_Plasma:
    .string "PLASMA$"


@ ---------- TEXT (Scene) ----------

ViridianForest_Text_Zinzolin_1:
    .string "This forest is crawling with eyes.\p"
    .string "Even the bugs are listening.$"

ViridianForest_Text_Proton_1:
    .string "Let them listen.\p"
    .string "The Kanto branch moves when we say it\n"
    .string "moves.$"

ViridianForest_Text_Zinzolin_2:
    .string "The plan is simple.\p"
    .string "Snagem built what we need.\p"
    .string "We take it, and we don't ask twice.$"
ViridianForest_Text_Proton_2:
    .string "Gonzap thinks he's a partner.\p"
    .string "He's a tool.\p"
    .string "Once we get the device, Kanto becomes\n"
    .string "the testing ground.$"
@ ============================================================
@ Bug Catchers (Trainers) - ALL use setspeaker
@ ============================================================
ViridianForest_EventScript_BugCatcher5::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    trainerbattle_single TRAINER_VF_BUGCATCHER1, ViridianForest_Text_BugCatcher5_Intro, ViridianForest_Text_BugCatcher5_Defeat, ViridianForest_EventScript_BugCatcher5_After
    end
ViridianForest_EventScript_BugCatcher5_After::
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher5_After, MSGBOX_NPC
    closemessage
    release
    end
ViridianForest_Text_BugCatcher5_Intro:
    .string "Something's off in this forest.\p"
    .string "I saw men in strange uniforms, and\n"
    .string "they weren't Rangers.\p"
    .string "They were whispering like it was a deal.$"
ViridianForest_Text_BugCatcher5_Defeat:
    .string "Whoa! My bugs got swatted!$"
ViridianForest_Text_BugCatcher5_After:
    .string "Even the bugs can feel it in the air.$"
ViridianForest_EventScript_BugCatcher6::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    trainerbattle_single TRAINER_VF_BUGCATCHER2, ViridianForest_Text_BugCatcher6_Intro, ViridianForest_Text_BugCatcher6_Defeat, ViridianForest_EventScript_BugCatcher6_After
    end
ViridianForest_EventScript_BugCatcher6_After::
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher6_After, MSGBOX_NPC
    closemessage
    release
    end
ViridianForest_Text_BugCatcher6_Intro:
    .string "My CATERPIE got scared for no reason.\p"
    .string "Then the air felt cold.\p"
    .string "Like something opened and shut,\n"
    .string "right between the trees.$"
ViridianForest_Text_BugCatcher6_Defeat:
    .string "Brr... not again!$"
ViridianForest_Text_BugCatcher6_After:
    .string "Maybe it was just the wind...$"
ViridianForest_EventScript_BugCatcher7::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    trainerbattle_single TRAINER_VF_BUGCATCHER3, ViridianForest_Text_BugCatcher7_Intro, ViridianForest_Text_BugCatcher7_Defeat, ViridianForest_EventScript_BugCatcher7_After
    end
ViridianForest_EventScript_BugCatcher7_After::
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher7_After, MSGBOX_NPC
    closemessage
    release
    end
ViridianForest_Text_BugCatcher7_Intro:
    .string "Hold up! Before you go deeper,\n"
    .string "tell me you felt it too.\p"
    .string "I heard two men talking up ahead.\n"
    .string "Names like Zinzolin and Proton.\p"
    .string "They said something about Snagem\n"
    .string "and taking what they need.$"
ViridianForest_Text_BugCatcher7_Defeat:
    .string "Okay, okay! You can pass.$"
ViridianForest_Text_BugCatcher7_After:
    .string "Those names... I've got a bad feeling.$"
@ ============================================================
@ GRUNTS BEHIND THEM
@ ============================================================
ViridianForest_EventScript_RocketGrunt_Trainer::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_GruntRocket
    trainerbattle_single TRAINER_VF_ROCKET, ViridianForest_Text_RocketGrunt_Intro, ViridianForest_Text_RocketGrunt_Defeat, ViridianForest_EventScript_RocketGrunt_After
    end
ViridianForest_EventScript_RocketGrunt_After::
    setspeaker ViridianForest_Speaker_GruntRocket
    msgbox ViridianForest_Text_RocketGrunt_After, MSGBOX_NPC
    closemessage
    release
    end
ViridianForest_Text_RocketGrunt_Intro:
    .string "No tourists past this point.\p"
    .string "Orders are orders.\p"
    .string "You didn't see anything.\n"
    .string "You didn't hear anything.\p"
    .string "Walk away.$"
ViridianForest_Text_RocketGrunt_Defeat:
    .string "Gah! I wasn't supposed to lose!$"
ViridianForest_Text_RocketGrunt_After:
    .string "Orders are orders. I'm out.$"
ViridianForest_EventScript_PlasmaGrunt_Trainer::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_Plasma
    trainerbattle_single TRAINER_VF_PLASMA, ViridianForest_Text_PlasmaGrunt_Intro, ViridianForest_Text_PlasmaGrunt_Defeat, ViridianForest_EventScript_PlasmaGrunt_After
    end
ViridianForest_EventScript_PlasmaGrunt_After::
    setspeaker ViridianForest_Speaker_Plasma
    msgbox ViridianForest_Text_PlasmaGrunt_After, MSGBOX_NPC
    closemessage
    release
    end
ViridianForest_Text_PlasmaGrunt_Intro:
    .string "You're early.\p"
    .string "Don't ruin the schedule.$"
ViridianForest_Text_PlasmaGrunt_Defeat:
    .string "Ngh... you're in the way!$"
ViridianForest_Text_PlasmaGrunt_After:
    .string "Stay out of this forest.$"
@ ============================================================
@ VIRIDIAN FOREST - ITEM PICKUPS (Poke Ball objects) - ITEM PICKUPS (Poke Ball objects)  ITEM PICKUPS (Pok Ball objects)
@ Set each Pok Ball object's Script in Porymap to one of these.
@ ============================================================

ViridianForest_EventScript_Item_Potion1::
    finditem ITEM_POTION
    end

ViridianForest_EventScript_Item_PokeBall::
    finditem ITEM_POKE_BALL
    end

ViridianForest_EventScript_Item_Antidote::
    finditem ITEM_ANTIDOTE
    end

ViridianForest_EventScript_Item_ParalyzeHeal::
    finditem ITEM_PARALYZE_HEAL
    end

ViridianForest_EventScript_Item_Time_Flute::
    finditem ITEM_TIME_FLUTE
    end

ViridianForest_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end
