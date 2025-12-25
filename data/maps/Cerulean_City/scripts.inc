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
@ NPC: Cooltrainer M (Power Plant info becomes "odd activity east")
@ =================================================

CeruleanCity_EventScript_CooltrainerM1::
    @ If you still have FLAG_RETURNED_MACHINE_PART in your project, keep this.
    @ Otherwise, swap it to your own story flag (or remove the goto_if_set block).
    @goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
    msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
    end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
    msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
    end


@ =================================================
@ NPC: Super Nerd / Boy (Cape becomes "reports + hidden entrance rumors")
@ =================================================

CeruleanCity_EventScript_Boy::
    msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
    end


@ =================================================
@ NPC: Guard at Cerulean Cave (story-appropriate warning)
@ =================================================

CeruleanCity_EventScript_Guard::
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
    msgbox CeruleanCity_Text_Slowbro_Stub, MSGBOX_NPC
    end

CeruleanCity_EventScript_SlowbroWoman::
    msgbox CeruleanCity_Text_SlowbroWoman_Stub, MSGBOX_NPC
    end


@ =================================================
@ NPC: Fisher (Rocket tip -> Cipher/Rocket “men in black” tip)
@ =================================================

CeruleanCity_EventScript_Fisher::
    @ If you use VAR_CERULEAN_CITY_STATE in your project, keep this.
    @ Otherwise remove the goto_if_eq and just show the normal text.
    @goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
    msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
    end

CeruleanCity_EventScript_FisherDuringRocket::
    msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
    end


@ =================================================
@ NPC: Youngster (leans into "shadow rumors")
@ =================================================

CeruleanCity_EventScript_Youngster::
    msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
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
    .string "POKeMON GYM\n"
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
