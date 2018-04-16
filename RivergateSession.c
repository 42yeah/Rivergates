#include "Rivergates.h"

void announce(RS* rs, char* msg)
{
    RO *observer = rs->observers;
    
    while (observer)
    {
        observer->message(msg);
        observer = observer->next;
    }
}

// Create a new RivergateSession instance.
RS *RS_create()
{
    RS *rs;
    rs = malloc(sizeof(RS));
    rs->map = malloc(0);
    rs->mapLen = 0;
    rs->rps = malloc(0);
    rs->rpLen = 0;
    rs->observers = NULL;

    for (int y = 0; y < MAPH; y++)
    {
        for (int x = 0; x < MAPW; x++)
        {
            RT rt = produceRTNothing();
            rt.repr = '.';
            rt.pos = cpos(x, y);
            RS_pushRT(rs, rt);
        }
    }

    return rs;
}

// Get the terrain; if blank, create it.
RT* RS_getRT(RS* rs, pos p)
{
    for (int i = 0; i < rs->mapLen; i++)
    {
    	
    	// TODO: give chunk POS! 
        if (pos_pequals(rs->map[i].pos, p))
        {
            return &(rs->map[i]);
        }
    }
    // Not found! Create it.
    RT rt = produceRTNothing();
    rt.pos = p;
    RS_pushRT(rs, rt);
    return &(rs->map[rs->mapLen - 1]);
}

// Get the map's repr.
char RS_getMapRepr(RS *rs, pos p)
{
    for (int i = 0; i < rs->rpLen; i++)
    {
        if (pos_pequals(rs->rps[i].pos, p))
        {
            return rs->rps[i].repr;
        }
    }

    return RS_getRT(rs, p)->repr;
}

// Push back a new terrain.
void RS_pushRT(RS* rs, RT rt)
{
    RT *mem = malloc(sizeof(RT) * (rs->mapLen + 1));
    memcpy(mem, rs->map, sizeof(RT) * rs->mapLen);
    mem[rs->mapLen] = rt;
    rs->mapLen++;
    rs->map = mem;
}

// Push back a new player.
void RS_pushRP(RS* rs, RP rp)
{
    RP *mem = malloc(sizeof(RP) * (rs->rpLen + 1));
    memcpy(mem, rs->rps, sizeof(RP) * rs->rpLen);
    free(rs->rps);
    mem[rs->rpLen] = rp;
    rs->rpLen++;
    rs->rps = mem;
}

// Return the player based on index.
RP* RS_getRPIndex(RS* rs, int i)
{
	if (i < 0 && i >= rs->rpLen)
    {
        return NULL;
    }
    return &(rs->rps[i]);
}

// Return the player based on position.
RP *RS_getRPPos(RS *rs, pos p)
{
    for (int i = 0; i < rs->rpLen; i++)
    {
        if (pos_pequals(rs->rps[i].pos, p))
        {
            return &(rs->rps[i]);
        }
    }

    return NULL;
}

void RS_processRE(RS *rs, RE *re)
{
    char msg[256];
	while (re)
    {
        RET type = re->type;
        pos p;
        RP *affected;
        RP *player = re->player;
        
        switch (type)
        {
        case WALK:
            p = RP_getDirectionPos(re->player);
            if (!RS_getRPPos(rs, p))
            {
                player->pos = p;
                sprintf(msg, "Player %s moved to (%d, %d)", player->name,
                        player->pos.x, player->pos.y);
                announce(rs, msg);
            }
            // BLOCKED
            else
            {
                sprintf(msg, "Player %s tried to walk, but is blocked...",
                        player->name);
                announce(rs, msg);
            }
            break;

        case CHOP:
            affected = RS_getRPPos(
                rs,
                pos_getAffectedPos(player->pos, player->thoughts.direction, 1));
            if (affected)
            {
                RP_damage(player, affected, player->thoughts.gear);
                sprintf(msg, "Player %s chopped player %s!\n", re->player->name,
                        affected->name);
                announce(rs, msg);
            }
            else
            {
                sprintf(msg, "Player %s chopped through thin air.\n",
                        re->player->name);
                announce(rs, msg);
            }
            break;
            
        case STAB:
        	affected = RS_getRPPos(
                rs,
                pos_getAffectedPos(player->pos, player->thoughts.direction, 1));
            if (affected)
            {
                RP_damage(player, affected, player->thoughts.gear);
                sprintf(msg, "Player %c stabbed player %c!\n", re->player->repr,
                        affected->repr);
                announce(rs, msg);
            }
            else
            {
                sprintf(msg, "Player %c stabbed through thin air.\n",
                        re->player->repr);
                announce(rs, msg);
            }
            break;
        }
        
        re = re->next;
    }
}