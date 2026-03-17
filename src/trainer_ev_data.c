#include "trainer_ev_data.h"

#include "constants/pokemon.h"
#include "constants/trainers.h"

// EV spread templates — order matches TrainerMonEVs: hp, atk, def, spe, spa, spd
#define EV0           {  0,   0,   0,   0,   0,   0}
#define EV_PHYS_FAST  {  0, 252,   0, 252,   0,   6}
#define EV_SPEC_FAST  {  0,   0,   0, 252, 252,   6}
#define EV_PHYS_BULK  {252, 252,   0,   0,   0,   6}
#define EV_SPEC_BULK  {252,   0,   0,   0, 252,   6}
#define EV_PHYS_TANK  {252,   0, 252,   0,   0,   6}
#define EV_SPEC_TANK  {252,   0,   0,   0,   6, 252}

// Nature shorthand — 0xFF = no override
#define N_  0xFF
#define NO_NATURES  {N_, N_, N_, N_, N_, N_}

// EV table for boss trainers.
// Each entry has an EV array and a separate nature array.
// Slot indices match party order (0 = first Pokemon, etc.).
// Entries for trainers not listed here are never looked up.
static const TrainerEVEntry sTrainerEVTable[] = {
    // =========================================================================
    // RIVAL (Silver) — all story battles
    // Three variants per battle (one per player starter choice).
    // =========================================================================

    // Battle 1 — New Bark Town (starter only)
    { TRAINER_RIVAL_SILVER_2,  { EV_SPEC_FAST, EV0, EV0, EV0, EV0, EV0 }, { NATURE_TIMID,  N_, N_, N_, N_, N_ } }, // Chikorita player → Cyndaquil
    { TRAINER_RIVAL_SILVER_3,  { EV_PHYS_FAST, EV0, EV0, EV0, EV0, EV0 }, { NATURE_JOLLY,  N_, N_, N_, N_, N_ } }, // Cyndaquil player → Totodile
    { TRAINER_RIVAL_SILVER_6,  { EV_SPEC_BULK, EV0, EV0, EV0, EV0, EV0 }, { NATURE_MODEST, N_, N_, N_, N_, N_ } }, // Totodile player  → Chikorita

    // Battle 2 — Cherrygrove: Gastly(s0), Zubat(s1), Starter(s2/ace)
    { TRAINER_RIVAL_SILVER,    { EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_BULK, EV0, EV0, EV0 }, { NATURE_TIMID, NATURE_JOLLY, NATURE_MODEST,  N_, N_, N_ } }, // → Bayleef
    { TRAINER_RIVAL_SILVER_7,  { EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV0, EV0, EV0 }, { NATURE_TIMID, NATURE_JOLLY, NATURE_TIMID,   N_, N_, N_ } }, // → Quilava
    { TRAINER_RIVAL_SILVER_10, { EV_SPEC_FAST, EV_PHYS_FAST, EV_PHYS_BULK, EV0, EV0, EV0 }, { NATURE_TIMID, NATURE_JOLLY, NATURE_ADAMANT, N_, N_, N_ } }, // → Croconaw

    // Battle 3 — Burned Tower: Gastly(s0), Magnemite(s1), Zubat(s2), Starter(s3/ace)
    // Magnemite: Modest (threat over speed games)
    { TRAINER_RIVAL_SILVER_4,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_BULK, EV0, EV0 },
        { NATURE_TIMID, NATURE_MODEST, NATURE_JOLLY, NATURE_MODEST,  N_, N_ }  // → Bayleef
    },
    { TRAINER_RIVAL_SILVER_8,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV0, EV0 },
        { NATURE_TIMID, NATURE_MODEST, NATURE_JOLLY, NATURE_TIMID,   N_, N_ }  // → Quilava
    },
    { TRAINER_RIVAL_SILVER_11,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_PHYS_BULK, EV0, EV0 },
        { NATURE_TIMID, NATURE_MODEST, NATURE_JOLLY, NATURE_ADAMANT, N_, N_ }  // → Croconaw
    },

    // Battle 4 — Goldenrod: Golbat(s0), Magnemite(s1), Haunter(s2), Sneasel(s3), Starter(s4/ace)
    { TRAINER_RIVAL_SILVER_17,
        { EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_BULK, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_JOLLY,  NATURE_MODEST,  N_ }  // → Meganium
    },
    { TRAINER_RIVAL_SILVER_18,
        { EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_JOLLY,  NATURE_TIMID,   N_ }  // → Quilava
    },
    { TRAINER_RIVAL_SILVER_12,
        { EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_FAST, EV_PHYS_BULK, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_JOLLY,  NATURE_ADAMANT, N_ }  // → Feraligatr
    },

    // Battle 5 — Mt. Mortar: Sneasel(s0), Golbat(s1), Magneton(s2), Haunter(s3), Kadabra(s4), Starter(s5/ace)
    // Magneton: Modest  |  Haunter/Kadabra: Timid
    { TRAINER_RIVAL_SILVER_5,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_MODEST  }  // → Meganium
    },
    { TRAINER_RIVAL_SILVER_9,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_TIMID   }  // → Typhlosion
    },
    { TRAINER_RIVAL_SILVER_13,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_ADAMANT }  // → Feraligatr
    },

    // Battle 6 — Kanto: Sneasel(s0), Golbat(s1), Magneton(s2), Gengar(s3), Alakazam(s4), Starter(s5/ace)
    { TRAINER_RIVAL_SILVER_14,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_MODEST  }  // → Meganium
    },
    { TRAINER_RIVAL_SILVER_15,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_TIMID   }  // → Typhlosion
    },
    { TRAINER_RIVAL_SILVER_16,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_ADAMANT }  // → Feraligatr
    },

    // Postgame rematch: Sneasel(s0), Crobat(s1), Magneton(s2), Gengar(s3), Alakazam(s4), Starter(s5/ace)
    { TRAINER_RIVAL_SILVER_19,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_MODEST  }  // → Meganium
    },
    { TRAINER_RIVAL_SILVER_20,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_TIMID   }  // → Typhlosion
    },
    { TRAINER_RIVAL_SILVER_21,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_PHYS_BULK },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID, NATURE_ADAMANT }  // → Feraligatr
    },

    // =========================================================================
    // TEAM ROCKET EXECUTIVES
    // =========================================================================

    // Proton #1 — Slowpoke Well: Zubat(s0), Koffing(s1)
    { TRAINER_EXECUTIVE_PROTON_PROTON,   { EV_PHYS_FAST, EV_PHYS_TANK, EV0, EV0, EV0, EV0 }, { NATURE_JOLLY, NATURE_BOLD, N_, N_, N_, N_ } },

    // Proton #2 — Radio Tower: Golbat(s0), Weezing(s1) — Weezing: Bold (not Impish)
    { TRAINER_EXECUTIVE_PROTON_PROTON_2,
        { EV_PHYS_FAST, EV_PHYS_TANK, EV0, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_BOLD,  N_,  N_,  N_,  N_  }
    },

    // Petrel #1 — Mahogany: Zubat(s0), Raticate(s1/ace), Koffing(s2)
    { TRAINER_EXECUTIVE_PETREL_PETREL,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_TANK, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_JOLLY,  NATURE_BOLD,  N_,  N_,  N_  }
    },

    // Petrel #2 — Radio Tower: Koffing×5, Weezing(s3/ace) — all Bold tanks
    { TRAINER_EXECUTIVE_PETREL_PETREL_2,
        { EV_PHYS_TANK, EV_PHYS_TANK, EV_PHYS_TANK, EV_PHYS_TANK, EV_PHYS_TANK, EV_PHYS_TANK },
        { NATURE_BOLD,  NATURE_BOLD,  NATURE_BOLD,  NATURE_BOLD,  NATURE_BOLD,  NATURE_BOLD  }
    },

    // Ariana #1 — Mahogany: Arbok(s0), Gloom(s1), Murkrow(s2)
    { TRAINER_EXECUTIVE_ARIANA_ARIANA,
        { EV_PHYS_FAST, EV_SPEC_BULK,   EV_PHYS_FAST, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_JOLLY,  N_,  N_,  N_  }
    },

    // Ariana #2 — Goldenrod: Arbok(s0), Vileplume(s1), Murkrow(s2)
    { TRAINER_EXECUTIVE_ARIANA_ARIANA_2,
        { EV_PHYS_FAST, EV_SPEC_BULK,   EV_PHYS_FAST, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_JOLLY,  N_,  N_,  N_  }
    },

    // Archer — Radio Tower: Houndour(s0), Koffing(s1), Houndoom(s2/ace)
    { TRAINER_EXECUTIVE_ARCHER_ARCHER,
        { EV_SPEC_FAST, EV_PHYS_TANK, EV_SPEC_FAST, EV0, EV0, EV0 },
        { NATURE_TIMID, NATURE_BOLD,  NATURE_TIMID,  N_,  N_,  N_  }
    },

    // =========================================================================
    // JOHTO GYM LEADERS — first challenge
    // =========================================================================

    // Falkner — Pidgey(s0), Pidgeotto(s1/ace)
    { TRAINER_LEADER_FALKNER_FALKNER,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV0, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_JOLLY,  N_,  N_,  N_,  N_  }
    },

    // Bugsy — Scyther(s0/ace), Kakuna(s1), Metapod(s2)
    { TRAINER_LEADER_BUGSY_BUGSY,
        { EV_PHYS_FAST, EV_PHYS_TANK, EV_PHYS_TANK, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_BOLD,  NATURE_BOLD,  N_,  N_,  N_  }
    },

    // Whitney — Clefairy(s0), Miltank(s1/ace)
    { TRAINER_LEADER_WHITNEY,
        { EV_SPEC_BULK, EV_PHYS_TANK,  EV0, EV0, EV0, EV0 },
        { NATURE_MODEST, NATURE_IMPISH, N_,  N_,  N_,  N_  }
    },

    // Morty — Gastly(s0), Haunter@21(s1), Gengar(s2/ace), Haunter@23(s3)
    { TRAINER_LEADER_MORTY_MORTY,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST, EV0, EV0 },
        { NATURE_TIMID, NATURE_TIMID, NATURE_TIMID, NATURE_TIMID,  N_,  N_  }
    },

    // Chuck — Primeape(s0), Poliwrath(s1/ace)
    { TRAINER_LEADER_CHUCK_CHUCK,
        { EV_PHYS_FAST, EV_PHYS_BULK,   EV0, EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_ADAMANT, N_,  N_,  N_,  N_  }
    },

    // Jasmine — Magnemite(s0), Magnemite(s1), Steelix(s2/ace)
    // Magnemites: Modest (not Timid — threat over speed games)
    { TRAINER_LEADER_JASMINE_JASMINE,
        { EV_SPEC_FAST,  EV_SPEC_FAST,  EV_PHYS_BULK,   EV0, EV0, EV0 },
        { NATURE_MODEST, NATURE_MODEST, NATURE_ADAMANT, N_,  N_,  N_  }
    },

    // Pryce — Seel(s0), Dewgong(s1), Piloswine(s2/ace)
    { TRAINER_LEADER_PRYCE_PRYCE,
        { EV_SPEC_TANK, EV_SPEC_BULK,  EV_PHYS_BULK,   EV0, EV0, EV0 },
        { NATURE_CALM,  NATURE_MODEST, NATURE_ADAMANT, N_,  N_,  N_  }
    },

    // Clair — Gyarados(s0), Dragonair(s1), Dragonair(s2), Kingdra(s3/ace)
    // Kingdra: Modest (boss ace — not Calm)
    { TRAINER_LEADER_CLAIR_CLAIR,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_BULK,   EV0, EV0 },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, N_,  N_  }
    },

    // =========================================================================
    // JOHTO GYM LEADERS — rematches
    // =========================================================================

    // Falkner-R — Staraptor(s0), Noctowl(s1), Swellow(s2), Honchkrow(s3), Pelipper(s4), Pidgeot(s5/ace)
    { TRAINER_LEADER_FALKNER_FALKNER_2,
        { EV_PHYS_FAST, EV_SPEC_TANK, EV_PHYS_FAST, EV_PHYS_BULK,   EV_SPEC_TANK, EV_PHYS_FAST },
        { NATURE_JOLLY, NATURE_CALM,  NATURE_JOLLY, NATURE_ADAMANT, NATURE_CALM,  NATURE_JOLLY  }
    },

    // Bugsy-R — Scizor(s0/ace), Shedinja(s1), Yanmega(s2), Pinsir(s3), Heracross(s4), Vespiquen(s5)
    { TRAINER_LEADER_BUGSY_BUGSY_2,
        { EV_PHYS_BULK,   EV_PHYS_FAST, EV_SPEC_FAST, EV_PHYS_BULK,   EV_PHYS_BULK,   EV_SPEC_TANK },
        { NATURE_ADAMANT, NATURE_JOLLY, NATURE_TIMID, NATURE_ADAMANT, NATURE_ADAMANT, NATURE_CALM  }
    },

    // Whitney-R — Girafarig(s0), Lickilicky(s1), Bibarel(s2), Delcatty(s3), Clefable(s4), Miltank(s5/ace)
    { TRAINER_LEADER_WHITNEY_2,
        { EV_SPEC_FAST, EV_SPEC_TANK, EV_PHYS_BULK,   EV_PHYS_FAST, EV_SPEC_BULK,   EV_PHYS_TANK  },
        { NATURE_TIMID, NATURE_CALM,  NATURE_ADAMANT, NATURE_JOLLY, NATURE_MODEST, NATURE_IMPISH }
    },

    // Morty-R — Drifblim(s0), Dusknoir(s1), Sableye(s2), Mismagius(s3), Gengar(s4), Gengar(s5/ace)
    { TRAINER_LEADER_MORTY_MORTY_2,
        { EV_SPEC_TANK, EV_PHYS_TANK,  EV_PHYS_TANK,  EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_FAST },
        { NATURE_CALM,  NATURE_IMPISH, NATURE_IMPISH, NATURE_TIMID, NATURE_TIMID, NATURE_TIMID  }
    },

    // Chuck-R — Medicham(s0), Hitmonchan(s1), Hitmonlee(s2), Breloom(s3), Primeape(s4), Poliwrath(s5/ace)
    { TRAINER_LEADER_CHUCK_CHUCK_2,
        { EV_PHYS_BULK,   EV_PHYS_BULK,   EV_PHYS_FAST, EV_PHYS_BULK,   EV_PHYS_FAST, EV_PHYS_BULK   },
        { NATURE_ADAMANT, NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT }
    },

    // Jasmine-R — Metagross(s0), Magnezone(s1), Skarmory(s2), Bronzong(s3), Empoleon(s4), Steelix(s5/ace)
    { TRAINER_LEADER_JASMINE_JASMINE_2,
        { EV_PHYS_BULK,   EV_SPEC_BULK,   EV_PHYS_TANK,  EV_SPEC_TANK, EV_SPEC_BULK,   EV_PHYS_TANK  },
        { NATURE_ADAMANT, NATURE_MODEST, NATURE_IMPISH, NATURE_CALM,  NATURE_MODEST, NATURE_IMPISH }
    },

    // Pryce-R — Abomasnow(s0), Dewgong(s1), Glalie(s2), Froslass(s3), Walrein(s4), Mamoswine(s5/ace)
    { TRAINER_LEADER_PRYCE_PRYCE_2,
        { EV_SPEC_BULK,   EV_SPEC_TANK, EV_PHYS_BULK,   EV_SPEC_FAST, EV_SPEC_TANK, EV_PHYS_BULK   },
        { NATURE_MODEST, NATURE_CALM,  NATURE_ADAMANT, NATURE_TIMID, NATURE_CALM,  NATURE_ADAMANT }
    },

    // Clair-R2 — Gyarados(s0), Dragonair(s1), Aerodactyl(s2), Kingdra(s3), Charizard(s4), Dragonite(s5/ace)
    { TRAINER_LEADER_CLAIR_CLAIR_2,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_BULK,   EV_SPEC_FAST, EV_PHYS_BULK   },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_JOLLY, NATURE_MODEST, NATURE_TIMID, NATURE_ADAMANT }
    },

    // Clair-R3 — Dragonair(s0), Kingdra(s1), Dragonite(s2/ace) — shorter rematch variant
    { TRAINER_LEADER_CLAIR_CLAIR_3,
        { EV_PHYS_FAST, EV_SPEC_BULK,   EV_PHYS_BULK,   EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_MODEST, NATURE_ADAMANT, N_,  N_,  N_  }
    },

    // =========================================================================
    // KANTO GYM LEADERS — first challenge
    // =========================================================================

    // Brock — Graveler(s0), Rhyhorn(s1), Omastar(s2), Onix(s3), Kabutops(s4/ace)
    { TRAINER_LEADER_BROCK_BROCK,
        { EV_PHYS_BULK,   EV_PHYS_BULK,   EV_SPEC_BULK,   EV_PHYS_TANK,  EV_PHYS_FAST, EV0 },
        { NATURE_ADAMANT, NATURE_ADAMANT, NATURE_MODEST, NATURE_IMPISH, NATURE_JOLLY, N_  }
    },

    // Misty — Golduck(s0), Quagsire(s1), Lapras(s2), Starmie(s3/ace)
    { TRAINER_LEADER_MISTY_MISTY,
        { EV_SPEC_FAST, EV_PHYS_TANK,  EV_SPEC_TANK, EV_SPEC_FAST, EV0, EV0 },
        { NATURE_TIMID, NATURE_IMPISH, NATURE_CALM,  NATURE_TIMID, N_,  N_  }
    },

    // Lt. Surge — Raichu(s0), Electrode(s1), Magneton(s2), Electrode(s3), Electabuzz(s4/ace)
    { TRAINER_LEADER_LT_SURGE_LT__SURGE,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_FAST, EV_SPEC_FAST, EV0 },
        { NATURE_TIMID, NATURE_TIMID, NATURE_MODEST, NATURE_TIMID, NATURE_TIMID,  N_  }
    },

    // Erika — Jumpluff(s0), Tangela(s1), Victreebel(s2), Bellossom(s3/ace)
    { TRAINER_LEADER_ERIKA_ERIKA,
        { EV_SPEC_FAST, EV_SPEC_TANK, EV_PHYS_BULK,   EV_SPEC_BULK,   EV0, EV0 },
        { NATURE_TIMID, NATURE_CALM,  NATURE_ADAMANT, NATURE_MODEST, N_,  N_  }
    },

    // Janine — Crobat(s0/ace), Weezing(s1), Ariados(s2), Ariados(s3), Venomoth(s4)
    { TRAINER_LEADER_JANINE_JANINE,
        { EV_PHYS_FAST, EV_PHYS_TANK, EV_PHYS_FAST, EV_PHYS_FAST, EV_SPEC_FAST, EV0 },
        { NATURE_JOLLY, NATURE_BOLD,  NATURE_JOLLY, NATURE_JOLLY, NATURE_TIMID,  N_  }
    },

    // Sabrina — Espeon(s0), MrMime(s1), Alakazam(s2/ace)
    { TRAINER_LEADER_SABRINA_SABRINA,
        { EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_FAST, EV0, EV0, EV0 },
        { NATURE_TIMID, NATURE_MODEST, NATURE_TIMID, N_,  N_,  N_  }
    },

    // Blaine — Magcargo(s0), Magmar(s1), Rapidash(s2/ace)
    { TRAINER_LEADER_BLAINE_BLAINE,
        { EV_SPEC_TANK, EV_SPEC_FAST, EV_PHYS_FAST, EV0, EV0, EV0 },
        { NATURE_CALM,  NATURE_TIMID, NATURE_JOLLY, N_,  N_,  N_  }
    },

    // Blue — Exeggutor(s0), Arcanine(s1), Rhydon(s2), Gyarados(s3), Machamp(s4), Pidgeot(s5/ace)
    { TRAINER_LEADER_BLUE_BLUE,
        { EV_SPEC_BULK,   EV_PHYS_FAST, EV_PHYS_BULK,   EV_PHYS_FAST,  EV_PHYS_BULK,   EV_PHYS_FAST  },
        { NATURE_MODEST, NATURE_JOLLY, NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT, NATURE_JOLLY }
    },

    // =========================================================================
    // KANTO GYM LEADERS — rematches
    // =========================================================================

    // Brock-R — Golem(s0), Relicanth(s1), Omastar(s2), Onix(s3), Kabutops(s4), Rampardos(s5/ace)
    { TRAINER_LEADER_BROCK_BROCK_2,
        { EV_PHYS_BULK,   EV_PHYS_BULK,   EV_SPEC_BULK,   EV_PHYS_TANK,  EV_PHYS_FAST, EV_PHYS_BULK   },
        { NATURE_ADAMANT, NATURE_ADAMANT, NATURE_MODEST, NATURE_IMPISH, NATURE_JOLLY, NATURE_ADAMANT }
    },

    // Misty-R — Starmie(s0/ace), Quagsire(s1), Lapras(s2), Lanturn(s3), Floatzel(s4), Milotic(s5)
    { TRAINER_LEADER_MISTY_MISTY_2,
        { EV_SPEC_FAST, EV_PHYS_TANK,  EV_SPEC_TANK, EV_SPEC_TANK, EV_PHYS_FAST, EV_SPEC_TANK },
        { NATURE_TIMID, NATURE_IMPISH, NATURE_CALM,  NATURE_CALM,  NATURE_JOLLY, NATURE_CALM  }
    },

    // Lt. Surge-R — Raichu(s0), Manectric(s1), Magnezone(s2), Electrode(s3), Pachirisu(s4), Electivire(s5/ace)
    { TRAINER_LEADER_LT_SURGE_LT__SURGE_2,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_FAST, EV_PHYS_FAST, EV_PHYS_BULK   },
        { NATURE_TIMID, NATURE_TIMID, NATURE_MODEST, NATURE_TIMID, NATURE_JOLLY, NATURE_ADAMANT }
    },

    // Erika-R — Shiftry(s0), Jumpluff(s1), Victreebel(s2), Bellossom(s3), Tangrowth(s4), Roserade(s5/ace)
    { TRAINER_LEADER_ERIKA_ERIKA_2,
        { EV_PHYS_BULK,   EV_SPEC_FAST, EV_PHYS_BULK,   EV_SPEC_BULK,   EV_SPEC_TANK, EV_SPEC_FAST },
        { NATURE_ADAMANT, NATURE_TIMID, NATURE_ADAMANT, NATURE_MODEST, NATURE_CALM,  NATURE_TIMID }
    },

    // Janine-R — Crobat(s0), Weezing(s1), Toxicroak(s2), Ariados(s3), Venomoth(s4), Drapion(s5/ace)
    { TRAINER_LEADER_JANINE_JANINE_2,
        { EV_PHYS_FAST, EV_PHYS_TANK, EV_PHYS_BULK,   EV_PHYS_FAST, EV_SPEC_FAST, EV_PHYS_BULK   },
        { NATURE_JOLLY, NATURE_BOLD,  NATURE_ADAMANT, NATURE_JOLLY, NATURE_TIMID, NATURE_ADAMANT }
    },

    // Sabrina-R — Alakazam(s0/ace), Espeon(s1), MrMime(s2), Jynx(s3), Wobbuffet(s4), Gallade(s5)
    { TRAINER_LEADER_SABRINA_SABRINA_2,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_FAST, EV_SPEC_TANK, EV_PHYS_BULK   },
        { NATURE_TIMID, NATURE_TIMID, NATURE_MODEST, NATURE_TIMID, NATURE_CALM,  NATURE_ADAMANT }
    },

    // Blaine-R — Torkoal(s0), Camerupt(s1), Rapidash(s2), Magcargo(s3), Houndoom(s4), Magmortar(s5/ace)
    { TRAINER_LEADER_BLAINE_BLAINE_2,
        { EV_PHYS_TANK,  EV_SPEC_BULK,   EV_PHYS_FAST, EV_SPEC_TANK, EV_SPEC_FAST, EV_SPEC_BULK   },
        { NATURE_IMPISH, NATURE_MODEST, NATURE_JOLLY, NATURE_CALM,  NATURE_TIMID, NATURE_MODEST }
    },

    // Blue-R — Exeggutor(s0), Machamp(s1), Rhyperior(s2), Arcanine(s3), Tyranitar(s4), Pidgeot(s5/ace)
    { TRAINER_LEADER_BLUE_BLUE_2,
        { EV_SPEC_BULK,   EV_PHYS_BULK,   EV_PHYS_BULK,   EV_PHYS_FAST, EV_PHYS_BULK,   EV_PHYS_FAST  },
        { NATURE_MODEST, NATURE_ADAMANT, NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT, NATURE_JOLLY }
    },

    // =========================================================================
    // ELITE FOUR & CHAMPION — first challenge
    // =========================================================================

    // Will — Xatu(s0), Jynx(s1), Exeggutor(s2), Slowbro(s3), Xatu(s4)
    { TRAINER_ELITE_FOUR_WILL_WILL,
        { EV_SPEC_FAST, EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_TANK, EV_SPEC_FAST, EV0 },
        { NATURE_TIMID, NATURE_TIMID, NATURE_MODEST, NATURE_CALM,  NATURE_TIMID, N_  }
    },

    // Koga — Ariados(s0), Venomoth(s1), Forretress(s2), Muk(s3), Crobat(s4)
    { TRAINER_ELITE_FOUR_KOGA_KOGA,
        { EV_PHYS_FAST, EV_SPEC_FAST, EV_PHYS_TANK,  EV_PHYS_BULK,   EV_PHYS_FAST, EV0 },
        { NATURE_JOLLY, NATURE_TIMID, NATURE_IMPISH, NATURE_ADAMANT, NATURE_JOLLY, N_  }
    },

    // Bruno — Hitmontop(s0), Hitmonlee(s1), Hitmonchan(s2), Onix(s3), Machamp(s4)
    { TRAINER_ELITE_FOUR_BRUNO_BRUNO,
        { EV_PHYS_BULK,   EV_PHYS_FAST,  EV_PHYS_BULK,   EV_PHYS_TANK,  EV_PHYS_BULK,   EV0 },
        { NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT, NATURE_IMPISH, NATURE_ADAMANT, N_  }
    },

    // Karen — Umbreon(s0), Vileplume(s1), Gengar(s2), Murkrow(s3), Houndoom(s4)
    { TRAINER_ELITE_FOUR_KAREN_KAREN,
        { EV_SPEC_TANK, EV_SPEC_BULK,   EV_SPEC_FAST,  EV_PHYS_FAST,  EV_SPEC_FAST,  EV0 },
        { NATURE_CALM,  NATURE_MODEST, NATURE_TIMID,  NATURE_JOLLY,  NATURE_TIMID,  N_  }
    },

    // Lance — Gyarados(s0), Dragonite(s1), Dragonite(s2), Aerodactyl(s3), Charizard(s4), Dragonite(s5/ace)
    // Lower Dragonites = Jolly; ace Dragonite = Adamant (nastier wallbreaking)
    { TRAINER_CHAMPION_LANCE,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_FAST,  EV_SPEC_FAST, EV_PHYS_FAST   },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_JOLLY, NATURE_JOLLY, NATURE_TIMID, NATURE_ADAMANT }
    },

    // =========================================================================
    // ELITE FOUR & CHAMPION — rematches
    // =========================================================================

    // Will-R — Bronzong(s0), Jynx(s1), Grumpig(s2), Slowbro(s3), Gardevoir(s4), Xatu(s5/ace)
    { TRAINER_ELITE_FOUR_WILL_WILL_2,
        { EV_SPEC_TANK, EV_SPEC_FAST, EV_SPEC_BULK,   EV_SPEC_TANK, EV_SPEC_FAST, EV_SPEC_FAST },
        { NATURE_CALM,  NATURE_TIMID, NATURE_MODEST, NATURE_CALM,  NATURE_TIMID, NATURE_TIMID  }
    },

    // Koga-R — Skuntank(s0), Venomoth(s1), Toxicroak(s2), Muk(s3), Crobat(s4/ace), Swalot(s5)
    { TRAINER_ELITE_FOUR_KOGA_KOGA_2,
        { EV_PHYS_BULK,   EV_SPEC_FAST, EV_PHYS_BULK,   EV_PHYS_BULK,   EV_PHYS_FAST, EV_SPEC_TANK },
        { NATURE_ADAMANT, NATURE_TIMID, NATURE_ADAMANT, NATURE_ADAMANT, NATURE_JOLLY, NATURE_CALM  }
    },

    // Bruno-R — Hitmontop(s0), Hitmonlee(s1), Hitmonchan(s2), Hariyama(s3), Machamp(s4), Lucario(s5/ace)
    { TRAINER_ELITE_FOUR_BRUNO_BRUNO_2,
        { EV_PHYS_BULK,   EV_PHYS_FAST, EV_PHYS_BULK,   EV_PHYS_TANK,  EV_PHYS_BULK,   EV_PHYS_BULK   },
        { NATURE_ADAMANT, NATURE_JOLLY, NATURE_ADAMANT, NATURE_IMPISH, NATURE_ADAMANT, NATURE_ADAMANT }
    },

    // Karen-R — Weavile(s0), Spiritomb(s1), Absol(s2), Honchkrow(s3), Houndoom(s4), Umbreon(s5/ace)
    { TRAINER_ELITE_FOUR_KAREN_KAREN_2,
        { EV_PHYS_FAST, EV_SPEC_TANK, EV_PHYS_BULK,   EV_PHYS_BULK,   EV_SPEC_FAST, EV_SPEC_TANK },
        { NATURE_JOLLY, NATURE_CALM,  NATURE_ADAMANT, NATURE_ADAMANT, NATURE_TIMID, NATURE_CALM  }
    },

    // Lance-R2 — Salamence(s0), Gyarados(s1), Garchomp(s2), Altaria(s3), Charizard(s4), Dragonite(s5/ace)
    { TRAINER_CHAMPION_LANCE_2,
        { EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_FAST, EV_PHYS_BULK,   EV_SPEC_FAST, EV_PHYS_BULK   },
        { NATURE_JOLLY, NATURE_JOLLY, NATURE_JOLLY, NATURE_ADAMANT, NATURE_TIMID, NATURE_ADAMANT }
    },

    // Lance-R3 — Gyarados(s0), Charizard(s1), Dragonite(s2/ace) — shorter rematch variant
    { TRAINER_CHAMPION_LANCE_3,
        { EV_PHYS_FAST, EV_SPEC_FAST, EV_PHYS_BULK,   EV0, EV0, EV0 },
        { NATURE_JOLLY, NATURE_TIMID, NATURE_ADAMANT, N_,  N_,  N_  }
    },

    // =========================================================================
    // RED — Mt. Silver
    // =========================================================================

    // Red — Pikachu(s0), Lapras(s1), Snorlax(s2), Venusaur(s3), Charizard(s4), Blastoise(s5)
    { TRAINER_PKMN_TRAINER_RED_RED,
        { EV_SPEC_FAST, EV_SPEC_TANK, EV_PHYS_TANK,  EV_SPEC_BULK,   EV_SPEC_FAST, EV_SPEC_TANK },
        { NATURE_TIMID, NATURE_CALM,  NATURE_IMPISH, NATURE_MODEST, NATURE_TIMID, NATURE_CALM  }
    },
};

#define TRAINER_EV_TABLE_SIZE (sizeof(sTrainerEVTable) / sizeof(sTrainerEVTable[0]))

const TrainerEVEntry *TrainerEV_GetEntry(u16 trainerId) {
    int i;
    for (i = 0; i < (int)TRAINER_EV_TABLE_SIZE; i++) {
        if (sTrainerEVTable[i].trainerId == trainerId) {
            return &sTrainerEVTable[i];
        }
    }
    return NULL;
}
