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
    [DIFFICULTY_NORMAL][TRAINER_GIOVANNI_1] =
    {
#line 102
        .trainerName = _("GIOVANNI"),
#line 103
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 104
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .encounterMusic_gender =
#line 106
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 108
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 110
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 109
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 111
    [DIFFICULTY_NORMAL][TRAINER_BROCK_KANTO] =
    {
#line 112
        .trainerName = _("BROCK"),
#line 113
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 115
        .trainerPic = TRAINER_PIC_BROCK_KANTO,
        .encounterMusic_gender =
#line 114
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 118
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 121
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 119
            .lvl = 15,
#line 120
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 121
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 126
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 129
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 127
            .lvl = 17,
#line 128
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 129
                MOVE_TACKLE,
                MOVE_BIND,
                MOVE_ROCK_THROW,
                MOVE_SCREECH,
            },
            },
            {
#line 134
            .species = SPECIES_SUDOWOODO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 137
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 135
            .lvl = 17,
#line 136
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 137
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 142
    [DIFFICULTY_NORMAL][TRAINER_CAMPER_KANTO] =
    {
#line 143
        .trainerName = _("JERRY"),
#line 144
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 145
        .trainerPic = TRAINER_PIC_CAMPER_KANTO,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 148
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 151
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 149
            .lvl = 1,
#line 150
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 151
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
            {
#line 154
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 157
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 155
            .lvl = 1,
#line 156
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 157
                MOVE_PECK,
                MOVE_GROWL,
            },
            },
        },
    },
#line 160
    [DIFFICULTY_NORMAL][TRAINER_ARCHER] =
    {
#line 161
        .trainerName = _("ARCHER"),
#line 162
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 163
        .trainerPic = TRAINER_PIC_ARCHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 166
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 168
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 167
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 169
    [DIFFICULTY_NORMAL][TRAINER_ARIANA] =
    {
#line 170
        .trainerName = _("ARIANA"),
#line 171
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 172
        .trainerPic = TRAINER_PIC_ARIANA,
        .encounterMusic_gender =
#line 173
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 175
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 177
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 176
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 178
    [DIFFICULTY_NORMAL][TRAINER_BIKER] =
    {
#line 179
        .trainerName = _("BIKER"),
#line 180
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 181
        .trainerPic = TRAINER_PIC_BIKER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 184
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 186
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 185
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 187
    [DIFFICULTY_NORMAL][TRAINER_BLAINE] =
    {
#line 188
        .trainerName = _("BLAINE"),
#line 189
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 191
        .trainerPic = TRAINER_PIC_BLAINE,
        .encounterMusic_gender =
#line 190
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 194
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 196
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 195
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 197
    [DIFFICULTY_NORMAL][TRAINER_BURGLAR] =
    {
#line 198
        .trainerName = _("BURGLAR"),
#line 199
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 200
        .trainerPic = TRAINER_PIC_BURGLAR,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 203
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 205
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 204
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 206
    [DIFFICULTY_NORMAL][TRAINER_CHAMPION_LANCE] =
    {
#line 207
        .trainerName = _("LANCE"),
#line 208
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 209
        .trainerPic = TRAINER_PIC_CHAMPION_LANCE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 212
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 214
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 213
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 215
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_BRUNO] =
    {
#line 216
        .trainerName = _("BRUNO"),
#line 217
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 218
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 221
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 223
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 222
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 224
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_KAREN] =
    {
#line 225
        .trainerName = _("KAREN"),
#line 226
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 227
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KAREN,
        .encounterMusic_gender =
#line 228
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 230
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 232
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 231
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 233
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_KOGA] =
    {
#line 234
        .trainerName = _("KOGA"),
#line 235
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 236
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KOGA,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 239
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 241
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 240
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 242
    [DIFFICULTY_NORMAL][TRAINER_ELITE_FOUR_WILL] =
    {
#line 243
        .trainerName = _("WILL"),
#line 244
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 245
        .trainerPic = TRAINER_PIC_ELITE_FOUR_WILL,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 248
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 249
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 251
    [DIFFICULTY_NORMAL][TRAINER_ENGINEER] =
    {
#line 252
        .trainerName = _("ENGINEER"),
#line 253
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 254
        .trainerPic = TRAINER_PIC_ENGINEER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 257
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 259
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 258
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 260
    [DIFFICULTY_NORMAL][TRAINER_ERIKA] =
    {
#line 261
        .trainerName = _("ERIKA"),
#line 262
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 264
        .trainerPic = TRAINER_PIC_ERIKA,
        .encounterMusic_gender =
#line 263
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 267
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 269
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 268
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 270
    [DIFFICULTY_NORMAL][TRAINER_EUSINE] =
    {
#line 271
        .trainerName = _("EUSINE"),
#line 272
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 273
        .trainerPic = TRAINER_PIC_EUSINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 276
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 278
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 277
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 279
    [DIFFICULTY_NORMAL][TRAINER_FIREBREATHER] =
    {
#line 280
        .trainerName = _("KLAY"),
#line 281
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 282
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 285
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 287
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 286
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 288
    [DIFFICULTY_NORMAL][TRAINER_GOLD] =
    {
#line 289
        .trainerName = _("GOLD"),
#line 290
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 291
        .trainerPic = TRAINER_PIC_GOLD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 294
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 296
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 295
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 297
    [DIFFICULTY_NORMAL][TRAINER_JANINE] =
    {
#line 298
        .trainerName = _("JANINE"),
#line 299
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 301
        .trainerPic = TRAINER_PIC_JANINE,
        .encounterMusic_gender =
#line 300
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 304
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 306
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 305
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 307
    [DIFFICULTY_NORMAL][TRAINER_JUGGLER] =
    {
#line 308
        .trainerName = _("JUGGLER"),
#line 309
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 310
        .trainerPic = TRAINER_PIC_JUGGLER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 313
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 315
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 314
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 316
    [DIFFICULTY_NORMAL][TRAINER_KIMONO_GIRL] =
    {
#line 317
        .trainerName = _("JOK"),
#line 318
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 319
        .trainerPic = TRAINER_PIC_KIMONO_GIRL,
        .encounterMusic_gender =
#line 320
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 322
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 324
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 323
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 325
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BLUE] =
    {
#line 326
        .trainerName = _("BLUE"),
#line 327
        .trainerClass = TRAINER_CLASS_LEADER,
#line 328
        .trainerPic = TRAINER_PIC_LEADER_BLUE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 331
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 333
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 332
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 334
    [DIFFICULTY_NORMAL][TRAINER_LEADER_BUGSY] =
    {
#line 335
        .trainerName = _("BUGSY"),
#line 336
        .trainerClass = TRAINER_CLASS_LEADER,
#line 337
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 340
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 342
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 341
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 343
    [DIFFICULTY_NORMAL][TRAINER_LEADER_CHUCK] =
    {
#line 344
        .trainerName = _("CHUCK"),
#line 345
        .trainerClass = TRAINER_CLASS_LEADER,
#line 346
        .trainerPic = TRAINER_PIC_LEADER_CHUCK,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 349
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 351
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 350
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 352
    [DIFFICULTY_NORMAL][TRAINER_LEADER_CLAIR] =
    {
#line 353
        .trainerName = _("CLAIR"),
#line 354
        .trainerClass = TRAINER_CLASS_LEADER,
#line 355
        .trainerPic = TRAINER_PIC_LEADER_CLAIR,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 358
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 360
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 359
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 361
    [DIFFICULTY_NORMAL][TRAINER_LEADER_FALKNER] =
    {
#line 362
        .trainerName = _("FALKNER"),
#line 363
        .trainerClass = TRAINER_CLASS_LEADER,
#line 364
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 367
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 369
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 368
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 370
    [DIFFICULTY_NORMAL][TRAINER_LEADER_JASMINE] =
    {
#line 371
        .trainerName = _("JASMINE"),
#line 372
        .trainerClass = TRAINER_CLASS_LEADER,
#line 373
        .trainerPic = TRAINER_PIC_LEADER_JASMINE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 376
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 378
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 377
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 379
    [DIFFICULTY_NORMAL][TRAINER_LEADER_MORTY] =
    {
#line 380
        .trainerName = _("MORTY"),
#line 381
        .trainerClass = TRAINER_CLASS_LEADER,
#line 382
        .trainerPic = TRAINER_PIC_LEADER_MORTY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 385
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 387
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 386
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 388
    [DIFFICULTY_NORMAL][TRAINER_LEADER_PRYCE] =
    {
#line 389
        .trainerName = _("PRYCE"),
#line 390
        .trainerClass = TRAINER_CLASS_LEADER,
#line 391
        .trainerPic = TRAINER_PIC_LEADER_PRYCE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 394
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 396
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 395
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 397
    [DIFFICULTY_NORMAL][TRAINER_LEADER_WHITNEY] =
    {
#line 398
        .trainerName = _("WHITNEY"),
#line 399
        .trainerClass = TRAINER_CLASS_LEADER,
#line 400
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 403
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 405
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 404
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 406
    [DIFFICULTY_NORMAL][TRAINER_LYRA] =
    {
#line 407
        .trainerName = _("LYRA"),
#line 408
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 409
        .trainerPic = TRAINER_PIC_LYRA,
        .encounterMusic_gender =
#line 410
F_TRAINER_FEMALE | 
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 412
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 414
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 413
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 415
    [DIFFICULTY_NORMAL][TRAINER_MISTY] =
    {
#line 416
        .trainerName = _("MISTY"),
#line 417
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 419
        .trainerPic = TRAINER_PIC_MISTY,
        .encounterMusic_gender =
#line 418
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 422
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 424
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 423
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 425
    [DIFFICULTY_NORMAL][TRAINER_NURSE] =
    {
#line 426
        .trainerName = _("NURSE"),
#line 427
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 428
        .trainerPic = TRAINER_PIC_NURSE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 431
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 433
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 432
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 434
    [DIFFICULTY_NORMAL][TRAINER_OFFICER] =
    {
#line 435
        .trainerName = _("OFFICER"),
#line 436
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 437
        .trainerPic = TRAINER_PIC_OFFICER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 440
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 442
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 441
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 443
    [DIFFICULTY_NORMAL][TRAINER_PETREL] =
    {
#line 444
        .trainerName = _("PETREL"),
#line 445
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 446
        .trainerPic = TRAINER_PIC_PETREL,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 449
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 451
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 450
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 452
    [DIFFICULTY_NORMAL][TRAINER_PROTON] =
    {
#line 453
        .trainerName = _("PROTON"),
#line 454
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 455
        .trainerPic = TRAINER_PIC_PROTON,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 458
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 460
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 459
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 461
    [DIFFICULTY_NORMAL][TRAINER_PSYCHIC_M2] =
    {
#line 462
        .trainerName = _("PSYCHIC"),
#line 463
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 464
        .trainerPic = TRAINER_PIC_PSYCHIC_M2,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 467
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 469
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 468
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 470
    [DIFFICULTY_NORMAL][TRAINER_SABRINA] =
    {
#line 471
        .trainerName = _("SABRINA"),
#line 472
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 474
        .trainerPic = TRAINER_PIC_SABRINA,
        .encounterMusic_gender =
#line 473
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 477
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 479
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 478
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 480
    [DIFFICULTY_NORMAL][TRAINER_SAGE] =
    {
#line 481
        .trainerName = _("SAGE"),
#line 482
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 483
        .trainerPic = TRAINER_PIC_SAGE,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 486
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 488
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 487
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 489
    [DIFFICULTY_NORMAL][TRAINER_SAGE_LEADER] =
    {
#line 490
        .trainerName = _("SAGE"),
#line 491
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 492
        .trainerPic = TRAINER_PIC_SAGE_LEADER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 495
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 497
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 496
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 498
    [DIFFICULTY_NORMAL][TRAINER_SILVER] =
    {
#line 499
        .trainerName = _("SILVER"),
#line 500
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 501
        .trainerPic = TRAINER_PIC_SILVER,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 504
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 506
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 505
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 507
    [DIFFICULTY_NORMAL][TRAINER_SUPER_NERD] =
    {
#line 508
        .trainerName = _("SUPER NERD"),
#line 509
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 510
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 513
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 515
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 514
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 516
    [DIFFICULTY_NORMAL][TRAINER_SURGE] =
    {
#line 517
        .trainerName = _("LT SURGE"),
#line 518
        .trainerClass = TRAINER_CLASS_KANTO_LEADER,
#line 520
        .trainerPic = TRAINER_PIC_SURGE,
        .encounterMusic_gender =
#line 519
            TRAINER_ENCOUNTER_MUSIC_GYM_LEADER,
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
    [DIFFICULTY_NORMAL][TRAINER_TWINS2] =
    {
#line 527
        .trainerName = _("TWINS2"),
#line 528
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 529
        .trainerPic = TRAINER_PIC_TWINS2,
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
    [DIFFICULTY_NORMAL][TRAINER_YOUNGSTER2] =
    {
#line 536
        .trainerName = _("YOUNGSTER2"),
#line 537
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 538
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 541
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 543
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 542
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 544
    [DIFFICULTY_NORMAL][TRAINER_ROCKET_GRUNT_M_1] =
    {
#line 545
        .trainerName = _("ZANDER"),
#line 546
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 547
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 549
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 550
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 552
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 553
            .lvl = 21,
#line 554
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 556
            .isShadow = TRUE,
#line 558
            .heartGauge = 5000,
#line 557
            .shadowID = 49,
            .moves = {
#line 559
                MOVE_SHADOW_HALF,
                MOVE_SHADOW_SKY,
                MOVE_SHADOW_WAVE,
            },
            },
        },
    },
#line 563
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER1] =
    {
#line 564
        .trainerName = _("Neil"),
#line 565
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 566
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 569
            .species = SPECIES_CATERPIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 571
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 570
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 572
            .species = SPECIES_WEEDLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 574
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 573
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 575
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 577
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 576
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 578
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER2] =
    {
#line 579
        .trainerName = _("Rick"),
#line 580
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 581
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 584
            .species = SPECIES_CUTIEFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 586
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 585
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 587
            .species = SPECIES_GRUBBIN,
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
            .species = SPECIES_JOLTIK,
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
    [DIFFICULTY_NORMAL][TRAINER_VF_BUGCATCHER3] =
    {
#line 594
        .trainerName = _("Jamal"),
#line 595
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 596
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
0,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 599
            .species = SPECIES_VENIPEDE,
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
            .species = SPECIES_VENONAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 604
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 603
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 605
            .species = SPECIES_PARAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 607
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 606
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 608
    [DIFFICULTY_NORMAL][TRAINER_VF_ROCKET] =
    {
#line 609
        .trainerName = _("Travis"),
#line 610
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
#line 611
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .encounterMusic_gender =
#line 613
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 614
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 616
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 618
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 617
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 619
            .species = SPECIES_EKANS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 621
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 620
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 622
    [DIFFICULTY_NORMAL][TRAINER_VF_PLASMA] =
    {
#line 623
        .trainerName = _("Corvin"),
#line 624
        .trainerClass = TRAINER_CLASS_TEAM_PLASMA,
#line 625
        .trainerPic = TRAINER_PIC_PLASMA_GRUNT_M_GEN5,
        .encounterMusic_gender =
#line 627
            TRAINER_ENCOUNTER_MUSIC_TEAM_ROCKET,
#line 628
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 630
            .species = SPECIES_TRUBBISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 632
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 631
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 633
            .species = SPECIES_SCRAGGY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 635
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 634
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 636
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER1] =
    {
#line 637
        .trainerName = _("YOUNGSTER1"),
#line 638
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 639
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 642
            .species = SPECIES_ROGGENROLA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 644
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 643
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 645
            .species = SPECIES_WOOBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 647
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 646
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 648
    [DIFFICULTY_NORMAL][TRAINER_RT3_YOUNGSTER2] =
    {
#line 649
        .trainerName = _("YOUNGSTER"),
#line 650
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 651
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 654
            .species = SPECIES_MUDBRAY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 655
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 657
            .species = SPECIES_MINCCINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 659
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 658
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 660
    [DIFFICULTY_NORMAL][TRAINER_RT3_LASS] =
    {
#line 661
        .trainerName = _("LASS"),
#line 662
        .trainerClass = TRAINER_CLASS_LASS,
#line 663
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 664
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 666
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 668
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 667
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 669
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 671
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 670
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 672
    [DIFFICULTY_NORMAL][TRAINER_RT3_FIREBREATHER] =
    {
#line 673
        .trainerName = _("Otis"),
#line 674
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
#line 675
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 678
            .species = SPECIES_MORELULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 680
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 679
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 681
            .species = SPECIES_AUDINO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 683
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 682
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 684
    [DIFFICULTY_NORMAL][TRAINER_TEMP_MIROR_B] =
    {
#line 685
        .trainerName = _("MIROR B"),
#line 686
        .trainerClass = TRAINER_CLASS_WANDERER,
#line 687
        .trainerPic = TRAINER_PIC_MIRROR_B,
        .encounterMusic_gender =
#line 689
            TRAINER_ENCOUNTER_MUSIC_MIRRORB,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 691
            .species = SPECIES_BLACEPHALON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 693
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 692
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 694
    [DIFFICULTY_NORMAL][TRAINER_EIN] =
    {
#line 695
        .trainerName = _("EIN"),
#line 696
        .trainerClass = TRAINER_CLASS_CIPHER_ADMIN,
#line 697
        .trainerPic = TRAINER_PIC_EIN,
        .encounterMusic_gender =
#line 699
            TRAINER_ENCOUNTER_MUSIC_CIPHER_PEON,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 701
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 703
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 702
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 704
    [DIFFICULTY_NORMAL][TRAINER_RT4_BLACK_BELT] =
    {
#line 705
        .trainerName = _("RYU"),
#line 706
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 707
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 710
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 712
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 711
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 713
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 715
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 714
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 716
    [DIFFICULTY_NORMAL][TRAINER_RT4_ROCKER] =
    {
#line 717
        .trainerName = _("AMP"),
#line 718
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 719
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 722
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 724
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 723
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 725
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 727
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 726
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 728
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER1] =
    {
#line 729
        .trainerName = _("LILY"),
#line 730
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 731
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 732
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 734
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 736
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 735
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 737
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 739
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 738
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 740
    [DIFFICULTY_NORMAL][TRAINER_RT4_PICNICKER2] =
    {
#line 741
        .trainerName = _("MIA"),
#line 742
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 743
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
#line 744
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 746
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 748
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 747
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 749
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 751
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 750
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 752
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN1] =
    {
#line 753
        .trainerName = _("BRENDAN"),
#line 754
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 755
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 758
            .species = SPECIES_STUFFUL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 760
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 759
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 761
            .species = SPECIES_PETILIL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 763
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 762
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 764
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN2] =
    {
#line 765
        .trainerName = _("BRENDAN"),
#line 766
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 767
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 770
            .species = SPECIES_PONYTA_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 772
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 771
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 773
            .species = SPECIES_EMOLGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 775
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 774
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 776
    [DIFFICULTY_NORMAL][TRAINER_RT4_BRENDAN3] =
    {
#line 777
        .trainerName = _("BRENDAN"),
#line 778
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 779
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 782
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 784
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 783
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 785
            .species = SPECIES_DEERLING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 787
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 786
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 788
    [DIFFICULTY_NORMAL][TRAINER_LOOKER_CERULEAN] =
    {
#line 789
        .trainerName = _("LOOKER"),
#line 790
        .trainerClass = TRAINER_CLASS_POLICEMAN,
#line 791
        .trainerPic = TRAINER_PIC_LOOKER_GEN5,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 794
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 797
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 795
            .lvl = 18,
#line 796
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 797
                MOVE_BITE,
                MOVE_EMBER,
            },
            },
            {
#line 800
            .species = SPECIES_CROAGUNK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 803
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 801
            .lvl = 19,
#line 802
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 803
                MOVE_LOW_KICK,
                MOVE_MUD_SLAP,
            },
            },
        },
    },
#line 806
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER1] =
    {
#line 807
        .trainerName = _("TIM"),
#line 808
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 809
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 812
            .species = SPECIES_PIDGEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 814
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 813
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 815
            .species = SPECIES_RATTATA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 817
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 816
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 818
    [DIFFICULTY_NORMAL][TRAINER_RT25_LADY] =
    {
#line 819
        .trainerName = _("MARIE"),
#line 820
        .trainerClass = TRAINER_CLASS_LADY,
#line 821
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
#line 822
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 824
            .species = SPECIES_CLEFAIRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 826
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 825
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 827
            .species = SPECIES_JIGGLYPUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 829
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 828
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 830
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_F] =
    {
#line 831
        .trainerName = _("KARA"),
#line 832
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 833
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
#line 834
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 836
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 838
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 837
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 839
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 841
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 840
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 842
    [DIFFICULTY_NORMAL][TRAINER_RT25_YOUNGSTER2] =
    {
#line 843
        .trainerName = _("BEN"),
#line 844
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 845
        .trainerPic = TRAINER_PIC_YOUNGSTER2,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 848
            .species = SPECIES_SPEAROW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 850
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 849
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 851
            .species = SPECIES_NIDORAN_M,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 853
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 852
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 854
    [DIFFICULTY_NORMAL][TRAINER_RT25_CAMPER] =
    {
#line 855
        .trainerName = _("COLE"),
#line 856
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 857
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 860
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 862
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 861
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 863
            .species = SPECIES_MANKEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 865
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 864
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 866
    [DIFFICULTY_NORMAL][TRAINER_RT25_LASS] =
    {
#line 867
        .trainerName = _("NINA"),
#line 868
        .trainerClass = TRAINER_CLASS_LASS,
#line 869
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
#line 870
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 872
            .species = SPECIES_NIDORAN_F,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 874
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 873
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 875
            .species = SPECIES_BELLSPROUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 877
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 876
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 878
    [DIFFICULTY_NORMAL][TRAINER_RT25_SUPER_NERD] =
    {
#line 879
        .trainerName = _("DEX"),
#line 880
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 881
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 884
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 886
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 885
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 887
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 889
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 888
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 890
    [DIFFICULTY_NORMAL][TRAINER_RT25_COOLTRAINER_M] =
    {
#line 891
        .trainerName = _("RYAN"),
#line 892
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 893
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 896
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 898
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 897
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 899
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 901
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 900
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 902
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_M] =
    {
#line 903
        .trainerName = _("TYLER"),
#line 904
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 905
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 908
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 910
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 909
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 911
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 913
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 912
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 914
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F1] =
    {
#line 915
        .trainerName = _("MAYA"),
#line 916
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 917
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 918
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 920
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 922
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 921
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 923
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 925
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 924
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 926
    [DIFFICULTY_NORMAL][TRAINER_CERULEAN_GYM_SWIMMER_F2] =
    {
#line 927
        .trainerName = _("KARA"),
#line 928
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 929
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
#line 930
F_TRAINER_FEMALE | 
0,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 932
            .species = SPECIES_PSYDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 934
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 933
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 935
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 937
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 936
            .lvl = 1,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
