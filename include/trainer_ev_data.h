#ifndef POKEHEARTGOLD_TRAINER_EV_DATA_H
#define POKEHEARTGOLD_TRAINER_EV_DATA_H

#ifndef PM_ASM
#include "global.h"

#define TRAINER_EV_PARTY_SIZE 6

typedef struct {
    u8 hp;
    u8 atk;
    u8 def;
    u8 spe;
    u8 spa;
    u8 spd;
} TrainerMonEVs;

typedef struct {
    u16 trainerId;
    TrainerMonEVs monEvs[TRAINER_EV_PARTY_SIZE];
} TrainerEVEntry;

const TrainerEVEntry *TrainerEV_GetEntry(u16 trainerId);
#endif // PM_ASM

#endif // POKEHEARTGOLD_TRAINER_EV_DATA_H
