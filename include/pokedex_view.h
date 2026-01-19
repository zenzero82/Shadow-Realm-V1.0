#ifndef GUARD_POKEDEX_VIEW_H
#define GUARD_POKEDEX_VIEW_H

#include "global.h"

#ifndef MAX_MONS_ON_SCREEN
#define MAX_MONS_ON_SCREEN 4
#endif

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount;
    u16 shadowListCount;
    u8 shadowStateList[MAX_SHADOW_MON_IDS];
    u16 shadowIdList[MAX_SHADOW_MON_IDS];
    u16 selectedPokemon;
    u16 selectedPokemonBackup;
    u16 dexMode;
    u16 dexModeBackup;
    u16 dexOrder;
    u16 dexOrderBackup;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 selectedMonSpriteId;
    u16 pokeBallRotationStep;
    u16 pokeBallRotationBackup;
    u8 pokeBallRotation;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u16 unkArr1[4];
    u8 filler[8];
    u8 currentPage;
    u8 currentPageBackup;
    bool8 isSearchResults:1;
    u8 selectedScreen;
    u8 screenSwitchState;
    u8 menuIsOpen;
    u16 menuCursorPos;
    s16 menuY;
    u8 unkArr2[8];
    u8 unkArr3[8];
};

extern EWRAM_DATA struct PokedexView *sPokedexView;

#endif // GUARD_POKEDEX_VIEW_H
