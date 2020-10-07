#pragma once
#include"Vec2.h"
class CircleF
{
public:

	CircleF()= default;
	CircleF(Vec2 center, float r);
	bool IsOverLapingWitH(const CircleF& other);
	bool isContaining(const Vec2& coordinate);
	

public:
	Vec2 center;
	float r;
};

