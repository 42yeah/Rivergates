#include "Rivergates.h"

RE* RE_create(RP* pl, RET type, RP* pls[], int plLen, int x, int y)
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

int getPriority(RET ret) {
    int priority[] = {0, 1};
    
    return priority[ret];
}

RE* RE_attach(RE* re, RE* attach)
{
    RE *iter = re;
    RE *prev;
    
    while (iter)
    {
        int p1 = getPriority(iter->type);
        int p2 = getPriority(attach->type);
        if (p2 <= p1)
        {
            // Insert BEFORE it; p2 higher than p1
            if (iter == re)
            {
                // ITER IS HEAD!!! LINK IT BEFORE ITER
                attach->next = iter;
                
                return attach;
            }
            else
            {
                RE *tmp = prev->next;
                prev->next = attach;
                attach->next = prev;

                return re;
            }
        }
        prev = iter;
        iter = iter->next;
    }
    // Iteration is done and it isn't inserted
    prev->next = attach;
    attach->next = NULL;

    return re;
}
