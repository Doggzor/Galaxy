#include "CircleF.h"
#include<cmath>

CircleF::CircleF(float x, float y, float R, Color c)
	:
	x{x},
	y{y},
	R{R},
	c{c}
{
}

CircleF::CircleF(Vec2& centar, float R, Color c)
	:
	CircleF(centar.x, centar.y, R, c)
{
}

bool CircleF::IsOverLapingWitH(const Vec2& other, float R)
{
	  
        float distSq = sqrt(((x - other.x)
            * (x - other.x))
            + ((y - other.y)
                * (y - other.y)));

		if (distSq< R )

		{
			return true;
		}
       
          

}
