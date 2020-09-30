#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "rng.h"

class img
{
public:
	//75x60
	static void TestAircraft(int x, int y, Graphics& gfx);
	//40x40
	static void TestEnemy(int x, int y, Graphics& gfx);
	static void HP_Bar(const Vec2& topleft, float maxWidth, float height, float maxHealth, float currentHealth, Graphics& gfx);
};
