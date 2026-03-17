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
// Slot indices match party order (0 = first Pokemon, etc.).
// Entries for trainers not listed here are never looked up.
static const TrainerEVEntry sTrainerEVTable[] = {
    // -------------------------------------------------------------------------
    // RIVAL (Silver) — all story battles
    // Battle 1 = New Bark (starter only); Battle 2 = Cherrygrove; Battle 3 = Burned Tower
    // Battle 4 = Goldenrod; Battle 5 = Mt. Mortar; Battle 6 = Kanto; Postgame = rematch
    // Three variants per battle (one per player starter choice).
    // -------------------------------------------------------------------------

    // Battle 1 — New Bark Town (starter only, no EVs)
    { TRAINER_RIVAL_SILVER_2,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Cyndaquil
    { TRAINER_RIVAL_SILVER_3,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Totodile
    { TRAINER_RIVAL_SILVER_6,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Chikorita

    // Battle 2 — Cherrygrove (s0=Gastly, s1=Zubat, s2=Starter ace)
    { TRAINER_RIVAL_SILVER,    { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Bayleef ace
    { TRAINER_RIVAL_SILVER_7,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Quilava ace
    { TRAINER_RIVAL_SILVER_10, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Croconaw ace

    // Battle 3 — Burned Tower (s0=Gastly, s1=Magnemite, s2=Zubat, s3=Starter ace)
    { TRAINER_RIVAL_SILVER_4,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Bayleef ace
    { TRAINER_RIVAL_SILVER_8,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Quilava ace
    { TRAINER_RIVAL_SILVER_11, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Croconaw ace

    // Battle 4 — Goldenrod (s0=Golbat, s1=Magnemite, s2=Haunter, s3=Sneasel, s4=Starter ace)
    { TRAINER_RIVAL_SILVER_17, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Meganium ace
    { TRAINER_RIVAL_SILVER_18, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Quilava ace
    { TRAINER_RIVAL_SILVER_12, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Feraligatr ace

    // Battle 5 — Mt. Mortar (s0=Sneasel, s1=Golbat, s2=Magneton, s3=Haunter, s4=Kadabra, s5=Starter ace)
    { TRAINER_RIVAL_SILVER_5,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Meganium ace
    { TRAINER_RIVAL_SILVER_9,  { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Typhlosion ace
    { TRAINER_RIVAL_SILVER_13, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Feraligatr ace

    // Battle 6 — Kanto (s0=Sneasel, s1=Golbat, s2=Magneton, s3=Gengar, s4=Alakazam, s5=Starter ace)
    { TRAINER_RIVAL_SILVER_14, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Chikorita player → Meganium ace
    { TRAINER_RIVAL_SILVER_15, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Cyndaquil player → Typhlosion ace
    { TRAINER_RIVAL_SILVER_16, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // Totodile player  → Feraligatr ace

    // Postgame rematch (s0=Sneasel, s1=Crobat, s2=Magneton, s3=Gengar, s4=Alakazam, s5=Starter ace)
    { TRAINER_RIVAL_SILVER_19, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // → Meganium ace
    { TRAINER_RIVAL_SILVER_20, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // → Typhlosion ace
    { TRAINER_RIVAL_SILVER_21, { EV0, EV0, EV0, EV0, EV0, EV0 } }, // → Feraligatr ace

    // -------------------------------------------------------------------------
    // JOHTO GYM LEADERS
    // -------------------------------------------------------------------------
    // Pidgey, Pidgeotto(ace)
    { TRAINER_LEADER_FALKNER_FALKNER,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Scyther(slot 0/ace), Kakuna, Metapod
    { TRAINER_LEADER_BUGSY_BUGSY,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Clefairy, Miltank(ace)
    { TRAINER_LEADER_WHITNEY,           { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Gastly, Haunter, Gengar(slot 2/ace), Haunter
    { TRAINER_LEADER_MORTY_MORTY,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Primeape, Poliwrath(ace)
    { TRAINER_LEADER_CHUCK_CHUCK,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Magnemite, Magnemite, Steelix(ace)
    { TRAINER_LEADER_JASMINE_JASMINE,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Seel, Dewgong, Piloswine(ace)
    { TRAINER_LEADER_PRYCE_PRYCE,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Gyarados, Dragonair, Dragonair, Kingdra(ace)
    { TRAINER_LEADER_CLAIR_CLAIR,       { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // JOHTO GYM LEADERS — rematches
    // -------------------------------------------------------------------------
    { TRAINER_LEADER_FALKNER_FALKNER_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BUGSY_BUGSY_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_WHITNEY_2,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_MORTY_MORTY_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_CHUCK_CHUCK_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_JASMINE_JASMINE_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_PRYCE_PRYCE_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_CLAIR_CLAIR_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_CLAIR_CLAIR_3,     { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // KANTO GYM LEADERS
    // -------------------------------------------------------------------------
    { TRAINER_LEADER_BROCK_BROCK,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_MISTY_MISTY,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_LT_SURGE_LT__SURGE,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_ERIKA_ERIKA,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_JANINE_JANINE,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_SABRINA_SABRINA,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BLAINE_BLAINE,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BLUE_BLUE,           { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // KANTO GYM LEADERS — rematches
    // -------------------------------------------------------------------------
    { TRAINER_LEADER_BROCK_BROCK_2,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_MISTY_MISTY_2,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_LT_SURGE_LT__SURGE_2,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_ERIKA_ERIKA_2,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_JANINE_JANINE_2,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_SABRINA_SABRINA_2,     { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BLAINE_BLAINE_2,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BLUE_BLUE_2,           { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // ELITE FOUR & CHAMPION — first challenge
    // -------------------------------------------------------------------------
    // Xatu, Jynx, Exeggutor, Slowbro, Xatu
    { TRAINER_ELITE_FOUR_WILL_WILL,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Ariados, Venomoth, Forretress, Muk, Crobat
    { TRAINER_ELITE_FOUR_KOGA_KOGA,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Hitmontop, Hitmonlee, Hitmonchan, Onix, Machamp
    { TRAINER_ELITE_FOUR_BRUNO_BRUNO, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Umbreon, Vileplume, Gengar(s2), Murkrow(s3), Houndoom
    { TRAINER_ELITE_FOUR_KAREN_KAREN, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Gyarados, Dragonite, Dragonite, Aerodactyl, Charizard, Dragonite
    { TRAINER_CHAMPION_LANCE,         { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // ELITE FOUR & CHAMPION — rematches
    // -------------------------------------------------------------------------
    { TRAINER_ELITE_FOUR_WILL_WILL_2,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_KOGA_KOGA_2,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_BRUNO_BRUNO_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_KAREN_KAREN_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_CHAMPION_LANCE_2,         { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_CHAMPION_LANCE_3,         { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // Lance encountered as a trainer (Dragon's Den / story)
    { TRAINER_PKMN_TRAINER_LANCE_LANCE, { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // RED — Mt. Silver
    // -------------------------------------------------------------------------
    { TRAINER_PKMN_TRAINER_RED_RED, { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // TEAM ROCKET EXECUTIVES
    // Proton: Slowpoke Well (#1), Radio Tower (#2)
    // Petrel: Mahogany Hideout (#1), Radio Tower (#2)
    // Ariana: Mahogany Hideout (#1), Goldenrod Underground (#2)
    // Archer: Goldenrod Radio Tower
    // -------------------------------------------------------------------------
    // Slowpoke Well — Zubat, Koffing (early, no EVs)
    { TRAINER_EXECUTIVE_PROTON_PROTON,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Radio Tower — Golbat(ace), Weezing(ace)
    { TRAINER_EXECUTIVE_PROTON_PROTON_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Mahogany Hideout — Zubat, Raticate(ace s1), Koffing
    { TRAINER_EXECUTIVE_PETREL_PETREL,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Radio Tower — Koffing×5, Weezing(ace s3)
    { TRAINER_EXECUTIVE_PETREL_PETREL_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Mahogany Hideout — Arbok, Gloom, Murkrow (mid, full team)
    { TRAINER_EXECUTIVE_ARIANA_ARIANA,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Goldenrod Underground — Arbok, Vileplume, Murkrow (late, full team)
    { TRAINER_EXECUTIVE_ARIANA_ARIANA_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    // Radio Tower — Houndour, Koffing, Houndoom(ace)
    { TRAINER_EXECUTIVE_ARCHER_ARCHER,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
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
