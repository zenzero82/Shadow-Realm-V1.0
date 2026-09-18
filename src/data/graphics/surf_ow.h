struct RideablePokemon
{
    u16 species;
    u8 trainerPose;
    const u32 *shinyPic;
};

#define SURFABLE_POKEMON_DEFAULT_FRAME_COUNT 6
#define SURFABLE_POKEMON_MAX_FRAME_COUNT     8

#include "config/surfable_species_enabled.h"
#include "../object_events/surfable/surfable_pokemon_graphics.h"
#include "../object_events/surfable/surfable_pokemon.h"
#include "../object_events/surfable/surfable_pokemon_pic_tables.h"
#include "../object_events/surfable/surfable_pokemon_templates.h"

STATIC_ASSERT(ARRAY_COUNT(gSurfablePokemon) == ARRAY_COUNT(sSurfablePokemonPalettes), SurfSpeciesAndPalettesCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(gSurfablePokemon) == ARRAY_COUNT(sSurfablePokemonShinyPalettes), SurfSpeciesAndShinyPalettesCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(gSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverworldSprites), SurfSpeciesAndSpritesCountMismatch);
STATIC_ASSERT(ARRAY_COUNT(gSurfablePokemon) == ARRAY_COUNT(gSurfablePokemonOverlaySprites), SurfSpeciesAndOverlaysCountMismatch);
