#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

class Map : public sf::Drawable
{
public:
   Map();
   ~Map();
   void addTile(std::shared_ptr<Tile> t);
private:
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   std::vector<std::shared_ptr<Tile> > tiles;
};

#endif
