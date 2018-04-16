#ifndef RIVERGATEPLAYER_H_
#define RIVERGATEPLAYER_H_

#include "Rivergates.h"

enum RivergateStat
{
    HP, MP, STAMINA
};

struct RivergatePlayer
{
    pos pos;
    char repr;
    RG *gears[MAXITEMLEN];
    int hp;
    int mp;
    int stamina;
    char name[16];

    struct RivergateThoughts
    {
        int x;
        int y;
        int direction;
        RP *rps;
        int rpLen;
        RG *gear;
    } thoughts;
};

RP produceRPNothing();

pos RP_getDirectionPos(RP *rp);

RE* RP_useGear(RP *rp, int index, RE *events);

void RP_damage(RP *dealer, RP *victim, RG *gear);

void RP_setName(RP* rp, char* name);

void RP_remove(RStat stat, RP* rp, int v);

bool RP_check(RStat stat, RP* rp, int v);

bool RP_checkAndRemove(RStat stat, RP* rp, int v);

#endif