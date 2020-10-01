#pragma once
#include"Vec2.h"
#include"Colors.h"
class CircleF
{
public:

	CircleF()= default;
	CircleF(float x, float y, float R, Color c);
	CircleF(Vec2& centar, float R, Color c);
	bool IsOverLapingWitH(const Vec2& other,float R);



private:
	Vec2 centar;
	Color c;
	float x;
	float y;
	float R;



};

