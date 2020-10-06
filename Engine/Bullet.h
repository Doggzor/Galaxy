#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "CircleF.h"
class Bullet
{
public:

	Bullet(const Vec2& pos, const Vec2& dir, const Color& c, float speed, float dmg, bool homing = false);
	void Update(float dt, const Vec2& target = { -1.0f, 0 });
	void Draw(Graphics& gfx);
	void delete_offscreen(Graphics& gfx);
	bool bHitTarget(const Vec2& collision_center, float collision_radius);

	Vec2 pos;
	Vec2 dir;
	float dmg;
	bool bDeleted = false;
	float radius = 6.0f;
	Color c;
	float speed = 0.0f;
	bool bHoming = false; //Only for enemy bullets, too much work to use for defender :D
	float DetectionRadius = 400.0f;
	float DetectionRadiusSq = DetectionRadius * DetectionRadius;
};

