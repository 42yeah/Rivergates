#ifndef RIVERGATEEVENT_H_
#define RIVERGATEEVENT_H_

enum RivergateEventType
{
    WALK = 0
};

// Linked-list styled
struct RivergateEvent
{
    RP *player;
    RP *target[MAXTARGETS];	  // Maximum MAXTARGETS targets
    int targetLen;
    int x, y;                    // Affected position
    struct RivergateEvent *next; // Event queue
    int type;
};

RE *RE_create(RP *pl, int type, RP *pls[], int plLen, int x, int y);

#endif