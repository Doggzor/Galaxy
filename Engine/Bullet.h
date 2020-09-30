#pragma once
#include "Vec2.h"
#include "Graphics.h"
struct Bullet
{
	Bullet(const Vec2& pos);
	void Update(float dt);
	void Draw(Graphics& gfx);
	bool bMarked_Delete(Graphics& gfx);

	Vec2 pos;
	float speed = 500.0f;
};

