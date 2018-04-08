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