#ifndef RIVERGATES_H_
#define RIVERGATES_H_

// Default tweakable values
#define MAPW 10
#define MAPH 10
#define MAXTARGETS 16
#define MAXLEN 16
#define MAXITEMLEN 5
#define FALSE 0
#define TRUE 1

// Directions - the enum hack
enum Direction
{
    U,  // Up
    UR, // Up-Right
    R,  // Right
    DR, // Down-Right
    D,  // Down
    DL, // Down-Left
    L,  // Left
    UL  // Up-Left
};

// Structs and typedefs
struct RivergatePlayer;
struct RivergateSession;
struct RivergateTerrain;
enum RivergateEventType;
struct RivergateEvent;
struct RivergateGear;
enum RivergateGearID;
struct RivergatePos;

typedef struct RivergateSession RS;
typedef struct RivergatePlayer RP;
typedef struct RivergateTerrain RT;
typedef enum RivergateEventType RET;
typedef struct RivergateEvent RE;
typedef struct RivergateGear RG;
typedef enum RivergateGearID RGID;
typedef struct RivergatePos pos;
typedef int bool;

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Game includes
#include "RivergatePos.h"
#include "RivergatePlayer.h"
#include "RivergateTerrain.h"
#include "RivergateSession.h"
#include "RivergateEvent.h"
#include "RivergateGear.h"

#endif