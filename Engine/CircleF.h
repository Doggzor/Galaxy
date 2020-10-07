#pragma once
#include"Graphics.h"
class CircleF
{
public:

	CircleF()= default;
	CircleF(float x, float y, float r, Color c);
	CircleF(Vec2& center, float r, Color c);
	bool IsOverLapingWitH(const CircleF& other);
	bool isContaining(const Vec2& coordinate);
	

public:
	Color c;
	float x;
	float y;
	float r;



};

