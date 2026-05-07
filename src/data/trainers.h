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
        .trainerName = _("MAYA"),
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
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 414
            .species = SPECIES_TORNADUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 419
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 415
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 416
            .isShadow = TRUE,
#line 418
            .heartGauge = 10000,
#line 417
            .shadowID = 115,
            },
            {
#line 420
            .species = SPECIES_ENAMORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 425
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 421
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 422
            .isShadow = TRUE,
#line 424
            .heartGauge = 10000,
#line 423
            .shadowID = 116,
            },
            {
#line 426
            .species = SPECIES_THUNDURUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 431
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 427
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 428
            .isShadow = TRUE,
#line 430
            .heartGauge = 10000,
#line 429
            .shadowID = 117,
            },
            {
#line 432
            .species = SPECIES_TAPU_LELE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 437
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 433
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 434
            .isShadow = TRUE,
#line 436
            .heartGauge = 10000,
#line 435
            .shadowID = 118,
            },
            {
#line 438
            .species = SPECIES_MELOETTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 443
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 439
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 440
            .isShadow = TRUE,
#line 442
            .heartGauge = 10000,
#line 441
            .shadowID = 119,
            },
            {
#line 444
            .species = SPECIES_BLACEPHALON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 449
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 445
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 446
            .isShadow = TRUE,
#line 448
            .heartGauge = 10000,
#line 447
            .shadowID = 120,
            },
        },
    },
#line 450
    [DIFFICULTY_NORMAL][TRAINER_RT4_BLACK_BELT] =
    {
#line 451
        .trainerName = _("RYU"),
#line 452
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 453
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 456
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 458
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 457
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 462
    [DIFFICULTY_NORMAL][TRAINER_RT4_ROCKER] =
    {
#line 463
        .trainerName = _("AMP"),
#line 464
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 465
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 468
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 470
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 469
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 474
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER1] =
    {
#line 475
        .trainerName = _("LILY"),
#line 476
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 477
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 478
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 480
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 482
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 481
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 486
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER2] =
    {
#line 487
        .trainerName = _("MIA"),
#line 488
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 489
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 490
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 492
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 494
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 493
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 495
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 497
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 496
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 498
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN1] =
    {
#line 499
        .trainerName = _("BRENDAN"),
#line 500
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_2,
#line 501
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 504
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 506
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 505
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 507
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 509
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 508
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 510
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN2] =
    {
#line 511
        .trainerName = _("BRENDAN"),
#line 512
        .trainerClass = TRAINER_CLASS_AETHER,
#line 513
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 516
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 518
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 517
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 519
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 521
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 520
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 522
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN3] =
    {
#line 523
        .trainerName = _("BRENDAN"),
#line 524
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 525
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 528
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 530
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 529
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 531
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 533
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 532
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 534
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_1] =
    {
#line 535
        .trainerName = _("MARK"),
#line 536
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 537
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 540
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 542
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 541
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 543
            .species = SPECIES_GEODUDE,
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
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_CAMPER_2] =
    {
#line 547
        .trainerName = _("TROY"),
#line 548
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 549
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 552
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 554
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 553
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 555
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 557
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 556
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 558
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_1] =
    {
#line 559
        .trainerName = _("RINA"),
#line 560
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 561
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 562
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 564
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 566
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 565
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 567
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 569
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 568
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 570
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_PICNICKER_2] =
    {
#line 571
        .trainerName = _("MEL"),
#line 572
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 573
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 574
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 576
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 578
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 577
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 579
    [DIFFICULTY_NORMAL][TRAINER_JJ_ILEX] =
    {
#line 580
        .trainerName = _("JESS&JAMES"),
#line 581
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 582
        .trainerPic = TRAINER_PIC_JESSIE_JAMES,
        .encounterMusic_gender =
#line 583
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 585
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 587
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 586
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 588
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 590
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 589
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 591
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 596
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 592
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 593
            .isShadow = TRUE,
#line 595
            .heartGauge = 5000,
#line 594
            .shadowID = 8,
            .moves = {
#line 596
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 598
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F1] =
    {
#line 599
        .trainerName = _("SABRINA"),
#line 600
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 601
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 602
F_TRAINER_FEMALE | 
#line 603
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 604
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 606
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 608
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 607
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 609
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 611
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 610
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 612
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M1] =
    {
#line 613
        .trainerName = _("RORY"),
#line 614
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 615
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 617
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 618
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 620
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 622
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 621
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 623
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 625
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 624
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 626
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F2] =
    {
#line 627
        .trainerName = _("LANA"),
#line 628
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 629
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 630
F_TRAINER_FEMALE | 
#line 631
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 632
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 634
            .species = SPECIES_GRIMER,
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
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 639
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 638
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 640
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 642
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 641
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 643
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M2] =
    {
#line 644
        .trainerName = _("MARK"),
#line 645
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 646
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 648
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 649
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 651
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 653
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 652
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 654
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 655
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 657
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_M3] =
    {
#line 658
        .trainerName = _("TODD"),
#line 659
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 660
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 662
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 663
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 665
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 667
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 666
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 668
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 670
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 669
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 671
    [DIFFICULTY_NORMAL][TRAINER_ILEX_ROCKET_GRUNT_F3] =
    {
#line 672
        .trainerName = _("RINA"),
#line 673
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 674
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .encounterMusic_gender =
#line 675
F_TRAINER_FEMALE | 
#line 676
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 677
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 679
            .species = SPECIES_ARBOK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 681
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 680
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 682
            .species = SPECIES_GRIMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 684
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 683
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 685
    [DIFFICULTY_NORMAL][TRAINER_ILEX_BUG_CATCHER] =
    {
#line 686
        .trainerName = _("BEN"),
#line 687
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 688
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 691
            .species = SPECIES_LEDYBA,
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
            .species = SPECIES_PINECO,
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
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 699
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 698
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 700
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_1] =
    {
#line 701
        .trainerName = _("GABE"),
#line 702
        .trainerClass = TRAINER_CLASS_HIKER,
#line 703
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 706
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 708
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 707
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 709
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 711
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 710
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 712
    [DIFFICULTY_NORMAL][TRAINER_ROUTE9_HIKER_2] =
    {
#line 713
        .trainerName = _("RUSTY"),
#line 714
        .trainerClass = TRAINER_CLASS_HIKER,
#line 715
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 718
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 720
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 719
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 721
    [DIFFICULTY_NORMAL][TRAINER_LOOKER_CERULEAN] =
    {
#line 722
        .trainerName = _("LOOKER"),
#line 723
        .trainerClass = TRAINER_CLASS_POLICEMAN,
#line 724
        .trainerPic = TRAINER_PIC_LOOKER_GEN5,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 727
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 730
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 728
            .lvl = 16,
#line 729
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 730
                MOVE_BITE,
                MOVE_EMBER,
            },
            },
            {
#line 733
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 736
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 734
            .lvl = 18,
#line 735
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 736
                MOVE_LOW_KICK,
                MOVE_MUD_SLAP,
            },
            },
        },
    },
#line 739
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER1] =
    {
#line 740
        .trainerName = _("TIM"),
#line 741
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 742
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 745
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 747
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 746
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 748
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 750
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 749
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 751
    [DIFFICULTY_NORMAL][TRAINER_RT25_LADY] =
    {
#line 752
        .trainerName = _("MARIE"),
#line 753
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 754
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 755
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 757
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 759
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 758
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 760
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 762
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 761
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 763
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_F] =
    {
#line 764
        .trainerName = _("KARA"),
#line 765
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 766
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 767
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 769
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 771
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 770
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 772
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 774
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 773
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 775
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER2] =
    {
#line 776
        .trainerName = _("BEN"),
#line 777
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 778
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 781
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 783
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 782
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 784
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 786
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 785
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 787
    [DIFFICULTY_NORMAL][TRAINER_RT25_CAMPER] =
    {
#line 788
        .trainerName = _("COLE"),
#line 789
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 790
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 793
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 795
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 794
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 796
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 798
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 797
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 799
    [DIFFICULTY_NORMAL][TRAINER_RT25_LASS] =
    {
#line 800
        .trainerName = _("NINA"),
#line 801
        .trainerClass = TRAINER_CLASS_LASS,
#line 802
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 803
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 805
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 807
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 806
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 808
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 810
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 809
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 811
    [DIFFICULTY_NORMAL][TRAINER_RT25_SUPER_NERD] =
    {
#line 812
        .trainerName = _("DEX"),
#line 813
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 814
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 817
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 819
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 818
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 820
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 822
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 821
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 823
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M] =
    {
#line 824
        .trainerName = _("TYLER"),
#line 825
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 826
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 829
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 831
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 830
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 832
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 834
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 833
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 835
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F1] =
    {
#line 836
        .trainerName = _("MAYA"),
#line 837
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 838
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 839
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 841
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 843
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 842
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 844
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 846
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 845
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 847
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F2] =
    {
#line 848
        .trainerName = _("KAREN"),
#line 849
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 850
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 851
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 853
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 855
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 854
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 856
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 858
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 857
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 859
    [DIFFICULTY_NORMAL][TRAINER_KURTS_HOUSE_IRONMASK] =
    {
#line 860
        .trainerName = _("MARAUDER"),
#line 861
        .trainerClass = TRAINER_CLASS_ROCKET_ADMIN,
#line 862
        .trainerPic = TRAINER_PIC_IRON_MASKED_MARAUDER,
        .encounterMusic_gender =
#line 863
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 865
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 867
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 866
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 868
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 870
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 869
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 871
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 877
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 872
            .lvl = 29,
#line 873
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 874
            .isShadow = TRUE,
#line 876
            .heartGauge = 7500,
#line 875
            .shadowID = 9,
            .moves = {
#line 877
                MOVE_SHADOW_RUSH,
                MOVE_SHADOW_HOLD,
                MOVE_SHADOW_MIST,
                MOVE_SHADOW_SHED,
            },
            },
        },
    },
#line 882
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_1] =
    {
#line 883
        .trainerName = _("AXEL"),
#line 884
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 885
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 886
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 888
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 890
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 889
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 891
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 893
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 892
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 894
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_2] =
    {
#line 895
        .trainerName = _("DANE"),
#line 896
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 897
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 898
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 900
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 902
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 901
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 903
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 905
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 904
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 906
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_3] =
    {
#line 907
        .trainerName = _("MIRA"),
#line 908
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 909
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 910
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 912
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 914
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 913
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 918
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_4] =
    {
#line 919
        .trainerName = _("COLT"),
#line 920
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 921
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 922
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 924
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 926
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 925
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 930
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_5] =
    {
#line 931
        .trainerName = _("ROOK"),
#line 932
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 933
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 934
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 936
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 938
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 937
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 939
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 941
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 940
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 942
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_6] =
    {
#line 943
        .trainerName = _("NASH"),
#line 944
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 945
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 946
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 948
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 950
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 949
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 951
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 953
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 952
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 954
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_1] =
    {
#line 955
        .trainerName = _("FAYE"),
#line 956
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 957
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 958
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 960
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 962
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 961
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 966
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_2] =
    {
#line 967
        .trainerName = _("ORIN"),
#line 968
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 969
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 970
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 972
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 974
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 973
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 975
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 977
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 976
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 978
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_3] =
    {
#line 979
        .trainerName = _("GAGE"),
#line 980
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 981
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 982
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 984
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 986
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 985
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 990
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_4] =
    {
#line 991
        .trainerName = _("NYX"),
#line 992
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 993
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 994
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 996
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 998
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 997
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
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
        },
    },
#line 1002
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_5] =
    {
#line 1003
        .trainerName = _("KADE"),
#line 1004
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1005
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1006
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1008
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1010
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1009
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1011
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1013
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1012
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1014
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_6] =
    {
#line 1015
        .trainerName = _("VOSS"),
#line 1016
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1017
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1018
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1020
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1022
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1021
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1023
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1025
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1024
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1026
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_7] =
    {
#line 1027
        .trainerName = _("IRIS"),
#line 1028
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1029
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1030
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1032
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1034
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1033
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1035
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1037
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1036
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1038
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_8] =
    {
#line 1039
        .trainerName = _("SERA"),
#line 1040
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1041
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 1042
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1044
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1046
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1045
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1047
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1049
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1048
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1050
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_BRYONY] =
    {
#line 1051
        .trainerName = _("BRYONY"),
#line 1052
        .trainerClass = TRAINER_CLASS_TEAM_FLARE_ADMIN,
#line 1053
        .trainerPic = TRAINER_PIC_BRYONY,
        .encounterMusic_gender =
#line 1054
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1056
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1058
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1057
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1059
            .species = SPECIES_PYROAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1061
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1060
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1062
            .species = SPECIES_PANGORO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1068
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1063
            .lvl = 29,
#line 1064
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1065
            .isShadow = TRUE,
#line 1067
            .heartGauge = 7500,
#line 1066
            .shadowID = 45,
            .moves = {
#line 1068
                MOVE_SHADOW_BLITZ,
                MOVE_SHADOW_BREAK,
                MOVE_SHADOW_DOWN,
                MOVE_SHADOW_HALF,
            },
            },
        },
    },
#line 1073
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_1] =
    {
#line 1074
        .trainerName = _("VESPER"),
#line 1075
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1076
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1077
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1079
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1081
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1080
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1082
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1084
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1083
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1085
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_2] =
    {
#line 1086
        .trainerName = _("ORLA"),
#line 1087
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1088
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1089
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1091
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1093
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1092
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1094
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1096
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1095
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1097
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_3] =
    {
#line 1098
        .trainerName = _("KADE"),
#line 1099
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 1100
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 1101
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1103
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1105
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1104
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1106
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1108
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1107
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1109
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_1] =
    {
#line 1110
        .trainerName = _("ROBIN"),
#line 1111
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1112
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1114
            .species = SPECIES_PIDGEOTTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1116
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1115
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1117
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1119
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1118
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1120
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_2] =
    {
#line 1121
        .trainerName = _("KYLE"),
#line 1122
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1123
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1125
            .species = SPECIES_TRUMBEAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1127
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1126
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1128
            .species = SPECIES_PIDGEOTTO,
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
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER] =
    {
#line 1132
        .trainerName = _("TIM"),
#line 1133
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1134
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1137
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1139
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1138
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1140
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1142
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1141
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1143
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_PICNICKER] =
    {
#line 1144
        .trainerName = _("LINA"),
#line 1145
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1146
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1147
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1149
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1151
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1150
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1152
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1154
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1153
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1155
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_1] =
    {
#line 1156
        .trainerName = _("RAY"),
#line 1157
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1158
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1161
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1163
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1162
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1164
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_2] =
    {
#line 1165
        .trainerName = _("NED"),
#line 1166
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1167
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1170
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1172
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1171
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1173
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_3] =
    {
#line 1174
        .trainerName = _("LEO"),
#line 1175
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 1176
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1179
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1181
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1180
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1182
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_BIRD_KEEPER] =
    {
#line 1183
        .trainerName = _("MILO"),
#line 1184
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 1185
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1188
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1190
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1189
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1191
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1193
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1192
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1194
    [DIFFICULTY_NORMAL][TRAINER_ROUTE33_HIKER] =
    {
#line 1195
        .trainerName = _("DUKE"),
#line 1196
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1197
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1200
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1202
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1201
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1203
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_CAMPER] =
    {
#line 1204
        .trainerName = _("NATE"),
#line 1205
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 1206
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1209
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1211
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1210
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1212
            .species = SPECIES_SKIDDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1214
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1213
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1215
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_GENTLEMAN] =
    {
#line 1216
        .trainerName = _("ALFRED"),
#line 1217
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 1218
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1221
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1223
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1222
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1224
            .species = SPECIES_DUNSPARCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1226
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1225
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1227
            .species = SPECIES_STANTLER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1229
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1228
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1230
    [DIFFICULTY_NORMAL][TRAINER_ROUTE34_YOUNGSTER] =
    {
#line 1231
        .trainerName = _("TIM"),
#line 1232
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 1233
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1236
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1238
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1237
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1239
            .species = SPECIES_STARLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1241
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1240
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1242
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_HIKER] =
    {
#line 1243
        .trainerName = _("GUS"),
#line 1244
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1245
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1248
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1249
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1251
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1253
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1252
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1254
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_SUPER_NERD] =
    {
#line 1255
        .trainerName = _("TREV"),
#line 1256
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1257
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1260
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1262
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1261
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1263
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER] =
    {
#line 1264
        .trainerName = _("BO"),
#line 1265
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 1266
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1269
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1271
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1270
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1272
    [DIFFICULTY_NORMAL][TRAINER_SILVER_HUNTER] =
    {
#line 1273
        .trainerName = _("SILVER"),
#line 1274
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 1275
        .trainerPic = TRAINER_PIC_SILVER,
        .encounterMusic_gender =
#line 1277
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1279
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1281
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1280
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1282
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_1] =
    {
#line 1283
        .trainerName = _("RUDO"),
#line 1284
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1285
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1287
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1289
            .species = SPECIES_KROKOROK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1291
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1290
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1292
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1294
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1293
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1295
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_2] =
    {
#line 1296
        .trainerName = _("VOSS"),
#line 1297
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1298
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1300
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1302
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1304
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1303
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1305
            .species = SPECIES_WATCHOG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1307
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1306
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1308
    [DIFFICULTY_NORMAL][TRAINER_POWERPLANT_PLASMA_3] =
    {
#line 1309
        .trainerName = _("NERO"),
#line 1310
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1311
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 1313
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1315
            .species = SPECIES_LIEPARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1317
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1316
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1318
            .species = SPECIES_GARBODOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1320
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1319
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 1320
                MOVE_SLUDGE_BOMB,
                MOVE_BODY_SLAM,
                MOVE_CLEAR_SMOG,
                MOVE_TOXIC_SPIKES,
            },
            },
        },
    },
#line 1325
    [DIFFICULTY_NORMAL][TRAINER_ZINZOLIN_POWER_PLANT] =
    {
#line 1326
        .trainerName = _("ZINZOLIN"),
#line 1327
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1328
        .trainerPic = TRAINER_PIC_ZINZOLIN_GEN5,
        .encounterMusic_gender =
#line 1330
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1332
            .species = SPECIES_CRYOGONAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1334
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1333
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1335
            .species = SPECIES_WEAVILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1340
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1336
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1337
            .isShadow = TRUE,
#line 1339
            .heartGauge = 10000,
#line 1338
            .shadowID = 25,
            },
            {
#line 1341
            .species = SPECIES_DRIFBLIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1343
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1342
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1344
            .species = SPECIES_ABOMASNOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1346
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1345
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1347
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SHAUNA] =
    {
#line 1348
        .trainerName = _("SHAUNA"),
#line 1349
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1350
        .trainerPic = TRAINER_PIC_SHAUNA,
        .encounterMusic_gender =
#line 1351
F_TRAINER_FEMALE | 
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1353
            .species = SPECIES_KLEFKI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1355
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1354
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1356
            .species = SPECIES_SLIGGOO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1358
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1357
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1359
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1361
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1360
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1362
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TREVOR] =
    {
#line 1363
        .trainerName = _("TREVOR"),
#line 1364
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1365
        .trainerPic = TRAINER_PIC_TREVOR,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1368
            .species = SPECIES_FLOETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1370
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1369
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1371
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1373
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1372
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1374
            .species = SPECIES_CHARMELEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1376
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1375
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1377
    [DIFFICULTY_NORMAL][TRAINER_CELADON_TIERNO] =
    {
#line 1378
        .trainerName = _("TIERNO"),
#line 1379
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1380
        .trainerPic = TRAINER_PIC_TIERNO,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1383
            .species = SPECIES_HAWLUCHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1385
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1384
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1386
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1388
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1387
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1389
            .species = SPECIES_WARTORTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1391
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1390
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1392
    [DIFFICULTY_NORMAL][TRAINER_CELADON_SERENA] =
    {
#line 1393
        .trainerName = _("SERENA"),
#line 1394
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1395
        .trainerPic = TRAINER_PIC_SERENA,
        .encounterMusic_gender =
#line 1396
F_TRAINER_FEMALE | 
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1398
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1400
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1399
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1401
            .species = SPECIES_SYLVEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1403
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1402
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1404
            .species = SPECIES_PANGORO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1406
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1405
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1407
            .species = SPECIES_DELPHOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1407
            .heldItem = ITEM_DELPHOXITE,
#line 1409
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1408
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1410
    [DIFFICULTY_NORMAL][TRAINER_CELADON_CALEM] =
    {
#line 1411
        .trainerName = _("CALEM"),
#line 1412
        .trainerClass = TRAINER_CLASS_KALOS_TRAINER,
#line 1413
        .trainerPic = TRAINER_PIC_CALEM,
        .encounterMusic_gender =
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1416
            .species = SPECIES_MEOWSTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1418
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1417
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1419
            .species = SPECIES_BARBARACLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1421
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1420
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1422
            .species = SPECIES_NOIVERN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1424
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1423
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1425
            .species = SPECIES_CHESNAUGHT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1425
            .heldItem = ITEM_CHESNAUGHTITE,
#line 1427
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1426
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1428
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_1] =
    {
#line 1429
        .trainerName = _("GRUNT"),
#line 1430
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1431
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1433
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1435
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1437
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1436
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1438
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1440
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1439
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1441
    [DIFFICULTY_NORMAL][TRAINER_CELADON_AETHER_GRUNT_2] =
    {
#line 1442
        .trainerName = _("GRUNT"),
#line 1443
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1444
        .trainerPic = TRAINER_PIC_AETHER_M,
        .encounterMusic_gender =
#line 1446
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1448
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1450
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1449
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1451
            .species = SPECIES_RATICATE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1453
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1452
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1454
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_MICHELLE] =
    {
#line 1455
        .trainerName = _("MICHELLE"),
#line 1456
        .trainerClass = TRAINER_CLASS_LASS,
#line 1457
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 1458
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1460
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1462
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1461
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1463
            .species = SPECIES_WEEPINBELL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1465
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1464
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1466
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_TANYA] =
    {
#line 1467
        .trainerName = _("TANYA"),
#line 1468
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 1469
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 1470
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1472
            .species = SPECIES_IVYSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1474
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1473
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1475
            .species = SPECIES_SKIPLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1477
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1476
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1478
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_JULIA] =
    {
#line 1479
        .trainerName = _("JULIA"),
#line 1480
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 1481
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 1482
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1484
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1486
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1485
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1487
            .species = SPECIES_PARASECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1489
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1488
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1490
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GYM_JO_AND_ZOE] =
    {
#line 1491
        .trainerName = _("JO&ZOE"),
#line 1492
        .trainerClass = TRAINER_CLASS_TWINS,
#line 1493
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 1494
F_TRAINER_FEMALE | 
0,
#line 1495
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1497
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1499
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1498
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1500
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1502
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1501
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1503
    [DIFFICULTY_NORMAL][TRAINER_ERIKA] =
    {
#line 1504
        .trainerName = _("ERIKA"),
#line 1505
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 1507
        .trainerPic = TRAINER_PIC_ERIKA,
        .encounterMusic_gender =
#line 1508
F_TRAINER_FEMALE | 
#line 1506
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1510
            .species = SPECIES_TANGELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1512
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1511
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1513
            .species = SPECIES_VICTREEBEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1515
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1514
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1516
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1518
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1517
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1519
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1521
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1520
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1522
    [DIFFICULTY_NORMAL][TRAINER_CELADON_GLADION] =
    {
#line 1523
        .trainerName = _("GLADION"),
#line 1524
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1525
        .trainerPic = TRAINER_PIC_GLADION,
        .encounterMusic_gender =
#line 1527
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1529
            .species = SPECIES_TYPE_NULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1531
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1530
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1532
            .species = SPECIES_ZOROARK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1534
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1533
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1535
            .species = SPECIES_LUCARIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1537
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1536
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1538
    [DIFFICULTY_NORMAL][TRAINER_SURGE] =
    {
#line 1539
        .trainerName = _("LT. SURGE"),
#line 1540
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 1542
        .trainerPic = TRAINER_PIC_SURGE,
        .encounterMusic_gender =
#line 1541
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1545
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1547
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1546
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1548
            .species = SPECIES_ELECTABUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1550
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1549
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1551
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1551
            .heldItem = ITEM_RAICHUNITE_X,
#line 1553
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1552
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1554
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_JUGGLER] =
    {
#line 1555
        .trainerName = _("LEO"),
#line 1556
        .trainerClass = TRAINER_CLASS_JUGGLER,
#line 1557
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1560
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1562
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1561
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1563
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1565
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1564
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1566
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_GENTLEMAN] =
    {
#line 1567
        .trainerName = _("EDGAR"),
#line 1568
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 1569
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1572
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1574
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1573
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1575
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1577
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1576
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1578
    [DIFFICULTY_NORMAL][TRAINER_VERMILION_GYM_ROCKER] =
    {
#line 1579
        .trainerName = _("AXEL"),
#line 1580
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 1581
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1584
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1586
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1585
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1587
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1589
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1588
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1590
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_CARRIE] =
    {
#line 1591
        .trainerName = _("CARRIE"),
#line 1592
        .trainerClass = TRAINER_CLASS_LASS,
#line 1593
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 1594
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1596
            .species = SPECIES_SNUBBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1598
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1597
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1599
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1601
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1600
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1602
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_LEAH] =
    {
#line 1603
        .trainerName = _("LEAH"),
#line 1604
        .trainerClass = TRAINER_CLASS_LASS,
#line 1605
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 1606
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1608
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1610
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1609
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1611
            .species = SPECIES_TEDDIURSA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1613
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1612
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1614
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_BROOKE] =
    {
#line 1615
        .trainerName = _("BROOKE"),
#line 1616
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 1617
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
#line 1618
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1620
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1622
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1621
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1623
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1625
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1624
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1626
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_GYM_MARA] =
    {
#line 1627
        .trainerName = _("MARA"),
#line 1628
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 1629
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 1630
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1632
            .species = SPECIES_LICKITUNG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1634
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1633
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1635
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1637
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1636
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1638
    [DIFFICULTY_NORMAL][TRAINER_LEADER_WHITNEY] =
    {
#line 1639
        .trainerName = _("WHITNEY"),
#line 1640
        .trainerClass = TRAINER_CLASS_JOHTO_LEADER,
#line 1642
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .encounterMusic_gender =
#line 1643
F_TRAINER_FEMALE | 
#line 1641
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1645
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1647
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1646
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1648
            .species = SPECIES_SNUBBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1650
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1649
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1651
            .species = SPECIES_MILTANK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1653
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1652
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1654
    [DIFFICULTY_NORMAL][TRAINER_VENUS] =
    {
#line 1655
        .trainerName = _("VENUS"),
#line 1656
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 1657
        .trainerPic = TRAINER_PIC_VENUS,
        .encounterMusic_gender =
#line 1658
F_TRAINER_FEMALE | 
#line 1659
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
#line 1660
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1662
            .species = SPECIES_HATTERENE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1664
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1663
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1665
            .species = SPECIES_AMOONGUSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1667
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1666
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1668
            .species = SPECIES_ROSERADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1670
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1669
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1671
            .species = SPECIES_MILOTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1673
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1672
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1674
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1679
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1675
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1676
            .isShadow = TRUE,
#line 1678
            .heartGauge = 10000,
#line 1677
            .shadowID = 71,
            },
            {
#line 1680
            .species = SPECIES_GOODRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1685
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1681
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1682
            .isShadow = TRUE,
#line 1684
            .heartGauge = 10000,
#line 1683
            .shadowID = 104,
            },
        },
    },
#line 1686
    [DIFFICULTY_NORMAL][TRAINER_GIOVANNI_SHADOW_REALM] =
    {
#line 1687
        .trainerName = _("GIOVANNI"),
#line 1688
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 1689
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .encounterMusic_gender =
#line 1691
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1693
            .species = SPECIES_REGIROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1698
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1694
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1695
            .isShadow = TRUE,
#line 1697
            .heartGauge = 10000,
#line 1696
            .shadowID = 109,
            },
            {
#line 1699
            .species = SPECIES_TERRAKION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1704
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1700
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1701
            .isShadow = TRUE,
#line 1703
            .heartGauge = 10000,
#line 1702
            .shadowID = 110,
            },
            {
#line 1705
            .species = SPECIES_IRON_TREADS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1710
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1706
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1707
            .isShadow = TRUE,
#line 1709
            .heartGauge = 10000,
#line 1708
            .shadowID = 111,
            },
            {
#line 1711
            .species = SPECIES_GREAT_TUSK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1716
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1712
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1713
            .isShadow = TRUE,
#line 1715
            .heartGauge = 10000,
#line 1714
            .shadowID = 112,
            },
            {
#line 1717
            .species = SPECIES_REGIGIGAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1722
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1718
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1719
            .isShadow = TRUE,
#line 1721
            .heartGauge = 10000,
#line 1720
            .shadowID = 113,
            },
            {
#line 1723
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1728
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1724
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1725
            .isShadow = TRUE,
#line 1727
            .heartGauge = 10000,
#line 1726
            .shadowID = 114,
            },
        },
    },
#line 1729
    [DIFFICULTY_NORMAL][TRAINER_NASCOUR_SHADOW_REALM] =
    {
#line 1730
        .trainerName = _("NASCOUR"),
#line 1731
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 1732
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 1734
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1736
            .species = SPECIES_IRON_BUNDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1741
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1737
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1738
            .isShadow = TRUE,
#line 1740
            .heartGauge = 10000,
#line 1739
            .shadowID = 121,
            },
            {
#line 1742
            .species = SPECIES_IRON_CROWN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1747
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1743
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1744
            .isShadow = TRUE,
#line 1746
            .heartGauge = 10000,
#line 1745
            .shadowID = 122,
            },
            {
#line 1748
            .species = SPECIES_CHIEN_PAO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1753
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1749
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1750
            .isShadow = TRUE,
#line 1752
            .heartGauge = 10000,
#line 1751
            .shadowID = 123,
            },
            {
#line 1754
            .species = SPECIES_CALYREX_ICE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1759
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1755
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1756
            .isShadow = TRUE,
#line 1758
            .heartGauge = 10000,
#line 1757
            .shadowID = 124,
            },
            {
#line 1760
            .species = SPECIES_REGICE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1765
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1761
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1762
            .isShadow = TRUE,
#line 1764
            .heartGauge = 10000,
#line 1763
            .shadowID = 125,
            },
            {
#line 1766
            .species = SPECIES_ARTICUNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1771
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1767
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1768
            .isShadow = TRUE,
#line 1770
            .heartGauge = 10000,
#line 1769
            .shadowID = 126,
            },
        },
    },
#line 1772
    [DIFFICULTY_NORMAL][TRAINER_GUZMA_SHADOW_REALM] =
    {
#line 1773
        .trainerName = _("GUZMA"),
#line 1774
        .trainerClass = TRAINER_CLASS_TEAM_SKULL,
#line 1775
        .trainerPic = TRAINER_PIC_GUZMA,
        .encounterMusic_gender =
#line 1777
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1779
            .species = SPECIES_KARTANA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1784
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1780
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1781
            .isShadow = TRUE,
#line 1783
            .heartGauge = 10000,
#line 1782
            .shadowID = 127,
            },
            {
#line 1785
            .species = SPECIES_NAGANADEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1790
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1786
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1787
            .isShadow = TRUE,
#line 1789
            .heartGauge = 10000,
#line 1788
            .shadowID = 128,
            },
            {
#line 1791
            .species = SPECIES_TAPU_BULU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1796
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1792
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1793
            .isShadow = TRUE,
#line 1795
            .heartGauge = 10000,
#line 1794
            .shadowID = 129,
            },
            {
#line 1797
            .species = SPECIES_ZERAORA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1802
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1798
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1799
            .isShadow = TRUE,
#line 1801
            .heartGauge = 10000,
#line 1800
            .shadowID = 130,
            },
            {
#line 1803
            .species = SPECIES_GUZZLORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1808
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1804
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1805
            .isShadow = TRUE,
#line 1807
            .heartGauge = 10000,
#line 1806
            .shadowID = 131,
            },
            {
#line 1809
            .species = SPECIES_BUZZWOLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1814
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1810
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1811
            .isShadow = TRUE,
#line 1813
            .heartGauge = 10000,
#line 1812
            .shadowID = 132,
            },
        },
    },
#line 1815
    [DIFFICULTY_NORMAL][TRAINER_LUSAMINE_SHADOW_REALM] =
    {
#line 1816
        .trainerName = _("LUSAMINE"),
#line 1817
        .trainerClass = TRAINER_CLASS_AETHER,
#line 1818
        .trainerPic = TRAINER_PIC_AETHER_F,
        .encounterMusic_gender =
#line 1819
F_TRAINER_FEMALE | 
#line 1820
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1822
            .species = SPECIES_XURKITREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1827
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1823
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1824
            .isShadow = TRUE,
#line 1826
            .heartGauge = 10000,
#line 1825
            .shadowID = 133,
            },
            {
#line 1828
            .species = SPECIES_CELESTEELA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1833
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1829
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1830
            .isShadow = TRUE,
#line 1832
            .heartGauge = 10000,
#line 1831
            .shadowID = 134,
            },
            {
#line 1834
            .species = SPECIES_PHEROMOSA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1839
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1835
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1836
            .isShadow = TRUE,
#line 1838
            .heartGauge = 10000,
#line 1837
            .shadowID = 135,
            },
            {
#line 1840
            .species = SPECIES_NIHILEGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1845
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1841
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1842
            .isShadow = TRUE,
#line 1844
            .heartGauge = 10000,
#line 1843
            .shadowID = 136,
            },
            {
#line 1846
            .species = SPECIES_LUNALA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1851
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1847
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1848
            .isShadow = TRUE,
#line 1850
            .heartGauge = 10000,
#line 1849
            .shadowID = 137,
            },
            {
#line 1852
            .species = SPECIES_SOLGALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1857
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1853
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1854
            .isShadow = TRUE,
#line 1856
            .heartGauge = 10000,
#line 1855
            .shadowID = 138,
            },
        },
    },
#line 1858
    [DIFFICULTY_NORMAL][TRAINER_COLRESS_SHADOW_REALM] =
    {
#line 1859
        .trainerName = _("COLRESS"),
#line 1860
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1861
        .trainerPic = TRAINER_PIC_COLRESS_GEN5,
        .encounterMusic_gender =
#line 1863
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1865
            .species = SPECIES_REGIELEKI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1870
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1866
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1867
            .isShadow = TRUE,
#line 1869
            .heartGauge = 10000,
#line 1868
            .shadowID = 139,
            },
            {
#line 1871
            .species = SPECIES_JIRACHI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1876
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1872
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1873
            .isShadow = TRUE,
#line 1875
            .heartGauge = 10000,
#line 1874
            .shadowID = 140,
            },
            {
#line 1877
            .species = SPECIES_MELMETAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1882
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1878
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1879
            .isShadow = TRUE,
#line 1881
            .heartGauge = 10000,
#line 1880
            .shadowID = 141,
            },
            {
#line 1883
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1888
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1884
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1885
            .isShadow = TRUE,
#line 1887
            .heartGauge = 10000,
#line 1886
            .shadowID = 142,
            },
            {
#line 1889
            .species = SPECIES_GENESECT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1894
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1890
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1891
            .isShadow = TRUE,
#line 1893
            .heartGauge = 10000,
#line 1892
            .shadowID = 143,
            },
        },
    },
#line 1895
    [DIFFICULTY_NORMAL][TRAINER_GHETSIS_SHADOW_REALM] =
    {
#line 1896
        .trainerName = _("GHETSIS"),
#line 1897
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 1898
        .trainerPic = TRAINER_PIC_GHETSIS_GEN5,
        .encounterMusic_gender =
#line 1900
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1902
            .species = SPECIES_MARSHADOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1907
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1903
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1904
            .isShadow = TRUE,
#line 1906
            .heartGauge = 10000,
#line 1905
            .shadowID = 145,
            },
            {
#line 1908
            .species = SPECIES_ZARUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1913
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1909
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1910
            .isShadow = TRUE,
#line 1912
            .heartGauge = 10000,
#line 1911
            .shadowID = 146,
            },
            {
#line 1914
            .species = SPECIES_REGIDRAGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1919
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1915
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1916
            .isShadow = TRUE,
#line 1918
            .heartGauge = 10000,
#line 1917
            .shadowID = 147,
            },
            {
#line 1920
            .species = SPECIES_ZEKROM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1925
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1921
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1922
            .isShadow = TRUE,
#line 1924
            .heartGauge = 10000,
#line 1923
            .shadowID = 148,
            },
            {
#line 1926
            .species = SPECIES_RESHIRAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1931
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1927
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1928
            .isShadow = TRUE,
#line 1930
            .heartGauge = 10000,
#line 1929
            .shadowID = 149,
            },
            {
#line 1932
            .species = SPECIES_KYUREM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1937
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1933
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1934
            .isShadow = TRUE,
#line 1936
            .heartGauge = 10000,
#line 1935
            .shadowID = 150,
            },
        },
    },
#line 1938
    [DIFFICULTY_NORMAL][TRAINER_MAXIE_SHADOW_REALM] =
    {
#line 1939
        .trainerName = _("MAXIE"),
#line 1940
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 1941
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender =
#line 1943
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1945
            .species = SPECIES_TING_LU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1950
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1946
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1947
            .isShadow = TRUE,
#line 1949
            .heartGauge = 10000,
#line 1948
            .shadowID = 151,
            },
            {
#line 1951
            .species = SPECIES_CHI_YU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1952
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1953
            .isShadow = TRUE,
#line 1955
            .heartGauge = 10000,
#line 1954
            .shadowID = 152,
            },
            {
#line 1957
            .species = SPECIES_LANDORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1962
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1958
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1959
            .isShadow = TRUE,
#line 1961
            .heartGauge = 10000,
#line 1960
            .shadowID = 153,
            },
            {
#line 1963
            .species = SPECIES_HEATRAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1968
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1964
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1965
            .isShadow = TRUE,
#line 1967
            .heartGauge = 10000,
#line 1966
            .shadowID = 154,
            },
            {
#line 1969
            .species = SPECIES_ENTEI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1974
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1970
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1971
            .isShadow = TRUE,
#line 1973
            .heartGauge = 10000,
#line 1972
            .shadowID = 155,
            },
            {
#line 1975
            .species = SPECIES_GROUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1980
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1976
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1977
            .isShadow = TRUE,
#line 1979
            .heartGauge = 10000,
#line 1978
            .shadowID = 156,
            },
        },
    },
#line 1981
    [DIFFICULTY_NORMAL][TRAINER_ARCHIE_SHADOW_REALM] =
    {
#line 1982
        .trainerName = _("ARCHIE"),
#line 1983
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
#line 1984
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .encounterMusic_gender =
#line 1986
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 1988
            .species = SPECIES_MANAPHY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1993
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1989
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1990
            .isShadow = TRUE,
#line 1992
            .heartGauge = 10000,
#line 1991
            .shadowID = 157,
            },
            {
#line 1994
            .species = SPECIES_TAPU_FINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1999
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1995
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 1996
            .isShadow = TRUE,
#line 1998
            .heartGauge = 10000,
#line 1997
            .shadowID = 158,
            },
            {
#line 2000
            .species = SPECIES_TERAPAGOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2005
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2001
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2002
            .isShadow = TRUE,
#line 2004
            .heartGauge = 10000,
#line 2003
            .shadowID = 159,
            },
            {
#line 2006
            .species = SPECIES_KELDEO,
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
            .shadowID = 160,
            },
            {
#line 2012
            .species = SPECIES_SUICUNE,
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
            .shadowID = 161,
            },
            {
#line 2018
            .species = SPECIES_KYOGRE,
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
            .shadowID = 162,
            },
        },
    },
#line 2024
    [DIFFICULTY_NORMAL][TRAINER_LYSANDRE_SHADOW_REALM] =
    {
#line 2025
        .trainerName = _("LYSANDRE"),
#line 2026
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 2027
        .trainerPic = TRAINER_PIC_LYSANDER,
        .encounterMusic_gender =
#line 2029
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2031
            .species = SPECIES_VICTINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2036
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2032
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2033
            .isShadow = TRUE,
#line 2035
            .heartGauge = 10000,
#line 2034
            .shadowID = 163,
            },
            {
#line 2037
            .species = SPECIES_DIANCIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2042
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2038
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2039
            .isShadow = TRUE,
#line 2041
            .heartGauge = 10000,
#line 2040
            .shadowID = 164,
            },
            {
#line 2043
            .species = SPECIES_WO_CHIEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2048
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2044
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2045
            .isShadow = TRUE,
#line 2047
            .heartGauge = 10000,
#line 2046
            .shadowID = 165,
            },
            {
#line 2049
            .species = SPECIES_VOLCANION,
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
            .shadowID = 166,
            },
            {
#line 2055
            .species = SPECIES_XERNEAS,
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
            .shadowID = 167,
            },
            {
#line 2061
            .species = SPECIES_YVELTAL,
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
            .shadowID = 168,
            },
        },
    },
#line 2067
    [DIFFICULTY_NORMAL][TRAINER_ROSE_SHADOW_REALM] =
    {
#line 2068
        .trainerName = _("ROSE"),
#line 2069
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 2070
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
#line 2072
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2074
            .species = SPECIES_LATIAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2079
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2075
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2076
            .isShadow = TRUE,
#line 2078
            .heartGauge = 10000,
#line 2077
            .shadowID = 169,
            },
            {
#line 2080
            .species = SPECIES_LATIOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2085
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2081
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2082
            .isShadow = TRUE,
#line 2084
            .heartGauge = 10000,
#line 2083
            .shadowID = 170,
            },
            {
#line 2086
            .species = SPECIES_REGISTEEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2091
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2087
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2088
            .isShadow = TRUE,
#line 2090
            .heartGauge = 10000,
#line 2089
            .shadowID = 171,
            },
            {
#line 2092
            .species = SPECIES_ZACIAN,
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
            .shadowID = 172,
            },
            {
#line 2098
            .species = SPECIES_ZAMAZENTA,
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
            .shadowID = 173,
            },
            {
#line 2104
            .species = SPECIES_ETERNATUS,
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
            .shadowID = 174,
            },
        },
    },
#line 2110
    [DIFFICULTY_NORMAL][TRAINER_SADA_TURO_SHADOW_REALM] =
    {
#line 2111
        .trainerName = _("SADA&TURO"),
#line 2112
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 2113
        .trainerPic = TRAINER_PIC_TURO,
        .encounterMusic_gender =
#line 2114
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2116
            .species = SPECIES_RAIKOU,
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
            .shadowID = 175,
            },
            {
#line 2122
            .species = SPECIES_TAPU_KOKO,
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
            .shadowID = 176,
            },
            {
#line 2128
            .species = SPECIES_ZAPDOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2133
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2129
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2130
            .isShadow = TRUE,
#line 2132
            .heartGauge = 10000,
#line 2131
            .shadowID = 177,
            },
            {
#line 2134
            .species = SPECIES_PECHARUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2139
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2135
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2136
            .isShadow = TRUE,
#line 2138
            .heartGauge = 10000,
#line 2137
            .shadowID = 178,
            },
            {
#line 2140
            .species = SPECIES_MIRAIDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2145
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2141
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2142
            .isShadow = TRUE,
#line 2144
            .heartGauge = 10000,
#line 2143
            .shadowID = 179,
            },
            {
#line 2146
            .species = SPECIES_KORAIDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2151
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2147
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2148
            .isShadow = TRUE,
#line 2150
            .heartGauge = 10000,
#line 2149
            .shadowID = 180,
            },
        },
    },
#line 2152
    [DIFFICULTY_NORMAL][TRAINER_GREEVIL_SHADOW_REALM] =
    {
#line 2153
        .trainerName = _("GREEVIL"),
#line 2154
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 2155
        .trainerPic = TRAINER_PIC_GREEVIL,
        .encounterMusic_gender =
#line 2157
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2159
            .species = SPECIES_CELEBI,
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
            .shadowID = 181,
            },
            {
#line 2165
            .species = SPECIES_DEOXYS,
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
            .shadowID = 182,
            },
            {
#line 2171
            .species = SPECIES_NECROZMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2176
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2172
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2173
            .isShadow = TRUE,
#line 2175
            .heartGauge = 10000,
#line 2174
            .shadowID = 183,
            },
            {
#line 2177
            .species = SPECIES_ZYGARDE_COMPLETE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2182
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2178
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2179
            .isShadow = TRUE,
#line 2181
            .heartGauge = 10000,
#line 2180
            .shadowID = 184,
            },
            {
#line 2183
            .species = SPECIES_RAYQUAZA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2188
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2184
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2185
            .isShadow = TRUE,
#line 2187
            .heartGauge = 10000,
#line 2186
            .shadowID = 185,
            },
            {
#line 2189
            .species = SPECIES_LUGIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2194
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2190
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2191
            .isShadow = TRUE,
#line 2193
            .heartGauge = 10000,
#line 2192
            .shadowID = 186,
            },
        },
    },
#line 2195
    [DIFFICULTY_NORMAL][TRAINER_EVICE_SHADOW_REALM] =
    {
#line 2196
        .trainerName = _("EVICE"),
#line 2197
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 2198
        .trainerPic = TRAINER_PIC_EVICE,
        .encounterMusic_gender =
#line 2200
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2202
            .species = SPECIES_VIRIZION,
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
            .shadowID = 187,
            },
            {
#line 2208
            .species = SPECIES_COBALION,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2213
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2209
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2210
            .isShadow = TRUE,
#line 2212
            .heartGauge = 10000,
#line 2211
            .shadowID = 188,
            },
            {
#line 2214
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2219
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2215
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2216
            .isShadow = TRUE,
#line 2218
            .heartGauge = 10000,
#line 2217
            .shadowID = 189,
            },
            {
#line 2220
            .species = SPECIES_CRESSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2225
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2221
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2222
            .isShadow = TRUE,
#line 2224
            .heartGauge = 10000,
#line 2223
            .shadowID = 190,
            },
            {
#line 2226
            .species = SPECIES_MOLTRES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2231
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2227
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2228
            .isShadow = TRUE,
#line 2230
            .heartGauge = 10000,
#line 2229
            .shadowID = 191,
            },
            {
#line 2232
            .species = SPECIES_HO_OH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2237
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2233
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2234
            .isShadow = TRUE,
#line 2236
            .heartGauge = 10000,
#line 2235
            .shadowID = 192,
            },
        },
    },
#line 2238
    [DIFFICULTY_NORMAL][TRAINER_CYRUS_SHADOW_REALM] =
    {
#line 2239
        .trainerName = _("CYRUS"),
#line 2240
        .trainerClass = TRAINER_CLASS_TEAM_GALACTIC,
#line 2241
        .trainerPic = TRAINER_PIC_CYRUS_GEN4,
        .encounterMusic_gender =
#line 2243
            TRAINER_ENCOUNTER_MUSIC_GALACTIC,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 2245
            .species = SPECIES_AZELF,
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
            .shadowID = 193,
            },
            {
#line 2251
            .species = SPECIES_UXIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2256
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2252
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2253
            .isShadow = TRUE,
#line 2255
            .heartGauge = 10000,
#line 2254
            .shadowID = 194,
            },
            {
#line 2257
            .species = SPECIES_MESPRIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2262
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2258
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2259
            .isShadow = TRUE,
#line 2261
            .heartGauge = 10000,
#line 2260
            .shadowID = 195,
            },
            {
#line 2263
            .species = SPECIES_DIALGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2268
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2264
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2265
            .isShadow = TRUE,
#line 2267
            .heartGauge = 10000,
#line 2266
            .shadowID = 196,
            },
            {
#line 2269
            .species = SPECIES_PALKIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2274
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2270
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2271
            .isShadow = TRUE,
#line 2273
            .heartGauge = 10000,
#line 2272
            .shadowID = 197,
            },
            {
#line 2275
            .species = SPECIES_GIRATINA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2280
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2276
            .lvl = 100,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2277
            .isShadow = TRUE,
#line 2279
            .heartGauge = 10000,
#line 2278
            .shadowID = 198,
            },
        },
    },
#line 2281
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F1] =
    {
#line 2282
        .trainerName = _("VEXA"),
#line 2283
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2284
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2285
F_TRAINER_FEMALE | 
#line 2286
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2288
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2290
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2289
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2291
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2293
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2292
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2294
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2299
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2295
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2296
            .isShadow = TRUE,
#line 2298
            .heartGauge = 10000,
#line 2297
            .shadowID = 4,
            .moves = {
#line 2299
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2301
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F2] =
    {
#line 2302
        .trainerName = _("NYRA"),
#line 2303
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2304
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2305
F_TRAINER_FEMALE | 
#line 2306
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2308
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2310
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2309
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2311
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2313
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2312
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2314
            .species = SPECIES_HONCHKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2319
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2315
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2316
            .isShadow = TRUE,
#line 2318
            .heartGauge = 7500,
#line 2317
            .shadowID = 30,
            .moves = {
#line 2319
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2321
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F3] =
    {
#line 2322
        .trainerName = _("MIRA"),
#line 2323
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2324
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2325
F_TRAINER_FEMALE | 
#line 2326
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2328
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2330
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2329
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2331
            .species = SPECIES_CUBCHOO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2333
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2332
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2334
            .species = SPECIES_BEARTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2339
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2335
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2336
            .isShadow = TRUE,
#line 2338
            .heartGauge = 7500,
#line 2337
            .shadowID = 35,
            .moves = {
#line 2339
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2341
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F4] =
    {
#line 2342
        .trainerName = _("SERA"),
#line 2343
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2344
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2345
F_TRAINER_FEMALE | 
#line 2346
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2348
            .species = SPECIES_AMAURA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2350
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2349
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2351
            .species = SPECIES_SNORUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2353
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2352
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2354
            .species = SPECIES_AURORUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2359
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2355
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2356
            .isShadow = TRUE,
#line 2358
            .heartGauge = 7500,
#line 2357
            .shadowID = 44,
            .moves = {
#line 2359
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2361
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F5] =
    {
#line 2362
        .trainerName = _("ZIA"),
#line 2363
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2364
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2365
F_TRAINER_FEMALE | 
#line 2366
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2368
            .species = SPECIES_SALANDIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2370
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2369
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2371
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2373
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2372
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2374
            .species = SPECIES_SALAZZLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2375
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2376
            .isShadow = TRUE,
#line 2378
            .heartGauge = 7500,
#line 2377
            .shadowID = 47,
            .moves = {
#line 2379
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2381
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F6] =
    {
#line 2382
        .trainerName = _("VERA"),
#line 2383
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2384
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2385
F_TRAINER_FEMALE | 
#line 2386
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2388
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2390
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2389
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2391
            .species = SPECIES_MAREANIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2393
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2392
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2394
            .species = SPECIES_TOXAPEX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2399
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2395
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2396
            .isShadow = TRUE,
#line 2398
            .heartGauge = 7500,
#line 2397
            .shadowID = 51,
            .moves = {
#line 2399
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2401
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_F7] =
    {
#line 2402
        .trainerName = _("LYNX"),
#line 2403
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2404
        .trainerPic = TRAINER_PIC_CIPHER_PEON_F,
        .encounterMusic_gender =
#line 2405
F_TRAINER_FEMALE | 
#line 2406
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2408
            .species = SPECIES_DEWPIDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2410
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2409
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2411
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2413
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2412
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2414
            .species = SPECIES_ARAQUANID,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2419
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2415
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2416
            .isShadow = TRUE,
#line 2418
            .heartGauge = 7500,
#line 2417
            .shadowID = 53,
            .moves = {
#line 2419
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2421
    [DIFFICULTY_NORMAL][TRAINER_GOLDENROD_RADIO_CIPHER_M1] =
    {
#line 2422
        .trainerName = _("DREX"),
#line 2423
        .trainerClass = TRAINER_CLASS_CIPHER_PEON,
#line 2424
        .trainerPic = TRAINER_PIC_CIPHER_PEON_M,
        .encounterMusic_gender =
#line 2426
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2428
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2430
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2429
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2431
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2433
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2432
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2434
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2439
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2435
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 2436
            .isShadow = TRUE,
#line 2438
            .heartGauge = 7500,
#line 2437
            .shadowID = 22,
            .moves = {
#line 2439
                MOVE_SHADOW_RUSH,
            },
            },
        },
    },
#line 2441
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER_WALT] =
    {
#line 2442
        .trainerName = _("WALT"),
#line 2443
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 2444
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2447
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2449
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2448
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2450
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2452
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2451
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2453
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER_2] =
    {
#line 2454
        .trainerName = _("OLLIE"),
#line 2455
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 2456
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2459
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2461
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2460
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2462
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2464
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2463
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 2465
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_COOLTRAINER] =
    {
#line 2466
        .trainerName = _("DAREN"),
#line 2467
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 2468
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
#line 2469
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2471
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2473
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2472
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 2474
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2476
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 2475
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
