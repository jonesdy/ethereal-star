#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Tile : public sf::Drawable
{
public:
   enum Property {NONE, BLOCK, TELEPORT};
   Tile();
   Tile(int xPos, int yPos, std::shared_ptr<sf::Sprite> sp, Property p);
   ~Tile();
   void create(int xPos, int yPos, std::shared_ptr<sf::Sprite> sp, Property p);
   int getX() const;
   int getY() const;
   Tile::Property getProperty() const;
private:
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   std::shared_ptr<sf::Sprite> sprite;
   int x;
   int y;
   Property property;
};

#endif
