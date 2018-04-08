#include "RivergateGear.h"

#include <string.h>

RG* RG_create(int id, char* name, int dmg, int stac, int mpc, int hpc)
{
    RG *rg = malloc(sizeof(RG));
    strcpy(rg->name, name);
    rg->dmg = dmg;
    rg->staminaCost = stac;
    rg->magicCost = mpc;
    rg->hpCost = hpc;
    rg->id = id;

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

void RG_modifyGear(RG* rg, char* name, int stac, int mpc, int hpc, int dmg)
{
    strcpy(rg->name, name);
    rg->staminaCost = stac;
    rg->magicCost = mpc;
    rg->hpCost = hpc;
    rg->dmg = dmg;
}

RG *RG_getGear(int id) {
    RG *rg = produceRGNothing();
    
    switch (id)
    {
    case NOTHING:
        break;

    case SWORD:
        RG_modifyGear(rg, "Sword", 30, 0, 0, 35);
        break;

    default:
        break;
    }

    return rg;
}
