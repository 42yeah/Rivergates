#include "Rivergates.h"

void defaultMsg(char *msg) { fprintf(stderr, "Message: not implemented.\n"); }

RO *RO_create()
{
    RO *ro = malloc(sizeof(RO));
    ro->next = NULL;
    ro->message = &defaultMsg;
    return ro;
}

RO *RO_append(RO *dst, RO *append)
{
    append->next = NULL;
    
	if (!dst)
    {
        return append;
    }
    dst->next = append;

    return dst;
}