#include "Gui.hpp"

const unsigned int Gui::WINDOW_WIDTH = 800;
const unsigned int Gui::WINDOW_HEIGHT = 640;
const sf::String Gui::WINDOW_TITLE = "Ethereal Star";

Gui::Gui()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
}

Gui::~Gui()
{
}

bool Gui::isInitialized() const
{
   return initialized;
}

bool Gui::isWindowOpen() const
{
   return window.isOpen();
}

void Gui::draw()
{
   while(window.isOpen())
   {
      sf::Event evt;
      while(window.pollEvent(evt))
      {
         if(evt.type == sf::Event::Closed)
         {
            window.close();
         }
      }

      window.clear();

      // Do drawing here
      for(unsigned int i = 0; i < entities.size(); i++)
      {
         // Get the current sprite info
         SpriteInfo si = entities[i]->getCurrentSpriteInfo();

         // See if we have set it up already
         if(sprites.count(si) != 1)
         {
            // We don't, create the sprite first
            sprites[si] = sf::Sprite(*textureManager.getTexture(si.getFileName(),
               si.getImageX(), si.getImageY(), si.getImageWidth(), si.getImageHeight()));
         }
         window.draw(sprites[si]);
      }

      window.display();
   }
}

void Gui::addEntity(std::shared_ptr<Entity> ent)
{
   entities.push_back(ent);
}
