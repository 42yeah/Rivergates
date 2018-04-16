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
    strcpy(rpNothing.name, "Player");
    
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

    rp->thoughts.gear = gear;

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

void RP_damage(RP *dealer, RP *rp, RG *gear)
{ 
    rp->hp -= gear->dmg;
}

void RP_setName(RP* rp, char* name)
{
    strcpy(rp->name, name);
}

void RP_remove(RStat stat, RP* rp, int v)
{
    switch (stat)
    {
    case HP:
        rp->hp -= v;
        break;

    case MP:
        rp->mp -= v;
        break;

    case STAMINA:
        rp->stamina -= v;
        break;
    }
}

bool RP_check(RStat stat, RP* rp, int v)
{
    switch (stat)
    {
    case HP:
        if (rp->hp >= v)
        {
            return TRUE;
        }
        break;

    case MP:
        if (rp->mp >= v)
        {
            return TRUE;
        }
        break;

    case STAMINA:
        if (rp->stamina >= v)
        {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool RP_checkAndRemove(RStat stat, RP* rp, int v)
{
    if (RP_check(stat, rp, v))
    {
        RP_remove(stat, rp, v);
        return TRUE;
    }
    return FALSE;
}