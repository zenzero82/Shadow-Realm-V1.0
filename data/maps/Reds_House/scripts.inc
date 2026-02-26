Reds_House_MapScripts::
	.byte 0

Speaker_RedsMom:
	.string "Red's Mom$"

Speaker_Broadcaster:
	.string "Broadcaster$"

PalletTown_RedsHouse_1F_EventScript_MomTrigger::
	checkflag FLAG_REDS_HOUSE_MOM_INTRO_DONE
	goto_if_eq PalletTown_RedsHouse_1F_EventScript_MomTrigger_Done

	lockall
	playse SE_PIN
	applymovement 1, RedsHouse_Move_Mom_ExclaimFaceDown
	waitmovement 0
	call PalletTown_RedsHouse_1F_EventScript_MomSpeech
	releaseall
	end

PalletTown_RedsHouse_1F_EventScript_MomTrigger_Done::
	end

PalletTown_RedsHouse_1F_EventScript_MomTalk::
	lock
	faceplayer
	goto_if_set FLAG_REDS_HOUSE_MOM_INTRO_DONE, PalletTown_RedsHouse_1F_EventScript_MomRepeat
	call PalletTown_RedsHouse_1F_EventScript_MomSpeech
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomRepeat::
	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomRestAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RedsHouse_1F_EventScript_MomRepeat_No
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreenswapbuffers FADE_FROM_BLACK
	goto PalletTown_RedsHouse_1F_EventScript_MomRepeat_Line

PalletTown_RedsHouse_1F_EventScript_MomRepeat_No::
	closemessage
	goto PalletTown_RedsHouse_1F_EventScript_MomRepeat_Line

PalletTown_RedsHouse_1F_EventScript_MomRepeat_Line::
	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomRepeatLine, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomSpeech::
	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomIntro_1, MSGBOX_DEFAULT
	closemessage

	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomIntro_2, MSGBOX_DEFAULT
	closemessage

	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomIntro_3, MSGBOX_DEFAULT
	closemessage

	setspeaker Speaker_RedsMom
	msgbox RedsHouse_Text_MomRepeatLine, MSGBOX_DEFAULT
	closemessage

	setflag FLAG_REDS_HOUSE_MOM_INTRO_DONE
	setvar VAR_TEMP_0, 1
	return

PalletTown_RedsHouse_1F_EventScript_TV::
	setspeaker Speaker_Broadcaster
	playbgm MUS_NEWSORRE, FALSE
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	fadedefaultbgm
	end

RedsHouse_Move_Mom_ExclaimFaceDown:
	emote_exclamation_mark
	face_down
	step_end

RedsHouse_Text_MomIntro_1:
	.string "Oh! Is that you, RED??\p"
	.string "Sorry, who are you?\p"
	.string "...Came through a portal, you say?\n"
	.string "Ah, it's part of the strange\l"
	.string "activities happening in KANTO!$"

RedsHouse_Text_MomIntro_2:
	.string "I thought you were my son RED\n"
	.string "as I haven't seen him in such a\l"
	.string "long time.$"

RedsHouse_Text_MomIntro_3:
	.string "He doesn't answer much ever since\n"
	.string "he became Champion, and I am worried\l"
	.string "about him with all these crazy things\l"
	.string "going on.\p"
	.string "Speaking of crazy things, you must be\n"
	.string "so tired and confused right now.\p"
	.string "You can use his bed to rest if you want.\p"
	.string "It's not like he's ever home to use it.$"

RedsHouse_Text_MomRepeatLine:
	.string "If you see RED, can you please\n"
	.string "tell him to come home and visit!$"

RedsHouse_Text_MomRestAsk:
	.string "Do you want to rest?$"

RedsHouse_Text_TV:
	.string "PROF. OAK has been missing for \n"
	.string "quite some time.\p"
	.string "Since he has been gone we have\l"
	.string "seen an increase in ROCKET activity.\p"
	.string "They seem to have invaded\n"
	.string "VIRIDIAN CITY.\l"
	.string "Please be safe out there.$"
