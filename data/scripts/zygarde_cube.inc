Common_EventScript_ZygardeCubePickup::
	lock
	getobjectfacingdirection VAR_LAST_TALKED, VAR_RESULT
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Common_EventScript_ZygardeCubeCell
	compare VAR_RESULT, DIR_WEST
	goto_if_eq Common_EventScript_ZygardeCubeCore
	goto Common_EventScript_ZygardeCubeItem

Common_EventScript_ZygardeCubeCell:
	addvar VAR_ZYGARDE_CELL_COUNT, 1
	goto_if_gt VAR_ZYGARDE_CELL_COUNT, 95, Common_EventScript_ZygardeCubeCellCap
	goto Common_EventScript_ZygardeCubeCellMessage

Common_EventScript_ZygardeCubeCellCap:
	setvar VAR_ZYGARDE_CELL_COUNT, 95

Common_EventScript_ZygardeCubeCellMessage:
	msgbox ZygardeCube_Text_GotCell, MSGBOX_DEFAULT
	goto Common_EventScript_ZygardeCubeFinish

Common_EventScript_ZygardeCubeCore:
	addvar VAR_ZYGARDE_CORE_COUNT, 1
	goto_if_gt VAR_ZYGARDE_CORE_COUNT, 5, Common_EventScript_ZygardeCubeCoreCap
	goto Common_EventScript_ZygardeCubeCoreMessage

Common_EventScript_ZygardeCubeCoreCap:
	setvar VAR_ZYGARDE_CORE_COUNT, 5

Common_EventScript_ZygardeCubeCoreMessage:
	msgbox ZygardeCube_Text_GotCore, MSGBOX_DEFAULT
	goto Common_EventScript_ZygardeCubeFinish

Common_EventScript_ZygardeCubeItem:
	giveitem ITEM_ZYGARDE_CUBE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox ZygardeCube_Text_GotCube, MSGBOX_DEFAULT

Common_EventScript_ZygardeCubeFinish:
	compare VAR_ZYGARDE_CELL_COUNT, 95
	goto_if_ne Common_EventScript_ZygardeCubeFinish_NoComplete
	compare VAR_ZYGARDE_CORE_COUNT, 5
	goto_if_ne Common_EventScript_ZygardeCubeFinish_NoComplete
	setflag FLAG_QUEST_100_POWER_COMPLETED
Common_EventScript_ZygardeCubeFinish_NoComplete:
	special SetLastTalkedObjectFlag
	removeobject VAR_LAST_TALKED
	release
	end

ZygardeCube_Text_GotCell:
	.string "You found a ZYGARDE\n"
	.string "Cell!$"

ZygardeCube_Text_GotCore:
	.string "You found a ZYGARDE\n"
	.string "Core!$"

ZygardeCube_Text_GotCube:
	.string "You obtained the ZYGARDE\n"
	.string "Cube!$"
