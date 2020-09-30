#include "Bullet.h"

Bullet::Bullet(const Vec2& pos)
	:
	pos(pos)
{
}

void Bullet::Update(float dt)
{
	pos.y -= speed * dt;
}

void Bullet::Draw(Graphics& gfx)
{
	gfx.DrawCircle((int)pos.x, (int)pos.y, 6, Colors::Cyan);
}

bool Bullet::bMarked_Delete(Graphics& gfx)
{
	return pos.x < 0 || pos.x > gfx.ScreenWidth || pos.y < 0 || pos.y > gfx.ScreenHeight;
}

