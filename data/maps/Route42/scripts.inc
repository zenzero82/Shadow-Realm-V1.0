Route42_MapScripts::
	.byte 0

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end


Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	goto EventScript_GimmighoulSignpost


Route42_Text_Sign1:
	.string "ROUTE 42\p"
	.string "ECRUTEAK CITY - MAHOGANY TOWN$"


Route42_Text_MtMortarSign1:
	.string "MT.MORTAR\p"
	.string "WATERFALL CAVE INSIDE$"
