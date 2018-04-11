#include <stdio.h>
#include <stdlib.h>
#include "Rivergates.h"

void message(char *text) { printf("MESSAGE: %s\n", text); }

void printMap(RS* rs)
{
	for (int y = 0; y < MAPH; y++)
    {
        for (int x = 0; x < MAPW; x++)
        {
            printf("%c", RS_getMapRepr(rs, cpos(x, y)));
        }
        printf("\n");
    }
}

RE *appendEvent(RE* re, char *op, RS* rs, int i) 
{
    bool isMove = TRUE;
    
	switch (op[0])
    {
    case 'k':
        RS_getRPIndex(rs, i)->thoughts.direction = U;
        break;

    case 'u':
        RS_getRPIndex(rs, i)->thoughts.direction = UR;
        break;

    case 'l':
        RS_getRPIndex(rs, i)->thoughts.direction = R;
        break;

    case 'n':
        RS_getRPIndex(rs, i)->thoughts.direction = DR;
        break;

    case 'j':
        RS_getRPIndex(rs, i)->thoughts.direction = D;
        break;

    case 'b':
        RS_getRPIndex(rs, i)->thoughts.direction = DL;
        break;

    case 'h':
        RS_getRPIndex(rs, i)->thoughts.direction = L;
        break;

    case 'y':
        RS_getRPIndex(rs, i)->thoughts.direction = UL;
        break;
        
    default:
        isMove = FALSE;
    }
    
	if (isMove)
	{
        RE *moveEvent = RE_create(RS_getRPIndex(rs, i), WALK, NULL, 0);
        if (!re)
        {
            return moveEvent;
        }
        else
        {
            re = RE_attach(re, moveEvent);
        }
    }
    return re;
}

int main() 
{
    ////////////////////////////////////
    // Map test
    ////////////////////////////////////
    RS *rs = RS_create();
    RS_pushRP(rs, produceRPNothing());
    RS_pushRP(rs, produceRPNothing());
    RS_getRPIndex(rs, 1)->pos.x = 9;
    RS_getRPIndex(rs, 1)->pos.y = 9;
    RO* observer = RO_create();
    observer->message = &message;
    rs->observers = RO_append(rs->observers, observer);

    for (int i = 0; i < rs->rpLen; i++)
    {
    	for (int j = 0; j < GEARLEN; j++)
        {
            printf("%d. %s\n", j + 1, RG_getGear(j)->name);
        }
        printf("CHOOSE GEAR PLAYER %d\n", i + 1);
    	for (int j = 0; j < MAXITEMLEN; j++)
   	 {
    	    int in;
    	    scanf("%d", &in);
            in--;
            RS_getRPIndex(rs, i)->gears[j] = RG_getGear(in);
            printf("You chose %s.\n", RS_getRPIndex(rs, i)->gears[j]->name);
   	 }
    }

	while (TRUE)
	{
        RE *events = NULL;
        for (int i = 0; i < rs->rpLen; i++)
        {
            char op[256] = {0};
            printMap(rs);
            scanf("%s", op);
            events = appendEvent(events, op, rs, i);
        }
        RS_processRE(rs, events);
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
    RE *re = RE_create(NULL, WALK, NULL, 0);
    RE *re1 = RE_create(NULL, CHOP, NULL, 0);
    re = RP_useGear(RS_getRPIndex(rs, 0), 0, re);
    re = RP_useGear(RS_getRPIndex(rs, 0), 0, re);

    return 0;
};