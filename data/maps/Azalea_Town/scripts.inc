Azalea_Town_MapScripts::
	.byte 0


__stub_Azalea_Town::
	end


AzaleaTown_EventScript_GymSign::
	msgbox AzaleaTown_EventScript_GymSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_GymSign_Text:
	.string "A POKéMON GYM statue.$"

AzaleaTown_EventScript_KurtSign::
	msgbox AzaleaTown_EventScript_KurtSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtSign_Text:
	.string "KURT'S HOUSE.$"

AzaleaTown_EventScript_IlexSign::
	msgbox AzaleaTown_EventScript_IlexSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_IlexSign_Text:
	.string "ILEX FOREST AHEAD.$"

AzaleaTown_EventScript_KilnSign::
	msgbox AzaleaTown_EventScript_KilnSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KilnSign_Text:
	.string "KURT'S CHARCOAL KILN.$"

AzaleaTown_EventScript_WellSign::
	msgbox AzaleaTown_EventScript_WellSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_WellSign_Text:
	.string "SLOWPOKE WELL.$"

AzaleaTown_EventScript_AzaleaSign::
	msgbox AzaleaTown_EventScript_AzaleaSign_Text, MSGBOX_SIGN
	end

AzaleaTown_EventScript_AzaleaSign_Text:
	.string "It's a sign.$"

AzaleaTown_EventScript_Youngster::
	faceplayer
	msgbox AzaleaTown_Text_Youngster, MSGBOX_NPC
	end

AzaleaTown_EventScript_Lass::
	faceplayer
	msgbox AzaleaTown_Text_Lass, MSGBOX_NPC
	end

AzaleaTown_EventScript_Rocket::
	faceplayer
	msgbox AzaleaTown_Text_Rocket, MSGBOX_NPC
	end

AzaleaTown_Text_Youngster:
	.string "BUGSY's gym is buzzing.\n"
	.string "I'm training up before I go in.$"

AzaleaTown_Text_Lass:
	.string "KURT's work keeps this town going.\n"
	.string "His balls are the best.$"

AzaleaTown_Text_Rocket:
	.string "Can't let you pass kid.$"
