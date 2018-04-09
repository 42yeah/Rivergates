#include <stdio.h>
#include <stdlib.h>
#include "Rivergates.h"

int main() 
{
    ////////////////////////////////////
    // Map test
    ////////////////////////////////////
    RS *rs = RS_create();
    RS_pushRP(rs, produceRPNothing());
    for (int y = 0; y < MAPH; y++)
    {
        for (int x = 0; x < MAPW; x++)
        {
            printf("%c", RS_getMapRepr(rs, x, y));
        }
        printf("\n");
    }

    ////////////////////////////////////
    // Gear test
    ////////////////////////////////////
    RS_getRPIndex(rs, 0)->gears[0] = RG_getGear(SWORD);
    for (int i = 0; i < MAXITEMLEN; i++)
    {
        printf("%s\n", RS_getRPIndex(rs, 0)->gears[i]->name);
    }
    
    ////////////////////////////////////
    // Event test
    ////////////////////////////////////
    RE *re = RE_create(NULL, WALK, NULL, 0, 3, 2);
    RE *re1 = RE_create(NULL, CHOP, NULL, 0, 1, 2);
    re = RP_useGear(RS_getRPIndex(rs, 0), 0, re);
    re = RP_useGear(RS_getRPIndex(rs, 0), 0, re);
    while (re)
    {
        printf("%d %d\n", re->x, re->y);
        re = re->next;
    }

    return 0;
};