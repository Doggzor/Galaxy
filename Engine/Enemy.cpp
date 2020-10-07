#include "Enemy.h"

Enemy::Enemy(const Model model, const Vec2& pos, const MovePattern MovePattern, const FirePattern FirePattern)
	:
	model(model),
	pos(pos)
{
	switch (model)
	{
	case Model::test:
		width = 40.0f;
		height = 40.0f;
		colRadius = 30.0f;
		speed = 200.0f;
		health_max = 200.0f;
		dmg = 10.0f;
		collision_dmg = 100.0f;
		reloadTime_max = 0.3f;
		if(MovePattern == MovePattern::ModelDefault) movePattern = MovePattern::Sinusoid_Down;
		if(FirePattern == FirePattern::ModelDefault) firePattern = FirePattern::SingleBullet_Down;
		break;
	}
	health_current = health_max;
	reloadTime_current = reloadTime_max;
	fMoveTimer = 0;

}

void Enemy::Draw(Graphics& gfx)
{
	int x = int(pos.x - width / 2.0f);
	int y = int(pos.y - height / 2.0f);

	img::TestEnemy(x, y, gfx);
	img::HP_Bar(Vec2((float)x, (float)y - 10.0f), width, 5.0f, health_max, health_current, gfx);
}

void Enemy::Update(float dt, Graphics& gfx)
{
	if( health_current <= 0 ||
		(pos.y - height / 2.0f > (float)gfx.ScreenBottom + 15.0f && bullets.size() == 0)) //Enemy (and his health bar) went donw off screen boundaries and all his bullets are destroyed
		bDead = true;

	if (pos.y - height / 2.0f <= (float)gfx.ScreenBottom + 15.0f) Move(dt); //Move only if enemy (and his health bar) didn't go thorugh the bottom of the screen
	reloadTime_current -= dt;
	
	Shoot();

}

void Enemy::TakeDmg(float dmg)
{
	health_current -= dmg;
}

Vec2 Enemy::GetPos() const
{
	return pos;
}

float Enemy::GetDmg() const
{
	return dmg;
}

bool Enemy::hasCrashedInto(const CircleF& circle)
{
	if (GetColCircle().IsOverLapingWith(circle))
	{
		bDead = true;
		return true;
	}
	else return false;
}

bool Enemy::hasCrashedInto(const Vec2& coordinate)
{
	if (GetColCircle().isContaining(coordinate))
	{
		bDead = true;
		return true;
	}
	else return false;
}

CircleF Enemy::GetColCircle() const
{
	return CircleF(pos, colRadius);
}


void Enemy::Move(float dt)
{
	switch (movePattern)
	{
	case MovePattern::Sinusoid_Down:
		fMoveTimer += 2.4f * dt;
		pos.x += 400.0f * cos(fMoveTimer) * dt;
		pos.y += 60.0f * dt;
		break;
	}
	
}

void Enemy::Shoot()
{
	const float bottom = pos.y + height / 2;

	if (reloadTime_current <= 0)
	{
		reloadTime_current = reloadTime_max;

		switch (firePattern)
		{
		case FirePattern::SingleBullet_Down:
			bullets.push_back(std::make_unique<Bullet>(CircleF(Vec2(pos.x, bottom), 6.0f), Vec2(0.0f, 1.0f), Colors::Red, 100.0f, dmg));
			break;
		}
	}
}
