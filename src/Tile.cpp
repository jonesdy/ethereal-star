#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(int tx, int ty, std::shared_ptr<sf::Sprite> sp, Property p)
{
   create(tx, ty, sp, p);
}

Tile::~Tile()
{
}

void Tile::create(int tx, int ty, std::shared_ptr<sf::Sprite> sp, Property p)
{
   tilePosition.x = tx;
   tilePosition.y = ty;
   sprite = sp;
   property = p;
}

int Tile::getTX() const
{
   return tilePosition.x;
}

int Tile::getTY() const
{
   return tilePosition.y;
}

Tile::Property Tile::getProperty() const
{
   return property;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   sprite->setPosition(tilePosition.x * sprite->getLocalBounds().width,
      tilePosition.y * sprite->getLocalBounds().height);
   target.draw(*sprite, states);
}
