#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Tile : public sf::Drawable
{
public:
   enum Property {NONE, BLOCK, TELEPORT};
   Tile();
   Tile(int tx, int ty, std::shared_ptr<sf::Sprite> sp, Property p);
   ~Tile();
   void create(int tx, int ty, std::shared_ptr<sf::Sprite> sp, Property p);
   int getTX() const;
   int getTY() const;
   Tile::Property getProperty() const;
private:
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   std::shared_ptr<sf::Sprite> sprite;
   sf::Vector2i tilePosition;
   Property property;
};

#endif
