#include "Rivergates.h"

RP produceRPNothing()
{
    RP rpNothing;
    rpNothing.pos.x = 0;
    rpNothing.pos.y = 0;
    for (int i = 0; i < MAXITEMLEN; i++)
    {
        rpNothing.gears[i] = produceRGNothing();
    }
    rpNothing.thoughts.x = 0;
    rpNothing.thoughts.y = 0;
    rpNothing.thoughts.rps = NULL;
    rpNothing.thoughts.direction = 0;
    rpNothing.thoughts.rpLen = 0;
    rpNothing.repr = '@';
    
    return rpNothing;
}

RE* RP_useGear(RP *rp, int index, RE *events)
{
    RG *gear = rp->gears[index];
    if (gear->id == SWORD)
    {
        // TODO: x and y
        RE *event = RE_create(rp, CHOP, NULL, 0, 0, 0);
        events = RE_attach(events, event);
    }

    return events;
}
