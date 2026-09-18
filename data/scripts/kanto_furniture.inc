Kanto_Furniture_EventScript_Bookshelf_Pallet::
	msgbox Kanto_Furniture_Text_Bookshelf_Pallet, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_Bookshelf_Viridian::
	msgbox Kanto_Furniture_Text_Bookshelf_Viridian, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_Bookshelf_Pewter::
	msgbox Kanto_Furniture_Text_Bookshelf_Pewter, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_Bookshelf_Cerulean::
	msgbox Kanto_Furniture_Text_Bookshelf_Cerulean, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_Bookshelf_Lavender::
	msgbox Kanto_Furniture_Text_Bookshelf_Lavender, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_TV_Pallet::
	msgbox Kanto_Furniture_Text_TV_Pallet, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_TV_Viridian::
	msgbox Kanto_Furniture_Text_TV_Viridian, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_TV_Pewter::
	msgbox Kanto_Furniture_Text_TV_Pewter, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_TV_Cerulean::
	msgbox Kanto_Furniture_Text_TV_Cerulean, MSGBOX_SIGN
	end

Kanto_Furniture_EventScript_TV_Lavender::
	msgbox Kanto_Furniture_Text_TV_Lavender, MSGBOX_SIGN
	end

RouteHouse_Furniture_EventScript_Bookshelf_Kanto::
	msgbox RouteHouse_Furniture_Text_Bookshelf_Kanto, MSGBOX_SIGN
	end

RouteHouse_Furniture_EventScript_Bookshelf_Johto::
	msgbox RouteHouse_Furniture_Text_Bookshelf_Johto, MSGBOX_SIGN
	end

RouteHouse_Furniture_EventScript_TV::
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	callnative RouteHouse_TV_TryStartBroadcast
	goto_if_eq VAR_RESULT, FALSE, RouteHouse_Furniture_EventScript_TV_NoBroadcast
	msgbox RouteHouse_Furniture_Text_TV_Broadcast, MSGBOX_DEFAULT
	releaseall
	end

RouteHouse_Furniture_EventScript_TV_NoBroadcast::
	msgbox RouteHouse_Furniture_Text_TV_NoBroadcast, MSGBOX_DEFAULT
	releaseall
	end

RouteHouse_Furniture_Text_Bookshelf_Kanto:
	.string "It is crammed with old field guides,\n"
	.string "route maps, and worn notebooks from\l"
	.string "past trips.$"

RouteHouse_Furniture_Text_Bookshelf_Johto:
	.string "These shelves are filled with travel\n"
	.string "journals and local wildlife guides\l"
	.string "from all across JOHTO.$"

RouteHouse_Furniture_Text_TV_Broadcast:
	.string "A breaking wild POKéMON bulletin is\n"
	.string "on the air!\p"
	.string "{STR_VAR_1} have been reported around\n"
	.string "{STR_VAR_2} more than usual.\p"
	.string "The anchor warns that these sightings\n"
	.string "may include unusual Abilities and\l"
	.string "rare moves.$"

RouteHouse_Furniture_Text_TV_NoBroadcast:
	.string "The TV is running a quiet local news\n"
	.string "hour.\p"
	.string "No special wild POKéMON bulletin is\n"
	.string "airing right now.$"
