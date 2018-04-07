#ifndef RIVERGATEEVENT_H_
#define RIVERGATEEVENT_H_

// Linked-list styled
struct RivergateEvent
{
    RP player;
    RP target[MAXTARGETS];       // Maximum MAXTARGETS targets
    int x, y;                    // Affected position
    struct RivergateEvent *next; // Event queue
};

#endif