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
	  
	if ((other.x - x) * (other.x - x) +
		(other.y - y) * (other.y - y) <= R*R )
	{

		return true;
	}
	
          

}

bool CircleF::isInside(float circle_x, float circle_y, int rad, int x, int y)
{
	
		// Compare radius of circle with distance  
		// of its center from given point 
		if ((x - circle_x) * (x - circle_x) +
			(y - circle_y) * (y - circle_y) <= rad * rad)
			return true;
		else
			return false;
}
