#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

class Entity
{
public:
   Entity();
   Entity(std::string file, int xPos, int yPos, int w, int h);
   ~Entity();
   void create(std::string file, int xPos, int yPos, int w, int h);
   std::string getFileName() const;
   int getX() const;
   int getY() const;
   int getWidth() const;
   int getHeight() const;
private:
   std::string fileName;
   int x;
   int y;
   int width;
   int height;
};

#endif
