@ Oak's Lab scripts

.set VAR_PLAYER_STARTER_SPECIES, VAR_TEMP_2  @ used for mon preview (showmonpic)

.set LOCALID_NIA, 1
.set LOCALID_RALTSBALL, 2
.set LOCALID_HONEDGEBALL, 3
.set LOCALID_ZORUABALL, 4
.set LOCALID_LEO, 5
.set LOCALID_OAK, 6
.set LOCALID_HOOPA_RING, 7


Oaks_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OaksLab_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OaksLab_EventScript_OnFrame
	.byte 0

OaksLab_EventScript_OnLoad::
    setvar VAR_TEMP_1, 0
    checkflag FLAG_OAKS_LAB_NEWGAME_INTRO_DONE
    goto_if_eq OaksLab_EventScript_OnLoad_AfterIntro
    checkflag FLAG_WEST_FOREST_INTRO_DONE
    goto_if_eq OaksLab_EventScript_OnLoad_AfterIntro
    hideobjectat LOCALID_PLAYER, MAP_OAKS_LAB
    setflag FLAG_HIDE_OAKS_LAB_NIA
    setflag FLAG_HIDE_OAKS_LAB_LEO
    setflag FLAG_HIDE_OAKS_LAB_HOOPA_RING
    setvar VAR_0x8004, 8
    setvar VAR_0x8005, 5
    removeobject LOCALID_OAK
    setobjectxyperm LOCALID_OAK, VAR_0x8004, VAR_0x8005
    clearflag FLAG_HIDE_OAKS_LAB_OAK
    addobject LOCALID_OAK
    setobjectxy LOCALID_OAK, VAR_0x8004, VAR_0x8005
    special SpawnCameraObjectAtVars
    special SetCameraFocusCoordsFromVars
OaksLab_EventScript_OnLoad_AfterIntro:
    call OaksLab_EventScript_ApplyPostStarterState
    end

OaksLab_EventScript_OnFrame::
    map_script_2 VAR_TEMP_1, 0, OaksLab_EventScript_CheckAutoIntro
    .2byte 0

OaksLab_EventScript_CheckAutoIntro::
    setvar VAR_TEMP_1, 1
    checkflag FLAG_OAKS_LAB_NEWGAME_INTRO_DONE
    goto_if_eq OaksLab_EventScript_CheckAutoIntro_Default
    checkflag FLAG_WEST_FOREST_INTRO_DONE
    goto_if_eq OaksLab_EventScript_CheckAutoIntro_Default
    goto OaksLab_EventScript_NewGameIntro
OaksLab_EventScript_CheckAutoIntro_Default:
    checkflag FLAG_OAKS_LAB_FORCE_INTRO
    goto_if_eq OaksLab_EventScript_CheckAutoIntro_Run
    end

OaksLab_EventScript_CheckAutoIntro_Run::
    clearflag FLAG_OAKS_LAB_FORCE_INTRO
    goto OaksLab_EventScript_LeoIntro

@ ==============================
@ SPEAKER STRINGS (unique labels)
@ ==============================

OaksLab_Speaker_Leo:
    .string "Prof. Aide Leo$"

OaksLab_Speaker_Nia:
    .string "Prof. Aide Nia$"

OaksLab_Speaker_Oak:
    .string "Professor Oak$"

@ ---------------- NEW GAME INTRO ----------------

OaksLab_EventScript_NewGameIntro::
    setvar VAR_TEMP_1, 1
    checkflag FLAG_OAKS_LAB_NEWGAME_INTRO_DONE
    goto_if_eq OaksLab_EventScript_NewGameIntro_Done

    lockall
    hideobjectat LOCALID_PLAYER, MAP_OAKS_LAB
    setflag FLAG_HIDE_OAKS_LAB_NIA
    setflag FLAG_HIDE_OAKS_LAB_LEO
    setflag FLAG_HIDE_OAKS_LAB_HOOPA_RING
    setvar VAR_0x8004, 8
    setvar VAR_0x8005, 5
    setobjectxy LOCALID_OAK, VAR_0x8004, VAR_0x8005

    setobjectxy LOCALID_PLAYER, 2, 2
    setobjectxyperm LOCALID_PLAYER, 2, 2
    special RemoveCameraObject
    special SpawnCameraObjectAtVars
    special SetCameraFocusCoordsFromVars

    applymovement LOCALID_OAK, OaksLab_Move_Oak_Pace
    waitmovement 0

    setspeaker OaksLab_Speaker_Oak
    msgbox OaksLab_Text_Oak_Concern, MSGBOX_DEFAULT
    closemessage

    playse SE_PC_LOGIN
    waitse
    playse SE_PIN
    applymovement LOCALID_OAK, OaksLab_Move_Oak_Exclaim
    waitmovement LOCALID_OAK
    applymovement LOCALID_OAK, OaksLab_Move_Oak_ToHome
    applymovement LOCALID_CAMERA, OaksLab_Move_Camera_ToOakHome
    waitmovement LOCALID_OAK
    waitmovement LOCALID_CAMERA

    setspeaker OaksLab_Speaker_Oak
    msgbox OaksLab_Text_Oak_Intro, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_OAK, OaksLab_Move_Oak_Down2
    applymovement LOCALID_CAMERA, OaksLab_Move_Camera_OakFollow
    waitmovement LOCALID_OAK
    waitmovement LOCALID_CAMERA

    clearflag FLAG_HIDE_OAKS_LAB_HOOPA_RING
    addobject LOCALID_HOOPA_RING
    setobjectxy LOCALID_HOOPA_RING, 2, 3
    setobjectxyperm LOCALID_HOOPA_RING, 2, 3
    showobjectat LOCALID_HOOPA_RING, MAP_OAKS_LAB

    setvar VAR_0x8004, LOCALID_HOOPA_RING
    setvar VAR_0x8001, 0
    setvar VAR_0x8002, 0
    special Special_HoopaRingSpawnGrow
    waitstate

    applymovement LOCALID_OAK, OaksLab_Move_Oak_PullIntoRing
    waitmovement 0
    setvar VAR_0x8000, LOCALID_OAK
    special Special_ObjectEventAbsorb
    waitstate
    playse SE_LAVARIDGE_FALL_WARP
    hideobjectat LOCALID_OAK, MAP_OAKS_LAB

    setvar VAR_0x8004, LOCALID_HOOPA_RING
    special Special_HoopaRingShrinkDespawn
    waitstate
    hideobjectat LOCALID_HOOPA_RING, MAP_OAKS_LAB

    applymovement LOCALID_CAMERA, OaksLab_Move_Camera_ToNia
    waitmovement LOCALID_CAMERA
    setobjectxy LOCALID_PLAYER, 4, 12
    setobjectxyperm LOCALID_PLAYER, 4, 12
    clearflag FLAG_HIDE_OAKS_LAB_NIA
    addobject LOCALID_NIA
    setobjectxy LOCALID_NIA, 5, 12
    showobjectat LOCALID_NIA, MAP_OAKS_LAB
    applymovement LOCALID_NIA, OaksLab_Move_Nia_EnterLab
    waitmovement LOCALID_NIA
    playse SE_PIN
    applymovement LOCALID_NIA, OaksLab_Move_Nia_ExclaimFaceUp
    waitmovement LOCALID_NIA
    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_Nia_FindOak, MSGBOX_DEFAULT
    closemessage

    fadescreenspeed FADE_TO_BLACK, 6
    msgbox OaksLab_Text_SixMonthsLater, MSGBOX_DEFAULT
    closemessage

    special RemoveCameraObject

    setflag FLAG_OAKS_LAB_NEWGAME_INTRO_DONE
    setflag FLAG_HIDE_OAKS_LAB_OAK
    setflag FLAG_HIDE_OAKS_LAB_HOOPA_RING
    clearflag FLAG_HIDE_OAKS_LAB_NIA

    releaseall
    warp MAP_PALLET_TOWN_WESTERN_FOREST, WARP_ID_NONE, 5, 5
    waitstate
    fadescreenspeed FADE_FROM_BLACK, 6
    end

OaksLab_EventScript_NewGameIntro_Done::
    end

OaksLab_EventScript_Oak_Talk::
    lock
    faceplayer
    setspeaker OaksLab_Speaker_Oak
    msgbox OaksLab_Text_Oak_Busy, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_EventScript_HoopaRing::
    end

@ ---------------- NIA MAIN SCRIPT ----------------

OaksLab_EventScript_Aide_Main::
    lock
    faceplayer

    @ Post-starter
    checkflag FLAG_OAKS_LAB_POST_STARTER_STATE
    goto_if_eq OaksLab_EventScript_Nia_PostStarter

    @ After Route 1, before starter
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_EventScript_Nia_PreStarter

    @ Before Route 1 scene
    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_FindCoworker, MSGBOX_DEFAULT
    closemessage
    release
    end

OaksLab_EventScript_Nia_PreStarter::
    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_Aide_PointToStarters, MSGBOX_DEFAULT
    closemessage

    @ Leo is now considered "in the lab"
    setflag FLAG_HIDE_PALLET_LEO

    release
    end

OaksLab_EventScript_Nia_PostStarter::
    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_Nia_PostStarter, MSGBOX_DEFAULT
    closemessage
    release
    end

@ ---------------- LEO TALK SCRIPT ----------------
@ Assign this script to Leo's object (local id 5) in Porymap.

OaksLab_EventScript_Leo_Talk::
    lock
    faceplayer

    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_Leo_Talk_HasStarter

    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_AfterNia, MSGBOX_DEFAULT
    closemessage
    goto OaksLab_EventScript_Leo_Talk_Release

OaksLab_EventScript_Leo_Talk_HasStarter::
    checkflag FLAG_SYS_NATIONAL_DEX
    goto_if_eq OaksLab_EventScript_Leo_PostStarter

    @ Repeat until starter is chosen
    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_AfterNia, MSGBOX_DEFAULT
    closemessage
    msgbox OaksLab_Text_Leo_GrantNationalDex, MSGBOX_DEFAULT
    closemessage
    call OaksLab_EventScript_ReceivePokedex
    setflag FLAG_SYS_NATIONAL_DEX
    special EnableNationalPokedex
    setflag FLAG_SYS_POKEDEX_GET
    special SetUnlockedPokedexFlags
    goto OaksLab_EventScript_Leo_Talk_Release

OaksLab_EventScript_Leo_Talk_Release::
    release
    end
OaksLab_EventScript_Leo_PostStarter::
    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_PostStarter, MSGBOX_DEFAULT
    closemessage
    release
    end

@ ---------------- EXIT BLOCKER ----------------
@ Prevent leaving until starter chosen (after Leo intro scene)

OaksLab_EventScript_ExitLab::
    checkflag FLAG_MET_ROUTE1_AIDE
    goto_if_eq OaksLab_EventScript_ExitLab_AfterLeo
    end

OaksLab_EventScript_ExitLab_AfterLeo::
    checkflag FLAG_SYS_POKEMON_GET
    goto_if_eq OaksLab_EventScript_ExitLab_Allow

    checkflag FLAG_OAKS_LAB_LEO_SCENE_DONE
    goto_if_eq OaksLab_EventScript_ExitLab_Block

    end

OaksLab_EventScript_ExitLab_Block::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, OaksLab_Move_Player_StepBackUp
    waitmovement 0
    turnobject LOCALID_LEO, DIR_SOUTH
    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_BlockExit, MSGBOX_DEFAULT
    closemessage
    releaseall
    end

OaksLab_EventScript_ExitLab_Allow::
    end

@ ---------------- POKEDEX RECEIVE ----------------

OaksLab_EventScript_ReceivePokedex::
    playfanfare MUS_OBTAIN_ITEM
    message OaksLab_Text_ReceivedPokedex
    waitfanfare
    return

@ ---------------- BG SIGN SCRIPTS ----------------

OaksLab_EventScript_OaksPC::
    msgbox OaksLab_Text_OaksPC, MSGBOX_SIGN
    end

OaksLab_EventScript_Bookshelf_Collection::
    msgbox OaksLab_Text_Bookshelf_Collection, MSGBOX_SIGN
    end

OaksLab_EventScript_Bookshelf_Studies::
    msgbox OaksLab_Text_Bookshelf_Studies, MSGBOX_SIGN
    end

OaksLab_EventScript_Bookshelf_XD::
    msgbox OaksLab_Text_Bookshelf_XD, MSGBOX_SIGN
    end

@ ---------------- INSIDE-LAB LEO INTRO SCENE ----------------
@ Coord event on (5,10) calls this.

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

    @ Move Leo and player up 6 tiles before Nia speaks
    applymovement LOCALID_LEO, OaksLab_Move_Leo_Up6
    applymovement OBJ_EVENT_ID_PLAYER, OaksLab_Move_Player_Up6
    waitmovement 0

    @ Keep Leo/Nia facing north until Leo addresses Nia
    turnobject LOCALID_LEO, DIR_NORTH
    turnobject LOCALID_NIA, DIR_NORTH

    playse SE_PIN
    applymovement LOCALID_NIA, OaksLab_Move_Nia_ExclaimFaceDown
    waitmovement 0

    turnobject LOCALID_NIA, DIR_SOUTH
    turnobject LOCALID_LEO, DIR_NORTH

    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_EnterLab, MSGBOX_DEFAULT
    closemessage

    turnobject LOCALID_NIA, DIR_NORTH

    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_OakEmailIntro, MSGBOX_DEFAULT
    closemessage

    turnobject LOCALID_NIA, DIR_SOUTH

    turnobject LOCALID_LEO, DIR_SOUTH

    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_ToPlayer, MSGBOX_DEFAULT
    closemessage

    setspeaker OaksLab_Speaker_Nia
    msgbox OaksLab_Text_Aide_PointToStarters, MSGBOX_DEFAULT
    closemessage

    setspeaker OaksLab_Speaker_Leo
    msgbox OaksLab_Text_Leo_GrantNationalDex, MSGBOX_DEFAULT
    closemessage

    checkflag FLAG_SYS_POKEDEX_GET
    goto_if_eq OaksLab_LeoIntro_AfterDex
    call OaksLab_EventScript_ReceivePokedex
    setflag FLAG_SYS_NATIONAL_DEX
    special EnableNationalPokedex
    setflag FLAG_SYS_POKEDEX_GET
    special SetUnlockedPokedexFlags

OaksLab_LeoIntro_AfterDex:
    setflag FLAG_OAKS_LAB_LEO_SCENE_DONE
    setflag FLAG_HIDE_PALLET_LEO

    releaseall
    end

OaksLab_LeoIntro_Done::
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

OaksLab_Move_Player_StepBackUp:
    walk_up
    step_end

OaksLab_Move_Nia_ExclaimFaceDown:
    emote_exclamation_mark
    step_end

OaksLab_Move_Oak_Down2:
    walk_down
    walk_down
    step_end

OaksLab_Move_Oak_Exclaim:
    emote_exclamation_mark
    step_end

OaksLab_Move_Oak_Pace:
    walk_left
    walk_right
    walk_right
    walk_left
    face_up
    step_end

OaksLab_Move_Oak_ToHome:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    step_end

OaksLab_Move_Oak_PullIntoRing:
    face_down
    lock_facing_direction
    slide_up
    unlock_facing_direction
    step_end

OaksLab_Move_Player_CamToOak:
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

OaksLab_Move_Player_CamToNia:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    step_end

OaksLab_Move_Camera_OakFollow:
    walk_down
    walk_down
    step_end

OaksLab_Move_Camera_ToOakHome:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    step_end

OaksLab_Move_Camera_ToNia:
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

OaksLab_Move_Nia_EnterLab:
    walk_up
    walk_up
    step_end

OaksLab_Move_Nia_ExclaimFaceUp:
    emote_exclamation_mark
    face_up
    step_end

@ ---------------- STARTER POKEBALLS ----------------

@ ---------- RALTS Poke Ball ----------
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

    setvar VAR_PLAYER_STARTER_SPECIES, SPECIES_IMPIDIMP
    setvar VAR_0x8004, SPECIES_IMPIDIMP

    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
    waitse
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Ralts_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------- HONEDGE Poke Ball ----------
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
    waitse
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Honedge_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------- ZORUA Poke Ball ----------
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

    setvar VAR_PLAYER_STARTER_SPECIES, SPECIES_SLOWPOKE_GALAR
    setvar VAR_0x8004, SPECIES_SLOWPOKE_GALAR

    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
    waitse
    playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL

    msgbox OaksLab_Text_Ball_Zorua_Inspect, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq OaksLab_EventScript_ChoseStarter
    goto OaksLab_EventScript_DeclinedStarter

@ ---------------- Common starter handlers ----------------

OaksLab_EventScript_StarterBall_AlreadyHaveStarter::
    lock
    msgbox OaksLab_Text_StarterBall_AlreadyHavePokemon, MSGBOX_DEFAULT
    release
    end

OaksLab_EventScript_DeclinedStarter::
    hidemonpic
    msgbox OaksLab_Text_DeclinedStarter, MSGBOX_DEFAULT
    closemessage
    release
    end

@ Per-species hide helpers using flags + removeobject
OaksLab_EventScript_HideBall_Ralts::
    setflag FLAG_HIDE_OAKS_LAB_RALTSBALL
    removeobject LOCALID_RALTSBALL
    return

OaksLab_EventScript_HideBall_Honedge::
    setflag FLAG_HIDE_OAKS_LAB_HONEDGEBALL
    removeobject LOCALID_HONEDGEBALL
    return

OaksLab_EventScript_HideBall_Zorua::
    setflag FLAG_HIDE_OAKS_LAB_ZORUABALL
    removeobject LOCALID_ZORUABALL
    return

OaksLab_EventScript_HideChosenBall::
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_IMPIDIMP,        OaksLab_EventScript_HideBall_Ralts
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_HONEDGE,         OaksLab_EventScript_HideBall_Honedge
    call_if_eq VAR_PLAYER_STARTER_SPECIES, SPECIES_SLOWPOKE_GALAR,  OaksLab_EventScript_HideBall_Zorua
    return

OaksLab_EventScript_ChoseStarter::
    hidemonpic

    playfanfare FANFARE_OBTAIN_ITEM
    msgbox OaksLab_Text_ChoseStarter, MSGBOX_DEFAULT
    waitfanfare

    callnative GiveStarterMon
    setflag FLAG_SYS_POKEMON_GET

    call OaksLab_EventScript_HideChosenBall

    bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
    msgbox OaksLab_Text_Receive_Starter_Generic, MSGBOX_DEFAULT

    msgbox OaksLab_Text_NicknamePrompt, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne OaksLab_SkipNickname

    setvar VAR_0x8004, 0
    call Common_EventScript_NameReceivedPartyMon

OaksLab_SkipNickname::
	call OaksLab_EventScript_SetPostStarterState
	callnative UpdateFollowingPokemon

	closemessage
	release
	end

OaksLab_EventScript_SetPostStarterState::
	checkflag FLAG_OAKS_LAB_POST_STARTER_STATE
	goto_if_eq OaksLab_EventScript_SetPostStarterState_Done
	setflag FLAG_OAKS_LAB_POST_STARTER_STATE
OaksLab_EventScript_SetPostStarterState_Done::
	return

OaksLab_EventScript_ApplyPostStarterState::
    checkflag FLAG_OAKS_LAB_POST_STARTER_STATE
    goto_if_eq OaksLab_EventScript_ApplyPostStarterState_Apply
    return
OaksLab_EventScript_ApplyPostStarterState_Apply::
    setobjectxy LOCALID_LEO, 2, 10
    setobjectxyperm LOCALID_LEO, 2, 10
    setobjectmovementtype LOCALID_LEO, MOVEMENT_TYPE_WANDER_AROUND
    setobjectxy LOCALID_NIA, 7, 2
    setobjectxyperm LOCALID_NIA, 7, 2
    setobjectmovementtype LOCALID_NIA, MOVEMENT_TYPE_FACE_UP
    turnobject LOCALID_NIA, DIR_NORTH
    return
@ ---------------- TEXT ----------------

OaksLab_Text_FindCoworker:
    .string "You're not with them, are you??\p"
    .string "Sorry, I've been on high alert since\n"
    .string "the Professor went missing.\p"
    .string "Can you please find my partner LEO?\n"
    .string "He went out to look for clues and has\l"
    .string "been gone for quite some time.\p"
    .string "I'm trying to see if the Professor left\n"
    .string "any hints on his PC.$"
OaksLab_Text_Leo_EnterLab:
    .string "Nia! It seems that issue the Professor\n"
    .string "has been researching has made its way\n"
    .string "to Pallet Town!\p"
    .string "One of those people just captured a\n"
    .string "POKEMON and transformed it!$"

OaksLab_Text_OakEmailIntro:
    .string "Oh no! This is not good.\p"
    .string "We may not be out of luck, though.\p"
    .string "The Professor got an email from\n"
    .string "a colleague. It says:\p"
    .string "A trainer arrived through a portal.\n"
    .string "Give them one of the POKEMON that\l"
    .string "Oak was studying...$"

OaksLab_Text_Leo_ToPlayer:
    .string "Who did you say you were?\p"
    .string "...Ah, I see. You don't know how you\n"
    .string "got here, and you came through a\l"
    .string "strange portal.\p"
    .string "...You're the one! Please, you have to\n"
    .string "help us!\p"
    .string "The POKEMON the Professor was studying\n"
    .string "are on the table.$"
OaksLab_Text_Aide_PointToStarters:
    .string "Leo, you should also give him a\n"
    .string "POKEDEX.\p"
    .string "I think the Professor will be okay\n"
    .string "with giving it to this trainer if he\l"
    .string "trusts him with a partner.$"
OaksLab_Text_Leo_AfterNia:
    .string "Now please, help us find the Professor\n"
    .string "and stop these evil people!$"
OaksLab_Text_Leo_BlockExit:
    .string "Hey! Route 1 is dangerous.\p"
    .string "Please pick a partner before you go!$"
OaksLab_Text_Leo_PostStarter:
    .string "I hope the Professor was right to\n"
    .string "entrust a POKEMON to you.\p"
    .string "There has been so much strange activity\n"
    .string "lately. I have trust issues...$"
OaksLab_Text_Leo_GrantNationalDex:
    .string "Ah, yes. Good point.\p"
    .string "Like she said, take this and use it\n"
    .string "on your journey.\p"
    .string "It can really help document the strange\n"
    .string "appearance of POKEMON in this region.$"
OaksLab_Text_Nia_PostStarter:
    .string "We don't know much about what is\n"
    .string "happening.\p"
    .string "We do know that Professor OAK was\n"
    .string "studying this odd transformation and\l"
    .string "said he was close to solving the case.\p"
    .string "Next thing we know, he just disappeared\n"
    .string "from the lab!$"
OaksLab_Text_Ball_Ralts_Inspect:
    .string "Do you want to select IMPIDIMP\nas your starter?$"

OaksLab_Text_Ball_Honedge_Inspect:
    .string "Do you want to select HONEDGE\nas your starter?$"

OaksLab_Text_Ball_Zorua_Inspect:
    .string "Do you want to select GALARIAN SLOWPOKE\nas your starter?$"

OaksLab_Text_StarterBall_NotYet:
    .string "It seems like there is a Pokemon inside.\p"
    .string "Better not touch it yet.$"

OaksLab_Text_StarterBall_AlreadyHavePokemon:
    .string "The Pokeball is empty.\p"
    .string "You already chose a starter Pokemon.$"

OaksLab_Text_NicknamePrompt:
    .string "Would you like to give your\nstarter a nickname?$"

OaksLab_Text_DeclinedStarter:
    .string "Better think it over carefully.\p"
    .string "This partner might be with me\n"
    .string "for a long time.$"

OaksLab_Text_ChoseStarter:
    .string "You decided to take this Pokemon\n"
    .string "as your partner.$"

OaksLab_Text_Receive_Starter_Generic:
    .string "You received {STR_VAR_1}!$"

OaksLab_Text_ReceivedPokedex:
    .string "You received the POKEDEX!$"

OaksLab_Text_OaksPC:
    .string "OAK's PC is full of notes on\n"
    .string "SHADOW POKeMON research.\p"
    .string "There are detailed studies on the\n"
    .string "starter POKeMON too.$"

OaksLab_Text_Bookshelf_Collection:
    .string "A large collection of books on\n"
    .string "POKeMON habitats and biology.$"

OaksLab_Text_Bookshelf_Studies:
    .string "Stacks of research papers on\n"
    .string "evolution and training methods.$"

OaksLab_Text_Bookshelf_XD:
    .string "A draft titled XD catches your eye.\p"
    .string "It mentions a strange new POKeMON form.$"

OaksLab_Text_Oak_Concern:
    .string "What is it that is different with\n"
    .string "these 3 POKeMON?\p"
    .string "Why are they able to resist?$"

OaksLab_Text_Oak_Intro:
    .string "That's got to be it! I finally\n"
    .string "understand what is causing the\l"
    .string "strange phenomenon in these POKEMON.\p"
    .string "I need to call the others and\n"
    .string "schedule a meeting.$"

OaksLab_Text_Nia_FindOak:
    .string "Professor? Huh, wonder where he went.$"

OaksLab_Text_SixMonthsLater:
    .string "Six months later...$"

OaksLab_Text_Oak_Busy:
    .string "OAK is busy at his PC.$"
