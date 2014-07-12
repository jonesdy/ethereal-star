#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>
#include <utility>
#include "SpriteInfo.hpp"

class Entity
{
public:
   enum Direction {UP, DOWN, LEFT, RIGHT};
   Entity();
   Entity(int xPos, int yPos, int w, int h);
   ~Entity();
   void create(int xPos, int yPos, int w, int h);
   int getX() const;
   int getY() const;
   int getWidth() const;
   int getHeight() const;
   void addSpriteInfo(SpriteInfo si, int frame, Direction dir);
   SpriteInfo getCurrentSpriteInfo();
   void move(int dx, int dy);
private:
   int x;
   int y;
   int width;
   int height;
   int frame;
   int maxFrame;
   Direction direction;
   std::map<std::pair<int, Direction>, SpriteInfo> spriteInfos;   // Frame, direction
};

#endif
