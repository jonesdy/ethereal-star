#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "Entity.hpp"
#include "TextureManager.hpp"

class Gui
{
public:
   static const int WINDOW_WIDTH;
   static const int WINDOW_HEIGHT;
   static const sf::String WINDOW_TITLE;
   Gui();
   ~Gui();
   bool isInitialized() const;
   bool isWindowOpen() const;
   void draw();
   void addEntity(std::shared_ptr<Entity> ent);
   void removeEntity(std::shared_ptr<Entity> ent);
   void addSpriteInfo(std::shared_ptr<SpriteInfo> si);
   void removeSpriteInfo(std::shared_ptr<SpriteInfo> si);
private:
   sf::RenderWindow window;
   bool initialized;
   TextureManager textureManager;
   std::map<SpriteInfo, sf::Sprite> sprites;
   std::vector<std::shared_ptr<Entity> > entities;          // Entities can change sprites
   std::vector<std::shared_ptr<SpriteInfo> > spriteInfos;
};

#endif
