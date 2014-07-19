#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include <vector>

class Map
{
public:
   Map();
   ~Map();
   void addTile(Tile t);
   std::vector<Tile> getTiles() const;
private:
   std::vector<Tile> tiles;
};

#endif
