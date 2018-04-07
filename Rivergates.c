#include <stdio.h>
#include <stdlib.h>
#include "Rivergates.h"

int main() 
{
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
    return 0; 
};