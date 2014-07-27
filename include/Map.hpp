#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable
{
public:
   Map();
   ~Map();
   void addTile(Tile t);
private:
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   std::vector<Tile> tiles;
};

#endif
