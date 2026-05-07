#ifndef GUARD_FIELD_SPECIALS_H
#define GUARD_FIELD_SPECIALS_H

extern bool8 gBikeCyclingChallenge;
extern u8 gBikeCollisions;
extern u16 gScrollableMultichoice_ScrollOffset;

u8 GetLeadMonIndex(void);
bool8 IsDestinationBoxFull(void);
u16 GetPCBoxToSendMon(void);
bool8 InMultiPartnerRoom(void);
void UpdateTrainerFansAfterLinkBattle(void);
void IncrementBirthIslandRockStepCount(void);
bool8 AbnormalWeatherHasExpired(void);
bool8 ShouldDoBrailleRegicePuzzle(void);
bool32 ShouldDoWallyCall(void);
bool32 ShouldDoScottFortreeCall(void);
bool32 ShouldDoScottBattleFrontierCall(void);
bool32 ShouldDoRoxanneCall(void);
bool32 ShouldDoRivalRayquazaCall(void);
bool32 CountSSTidalStep(u16 delta);
u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y);
void ShowScrollableMultichoice(void);
void FrontierGamblerSetWonOrLost(bool8 won);
u8 TryGainNewFanFromCounter(u8 incrementId);
bool8 InPokemonCenter(void);
void SetShoalItemFlag(u16 unused);
void UpdateFrontierManiac(u16 daysSince);
void UpdateFrontierGambler(u16 daysSince);
void ResetCyclingRoadChallengeData(void);
bool8 UsedPokemonCenterWarp(void);
void ResetFanClub(void);
bool8 ShouldShowBoxWasFullMessage(void);
void SetPCBoxToSendMon(u8 boxId);
void PreparePartyForSkyBattle(void);
void GetObjectPosition(u16*, u16*, u32, u32);
bool32 CheckObjectAtXY(u32, u32);
bool32 CheckPartyHasSpecies(u32);
void Special_Kukui_CheckShadowMeowthInParty(void);
void Special_Kukui_TakeShadowMeowth(void);
void Special_Kukui_ReturnShadowMeowth(void);
u16 Special_OverworldWildEncounters_OnReturnToField(void);
u16 Special_OverworldWildEncounters_OnMapLoad(void);
void Special_KurtApricornMenu(void);
u16 Special_HeadbuttTree(void);
u16 Special_HeadbuttTree_StartBattle(void);
u16 SuppressGimmighoulSignpost(void);
u16 TryClaimGimmighoulSignpost(void);
void Special_LockPlayerFacingDown(void);
void Special_ClearPlayerFacingOverride(void);
void Special_SetObjectPriorityHigh(void);
void Special_RestoreNebbyFollower(void);
void Special_ApplyCipherDisguise(void);
void Special_RestorePlayerAvatarGraphics(void);
void SetLastTalkedObjectFlag(void);
u16 IsHoldingAButton(void);

#endif // GUARD_FIELD_SPECIALS_H
