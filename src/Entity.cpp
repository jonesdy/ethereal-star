#include "Entity.hpp"

Entity::Entity()
{
   create(0, 0);
}

Entity::Entity(int xPos, int yPos)
{
   create(xPos, yPos);
}

Entity::~Entity()
{
}

void Entity::create(int xPos, int yPos)
{
   x = xPos;
   y = yPos;
   frame = 0;
   maxFrame = 0;
   direction = Direction::UP;
   prevDirection = direction;
}

int Entity::getX() const
{
   return x;
}

int Entity::getY() const
{
   return y;
}

int Entity::getWidth()
{
   return getCurrentSpriteInfo().getImageWidth();
}

int Entity::getHeight()
{
   return getCurrentSpriteInfo().getImageHeight();
}

void Entity::addSpriteInfo(SpriteInfo si, int fr, Direction dir)
{
   spriteInfos[std::pair<int, Direction>(fr, dir)] = si;
   if(fr > maxFrame)
   {
      maxFrame = fr;
   }
}

SpriteInfo Entity::getCurrentSpriteInfo()
{
   SpriteInfo si = spriteInfos[std::pair<int, Direction>(frame, direction)];
   si.setX(x);
   si.setY(y);
   return si;
}

void Entity::move(int dx, int dy)
{
   x += dx;
   y += dy;

   // Determine which frame to use
   if(frame < maxFrame)
   {
      frame++;
   }
   else
   {
      frame = 0;
   }

   // Determine which direction to use
   if(dx > 0)
   {
      direction = Direction::RIGHT;
   }
   else if(dx < 0)
   {
      direction = Direction::LEFT;
   }
   else if(dy > 0)
   {
      direction = Direction::DOWN;
   }
   else if(dy < 0)
   {
      direction = Direction::UP;
   }

   if(prevDirection != direction)
   {
      prevDirection = direction;
      frame = 0;
   }
}
