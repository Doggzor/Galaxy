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
	enum class Difficulty
	{
		Easy,
		Normal,
		Hard
	};
	enum class Model
	{
		Fighter,
		Destroyer,
		Battleship
	};
	Defender() = default;
	Defender(const Vec2& pos, const Model model, const Difficulty difficulty);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd,Graphics&gfx,float dt);
	void TakeDmg(float dmg);
	Vec2 GetPos() const;
	CircleF GetColCircle() const;
	float GetDmg() const;
	bool bDead = false;

	std::vector<std::unique_ptr <Bullet> > bullets;

	void SetDifficulty(const Difficulty difficulty);

private:

	void Shoot();

	float diff_multiplier = 1.0f;

	Model model;
	Vec2 pos;
	Vec2 dir{ 0.0f,0.0f };
	float width = 75.0f;
	float height= 60.0f;
	float colRadius = 30.0f;
	float speed;
	float health_max = 1000.0f;
	float health_current = health_max;
	float shield_max = 0;
	float shield_current = shield_max;
	float shield_recharge = 10.0f;
	float reloadTime_max = 0.3f;
	float reloadTime_current = 0;
	float dmg = 30.0f;
	float bulletSpeed = 500.0f;
	float bulletRadius = 0;

};

