#include "Rivergates.h"

RP produceRPNothing()
{
    RP rpNothing;
    rpNothing.x = 0;
    rpNothing.y = 0;
    for (int i = 0; i < MAXITEMLEN; i++)
    {
        rpNothing.gears[i] = produceRGNothing();
    }
    rpNothing.repr = '@';
    
    return rpNothing;
}

void RP_useGear(RP *rp, int index, RE *events)
{
    RG *gear = rp->gears[index];
    if (gear->id == SWORD)
    {
        // TODO: x and y
        RE *event = RE_create(rp, CHOP, NULL, 0, 0, 0);
        RE_attach(events, event);
    }
    
}
