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
            .moves = {
#line 90
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 92
    [DIFFICULTY_NORMAL][TRAINER_JJ_VIRIDIAN] =
    {
#line 93
        .trainerName = _("JESS&JAMES"),
#line 94
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 95
        .trainerPic = TRAINER_PIC_JESSIE_JAMES,
        .encounterMusic_gender =
#line 96
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 98
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 100
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 99
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 101
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 102
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 104
    [DIFFICULTY_NORMAL][TRAINER_BROCK_KANTO] =
    {
#line 105
        .trainerName = _("BROCK"),
#line 106
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 108
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .encounterMusic_gender =
#line 107
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 111
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 115
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 112
            .lvl = 14,
#line 113
            .ball = ITEM_HEAVY_BALL,
#line 114
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 115
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 120
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 124
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 121
            .lvl = 16,
#line 122
            .ball = ITEM_HEAVY_BALL,
#line 123
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 124
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_THROW,
                MOVE_SCREECH,
            },
            },
            {
#line 129
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 133
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 130
            .lvl = 16,
#line 131
            .ball = ITEM_HEAVY_BALL,
#line 132
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 133
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 138
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_KANTO] =
    {
#line 139
        .trainerName = _("JERRY"),
#line 140
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 141
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 144
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 145
            .lvl = 12,
#line 146
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 147
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 150
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 153
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 151
            .lvl = 12,
#line 152
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 153
                MOVE_PECK,
                MOVE_GROWL,
            },
            },
        },
    },
#line 156
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AL] =
    {
#line 157
        .trainerName = _("AL"),
#line 158
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 159
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 162
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 164
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 163
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 165
            .species = SPECIES_ARIADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 167
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 166
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 168
            .species = SPECIES_VIVILLON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 169
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 171
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_JOSH] =
    {
#line 172
        .trainerName = _("JOSH"),
#line 173
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 174
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 177
            .species = SPECIES_FORRETRESS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 178
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 180
            .species = SPECIES_KRICKETUNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 182
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 181
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 183
            .species = SPECIES_SHUCKLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 185
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 184
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 186
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_BENNY] =
    {
#line 187
        .trainerName = _("BENNY"),
#line 188
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 189
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 192
            .species = SPECIES_VESPIQUEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 194
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 193
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 195
            .species = SPECIES_YANMEGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 197
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 196
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 198
            .species = SPECIES_MOTHIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 200
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 199
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 201
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AMY_AND_MAY] =
    {
#line 202
        .trainerName = _("AMY&MAY"),
#line 203
        .trainerClass = TRAINER_CLASS_TWINS,
#line 204
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 205
F_TRAINER_FEMALE | 
0,
#line 206
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 208
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 210
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 209
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 211
            .species = SPECIES_ARIADOS,
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
            .species = SPECIES_WORMADAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 216
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 215
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 217
    [DIFFICULTY_NORMAL][TRAINER_BUGSY_1] =
    {
#line 218
        .trainerName = _("BUGSY"),
#line 219
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 221
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .encounterMusic_gender =
#line 220
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 224
            .species = SPECIES_KLEAVOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 226
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 225
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 227
            .species = SPECIES_HERACROSS,
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
            .species = SPECIES_VIKAVOLT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 232
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 231
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 233
            .species = SPECIES_SCIZOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 235
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 234
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 236
    [DIFFICULTY_NORMAL][TRAINER_LEADER_FALKNER] =
    {
#line 237
        .trainerName = _("FALKNER"),
#line 238
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 239
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .encounterMusic_gender =
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 242
            .species = SPECIES_FEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 244
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 243
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 245
            .species = SPECIES_ORICORIO_PAU,
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
            .species = SPECIES_TRANQUILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 249
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 251
            .species = SPECIES_HONCHKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 253
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 252
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 254
    [DIFFICULTY_NORMAL][TRAINER_MISTY] =
    {
#line 255
        .trainerName = _("MISTY"),
#line 256
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 258
        .trainerPic = TRAINER_PIC_MISTY,
        .encounterMusic_gender =
#line 259
F_TRAINER_FEMALE | 
#line 257
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 261
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 264
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 262
            .lvl = 19,
#line 263
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 265
            .species = SPECIES_CORSOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 268
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 266
            .lvl = 19,
#line 267
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 269
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 272
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 270
            .lvl = 20,
#line 271
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 273
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 276
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 274
            .lvl = 22,
#line 275
            .ball = ITEM_DIVE_BALL,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 276
                MOVE_TWISTER,
                MOVE_BITE,
                MOVE_LEER,
                MOVE_THUNDER_WAVE,
            },
            },
        },
    },
#line 281
    [DIFFICULTY_NORMAL][TRAINER_ROCKET_GRUNT_M_1] =
    {
#line 282
        .trainerName = _("ZANDER"),
#line 283
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 284
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 286
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 287
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 289
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 292
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 290
            .lvl = 23,
#line 291
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 293
            .isShadow = TRUE,
#line 295
            .heartGauge = 5000,
#line 294
            .shadowID = 49,
            .moves = {
#line 296
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_SKY,
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 300
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER1] =
    {
#line 301
        .trainerName = _("Neil"),
#line 302
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 303
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 306
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 308
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 307
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 309
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 311
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 310
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 312
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 314
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 313
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 315
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER2] =
    {
#line 316
        .trainerName = _("Rick"),
#line 317
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 318
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 321
            .species = SPECIES_CUTIEFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 323
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 322
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 324
            .species = SPECIES_GRUBBIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 326
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 325
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 327
            .species = SPECIES_JOLTIK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 329
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 328
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 330
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER3] =
    {
#line 331
        .trainerName = _("Jamal"),
#line 332
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 333
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 336
            .species = SPECIES_VENIPEDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 338
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 337
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 339
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 341
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 340
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 342
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 344
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 343
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 345
    [DIFFICULTY_NORMAL][TRAINER_VF_ROCKET] =
    {
#line 346
        .trainerName = _("Travis"),
#line 347
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 348
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 350
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 351
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 353
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 355
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 354
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 356
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 358
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 357
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 359
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER1] =
    {
#line 360
        .trainerName = _("BEN"),
#line 361
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 362
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 365
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 367
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 366
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 368
            .species = SPECIES_WOOBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 370
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 369
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 371
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER2] =
    {
#line 372
        .trainerName = _("CALVIN"),
#line 373
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 374
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 377
            .species = SPECIES_MUDBRAY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 378
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 380
            .species = SPECIES_MINCCINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 382
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 381
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 383
    [DIFFICULTY_NORMAL][TRAINER_RT3_LASS] =
    {
#line 384
        .trainerName = _("LASS"),
#line 385
        .trainerClass = TRAINER_CLASS_LASS,
#line 386
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 387
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 389
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 391
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 390
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 392
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 394
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 393
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 395
    [DIFFICULTY_NORMAL][TRAINER_RT3_FIREBREATHER] =
    {
#line 396
        .trainerName = _("Otis"),
#line 397
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 398
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 401
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 403
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 402
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 404
            .species = SPECIES_AUDINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 406
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 405
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 407
    [DIFFICULTY_NORMAL][TRAINER_TEMP_MIROR_B] =
    {
#line 408
        .trainerName = _("MIROR B"),
#line 409
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 410
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 412
            TRAINER_ENCOUNTER_MUSIC_MIRRORB,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 414
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 416
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 415
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 417
    [DIFFICULTY_NORMAL][TRAINER_RT4_BLACK_BELT] =
    {
#line 418
        .trainerName = _("RYU"),
#line 419
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 420
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 423
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 425
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 424
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 426
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 428
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 427
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 429
    [DIFFICULTY_NORMAL][TRAINER_RT4_ROCKER] =
    {
#line 430
        .trainerName = _("AMP"),
#line 431
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 432
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 435
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 437
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 436
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 438
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 440
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 439
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 441
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER1] =
    {
#line 442
        .trainerName = _("LILY"),
#line 443
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 444
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 445
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 447
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 449
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 448
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 450
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 452
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 451
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 453
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER2] =
    {
#line 454
        .trainerName = _("MIA"),
#line 455
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 456
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 457
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 459
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 461
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 460
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 462
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 464
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 463
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 465
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN1] =
    {
#line 466
        .trainerName = _("BRENDAN"),
#line 467
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 468
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 471
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 473
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 472
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 474
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 476
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 475
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 477
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN2] =
    {
#line 478
        .trainerName = _("BRENDAN"),
#line 479
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 480
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 483
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 485
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 484
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 486
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 488
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 487
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 489
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN3] =
    {
#line 490
        .trainerName = _("BRENDAN"),
#line 491
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 492
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 495
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 497
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 496
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 498
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 500
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 499
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 501
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_1] =
    {
#line 502
        .trainerName = _("MARK"),
#line 503
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 504
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 507
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 509
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 508
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 510
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 512
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 511
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 513
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_2] =
    {
#line 514
        .trainerName = _("TROY"),
#line 515
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 516
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 519
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 521
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 520
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 522
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 524
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 523
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 525
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_1] =
    {
#line 526
        .trainerName = _("RINA"),
#line 527
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 528
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 529
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 531
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 533
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 532
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 534
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 536
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 535
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 537
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_2] =
    {
#line 538
        .trainerName = _("MEL"),
#line 539
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 540
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 541
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 543
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 545
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 544
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 546
    [DIFFICULTY_NORMAL][TRAINER_JJ_ILEX] =
    {
#line 547
        .trainerName = _("JESS&JAMES"),
#line 548
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 549
        .trainerPic = TRAINER_PIC_JESSIE_JAMES,
        .encounterMusic_gender =
#line 550
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 552
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 554
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 553
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 555
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 557
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 556
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 558
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 563
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 559
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 560
            .isShadow = TRUE,
#line 562
            .heartGauge = 5000,
#line 561
            .shadowID = 8,
            .moves = {
#line 563
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 565
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F1] =
    {
#line 566
        .trainerName = _("SABRINA"),
#line 567
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 568
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 569
F_TRAINER_FEMALE | 
#line 570
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 571
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 573
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 575
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 574
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 576
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 578
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 577
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 579
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M1] =
    {
#line 580
        .trainerName = _("RORY"),
#line 581
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 582
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 584
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 585
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 587
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 589
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 588
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 590
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 592
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 591
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 593
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F2] =
    {
#line 594
        .trainerName = _("LANA"),
#line 595
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 596
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 597
F_TRAINER_FEMALE | 
#line 598
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 599
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 601
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 603
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 602
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 604
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 606
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 605
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 607
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 609
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 608
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 610
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M2] =
    {
#line 611
        .trainerName = _("MARK"),
#line 612
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 613
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 615
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 616
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 618
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 620
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 619
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 621
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 623
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 622
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 624
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M3] =
    {
#line 625
        .trainerName = _("TODD"),
#line 626
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 627
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 629
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 630
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 632
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 634
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 633
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 635
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 637
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 636
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 638
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F3] =
    {
#line 639
        .trainerName = _("RINA"),
#line 640
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 641
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 642
F_TRAINER_FEMALE | 
#line 643
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 644
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 646
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 648
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 647
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 649
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 651
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 650
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 652
    [DIFFICULTY_NORMAL][TRAINER_ILEX_BUG_CATCHER] =
    {
#line 653
        .trainerName = _("BEN"),
#line 654
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 655
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 658
            .species = SPECIES_LEDYBA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 660
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 659
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 661
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 663
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 662
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 664
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 666
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 665
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 667
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_1] =
    {
#line 668
        .trainerName = _("GABE"),
#line 669
        .trainerClass = TRAINER_CLASS_HIKER,
#line 670
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 673
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 675
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 674
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 676
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 678
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 677
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 679
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_2] =
    {
#line 680
        .trainerName = _("RUSTY"),
#line 681
        .trainerClass = TRAINER_CLASS_HIKER,
#line 682
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 685
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 687
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 686
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 688
    [DIFFICULTY_NORMAL][TRAINER_LOOKER_CERULEAN] =
    {
#line 689
        .trainerName = _("LOOKER"),
#line 690
        .trainerClass = TRAINER_CLASS_POLICEMAN,
#line 691
        .trainerPic = TRAINER_PIC_LOOKER_GEN5,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 694
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 697
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 695
            .lvl = 16,
#line 696
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 697
                MOVE_BITE,
                MOVE_EMBER,
            },
            },
            {
#line 700
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 703
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 701
            .lvl = 18,
#line 702
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 703
                MOVE_LOW_KICK,
                MOVE_MUD_SLAP,
            },
            },
        },
    },
#line 706
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER1] =
    {
#line 707
        .trainerName = _("TIM"),
#line 708
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 709
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 712
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 714
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 713
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 715
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 717
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 716
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 718
    [DIFFICULTY_NORMAL][TRAINER_RT25_LADY] =
    {
#line 719
        .trainerName = _("MARIE"),
#line 720
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 721
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 722
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 724
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 726
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 725
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 727
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 729
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 728
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 730
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_F] =
    {
#line 731
        .trainerName = _("KARA"),
#line 732
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 733
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 734
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 736
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 738
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 737
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 739
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 741
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 740
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 742
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER2] =
    {
#line 743
        .trainerName = _("BEN"),
#line 744
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 745
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 748
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 750
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 749
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 751
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 753
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 752
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 754
    [DIFFICULTY_NORMAL][TRAINER_RT25_CAMPER] =
    {
#line 755
        .trainerName = _("COLE"),
#line 756
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 757
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 760
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 762
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 761
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 763
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 765
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 764
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 766
    [DIFFICULTY_NORMAL][TRAINER_RT25_LASS] =
    {
#line 767
        .trainerName = _("NINA"),
#line 768
        .trainerClass = TRAINER_CLASS_LASS,
#line 769
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 770
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 772
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 774
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 773
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 775
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 777
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 776
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 778
    [DIFFICULTY_NORMAL][TRAINER_RT25_SUPER_NERD] =
    {
#line 779
        .trainerName = _("DEX"),
#line 780
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 781
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 784
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 786
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 785
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 787
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 789
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 788
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 790
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M] =
    {
#line 791
        .trainerName = _("TYLER"),
#line 792
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 793
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 796
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 798
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 797
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 799
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 801
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 800
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 802
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F1] =
    {
#line 803
        .trainerName = _("MAYA"),
#line 804
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 805
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 806
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 808
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 810
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 809
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 811
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 813
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 812
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 814
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F2] =
    {
#line 815
        .trainerName = _("KAREN"),
#line 816
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 817
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 818
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 820
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 822
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 821
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 823
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 825
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 824
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 826
    [DIFFICULTY_NORMAL][TRAINER_KURTS_HOUSE_IRONMASK] =
    {
#line 827
        .trainerName = _("MARAUDER"),
#line 828
        .trainerClass = TRAINER_CLASS_ROCKET_ADMIN,
#line 829
        .trainerPic = TRAINER_PIC_IRON_MASKED_MARAUDER,
        .encounterMusic_gender =
#line 830
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 832
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 834
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 833
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 835
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 837
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 836
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 838
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 844
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 839
            .lvl = 29,
#line 840
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 841
            .isShadow = TRUE,
#line 843
            .heartGauge = 7500,
#line 842
            .shadowID = 9,
            .moves = {
#line 844
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_MIST,
                MOVE_SHADOW_SHED,
            },
            },
        },
    },
#line 849
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_1] =
    {
#line 850
        .trainerName = _("AXEL"),
#line 851
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 852
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 853
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 855
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 857
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 856
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 858
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 860
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 859
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 861
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_2] =
    {
#line 862
        .trainerName = _("DANE"),
#line 863
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 864
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 865
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 867
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 869
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 868
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 870
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 872
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 871
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 873
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_3] =
    {
#line 874
        .trainerName = _("MIRA"),
#line 875
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 876
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 877
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 879
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 881
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 880
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 882
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 884
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 883
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 885
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_4] =
    {
#line 886
        .trainerName = _("COLT"),
#line 887
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 888
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 889
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 891
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 893
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 892
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 894
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 896
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 895
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 897
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_5] =
    {
#line 898
        .trainerName = _("ROOK"),
#line 899
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 900
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 901
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 903
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 905
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 904
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 906
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 908
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 907
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 909
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_6] =
    {
#line 910
        .trainerName = _("NASH"),
#line 911
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 912
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 913
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 915
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 917
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 916
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 918
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 920
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 919
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 921
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_1] =
    {
#line 922
        .trainerName = _("FAYE"),
#line 923
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 924
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 925
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 927
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 929
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 928
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 930
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 932
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 931
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 933
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_2] =
    {
#line 934
        .trainerName = _("ORIN"),
#line 935
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 936
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 937
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 939
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 941
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 940
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 942
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 944
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 943
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 945
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_3] =
    {
#line 946
        .trainerName = _("GAGE"),
#line 947
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 948
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 949
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 951
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 953
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 952
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 954
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 955
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 957
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_4] =
    {
#line 958
        .trainerName = _("NYX"),
#line 959
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 960
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 961
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 963
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 965
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 964
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 966
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 968
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 967
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 969
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_5] =
    {
#line 970
        .trainerName = _("KADE"),
#line 971
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 972
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 973
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 975
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 977
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 976
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 978
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 980
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 979
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 981
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_6] =
    {
#line 982
        .trainerName = _("VOSS"),
#line 983
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 984
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 985
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 987
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 989
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 988
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 990
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 992
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 991
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 993
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_7] =
    {
#line 994
        .trainerName = _("IRIS"),
#line 995
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 996
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 997
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 999
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1001
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1000
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1002
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1004
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1003
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1005
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_8] =
    {
#line 1006
        .trainerName = _("SERA"),
#line 1007
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1008
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1009
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1011
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1013
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1012
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1014
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1016
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1015
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1017
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_BRYONY] =
    {
#line 1018
        .trainerName = _("BRYONY"),
#line 1019
        .trainerClass = TRAINER_CLASS_TEAM_FLARE_ADMIN,
#line 1020
        .trainerPic = TRAINER_PIC_BRYONY,
        .encounterMusic_gender =
#line 1021
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1023
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1025
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1024
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1026
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1028
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1027
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1029
            .species = SPECIES_PANGORO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1035
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1030
            .lvl = 29,
#line 1031
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1032
            .isShadow = TRUE,
#line 1034
            .heartGauge = 7500,
#line 1033
            .shadowID = 45,
            .moves = {
#line 1035
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_BREAK,
                MOVE_SHADOW_DOWN,
                MOVE_SHADOW_HALF,
            },
            },
        },
    },
#line 1040
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_1] =
    {
#line 1041
        .trainerName = _("VESPER"),
#line 1042
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1043
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1044
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1046
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1048
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1047
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1049
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1051
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1050
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1052
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_2] =
    {
#line 1053
        .trainerName = _("ORLA"),
#line 1054
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1055
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1056
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1058
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1060
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1059
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1061
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1063
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1062
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1064
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_3] =
    {
#line 1065
        .trainerName = _("KADE"),
#line 1066
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1067
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1068
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1070
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1072
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1071
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1073
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1075
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1074
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1076
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_1] =
    {
#line 1077
        .trainerName = _("ROBIN"),
#line 1078
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1079
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1081
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1083
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1082
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1084
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1086
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1085
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1087
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_2] =
    {
#line 1088
        .trainerName = _("KYLE"),
#line 1089
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1090
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1092
            .species = SPECIES_TRUMBEAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1094
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1093
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1095
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1097
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1096
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1098
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER] =
    {
#line 1099
        .trainerName = _("TIM"),
#line 1100
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1101
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1104
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1106
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1105
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1107
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1109
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1108
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1110
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_PICNICKER] =
    {
#line 1111
        .trainerName = _("LINA"),
#line 1112
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1113
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1114
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1116
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1118
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1117
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1119
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1121
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1120
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1122
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_1] =
    {
#line 1123
        .trainerName = _("RAY"),
#line 1124
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1125
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1128
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1130
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1129
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1131
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_2] =
    {
#line 1132
        .trainerName = _("NED"),
#line 1133
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1134
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1137
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1139
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1138
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1140
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_3] =
    {
#line 1141
        .trainerName = _("LEO"),
#line 1142
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1143
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1146
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1148
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1147
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1149
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_BIRD_KEEPER] =
    {
#line 1150
        .trainerName = _("MILO"),
#line 1151
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1152
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1155
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1157
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1156
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1158
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1160
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1159
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1161
    [DIFFICULTY_NORMAL][TRAINER_ROUTE33_HIKER] =
    {
#line 1162
        .trainerName = _("DUKE"),
#line 1163
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1164
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1167
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1169
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1168
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1170
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_CAMPER] =
    {
#line 1171
        .trainerName = _("NATE"),
#line 1172
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1173
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1176
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1178
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1177
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1179
            .species = SPECIES_SKIDDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1181
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1180
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1182
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_GENTLEMAN] =
    {
#line 1183
        .trainerName = _("ALFRED"),
#line 1184
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 1185
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1188
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1190
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1189
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1191
            .species = SPECIES_DUNSPARCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1193
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1192
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1194
            .species = SPECIES_STANTLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1196
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1195
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1197
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_YOUNGSTER] =
    {
#line 1198
        .trainerName = _("TIM"),
#line 1199
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1200
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1203
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1205
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1204
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1206
            .species = SPECIES_STARLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1208
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1207
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1209
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_HIKER] =
    {
#line 1210
        .trainerName = _("GUS"),
#line 1211
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1212
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1215
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1217
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1216
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1218
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1220
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1219
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1221
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_SUPER_NERD] =
    {
#line 1222
        .trainerName = _("TREV"),
#line 1223
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1224
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1227
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1229
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1228
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1230
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER] =
    {
#line 1231
        .trainerName = _("BO"),
#line 1232
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 1233
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1236
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1238
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1237
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1239
    [DIFFICULTY_NORMAL][TRAINER_SILVER_HUNTER] =
    {
#line 1240
        .trainerName = _("SILVER"),
#line 1241
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 1242
        .trainerPic = TRAINER_PIC_SILVER,
        .encounterMusic_gender =
#line 1244
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1246
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1248
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1247
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1249
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SHAUNA] =
    {
#line 1250
        .trainerName = _("SHAUNA"),
#line 1251
        .trainerClass = TRAINER_CLASS_LASS,
#line 1252
        .trainerPic = TRAINER_PIC_SHAUNA,
        .encounterMusic_gender =
#line 1253
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1255
            .species = SPECIES_QUILLADIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1257
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1256
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1258
            .species = SPECIES_FLOETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1260
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1259
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1261
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TREVOR] =
    {
#line 1262
        .trainerName = _("TREVOR"),
#line 1263
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 1264
        .trainerPic = TRAINER_PIC_TREVOR,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1267
            .species = SPECIES_FROGADIER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1269
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1268
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1270
            .species = SPECIES_LUCARIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1272
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1271
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1273
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TIERNO] =
    {
#line 1274
        .trainerName = _("TIERNO"),
#line 1275
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1276
        .trainerPic = TRAINER_PIC_TIERNO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1279
            .species = SPECIES_BRAIXEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1281
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1280
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1282
            .species = SPECIES_GOGOAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1284
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1283
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1285
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SERENA] =
    {
#line 1286
        .trainerName = _("SERENA"),
#line 1287
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 1288
        .trainerPic = TRAINER_PIC_SERENA,
        .encounterMusic_gender =
#line 1289
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1291
            .species = SPECIES_MEOWSTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1293
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1292
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1294
            .species = SPECIES_SYLVEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1296
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1295
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1297
            .species = SPECIES_TALONFLAME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1299
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1298
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1300
    [DIFFICULTY_NORMAL][TRAINER_CELADON_CALEM] =
    {
#line 1301
        .trainerName = _("CALEM"),
#line 1302
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 1303
        .trainerPic = TRAINER_PIC_CALEM,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1306
            .species = SPECIES_GRENINJA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1308
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1307
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1309
            .species = SPECIES_LUCARIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1311
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1310
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1312
            .species = SPECIES_NOIVERN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1314
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1313
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1315
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_1] =
    {
#line 1316
        .trainerName = _("GRUNT"),
#line 1317
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1318
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1320
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1322
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1324
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1323
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1325
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1327
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1326
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1328
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_2] =
    {
#line 1329
        .trainerName = _("GRUNT"),
#line 1330
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1331
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1333
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1335
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1337
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1336
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1338
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1340
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1339
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
