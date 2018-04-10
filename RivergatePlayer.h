#ifndef RIVERGATEPLAYER_H_
#define RIVERGATEPLAYER_H_

#include "Rivergates.h"

struct RivergatePlayer
{
    pos pos;
    char repr;
    RG *gears[MAXITEMLEN];
    
    struct RivergateThoughts
    {
        int x;
        int y;
        int direction;
        RP *rps;
        int rpLen;
    } thoughts;
};

RP produceRPNothing();

pos RP_getDirectionPos(RP *rp);

RE* RP_useGear(RP *rp, int index, RE *events);

#endif