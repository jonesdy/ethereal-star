#include "Gui.hpp"

const int Gui::WINDOW_WIDTH = 800;
const int Gui::WINDOW_HEIGHT = 640;
const sf::String Gui::WINDOW_TITLE = "Ethereal Star";

Gui::Gui()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
   srand(time(NULL));
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
   if(isWindowOpen())
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
      for(unsigned int i = 0; i < spriteInfos.size(); i++)
      {
         // Get the sprite info
         SpriteInfo si = *spriteInfos[i];

         // See if we have a sprite for this already
         if(sprites.count(si) != 1)
         {
            // We don't so create the sprite first
            sprites[si] = sf::Sprite(*textureManager.getTexture(si.getFileName(),
               si.getImageX(), si.getImageY(), si.getImageWidth(), si.getImageHeight()));
         }

         // Don't draw if it's off the screen
         if((si.getX() > 0) && (si.getX() - si.getImageWidth() < WINDOW_WIDTH) &&
            (si.getY() > 0) && (si.getY() - si.getImageHeight() < WINDOW_HEIGHT))
         {
            window.draw(sprites[si]);
         }
      }

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
         
         // Don't bother drawing if the sprite is off the screen
         if((si.getX() > 0) && (si.getX() - si.getImageWidth() < WINDOW_WIDTH) &&
            (si.getY() > 0) && (si.getY() - si.getImageHeight() < WINDOW_HEIGHT))
         {
            sprites[si].setPosition(si.getX(), si.getY());
            window.draw(sprites[si]);
         }
      }

      window.display();
   }
}

void Gui::addEntity(std::shared_ptr<Entity> ent)
{
   entities.push_back(ent);
}

void Gui::removeEntity(std::shared_ptr<Entity> ent)
{
   // TODO: Actually test this
   entities.erase(std::remove(entities.begin(), entities.end(), ent), entities.end());
}

void Gui::addSpriteInfo(std::shared_ptr<SpriteInfo> si)
{
   spriteInfos.push_back(si);
}

void Gui::removeSpriteInfo(std::shared_ptr<SpriteInfo> si)
{
   // TODO: Actually test this
   spriteInfos.erase(std::remove(spriteInfos.begin(), spriteInfos.end(), si), spriteInfos.end());
}
