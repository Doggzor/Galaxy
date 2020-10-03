#pragma once
#include"Graphics.h"
#include"img.h"
#include"RectF.h"
#include"Vec2.h"
#include"Keyboard.h"
#include "Bullet.h"
#include"CircleF.h"
#include"Defender.h"

class Enemy
{
public:
	Enemy(const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(float dt, Graphics& gfx);
	void TakeDmg(float dmg);
	const Vec2& GetPos();
	bool DoDefenderColision(Defender&def);

	float colRadius = 30.0f;
	bool bDead = false;

	std::vector<Bullet*> bullets;
	Vec2 pos;
private:
	void Shoot();

	
	static constexpr float width = 40;
	static constexpr  float height = 40;
	float speed = 200.0f;
	float healthMax = 200.0f;
	float health = 200.0f;
	float dmg = 0;
	float fMoveTimer = 0;
	float reload = 0.4f;

};

