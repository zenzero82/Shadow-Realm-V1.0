Route26_House2_MapScripts::
	.byte 0

Route26_House2_Speaker_Artist:
	.string "ARTIST$"

Route26_House2_Speaker_Lady:
	.string "RESIDENT$"

Route26_House2_EventScript_Artist::
	lock
	faceplayer
	setspeaker Route26_House2_Speaker_Artist
	checkitem ITEM_PHOTO_CAMERA
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_Artist_AfterGift
	msgbox Route26_House2_Text_Artist_Intro, MSGBOX_DEFAULT
	giveitem ITEM_PHOTO_CAMERA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route26_House2_Text_Artist_GiveCamera, MSGBOX_DEFAULT
	release
	end

Route26_House2_EventScript_Artist_AfterGift::
	msgbox Route26_House2_Text_Artist_AfterGift, MSGBOX_DEFAULT
	release
	end

Route26_House2_EventScript_Lady::
	faceplayer
	setspeaker Route26_House2_Speaker_Lady
	msgbox Route26_House2_Text_Lady, MSGBOX_NPC
	end

Route26_House2_Text_Artist_Intro:
	.string "I used to love capturing moments with\n"
	.string "photography.\p"
	.string "These days I prefer paint.\n"
	.string "A brush lets me hold onto the feeling\l"
	.string "of a scene, not just the image.\p"
	.string "Still, a CAMERA is useful when\n"
	.string "something beautiful appears before\l"
	.string "the paint can dry.$"

Route26_House2_Text_Artist_GiveCamera:
	.string "Here, take this PHOTO CAMERA.\p"
	.string "Use it when you find a scene worth\n"
	.string "remembering.$"

Route26_House2_Text_Artist_AfterGift:
	.string "Paint can wait for the studio.\p"
	.string "A camera is perfect for catching the\n"
	.string "moment before it slips away.$"

Route26_House2_Text_Lady:
	.string "ROUTE 26 feels peaceful indoors, but\n"
	.string "the trainers outside are always pushing\l"
	.string "toward the LEAGUE.$"
