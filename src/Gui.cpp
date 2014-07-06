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
      //window.draw(stuff);

      window.display();
   }
}
