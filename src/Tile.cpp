#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(int xPos, int yPos, std::shared_ptr<sf::Sprite> sp, Property p)
{
   create(xPos, yPos, sp, p);
}

Tile::~Tile()
{
}

void Tile::create(int xPos, int yPos, std::shared_ptr<sf::Sprite> sp, Property p)
{
   x = xPos;
   y = yPos;
   sprite = sp;
   property = p;
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

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   sprite->setPosition(x, y);
   target.draw(*sprite, states);
}
