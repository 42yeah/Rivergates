#ifndef RIVERGATETERRAIN_H_
#define RIVERGATETERRAIN_H_

#include "Rivergates.h"

struct RivergateTerrain
{
    int x;
    int y;
    char repr;
    bool passable;
};

RT produceRTNothing();

#endif