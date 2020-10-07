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
#include<iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    space(fWorldSpeed, gfx),
    def(Vec2(400.0f, 600.0f), 300.0f)
    
{
    enemy.push_back(std::make_unique <Enemy>(Enemy::Model::test, Vec2(400.0f, 50.0f)));
    //enemy.push_back(std::make_unique <Enemy>(Enemy::Model::test, Vec2(800.0f, 50.0f)));
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
    
    if (wnd.kbd.KeyIsPressed(VK_SPACE))
    {
        GS = GameState::GameOn;
    }
    if (GS != GameState::GameOn)
    {
        GS = GameState::GamePaused;
   }
    
    
    switch (GS)
    {
    case Game::GameState::GameOn:

        space.Update(dt, gfx);
        def.Update(wnd.kbd, gfx, dt);
        for (int i = 0; i < def.bullets.size(); i++) //Update defender bullets
        {
            def.bullets[i]->Update(dt);
            def.bullets[i]->delete_offscreen(gfx); //Mark bullets that are off screen to be deleted
            for (int j = 0; j < enemy.size(); j++)
            if (def.bullets[i]->isTargetHit(CircleF(enemy[j]->GetColCircle()))) //Check collision against all enemies
            {
                enemy[j]->TakeDmg(def.GetDmg());
                gfx.DrawSprite((int)def.bullets[i]->circle.center.x, (int)(def.bullets[i]->circle.center.y - def.bullets[i]->circle.r) - 20, surf); //Draw blast in place of impact (temporary)
            }
            if (def.bullets[i]->bDeleted) def.bullets.erase(std::remove(def.bullets.begin(), def.bullets.end(), def.bullets[i])); //Delete bullets if needed
            
        }
        for (int i = 0; i < enemy.size(); i++) //Update enemies
        {
            enemy[i]->Update(dt, gfx);
            if (enemy[i]->hasCrashedInto(def.GetPos())) def.TakeDmg(enemy[i]->collision_dmg); //Check if enemy crashed into defender
            for (int j = 0; j < enemy[i]->bullets.size(); j++) //Update bullets for all enemies
            {
                enemy[i]->bullets[j]->Update(dt, def.GetPos());
                enemy[i]->bullets[j]->delete_offscreen(gfx); //Mark bullets that are off screen to be deleted
                if (enemy[i]->bullets[j]->isTargetHit(def.GetColCircle())) //Check collision against the defender
                {
                    def.TakeDmg(enemy[i]->GetDmg());
                    gfx.DrawSprite((int)enemy[i]->bullets[j]->circle.center.x, (int)(enemy[i]->bullets[j]->circle.center.y - enemy[i]->bullets[j]->circle.r) + 20, surf); //Draw blast in place of impact (temporary)
                }
                if (enemy[i]->bullets[j]->bDeleted) enemy[i]->bullets.erase(std::remove(enemy[i]->bullets.begin(), enemy[i]->bullets.end(), enemy[i]->bullets[j])); //Delete bullets if needed
            }
            if (enemy[i]->bDead) enemy.erase(std::remove(enemy.begin(), enemy.end(), enemy[i])); //Delete enemies if needed
        }
        break;
    case Game::GameState::GamePaused:
        break;
    }
   
   
}

void Game::ComposeFrame()
{ 
   // gfx.DrawSprite(0,0, surf);
    space.Draw(gfx);
    def.Draw(gfx);
    for (int i = 0; i < def.bullets.size(); i++) def.bullets[i]->Draw(gfx); //Draw defender bullets
    
    for (int i = 0; i < enemy.size(); i++) //Draw enemies
    {
        enemy[i]->Draw(gfx);
        for (int j = 0; j < enemy[i]->bullets.size(); j++) enemy[i]->bullets[j]->Draw(gfx); //Draw enemy bullets
    }

}

