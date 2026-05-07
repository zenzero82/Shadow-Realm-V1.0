celadon_apartmentroofhouse_MapScripts::
	.byte 0

celadon_apartmentroofhouse_Speaker_BlackBelt:
	.string "KENJI$"

celadon_apartmentroofhouse_EventScript_BlackBelt::
	faceplayer
	setspeaker celadon_apartmentroofhouse_Speaker_BlackBelt
	msgbox celadon_apartmentroofhouse_Text_BlackBelt, MSGBOX_NPC
	end

celadon_apartmentroofhouse_Text_BlackBelt:
	.string "I train here to keep my focus.\p"
	.string "The city noise fades on the roof.$"
