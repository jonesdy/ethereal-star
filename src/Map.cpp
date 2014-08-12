#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::addTile(std::shared_ptr<Tile> t)
{
   tiles.push_back(t);
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   // TODO: Build a render image of the tiles so we don't have to draw them every time
   for(unsigned int i = 0; i < tiles.size(); i++)
   {
      target.draw(*tiles[i], states);
   }
}
