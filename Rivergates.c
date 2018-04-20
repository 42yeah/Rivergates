#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void askDirection(RP* rp)
{
    printf("Direction: ");
    char op[8];
    scanf("%s", op);
    int thd;
    switch (op[0])
    {
    case 'k':
        rp->thoughts.direction = U;
        break;

    case 'u':
        rp->thoughts.direction = UR;
        break;

    case 'l':
        rp->thoughts.direction = R;
        break;

    case 'n':
        rp->thoughts.direction = DR;
        break;

    case 'j':
        rp->thoughts.direction = D;
        break;

    case 'b':
        rp->thoughts.direction = DL;
        break;

    case 'h':
        rp->thoughts.direction = L;
        break;

    case 'y':
        rp->thoughts.direction = UL;
        break;

    default:
        printf("Unknown direction. Treats as the direction last time\n");
        break;
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

    bool gearUsed = FALSE;
    if (op[0] >= '1' && op[0] <= '5')
    {
        int action = atoi(op);
        action--;
        
        if (action >= 0 && action <= MAXITEMLEN && RS_getRPIndex(rs, i)->gears[action]->id != NOTHING)
        {
            re = RP_useGear(RS_getRPIndex(rs, i), action, re);
            askDirection(RS_getRPIndex(rs, i));
            gearUsed = TRUE;
        }
    }

    if (!gearUsed && !isMove)
    {
        printf("You decided to rest.\n");
        RE* event = RE_create(RS_getRPIndex(rs, i), REST, NULL, 0);
        re = RE_attach(re, event);
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
    RP_setName(RS_getRPIndex(rs, 0), "Player 1");
    RP_setName(RS_getRPIndex(rs, 1), "Player 2");
    RO* observer = RO_create();
    observer->message = &message;
    rs->observers = RO_append(rs->observers, observer);

    for (int i = 0; i < rs->rpLen; i++)
    {
    	for (int j = 0; j < GEARLEN; j++)
        {
            printf("%d. %s\n", j + 1, RG_getGear(j)->name);
        }
        printf("Choose gear %s\n", RS_getRPIndex(rs, i)->name);
    	for (int j = 0, index = 0; j < MAXITEMLEN; j++, index++)
        {
    	    int in;
    	    scanf("%d", &in);
            in--;
            RG *gear = RG_getGear(in);
            bool found = FALSE;
            for (int k = 0; k < MAXITEMLEN; k++)
            {
                RG *ownGear = RS_getRPIndex(rs, i)->gears[k];
            	if (strcmp(ownGear->name, gear->name) == 0)
                {
                    ownGear->amount += gear->amount;
                    found = TRUE;
                    index--;
                    break;
                }
            }
            if (!found)
            {
                RS_getRPIndex(rs, i)->gears[j] = gear;
            }
            
            printf("You chose %s.\n", gear->name);
   	    }
    }

	while (TRUE)
	{
        RE *events = NULL;
        for (int i = 0; i < rs->rpLen; i++)
        {
            char op[256] = {0};
            RP* player = RS_getRPIndex(rs, i);
            printf("\n\n\n\n\n\n\n\n\n\n\n\nPass the phone...\n");
            
            while (strcmp(op, "ok") != 0)
            {
                scanf("%s", op);
            }
            
            // Print map
            printMap(rs);

            // Print status 
            printf("%s,\n", player->name);
            printf("HP: %d\n", player->hp);
            printf("MP: %d\n", player->mp);
            printf("STA: %d\n", player->stamina);
            
            // Print gears
            for (int j = 0; j < MAXITEMLEN; j++)
            {
                RG *gear = player->gears[j];
                if (strcmp(gear->name, "Nothing") == 0 || gear->amount == 0)
                {
                    continue;
                }
                printf("%d. %d %s\n", j + 1,
                       RS_getRPIndex(rs, i)->gears[j]->amount,
                       RS_getRPIndex(rs, i)->gears[j]->name);
            }
            scanf("%s", op);
            events = appendEvent(events, op, rs, i);
        }
        
        RS_processRE(rs, events);
        printMap(rs);
    }

    return 0;
};