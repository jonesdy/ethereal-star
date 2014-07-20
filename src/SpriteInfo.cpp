#include "SpriteInfo.hpp"
#include <sstream>

SpriteInfo::SpriteInfo()
{
   create("", 0, 0, 0, 0);
}

SpriteInfo::SpriteInfo(std::string file, int ix, int iy, int width, int height)
{
   create(file, ix, iy, width, height);
}

SpriteInfo::~SpriteInfo()
{
}

void SpriteInfo::create(std::string file, int ix, int iy, int width, int height)
{
   fileName = file;
   x = 0;
   y = 0;
   imageX = ix;
   imageY = iy;
   imageWidth = width;
   imageHeight = height;
}

std::string SpriteInfo::getFileName() const
{
   return fileName;
}

void SpriteInfo::setX(int xPos)
{
   x = xPos;
}

void SpriteInfo::setY(int yPos)
{
   y = yPos;
}

int SpriteInfo::getX() const
{
   return x;
}

int SpriteInfo::getY() const
{
   return y;
}

int SpriteInfo::getImageX() const
{
   return imageX;
}

int SpriteInfo::getImageY() const
{
   return imageY;
}

int SpriteInfo::getImageWidth() const
{
   return imageWidth;
}

int SpriteInfo::getImageHeight() const
{
   return imageHeight;
}

std::string SpriteInfo::toString() const
{
   std::ostringstream ss;
   ss<<fileName<<imageX<<imageY<<imageWidth<<imageHeight;
   return ss.str();
}

bool SpriteInfo::operator<(SpriteInfo si) const
{
   return toString() < si.toString();
}
