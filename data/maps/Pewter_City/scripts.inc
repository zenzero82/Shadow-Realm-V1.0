Pewter_City_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PewterCity_OnFrame
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

PewterCity_Speaker_Elias:
    .string "Elias$"
PewterCity_Speaker_Nina:
    .string "Nina$"
PewterCity_Speaker_Tess:
    .string "Tess$"

.set LOCALID_TWIN, 8



@ --------------------
@ Signs / existing NPCs
@ --------------------

PewterCity_OnFrame:
    map_script_2 VAR_TEMP_1, 0, PewterCity_EventScript_CityEnter
    .2byte 0

PewterCity_EventScript_CityEnter::
    setvar VAR_TEMP_1, 1
    setflag FLAG_VISITED_PEWTER_CITY
    checkflag FLAG_QUEST_PEWTER_NPCS_STARTED
    goto_if_eq PewterCity_EventScript_CityEnter_QuestSkip
    checkflag FLAG_QUEST_PEWTER_NPCS_COMPLETED
    goto_if_eq PewterCity_EventScript_CityEnter_QuestSkip
    lockall
    setflag FLAG_QUEST_PEWTER_NPCS_STARTED
    call QuestJournal_EventScript_NewQuestAlert
    releaseall
PewterCity_EventScript_CityEnter_QuestSkip:
    end

PewterCity_EventScript_CitySign::
    msgbox PewterCity_Text_Sign, MSGBOX_SIGN
    specialvar VAR_RESULT, TryClaimGimmighoulSignpost
    goto_if_eq VAR_RESULT, FALSE, PewterCity_EventScript_CitySign_Done
    lockall
    msgbox gText_GimmighoulSignpost, MSGBOX_DEFAULT
    showmonpic SPECIES_GIMMIGHOUL_ROAMING, 10, 3
    playmoncry SPECIES_GIMMIGHOUL, CRY_MODE_NORMAL
    waitmoncry
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8000, 25
    additem ITEM_GIMMIGHOUL_COIN, 25
    buffernumberstring STR_VAR_1, VAR_0x8000
    playfanfare MUS_OBTAIN_ITEM
    msgbox gText_GimmighoulCoinsObtained, MSGBOX_DEFAULT
    waitfanfare
    checkflag FLAG_QUEST_GIMMI_MY_MONEY_STARTED
    goto_if_eq PewterCity_EventScript_CitySign_Release
    applymovement LOCALID_TWIN, PewterCity_Movement_TwinApproachGimmighoulSign
    waitmovement 0
    setflag FLAG_QUEST_GIMMI_MY_MONEY_STARTED
    setflag FLAG_QUEST_PEWTER_NPC_TWIN
    call QuestJournal_EventScript_CheckPewterCityNPCs
    setspeaker PewterCity_Speaker_Tess
    msgbox PewterCity_Text_Twin_GimmighoulIntro, MSGBOX_DEFAULT
    closemessage
    call QuestJournal_EventScript_NewQuestAlert
PewterCity_EventScript_CitySign_Release:
    releaseall
PewterCity_EventScript_CitySign_Done:
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
    setflag FLAG_QUEST_PEWTER_NPC_FATMAN
    call QuestJournal_EventScript_CheckPewterCityNPCs
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

PewterCity_EventScript_BrockTalk::
    lock
    faceplayer
    goto_if_set FLAG_PEWTER_BROCK_WES_SCENE_DONE, PewterCity_EventScript_BrockTalk_Known
    setspeaker PewterCity_Speaker_Brock_Unknown
    msgbox PewterCity_Text_BrockTalk_Unknown, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_BrockTalk_Known::
    setspeaker PewterCity_Speaker_Brock
    msgbox PewterCity_Text_BrockTalk_Known, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_WesTalk::
    lock
    faceplayer
    goto_if_set FLAG_PEWTER_BROCK_WES_SCENE_DONE, PewterCity_EventScript_WesTalk_Known
    setspeaker PewterCity_Speaker_Wes_Unknown
    msgbox PewterCity_Text_WesTalk_Unknown, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_WesTalk_Known::
    setspeaker PewterCity_Speaker_Wes
    msgbox PewterCity_Text_WesTalk_Known, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_OldMan::
    lock
    faceplayer
    setspeaker PewterCity_Speaker_Elias
    msgbox PewterCity_Text_OldMan, MSGBOX_DEFAULT
    closemessage
    setflag FLAG_QUEST_PEWTER_NPC_OLD_MAN
    call QuestJournal_EventScript_CheckPewterCityNPCs
    checkflag FLAG_QUEST_MT_MOON_STARTED
    goto_if_eq PewterCity_EventScript_OldMan_Done
    checkflag FLAG_QUEST_MT_MOON_COMPLETED
    goto_if_eq PewterCity_EventScript_OldMan_Done
    checkflag FLAG_QUEST_BROCK_COMPLETED
    goto_if_eq PewterCity_EventScript_OldMan_GiveQuest
    goto PewterCity_EventScript_OldMan_Done
PewterCity_EventScript_OldMan_GiveQuest:
    setflag FLAG_QUEST_MT_MOON_STARTED
    call QuestJournal_EventScript_NewQuestAlert
PewterCity_EventScript_OldMan_Done:
    release
    end

PewterCity_EventScript_Lass::
    lock
    faceplayer
    setspeaker PewterCity_Speaker_Nina
    msgbox PewterCity_Text_Lass, MSGBOX_DEFAULT
    closemessage
    setflag FLAG_QUEST_PEWTER_NPC_LASS
    call QuestJournal_EventScript_CheckPewterCityNPCs
    release
    end

PewterCity_EventScript_Twin::
    lock
    faceplayer
    setflag FLAG_QUEST_PEWTER_NPC_TWIN
    call QuestJournal_EventScript_CheckPewterCityNPCs
    checkflag FLAG_QUEST_GIMMI_MY_MONEY_STARTED
    goto_if_eq PewterCity_EventScript_Twin_GiveClue
    setspeaker PewterCity_Speaker_Tess
    msgbox PewterCity_Text_Twin_PreGimmighoul, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_Twin_GiveClue::
    setspeaker PewterCity_Speaker_Tess
    msgbox PewterCity_Text_Twin_GimmighoulClue, MSGBOX_DEFAULT
    closemessage
    release
    end

PewterCity_EventScript_Geodude::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_GEODUDE, CRY_MODE_NORMAL
    waitmoncry
    release
    end

PewterCity_EventScript_Graveler::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_GRAVELER, CRY_MODE_NORMAL
    waitmoncry
    release
    end

PewterCity_EventScript_Rockruff::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_ROCKRUFF, CRY_MODE_NORMAL
    waitmoncry
    release
    end

QuestJournal_EventScript_CheckPewterCityNPCs::
    checkflag FLAG_QUEST_PEWTER_NPCS_COMPLETED
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_End
    checkflag FLAG_QUEST_PEWTER_NPCS_STARTED
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Fatman
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Fatman:
    checkflag FLAG_QUEST_PEWTER_NPC_FATMAN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_OldMan
    return
QuestJournal_EventScript_CheckPewterCityNPCs_OldMan:
    checkflag FLAG_QUEST_PEWTER_NPC_OLD_MAN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Lass
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Lass:
    checkflag FLAG_QUEST_PEWTER_NPC_LASS
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Twin
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Twin:
    checkflag FLAG_QUEST_PEWTER_NPC_TWIN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_House1Boy
    return
QuestJournal_EventScript_CheckPewterCityNPCs_House1Boy:
    checkflag FLAG_QUEST_PEWTER_NPC_HOUSE1_BOY
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_House2OldMan
    return
QuestJournal_EventScript_CheckPewterCityNPCs_House2OldMan:
    checkflag FLAG_QUEST_PEWTER_NPC_HOUSE2_OLD_MAN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_MuseumScientist1
    return
QuestJournal_EventScript_CheckPewterCityNPCs_MuseumScientist1:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM_SCIENTIST1
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_MuseumScientist2
    return
QuestJournal_EventScript_CheckPewterCityNPCs_MuseumScientist2:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM_SCIENTIST2
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_MuseumAttendant
    return
QuestJournal_EventScript_CheckPewterCityNPCs_MuseumAttendant:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM_ATTENDANT
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_MuseumHiker
    return
QuestJournal_EventScript_CheckPewterCityNPCs_MuseumHiker:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM_HIKER
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_MuseumOldMan
    return
QuestJournal_EventScript_CheckPewterCityNPCs_MuseumOldMan:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM_OLD_MAN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FNerd
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FNerd:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_NERD
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FBalding
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FBalding:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_BALDING
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FTwin
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Museum2FTwin:
    checkflag FLAG_QUEST_PEWTER_NPC_MUSEUM2F_TWIN
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_PokecenterBeauty
    return
QuestJournal_EventScript_CheckPewterCityNPCs_PokecenterBeauty:
    checkflag FLAG_QUEST_PEWTER_NPC_POKECENTER_BEAUTY
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_PokecenterBugCatcher
    return
QuestJournal_EventScript_CheckPewterCityNPCs_PokecenterBugCatcher:
    checkflag FLAG_QUEST_PEWTER_NPC_POKECENTER_BUG_CATCHER
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_PokemartLass
    return
QuestJournal_EventScript_CheckPewterCityNPCs_PokemartLass:
    checkflag FLAG_QUEST_PEWTER_NPC_POKEMART_LASS
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_PokemartYoungster
    return
QuestJournal_EventScript_CheckPewterCityNPCs_PokemartYoungster:
    checkflag FLAG_QUEST_PEWTER_NPC_POKEMART_YOUNGSTER
    goto_if_eq QuestJournal_EventScript_CheckPewterCityNPCs_Done
    return
QuestJournal_EventScript_CheckPewterCityNPCs_Done:
    setflag FLAG_QUEST_PEWTER_NPCS_COMPLETED
    call QuestJournal_EventScript_QuestCompleteAlert
QuestJournal_EventScript_CheckPewterCityNPCs_End:
    return


PewterCity_Text_Sign:
    .string "PEWTER CITY\n"
    .string "A Stone Gray City$"

PewterCity_Text_GymSign:
    .string "PEWTER CITY POKéMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "The Rock Solid POKéMON Trainer$"

PewterCity_Text_MuseumSign:
    .string "PEWTER MUSEUM OF SCIENCE\n"
    .string "OPEN DAILY\p"
    .string "Fossils, space, and rare stones on\n"
    .string "display.$"

PewterCity_Text_MtMoonGiftShopSign:
    .string "There's a notice here...\p"
    .string "MT.MOON GIFT SHOP NOW OPEN!$"

PewterCity_Text_WelcomeSign:
    .string "WELCOME TO PEWTER CITY!$"

PewterCity_Text_Woman:
    .string "The city feels tense lately.\p"
    .string "People whisper about TEAM\n"
    .string "ROCKET again...\p"
    .string "If they're really back, I hope\n"
    .string "the GYM LEADER keeps\l"
    .string "PEWTER safe.$"

PewterCity_Text_Fatman:
    .string "I heard the road toward\n"
    .string "MT. MOON has had\n"
    .string "strange sightings at night...\p"
    .string "Not just wild Pokemon.\n"
    .string "Something else too.$"

PewterCity_Text_Kid:
    .string "My dad says the TV glitches like it's\n"
    .string "showing a different world.\p"
    .string "That sounds scary...\n"
    .string "but kinda cool too.$"

PewterCity_Text_BrockTalk_Unknown:
    .string "...We should make sure the city is\n"
    .string "calm before the next challenge.$"

PewterCity_Text_BrockTalk_Known:
    .string "I'll be at the GYM if you want\n"
    .string "to test your strength.$"

PewterCity_Text_WesTalk_Unknown:
    .string "Hold on. I need to be sure you're not\n"
    .string "with them.$"

PewterCity_Text_WesTalk_Known:
    .string "Keep your eyes open on ROUTE 3.\n"
    .string "Things move fast there.$"

PewterCity_Text_OldMan:
    .string "Pewter's stones are steady, but the\n"
    .string "world feels shaken.\p"
    .string "Stock up before you head for\n"
    .string "MT. MOON.$"

PewterCity_Text_Lass:
    .string "The MUSEUM is my favorite spot.\p"
    .string "They say new exhibits are coming in\n"
    .string "from the mountain.$"

PewterCity_Text_Twin:
    .string "I count the rocks by the GYM for fun!\n"
    .string "There are sooo many!$"

PewterCity_Text_Twin_PreGimmighoul:
    .string "Hey! You should check out that sign\n"
    .string "over there.\p"
    .string "I think there is a POKeMON\n"
    .string "behind it.$"

PewterCity_Text_Twin_GimmighoulIntro:
    .string "Hey! That was a Gimmighoul!\p"
    .string "They like to hang out around sign\n"
    .string "posts and they often drop coins.\p"
    .string "My daddy told me that if you get 999\n"
    .string "coins they will evolve!\p"
    .string "He also told me that sometimes they\n"
    .string "will be in a chest and hanging around.\p"
    .string "Those ones normally keep more coins\n"
    .string "in their chests!\p"
    .string "You know stranger, you should try to\n"
    .string "find them all, seems like it will be fun!$"

PewterCity_Text_Twin_GimmighoulClue:
    .string "If you're still looking, I heard\n"
    .string "another one likes signs near MT. MOON.\p"
    .string "Maybe check the road east of town or\n"
    .string "the area outside the mountain!$"

PewterCity_Movement_TwinApproachGimmighoulSign:
    walk_right
    walk_right
    walk_right
    walk_right
    step_end



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
    checkflag FLAG_QUEST_BROCK_STARTED
    goto_if_eq PewterCity_EventScript_BrockWesScene_QuestSkip
    setflag FLAG_QUEST_BROCK_STARTED
    call QuestJournal_EventScript_NewQuestAlert
PewterCity_EventScript_BrockWesScene_QuestSkip:

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
    .string "TEAM ROCKET'S activity in KANTO is\n"
    .string "getting worse by the day.\p"
    .string "Ever since PROF. OAK vanished, the\n"
    .string "League's been scrambling.$"

PewterCity_Text_BrockWes_PrePlayer_Wes:
    .string "And every time someone gets close to\n"
    .string "CIPHER, the trail goes cold.$"

PewterCity_Text_BrockWes_PrePlayer_Brock2:
    .string "If CIPHER and ROCKET are working\n"
    .string "together then innocent Pokemon are\l"
    .string "the ones who pay the price.$"

PewterCity_Text_Wes_SeePlayer:
    .string "Hm?$"

PewterCity_Text_Brock_SeePlayer:
    .string "You there!$"

PewterCity_Text_Wes_Interrogate:
    .string "I haven't seen you around PEWTER.\n"
    .string "You with TEAM ROCKET... or CIPHER?$"

PewterCity_Text_Brock_TrustsPlayer:
    .string "Answer carefully.\n"
    .string "Pokemon are already in enough danger.\p"
    .string "...\p"
    .string "I see.\p"
    .string "Sorry for the suspicion.\n"
    .string "These days, we can't be too careful.$"

PewterCity_Text_Wes_IntroName:
    .string "Name's WES.\p"
    .string "Used to run with TEAM SNAGEM.$"

PewterCity_Text_Wes_Backstory:
    .string "We helped steal Pokemon so\n"
    .string "CIPHER could twist their\l"
    .string "hearts.\p"
    .string "I wanted out from all that.\p"
    .string "Then one day, everything shifted.\p"
    .string "One battle, one explosion...\n"
    .string "And when I came to,\l"
    .string "I was here in KANTO.\p"
    .string "RED and a kid named MICHAEL helped me\n"
    .string "get my bearings.\p"
    .string "We set up a base near\n"
    .string "CERULEAN CITY to watch\l"
    .string "what CIPHER and ROCKET are doing.$"

PewterCity_Text_Wes_Challenge:
    .string "If you really want to help\n"
    .string "stop CIPHER,\p"
    .string "I need to know you can\n"
    .string "handle yourself.\p"
    .string "PEWTER's GYM LEADER is strong.\n"
    .string "Beat him, and I'll take you\l"
    .string "seriously.\p"
    .string "Once you've earned his BADGE, find me\n"
    .string "at the hideout near CERULEAN.\p"
    .string "We'll talk about what comes next.$"

PewterCity_Text_Brock_IntroName:
    .string "I'm BROCK, PEWTER CITY's GYM LEADER.\p"
    .string "If you want to stand against CIPHER,\n"
    .string "show me your resolve.$"

PewterCity_Text_Brock_ToGym:
    .string "I've battled RED, GARY, and plenty of\n"
    .string "strong trainers.\p"
    .string "When you're ready, come to the GYM.\n"
    .string "I'll be waiting.$"

PewterCity_Text_Wes_HeadOut:
    .string "Don't keep me waiting, kid.\p"
    .string "Beat BROCK, then head for CERULEAN.\p"
    .string "If you can handle that, maybe we can\n"
    .string "fight CIPHER together.$"


@ -------------------------------
@ EXTRA PEWTER NPCS CAN GO BELOW
@ -------------------------------
