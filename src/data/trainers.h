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
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 81
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 83
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 86
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 84
            .lvl = 4,
#line 85
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 87
            .isShadow = TRUE,
#line 89
            .heartGauge = 5000,
#line 88
            .shadowID = 1,
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
        .trainerClass = TRAINER_CLASS_LEADER,
#line 104
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 107
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 110
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 108
            .lvl = 15,
#line 109
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 110
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 115
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 118
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 116
            .lvl = 17,
#line 117
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 118
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_THROW,
                MOVE_SCREECH,
            },
            },
            {
#line 123
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 126
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 124
            .lvl = 17,
#line 125
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 126
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 131
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 134
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 132
            .lvl = 18,
#line 133
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 134
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 139
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_KANTO] =
    {
#line 140
        .trainerName = _("JERRY"),
#line 141
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 142
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 145
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 148
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 146
            .lvl = 7,
#line 147
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 148
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 151
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 154
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 152
            .lvl = 7,
#line 153
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 154
                MOVE_PECK,
                MOVE_GROWL,
            },
            },
        },
    },
#line 157
    [DIFFICULTY_NORMAL][TRAINER_ARCHER] =
    {
#line 158
        .trainerName = _("ARCHER"),
#line 159
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 160
        .trainerPic = TRAINER_PIC_ARCHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 163
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 165
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 164
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 166
    [DIFFICULTY_NORMAL][TRAINER_ARIANA] =
    {
#line 167
        .trainerName = _("ARIANA"),
#line 168
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 169
        .trainerPic = TRAINER_PIC_ARIANA,
        .encounterMusic_gender =
#line 170
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 172
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 174
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 173
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 175
    [DIFFICULTY_NORMAL][TRAINER_BIKER] =
    {
#line 176
        .trainerName = _("BIKER"),
#line 177
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 178
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 181
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 183
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 182
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 184
    [DIFFICULTY_NORMAL][TRAINER_BLAINE] =
    {
#line 185
        .trainerName = _("BLAINE"),
#line 186
        .trainerClass = TRAINER_CLASS_LEADER,
#line 187
        .trainerPic = TRAINER_PIC_BLAINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 190
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 192
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 191
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 193
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR] =
    {
#line 194
        .trainerName = _("BURGLAR"),
#line 195
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 196
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 199
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 201
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 200
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 202
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_LANCE] =
    {
#line 203
        .trainerName = _("LANCE"),
#line 204
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 205
        .trainerPic = TRAINER_PIC_CHAMPION_LANCE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 208
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 210
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 209
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 211
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO] =
    {
#line 212
        .trainerName = _("BRUNO"),
#line 213
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 214
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 217
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 219
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 218
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 220
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_KAREN] =
    {
#line 221
        .trainerName = _("KAREN"),
#line 222
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 223
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KAREN,
        .encounterMusic_gender =
#line 224
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 226
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 228
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 227
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 229
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_KOGA] =
    {
#line 230
        .trainerName = _("KOGA"),
#line 231
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 232
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KOGA,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 235
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 237
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 236
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 238
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_WILL] =
    {
#line 239
        .trainerName = _("WILL"),
#line 240
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 241
        .trainerPic = TRAINER_PIC_ELITE_FOUR_WILL,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 244
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 246
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 245
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 247
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER] =
    {
#line 248
        .trainerName = _("ENGINEER"),
#line 249
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 250
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 253
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 255
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 254
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 256
    [DIFFICULTY_NORMAL][TRAINER_ERIKA] =
    {
#line 257
        .trainerName = _("ERIKA"),
#line 258
        .trainerClass = TRAINER_CLASS_LEADER,
#line 259
        .trainerPic = TRAINER_PIC_ERIKA,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 262
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 264
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 263
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 265
    [DIFFICULTY_NORMAL][TRAINER_EUSINE] =
    {
#line 266
        .trainerName = _("EUSINE"),
#line 267
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 268
        .trainerPic = TRAINER_PIC_EUSINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 271
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 273
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 272
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 274
    [DIFFICULTY_NORMAL][TRAINER_FIREBREATHER] =
    {
#line 275
        .trainerName = _("KLAY"),
#line 276
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 277
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 280
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 282
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 281
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 283
    [DIFFICULTY_NORMAL][TRAINER_GOLD] =
    {
#line 284
        .trainerName = _("GOLD"),
#line 285
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 286
        .trainerPic = TRAINER_PIC_GOLD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 289
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 291
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 290
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 292
    [DIFFICULTY_NORMAL][TRAINER_JANINE] =
    {
#line 293
        .trainerName = _("JANINE"),
#line 294
        .trainerClass = TRAINER_CLASS_LEADER,
#line 295
        .trainerPic = TRAINER_PIC_JANINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 298
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 300
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 299
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 301
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER] =
    {
#line 302
        .trainerName = _("JUGGLER"),
#line 303
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 304
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 307
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 309
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 308
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 310
    [DIFFICULTY_NORMAL][TRAINER_KIMONO_GIRL] =
    {
#line 311
        .trainerName = _("JOK"),
#line 312
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 313
        .trainerPic = TRAINER_PIC_KIMONO_GIRL,
        .encounterMusic_gender =
#line 314
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 316
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 318
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 317
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 319
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BLUE] =
    {
#line 320
        .trainerName = _("BLUE"),
#line 321
        .trainerClass = TRAINER_CLASS_LEADER,
#line 322
        .trainerPic = TRAINER_PIC_LEADER_BLUE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 325
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 327
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 326
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 328
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BUGSY] =
    {
#line 329
        .trainerName = _("BUGSY"),
#line 330
        .trainerClass = TRAINER_CLASS_LEADER,
#line 331
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 334
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 336
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 335
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 337
    [DIFFICULTY_NORMAL][TRAINER_LEADER_CHUCK] =
    {
#line 338
        .trainerName = _("CHUCK"),
#line 339
        .trainerClass = TRAINER_CLASS_LEADER,
#line 340
        .trainerPic = TRAINER_PIC_LEADER_CHUCK,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 343
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 345
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 344
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 346
    [DIFFICULTY_NORMAL][TRAINER_LEADER_CLAIR] =
    {
#line 347
        .trainerName = _("CLAIR"),
#line 348
        .trainerClass = TRAINER_CLASS_LEADER,
#line 349
        .trainerPic = TRAINER_PIC_LEADER_CLAIR,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 352
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 354
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 353
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 355
    [DIFFICULTY_NORMAL][TRAINER_LEADER_FALKNER] =
    {
#line 356
        .trainerName = _("FALKNER"),
#line 357
        .trainerClass = TRAINER_CLASS_LEADER,
#line 358
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 361
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 363
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 362
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 364
    [DIFFICULTY_NORMAL][TRAINER_LEADER_JASMINE] =
    {
#line 365
        .trainerName = _("JASMINE"),
#line 366
        .trainerClass = TRAINER_CLASS_LEADER,
#line 367
        .trainerPic = TRAINER_PIC_LEADER_JASMINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 370
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 372
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 371
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 373
    [DIFFICULTY_NORMAL][TRAINER_LEADER_MORTY] =
    {
#line 374
        .trainerName = _("MORTY"),
#line 375
        .trainerClass = TRAINER_CLASS_LEADER,
#line 376
        .trainerPic = TRAINER_PIC_LEADER_MORTY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 379
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 381
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 380
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 382
    [DIFFICULTY_NORMAL][TRAINER_LEADER_PRYCE] =
    {
#line 383
        .trainerName = _("PRYCE"),
#line 384
        .trainerClass = TRAINER_CLASS_LEADER,
#line 385
        .trainerPic = TRAINER_PIC_LEADER_PRYCE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 388
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 390
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 389
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 391
    [DIFFICULTY_NORMAL][TRAINER_LEADER_WHITNEY] =
    {
#line 392
        .trainerName = _("WHITNEY"),
#line 393
        .trainerClass = TRAINER_CLASS_LEADER,
#line 394
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 397
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 399
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 398
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 400
    [DIFFICULTY_NORMAL][TRAINER_LYRA] =
    {
#line 401
        .trainerName = _("LYRA"),
#line 402
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 403
        .trainerPic = TRAINER_PIC_LYRA,
        .encounterMusic_gender =
#line 404
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 406
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 408
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 407
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 409
    [DIFFICULTY_NORMAL][TRAINER_MISTY] =
    {
#line 410
        .trainerName = _("MISTY"),
#line 411
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 412
        .trainerPic = TRAINER_PIC_MISTY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 415
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 417
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 416
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 418
    [DIFFICULTY_NORMAL][TRAINER_NURSE] =
    {
#line 419
        .trainerName = _("NURSE"),
#line 420
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 421
        .trainerPic = TRAINER_PIC_NURSE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 424
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 426
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 425
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 427
    [DIFFICULTY_NORMAL][TRAINER_OFFICER] =
    {
#line 428
        .trainerName = _("OFFICER"),
#line 429
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 430
        .trainerPic = TRAINER_PIC_OFFICER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 433
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 435
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 434
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 436
    [DIFFICULTY_NORMAL][TRAINER_PETREL] =
    {
#line 437
        .trainerName = _("PETREL"),
#line 438
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 439
        .trainerPic = TRAINER_PIC_PETREL,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 442
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 444
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 443
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 445
    [DIFFICULTY_NORMAL][TRAINER_PROTON] =
    {
#line 446
        .trainerName = _("PROTON"),
#line 447
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 448
        .trainerPic = TRAINER_PIC_PROTON,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 451
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 453
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 452
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 454
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_M2] =
    {
#line 455
        .trainerName = _("PSYCHIC"),
#line 456
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 457
        .trainerPic = TRAINER_PIC_PSYCHIC_M2,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 460
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 462
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 461
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 463
    [DIFFICULTY_NORMAL][TRAINER_SABRINA] =
    {
#line 464
        .trainerName = _("SABRINA"),
#line 465
        .trainerClass = TRAINER_CLASS_LEADER,
#line 466
        .trainerPic = TRAINER_PIC_SABRINA,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 469
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 471
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 470
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 472
    [DIFFICULTY_NORMAL][TRAINER_SAGE] =
    {
#line 473
        .trainerName = _("SAGE"),
#line 474
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 475
        .trainerPic = TRAINER_PIC_SAGE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 478
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 480
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 479
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 481
    [DIFFICULTY_NORMAL][TRAINER_SAGE_LEADER] =
    {
#line 482
        .trainerName = _("SAGE"),
#line 483
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 484
        .trainerPic = TRAINER_PIC_SAGE_LEADER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 487
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 489
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 488
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 490
    [DIFFICULTY_NORMAL][TRAINER_SILVER] =
    {
#line 491
        .trainerName = _("SILVER"),
#line 492
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 493
        .trainerPic = TRAINER_PIC_SILVER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 496
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 498
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 497
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 499
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD] =
    {
#line 500
        .trainerName = _("SUPER NERD"),
#line 501
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 502
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 505
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 507
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 506
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 508
    [DIFFICULTY_NORMAL][TRAINER_SURGE] =
    {
#line 509
        .trainerName = _("LT SURGE"),
#line 510
        .trainerClass = TRAINER_CLASS_LEADER,
#line 511
        .trainerPic = TRAINER_PIC_SURGE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 514
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 516
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 515
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 517
    [DIFFICULTY_NORMAL][TRAINER_TWINS2] =
    {
#line 518
        .trainerName = _("TWINS2"),
#line 519
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 520
        .trainerPic = TRAINER_PIC_TWINS2,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 523
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 525
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 524
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 526
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER2] =
    {
#line 527
        .trainerName = _("YOUNGSTER2"),
#line 528
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 529
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 532
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 534
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 533
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 535
    [DIFFICULTY_NORMAL][TRAINER_ROCKET_GRUNT_M_1] =
    {
#line 536
        .trainerName = _("ZANDER"),
#line 537
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 538
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 540
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 541
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 543
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 546
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 544
            .lvl = 21,
#line 545
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 547
            .isShadow = TRUE,
#line 549
            .heartGauge = 5000,
#line 548
            .shadowID = 49,
            .moves = {
#line 550
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_SKY,
                MOVE_SHADOW_WAVE,
            },
            },
        },
    },
