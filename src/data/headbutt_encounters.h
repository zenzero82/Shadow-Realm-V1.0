#include "headbutt.h"
#include "constants/species.h"

static const struct WildPokemon sHeadbuttWildMons_Default[HEADBUTT_WILD_COUNT] =
{
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_PINECO },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_BURMY },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_HERACROSS },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_AIPOM },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_EXEGGCUTE },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_MUNCHLAX },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_CHERUBI },
    { .minLevel = 5, .maxLevel = 15, .species = SPECIES_SHROOMISH },
};

static const struct HeadbuttEncounterTable gHeadbuttEncounterTables[] =
{
    {
        .wildMonsInfo = { sHeadbuttWildMons_Default, sHeadbuttWildMons_Default, sHeadbuttWildMons_Default },
    },
};
