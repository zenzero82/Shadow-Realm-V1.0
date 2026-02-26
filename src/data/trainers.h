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
            .lvl = 1,
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
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 98
            .species = SPECIES_MEOWTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 100
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 99
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 101
    [DIFFICULTY_NORMAL][TRAINER_BROCK_KANTO] =
    {
#line 102
        .trainerName = _("BROCK"),
#line 103
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 105
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .encounterMusic_gender =
#line 104
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 108
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 111
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 109
            .lvl = 1,
#line 110
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 111
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 116
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 119
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 117
            .lvl = 1,
#line 118
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 119
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_THROW,
                MOVE_SCREECH,
            },
            },
            {
#line 124
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 127
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 125
            .lvl = 1,
#line 126
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 127
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 132
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_KANTO] =
    {
#line 133
        .trainerName = _("JERRY"),
#line 134
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 135
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 138
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 139
            .lvl = 1,
#line 140
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 141
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 144
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 145
            .lvl = 1,
#line 146
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 147
                MOVE_PECK,
                MOVE_GROWL,
            },
            },
        },
    },
#line 150
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AL] =
    {
#line 151
        .trainerName = _("AL"),
#line 152
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 153
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 156
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 158
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 157
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 159
            .species = SPECIES_BUTTERFREE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 161
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 160
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 162
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_JOSH] =
    {
#line 163
        .trainerName = _("JOSH"),
#line 164
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 165
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 168
            .species = SPECIES_YANMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 170
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 169
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 171
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_BENNY] =
    {
#line 172
        .trainerName = _("BENNY"),
#line 173
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 174
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 177
            .species = SPECIES_KAKUNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 178
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 180
            .species = SPECIES_BEEDRILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 182
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 181
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 183
    [DIFFICULTY_NORMAL][TRAINER_AZALEA_AMY_AND_MAY] =
    {
#line 184
        .trainerName = _("AMY&MAY"),
#line 185
        .trainerClass = TRAINER_CLASS_TWINS,
#line 186
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
#line 187
F_TRAINER_FEMALE | 
0,
#line 188
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 190
            .species = SPECIES_LEDYBA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 195
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 191
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 192
            .isShadow = TRUE,
#line 194
            .heartGauge = 5000,
#line 193
            .shadowID = 50,
            .moves = {
#line 195
                MOVE_SHADOW_RUSH,
            },
            },
            {
#line 197
            .species = SPECIES_SPINARAK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 202
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 198
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 199
            .isShadow = TRUE,
#line 201
            .heartGauge = 5000,
#line 200
            .shadowID = 51,
            .moves = {
#line 202
                MOVE_SHADOW_RUSH,
            },
            },
            {
#line 204
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 206
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 205
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 207
    [DIFFICULTY_NORMAL][TRAINER_BUGSY_1] =
    {
#line 208
        .trainerName = _("BUGSY"),
#line 209
        .trainerClass = TRAINER_CLASS_LEADER,
#line 211
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .encounterMusic_gender =
#line 210
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 214
            .species = SPECIES_PINECO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 216
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 215
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 216
                MOVE_PIN_MISSILE,
                MOVE_HEADBUTT,
                MOVE_BULLET_SEED,
                MOVE_HARDEN,
            },
            },
            {
#line 221
            .species = SPECIES_LEDIAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 223
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 222
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 223
                MOVE_BULLET_SEED,
                MOVE_COMET_PUNCH,
                MOVE_SUPERSONIC,
                MOVE_REFLECT,
            },
            },
            {
#line 228
            .species = SPECIES_SCYTHER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 228
            .heldItem = ITEM_BERRY_JUICE,
#line 230
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 229
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 230
                MOVE_QUICK_ATTACK,
                MOVE_FURY_CUTTER,
                MOVE_BULLET_SEED,
                MOVE_PURSUIT,
            },
            },
        },
    },
#line 235
    [DIFFICULTY_NORMAL][TRAINER_LEADER_FALKNER] =
    {
#line 236
        .trainerName = _("FALKNER"),
#line 237
        .trainerClass = TRAINER_CLASS_LEADER,
#line 238
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 241
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 243
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 242
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 244
    [DIFFICULTY_NORMAL][TRAINER_MISTY] =
    {
#line 245
        .trainerName = _("MISTY"),
#line 246
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 248
        .trainerPic = TRAINER_PIC_MISTY,
        .encounterMusic_gender =
#line 249
F_TRAINER_FEMALE | 
#line 247
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 251
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 253
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 252
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 254
            .species = SPECIES_CORSOLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 256
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 255
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 257
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 259
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 258
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 260
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 262
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 261
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 263
    [DIFFICULTY_NORMAL][TRAINER_ROCKET_GRUNT_M_1] =
    {
#line 264
        .trainerName = _("ZANDER"),
#line 265
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 266
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 268
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 269
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 271
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 274
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 272
            .lvl = 1,
#line 273
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 275
            .isShadow = TRUE,
#line 277
            .heartGauge = 5000,
#line 276
            .shadowID = 49,
            .moves = {
#line 278
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_SKY,
                MOVE_SHADOW_WAVE,
            },
            },
        },
    },
#line 282
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER1] =
    {
#line 283
        .trainerName = _("Neil"),
#line 284
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 285
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 288
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 290
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 289
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 291
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 293
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 292
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 294
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 296
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 295
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 297
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER2] =
    {
#line 298
        .trainerName = _("Rick"),
#line 299
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 300
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 303
            .species = SPECIES_CUTIEFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 305
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 304
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 306
            .species = SPECIES_GRUBBIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 308
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 307
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 309
            .species = SPECIES_JOLTIK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 311
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 310
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 312
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER3] =
    {
#line 313
        .trainerName = _("Jamal"),
#line 314
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 315
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 318
            .species = SPECIES_VENIPEDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 320
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 319
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 321
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 323
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 322
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 324
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 326
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 325
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 327
    [DIFFICULTY_NORMAL][TRAINER_VF_ROCKET] =
    {
#line 328
        .trainerName = _("Travis"),
#line 329
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 330
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 332
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 333
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 335
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 337
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 336
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 338
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 340
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 339
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 341
    [DIFFICULTY_NORMAL][TRAINER_VF_PLASMA] =
    {
#line 342
        .trainerName = _("Corvin"),
#line 343
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 344
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 346
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
#line 347
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 349
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 351
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 350
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 352
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 354
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 353
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 355
    [DIFFICULTY_NORMAL][TRAINER_VF_GALACTIC] =
    {
#line 356
        .trainerName = _("Vega"),
#line 357
        .trainerClass = TRAINER_CLASS_TEAM_GALACTIC,
#line 358
        .trainerPic = TRAINER_PIC_GALACTIC_GRUNT_M_GEN4,
        .encounterMusic_gender =
#line 360
            TRAINER_ENCOUNTER_MUSIC_GALACTIC,
#line 361
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 363
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 365
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 364
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 366
            .species = SPECIES_STUNKY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 368
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 367
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 369
    [DIFFICULTY_NORMAL][TRAINER_VF_SKULL] =
    {
#line 370
        .trainerName = _("Rex"),
#line 371
        .trainerClass = TRAINER_CLASS_TEAM_SKULL,
#line 372
        .trainerPic = TRAINER_PIC_SKULL_MFP,
        .encounterMusic_gender =
#line 374
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 375
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 377
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 378
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 380
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 382
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 381
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 383
    [DIFFICULTY_NORMAL][TRAINER_VF_FLARE] =
    {
#line 384
        .trainerName = _("Pyre"),
#line 385
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 386
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 388
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 389
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 391
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 393
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 392
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 394
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 396
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 395
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 397
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER1] =
    {
#line 398
        .trainerName = _("BEN"),
#line 399
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 400
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 403
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 405
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 404
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 406
            .species = SPECIES_WOOBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 408
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 407
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 409
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER2] =
    {
#line 410
        .trainerName = _("CALVIN"),
#line 411
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 412
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 415
            .species = SPECIES_MUDBRAY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 417
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 416
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 418
            .species = SPECIES_MINCCINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 420
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 419
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 421
    [DIFFICULTY_NORMAL][TRAINER_RT3_LASS] =
    {
#line 422
        .trainerName = _("LASS"),
#line 423
        .trainerClass = TRAINER_CLASS_LASS,
#line 424
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 425
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 427
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 429
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 428
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 430
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 432
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 431
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 433
    [DIFFICULTY_NORMAL][TRAINER_RT3_FIREBREATHER] =
    {
#line 434
        .trainerName = _("Otis"),
#line 435
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 436
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 439
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 441
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 440
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 442
            .species = SPECIES_AUDINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 444
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 443
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 445
    [DIFFICULTY_NORMAL][TRAINER_TEMP_MIROR_B] =
    {
#line 446
        .trainerName = _("MIROR B"),
#line 447
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 448
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 450
            TRAINER_ENCOUNTER_MUSIC_MIRRORB,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 452
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 454
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 453
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 455
    [DIFFICULTY_NORMAL][TRAINER_RT4_BLACK_BELT] =
    {
#line 456
        .trainerName = _("RYU"),
#line 457
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 458
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 461
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 463
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 462
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 464
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 466
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 465
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 467
    [DIFFICULTY_NORMAL][TRAINER_RT4_ROCKER] =
    {
#line 468
        .trainerName = _("AMP"),
#line 469
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 470
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 473
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 475
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 474
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 476
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 478
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 477
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 479
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER1] =
    {
#line 480
        .trainerName = _("LILY"),
#line 481
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 482
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 483
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 485
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 487
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 486
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 488
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 490
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 489
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 491
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER2] =
    {
#line 492
        .trainerName = _("MIA"),
#line 493
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 494
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 495
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 497
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 499
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 498
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 500
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 502
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 501
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 503
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN1] =
    {
#line 504
        .trainerName = _("BRENDAN"),
#line 505
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 506
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 509
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 511
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 510
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 512
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 514
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 513
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 515
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN2] =
    {
#line 516
        .trainerName = _("BRENDAN"),
#line 517
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 518
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 521
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 523
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 522
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 524
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 526
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 525
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 527
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN3] =
    {
#line 528
        .trainerName = _("BRENDAN"),
#line 529
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 530
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 533
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 535
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 534
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 536
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 538
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 537
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 539
    [DIFFICULTY_NORMAL][TRAINER_LOOKER_CERULEAN] =
    {
#line 540
        .trainerName = _("LOOKER"),
#line 541
        .trainerClass = TRAINER_CLASS_POLICEMAN,
#line 542
        .trainerPic = TRAINER_PIC_LOOKER_GEN5,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 545
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 548
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 546
            .lvl = 1,
#line 547
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 548
                MOVE_BITE,
                MOVE_EMBER,
            },
            },
            {
#line 551
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 554
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 552
            .lvl = 1,
#line 553
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 554
                MOVE_LOW_KICK,
                MOVE_MUD_SLAP,
            },
            },
        },
    },
#line 557
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER1] =
    {
#line 558
        .trainerName = _("TIM"),
#line 559
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 560
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 563
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 565
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 564
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 566
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 568
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 567
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 569
    [DIFFICULTY_NORMAL][TRAINER_RT25_LADY] =
    {
#line 570
        .trainerName = _("MARIE"),
#line 571
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 572
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
#line 573
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 575
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 577
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 576
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 578
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 580
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 579
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 581
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_F] =
    {
#line 582
        .trainerName = _("KARA"),
#line 583
        .trainerClass = TRAINER_CLASS_ACE_TRAINER,
#line 584
        .trainerPic = TRAINER_PIC_ACE_TRAINER_GEN2F,
        .encounterMusic_gender =
#line 585
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 587
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 589
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 588
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 590
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 592
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 591
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 593
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER2] =
    {
#line 594
        .trainerName = _("BEN"),
#line 595
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 596
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 599
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 601
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 600
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 602
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 604
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 603
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 605
    [DIFFICULTY_NORMAL][TRAINER_RT25_CAMPER] =
    {
#line 606
        .trainerName = _("COLE"),
#line 607
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 608
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 611
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 613
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 612
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 614
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 616
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 615
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 617
    [DIFFICULTY_NORMAL][TRAINER_RT25_LASS] =
    {
#line 618
        .trainerName = _("NINA"),
#line 619
        .trainerClass = TRAINER_CLASS_LASS,
#line 620
        .trainerPic = TRAINER_PIC_LASS_GEN2,
        .encounterMusic_gender =
#line 621
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 623
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 625
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 624
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 626
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 628
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 627
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 629
    [DIFFICULTY_NORMAL][TRAINER_RT25_SUPER_NERD] =
    {
#line 630
        .trainerName = _("DEX"),
#line 631
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 632
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 635
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 637
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 636
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 638
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 640
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 639
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 641
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M] =
    {
#line 642
        .trainerName = _("TYLER"),
#line 643
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 644
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 647
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 649
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 648
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 650
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 652
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 651
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 653
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F1] =
    {
#line 654
        .trainerName = _("MAYA"),
#line 655
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 656
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 657
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 659
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 661
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 660
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 662
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 664
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 663
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 665
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F2] =
    {
#line 666
        .trainerName = _("KAREN"),
#line 667
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 668
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 669
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 671
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 673
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 672
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 674
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 676
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 675
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 677
    [DIFFICULTY_NORMAL][TRAINER_KURTS_HOUSE_IRONMASK] =
    {
#line 678
        .trainerName = _("MARAUDER"),
#line 679
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 680
        .trainerPic = TRAINER_PIC_SNAGEM,
        .encounterMusic_gender =
#line 681
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 683
            .species = SPECIES_MURKROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 685
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 684
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 686
            .species = SPECIES_SNEASEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 688
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 687
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 689
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_1] =
    {
#line 690
        .trainerName = _("AXEL"),
#line 691
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 692
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 693
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 695
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 697
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 696
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 698
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 700
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 699
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 701
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_2] =
    {
#line 702
        .trainerName = _("DANE"),
#line 703
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 704
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 705
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 707
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 709
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 708
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 710
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 712
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 711
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 713
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_3] =
    {
#line 714
        .trainerName = _("MIRA"),
#line 715
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 716
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 717
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 719
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 721
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 720
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 722
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 724
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 723
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 725
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_4] =
    {
#line 726
        .trainerName = _("COLT"),
#line 727
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 728
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 729
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 731
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 733
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 732
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 734
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 736
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 735
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 737
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_5] =
    {
#line 738
        .trainerName = _("ROOK"),
#line 739
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 740
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 741
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 743
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 745
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 744
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 746
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 748
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 747
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 749
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_1F_PLASMA_6] =
    {
#line 750
        .trainerName = _("NASH"),
#line 751
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 752
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 753
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 755
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 757
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 756
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 758
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 760
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 759
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 761
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_1] =
    {
#line 762
        .trainerName = _("FAYE"),
#line 763
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 764
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 765
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 767
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 769
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 768
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 770
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 772
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 771
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 773
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_2] =
    {
#line 774
        .trainerName = _("ORIN"),
#line 775
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 776
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 777
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 779
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 781
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 780
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 782
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 784
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 783
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 785
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_3] =
    {
#line 786
        .trainerName = _("GAGE"),
#line 787
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 788
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 789
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 791
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 793
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 792
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 794
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 796
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 795
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 797
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_4] =
    {
#line 798
        .trainerName = _("NYX"),
#line 799
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 800
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 801
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 803
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 805
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 804
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 806
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 808
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 807
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 809
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_5] =
    {
#line 810
        .trainerName = _("KADE"),
#line 811
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 812
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 813
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 815
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 817
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 816
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 818
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 820
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 819
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 821
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_6] =
    {
#line 822
        .trainerName = _("VOSS"),
#line 823
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 824
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 825
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 827
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 829
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 828
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 830
            .species = SPECIES_DRILBUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 832
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 831
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 833
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_7] =
    {
#line 834
        .trainerName = _("IRIS"),
#line 835
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 836
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 837
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 839
            .species = SPECIES_PURRLOIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 841
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 840
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 842
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 844
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 843
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 845
    [DIFFICULTY_NORMAL][TRAINER_ROCK_TUNNEL_B1F_PLASMA_8] =
    {
#line 846
        .trainerName = _("SERA"),
#line 847
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 848
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_F_GEN5,
        .encounterMusic_gender =
#line 849
            TRAINER_ENCOUNTER_MUSIC_PLASMA,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 851
            .species = SPECIES_SANDILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 853
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 852
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 854
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 856
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 855
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 857
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_BRYONY] =
    {
#line 858
        .trainerName = _("BRYONY"),
#line 859
        .trainerClass = TRAINER_CLASS_TEAM_FLARE_ADMIN,
#line 860
        .trainerPic = TRAINER_PIC_BRYONY,
        .encounterMusic_gender =
#line 861
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 863
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 865
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 864
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 866
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 868
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 867
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 869
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_1] =
    {
#line 870
        .trainerName = _("VESPER"),
#line 871
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 872
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 873
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 875
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 877
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 876
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 878
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 880
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 879
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 881
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_2] =
    {
#line 882
        .trainerName = _("ORLA"),
#line 883
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 884
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 885
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 887
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 889
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 888
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 890
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 892
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 891
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 893
    [DIFFICULTY_NORMAL][TRAINER_SLOWPOKEWELL_FLARE_3] =
    {
#line 894
        .trainerName = _("KADE"),
#line 895
        .trainerClass = TRAINER_CLASS_TEAM_FLARE,
#line 896
        .trainerPic = TRAINER_PIC_FLARE_MFP,
        .encounterMusic_gender =
#line 897
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 899
            .species = SPECIES_FLETCHLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 901
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 900
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 902
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 904
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 903
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 905
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_1] =
    {
#line 906
        .trainerName = _("ROBIN"),
#line 907
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 908
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 910
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 912
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 911
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 913
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 915
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 914
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 916
    [DIFFICULTY_NORMAL][TRAINER_VIOLET_GYM_BIRD_KEEPER_2] =
    {
#line 917
        .trainerName = _("KYLE"),
#line 918
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 919
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 921
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 923
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 922
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 924
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 926
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 925
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 927
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_YOUNGSTER] =
    {
#line 928
        .trainerName = _("TIM"),
#line 929
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 930
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 933
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 935
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 934
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 936
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 938
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 937
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 939
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_PICNICKER] =
    {
#line 940
        .trainerName = _("LINA"),
#line 941
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 942
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 943
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 945
            .species = SPECIES_HOPPIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 947
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 946
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 948
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 950
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 949
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 951
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_1] =
    {
#line 952
        .trainerName = _("RAY"),
#line 953
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 954
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 957
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 959
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 958
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 960
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_2] =
    {
#line 961
        .trainerName = _("NED"),
#line 962
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 963
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 966
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 968
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 967
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 969
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_FISHERMAN_3] =
    {
#line 970
        .trainerName = _("LEO"),
#line 971
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 972
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 975
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 977
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 976
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 978
    [DIFFICULTY_NORMAL][TRAINER_ROUTE32_BIRD_KEEPER] =
    {
#line 979
        .trainerName = _("MILO"),
#line 980
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 981
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 984
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 986
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 985
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 987
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 989
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 988
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 990
    [DIFFICULTY_NORMAL][TRAINER_ROUTE33_HIKER] =
    {
#line 991
        .trainerName = _("DUKE"),
#line 992
        .trainerClass = TRAINER_CLASS_HIKER,
#line 993
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 996
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 998
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 997
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 999
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_HIKER] =
    {
#line 1000
        .trainerName = _("GUS"),
#line 1001
        .trainerClass = TRAINER_CLASS_HIKER,
#line 1002
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1005
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1007
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1006
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 1008
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1010
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1009
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1011
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_SUPER_NERD] =
    {
#line 1012
        .trainerName = _("TREV"),
#line 1013
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
#line 1014
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1017
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1019
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1018
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 1020
    [DIFFICULTY_NORMAL][TRAINER_UNION_CAVE_FIREBREATHER] =
    {
#line 1021
        .trainerName = _("BO"),
#line 1022
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 1023
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1026
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1028
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1027
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
