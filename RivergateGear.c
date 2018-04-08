#include "RivergateGear.h"

#include <string.h>

RG* RG_create(char* name, int dmg, int stac, int mpc, int hpc)
{
    RG *rg = malloc(sizeof(RG));
    strcpy(rg->name, name);
    rg->dmg = dmg;
    rg->staminaCost = stac;
    rg->magicCost = mpc;
    rg->hpCost = hpc;

    return rg;
}

RG* RG_clone(RG* rg)
{
    RG *mem = malloc(sizeof(RG));
    memcpy(mem, rg, sizeof(RG));

    return mem;
}

RG *produceRGNothing()
{
    RG *rg = malloc(sizeof(RG));
    strcpy(rg->name, "None");
    rg->dmg = 0;
    rg->staminaCost = 0;
    rg->magicCost = 0;
    rg->hpCost = 0;

    return rg;
}
