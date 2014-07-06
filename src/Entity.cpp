#include "Entity.hpp"

Entity::Entity()
{
   x = 0;
   y = 0;
   width = 0;
   height = 0;
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
