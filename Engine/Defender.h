#pragma once
#include"Graphics.h"
#include"img.h"
#include"RectF.h"
#include"Vec2.h"
#include"Keyboard.h"
#include "Bullet.h"
#include <memory>

class Defender
{
public:

	Defender() = default;
	Defender(const Vec2& pos_in, float speed_in);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd,Graphics&gfx,float dt);
	void TakeDmg(float dmg);
	Vec2 GetPos() const;
	CircleF GetColCircle() const;
	float GetDmg() const;
	//void Respawn();
	bool bDead = false;

	std::vector<std::unique_ptr <Bullet> > bullets;

private:

	void Shoot();

	Vec2 pos;
	Vec2 dir{ 0.0f,0.0f };
	static constexpr float colRadius = 30.0f;
	static constexpr float width = 75.0f;
	static constexpr float height= 60.0f;
	float speed;
	float health_max = 1000.0f;
	float health_current = health_max;
	float reloadTime_max = 0.3f;
	float reloadTime_current = 0;
	float dmg = 30.0f;

	float bulletSpeed = 500.0f;

};

