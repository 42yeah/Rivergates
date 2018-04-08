#include "Rivergates.h"

RE* RE_create(RP* pl, int type, RP* pls[], int plLen, int x, int y)
{
    RE *re = (RE *)malloc(sizeof(RE));
    re->player = pl;
    for (int i = 0; i < plLen; i++)
    {
        re->target[i] = pls[i];
    }
    re->targetLen = plLen;
    re->x = x;
    re->y = y;
    re->next = NULL;
    re->type = type;

    return re;
}