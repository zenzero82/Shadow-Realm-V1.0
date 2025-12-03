Route1_MapScripts::
	.byte 0

Route1_EventScript_Torkin::
    trainerbattle_single TRAINER_TORKIN, Route1_Text_TorkinIntro, Route1_Text_TorkinDefeated
    msgbox Route1_Text_TorkinPostBattle, MSGBOX_AUTOCLOSE
    end
