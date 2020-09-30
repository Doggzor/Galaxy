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
    space(fWorldSpeed, gfx),
    def(Vec2(400.0f, 300.0f), 300.0f),
    testEnemy(Vec2(400.0f, 100.0f))
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
    def.Update(wnd.kbd, gfx, dt);
    for (auto b : def.bullets)
    {
        b->Update(dt);
        if (!testEnemy.bDead && b->bHitTarget(testEnemy.GetPos(), testEnemy.colRadius))
        {
            testEnemy.TakeDmg(def.dmg);
        }
    }
    testEnemy.Update(dt, gfx);
    for (auto b : testEnemy.bullets)
    {
        b->Update(dt);
        b->bHitTarget(def.GetPos(), def.colRadius);
    }
}

void Game::ComposeFrame()
{
    space.Draw(gfx);
    def.Draw(gfx);
    for (auto b : def.bullets) b->Draw(gfx);
    testEnemy.Draw(gfx);
    for (auto b : testEnemy.bullets) b->Draw(gfx);
}

