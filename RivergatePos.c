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

pos pos_getAffectedPos(pos p, enum Direction d, int x)
{
    pos pmod = p;
    
    for (int i = 0; i < x; i++)
    {
		switch (d)
  	  {
   	 case U:
   	     pmod.y--;
    	    break;

   	 case UR:
    	    pmod.y--;
    	    pmod.x++;
     	   break;

   	 case R:
    	    pmod.x++;
    	    break;

    	case DR:
   	     pmod.y++;
      	  pmod.x++;
     	   break;

    	case D:
        	pmod.y++;
    	    break;

   	 case DL:
   	     pmod.y++;
   	     pmod.x--;
    	    break;

   	 case L:
   	     pmod.x--;
    	    break;

 	   case UL:
   	     pmod.x--;
  	      pmod.y--;
    	    break;

  	  default:
   	     break;
   	 }
    }

    return pmod;
}
