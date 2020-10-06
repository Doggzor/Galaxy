#include "Bullet.h"

Bullet::Bullet(const Vec2& pos, const Vec2& dir, const Color& c, float speed, float dmg, bool homing)
	:
	pos(pos),
	c(c),
	dir(dir),
	speed(speed),
	dmg(dmg),
	bHoming(homing)
{
}

void Bullet::Update(float dt, const Vec2& target)
{
	if(target.x >= 0) //Aquire target only if it is initialized
	if (bHoming && DetectionRadiusSq > (target - pos).GetLengthSq()) dir = target - pos; //Follow target if it's inside detection radius
	pos += dir.GetNormalized() * speed * dt;
}

void Bullet::Draw(Graphics& gfx)
{
	gfx.DrawCircle((int)pos.x, (int)pos.y, (int)radius, c);
}

void Bullet::delete_offscreen(Graphics& gfx)
{
	const int left = (int)(pos.x - radius);
	const int right = (int)(pos.x + radius);
	const int top = (int)(pos.y - radius);
	const int bottom = (int)(pos.y + radius);
	if (right < gfx.ScreenLeft || left > gfx.ScreenRight || bottom < gfx.ScreenTop || top > gfx.ScreenBottom) bDeleted = true;
}

bool Bullet::bHitTarget(const Vec2& collision_center, float collision_radius)
{
		if ((collision_center - pos).GetLengthSq() < (collision_radius + radius) * (collision_radius + radius))
		{
			bDeleted = true;
			return true;
		}
		else return false;
}

