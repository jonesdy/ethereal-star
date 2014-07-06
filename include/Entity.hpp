#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

class Entity
{
public:
   Entity();
   Entity(int xPos, int yPos, int w, int h);
   ~Entity();
   void create(int xPos, int yPos, int w, int h);
   int getX() const;
   int getY() const;
   int getWidth() const;
   int getHeight() const;
private:
   int x;
   int y;
   int width;
   int height;
};

#endif
