#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::addTile(Tile t)
{
   tiles.push_back(t);
}

std::vector<Tile> Map::getTiles() const
{
   return tiles;
}
