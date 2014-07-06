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
      for(unsigned int i = 0; i < sprites.size(); i++)
      {
         window.draw(sprites[i]);
      }

      window.display();
   }
}

void Gui::addEntity(std::shared_ptr<Entity> ent, std::string fileName, int imageX, int imageY)
{
   entities.push_back(ent);
   sprites.push_back(sf::Sprite(*textureManager.getTexture(fileName, imageX, imageY,
      ent->getWidth(), ent->getHeight())));
}
