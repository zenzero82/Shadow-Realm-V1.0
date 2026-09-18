//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/trainers.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/trainers.h' to remove #line markers.
//

#line 1 "src/data/trainers.party"

#line 75
    [DIFFICULTY_NORMAL][TRAINER_TORKIN] =
    {
#line 76
        .trainerName = _("TORKIN"),
#line 77
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 78
        .trainerPic = TRAINER_PIC_CIPHER_PEON_M,
        .encounterMusic_gender =
#line 80
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
#line 81
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 83
            .nickname = COMPOUND_STRING("XD003"),
#line 83
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 86
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 31, 31, 0),
#line 84
            .lvl = 4,
#line 85
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 87
            .isShadow = TRUE,
#line 89
            .heartGauge = 5000,
#line 88
            .shadowID = 3,
#line 90
            .shadowUnlockMove = MOVE_THUNDERBOLT,
            .moves = {
#line 91
                MOVE_SHADOW_BOLT,
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_PANIC,
            },
            },
        },
    },
#line 95
    [DIFFICULTY_NORMAL][TRAINER_JJ_VIRIDIAN] =
    {
#line 96
        .trainerName = _("JESS&JAMES"),
#line 97
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 98
        .trainerPic = TRAINER_PIC_JESSIE_JAMES,
        .encounterMusic_gender =
#line 99
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 101
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 102
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 104
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 106
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 105
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 107
    [DIFFICULTY_NORMAL][TRAINER_BROCK_KANTO] =
    {
#line 108
        .trainerName = _("BROCK"),
#line 109
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 111
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .encounterMusic_gender =
#line 110
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 114
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 118
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 115
            .lvl = 14,
#line 116
            .ball = ITEM_HEAVY_BALL,
#line 117
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 118
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 123
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 127
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 124
            .lvl = 16,
#line 125
            .ball = ITEM_HEAVY_BALL,
#line 126
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 127
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_THROW,
                MOVE_SCREECH,
            },
            },
            {
#line 132
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 136
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 133
            .lvl = 16,
#line 134
            .ball = ITEM_HEAVY_BALL,
#line 135
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 136
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 141
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_KANTO] =
    {
#line 142
        .trainerName = _("JERRY"),
#line 143
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 144
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 147
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 150
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 148
            .lvl = 12,
#line 149
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 150
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 153
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 156
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 154
            .lvl = 12,
#line 155
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 156
                MOVE_PECK,
                MOVE_GROWL,
            },
            },
        },
    },
#line 159
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AL] =
    {
#line 160
        .trainerName = _("AL"),
#line 161
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 162
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 165
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 167
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 166
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 168
            .species = SPECIES_ARIADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 169
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 171
            .species = SPECIES_VIVILLON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 173
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 172
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 174
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_JOSH] =
    {
#line 175
        .trainerName = _("JOSH"),
#line 176
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 177
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 180
            .species = SPECIES_FORRETRESS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 182
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 181
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 183
            .species = SPECIES_KRICKETUNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 185
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 184
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 186
            .species = SPECIES_SHUCKLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 188
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 187
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 189
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_BENNY] =
    {
#line 190
        .trainerName = _("BENNY"),
#line 191
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 192
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 195
            .species = SPECIES_VESPIQUEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 197
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 196
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 198
            .species = SPECIES_YANMEGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 200
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 199
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 201
            .species = SPECIES_MOTHIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 203
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 202
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 204
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AMY_AND_MAY] =
    {
#line 205
        .trainerName = _("AMY&MAY"),
#line 206
        .trainerClass = TRAINER_CLASS_TWINS,
#line 207
        .trainerPic = TRAINER_PIC_TWINS2,
        .encounterMusic_gender =
#line 208
F_TRAINER_FEMALE | 
0,
#line 209
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 211
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 213
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 212
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 214
            .species = SPECIES_ARIADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 216
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 215
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 217
            .species = SPECIES_WORMADAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 219
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 218
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 220
    [DIFFICULTY_NORMAL][TRAINER_BUGSY_1] =
    {
#line 221
        .trainerName = _("BUGSY"),
#line 222
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 224
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .encounterMusic_gender =
#line 223
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 227
            .species = SPECIES_KLEAVOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 229
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 228
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 230
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 232
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 231
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 233
            .species = SPECIES_VIKAVOLT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 235
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 234
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 236
            .species = SPECIES_SCIZOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 238
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 237
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 239
    [DIFFICULTY_NORMAL][TRAINER_LEADER_FALKNER] =
    {
#line 240
        .trainerName = _("FALKNER"),
#line 241
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 242
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .encounterMusic_gender =
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 245
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 247
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 246
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 248
            .species = SPECIES_ORICORIO_PAU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 249
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 251
            .species = SPECIES_TRANQUILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 253
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 252
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 254
            .species = SPECIES_HONCHKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 256
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 255
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 257
    [DIFFICULTY_NORMAL][TRAINER_MISTY] =
    {
#line 258
        .trainerName = _("MISTY"),
#line 259
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 261
        .trainerPic = TRAINER_PIC_MISTY,
        .encounterMusic_gender =
#line 262
F_TRAINER_FEMALE | 
#line 260
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 264
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 267
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 265
            .lvl = 19,
#line 266
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 268
            .species = SPECIES_CORSOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 271
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 269
            .lvl = 19,
#line 270
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 272
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 273
            .lvl = 20,
#line 274
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 276
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 279
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 277
            .lvl = 22,
#line 278
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 279
                MOVE_TWISTER,
                MOVE_BITE,
                MOVE_LEER,
                MOVE_THUNDER_WAVE,
            },
            },
        },
    },
#line 284
    [DIFFICULTY_NORMAL][TRAINER_ROCKET_GRUNT_M_1] =
    {
#line 285
        .trainerName = _("ZANDER"),
#line 286
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 287
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 289
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 290
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 292
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 295
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 293
            .lvl = 23,
#line 294
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 296
            .isShadow = TRUE,
#line 298
            .heartGauge = 7500,
#line 297
            .shadowID = 49,
#line 299
            .shadowUnlockMove = MOVE_PLAY_ROUGH,
            .moves = {
#line 300
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_PANIC,
            },
            },
        },
    },
#line 304
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER1] =
    {
#line 305
        .trainerName = _("Neil"),
#line 306
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 307
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 310
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 312
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 311
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 313
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 315
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 314
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 316
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 318
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 317
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 319
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER2] =
    {
#line 320
        .trainerName = _("Rick"),
#line 321
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 322
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 325
            .species = SPECIES_CUTIEFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 327
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 326
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 328
            .species = SPECIES_GRUBBIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 330
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 329
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 331
            .species = SPECIES_JOLTIK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 333
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 332
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 334
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER3] =
    {
#line 335
        .trainerName = _("Jamal"),
#line 336
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 337
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 340
            .species = SPECIES_VENIPEDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 342
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 341
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 343
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 345
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 344
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 346
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 348
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 347
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 349
    [DIFFICULTY_NORMAL][TRAINER_VF_ROCKET] =
    {
#line 350
        .trainerName = _("Travis"),
#line 351
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 352
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 354
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 355
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 357
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 359
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 358
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 360
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 362
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 361
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 363
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER1] =
    {
#line 364
        .trainerName = _("BEN"),
#line 365
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 366
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 369
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 371
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 370
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 372
            .species = SPECIES_PIDOVE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 374
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 373
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 375
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER2] =
    {
#line 376
        .trainerName = _("CALVIN"),
#line 377
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 378
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 381
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 383
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 382
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 384
            .species = SPECIES_YUNGOOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 386
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 385
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 387
    [DIFFICULTY_NORMAL][TRAINER_RT3_LASS] =
    {
#line 388
        .trainerName = _("MAYA"),
#line 389
        .trainerClass = TRAINER_CLASS_LASS,
#line 390
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 391
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 393
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 395
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 394
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 396
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 398
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 397
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 399
    [DIFFICULTY_NORMAL][TRAINER_RT3_FIREBREATHER] =
    {
#line 400
        .trainerName = _("Otis"),
#line 401
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 402
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 405
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 407
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 406
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 408
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 410
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 409
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 411
    [DIFFICULTY_NORMAL][TRAINER_TEMP_MIROR_B] =
    {
#line 412
        .trainerName = _("MIROR B"),
#line 413
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 414
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 416
            TRAINER_ENCOUNTER_MUSIC_MIRRORB,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 418
            .species = SPECIES_TORNADUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 423
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 419
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 420
            .isShadow = TRUE,
#line 422
            .heartGauge = 10000,
#line 421
            .shadowID = 115,
            },
            {
#line 424
            .species = SPECIES_ENAMORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 429
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 425
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 426
            .isShadow = TRUE,
#line 428
            .heartGauge = 10000,
#line 427
            .shadowID = 116,
            },
            {
#line 430
            .species = SPECIES_THUNDURUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 435
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 431
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 432
            .isShadow = TRUE,
#line 434
            .heartGauge = 10000,
#line 433
            .shadowID = 117,
            },
            {
#line 436
            .species = SPECIES_TAPU_LELE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 441
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 437
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 438
            .isShadow = TRUE,
#line 440
            .heartGauge = 10000,
#line 439
            .shadowID = 118,
            },
            {
#line 442
            .species = SPECIES_MELOETTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 447
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 443
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 444
            .isShadow = TRUE,
#line 446
            .heartGauge = 10000,
#line 445
            .shadowID = 119,
            },
            {
#line 448
            .species = SPECIES_BLACEPHALON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 453
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 449
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 450
            .isShadow = TRUE,
#line 452
            .heartGauge = 10000,
#line 451
            .shadowID = 120,
            },
        },
    },
#line 454
    [DIFFICULTY_NORMAL][TRAINER_RT4_BLACK_BELT] =
    {
#line 455
        .trainerName = _("RYU"),
#line 456
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 457
        .trainerPic = TRAINER_PIC_BLACK_BELT_GEN2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 460
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 462
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 461
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 463
            .species = SPECIES_THROH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 465
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 464
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 466
    [DIFFICULTY_NORMAL][TRAINER_RT4_ROCKER] =
    {
#line 467
        .trainerName = _("AMP"),
#line 468
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 469
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 472
            .species = SPECIES_BLITZLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 474
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 473
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 475
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 477
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 476
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 478
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER1] =
    {
#line 479
        .trainerName = _("LILY"),
#line 480
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 481
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 482
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 484
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 486
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 485
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 487
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 489
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 488
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 490
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER2] =
    {
#line 491
        .trainerName = _("MIA"),
#line 492
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 493
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 494
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 496
            .species = SPECIES_COTTONEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 498
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 497
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 499
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 501
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 500
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 502
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN1] =
    {
#line 503
        .trainerName = _("BRENDAN"),
#line 504
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_2,
#line 505
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 508
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 510
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 509
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 511
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 513
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 512
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 514
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN2] =
    {
#line 515
        .trainerName = _("BRENDAN"),
#line 516
        .trainerClass = TRAINER_CLASS_AETHER,
#line 517
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 520
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 522
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 521
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 523
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 525
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 524
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 526
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN3] =
    {
#line 527
        .trainerName = _("BRENDAN"),
#line 528
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 529
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 532
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 534
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 533
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 535
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 537
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 536
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 538
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_1] =
    {
#line 539
        .trainerName = _("MARK"),
#line 540
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 541
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 544
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 546
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 545
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 547
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 549
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 548
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 550
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_COOLTRAINER_F1] =
    {
#line 551
        .trainerName = _("MARA"),
#line 552
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 553
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 554
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 556
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 558
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 557
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 559
            .species = SPECIES_LUXIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 561
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 560
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 562
            .species = SPECIES_ESPEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 564
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 563
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 565
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_COOLTRAINER_M] =
    {
#line 566
        .trainerName = _("RYAN"),
#line 567
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 568
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2M,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 571
            .species = SPECIES_HERACROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 573
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 572
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 574
            .species = SPECIES_QUAGSIRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 576
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 575
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 577
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 579
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 578
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 580
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_ROCKER] =
    {
#line 581
        .trainerName = _("VINCE"),
#line 582
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 583
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 586
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 588
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 587
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 589
            .species = SPECIES_HELIOPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 591
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 590
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 592
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 594
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 593
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 595
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_FISHERMAN_1] =
    {
#line 596
        .trainerName = _("NOLAN"),
#line 597
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 598
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 601
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 603
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 602
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 604
            .species = SPECIES_OCTILLERY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 606
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 605
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 607
            .species = SPECIES_FLOATZEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 609
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 608
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 610
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_PSYCHIC] =
    {
#line 611
        .trainerName = _("ELI"),
#line 612
        .trainerClass = TRAINER_CLASS_PSYCHIC_M,
#line 613
        .trainerPic = TRAINER_PIC_PSYCHIC_M2,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 616
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 618
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 617
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 619
            .species = SPECIES_MISDREAVUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 621
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 620
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 622
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 624
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 623
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 625
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_COOLTRAINER_F2] =
    {
#line 626
        .trainerName = _("TESSA"),
#line 627
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 628
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 629
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 631
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 633
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 632
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 634
            .species = SPECIES_MEOWSTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 636
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 635
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 637
            .species = SPECIES_HAWLUCHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 639
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 638
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 640
    [DIFFICULTY_NORMAL][TRAINER_ROUTE27_FISHERMAN_2] =
    {
#line 641
        .trainerName = _("BRODY"),
#line 642
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 643
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 646
            .species = SPECIES_QWILFISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 648
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 647
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 649
            .species = SPECIES_CLAUNCHER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 651
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 650
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 652
            .species = SPECIES_CLAWITZER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 654
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 653
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 655
    [DIFFICULTY_NORMAL][TRAINER_ROUTE26_PSYCHIC] =
    {
#line 656
        .trainerName = _("SEER"),
#line 657
        .trainerClass = TRAINER_CLASS_PSYCHIC_M,
#line 658
        .trainerPic = TRAINER_PIC_PSYCHIC_M2,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 661
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 663
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 662
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 664
            .species = SPECIES_MEOWSTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 666
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 665
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 667
            .species = SPECIES_ESPEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 669
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 668
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 670
    [DIFFICULTY_NORMAL][TRAINER_ROUTE26_COOLTRAINER_M] =
    {
#line 671
        .trainerName = _("GARRETT"),
#line 672
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 673
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2M,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 676
            .species = SPECIES_DONPHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 678
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 677
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 679
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 681
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 680
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 682
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 684
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 683
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 685
    [DIFFICULTY_NORMAL][TRAINER_ROUTE26N_COOLTRAINER_F1] =
    {
#line 686
        .trainerName = _("LENA"),
#line 687
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 688
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 689
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 691
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 693
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 692
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 694
            .species = SPECIES_TOGETIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 696
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 695
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 697
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 699
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 698
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 700
    [DIFFICULTY_NORMAL][TRAINER_ROUTE26N_COOLTRAINER_M] =
    {
#line 701
        .trainerName = _("BRETT"),
#line 702
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 703
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2M,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 706
            .species = SPECIES_QUAGSIRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 708
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 707
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 709
            .species = SPECIES_GLIGAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 711
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 710
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 712
            .species = SPECIES_GABITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 714
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 713
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 715
    [DIFFICULTY_NORMAL][TRAINER_ROUTE26N_COOLTRAINER_F2] =
    {
#line 716
        .trainerName = _("NIA"),
#line 717
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 718
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 719
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 721
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 723
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 722
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 724
            .species = SPECIES_MISDREAVUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 726
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 725
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 727
            .species = SPECIES_SYLVEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 729
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 728
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 730
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_BIKER_1] =
    {
#line 731
        .trainerName = _("ZEKE"),
#line 732
        .trainerClass = TRAINER_CLASS_BIKER,
#line 733
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 736
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 738
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 737
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 739
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 741
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 740
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 742
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 744
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 743
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 745
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_BIKER_2] =
    {
#line 746
        .trainerName = _("AXEL"),
#line 747
        .trainerClass = TRAINER_CLASS_BIKER,
#line 748
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 751
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 753
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 752
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 754
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 756
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 755
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 757
            .species = SPECIES_GARBODOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 759
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 758
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 760
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_BIKER_3] =
    {
#line 761
        .trainerName = _("DUKE"),
#line 762
        .trainerClass = TRAINER_CLASS_BIKER,
#line 763
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 766
            .species = SPECIES_SALANDIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 768
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 767
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 769
            .species = SPECIES_GRIMER_ALOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 771
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 770
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 772
            .species = SPECIES_MUK_ALOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 774
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 773
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 775
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_BIKER_4] =
    {
#line 776
        .trainerName = _("ROCCO"),
#line 777
        .trainerClass = TRAINER_CLASS_BIKER,
#line 778
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 781
            .species = SPECIES_PAWNIARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 783
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 782
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 784
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 786
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 785
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 787
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 789
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 788
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 790
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_BIKER_5] =
    {
#line 791
        .trainerName = _("JETT"),
#line 792
        .trainerClass = TRAINER_CLASS_BIKER,
#line 793
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 796
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 798
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 797
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 799
            .species = SPECIES_MAREANIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 801
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 800
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 802
            .species = SPECIES_TOXAPEX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 804
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 803
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 805
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_SUPER_NERD_1] =
    {
#line 806
        .trainerName = _("MILO"),
#line 807
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 808
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 811
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 813
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 812
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 814
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 816
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 815
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 817
    [DIFFICULTY_NORMAL][TRAINER_ROUTE8_SUPER_NERD_2] =
    {
#line 818
        .trainerName = _("ORIN"),
#line 819
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 820
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 823
            .species = SPECIES_PORYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 825
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 824
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 826
            .species = SPECIES_KLANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 828
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 827
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 829
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_2] =
    {
#line 830
        .trainerName = _("TROY"),
#line 831
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 832
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 835
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 837
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 836
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 838
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 840
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 839
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 841
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_1] =
    {
#line 842
        .trainerName = _("RINA"),
#line 843
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 844
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 845
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 847
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 849
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 848
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 850
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 852
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 851
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 853
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_2] =
    {
#line 854
        .trainerName = _("MEL"),
#line 855
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 856
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 857
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 859
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 861
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 860
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 862
    [DIFFICULTY_NORMAL][TRAINER_JJ_ILEX] =
    {
#line 863
        .trainerName = _("JESS&JAMES"),
#line 864
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 865
        .trainerPic = TRAINER_PIC_JESSIE_JAMES,
        .encounterMusic_gender =
#line 866
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 868
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 870
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 869
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 871
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 873
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 872
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 874
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 880
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 875
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 876
            .isShadow = TRUE,
#line 878
            .heartGauge = 5000,
#line 877
            .shadowID = 8,
#line 879
            .shadowUnlockMove = MOVE_FURY_SWIPES,
            .moves = {
#line 880
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_PANIC,
                MOVE_SHADOW_HOLD,
            },
            },
        },
    },
#line 884
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F1] =
    {
#line 885
        .trainerName = _("SABRINA"),
#line 886
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 887
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 888
F_TRAINER_FEMALE | 
#line 889
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 890
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 892
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 894
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 893
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 895
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 897
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 896
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 898
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M1] =
    {
#line 899
        .trainerName = _("RORY"),
#line 900
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 901
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 903
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 904
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 906
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 908
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 907
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 909
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 911
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 910
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 912
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F2] =
    {
#line 913
        .trainerName = _("LANA"),
#line 914
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 915
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 916
F_TRAINER_FEMALE | 
#line 917
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 918
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 920
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 922
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 921
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 923
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 925
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 924
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 926
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 928
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 927
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 929
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M2] =
    {
#line 930
        .trainerName = _("MARK"),
#line 931
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 932
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 934
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 935
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 937
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 939
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 938
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 940
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 942
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 941
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 943
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M3] =
    {
#line 944
        .trainerName = _("TODD"),
#line 945
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 946
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 948
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 949
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 951
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 953
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 952
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 954
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 955
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 957
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F3] =
    {
#line 958
        .trainerName = _("RINA"),
#line 959
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 960
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 961
F_TRAINER_FEMALE | 
#line 962
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 963
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 965
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 967
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 966
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 968
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 970
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 969
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 971
    [DIFFICULTY_NORMAL][TRAINER_ILEX_BUG_CATCHER] =
    {
#line 972
        .trainerName = _("BEN"),
#line 973
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 974
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 977
            .species = SPECIES_LEDYBA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 979
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 978
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 980
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 982
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 981
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 983
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 985
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 984
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 986
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_1] =
    {
#line 987
        .trainerName = _("GABE"),
#line 988
        .trainerClass = TRAINER_CLASS_HIKER,
#line 989
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 992
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 994
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 993
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 995
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 997
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 996
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 998
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_2] =
    {
#line 999
        .trainerName = _("RUSTY"),
#line 1000
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1001
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1004
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1006
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1005
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1007
    [DIFFICULTY_NORMAL][TRAINER_LOOKER_CERULEAN] =
    {
#line 1008
        .trainerName = _("LOOKER"),
#line 1009
        .trainerClass = TRAINER_CLASS_POLICEMAN,
#line 1010
        .trainerPic = TRAINER_PIC_LOOKER_GEN5,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1013
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1016
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1014
            .lvl = 16,
#line 1015
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1016
                MOVE_BITE,
                MOVE_EMBER,
            },
            },
            {
#line 1019
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1022
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1020
            .lvl = 18,
#line 1021
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1022
                MOVE_LOW_KICK,
                MOVE_MUD_SLAP,
            },
            },
        },
    },
#line 1025
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER1] =
    {
#line 1026
        .trainerName = _("TIM"),
#line 1027
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 1028
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1031
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1033
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1032
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1034
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1036
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1035
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1037
    [DIFFICULTY_NORMAL][TRAINER_RT25_LADY] =
    {
#line 1038
        .trainerName = _("MARIE"),
#line 1039
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 1040
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 1041
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1043
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1045
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1044
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1046
            .species = SPECIES_TIMBURR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1048
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1047
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1049
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_F] =
    {
#line 1050
        .trainerName = _("KARA"),
#line 1051
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 1052
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 1053
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1055
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1057
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1056
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1058
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1060
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1059
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1061
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER2] =
    {
#line 1062
        .trainerName = _("BEN"),
#line 1063
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1064
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1067
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1069
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1068
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1070
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1072
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1071
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1073
    [DIFFICULTY_NORMAL][TRAINER_RT25_CAMPER] =
    {
#line 1074
        .trainerName = _("COLE"),
#line 1075
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1076
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1079
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1081
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1080
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1082
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1084
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1083
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1085
    [DIFFICULTY_NORMAL][TRAINER_RT25_LASS] =
    {
#line 1086
        .trainerName = _("NINA"),
#line 1087
        .trainerClass = TRAINER_CLASS_LASS,
#line 1088
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 1089
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1091
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1093
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1092
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1094
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1096
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1095
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1097
    [DIFFICULTY_NORMAL][TRAINER_RT25_SUPER_NERD] =
    {
#line 1098
        .trainerName = _("DEX"),
#line 1099
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1100
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1103
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1105
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1104
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1106
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1108
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1107
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1109
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M] =
    {
#line 1110
        .trainerName = _("TYLER"),
#line 1111
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 1112
        .trainerPic = TRAINER_PIC_SWIMMER_M_GEN2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1115
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1117
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1116
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1118
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1120
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1119
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1121
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F1] =
    {
#line 1122
        .trainerName = _("MAYA"),
#line 1123
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 1124
        .trainerPic = TRAINER_PIC_SWIMMER_F_GEN2,
        .encounterMusic_gender =
#line 1125
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1127
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1129
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1128
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1130
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1132
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1131
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1133
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F2] =
    {
#line 1134
        .trainerName = _("KAREN"),
#line 1135
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 1136
        .trainerPic = TRAINER_PIC_SWIMMER_F_GEN2,
        .encounterMusic_gender =
#line 1137
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1139
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1141
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1140
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1142
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1144
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1143
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1145
    [DIFFICULTY_NORMAL][TRAINER_KURTS_HOUSE_IRONMASK] =
    {
#line 1146
        .trainerName = _("MARAUDER"),
#line 1147
        .trainerClass = TRAINER_CLASS_ROCKET_ADMIN,
#line 1148
        .trainerPic = TRAINER_PIC_IRON_MASKED_MARAUDER,
        .encounterMusic_gender =
#line 1149
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1151
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1153
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1152
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1154
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1156
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1155
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1157
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1158
            .lvl = 29,
#line 1159
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1160
            .isShadow = TRUE,
#line 1162
            .heartGauge = 10000,
#line 1161
            .shadowID = 9,
#line 1163
            .shadowUnlockMove = MOVE_STEEL_WING,
            .moves = {
#line 1164
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_STORM,
                MOVE_SHADOW_HOLD,
            },
            },
        },
    },
#line 1168
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_1] =
    {
#line 1169
        .trainerName = _("AXEL"),
#line 1170
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1171
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1172
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1174
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1176
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1175
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1177
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1178
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1180
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_2] =
    {
#line 1181
        .trainerName = _("DANE"),
#line 1182
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1183
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1184
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1186
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1188
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1187
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1189
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1191
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1190
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1192
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_3] =
    {
#line 1193
        .trainerName = _("MIRA"),
#line 1194
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1195
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1196
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1198
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1200
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1199
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1201
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1203
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1202
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1204
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_4] =
    {
#line 1205
        .trainerName = _("COLT"),
#line 1206
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1207
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1208
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1210
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1212
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1211
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1213
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1215
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1214
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1216
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_5] =
    {
#line 1217
        .trainerName = _("ROOK"),
#line 1218
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1219
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1220
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1222
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1224
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1223
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1225
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1227
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1226
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1228
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_6] =
    {
#line 1229
        .trainerName = _("NASH"),
#line 1230
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1231
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1232
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1234
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1236
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1235
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1237
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1239
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1238
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1240
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_1] =
    {
#line 1241
        .trainerName = _("FAYE"),
#line 1242
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1243
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1244
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1246
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1248
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1247
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1249
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1251
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1250
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1252
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_2] =
    {
#line 1253
        .trainerName = _("ORIN"),
#line 1254
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1255
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1256
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1258
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1260
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1259
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1261
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1263
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1262
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1264
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_3] =
    {
#line 1265
        .trainerName = _("GAGE"),
#line 1266
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1267
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1268
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1270
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1272
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1271
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1273
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1274
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1276
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_4] =
    {
#line 1277
        .trainerName = _("NYX"),
#line 1278
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1279
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1280
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1282
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1284
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1283
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1285
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1287
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1286
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1288
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_5] =
    {
#line 1289
        .trainerName = _("KADE"),
#line 1290
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1291
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1292
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1294
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1296
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1295
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1297
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1299
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1298
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1300
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_6] =
    {
#line 1301
        .trainerName = _("VOSS"),
#line 1302
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1303
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1304
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1306
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1308
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1307
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1309
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1311
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1310
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1312
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_7] =
    {
#line 1313
        .trainerName = _("IRIS"),
#line 1314
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1315
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1316
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1318
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1320
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1319
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1321
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1323
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1322
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1324
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_8] =
    {
#line 1325
        .trainerName = _("SERA"),
#line 1326
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1327
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1328
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1330
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1332
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1331
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1333
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1335
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1334
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1336
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_BRYONY] =
    {
#line 1337
        .trainerName = _("BRYONY"),
#line 1338
        .trainerClass = TRAINER_CLASS_TEAM_FLARE_ADMIN,
#line 1339
        .trainerPic = TRAINER_PIC_BRYONY,
        .encounterMusic_gender =
#line 1340
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1342
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1344
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1343
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1345
            .species = SPECIES_PYROAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1347
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1346
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1348
            .species = SPECIES_PANGORO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1355
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1349
            .lvl = 29,
#line 1350
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1351
            .isShadow = TRUE,
#line 1353
            .heartGauge = 10000,
#line 1352
            .shadowID = 45,
#line 1354
            .shadowUnlockMove = MOVE_CRUNCH,
            .moves = {
#line 1355
                MOVE_SHADOW_BREAK,
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_HOLD,
            },
            },
        },
    },
#line 1359
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_1] =
    {
#line 1360
        .trainerName = _("VESPER"),
#line 1361
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1362
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1363
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1365
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1367
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1366
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1368
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1370
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1369
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1371
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_2] =
    {
#line 1372
        .trainerName = _("ORLA"),
#line 1373
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1374
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1375
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1377
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1378
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1380
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1382
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1381
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1383
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_3] =
    {
#line 1384
        .trainerName = _("KADE"),
#line 1385
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1386
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1387
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1389
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1391
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1390
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1392
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1394
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1393
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1395
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_1] =
    {
#line 1396
        .trainerName = _("ROBIN"),
#line 1397
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1398
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1400
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1402
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1401
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1403
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1405
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1404
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1406
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_2] =
    {
#line 1407
        .trainerName = _("KYLE"),
#line 1408
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1409
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1411
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1413
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1412
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1414
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1416
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1415
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1417
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER] =
    {
#line 1418
        .trainerName = _("TIM"),
#line 1419
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1420
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1423
            .species = SPECIES_SENTRET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1425
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1424
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1426
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1428
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1427
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1429
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_PICNICKER] =
    {
#line 1430
        .trainerName = _("LINA"),
#line 1431
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1432
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1433
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1435
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1437
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1436
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1438
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1440
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1439
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1441
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_1] =
    {
#line 1442
        .trainerName = _("RAY"),
#line 1443
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1444
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1447
            .species = SPECIES_WOOPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1449
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1448
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1450
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_2] =
    {
#line 1451
        .trainerName = _("NED"),
#line 1452
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1453
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1456
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1458
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1457
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1459
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_3] =
    {
#line 1460
        .trainerName = _("LEO"),
#line 1461
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1462
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1465
            .species = SPECIES_FINNEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1467
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1466
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1468
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_BIRD_KEEPER] =
    {
#line 1469
        .trainerName = _("MILO"),
#line 1470
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1471
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1474
            .species = SPECIES_STARLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1476
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1475
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1477
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1479
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1478
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1480
    [DIFFICULTY_NORMAL][TRAINER_ROUTE33_HIKER] =
    {
#line 1481
        .trainerName = _("DUKE"),
#line 1482
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1483
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1486
            .species = SPECIES_BONSLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1488
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1487
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1489
            .species = SPECIES_PHANPY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1491
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1490
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1492
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_CAMPER] =
    {
#line 1493
        .trainerName = _("NATE"),
#line 1494
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1495
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1498
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1500
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1499
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1501
            .species = SPECIES_SKIDDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1503
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1502
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1504
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_GENTLEMAN] =
    {
#line 1505
        .trainerName = _("ALFRED"),
#line 1506
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 1507
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1510
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1512
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1511
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1513
            .species = SPECIES_DUNSPARCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1515
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1514
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1516
            .species = SPECIES_STANTLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1518
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1517
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1519
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_YOUNGSTER] =
    {
#line 1520
        .trainerName = _("TIM"),
#line 1521
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1522
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1525
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1527
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1526
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1528
            .species = SPECIES_STARLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1530
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1529
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1531
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_HIKER] =
    {
#line 1532
        .trainerName = _("GUS"),
#line 1533
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1534
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1537
            .species = SPECIES_BONSLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1539
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1538
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1540
            .species = SPECIES_NOIBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1542
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1541
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1543
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_SUPER_NERD] =
    {
#line 1544
        .trainerName = _("TREV"),
#line 1545
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1546
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1549
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1551
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1550
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1552
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER] =
    {
#line 1553
        .trainerName = _("BO"),
#line 1554
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 1555
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1558
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1560
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1559
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1561
    [DIFFICULTY_NORMAL][TRAINER_SILVER_HUNTER] =
    {
#line 1562
        .trainerName = _("SILVER"),
#line 1563
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 1564
        .trainerPic = TRAINER_PIC_SILVER,
        .encounterMusic_gender =
#line 1566
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1568
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1570
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1569
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1571
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_1] =
    {
#line 1572
        .trainerName = _("RUDO"),
#line 1573
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1574
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1576
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1578
            .species = SPECIES_KROKOROK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1580
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1579
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1581
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1583
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1582
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1584
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_2] =
    {
#line 1585
        .trainerName = _("VOSS"),
#line 1586
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1587
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1589
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1591
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1593
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1592
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1594
            .species = SPECIES_WATCHOG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1596
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1595
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1597
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_3] =
    {
#line 1598
        .trainerName = _("NERO"),
#line 1599
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1600
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1602
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1604
            .species = SPECIES_LIEPARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1606
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1605
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1607
            .species = SPECIES_GARBODOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1609
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1608
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1609
                MOVE_SLUDGE_BOMB,
                MOVE_BODY_SLAM,
                MOVE_CLEAR_SMOG,
                MOVE_GUNK_SHOT,
            },
            },
        },
    },
#line 1614
    [DIFFICULTY_NORMAL][TRAINER_ZINZOLIN_POWER_PLANT] =
    {
#line 1615
        .trainerName = _("ZINZOLIN"),
#line 1616
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1617
        .trainerPic = TRAINER_PIC_ZINZOLIN_GEN5,
        .encounterMusic_gender =
#line 1619
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1621
            .species = SPECIES_CRYOGONAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1623
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1622
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1624
            .species = SPECIES_WEAVILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1630
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1625
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1626
            .isShadow = TRUE,
#line 1628
            .heartGauge = 10000,
#line 1627
            .shadowID = 25,
#line 1629
            .shadowUnlockMove = MOVE_ICE_PUNCH,
            .moves = {
#line 1630
                MOVE_SHADOW_CHILL,
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_RUSH,
            },
            },
            {
#line 1634
            .species = SPECIES_DRIFBLIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1636
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1635
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1637
            .species = SPECIES_ABOMASNOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1639
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1638
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1640
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SHAUNA] =
    {
#line 1641
        .trainerName = _("SHAUNA"),
#line 1642
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1643
        .trainerPic = TRAINER_PIC_SHAUNA,
        .encounterMusic_gender =
#line 1644
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1646
            .species = SPECIES_KLEFKI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1648
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1647
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1649
            .species = SPECIES_SLIGGOO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1651
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1650
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1652
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1654
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1653
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1655
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TREVOR] =
    {
#line 1656
        .trainerName = _("TREVOR"),
#line 1657
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1658
        .trainerPic = TRAINER_PIC_TREVOR,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1661
            .species = SPECIES_FLOETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1663
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1662
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1664
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1666
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1665
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1667
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1669
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1668
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1670
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TIERNO] =
    {
#line 1671
        .trainerName = _("TIERNO"),
#line 1672
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1673
        .trainerPic = TRAINER_PIC_TIERNO,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1676
            .species = SPECIES_HAWLUCHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1678
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1677
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1679
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1681
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1680
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1682
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1684
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1683
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1685
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SERENA] =
    {
#line 1686
        .trainerName = _("SERENA"),
#line 1687
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1688
        .trainerPic = TRAINER_PIC_SERENA,
        .encounterMusic_gender =
#line 1689
F_TRAINER_FEMALE | 
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1691
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1693
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1692
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1694
            .species = SPECIES_SYLVEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1696
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1695
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1697
            .species = SPECIES_PANGORO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1699
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1698
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1700
            .species = SPECIES_DELPHOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1700
            .heldItem = ITEM_DELPHOXITE,
#line 1702
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1701
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1703
    [DIFFICULTY_NORMAL][TRAINER_CELADON_CALEM] =
    {
#line 1704
        .trainerName = _("CALEM"),
#line 1705
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1706
        .trainerPic = TRAINER_PIC_CALEM,
        .encounterMusic_gender =
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1709
            .species = SPECIES_MEOWSTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1711
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1710
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1712
            .species = SPECIES_BARBARACLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1714
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1713
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1715
            .species = SPECIES_NOIVERN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1717
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1716
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1718
            .species = SPECIES_CHESNAUGHT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1718
            .heldItem = ITEM_CHESNAUGHTITE,
#line 1720
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1719
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1721
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_1] =
    {
#line 1722
        .trainerName = _("GRUNT"),
#line 1723
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1724
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1726
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1728
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1730
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1729
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1731
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1733
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1732
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1734
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_2] =
    {
#line 1735
        .trainerName = _("GRUNT"),
#line 1736
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1737
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1739
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1741
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1743
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1742
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1744
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1746
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1745
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1747
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_MICHELLE] =
    {
#line 1748
        .trainerName = _("MICHELLE"),
#line 1749
        .trainerClass = TRAINER_CLASS_LASS,
#line 1750
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 1751
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1753
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1755
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1754
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1756
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1758
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1757
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1759
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_TANYA] =
    {
#line 1760
        .trainerName = _("TANYA"),
#line 1761
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1762
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1763
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1765
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1767
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1766
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1768
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1770
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1769
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1771
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_JULIA] =
    {
#line 1772
        .trainerName = _("JULIA"),
#line 1773
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 1774
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 1775
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1777
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1779
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1778
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1780
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1782
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1781
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1783
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_JO_AND_ZOE] =
    {
#line 1784
        .trainerName = _("JO&ZOE"),
#line 1785
        .trainerClass = TRAINER_CLASS_TWINS,
#line 1786
        .trainerPic = TRAINER_PIC_TWINS2,
        .encounterMusic_gender =
#line 1787
F_TRAINER_FEMALE | 
0,
#line 1788
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1790
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1792
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1791
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1793
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1795
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1794
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1796
    [DIFFICULTY_NORMAL][TRAINER_ERIKA] =
    {
#line 1797
        .trainerName = _("ERIKA"),
#line 1798
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 1800
        .trainerPic = TRAINER_PIC_ERIKA,
        .encounterMusic_gender =
#line 1801
F_TRAINER_FEMALE | 
#line 1799
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1803
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1805
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1804
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1806
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1808
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1807
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1809
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1811
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1810
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1812
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1814
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1813
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1815
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GLADION] =
    {
#line 1816
        .trainerName = _("GLADION"),
#line 1817
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1818
        .trainerPic = TRAINER_PIC_GLADION,
        .encounterMusic_gender =
#line 1820
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1822
            .species = SPECIES_TYPE_NULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1824
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1823
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1825
            .species = SPECIES_ZOROARK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1827
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1826
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1828
            .species = SPECIES_LUCARIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1830
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1829
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1831
    [DIFFICULTY_NORMAL][TRAINER_SURGE] =
    {
#line 1832
        .trainerName = _("LT. SURGE"),
#line 1833
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 1835
        .trainerPic = TRAINER_PIC_SURGE,
        .encounterMusic_gender =
#line 1834
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1838
            .species = SPECIES_MAGNEZONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1840
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1839
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1841
            .species = SPECIES_ELECTIVIRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1843
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1842
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1844
            .species = SPECIES_ROTOM_FAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1846
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1845
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1847
            .species = SPECIES_HELIOLISK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1849
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1848
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1850
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1850
            .heldItem = ITEM_RAICHUNITE_X,
#line 1852
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1851
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1853
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_JUGGLER] =
    {
#line 1854
        .trainerName = _("LEO"),
#line 1855
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 1856
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1859
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1861
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1860
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1862
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1864
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1863
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1865
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_GENTLEMAN] =
    {
#line 1866
        .trainerName = _("EDGAR"),
#line 1867
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 1868
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1871
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1873
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1872
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1874
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1876
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1875
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1877
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_ROCKER] =
    {
#line 1878
        .trainerName = _("AXEL"),
#line 1879
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 1880
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1883
            .species = SPECIES_KILOWATTREL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1885
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1884
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1886
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1888
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1887
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1889
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_CARRIE] =
    {
#line 1890
        .trainerName = _("CARRIE"),
#line 1891
        .trainerClass = TRAINER_CLASS_LASS,
#line 1892
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 1893
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1895
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1897
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1896
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1898
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1900
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1899
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1901
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_LEAH] =
    {
#line 1902
        .trainerName = _("LEAH"),
#line 1903
        .trainerClass = TRAINER_CLASS_LASS,
#line 1904
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 1905
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1907
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1909
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1908
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1910
            .species = SPECIES_URSARING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1912
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1911
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1913
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_BROOKE] =
    {
#line 1914
        .trainerName = _("BROOKE"),
#line 1915
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 1916
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 1917
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1919
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1921
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1920
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1922
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1924
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1923
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1925
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_MARA] =
    {
#line 1926
        .trainerName = _("MARA"),
#line 1927
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 1928
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 1929
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1931
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1933
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1932
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1934
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1936
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1935
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1937
    [DIFFICULTY_NORMAL][TRAINER_LEADER_WHITNEY] =
    {
#line 1938
        .trainerName = _("WHITNEY"),
#line 1939
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 1941
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .encounterMusic_gender =
#line 1942
F_TRAINER_FEMALE | 
#line 1940
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1944
            .species = SPECIES_PORYGON2,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1946
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1945
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1947
            .species = SPECIES_SNORLAX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1949
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1948
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1950
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1952
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1951
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1953
            .species = SPECIES_BEWEAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1955
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1954
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1956
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1958
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1957
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1959
    [DIFFICULTY_NORMAL][TRAINER_VENUS] =
    {
#line 1960
        .trainerName = _("VENUS"),
#line 1961
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 1962
        .trainerPic = TRAINER_PIC_VENUS,
        .encounterMusic_gender =
#line 1963
F_TRAINER_FEMALE | 
#line 1964
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
#line 1965
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1967
            .species = SPECIES_HATTERENE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1969
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1968
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1970
            .species = SPECIES_AMOONGUSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1972
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1971
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1973
            .species = SPECIES_ROSERADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1975
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1974
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1976
            .species = SPECIES_MILOTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1978
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1977
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1979
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1985
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1980
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1981
            .isShadow = TRUE,
#line 1983
            .heartGauge = 10000,
#line 1982
            .shadowID = 71,
#line 1984
            .shadowUnlockMove = MOVE_GIGA_DRAIN,
            .moves = {
#line 1985
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_SKY,
                MOVE_SHADOW_HOLD,
            },
            },
            {
#line 1989
            .species = SPECIES_GOODRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1995
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1990
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1991
            .isShadow = TRUE,
#line 1993
            .heartGauge = 10000,
#line 1992
            .shadowID = 104,
#line 1994
            .shadowUnlockMove = MOVE_DRAGON_PULSE,
            .moves = {
#line 1995
                MOVE_SHADOW_MIST,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_STORM,
            },
            },
        },
    },
#line 1999
    [DIFFICULTY_NORMAL][TRAINER_GIOVANNI_SHADOW_REALM] =
    {
#line 2000
        .trainerName = _("GIOVANNI"),
#line 2001
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 2002
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .encounterMusic_gender =
#line 2004
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2006
            .species = SPECIES_REGIROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2011
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2007
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2008
            .isShadow = TRUE,
#line 2010
            .heartGauge = 10000,
#line 2009
            .shadowID = 109,
            },
            {
#line 2012
            .species = SPECIES_TERRAKION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2017
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2013
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2014
            .isShadow = TRUE,
#line 2016
            .heartGauge = 10000,
#line 2015
            .shadowID = 110,
            },
            {
#line 2018
            .species = SPECIES_IRON_TREADS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2023
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2019
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2020
            .isShadow = TRUE,
#line 2022
            .heartGauge = 10000,
#line 2021
            .shadowID = 111,
            },
            {
#line 2024
            .species = SPECIES_GREAT_TUSK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2029
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2025
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2026
            .isShadow = TRUE,
#line 2028
            .heartGauge = 10000,
#line 2027
            .shadowID = 112,
            },
            {
#line 2030
            .species = SPECIES_REGIGIGAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2035
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2031
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2032
            .isShadow = TRUE,
#line 2034
            .heartGauge = 10000,
#line 2033
            .shadowID = 113,
            },
            {
#line 2036
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2041
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2037
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2038
            .isShadow = TRUE,
#line 2040
            .heartGauge = 10000,
#line 2039
            .shadowID = 114,
            },
        },
    },
#line 2042
    [DIFFICULTY_NORMAL][TRAINER_NASCOUR_SHADOW_REALM] =
    {
#line 2043
        .trainerName = _("NASCOUR"),
#line 2044
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 2045
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 2047
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2049
            .species = SPECIES_IRON_BUNDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2054
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2050
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2051
            .isShadow = TRUE,
#line 2053
            .heartGauge = 10000,
#line 2052
            .shadowID = 121,
            },
            {
#line 2055
            .species = SPECIES_IRON_CROWN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2060
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2056
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2057
            .isShadow = TRUE,
#line 2059
            .heartGauge = 10000,
#line 2058
            .shadowID = 122,
            },
            {
#line 2061
            .species = SPECIES_CHIEN_PAO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2066
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2062
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2063
            .isShadow = TRUE,
#line 2065
            .heartGauge = 10000,
#line 2064
            .shadowID = 123,
            },
            {
#line 2067
            .species = SPECIES_CALYREX_ICE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2072
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2068
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2069
            .isShadow = TRUE,
#line 2071
            .heartGauge = 10000,
#line 2070
            .shadowID = 124,
            },
            {
#line 2073
            .species = SPECIES_REGICE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2078
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2074
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2075
            .isShadow = TRUE,
#line 2077
            .heartGauge = 10000,
#line 2076
            .shadowID = 125,
            },
            {
#line 2079
            .species = SPECIES_ARTICUNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2084
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2080
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2081
            .isShadow = TRUE,
#line 2083
            .heartGauge = 10000,
#line 2082
            .shadowID = 126,
            },
        },
    },
#line 2085
    [DIFFICULTY_NORMAL][TRAINER_GUZMA_SHADOW_REALM] =
    {
#line 2086
        .trainerName = _("GUZMA"),
#line 2087
        .trainerClass = TRAINER_CLASS_TEAM_SKULL,
#line 2088
        .trainerPic = TRAINER_PIC_GUZMA,
        .encounterMusic_gender =
#line 2090
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2092
            .species = SPECIES_KARTANA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2097
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2093
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2094
            .isShadow = TRUE,
#line 2096
            .heartGauge = 10000,
#line 2095
            .shadowID = 127,
            },
            {
#line 2098
            .species = SPECIES_NAGANADEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2099
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2100
            .isShadow = TRUE,
#line 2102
            .heartGauge = 10000,
#line 2101
            .shadowID = 128,
            },
            {
#line 2104
            .species = SPECIES_TAPU_BULU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2109
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2105
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2106
            .isShadow = TRUE,
#line 2108
            .heartGauge = 10000,
#line 2107
            .shadowID = 129,
            },
            {
#line 2110
            .species = SPECIES_ZERAORA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2115
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2111
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2112
            .isShadow = TRUE,
#line 2114
            .heartGauge = 10000,
#line 2113
            .shadowID = 130,
            },
            {
#line 2116
            .species = SPECIES_GUZZLORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2121
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2117
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2118
            .isShadow = TRUE,
#line 2120
            .heartGauge = 10000,
#line 2119
            .shadowID = 131,
            },
            {
#line 2122
            .species = SPECIES_BUZZWOLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2127
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2123
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2124
            .isShadow = TRUE,
#line 2126
            .heartGauge = 10000,
#line 2125
            .shadowID = 132,
            },
        },
    },
#line 2128
    [DIFFICULTY_NORMAL][TRAINER_LUSAMINE_SHADOW_REALM] =
    {
#line 2129
        .trainerName = _("LUSAMINE"),
#line 2130
        .trainerClass = TRAINER_CLASS_AETHER,
#line 2131
        .trainerPic = TRAINER_PIC_AETHER_F,
        .encounterMusic_gender =
#line 2132
F_TRAINER_FEMALE | 
#line 2133
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2135
            .species = SPECIES_XURKITREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2140
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2136
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2137
            .isShadow = TRUE,
#line 2139
            .heartGauge = 10000,
#line 2138
            .shadowID = 133,
            },
            {
#line 2141
            .species = SPECIES_CELESTEELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2146
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2142
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2143
            .isShadow = TRUE,
#line 2145
            .heartGauge = 10000,
#line 2144
            .shadowID = 134,
            },
            {
#line 2147
            .species = SPECIES_PHEROMOSA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2152
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2148
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2149
            .isShadow = TRUE,
#line 2151
            .heartGauge = 10000,
#line 2150
            .shadowID = 135,
            },
            {
#line 2153
            .species = SPECIES_NIHILEGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2158
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2154
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2155
            .isShadow = TRUE,
#line 2157
            .heartGauge = 10000,
#line 2156
            .shadowID = 136,
            },
            {
#line 2159
            .species = SPECIES_LUNALA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2160
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2161
            .isShadow = TRUE,
#line 2163
            .heartGauge = 10000,
#line 2162
            .shadowID = 137,
            },
            {
#line 2165
            .species = SPECIES_SOLGALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2166
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2167
            .isShadow = TRUE,
#line 2169
            .heartGauge = 10000,
#line 2168
            .shadowID = 138,
            },
        },
    },
#line 2171
    [DIFFICULTY_NORMAL][TRAINER_COLRESS_SHADOW_REALM] =
    {
#line 2172
        .trainerName = _("COLRESS"),
#line 2173
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 2174
        .trainerPic = TRAINER_PIC_COLRESS_GEN5,
        .encounterMusic_gender =
#line 2176
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 2178
            .species = SPECIES_REGIELEKI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2183
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2179
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2180
            .isShadow = TRUE,
#line 2182
            .heartGauge = 10000,
#line 2181
            .shadowID = 139,
            },
            {
#line 2184
            .species = SPECIES_JIRACHI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2189
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2185
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2186
            .isShadow = TRUE,
#line 2188
            .heartGauge = 10000,
#line 2187
            .shadowID = 140,
            },
            {
#line 2190
            .species = SPECIES_MELMETAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2195
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2191
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2192
            .isShadow = TRUE,
#line 2194
            .heartGauge = 10000,
#line 2193
            .shadowID = 141,
            },
            {
#line 2196
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2201
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2197
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2198
            .isShadow = TRUE,
#line 2200
            .heartGauge = 10000,
#line 2199
            .shadowID = 142,
            },
            {
#line 2202
            .species = SPECIES_GENESECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2207
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2203
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2204
            .isShadow = TRUE,
#line 2206
            .heartGauge = 10000,
#line 2205
            .shadowID = 143,
            },
        },
    },
#line 2208
    [DIFFICULTY_NORMAL][TRAINER_GHETSIS_SHADOW_REALM] =
    {
#line 2209
        .trainerName = _("GHETSIS"),
#line 2210
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 2211
        .trainerPic = TRAINER_PIC_GHETSIS_GEN5,
        .encounterMusic_gender =
#line 2213
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2215
            .species = SPECIES_MARSHADOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2220
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2216
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2217
            .isShadow = TRUE,
#line 2219
            .heartGauge = 10000,
#line 2218
            .shadowID = 145,
            },
            {
#line 2221
            .species = SPECIES_ZARUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2226
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2222
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2223
            .isShadow = TRUE,
#line 2225
            .heartGauge = 10000,
#line 2224
            .shadowID = 146,
            },
            {
#line 2227
            .species = SPECIES_REGIDRAGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2232
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2228
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2229
            .isShadow = TRUE,
#line 2231
            .heartGauge = 10000,
#line 2230
            .shadowID = 147,
            },
            {
#line 2233
            .species = SPECIES_ZEKROM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2238
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2234
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2235
            .isShadow = TRUE,
#line 2237
            .heartGauge = 10000,
#line 2236
            .shadowID = 148,
            },
            {
#line 2239
            .species = SPECIES_RESHIRAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2244
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2240
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2241
            .isShadow = TRUE,
#line 2243
            .heartGauge = 10000,
#line 2242
            .shadowID = 149,
            },
            {
#line 2245
            .species = SPECIES_KYUREM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2246
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2247
            .isShadow = TRUE,
#line 2249
            .heartGauge = 10000,
#line 2248
            .shadowID = 150,
            },
        },
    },
#line 2251
    [DIFFICULTY_NORMAL][TRAINER_MAXIE_SHADOW_REALM] =
    {
#line 2252
        .trainerName = _("MAXIE"),
#line 2253
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 2254
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender =
#line 2256
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2258
            .species = SPECIES_TING_LU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2263
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2259
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2260
            .isShadow = TRUE,
#line 2262
            .heartGauge = 10000,
#line 2261
            .shadowID = 151,
            },
            {
#line 2264
            .species = SPECIES_CHI_YU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2269
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2265
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2266
            .isShadow = TRUE,
#line 2268
            .heartGauge = 10000,
#line 2267
            .shadowID = 152,
            },
            {
#line 2270
            .species = SPECIES_LANDORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2271
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2272
            .isShadow = TRUE,
#line 2274
            .heartGauge = 10000,
#line 2273
            .shadowID = 153,
            },
            {
#line 2276
            .species = SPECIES_HEATRAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2281
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2277
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2278
            .isShadow = TRUE,
#line 2280
            .heartGauge = 10000,
#line 2279
            .shadowID = 154,
            },
            {
#line 2282
            .species = SPECIES_ENTEI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2287
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2283
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2284
            .isShadow = TRUE,
#line 2286
            .heartGauge = 10000,
#line 2285
            .shadowID = 155,
            },
            {
#line 2288
            .species = SPECIES_GROUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2293
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2289
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2290
            .isShadow = TRUE,
#line 2292
            .heartGauge = 10000,
#line 2291
            .shadowID = 156,
            },
        },
    },
#line 2294
    [DIFFICULTY_NORMAL][TRAINER_ARCHIE_SHADOW_REALM] =
    {
#line 2295
        .trainerName = _("ARCHIE"),
#line 2296
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
#line 2297
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .encounterMusic_gender =
#line 2299
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2301
            .species = SPECIES_MANAPHY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2306
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2302
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2303
            .isShadow = TRUE,
#line 2305
            .heartGauge = 10000,
#line 2304
            .shadowID = 157,
            },
            {
#line 2307
            .species = SPECIES_TAPU_FINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2312
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2308
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2309
            .isShadow = TRUE,
#line 2311
            .heartGauge = 10000,
#line 2310
            .shadowID = 158,
            },
            {
#line 2313
            .species = SPECIES_TERAPAGOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2318
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2314
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2315
            .isShadow = TRUE,
#line 2317
            .heartGauge = 10000,
#line 2316
            .shadowID = 159,
            },
            {
#line 2319
            .species = SPECIES_KELDEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2324
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2320
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2321
            .isShadow = TRUE,
#line 2323
            .heartGauge = 10000,
#line 2322
            .shadowID = 160,
            },
            {
#line 2325
            .species = SPECIES_SUICUNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2330
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2326
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2327
            .isShadow = TRUE,
#line 2329
            .heartGauge = 10000,
#line 2328
            .shadowID = 161,
            },
            {
#line 2331
            .species = SPECIES_KYOGRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2336
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2332
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2333
            .isShadow = TRUE,
#line 2335
            .heartGauge = 10000,
#line 2334
            .shadowID = 162,
            },
        },
    },
#line 2337
    [DIFFICULTY_NORMAL][TRAINER_LYSANDRE_SHADOW_REALM] =
    {
#line 2338
        .trainerName = _("LYSANDRE"),
#line 2339
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 2340
        .trainerPic = TRAINER_PIC_LYSANDER,
        .encounterMusic_gender =
#line 2342
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2344
            .species = SPECIES_VICTINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2349
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2345
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2346
            .isShadow = TRUE,
#line 2348
            .heartGauge = 10000,
#line 2347
            .shadowID = 163,
            },
            {
#line 2350
            .species = SPECIES_DIANCIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2355
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2351
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2352
            .isShadow = TRUE,
#line 2354
            .heartGauge = 10000,
#line 2353
            .shadowID = 164,
            },
            {
#line 2356
            .species = SPECIES_WO_CHIEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2361
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2357
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2358
            .isShadow = TRUE,
#line 2360
            .heartGauge = 10000,
#line 2359
            .shadowID = 165,
            },
            {
#line 2362
            .species = SPECIES_VOLCANION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2367
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2363
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2364
            .isShadow = TRUE,
#line 2366
            .heartGauge = 10000,
#line 2365
            .shadowID = 166,
            },
            {
#line 2368
            .species = SPECIES_XERNEAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2373
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2369
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2370
            .isShadow = TRUE,
#line 2372
            .heartGauge = 10000,
#line 2371
            .shadowID = 167,
            },
            {
#line 2374
            .species = SPECIES_YVELTAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2375
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2376
            .isShadow = TRUE,
#line 2378
            .heartGauge = 10000,
#line 2377
            .shadowID = 168,
            },
        },
    },
#line 2380
    [DIFFICULTY_NORMAL][TRAINER_ROSE_SHADOW_REALM] =
    {
#line 2381
        .trainerName = _("ROSE"),
#line 2382
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 2383
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 2385
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2387
            .species = SPECIES_LATIAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2392
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2388
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2389
            .isShadow = TRUE,
#line 2391
            .heartGauge = 10000,
#line 2390
            .shadowID = 169,
            },
            {
#line 2393
            .species = SPECIES_LATIOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2398
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2394
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2395
            .isShadow = TRUE,
#line 2397
            .heartGauge = 10000,
#line 2396
            .shadowID = 170,
            },
            {
#line 2399
            .species = SPECIES_REGISTEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2404
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2400
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2401
            .isShadow = TRUE,
#line 2403
            .heartGauge = 10000,
#line 2402
            .shadowID = 171,
            },
            {
#line 2405
            .species = SPECIES_ZACIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2410
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2406
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2407
            .isShadow = TRUE,
#line 2409
            .heartGauge = 10000,
#line 2408
            .shadowID = 172,
            },
            {
#line 2411
            .species = SPECIES_ZAMAZENTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2416
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2412
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2413
            .isShadow = TRUE,
#line 2415
            .heartGauge = 10000,
#line 2414
            .shadowID = 173,
            },
            {
#line 2417
            .species = SPECIES_ETERNATUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2422
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2418
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2419
            .isShadow = TRUE,
#line 2421
            .heartGauge = 10000,
#line 2420
            .shadowID = 174,
            },
        },
    },
#line 2423
    [DIFFICULTY_NORMAL][TRAINER_SADA_TURO_SHADOW_REALM] =
    {
#line 2424
        .trainerName = _("SADA&TURO"),
#line 2425
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 2426
        .trainerPic = TRAINER_PIC_TURO,
        .encounterMusic_gender =
#line 2427
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2429
            .species = SPECIES_RAIKOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2434
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2430
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2431
            .isShadow = TRUE,
#line 2433
            .heartGauge = 10000,
#line 2432
            .shadowID = 175,
            },
            {
#line 2435
            .species = SPECIES_TAPU_KOKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2440
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2436
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2437
            .isShadow = TRUE,
#line 2439
            .heartGauge = 10000,
#line 2438
            .shadowID = 176,
            },
            {
#line 2441
            .species = SPECIES_ZAPDOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2446
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2442
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2443
            .isShadow = TRUE,
#line 2445
            .heartGauge = 10000,
#line 2444
            .shadowID = 177,
            },
            {
#line 2447
            .species = SPECIES_PECHARUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2452
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2448
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2449
            .isShadow = TRUE,
#line 2451
            .heartGauge = 10000,
#line 2450
            .shadowID = 178,
            },
            {
#line 2453
            .species = SPECIES_MIRAIDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2458
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2454
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2455
            .isShadow = TRUE,
#line 2457
            .heartGauge = 10000,
#line 2456
            .shadowID = 179,
            },
            {
#line 2459
            .species = SPECIES_KORAIDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2464
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2460
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2461
            .isShadow = TRUE,
#line 2463
            .heartGauge = 10000,
#line 2462
            .shadowID = 180,
            },
        },
    },
#line 2465
    [DIFFICULTY_NORMAL][TRAINER_GREEVIL_SHADOW_REALM] =
    {
#line 2466
        .trainerName = _("GREEVIL"),
#line 2467
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 2468
        .trainerPic = TRAINER_PIC_GREEVIL,
        .encounterMusic_gender =
#line 2470
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2472
            .species = SPECIES_CELEBI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2477
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2473
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2474
            .isShadow = TRUE,
#line 2476
            .heartGauge = 10000,
#line 2475
            .shadowID = 181,
            },
            {
#line 2478
            .species = SPECIES_DEOXYS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2483
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2479
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2480
            .isShadow = TRUE,
#line 2482
            .heartGauge = 10000,
#line 2481
            .shadowID = 182,
            },
            {
#line 2484
            .species = SPECIES_NECROZMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2489
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2485
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2486
            .isShadow = TRUE,
#line 2488
            .heartGauge = 10000,
#line 2487
            .shadowID = 183,
            },
            {
#line 2490
            .species = SPECIES_ZYGARDE_COMPLETE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2495
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2491
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2492
            .isShadow = TRUE,
#line 2494
            .heartGauge = 10000,
#line 2493
            .shadowID = 184,
            },
            {
#line 2496
            .species = SPECIES_RAYQUAZA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2501
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2497
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2498
            .isShadow = TRUE,
#line 2500
            .heartGauge = 10000,
#line 2499
            .shadowID = 185,
            },
            {
#line 2502
            .species = SPECIES_LUGIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2507
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2503
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2504
            .isShadow = TRUE,
#line 2506
            .heartGauge = 10000,
#line 2505
            .shadowID = 186,
            },
        },
    },
#line 2508
    [DIFFICULTY_NORMAL][TRAINER_EVICE_SHADOW_REALM] =
    {
#line 2509
        .trainerName = _("EVICE"),
#line 2510
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 2511
        .trainerPic = TRAINER_PIC_EVICE,
        .encounterMusic_gender =
#line 2513
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2515
            .species = SPECIES_VIRIZION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2520
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2516
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2517
            .isShadow = TRUE,
#line 2519
            .heartGauge = 10000,
#line 2518
            .shadowID = 187,
            },
            {
#line 2521
            .species = SPECIES_COBALION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2526
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2522
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2523
            .isShadow = TRUE,
#line 2525
            .heartGauge = 10000,
#line 2524
            .shadowID = 188,
            },
            {
#line 2527
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2532
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2528
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2529
            .isShadow = TRUE,
#line 2531
            .heartGauge = 10000,
#line 2530
            .shadowID = 189,
            },
            {
#line 2533
            .species = SPECIES_CRESSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2538
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2534
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2535
            .isShadow = TRUE,
#line 2537
            .heartGauge = 10000,
#line 2536
            .shadowID = 190,
            },
            {
#line 2539
            .species = SPECIES_MOLTRES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2544
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2540
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2541
            .isShadow = TRUE,
#line 2543
            .heartGauge = 10000,
#line 2542
            .shadowID = 191,
            },
            {
#line 2545
            .species = SPECIES_HO_OH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2550
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2546
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2547
            .isShadow = TRUE,
#line 2549
            .heartGauge = 10000,
#line 2548
            .shadowID = 192,
            },
        },
    },
#line 2551
    [DIFFICULTY_NORMAL][TRAINER_CYRUS_SHADOW_REALM] =
    {
#line 2552
        .trainerName = _("CYRUS"),
#line 2553
        .trainerClass = TRAINER_CLASS_TEAM_GALACTIC,
#line 2554
        .trainerPic = TRAINER_PIC_CYRUS_GEN4,
        .encounterMusic_gender =
#line 2556
            TRAINER_ENCOUNTER_MUSIC_GALACTIC,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2558
            .species = SPECIES_AZELF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2563
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2559
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2560
            .isShadow = TRUE,
#line 2562
            .heartGauge = 10000,
#line 2561
            .shadowID = 193,
            },
            {
#line 2564
            .species = SPECIES_UXIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2569
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2565
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2566
            .isShadow = TRUE,
#line 2568
            .heartGauge = 10000,
#line 2567
            .shadowID = 194,
            },
            {
#line 2570
            .species = SPECIES_MESPRIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2575
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2571
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2572
            .isShadow = TRUE,
#line 2574
            .heartGauge = 10000,
#line 2573
            .shadowID = 195,
            },
            {
#line 2576
            .species = SPECIES_DIALGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2581
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2577
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2578
            .isShadow = TRUE,
#line 2580
            .heartGauge = 10000,
#line 2579
            .shadowID = 196,
            },
            {
#line 2582
            .species = SPECIES_PALKIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2587
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2583
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2584
            .isShadow = TRUE,
#line 2586
            .heartGauge = 10000,
#line 2585
            .shadowID = 197,
            },
            {
#line 2588
            .species = SPECIES_GIRATINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2593
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2589
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2590
            .isShadow = TRUE,
#line 2592
            .heartGauge = 10000,
#line 2591
            .shadowID = 198,
            },
        },
    },
#line 2594
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F1] =
    {
#line 2595
        .trainerName = _("VEXA"),
#line 2596
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2597
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2598
F_TRAINER_FEMALE | 
#line 2599
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2601
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2603
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2602
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2603
                MOVE_SLUDGE_BOMB,
                MOVE_WILL_O_WISP,
                MOVE_CLEAR_SMOG,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 2608
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2610
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2609
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2610
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_STUN_SPORE,
                MOVE_MOONLIGHT,
            },
            },
            {
#line 2615
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2621
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2616
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2617
            .isShadow = TRUE,
#line 2619
            .heartGauge = 7500,
#line 2618
            .shadowID = 4,
#line 2620
            .shadowUnlockMove = MOVE_FELL_STINGER,
            .moves = {
#line 2621
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_PANIC,
            },
            },
        },
    },
#line 2625
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F2] =
    {
#line 2626
        .trainerName = _("NYRA"),
#line 2627
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2628
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2629
F_TRAINER_FEMALE | 
#line 2630
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2632
            .species = SPECIES_TOUCANNON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2634
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2633
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2635
            .species = SPECIES_PIDGEOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2637
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2636
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2638
            .species = SPECIES_HONCHKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2644
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2639
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2640
            .isShadow = TRUE,
#line 2642
            .heartGauge = 7500,
#line 2641
            .shadowID = 30,
#line 2643
            .shadowUnlockMove = MOVE_NIGHT_SLASH,
            .moves = {
#line 2644
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_PANIC,
                MOVE_SHADOW_SKY,
            },
            },
        },
    },
#line 2648
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F3] =
    {
#line 2649
        .trainerName = _("MIRA"),
#line 2650
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2651
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2652
F_TRAINER_FEMALE | 
#line 2653
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2655
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2657
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2656
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2658
            .species = SPECIES_PILOSWINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2660
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2659
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2660
                MOVE_ICY_WIND,
                MOVE_MUD_SLAP,
                MOVE_ROCK_TOMB,
                MOVE_HAIL,
            },
            },
            {
#line 2665
            .species = SPECIES_BEARTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2671
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2666
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2667
            .isShadow = TRUE,
#line 2669
            .heartGauge = 7500,
#line 2668
            .shadowID = 35,
#line 2670
            .shadowUnlockMove = MOVE_ICICLE_CRASH,
            .moves = {
#line 2671
                MOVE_SHADOW_CHILL,
                MOVE_SHADOW_STORM,
                MOVE_SHADOW_END,
            },
            },
        },
    },
#line 2675
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F4] =
    {
#line 2676
        .trainerName = _("SERA"),
#line 2677
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2678
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2679
F_TRAINER_FEMALE | 
#line 2680
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2682
            .species = SPECIES_AVALUGG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2684
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2683
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2685
            .species = SPECIES_FROSLASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2687
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2686
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2688
            .species = SPECIES_AURORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2694
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2689
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2690
            .isShadow = TRUE,
#line 2692
            .heartGauge = 7500,
#line 2691
            .shadowID = 44,
#line 2693
            .shadowUnlockMove = MOVE_ANCIENT_POWER,
            .moves = {
#line 2694
                MOVE_SHADOW_CHILL,
                MOVE_SHADOW_STORM,
                MOVE_SHADOW_SKY,
            },
            },
        },
    },
#line 2698
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F5] =
    {
#line 2699
        .trainerName = _("ZIA"),
#line 2700
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2701
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2702
F_TRAINER_FEMALE | 
#line 2703
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2705
            .species = SPECIES_SKUNTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2707
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2706
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2707
                MOVE_TOXIC,
                MOVE_SUCKER_PUNCH,
                MOVE_ACID_SPRAY,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 2712
            .species = SPECIES_WEEZING_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2714
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2713
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2715
            .species = SPECIES_SALAZZLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2721
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2716
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2717
            .isShadow = TRUE,
#line 2719
            .heartGauge = 7500,
#line 2718
            .shadowID = 47,
#line 2720
            .shadowUnlockMove = MOVE_FLAMETHROWER,
            .moves = {
#line 2721
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_MIST,
                MOVE_SHADOW_PANIC,
            },
            },
        },
    },
#line 2725
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F6] =
    {
#line 2726
        .trainerName = _("VERA"),
#line 2727
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2728
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2729
F_TRAINER_FEMALE | 
#line 2730
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2732
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2734
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2733
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2734
                MOVE_ACID_SPRAY,
                MOVE_WATER_PULSE,
                MOVE_ICY_WIND,
                MOVE_HEX,
            },
            },
            {
#line 2739
            .species = SPECIES_OVERQWIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2741
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2740
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2742
            .species = SPECIES_TOXAPEX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2748
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2743
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2744
            .isShadow = TRUE,
#line 2746
            .heartGauge = 7500,
#line 2745
            .shadowID = 51,
#line 2747
            .shadowUnlockMove = MOVE_BANEFUL_BUNKER,
            .moves = {
#line 2748
                MOVE_SHADOW_DOWN,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_MIST,
            },
            },
        },
    },
#line 2752
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F7] =
    {
#line 2753
        .trainerName = _("LYNX"),
#line 2754
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2755
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2756
F_TRAINER_FEMALE | 
#line 2757
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2759
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2761
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2760
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2762
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2764
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2763
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2764
                MOVE_STUN_SPORE,
                MOVE_AIR_CUTTER,
                MOVE_WATER_PULSE,
                MOVE_SCARY_FACE,
            },
            },
            {
#line 2769
            .species = SPECIES_ARAQUANID,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2775
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2770
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2771
            .isShadow = TRUE,
#line 2773
            .heartGauge = 10000,
#line 2772
            .shadowID = 53,
#line 2774
            .shadowUnlockMove = MOVE_LIQUIDATION,
            .moves = {
#line 2775
                MOVE_SHADOW_MIST,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_CHILL,
            },
            },
        },
    },
#line 2779
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F8] =
    {
#line 2780
        .trainerName = _("KORA"),
#line 2781
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2782
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2783
F_TRAINER_FEMALE | 
#line 2784
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2786
            .species = SPECIES_KLANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2788
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2787
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2788
                MOVE_THUNDER_WAVE,
                MOVE_GEAR_GRIND,
                MOVE_SCREECH,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 2793
            .species = SPECIES_GLISCOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2795
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2794
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2796
            .species = SPECIES_COPPERAJAH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2802
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2797
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2798
            .isShadow = TRUE,
#line 2800
            .heartGauge = 7500,
#line 2799
            .shadowID = 54,
#line 2801
            .shadowUnlockMove = MOVE_HEAVY_SLAM,
            .moves = {
#line 2802
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_BREAK,
                MOVE_SHADOW_BLITZ,
            },
            },
        },
    },
#line 2806
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F9] =
    {
#line 2807
        .trainerName = _("VESPA"),
#line 2808
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2809
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2810
F_TRAINER_FEMALE | 
#line 2811
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2813
            .species = SPECIES_GALVANTULA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2815
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2814
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2815
                MOVE_STICKY_WEB,
                MOVE_VOLT_SWITCH,
                MOVE_BUG_BUZZ,
                MOVE_THUNDER_WAVE,
            },
            },
            {
#line 2820
            .species = SPECIES_SCOVILLAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2822
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2821
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2823
            .species = SPECIES_CENTISKORCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2829
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2824
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2825
            .isShadow = TRUE,
#line 2827
            .heartGauge = 7500,
#line 2826
            .shadowID = 58,
#line 2828
            .shadowUnlockMove = MOVE_FIRE_LASH,
            .moves = {
#line 2829
                MOVE_SHADOW_FIRE,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_BLITZ,
            },
            },
        },
    },
#line 2833
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_M1] =
    {
#line 2834
        .trainerName = _("DREX"),
#line 2835
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2836
        .trainerPic = TRAINER_PIC_CIPHER_PEON_M,
        .encounterMusic_gender =
#line 2838
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2840
            .species = SPECIES_ELECTABUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2842
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2841
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2842
                MOVE_THUNDER_WAVE,
                MOVE_SHOCK_WAVE,
                MOVE_LIGHT_SCREEN,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 2847
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2849
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2848
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 2849
                MOVE_ELECTRO_BALL,
                MOVE_MIRROR_SHOT,
                MOVE_THUNDER_WAVE,
                MOVE_TRI_ATTACK,
            },
            },
            {
#line 2854
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2860
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2855
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2856
            .isShadow = TRUE,
#line 2858
            .heartGauge = 7500,
#line 2857
            .shadowID = 22,
#line 2859
            .shadowUnlockMove = MOVE_THUNDER_FANG,
            .moves = {
#line 2860
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_BOLT,
                MOVE_SHADOW_HOLD,
            },
            },
        },
    },
#line 2864
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER_WALT] =
    {
#line 2865
        .trainerName = _("WALT"),
#line 2866
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 2867
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2870
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2872
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2871
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2873
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2875
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2874
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2876
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER_2] =
    {
#line 2877
        .trainerName = _("OLLIE"),
#line 2878
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 2879
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2882
            .species = SPECIES_BIDOOF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2884
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2883
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2885
            .species = SPECIES_STARLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2887
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2886
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2888
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_COOLTRAINER] =
    {
#line 2889
        .trainerName = _("DAREN"),
#line 2890
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 2891
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2894
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2896
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2895
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2897
            .species = SPECIES_RIOLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2899
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2898
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2900
    [DIFFICULTY_NORMAL][TRAINER_ROUTE30_YOUNGSTER] =
    {
#line 2901
        .trainerName = _("KYLE"),
#line 2902
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 2903
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2906
            .species = SPECIES_SENTRET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2908
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2907
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2909
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2911
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2910
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2912
    [DIFFICULTY_NORMAL][TRAINER_ROUTE30_BUG_CATCHER] =
    {
#line 2913
        .trainerName = _("MILO"),
#line 2914
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 2915
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2918
            .species = SPECIES_SCATTERBUG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2920
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2919
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2921
            .species = SPECIES_SPINARAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2923
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2922
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2924
    [DIFFICULTY_NORMAL][TRAINER_ROUTE31_YOUNGSTER] =
    {
#line 2925
        .trainerName = _("JARED"),
#line 2926
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 2927
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2930
            .species = SPECIES_STARAVIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2932
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2931
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2933
            .species = SPECIES_LUXIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2935
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2934
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2936
    [DIFFICULTY_NORMAL][TRAINER_ROUTE31_BUG_CATCHER] =
    {
#line 2937
        .trainerName = _("ELI"),
#line 2938
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 2939
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2942
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2944
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2943
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2945
            .species = SPECIES_ARIADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2947
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2946
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2948
    [DIFFICULTY_NORMAL][TRAINER_ROUTE20_FISHERMAN] =
    {
#line 2949
        .trainerName = _("WADE"),
#line 2950
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 2951
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2954
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2955
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2957
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2959
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2958
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2960
            .species = SPECIES_BASCULIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2962
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2961
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2963
    [DIFFICULTY_NORMAL][TRAINER_ROUTE20_SWIMMER_F1] =
    {
#line 2964
        .trainerName = _("MARINA"),
#line 2965
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 2966
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 2967
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2969
            .species = SPECIES_WISHIWASHI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2971
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2970
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2972
            .species = SPECIES_FRILLISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2974
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2973
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2975
            .species = SPECIES_ALOMOMOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2977
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2976
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2978
    [DIFFICULTY_NORMAL][TRAINER_ROUTE20_SWIMMER_F2] =
    {
#line 2979
        .trainerName = _("SELENE"),
#line 2980
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 2981
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 2982
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2984
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2986
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2985
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2987
            .species = SPECIES_BRUXISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2989
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2988
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2990
            .species = SPECIES_JELLICENT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2992
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2991
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2993
    [DIFFICULTY_NORMAL][TRAINER_ROUTE20_SWIMMER_M] =
    {
#line 2994
        .trainerName = _("BROOKS"),
#line 2995
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2996
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2999
            .species = SPECIES_BASCULIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3001
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3000
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3002
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3004
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3003
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3005
            .species = SPECIES_JELLICENT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3007
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3006
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3008
    [DIFFICULTY_NORMAL][TRAINER_RUSTBORO_ROXANNE] =
    {
#line 3009
        .trainerName = _("ROXANNE"),
#line 3010
        .trainerClass = TRAINER_CLASS_LEADER,
#line 3011
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
#line 3012
F_TRAINER_FEMALE | 
#line 3013
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 3015
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3017
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3016
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3018
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3020
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3019
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3021
            .species = SPECIES_KROOKODILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3023
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3022
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3024
            .species = SPECIES_FLYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3026
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3025
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3027
            .species = SPECIES_MAMOSWINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3029
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3028
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3030
            .species = SPECIES_EXCADRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3032
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3031
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3033
    [DIFFICULTY_NORMAL][TRAINER_JOSH] =
    {
#line 3034
        .trainerName = _("JOSH"),
#line 3035
        .trainerClass = TRAINER_CLASS_HIKER,
#line 3036
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3039
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3041
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3040
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3042
            .species = SPECIES_STUNFISK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3044
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3043
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3045
            .species = SPECIES_MUDSDALE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3047
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3046
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3048
    [DIFFICULTY_NORMAL][TRAINER_TOMMY] =
    {
#line 3049
        .trainerName = _("TOMMY"),
#line 3050
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 3051
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3054
            .species = SPECIES_PALPITOAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3056
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3055
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3057
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3059
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3058
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3060
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3062
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3061
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3063
    [DIFFICULTY_NORMAL][TRAINER_MARC] =
    {
#line 3064
        .trainerName = _("MARC"),
#line 3065
        .trainerClass = TRAINER_CLASS_HIKER,
#line 3066
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3069
            .species = SPECIES_DIGGERSBY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3071
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3070
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3072
            .species = SPECIES_GOLURK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3074
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3073
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3075
            .species = SPECIES_FLYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3077
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3076
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3078
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_MARNIE] =
    {
#line 3079
        .trainerName = _("MARNIE"),
#line 3080
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 3081
        .trainerPic = TRAINER_PIC_MARNIE,
        .encounterMusic_gender =
#line 3082
F_TRAINER_FEMALE | 
#line 3083
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3085
            .species = SPECIES_MANDIBUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3087
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3086
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3088
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3090
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3089
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3091
            .species = SPECIES_KROOKODILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3093
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3092
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3094
            .species = SPECIES_MORPEKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3096
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3095
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3097
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3098
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 3099
            .isShadow = TRUE,
#line 3101
            .heartGauge = 7500,
#line 3100
            .shadowID = 17,
#line 3102
            .shadowUnlockMove = MOVE_PSYCHO_CUT,
            .moves = {
#line 3103
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_BREAK,
                MOVE_SHADOW_SKY,
            },
            },
        },
    },
#line 3107
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_UNDERGROUND_SWITCHES_ROCKET_1] =
    {
#line 3108
        .trainerName = _("JAX"),
#line 3109
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 3110
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 3112
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3114
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3116
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3115
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3117
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3119
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3118
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3120
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3122
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3121
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3123
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_UNDERGROUND_SWITCHES_ROCKET_2] =
    {
#line 3124
        .trainerName = _("REESE"),
#line 3125
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 3126
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 3128
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3130
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3132
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3131
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3133
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3135
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3134
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3136
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3138
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3137
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3139
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_UNDERGROUND_SWITCHES_BURGLAR] =
    {
#line 3140
        .trainerName = _("VINCE"),
#line 3141
        .trainerClass = TRAINER_CLASS_BURGLAR,
#line 3142
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
#line 3144
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3146
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3148
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3147
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3149
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3151
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3150
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3152
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3154
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3153
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3155
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_UNDERGROUND_STORAGE_ROCKET] =
    {
#line 3156
        .trainerName = _("CLYDE"),
#line 3157
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 3158
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 3160
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3162
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3163
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3165
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3167
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3166
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3168
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3169
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3171
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M_TYLER] =
    {
#line 3172
        .trainerName = _("TYLER"),
#line 3173
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 3174
        .trainerPic = TRAINER_PIC_SWIMMER_M_GEN2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3177
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3178
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3180
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3182
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3181
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 3183
    [DIFFICULTY_NORMAL][TRAINER_PEWTER_GYM_CAMPER_JERRY] =
    {
#line 3184
        .trainerName = _("JERRY"),
#line 3185
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3186
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3189
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3192
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3190
            .lvl = 12,
#line 3191
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 3194
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3197
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 3195
            .lvl = 12,
#line 3196
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
