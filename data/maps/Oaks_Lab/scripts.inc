@ Oak's Lab scripts

.set VAR_PLAYER_STARTER_SPECIES, VAR_TEMP_2  @ used for mon preview (showmonpic)

Oaks_Lab_MapScripts::
    .byte 0

@ Flags used:
@   FLAG_MET_ROUTE1_AIDE             0x022
@   FLAG_HIDE_PALLET_LEO             0x023  @ hides Leo near Route 1 in Pallet
@   FLAG_HIDE_OAKS_LAB_LEO           0x024  @ hides Leo inside Oak's Lab (object 5)
@   FLAG_OAKS_LAB_LEO_SCENE_DONE     0x025
@   FLAG_WEST_FOREST_INTRO_DONE      0x026
@   FLAG_HIDE_OAKS_LAB_RALTSBALL     0x027
@   FLAG_HIDE_OAKS_LAB_HONEDGEBALL   0x028
@   FLAG_HIDE_OAKS_LAB_ZORUABALL     0x029
@   FLAG_SYS_POKEMON_GET             @ vanilla "got a mon" flag

@ ---------------- NIA MAIN SCRIPT ----------------

OaksLab_EventScript_Aide_Main::
    lock
    faceplayer

    @ If player already has a starter
    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_Aide_AfterStarter

    @ If Route 1 aide event has happened, Nia points to starters
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_EventScript_Aide_AfterRoute1

    @ Default: before Route 1 scene
    msgbox OaksLab_Text_FindCoworker, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_EventScript_Aide_AfterRoute1::
    msgbox OaksLab_Text_Aide_PointToStarters, MSGBOX_DEFAULT
    closemessage

    @ Once Nia has acknowledged the Route 1 event,
    @ hide Leo's Pallet Town overworld (he is now "in the lab").
    setflag FLAG_HIDE_PALLET_LEO

    release
    end

OaksLab_EventScript_Aide_AfterStarter::
    msgbox OaksLab_Text_AfterStarter, MSGBOX_DEFAULT
    closemessage
    release
    end

@ ---------------- INSIDE-LAB LEO INTRO SCENE ----------------
@ Coord event on (5,11) calls this.

OaksLab_EventScript_LeoIntro::
    @ If Route 1 scene has NOT happened yet, do nothing.
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_LeoIntro_HaveSeenRoute1
    end

OaksLab_LeoIntro_HaveSeenRoute1:
    @ If this scene already ran once, do nothing.
    checkflag FLAG_OAKS_LAB_LEO_SCENE_DONE
    goto_if_eq OaksLab_LeoIntro_Done

    lockall

    @ Make Leo visible for this scene (his object uses FLAG_HIDE_OAKS_LAB_LEO).
    clearflag FLAG_HIDE_OAKS_LAB_LEO

    @ Move Leo (local ID 5) and the player up 6 tiles before Nia speaks
    applymovement 5, OaksLab_Move_Leo_Up6
    applymovement OBJ_EVENT_ID_PLAYER, OaksLab_Move_Player_Up6
    waitmovement 0

    @ Nia (local ID 1) comes into view. Turn Nia to face down.
    turnobject 1, DIR_SOUTH

    @ Nia explains Oak's email, Route 1, and the starters
    msgbox OaksLab_Text_OakEmailIntro, MSGBOX_DEFAULT
    closemessage

    @ After Nia finishes, Leo (local ID 5) faces down and tells the player to pick a starter.
    turnobject 5, DIR_SOUTH
    msgbox OaksLab_Text_Leo_AfterNia, MSGBOX_DEFAULT
    closemessage

    @ Leo stays in the lab. Mark the scene as done so it doesn't repeat.
    setflag FLAG_OAKS_LAB_LEO_SCENE_DONE
    @ And permanently hide outside Leo in Pallet Town
    setflag FLAG_HIDE_PALLET_LEO

    releaseall
    end

OaksLab_LeoIntro_Done:
    end

@ Movements: Up 6 steps

OaksLab_Move_Leo_Up6:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

OaksLab_Move_Player_Up6:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

@ ---------------- STARTER POKEBALLS ----------------
@ Local IDs (current layout):
@   2 = RALTS
@   3 = HONEDGE
@   4 = ZORUA

@ ---------- RALTS Poké Ball (local ID 2) ----------
OaksLab_EventScript_StarterBall_Ralts::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_StarterBall_Ralts_Ready

    lock
    faceplayer
    msgbox OaksLab_Text_StarterBall_NotYet, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_StarterBall_Ralts_Ready:
    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_StarterBall_AlreadyHaveStarter

    lock
    faceplayer

    setvar VAR_PLAYER_STARTER_SPECIES, SPECIES_RALTS
    setvar VAR_0x8004, SPECIES_RALTS

    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Ralts_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------- HONEDGE Poké Ball (local ID 3) ----------
OaksLab_EventScript_StarterBall_Honedge::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_StarterBall_Honedge_Ready

    lock
    faceplayer
    msgbox OaksLab_Text_StarterBall_NotYet, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_StarterBall_Honedge_Ready:
    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_StarterBall_AlreadyHaveStarter

    lock
    faceplayer

    setvar VAR_PLAYER_STARTER_SPECIES, SPECIES_HONEDGE
    setvar VAR_0x8004, SPECIES_HONEDGE

    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Honedge_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------- ZORUA Poké Ball (local ID 4) ----------
OaksLab_EventScript_StarterBall_Zorua::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_StarterBall_Zorua_Ready

    lock
    faceplayer
    msgbox OaksLab_Text_StarterBall_NotYet, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_StarterBall_Zorua_Ready:
    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_StarterBall_AlreadyHaveStarter

    lock
    faceplayer

    setvar VAR_PLAYER_STARTER_SPECIES, SPECIES_ZORUA
    setvar VAR_0x8004, SPECIES_ZORUA

    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Zorua_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------------- Common starter handlers ----------------

OaksLab_EventScript_StarterBall_Cancel:
    closemessage
    release
    end

OaksLab_EventScript_StarterBall_AlreadyHaveStarter:
    lock
    msgbox OaksLab_Text_StarterBall_AlreadyHavePokemon, MSGBOX_DEFAULT
    release
    end

@ Player said NO at the Yes/No prompt
OaksLab_EventScript_DeclinedStarter:
    hidemonpic
    msgbox OaksLab_Text_DeclinedStarter, MSGBOX_DEFAULT
    closemessage
    release
    end

@ Per-species hide helpers using flags + removeobject
OaksLab_EventScript_HideBall_Ralts:
    setflag FLAG_HIDE_OAKS_LAB_RALTSBALL
    removeobject 2
    return

OaksLab_EventScript_HideBall_Honedge:
    setflag FLAG_HIDE_OAKS_LAB_HONEDGEBALL
    removeobject 3
    return

OaksLab_EventScript_HideBall_Zorua:
    setflag FLAG_HIDE_OAKS_LAB_ZORUABALL
    removeobject 4
    return

OaksLab_EventScript_HideChosenBall:
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_RALTS,   OaksLab_EventScript_HideBall_Ralts
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_HONEDGE, OaksLab_EventScript_HideBall_Honedge
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_ZORUA,   OaksLab_EventScript_HideBall_Zorua
    return

@ Player said YES – give starter, hide correct ball, nickname, follower update
OaksLab_EventScript_ChoseStarter:
    hidemonpic

    playfanfare FANFARE_OBTAIN_ITEM
    msgbox OaksLab_Text_ChoseStarter, MSGBOX_DEFAULT
    waitfanfare

    callnative GiveStarterMon
    setflag FLAG_SYS_POKEMON_GET

    @ Hide the correct Poké Ball (flag + removeobject)
    call OaksLab_EventScript_HideChosenBall

    @ “You received {species}!” line
    bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
    msgbox OaksLab_Text_Receive_Starter_Generic, MSGBOX_DEFAULT

    @ Nickname prompt
    msgbox OaksLab_Text_NicknamePrompt, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne OaksLab_SkipNickname

    setvar VAR_0x8004, 0        @ party index 0
    call Common_EventScript_NameReceivedPartyMon

OaksLab_SkipNickname:
    @ Update follower Pokémon now that party has changed
    @ Comment this line out if it gives an undefined reference.
    callnative UpdateFollowingPokemon

    closemessage
    release
    end

@ ---------------- TEXT ----------------

OaksLab_Text_FindCoworker:
    .string "ASSISTANT NIA: Oh, hello.\p"
    .string "My coworker LEO went to check something\n"
    .string "near Route 1 and has not come back yet.\p"
    .string "He saw a report about portals on the\n"
    .string "news and wanted to see if anything\l"
    .string "strange was happening nearby.$"

OaksLab_Text_OakEmailIntro:
    .string "ASSISTANT NIA: So you met LEO outside?\p"
    .string "He said a strange man used a device on\n"
    .string "a Pokemon and it went out of control.\p"
    .string "Before Professor OAK disappeared, he\n"
    .string "sent one final email:\p"
    .string "Cipher is on the move.\n"
    .string "They have learned to twist Pokemon\l"
    .string "hearts into something unnatural.\p"
    .string "If someone appears from the portal,\n"
    .string "entrust them with one of my partners.$"

OaksLab_Text_Aide_PointToStarters:
    .string "ASSISTANT NIA: Those three Pokeballs on\n"
    .string "the table each contain a partner Pokemon.\p"
    .string "Take a look at them and choose the\n"
    .string "one you feel drawn to.$"

OaksLab_Text_Leo_AfterNia:
    .string "ASSISTANT LEO: You heard her.\p"
    .string "Pick a partner from the table.\p"
    .string "It is too dangerous on Route 1 without\n"
    .string "a Pokemon at your side.$"

OaksLab_Text_Ball_Ralts_Inspect:
    .string "Do you want to select RALTS\nas your starter?$"

OaksLab_Text_Ball_Honedge_Inspect:
    .string "Do you want to select HONEDGE\nas your starter?$"

OaksLab_Text_Ball_Zorua_Inspect:
    .string "Do you want to select ZORUA\nas your starter?$"

OaksLab_Text_StarterBall_NotYet:
    .string "It seems like there is a Pokemon inside.\p"
    .string "Better not touch it yet.$"

OaksLab_Text_StarterBall_AlreadyHavePokemon:
    .string "The Pokeball is empty.\p"
    .string "You already chose a starter Pokemon.$"

OaksLab_Text_Receive_Ralts:
    .string "You received RALTS!$"

OaksLab_Text_Receive_Honedge:
    .string "You received HONEDGE!$"

OaksLab_Text_Receive_Zorua:
    .string "You received ZORUA!$"

OaksLab_Text_NicknamePrompt:
    .string "Would you like to give your\nstarter a nickname?$"

OaksLab_Text_AfterStarter:
    .string "ASSISTANT NIA: Take good care of that\n"
    .string "Pokemon.\p"
    .string "If Cipher really is active again, we will\n"
    .string "need trainers we can trust out there.$"

@ New generic texts for common handlers

OaksLab_Text_DeclinedStarter:
    .string "Better think it over carefully.\p"
    .string "This partner might be with me\n"
    .string "for a long time.$"

OaksLab_Text_ChoseStarter:
    .string "You decided to take this Pokemon\n"
    .string "as your partner.$"

OaksLab_Text_Receive_Starter_Generic:
    .string "You received {STR_VAR_1}!$"
