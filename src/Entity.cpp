#include "Entity.hpp"

Entity::Entity()
{
   fileName = "";
   x = 0;
   y = 0;
   width = 0;
   height = 0;
}

Entity::Entity(std::string file, int xPos, int yPos, int w, int h)
{
   create(file, xPos, yPos, w, h);
}

Entity::~Entity()
{
}

void Entity::create(std::string file, int xPos, int yPos, int w, int h)
{
   fileName = file;
   x = xPos;
   y = yPos;
   width = w;
   height = h;
}

std::string Entity::getFileName() const
{
   return fileName;
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
