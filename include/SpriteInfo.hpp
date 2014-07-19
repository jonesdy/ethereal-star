#ifndef SPRITEINFO_HPP
#define SPRITEINFO_HPP

#include <string>

class SpriteInfo
{
public:
   SpriteInfo();
   SpriteInfo(std::string file,int ix, int iy, int width, int height);
   ~SpriteInfo();
   void create(std::string file,int ix, int iy, int width, int height);
   std::string getFileName() const;
   void setX(int xPos);
   void setY(int yPos);
   int getX() const;
   int getY() const;
   int getImageX() const;
   int getImageY() const;
   int getImageWidth() const;
   int getImageHeight() const;
   std::string toString() const;
   bool operator<(SpriteInfo si) const;      // So we can use std::map
private:
   std::string fileName;
   int x;
   int y;
   int imageX;
   int imageY;
   int imageWidth;
   int imageHeight;
};

#endif
