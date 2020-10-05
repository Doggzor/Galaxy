#include "Enemy.h"

Enemy::Enemy(const Vec2& pos)
	:
	pos(pos)
{
}

void Enemy::Draw(Graphics& gfx)
{
	int x = int(pos.x - width / 2.0f);
	int y = int(pos.y - height / 2.0f);
	if (!bDead)
	{
		img::TestEnemy(x, y, gfx);
		img::HP_Bar(Vec2((float)x, (float)y - 10.0f), width, 5.0f, health_max, health_current, gfx);
	}
}

void Enemy::Update(float dt, Graphics& gfx)
{
	bDead = health_current <= 0;
	if (!bDead)
	{
		fMoveTimer += 2.4f * dt;
		pos.x += 400.0f * cos(fMoveTimer) * dt;
		pos.y += 0.0f * dt;

		reloadTime_current -= dt;
		Shoot();
	}
}

void Enemy::TakeDmg(float dmg)
{
	health_current -= dmg;
}

const Vec2& Enemy::GetPos()
{
	return pos;
}

bool Enemy::DoDefenderColision(Defender& def)
{
	CircleF  cf;
	float R = 50.0f;

	return cf.isInside(pos.x, pos.y, R, def.GetPos());
}

void Enemy::Shoot()
{
	const float bottom = pos.y + height / 2;

	if (reloadTime_current <= 0)
	{
		reloadTime_current = reloadTime_max;
		bullets.push_back(std::make_unique<Bullet>(Vec2(pos.x, bottom), dmg, false));
	}
}
