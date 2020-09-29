#include "Space.h"

Space::Space(float x_in, float y_in, float speed_in,int yelow_in)
	:
	x(x_in),
	y(y_in),
	speed(speed_in),
	yelow(yelow_in)
{
}

void Space::Draw(Graphics& gfx)
{
	gfx.PutPixel(x, y, 255, 255, yelow);
}
