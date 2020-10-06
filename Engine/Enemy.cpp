#include "Enemy.h"

Enemy::Enemy(const Model model, const Vec2& pos)
	:
	model(model),
	pos(pos)
{
	switch (model)
	{
	case Model::test:
		width = 40;
		height = 40;
		speed = 200.0f;
		health_max = 200.0f;
		dmg = 10.0f;
		reloadTime_max = 0.3f;
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

const Vec2& Enemy::GetPos()
{
	return pos;
}

float Enemy::GetDmg() const
{
	return dmg;
}

bool Enemy::DoDefenderColision(Defender& def)
{
	CircleF  cf;
	float R = 50.0f;

	return cf.isInside(pos.x, pos.y, R, def.GetPos());
}

void Enemy::Move(float dt)
{
	switch (model)
	{
	case Model::test:
		//Sinusoid going down
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

		switch (model)
		{
		case Model::test:
			//Single shot downwards
			bullets.push_back(std::make_unique<Bullet>(Vec2(pos.x, bottom), Vec2(0.0f, 1.0f), Colors::Red, 500.0f, dmg));
			break;
			//Triple shot
			//bullets.push_back(std::make_unique<Bullet>(Vec2(pos.x, bottom), Vec2(-0.5f, 1.0f), dmg, false));
			//bullets.push_back(std::make_unique<Bullet>(Vec2(pos.x, bottom), Vec2(0.0f, 1.0f), dmg, false));
			//bullets.push_back(std::make_unique<Bullet>(Vec2(pos.x, bottom), Vec2(0.5f, 1.0f), dmg, false));
		}
	}
}
