#include "Entity.hpp"

Entity::Entity()
{
   create(0, 0, 0, 0);
}

Entity::Entity(int xPos, int yPos, int w, int h)
{
   create(xPos, yPos, w, h);
}

Entity::~Entity()
{
}

void Entity::create(int xPos, int yPos, int w, int h)
{
   x = xPos;
   y = yPos;
   width = w;
   height = h;
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

int Entity::getWidth() const
{
   return width;
}

int Entity::getHeight() const
{
   return height;
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
   return spriteInfos[std::pair<int, Direction>(frame, direction)];
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
