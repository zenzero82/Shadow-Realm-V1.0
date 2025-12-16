Pewter_City_MapScripts::
    .byte 0

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

PewterCity_Text_Sign:
    .string "PEWTER CITY\n"
    .string "A Stone Gray City$"

PewterCity_Text_GymSign:
    .string "PEWTER CITY POKEMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "The Rock Solid POKEMON Trainer$"

PewterCity_Text_MuseumSign:
    .string "There's a notice here…\p"
    .string "PEWTER MUSEUM OF SCIENCE is closed for\n"
    .string "renovations…$"

PewterCity_Text_MtMoonGiftShopSign:
    .string "There's a notice here…\p"
    .string "MT.MOON GIFT SHOP NOW OPEN!$"

PewterCity_Text_WelcomeSign:
    .string "WELCOME TO PEWTER CITY!$"


@ =====================================================
@ BROCK + WES INTRO SCENE AT PEWTER ENTRANCE
@ =====================================================
@ Coord event:
@   Trigger 0 (the tile between Brock and Wes) ->
@       PewterCity_EventScript_BrockWesTrigger0
@
@ Overworld objects in Porymap:
@   LOCALID 1 = Brock, facing down, standing on left side of path
@   LOCALID 2 = Wes, facing down, standing on right side of path
@
@ Flags you should define in flags.h (using unused IDs):
@   FLAG_PEWTER_BROCK_WES_SCENE_DONE   - scene played once
@   FLAG_HIDE_PEWTER_CITY_BROCK        - hide this overworld Brock after scene
@   FLAG_HIDE_PEWTER_CITY_WES          - hide Wes after scene
@
@ In Porymap:
@   - Set LOCALID 1's object flag to FLAG_HIDE_PEWTER_CITY_BROCK (optional)
@   - Set LOCALID 2's object flag to FLAG_HIDE_PEWTER_CITY_WES (optional)
@   - Initially leave both flags CLEAR so they appear the first time.

PewterCity_EventScript_BrockWesTrigger0::
    @ If we already ran this scene, do nothing
    checkflag FLAG_PEWTER_BROCK_WES_SCENE_DONE
    goto_if_eq PewterCity_EventScript_BrockWesTrigger_Done

    lockall
    @ Player is already between them; if you want them to face up:
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Move_Player_FaceUp
    waitmovement 0

    goto PewterCity_EventScript_BrockWesScene

PewterCity_EventScript_BrockWesTrigger_Done::
    end

@ ----------------------
@ Main Brock + Wes scene
@ ----------------------

PewterCity_EventScript_BrockWesScene::
    @ Brock and Wes are talking before they notice the player.

    msgbox PewterCity_Text_BrockWes_PrePlayer, MSGBOX_DEFAULT
    closemessage

    @ Both notice the player at the same time
    playse SE_PIN
    applymovement 1, PewterCity_Move_Brock_Exclaim
    applymovement 2, PewterCity_Move_Wes_Exclaim
    waitmovement 0

    @ They turn down toward the player (player is below them)
    @ DIR_SOUTH = 1
    turnobject 1, 1
    turnobject 2, 1

    msgbox PewterCity_Text_BrockWes_SeePlayer, MSGBOX_DEFAULT
    closemessage

    @ Wes questions the player about Cipher
    msgbox PewterCity_Text_Wes_Interrogate, MSGBOX_DEFAULT
    closemessage

    @ Player is assumed to answer “not with Cipher” in spirit,
    @ so Brock & Wes decide they are on the same side.
    msgbox PewterCity_Text_Brock_TrustsPlayer, MSGBOX_DEFAULT
    closemessage

    @ Wes explains his backstory and the Cerulean hideout
    msgbox PewterCity_Text_Wes_Backstory, MSGBOX_DEFAULT
    closemessage

    @ Wes gives the “prove yourself vs Brock” condition
    msgbox PewterCity_Text_Wes_Challenge, MSGBOX_DEFAULT
    closemessage

    @ Brock encourages the Gym battle and heads off
    msgbox PewterCity_Text_Brock_ToGym, MSGBOX_DEFAULT
    closemessage

    @ Brock walks to the Gym (1 right, 7 up) then disappears
    applymovement 1, PewterCity_Move_Brock_ToGym
    waitmovement 0
    setflag FLAG_HIDE_PEWTER_CITY_BROCK
    removeobject 1

    @ Wes heads toward Cerulean (11 right) then disappears
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

@ Brock: 1 step right, then 7 steps up to reach the Gym, then stop.
@ Make sure his starting tile lines up with this path.
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

@ Wes: 11 steps to the right, then stop and vanish.
@ Place his starting position so this path makes sense visually.
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

@ They’re talking before noticing the player.
@ Brock keeps his “reliable, serious gym leader” tone.
@ Wes is a bit sharper and more guarded.

PewterCity_Text_BrockWes_PrePlayer:
    .string "BROCK: Team Rocket's activity in KANTO\n"
    .string "is getting worse by the day.\p"
    .string "WES: And every time someone gets close\n"
    .string "to Cipher, the trail goes cold.\p"
    .string "BROCK: Ever since PROF. OAK vanished,\n"
    .string "the League's been scrambling.$"

@ Both turn and see the player.

PewterCity_Text_BrockWes_SeePlayer:
    .string "WES: Hm?\p"
    .string "BROCK: You there!$"

@ Wes does the main interrogation.

PewterCity_Text_Wes_Interrogate:
    .string "WES: I haven't seen you around PEWTER.\n"
    .string "You with TEAM ROCKET… or Cipher?\p"
    .string "BROCK: Answer carefully.\n"
    .string "Pokemon are already in enough danger.$"

@ After deciding the player is on their side.

PewterCity_Text_Brock_TrustsPlayer:
    .string "BROCK: I see.\p"
    .string "Your eyes… They don't look like\n"
    .string "someone who fights for Cipher.\p"
    .string "BROCK: Sorry for the suspicion.\n"
    .string "These days, we can't be too careful.$"

@ Wes explains who he is + how he got here + Red/Michael/Cerulean base.

PewterCity_Text_Wes_Backstory:
    .string "WES: Name's WES.\n"
    .string "Used to run with TEAM SNAGEM.\p"
    .string "We helped steal POKEMON so Cipher\n"
    .string "could twist their hearts.\p"
    .string "WES: I walked away from all that.\n"
    .string "Then one day, everything… shifted.\p"
    .string "One battle, one explosion… and when\n"
    .string "I came to, I was here in KANTO.\p"
    .string "RED and a kid named MICHAEL helped\n"
    .string "me get my bearings.\p"
    .string "We set up a base near CERULEAN CITY to\n"
    .string "watch what Cipher and ROCKET are doing.$"

@ Wes gives the “prove yourself vs Brock, then meet me” pitch.

PewterCity_Text_Wes_Challenge:
    .string "WES: If you really want to help stop\n"
    .string "Cipher, I need to know you can handle\n"
    .string "yourself.\p"
    .string "BROCK here is PEWTER's GYM LEADER.\n"
    .string "Beat him, and I'll take you seriously.\p"
    .string "WES: Once you've earned his BADGE, find\n"
    .string "me at the hideout near CERULEAN.\p"
    .string "We'll talk about what comes next.$"

@ Brock encourages the gym battle.

PewterCity_Text_Brock_ToGym:
    .string "BROCK: I'm BROCK, PEWTER CITY's GYM\n"
    .string "LEADER.\p"
    .string "I've battled RED, BLUE, and plenty\n"
    .string "of strong trainers.\p"
    .string "If you want to stand against Cipher,\n"
    .string "show me your resolve in a GYM battle.\p"
    .string "BROCK: When you're ready, come to the\n"
    .string "GYM. I'll be waiting.$"

@ Wes heading back toward Cerulean after Brock leaves.

PewterCity_Text_Wes_HeadOut:
    .string "WES: Don't keep me waiting, kid.\p"
    .string "Beat BROCK, then head for CERULEAN.\n"
    .string "If you can handle that, maybe we can\n"
    .string "fight Cipher together.$"


@ -------------------------------
@ EXTRA PEWTER NPCS CAN GO BELOW
@ -------------------------------


