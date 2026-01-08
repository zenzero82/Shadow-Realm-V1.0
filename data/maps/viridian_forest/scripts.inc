viridian_forest_MapScripts::
    .byte 0

@ ============================================================
@ VIRIDIAN FOREST (KANTO) – Scene + Items + NPCs (NO TRAINERS)
@ Local IDs from your events.inc:
@   1 = Proton
@   2 = Zinzolin
@   3 = Rocket Grunt (NPC dialogue only for now)
@   4 = Plasma Grunt (dialogue only)
@   5,6,7 = Bug Catchers (all NPC dialogue)
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

@ Use a real free flag in constants/flags.h later.
.set FLAG_VIRIDIAN_FOREST_PLASMA_SCENE_DONE,  FLAG_TEMP_1

@ -------------------------
@ Map Scripts
@ -------------------------

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
 	walk_up
    walk_up
    walk_up
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
    .string "Snagem built what we need.\n"
    .string "We take it… and we don’t ask twice.$"

ViridianForest_Text_Proton_2:
    .string "Gonzap thinks he’s a partner.\p"
    .string "He’s a tool.\p"
    .string "Once we get the device, Kanto becomes\n"
    .string "the testing ground.$"


@ ============================================================
@ BUG CATCHERS (NPC chatter) – ALL use setspeaker
@ ============================================================

ViridianForest_EventScript_BugCatcher5::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher5, MSGBOX_NPC
    closemessage
    release
    end

ViridianForest_Text_BugCatcher5:
    .string "Something's off in this forest.\p"
    .string "I saw men in strange uniforms… and they\n"
    .string "weren't Rangers.\p"
    .string "They were whispering like it was a deal.$"


ViridianForest_EventScript_BugCatcher6::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher6, MSGBOX_NPC
    closemessage
    release
    end

ViridianForest_Text_BugCatcher6:
    .string "My CATERPIE got scared for no reason.\p"
    .string "Then the air felt… cold.\p"
    .string "Like something opened and shut,\n"
    .string "right between the trees.$"


@ ============================================================
@ BUG CATCHER (OBJECT 7) – NPC (FORESHADOW) – NO TRAINER
@ ============================================================

ViridianForest_EventScript_BugCatcher7_NPC::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_BugCatcher
    msgbox ViridianForest_Text_BugCatcher7, MSGBOX_NPC
    closemessage
    release
    end

ViridianForest_Text_BugCatcher7:
    .string "Hold up!\p"
    .string "Before you go deeper…\n"
    .string "Tell me you felt it too.\p"
    .string "I heard two men talking up ahead.\n"
    .string "Names… like Zinzolin and Proton.\p"
    .string "They said something about Snagem…\n"
    .string "and taking what they need.$"


@ ============================================================
@ GRUNTS BEHIND THEM – BOTH NPC DIALOGUE ONLY
@ ============================================================

ViridianForest_EventScript_RocketGrunt_NPC::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_GruntRocket
    msgbox ViridianForest_Text_RocketGrunt, MSGBOX_NPC
    closemessage
    release
    end

ViridianForest_Text_RocketGrunt:
    .string "No tourists past this point.\p"
    .string "Orders are orders.\p"
    .string "You didn’t see anything.\n"
    .string "You didn’t hear anything.\p"
    .string "Walk away.$"


ViridianForest_EventScript_PlasmaGrunt_NPC::
    lock
    faceplayer
    setspeaker ViridianForest_Speaker_Plasma
    msgbox ViridianForest_Text_PlasmaGrunt, MSGBOX_NPC
    closemessage
    release
    end

ViridianForest_Text_PlasmaGrunt:
    .string "…\p"
    .string "You’re early.\p"
    .string "Don’t ruin the schedule.$"


@ ============================================================
@ VIRIDIAN FOREST – ITEM PICKUPS (Poké Ball objects)
@ Set each Poké Ball object's Script in Porymap to one of these.
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

ViridianForest_EventScript_Item_Potion2::
    finditem ITEM_POTION
    end

ViridianForest_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end
