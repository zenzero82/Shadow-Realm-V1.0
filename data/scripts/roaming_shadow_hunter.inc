@ Example scripts for the roaming shadow hunter system.
@ These are stubs; wire them into each spawn map's scripts as needed.

RoamingHunter_OnMapLoad::
RoamingHunter_CheckSpawn::
	special RoamingHunter_TryCreateNpcOnMap
	goto_if_eq VAR_RESULT, 0, RoamingHunter_HideNpc
	@ Kanto maps use fixed Cassidy/Butch gfx; other maps can use VAR_OBJ_GFX_ID_0.
	clearflag FLAG_ROAMING_HUNTER_NPC_HIDE
	end

RoamingHunter_HideNpc::
	setflag FLAG_ROAMING_HUNTER_NPC_HIDE
	end

RoamingHunter_NpcScript::
	lock
	faceplayer
	special PlayTrainerEncounterMusic
	special RoamingHunter_StartBattle
	waitstate
	special RoamingHunter_OnBattleWon
	release
	end
