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
     if (pos.x <= 0) pos.x = 0;                                         
     if (pos.x > gfx.ScreenWidth - 76) pos.x = gfx.ScreenWidth - 76;    
     if (pos.y <= 0) pos.y = 0;                                         
     if (pos.y > gfx.ScreenHeight - 61) pos.y = gfx.ScreenHeight - 61;  
   
}
