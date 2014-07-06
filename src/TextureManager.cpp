#include "TextureManager.hpp"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

std::shared_ptr<sf::Texture> TextureManager::getTexture(std::string fileName,
   int x, int y, int width, int height)
{
   // See if we already loaded this file
   if(images.count(fileName) == 0)
   {
      // Load it
      images[fileName] = std::unique_ptr<sf::Image>(new sf::Image);
      if(!images[fileName]->loadFromFile(fileName))
      {
         return nullptr;
      }
   }

   // See if we already loaded this texture
   std::vector<sf::IntRect> &textCuts = textureCuts[fileName];
   sf::IntRect desiredCut(x, y, width, height);
   for(unsigned int i = 0; i < textCuts.size(); i++)
   {
      if(textCuts[i] == desiredCut)
      {
         return textures[fileName][i];
      }
   }

   // Haven't loaded it yet, let's load it now
   textureCuts[fileName].push_back(desiredCut);
   std::shared_ptr<sf::Texture> newTexture(new sf::Texture);
   newTexture->loadFromImage(*images[fileName], desiredCut);
   textures[fileName].push_back(newTexture);
   return newTexture;
}
