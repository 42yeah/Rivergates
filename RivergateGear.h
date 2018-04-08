#ifndef RIVERGATEGEAR_H_
#define RIVERGATEGEAR_H_

#include "Rivergates.h"

struct RivergateGear
{
    char name[MAXLEN];
    int dmg;
    int staminaCost;
    int magicCost;
    int hpCost;
};

RG* RG_create(char* name, int dmg, int stac, int mpc, int hpc);

RG *RG_clone(RG *rg);

RG *produceRGNothing();

#endif