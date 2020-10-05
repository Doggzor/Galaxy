#include "Bullet.h"

Bullet::Bullet(const Vec2& pos, float dmg, bool friendly)
	:
	pos(pos),
	dmg(dmg),
	bFriendly(friendly)
{
	if (bFriendly) c = Colors::Cyan;
	else c = Colors::Red;
}

void Bullet::Update(float dt)
{
		if (bFriendly) pos.y -= speed * dt;
		else pos.y += speed * dt;
}

void Bullet::Draw(Graphics& gfx)
{
	gfx.DrawCircle((int)pos.x, (int)pos.y, (int)radius, c);
}

void Bullet::delete_offscreen(Graphics& gfx)
{
	if (pos.x < 0 || pos.x > gfx.ScreenWidth || pos.y < 0 || pos.y > gfx.ScreenHeight) bDeleted = true;
}

bool Bullet::bHitTarget(const Vec2& collision_center, float collision_radius)
{
		const float length0 = (collision_center - pos).GetLengthSq();
		const float length1 = (collision_radius + radius) * (collision_radius + radius);
		if ((collision_center - pos).GetLengthSq() < (collision_radius + radius) * (collision_radius + radius))
		{
			bDeleted = true;
			return true;
		}
		else return false;
}
