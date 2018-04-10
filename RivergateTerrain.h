#ifndef RIVERGATETERRAIN_H_
#define RIVERGATETERRAIN_H_

#include "Rivergates.h"

struct RivergateTerrain
{
    pos pos;
    char repr;
    bool passable;
};

RT produceRTNothing();

#endif