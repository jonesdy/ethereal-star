#ifndef TILE_HPP
#define TILE_HPP

#include "SpriteInfo.hpp"

class Tile
{
public:
   enum Property {NONE, BLOCK, TELEPORT};
   Tile();
   Tile(int xPos, int yPos, SpriteInfo si, Property p);
   ~Tile();
   void create(int xPos, int yPos, SpriteInfo si, Property p);
   SpriteInfo getSpriteInfo() const;
   int getX() const;
   int getY() const;
   Tile::Property getProperty() const;
private:
   SpriteInfo spriteInfo;
   int x;
   int y;
   Property property;
};

#endif
