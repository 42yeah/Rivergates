#include "Rivergates.h"

RE* RE_create(RP* pl, RET type, RP* pls[], int plLen)
{
    RE *re = (RE *)malloc(sizeof(RE));
    re->player = pl;
    for (int i = 0; i < plLen; i++)
    {
        re->target[i] = pls[i];
    }
    re->targetLen = plLen;
    re->next = NULL;
    re->type = type;

    return re;
}

int getPriority(RET ret) {
    // The order of RivergateEventType indicates the priority.
    return ret;
}

void printRE(RE* re)
{
    printf("====RE====\n");
    while (re)
    {
        printf("PLAYER %p\nTYPE %d\n", re->player, re->type);
        re = re->next;
        printf("====--====\n");
    }
    printf("====RE====\n");
}

RE* RE_attach(RE* re, RE* attach)
{
    RE *iter = re;
    RE *prev;
    
    if (!re)
    {
        return attach;
    }
    
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
                attach->next = tmp;
                
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