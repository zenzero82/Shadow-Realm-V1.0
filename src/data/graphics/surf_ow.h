static const u32 gSurfOwPic_Pikachu[] = INCBIN_U32("graphics/surf_ow/pikachu.4bpp");
static const u16 gSurfOwPal_Pikachu[] = INCBIN_U16("graphics/surf_ow/pikachu.gbapal");

static const struct SpriteFrameImage sSurfOwFrames_Pikachu[] =
{
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 0),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 1),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 2),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 3),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 4),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 5),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 6),
    overworld_frame(gSurfOwPic_Pikachu, 8, 8, 7),
};

static const union AnimCmd sSurfOwAnim_Pikachu_South[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Pikachu_North[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Pikachu_West[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Pikachu_East[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSurfOwAnimTable_Pikachu[] =
{
    sSurfOwAnim_Pikachu_South,
    sSurfOwAnim_Pikachu_North,
    sSurfOwAnim_Pikachu_West,
    sSurfOwAnim_Pikachu_East,
};

static const struct SpriteTemplate gSurfOwTemplate_Pikachu =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SURF_OW,
    .oam = &gObjectEventBaseOam_64x64,
    .anims = sSurfOwAnimTable_Pikachu,
    .images = sSurfOwFrames_Pikachu,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSurfBlobFieldEffect,
};

static const u32 gSurfOwPic_Sharpedo[] = INCBIN_U32("graphics/surf_ow/sharpedo.4bpp");
static const u16 gSurfOwPal_Sharpedo[] = INCBIN_U16("graphics/surf_ow/sharpedo.gbapal");

static const struct SpriteFrameImage sSurfOwFrames_Sharpedo[] =
{
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 0),
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 1),
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 2),
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 3),
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 4),
    overworld_frame(gSurfOwPic_Sharpedo, 4, 4, 5),
};

static const union AnimCmd sSurfOwAnim_Sharpedo_South[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Sharpedo_North[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Sharpedo_West[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Sharpedo_East[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSurfOwAnimTable_Sharpedo[] =
{
    sSurfOwAnim_Sharpedo_South,
    sSurfOwAnim_Sharpedo_North,
    sSurfOwAnim_Sharpedo_West,
    sSurfOwAnim_Sharpedo_East,
};

static const struct SpriteTemplate gSurfOwTemplate_Sharpedo =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SURF_OW,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sSurfOwAnimTable_Sharpedo,
    .images = sSurfOwFrames_Sharpedo,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSurfBlobFieldEffect,
};

static const u32 gSurfOwPic_Lapras[] = INCBIN_U32("graphics/surf_ow/lapras.4bpp");
static const u16 gSurfOwPal_Lapras[] = INCBIN_U16("graphics/surf_ow/lapras.gbapal");

static const struct SpriteFrameImage sSurfOwFrames_Lapras[] =
{
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 0),
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 1),
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 2),
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 3),
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 4),
    overworld_frame(gSurfOwPic_Lapras, 4, 4, 5),
};

static const union AnimCmd sSurfOwAnim_Lapras_South[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Lapras_North[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Lapras_West[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Lapras_East[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSurfOwAnimTable_Lapras[] =
{
    sSurfOwAnim_Lapras_South,
    sSurfOwAnim_Lapras_North,
    sSurfOwAnim_Lapras_West,
    sSurfOwAnim_Lapras_East,
};

static const struct SpriteTemplate gSurfOwTemplate_Lapras =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SURF_OW,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sSurfOwAnimTable_Lapras,
    .images = sSurfOwFrames_Lapras,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSurfBlobFieldEffect,
};

static const u32 gSurfOwPic_Feraligatr[] = INCBIN_U32("graphics/surf_ow/feraligatr.4bpp");
static const u16 gSurfOwPal_Feraligatr[] = INCBIN_U16("graphics/surf_ow/feraligatr.gbapal");

static const struct SpriteFrameImage sSurfOwFrames_Feraligatr[] =
{
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 0),
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 1),
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 2),
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 3),
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 4),
    overworld_frame(gSurfOwPic_Feraligatr, 8, 8, 5),
};

static const union AnimCmd sSurfOwAnim_Feraligatr_South[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Feraligatr_North[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Feraligatr_West[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Feraligatr_East[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSurfOwAnimTable_Feraligatr[] =
{
    sSurfOwAnim_Feraligatr_South,
    sSurfOwAnim_Feraligatr_North,
    sSurfOwAnim_Feraligatr_West,
    sSurfOwAnim_Feraligatr_East,
};

static const struct SpriteTemplate gSurfOwTemplate_Feraligatr =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SURF_OW,
    .oam = &gObjectEventBaseOam_64x64,
    .anims = sSurfOwAnimTable_Feraligatr,
    .images = sSurfOwFrames_Feraligatr,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSurfBlobFieldEffect,
};

static const u32 gSurfOwPic_Kyogre[] = INCBIN_U32("graphics/surf_ow/kyogre.4bpp");
static const u16 gSurfOwPal_Kyogre[] = INCBIN_U16("graphics/surf_ow/kyogre.gbapal");

static const struct SpriteFrameImage sSurfOwFrames_Kyogre[] =
{
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 0),
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 1),
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 2),
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 3),
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 4),
    overworld_frame(gSurfOwPic_Kyogre, 8, 8, 5),
};

static const union AnimCmd sSurfOwAnim_Kyogre_South[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Kyogre_North[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Kyogre_West[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfOwAnim_Kyogre_East[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSurfOwAnimTable_Kyogre[] =
{
    sSurfOwAnim_Kyogre_South,
    sSurfOwAnim_Kyogre_North,
    sSurfOwAnim_Kyogre_West,
    sSurfOwAnim_Kyogre_East,
};

static const struct SpriteTemplate gSurfOwTemplate_Kyogre =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SURF_OW,
    .oam = &gObjectEventBaseOam_64x64,
    .anims = sSurfOwAnimTable_Kyogre,
    .images = sSurfOwFrames_Kyogre,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSurfBlobFieldEffect,
};

const struct SurfOwEntry gSurfOwEntries[] =
{
    {
        .species = SPECIES_PIKACHU,
        .palette = gSurfOwPal_Pikachu,
        .shinyPalette = NULL,
        .baseTemplate = &gSurfOwTemplate_Pikachu,
        .overlayTemplate = NULL,
    },
    {
        .species = SPECIES_SHARPEDO,
        .palette = gSurfOwPal_Sharpedo,
        .shinyPalette = NULL,
        .baseTemplate = &gSurfOwTemplate_Sharpedo,
        .overlayTemplate = NULL,
    },
    {
        .species = SPECIES_LAPRAS,
        .palette = gSurfOwPal_Lapras,
        .shinyPalette = NULL,
        .baseTemplate = &gSurfOwTemplate_Lapras,
        .overlayTemplate = NULL,
    },
    {
        .species = SPECIES_FERALIGATR,
        .palette = gSurfOwPal_Feraligatr,
        .shinyPalette = NULL,
        .baseTemplate = &gSurfOwTemplate_Feraligatr,
        .overlayTemplate = NULL,
    },
    {
        .species = SPECIES_KYOGRE,
        .palette = gSurfOwPal_Kyogre,
        .shinyPalette = NULL,
        .baseTemplate = &gSurfOwTemplate_Kyogre,
        .overlayTemplate = NULL,
    },
    {
        .species = SPECIES_NONE,
    },
};
