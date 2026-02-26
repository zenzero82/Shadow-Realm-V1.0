#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) ((x) < NUM_PALS_IN_PRIMARY ? 1 << (x) : 1 << ((x) - NUM_PALS_IN_PRIMARY))

const struct Tileset gTileset_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};

const struct Tileset gTileset_Rustboro =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro,
    .palettes = gTilesetPalettes_Rustboro,
    .metatiles = gMetatiles_Rustboro,
    .metatileAttributes = gMetatileAttributes_Rustboro,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_Dewford =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Dewford,
    .palettes = gTilesetPalettes_Dewford,
    .metatiles = gMetatiles_Dewford,
    .metatileAttributes = gMetatileAttributes_Dewford,
    .callback = InitTilesetAnim_Dewford,
};

const struct Tileset gTileset_Slateport =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Slateport,
    .palettes = gTilesetPalettes_Slateport,
    .metatiles = gMetatiles_Slateport,
    .metatileAttributes = gMetatileAttributes_Slateport,
    .callback = InitTilesetAnim_Slateport,
};

const struct Tileset gTileset_Mauville =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mauville,
    .palettes = gTilesetPalettes_Mauville,
    .metatiles = gMetatiles_Mauville,
    .metatileAttributes = gMetatileAttributes_Mauville,
    .callback = InitTilesetAnim_Mauville,
};

const struct Tileset gTileset_Lavaridge =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge,
    .palettes = gTilesetPalettes_Lavaridge,
    .metatiles = gMetatiles_Lavaridge,
    .metatileAttributes = gMetatileAttributes_Lavaridge,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Fallarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fallarbor,
    .palettes = gTilesetPalettes_Fallarbor,
    .metatiles = gMetatiles_Fallarbor,
    .metatileAttributes = gMetatileAttributes_Fallarbor,
    .callback = InitTilesetAnim_Fallarbor,
};

const struct Tileset gTileset_Fortree =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fortree,
    .palettes = gTilesetPalettes_Fortree,
    .metatiles = gMetatiles_Fortree,
    .metatileAttributes = gMetatileAttributes_Fortree,
    .callback = InitTilesetAnim_Fortree,
};

const struct Tileset gTileset_Lilycove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lilycove,
    .palettes = gTilesetPalettes_Lilycove,
    .metatiles = gMetatiles_Lilycove,
    .metatileAttributes = gMetatileAttributes_Lilycove,
    .callback = InitTilesetAnim_Lilycove,
};

const struct Tileset gTileset_Mossdeep =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mossdeep,
    .palettes = gTilesetPalettes_Mossdeep,
    .metatiles = gMetatiles_Mossdeep,
    .metatileAttributes = gMetatileAttributes_Mossdeep,
    .callback = InitTilesetAnim_Mossdeep,
};

const struct Tileset gTileset_EverGrande =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EverGrande,
    .palettes = gTilesetPalettes_EverGrande,
    .metatiles = gMetatiles_EverGrande,
    .metatileAttributes = gMetatileAttributes_EverGrande,
    .callback = InitTilesetAnim_EverGrande,
};

const struct Tileset gTileset_Pacifidlog =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog,
    .palettes = gTilesetPalettes_Pacifidlog,
    .metatiles = gMetatiles_Pacifidlog,
    .metatileAttributes = gMetatileAttributes_Pacifidlog,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_Sootopolis =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sootopolis,
    .palettes = gTilesetPalettes_Sootopolis,
    .metatiles = gMetatiles_Sootopolis,
    .metatileAttributes = gMetatileAttributes_Sootopolis,
    .callback = InitTilesetAnim_Sootopolis,
};

const struct Tileset gTileset_BattleFrontierOutsideWest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideWest,
    .palettes = gTilesetPalettes_BattleFrontierOutsideWest,
    .metatiles = gMetatiles_BattleFrontierOutsideWest,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideWest,
    .callback = InitTilesetAnim_BattleFrontierOutsideWest,
};

const struct Tileset gTileset_BattleFrontierOutsideEast =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideEast,
    .palettes = gTilesetPalettes_BattleFrontierOutsideEast,
    .metatiles = gMetatiles_BattleFrontierOutsideEast,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideEast,
    .callback = InitTilesetAnim_BattleFrontierOutsideEast,
};

const struct Tileset gTileset_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding,
    .palettes = gTilesetPalettes_InsideBuilding,
    .metatiles = gMetatiles_InsideBuilding,
    .metatileAttributes = gMetatileAttributes_InsideBuilding,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_Shop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop,
    .palettes = gTilesetPalettes_Shop,
    .metatiles = gMetatiles_Shop,
    .metatileAttributes = gMetatileAttributes_Shop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter,
    .palettes = gTilesetPalettes_PokemonCenter,
    .metatiles = gMetatiles_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_Cave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave,
    .palettes = gTilesetPalettes_Cave,
    .metatiles = gMetatiles_Cave,
    .metatileAttributes = gMetatileAttributes_Cave,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_PokemonSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonSchool,
    .palettes = gTilesetPalettes_PokemonSchool,
    .metatiles = gMetatiles_PokemonSchool,
    .metatileAttributes = gMetatileAttributes_PokemonSchool,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonFanClub =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonFanClub,
    .palettes = gTilesetPalettes_PokemonFanClub,
    .metatiles = gMetatiles_PokemonFanClub,
    .metatileAttributes = gMetatileAttributes_PokemonFanClub,
    .callback = NULL,
};

const struct Tileset gTileset_Unused1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused1,
    .palettes = gTilesetPalettes_Unused1,
    .metatiles = gMetatiles_Unused1,
    .metatileAttributes = gMetatileAttributes_Unused1,
    .callback = NULL,
};

const struct Tileset gTileset_MeteorFalls =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls,
    .palettes = gTilesetPalettes_MeteorFalls,
    .metatiles = gMetatiles_MeteorFalls,
    .metatileAttributes = gMetatileAttributes_MeteorFalls,
    .callback = NULL,
};

const struct Tileset gTileset_OceanicMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OceanicMuseum,
    .palettes = gTilesetPalettes_OceanicMuseum,
    .metatiles = gMetatiles_OceanicMuseum,
    .metatileAttributes = gMetatileAttributes_OceanicMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub,
    .palettes = gTilesetPalettes_CableClub,
    .metatiles = gMetatiles_CableClub,
    .metatileAttributes = gMetatileAttributes_CableClub,
    .callback = NULL,
};

const struct Tileset gTileset_SeashoreHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeashoreHouse,
    .palettes = gTilesetPalettes_SeashoreHouse,
    .metatiles = gMetatiles_SeashoreHouse,
    .metatileAttributes = gMetatileAttributes_SeashoreHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PrettyPetalFlowerShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PrettyPetalFlowerShop,
    .palettes = gTilesetPalettes_PrettyPetalFlowerShop,
    .metatiles = gMetatiles_PrettyPetalFlowerShop,
    .metatileAttributes = gMetatileAttributes_PrettyPetalFlowerShop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare,
    .palettes = gTilesetPalettes_PokemonDayCare,
    .metatiles = gMetatiles_PokemonDayCare,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_Facility =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Facility,
    .palettes = gTilesetPalettes_Facility,
    .metatiles = gMetatiles_Facility,
    .metatileAttributes = gMetatileAttributes_Facility,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop,
    .palettes = gTilesetPalettes_BikeShop,
    .metatiles = gMetatiles_BikeShop,
    .metatileAttributes = gMetatileAttributes_BikeShop,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_RusturfTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RusturfTunnel,
    .palettes = gTilesetPalettes_RusturfTunnel,
    .metatiles = gMetatiles_RusturfTunnel,
    .metatileAttributes = gMetatileAttributes_RusturfTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_InsideOfTruck =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideOfTruck,
    .palettes = gTilesetPalettes_InsideOfTruck,
    .metatiles = gMetatiles_InsideOfTruck,
    .metatileAttributes = gMetatileAttributes_InsideOfTruck,
    .callback = NULL,
};

const struct Tileset gTileset_Unused2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused2,
    .palettes = gTilesetPalettes_Unused2,
    .metatiles = gMetatiles_Unused2,
    .metatileAttributes = gMetatileAttributes_Unused2,
    .callback = NULL,
};

const struct Tileset gTileset_Contest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Contest,
    .palettes = gTilesetPalettes_Contest,
    .metatiles = gMetatiles_Contest,
    .metatileAttributes = gMetatileAttributes_Contest,
    .callback = NULL,
};

const struct Tileset gTileset_LilycoveMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LilycoveMuseum,
    .palettes = gTilesetPalettes_LilycoveMuseum,
    .metatiles = gMetatiles_LilycoveMuseum,
    .metatileAttributes = gMetatileAttributes_LilycoveMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_BrendansMaysHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BrendansMaysHouse,
    .palettes = gTilesetPalettes_BrendansMaysHouse,
    .metatiles = gMetatiles_BrendansMaysHouse,
    .metatileAttributes = gMetatileAttributes_BrendansMaysHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab,
    .palettes = gTilesetPalettes_Lab,
    .metatiles = gMetatiles_Lab,
    .metatileAttributes = gMetatileAttributes_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_Underwater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Underwater,
    .palettes = gTilesetPalettes_Underwater,
    .metatiles = gMetatiles_Underwater,
    .metatileAttributes = gMetatileAttributes_Underwater,
    .callback = InitTilesetAnim_Underwater,
};

const struct Tileset gTileset_PetalburgGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PetalburgGym,
    .palettes = gTilesetPalettes_PetalburgGym,
    .metatiles = gMetatiles_PetalburgGym,
    .metatileAttributes = gMetatileAttributes_PetalburgGym,
    .callback = NULL,
};

const struct Tileset gTileset_SootopolisGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym,
    .palettes = gTilesetPalettes_SootopolisGym,
    .metatiles = gMetatiles_SootopolisGym,
    .metatileAttributes = gMetatileAttributes_SootopolisGym,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_GenericBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding,
    .palettes = gTilesetPalettes_GenericBuilding,
    .metatiles = gMetatiles_GenericBuilding,
    .metatileAttributes = gMetatileAttributes_GenericBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGameCorner,
    .palettes = gTilesetPalettes_MauvilleGameCorner,
    .metatiles = gMetatiles_MauvilleGameCorner,
    .metatileAttributes = gMetatileAttributes_MauvilleGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_RustboroGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RustboroGym,
    .palettes = gTilesetPalettes_RustboroGym,
    .metatiles = gMetatiles_RustboroGym,
    .metatileAttributes = gMetatileAttributes_RustboroGym,
    .callback = NULL,
};

const struct Tileset gTileset_DewfordGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DewfordGym,
    .palettes = gTilesetPalettes_DewfordGym,
    .metatiles = gMetatiles_DewfordGym,
    .metatileAttributes = gMetatileAttributes_DewfordGym,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGym,
    .palettes = gTilesetPalettes_MauvilleGym,
    .metatiles = gMetatiles_MauvilleGym,
    .metatileAttributes = gMetatileAttributes_MauvilleGym,
    .callback = InitTilesetAnim_MauvilleGym,
};

const struct Tileset gTileset_LavaridgeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavaridgeGym,
    .palettes = gTilesetPalettes_LavaridgeGym,
    .metatiles = gMetatiles_LavaridgeGym,
    .metatileAttributes = gMetatileAttributes_LavaridgeGym,
    .callback = NULL,
};

const struct Tileset gTileset_TrickHousePuzzle =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrickHousePuzzle,
    .palettes = gTilesetPalettes_TrickHousePuzzle,
    .metatiles = gMetatiles_TrickHousePuzzle,
    .metatileAttributes = gMetatileAttributes_TrickHousePuzzle,
    .callback = NULL,
};

const struct Tileset gTileset_FortreeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FortreeGym,
    .palettes = gTilesetPalettes_FortreeGym,
    .metatiles = gMetatiles_FortreeGym,
    .metatileAttributes = gMetatileAttributes_FortreeGym,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGym,
    .palettes = gTilesetPalettes_MossdeepGym,
    .metatiles = gMetatiles_MossdeepGym,
    .metatileAttributes = gMetatileAttributes_MossdeepGym,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShip =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideShip,
    .palettes = gTilesetPalettes_InsideShip,
    .metatiles = gMetatiles_InsideShip,
    .metatileAttributes = gMetatileAttributes_InsideShip,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset *const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset *const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;

const struct Tileset gTileset_EliteFour =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFour,
    .palettes = gTilesetPalettes_EliteFour,
    .metatiles = gMetatiles_EliteFour,
    .metatileAttributes = gMetatileAttributes_EliteFour,
    .callback = InitTilesetAnim_EliteFour,
};

const struct Tileset gTileset_BattleFrontier =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontier,
    .palettes = gTilesetPalettes_BattleFrontier,
    .metatiles = gMetatiles_BattleFrontier,
    .metatileAttributes = gMetatileAttributes_BattleFrontier,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePalace =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePalace,
    .palettes = gTilesetPalettes_BattlePalace,
    .metatiles = gMetatiles_BattlePalace,
    .metatileAttributes = gMetatileAttributes_BattlePalace,
    .callback = NULL,
};

const struct Tileset gTileset_BattleDome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleDome,
    .palettes = gTilesetPalettes_BattleDome,
    .metatiles = gMetatiles_BattleDome,
    .metatileAttributes = gMetatileAttributes_BattleDome,
    .callback = InitTilesetAnim_BattleDome,
};

const struct Tileset gTileset_BattleFactory =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFactory,
    .palettes = gTilesetPalettes_BattleFactory,
    .metatiles = gMetatiles_BattleFactory,
    .metatileAttributes = gMetatileAttributes_BattleFactory,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePike =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePike,
    .palettes = gTilesetPalettes_BattlePike,
    .metatiles = gMetatiles_BattlePike,
    .metatileAttributes = gMetatileAttributes_BattlePike,
    .callback = NULL,
};

const struct Tileset gTileset_BattleArena =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleArena,
    .palettes = gTilesetPalettes_BattleArena,
    .metatiles = gMetatiles_BattleArena,
    .metatileAttributes = gMetatileAttributes_BattleArena,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePyramid =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePyramid,
    .palettes = gTilesetPalettes_BattlePyramid,
    .metatiles = gMetatiles_BattlePyramid,
    .metatileAttributes = gMetatileAttributes_BattlePyramid,
    .callback = InitTilesetAnim_BattlePyramid,
};

const struct Tileset gTileset_MirageTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MirageTower,
    .palettes = gTilesetPalettes_MirageTower,
    .metatiles = gMetatiles_MirageTower,
    .metatileAttributes = gMetatileAttributes_MirageTower,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGameCorner,
    .palettes = gTilesetPalettes_MossdeepGameCorner,
    .metatiles = gMetatiles_MossdeepGameCorner,
    .metatileAttributes = gMetatileAttributes_MossdeepGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor,
    .palettes = gTilesetPalettes_IslandHarbor,
    .metatiles = gMetatiles_IslandHarbor,
    .metatileAttributes = gMetatileAttributes_IslandHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill,
    .palettes = gTilesetPalettes_TrainerHill,
    .metatiles = gMetatiles_TrainerHill,
    .metatileAttributes = gMetatileAttributes_TrainerHill,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock,
    .palettes = gTilesetPalettes_NavelRock,
    .metatiles = gMetatiles_NavelRock,
    .metatileAttributes = gMetatileAttributes_NavelRock,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontierRankingHall =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierRankingHall,
    .palettes = gTilesetPalettes_BattleFrontierRankingHall,
    .metatiles = gMetatiles_BattleFrontierRankingHall,
    .metatileAttributes = gMetatileAttributes_BattleFrontierRankingHall,
    .callback = NULL,
};

const struct Tileset gTileset_BattleTent =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleTent,
    .palettes = gTilesetPalettes_BattleTent,
    .metatiles = gMetatiles_BattleTent,
    .metatileAttributes = gMetatileAttributes_BattleTent,
    .callback = NULL,
};

const struct Tileset gTileset_MysteryEventsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MysteryEventsHouse,
    .palettes = gTilesetPalettes_MysteryEventsHouse,
    .metatiles = gMetatiles_MysteryEventsHouse,
    .metatileAttributes = gMetatileAttributes_MysteryEventsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_UnionRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnionRoom,
    .palettes = gTilesetPalettes_UnionRoom,
    .metatiles = gMetatiles_UnionRoom,
    .metatileAttributes = gMetatileAttributes_UnionRoom,
    .callback = NULL,
};

const struct Tileset gTileset_FRLG_Town =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_FRLG_Town,
    .palettes = gTilesetPalettes_FRLG_Town,
    .metatiles = gMetatiles_FRLG_Town,
    .metatileAttributes = gMetatileAttributes_FRLG_Town,
    .callback = NULL,
};

const struct Tileset gTileset_kanto_inside =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_kanto_inside,
    .palettes = gTilesetPalettes_kanto_inside,
    .metatiles = gMetatiles_kanto_inside,
    .metatileAttributes = gMetatileAttributes_kanto_inside,
    .callback = NULL,
};

const struct Tileset gTileset_viridian =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_viridian,
    .palettes = gTilesetPalettes_viridian,
    .metatiles = gMetatiles_viridian,
    .metatileAttributes = gMetatileAttributes_viridian,
    .callback = NULL,
};

const struct Tileset gTileset_reds =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_reds,
    .palettes = gTilesetPalettes_reds,
    .metatiles = gMetatiles_reds,
    .metatileAttributes = gMetatileAttributes_reds,
    .callback = NULL,
};

const struct Tileset gTileset_oaks_lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_oaks_lab,
    .palettes = gTilesetPalettes_oaks_lab,
    .metatiles = gMetatiles_oaks_lab,
    .metatileAttributes = gMetatileAttributes_oaks_lab,
    .callback = NULL,
};

const struct Tileset gTileset_kanto_lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_kanto_lab,
    .palettes = gTilesetPalettes_kanto_lab,
    .metatiles = gMetatiles_kanto_lab,
    .metatileAttributes = gMetatileAttributes_kanto_lab,
    .callback = NULL,
};

const struct Tileset gTileset_frlg_pallet =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_frlg_pallet,
    .palettes = gTilesetPalettes_frlg_pallet,
    .metatiles = gMetatiles_frlg_pallet,
    .metatileAttributes = gMetatileAttributes_frlg_pallet,
    .callback = NULL,
};

const struct Tileset gTileset_Reds =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Reds,
    .palettes = gTilesetPalettes_Reds,
    .metatiles = gMetatiles_Reds,
    .metatileAttributes = gMetatileAttributes_Reds,
    .callback = NULL,
};

const struct Tileset gTileset_FRLG_Pallet =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FRLG_Pallet,
    .palettes = gTilesetPalettes_FRLG_Pallet,
    .metatiles = gMetatiles_FRLG_Pallet,
    .metatileAttributes = gMetatileAttributes_FRLG_Pallet,
    .callback = NULL,
};

const struct Tileset gTileset_johto_general =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_johto_general,
    .palettes = gTilesetPalettes_johto_general,
    .metatiles = gMetatiles_johto_general,
    .metatileAttributes = gMetatileAttributes_johto_general,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_azalea =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_azalea,
    .palettes = gTilesetPalettes_azalea,
    .metatiles = gMetatiles_azalea,
    .metatileAttributes = gMetatileAttributes_azalea,
    .callback = NULL,
};

const struct Tileset gTileset_pewter_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_pewter_gym,
    .palettes = gTilesetPalettes_pewter_gym,
    .metatiles = gMetatiles_pewter_gym,
    .metatileAttributes = gMetatileAttributes_pewter_gym,
    .callback = NULL,
};

const struct Tileset gTileset_celadon_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_celadon_gym,
    .palettes = gTilesetPalettes_celadon_gym,
    .metatiles = gMetatiles_celadon_gym,
    .metatileAttributes = gMetatileAttributes_celadon_gym,
    .callback = InitTilesetAnim_AzaleaTown_Gym,
};

const struct Tileset gTileset_cerulean_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cerulean_gym,
    .palettes = gTilesetPalettes_cerulean_gym,
    .metatiles = gMetatiles_cerulean_gym,
    .metatileAttributes = gMetatileAttributes_cerulean_gym,
    .callback = NULL,
};

const struct Tileset gTileset_vermilion_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_vermilion_gym,
    .palettes = gTilesetPalettes_vermilion_gym,
    .metatiles = gMetatiles_vermilion_gym,
    .metatileAttributes = gMetatileAttributes_vermilion_gym,
    .callback = NULL,
};

const struct Tileset gTileset_pewter_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_pewter_city,
    .palettes = gTilesetPalettes_pewter_city,
    .metatiles = gMetatiles_pewter_city,
    .metatileAttributes = gMetatileAttributes_pewter_city,
    .callback = NULL,
};

const struct Tileset gTileset_pokecenter_kanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_pokecenter_kanto,
    .palettes = gTilesetPalettes_pokecenter_kanto,
    .metatiles = gMetatiles_pokecenter_kanto,
    .metatileAttributes = gMetatileAttributes_pokecenter_kanto,
    .callback = NULL,
};

const struct Tileset gTileset_pokemart_kanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_pokemart_kanto,
    .palettes = gTilesetPalettes_pokemart_kanto,
    .metatiles = gMetatiles_pokemart_kanto,
    .metatileAttributes = gMetatileAttributes_pokemart_kanto,
    .callback = NULL,
};

const struct Tileset gTileset_pewter_museum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_pewter_museum,
    .palettes = gTilesetPalettes_pewter_museum,
    .metatiles = gMetatiles_pewter_museum,
    .metatileAttributes = gMetatileAttributes_pewter_museum,
    .callback = NULL,
};

const struct Tileset gTileset_viridian_forest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_viridian_forest,
    .palettes = gTilesetPalettes_viridian_forest,
    .metatiles = gMetatiles_viridian_forest,
    .metatileAttributes = gMetatileAttributes_viridian_forest,
    .callback = NULL,
};

const struct Tileset gTileset_kanto_generic2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_kanto_generic2,
    .palettes = gTilesetPalettes_kanto_generic2,
    .metatiles = gMetatiles_kanto_generic2,
    .metatileAttributes = gMetatileAttributes_kanto_generic2,
    .callback = NULL,
};

const struct Tileset gTileset_new_bark =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_new_bark,
    .palettes = gTilesetPalettes_new_bark,
    .metatiles = gMetatiles_new_bark,
    .metatileAttributes = gMetatileAttributes_new_bark,
    .callback = NULL,
};

const struct Tileset gTileset_johto_general_og =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_johto_general_og,
    .palettes = gTilesetPalettes_johto_general_og,
    .metatiles = gMetatiles_johto_general_og,
    .metatileAttributes = gMetatileAttributes_johto_general_og,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_johto_building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_johto_building,
    .palettes = gTilesetPalettes_johto_building,
    .metatiles = gMetatiles_johto_building,
    .metatileAttributes = gMetatileAttributes_johto_building,
    .callback = NULL,
};

const struct Tileset gTileset_cerulean_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cerulean_city,
    .palettes = gTilesetPalettes_cerulean_city,
    .metatiles = gMetatiles_cerulean_city,
    .metatileAttributes = gMetatileAttributes_cerulean_city,
    .callback = NULL,
};

const struct Tileset gTileset_kanto_gates =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_kanto_gates,
    .palettes = gTilesetPalettes_kanto_gates,
    .metatiles = gMetatiles_kanto_gates,
    .metatileAttributes = gMetatileAttributes_kanto_gates,
    .callback = NULL,
};

const struct Tileset gTileset_viridian_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_viridian_gym,
    .palettes = gTilesetPalettes_viridian_gym,
    .metatiles = gMetatiles_viridian_gym,
    .metatileAttributes = gMetatileAttributes_viridian_gym,
    .callback = NULL,
};

const struct Tileset gTileset_mtmoon =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_mtmoon,
    .palettes = gTilesetPalettes_mtmoon,
    .metatiles = gMetatiles_mtmoon,
    .metatileAttributes = gMetatileAttributes_mtmoon,
    .callback = NULL,
};

const struct Tileset gTileset_lavender_town =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_lavender_town,
    .palettes = gTilesetPalettes_lavender_town,
    .metatiles = gMetatiles_lavender_town,
    .metatileAttributes = gMetatileAttributes_lavender_town,
    .callback = NULL,
};

const struct Tileset gTileset_vermilion_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_vermilion_city,
    .palettes = gTilesetPalettes_vermilion_city,
    .metatiles = gMetatiles_vermilion_city,
    .metatileAttributes = gMetatileAttributes_vermilion_city,
    .callback = NULL,
};

const struct Tileset gTileset_celadon_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_celadon_city,
    .palettes = gTilesetPalettes_celadon_city,
    .metatiles = gMetatiles_celadon_city,
    .metatileAttributes = gMetatileAttributes_celadon_city,
    .callback = NULL,
};

const struct Tileset gTileset_saffron_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_saffron_city,
    .palettes = gTilesetPalettes_saffron_city,
    .metatiles = gMetatiles_saffron_city,
    .metatileAttributes = gMetatileAttributes_saffron_city,
    .callback = NULL,
};

const struct Tileset gTileset_fuchsia_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_fuchsia_city,
    .palettes = gTilesetPalettes_fuchsia_city,
    .metatiles = gMetatiles_fuchsia_city,
    .metatileAttributes = gMetatileAttributes_fuchsia_city,
    .callback = NULL,
};

const struct Tileset gTileset_cinnabar_island =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cinnabar_island,
    .palettes = gTilesetPalettes_cinnabar_island,
    .metatiles = gMetatiles_cinnabar_island,
    .metatileAttributes = gMetatileAttributes_cinnabar_island,
    .callback = NULL,
};

const struct Tileset gTileset_indigo_plateau =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_indigo_plateau,
    .palettes = gTilesetPalettes_indigo_plateau,
    .metatiles = gMetatiles_indigo_plateau,
    .metatileAttributes = gMetatileAttributes_indigo_plateau,
    .callback = NULL,
};

const struct Tileset gTileset_cycling_road =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cycling_road,
    .palettes = gTilesetPalettes_cycling_road,
    .metatiles = gMetatiles_cycling_road,
    .metatileAttributes = gMetatileAttributes_cycling_road,
    .callback = NULL,
};

const struct Tileset gTileset_blackthorn_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_blackthorn_city,
    .palettes = gTilesetPalettes_blackthorn_city,
    .metatiles = gMetatiles_blackthorn_city,
    .metatileAttributes = gMetatileAttributes_blackthorn_city,
    .callback = NULL,
};

const struct Tileset gTileset_johto_NE =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_johto_NE,
    .palettes = gTilesetPalettes_johto_NE,
    .metatiles = gMetatiles_johto_NE,
    .metatileAttributes = gMetatileAttributes_johto_NE,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_johto_nw =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_johto_nw,
    .palettes = gTilesetPalettes_johto_nw,
    .metatiles = gMetatiles_johto_nw,
    .metatileAttributes = gMetatileAttributes_johto_nw,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_cherrygrove_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cherrygrove_city,
    .palettes = gTilesetPalettes_cherrygrove_city,
    .metatiles = gMetatiles_cherrygrove_city,
    .metatileAttributes = gMetatileAttributes_cherrygrove_city,
    .callback = NULL,
};

const struct Tileset gTileset_violet_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_violet_city,
    .palettes = gTilesetPalettes_violet_city,
    .metatiles = gMetatiles_violet_city,
    .metatileAttributes = gMetatileAttributes_violet_city,
    .callback = NULL,
};

const struct Tileset gTileset_goldenrod_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_goldenrod_city,
    .palettes = gTilesetPalettes_goldenrod_city,
    .metatiles = gMetatiles_goldenrod_city,
    .metatileAttributes = gMetatileAttributes_goldenrod_city,
    .callback = NULL,
};

const struct Tileset gTileset_ecruteak_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ecruteak_city,
    .palettes = gTilesetPalettes_ecruteak_city,
    .metatiles = gMetatiles_ecruteak_city,
    .metatileAttributes = gMetatileAttributes_ecruteak_city,
    .callback = NULL,
};


const struct Tileset gTileset_olivine =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_olivine,
    .palettes = gTilesetPalettes_olivine,
    .metatiles = gMetatiles_olivine,
    .metatileAttributes = gMetatileAttributes_olivine,
    .callback = NULL,
};

const struct Tileset gTileset_cianwood_city =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cianwood_city,
    .palettes = gTilesetPalettes_cianwood_city,
    .metatiles = gMetatiles_cianwood_city,
    .metatileAttributes = gMetatileAttributes_cianwood_city,
    .callback = NULL,
};

const struct Tileset gTileset_safari_johto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_safari_johto,
    .palettes = gTilesetPalettes_safari_johto,
    .metatiles = gMetatiles_safari_johto,
    .metatileAttributes = gMetatileAttributes_safari_johto,
    .callback = NULL,
};

const struct Tileset gTileset_mahogany =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_mahogany,
    .palettes = gTilesetPalettes_mahogany,
    .metatiles = gMetatiles_mahogany,
    .metatileAttributes = gMetatileAttributes_mahogany,
    .callback = NULL,
};

const struct Tileset gTileset_cerulean_bikeshop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cerulean_bikeshop,
    .palettes = gTilesetPalettes_cerulean_bikeshop,
    .metatiles = gMetatiles_cerulean_bikeshop,
    .metatileAttributes = gMetatileAttributes_cerulean_bikeshop,
    .callback = NULL,
};

const struct Tileset gTileset_undergroundtunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_undergroundtunnel,
    .palettes = gTilesetPalettes_undergroundtunnel,
    .metatiles = gMetatiles_undergroundtunnel,
    .metatileAttributes = gMetatileAttributes_undergroundtunnel,
    .callback = NULL,
};

const struct Tileset gTileset_silphco =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_silphco,
    .palettes = gTilesetPalettes_silphco,
    .metatiles = gMetatiles_silphco,
    .metatileAttributes = gMetatileAttributes_silphco,
    .callback = NULL,
};

const struct Tileset gTileset_generator =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_generator,
    .palettes = gTilesetPalettes_generator,
    .metatiles = gMetatiles_generator,
    .metatileAttributes = gMetatileAttributes_generator,
    .callback = NULL,
};

const struct Tileset gTileset_seacottage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_seacottage,
    .palettes = gTilesetPalettes_seacottage,
    .metatiles = gMetatiles_seacottage,
    .metatileAttributes = gMetatileAttributes_seacottage,
    .callback = NULL,
};

const struct Tileset gTileset_portindoor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_portindoor,
    .palettes = gTilesetPalettes_portindoor,
    .metatiles = gMetatiles_portindoor,
    .metatileAttributes = gMetatileAttributes_portindoor,
    .callback = NULL,
};

const struct Tileset gTileset_daycare2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_daycare2,
    .palettes = gTilesetPalettes_daycare2,
    .metatiles = gMetatiles_daycare2,
    .metatileAttributes = gMetatileAttributes_daycare2,
    .callback = NULL,
};

const struct Tileset gTileset_soulhouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_soulhouse,
    .palettes = gTilesetPalettes_soulhouse,
    .metatiles = gMetatiles_soulhouse,
    .metatileAttributes = gMetatileAttributes_soulhouse,
    .callback = NULL,
};

const struct Tileset gTileset_undergroundrocket =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_undergroundrocket,
    .palettes = gTilesetPalettes_undergroundrocket,
    .metatiles = gMetatiles_undergroundrocket,
    .metatileAttributes = gMetatileAttributes_undergroundrocket,
    .callback = NULL,
};

const struct Tileset gTileset_cafe =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cafe,
    .palettes = gTilesetPalettes_cafe,
    .metatiles = gMetatiles_cafe,
    .metatileAttributes = gMetatileAttributes_cafe,
    .callback = NULL,
};

const struct Tileset gTileset_departmentstore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_departmentstore,
    .palettes = gTilesetPalettes_departmentstore,
    .metatiles = gMetatiles_departmentstore,
    .metatileAttributes = gMetatileAttributes_departmentstore,
    .callback = NULL,
};

const struct Tileset gTileset_apartments =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_apartments,
    .palettes = gTilesetPalettes_apartments,
    .metatiles = gMetatiles_apartments,
    .metatileAttributes = gMetatileAttributes_apartments,
    .callback = NULL,
};

const struct Tileset gTileset_gamecorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_gamecorner,
    .palettes = gTilesetPalettes_gamecorner,
    .metatiles = gMetatiles_gamecorner,
    .metatileAttributes = gMetatileAttributes_gamecorner,
    .callback = NULL,
};

const struct Tileset gTileset_Goldenrod_TrainStation =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Goldenrod_TrainStation,
    .palettes = gTilesetPalettes_Goldenrod_TrainStation,
    .metatiles = gMetatiles_Goldenrod_TrainStation,
    .metatileAttributes = gMetatileAttributes_Goldenrod_TrainStation,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakTheater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakTheater,
    .palettes = gTilesetPalettes_EcruteakTheater,
    .metatiles = gMetatiles_EcruteakTheater,
    .metatileAttributes = gMetatileAttributes_EcruteakTheater,
    .callback = InitTilesetAnim_ecruteak_theater,
};

const struct Tileset gTileset_FightingDojoVIP =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FightingDojoVIP,
    .palettes = gTilesetPalettes_FightingDojoVIP,
    .metatiles = gMetatiles_FightingDojoVIP,
    .metatileAttributes = gMetatileAttributes_FightingDojoVIP,
    .callback = NULL,
};

const struct Tileset gTileset_saffron_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_saffron_gym,
    .palettes = gTilesetPalettes_saffron_gym,
    .metatiles = gMetatiles_saffron_gym,
    .metatileAttributes = gMetatileAttributes_saffron_gym,
    .callback = NULL,
};

const struct Tileset gTileset_safari_entrance =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_safari_entrance,
    .palettes = gTilesetPalettes_safari_entrance,
    .metatiles = gMetatiles_safari_entrance,
    .metatileAttributes = gMetatileAttributes_safari_entrance,
    .callback = NULL,
};

const struct Tileset gTileset_NationalPark =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NationalPark,
    .palettes = gTilesetPalettes_NationalPark,
    .metatiles = gMetatiles_NationalPark,
    .metatileAttributes = gMetatileAttributes_NationalPark,
    .callback = InitTilesetAnim_NationalPark,
};

const struct Tileset gTileset_WhirlIslands =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_WhirlIslands,
    .palettes = gTilesetPalettes_WhirlIslands,
    .metatiles = gMetatiles_WhirlIslands,
    .metatileAttributes = gMetatileAttributes_WhirlIslands,
    .callback = NULL,
};

const struct Tileset gTileset_fuchsia_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_fuchsia_gym,
    .palettes = gTilesetPalettes_fuchsia_gym,
    .metatiles = gMetatiles_fuchsia_gym,
    .metatileAttributes = gMetatileAttributes_fuchsia_gym,
    .callback = NULL,
};

const struct Tileset gTileset_house2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_house2,
    .palettes = gTilesetPalettes_house2,
    .metatiles = gMetatiles_house2,
    .metatileAttributes = gMetatileAttributes_house2,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Sandy =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Sandy,
    .palettes = gTilesetPalettes_Cave_Sandy,
    .metatiles = gMetatiles_Cave_Sandy,
    .metatileAttributes = gMetatileAttributes_Cave_Sandy,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Green =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Green,
    .palettes = gTilesetPalettes_Cave_Green,
    .metatiles = gMetatiles_Cave_Green,
    .metatileAttributes = gMetatileAttributes_Cave_Green,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Grey =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Grey,
    .palettes = gTilesetPalettes_Cave_Grey,
    .metatiles = gMetatiles_Cave_Grey,
    .metatileAttributes = gMetatileAttributes_Cave_Grey,
    .callback = NULL,
};

const struct Tileset gTileset_cave_ice =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cave_ice,
    .palettes = gTilesetPalettes_cave_ice,
    .metatiles = gMetatiles_cave_ice,
    .metatileAttributes = gMetatileAttributes_cave_ice,
    .callback = NULL,
};

const struct Tileset gTileset_blackthorn_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_blackthorn_gym,
    .palettes = gTilesetPalettes_blackthorn_gym,
    .metatiles = gMetatiles_blackthorn_gym,
    .metatileAttributes = gMetatileAttributes_blackthorn_gym,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter_White =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter_White,
    .palettes = gTilesetPalettes_PokemonCenter_White,
    .metatiles = gMetatiles_PokemonCenter_White,
    .metatileAttributes = gMetatileAttributes_PokemonCenter_White,
    .callback = NULL,
};

const struct Tileset gTileset_johtomart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_johtomart,
    .palettes = gTilesetPalettes_johtomart,
    .metatiles = gMetatiles_johtomart,
    .metatileAttributes = gMetatileAttributes_johtomart,
    .callback = NULL,
};

const struct Tileset gTileset_trainer_school =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_trainer_school,
    .palettes = gTilesetPalettes_trainer_school,
    .metatiles = gMetatiles_trainer_school,
    .metatileAttributes = gMetatileAttributes_trainer_school,
    .callback = NULL,
};

const struct Tileset gTileset_kurts_house =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_kurts_house,
    .palettes = gTilesetPalettes_kurts_house,
    .metatiles = gMetatiles_kurts_house,
    .metatileAttributes = gMetatileAttributes_kurts_house,
    .callback = NULL,
};

const struct Tileset gTileset_barn =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_barn,
    .palettes = gTilesetPalettes_barn,
    .metatiles = gMetatiles_barn,
    .metatileAttributes = gMetatileAttributes_barn,
    .callback = NULL,
};

const struct Tileset gTileset_bellchimetrail =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_bellchimetrail,
    .palettes = gTilesetPalettes_bellchimetrail,
    .metatiles = gMetatiles_bellchimetrail,
    .metatileAttributes = gMetatileAttributes_bellchimetrail,
    .callback = NULL,
};

const struct Tileset gTileset_ecruteak_gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ecruteak_gym,
    .palettes = gTilesetPalettes_ecruteak_gym,
    .metatiles = gMetatiles_ecruteak_gym,
    .metatileAttributes = gMetatileAttributes_ecruteak_gym,
    .callback = NULL,
};

const struct Tileset gTileset_undergroundstorage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_undergroundstorage,
    .palettes = gTilesetPalettes_undergroundstorage,
    .metatiles = gMetatiles_undergroundstorage,
    .metatileAttributes = gMetatileAttributes_undergroundstorage,
    .callback = NULL,
};

const struct Tileset gTileset_cave_default =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_cave_default,
    .palettes = gTilesetPalettes_cave_default,
    .metatiles = gMetatiles_cave_default,
    .metatileAttributes = gMetatileAttributes_cave_default,
    .callback = NULL,
};

const struct Tileset gTileset_route32 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_route32,
    .palettes = gTilesetPalettes_route32,
    .metatiles = gMetatiles_route32,
    .metatileAttributes = gMetatileAttributes_route32,
    .callback = NULL,
};

const struct Tileset gTileset_Route38_Farmland =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route38_Farmland,
    .palettes = gTilesetPalettes_Route38_Farmland,
    .metatiles = gMetatiles_Route38_Farmland,
    .metatileAttributes = gMetatileAttributes_Route38_Farmland,
    .callback = NULL,
};

const struct Tileset gTileset_shoprooftop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_shoprooftop,
    .palettes = gTilesetPalettes_shoprooftop,
    .metatiles = gMetatiles_shoprooftop,
    .metatileAttributes = gMetatileAttributes_shoprooftop,
    .callback = NULL,
};

const struct Tileset gTileset_burnedtower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_burnedtower,
    .palettes = gTilesetPalettes_burnedtower,
    .metatiles = gMetatiles_burnedtower,
    .metatileAttributes = gMetatileAttributes_burnedtower,
    .callback = NULL,
};

const struct Tileset gTileset_shadowrealm =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_shadowrealm,
    .palettes = gTilesetPalettes_shadowrealm,
    .metatiles = gMetatiles_shadowrealm,
    .metatileAttributes = gMetatileAttributes_shadowrealm,
    .callback = NULL,
};

const struct Tileset gTileset_wescave =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_wescave,
    .palettes = gTilesetPalettes_wescave,
    .metatiles = gMetatiles_wescave,
    .metatileAttributes = gMetatileAttributes_wescave,
    .callback = NULL,
};

const struct Tileset gTileset_wescave2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_wescave2,
    .palettes = gTilesetPalettes_wescave2,
    .metatiles = gMetatiles_wescave2,
    .metatileAttributes = gMetatileAttributes_wescave2,
    .callback = InitTilesetAnim_WesCave,
};

const struct Tileset gTileset_ruinsofAlphOutside =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ruinsofAlphOutside,
    .palettes = gTilesetPalettes_ruinsofAlphOutside,
    .metatiles = gMetatiles_ruinsofAlphOutside,
    .metatileAttributes = gMetatileAttributes_ruinsofAlphOutside,
    .callback = NULL,
};
