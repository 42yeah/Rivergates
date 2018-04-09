#ifndef RIVERGATEPLAYER_H_
#define RIVERGATEPLAYER_H_

#include "Rivergates.h"

struct RivergatePlayer
{
    int x;
    int y;
    char repr;
    RG *gears[MAXITEMLEN];
};

RP produceRPNothing();

RE* RP_useGear(RP *rp, int index, RE *events);

#endif