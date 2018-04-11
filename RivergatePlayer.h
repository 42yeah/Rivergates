#ifndef RIVERGATEPLAYER_H_
#define RIVERGATEPLAYER_H_

#include "Rivergates.h"

struct RivergatePlayer
{
    pos pos;
    char repr;
    RG *gears[MAXITEMLEN];
    int hp;
    int mp;
    int stamina;
    
    struct RivergateThoughts
    {
        int x;
        int y;
        int direction;
        RP *rps;
        int rpLen;
        RG *gear;
    } thoughts;
};

RP produceRPNothing();

pos RP_getDirectionPos(RP *rp);

RE* RP_useGear(RP *rp, int index, RE *events);

void RP_damage(RP *dealer, RP *victim, RG *gear);

#endif