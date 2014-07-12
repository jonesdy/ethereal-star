#include "SpriteInfo.hpp"
#include <sstream>

SpriteInfo::SpriteInfo()
{
   create("", 0, 0, 0, 0);
}

SpriteInfo::SpriteInfo(std::string file, int x, int y, int width, int height)
{
   create(file, x, y, width, height);
}

SpriteInfo::~SpriteInfo()
{
}

void SpriteInfo::create(std::string file, int x, int y, int width, int height)
{
   fileName = file;
   imageX = x;
   imageY = y;
   imageWidth = width;
   imageHeight = height;
}

std::string SpriteInfo::getFileName() const
{
   return fileName;
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
