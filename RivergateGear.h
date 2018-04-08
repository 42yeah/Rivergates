#ifndef RIVERGATEGEAR_H_
#define RIVERGATEGEAR_H_

#include "Rivergates.h"

enum RivergateGearID
{
    NOTHING = -1,
    SWORD = 0
};

struct RivergateGear
{
    char name[MAXLEN];
    int dmg;
    int staminaCost;
    int magicCost;
    int hpCost;
    int id;
};

RG* RG_create(int id, char* name, int dmg, int stac, int mpc, int hpc);

RG *RG_clone(RG *rg);

RG *produceRGNothing();

RG *RG_getGear(int id);

#endif