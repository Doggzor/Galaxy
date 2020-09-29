#pragma once
#include"Graphics.h"

class Space
{

public:

	Space(float x_in,float y_in,float speed_in,int yelow_in);
	void Draw(Graphics& gfx);
	void Update();
	void Respown();
	bool isEdgeOfWorld();

private:

	float x;
	float y;
	float speed;
	int yelow;

};

