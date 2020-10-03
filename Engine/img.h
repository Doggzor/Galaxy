#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "rng.h"
#include"RectF.h"
#include"Surface.h"
#include<string>

class img
{
public:
	//75x60
	static void TestAircraft(int x, int y, Graphics& gfx);
	//40x40
	static void TestEnemy(int x, int y, Graphics& gfx);
	static void HP_Bar(const Vec2& topleft, float maxWidth, float height, float maxHealth, float currentHealth, Graphics& gfx);
	void Gif6(int& slider, Graphics& gfx, Vec2& centar,const std::string& vol1,const std::string& vol2,const std::string& vol3, const std::string& vol4, const std::string& vol5, const std::string& vol6);
	
};
