#ifndef RIVERGATESESSION_H_
#define RIVERGATESESSION_H_

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

char RS_getMapRepr(RS *rs, int x, int y);

#endif
