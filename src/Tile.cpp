#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(int xPos, int yPos, SpriteInfo si, Property p)
{
   create(xPos, yPos, si, p);
}

Tile::~Tile()
{
}

void Tile::create(int xPos, int yPos, SpriteInfo si, Property p)
{
   x = xPos;
   y = yPos;
   spriteInfo = si;
   property = p;
}

SpriteInfo Tile::getSpriteInfo() const
{
   return spriteInfo;
}

int Tile::getX() const
{
   return x;
}

int Tile::getY() const
{
   return y;
}

Tile::Property Tile::getProperty() const
{
   return property;
}
