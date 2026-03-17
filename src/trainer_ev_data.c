#include "trainer_ev_data.h"

#include "constants/trainers.h"

// Shorthand for a slot with no EVs
#define EV0 {0, 0, 0, 0, 0, 0}

// EV table for boss trainers.
// Slot indices match party order (0 = first Pokemon, etc.).
// Entries for trainers not listed here are never looked up.
// All values start at 0 and should be filled in once the system is verified.
static const TrainerEVEntry sTrainerEVTable[] = {
    // -------------------------------------------------------------------------
    // RIVAL (Silver) — all story battles
    // -------------------------------------------------------------------------
    { TRAINER_RIVAL_SILVER,    { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_2,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_3,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_4,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_5,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_6,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_7,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_8,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_9,  { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_10, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_11, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_12, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_13, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_14, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_15, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_16, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_17, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_18, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_19, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_20, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_RIVAL_SILVER_21, { EV0, EV0, EV0, EV0, EV0, EV0 } },

    // -------------------------------------------------------------------------
    // JOHTO GYM LEADERS
    // -------------------------------------------------------------------------
    { TRAINER_LEADER_FALKNER_FALKNER,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_BUGSY_BUGSY,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_WHITNEY,           { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_MORTY_MORTY,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_CHUCK_CHUCK,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_JASMINE_JASMINE,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_LEADER_PRYCE_PRYCE,       { EV0, EV0, EV0, EV0, EV0, EV0 } },
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
    { TRAINER_ELITE_FOUR_WILL_WILL,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_KOGA_KOGA,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_BRUNO_BRUNO, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_ELITE_FOUR_KAREN_KAREN, { EV0, EV0, EV0, EV0, EV0, EV0 } },
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
    { TRAINER_EXECUTIVE_PROTON_PROTON,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_EXECUTIVE_PROTON_PROTON_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_EXECUTIVE_PETREL_PETREL,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_EXECUTIVE_PETREL_PETREL_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_EXECUTIVE_ARIANA_ARIANA,   { EV0, EV0, EV0, EV0, EV0, EV0 } },
    { TRAINER_EXECUTIVE_ARIANA_ARIANA_2, { EV0, EV0, EV0, EV0, EV0, EV0 } },
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
