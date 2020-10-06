#pragma once
#include"Graphics.h"
#include"img.h"
#include"RectF.h"
#include"Vec2.h"
#include"Keyboard.h"
#include "Bullet.h"
#include"CircleF.h"
#include"Defender.h"
#include <memory>

class Enemy
{
public:
	enum class Model
	{
		test
	};
	Enemy(const Model model, const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(float dt, Graphics& gfx);
	void TakeDmg(float dmg);
	const Vec2& GetPos();
	float GetDmg() const;
	bool DoDefenderColision(Defender&def);

	float colRadius = 30.0f;
	bool bDead = false;

	std::vector < std::unique_ptr<Bullet>> bullets;

private:
	void Move(float dt);
	void Shoot();

	Model model;
	Vec2 pos;
	float width = 0;
	float height = 0;
	float speed = 0;
	float health_max = 0;
	float health_current = health_max;
	float dmg = 0;
	float fMoveTimer = 0;
	float reloadTime_max = 0;
	float reloadTime_current = reloadTime_max;

};

