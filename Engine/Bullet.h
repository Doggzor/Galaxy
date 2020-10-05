#pragma once
#include "Vec2.h"
#include "Graphics.h"
struct Bullet
{
	Bullet(const Vec2& pos, float dmg, bool friendly);
	void Update(float dt);
	void Draw(Graphics& gfx);
	void delete_offscreen(Graphics& gfx);
	bool bHitTarget(const Vec2& collision_center, float collision_radius);

	Vec2 pos;
	float dmg;
	bool bDeleted = false;
	float radius = 6.0f;
	Color c;
	float speed = 500.0f;
	bool bFriendly;
};

