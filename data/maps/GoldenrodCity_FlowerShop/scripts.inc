GoldenrodCity_FlowerShop_MapScripts::
	.byte 0

GoldenrodCity_FlowerShop_Speaker_Lily:
	.string "LILY$"

GoldenrodCity_FlowerShop_Speaker_Rose:
	.string "ROSE$"

GoldenrodCity_FlowerShop_Speaker_Poppy:
	.string "POPPY$"

GoldenrodCity_FlowerShop_EventScript_Lily::
	lock
	faceplayer
	setspeaker GoldenrodCity_FlowerShop_Speaker_Lily
	msgbox GoldenrodCity_FlowerShop_Text_Lily, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_Rose::
	lock
	faceplayer
	setspeaker GoldenrodCity_FlowerShop_Speaker_Rose
	msgbox GoldenrodCity_FlowerShop_Text_Rose, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_Poppy::
	lock
	faceplayer
	setspeaker GoldenrodCity_FlowerShop_Speaker_Poppy
	msgbox GoldenrodCity_FlowerShop_Text_Poppy, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_Text_Lily:
	.string "Flowers help people breathe again.\n"
	.string "That's worth staying open for.$"

GoldenrodCity_FlowerShop_Text_Rose:
	.string "I keep bright bouquets in the window.\n"
	.string "If those black-uniformed creeps want\n"
	.string "to scare people, they can glare at\n"
	.string "the flowers first.$"

GoldenrodCity_FlowerShop_Text_Poppy:
	.string "My favorite flowers are the ones that\n"
	.string "grow back after being stepped on.$"
