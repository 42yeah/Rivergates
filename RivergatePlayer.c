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
    rpNothing.hp = DEFHP;
    rpNothing.mp = DEFMP;
    rpNothing.stamina = DEFSTA;
    
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
        RE *event = RE_create(rp, CHOP, NULL, 0);
        events = RE_attach(events, event);
    }

    return events;
}

pos RP_getDirectionPos(RP *rp)
{
    pos p = rp->pos;
	switch (rp->thoughts.direction)
    {
    case U:
        p.y--;
        break;

    case UR:
        p.y--;
        p.x++;
        break;

    case R:
        p.x++;
        break;

    case DR:
        p.x++;
        p.y++;
        break;

    case D:
        p.y++;
        break;

    case DL:
        p.y++;
        p.x--;
        break;

    case L:
        p.x--;
        break;

    case UL:
        p.y--;
        p.x--;
        break;

    default:
        break;
    }

    return p;
}
