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

RT *RS_getRT(RS *rs, int x, int y);

RP *RS_getRPIndex(RS *rs, int i);

RP *RS_getRPPos(RS *rs, int x, int y);

char RS_getMapRepr(RS *rs, int x, int y);

#endif