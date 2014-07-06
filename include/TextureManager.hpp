#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>
#include <memory>

class TextureManager
{
public:
   TextureManager();
   ~TextureManager();
   std::shared_ptr<sf::Texture> getTexture(std::string fileName, int x, int y, int width, int height);
private:
   std::map<std::string, std::unique_ptr<sf::Image> > images;
   std::map<std::string, std::vector<sf::IntRect> > textureCuts;
   std::map<std::string, std::vector<std::shared_ptr<sf::Texture> > > textures;
};

#endif
