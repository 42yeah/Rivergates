#ifndef RIVERGATEEVENT_H_
#define RIVERGATEEVENT_H_

enum RivergateEventType
{
    WALK = 0, CHOP
};

// Linked-list styled
struct RivergateEvent
{
    RP *player;
    RP *target[MAXTARGETS];	  // Maximum MAXTARGETS targets
    int targetLen;
    int x, y;                    // Affected position
    struct RivergateEvent *next; // Event queue
    RET type;
};

RE *RE_create(RP *pl, RET type, RP *pls[], int plLen, int x, int y);

int getPriority(RET ret);

RE *RE_attach(RE *re, RE *attach);

#endif