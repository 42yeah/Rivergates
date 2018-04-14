#ifndef RIVERGATEPOS_H_
#define RIVERGATEPOS_H_

#include "Rivergates.h"

struct RivergatePos
{
    int x;
    int y;
};

bool pos_pequals(pos a, pos b);

pos cpos(int x, int y);

pos pos_getAffectedPos(pos p, enum Direction d, int x);

#endif