#include "Gui.hpp"

const int Gui::WINDOW_WIDTH = 800;
const int Gui::WINDOW_HEIGHT = 640;
const sf::String Gui::WINDOW_TITLE = "Ethereal Star";

Gui::Gui()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
   window.setFramerateLimit(60);
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
   lastEvent.reset();
   if(isWindowOpen())
   {
      sf::Event evt;
      while(window.pollEvent(evt))
      {
         if(evt.type == sf::Event::Closed)
         {
            window.close();
         }
         else
         {
            lastEvent.reset(new sf::Event(evt));
         }
      }

      window.clear();

      // Do drawing here
      for(unsigned int i = 0; i < drawables.size(); i++)
      {
         window.draw(*drawables[i]);
      }

      window.display();
   }
}

void Gui::addDrawable(std::shared_ptr<sf::Drawable> drawable)
{
   drawables.push_back(drawable);
}

void Gui::removeDrawable(std::shared_ptr<sf::Drawable> drawable)
{
   // TODO: Actually test this
   drawables.erase(std::remove(drawables.begin(), drawables.end(), drawable), drawables.end());
}

std::shared_ptr<sf::Event> Gui::getLatestEvent()
{
   return lastEvent;
}
