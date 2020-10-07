#include "CircleF.h"
#include<cmath>

CircleF::CircleF(float x, float y, float r, Color c)
	:
	x(x),
	y(y),
	r(r),
	c(c)
{
}

CircleF::CircleF(Vec2& center, float r, Color c)
	:
	CircleF(center.x, center.y, r, c)
{
}

bool CircleF::IsOverLapingWitH(const CircleF& other)
{
	const Vec2 center(x, y);
	const Vec2 other_center(other.x, other.y);
	return (other_center - center).GetLengthSq() < (other.r + r) * (other.r + r);

}

bool CircleF::isContaining(const Vec2& coordinate)
{
	return (coordinate - Vec2(x, y)).GetLengthSq() < r * r;
}
