#ifndef RIVERGATEGEAR_H_
#define RIVERGATEGEAR_H_

#include "Rivergates.h"

enum RivergateGearID
{
    NOTHING = -1,
    SWORD = 0,
    DAGGER,
    GEARLEN
};

struct RivergateGear
{
    char name[MAXLEN];
    int dmg;
    int staminaCost;
    int magicCost;
    int hpCost;
    int id;
    int amount;
};

RG* RG_create(int id, char* name, int dmg, int stac, int mpc, int hpc, int amount);

RG *RG_clone(RG *rg);

RG *produceRGNothing();

RG *RG_getGear(int id);

void RG_modifyGear(RG *rg, int id, char *name, int stac, int mpc, int hpc,
                   int dmg, int amount);

#endif