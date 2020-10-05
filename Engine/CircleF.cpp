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
	  
	return ((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) <= R * R);

}

bool CircleF::isInside(float circle_x, float circle_y, float circle_rad, const Vec2& pos)
{
	
		// Compare radius of circle with distance  
		// of its center from given point 
	return ((pos.x - circle_x) * (pos.x - circle_x) + (pos.y - circle_y) * (pos.y - circle_y) <= circle_rad * circle_rad);
}
