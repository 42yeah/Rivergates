#ifndef RIVERGATESESSION_H_
#define RIVERGATESESSION_H_

#include "Rivergates.h"

struct RivergateSession
{
    RT *map;
    int mapLen;
    RP *rps;
    int rpLen;
};

void RS_pushRT(RS *rs, RT rt);

void RS_pushRP(RS *rs, RP rp);

RS *RS_create();

RT *RS_getRT(RS *rs, pos p);

RP *RS_getRPIndex(RS *rs, int i);

RP *RS_getRPPos(RS *rs, pos p);

char RS_getMapRepr(RS *rs, pos p);

#endif