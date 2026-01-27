#include "global.h"
#include "graphics.h"

//Graphics data

const u8 gNamingScreenCursorTiles[]            = INCBIN_U8("graphics/naming_screen/cursor.4bpp");
const u8 gNamingScreenActiveCursorSmallTiles[] = INCBIN_U8("graphics/naming_screen/active_cursor_small.4bpp");
const u8 gNamingScreenActiveCursorBigTiles[]   = INCBIN_U8("graphics/naming_screen/active_cursor_big.4bpp");
const u8 gNamingScreenUnderscoreTiles[]        = INCBIN_U8("graphics/naming_screen/underscore.4bpp");
const u32 gNamingScreenBGTiles[]               = INCBIN_U32("graphics/naming_screen/tiles.lz");
const u32 gNamingScreenBGMap[]                 = INCBIN_U32("graphics/naming_screen/bg.lz");
const u32 gNamingScreenButtonsEng[]            = INCBIN_U32("graphics/naming_screen/buttons_eng.lz");
const u32 gNamingScreenCharUpperMap[]          = INCBIN_U32("graphics/naming_screen/letters_uppers.lz");
const u32 gNamingScreenCharLowerMap[]          = INCBIN_U32("graphics/naming_screen/letters_lowers.lz");
const u32 gNamingScreenCharOtherMap[]          = INCBIN_U32("graphics/naming_screen/symbols.lz");
const u16 gNamingScreenTextPal[]               = INCBIN_U16("graphics/naming_screen/text.gbapal");
const u16 gNamingScreenPal[] = INCBIN_U16("graphics/naming_screen/bg.gbapal");
const u16 gNamingScreenSelPal[] = INCBIN_U16("graphics/naming_screen/button_selected.gbapal");
const u16 gSpriteImage_PcIcon0[] = INCBIN_U16("graphics/naming_screen/pc_icon/0.4bpp");
const u16 gSpriteImage_PcIcon1[] = INCBIN_U16("graphics/naming_screen/pc_icon/1.4bpp");
const u16 gNamingScreenPalettes[][16] = 
{
    INCBIN_U16("graphics/naming_screen/pc_icon/0.gbapal"),
	INCBIN_U16("graphics/naming_screen/underscore.gbapal"),
    INCBIN_U16("graphics/naming_screen/cursor.gbapal"),
};
const u16 gRivalSpriteTiles[] = INCBIN_U16("graphics/interface/naming_screen_83E1980.4bpp");
const u16 gRivalSpritePalette[] = INCBIN_U16("graphics/interface/naming_screen_83E1980.gbapal");