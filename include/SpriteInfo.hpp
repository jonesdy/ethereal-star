#ifndef SPRITEINFO_HPP
#define SPRITEINFO_HPP

#include <string>

class SpriteInfo
{
public:
   SpriteInfo();
   SpriteInfo(std::string file, int x, int y, int width, int height);
   ~SpriteInfo();
   void create(std::string file, int x, int y, int width, int height);
   std::string getFileName() const;
   int getImageX() const;
   int getImageY() const;
   int getImageWidth() const;
   int getImageHeight() const;
   std::string toString() const;
   bool operator<(SpriteInfo si) const;      // So we can use std::map
private:
   std::string fileName;
   int imageX;
   int imageY;
   int imageWidth;
   int imageHeight;
};

#endif
