#ifndef RIVERGATES_H_
#define RIVERGATES_H_

// Default tweakable values
#define MAPW 10
#define MAPH 10
#define TRUE 1
#define FALSE 0
#define MAXTARGETS 16

// Structs and typedefs
struct RivergatePlayer;
struct RivergateSession;
struct RivergateTerrain;
enum RivergateEventType;
struct RivergateEvent;

typedef struct RivergateSession RS;
typedef struct RivergatePlayer RP;
typedef struct RivergateTerrain RT;
typedef enum RivergateEventType RET;
typedef struct RivergateEvent RE;
typedef int bool;

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Game includes
#include "RivergatePlayer.h"
#include "RivergateTerrain.h"
#include "RivergateSession.h"
#include "RivergateEvent.h"

#endif