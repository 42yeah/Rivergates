#include "Rivergates.h"

bool pos_pequals(pos a, pos b)
{
	if (a.x == b.x && a.y == b.y)
    {
        return TRUE;
    }
    return FALSE;
}

pos cpos(int x, int y)
{
    pos p;
    p.x = x;
    p.y = y;

    return p;
}
