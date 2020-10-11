#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Surface.h"
struct Button
{
public:
	Button(int x, int y, const Surface& unselected, const Surface& hoveredOver, const Surface& selected)
		:
		x(x),
		y(y),
		unselected(unselected),
		hoveredOver(hoveredOver),
		selected(selected)
	{
	}
	void Update(Keyboard& kbd)
	{
		if (bHoveredOver && kbd.KeyIsPressed(VK_RETURN))
		{
			if (!bSelected) bSelected = true;
			else bSelected = false;
		}
	}
	void Draw(Graphics& gfx)
	{
		if (bSelected) gfx.DrawSprite(x, y, selected);
		else if (bHoveredOver) gfx.DrawSprite(x, y, hoveredOver);
		else gfx.DrawSprite(x, y, unselected);
	}

	int x;
	int y;
	bool bSelected = false;
	bool bHoveredOver = false;
	Surface unselected;
	Surface hoveredOver;
	Surface selected;
};

