#include "Defender.h"

Defender::Defender(const Vec2& pos_in, float speed_in)
	:
	pos(pos_in),
	speed(speed_in)
	
{
}

void Defender::Draw(Graphics& gfx)

{
	int x = int(pos.x - width/2 );
	int y = int(pos.y-height/2);

	img::TestAircraft(x, y, gfx);
}

void Defender::Update(Keyboard& kbd,Graphics& gfx,float dt)
{
  
      dir = { 0.0f,0.0f };

      if (kbd.KeyIsPressed(VK_LEFT))
      {
          dir.x -= 1.0f;
      }
      if (kbd.KeyIsPressed(VK_RIGHT))
      {
          dir.x += 1.0f;
     }
     if (kbd.KeyIsPressed(VK_UP))  
     {
         dir.y -= 1.0f;
     }
     if (kbd.KeyIsPressed(VK_DOWN))                
     {
         dir.y += 1.0f;
     }
     pos += dir.GetNormalized() * speed*dt;
   
     const float right = pos.x + width / 2;
     const float left = pos.x - width / 2;
     const float top = pos.y - height / 2;
     const float bottom = pos.y + height / 2;
     
     if (right > float(gfx.ScreenWidth))
     {
         pos.x = float(gfx.ScreenWidth )- width / 2;
     }
     if (left < 0)
     {
         pos.x = width / 2;
     }
     if (top < 0)
     {
         pos.y = 0 + height / 2;
     }
     if (bottom > float(gfx.ScreenHeight))
     {
         pos.y = float(gfx.ScreenHeight) - height/2;

     }

    if (reload > 0) reload -= dt;
    dir = { 0.0f,0.0f };

    if (kbd.KeyIsPressed(VK_LEFT))
    {
        dir.x -= 1.0f;
    }
    if (kbd.KeyIsPressed(VK_RIGHT))
    {
        dir.x += 1.0f;
    }
    if (kbd.KeyIsPressed(VK_UP))  
    {
        dir.y -= 1.0f;
    }
    if (kbd.KeyIsPressed(VK_DOWN))                
    {
        dir.y += 1.0f;
    }
    pos += dir.GetNormalized() * speed*dt;

    if (kbd.KeyIsPressed(VK_SPACE)) Shoot();
   
   
    
    if (right > float(gfx.ScreenWidth))
    {
        pos.x = float(gfx.ScreenWidth )- width / 2;
    }
    else if (left < 0)
    {
        pos.x = width / 2;
    }
    if (top < 0)
    {
        pos.y = 0 + height / 2;
    }
    else if (bottom > float(gfx.ScreenHeight))
    {
        pos.y = float(gfx.ScreenHeight) - height/2;

    }
}

const Vec2& Defender::GetPos()
{
    return pos;
}


void Defender::Shoot()
{
    const float left = pos.x - width / 2;
    const float top = pos.y - height / 2;

    if (reload <= 0)
    {
        reload = 0.0f;

        bullets.push_back(std::make_unique<Bullet>(Vec2(left + 25.0f, top), dmg, true));
        bullets.push_back(std::make_unique<Bullet>(Vec2(left + 50.0f, top), dmg, true));
    }

}
