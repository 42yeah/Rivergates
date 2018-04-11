#include "Rivergates.h"

RO *RO_create()
{
    RO *ro = malloc(sizeof(RO));
    ro->next = NULL;
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
