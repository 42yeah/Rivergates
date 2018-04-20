#ifndef RIVERGATEEVENT_H_
#define RIVERGATEEVENT_H_

#include "Rivergates.h"

enum RivergateEventType
{
    REST = 0, WALK, STAB, CHOP, PIERCE, RETLEN
};

// Linked-list styled
struct RivergateEvent
{
    RP *player;
    RP *target[MAXTARGETS];	  // Maximum MAXTARGETS targets
    int targetLen;
    struct RivergateEvent *next; // Event queue
    RET type;
};

RE *RE_create(RP *pl, RET type, RP *pls[], int plLen);

int getPriority(RET ret);

RE *RE_attach(RE *re, RE *attach);

#endif