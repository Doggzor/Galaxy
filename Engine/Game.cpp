/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    space(fWorldSpeed, gfx)
{
}

void Game::Go()
{
	gfx.BeginFrame();
    float ElapsedTime = ft.Mark();
    while (ElapsedTime > 0.0f)
    {
        const float dt = std::min(0.0025f, ElapsedTime);
        UpdateModel(dt);
        ElapsedTime -= dt;
    }
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
    space.Update(dt, gfx);

    /*****************************TEST************************************/
    /**/                                                               /**/
    /**/   if (wnd.kbd.KeyIsPressed(VK_LEFT)) x -= 1;                  /**/
    /**/   if (wnd.kbd.KeyIsPressed(VK_RIGHT)) x += 1;                 /**/
    /**/   if (wnd.kbd.KeyIsPressed(VK_UP)) y -= 1;                    /**/
    /**/   if (wnd.kbd.KeyIsPressed(VK_DOWN)) y += 1;                  /**/
    /**/                                                               /**/
    /**/   if (x <= 0) x = 0;                                          /**/
    /**/   if (x > gfx.ScreenWidth - 76) x = gfx.ScreenWidth - 76;     /**/
    /**/   if (y <= 0) y = 0;                                          /**/
    /**/   if (y > gfx.ScreenHeight - 61) y = gfx.ScreenHeight - 61;   /**/
    /**/                                                               /**/
    /*********************************************************************/
}

void Game::ComposeFrame()
{
    space.Draw(gfx);
    img::TestAircraft(x, y, gfx);
}

