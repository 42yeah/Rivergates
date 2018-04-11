#ifndef RIVERGATEOBSERVER_H_
#define RIVERGATEOBSERVER_H_

#include "Rivergates.h"

struct RivergateObserver
{
    void (*message)(char *msg);

    struct RivergateObserver *next;
};

RO *RO_create();

RO *RO_append(RO *dst, RO *append);

#endif
