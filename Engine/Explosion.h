#pragma once
#include "Graphics.h"
#include "img.h"
#include "Vec2.h"
struct Explosion
{
	enum class Size
	{
		Small,
		Medium,
		Large
	};
	Explosion(const Vec2& pos, Size size)
		:
		pos(pos),
		size(size)
	{
		switch (size)
		{
		case Size::Small:
			duration = 0.1f;
			break;
		case Size::Medium:
			duration = 0.25f;
			break;
		default:
			duration = 0.1f;

		}
	}
	void Update(float dt)
	{
		duration -= dt;
		bExpired = duration <= 0;
	}
	void Draw(Graphics& gfx)
	{
		switch (size)
		{
		case Size::Small:
			img::Explosion_Small(pos, gfx);
			break;
		case Size::Medium:
			img::Explosion_Medium(pos, gfx);
			break;
		}

	}

	Vec2 pos;
	Size size;
	float duration;
	bool bExpired = false;
};

